# Generic Syntax

> Learn how to write type-safe code using generics in TypeScript.

Generics, or, more specifically, the generic syntax is a way of writing code that will work with a wide range of objects and primitives.

As an example, suppose that we wanted to write a function that iterates over a given array of objects and returns a concatenation of their values. So, given a list of numbers, say `[1, 2, 3]`, it should return the string `"1, 2, 3"`. Or, given a list of strings, say `["first", "second", "third"]`, it should return the string `"first, second, third"`.

Using generics allows us to write type-safe code that can force each element of the array to be of the same type and, as such, would not allow a mixed list of values to be sent through to our function, say `[1, "second", true]`.

## What is the Generic Syntax?

TypeScript uses an angled bracket syntax and a type symbol, or type substituted name, to indicate that we are using generic syntax.

In other words, to specify that the type named `T` is being used within generic syntax, we will write `<T>` to indicate that this code is substituting a normal type named with the symbol `T`. Then, when we use a generic type, TypeScript will essentially substitute the type named `T` with an actual type.

## How to Use Generic Syntax in TypeScript

This is best explained through some example code, as follows:

```ts
// Define a function named 'printGeneric' that takes in a generic type 'T' as a parameter
function printGeneric<T>(value: T) {
  // Log the type of 'T' and the value of 'value' to the console
  console.log(`typeof T is : ${typeof value}`);
  console.log(`value is : ${value}`);
}
```

- We have a function named `printGeneric` that is using generic syntax and specifying that its type substitute name is named `T` by appending `<T>` to the function name.
- This function takes a single parameter named `value` of the type `T`.

So, what we have done here is replace the type within the function definition, which would normally be `value: string`, or `value: number`, for example, with the generic syntax of `value: T`.

This `printGeneric` function will log the result of the `typeof` operator for the value that was sent in, as well as its actual value.

## Using a Function with Generic Syntax

We can now use the function as follows:

```ts
// Define a function named "printGeneric" that takes in a generic type "T" as a parameter
function printGeneric<T>(value: T) {
  // Log the type of "T" and the value of "value" to the console
  console.log(`typeof T is : ${typeof value}`);
  console.log(`value is : ${value}\n`)
}

// Call the printGeneric function with various argument types

printGeneric(1);
printGeneric("test");
printGeneric(true);
printGeneric(() => { });
printGeneric({ id: 1 });
```

Output:

```
typeof T is : number
value is : 1

typeof T is : string
value is : test

typeof T is : boolean
value is : true

typeof T is : function
value is : () => { }

typeof T is : object
value is : [object Object]
```

Here, we are calling the `printGeneric` function with a wide range of values:
  - The first call is with a numeric value of `1`.
  - The second call is with a string value of `"test"`.
  - The third call is with a boolean value of `true`.
  - We then call the `printGeneric` function with an actual function.
  - The last call is with an object with a single property named `id`.

We can see from the output of the code above, the `printGeneric` function is indeed working with pretty much every type that we can throw at it. The `typeof` operator is identifying what the type of `T` is, either a `string`, `number`, `boolean`, `function`, or `object`, and the value that is logged to the console is correct.

## Explicitly Specifying the Type in Genric Syntax

This is best explained by showing how we can also call this function as follows:

```ts
// Define a function named "printGeneric" that takes in a generic type "T" as a parameter
function printGeneric<T>(value: T) {
  // Log the type of "T" and the value of "value" to the console
  console.log(`typeof T is : ${typeof value}`);
  console.log(`value is : ${value}`)
}

printGeneric<string>("test");
```

Output:

```
typeof T is : string
value is : test
```

- We are using type casting notation to explicitly specify what type we are calling this function with.

> **Note:** Previously, we did not explicitly set the type using this long form notation, but simply called the function with an argument, that is, `printGeneric(1)`. In this instance, TypeScript is inferring the type T to be a number. Note, too, that if we explicitly set the type to be used using this long-form notation, then this will override any usage of the type T, and our normal type rules will apply for any usage of the type T.

Consider the following example:

```ts
// Define a function named "printGeneric" that takes in a generic type "T" as a parameter
function printGeneric<T>(value: T) {
  // Log the type of "T" and the value of "value" to the console
  console.log(`typeof T is : ${typeof value}`);
  console.log(`value is : ${value}`)
}

printGeneric<string>(1);
```

Output:

```
index.ts(8,22): error TS2345: Argument of type 'number' is not assignable to parameter of type 'string'.
```

- We are explicitly specifying that the function will be called with a type `<string>`, but our single argument is actually of the type number. Therefore, the code generates an error.

The error is telling us that we are attempting to call a generic function with the wrong type as an argument, as the type of `T` was explicitly set.

> **Note:** If we do not explicitly specify what type the generic function should use by omitting the `<type>` specifier, the compiler will infer the type to be used from the type of each argument.

## Multiple Generic Types

We can also specify more than one type to be used in a generic function as follows:

```ts
// Define a function using multiple generic types
function usingTwoTypes<A,B> ( first: A, second: B ) {}
```

- We have a function named `usingTwoTypes` that has a type name for both the first and second parameters in this function, `A` and `B`.

This function can specify any type for either `A` or `B` as follows:

```ts
// Define a function using multiple generic types
function usingTwoTypes<A, B> ( first: A, second: B) {}

// Call the usingTwoTypes function with various argument types
usingTwoTypes<number, string> ( 1, "test");
usingTwoTypes(1, "test");
usingTwoTypes<boolean, boolean>(true, false);
usingTwoTypes("first", "second");
```

We are freely mixing the syntax we are using to call the `usingTwoTypes` function.