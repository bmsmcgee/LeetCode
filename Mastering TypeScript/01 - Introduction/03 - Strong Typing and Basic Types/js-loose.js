// Declare a variable called "test" and initialize it with a string value
console.log("Let's declare the variable 'test' with a string value\n");
var test = "a string";

// Log the value of "test" to the console
console.log("test = " + test);

console.log(
  "\nWe can see the successful assignment of a string type to the 'test' variable.\n"
);

// Change the value of "test" to an integer
console.log("Now let's assign an integer value to 'test'\n");
test = 1;

console.log("test = " + test);

console.log(
  "\nWe can see the successful assignment of an integer type to the 'test' variable. Notice that the type of the 'test' variable has changed from a string to an integer.\n"
);

// Change the value of "test" to a function
console.log("Now let's assign a function to 'test'\n");
test = function (a, b) {
  return a + b;
};

console.log("test = " + test + "\n");

console.log(
  "This is how types work in JavaScript: variables can hold values of any data type, and the type of a variable can change during the execution of a program. This is in contrast to strongly-typed languages like TypeScript, in which variables must be explicitly declared with a specific data type and can only hold values of that type."
);
