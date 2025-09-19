# Optional Properties and Prefixing Interface Names

> Learn about optional interface properties, view the transpiled JavaScript output, and learn about the devate over interface name prefixes in TypeScript.

## Introduction to Optional Properties

Interface definitions may also include optional properties similar to functions that specify optional parameters uding the question mark (`?`) syntax.

Consider the following interface:

```ts
interface IOptional {
  id: number;
  name?: string;
}
```

Here, we have an interface named `IOptional`, which has defined an `id` property of type `number` and an optional property named `name` of type `string`.

We can noe define objects as follows:

```ts
interface IOptional {
  id: number;
  name?: string;
}

let optionalId: IOptional = {
  id: 1,
};
// 'optionalId' is an object of type 'IOptional' with only the required 'id' property set to 1

let optionalIdName: IOptional = {
  id: 2,
  name: "optional name",
};
// 'optionalIdName' is an object of type 'IOptional' with both required 'id' property set to 2 and optional 'name' property set to "optional name"
```

Here, we have two objects named `optionalId` and `optionalIdName` that both implement the `IOptional` interface. 

As the `name` property has been marked optional, both of these objects correctly implement the interface.

## Interfaces are Compiled Away

Interfaces do not generate any JavaScript code. This means that interfaces are constructs only used in the TypeScript compilation step and language services and are there to ensure type safety.

The JavaScript that is generated for our code thus far is as follows:

```js
// Object with properties "id" (number) and "name" (string)
var idObject = {
  id: 2,
  name: "this is a name"
};

// Object with only property "id" (number)
var optionalId = {
  id: 1
};

// Object with properties "id" (number) and "name" (string)
var optionalIdName = {
  id: 2,
  name: "optional name"
};
```

The code works without any problems because, in JavaScript, an object does not have to have all the properties specified in a certain interface or a certain usage; it can have more or fewer properties or even no properties at all. The properties of an object can be added, modified, or deleted dynamically at runtime.

We can see that the interface definitions that we have been using have all been removed during the compilation step, and all we are left with in this generated JavaScrip is the objects themselves.

## Intoduction to TypeScript's Coding Standard for Interface Names

The TypeScript team has a coding standard for contributions to the TypeScript code base that prohibits the use of the letter `I` for prefixing interfaces. In code samples that we have seen, names like `IIdName` and `IOptional` have been used. According to the TypeScript team's standard, these should simply be named `IdName` and `Optional`.

The reason for this standard boils down to two things:
  - Firstly, an interface defines the shape of an object and is, therefore, really just a type, in the same manner as a string is a type, or a number is a type. When comparing types, the TypeScript compiler will use duck typing to check whether the shape of one object is compatible with another so therefore, there is no distinction between an interface and a class.
  - Secondly, the TypeScript language does not generate any code related to interfaces, so we cannot interrogate an interface at runtime and ask questions such as, *"What properties does this interface define?"*.

## TypeScript vs. C#

Other languages, such as C#, use a technique called **reflection**, which allows code to query an interface and gather information on the available properties and their types at runtime. In TypeScript, this is not possible. An interface is simply a name for a type, just like a type alias is a name for a type. However, we do not prefix type aliases with the letter `A` or classes with the letter `C`, so why should we prefix interface names with the letter `I`?

## Prefixing Interface Names with the Letter `I`

There are, however, some reasons why using a prefix with the letter `I` does make sense. If you or your team are migrating from languages like C# or Java, then this naming convention will seem familiar and natural. It also helps when reading code outside of an IDE such as VSCode, which has access to the TypeScript language service and can give you hints as to when an interface is used.

Reading code in a code review tool, for example, does not have this contextual help and can, therefore, lead to confusion around whether a type is an interface or something else.

For the purpose of this chapter, we will continue to distinguish between interfaces and other types by using an I prefix for interfaces, which helps within the code samples. This serves to make it explicit when we are using an interface as opposed to a class or any other type. The rule that the TypeScript team has adopted is a rule for their particular development team, and you should adopt it if it makes sense within your code base or within your team itself. Once you have decided on a particular naming convention, then stick with it, as there are pros and cons to either naming standard.