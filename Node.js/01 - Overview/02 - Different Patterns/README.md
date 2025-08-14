# Different Patterns in Node.js

## Node.js Motivation

Before Node.js, there were significant issues with popular servers, which made it difficult to create scalable applications.

For example, the Apache HTTP Server had trouble handling a high volume of concurrent requests. It would create a separate thread for each network request, which lef to remendous resources consumed during increased website traffic periods. An increase in traffic beyond the server's capacity would cause Apache to start dropping additional requests, leading to a poor customer experience.

The Apache HTTP Server also implemented blocking code, which meant a program had to wait for a current task to finish and release its resources before proceeding with the next task.

Node.js was created to solve these problems.

## Blocking Code

To understand why Node.js is an excellent choice for creating scalable network applications, we must first understand blocking and non-blocking code as they relate to Node.js' I/O operations.

I/O stands for "input/output", whihc is needed whenever a Node.hs application is communiating with the server it's running on (for example, reading some data from a file on the file system) or some other server (like querying the database or reading from the network).

Blocking methods execute synchronously. Suppose an application has the following code to read a file:

```js
// Load the file system module
const fs = require("fs");

// While waiting for the file to be read, can't do anything else!
const data = fs.readFileSync("/file.md", "utf-8");
console.log(data);

// Will only run after the console.log on the previous line
doMoreStuff();
```

The example above is synchronous.

The `const data = fs.readFileSync("/file.md", "utf-8");` line will block the execution of any additional JavaScript, like `doMoreStuff()`, until the entire `/file.md` file is read.

If an error is thrown, it will need to be caught, or the process will crash.

While separate threads could handle multiple tasks concurrently, spawning a new thread for each task is expensive in terms of memory and CPU usage. As the number of threads increase, so does memory usage. Multithreaded applications also result in increased complexity, such as multiple threads accessing shared data.

## Non-Blocking Code

Non-blocking methods execute asynchronously.

Here is the asynchronous version of the file read operation from the previous section:

```js
// Load the file system module
const fs = require("fs");

// Pass a callback function as a third argument
fs.readFile("/file.md", "utf-8", (err, data) => {
  if (err) throw err;
  console.log(data);
});

// Will run before console.log
doMoreStuff();
```

In the asynchronouse version, we see the following:
  - The `fs.readFile()` method is non-blocking, so JavaScript execution can continue, and `doMoreStuff()` will be called before `fs.readFile()` has finished running.
  - We can pass a callback as a third argument to `fs.readFile()`. This vallback function gets sent to a callback queue. The callback function only gets invoked when the file read is finished.
    - This ability to register a callback in an asynchronous call is what makes Node.js event driven.
    - We can handle any errors in the callback. The first argument of this callback gives us access to the error object (i.e., error-first callback).
