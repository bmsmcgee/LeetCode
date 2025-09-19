# Weak Types in Interfaces

> Learn how weak types in TypeScript offer flexibility for defining and validating data structures without strict type enforcement.

## Introduction to Weak Types

When we define an interface where all of its properties are optional, this is considered to be a weak type. In other words, we have defined an interface, but none of the properties of the interface are mandatory.

Let's see what happens if we create a weak type and then try to bend the standard type rules as follows:

```ts
// Interface `IWeakType` defines the structure of a weak type object with optional properties `id` and `name`
interface IWeakType {
  id?: number;
  name?: string;
}

// `weakTypeNoOverlap` is a variable that is assigned an object that does not match the structure defined by `IWeakType`
// The object has a `description` property, which is not part of the `IWeakType` definition
let weakTypeNoOverlap: IWeakType = {
  description: "a description"
};
```

Output:

```
index.ts(10,3): error TS2322: Type '{ description: string; }' is not assignable to type 'IWeakType'.
  Object literal may only specify known properties, and 'description' does not exist in type 'IWeakType'.
```

- We define an interface name `IWeakType` from **line 2-4**, which has an `id` property of type `number` and a `name` property of type `string`. Both of these properties have been marked as optional.
- We then create a variable named `weakTypeNoOverlap` on **line 9**, which implements the `IWeakType` interface and has a single property named `description`.

We can see that the compiler is detecting that the `weakTypeNoOverlap` object has not implemented the `IWeakType` interface, as it does not have either an `id` or a `name` property. We can see, therefore, that TypeScript will strongly type even weak types.

## Fixing the Error in the Code

We can modify the code to make it work by adding the `description` property to the `IWeakType` interface, allowing the object assigned to `weakTypeNoOverlap` to match the structure defined by the interface.

Let's see how that looks in the following code:

```ts
// Interface `IWeakType` defines the structure of a weak type object with optional properties `id`, `name`, and `description`
interface IWeakType {
  id?: number;
  name?: string;
  description?: string;
}

// `weakTypeNoOverlap` is a variable that is assigned an object that matches the structure defined by `IWeakType`
// The object has a `description` property, which is now part of the `IWeakType` definition
let weakTypeNoOverlap: IWeakType = {
  description: "a description",
};
```

The code should work without producing any errors because the object assigned to `weakTypeNoOverlap` matches the structure defined by the `IWeakType` interface. The TypeScript compiler will not complain about the additional `description` property because it is now part of the defined structure.

> **Note:** While we are able to create weak types in TypeScript, they are really just an edge case in terms of usage. We should really be thinking differently about our interface definition if all properties become optional, and we are introducing a weak type.

