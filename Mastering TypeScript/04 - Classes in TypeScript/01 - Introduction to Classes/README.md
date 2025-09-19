# Introduction to Classes

> Learn the fundamentals of TypeScript classes, including property and method declaration, as well as utilizing the `this` keyword to access class properties.

## Classes in TypeScript

A class is the definition of an object, what data it holds, and what operations it can perform. Classes and interfaces form the cornerstone of object-oriented programming.

Let's take a look at a simple class definition in TypeScript as follows:

```ts
// Defining a class named SimpleClass
class SimpleClass {
  // Property named 'id' with type number
  id: number;
  // Method named 'print' with return type void
  print(): void {
    console.log(`SimpleClass.print() called.`);
  }
}
```

Output:

```
index.ts(4,3): error TS2564: Property 'id' has no initializer and is not definitely assigned in the constructor.
```

Here, we define a class using the `class` keyword, which is named `SimpleClass`, and has an `id` property of type `number` and a `print` function, which logs a message to the console.

Notice anything wrong with this code? Well, the compiler generates an error message.

## Error Handling for Uninitialized Properties

What this error is indicating is that if we create an instance of this class, then the newly created class will not have the `id` property initialized, and it will therefore be `undefined`.

If our code is expecting the `id` property to have a value, then we might be surprised when it returns `undefined`, and the compiler is warning us of this potential error.

There are two ways to fix this compiler error. We could set it to a default value such as `0`, or we could simply make the `id` property a type union, as follows:

```ts
id: number | undefined;
```

Here, we specified that the `id` property could be a `number`, or it could be `undefined`. We are therefore making a conscious decision within our code that we are prepared for this value to be `undefined`.

In order to use our `SimpleClass` class definition, we will need to create an instance of this class as follows:

```ts
// Defining a class named SimpleClass
class SimpleClass {
  // Property named "id" with type number
  id: number;
  // Method named "print" with return type void
  print(): void {
    console.log(`SimpleClass.print() called.`);
  }
}

// Cretating an instance of the SimpleClass
let mySimpleClass = new SimpleClass();
```

Output:

```
SimpleClass.print() called.
```

We have defined a variable named `mySimpleClass` and set it to a new instance of the `SimpleClass` class by using the `new` keyword. Once the instance of this class has been created, we call the `print` function.

## Using the `this` Keyword

As we have seen, a class definition specifies both the properties of a class and the functions that it implements. Within the class, if we need to access a property of the class instance, we need to use the `this` keyword as follows:

```ts
class SimpleClass {
  // 'id' property can be either a number or undefined
  id: number | undefined;
  print(): void {
    console.lof(`SimpleClass.id = ${this.id}`); // Logs the value of 'id' property using template string
  }
}
```

Here, we have modified the `print` function to print the value of the `id` property to the console within the template string, `${this.id}`.

> **Note:** We need to prefix the `id` property with the keyword `this` in order to access it within a class.

We can now test this code as follows:

```ts
class SimpleClass {
  // "id" property can be either a number or undefined
  id: number | undefined;
  print(): void {
    console.log(`SimpleClass.id = ${this.id}`);
  }
}

// Create an instance of SimpleClass and assign it to "mySimpleClass" variable
let mySimpleClass = new SimpleClass();

// Set the value of "id" property to 2020
mySimpleClass.id = 2020;

// Call the "print" method to log the value of "id" property
mySimpleClass.print();
```

Output:

```
SimpleClass.id = 2020
```

We have modified our earlier code sample and assigned the value of `2020` to the `id` property of the variable `mySimpleClass`. We then call the `print` function of this class.

The `print` function is accessing the value of the internal class property named `id` and correctly printing the value of `2020` to the console.