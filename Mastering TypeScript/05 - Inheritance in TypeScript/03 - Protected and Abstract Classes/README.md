# Protected and Abstract Classes

> Learn about the features of `protected` and `abstract` classes in TypeScript.

## Protected Classes

Classes can mark both properties and functions with the `protected` keyword. If a property is marked as `protected`, then it is not accessible outisde of the class itself, similar to the behaviour of the `private` keyword.

It is, however, accessible to derived classes, which is different from `private` variables that are not accessible to derived classes, which can be seen in the following example:

```ts
// Define the BaseClassProtected class
class BaseClassProtected {
  // Declare a protected property 'id' of type number
  protected id: number;

  // Declare a private property 'name' of type string with a default value of ""
  private name: string = "";

  // Constructor which takes a number argument 'id'
  constructor(id: number) {
    // Set the value of the 'id' property to the argument
    this.id = id;
  }
}

// Define the AccessProtected class which extends the BaseClassProtected class
class AccessProtected extends BaseClassProtected {
  // Constructor which takes a number argument 'id'
  constructor(id: number) {
    // Call the constructor of the BaseClassProtected class with the argument
    super(id);
    // Log the value of the 'id' property from the BaseClassProtected class
    console.log(`base.id = ${this.id}`);
    // Log the value of the 'name' property from the BaseClassProtected class
    console.log(`base.name = ${this.name}`);
  }
}
```

Output:

```
index.ts(25,37): error TS2341: Property 'name' is private and only accessible within class 'BaseClassProtected'.
```

- We define a class named `BaseClassProtected` that has a protected property named `id` of type `number` and a private property named `name` of type `string`. We are setting the value of the `protected` `id` property within the constructor.
- We then define a class named `AccessProtected` that derives from the `BaseClassProtected` class. This class has a constructor function that is passing the `id` argument down into the base class constructor.

As we can see, the code generates an error when we run it. The error is telling us that we are attempting to access the protected `id` property of the base class, and then we are attempting to access the private `name` property of the base class.

Access to the protected `id` property is allowed, but access to the private `name` property is not.

Let's also test this theory outside of the classes themselves:

```ts
// Define the BaseClassProtected class
class BaseClassProtected {
  protected id: number;
  private name: string = "";

  // Constructor which takes a number argument "id"
  constructor(id: number) {
    // Set the value of the "id" property to the argument
    this.id = id;
  }
}

// Define the AccessProtected class which extends the BaseClassProtected class
class AccessProtected extends BaseClassProtected {
  // Constructor which takes a number argument "id"
  constructor(id: number) {
    // Call the constructor of the BaseClassProtected class with the argument
    super(id);
  }
}

// Create an instance of the AccessProtected class with the argument "1"
let accessProtected = new AccessProtected(1);

// Try to set the value of the protected property "id"
accessProtected.id = 1;

// Try to set the value of the private property "name"
accessProtected.name = "test";
```

Output:

```
index.ts(27,17): error TS2445: Property 'id' is protected and only accessible within class 'BaseClassProtected' and its subclasses.
index.ts(30,17): error TS2341: Property 'name' is private and only accessible within class 'BaseClassProtected'.
```

- We have made some changes to the `AccessProtected` class and removed the `console.log` statements.
- We also create a variable named `accessProtected` that holds an instance of `AccessProtected` class.
- We then attempt to assign values to the `id` property and the `name` property of this class.

This code generates an error, which clearly tells us that the `id` property is `protected` and only accessible within the `BaseClassProtected` class and any class that is derived from it. The `name` property is `private` and is only accessible within the `BaseClassProtected` class itself.

## Abstract Classes

An abstract class is a class that can't be instantiated. In other words, it is a class that is designed to be derived from. The purpose of abstract classes is generally to provide a set of basic properties or functions that are shared across a group of similar classes. Abstract classes are marked with the `abstract` keyword.

Let's take a look at the use of an abstract class as follows:

```ts
// Define the abstract class "EmployeeBase"
abstract class EmployeeBase {
  // Declare public properties 'id' and 'name' of type number and string respectively
  public id: number;
  public name: string;

  // Ctor which takes two arguments, 'id' and 'name'
  constructor(id: number, name: string) {
    // Set the values of the properties 'id' and 'name' to the arguments
    this.id = id;
    this.name = name;
  }
}

// Define the 'OfficeWorker' class which extends the 'EmployeeBase' class
class OfficeWorker extends EmployeeBase{}

// Define the 'OfficeManager' class which extends the 'OfficeWorker' class
class OfficeManager extends OfficeWorker {
  // Declare a public property 'employees' of type array of 'OfficeWorker' objects with an empty default value
  public employees: OfficeWorker[] = [];
}
```

- We define an abstract class named `EmployeeBase` that has an `id` property of type `number` and a `name` property of type `string`. The `EmployeeBase` class has a constructor function that initializes these properties.
- We then define a class named `OfficeWorker` that derived from the abstract `EmployeeBase` class.
- Finally, we have a class named `OfficeManager` that derives from the `OfficeWorker` class and has an internal property named `employees` that is an array of type `OfficeWorker`.

We can construct instances of these classes as follows:

```ts
let joeBlogg = new OfficeWorker(1, "Joe");

let jillBlogg = new OfficeWorker(2, "Jill");

let jackManager = new OfficeManager(3, "Jack");
```

- We create two variables named `joeBlogg` and `jillBlogg` that are of type `OfficeWorker`.
- We also create a variable named `jackManager` that is of type `OfficeWorker`.

Take a look at how we need to provide two arguments when constructing these objects. This is because both the `OfficeWorker` class and the `OfficeManager` class inherit from the abstract base class, `EmployeeBase`. The abstract base class `EmployeeBase` requires both an `id` and. `name` argument in its constructor.

> **Note:** Abstract classes are designed to be derived from. They provide a convenient method of sharing common properties and functions between groups of objects.