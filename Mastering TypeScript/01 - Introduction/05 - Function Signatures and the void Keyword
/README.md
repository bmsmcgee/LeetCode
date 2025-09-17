# Function Signatures and the `void` Keyword

> Learn how to use type annotations in TypeScript to strongly type function signatures.

## Function Signatures in TypeScript

One of the best features of using type annotations in TypeScript is that they can also be used to strongly type function signatures.

To explore this feature a little further, let's write a JavaScript function to perform a calculation as follows:

```js
// This function calculates the result of (a * b) + c
function calculate(a, b, c) {
  
  // Return the result of (a * b) + c
  return (a * b) + c;
  }

// Log the result of calling the calculate function with arguments 3, 2 and 1
console.log("calculate() = " + calculate(3, 2, 1));
```

Output:

```
calculate() = 7
```

Here, we have defined a JavaScript function named `calculate` from **lines 2 &mdash; 6** that has three parameters, `a`, `b`, and `c`.

Within this function, we are multiplying `a` and `b`, and then adding the value of `c`.

The result is correct, as $2\times 3 = 6$, and $6 + 1 = 7$.

Now, let's see what happens if we incorrectly call the function with strings instead of numbers, as follows:

```js
// This function calculates the result of (a * b) + c
function calculate(a, b, c) {
  
  // Return the result of (a * b) + c
  return (a * b) + c;
  }

// Log the result of calling the calculate function with arguments "2", "3", and "1"
console.log("calculate() = " + calculate("2", "3", "1"));
```

Output:

```
calculate() = 61
```

The result of `61` is very different from the expected result of `7`. So, what is going on here?

If we take a closer look at the code in the calculate function, we can figure out what JavaScript does when it tries to mix variables of different types. The product of two numbers, that is, `(a * b)`, will generate a numeric value. So, even though our values of `a` and `b` are strings, JavaScript will attempt to convert these numbers before multiplying them together. So, we end up with $3\times 2=6$.

Unfortunately, the `+` operator can be used on both numbers and strings and if one of the arguments is a string, JavaScript will convert both to strings prior to addition.

This results in the string `"6"` being appended to the string `"1"`, resulting in the string `"61"`.

This code snippet is an example of how JavaScript can modify the type of a variable depending on how it is actually used. This means that in order to work effectively with JavaScript, we need to be aware of this sort of type conversion and understand when and where it could take place. Obviously, these sorts of automatic type conversions can cause unwanted behaviour in our code.

Let's now write the equivalent function in TypeScript, but this time specify that all arguments must be of type `number`, as follows:

```ts
// This function takes three numbers and calculates the result of (a * b) + c to return the resulting number.
function calculate(a: number, b: number, c: number): number {

    // Return the result of (a * b) + c
    return (a * b) + c;
}


// Log the result of calling the calculate function with arguments 2, 3, and 1
console.log(`calculate() = ${calculate(2, 3, 1)}`);
```

Output:

```
calculate() = 7
```

- On **line 2**, we specify that the arguments `a`, `b`, and `c` in our TypeScript version of the `calculate` function must all be of type `number`. In addition to this, we specify the return type of the entire function to be of type `number` by placing a type annotation at the end of the function definition, that is, `: number { ... }`. This also ensures that the caller of this function knows that the function will return a value of type `number`.

With our function definition now specifying a type for each argument, attempting to call this function with strings will fail, as follows:

```ts
// This function takes three numbers and calculates the result of (a * b) + c to return the resulting number.
function calculate(a: number, b: number, c: number): number {

    // Return the result of (a * b) + c 
    return (a * b) + c;
}

// Log the result of calling the calculate function with arguments "2", "3", and "1"
console.log(`calculate() = ${calculate("2", "3", "1")}`);
```

Output:

```
index.ts(9,40): error TS2345: Argument of type 'string' is not assignable to parameter of type 'number'.
```

This error message clearly tells us that we can't use a string as an argument where a numeric argument is expected. We also can't use the value that is returned by the function incorrectly, as follows:

```ts
// This function takes three numbers and calculates the result of (a * b) + c to return the resulting number.
function calculate(a: number, b: number, c: number): number {

    // Return the result of (a * b) + c 
    return (a * b) + c;
}

// Declaring a variable of string type
var returnedValue: string = calculate(3, 2, 1);
```

Output:

```
index.ts(9,5): error TS2322: Type 'number' is not assignable to type 'string'.
```

So, the TypeScript compiler is also telling us that the return value of the `calculate` function is of type `number`, and so we can't assign it to a variable that is of type `string`.

## The `void` Keyword

We have taken an in-depth look at functions that return a value, but what about functions that do not return a value? This is where the TypeScript keyword `void` comes in handy.

```ts
// This function takes in a string as a parameter and does not return anything
function printString(a: string) : void {
  // This line logs the string passed as an argument to the console
  console.log(a);
}

// This variable is declared as a string type and is assigned the return value of the printString function
var returnedValue : string = printString("this is a string");
```

Output:

```
index.ts(8,5): error TS2322: Type 'void' is not assignable to type 'string'.
```

- We define a function named `printString` from **lines 2 &mdash; 5** that takes a single parameter named `a`f, which is of type `string`. We have also specified that this function will not return a value by using the return type of `void`.

The last line of this code snippet will, therefore, generate the error. This error message tells us that the `printString` function does not return anything and therefore returns a type of `void`. If we attempt to assign something of a `void` type to a string, we will generate this type of error.
