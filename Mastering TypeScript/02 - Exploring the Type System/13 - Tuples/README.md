# Tuples

> Learn tuples in TypeScript, including named element types, tuple destructuring, optional elements, and spread syntax for variable-sized tuples.

## Introduction to Tuples in TypeScript

Tuples are a method of defining a type that has a finite number of unnamed properties, with each property having an associated type. When using a tuple, all of the properties must be provided.

This can best be explained in an example as follows:

```ts
// Decalre a tuple called tuple1 with elements of type string and boolean
let tuple1: [string, boolean];

// Assign values "test" and true to the tuple
tuple1 = ["test", true];

// This assignment is incorrect as it is missing a second element of type boolean
// and will result in a TypeScript error
tuple1 = ["test"];
```

- We define a variable named `tuple1` on **line 2**, whose type is defined as an array of types. The first type is a `string`, and the second type is a `boolean`.
- We then assign a value to the `tuple1` variable on **line 5** that contains an array with two values: the first of type `string` and the second of type `boolean`.

Note that **line 9** of this code generates an error because it attempts to assign a value to the `tuple1` variable that does not have all of the properties that are required.

What this error is telling us is that the number and types defined in a typle must be provided when we assign anything to a tuple.

## Tuple Destructuring

As tuples use the array syntax, they can be destructed or disassembled in two ways.

The first way of destructuring a tuple uses the simple array syntax, as follows:

```ts
// Print the first element of tuple1
console.log(`tuple1[0] : ${tuple1[0]}`);

// Print the second element of tuple1
console.log(`tuple1[1] : ${tuple1[1]}`);
```

Output:

```
tuple1[0] : test
tuple1[1] : true
```

- We are logging the values of the `tuple1` variable to the console by referencing its index within the array, that is, `tuple1[0]` and `tuple1[1]`.

> **Note:** The compiler knows that there are only two elements of this array, and if we attempt to access the third value within this tuple &mdash; that is, `tuple1[2]` &mdash; the compiler will generate an error.

Another way of destructuring a tuple is to use the array syntax to create an array of named elements and then assign the value of the tuple to this variable, as follows:

```ts
// Destructuring assignment to extract values from tuple1
let [tupleString, tupleBoolean] = tuple1;

// Print the value of tupleString
console.log(`tupleString = ${tupleString}`);

// Print the value of tupleBoolean
console.log(`tupleBoolean = ${tupleBoolean}`);
```

Output:

```
tupleString = test
tupleBoolean = true
```

- We use the array syntax to create a tuple out of two variable names on **line 2**, that is, `tupleString` and `tupleBoolean`.
- We then assign the value of our original `tuple`, that is, `tuple1`, to this array of named variables on **lines 5 and 8**.
- We can then use these named variables instead of needing to access them using the standard array syntax, that is, `tuple1[0]`.

When we run the code, we can see that the tuple has been correctly destructured into our two named variables, `tupleString` and `tupleBoolean`.

Using the named variable syntax to destructure tuples is a better way of constructing our code, as we can name the variable according to how it will be used.

## Optional Tuple Elements

The tuple elements can be marked optional by using the question mark (`?`) after the type, as follows:

```ts
// Declare a tuple called tupleOptional with elements of type string and optional boolean
let tupleOptional: [string, boolean?];

// Assign values "test" and true to the tuple
tupleOptional = ["test", true];

// Assign values "test" to the tuple with the second element being optional
tupleOptional = ["test"];

// Print the first element of tupleOptional
console.log(`tupleOptional[0] : ${tupleOptional[0]}`);

// Print the second element of tupleOptional, which may be undefined
console.log(`tupleOptional[1] : ${tupleOptional[1]}`);
```

Output:

```
tupleOptional[0] : test
tupleOptional[1] : undefined
```

- We define a tuple named `tupleOptional` on **line 2** that consists of two elements, a `string`, and an optional `boolean` value.
- We then assign the values of `["test", true]` to this tuple on **line 5**, and then we assign just the value `["test"]` to this tuple on **line 8**. As the second element has been marked as optional, we do not need to specify it.
- We then log the values of the tuple elements to the console using array syntax.

When we run this code, we can see that the tuple value at index `0` has been set to the value of `"test"`, but that the tuple at index `1` is `undefined` as it was not specified in our last assignment statement.

## Tuples and Spread Syntax

We are also able to use spread syntax to define a tuple that can have a variable number of elements.

Consider the following code:

```ts
// Declare a tuple called tupleRest with elements of type number and an array of strings
let tupleRest: [number, ...string[]];

// Assign a value of 1 to the first element of the tuple, and an empty array of strings to the rest
tupleRest = [1];

// Assign a value of 1 to the first element of the tuple, and an array with one element "string1" to the rest
tupleRest = [1, "string1"];

// Assign a value of 1 to the first element of the tuple, and an array with two elements "string1" and "string2" to the rest
tupleRest = [1, "string1", "string2"];
```

- We use spread syntax on **line 2** to indicate that the variable named `tupleRest` has a number of elements, followed by a variable number of string elements.
- We then assign values to this tuple, starting with a single numerical value and then a numerical value and a variable number of string values. All of these assignments are valid.

## Object Destructuring

In a similar way to tuples, standard objects can also be destructured.

Consider the following example:

```ts
// Declare an object literal with properties aNum, bStr, and cBool
let complexObject = {
 aNum: 1,
 bStr: "name",
 cBool: true
}

// Destructuring assignment to extract properties from complexObject
let { aNum, bStr, cBool } = complexObject;
```

- We define an object named `complexObject` from **lines 2-6** that has three properties: `aNum`, `bStr`, and `cBool`. Each of these properties has been assigned a value.
- We then destructure this object into three separate variables, named `aNum`, `bStr`, and `cBool`, in a similar manner to how we destructured tuples.

We can now use these variables as follows:

```ts
// Print the value of aNum, bstr and cBool
console.log(`aNum : ${aNum}`);
console.log(`bStr : ${bStr}`);
console.log(`cBool : ${cBool}`);
```

Output:

```
aNum : 1
bStr : name
cBool : true
```

We are using the aNum, bStr, and cBool variables that we created when destructuring the `complexObject` object. As we can see from this output, we are able to destructure simple objects into a series of variables, which allows us to access the value of these properties through our standard variable naming syntax.

Note that we are also able to rename the variable names during the destructuring step as follows:

```ts
// Destructuring assignment with property renaming to extract properties from complexObject
let { aNum: objId, bStr: objName, cBool: isValid } = complexObject;

// Print the value of objId, which was destructured from property aNum
console.log(`objId : ${objId}`);

// Print the value of objName, which was destructured from property bStr
console.log(`objName : ${objName}`);

// Print the value of isValid, which was destructured from property cBool
console.log(`isValid : ${isValid}`);
```

Output:

```
objId : 1
objName : name
isValid : true
```

Here, we are destructuring the `complexObject` into a series of variables. Note the use of the colon (`:`) in this example on **line 2**. We are using the colon to rename the `aNum` property into the `objId` variable, using the syntax `aNum: objId`.

Similarly, the `bStr` property is renamed to a variable named `objName`, and the `cBool` property is renamed to a variable called `isValid`. The colon (`:`) symbol here does not specify a type as it normally would, but instead is used to rename the variable name used in destructuring.