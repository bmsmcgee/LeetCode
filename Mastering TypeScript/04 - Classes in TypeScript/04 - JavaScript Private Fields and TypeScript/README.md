# JavaScript Private Fields and TypeScript

> Learn about the `private` fields in ECMAScript and its comparison with TypeScript access modifiers.

## Introduction to ES6 `private` Fields

An experimental proposal to the ECMAScript standard introduces the concept of a private field by using the hash (`#`) symbol before a property name.

This means that if we are targeting a runtime that supports it, such as Node version 12, we can write a JavaScript class as follows:

```ts
// Class 'ClassES6Private' defines a private property '#id' of type number
class ClassES6Private {
  // Property '#id' is a private field and can only be accessed within the class
  #id: number;

  // Constructor initializes the private '#id' field with the passed 'id' argument
  constructor(id: number) {
    this.#id = id;
  }
}

// Instantiate a new object of type 'ClassES6Private' with an 'id' of 10
let es6PrivateClass = new ClassES6Private(10);

// Attempt to change the private '#id' field
es6PrivateClass.#id = 20;
```

Output:

```
index.ts(16,17): error TS18013: Property '#id' is not accessible outside class 'ClassES6Private' because it has a private identifier.
```

Here, we use the hash symbol as a prefix to the `id` property in our class definition, which has become `#id`. The rest of the class is identical to the previous class definition that used the `private` keyword and will work in the same way.

Note that on the last line of this code snippet, we are attempting to assign the value of `20` to the private `#id` property of our class instance.

## TypeScript vs. ES6 `private` Fields

There are pros and cons to using TypeScript's access modifiers versus ES6 private fields. Thus far, we have only worked with the `public` and `private` modifiers, but TypeScript enhances these modifiers with both `readonly` and `protected`.

Just remember that the access modifiers used in TypeScript are compiled away in the resulting JavaScript. JavaScript private fields, however, will still translate into the generated JavaScript.