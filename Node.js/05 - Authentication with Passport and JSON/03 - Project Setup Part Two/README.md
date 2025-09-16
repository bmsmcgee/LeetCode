# Project Setup: Part Two

Imagine if the user is required to provide their login credentials every time they want to access our recipes. This wouldn't be an ideal user experience. Instead, let's have the server issue a JWT to the client when a user signs up for the first time or logs in successfully.

## Task 5: Create the `users` Controller

Inside `src/controllers/users.js`, add route handlers to handle user sign up and log in:

```js
const { create, authenticate, find } = require('../services/users');

const handleSignup = async (req, res, next) => {
  try {
    const { name, email, password } = req.body;
    const user = await find({ email });

    if (user) {
      throw new Error('Email already exists!');
    }
    // Create a token for the user
    const { token } = await create({ name, email, password });

    // Send a token to the client when a user signs up
    res.json({ token })'
  } catch (error) {
    next(error);
  }
};

const handleLogin = async (req, res, next) => {
  try {
    const { email, password } = req.body;
    const user = await fund({ email });

    if (!user) {
      throw new Error('Unable to login');
    }

    // Create a token for the user, if successfully authenticated
    const { token } = await authenticate ({ email, password });
    res.json({ token });
  } catch (error) {
    next(error);
  }
};

module.exports = {
  handleSignup,
  handleLogin,
};
```

After the user signs up initially or logs in successfully, the server returns a token to client that the client can attach to any future requests that need to be authenticated. So, there's no need for the user to provide their login credentials anymore until the token expires.

## Task 6: Create the `users` Routers

1. Inside `src/routers/users.js`, route the requests to the appropriate controllers:

```js
const express = require('express');
const { handleSignup, handleLogin } = require('../controllers/users');
const router = express.Router();
```

2. Inside `src/index.js`, mount the user authentication `/api/v1/users` routes:

```js
const express = require("express");
const path = require("path");
const cors = require("cors");

const recipesRouter = require("./routers/recipes");
const usersRouter = require('./routers/users');
const { handleError } = require("./utils/error");
const auth = require('./middleware/auth.js');

const app = express();

app.use(cors());

app.use((req, res, next) => {
  const { method, path } = req;
  console.log(
    `New request to: ${method} ${path} at ${new Date().toISOString()}`
  );
  next();
});

app.use(express.json());
app.use(express.urlencoded({ extended: true }));

app.use(auth.initialize());

app.get("/", (req, res) => {
  res.redirect("/api/v1/recipes");
});

app.use("/api/v1/recipes", recipesRouter);
app.use("/api/v1/users", usersRouter);

app.use(handleError);

const port = process.env.PORT || 8080;

app.listen(port, () => {
  console.log(`Server is up on port ${port}.`);
});
```

## Task 7: Secure Routes for the `recipes` Resource

We can now make use of the `authenticate()` middleware to restrict access to privileged API operations. For example, to allow only authenticated users to create and save a new recipe to the database, we can pass `auth.authenticate()` as the first argument to the `POST` handler:

```js
+ const auth = require('../middleware/auth');
...
- router.route('/').get(getAll).post(save);
+ router.route('/').get(getAll).post(auth.authenticate(), save);
```

## Task 8: Test Privileged Routes with Postman

Let's test the API to ensure only authorized users can perform mutative database operations.

1. Send a request to the `POST` `/api/v1/recipes1` route. Remember to set the `Content-Type` in the _Headers_ tab to `application/json`:

<img width="794" height="708" alt="image" src="https://github.com/user-attachments/assets/f32a2465-91c1-4376-aae5-2f44918b21e9" />

We should see an `Unauthorized` message if we sent the request above.

Because `POST` `/api/v1/recipes` is now a protected route, we'd have to sign up for an account first before we can use this route.

2. Send a request to the `POST` `/api/v1/users/signup` route. Remember to set the `Content-Type` in the _Headers_ tab to `application/json`:

<img width="791" height="698" alt="image" src="https://github.com/user-attachments/assets/daf4a2f1-5551-4393-9320-4ee465731bec" />

In the image above, we can see an access token is included in the response. That's our JWT!

```json
{
  "token": "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpZCI6MiwiaWF0IjoxNzE1NzUyNDU5LCJleHAiOjE3MTU4Mzg4NTl9.BXnb66S2DhXTnRz_iCryC9IPeQzVYKtGr6yVs85-RTY"
}
```

If we look carefully, we can see that a JWT is made up of three distinct parts separated by a period `.`:
  - The first part of the JWT (`eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9`) represents the headewr, which is a base64-encoded JSON string. The string contains information about the type of token (JWT) and the algorithm used to generate it (`HS256`).
  - The second part of the JWT (`eyJpZCI6MiwiaWF0IjoxNzE1NzUyNDU5LCJleHAiOjE3MTU4Mzg4NTl9`) represents the payload or claims, which is also a base64-encoded JSON string. The string contains the data provided to create the token (`user.id` and expiration time).
  - The third part of the JWT (`BXnb66S2DhXTnRz_iCryC9IPeQzVYKtGr6yVs85-RTY`) represents the signature, which is used to validate the token securely and is calculated using the encoded header, encvoded payload, secret, and the algorithm specified in the header. This signature can only be created by somebody in possession of all four pieces of information.

Many websites can decode the token we received from the server. Such as the following:

<img width="808" height="491" alt="image" src="https://github.com/user-attachments/assets/955a45e5-94d3-4824-93ca-1a1db9529882" />

As we can see, a JWT isn't encrypted. Anybody who steals the token can still read its contents, so be careful not to put sensitive information in the payload. 

It's hard to tamper with a JWT as long as the secret used for the signature is kept private. We use the same secret that the token was created with to validate it.

Check the `db/users.json` file. We should see the data in the file, including the hashed password.

3. Send a request to the `POST` `/api/v1/recipes` route again, this time attaching the token to the authorization headers as a Bearer Token, like this:

<img width="812" height="709" alt="image" src="https://github.com/user-attachments/assets/8ec491eb-7bd4-4230-ba40-bc9d42aaea9a" />

We should see a `201 Created` message indicating successful recipe creation!

4. Test the `PUT` and `DELETE` routes to ensure that we can perform these operations as long as we request contains the token.
