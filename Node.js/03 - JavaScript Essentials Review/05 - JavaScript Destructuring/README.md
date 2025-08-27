# JavaScript Destructuring

## Destructuring

When we have to access numerous properties from an object, such as state or props in a React component, we can use destructuring assignment. This avoids assigning the properties to a variable one by one, resulting in cleaner syntax. We can destructure objects, arrays, and even function parameters.

### Destructuring Objects

The destructuring syntax allows data to be easily extracted from arrays or objects into separate variables.

```js
const person = {
  name: "Hou Chia",
  title: "software engineer",
  city: "Brooklyn, NY",
  age: 32,
};

console.log(person);
```

If we wanted to extract the values from the `person` object into variables that we can use in our program, we might write something like this:

```js
const name = person.name;
const title = person.title;
const city = person.city;
const age = person.age;

console.log(name);
```

With destructuring, we can accomplish the same thing in one line of code:

```js
const { name, title, city, age } = person;
console.log(name, title, city, age);
```

If we wanted to store the data in variable names that are different from the property names of the object, we can specify the custom variable names using a `:` followed by the custom name, like this:

```js
const {
  name: employeeName,
  title: employeeTitle,
  city: employeeCity,
  age: employeeAge,
} = person;

console.log(employeeName, employeeTitle, employeeCity, employeeAge);
```

Destructuring assignment keeps the syntax concise.

### Destructuring Arrays

We can also destructure arrays as follows:

```js
const letters = ["a", "b", "c"];

const [firstLetter, secondLetter, thirdLetter] = letters;

console.log(firstLetter)  // a
```

We can use `=` to assign default values:

```js
let [a = 4, b = 3] = [2];
console.log(a);  // 2
console.log(b);  // 3
```

### Destructuring Parameters

We can also use destructuring to simplify the arguments passed to a function. if a function takes more than one parameter, we can pass in an object that contains possible key-values and destructure the object.

The function `introduce()` below accepts four arguments:

```js
const introduce = (name, title, city, age) => {
  console.log(`Hello, my name is ${name}, and I'm a ${title}. I live in ${city}, and I'm ${age} years old.`);
};

introduce("Hou", "software engineer", "Brooklyn, NY", 32);
```

When calling the `introduce()` function, the order in which the arguments are passed to the `introduce()` function matters here. If the order of any two arguments were to be accidentally switched, then the function would output a nonsensical message.

With destructuring, we can pass an object that contains all the relevant data for the person, like this:

```js
const person = {
  name: "Hou Chia",
  title: "software engineer",
  city: "Brooklyn, NY",
  age: 32,
};

const introduce = ({ name, title, city, age }) => {
  return `Hello, my name is ${name}, and I'm a ${title}. I live in ${city}, and I'm ${age} years old.`;
};

console.log(introduce(person));
```

We can destructure the `person` object directly within the function parameter.

