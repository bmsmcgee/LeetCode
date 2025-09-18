# Nullish Coalescing an `null` or `undefined` Operands

> Learn nullish coalescing in TypeScript for default values with `null` or `undefined` variables.

## Nullish Coalescing

In general, it is a good idea to check that a particular variable is not either `null` or `undefined` before using it, as this can lead to errors. TypeScript allows us to use a feature of the 2020 JavaScript standard called **nullish coalescing**, which is a handy shorthand that will provide a default value if a variable is either `null` or `undefined`.

```ts
function nullishCheck(a: number | undefined | null) {
  // Check if the passed variable 'a' is either undefined or null
  // If it is, then print 'undefined or null'
  // Else print the value of 'a'
  console.log(`a : ${a ?? `undefined or null`}`);
}

// Call the function with a number
nullishCheck(1);

// Call the function with null
nullishCheck(null);

// Call the function with undefined
nullishCheck(undefined);
```

Output:

```
a : 1
a : undefined or null
a : undefined or null
```

Here, we have a single function named `nullishCheck` on **lines 1-6** that accepts a single parameter named `a` that can be either a `number`, `undefined`, or `null`.

This function then logs the value of the variable `a` to the console but uses a double question mark (`??`), which is the nullish coalescing operator. This syntax provides an alternative value, which is provided on the right-hand side of the operator, to use if the variable on the left-hand side is either `null` or `undefined`.

We then call this function three times:
  - The first call is with the value `1` on **line 9**. We can see that the first call to the `nullishCheck` function provides the value `1`, and this value is printed to the console untouched.
  - The second call is with the value `null` on **line 12**, and therefore, the function will substitute the string `undefined or null` in place of the value of `a`.
  - The thurd call is with the value `undefined` on **line 15**, and as we can see, the nullish check wil fail over to `undefined or null` in this case as well.

> **Note:** We can also use a function on the right-hand side of the nullish coalescing operator, or indeed a conditional statement as well, as long as the type of the value returned is correct.

## `null` or `undefined` Operands

TypeScript will also aply its checks for `null` or `undefined` when we use basic operands, such as add (`+`), multiply (`*`), divide (`/`), or subtract (`-`).

This can best be seen using a simple example, as follows:

```ts
// This function takes in two parameters, "a" and "b"
// "a" is a number
// "b" is either a number, null, or undefined

function testNullOperands(a: number, b: number | null | undefined) {
  
  // This line declares a variable "addResult" and assigns it the result of adding "a" and "b"
  let addResult = a + b;
  
}
```

Output:

```
index.ts(8,23): error TS18049: 'b' is possibly 'null' or 'undefined'.
```

- We have a function named `testNullOperands` on **line 5** that accepts two parameters:
  - The first, named `a`, is of type `number`.
  - The second parameter, named `b`, can be of type `number`, `null`, or `undefined`.
- On **line 8**, the function creates a variable named `addResult`, which should hold the rest of adding `a` to `b`.

This code will, however, generate an error.

This error occurs because we are trying to add two values, one of which may not be a numeric value. As we have defined the parameter `b` in this function to be of type `number`, `null`, or `undefined`, the compiler is picking up that we can't add `null` to a `number`, not can we add `undefined` to a `number`, hence the error.

A simple fix to this function may be to use the nullish coalescing operator as follows:

```ts
// This function takes in two parameters, "a" and "b"
// "a" is a number
// "b" is either a number, null, or undefined

function testNullOperands(a: number, b: number | null | undefined) {
  
  // This line declares a variable "addResult" and assigns it the result of adding "a" with the value of "b" if b is not null or undefined, otherwise it will use default value 0
  let addResult = a + (b ?? 0);
  
}
```

As we can see, there is no error now. We are using the nullish coalescing operator to substitute the value of `0` for the value of `b` if `b` is either `null` or `undefined`.