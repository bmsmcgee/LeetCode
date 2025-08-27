# JavaScript Strings

## Strings

ES6 strings offer new string methods, template literals, and tagged template literals.

### New String Methods

ES6 offers a few new string methods:
  - The `.repeat(number)` method repeats a given string a specified number of times.
  - The `.startsWith(searchString, position)` method returns `true` is a string starts with `searchString`. The `position` parameter specifies the start position of the search, with the default value being `0`.
  - The `.endWith(searchString, length)` method returns `true` if a string ends with `searchString`. The `length` parameter specifies the length of the string to search.
  - The `.includes(searchString, position)` method returns `true` if a given string can be found in another string.

### Template Literals

Template literals allow us to embed expressions in our strings using backticks (\`) and `${express}`. This can help simplify the syntax string concatenation and create multiline strings. See the code below for an example:

```js
const greeting = "Good morning";
const weather = "sunny";
// ES5
const sentence = greeting + ", how are you doing?" + " The weather is " + weather + " today.";

// ES6
const sentenceES6 = `${greeting}, how are you doing? The weather is ${weather} today.`;

const multiLineString = `
Hello,
my friend
how are you, doing?
`;

console.log(sentence);
console.log(sentenceES6);
console.log(multiLineString);

/* Outputs
Good morning, how are you doing? The weather is sunny today.
Good morning, how are you doing? The weather is sunny today.

Hello,
my friend,
how are you, doing?
*/
```
