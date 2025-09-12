# Implement Middleware

Middleware functions can be used for various tasks, such as logging, authentication, parsing data, and so on.

## Middleware

Middleware functions are those that alter the request (`req`) and response (`res`) objects in the request-response cycle of an application.

**New HTTP Request** $\Longrightarrow$ **Middleware Functions** $\Longrightarrow$ **Route Handlers**

Middleware functions should accept three parameters: `re`, `res`, `next`. They're executed in a specific order. When the current middleware function is done, it passes control to the next middleware function in the stack by calling `next()`.

If we don't call `next()` inside a middleware function, the route handlers that come after the middleware function won't run.

## Task 9: Implement Application-Level Middleware

Create a simple logging middleware to print information about every incoming request. Add the following middleware before the route handlers in the `src/index.js` file:

```js
const express = require('express');
const path = require('path');

const app = express();

app.use((req, res, next) => {
  const { method, path } = req;
  console.log(
    `New request to: ${method} ${path} at ${new Date().toISOString()}`
  );
  next();
});

const publicDirectoryPath = path.join(__dirname, './public');
app.use(express.static(publicDirectoryPath));

app.get("/", (req, res) => {
res.send("Hello Express Student!");
});

app.get("/:name", (req, res) => {
 res.send(`Welcome to Express Recipes, ${req.params.name}!`);
});

const port = process.env.PORT || 8080;

app.listen(port, () => {
 console.log(`Server is up on port ${port}.`);
});

```

Breaking down the syntax:

  - We use `app.use()` to set up a middleware function. Because a mount path isn't passed as the first argument, the function will be executed every time the application receives a request.
  - We use the callback function, passed to `app.use()`, to log information about the incoming request, and finally call `next()`.
  - When we call `next()`, it passes control to the next middleware, which in this case is the middleware that serves static files from the `public/` folder.

If we try it ona local machine then we may navigate to `http://localhost:8080`. At this point, we have a basic Express server capable of serving static assets and handling a basic HTTP `GET` request!
