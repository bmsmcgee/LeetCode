# Enums

> Learn how to use TypeScript enums to define named value sets for variables or function parameters.

## Introduction to Enums

Enums are a special type whose concept is similar to other languages, such as C#, C++, or Java, and provides the solution to the problem of special numbers or special strings.

Enums are used to define a human-readable name for a specific number or string.

Consider the following code:

```ts
// Define an enum with the values 'Open' and 'Closed'
enum DoorState {
  Open,
  Closed
}

// Declare a function that takes an argument of type 'DoorState'
function checkDoorState(state: DoorState) {
  // Print the enum value to the console
  console.log(`enum value is: ${state}`);


  // User a switch statement to check the value of 'state'
  switch (state) {
    // If 'state' is 'Open', print a message to the console
    case DoorState.Open:
      console.log(`Door is open`);
      break;
    // If 'state' is 'Closed', print a message to the console
    case DoorState.Closed:
      console.log(`Door is closed`);
      break;
  }
}
```

- We start by using the `enum` keyword to define an enum named `DoorState` on **line 2**. This `enum` has two possible values, either `Open` or `Closed`.
- We then have a function named `checkDoorState` on **lines 8-23** that has a single parameter named `state` of type `DoorState`. This means tha the correct way to call this function is with one of the values that the `DoorState` enum provides us.
- This function starts by logging the actual value of the state parameter to the console according to the statement on **line 10** and then executes a `switch` statement. This `switch` statement spanning through **lines 13-22** simply logs a message to the console depending on the value of the state parameter that was passed in.

We can now run this code as follows:

```ts
// Calling the 'checkDoorState' function with the 'Open' state as an argument
checkDoorState(DoorState.Open);

 // Calling the 'checkDoorState' function with the 'Closed' state as an argument
checkDoorState(DoorState.Closed);
```

Output:

```
enum value is : 0
Door is open
enum value is : 1
Door is closed
```

- We call the `checkDoorState` function on **lines 2 and 5**, once for each possible value within the `DoorState` enum.

When we run this code, we can clearly see that the compuler has generated a numerical value for each of our defined enum values. The numerical value for the enum value `DoorState.Open` is `0`, and likewise, the numerical value of `DoorState.Closed` has been set to `1`. This all occurs under the hood.

Using enums helps us to provide a clear set of values for a variable or function parameter. They also provide a tried and tested way of eliminating so-called *"magic numbers"* by defining a limited number of possible values.

One last note on enums is that we can set the numerical value of an enum value to whatever we like, as shown in the following code:

```ts
enum DoorStateSpecificValues {
  Open = 3,
  Closed = 7,
  Unspecified = 256
}
```

- We define an enum named `DoorStateSpecificValues` spanning through **lines 1-5**, that has three possible values, `Open`, `Closed`, and `Unspecified`.
- We have also overrideen the default values for this enum such that the `Open` value will be `3`, the `Closed` value will be `7`, and the `Unspecified` value will be `356`.

## String Enums

A further variant of the `enum` type is what is known as a **string enum**, where the numerical values are replaced with strings, sa follows:

```ts
enum DoorStateString {
  OPEN = "Open",
  CLOSED = "Closed"
}
console.log(`OPEN = ${DoorStateString.OPEN}`);
```

Output:

```
OPEN = Open
```

- We have an enum named `DoorStateString` and have replaced the numerical values with string values for each of the defined enum values on **lines 2 and 3**.
- On **line 5**, we then log a message to the console with value of the `DoorStateString.OPEN`.

## `const` Enums

The final variant of the enum family is called the **const enum**, which adds the `const` keyword before the `enum` definition, as follows:

```ts
// Declare a constant enum called DoorStateConst
const enum DoorStateConst {
  // The value of 'Open' is set to 10
  Open = 10,
  // The value of 'Closed' is set to 20
  Closed = 20
}

// Log the string 'const Closed = [value of DoorStateConst.Open]' to the console
console.log(`const Closed = ${DoorStateConst.Closed}`);
```

Output:

```
const Closed = 20
```

- We define a `const` `enume` named `DoorStateConst` on **lines 2-7**, providing two possible values: `Open` and `Closed`.
- On **line 10**, we log the value of the `DoorStateConst.Closed` enum value to the console.

The `const` `enums` have been introduced for performance reasons.