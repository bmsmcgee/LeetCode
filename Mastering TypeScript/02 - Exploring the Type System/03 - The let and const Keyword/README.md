# The `let` and `const` Keywords

> Learn how to define a vairable's scope and constants using the `let` and `const` keywords in TypeScript.

## The `let` Keyword

The fluid nature of JavaScript variables can sometimes cause errors when we inadvertently define variables with the same name but in a different scope within a code block.

Consider the following TypeScript code:

```ts
// Declare a variable called index with a type of number and assign it the value 0
var index: number = 0;

// If index is equal to 0, create a new block scope with a new variable also called index, but with a type of number and value of 2, and log its value
if (index == 0) {
  var index: number = 2;
  console.lof(`index = ${index}`);
}

// Log the value of index
console.log(`index = ${index}`);
```

Output: 

```
index = 2
index = 2
```

- On **line 2**, we define a variable named `index` of type `number` using the `var` keyword and assign it a value of`0`.
- We then test if this value is equal to `0` on **line 5**, and if it is, we enter a code block.
- The first statement in this code block on **line 6** defined a variable named `index` of type `number` and then assigns the value `2` to it.
- We then print the value of the `index` variable both inside this code block on **line 7** and outside of it on **line 11**.

What this is showing us is that even though we thought we created a new variable within the `if` code block named `index`, this variable redeclaration actually points to the original `index` variable and does not create a new one. So, setting the value of the `index` variable within the code block will modify the value of the `index` variable outside of the code block as well. This is not what was intended.

The ES6 JavaScript specification introduces the `let` keyword to prevent this from happening.

Refactoring the preceeding code using the `let` keyword shows:

```ts
// Declare a variable called index with a type of number and assign it the value 0
let index: number = 0;

// If index is equal to 0, create a new block scope with a new variable also called index, but with a type of number and value of 2, and log its value
if (index == 0) {
  let index: number = 2;
  console.log(`index = ${index}`);
}

// Log the value of index
console.log(`index = ${index}`);
```

Output:

```
index = 2
index = 0
```

The difference between this code and the previous code is the use of `let` instead of `var` to declare the `index` variable on **lines 2 and 6**, respectively.

Using `let` creates a new block-scoped variable instead of a function-scoped variable like `var`. This means that the `index` variable declared within the block scope of the `if` statement will not overwrite the `index` variable outide of the block scope.

> **Tip:** It is best practice to use the `let` keyword to define variables and not to use the `var` keyword at all. By using `let`, we are being more explicit about the intended use of these variables, which will help the compiler to pick up any mistakes in our code where these rules are broken.

## The `const` Keyword

When working with variables, it sometimes helps to indicate that the variable's value can't be modified after it has been created with a specific value. TypeScript uses the `const` keyword, which was introduced in ES6, in order to accomplish this.

Consider the following code:

```ts
// Declare a variable called constValue with a type of string and assign it the value "this should not be changed"
const constValue = "this should not be changed";

// Attempt to assign a new value "updated" to constValue
constValue = "updated";
```

Output:

```
index.ts(5,1): error TS2588: Cannot assign to 'constValue' because it is a constant.
```

- We define a variable named `constValue` and indicate that its value can't be changed using the `const` keyword on **line 2**.
- An error is being generated because we attempted to modify the value of the `constValue` variable on **line 5**, which is not allowed.

> **Tip:** It is best practice to identify constant variables within our code and explicitly mark them as `const`. The use of `const` and `let` clearly indicates to the reader of the code the intent of the variable. A variable marked as `const` can't be changed, and a variable declared with `let` is a block-scoped temporary variable.