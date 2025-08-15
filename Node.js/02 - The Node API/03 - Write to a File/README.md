# Write to a File

Implement a `writeFile()` function that asynchronously writes data to `test.txt`, replacing all existing data with new data passed to `writeFile()`.

We can write to a file with `fs.writeFile()`. This method accepts two arguments:
  - File path
  - Data to write

After writing `test.txt` with the implemented function, check the contents of `test.txt` displayed by the `readFile()` function.

  ```js
  const writeFile = async (path, data) => {
    try {
      await fs.writeFile(path, data);
    } catch (error) {
      console.error(error);
    }
  };

  writeFile('./test.txt', 'hello world');
  ```

  <img width="1047" height="567" alt="image" src="https://github.com/user-attachments/assets/270cbbd6-81cc-412b-8fe8-9c2a29092659" />

  
