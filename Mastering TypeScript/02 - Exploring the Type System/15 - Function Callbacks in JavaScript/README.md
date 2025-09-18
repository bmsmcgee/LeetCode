# Function Callbacks in JavaScript

> Learn how to use function callbacks by passing them as arguments to other functions.

## Introduction to Function Callbacks

One of the most powerful features of JavaScript, and in fact, the technology that NodeJS was built on, is the concept of callback functions. A callback function is a function that is passed in as an argument to another function and is then generally invoked within the original function. In other words, we are calling a function and telling it to go and do what it needs to do, and when it is finished, to call the function that we have supplied.

## Passing a Function as an Argument

Just as we can pass a value into a function, we can also pass a function into a function as one of its arguments.

This is best illustrated by taking a look at some JavaScript code as follows:

```js
// Declare a callback function called "myCallback" 
var myCallback = function(text) {
    // Log the message "myCallback called with" followed by the input "text"
    console.log("myCallback called with " + text);
}

// Declare a function "withCallbackArg" that takes two arguments "message" and "callbackFn"
function withCallbackArg(message, callbackFn) {
    // Log the message "withCallback called, message :" followed by the input "message"
    console.log("withCallback called, message : " + message);
    // Call the callback function "callbackFn" with the message "message + " from withCallback" as an argument
    callbackFn(message + " from withCallback");
}

// Call the function "withCallbackArg" with two arguments "initial text" and the callback function "myCallback"
withCallbackArg("initial text", myCallback);
```

Output:

```
withCallback called, message : initial text
myCallback called with initial text from withCallback
```

Here, we start with a function named `myCallback` that accepts a single parameter named text on **line 2**. It simply logs the value of the text argument to the console.

We then define a function named `withCallbackArg` from **lines 8-13**, which has two parameters named `message` and `callbackFn`. This function logs a message to the console using the `message` argument and then invokes the function passed in as the `callbackFn` parameter.

When invoking the function passed in, it invokes it with some text indicating that it was called within the `withCallback` function.

Finally, we invoke the `withCallbackArg` function with two arguments. The first argument is the text string of `"initial text"`, and the second argument is the `myCallback` function itself.

As we can see from the output, the `withCallbackArg` function is being invoked and logging the `"withCallback called, message : initial text:` message to the console. It is then invoking the function that we passed into it as a callback function, which is the `myCallback` function.

Unfortunately, JavaScript can't tell until it executes this code whether the second argument passed into the `withCallbackArg` function is actually a function.

## Passing a `string` as an Argument

Let's test this theory by passing in a `string` for the `callbackFn` parameter instead of an actual function, as follows:

```js
// Declare a callback function called "myCallback" 
var myCallback = function(text) {
    // Log the message "myCallback called with" followed by the input "text"
    console.log("myCallback called with " + text);
}

// Declare a function "withCallbackArg" that takes two arguments "message" and "callbackFn"
function withCallbackArg(message, callbackFn) {
    // Log the message "withCallback called, message :" followed by the input "message"
    console.log("withCallback called, message : " + message);
    // Call the callback function "callbackFn" with the message "message + " from withCallback" as an argument
    callbackFn(message + " from withCallback");
}

withCallbackArg("text", "this is not a function");
```

Output:

```
withCallback called, message : text

/usercode/index.js:12
    callbackFn(message + " from withCallback");
    ^

TypeError: callbackFn is not a function
    at withCallbackArg (/usercode/index.js:12:5)
    at Object.<anonymous> (/usercode/index.js:15:1)
    at Module._compile (internal/modules/cjs/loader.js:778:30)
    at loader (/usr/local/lib/node_modules/babel-register/lib/node.js:144:5)
    at Object.require.extensions.(anonymous function) [as .js] (/usr/local/lib/node_modules/babel-register/lib/node.js:154:7)
    at Module.load (internal/modules/cjs/loader.js:653:32)
    at tryModuleLoad (internal/modules/cjs/loader.js:593:12)
    at Function.Module._load (internal/modules/cjs/loader.js:585:3)
    at Function.Module.runMain (internal/modules/cjs/loader.js:831:12)
    at Object.<anonymous> (/usr/local/lib/node_modules/babel-cli/lib/_babel-node.js:154:22)
```

Here, we are invoking the `withCallbackArg` function on **line 15** with two string values instead of a string value and a function signature, which the function is expecting.

We can see that we have cause a JavaScript runtime exception to occur because the second argument that we passed into the `withCallbackArg` function was not a function; it was just a string.

JavaScript programmers, therefore, need to be carefule when working with callbacks.

The most useful technique for avoiding this sort of runtime error is to check if the argument passed in is actually a function using `typeof`, similar to how we used `typeof` when creating type guards. This leads to a lot of defensive code being written to ensure that when a function is expecting a function to be passed in as a callback, it really is a function before attempting to invoke it.