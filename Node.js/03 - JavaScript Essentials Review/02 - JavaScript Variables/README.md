# JavaScript Variables

In JavaScript, variables can be declared with `var`, `let`, or `const`.

  > **Note:** The `let` and `const` keywords were introduced in ES6 and are the preferred variable declaration methods.

## Variable Update

The `var` variables can be updated and redeclared within its scope.

What will be logged to the console in the below code?

  ```js
  var color = "red";
  var color = "yellow";
  console.log(color);
  ```

The value `yellow` is logged because `var` variables can be updated and redeclared within its scope.

While `let` variables can be updated, they can't be redeclared.

Look at the code below. What will be logged to the console?

  ```js
  let color = "red";
  let color = "yellow";
  console.log(color);    // SyntaxError: Identifier 'color' has already been declared

  let greeting = "hello";
  greeting = "hi";
  console.log(greeting);  // 'hi' is logged, since `let` variables can be updated
  ```

If the variable needs to change, like in a `for` loop, we should use `let`.

The `const` variables can neither be updated nor redeclared. Typically, we should always use `const` unless we know the variable will change. By using `const`, we're telling our future selves and our code collaborators that the data item shouldn't change its value.

What will be logged to the console in the code below?

  ```js
  const color = "red";
  color = "yellow";
  console.log(color);  // TypeError: Assignment to constant variable.
  ```

Setting a `const` data item to an object is interesting. Once we've assigned an object to `const`, we can't reassign the `const` data item to a different object, but we can update the methods and properties on the object.

Look at the code below. What will be logged to the console?

  ```js
  const computer = {
    type: "Macintosh",
    os: "Catalina",
  };

  computer.type = "Microsoft";
  computer.os = "Windows 10";

  console.log(computer);  // { type: 'Microsoft', os: 'Windows 10' }
  ```

Look at the code below. What will be logged to the console?

  ```js
  const computer = {
    type: "Macintosh",
    os: "Catalina",
  };

  computer.type = "Microsoft";
  computer.os = "Windows 10";

  console.log(computer);  // { type: 'Microsoft', os: 'Windows 10' }

  computer = {
    type: "Chromebook",
    os: "Chrome OS",
  };

  console.log(computer);  // TypeError: Assignment to constant variable
  ```

## Variable Scope

Scope describes the part of the program where variables are accessible by the program.

### The Scope of `var` Variables

The `var` variables are global or function scoped.

In the code below what will be logged to the console?

  ```js
  var fruit = "apple";
  var fruitEaten = 3;

  if (fruitEaten > 2) {
    var fruit = "orange";
  }

  console.log(fruit); // 'orange'
  ```

Look at the code below. What will be logged to the console?

  ```js
  const printColor = () => {
    var color = "red";
  };

  console.log(color); // ReferenceError: color is not defined
  ```

### The Scope of `const` and `let` Variables

The `const` and `let` variables are block scope. This means that a variable declared within a block, such as the space in between the curly brackets of an `if-else` statement, can only be accessed within that block.

Look at the code below. What will be logged to the console?

  ```js
  shouldEatFruit = true;
  if (shouldEatFruit) {
    let fruit = "orange";
    const anotherFruit = "apple";
    console.log("fruit inside block: ", fruit);  // fruit inside block: orange
    console.log("anotherFruit inside block: ", anotherFruit);  // anotherFruit inside block: apple
  }

  console.log("fruit outside block: ", fruit); // ReferenceError: fruit is not defined
  console.log("anotherFruit outside block:", anotherFruit); // ReferenceError: anotherFruit is not defined
  ```

Look at the code below. What will be logged to the console?

  ```js
  let number = 1;

  if (number === 1) {
    let number = 2;
    console.log("inside block: ", number);  // inside block: 1
  }

  console.log("outside block: ", number);  // outside block: 2
  ```

## Variable Hoisting

**Hoisting** describes the default JavaScript behaviour of moving variable declarations to the top of their scope. The `var`, `let`, and `const` variables are all hoisted, albeit a little differenty.

During hoisting, `var` variables are initialized to undefined, so trying to access a variable declared with `var` before the declaration returns `undefined`.

Look at the code below. What will be logged to the console?

  ```js
  console.log(animal);    // undefined
  var animal = "rabbit";
  ```

Another example:

  ```js
  var flower = "rose";

  const printFlower = () => {
    console.log(flower);  // undefined
    var flower = "hibiscus";
  };

  printFlower();  
  }
  ```

Trying to do the same with `let` or `const` will return a `ReferenceError` because they aren't initialized during hoisting.

Look at the code below. What will be logged to the console?

  ```js
  console.log(flower);
  let flower = "rose";  // ReferenceError: Cannot access 'flower' before initialization
  ```

As we can see, `let` helps the developer avoid undesireable ways of writing code, such as trying to access a variable before it's declared in the code, while allowing variables with it to be updated. In short, we shouldn't ever have to use `var` again.
