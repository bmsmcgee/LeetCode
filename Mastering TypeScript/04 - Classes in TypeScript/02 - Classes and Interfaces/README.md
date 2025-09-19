# Classes and Interfaces

> Learn about the relationship between classes and interfaces in object-oriented design patterns

## Relationship Between Classes and Interfaces

There is a very strong relationship between classes and interfaces, particularly in object-oriented design patterns. An interface describes a custom type and can include both properties and functions. A class is the definition of an object, also including its properties and functions. This allows us to use interfaces to describe some common behaviour within a set of classes and write code that will work with this set of classes.

As an example of this, consider the following class definitions:

```ts
// Define a class ClassA with a method print
class ClassA {
  // Method print with a void return type
  print(): void {
    // Log message indicating that ClassA.print has been called
    console.log(`ClassA.print() called.`)
  };
}

// Define a class ClassB with a method print
class ClassB {
  // Method print with a void return type
  print(): void {
    // Log message indicating that ClassB.print has been called
    console.log(`ClassB.print() called.`)
  };
}
```

Here, we have class definitions for two classes, named `ClassA` (**lines 2-8**) and `ClassB` (**lines 11-17**). Both of these classes have a `print` functions.

Now, suppose that we want to write some code that did not really care what type of class we used. All it cared about was whether the class implemented a `print` function.

We can easily create an interface describing the behaviour we need as follows:

```ts
// Define an interface IPrint with a method print
interface IPrint {
  print(): void;
}

// Define a function printClass which takes a parameter a of type IPrint
function printClass(a: IPrint) {
  // Call the method print on the object passed in as a parameter
  a.print();
}
```

Here, we have defined an interface named `IPrint` that contains a single function named `print` and returns `void`.

We then have a function named `printClass` on **line 7** that takes a single parameter named `a` and is of type `IPrint`. We are using the interface `IPrint` in this function definition to describe the attributes of an object that can be passed in as a parameter.

### Marking Classes as Usable

We can now update our class definitions and mark them as being usable by the `printClass` function, as follows:

```ts
// ClassA implements the IPrint interface
class ClassA implements IPrint {
  print(): void {
    console.log(`ClassA.print() called.`);
  }
}

// ClassB implements the IPrint interface
class ClassB implements IPrint {
  print(): void {
    console.log(`ClassB.print() called.`);
  }
}
```

We are using the TypeScript keyqord `implements` to state that both `ClassA` and `ClassB` implement the `IPrint` interface and are therefore usable by our `printClass` function.

We can now use this function as follows:

```ts
// Create new instances of ClassA and ClassB
let classA = new ClassA();
let classB = new ClassB();

// Call the 'printClass' function on both instances of ClassA and ClassB
printClass(classA);
printClass(classB);
```

Output:

```
ClassA.print() called.
ClassB.print() called.
```

Here, we have created an instance of each of our classes, and assigned them to the variables `classA` and `classB`. We then pass these variables into our `printClass` function as arguments.

> **Note:** We have hidden the class and interface definitions in the code above for readability purposes.

Interfaces, therefore, can be seen as a type of contract that classes must implement if they are expected to provide certain properties and certain behaviours.

## Duck Typing with Classes and Interfaces

TypeScript's duck typing rules will ensure that a particular class has the correct shape when used, even if it does not implement the interface as described.

As an example of this, consider the following code:

```ts
// Defining ClassC
class ClassC {
  // Method that logs a message to the console
  print(): void {
    console.log(`ClassC.print() called.`);
  }
}

// Creating an instance of ClassC
let classC = new ClassC();

// Calling the printClass function and passing in the classC instance
printClass(classC);
```

Output:

```
ClassC.print() called.
```

Here, we have defined a class named `ClassC` that has the `print` function that is required by the `IPrint` interface, but it does not explicitly state that it implements the `IPrint` interface. Note how we are missing the `implements IPrint` statement in the code, but we are still able to use the instance of this class, named `classC`, in a call to the `printClass` function on the last line of this snippet.

Thie is a further example of TypeScript's duck typing rules, making sure that the shape of the type used is correct for a call to the `printClass` function.

Defining interfaces and using them in our code, however, ensures that when changes are made to class definitions or interface definitions, we are able to trap any possible errors early.