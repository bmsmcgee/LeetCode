# JavaScript Rest and Spread

## Rest Parameters and Spread Syntax with `...`

Depending on the context, the syntax `...` can be used as rest parameters or spread syntax. We can use rest and spread with arrays or objects.

### Rest Parameters

The rest parameters can collext an arbitrary number of property keys in an object into a new object:

```js
let { a, b, ...pairs } = { a: 10, b: 20, c: 30, d: 40 };
console.log(a);  // 10
console.log(b);  // 20
console.log(pairs);  //  { c: 30, d: 40 }
```

The rest element `...pairs` must come last in the destructuring order, so `{...pairs, a, b } = { a: 10, b: 20, c: 30, d: 40 };` won't work.

### Spread Syntax

The spread syntax unpacks the collected elements into a new object. Therefore, we can use spread `...` to clone the properties from one object to another.

Take a look at the code below:

```js
const person = { name: "Hou", title: "software engineer" };
const personalInfo = {age: 32, location: "Brooklyn, NY" };

const employee = {
  id: 1,
  department: "engineering",
  ...person,
  ...personalInfo,
};

console.log(employee);

/*Output

{ id: 1,
  department: 'engineering',
  name: 'Hou',
  title: 'software engineer',
  age: 32,
  location: 'Brooklyn, NY' }

*/
```

As we can see, the `employee` object contains the `name` and `title` properties from the `person` object, and the `age` and `location` properties from the `personalInfo` object.

  > **Note:** The spread operator performs a shallow copy, not a deep copy of an object.
