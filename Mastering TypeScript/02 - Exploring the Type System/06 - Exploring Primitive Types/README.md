# Exploring Primitive Types

> Learn about primitive types and their use in TypeScript, and take a detailed look at `null` and `undefined` types.

## Primitive Types

What are primitive types? In programming, a primitive is a data type that is not derived from any other type and is not an object. They are the most basic types available in a programming language and are typically the building blocks for more complex data structures.

A few of the basic or primitive types that are available in TypeScript are `numbers`, `strings`, and `booleans`. While these represent some of the most basic and widely used types in the language, there are quite a few more, including `undefined`, `null`, `unknown`, and `never`.

Related to these primitive types, we also have some language feeatures, such as conditional expressions and optional chaining, that provide a convenient shorthand method of writing otherwise rather long-winded code.

| **TypeScript Primitive Types** |
| :----------------------------: |
|            `number`            |
|            `string`            |
|           `boolean`            |
|            `never`             |
|           `unknown`            |
|             `null`             |
|          `undefined`           |

## `undefined`

There are a range of circumstances where the value of something in JavaScript is `undefined`.

Let's take a look at an example of this:

```js
let array = ["123", "456", "789"];  // Initialize an array with 3 elements
delete array[0];  // delete the element at index 0 of the array, in this case "123"

// Use a for loop to iterate over the array
for (let i = 0; i < array.length; i++) {
  consol.log(`array[${i}] = ${array[i]}`);  // log the element at the current index of the array
}
```

Output:

```
array[0] = undefined
array[1] = 456
array[2] = 789
```

- We start by declaring a variable that holds an array of strings named `array`.
- Then, on **line 2**, we delete the first element of this array.
- Finally, we use a simple `for` loop on **line 5** to loop through the elements of this array and print the value of the array element to the console.

As we can see, when we run this code, the `array` still has three elements, but the first element has been set to `undefined`, which is the result of deleting this `array` element.

In TypeScript, we can use the `undefined` type to explicitly state that a variable could be undefined, as follows:

```ts
let array = ["123", "456", "789"];  // Initialize an array with 3 elements, "123", "456", and "789"
delete array[0]; // delete the element at index 0 of the array, in this case "123". Using delete leaves a hole in the index and can cause unexpected behavior in many situations. 

// Use a for loop to iterate over the array
for (let i = 0; i < array.length; i++) {
  checkAndPrintElement(array[i]); // call the checkAndPrintElement function with the current element of the array as a parameter
}

// checkAndPrintElement function 
function checkAndPrintElement(arrElement: string | undefined) {
  // check if the passed element is undefined
  if (arrElement === undefined) {
    console.log(`invalid array element`); // If the element is undefined, log the message "invalid array element"
  } else {
    console.log(`valid array element : ${arrElement}`); // Else if the element is defined, log the message "valid array element: " and the element
  }
}
```

Output:

```
invalid array element
valid array element : 456
valid array element : 789
```

- We loop through our `array` on **lines 5-7** and call a function named `checkAndPrintElement`.
- This function spanning through **lines 10-17** has a single parameter named `arrayElement` and is defined as allowing it to be of type `string` or `undefined`. Within the function itself, we check if the array element is, in fact, `undefined` and log a warning message to the console. If the parameter is not `undefined`, we simply log its value to the console.

The `undefined` type, therefore, allows us to explicitly state when we expect a variable to be undefined. We are essentially telling the compiler that we are aware that a variable may not yet have been given a value, and we will write our code accordingly.

## `null`

Along with `undefined`, JavaScript also allows values to be set to `null`. Setting a value to `null` is intended to indicate that a variable is known but has no value, as opposed to `undefined`, where the variable has not been defined in the current scope.

Consider the code:

```ts
// Function that takes a parameter of type 'number' or 'null'
function printValues(a: number | null) {
  console.log(`a = ${a}`); // log the value of a
}

printValues(1);     // call the function with a number value of 1
printValues(null);  // call the function with a null value
```

Output:

```
a = 1
a = null
```

- We define a function named `printValues` on **line 2**, which has a single parameter named `a`, which can be of type `number` or of type `null`. The function simply logs the value to the console.
- We then call this function on **lines 6 and 7** with the values of `1` and `null`, respectively.

When we run this code, we can see that the console logs match the input values that we called the `printValues` function with. Again, `null` is used to indicate that a variable has no value, as opposed to the variable not being defined in the current scope.

## `undefined` vs. `null`

The use of `null` and `undefined` has been debated for many years, with some arguing that `null` is not really necessary and that `undefined` could be used instead.

There are others that argue the exact opposite, stating that `null` should be used in particular cases.

Just remember that TypeScript will warn us if it detects that a value could be `null` or possibly `undefined`, which can help to detect unwanted issues with our code.

> **Note:** It is worth noting that `null` is a more explicit way of indicating that a variable has no value and is mainly used when you want to be clear about the intent of code and explicitly state that you're providing no value, in contrast, `undefined` is often seen as something that happens automatically or by default.