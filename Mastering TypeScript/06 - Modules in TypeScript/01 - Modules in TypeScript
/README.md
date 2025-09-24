# Modules in TypeScript

> Learn how to create, export, and import modules in TypeScript to modularize and structure our codebase.

## Introduction to Modules in TypeScript

Modularization is a popular technique used in programming languages that allows programs to be built from a serioes of smaller libraries or modules. This technique is also applied to object-oriented code bases, where each class is typically housed in its own file. When referencing classes that exist in another source file, we need a mechanism for the TypeScript compiler, as well as the JavaScript runtime, to be able to locate the class that we are referencing. This is where modules are used.

TypeScript has adopted the module syntax that is part of ES2015. This means that we can use this syntax when working with modules, and the compiler will generate the relevant JavaScript to support modules based on the target JavaScript version we have selected. There is no change in syntax, and there is no change in our code in order to support earlier versions of the JavaScript runtime.

## Exporting Modules

There are two things that we need in order to write and use modules.

Firstly, a module needs to expose something to the outisde world in order for it to be consumed. This is called exporting a symbol from a module and uses the TypeScript keyword `export`.

As an example of this, suppose we create a source directory named `modules`, and within this `modules` directory, a file named `Module1.ts` contains the following code:

```ts
// This is the definition of a class named Module1
export class Module1 {
  // This is the definition of the 'print' method of the Module1 class
  // It does not return anything (as specified by the 'void' type), it just calls the 'localPrint' function
  print(): void {
    localPrint(`Module1.print() called`);
  }
}

// This is the definition of a function named 'localPrint'
// It takes a single argument of type 'string'
function localPrint(text: string) {
  // This line logs the text argument to the console
  console.log(`localPrint: ${text}`);
}
```

- We define a class named `Module1` that uses the `export` keyword to mark it as consumable outside of this file. This class has a single function named `print`, which is calling another function named `localPrint` to print a message to the console.
- We then have the definition of the `localPrint` function, which takes a single parameter named `text` of type `string`, and logs a message to the console.

What is important about the `localPrint` function is that it has not been marked with the `export` keyword. This means that the `localPrint` function is not available outside of the `Module`.ts` module and has a private scope.

Another point to note with this file is that even if the `Module1` class is used in another file, it will stil have access to its privately scoped `localPrint` function.

## Importing Modules

In order to consume a sumbol that has been exported, any source file that needs this module must import it using the `import` keyword.

Let's take a lok at this `import` syntax:

```ts
// Import the Module1 class from the "./modules/Module1" module
import { Module1 } from "./modules/Module1";

// Create an instance of the Module1 class
let mod1 = new Module1();

// Call the `print` method on the mod1 instance
mod1.print();
```

Output:

```
localPrint: Module1.print() called
```

- We use the `import` keyword to import the definition of the `Module1` class from the `modules/Module1` file.

> **Note:** Take a look at the syntax that we are using. Following the `import` statement is a name in braces `{ Module1 }`, which is the name that we will use for the imported class. Also, note that we do not specify a `.ts` or a `.js` extension when importing modules. The module loader will take care of locating the correct file on the disk.

- Once the class has been imported, we can use the class definition of `Module1` as normal. We create an instance of this class named `mod1` and then call the `print` function.

We can see that the `print` function on the `Module1` class is indeed calling the `localPrint` function that was defined within the `Module1.ts` file, which was privately scoped.

Even though we only imported the `Module1` class itself, this class still has access to any privately scoped functions defined in its source file.

## Renaming Modules

When importing a symbol from a module, we can also choose the name that we want to use when referencing the exported symbols within it, as follows:

```ts
// Import the "Module1" module from the "./modules/Module1" file and rename it to "MyMod1".
import { Module1 as MyMod1 } from "./modules/Module1";

// Create a new instance of the "MyMod1" module and assign it to a variable "myRenamedMod".
let myRenamedMod = new MyMod1();

// Call the "print" method on the "myRenamedMod" object.
myRenamedMod.print();
```

- We have another `import` statement that is importing the class from the `modules.Module1` file. Note that we have used the `as` keyword when specifying the module name &mdash; that is, `{ Module1 as MyMod1 }`. This means that we have renamed the class that has been exported from `Module1` to `MyMod1` within this file.
- We then use this renamed class name to create an instance of the `MyMod1` class (which really is the `Module1` class) named `myRenamedMod`. We then call the print function on this class instance.