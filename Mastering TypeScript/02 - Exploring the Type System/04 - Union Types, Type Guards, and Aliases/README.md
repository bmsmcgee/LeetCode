# Union Types, Type Guards, and Aliases

> Learn to combine types and understand type guards and aliases.

## Introduction to Unions

TypeScript allows us to express a type as a combination of two or more other types. These types are known as union types, and they uses the pipe symbol (`|`) to list all of the types that will make up this new type.

Consider the following code:

```ts
// Declare a function called printObject that takes in a parameter called obj with a type of string or number
function printObject(obj: string | number) {
  // Log the value of obj
  console.log(`obj = ${obj}`);
}

// Call printObject with a number value
printObject(1);

// Call printObject with a string value
printObject("string value");
```

Output:

```
obj = 1
obj = string value
```

- We define a function named `printObject` on **line 2** that has a single parameter named `obj`.
- On **lines 8** and **11**, we call the function `printObject` with a number and then with a string, respectively.

## Type Guards

When working with union types, the compiler will still apply its strong typing rules to ensure type safety.

Consider the following code:

```ts
// Declare a function called addWithUnion that takes in two parameters, arg1 and arg2, with types of string or number
function addWithUnion(
  arg1: string | number,
  arg2: string | number
) {
  // Return the sum of arg1 and arg2
  return arg1 + arg2;
}
```

Output:

```
index.ts(7,10): error TS2365: Operator '+' cannot be applied to types 'string | number' and 'string | number'.
```

- We define a function named `addWithUnion` on **lines 2 &mdash; 5** that accepts two parameters and returns their sum. The `arg1` and `arg2` parameters are union types and can therefore hold either a `string` or a `number`.

Unfortunately, this code will generate an error when we run it.

What the compiler is telling us here is that it can't tell what type it should use when it attempts to add `arg1` to `arg2`.

Is it supposed to add a `string` to a `number` or a `string` to a `string`? This is where type guards come in.

A **type guard** is an expression that performs a check on our type and then guarentees that type within its scope. Refactoring the previous function with a type guard:

```ts
// Declare a function called addWithTypeGuard that takes in two parameters, arg1 and arg2, with types of string or number
function addWithTypeGuard(
  arg1: string | number,
  arg2: string | number
) {
  // Check if arg1 is a string
  if (typeof arg1 === "string") {
    // If it is, log that it is a string and return the sum of arg1 and arg2 as a string
    console.log(`arg1 is of type string`);
    return arg1 + arg2;
  }
  // Check if both arg1 and arg2 are numbers
  if (typeof arg1 === "number" && typeof arg2 === "number") {
    // If they are, log that they are numbers and return the sum of arg1 and arg2 as a number
    console.log(`arg1 and arg2 are numbers`);
    return arg1 + arg2;
  }
  // If arg1 and arg2 are not both numbers, log that they are being treated as strings and return their concatenation as a string
  console.log(`default return treat both as strings`)
  return arg1.toString() + arg2.toString();
}
```

- We add two `if` statements within the body of our code. The `if` statement on **line 7** uses the JavaScript `typeof` keyword to test what type the `arg1` argument is. The `typeof` operator will return a string depending on what the value of the argument is at runtime. This can be one of the following possible values: `"number"`, `"number"`, `"string"`, `"boolean"`, `"object"`, or `"undefined"`.
- If the type of the `arg1` argument is a string, then the first code block (**lines 9 &mdash; 11**) will execute. Within this code block, the compiler knows that `arg1` is of type `string`, and will therefore treat `arg1` to be of type `string` within the code block. Our type guard, therefore, is the code block after the check for the type of string.
- The second `if` statement in our code, on **line 13**, has two `typeof` checks and is checking whether both the `arg1` and `arg2` arguments are of type `number`. If they are both numbers, then both `arg1` and `arg2` are treated as type `number` within the code block. This type guard, therefore, will treat both the `arg1` and `arg2` arguments as type `number` within this code block.

Let's test the function:

```ts
// Declare a function called addWithTypeGuard that takes in two parameters, arg1 and arg2, with types of string or number
function addWithTypeGuard(
  arg1: string | number,
  arg2: string | number
) {
  // Check if arg1 is a string
  if (typeof arg1 === "string") {
    // If it is, log that it is a string and return the sum of arg1 and arg2 as a string
    console.log(`arg1 is of type string`);
    return arg1 + arg2;
  }
  // Check if both arg1 and arg2 are numbers
  if (typeof arg1 === "number" && typeof arg2 === "number") {
    // If they are, log that they are numbers and return the sum of arg1 and arg2 as a number
    console.log(`arg1 and arg2 are numbers`);
    return arg1 + arg2;
  }
  // If arg1 and arg2 are not both numbers, log that they are being treated as strings and return their concatenation as a string
  console.log(`default return treat both as strings`)
  return arg1.toString() + arg2.toString();
}

console.log(` "1", "2" = ${addWithTypeGuard("1", "2")}`);
console.log(` 1 , 2 = ${addWithTypeGuard(1, 2)}`);
console.log(` 1 , "2" = ${addWithTypeGuard(1, "2")}`);
```

Output:

```
arg1 is of type string
 "1", "2" = 12
arg1 and arg2 are numbers
 1 , 2 = 3
default return treat both as strings
 1 , "2" = 12
 ```

 We call the `addWithTypeGuard` function three times: once with both arguments of type `string`, once with both arguments of type `number, and the third time with a `number` and a `string`:
  - on **line 23**, we call the `addWithTypeGuard` function with both arguments of type `string`. The code identifies the first argument as being of type `string` and, therefore, enters the first `if` statement block on **line 7**. The concatenation of the string `"1"` with the string `"2"` results in the string `"12"`.
  - On **line 24**, we call the `addWithTypeGuard` function with both arguments of type `number`. Our code identifies both arguments as numbers on **line 13** and, as such, adds the value `1` and the value `2`, resulting in `3`.
  - Finally, on **line 25**, we call the `addWithTypeGuard` function with a `number` and a `string`. The code, therefore, falls through to our default code on **line 20** and treats both arguments as strings.

## Type Aliases

TypeScript introduces the concept of a type alias, where we can create a named type that can be used as a substitute for a type union.

Type aliases can be used wherever normal types are used and are denoted by using the `type` keyword, as follows:

```ts
// Define a type alias for a string or number
type StringOrNumber = string | number;

// Declare a function that takes two arguments, both of type 'StringOrNumber'
function addWithTypeAlias(
  arg1: StringOrNumber,
  arg2: StringOrNumber
) {
  // Convert both arguments to strings and return the concatenation
  return arg1.toString() + arg2.toString();
}
```

- We define a type alias on **line 2** named `StringOrNumber` by using the `type` keyword and assigning a type union of `string` or `number` to it.
- We then use this `StringOrNumber` type in our function definition for the `addWithTypeAlias` function on **lines 5 &mdash; 11**.

Type aliases are a handy way of specifying a type union and giving it a name, and they are particularly useful when the type union is used over and over again.