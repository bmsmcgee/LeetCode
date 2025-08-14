# Introduction to Node.js

## Node.js Overview

Node.js was first released in 2009 by a programmer named Ryan Dahl.

## What is Node.js?

Node.js is a JavaScript runtime built on Chrome's V8 JavaScript engine.

Node.js enables JavaScript to run outisde the browser. It can be used to build server-side applications that efficiently handle high traffic volumes.

Node.js is portable, meaning it can run on various operating systems, including Mac, Windows, Linux, and several other systems. It's also a free and open-source technology.

## Node.js uses the V8 JavaScript Engine

A JavaScript engine is a program that compiles JavaScript to machine code that the operating system can understand.

V8 is the name of the JavaScript engine that powers Node.js. Created by Google and open source since 2008, V8 powers the Google Chrome browser today. It is written in C++.

One advantage of using Node.js is that it benefits from Google's investment in V8's improved performance year after year.

Besides V8, examples of other JavaScript engines include SpiderMonkey (used by Firefox) and Chakra (used by Edge).

## Node.js Versus the Browser

Before the advent of Node.js, JavaScript could only run in the browser, and its primary purpose was to create browser interactions (e.g., adding click events). Node.js allows us to write JavaScript in the server to perform common tasks, such as accessing the file system and connecting to databases.

Nowadays, JavaScript has proven to be among the most popular programming languages. If a developer extensively uses JavaScript, then Node.js offers a considerable advantage, which is the ability to program the entire application - the frontend and backend - in a single language. However, while Node.js and browsers like Chrom both execute JavaScript and use the same V8 JavaScript engine, there are a few key differences between them.

| Browser                                                      | Node.js                                                                     |
| :----------------------------------------------------------: | :-------------------------------------------------------------------------: |
| The browser has access to `document` and `window` objects.   | Node.js has access to `http` and `fs` objects.                              |
| The `global` object references the `window`.                 | The `global` object references Node.js-specific modules.                    |
| The browser uses ECMAScript modules (`import` and `export`). | Node.js uses the CommonJS module system (`require()` and `module.exports`). |

While Node.js and browsers share several standard built-in JavaScript features (like `Array`), several predefined objects exist in one environment but not in the other. For example, Node.js doesn't have access to the `document` and `window` objects used on the client side for Document Object Model (DOM) manipulation and user event handling. On the other hand, the browser doesn't have access to Node.js APIs, such as `http` and `fs`, which are needed for setting up web servers and manipulating file systems, respectively.

Both Node.js and browsers have access to a `global` object. In the browser, the `global` object references the `window` object. In Node.js, however, the `global` object exposes a collection of useful modeuls, functions, and strings that we can use in our programs.

Node.js uses the CommonJS module system, which uses `require()` and `module.exports`, to share code between different files. In the browser, we're starting to see the ECMAScript modules standard, which uses the `import` and `export` statements, being implemented. As of October 2020, ECMAScript modules are still an experimental feature in Node.js.
