# Transpiling

Learn TypeScript and transpile code into JavaScript for JS-only environments, and understand the fundamentals of the transpilation process.

## `"hello TypeScript"`

When we run a TypeScript file, the TypeScript compiler is responsible for transpiling it into a corresponding JavaScript file. This process is known as **transpiling**, allowing us to run our TypeScript code in environments that only support JavaScript, such as a web browser or a Node server.

## Transpiling Process

Create a file called `hello_typescript.ts` with the corresponding code:

```ts
console.log(`Hello TypeScript`);
```

Now that we have our `hello_typescript.ts` file ready to go, it's time to transpile it into JavaScript using the `tsc` command. To transpile the `hello_typescript.ts` file using `tsc`, run the following command in the terminal:

```bash
tsc hello_typescript.ts
```

This will generate a corresponding JavaScript file called `hello_typescript.js`, which contains the transpiled version of our TypeScript Code. We can then run the JavaScript file in a browser or on a Node.js server to execute the code.

Running the `ls` command again will show the `hello_typescript.ts` and `hello_typescript.js` files in the directory.

It's that easy! With a straightforward command, we've turned out TypeScript code into a format that can be run in any JavaScript runtime environment. Don't take our word for it. Let's test if everything is working as intended or not.

To do this, we can use the `node` command to run the `hello_typescript.js` file in a Node.js runtime environment. Try running the following command:

```bash
node hello_typescript.js
```

This will execute the `hello_typescript.js` file in a Node.js runtime environment, and we should see the output of the program (the message "`Hello TypeScript`") printed to the console.

We should now understand how to transpile a TypeScript file using the `tsc` command and how to run the resulting JavaScript code in a Node.js runtime environment.

## Template Strings and JavaScript Versions

In order to introduce how the TypeScript compiler can make our JavaScript development easier, let's take a quick look at something called **template strings** or template literals. In the previous code snippet, you may have noticed that we used the backtick (`` ` ``) as a string delimiter for the text `Hello TypeScript`.

```ts
console.log(`Hello TypeScript`);
```

If we take a look at the generated JavaScript file (`hello_typescript.js`), we will see that the TypeScript compiler has modified this line of code to use double quotes, as follows:

```js
console.log("Hello TypeScript");
```

This conversion is because template strings are not supported in all versions of JavaScript. The TypeScript compiler must ensure that the generated JavaScript code is compatible with the target JavaScript runtime, and it does this by converting template strings to standard strings when necessary.

The use of the backtick (`` ` ``) to delineate strings gives us the ability to inject values directly into the string, as follows:

```ts
var version = `ES6`;
console.log(`Hello ${version} TypeScripte`);
```

Here, we have declared a local variable named `version`, which holds a string with the value of `ES6`. We have then modified the string we are printing on the console to inject the value of the version string into the middle of the output by using the `${ ... variable name ... }` syntax. If we compile this file and take a look at the generated JavaScript, we will see that this now becomes:

```js
var version = "ES6";
console.log("Hello " + version + " TypeScript");
```

Here, we can see that TypeScript has interpreted our template string, and generated the equivalent JavaScript, which uses double quotes (`"`) to surround each string, and the plus sign (`+`) to concatenate strings.

The use of template strings is actually valid in JavaScript, but there is a significant catch to using them. Template strings have only been introduced into later versions of the JavaScript standard &mdash; in particular, ES2015, also known as the 6th Edition or just ES6. This means that we need an ES6-capable JavaScript runtime in order to use template strings. TypeScript, however, will generate JavaScript based on the version of the JavaScript runtime you are targeting. Just bear in mind, however, that even though a new standard has been published, this does not mean that all internet browsers, or, more correctly, all JavaScript runtimes, will support the new standard immediately.

Most modern internet browsers now suppoert the ES5 standard. Unfortunately, we will have to wait for a number of years before we can say that most modern internet browsers support the ES6 standard. This means that we must be mindful of our target audience, and target runtime if we attempt to use any ES6 features, such as template strings, within code that will be running within a browser.

## TypeScript Project Configuration

TypeScript uses a configuration file named `tsconfig.json` that holds a number of compilation options. We can use the `tsc` command-line compiler to generate a `tsconfig.json` file by using the `--init` command, as follows:

```bash
tsc --init
```

This `--init` option will automatically generate the `tsconfig.json` file within the current directory, which is used, amongst other things, to specify the target JavaScript version. This is how the contents of this file may look like:

```json
{
  "compilerOptions": {
    "target": "ES3",
    "module": "commonjs",
    "strict": true,
    "esModuleInterop": true,
    "skipLibCheck": true,
    "forceConsistentCasingInFileNames": true
  }
}
```

Here, we can see that the `tsconfig.json` file uses standard JSON syntax to specify an object that has one main property named `compilerOptions`, and within this main property, a number of subproperties named `target`, `module`, `strict`, and so on. The `target` property is used to specify the JavaScript version that we would like to generate for, and its value can be one of a number of options. We can find some in the table below:

**TypeScript Configuration**

| Option for `target` Property | Version of JavaScript  |
| ---------------------------- | ---------------------- |
| `"ES3"`                      | ECMAScript 3 (ES3)     |
| `"ES5"`                      | ECMAScript 5 (ES5)     |
| `"ES6"` or `"ES2015"`        | ECMAScript 2015 (ES6)  |
| `"ES2016"`                   | ECMAScript 2016 (ES7)  |
| `"ES2017"`                   | ECMAScript 2017 (ES8)  |
| `"ES2018"`                   | ECMAScript 2018 (ES9)  |
| `"ES2019"`                   | ECMAScript 2019 (ES10) |
| `"ES2020"`                   | ECMAScript 2020 (ES11) |
| `"ESnext"`                   | Latest Version         |

With a `tsconfig.json` file in place, we do not need to specify the name of the TypeScript file that we would like to compile; we can simply type `tsc` on the command line rather than `tsc --init`, followed by the desired version.

Here, the TypeScript compiler is reading the `tsconfig.json` file and applying the compilation values that it finds there to any `.ts` file that it finds in either the current directory or any subdirectories.

This means that in order to compile a TypeScript project that may contain many files in many sub-directories, we just need to type `tsc` in the root directory of the project.

Now that we have changed the target version of JavaScript that we wish to generate for, which is now `ES6`, let's take a look at the output of the compiler in the file `hello_typescript.hs`, as follows:

```js
"use strict";
var version = `es6`;
console.log(`hello ${version} typescript`);
```

Ignoring the `"use strict"` line at the top of this file, we can see that the generated JavaScript has not changed from our original TypeScript file.

This shows that the compiler is correctly generating ES6-compatible JavaScript, even though we have not modified our original TypeScript file.

## Watching Files for Changes

TypeScript also has a handy option that will watch an entire directory tree and if a file changes, it will automatically recompile the entire project.

Let's run the TypeScript compiler in this mode as follows:

```bash
tsc -w hello.ts
```

The output would look something like this:

```
[4:15:16 PM] Starting compilation in watch mode...
[4:15:16 PM] Found 0 errors. Watching for file changes.
```

Here, we can see that the TypeScript compiler is now in watch mode, and is watching files in our project directory for any changes.

