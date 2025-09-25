# Constraining Generic Types with Examples

> Learn how to restrict generic code to a specific set of types using the Concatenator class example.

## Constraining the Type of `T`

In most instances, we will want to limit the type of `T` in order to only allow a specific set of types to be used within our generic code. This is best explained through an example as follows:

```ts
// This class takes an array of strings or numbers and concatenates them into a single string
class Concatenator<T extends Array<string> | Array<number>> {

  // Method that concatenates the array of items into a string
  public concatenateArray(items: T): string {

    // Initialize an empty string to store the concatenated values
    let returnString = "";

    // Loop through each item in the array
    for (let i = 0; i < items.length; i++) {
      // If this is not the first item, add a comma before appending the value
      returnString += i > 0 ? "," : "";

      // Append the current value to the return string
      returnString += items[i].toString();
    }

    // Return the final concatenated string
    return returnString;
  }
}
```

- We have defined a class named `Concatenator` that is using generic syntax and is also constraining the type of `T` to be either an array of strings or an array of numbers via the `extends` keyword. This means that wherever `T` is used within our code, `T` can only be interpreted as either a `string` array or a `number` array.
- This class has a single function named `concatenateArray` that has a single parameter named `items` of type `T` and returns a `string`.
- Within this function, we are simply looping through each element in the argument array named `items` and appending a string representation of the `item` to the variable `returnString`.

We can now use this class as follows:

```ts
// Create a new instance of the Concatenator class
let concator = new Concatenator();

// Concatenate an array of strings
let concatResult = concator.concatenateArray(["first", "second", "third"]);
console.log(`concatResult = ${concatResult}`);

// Concatenate an array of numbers
concatResult = concator.concatenateArray([1000, 2000, 3000]);
console.log(`concatResult = ${concatResult}`);
```

Output:

```
concatResult = first,second,third
concatResult = 1000,2000,3000
```

- We start by creating a new instance of the `Concatenator` class and assign it to the variable named `concator`.
- We call the `concatenateArray` function with an array of strings and assign the result to the variable named `concatResult`, which is of type `string`.
- We print this value to the console.
- We call the `concatenateArray` function with an array of numbers and again print the returned string value to the console.

We can see from the output that our `concatArray` function is returning a string representation of the array that we pass in as an argument.

## Misuse of the Constrained `T`

If we attempt to call this function with an array of booleans, the code will generate an error. Let's take a look at how this happens with the following code:

```ts
// Invalid assignment
concatResult = concator.concatenateArray([
 true, false, true
]);
```

Output:

```
index.ts(40,2): error TS2322: Type 'boolean' is not assignable to type 'string | number'.
index.ts(40,8): error TS2322: Type 'boolean' is not assignable to type 'string | number'.
index.ts(40,15): error TS2322: Type 'boolean' is not assignable to type 'string | number'.
```

Here, we can see that because we constrained the type of `T` in our `Concatenator` class to only allow arrays of `strings` or arrays of `numbers`, the compiler will not allow us to call this function with an array of booleans.