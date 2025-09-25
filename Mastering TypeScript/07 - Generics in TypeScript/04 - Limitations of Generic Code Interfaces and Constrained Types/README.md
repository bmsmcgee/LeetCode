# Limitations of Generic Code: Interfaces and Constrained Types

> Learn about the limitations of generic code and how to use interfaces to constrain the type of `T` and reference common properties and functions.

We have already seen how we can constrain the type of `T` in our generic code in order to limit the number of types that can be used. Another limit of generic code is that it can only reference functions or properties of objects that are common to any type of `T`.

## Interfaces and Constrained Type

As an example of this limitation, consider the following code:

```ts
// Define an interface IPrintId with id property of type
// number and print method with no return value.
interface IPrintId {
  id: number;
  print(): void;
}

// Define an interface IPrintName with name property of type
// string and print method with nor return value.
interface IPrintName {
  name: string;
  print(): void;
}
```
- We have two interfaces named `IPrintId` and `IPrintName`. Both interfaces have a function named `print` that returns `void`.
- The `IPrintId` interface has a property named `id` of type `number`, and the `IPrintName` interface has a property named `name` of type `string`.

These two properties are unique to each of these interfaces.

## Using a Generic Function with Interfaces

Now, let's consider a generic function that is designed to work with these two interfaces as follows:

```ts
// Define a function called 'useT' that takes an argument 'item' of type 'T'
function useT<T extends IPrintId | IPrintName>(item: T): void {
  item.print();
  item.id = 1;        // error: id is not common
  item.name = "test"; // error: name is not common
}
```

Output:

```
index.ts(23,7): error TS2339: Property 'id' does not exist on type 'IPrintId | IPrintName'.
  Property 'id' does not exist on type 'IPrintName'.
index.ts(24,7): error TS2339: Property 'name' does not exist on type 'IPrintId | IPrintName'.
  Property 'name' does not exist on type 'IPrintId'.  
```

- We have defined a function named `useT` that accepts a type named `T` that can be either an instance of the `IPrintId` interface or an instance of the `IPrintName` interface.
- The function has a single parameter named `item` of type `T`. Within this function, we are calling the `print` method of the `item` parameter, and then we attempt to assign the value of `1` to the `id` property and a value of `"test"` to the `name` property of the `item` parameter.

We can see that the code is generating an error. The error clearly indicates that the `id` and `name` property does not exist on the type `T`. In other words, we are only able to call properties or functions on type `T` where they are common to all types of `T`.

As the `id` property is unique to the `IPrintId` interface, and the `name` property is unique to the `IPrintName` interface, we are not allowed to reference these properties when we reference `T`. The only property that these two interfaces have in common is the `print` function, and therefore, only the `print` function can be used in this case.

> **Note:** TypeScript will ensure that we are only able to reference propertyes and functions on a type of `T`, where these properties and functions are common across all types that are allowed for `T`.