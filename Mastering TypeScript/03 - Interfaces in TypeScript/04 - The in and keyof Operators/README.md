# The `in` and `keyof` Operators

> Learn how to use the `in` operator and type guards in TypeScript to distinguish between object interfaces, along with extracting property names using the `keyof` operator.

## The `in` Operator

JavaScript and, subsequently, TypeScript allow us to interrogate an object and see if it has a property using the `in` operator.

Let's explore this operator with the following interfaces:

```ts
// Define the IIdName interface
interface IIdName {
  id: number;
  name: string;
}

// Define the IDescrValue interface
interface IdescrValue {
  descr: string;
  value: number;
}
```

Here, we have two interfaces:
  - The first is `IIdName`, and contains an `id` property of type `number` and a `name` property of type `string`.
  - The second interface is `IDescrValue`, and contains a `descr` property of type `string`, and a `value` property of type `number`.

Note that these interfaces describe completely different objects and have no overlapping properties whatsoever.

## Using the `in` Operator in a Function

We can now write a function that will distinguish between these two interfaces using the `in` operator as follows:

```ts
interface IIdName {
  id: number;
  name: string;
}

interface IDescrValue {
  descr: string;
  value: number;
}

// Define the printNameOrValue function which takes an object
// that implements either the IIdName or IDescrValue interface
function printNameOrValue(obj: IIdName | IDescrValue): void {
  // Use the 'in' operator to check if the object has an 'id' property
  if ('id' in obj) {
    console.log(`obj.name : ${obj.name}`);
  }
  // Use the 'in' operator to check if the object has a 'descr' property
  if ('descr' in obj) {
    console.log(`obj.value : ${obj.value}`);
  }
}
```

- We have a function named `printNameOrValue` from **lines 13-22** that has a single parameter named `obj`, which can either be of the type `IIdName`, or of the type `IDescrValue`.
- We are then using an `if` statement on **line 15** to create a type guard that checks for the property `id` using the `in` operator. In other words, if the object has a property named `id`, then enter the `if` block. Within this `if` block, the object will be treated as implementing the `IIdName` interface, and this code block is acting as a type guard. We then log the value of the `obj.name` property, which is also part of the `IIdName` interface, to the console.
- The second `if` statement on **line 19** in this function is again using the `in` operator, but this time using the `descr` property to detect if the object implements the `IDescrValue` interface. If it does implement this interface, we then log the value of the `obj.value` property, which is part of the `IDescrValue` interface, to the console.

Example Usage

We can now use this function as follows:

```ts
interface IIdName {
  id: number;
  name: string;
}

interface IDescrValue {
  descr: string;
  value: number;
}

function printNameOrValue(obj: IIdName | IDescrValue): void {
  if ("id" in obj) {
    console.log(`obj.name : ${obj.name}`);
  }
  if ("descr" in obj) {
    console.log(`obj.value : ${obj.value}`);
  }
}

// Calling the printNameOrValue function with two objects with different properties
printNameOrValue({
  id: 1,
  name: "nameValue",
});
printNameOrValue({
  descr: "description",
  value: 2,
});
```

Output:

```
obj.name : nameValue
obj.value : 2
```

- We are calling the `printNameOrValue` function with two different objects, on **lines 22-23** and **lines 26-27**, respectively:
  - The structure of the first object conforms to the `IIdName` interface.
  - The structure of the second object conforms to the `IDescrValue` interface.

The compiler will let us know if we call this function with anything that does not match either of these interfaces.

We can see from the output the function `printNameOrValue` is detecting the properties of each of these objects using the `in` operator and entering the type guard code block depending on what properties it finds.

> **Note:** If an object implements both interfaces or has properties that match both of these interfaces, then both type guards will be executed, as we have two `if` statements and not an `if else` statement.

## The `keyof` Keyword

TypeScript allows us to iterate through the properties of a type and extract the names of its properties through the `keyof` keyword, which we can use as a string literal type.

Let's explore this concept and how it applies to interfaces, as follows:

```ts
// Define an interface 'IPerson' with properties 'id' and 'name'
interface IPerson {
  id: number;
  name: string;
}

// Generate a string literal type for the properties of the interface 'IPerson'
type PersonPropertyName = keyof IPerson;
```

- We define an interface named `IPerson` on **lines 2-5** that defines two properties named `id` and `name`.
- We are then creating a string literal type on **line 8** for the valid properties of this interface named `PersonPropertyName`.

Note that here, we are simply using the `keyof` keyword to generate a string literal type for the properties found in the `IPerson` interface.

This is equivalent to the following string literal:

```ts
type PersonPropertyLiteral = "id" | "name";
```

## Using the Generated String Literal Type

We can now use this type as follows:

```ts
interface IPerson {
  id: number;
  name: string;
}

type PersonPropertyName = keyof IPerson;

// Define a function `getProperty` that accepts two parameters
function getProperty(key: PersonPropertyName, value: IPerson) {
  console.log(`${key} = ${value[key]}`);
}

// Call the function `getProperty` with argument `"id"` and an object with `id` and `name` properties
getProperty("id", { id: 1, name: "firstName" });

// Call the function `getProperty` with argument `"name"` and an object with `id` and `name` properties
getProperty("name", { id: 2, name: "secondName" });

// Call the function `getProperty` with argument `"telephone"` and an object with `id` and `name` properties
getProperty("telephone", { id: 3, name: "thirdName" });
```

Output (comment out last `getProperty`):

```
id = 1
name = secondName
```

Output (uncomment last `getProperty`):

```
index.ts(20,13): error TS2345: Argument of type '"telephone"' is not assignable to parameter of type 'keyof IPerson'.
```

We define a function named `getProperty` that has two parameters named `key` of type `PersonPropertyName` and `value` of type `IPerson`.

This function is using the string literal `PersonPreopertyName` that was constructued using the `keyof` keyword. The function simply logs the name of the property key provided and the value of the corresponding property to the console.

We are then invoking the function three times:
  - The call on **line 14** to the `getProperty` function will output the value of the `id` property.
  - The call on **line 17** to the `getProperty` function will output the value of the `name` property.
  - The call that is on **line 20**, however, will generate an error.

When we run the code, we can see that the compiler is correctly idtentifying that we are not allowed to call this function with the argument of `"telephone"`, as this argument is not part of our string literal type.

> **Note:** Using the `keyof` keyword will generate a string literal that automatically includes all of the properties of an interface. This technique is obviously preferable to having to maintain string literals manually.