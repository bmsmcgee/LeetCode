# Function Signatures and Function Overrides in TypeScript

> Learn TypeScript's strong typing rules for callback functions, multiple function signatures in a single function, and the role of function literals in parameter definitions.

## Function Signatures

TypeScript uses its strong typing rules to ensure that if we define a function that needs a callback function, we can ensure that this function is provided correctly. In order to specify that a function parameter must be a function signature, TypeScript introduces the fat arrow syntax, or `() =>`, to indicate a function signature.

Let's see an example using this syntax as follows:

```ts
// Declare a function "myCallback" that takes a string argument "text" and returns nothing
function myCallback(text: string): void {
  // Log the message "myCallback called with" followed by the input "text" using template literals
  console.log(`myCallback called with ${text}`);
}

// Declare a function "withCallbackArg" that takes two arguments:
// - "message" of type string
// - "callbackFn" of type function that takes a string argument and returns nothing
function withCallbackArg(
 message: string,
 callbackFn: (text: string) => void
) {
  // Log the message "withCallback called, message :" followed by the input "message" using template literals
  console.log(`withCallback called, message : ${message}`);
  // Call the callback function "callbackFn" with the message "message + " from withCallback" as an argument
  callbackFn(`${message} from withCallback`);
}
```

We define a strongly typed function named `myCallback` that has a single parameter named `text`, which is of type `string`, and returns `void`.

We then define a strongly typed function named `withCallbackArg` that also has two parameters. The first parameter is named `message` and is of type `string`, and the second parameter, named `callbackFn` on **line 12**, is using the fat arrow syntax, as follows:

```ts
callbackFn: (text: string) =>
```

This syntax defined the `callbackFn` parameter as being a function that accepts a single parameter of type `string`, and returns `void`.

We can then use this `withCallbackArg` function as follows:

```ts
// Declare a function "myCallback" that takes a string argument "text" and returns nothing
function myCallback(text: string): void {
  // Log the message "myCallback called with" followed by the input "text" using template literals
  console.log(`myCallback called with ${text}`);
}

// Declare a function "withCallbackArg" that takes two arguments:
// - "message" of type string
// - "callbackFn" of type function that takes a string argument and returns nothing
function withCallbackArg(
 message: string,
 callbackFn: (text: string) => void
) {
  // Log the message "withCallback called, message :" followed by the input "message" using template literals
  console.log(`withCallback called, message : ${message}`);
  // Call the callback function "callbackFn" with the message "message + " from withCallback" as an argument
  callbackFn(`${message} from withCallback`);
}

withCallbackArg("initial text", myCallback);
withCallbackArg("text", "this is not a function");
```

Output ("initial text", myCallback):

```
withCallback called, message : initial text
myCallback called with initial text from withCallback
```

Output ("text", "this is not a function"):

```
index.ts(21,25): error TS2345: Argument of type 'string' is not assignable to parameter of type '(text: string) => void'.
```

We invoke the `withCallbackArg` function twice: once legitimately, by providing a string and a function as arguments on **line 20**, and once in error, by providing two strings as arguments on **line 21**.

We can clearly see that the compuler will not allow us to invoke the `withCallbackArg` function if we do not provide the second argument as a function with a signature that matches our function definition.

This is a very powerful feature of TypeScript. With its strong typing rules, it is preventing us from providing callback functions that do not conform to the correct function signature. Again, this helps to catch errors at the time of compilation and not further down the line when the code needs to be actually run and tested.

## Function Overrides

TypeScript provides an alternative to union types when defining a function and allows a function signature to provide different parameter types.

Consider the following code:

```ts
// The function add has two different function signatures, each with different parameter types and return types.
function add(a: string, b: string): string;
function add(a: number, b: number): number;

// The implementation of the function add takes two parameters of any type and returns their sum.
function add(a: any, b: any) {
  return a + b;
}

// Calling the add function with different parameters
add("first", "second");
add(1, 2);
```

- We define a function definition named `add` on **line 2** that accepts two parameters, named `a` and `b`, which are both of type `string`, and returns a string.
- We then define another function with the same name, `add` on **line 3**, that accepts two parameters named `a` and `b` that are of type `number`, which returns a number.
- Finally, on **lines 6-8**, we define a function, again with the name of `add`, that accepts two parameters named `a` and `b` but are of type `any`. This function definition also provides a function implementation, which simply returns the addition of the `a` and `b` arguments. This technique is used to provide what are known as function overrides.

We can call this function with two arguments of type `string`, or two arguments of type `number`, as follows:

```ts
// Calling the add function with different parameters
add("first", "second");
add(1, 2);
add(true, false);
```

We invoke the `add` function with three types of arguments:
  - Firstly, we invoke it with two arguments of type `string` on **line 11**.
  - Secondly, we invoke it with two arguments of type `number` on **line 12**.
  - Thirdly, we invoke the `add` function with two arguments of type `boolean` on **line 13**.

We can see that the only valid function signatures are where the arguments `a` and `b` are both of type `string` or where the arguments `a` and `b` are both of type `number`.

Even though our final function definition uses the type of `any`, this function definition is not made available and is simply used for the function implementation. We, therefore, can't invoke this function with two `boolean` arguments because the error shows.

## Literals

TypeScript also allows us to use what are known as **literals**, which are almost a hybrid of `enums` and type aliases. A literal will imit the allowed values to a set of values specified. A literal can be made of `string`, `number`, or `boolean` values.

Consider the following code:

```ts
// Define a literal `AllowedStringValues` that can be either "one", "two", or "three".
type AllowedStringValues = "one" | "two" | "three";

// Define a literal `AllowedNumericValues` that can be either 1, 20, or 65535.
type AllowedNumericValues = 1 | 20 | 65535;

// The `withLiteral` function takes a parameter `input` of the union type `AllowedStringValues | AllowedNumericValues`.
function withLiteral(input: AllowedStringValues | AllowedNumericValues) {
  // Logs the string representation of `input` to the console.
  console.log(`called with : ${input}`);
}
```

- We define a literal named `AllowedStringValues` on **line 2** as well as a literal named `AllowedNumericValues` on **line 5**.

> **Note:** The syntax used for literals is very similar to the syntax of a type alias where we use the `type` keyword followed by a set of allowed values. Unlike type aliases, however, we are not specifying a set of different types. We are specifying a set of allowed values, which is similar in concept to an `enum`.

- We then have a function named `withLiteral` on **lines 8-11** that accepts a single parameter of type `AllowedStringValues` or of type `AllowedNumericValues`.

This function simply logs the value of the input argument to the console.

We can now use this function as follows:

```ts
// Define a type `AllowedStringValues` that can be either "one", "two", or "three".
type AllowedStringValues = "one" | "two" | "three";

// Define a type `AllowedNumericValues` that can be either 1, 20, or 65535.
type AllowedNumericValues = 1 | 20 | 65535;

// The `withLiteral` function takes a parameter `input` of the union type `AllowedStringValues | AllowedNumericValues`.
function withLiteral(input: AllowedStringValues | AllowedNumericValues) {
  // Logs the string representation of `input` to the console.
  console.log(`called with : ${input}`);
}

// Calls the `withLiteral` function with different arguements
withLiteral("one");
withLiteral("two");
withLiteral("three");
withLiteral(65535);
withLiteral("four");
withLiteral(2);
```

We are invoking the `withLiteral` function with six values:
  - `"one"`
  - `"two"`
  - `"three"`
  - `65535`
  - `"four"`
  - `2`

Our literals, however, will only allow the values of `"one"`, `"two"`, `"three"`, `1`, `20`, and `65535`.

As such, **lines 18 and 19** of this code will generate errors. These error messages are generated because our literals do not allow the value `"four"` or the value `2` to be used.

> **Note:** Literals provide us with another tool that we can use when we need to define a function that accepts a standard `string`, `number`, or `boolean`, but where we need to limit the values provided to a defined set of values.