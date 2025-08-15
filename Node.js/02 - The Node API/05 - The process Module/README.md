# The `process` Module

## Overview

The `process` object provides information about the current Node.js process and allows the program to interact with it.

The `process` is a global object, so it can be accessed anywhere inside our Node.js applications without using `require()`.

We'll look at a few common `process` properties, such as `.argv` and `.env`.

## Access CLI Arguments

The `process.argv` property allows us to access the values passed into the aplication from the command line. It stores the values in an array.

1. Add the following code to the `process.js` file:

   ```js
   const name = process.argv[2];
   console.log(process.argv);
   console.log(`Hi, I'm ${name}!`);
   ```

2. In the `nodejs-api` folder, run `process.js`, passing in any name as an argument

   <img width="1003" height="523" alt="image" src="https://github.com/user-attachments/assets/456585f3-766a-4e0b-bfa5-fad1c245ee6e" />

  > The `argv` property consists of an array of all the command line invocation arguments. The first element, `process.argv[0]`, is the full path of the node command. The second element, `process.argv[1]`, is the full path of the file being execute. The third element and beyond consist of the additional arguments passed from the command line. Node.js accepts any number of arguments from the command line.

3. Try passing in a `location` argument. To do this replace the code in `process.js` file with the following:

   ```js
   const name = process.argv[2];
   console.log(process.argv);
   const location = process.argv[3];
   console.log(`Hi, I'm ${name}! I live in ${location}`);
   ```

4. Run the command with two arguments

   <img width="1047" height="567" alt="image" src="https://github.com/user-attachments/assets/34e7a79d-c0ec-4c66-92d9-072e727c1270" />

## Access Node.js Environment Variables

Environment variables allow us to configure our applications in different environments. For example, we could set an environment variable to connect our test server to the test database. In Node.js, these variables can be accessed via `process.env`.

1. To lof the `process.env` property to the console, add the following line to the `process.js` file

   ```js
   console.log('process.env:', process.env);
   ```

   > This logs an object containing all the environment variables for the Node.js process.

2. Log `process.env.NODE_ENV` to the console:

   ```js
   console.log('process.env.NODE_ENV: ', process.env.NODE_ENV);
   ```

   > Should get `process.env.NODE_ENV: undefined`.

3. Set a custom environment variable from the command line:

   ```bash
   NODE_ENV=development node process.js Brandon Calgary
   ```

   <img width="1047" height="567" alt="image" src="https://github.com/user-attachments/assets/5dc15c45-8ca4-4f86-80a3-af534667c31b" />
