# Interfaces Extending Classes

> Learn how to derive an interface from a class definition and how to implement the derived interface in a class.

## Deriving an Interface from a Class Definition

An interface defines a set of methods or properties that a class must implement, while a class definition outlines the blueprint for creating objects with specific attributes and behaviours.

On a final note with regard to interface and class definitions, note that an interface can derive from a class definition, as can be seen in the following example:

```ts
// Definition of class BaseInterfaceClass with properties if and method print
class BaseInterfaceClass {
  id: number = 0;
  // Method that logs the value of id property
  print() {
    console.log(`this.id = ${this.id}`);
  }
}

// Definition of interface IBaseInterfaceClassExt that extends BaseInterfaceClass
interface IBaseInterfaceClassExt extends BaseInterfaceClass {
  // Method that sets the value of id property
  setId(id: number): void;
}
```

- We have a class definition for a class named `BaseInterfaceClass` that has a single property named `id` and a function named `print`.
- We then define an interface named `IBaseInterfaceClassExt` that derived from the BaseInterfaceClass using the `extends` keyword.

This interface then defines a function named `setId` that takes a single parameter named `id` of type `number`. So, we have derived an interface directly from a class definition and added a function definition.

## Implementing the Derived Interface in a Class

When implementing the derived interface in a class, the class must provide an implementation for each method defined in the interface.

Note that we can then use this interface in the same way that we use any other type of interface as follows:

```ts
// Class 'ImplementsExt' extends from the 'BaseInterfaceClass' class
class ImplementsExt  
  extends BaseInterfaceClass {
  // Implementing the 'IBaseInterfaceClassExt' interface
  // to ensure all its properties and methods are implemented
  setId(id: number): void {
    this.id = id;
  }
}
```

We have a class named `ImplementsExt` that derives from the base class named `BaseInterfaceClass` and also implements the `IBaseInterfaceClassExt` interface.

This class, therefore, must provide an implementation of the `setId` function that was defined by the `IBaseInterfaceClassExt` interface. This ensures that objects created from the `ImplementsExt` class have the expected behaviours and attributes as outlined in the interface.