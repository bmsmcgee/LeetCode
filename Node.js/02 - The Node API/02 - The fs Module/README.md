# The `fs` Module

## Overview

The `fs` module is a built-in global Node.js module that exposes an API for accessing, manipulating, and interacting with the file system.

We'll use a few methods from the `fs` module to read and write information to `test.txt`.

All `fs` operations are available either in synchronous or asynchronous forms ([click here](https://nodejs.org/api/fs.html#fs_file_system) for details) 

In this section, we'll use a newer feature of `fs`, called the [`fs` Promises API](https://nodejs.org/api/fs.html#fs_fs_promises_api), which returns `Promise` objects so that we can use the `async` and `await` keywords instead of callbacks to handle asynchronicity.

We can access the API by importing it at the top of the file via `require('fs').promises`.

## Load the `fs` Module

The module system uses the `require()` function to load in a module and access its contents.

To load in the `fs` module and get access to its properties and methods, we use `require()` at the top of the `file-system.js` file:

  <img width="1047" height="567" alt="image" src="https://github.com/user-attachments/assets/64c80625-7bc8-44f3-9bf8-a3b4e861f2a0" />

## Inspect File Details

Every file comes with a set of information, such as the size, creation time, and so on, that we can inspect with `fs.stat`. We can use the output of fs.stat()` to perform common programming tasks, such as checking whether or not the path reolves to a file or a directory.

Add the following code right below the `fs` module `require()` function:

  <img width="1047" height="567" alt="image" src="https://github.com/user-attachments/assets/0ec4bec5-c78e-4869-8d29-afb2f7de7892" />

The `getStats()` method accepts a file path as an argument and calls the `fs.stat()` method using the `async/await` pattern. If the `fs.stat()` call is successful, the file stats are logged to the console. Otherwise, an error is logged.

In the `nodejs-api` directory, run the script with the shown command:

  <img width="1047" height="567" alt="image" src="https://github.com/user-attachments/assets/1016000d-3a0f-4571-b6a0-fdf08d7fc676" />

We can call special methods on the `stats` object to obtain further information about the object. For example, `.isFile()` and `.isDirectory()` check whether a given file path leads to a file or a directory, respectively. To better understand how they work, modify `getStats()` as follows:

  <img width="1047" height="567" alt="image" src="https://github.com/user-attachments/assets/c86e0ac3-beb4-4d44-ad73-53f5fd4e8913" />

  <img width="1047" height="567" alt="image" src="https://github.com/user-attachments/assets/ca22576e-78cf-4aca-9262-0c13a82f3a4f" />

We'll see `isFile: true` and `isDirectory: false` logged to the console since `./test.txt` leads to a file.

When we're done, don't forget to comment out `getStats('./test.txt')` so that we can keep the console clear when testing out the remaining `fs` methods.

  <img width="1047" height="567" alt="image" src="https://github.com/user-attachments/assets/eec18f1f-8157-4bea-b666-b9e492a2bd5e" />

## Read the Contents of a File

We can read a file with `fs.readFile()`. This method accepts two arguments:
  - File path
  - Character encoding type (e.g., `utf8`)

Add to the `file-system.js` file:

  <img width="1047" height="567" alt="image" src="https://github.com/user-attachments/assets/4b98b6cf-74ad-48f3-a397-995c0b65baa5" />

Run the script:

  <img width="1047" height="567" alt="image" src="https://github.com/user-attachments/assets/1258badd-1a9f-440e-b7a6-178a45231e5f" />

_Note: There is currently no content written to_ `test.txt`
