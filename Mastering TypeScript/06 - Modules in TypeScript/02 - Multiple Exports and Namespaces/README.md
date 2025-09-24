# Multiple Exports and Namespaces

> Learn how to import multiple symbols from a module using named imports or the `*` as syntax for namespace attachment.

## Multiple Exports

When working with external libraries &mdash; that is, libraries that have been published for general consumption &mdash; it is common practice for a published library to export all classes, functions, and interfaces from a single module file.

This means that we do not need to know how this library is structured or how complex the class hierarchy is internally; we simply import the entire library from one file.

As an example of this technique, suppose we have a file named `modules/MultipleExports.ts`, as follows:

```ts
// This is a TypeScript code that exports two classes, MultipleClass1
// and MultipleClass2, using the 'export' keyword.

export class MultipleClass1 {}
export class MultipleClass2 {}

// It's worth noting that these classes are empty, meaning they don't have any properties
// or methods defined within them.
```

- We export two classes from this module file, which are named `MultipleClass1` and `MultipleClass2`

We can then import both of these classes in our `modules_main.ts` file as follows:

```ts
// Importing MultipleClass1 and MultipleClass2 from the "MultipleExports" module using
// destructuring syntax

import { MultipleClass1, MultipleClass2 }
 from "./modules/MultipleExports";

// Instantiating a new object of class MultipleClass1 and assigning it to the variable "mc1"
let mc1 = new MultipleClass1();

// Instantiating a new object of class MultipleClass2 and assigning it to the variable "mc2"
let mc2 = new MultipleClass2();
```

- We are using the standard `import` syntax but have included both the `MultipleClass1` and `MultipleClass2` classes as named classes in our `import` statement in a comma-separated list.

Because we have named both of these classes on our `import`, we can create instances of these classes as normal.

## Modular Namespaces

There is, however, another syntax that we can use to import multiple symbold from a module. This syntax will import all available exports from a module, without naming each of them individually, by attaching them to a namespace, as follows:

```ts
// Import all exports from the "MultipleExports" module and assign
// them to the "MultipleExports" variable

import * as MultipleExports from "./modules/MultipleExports";

// Create a new instance of the "MultipleClass1" class from the imported module
// and assign it to the "meMc1" variable
let meMc1 = new MultipleExports.MultipleClass1();

// Create a new instance of the "MultipleClass2" class from the imported module
// and assign it to the "meMc2" variable
let meMc2 = new MultipleExports.MultipleClass2();
```

- We are not importing individual classes from the `ModuleExports.ts` file by naming each of them one by one. We are instead importing everything that has been exported by using the `*` as syntax.
- We are creating an instance of the `MultipleClass1` class and the `MultipleClass2` class, but in doing so, we must reference them both using the namespace &mdash; that is, `MultipleExports.MultipleClass1` and `MultipleExports.MultipleClass2`.

## Default Exports

A module file can also mark an exported item as the default export for the file using the `default` keyword. While this is generally not used for class definitions, it is sometimes used for function definitions.

Let's create a new file named `modules/DefaultExport.ts` as follows:

```ts
// This TypeScript code exports a default function named `DefaultAdd`
// that takes two arguments of type `number`, adds them together, 
// and returns the sum.
export default function DefaultAdd(
  a: number,
  b: number
) {
  return a + b; // Adds the two arguments and returns the sum
}

// This code exports a non-default class named `ModuleNonDefaultExport`
export class ModuleNonDefaultExport { } // An empty class definition
```

- We have exported a function named `DefaultAdd` that will return the sum of two numbers. This function has also been marked with the `default` keyword.
- We are also exporting a class named `ModuleNonDefaultExport`.

We can now import this default function as follows:

```ts
import DefaultAdd from "./modules/DefaultExport";

let modDefault = DefaultAdd(1, 2);
```

- We use a very simple syntax for importing the `DefaultAdd` function. We do not need to use the curly braces but instead target the default export function by name.
- We then invoke the `DefaultAdd` function to add two numbers and assign the return value to a variable named `modDefault`.

The `DefaultExcport.ts` module, however, also exports a class named `ModuleNonDefaultExport`. We are still able to use this class, but it must be imported using the standard import syntax as follows:

```ts
import DefaultAdd, { ModuleNonDefaultExport }
 from "./modules/DefaultExport";
 
let modNonDefault = new ModuleNonDefaultExport();
```

- We have updated our `import` statement to include the `ModuleNonDefaultExport` class using the standard import syntax that surrounds the class name with curly braces.

We are then able to use the class as usual within our code.