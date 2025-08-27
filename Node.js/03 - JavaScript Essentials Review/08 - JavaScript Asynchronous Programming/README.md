# JavaScript Asynchronous Programming

## Asynchronous Programming with `async`/`await`

In the not-so-distant past, developers typically relied on promise chains to handle asynchronous logic, which would quickly lead to messy and unreadable code.

The `async`/`await` statements greatly simplify the syntax for making asynchronous calls with JavaScript. They make asynchronous code look like synchronous code.

Functions declared with `async` always return a promise, like in the example below:

```js
const greet = async () => "hello";  // async implicitly wraps 'hello' in a promise
console.log(greet());  // returns a Promise object

greet().then((greeting) => console.log(greeting));  // logs 'hello'

/* Output

Promise { 'hello' }
hello

*/
```

The code above is equivalent to the following:

```js
const greet = async () => Promise.resolve("hello").then(function(value) {
  console.log(value);  // "Success"
}, function(value) {
  // not called
});

console.log(greet());  // returns a Promise object

/* Output

Promise { <pending> }
hello

*/
```

The `await` pauses function execution at the awaited line until the promise is either resolved or rejected with a result. It only works inside `async` functions.

```js
const smileAfterDelay = (delay) => {
  return new Promise((resolve) => {
    setTimeout(() => {
      resolve("😁");
    }, delay);
  });
};

//const smiley = await smileAfterDelay(2000);
//console.log(smiley);

const smileAtMe = async () => {
  const smiley = await smileAfterDelay(3000); // wait on this line until promise is resolved or rejected
  console.log(smiley);
};

smileAtMe(); // 😁 <-- after 3 seconds
```

The function at **line 9** won't work because `await smileAfterDelay()` isn't inside an `async` function. However, if we comment **lines 9** and **10** out, the function at **line 17** would return a 😁 after three seconds.

## Using `async`/`await` with the `fetch()` Method

The built-in JavaScript Fetch API, which is promise-based, is a prime candidate for handling with `async`/`await`.

```js
// ES5
const fetchTrivia = () => {
  fetch(https://opentdb.com/api.php?amount=1&category=18")
  .then((response) => response.json())
  .then((data) => {
    console.log(data.results[0]);
  })
  .catch(console.error);
};

fetchTrivia();
```

The `fetchTrivia()` function performs a `GET` request using `fetch()` to a public API, extracts the information from the returned JSON response, and logs the result to the console. The response is handled by chaining promis methods, such as `,then()` and `.catch()` to the end of the `fetch()` method.

But if an operation depends on multiple API calls, the syntax above quickly results in a `Promise` hell.

ES6 offers a better alternative. Here's the same function written with `async`/`await` in the following code:

```js
// ES6
const fetchTrivia = async () => {
  try {
    const response = await fetch(
      "https://opentdb.com/api.php?amount=1&category=18"
    );
    const data = await response.json();
    console.log(data.results[0]);
  } catch (error) {
    console.error(error);
  }
};
```

Wrapping the `fetch()` call in a `try`/`catch` block allows errors to be handled in the `catch` block.
