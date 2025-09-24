# Abstract Class Methods

> Learn about abstract class methods, their definition and implementation in derived classes, and practical applications.

## Abstract Class Methods in TypeScript

An abstract class method is similar to an abstract class in that it is designed to be overridden. In other words, declaring a class method as abstract means that a derived class must provide an implementation of this method. For this reason, abstract class methods are not allowed to provide a function implementation.

As an example of this, let's update the `EmployeeBase` class:

```ts
// Define an abstract class EmployeeBase with the following properties and methods:
// - `id` property of type number
// - `name` property of type string
// - `doWork` method with no return type (abstract method)
// - constructor that initializes `id` and `name` properties with `id` and `name` arguments
abstract class EmployeeBase {
  public id: number;
  public name: string;

  // Abstract method with no implementation, to be overridden by derived classes
  abstract doWork(): void;

  constructor(id: number, name: string) {
    this.id = id;
    this.name = name;
  }
}
```

Here, we have added a class method named `doWork` that has been marked as `abstract`. This means that we will need to provide an implementation of this method in any derived class as follows:

```ts
// Define a class OfficeWorker that derives from the abstract class EmployeeBase
// and implements the `doWork` method.
class OfficeWorker extends EmployeeBase {
  // Implementation of the `doWork` method, logging a message indicating the employee's name
  // and the work being done
  doWork() {
    console.log(`${this.name} : doing work`);
  }
}
```

We have updated the `OfficeWorker` class, which derives from the `EmployeeBase` class, and provided an implementation of the `doWork` abstract method. This function simply logs a message to the console.

Let's now update the `OfficeManager` class as follows:

```ts
class OfficeManager extends OfficeWorker {
  // Property 'employees' is an array of type OfficeWorker
  public employees: OfficeWorker[] = [];

  // Method 'manageEmployees' that manages the work of employees
  manageEmployees() {
    // Call the parent class 'doWork' method through super
    super.doWork();

    // Loop through each 'employee' in the 'employees' array and call its 'doWork' method
    for (let employee of this.employees) {
      employee.doWork();
    }
  }
}
```

- We add a method named `manageEmployees` to the `OfficeManager` class. This method calls the `doWork` method, which is defined on the `OfficeWorker` base class, and we need to use the `super` keyword to access it.
- It then loops through each of the elements in the `employees` array and calls the `doWork` method on each of these classes.

We can use these updated classes as follows:

```ts
abstract class EmployeeBase {
  public id: number;
  public name: string;
  abstract doWork(): void;

  constructor(id: number, name: string) {
    this.id = id;
    this.name = name;
  }
}

class OfficeWorker extends EmployeeBase {
  doWork() {
    console.log(`${this.name} : doing work`);
  }
}

class OfficeManager extends OfficeWorker {
  public employees: OfficeWorker[] = [];
  manageEmployees() {
    super.doWork();
    for (let employee of this.employees) {
      employee.doWork();
    }
  }
}

let joeBlogg = new OfficeWorker(1, "Joe");
let jillBlogg = new OfficeWorker(2, "Jill")
let jackManager = new OfficeManager(3, "Jack");

jackManager.employees.push(joeBlogg);
jackManager.employees.push(jillBlogg);
jackManager.manageEmployees();
```

Output:

```
Jack : doing work
Joe : doing work
Jill : doing work
```

- We add the `joeBlogg` and `jillBlogg` instances of the `OfficeWorker` class to the `employees` array on the `jackManager` instance of the `OfficeManager` class.
- We then call the `manageEmployees` function on the `jackManager` instance.

We can see the output of each of the `doWork` abstract method calls. Because the `OfficeManager` class inherits from the `OfficeWorker` class, the `doWork` method is available on this class instance as well. The `OfficeManager` class simply calls its own instance of the `doWork` method and then iterates through each element in its employees array, calling the `doWork` method on each instance.