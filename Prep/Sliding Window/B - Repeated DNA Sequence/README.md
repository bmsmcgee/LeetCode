# Repeated DNA Sequence

## Statement

>A DNA sequence consists of nucleotides represented by the letters 'A', 'C', 'G', and 'T' only. For example, "ACGAATTCCG" is a valid DNA sequence.

Give a string, `s`, that represents a DNA sequence, return all the 10-letter-long sequences (continuous substrings of exactly 10 characters) that appear more than once in `s`. You can return the output in any order.

## Approach

### Step 1. Encode Characters into Numbers

Before processing DNA sequences in `s`, we must convert the characters `'A'`, `'C'`, `'G'`, and `'T'` into numberical values. This allows us to perform mathematical operations, like computing hashes, more efficiently. We assign 0 $\rightarrow$ `'C'`, 1 $\rightarrow$ `'B'`, 2 $\rightarrow$ `'C'`, and 3 $\rightarrow$ `'T'`.

| Character | Encoding |
| :-------: | :------: |
| A         | 0        |
| C         | 1        |
| G         | 2        |
| T         | 3        |

We'll define this mapping in a dictionary `toInt`. Then we'll convert each character in `s` into its corresponding numeric value and store it in a list `encodedSequence`. Let's look at the code for this step:

```cpp
vector<int> findRepeatedDnaSequences(const string& s) {
    // Define a mapping of DNA characters to numerical values
    unordered_map<char, int> toInt = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};

    // Convert each character in the input string to its corresponding number
    vector<int> encodedSequence;
    for (char c : s) {
        encodedSequence.push_back(toInt[c]);
    }

    // Return the encoded list of numbers
    return encodedSequence;
}
```

### Step 2: Compute the First Hash (Rolling Hash)

Now that we have the numerical form of the DNA sequence in `s`, we can compute a rolling hash for the first 10-letter substring. Hashing allows us to efficiently compare substrings without repeatedly checking each character.

For hashing, we'll use the _polynomial rolling hash_:

$$hash = (c_{1}\times a^{k-1}) + (c_{2}\times a^{k-2}) + ... + (c_{k}\times a^{0})$$

Here, $c_{i}$ represents each character in `s`, $a$ is the size of our alphabet, i.e., 4 for the DNA sequence in `s`, and $k$ is the length of the substring for which we are computing the has, i.e. 10 in our case.

By plugging in the values we'll compute the initial hash as follows:

$$h_{0} = (c_{1}\times 4^{9}) + (c_{2}\times 4^{8}) + ... + (c_{10}\times 4^{0})$$

Here, each character $c_{i}$ contributes to the hash using base-4 multiplication. This uniquely represents the sequence we can update as we slide through the DNA string.

In the code implementation, we'll define and initialize some variables to store each equation component above. We will define the constants `k = 10` and `a = 4`. We'll use the variable `h` to store the rolling hash value and `a_k` to compute $4^{k}$. Then we'll use a loop to process the first 10 letters of `s` for computing the first hash. This loop will do the following:
  - Builds a unique number (hash) for the first 10 letters iteratively.
  - Prepares a multiplier (`a_k`) for future hash updates.

Let's look at the code for this step:

```cpp
vector<int> findRepeatedDnaSequences(const string& s) {
    // Define a mapping of DNA characters to numerical values
    unordered_map<char, int> toInt = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};

    // Convert each character in the input string to its corresponding number
    vector<int> encodedSequence;
    for (char c : s) {
        encodedSequence.push_back(toInt[c]);
    }

    const int k = 10;   // Length of DNA sequence to check
    const int a = 4;    // Base-4 encoding

    int h = 0;
    int a_k = 1;    // Store a^k for hash updates

    // Compute the initial hash using base-4 multiplication
    for (int i = 0; i < k; i++) {
      h = h * a + encodedSequence[i];
      a_k *= a;    // Precompute a^k for later use in rolling hash updates
    }

    return h;
}
```

### Step 3; Update the Hash and use a Set to Track Seen Substrings

After computing the initial hash, we slide a window through the string, efficiently updating the hash. Instead of recomputing the hash from scratch at ecery step, we adjust it by:
  - Removing the old character from the left.
  - Adding the new character on the right.

Using a rolling hash, the update formula becomes:

$$new hash = (old\space hash\times 4) - (leftmost\space digit\times 4^{10}) + new\space digit$$

In the code implementation, we'll use a loop to slide over `s` and update the hash value, `h`, for each new window. As we have already computed the hash for the first window, we'll start our loop from the index `1` of `s`. The variable `start` will always indicate the starting point of our window, and we'll get the ending point by adding `k` to it (to be precise in therms of coding, `start + k - 1`). So, to remove the contribution of the leftmost character and add the contribution of the right most character in `h`, we'll update as follows:

`h = (h * a) - (encodedSequence[start - 1] * a_k) + (encodedSequence[start + k - 1])`

We'll use a set, `seenHashes`, to track hashes we've seen before. If a hash, `h`, appears again, we add the corresponding substring to the result, `output`. Let's look at the code:

```cpp
vector<int> findRepeatedDnaSequences(const string& s) {
    // Define a mapping of DNA characters to numerical values
    unordered_map<char, int> toInt = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};

    // Convert each character in the input string to its corresponding number
    vector<int> encodedSequence;
    for (char c : s) {
        encodedSequence.push_back(toInt[c]);
    }

    const int k = 10;   // Length of DNA sequence to check
    int n = s.size();

    // If the string is shorter than 10 characters, return an empty list
    if (n <= k) {
      return {};
    }

    const int a = 4;    // Base-4 encoding
    int h = 0;          // Hash value

    // Sets to track hashes and repeated sequences
    unordered_set<int> seenHashes;
    unordered_set<string> output;

    int a_k = 1;        // Store a^k for hash updates

    // Compute the initial hash using base-4 multiplication
    for (int i = 0; i < k; i++) {
      h = h * a + encodedSequence[i];
      a_k *= a;    // Precompute a^k for later use in rolling hash updates
    }

    seenHashes.insert(h);    // Store the initial hash

    // Sliding window to update the hash efficiently
    for (int start = 1; start <= n - k; ++start) {
      // Remove the leftmost character and add the new rightmost character
      h = h * a - encodedSequence[start - 1] * a_k + encodedSequence[start + k - 1];

      // If this has has been seen before, add the corresponding substring to the output
      if (seenHashes.count(h)) {
        output.insert(s.substr(start, k));
      } else {
        seenHashes.insert(h);
      }
    }

    // Convert set to list before returning
    return vector<string>(output.begin(), output.end());
}
```

## Summary

1. Encode DNA sequence in `s` by converting `'A'`, `'C'`, `'G'`, and `'T'` into numbers (0, 1, 2, 3) for easier computation.
2. Use a set to store seen hashes and detect repeating sequences.
3. Compute the rolling hash for the first 10-letter substring and store it in the set.
4. Move the window one step forward and compute the hash of the new window. Store this new hash in the set. Store the corresponding substring in the result if the calculated hash appears again.
5. Once the entire string has been traversed, return the result containing all the repeating 10-letter long sequences.

## Visualization

<img width="933" height="655" alt="image" src="https://github.com/user-attachments/assets/0a5f3c95-9406-468a-8f1c-73038ad65fee" />

<img width="934" height="657" alt="image" src="https://github.com/user-attachments/assets/26d2fc0c-f3be-4d4a-a344-fb0ef5b29e43" />

<img width="933" height="656" alt="image" src="https://github.com/user-attachments/assets/ac1cf45f-b4be-40b9-99fc-e2f45151198c" />

<img width="932" height="657" alt="image" src="https://github.com/user-attachments/assets/ef526abc-0502-473d-ae52-0e295e9b7d40" />

<img width="934" height="655" alt="image" src="https://github.com/user-attachments/assets/fbbd7ef7-3612-40df-90a9-84c5e1ef8ab9" />

<img width="933" height="655" alt="image" src="https://github.com/user-attachments/assets/6a18fbb2-0bbe-4c6f-8eed-dc81d92b5c59" />

<img width="933" height="656" alt="image" src="https://github.com/user-attachments/assets/d637fdea-70e0-477d-98e8-d38136bcbfcc" />

<img width="933" height="655" alt="image" src="https://github.com/user-attachments/assets/a764e97c-2655-4d11-a33b-7ceb57c048bc" />

<img width="933" height="655" alt="image" src="https://github.com/user-attachments/assets/a82d1f9b-3268-4f86-a5f1-7b6224f77e90" />

<img width="933" height="656" alt="image" src="https://github.com/user-attachments/assets/bf55046d-cb7e-42ae-888f-1fd6f1dae480" />

<img width="934" height="655" alt="image" src="https://github.com/user-attachments/assets/ce88c253-853d-40e5-88ef-d12181f63dc4" />

<img width="932" height="655" alt="image" src="https://github.com/user-attachments/assets/aacc947a-7cfe-4f59-a3f3-b026e07fc279" />

<img width="932" height="656" alt="image" src="https://github.com/user-attachments/assets/028f0ad0-eba4-4da8-8c4a-1b3d4c3f345e" />

<img width="934" height="656" alt="image" src="https://github.com/user-attachments/assets/a1000516-4988-4a64-9e2c-10c9d1a5b7b4" />

<img width="933" height="656" alt="image" src="https://github.com/user-attachments/assets/51ab15e1-b8aa-4822-824d-c5e4052bf61a" />


## Time Complexity

Breaking down and analyzing the time complexity of the solution:
  - Go through tthe input string once to convert characters into numbers, takes $O(n)$.
  - Compute the first rolling hash in $O(k)$ time (where $k=10$). As $k$ is a fixed small number, it is treated as $O(1)$.
  - Slide through the string once, updating the hash in $O(1)$ time for each step. Overall, it takes $O(n-k)$ time, which can be simplified to $O(n)$ as $k$ is constant.
  - Checking and storing hashes in a set is $O(1)$ on average.

Summing these up, the overall time complexity simplifies to:

$$O(n)+O(1)+O(n)+O(1)=O(n)$$

## Space Complexity

Breaking down and analyzing the space complexity of the solution:
  - Store the encoded sequence as a list of nimbers, takes $O(n)$ space.
  - Store hashes in a set that would have, at most, $n-k+1$ entries. This is simplified to $O(n)$ space.
  - Store repeated sequences in another set that takes, at most, $n-k+1$ unique sequences. This is simplified to $O(n)$ space.

Summing these up, the overall space complexity simplifies to:

$$O(n)+O(n)+O(n)=O(n)$$
