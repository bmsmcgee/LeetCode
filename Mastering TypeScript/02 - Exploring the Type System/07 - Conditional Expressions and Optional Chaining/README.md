# Conditional Expressions and Optional Chaining

> Learn what conditional expressions are and how we can use nested properties through optional chaining

## Conditional Expressions

**Conditional expressions**, also known as ternary expressions, are a feature of JavaScript that allows us to write concise statements that execute different actions depending on a boolean condition. They have the following syntax:

```bash
(conditional) ? ( true statement ) : ( false statement );
```

We can use this JavaScript feature in TypeScript, which uses a question mark (`?`) sumbol to define the `if` statement and a colon (`:`) to define the `then` and `else` paths.

Consider the following code:

```ts
const value: number = 10; // Declare and initialize a number variable

// Declare and initialize a string variable that will hold a message
const message: string = value > 10 ? 
  "value is larger than 10" : 
  "value is 10 or less";

console.log(message); // Print the message to the console
```

Output:

```
value is 10 or less
```

- We start by declaring a variable named `value` on **line 1** of type `number` that is set to the value of `10`.
- We then create a variable named `message` on **line 4**, which is of type `string` and uses the conditional expression syntax to check whether the value of the `value` variable is greater than `10`.

When we run the code, we can see that the `message` variable has been set to the string value of `"value is 10 or less"` because the `value > 10` conditional check returned `false`.

Conditional expressions are a very handy syntax to use in place of the long-winded syntax we would normally have to use in order to code a simple `if-then-else` statement.

> **Note:** Conditional expressions can be chained together, so either the truth statement, the false statement, or both can include another conditional expression.

## Optional Chaining

When using object properties in JavaScript, and in particular nested properties, it is important to ensure that a nested property exists before attempting to access it.

Consider the following JS code:

```js
var objectA = {
  nestedProperty: {
    name: "nestedPropertyName"
  }
}

function printNestedObject(obj) {
  // This function takes in an object as an argument
  console.log("obj.nestedProperty.name = " + obj.nestedProperty.name);
}

// This calls the function, passing in the 'objectA' object as an argument
printNestedObject(objectA);
```

Output:

```
obj.nestedProperty.name = nestedPropertyName
```

- We have an object named `objectA` that has a nested structure. It has a single property named `nestedProperty` on **line 2**, which holds a child object with a single property called `name` on **line 3**.
- We then have a function called `printNestedObject` from **line 7-10** that has a single parameter named `obj`, which will log the value of the `obj.nestedProperty.name` property to the console.
- We then invoke the `printNestedObject` function and pass in `objectA` as the single argument on **line 13**.

As expected, the function works correctly.

Let's now see what happens if we pass in an object that does not have the nested structure that we were expecting.

```js
console.log("calling printNestedObject");
printNestedObject({});
console.log("completed");
```

Output:

```
calling printNestedObject

/usercode/index.js:16
    console.log("obj.nestedProperty.name = " + obj.nestedProperty.name);
                                                                  ^

TypeError: Cannot read property 'name' of undefined
    at printNestedObject (/usercode/index.js:16:67)
    at Object.<anonymous> (/usercode/index.js:21:1)
    at Module._compile (internal/modules/cjs/loader.js:778:30)
    at loader (/usr/local/lib/node_modules/babel-register/lib/node.js:144:5)
    at Object.require.extensions.(anonymous function) [as .js] (/usr/local/lib/node_modules/babel-register/lib/node.js:154:7)
    at Module.load (internal/modules/cjs/loader.js:653:32)
    at tryModuleLoad (internal/modules/cjs/loader.js:593:12)
    at Function.Module._load (internal/modules/cjs/loader.js:585:3)
    at Function.Module.runMain (internal/modules/cjs/loader.js:831:12)
    at Object.<anonymous> (/usr/local/lib/node_modules/babel-cli/lib/_babel-node.js:154:22)
```

As we can see, our code has logged the first message to the console and has caused a JavaScript runtime error.

> **Note:** The final call to log the `"completed"` message to the console has not even executed because the entire program crashed while attempting to read the `name` property on an object that is `undefined`.

This is obviously a situation to avoid, and it can actually happen quite often. This sort of nested object structure is most often seen when working with JSON data.

It is best practice to check that the properties that you are expecting to find are actually there, before attempting to access them.

```ts
// This function takes an object as its input and checks for the existence of the nested property "nestedProperty.name"
function printNestedObject(obj: any) {
  // Check if the input object is defined
  if (obj != undefined
  && obj.nestedProperty != undefined
  && obj.nestedProperty.name) {
    console.log(`name = ${obj.nestedProperty.name}`)
  } else {
    console.log(`name not found or undefined`);
  }
}

let objectA = { nestedProperty: { name: 'John Doe' } };

printNestedObject(objectA); 
```

Output:

```
name = John Doe
```

- We have modified our `printNestedObject` function, which now starts with a long `if` statement spanning from **lines 4-11**.
- This `if` statement first checks whether the `obj` parameter is defined. If it is, it then checks if the `obj.nestedProperty` property is defined and, finally, if the `obj.nestedProperty.name` property is defined. If none of these return `undefined`, the code prints the value to the console. Otherwise, it logs a message to state that it was unable to find the whole nested property.

This type of code is fairly common when working with nested structures and must be put in place to protext our code from causing runtime errors.

The TypeScript team, however, has been hard at work in driving a proposal in order to include a feature named `optional chaining` into the ECMAScript standard, which has now been adopted in the `ES2020` version of JavaScript.

This feature is best described by looking at the following code:

```ts
function printNestedOptionalChain(obj: any) {
  // Check if obj is defined and if it has a property called "nestedProperty"
  if (obj?.nestedProperty?.name) {
    // If the above check passes, log the value of the "name" property
    console.log(`name = ${obj.nestedProperty.name}`);
  } else {
    // If the check fails, lof that the "name" property was not found or is undefined
    console.log(`Name not 0found or undefined`);
  }
}
```

We have a function named `printNestedOptionalChain` that has exactly the same functionality as our previous `printNestedObject` function.

The only difference is that the previous `if` statement, which consisted of three lines, is now reduced to one line. Note how was are using the `?.` syntax in order to access each nestedd property. This has the effect that if any one of the nested properties returns `null` or `undefined`, the entire statement will return `undefined`.

Let's test this theory by calling this function as follows:

```ts
function printNestedOptionalChain(obj: any) {
  // Check if obj is defined and if it has a property called "nestedProperty"
  if (obj?.nestedProperty?.name) {
    // If the above check passes, log the value of the "name" property
    console.log(`name = ${obj.nestedProperty.name}`)
  } else {
    // If the check fails, log that the "name" property was not found or is undefined
    console.log(`name not found or undefined`);
  }
}

printNestedOptionalChain(undefined);
printNestedOptionalChain({
  aProperty: "another property",
});
printNestedOptionalChain({
  nestedProperty: {
    name: null,
  },
});
printNestedOptionalChain({
  nestedProperty: {
    name: "nestedPropertyName",
  },
});
```

Output:

```
name not found or undefined
name not found or undefined
name not found or undefined
name = nestedPropertyName
```

Here, we have called our `printNestedOptionalChain` function four times:
  - The first call on **line 12** sets the entire `obj` argument to `undefined`.
  - The second call on **lines 13-15** has provided a valid `obj` argument, but it does not have the `nestedProperty` property that the code is looking for.
  - The third call on **lines 16-20** has the `nestedProperty.name` property, but it is set to `null`.
  - In the last call on **lines 21-25**, we call the function with a valid object that has the nested structure that we are looking for.

We can see that the optional chaining syntax will return `undefined` if any of the properties within the property chain are either `null` or `undefined`.

Also, optional chaining has been a much-anticipated feature, and the syntax is a welcome sight for developers who are used to writing long-winded `if` statements to ensure that our code is robust and will not fail unexpectedly.