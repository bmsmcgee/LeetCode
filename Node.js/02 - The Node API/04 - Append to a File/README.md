# Append to a File

## Append to a File

Now implement an `appendFile()` function that asynchronously appends data to the end of the `test.txt` file.

We can append to a file with `fs.appendFile()`. This method accepts two arguments:
  - File path
  - Data to write

Add the following code:

  ```js
  const appendFile = async (path, data) => {
    try {
      await fs.appendFile(path, data);
    } catch (error) {
      console.error(error);
    }
  };

  appendFile('./test.txt', '\nappending another hello world');
  ```

The content of the `test.txt` file after appending some text to it:

  <img width="1047" height="567" alt="image" src="https://github.com/user-attachments/assets/53a79654-859e-4ad7-afd5-131ad62586fa" />

## Node.js Streams

The `fs` methods above load the full content of `test.txt` in memory before manipulating the content. As a result, huge files will hurt our program's memory efficiency and speed of execution.

In this case, a better option is to access the file content using _streams_. **Streams** are a way to handle and process data in smaller chunks without loading all the data in memory.
