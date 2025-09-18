# Definite Assignment

> Learn to handle variable use and definition, including errors and definite assignment assertion syntax.

## Introduction to Definite Assignment

Variables in JavaScript are defined by using the `var` keyword. Unfortunately, the JavaScript runtime is very lenient on where these definitions occur and will allow a variable to be used before it has been defined.

Consider the following JavaScript code:

```js
// This line logs the value of the variable "aValue" to the console, before it has been defined
console.log("aValue = " + aValue);

// This line declares the variable "aValue" and assigns it the value of 1
var aValue = 1;

// This line logs the value of the variable "aValue" to the console, after it has been defined and assigned a value
console.log("aValue = " + aValue);
```

Output:

```
aValue = undefined
aValue = 1
```

We start the code by logging the value of a variable named `aValue` to the console. Note, however, that we only declare the `aValue` variable on **line 5** of the above code snippet.

As we can see from this output, the value of the `aValue` variable before it had been declared is `undefined`. This can obviously lead to unwanted behaviour, and any good JavaScript programmer will check that a variable is not `undefined` before attempting to use it.

If we attempt the same thing in TypeScript:

```ts
// This line logs the value of the variable "lValue" to the console, before it has been defined
console.log(`lValue = ${lValue}`);

// This line declares the variable "lValue" and assigns it the value of 2
let lValue = 2;
```

Output:

```
index.ts(2,25): error TS2448: Block-scoped variable 'lValue' used before its declaration.
```

The compiler is letting us know that we have possible made a logic error by using the value of a variable before we have declared the variable itself.

## A Tricky Scenario

Let's consider a trickier case of where this could happen, where even the compiler can get things wrong, as follows:

```ts
// Declare a variable named "globalString" with the type of "string"
var globalString: string;

// Call the function "setGlobalString" and pass in the argument "this string is set"
setGlobalString("this string is set");

// Log the current value of the "globalString" variable to the console
console.log(`globalString = ${globalString}`);

// Define a function named "setGlobalString" that takes in a parameter named "value" with the type "string"
function setGlobalString(value: string) {
  // Assign the value of the "value" parameter to the "globalString" variable
  globalString = value;
}
```

Output:

```
index.ts(8,31): error TS2454: Variable 'globalString' is used before being assigned.
```

- We start by declaring a variable named `globalString` of type `string` on **line 2**.
- We then call a function named `setGlobalString` on **line 5** that will set the value of the `globalString` variable to the string provided.
- Then, we log the value of the `globalString` variable to the console on **line 8**.
- Finally, we have the definition of the `setGlobalString` function that just sets the value of the `globalString` variable to the parameter named `value`. This looks like fairly simple, understandable code, but it generates an error.

When we run this code, according to the compiler, we are attempting to use the value of the `globalString` variable before it has been given a value. Unfortunately, the compiler does not quite understand that by invoking the `setGlobalString` function, the `globalString` variable will actually have been assigned a value before we attempt to log it to the console.

## Fixing the Error

To cater to this scenario, since the code that we have written will work correctly, we can use the **definite assignment assertion syntax**, which is to append an exclamation mark (`!`) after the variable name that the compiler is complaining about. There are actually two places where we can add it.

### Method #1: Definite assignment where a variable is used

Firstly, we can modify the code on the line where we use this variable for the first time, as follows:

```ts
// Declare a variable named "globalString" with the type of "string"
var globalString: string;

// Call the function "setGlobalString" and pass in the argument "this string is set"
setGlobalString("this string is set");

// Log the current value of the "globalString" variable to the console, using the definite assignment assertion syntax to indicate that the variable has been assigned a value before this point.
console.log(`globalString = ${globalString!}`);

// Define a function named "setGlobalString" that takes in a parameter named "value" with the type "string"
function setGlobalString(value: string) {
  // Assign the value of the "value" parameter to the "globalString" variable
  globalString = value;
}
```

Output:

```
globalString = this string is set
```

We have placed an exclamation mark (`!`) after the use of the `globalString` variable on **line 8**, which has now become `globalString!`. This will tell the compiler that we are overriding its type-checking rules and are willing to let it use the `globalString` variable even though it thinks it has not been assigned.

### Method #2: Definite assignment where a variable is defined

The second place that we can use the **definite assignment assertion syntax** is in the definition of the variable itself, as follows:

```ts
// Declare a variable named "globalString" with the type of "string" and with a definite assignment assertion operator (!) 
var globalString!: string;

// Call the function "setGlobalString" and pass in the argument "this string is set"
setGlobalString("this string is set");

// Log the current value of the "globalString" variable to the console
console.log(`globalString = ${globalString}`);

// Define a function named "setGlobalString" that takes in a parameter named "value" with the type "string"
function setGlobalString(value: string) {
  // Assign the value of the "value" parameter to the "globalString" variable
  globalString = value;
}
```

Output:

```
globalString = this string is set
```

Here, we have used the definite assignment assertion operator on the definition of the variable itself on **line 2**. This will also remove the compilation error.

## Why We Need Definite Assignment

While we do have the ability to break standard TypeScript rules by using definite assignment operators, the most important question is, *"Why?"* Here are some common questions that one must ask:
  - Why do we need to structure our code in this way?
  - Why are we using a global variable in the first place?
  - Why are we using the value of a variable where if we change our logic, it could end up being `undefined`?

It certainly would be better to refactor our code so that we avoid these scenarios.