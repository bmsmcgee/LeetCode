# JavaScript Functions

## ES6 Functions: Arrow Functions

Arrow functions were introduced in ES6. They provide a simpler syntax for creating functions and more intuitive handling.

See example below, which uses an ES5 function expression syntax:

```js
var printName = function(firstName, lastName) {
  return `${firstName}${lastName}`;
};

output = printName("educative.","io");
console.log(output);

/*Output

educative.io

*/
```

To convert the `printName()` function to use the ES6 arrow syntax, we'll have to follow two steps:
  1. Drop the function keyword.
  2. Add a fat arrown between the parentheses and opening curly brace.

The resulting cuntion will look like this:

```js
const printName = (firstName, lastName) => {
  return `${firstName}${lastName}`;
};

output = printName("educative.","io");
console.log(output);

/*Output

educative.io

*/
```

If our function immediately returns a value, the curly braces that wrap the function body and return statements aren't needed. The value is implicitly returned.

Here's the shorthand we can use:

```js
const printName = (firstName, lastName) => `${firstName}${lastName}`;

output = printName("educative.","io");
console.log(output);

/*Output

educative.io

*/
```

## Default Parameters

JavaScript function parameters default to `undefined`. If we want to set a different default value, we can specify default parameters when we define our function. Default parameters allow named parameters of a function to be initialized with default values if no value or `undefined` is passed during function invocation. 

See code below for example:

```js
function add(a, b = 1) {
  return a + b;
}

console.log(add(5, 2));  // 7

console.log(add(5));  // 6
```

Here is another example:

```js
function greeting(name = "Jane", greeting) {
  return `${greeting}, ${name}!`;
}

console.log(greeting("john", "Good morning"));  // Good morning, John!

console.log(greeting(undefined, "Good afternoon"));  // Good afternoon, Jane!
```

In regular functions, the `this` keyword represents the object that called the function, which could be the window, the document, a button, and so on. In arrow functions, there's no binding of `this`. With arrow functions, the `this` keyword always represents the object that defined the arrow function.
