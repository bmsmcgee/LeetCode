# Implement Routing

## Routing

Routing refers to how an application handles a client request to a particular endpoint. An endpoint consists of a **path**, such as `/hello` in `https://www.helloworld.com/hello`, and an **HTTP method**, which would be `GET`, `PUT`, `POST`, `PATCH`, or `DELETE`.

## Task 6: Express Route Handler

Inside `src/index.js`, create a route handler after instantiating the Express application:

```js
const express = require('express');
const app = express();

// Route handler that sends a message to someone

app.get('/', (req, res) => {
  res.send('Hello Express Person!');
});

const port = process.env.PORT || 8080;

app.listen(port, () => {
  console.log(`Server is up on port ${port}.`);
});
```

Breaking down the syntax:
  - **Line 2**: The `app` keyword refers to the instance of the Express server declared earlier at the top of the file.
  - **Line 6**: The `.get()` function tells our Express server what HTTP method to listen for.
    - The first argument is the path to set up the handler for. This route path will match requests to the root route `/`.
    - The second argument is a callback function that's executed when the path`/` is visited. The callback function accepts two arguments:
      1. The first is the [HTTP request object](https://expressjs.com/en/5x/api.html#req) (referred to as `req`).
      2. The second is the [HTTP response object](https://expressjs.com/en/5x/api.html#res), `res`, that an Express application sends to the client.
  - **Line 7** : Calling `res.send()` in the route handler sends a message back as the response to the client

We now have a working route!

## Task 7: Dynamic Routes

Routes can be made dynamic, meaning that parameters can be added to the routes.

Route parameters are simply placeholders (similar to variables) in a URL. They always start with the `:` symbol. They allow us to customize our server's responses to an HTTP request.

The provided code accepts a `name` parameter:

```js
const express = require('express');
const app = express();

app.get('/', (req, res) => {
  res.send('Hello Express Person!');
});

app.get('/:name', (req, res) => {
  res.send(`Welcome to Express Recipes, ${req.params.name}!`);
});

const port = process.env.PORT || 8080;

app.listen(port, () => {
  console.log(`Server is up on port ${port}.`);
});
```

We can now access the `:name` route parameter as a key inside the `req.params` object. Our greeting is more personal.
