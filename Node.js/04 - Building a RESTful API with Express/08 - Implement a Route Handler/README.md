# Implement a Route Handler

## Route Handler for `POST`

A common server task is to handle form data or JSON data submitted via a `POST` request. However, by default, Express doesn't know how to handle certain types of requests, like a `POST` request that contains JSON data in the request body, unless we call specific middlewares.

Here are two widely built-in middlewares:
  - `express.json()`
  - `exress.urlencoded()`

1. Add the `express.json()` middleware to parse JSON data and make it accessible in the request object (via `req.body`). Also, add the `express.urlencoded()` middleware to parse incoming requests with URL-encoded payloads.

```js
const express = require('express');
const path = require('path');

const recipesRouter = require('./routers/recipes');

const app = express();

app.use((req, res, next) => {
  const { method, path } = req;
  console.log(
    `New request to: ${method} ${path} at ${new Date().toISOString()}`
  );
  next();
});

app.use(express.json());
app.use(express.urlencoded({ extended: true }));

app.use('/api/v1/recipes', recipesRouter);

const port = process.env.PORT || 8080;

app.listen(port, () => {
  console.log(`Server is up on port ${port}.`);
});
```

2. In the recipes `service`, implement a `save()` method to save a new recipe to the database:

```js
const fs = require('fs').promises;
const path = require('path');

const recipesFilePath = path.join(__dirname, '../../db/recipes.json');

const getAll = async () => JSON.parse(await fs.readFile(recipesFilePath));

const save = async (recipe) => {

  const recipes = await getAll();

  recipe.id = recipes.length + 1;

  recipes.push(recipe);

  await fs.writeFile(recipesFilePath, JSON.stringify(recipes));

  return recipe;
};

module.exports = {
  getAll,
  save
};
```

Breaking down the above syntax:
  - **Line 4**: Contract the path to the recipes data.
  - **Line 10**: Get all recipes from the database.
  - **Line 14**: Push the new recipe into the current list of recipes.
  - **Line 16**: Save all recipes to the database.

3. In the recipes controller, implement a `save()` route handler for `POST` requests to `api/v1/recipes`:

```js
const service = require('../services/recipes');

const getAll = async (req, res, next) => {
  try {
    res.json({ data: await service.getAll() });
  } catch (error) {
    next(error);
  }
};

const save = async (req, res, next) => {
  try {

    const {
      name,
      healthLabels,
      cookTimeMinutes,
      prepTimeMinutes,
      ingredients,
    } = req.body;

    const newRecipe = {
      name,
      healthLabels: [...healthLabels],
      cookTimeMinutes,
      prepTimeMinutes,
      ingredients: [...ingredients],
    };

    res.status(201).json({ data: await service.save(newRecipe) });
  } catch (error) {
    next(error);
  }
};

module.exports = {
  getAll,
  save
};
```

Breaking down the above syntax:
  - **Lines 14-20**: Extract only the data that's needed from the request body using destructuring.
  - **Lines 22-28**: Format the new recipe you want to save to the database. Within the `newRecipe` object, make copies of the `healthLabels` and `ingredients` arrays to store in the database.
  - **Lines 30-32**: Respond with a `201` created status code along with the newly created recipe.

4. Back in the recipes `router`, import and mount the `save()` router handler on the `/` path:

```js
const express = require('express');
const router = express.Router();

const { getAll, save } = require('../controllers/recipes');

router.get('/', getAll);
router.post('/', save);

module.exports = router;
```
