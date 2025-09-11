# Project Setup: Part Two

## Task 3: Install Project Dependencies

Install Express for the project as follows:

```bash
npm install express
```

### What does Running the Above Command Create in our Folder?

A new folder called `node_modules` is created. It's the folder where `npm` installs the packages the project needs, such as dependencies.

The `express` package is installed in the current file tree under the `node_modules` subfolder.

As this happens, `npm` also adds the `express` entry in the dependencies property of the `package.json` file present in the current folder.

Finally, a `package-lock.json` file is also created.

  > The goal of the [`package-lock.json`](https://docs.npmjs.com/cli/v8/configuring-npm/package-json) file is to keep track of the exact version of every package that's installed so that a product is 100% reproducible in the same way, even if packages are updated by their maintainers.

To see the latest version of all the `npm` packages installed, including their dependencies, run the following command:

```bash
npm list
```

Running the above commands:

<img width="939" height="434" alt="image" src="https://github.com/user-attachments/assets/0ce1a0df-ba86-4a1e-943b-08176a59c2a3" />

## Task 4: Add a `.gitignore` File

Generated code (`node_modules`) is typically not committed to Git since it could take up a lot of space unnecessarily. Additionally, sensitive environment variables shouldn't be committed to Git. We can add a `.gitignore` file in our root directory to specify which files or folders Git should ignore:

```bash
touch .gitignore
```

Add `node_modules` and `.env` to the `.gitignore` file.

Since the project dependencies aren't committed to the Git repository, we might ask, _"How would other developers get these dependencies when they clone the project to their local machine?"_

Keep in mind `package-lock.json` makes our build reproducible. Another developer could just run `npm install` on their local machine to install the dependencies listed in `package-lock.json`.

In the next section, environment variables will be stored ina  file called `.env`. The `.env` file shoud not ever be committed to the Git repository because it will contain the API's authentication secret and other sensitive credentials. So, `.env` should be listed in the `.gitignore` file.

## Task 5: Create a Basic Express Server

1. Once the `express` package has been installed in `node_modules/` (along with other dependencies), it can be used in the code. Since we'll create multiple server-side files, we can organize the code that we write within a folder called `src` (source). Then, inside of the `src` folder, we create a file called `index.js`:

```bash
mkdir src
touch src/index.js
```

2. Inside `src/index.js`, configure and set up an Express server, like shown:

```js
const express = require('express');

const app = express();

const portt = process.env.PORT || 8080;

app.listen(port, () => {
  console.log(`Server is up on port ${port}.`);
});
```

Let's breakdown the syntax above:
   - **Line 1**: We use the CommonJS `require()` function to import the Express module into the program.
   - **Line 3**: We invoke `express()` to instantiate a new Express application.
   - **Lines 5-9**: We listen on port `8080` for incoming requests and log a message when the server is up and running.

That's all it takes to create a basic Node.js server with Express!

3. To start our server, run:

```bash
node src/index.js
Server is up on port 8080
```

The Node.js process will stay running until we shit it doen. We can always use _CTRL + c_ to terminate the process, stop the server, and regain control of the terminal. If we need to run other CLI commands, we'd have to start a new terminal window.

<img width="936" height="460" alt="image" src="https://github.com/user-attachments/assets/d052d69f-9cee-4fdd-94c3-5b684f01dba2" />
