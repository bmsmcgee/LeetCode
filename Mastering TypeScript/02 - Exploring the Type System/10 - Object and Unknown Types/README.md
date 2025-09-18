# `object` and `unknown` Types

> Learn the difference between using the `object` and `unknown` types in TypeScript.

## The `object` Type

TypeScript introduces the `object` type to cover types that are not primitive types. This includes any type that is not `number`, `boolean`, `string`, `null`, `symbol`, or `undefined`.

Consider the following code:

```ts
let structuredObject: object = {
  name: "myObject",
  properties: {
    id: 1,
    type: "AnObject"
  }
};

// Define a function that takes an object as an argument and logs its string representation
function printObjectType(a: object) {
  console.log(`a: ${JSON.stringify(a)}`);
}

printObjectType(structuredObject);
printObjectType("this is a string");
```

Output (structuredObject):

```
a: {"name":"myObject","properties":{"id":1,"type":"AnObject"}}
```

Output ("this is a string"): 

```
index.ts(15,17): error TS2345: Argument of type 'string' is not assignable to parameter of type 'object'.
```

- On **lines 1-7**, we can see that we have a variable named `structuredObject` that is a standard JavaScript object with a `name` property and a nested property named `properties`. The `properties` property has an `id` property and a `type` property. This is a typical nested structure that we find used within JavaScript or a structure returned from an API call that returns JSON. Note that we have explicitly typed this `structuredObject` variable to be of type `object`.
- On **lines 10-12**, we define a function named `printObjectType` that accepts a single parameter, named `a`, which is of type `object`. The function simply logs the value of the `a` parameter to the console. Note, however that we are using the `JSON.stringify` function in order to format the `a` parameter in a human-readable string.
- When we call the `printObjectType` function with the `structuredObject` variable on **line 14** and then attempt to call the `printObjectType` function with a simple string on **line 15**, the code produces an error.

This is because we defined the `printObjectType` function to only accept a parameter of type `object`; we cannot use any other type to call this function. This is due to the fact that `object` is a primitive type, similar to `string`, `number`, `boolean`, `null`, or `undefined`, and as such, we need to conform to standard TypeScript typing rules.

## The `unknown` Type

TypeScript introduces a special type into its list of basic types, which is the type `unknkown`. The `unknown` type can be seen as a type-safe alternative to the type `any`. The difference between the two, however, is that a variable of type `unknown` can't be assigned to a known type without explicit casting.

Let's explore these differences with some code as follows:

```ts
// Declare a variable of type any with a string value
let a: any = "test";

// Declare a variable of type number with a number value
let aNumber: number = 2;

// Attempt to assign a value of type any to a variable of type number
aNumber = a;
```

- On **line 2** of the code, we have defined a variable named `a` that is of type `any`, and set its value to the string `"test"`.
- On **line 5** of the code, we then define a variable named `aNumber`, of type `number`, and set its value to `2`.
- On **line 8**, we assign the value of `a`, which is the string `"test"`, to the variable `aNumber`. This is allowed since we have defined the type of the variable `a` to be of type `any`. Ecen though we have assigned a string to the `a` variable, TypeScript assumes that we know what we are doing, and, therefore will allow us to assign a `string` to a `number`.

Let's refactor this code but use the `unknown` type instead of the `any` type now.

```ts
// Declare a variable of type unknown with a string value
let u: unknown = "an unknown";

// Assign a number value to the unknown type variable
u = 1;

// Declare a variable of type number
let aNumber2: number;

// Assign the value of the unknown type variable to a number type variable
aNumber2 = u;
```

Output:

```
index.ts(11,1): error TS2322: Type 'unknown' is not assignable to type 'number'.
```

In the updated code:
  - We start off by defining a variable named `u` of type `unknown` on **line 2** and set its value to the string `"an unknown"`.
  - On **line 5**, we assign the numeric value of `1` to the variable `u`. This shows that the `unknown` type mimics the behaviour of the `any` type in that it has relaxed the normal strict type-checking rules, and therefore this assignment is allowed.
  - We then define a variable named `aNumber2  of type `number` on **line 8** and then on **line 11** attempt to assign the value of the `u` variable to it. This causes an error, as we can see after running the code.

This is a very interesting error and highlights the differences between the `any` type and the `unknown` type. While the `any` type, in effect, relaxes all type checking, the `unknown` type is a primitive type and follows the same rules that are applied to any of the primitive types, such as `string`, `number`, or `boolean`.

This means that we must cast an `unknown` type to another primitive type before assignment.

We can fix the preceding error as follows:

```ts
// Declare a variable of type unknown with a string value
let u: unknown = "an unknown";

// Assign a number value to the unknown type variable
u = 1;

// Declare a variable of type number
let aNumber2: number;

// Assign the value of the unknown type variable to a number type variable
aNumber2 = <number>u;
```

We have used explicit casting to cast the value of `u` from type `unknown` to type `number`. Since we have explicitly specified that we are converting an `unknown` type to a `number` type, the compiler will allow this. Therefore, no error will be generated.

Using the `unknown` type forces us to make a conscious decision when using these values. In essence, we are letting the compiler know that we know what type this value should be when we actually want to use it.

This is why it is seen as a type-safe version of any, as we need to use explicit casting to convert an `unknown` type into a known type before using it.
