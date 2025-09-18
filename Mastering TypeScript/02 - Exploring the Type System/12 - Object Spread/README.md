# Object Spread

> Learn about object spread and how to leverage it in TypeScript for cleaner and more efficient code.

## Introduction to Object Spread

When working with basic JavaScript objects, we often need to copy the properties of one object to another or do some mixing and matching of properties from various objects. In TypeScript, we can use an ES7 technique known as object spread to accomplish this.

Consider the following code:

```ts
// Define firstObj with properties id and name
var firstObj = { id: 1, name: "firstObj" };

// Copy the properties of firstObj tosecondObj using object spread syntax
var secondObj = { ...firstObj };

// Log the secondObj to the console
console.log(`secondObj : ${JSON.stringify(secondObj)}`);
```

Output:

```
secondObj : {"id":1,"name":"firstObj"}
```

- We define a variable named `firstObj` on **line 2** that is of type `object` and has an `id` property and a `name` property.
- We then define a variable named `secondObj` on **line 5** and use the object spread syntax of three dots (`...`) to assign a value to it. The value we are assigning is an object that is made up of the `firstObj` variable, that is, `{ ...firstObj }`.

When we run this code, we can see that the `id` and `name` properties and values have been copied into the new `secondObj` variable.

We can also use this technique to combine multiple objects together.

Consider the following code:

```ts
// Define an object named nameObj with a single property 'name'
let nameObj: object = { name: "nameObj name" };

// Define an object named idObj with a single property 'id'
let idObj: object = { id: 1 };

// Use the spread syntax (three dots ...) to combine the properties of nameObj and idObj into a new object named obj3
let obj3 = { ...nameObj, ...idObj };

// Log the stringified value of obj3 to the console
console.log(`obj3 = ${JSON.stringify(obj3)}`);
```

Output:

```
obj3 = {"name":"nameObj name","id":1}
```

- We have defined a variable named `nameObj` on **line 2** that has a single property called `name`.
- We then have a variable named `idObj` on **line 5** that has a single property named `id`.

> **Note:** We are using the spread syntax to create a variable named `obj3` that is the result of combining the properties of `nameObj` and the properties of the `idObj` variables.

The output of the code shows us that the properties of both objects have been merged into the `obj3` variable using the object spread syntax.

## Spread Precedence

When using object spread, properties will be copied incrementally. 

In other words, if two objects have a property with the same name, then the object that was specified last will take precedence.

As an example of this, consider the following:

```ts
// Define a variable named objPrec1 of type object with properties id and name
let objPrec1: object = { id: 1, name: "obj1 name" };

// Define a variable named objPrec2 of type object with properties id and desc
let objPrec2: object = { id: 1001, desc: "obj2 description" };

// Use the object spread syntax to merge the properties of objPrec1 and objPrec2 into a new object, objPrec3
let objPrec3 = { ...objPrec1, ...objPrec2 };

// Log the contents of objPrec3 to the console using JSON.stringify() with 4 spaces of indentation
console.log(`objPrec3 : ${JSON.stringify(objPrec3, null, 4)}`);
```

Output:

```
objPrec3 : {
    "id": 1001,
    "name": "obj1 name",
    "desc": "obj2 description"
}
```

- We have defined two variables named `objPrec1` and `objPrec2` on **line 2** and **line 5**, respectively. Both of these objects have an `id` property; however, `objPrec1` has a `name` property, and `objPrec2` has a `desc` property.
- We then create a variable named `objPrec3` on **line 8** that is a combination of these two objects.
- Finally, on **line 11**, we print the value of the `objPrec3` object to the console.

From the output, we can see that the spread operator has combined the properties of both original objects into the `objPrec3` variable.

> **Note:** The `id` property was common between both original objects, and the value of `1001` has taken precedence in this case because it has been taken from the object that was specified last.

## Spread with Arrays

Interestingly, the spread syntax can also be used with arrays.

Consider the following code:

```ts
let firstArray = [1, 2, 3];
let secondArray = [3, 4, 5];

// Merge the two arrays into a third array using the spread operator
let thirdArray = [...firstArray, ...secondArray];

// Print the third array to the console
console.log(`third array = ${thirdArray}`);
```

Output:

```
third array = 1,2,3,3,4,5
```

- We have defined two arrays named `firstArray` and `secondArray` on **lines 1 and 2**, respectively.
- We then use the spread syntax to combine these two arrays into another variable named `thirdArray` on **line 5**.
- On **line 8**, we then print the value of the `thirdArray` variable to the console.

Looking at the output of the code, we see that the contents of the two arrays have been combined into the `thirdArray` variable.

Interestingly, the new array contains the value `3` twice because it was present in both arrays.

> **Note:** This syntax can be used on arrays of any type. The spread syntax can also appear in any order.

Consider the following code:

```ts
// Create an array of objects with a single element
let objArray1 = [
  { id: 1, name: "first element" },
]

// Create another array of objects with a single element
let objArray2 = [
  { id: 2, name: "second element" }
]

// Merge the two arrays of objects with a new object using the spread operator
let objArray3 = [
  ...objArray1,
  { id: 3, name: "third element" },
  ...objArray2
]

// Print the contents of objArray3 to the console
console.log(`objArray3 = ${JSON.stringify(objArray3, null, 4)}`);
```

Output:

```
objArray3 = [
    {
        "id": 1,
        "name": "first element"
    },
    {
        "id": 3,
        "name": "third element"
    },
    {
        "id": 2,
        "name": "second element"
    }
]
```

- We have defined two arrays named `objArray1` (**lines 2-4**) and `objArray2` (**lines 7-9**), each with a single array element that has both an `id` property and a `name` property.
- We then create a third variable named `objArray3` on **lines 12-16**, which uses object spread to create a third array.

We can see from the output that the `objArray3` variable contains all of the elements of both the `objArray1` and `objArray2` arrays, as well as the element with `id : 3`, and `name : "third element"` that we injected into the middle of the array using spread syntax.