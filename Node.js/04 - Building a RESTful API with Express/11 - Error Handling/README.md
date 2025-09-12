# Error Handling

Express comes with a default built-in error handler that deals with any errors that might arise in the application.

## Handle Errors Centrally

Since we haven't written custome error handlers to handle the errors passed to `next()` in `src/controllers/recipe.js`, the errors will be handled by the built-in error handler.

Lets see what the default handler does. If a faulty path is visited where a recipe with a certain `id` doesn't exist, then an error is displayed in the browser, as shown below:

<img width="939" height="50" alt="image" src="https://github.com/user-attachments/assets/51d7ea9d-a5cf-42b1-b1e8-cd8c51bc57c0" />

The error is written to the client with the stack trace in development mode. For security purposes, the stack trace isn't exposed in the production environment. As we can see, the error message is neither descriptive nor helpful for the client.

We can create a custom error handler to fix that. To avoid duplicating the code for error handling, we can also create a helper method to handle errors centrally in the application.

1. Create a directory called `utils` with `src/`. Inside the `utils` directory, create a file called `error.js`.

```bash
mkdir src/utils
touch src/utils/error.js
```

2. The built-in Node.js `Error` class contains important information about application errors like stack traces. So, let's define a custom error class that inherits from it:

```js
class CustomError extends Error {
  constructor({ statusCode, message }) {
    super();
    this.statusCode = statusCode;
    this.message = message;
  }
}

module.exports = {
CustomError,
};
```

Breaking down the syntax:
  - **Line 3**: Inherit properties and methods from the built-in `Error` class.
  - **Line 4**: Define a custom status code for the error.
  - **Line 5**: Define a custom message for the error.

3. Inside `src/utils/error.js`, define an error-handling middleware to handle errors in the application, right below the `CustomError` class:

```js
const handleError = (err, req, res, next) => {
  let { statusCode, message } = err;

  console.error(message);

  if (!statusCode) statusCode = 500;

  res.status(statusCode).json({
    status: 'error',
    statusCode,
    message,
  });
};

module.exports = {
  handleError,
  CustomError,
};
```

Breaking down the syntax:
  - **Line 4**: Log error message in our server's console.
  - **Line 6**: If no status code is specified, set it to `Internal Server Error (500)`.
  - **Line 7**: Send back an error with a valid HTTP status code and message.

Note that an error-handling function has four arguments instead of three, namely `err`, `req`, `res`, and `next`. They will only get called if an error occurs.

4. Inside `src/index.js`, import `handleError` at the top of the file and call it last, after all other `app.use()` and route calls, like this:

```js
const express = require("express");
const path = require('path');
const cors = require("cors");

const recipesRouter = require('./routers/recipes');
const { handleError } = require('./utils/error');

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

app.get("/", (req, res) => {
  res.redirect("/api/v1/recipes");
});

app.use('/api/v1/recipes', recipesRouter);

app.use(handleError);

const port = process.env.PORT || 8080;

app.listen(port, () => {
  console.log(`Server is up on port ${port}.`);
});
```

5. If we visit a faulty path, we should see the following message:

<img width="807" height="118" alt="image" src="https://github.com/user-attachments/assets/f1544504-6ffe-4d63-adfc-17af0f2d457e" />
