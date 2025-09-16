# Project Setup: Part One

Understand the project's dependencies and files before beginning to work with Passport.js

## Task 1: Install Dependencies

1. Navigate to the project folder.
2. Install the following dependencies:
    - `bcrypt`
    - `express`
    - `jsonwebtoken`
    - `passport`
    - `passport-jwt`
    - `dotenv`

```bash
npm install --save bcrypt express jsonwebtoken passport passport-jwt dotenc
```

## Task 2: Set Up Files for User Authentication Routes

1. In the previous section, we set up a `router`, `controller`, and `service` for the recipes resource in the Express Recipes API. Let's follow a similar pattern to organize our user authentication logic:

```bash
touch src/routers/users.js src/services/users.js db/users.json src/controllers/users.js
```

2. Create a new folder to store middleware functions. Within it, create a file called `auth.js`:

```bash
mkdir src/middleware
touch src/middleware/auth.js
```

Later on, we will configure the Passport.js strategy inside `src/middleware/auth.js`

3. We'll store the users' data in `db/users.json`

Add a user to the file to serve as an example of what an entry in the file might look like:

```json
[
  {
    "id": 1,
    "name": "Hou",
    "email": "hou@mail.com",
    "password": "$2b$10$u2r3EK7.p4l9bzQd74nGNepvIHw5gF84j4Dy6/kJmtNR4OC.A5t5O"
  }
]
```

Notice that the user's `password` is hashed for security reasons. Later on, we'll learn how to use `bcrypt` to hash a user's password before storing it in the database.

4. Create a `.env` file in the project root folder to store the JWT-related configuration variables:

```txt
JWT_SECRET=##%%MyS3cr3tK3Y%%##
```

`JWT_SECRET` will be used to create a signature for signing and validating the JWTs.

Keep in mind that since the `.env` file typically contains sensitive information (like API secret keys), we don't want to commit it to Git, so it should be added to the `.gitignore` file.

We'll use the `JWT_SECRET` variable later on to configure the Passport.js strategy.

## Task 3: Configure the Passport.js JWT Strategy

1. Before Passport.js can authenticate a request, we must set up the Passport.js authentication middleware and configure Passport.js to use the JWT authentication strategy. Add the following code to `src/middleware/auth.js`:

```js
require('dotenv').config();
const passport = require('passport');
const { Strategy, ExtractJwt } = require('passport-jwt');

const { find: findUser } = require('../services/users');

const { JWT_SECRET } = process.env;

const strategy = new Strategy (
  {
    jwtFromRequest: ExtractJwt.fromAuthHeaderAsBearerToken(),
    secretOrKey: JWT_SECRET,
  },
  async (jwtPayload, done) => {
    try {
      const user = await findUser({ id: jwtPayload.id });
  
      if (!user) {
        const err = new Error('User not found');
        err.statusCode = 404;
        throw err;
      }
  
      done(null, user);
    } catch (error) {
      done(error);
    }
  }
);

passport.use(strategy);

const initialize = () => {
  return passport.initialize();
};

const authenticate = () => {
  return passport.authenticate('jwt', { session: false });
};

module.exports = {
  initialize,
  authenticate,
};
```

Breaking down the syntax:
  - **Line 1**: Load the environment variables into `process.env`.
  - **Line 9**: Create a new instance of the JWT `Passport.js` strategy, passing a configuration object as the first argument that controls how a token is extracted from the request.
  - **Line 11**: Extract the `bearer` token from the authorization header where the encoded JWT string is stored.
  - **Line 12**: This is a string for verifying the token's signature.
  - **Line 14**: The `jwtPayload` parameter contains the decoded JWT payload. This includes the user's ID, which we can use to check whether or not the user already exists in the database.
  - **Line 24**: `done` is an error-first callback with a signature (`error`, `user`, `info`). The found user is passed to the route handler.
  - **Line 31**: Register the strategy configured above so that Passport.js can use its authentication.
  - **Line 33**: This is a middleware for initializing passport.
  - **Line 37**: We'll add this middleware to protected routes later on. The middleware calls `passport.authenticate()` with two arguments. Since we're using JWTs, we don't need to create a session, so set it to `false` here. Otherwise, Passport.js will attempt to create a session.
 
2. In `src/index.js`, import and load the `auth` middleware when starting the server, like this:

```js
const express = require("express");
const path = require("path");
const cors = require("cors");

const recipesRouter = require("./routers/recipes");
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

app.use(handleError);

const port = process.env.PORT || 8080;

app.listen(port, () => {
  console.log(`Server is up on port ${port}.`);
});
```

## Task 4: Create the `users` Service

Inside `src/services/users`, create three functions: `authenticate()` and `create()`, which authenticate and create users with JWT authorization tokens, respectively, and `find()`, which retrieves a user by `id` or `email`:

```js
require('dotenv').config();
const bcrypt = require('bcrypt');
const fs = require('fs').promises;
const jwt = require('jwt');
const path = require('path');

const { JWT_SECRET } = process.env;
const usersFilePath = path.join(__dirname, '../../db/users.json');

const authenticate = async ({ id, email, password }) => {
  const user = await find({ email })'

  const isPasswordValid = await bcrypt.compare(password, user.password);

  const token = jwt.sign({ id: user.id }, JWT_SECRET, {
    expiresIn: 24 * 60 * 60,
  });

  return { token };
};

const create = async ({ email, name, password }) +> {
  const users = JSON.parse(await fs.readFile(usersFilePath));

  const newUser = {
    id: users.length + 1,
    email,
    name,

    password: await bcrypt.hash(password, 10),
  };

  const token = jwt.sign({ id: newUser.id }, JWT_SECRET, {
    expiresIn: 24 * 60 * 60,
  });

  users.push(newUser);

  await fs.writeFile(usersFilePath, JSON.stringify(users));

  return { token };
};

const find = async ({ id, email }) => {
  const users = JSON.parse(await fs.readFile(usersFilePath));
  return users.find((user) => user.id === parseInt(id) || user.email === email);
};

module.exports = {
  authenticate,
  create,
  find,
};
```

Breaking down the syntax:
  - **Line 10**: Authenticate the user and return an authorization token for the user. Use this function to authenticate a user who's logging in.
  - **Line 13**: Hash the user's password to compare the result with the hash, and save it in the database to see if the password is correct.
  - **Line 15**: Call `jwt.sign()`, which returns an authentication token. The first argument is an object that contains the data to be embedded in the token. We can pass in a unique identifier for the user, such as the user's ID stored in the database. The second argument is a string, which could be any random series of characters used to sign the token to ensure the token hasn't been tampered with whenm it's sent back to the server later on. The third argument is a configuration object for the token.
  - **Line 22**: Save the new user to the database and return an authorization token for the user.
  - **Line 30**: Here, pass the user's password to the `bcrypt.hash()` function to create a hash, which is stored in the database instead of the user's origingal password. Hashing is a one-way operation, so the has can't be revered to its original form. The first argument is the password to be encrypted. The second argument is the number salt rounds. The higher the num,ber salt rounds used, the stronger the resulting hashed password becomes.
  - **Line 33**: Generate the JWT with `jwt.sign`. The return value is the authentication token.
  - **Line 34**: Expire token after a certain amount of time so users can't stay logged in forever.
  - **Line 39**: Save the new user to the database.
