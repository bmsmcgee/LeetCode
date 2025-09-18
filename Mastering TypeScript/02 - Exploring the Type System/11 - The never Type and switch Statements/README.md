# The `never` Type and `switch` Statements

> Learn about the `never` type and how it's used with `switch` statements in TypeScript.

## The `never` Type

The final primitive type in the TypeScript collection is a type of `never`. This type is used to indicate instances where something should never occur. Even though this may sound confusing, we can often write code where this occurs.

Consider the following code:

```ts
// Define a function that always throws an error
function alwaysThrows() {
  // Throw an error with a specified message
  throw new Error("this will always throw");

  // Return a value, but it will never be reached because of the thrown error
  return -1;
}

alwaysThrows();
```

- We have a function named `alwaysThrows()` on **lines 2-8**, which will, according to its logic, always throw an error.
- Remember that once a function throws an error, it will immediately return, and no other code in the function will execute. This means that **line 7**, which returns a value of `-1`, will never execute.

This is where the `never` type can be used to guard against possible logic errors in our code.

Let's change the function definition to return a type of `never`, as follows:

```ts
// Define a function that always throws an error and returns never
function alwaysThrows(): never {
  // Throw an error with a specified message
  throw new Error("this will always throw");
  
  // Return a value, but it will never be reached because of the thrown error
  return -1;
}

alwaysThrows();
```

Output:

```
index.ts(7,3): error TS2322: Type 'number' is not assignable to type 'never'.
```

- With the addition of the return type of `never` for this function on **line 2**, the compiler will now generate the error.

This error message is clearly telling us that the function, which returns a type of `never`, is attempting to return the value of `-1`. The compiler, therefore, has identified a flaw in our logic.

## The `never` Type with `switch` Statements

A more advanced use of the `never` type can be used to trap logic errors within `switch` statements.

Consider the following code:

```ts
// Define an enumeration with two values
enum AnEnum {
  FIRST,
  SECOND
}

// Define a function that takes an enumeration value and returns a string
function getEnumValue(enumValue: AnEnum): string {
  // Use a switch statement to determine which enumeration value was passed
  switch (enumValue) {
    // Return a string for the FIRST enumeration value
    case AnEnum.FIRST: return "First Case";
  }

  // Declare a variable to store the return value, with a type of never
  let returnValue: never = enumValue;

  // Return the value
  return returnValue;
}
```

Output:

```
index.ts(16,7): error TS2322: Type 'AnEnum' is not assignable to type 'never'.
```

- We start with a definition of an `enum` named `AnEnum` from **lines 2-5**, which has two values, `FIRST` and `SECOND`.
- We then define a function named `getEnumValue`, which spans through **lines 8-13**, has a single parameter named `enumValue` of type `AnEnum`, and returns a `string`. The logic within this function is pretty simple and is designed to return a string based on the `enumValue` passed in.

> **Note:** The `switch` statement only has a `case` statement for the `FIRST` value of the enum but does not have a `case` statement for the `SECOND` value of the enum. This code, therefore, will not work correctly if we call the function with `AnEnum.SECOND`. This is where the **lines 16 and 19** of this function come in handy.

Let's take a closer look at this code.
  - After our `switch` statement on **line 10**, we define a variable named `returnValue`, which is of type `never`. The trick in this code is that we assign the value of the incoming parameter, `enumValue`, which is of type `AnEnum`, to the `returnValue` variable, which is of type `never`. This statement is generating the error.
  - The TypeScript compiler is examining our code and determining that there is a `case` statement missing for the `AnEnum.SECOND` value.
  - In this case, the logic falls through the `switch` statement and then attempts to assign the `AnEnum.SECOND` value to a variable of type `never`, hence the error.

This code can be easily fixed as follows:

```ts
// Define an enumeration with two values
enum AnEnum {
  FIRST,
  SECOND
}

// Define a function that takes an enumeration value and returns a string
function getEnumValue(enumValue: AnEnum): string {
  // Use a switch statement to determine which enumeration value was passed
  switch (enumValue) {
    // Return a string for the FIRST enumeration value
    case AnEnum.FIRST: return "First Case";
    // Return a string for SECOND enumeration value
    case AnEnum.SECOND: return "Second Case";
  }

  // Declare a variable to store the return value, with a type of never
  let returnValue: never = enumValue;

  // Return the value
  return returnValue;
}
```

We have added the missing `case` statement on **line 14** to handle the `AnEnum.SECOND` value. With this in place, the error is resolved. While this may be fairly easy to spot in a simple example like this, this sort of error is commonplace when working with large code bases.

Over time, developers often add values to an `enum` to get their unit tests to work but can easily miss these missing `case` statements. Using the `never` type here safeguards our code so that we can pick up these errors earlier.