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

## How does JavaScript Run a Callback Function Asynchronously?

JavaScript is able to run a callback function asynchronously because of something running behind the scenes called the **event loop**.

The event loop allows Node.js to perform non-blocking I/O operations. The multithreaded operations are delegated to the system kernel when needed.

This mechanism helps the program invoke the callback function when the main function is finished.

The event loop is neither part of the V8 JavaScript engine nor part of the JavaScript language. It's implemented through a library called `libuv` within Node.js.

## Non-Blocking Code Benefits

Non-blocking paradigms allow Node.js to process other code or make other requests while waiting for a response from some long-running operations, such as network requests.

A Node.js application can handle higher throughput and thousands of concurrent connections while processing multiple requests simultaneously in a single thread without having to create a new thread for every request.

For this reason, Node.js libraries usually are created using non-blocking paradigms.

However, Node.js isn't a suitable choice for CPU-intensive and heavy computing workloads, such as video transcoding, graphics processing, or sorting a billion users. This is because CPU tasks aren't executed asynchronously and will block the single Node.js thread, causing the application to be unresponsive.

## Node.js Case Studies

Here are a few examples of how different companies have used Node.js to scale their applications:
  - Netflix started using Node.js to enable high-volume web streaming for millions of its users to provide them observability, debuggability, and availability. As a result, Netflix developed its NodeQuark infrastructure, which enables the developers to create custom API experiences to run Netflix on different devices seamlessly.
  - Ryan Hillard created an interactive form for the U.S. Small Business Administration using Node.js and other open-source software. The original proposal from an external vendor would have cost $130,000, but Hillard was able to create a solution for $3,000. He gave a talk that describes the technical difficulties he encountered and the way his Node.js solution fixed the problem.
  - The Weather Channel of IBM uses Node.js for its weather forecasting website to deliver information about the weather news and observations to over a billion of its users worldwide.
  - PayPal has been using Node.js for its server-side appplication platform due to its efficient and easily manageable code.
  - LinkedIn has been using Node.hs to manage its users asynchronously. It has resulted in significant performance improvement and reduction of hardware cost.
