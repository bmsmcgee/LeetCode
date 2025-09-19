# Constructor Parameter Properties and Property Accessors

> Discover how TypeScript shorthand access modifiers simplify class property creation by applying them to constructor parameters.

## Introduction to TypeScript Shorthand Access Modifiers

TypeScript also introduces a shorthand version for access modifiers that can be applied to parameters in a constructor function.

As an example of this, consider the following code:

```ts
class ClassWithCtorMods {
  // Constructor function with parameters, 'id' and 'name'
  // Using shorthand access modifiers, 'public' for 'id' and 'private' for 'name'
  constructor(public id: number, private name: string) {

  }
}

// Create an instance of ClassWithCtorMods and assign it to the variable 'myClassMod'
let myClassMod = new ClassWithCtorMods(1, "test");

// Log the value of the 'id' property to the console
console.log(`myClassMod.id = ${myClassMod.id}`);

// Log the value of the 'name' property to the console
console.log(`myClassMod.name = ${myClassMod.name}`);
```

Output 1:

```
myClassMod.id = 1
```

Output 2:

```
index.ts(15,45): error TS2341: Property 'name' is private and only accessible within class 'ClassWithCtorMods'.
```

- We define a class named `ClassWithCtorMods` on **lines 1-6** that has a single `constructor` function.
- This `constructor` function has two parameters:
  - The first is named `id` and is of type `number`.
  - The second is named `name` and is of type `string`.

> **Note:** We have marked the `id` property as `public` within the constructor function definition, and we have marked the `name` property as `private`. This shorthand automatically creates an internal `id` property and a `name` property on the class itself, which can be used as standard properties.

- We then create an instance of this class on **line 9** and assign it to a variable named `myClassMod`.
- We then log the value of both the `id` property and the `name` property to the console.

This code, however, generates an error. The error is telling us that the automatically created property named `name` is marked as `private` and is, therefore, not accessible outside of the class itself.

> **Note:** This shorthand syntax is only available for use within the constructor function itself and not in any other functions of a class

## The `readonly` Property in TypeScript

In addition to the `public` and `private` access modifiers, we can also mark a class property as `readonly`.

This is similar to the concept of the `const` keyword and means that once a value has been assigned to a `readonly` property, it is not allowed to be modified.

### Example of a `readonly` Property

Let's take a look at a TypeScript example to understand the concept better.

```ts
class ClassWithReadonly {
  // Declare a property named 'name' with the type 'string' and mark it as readonly
  readonly name: string;

  // Constructor function to initialize the 'name' property
  constructor(_name: string) {
    // Assign the value of the incoming parameter '_name' to the 'name property
    this.name = _name;
  }

  // Function to attempt to set the value of the 'name' property
  setNameValue(_name: string) {
    // Attempt to assign a new value to the 'name' property
    this.name = _name;
  }
}
```

Output:

```
index.ts(14,10): error TS2540: Cannot assign to 'name' because it is a read-only property.
```

- We have a class named `ClassWithReadonly` on **lines 1-16** that has a single property named `name` of type `string` that has been marked as `readonly`.
- We then have a `constructor` function on **lines 6-9** that accepts a single parameter named `_name`.

> **Note:** We are assigning the value of the incoming `_name` parameter to the internal `readonly name` property of our class. The `readonly` properties are only allowed to set within the `constructor` function.

- We then have a function named `setNameValue` on **lines 12-15** that is attempting to set the value of the internal `name` property but is not a `constructor` function.

This code generates an error. The error occurs when we attempt to assign a value to the `name` property within the `setNameValue` member function. As this error shows, we can only set a value for a `readonly` property within the class constructor function.

> **Note:** The `readonly` modifier can also be used within interface definitions, and it is also excluded from the generated JavaScript.

## Understanding Property Accessors

ECMAScript 5 introduced the concept of property accessors, or `get` and `set` functions. A property accessor is simply a function that is called when a user of our class gets the value of a property or sets its value.

By using a function instead of a simple property, we can detect when someone modifies or accesses a property, which we can use to trigger other logic.

### Example of Property Accessors

Let's take a look at an example to understand the concept better

```ts
class ClassWithAccessors {
  // Declare a private property to store the ID
  private _id: number = 0;

  // Define the getter for the "id" property
  get id(): number {
    console.log(`get id property`); // log when the "id" property is being accessed
    return this._id;  // return the private "_id" property
  }

  // Define the setter for the "id" property
  set id(value: number) {
    console.log(`set id property`); // log when the "id" property is being modified
    this._id = value; // set the value of the private "_id" property
  }
}
```

- We define a class named `ClassWithAccessors` that has a single private property named `_id` of type `number`.
- We then define a function named `id` on **lines 6-9** that logs a message to the console and then returns the value of the `_id` property. Note that this function has been marked as a get function, using th `get` keyword.
- We then define a `set` function on **lines 12-15**, also with the name `id`, that will set the value of the internal `_id` property.

> **Note:** The `get` function and the `set` function are both named `id`.

We can now use this class as follows:

```ts
// create an instance of the ClassWithAccessors
let classWithAccessors = new ClassWithAccessors();

// set the value of the "id" property using the setter
classWithAccessors.id = 10;

// get the value of the "id" property using the getter
console.log(`classWithAccessors.id = ${classWithAccessors.id}`); // logs: "classWithAccessors.id = 10"
```

Output:

```
set id property
get id property
classWithAccessors.id = 10
```

- We have created a variable named `classWithAccessors` on **line 2**, which holds an instance of the `ClassWithAccessors` class. This class instance exposes what lookds like a normal property named `id`.
- We set the value of this property to `10` on **line 5** and then print the value of the property to the console on **line 8**.

The `get` and `set` functions, therefore, are exposing what looks like a property to the outside world, named `id`, but internally within the class, they are actually functions and not properties.