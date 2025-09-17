// Declare a variable 'nameIdObject' and initialize it with an object that has a 'name' property, an 'id' property, and a 'print' method
var nameIdObject = { name: "myName", id: 1, print() {} };

// Output the value of the 'name' property of 'nameIdObject'
console.log(`nameIdObject.name: ${nameIdObject.name}`);

// Output the value of the 'id' property of 'nameIdObject'
console.log(`nameIdObject.id: ${nameIdObject.id}`);

// Assign a new object to 'nameIdObject'. This object has the same properties and methods as the original object, but the property values are different
nameIdObject = { id: 2, name: "anotherName", print() {} };

// Output the updated value of the 'name' property of 'nameIdObject'
console.log(`nameIdObject.name: ${nameIdObject.name}`);

// Output the updated value of the 'id' property of 'nameIdObject'
console.log(`nameIdObject.id: ${nameIdObject.id}`);
