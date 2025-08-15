# Explore the Node.js REPL Environment

## REPL Environment

Let's try the REPL node environment by opening the terminal and following these steps:
  1. Type "node" into the terminal. This will open up a REPL (Read-Evaluate-Print-Loop) where we can run individual node statements using JavaScript. The command stays in idle mode, waiting for us to input code.

     <img width="1003" height="523" alt="image" src="https://github.com/user-attachments/assets/133a3545-2017-471a-aec7-c34f39a59adb" />

  3. Core JavaScript features we're familiar with in the browser, like `toUpperCase()`, are still available in Node.js. Try running the following with REPL:

     ```js
     "hello world".toUpperCase(); // returns 'HELLO WORLD      
     ```

     <img width="1047" height="567" alt="image" src="https://github.com/user-attachments/assets/da938610-26d0-4946-91b8-71e603e57f96" />

  3. Try entering the name of a JavaScript class, like `Number`, add a dot, and pressing "Tab". The REPL will print all the properties and methods we can access in that class. Try running some of these methods and properties, such as `Number.MAX_VALUE`.

     <img width="1047" height="567" alt="image" src="https://github.com/user-attachments/assets/ae9bf555-6083-4ff9-bad3-24bc92e58ef8" />

     <img width="1047" height="567" alt="image" src="https://github.com/user-attachments/assets/667aa13a-512e-427c-8488-267aa99d3413" />

  4. Inspect the global objects we have access to by typing "global" and pressing "Tab". Some of these global objects may be familiar from browser-based JavaScript.

     <img width="1047" height="567" alt="image" src="https://github.com/user-attachments/assets/42236b55-4eb3-4752-b496-7b502f91ffe7" />

  5. To exit REPL mode, type ".exit" or hit "CTRL + c" twice.

     <img width="1047" height="567" alt="image" src="https://github.com/user-attachments/assets/37a34ec8-f5b6-40bd-bf91-742ee8719370" />

