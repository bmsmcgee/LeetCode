# JavaScript Modules

## Modules

  > **Note:** This section uses [CommonJS](https://requirejs.org/docs/commonjs.html) modules throughout

Modules allow developers to organize their codebase within separate files or components for better reusability, flexibility, shareability, and overall maintenance. Multiple modules can be composed together to create an application.

ECMAScript modules, which are a newer feature in JavaScript, are defined with the use of the `import` and `export` keywords.

Although ECMAScript modules are the official standard format to package JavaScript code, they're still considered an experimental Node.js feature as of July 2020. This is because the Node.js team is still working on ensuring backward compatibility and support for both module systems.

CommonJS, which is the legacy system, uses the `module.exports` syntax for exports and the `require()` function for imports:

```js
const {sayHi } = require("./file1.js");  // import
sayHi("Hou");
```

## Named Exports and Importing Modules

There are two different types of `export`: named and default. Each module can have multiple named exports **but only one** default export.

Suppose we need to export several values from the file. Named exports will be helpful here. The file below exports the `sayHi()` function, `person` object, and `greetingInMandarin` string:

```js
export function sayHi (greeting, name) {
  console.log(`Hello, ${name}!`);
};

export const person = {
  firstName: "Hou",
  lastName: "Chia",
};

export let greetingInMandarin = "Ni hao";
```

If multiple values need to be exported from a module, it's typical to create an export list at the bottom of the module so that we don't have to use the `export` keyword repeatedly. This has the advantage of clarifying which values are being exported from the module.

```js
const { sayHi, person, greetingInMandarin } = require("./file1.js");
console.log(sayHi(greetingInMandarin, person.firstName, person.lastName));
```

## Default Exports

If we want to export a single value or have a fallback value for our module, we could use a default export.

Then, we can import the default export in another script as follows:

```js
import greet from "./greeting";
import greeWithHello from "./greeting";  // This import is also valid, as you can reference the imported value using a different variable name
```
