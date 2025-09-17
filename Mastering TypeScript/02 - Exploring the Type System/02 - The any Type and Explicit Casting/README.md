# The `any` Type and Explicit Casting

> Explore TypeScript's `any` type for fluid variable usage and explicit casting, bypassing strict type rules.

TypeScript allows a simple type annotation syntax. We also know that TypeScript generates JavaScript and, as such, must be able to mimic what JavaScript can do. Unfortunately, matching what JavaScript can do may also include relaxing the strict typing rules and allowing a string value to be assigned to a numeric value, for example.

The `any` type completely removes the strict type rules associated with a variable and allows the fluid and unconstrained use of variables, like in JavaScript. We will also strongly recommend not using the `any` type as much as possible.

## The `any` Type

TypeScript uses the type annotation syntax to define what type a particular variable or function parameter should be. Once we have set a type for a variable, the compiler will ensure that this type is maintained throughout our code base.

Unfortunately, this means that we can't recreate JavaScript where the JavaScript does not match these strict type rules.

Consider the following JS code:

```js
// Declare a variable called item1 with an object literal that has properties id and name
var item1 = { id: 1, name: "item1"};

// Assign a new object literal to item1 with only an id property
item1 = { id: 2 };
```

- We create a variable named `item1` on **line 2** and assign an object value to it that has an `id` and `name` property.
- We then reassign this variable to an object that only has an `id` property on **line 5**.

This is valid JavaScript code, and therefore, if we are using TypeScript to generate JavaScript, we will need to be able to mimic this functionality.

TypeScript introduces the `any` type for such occasions. Specifying that an object has a type of `any` will, in essence, remove the TypeScript strict type checking.

The following TypeScript code shows how to use the `any` type to mimic our original JavaScript code:

```ts
// Declare a variable called item1 with a type of any and assign to it an object literal that has properties id and name
var item1: any = { id: 1, name: "item1" };

// Assign a new object literal to item1 with only an id property
item1 = { id: 1 };
```

- We specify that the type of the `item1` variable is `any` on **line 2**. The `any` type then allows a variable to follow JavaScript's loosely defined typing rules so that anything can be assigned to anything.
- Without the type specifier of `any`, **line 5** of this code snippet would normally generate an error.

While the `any` type is a necessary feature of the TypeScript language and is used for backward compatibility with JavaScript, its usage should be limited as much as possible. As we have seen with untyped JavaScript, excessive use of the `any` type will quickly lead to coding errors that will be difficult to find.

Rather than using the `any` type, let's try to figure out the correct type of the object that we are using and then use that type instead.

Interfaces are a way of defining custom types. Using interfaces allows us to cover almost every possible combination of types, meaning that using the `any` type, in most cases, is unnecessary. We use an acronym within our programmin teams, which is **Simply Find an Interface for the Any Type (A.F.I.A.T.)**, pronounced sveat or sweat. While this may sound rather odd, it simply brings home the point that the `any` type can and should be defined as an interface, so simply find it.

In short, avoid the `any` type at any cost.

## Explicit Casting

As with any strongly typed language, there comes a time when we need to explicitly specify the type of an object. This is generally used when working with object-oriented concepts, such as classes, abstract classes, and interfaces, but this techniqure can bre used on primitive TypeScript types as well.

Let's rewrite the previous example using explicit casting as follows:

```ts
// Declare a variable called item1 and assign to it an object literal that has properties id and name, explicitly specifying its type as any
var item1 = <any>{ id: 1, name: "item1" };

// Assign a new object literal to item1 with only an id property
item1 = { id: 2 };
```

- On **line 2**, we replace the `: any` type specifier on the left-hand side of the assignment operator with an explicit cast of `<any>` on the right-hand side of the assignment operator. This explicit casting technique uses the angled bracket syntax, that is, `<` and `>`, surrounding the name of the type.

In essence, this syntax is equivalent to our earlier example and specifies that the type of the `item1` variable is `any`.

Another variant of this casting technique is to use the `as` keyword as follows:

```ts
// Declare a variable called item1 and assign to it an object literal that has properties id and name, explicitly specifying its type as any using the <any> cast syntax
var item1 = { id: 1, name: "item1" } as any;

// Assign a new object literal to item1 with only an id property
item1 = { id: 2 };
```

- On **line 2**, we define the variable named `item1`, similar to our earlier definitions, but append the keyqord `as` and then name the type that this variable should be treated as, which in this case is `any`.

This example, and the previous example, are equivalent in outcome since the `item1` variable is of type `any` no matter which version of the explicit casting syntax we use. 