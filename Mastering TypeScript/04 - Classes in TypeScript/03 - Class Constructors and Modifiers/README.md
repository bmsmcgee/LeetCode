# Class Constructors and Modifiers

> Learn about using class constructors to accept arguments an initialize class properties and using `public`, `private`, and `protected` access modifiers in TypeScript.

## Class Constructors

Class constructors can accept arguments during their initial construction. This allows us to combine the creation of a class and the setting of its parameters into a single line of code.

Consider the following class definition:

```ts
// Class definition for a ClassWithConstructor
class ClassWithConstructor {
  // Property to store the identifier
  id: number;

  // Constructor function to initialize the class with an identifier
  constructor(_id: number) {
    // Assigning the constructor argument to the class property
    this.id = _id;
  }
}
```

We define a class named `ClassWithConstructor` on **lines 2-11** that has a single property named `id` of type `number`.

We then have a function definition for a function named `constructor` on **lines 7-10** with a single parameter named `_id` of type `number`. Within this constructor function, we are setting the value of the internal `id` property to the value of the `_id` parameter that was passed in.

> **Note:** Notice the definition of the `id` property in this class. Previously, we needed to define a property as being of the type `number | undefined`. Here, however, because we are initializing the property via the constructor, it will always be defined when an instance of the class is initialized.

We can construct an instance of this class as follows:

```ts
// Creating an instance of the ClassWithConstructor class with identifier 10
let classWithConstructor = new ClassWithConstructor(10);

// Logging the instance of ClassWithConstructor as a stringified JSON object
console.log(`classWithConstructor = 
  ${JSON.stringify(classWithConstructor)}`);
```

Output:

```
classWithConstructor = 
  {"id":10}
```

We have created an instance of the `ClassWithConstructor` class on **line 2** and passed in the argument of `10` to the constructor.

On **line 5-6** we then simply log the value of this class instance to the console.

Another aspect to note about class constructors is that TypeScript understands the scoping rules of class properties and the scoping rules of parameters.

Our earlier class definitions can be rewritten slightly as follows:

```ts
class ClassWithConstructor {
  id: number;

  // Constructor function for the class, taking in a parameter "id" of type number
  constructor(id: number) {
    this.id = id;
  }
}
```

We have the same class defintion we used earlier, with a subtle difference. Note how the constructor function now accepts a parameter named `id`, instead of `_id`, as we used earlier.

This is possible, as the scope of the `id` parameter, as passed into the constructor function, is different to scope of the class instace property named `id`. Using `this.id` to access the class instance property clearly distinguishes it from the `id` function parameter.

## Class Modifiers.

TypeScript introduces the `public` and `private` access modifiers to indicate whether a class vairable or function can be accessed from outside the class itself. Additionally, we can also use the `protected` access modifier.

### Example of `public` Property

A `public` property can be accessed by any calling code as follows:

```ts
// Define a class 'ClassWithPublicProperty'
class ClassWithPublicProperty {
  // Declare a public property 'id' of type number or undefined
  public id: number | undefined;
}

// Create an instance of the ClassWithPublicProperty' class
let publicAccess = new ClassWithPublicProperty();

// Assign a value to the public property 'id'
publicAccess.id = 10;
```

Here, we have defined a class named `ClassWithPublicProperty`, which has a single property named `id` that has been marked as `public` on **line 4**. This means that we are able to set the value of the `id` property once we have created an instance of this class, which in this instance has been set to the value `10`.

### Example of the `private` Property

Let's now explore how marking a property `private` will affect access to this property as follows:

```ts
// Define a class with a private property named "id"
class ClassWithPrivateProperty {
  // Declare the private property "id" with the type "number"
  private id: number;

  // Constructor with parameter "id" to initialize the private property "id"
  constructor(id: number) {
    this.id = id;
  }
}

// Create an instance of ClassWithPrivateProperty and pass in a value of 10 for "id"
let privateAccess = new ClassWithPrivateProperty(10);

// Attempt to assign a value of 20 to the private property "id". 
// This will throw an error because private properties cannot be accessed or modified outside of the class.
privateAccess.id = 20;
```

Output:

```
index.ts(17,15): error TS2341: Property 'id' is private and only accessible within class 'ClassWithPrivateProperty'.
```

We define a class named `ClassWithPrivateProperty` that has a single property named `id`, which has been marked as `private` on **line 4**.

This class also has a constructor function on **lines 7-9**, which will set the value of the internal `id` property to the value of the `id` argument that was passed in.

We then create an instance of this class on **line 13** and attempt to assign the value of `20` to the private `id` property on **line 17**.

When we run this code, we can see that because we have marked the `id` property as private, we can't access it outside the class itself. Note, however, that within the constructor function, which is inside the class itself, we are able to set the value of the private `id` property.

