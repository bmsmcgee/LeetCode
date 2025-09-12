# Enable CORS

We can use third-party middleware to add functionality to Express applications, including support for **Cross-Origin Resource Sharing (CORS)**.

## Cross-Origin Resource Sharing (CORS)

By default, any requests that come from an origin other than the server hosting our application will be blocked.

So, if a website that's hosted on a different origin tries to make `GET` requests to the Express server, the requests would be blocked unless the website is added to a CORS whitelist in Express.

The `npm` package `cors` is a middleware that allows us to configure CORS in Express applications with various options. By default, the cors package just enables resource sharing and access for all origins.

1. Install `cors` by running the following command in the project folder in the terminal window:

```bash
npm install cors --save
```

2. Inside `src/index.js`, call the `cors` middleware as part of the server setup:

```js
const express = require("express");
const path = require('path');
const cors = require("cors");

const recipesRouter = require('./routers/recipes');

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

const port = process.env.PORT || 8080;

app.listen(port, () => {
  console.log(`Server is up on port ${port}.`);
});
```

Now we have a fully working API!

## Task 13: Chain Route Handlers with `router.route()`

1. We can use `router.route()` to chain route handlers that share the same route path. We can see this in the code below:

```js
const express = require('express');
const router = express.Router();

const {
 deleteRecipe,
 getAllRecipes,
 getRecipe,
 saveRecipe,
 updateRecipe,
} = require('../controllers/recipe');

// Route `GET` and `POST` HTTP requests for `/`
router.route('/').get(getAllRecipes).post(saveRecipe);

// Route `GET`, `PUT`, and `DELETE` HTTP requests for `api/v1/recipes/:id`
router.route('/:id').get(getRecipe).put(updateRecipe).delete(deleteRecipe);

module.exports = router;
```

