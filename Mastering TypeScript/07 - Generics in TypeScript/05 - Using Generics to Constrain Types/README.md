# Using Generics to Constrain Types

> Learn how to use one generic type to apply a constraint on another type in TypeScript to improve type safety.

## Construct a Generic Type from Another

A generic type can be constructed out of another generic type. This technique essentially uses on type to apply a constraint on another type.

Let's take a look at an example:

```ts
// Define a function named printProperty that takes two generic type parameters
function printProperty<T, K extends keyof T>(object: T, key: K) {
  let propertyValue = object[key];
  console.log(`object[${key}] = ${propertyValue}`);
}
```

Here, we have a function named `printProperty` that has two generic types named `T` and `K`.

The type `K` is constrained to be a value computed from the `keyof` operator on type `T`. Remember that the `keyof` operator will return a string literal type that is made up of the properties of an object, so `K` will be constrained to the property names of the type `T`.

The `printProperty` function has two parameters named `object` of type `T`, and `key` of type `K`. The function assigns the value of the object's property named in the key parameter to a variable named `propertyValue` using the syntax `object[key]`. It then logs this value to the console.

Let's test this function as follows:

```ts
let obj1 = {
  id: 1,
  name: "myName",
  print() { console.log(`${this.id}`) }
}

printProperty(obj1, "id");
printProperty(obj1, "name");
printProperty(obj1, "surname");
```

Output:

```
index.ts(18,21): error TS2345: Argument of type '"surname"' is not assignable to parameter of type '"id" | "name" | "print"'.
```

- We have constructed an object named `obj1`, which has an `id` property of type `number`, a `name` property of type `string`, and a `print` function.
- We call the `printProperty` function three times, once with the key argument set to `"id"`, another with it set to `"name"`, and a third time with the key argument set to `"surname"`. The third call will produce an error.

We can see that the compiler has generated a string literal type based on the properties of the `obj1` object, and we are only allowed to call this function with a valid property `name` as the second argument. As the `obj1` object does not have a `surname` property, this line of the code snippet is generating an error.

## Handling Errors in Generic Types

Let's try running the code again, but with the last line removed:

```ts
// Define an object with a unique id, name and print method
let obj1 = {
  id: 1,
  name: "myName",
  print() { console.log(`${this.id}`) } // Prints the id of the object
}

// Call the function to print a property of an object
printProperty(obj1, "id");
printProperty(obj1, "name");
```

Output:

```
object[id] = 1
object[name] = myName
```

We can see that our `printProperty` function is indeed printing the value of the corresponding property.

Let's now see what happens when we use this function to print the `print` property:

```ts
// Define an object with a unique id, name and print method
let obj1 = {
  id: 1,
  name: "myName",
  print() { console.log(`${this.id}`) } // Prints the id of the object
}

printProperty(obj1, "print");
```

Output:

```
object[print] = function () { console.log("".concat(this.id)); }
```

- We call the `printProperty` function and use the `"print"` property as our second argument.
- We can see that we a re printing out the definition of the `print` function, which corresponds to the value of `obj1["print"]`.

> **Note:** This code does not invoke the function; it simply logs the value of the property, which happens to be a function.

## Generic Interfaces

In the same manner that functions and classes can use generics, we are also able to create interfaces that use generic syntax.

Let's take a look at an example:

```ts
interface IPrint {
  print(): void;
}

interface ILogInterface<T extends IPrint> {
  logToConsole(iPrintObj: T): void;
}

class LogClass<T extends IPrint> implements ILogInterface<t> {
  logToConsole(iPrintObj: T): void {
    iPrintObj.print();
  }
}
```

- We define an interface named `IPrint` that has a single function named `print` that returns `void`.
- We then define an interface named `ILogInterface` that uses generic syntax to define a type `T` that extends the `IPrint` interface. This interface has a single function named `logToConsole`, which has a single parameter named `iPrintObj` of type `T`.
- We have a class definition for a class named `LogClass`, which is also using generic syntax to define a type `T` that extends from the `IPrint` interface. This class implements the `ILogInterface` interface and, as such, must define a `logToConsole` function.

> **Note:** The `ILogInterface` interface requires the type of `T` to implement the `IPrint` interface and uses the generic syntax to define this, that is, `<T extends IPrint>`.

When we define the `LogClass` class, the type `T` must match the interface type definition exactly, that is, it must also be `<T extends IPrint>`.

We can now use this class definition as follows:

```ts
let printObject: IPrint = {
  print() { console.log(`printObject.print() called`) }
}

let lofClass = new LogClass();
logClass.logToConsole(printObject);
```

Output:

```
printObject.print() called
```

- We have an object named `printObject` that implements the `IPrint` interface because it has a `print` function.
- We then create an instance of the `LogClass` class and call the `logToConsole` function with the `printObject` variable as the only argument.

We cn see from the output that the `logToConsole` function of the `LogClass` instance is calling the `print` function of the `printObject` variable.

## Creating New Objects within Generics

From time to time, generic classes may need to create an object of the type that was passed in as the generic type `T`.

Consider the following code:

```ts
class ClassA {}
class ClassB {}

function createClassInstance<T>(arg1: T): T {
  return new arg1();  // error
}

let classAInstance = createClassInstance(ClassA);
```

Output: 

```
index.ts(5,13): error TS2351: This expression is not constructable.
  Type '{}' has no construct signatures.
```

- We define two classes named `ClassA` and `ClassB`.
- We then define a function named `createClassInstance` that uses generic syntax to define the type `T`. This function has a single parameter named `arg1` of type `T`. This function returns a type `T`, and is intended to create a new instance of the class that was passed in as the single `arg1` parameter.
- We can see how we intend to use the `createClassInstance` function. We are calling this function with the class definition of `ClassA` as the only argument. Unfortunately, this code will generate the error we see.

We can see that the compiler will not allow us to construct a new instance of the type `T` in this way. This is because the type of `T` is really of type `unknown` to the function at this stage.

According to the TypeScript documentation, in order for a generic class to be able to construct an object of type `T`, we need to refer to the type `T` by its constructor function.

Our `createClassInstance` function needs to be rewritten as follows:

```ts
function createClassInstance<T>(arg1: { new(): T }): T {
  return new arg1();
}
```

Here, we have modified the `arg1` parameter and are constructing an anonymous type that defines a new function and returns the type `t` &mdash; that is, `arg1: { new() : T }`. In other words, the `arg` parameter is a type that overloads the new function and returns an instance of `T`.

The code will now compile and work as expected.