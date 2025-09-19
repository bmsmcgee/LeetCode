# Static Functions and Namespaces

> Learn how to use static functions and properties in classes to have a single instance of a function or property throughout the code base.

## Static Functions 

A class can mark a function with the `static` keyword, meaning that there will only be a single instance of this function available throughout the code base.

When using a `static` function, we do not need to create an instace of the class in order to invoke this function, as follows:

```ts
// Declare a class named 'StaticFunction'
class StaticFunction {
  // Declaring a static function named 'printTwo'
  static printTwo() {
    // Logging the value '2' to the console
    console.log(2);
  }
}

// Calling the static function 'printTwo' without creating an instance of the class
StaticFunction.printTwo();
```

- We have the definition of a class named `StaticFunction`. This class has a single function named `printTwo` on **line 4** that has been marked as `static`. This function simply prints the value `2` to the console.

> **Note:** We do not need to create an instance of this class using the `new` keyword. We simply call this function by its fully qualified name, that is, `<className>.<functionName>`, which in this case is `StaticFunction.printTwo()`.

## Static Properties

In a similar manner to static functions, classes can also have static properties. If a class property has been marked as `static`, then there will only be a single instance of this property throughout the code base.

```ts
// Define a class 'StaticProperty'
class StaticProperty {
  // Declare a static property 'count' with value of 0
  static count = 0;

  // Define a method 'updateCount' to increase the value of 'count' by 1
  updateCount() {
    StaticProperty.count++;
  }
}
```

- We define a class named `StaticProperty` from **lines 2-10**, that has a single property named `count` that has been marked as `static`.
- We have then defined a function named `updateCount` on **line 7** that will increase the value of the `static count` property by one each time it is called.

Consider how this class is used as follows:

```ts
// Create two instances of the class "StaticProperty"
let firstInstance = new StaticProperty();
let secondInstance = new StaticProperty();

// Call the method "updateCount" on the first instance
firstInstance.updateCount();
// Log the value of "count" after calling the method on the first instance
console.log(`StaticProperty.count = ${StaticProperty.count}`);

// Call the method "updateCount" on the second instance
secondInstance.updateCount();
// Log the value of "count" after calling the method on the second instance
console.log(`StaticProperty.count = ${StaticProperty.count}`);
```

Output:

```
StaticProperty.count = 1
StaticProperty.count = 2
```

- We create two variables named `firstInstance` (**line 2**) and `secondInstance` (**line 3**) that hold instances of the `StaticProperty` class.
- We then call the `updateCount` function on the `firstInstance` variable on **line 6** and log the value of the `count` property of the `StaticProperty` class to the console.
- We then use the `secondInstance` variable to again call the `updateCount` function on **line 11**, this time on another instance of the `StaticProperty` class.

We can see that both calls to the `updateCount` function, whether it be from the `firstInstance` variable or the `secondInstance` variable, have updated the value of the static property `count`.

This shows that if a class property has been marked as `static`, then there will only be a single instance of this property throughout the code base.

## Namespaces in TypeScript

When working within large projects, and particularly when working with large numbers of external libraries, there may come a time when two classes or interfaces share the same name. To handle such situations, TypeScript employs a namespaces.

A **namespace** in TypeScript is a way to organize code and ensure that class names remain unique.

### Creating a `namespace` in TypeScript

To create a namespace in TypeScript, we use the `namespace` keyword followed by the desired name of the namespace. Within the namespace block, we can define one or more classes or interfaces.

The following ecxample demonstrates how to create a namespace named `FirstNameSpace`.

```ts
// Declare a namesapce named 'FirstNameSpace'
namespace FirstNameSpace {
  // Export a class named 'NameSpaceClass' from the namespace
  export class NameSpaceClass {}
  // Declare a class named 'NotExported' within the namespace
  class NotExported {}
}
```

- We use the `namespace` keyword to create a namespace named `FirstNameSpace` on **line 2**. This namespace covers all class or interface definitions that fall within its code block.
- Within the `FirstNameSpace` code block, we define two classes named `NameSpaceClass` and `NotExported`. Note how we have used the `export` keyword for the `NameSpaceClass`.

### Exporting a Class from a `namespace`

The `export` keyword will make this class available outside of the namespace itself.

As an example of this, consider the following code:

```ts
// Instantiate the exported class "NameSpaceClass" from the namespace "FirstNameSpace"
let nameSpaceClass = new FirstNameSpace.NameSpaceClass();
// This line will result in an error because the class "NotExported" is not exported from the namespace
let notExported = new FirstNameSpace.NotExported();
```

Output:

```
index.ts(12,38): error TS2339: Property 'NotExported' does not exist on type 'typeof FirstNameSpace'.
```

- We have created two variables named `nameSpaceClass` and `notExported` on **lines 2 and 4**.
- We then create instances of the classes held within the `FirstNameSpace` namespace.

> **Note:** Take a look at how we need to prefix the class name that we are trying to instantiate with the name of the namespace itself, that is, `FirstNameSpace.NameSpaceClass`. This code, however, will generate an error.

This error is clearly telling us that the `NotExported` class is not made available for use outside of the namespace, as it has not been marked with the `export` keyword.

> **Note:** By making us refer to a class that is within a namespace by its fully qualified name, the compiler will ensure that we have unique class names across our code base.