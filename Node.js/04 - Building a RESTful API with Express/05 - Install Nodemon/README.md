# Install Nodemon

## Nodemon

Enter [Nodemon](https://www.npmjs.com/package/nodemon), a development tool that monitors Node.js applications and automatically restarts the server whenever it detects file changes.

1. Install the `nodemon` package globally

```bash
npm install -g nodemon
```

A _global_ installation is performed using the `-g` flag. Installing a package globally allows it to be used across all Node.js applications. The package won't be included in the project dependency; instead, it will be installed in a global location on the machine.

The `npm root -g` command will tell where that exact location is on the respoective machine.

2. Stop any server that's currently running. Then, start up the Express application with the `nodemon` command:

```bash
nodemon index.js
```

3. Try making a change inside `index.js` - for example, changing the greeting. Check the terminal that's running the server. The server should be restarted automatically...

4. It'd be a hassle to have to remember that long command every time we want to start the server. Let's update the `start` script in the `package.json` file to run this command:

```json
"start": "nodemon src/index.js --ignore ./db"
```

The `--ignore ./db` option tells `Nodemon` to ignore changes to the `/db` folder, which we'll add later. The `./db` folder will contain the API data. By ignoreing changes to the `/db` folder. Nodemon won't restart the server every time data is added, removed, or updated inside the `./db` folder.

We can just run `npm run start` whenever there's a need to `start` the server, where `start` is the name of the script to execute.

## Task 8: Serving Static Assets

Express can serve up all the assets needed for the website, including HTML, CSDS, JavaScript, images, fonts, and more.

We just need to tell Express the path to the directory it should serve. Here are the steps:

1. Create a `public/` folder in our project `root` and add an `index.html` file and a `styles.css` file to it:

```html
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <link rel="stylesheet" href="styles.css" />
    <title>Express Recipes</title>
  </head>
  <body>
    <h1>Welcome to Express Recipes</h1>
  </body>
</html>
```

2. Add the following code in the `express-recipes/public/styles.css` file:

```css
h1 {
  color: blue;
}
```

3. Configure the Express server to serve content stored in the `public/` folder:

```js
const express = require('express');
const path = require('path');

const app = express();

const publicDirectoryPath = path.join(__dirname, './public');
app.use(express.static(publicDirectoryPath));

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

Breaking down the above syntax:
  - First, we import Node.js's [`path`](https://nodejs.org/dist/latest-v11.x/docs/api/path.html) module, which is needed to generate the absolute path to the `public/` folder.
  - Next, we construct the absolute path to the `public/` folder. The call to `path.join` allows us to create an absolute path by combining individual path segments. It combines `__dirname`, which is the directory path for the current script, with the relative path to the `public/` folder. Note that if any site assets aren't in the `public/` folder, then they're not public, and the browser won't be able to load them.
  - Finally, we register a middleware function using `app.use()`. Within `app.use()`, call `express.static()`, which is a built-in middleware function that serves static assets included in the `public/` directory to the client.
