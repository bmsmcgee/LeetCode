# Introduction to Interfaces

> Learn about some of the common features of object-oriented programming and see how interfaces work in TypeScript

## Object-Oriented Programming in TypeScript

TypeScript brings a variety of language enhancements to modern JavaScript development. This includes the primitive types, like `string`, `number`, `boolean`, `undefined`, and `never`, as well as features brought in from multiple ECMAScript standards, like `let`, `const`, and optional chaining. TypeScript, therefore, allows us to use these enhanced language features from future JavaScript standards in our code right now, and it takes care of generating the correct JavaScript based on our runtime target.

The ECMAScript standard published in 2015, known as ES6, introduced the concept of classes and inheritance. JavaScript programmers, however, have been able to create classes and use object-oriented programming techniques for many years by using what is known as the **closure design pattern** and the **prototype design pattern**. However, the creation of JavaScript objects through closures has been more by convention than being baked directly into the language.

TypeScript has supported the object-oriented concepts of interfaces, classes, and inheritance since its earliest versions. Remember that it generates JavaScript and, as such, is capable of converting the classes that we construct today into older-style JavaScript closures if we are targeting older versions of the JavaScript runtime. This means that no matter what JavaScript runtime we are targeting, the TypeScript compiler will take care of generating the correct JavaScript.

## Interfaces

We discussed how TypeScript uses duck typing to assess if two objects are compatible. These typing rules govern whether an abject can be assigned to another and compares the properties of one object to the other.

Interfaces provide us with a mechanism to define what properties an object must implement and is, therefore, a way for us to define a custom type. By defining an interface, we are describing the properties and functions that an object is expected to have in order to be used by our code.

To illustrate these concepts, consider the following code:

```ts
// This interface defines the structure of an object that
// must have a property called "id" that is a number and
// a property called "name" that is a string.
interface IIdName {
  id: number;
  name: string;
}
```

Here, we have used the `interface` keyword to define a TypeScript interface named `IIdName` on **lines 4-7**. This interface describes an object that has an `id` property of type `number`, and a `name` property of type `string`.

Once we have defined an interface, we can use it in the same way as a primitive type.

Let's take a look at how we can do this with the help of the following example:

```ts
interface IIdName {
  id: number;
  name: string;
}

// Declaring a variable `idObject` with type 'IIdName'
let idObject: IIdName = {
  // Property 'id' with value 2
  id: 2
};
```

Output:

```
index.ts(7,5): error TS2741: Property 'name' is missing in type '{ id: number; }' but required in type 'IIdName'.
```

- We have created a variable named `idObject` on **line 7** and specified that its type is the interface `IIdName`.
- We have, however, only specified a single property named `id` on **line 9** and have not specified the `name` property, which means that our object does not match the properties we are expecting according to the interface definition.

This code generates an error.

When we run the code, we can see that the compiler is treating our interface definition just like it would treat a standard type. We are stating that the object `idObject` implements the `IIdName` interface, but we have not provided the `name` property that is required. Hence, the error occurs.

To remove this error, we need to define both properties on our object, as required by the interface, as follows:

```ts
interface IIdName {
  id: number;
  name: string;
}

// The object now has `id` property with value `2` and `name` property with value `"this is a name"`
let idObject: IIdName = {
  id: 2,
  name: "this is a name"
};
```

As we can see, the code executes without any error now, which in turn means that we have created the `idObject` object correctly this time.

TypeScript will treat interfaces in the same way as it treats primitive types, and it will use duck typing to ensure that when we say that an object matches an interface, then it really does match the interface, with no property left behind.