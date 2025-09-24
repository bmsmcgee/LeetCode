# Introduction to Inheritance

> Learn about inheritance in TypeScript, including base and derived classes/interfaces, and how to imlement it using the extend keyword.

## Inheritance in TypeScript

Inheritance is another paradigm that is one of the cornerstones of object-oriented programming. Inheritance allows us to create an object based on another object, thereby inheriting all of its characteristics, including properties and functions. In TypeScrit, inheritance can be used by classes and interfaces. We will take a closer look at inheritance and what it means for both classes and interfaces.

When discussing inheritance, it is important to clearly distinguish between the class that forms the basis of the inheritance structure and the class that is doing all of the inheriting.

We will use the terms **base class** or **base interface** to denote the class or interface that forms the base of the inheritance structure, and the terms **derived class** or **derived interface** to denote the class or interface that is doing the inheriting.

TypeScript uses the `extends` keyword to implement inheritance, and we will look at practical examples of its usage next.

## Interface Inheritance

One interface can form the base interface for one or many other interfaces.

As an example of this, consider the following code:

```ts
// Define an interface 'IBase' with a roerty 'id' of tye number
interface IBase {
  id: number;
}

// Define an interface 'IDerivedFromBase' that extends 'IBase'
// This means that 'IDerivedFromBase' inherits the property 'id' from 'IBase'
// and adds a new property 'name' of tye string
interface IDerivedFromBase extends IBase {
  name: string;
}

// Define a class 'IdNameClass' that implements the interface 'IDerivedFromBase'
// This means that the class 'IdNameClass' must have all the properties secified in the 'IDerivedFromBase' interface
class IdNameClass implements IDerivedFromBase {
  name: string = "nameString";
}
```

Outut:

```
index.ts(16,7): error TS2420: Class 'IdNameClass' incorrectly implements interface 'IDerivedFromBase'.
  Property 'id' is missing in type 'IdNameClass' but required in type 'IDerivedFromBase'.
```

- We define an interface named `IBase` with a single property `id` of type number
- We then define a second interface named `IDerivedFromBase` that uses the `extends` keyword to inherit from `IBase`
- At the end of the code, we define a class named `IDNameClass` that implements the `IDerivedFromBase` interface and has a single property named `name` of type `string`.

However, when we run this code, it generates an error. The compiler tells us that the `IDerivedFromBase` interface has both a `name` and an `id` property because it inherits the `id` property from the `IBase` interface.

As we have not defined the `id` property in our class definition, the class is not correctly implementing the interface, hence the error.

We can fix this class definition as follows:

```ts
// Define an interface 'IBase' with a property 'id' of type number
interface IBase {
  id: number;
}

// Define an interface 'IDerivedFromBase' that extends 'IBase'
// This means that 'IDerivedFromBase' inherits the property 'id' from 'IBase'
// and adds a new property 'name' of type string
interface IDerivedFromBase
  extends IBase {
  name: string;
}

// Define a class 'IdNameClass' that implements the interface 'IDerivedFromBase'
// This means that the class 'IdNameClass' must have all the properties specified in the 'IDerivedFromBase' interface
class IdNameClass
  implements IDerivedFromBase {
  id: number = 0;
  name: string = "nameString";
}
```

As we can see, the code compiles correctly now without giving any errors. This is because we have added the `id` property on the class definition for `IdNameClass` and are, therefore, correctly implementing the `IDerivedFromBase` interface.

### Narrowing a Type on a Derived Interface

When using interface inheritance, we can also narrow a type on a derived interface.

Consider the following two interfaces:

```ts
// Interface 'IBaseStringOrNumber' defines a property 'id' that can be either a string or a number
interface IBaseStringOrNumber {
  id: string | number;
}

// Interface `IDerivedFromBaseNumber` extends `IBaseStringOrNumber` and defines the property `id` as being a number type
interface IDerivedFromBaseNumber extends IBaseStringOrNumber {
  id: number;
}
```

We have an interface named `IBaseStringOrNumber` that defines a single property named `id`, which can be either a `string` or a `number`.
We then define another interface named `IDerivedFromBaseNumber`, which extends `IBaseStringOrNumber`. In this derived interface, the `id` property is redefined as being of type `number`, which narrows its definition from `string | number` in `IBaseStringOrNumber`.

### Multiple Inheritances in Interfaces

Interfaces also support multiple inheritances.

Consider the following code:

```ts
// Interface 'IMultiple' extends both 'IDerivedFromBase' and 'IDerivedFromBaseNumber'
interface IMultiple extends IDerivedFromBase, IDerivedFromBaseNumber {
  // Property 'description' is of type string
  description: string;
}

// Variable 'multipleObject' is of type 'IMultiple'
let multipleObject: IMultiple = {
  // Property 'id' must be a number, as specified in 'IDerivedFromBaseNumber'
  id: 1,
  // Property 'name' is required by 'IDerivedFromBase'
  name: "myName',
  // Property 'description' must be a string
  description: "myDescription"
};
```

- We define an interface named `IMultiple` that extends both `IderivedFromBase` and `IDerivedFromBaseNumber` interfaces using a comma,separated list. The `IMultiple` interface also defines a property named description of type `string`.
- We define an object named `multipleObject` that implements the `IMultiple` interface. According to our inheritance rules, this `IMultiple` interface, therefore, has three properties:
  - An `id` property of type `number` from the `IDerivedFromBaseNumber` interface.
  - A `name` property from the `IDerivedFromBase` interface.
  - The `description` property
- This `multipleObject` object must provide values for each of the properties specified in the `IMultiple` interface.

## Class Inheritance

Classes can also use the `extends` keyword to create an inheritance structure. Using our existing definitions for the `IBase` and `IDerivedFromBase` interfaces, the following code shows an example of class inheritance:

```ts
// This is the BaseClass implementation that implements the IBase interface
// The 'id' property is set to a default value of 0
class BaseClass implements IBase {
  id: number = 0;
}

// This is the DerivedFromBaseClass that extends the BaseClass
// and implements the IDerivedFromBase interface
// The 'name' property is set to a default value of "nameString"
class DerivedFromBaseClass extends BaseClass implements IDerivedFromBase {
  name: string = "nameString";
}
```

- We define a class named `BaseClass` that implements the `IBase` interface and must define an `id` property of type `number`.
- We then have a class definition for class named `DerivedFromBaseClass`, which inherits from `BaseClass` (using the `extends` keyword) and also implements the `IDerivedFromBase` interface.
- As `BaseClass` already has `id` property, the only other property that `DerivedFromBaseClass` needs to implement is the `name` property.

### A Class with Multiple Interfaces

JavaScript does not support the concept of multiple inheritance when it comes to classes. This means that a class can only inherit from one other class. Interfaces, however, do support multiple inheritances, as we saw before.

A class, however, can implement multiple interfaces as follows:

```ts
// An interface defines a blueprint for an object
// and allows objects to be created with properties and methods
interface IFirstInterface {
  // defines a property 'id' with a number type
  id: number;
}

// Another interface defining a blueprint for an object
interface ISecondInterface {
  // defines a property 'name' with a string type
  name: string;
}

// A class that implements two interfaces, IFirstInterface and ISecondInterface
class MultipleInterfaces implements IFirstInterface, ISecondInterface {
  // initializing the property 'id' with a default value of 0
  id: number = 0;

  // initializing the property 'name' with a default value of 'nameString'
  name: string = "nameString";
}
```

- Here we have two interfaces that are independent of each other:
  - `IFirstInterface` has a single property named `id` of type `number`.
  - `ISecondInterface` has a single property named `name` of type `string`.
- We the defined a class named `MultipleInterfaces` that implements both interfaces by simply naming them in a comma-separated list.

As the `MultipleInterfaces` class implements both independent interfaces, it must define both an `id` property and a `name` property.