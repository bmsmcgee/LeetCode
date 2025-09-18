# Functions

> Learn about TypeScript function type safety, optional parameters, default parameters, and rest parameters

## Exploring the Type System with Functions

TypeScript language can be used to introduce further type safety whenever functions are used. Functions can use optional parameters and spread syntax. We will look at how we can define a function signature in such a manner that if a function defines another function as a parameter, we can make sure that the function we pass in has the correct parameters.

## Optional Parameters

Similar to tuples in TypeScript, we can specify that a function can have optional elements in the same way, using the question mark (`?`).

Consider the following code:

```ts
// This function concatenates two string values, "a" and "b", and logs the result to the console.
// The second parameter "b" is optional, indicated by the "?" after its type declaration.
function concatValues(a: string, b?: string) {
  console.log(`a + b = ${a + b}`);
}

// Call the function with two arguments
concatValues("first", "second");

// Call the function with only one argument
concatValues("third");
```

Output:

```
a + b = firstsecond
a + b = thirdundefined
```

- We define a function named `concatValues` from **lines 3-5** that has two parameters, `a` and `b`, both of type `string`. The second argument, `b` however, has been marked as optional using the question mark (`?`) after the argument name, that is, `b?: string`.
- We then call this function with two parameters on **line 8** and then with only a single parameter on **line 11**.

We can see from the output that the first call to the `concatValues` function only provided a value for the first argument because the second argument was marked as optional.

This second call to the `concatValues` functions produces the output `thirdundefined` because we have not specified a value for the second argument. This means that the argument `b` was not specified and is thus `undefined`.

> **Note:** Any optional parameters must be listed last in the parameter list of the function definition. We can have as many optional parameters as we like as long as nonoptional parameters precede the optional parameters.

## Default Parameters

A variant of the optional parameter syntax allows us to specify a default value for a parameter if it has not been supplied.

Consider the following code:

```ts
// This function concatenates two string values, "a" and "b", and logs the result to the console.
// The second parameter "b" has a default value of "default", indicated by the "=" and the string value after its type declaration.
function concatWithDefault(a: string, b: string = "default") {
  console.log(`a + b = ${a + b}`);
}

// Calling the function with different arguments
concatWithDefault("first", "second");
concatWithDefault("third");
```

Output:

```
a + b = firstsecond
a + b = thirddefault
```

- We define a function named `concatWithDefault` from **lines 3-5** that has two parameters, `a` and `b`, both of type `string`.
- We then call this function with two arguments on **line 8** and then with just a single argument on **line 9**.

We can see from the output that when we supply two arguments to the `concatWithDefault` function, the function will concatenate the arguments as expected. When we only supply a single argument, the second argument will default to the value `default`.

## Rest Parameters

Interestingly, the parameters specified in a JavaScript function are all optional. Even if a JavaScript function specifies parameters in its function definition, we do not need to supply them when calling the function.

In quirky twise of the language, even if we do not specify any parameters in a function definition, we can still access the values that were provided when the function was invoked.

Consider the following JavaScript code:

```js
// This function logs all of the arguments passed to it, along with their index.
function testArguments() {
  for (var i = 0; i < arguments.length; i++) {
    console.log(`argument[${i}] = ${arguments[i]}`);
  }
}

// Calling the function with different arguments
testArguments(1, 2);
testArguments("first", "second", "third");
```

Output:

```
argument[0] = 1
argument[1] = 2
argument[0] = first
argument[1] = second
argument[2] = third
```

- We have defined a JavaScript function named `testArguments` from **lines 2-6** that does not specify any parameters.
- We then create a `for` loop to loop through the values of an array named `arguments`. If an array element is found, we log the value of the array element to the console. All JavaScript functions automatically have access to a special variable, named `arguments`, that can be used to retrieve all of the arguments that were used when the function is invoked.
- We then invoke the `testArguments` function twice, once with the arguments `1` and `2` on **line 9** and again with the arguments `"first"`, `"second"`, and `"third"` on **line 10**.

We can see from the output a log of the arguments that were used to invoke the `testArguments`function. The first time we invoked the function, we used the arguments `1` and `2`. The second time we invoked this function, we used the arguments of `"first"`, `"second"`, and `"third"`.

In order to express the equivalent function definition in TypeScript, we will need to use the rest syntax as follows:

```ts
// Define a function named `testArguments` that takes a rest parameter `args`
function testArguments(...args: (string[] | number[])) {
  for (let i in args) {
    // Log each argument in the format `args[i] = argument_value`
    console.log(`args[${i}] = ${args[i]}`);
  }
}

// Call the `testArguments` function with different arguements
testArguments("1");
testArguments(10, 20);
```

Output:

```
args[0] = 1
args[0] = 10
args[1] = 20
```

- We define a function named `testArguments` using rest syntax (the three dots, `...`) on **lines 2-7** to specify that the function can be called with any number of parameters. We are also using a type union here to indicate that the variable parameters can be of type `string` or of type `number`.
- We then invoke the `testArguments` function on **line 10** with one argument, which is the string `"1"`, and then invoke it on **line 11** with two numbers, namely `10` and `20`.

We can see from the output that the `testArguments` function can be called with multiple arguments, and because the function definition allows these parameters to be either of type `string` or of type `number`, we are able to mimic the functionality of the earlier JavaScrip function.