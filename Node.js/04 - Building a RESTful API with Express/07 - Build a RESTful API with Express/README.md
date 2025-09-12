# Build a RESTful API with Express

## Overview

Let's implement a simplified Express API that serves recipe data via JSON over HTTP. We'll call it Express Recipes. The request-response cycle below traces how a user's `GET` request would flow through the Express Recipes application.

<img width="409" height="437" alt="image" src="https://github.com/user-attachments/assets/58b39786-064a-4561-92ee-110aa97b4a6c" />

To keep the API code organization easy to understand, maintain, and modify, we'll structure and write modular code using three main layers, namely the `router`, `controller`, and `service`.
  - The `router` for a given resource is responsible for routing requests to the appropriate `controller` based on the URL.
  - The `controller` for a given resource defines the logic for handling each route and is responsble for manipulating the state of a resource in the API. They also send back a response (either successful or not) to the client.
  - The `service` encapsulates or groups together the functions that perform a specific category of tasks in an application, like making CRUD transactions for a given resource. Services make code DRY (Don't Repeat Yourself principle) because the functions defined in a `service` can be reused throughtout the application.

Overall, structyuring and layering of the code this way would lead to better modularization, encapsulation, and separation of concerns in the codebase.

Here are the steps involved in the request-response cycle:
  1. The browser sends a `GET` request for all the recipes.
  2. The `router` maps the HTTP request to the corresponding `controller` for handling.
  3. The `controller` receives the HTTP request and asks the `service` to fetch data from storage.
  4. The `service` loads the data from `recipes.json`.
  5. The `service` returns data to the `controller`.
  6. The `controller` sends JSON data back to the browser.

## RESTful API

An API allows clients to access data on a server. **REpresentational State Transfer (REST)** is a popular architectural convention for structuring and naming APIs using a standardized protocol, such as the Hyper-Text Transfer Protocol (HTTP) standard.

A REST API based on the HTTP standard leverages five main HTTP methods to retrieve and manipulate data. Each method corresponds to a create, read, update, delete (CRUD) operation.

**HTTP Methods Corresponding to CRUD Operations**
| HTTP Method | CRUD Functionality | Database Action      |
| :---------: | :----------------: | :------------------: |
| GET         | Read               | Retrieve Data        |
| POST        | Create             | Add Data             |
| PUT         | Update             | Modify Existing Data |
| PATCH       | Update             | Modify Existing Data |
| DELETE      | Delete             | Delete Existing Data |


### What is the Difference Between PUT and PATCH?

`PATCH` replaces part of the data, and `PUT` replaces the whole thing. For example, when updating a user profile, `PUT` completely replaces the profile in the database, whereas `PATCH` changes a few Profile fields.

The Express Recipes API will support the following RESTful endpoints:

**Supported RESTful Endpoints**
| HTTP Method | Path               | Action                                                         |
| :---------: | :----------------: | :------------------------------------------------------------: |
| GET         | /api/v1/recipes    | Read information about all recipes                             |
| POST        | /api/v1/recipes    | Create a new recipe                                            |
| GET         | /api/v1/recipes/1  | Read information about the recipe with ID of `1`               |
| PUT         | /api/v1/recipes/1  | Update the existing recipe with ID of `1` with all new content |
| DELETE      | /api/v1/recipes/1  | Delete the existing recipe with ID of `1`                      |

  > **Note**: It's a best preactice to version the endpoints (`/api/v1`) so that we can maintain compatibility with older services while continuing to improve the API.

## JavaScript Object Notation (JSON)

Let's review what JSON is. HTTP sends data as strings. However, we often want to pass structured data, such as arrays and objects, between web applications.

In order to do so, native data structures are serialized. They're converted from a JavaScript object into a string representation of the data (serialization), using the JavaScript Object Notation (JSON) format.

This JSON string can be transmitted over the internet and the parsed back into data (deserialized) once it reaches its destination, the browser.

Since JSON is easy to read, lightweight, and easy to parse, it has become a universal standard for transmitting data across the web.

Here is a JSON example:

```json
{
  "owners": [
    { "name": "Hou", "id": 1 },
    { "name": "Tim", "id": 2 }
  ],
  "restaurantLocation": "This is a an address"
}
```

## Task 10: Remove Test Code from `src/index.js`

Remove unneeded code:

```js
const express = require("express");
const path = require('path');

const app = express();

app.use((req, res, next) => {
  const { method, path } = req;
  console.log(
  `New request to: ${method} ${path} at ${new Date().toISOString()}`
  );
  next();
});

//const publicDirectoryPath = path.join(\_\_dirname, './public');
//app.use(express.static(publicDirectoryPath));

//app.get("/", (req, res) => {
//res.send("Hello Express Student!");
//});

//app.get("/:name", (req, res) => {
//  res.send(`Welcome to Express Recipes, ${req.params.name}!`);
//});

const port = process.env.PORT || 8080;

app.listen(port, () => {
  console.log(`Server is up on port ${port}.`);
});
```

## Task 11: Use the `express.Router` Class to Create Modular Route Handlers

1. Right now, the `src/index.js` file is pretty cluttered since it includes all the code needed for server setup and initialization, middleware processing, and route handling.

To maintain better separation of concerns and modularity in the codebase, let's move the API routing logic to a separate folder called `routers` inside the `src` folder:

```bash
mkdir src/routers
touch src/routers/recipes.js
```

2. Inside `src/routers/recipes.js`, create a `router` instance and export the module:

```js
const express = require('express');

const router = express.Router();

// Add route handlers here later

// Export the router
module.exports = router;
```

The `express.Router()` creates a `router` instance, which is like a mini Express application that runs its own complete middleware and routing system. It's responsible for routing a single given API resource, such as the `recipes` data. This `router` module can be attached to the main Express application defined in `src/index.js`. If our API needs to manage multiple resources, then we can create multiple `router` instances to manage the routing for each resource.

3. Inside `src/index.js`, load the `router` module at the top and mount the recipes `router` at the `/api/v1/recipes`:

```js
const express = require('express');
const path = require('path');

const recipeRouter = require('./routers/recipes');

app.use((req, res, next) => {
  const { method, path } = req;
  console.log(
  `New request to: ${method} ${path} at ${new Date().toISOString()}`
  );
  next();
});

app.use('/api/v1/recipes', recipesRouter);

const port = process.env.PORT || 8080;

app.listen(port, () => {
  console.log(`Server is up on port ${port}.`);
});
```

The middleware `app.use('/api/v1/recipes', recipesRouter)` will route any path matching `/api/v1/recipes` to the `recipesRouter`.

## Task 12: Implement a Route Handler for `GET` `/api/v1/recipes/`

Keep in mind that after an incoming request has been matched to a `controller`, the `controller` will call the appropriate method from the `service` layer to interact with the database. So, we'd need to implement the `controller` and `service` layers next.

1. For simplicity, let's store the API data in a JSON file. Create a folder called `db` in the project root. Inside the `db` folder, create a new file called `recipes.json`.

2. The API relies on the `fs.promises` API to perform CRUD operations on the recipes data. Here is the starter dataset for the Express Recipes API.

```json
[
  {
    "id": 1,
    "name": "Chicken Vesuvio",
    "healthLabels": ["Sugar-Conscious", "Peanut-Free", "Tree-Nut-Free"],
    "cookTimeMinutes": 60,
    "prepTimeMinutes": 10,
    "ingredients": [
      "1/2 cup olive oil",
      "5 cloves garlic, peeled",
      "2 large russet potatoes, peeled and cut into chunks",
      "1 3-4 pound chicken, cut into 8 pieces (or 3 pound chicken legs)",
      "3/4 cup white wine",
      "3/4 cup chicken stock",
      "3 tablespoons chopped parsley",
      "1 tablespoon dried oregano",
      "Salt and pepper",
      "1 cup frozen peas, thawed"
    ]
  },
  {
    "id": 2,
    "name": "Burnt-Scallion Fish",
    "healthLabels": [
      "Sugar-Conscious",
      "Peanut-Free",
      "Tree-Nut-Free",
      "Alcohol-Free",
      "Immuno-Supportive"
    ],
    "cookTimeMinutes": 60,
    "prepTimeMinutes": 20,
    "ingredients": [
      "2 bunches scallions",
      "8 tbsp. butter",
      "2 8-oz. fish filets"
    ]
  },
  {
    "id": 3,
    "name": "Salted Duck Eggs Recipe",
    "healthLabels": [
      "Sugar-Conscious",
      "Vegetarian",
      "Peanut-Free",
      "Tree-Nut-Free",
      "Alcohol-Free",
      "Immuno-Supportive"
    ],
    "cookTimeMinutes": 120,
    "prepTimeMinutes": 30,
    "ingredients": [
      "2 1/2 quarts water",
      "3 cups kosher salt",
      "One dozen (12) duck eggs"
    ]
  },
  {
    "id": 4,
    "name": "Chocolate Covered Chocolates Recipe",
    "healthLabels": [
      "Vegetarian",
      "Peanut-Free",
      "Tree-Nut-Free",
      "Alcohol-Free"
    ],
    "cookTimeMinutes": 60,
    "prepTimeMinutes": 50,
    "ingredients": [
      "1 cup chocolate morsels (dark, milk, or white)",
      "16-20 chocolate truffles"
    ]
  },
  {
    "id": 5,
    "name": "Roast Goose",
    "healthLabels": [
      "Sugar-Conscious",
      "Peanut-Free",
      "Tree-Nut-Free",
      "Alcohol-Free",
      "Immuno-Supportive"
    ],
    "cookTimeMinutes": 60,
    "prepTimeMinutes": 25,
    "ingredients": [
      "1 goose, 10-12 lbs (see note)",
      "-- kosher salt and pepper"
    ]
  },
  {
    "id": 6,
    "name": "Frog Legs with Garlic and Parsley",
    "healthLabels": [
      "Sugar-Conscious",
      "Tree-Nut-Free",
      "Alcohol-Free",
      "Immuno-Supportive"
    ],
    "cookTimeMinutes": 15,
    "prepTimeMinutes": 10,
    "ingredients": [
      "1 dozen frog legs",
      "Salt and freshly ground black pepper",
      "Flour, preferably Wondra",
      "Peanut oil",
      "1 teaspoon garlic, chopped",
      "2 tablespoons parsley, coarsely chopped",
      "1 tablespoon sweet butter",
      "A dash of lemon juice"
    ]
  },
  {
    "id": 7,
    "name": "Royal Blueberry Ice Pops",
    "healthLabels": [
      "Vegetarian",
      "Peanut-Free",
      "Tree-Nut-Free",
      "Alcohol-Free"
    ],
    "cookTimeMinutes": 243,
    "prepTimeMinutes": 15,
    "ingredients": [
      "2 1/2-pint baskets fresh blueberries, rinsed, drained",
      "1 8-ounce container blueberry yogurt",
      "1/4 cup water",
      "1/4 cup honey",
      "2 tablespoons sugar"
    ]
  },
  {
    "id": 8,
    "name": "Chili Cheese Dog Grilled Cheese Recipe",
    "healthLabels": [
      "Sugar-Conscious",
      "Peanut-Free",
      "Tree-Nut-Free",
      "Alcohol-Free"
    ],
    "cookTimeMinutes": 20,
    "prepTimeMinutes": 10,
    "ingredients": [
      "2 tablespoons butter, cut into three even pieces",
      "1 hot dog, cut into 4 thin slices lengthwise",
      "2 slices hearty white bread, such as Pepperidge Farm or Arnold",
      "2 slices American, Cheddar, or Jack cheese",
      "1/2 cup your favorite chili",
      "Kosher salt"
    ]
  },
  {
    "id": 9,
    "name": "Pandan Wrapped Roast Pork",
    "healthLabels": [
      "Sugar-Conscious",
      "Peanut-Free",
      "Tree-Nut-Free",
      "Alcohol-Free"
    ],
    "cookTimeMinutes": 60,
    "prepTimeMinutes": 60,
    "ingredients": [
      "14 pandan (screw pine) leaves",
      "4 lbs pork butt or other well marbled cut of pork cut into large chunks",
      "smoked sea salt"
    ]
  },
  {
    "id": 10,
    "name": "Roast Beef",
    "healthLabels": [
      "Sugar-Conscious",
      "Peanut-Free",
      "Tree-Nut-Free",
      "Alcohol-Free"
    ],
    "cookTimeMinutes": 127,
    "prepTimeMinutes": 20,
    "ingredients": [
      "8-lb. shell roast of beef",
      "Coarse salt and freshly ground black pepper"
    ]
  }
]
```

3. Inside the `src` folder, create a folder called `services`. Within the `services` folder, create a file called `recipes.js`. Then add the code:

```js
const fs = require('fs').promises;
const path = require('path');

const recipesFilePath = path.join(__dirname, '../../db/recipes.json');

const getAll = async () => JSON.parse(await fs.readFile(recipesFilePath));

module.exports = {
  getAll,
};
```

**Line 1** imports the `fs` methods that return promise objects so that we can use the `async/await` pattern in our `service` later. The `getAll()` method reads, parses, and returns the contents of the `db/recipes.json` file.

4. Inside the `src` folder, create a folder called `controllers`. Within it, create a file called `recipes.js`. Implement the `getAll` route handler inside this file:

```js
const service = require('../services/recipes');

const getAll = async (req, res, next) => {
  try {
    res.json({ data: await service.getAll() });
  } catch (error) {
    next(error);
  }
};

module.exports = {
  getAll,
};
```

Note that the route handler is passed a `next` argument, which can be used to handle errors caught in the `try`/`catch` block. We'll handle these errors later.

5. Back in the recipes `router`, import and mount the `router` handler on the `/` path, like in the following code:

```js
const express = require('express');
const router = express.Router();

const { getAll } = require('../controllers/recipes');

router.get('/', getAll);

module.exports = router;
```

6. If we wish to run it on a local machine, we may navigate to `http://localhost:8080/api/v1/recipes`. We should get back an object that contains all the recipes stored in the `data` property.
