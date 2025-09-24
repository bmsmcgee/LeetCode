# The `super` Function and Function Overriding

> Learn how to use the `super` keyword to call base class constructors and method overrides.

## The `super` Function

When using inheritance, it is quite common for a base class and a derived class to implement the same method. This is seen most often with class constructors. If a derived class has a constructor, then this constructor must call the base class constructor using the `super` keyword, or TypeScript will generate an error:

```ts
// Class definition for BaseClassWithCtor
class BaseClassWithCtor {
  // provate property to store the id
  private id: number;

  // constructor to initialize the id
  constructor(id: number) {
    this.id = id;
  }
}

// Class definition for DerivedClassWithCtor that extends BaseClassWithCtor
class DerivedClassWithCtor extends BaseClassWithCtor {
  // private property to store the name
  private name: string;

  // constructor to initialize the id and name
  constructor(id: number, name: string) {
    // calling the super constructor to initialize the id
    super(id);
    this.name = name;
  }
}
```

- We define a class named `BaseClassWithCtor` that has a single property named `id` of type `number` and also defines a `constructor` function that initializes this `id` property.
- We then define a class named `DerivedClassWithCtor` that inherits from the `BaseClassWithCtor` class. Also, note how we are calling the constructor for the base class, `BaseClassWithCtor`, within the constructor of the `DerivedClassWithCtor` class, by using the `super` function.
- This `super` call also passes the value that it is receiving in the `id` parameter through to the base class constructor.

> **Note:** Even if a base class does not define a constructor function, if the derived class does define a constructor function, then the derived class must call the `super` function with no arguments.

## Function Overriding

**Function overriding** is when a derived class defines a method that has the same name as a base class method.

The derived class can determine whether or not to call the implementation of the function in the base class.

Let's take a look at this technique as follows:

```ts
// Define the BaseClassWithFn class
class BaseClassWithFn {
  // Define the print method which takes a string argument
  print(text: string) {
    console.log(`BaseClassWithFn.print() : ${text}`)
  }
}

// Define the DerivedClassFnOverride class which extends the BaseClassWithFn class
class DerivedClassFnOverride extends BaseClassWithFn {
  // Override the print method in the BaseClassWithFn class
  print(text: string) {
    // Log a new message to the console with the class named and the argument
    console.log(`DerivedClassFnOverride.print(${text})`);
  }
}

let derivedClassFnOverride = new DerivedClassFnOverride();
derivedClassFnOverride.print("test");
```

Output:

```
DerivedClassFnOverride.print(test)
```

- We define a class named `BaseClassWithFn` that has a single `print` function with a single parameter named `text` of type `string`.
- We then define a class named `DerivedClassFnOverride` that inherits from the `BaseClassWithFn` class and also has a single `print` function with the same parameters and types. The derived class's implementation of the `print` function overrides the base class implementation of the `print` function.
- We create a new instance of the `DerivedClassFnOverride` class and call its `print` function with the argume `"test"` to see this phenomenon working.

We can, however, still call the base class's function implementation using the `super` keyword as follows:

```ts
// Define the BaseClassWithFn class
class BaseClassWithFn {
  // Define the print method which takes a string argument
  print(text: string) {
    // Log the message to the console with the class name and the argument
    console.log(`BaseClassWithFn.print() : ${text}`);
  }
}

// Define the DerivedClassFnOverride class which extends the BaseClassWithFn class
class DerivedClassFnOverride extends BaseClassWithFn {
  // Override the print method in the BaseClassWithFn class
  print(text: string) {
    // Call the print method in the BaseClassWithFn class with a new message
    super.print(`from DerivedClassFn callthrough : ${text}`);
  }
}

// Create an instance of the DerivedClassFnOverride class
let derivedClassFnOverride = new DerivedClassFnOverride();

// Call the print method on the derivedClassFnOverride instance
derivedClassFnOverride.print("test");
```

Output:

```
BaseClassWithFn.print() : from DerivedClassFn callthrough : test
```

- We define a class named `DerivedClassFnCallthrough` that inherits from the `BaseClassWithFn` class and also has a function override for the `print` function.
- The implementation of this `print` function calls through to the base calss implementation by using the `super` keyword, that is, `super.print`.
- To test that this works, we create an isntance of the `DerivedClassFnCallthrough` class named `derivedCallthrough` and call the `print` functions.

When we run the code, we can clearly see that the base class's `print` function has been invoked by the derived class's `print` function through the use of the `super` keyword.