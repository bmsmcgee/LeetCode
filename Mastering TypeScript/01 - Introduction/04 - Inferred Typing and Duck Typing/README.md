# Inferred Typing and Duck Typing

> Discover how TypeScript uses inferred typing for variables and employs duck typing for object compatibility

**Inferred typing** is a feature of TypeScript that allows the type of a variable or expression to be determined based on the context in which it appears rather than being explicitly specified with a type annotation.

**Duck typing** checks the compatibility of an object with a particular type based on the presence of certain properties or methods rather than the object's actual type.

## Inferred Typing

TypeScript uses a technique called inferred typing, or type inference, to determine the type of a variable. This means that even if we do not explicitly specify the type of a variable, the compiler will determine its type based on when it was first assigned. Again, once the variable has a type, normal type comparisons will be used.

As an example, consider the following code:

```ts
// Declare a variable 'inferredString' and initialize it with a string value
var inferredString = "this is a string";

// Declare a variable 'inferredNumber' and initialize it with a number value
var inferredNumber = 1;

// Attempt to assign the value of 'inferredString' (a string) to 'inferredNumber' (a number)
// This will produce a type error because it is not possible to assign a string to a number
inferredNumber = inferredString;
```

- We create two variables named `inferredString` and `inferredNumber` on **lines 2 and 5**, respectively, and assign a string value to the first variable and a numeric value to the second.
- We then attempt to assign the value of `inferredString` to the varirable `inferredNumber` on **line 9**.

However, the code generates the following error:

```
error TS2322: Type 'string' is not assignable to type 'number'.
```

What this error is telling us is that TypeScript has inferred that the type of the variable `inferredString` is of type `string`, even though we have not used the explicit `: string` type syntax. In the same manner, TypeScript has inferred that the type of the variable `inferredNumber` is of type `number`, hence the error.

Inferred typing can be useful in TypeScript because it allows us to omit explicit type annotations in situations where the type can be easily determined from the context. This makes our code more concise and easier to read since we don't have to clutter it with unnecessary type annotations.

However, it's important to note that inferred typinf relies on TypeScript's type inference algorithm, which may not always make the correct type assignments.

## Duck Typing

TypeScript uses a method called duck typing for more complex variable types. Duck typing suggests that *"if it looks like a duck and quacks like a duck, then it probably is a duck"*.

In other words, two variables are considered to have the same type if they have the same properties and methods.

```ts
// Declare a variable 'nameIdObject' and initialize it with an object that has a 'name' property, an 'id' property, and a 'print' method
var nameIdObject = { name: "myName", id: 1, print() { } };

// Output the value of the 'name' property of 'nameIdObject'
console.log(`nameIdObject.name: ${nameIdObject.name}`);

// Output the value of the 'id' property of 'nameIdObject'
console.log(`nameIdObject.id: ${nameIdObject.id}`);

// Assign a new object to 'nameIdObject'. This object has the same properties and methods as the original object, but the property values are different
nameIdObject = { id: 2, name: "anotherName", print() { } };

// Output the updated value of the 'name' property of 'nameIdObject'
console.log(`nameIdObject.name: ${nameIdObject.name}`);

// Output the updated value of the 'id' property of 'nameIdObject'
console.log(`nameIdObject.id: ${nameIdObject.id}`);
```

Output:

```
nameIdObject.name: myName
nameIdObject.id: 1
nameIdObject.name: anotherName
nameIdObject.id: 2
```

In this code:
  - We define a variable called `nameIdObject` on **line 2**, which is a standard JavaScript object and has a `name` property, an `id` property, and a `print` function.
  - We then reassign the value of this variable to another object that also has a `name` property, and `id` property, and a `print` function on **line 11**

The compiler will use duck typing in this instance to figure out if this assignment is valid. In other words, if an object has the same set of properties and functions, then they are considered to be of the same type.

At first glance, we can see that in the first object, the `name` property comes before the `id` property, while in the second object, the `id` property comes before the `name` property. It is possible for the properties of an object to appear in a different order in different objects as long as the objects have the same shape (that is, they have the same set of properties and methods). In TypeScript, objects are considered compatible based on their shape rather than the order of their properties.

In contrast, if an object is missing a property or has an extra property that is not present in the other object, then the objects are not considered compatible. Let's see how they compiler reacts if we attempt to break this rule.

```ts
// Declare a variable 'nameIdObject' and initialize it with an object that has a 'name' property, an 'id' property, and a 'print' method
var nameIdObject = { name: "myName", id: 1, print() {} };
// Assign a new object to 'nameIdObject'. This object has a 'name' property and an 'id' property, but it does not have the 'print' method
// that the original object had.
nameIdObject = { id: 3, name: "thirdName" };
```

Produces error:

```
index.ts(5,1): error TS2741: Property 'print' is missing in type '{ id: number; name: string; }' but required in type '{ name: string; id: number; print(): void; }'.
```

Here, we can see that the error message clearly states that the `print` property is missing because TypeScript is using duck typing to ensure type safety.

  > **Note:** These errors will occur if the name of a property, they type of a property, or the number of properties are not exactly the same when assigning a value to an object.

Another slightly difference example of duck typing:

```ts
// Declare a variable 'obj1' and initialize it with an object that has an 'id' property and a 'print' method
var obj1 = { id: 1, print() { } };

// Declare a variable 'obj2' and initialize it with an object that has an 'id' property, a 'print' method, and a 'select' method
var obj2 = { id: 2, print() { }, select() { } }

// Attempt to assign 'obj2' to 'obj1'. This won't cause a type error because 'obj2' has all of the methods that are present in the type of 'obj1'
obj1 = obj2;

// Attempt to assign 'obj1' to 'obj2'. This will cause a type error because 'obj1' is missing the 'select' method that is present in the type of 'obj2'
obj2 = obj1;
```

- We declare two objects named `obj1` and `obj2` on **lines 2 and 5**, which are identical except that `obj2` has an extra `select` function.
- We then assign the value of `obj2` to `obj1` on **line 8**. This will not generate an error because the type of `obj2` has all of the properties of the type of `obj1`. This means that the duck typing method is checking whether `obj2` has at least the properties of `obj1`, which it does.
- We assign the value of `obj1` to `obj2` on **line 11**, which is generating the error because the compiler has correctly identified that the type of `obj1` does not have at least all of the properties of `obj2`, as it is missing the `select` function.