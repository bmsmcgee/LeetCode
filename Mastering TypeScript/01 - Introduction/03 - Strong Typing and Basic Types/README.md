# Strong Typing and Basic Types

> Discover the distinction between strong typing in JavaScript and TypeScript and how TypeScript enforces rules for accurately using variables, functions, and objects.

JavaScript is not strongly typed. It is a language that is very dynamic, as it allows objects to change their types, properties, and behaviour on the fly. TypeScript, however, is strongly typed and will enforce rules that govern how we use variables, functions, and objects.

We will start with the concepts of strong typing or static typing, as it is also known. We will then move on to exploring some of the basic types that the language uses and how the language can detect what type a variable is based on how and where it is used within our code. We will then tackle the basics of function signatures and finally see how to import and use third-party JavaScript libraries.

## Strong Typing

**Strong typing** means that when we create a variable or define a parameter in a function, we specify what type it is. Once this type has been specified, we cannot change it. Loose typing is the exact opposite of this concept, and JavaScript is a loosely typed language.

As an example of loose typing in JavaScript, let's take a look at the following code:

```js
// Declare a variable called "test" and initialize it with a string value
console.log("Let's declare the variable 'test' with a string value\n");
var test = "a string";

// Log the value of "test" to the console
console.log("test = " + test);

console.log("\nWe can see the successful assignment of a string type to the 'test' variable.\n");

// Change the value of "test" to an integer
console.log("Now let's assign an integer value to 'test'\n");
test = 1;

console.log("test = " + test);

console.log("\nWe can see the successful assignment of an integer type to the 'test' variable.Notice that the type of the 'test' variable has changed from a string to an integer.\n");

// Change the value of "test" to a function
console.log("Now let's assign a function to 'text'\n");
test = function (a, b) {
  return a + b;
}

console.log("test = " + test + "\n");

console.log("This is how types work in JavaScript: variables can hold values of any data type, and the type of a variable can change during the execution of a program. This is in contrast to strongly-typed languages like TypeScript, in which variables must be explicitly declared with a specific data type and can only hold values of that type.");
```

- On **Line 3** of this code snippet, we declare a local variable named `test` and assign it a `string` value. We then use the `console.log` function to print its value to the console. We display a message indicating that the assignment of a string value to `test` was successful.
- On **line 12**, we assign an integer value of `1` to the `test` variable and print its value to the console. We display a message indicating that the assignment of an integer value to `test` was successful.
- Finally, from **line 24 &mdash; 26**, we assign a function that takes two parameters, named `a` and `b`, to the `test` variable and print its value to the console. We display a message indicating that the assignment of a function to `test` was successful.

When we run the code, we can clearly see the changes that we are making to the `test` variable. It changes from a string value to a numeric value and then finally becomes a function.

Unfortunately, changing the type of a variable at runtime can be a very dangerous thing to do. If our code is expecting a variable to be a number and tries to perform calculations on it, the results of these calculations may be unexpected if the variable held a string.

In a similar way, if a variable is a function that does something, and someone inadvertently changes that variable into a string, a whole block of functionality has suddenly become lost.

TypeScript is a strongly typed language. This means that if we declare a variable to be of type `string`, then we need to treat it as a string throughout or code base.

So, how do we declare that a variable should be of a particular type? Well, TypeScript introduces a simple notation using the colon (`:`) symbol to indicate what type a variable should be, as follows:

```ts
// Declare a variable with the type "string"
var myString: string;

// Assign a value to the "myString" variable
myString = `This is a string`;

// Log the value of "myString" to the console
console.log(`myString = ${myString}`);
```

Here, we can see that we have declared a variable named `myString`, and have followed it with a colon and the `string` keyword before we assign a value. This technique is called **type annotation**, and it sets the type of the `myString` variable to be of type `string`.

If we were to now try and assign a number to it, TypeScript would generate a compilation error as follows:

```ts
// Declare a variable with the type "string"
var myString: string;

// Attempt to assign a value of type "number" to the "myString" variable
myString = 1;

// This assignment will result in an error, because "myString" has been explicitly declared as a string type
// and can only hold values of the string type
```

Here, we have a `TS2322` error, which indicates that the type '1' (which is of type `number`) is not assignable to a variable that has been specified as being of type `string`.

## Basic Typing

TypeScript provides a number of basic types that can be used for type annotation. As an example of these types, let's focus on four common types, namely string, number, boolean, and array. Let's take a look at the following example to see them in action.

```ts
// Declare a string variable named 'myString' and initialize it with the value "Hello"
var myString: string = `Hello`;

// Declare a boolean variable named 'myBoolean' and initialize it with the value true
var myBoolean: boolean = true;

// Declare a number variable named 'myNumber' and initialize it with the valuer 1234
var myNumber: number = 1234;

// Declare an array of strings named 'myStringArray' and initialize it with the values ["first", "second", "third"]
var myStringArray: string[] = [`first`, `second`, `third`];
```

Here, we are declaring four variables using the `var` keyword: `myString`, `myBoolean`, `myNumber`, and `myStringArray`.
  - `myString` is a string vairable initialized with the value `` `Hello` ``.
  - `myBoolean` is a boolean variable initialized with the value `true`.
  - `myNumber` is a number variable initialized with the value `1234`.
  - `myStringArray` is an array of strings initialized with the values `` [`first`, `second`, `third`] ``.

The type of each variable is specified using TypeScript's type annotations, which are added after the variable name and a colon (`:`). For example, the `myString` variable is annotated with the string type, which indicates that it can only hold string values. The `myStringArray` variable is annotated with the `string[]` type, which indicates that it is an array of strings.

