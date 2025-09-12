# Implement Route Handlers for `GET`, `PUT`, and `DELETE`

Let's allow the API consumer to retrieve, update, or delete a recipe by ID. 

## Implementing Route Handlers

1. First, implement the necessary functions in the service layer ro perform CRUD operations on the database. Add the following code in the `express-recipes/src/services/recipes.js` file:

```js
const fs = require('fs').promises;
const path = require('path');

const recipesFilePath = path.join(__dirname, '../../db/recipes.json');

const getAll = async () => JSON.parse(await fs.readFile(recipesFilePath));

const get = async (id) => {
  const recipes = await getAll();
  return recipes.find(recipe) => recipe.id === parseInt(id));
};

const save = async (recipe) => {
  const recipes = await getAll();

  recipe.id = recipes.length + 1;
  recipes.push(recipe);

  await fs.writeFile(recipesFilePath, JSON.stringify(recipes));

  return recipe;
};

const update = async (id, updated) => {
  const recipes = await getAll();

  updated.id = parseInt(id);

  const updatedRecipes = recipes.map((recipe) => {
    return recipe.id === parseInt(id) ? updated : recipe;
  });

  await fs.writeFile(recipesFilePath, JSON.stringify(updatedRecipes));

  return updated;
};

const remove = async (id) => {
  const recipes = await getAll();
  const newRecipes = recipes
    .map((recipe) => {
      return recipe.id === parseInt(id) ? null : recipe;
    })
    .filter((recipe) => recipe !== null);

  await fs.writeFile(recipesFilePath, JSON.stringify(newRecipes));
};

module.exports = {
  getAll,
  get,
  save,
  update,
  remove,
};
```

2. Next, create the route handler functions, which will call the service layer functions that we created in the previous step. Add the following code in the `express-recipes/src/controllers/recipes.js` file:

```js
const service = require('../services/recipes');

const getAll = async (req, res, next) => {
  try {
    res.json({ data: await service.getAll() });
  } catch (error) {
    next(error);
  }
};

const get = async (req, res, next) => {
  try {
    const recipe = await service.get(req.params.id);

    if (recipe === undefined) {
      const err = new Error('Recipe not found');
      err.statusCode = 404;
      throw err;
    }

    res.json({ data: recipe });
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

const update = async (req, res, next) => {
  try {
    const recipe = await service.get(req.params.id);

    if (recipe === undefined) {
      const err = new Error("Recipe not found");
      err.statusCode = 404;
      throw err;
    }

    const {
      name,
      healthLabels,
      cookTimeMinutes,
      prepTimeMinutes,
      ingredients,
    } = req.body;

    const updated = await service.update(req.params.id, {
      name,
      healthLabels: [...healthLabels],
      cookTimeMinutes,
      prepTimeMinutes,
      ingredients: [...ingredients],
    });

    res.json({ data: updated });
  } catch (error) {
    next(error);
  }
};

const remove = async (req, res, next) => {
  try {
    const recipe = await service.get(req.params.id);

    if (recipe === undefined) {
      const err = new Error("Recipe not found");
      err.statusCode = 404;
      throw err;
    }

    await service.remove(req.params.id);
//  Send a proper status
  } catch (error) {
    next(error);
  }
};

module.exports = {
  getAll,
  get,
  save,
  update,
  remove,
};
```

3. Finally, add the API routes to the `recipes` router to route the requests to the appropriate controllers. Add the following code in the `express-recipes/src/routers/recipes.js` file:

```js
const express = require("express");
const router = express.Router();

const { getAll, get, save, update, remove } = require("../controllers/recipes");

router.get("/", getAll);
router.post("/", save);
router.get("/:id", get);
router.put("/:id", update);
router.delete("/:id", remove);

module.exports = router;
```

## Redirect the Base URL `/` to `/api/v1/recipes`

Let's make the API a bit more user-friendly. Requests to `/` will be redirected to `/api/v1/recipes`, where all out routes are defined. We can use the `res.redirect()` method to redirect requests to a different desired path, which is passed as an argument to the method.

In the `src/index.js` file, we add a route handler above the recipes router as shown in the code below:

```js
const express = require("express");
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

app.get("/", (req, res) => {
  res.redirect("/api/v1/recipes");
});

app.use('/api/v1/recipes', recipesRouter);

const port = process.env.PORT || 8080;

app.listen(port, () => {
  console.log(`Server is up on port ${port}.`);
});
```

Once the browser receives a redirect, it performs a `GET` request to the `/api/v1/recipes` endpoint instead.
