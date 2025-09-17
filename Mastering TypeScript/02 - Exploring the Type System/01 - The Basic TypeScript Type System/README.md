# The Basic TypeScript Type System

> Get introduced to the various elements and concepts related to types in TypeScript

## Overview

Let's explore all the primitive types that are available, as well as some language elements that we can use to better describe how to use these types. We will discuss when and where to use these types and language elements and even when not to use some types.

We will first explore the `any` type, the `let` and `const` keywords, and the `union` types. The concept of union types feeds directly into a discussion on type guards and type aliases. We will then talk about enums, including string enums and const enums.

After that, we will work through the remainder of the primitive types that are available for use, including `undefined`, `null`, `object`, and `unknown`. There are also language features that help us when we have to work with values that could be `undefined` or `null`, including optional chaining, nullish coalescing, and definite assignment. We will also discuss the `never` type and how it can be used to identify logic errors.

After understanding the basics of the type system, we will discuss the object spread syntax, which is used to combine the properties of one object with the properties of another. We will see how this spread syntax can also be used with arrays as a handy syntax for combining arrays and array values.

The next thing we will cover are tuples, especially what they are and how they can be used in TypeScript.

At the end of the section, we will deal with the use of types within functions and function signatures. We will see how we can use optional parameters in a function, default parameters, and rest syntax. We will also show how we can define a funciton signature as a function parameter in order to ensure that any function provided as a callback function has the correct parameters and parameter types.

We will explore what types are available for use, how and where these types can be used, and what language features are available to help with our use of types.