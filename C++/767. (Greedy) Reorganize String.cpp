class Solution {
    public:
        string reorganizeString(string s) {
            unordered_map<char, int> mp; // Hash map to store the frequency of each character
    
            int maxCount = 0; // Variable to track the maximum frequency of any character
            char letter = 0;  // Character that appears the most in the string
    
            // Count the frequency of each character and determine the most frequent character
            for (const char &c : s) {
                mp[c]++; // Increment the frequency count for the character
                if (mp[c] > maxCount) { // Update the most frequent character if necessary
                    maxCount = mp[c];
                    letter = c;
                }
            }
    
            // If the most frequent character appears more times than allowed, return ""
            // The condition ensures that the most frequent character does not exceed half the length of the string
            if (maxCount > (s.length() + 1) / 2) {
                return "";
            }
    
            string res = s; // Result string, initialized with the input string
            int idx = 0;    // Index to place characters in the result string
    
            // Place the most frequent character in even indices first
            while (mp[letter] != 0) {
                res[idx] = letter; // Assign the most frequent character at the current position
                idx += 2;          // Move to the next available even index
                mp[letter]--;      // Decrease the frequency of the placed character
            }
    
            // Place the remaining characters in the string
            for (const char &c : s) {
                while (mp[c] > 0) { // As long as the character has occurrences left to place
                    if (idx >= s.length()) { // If we run out of even indices, start filling odd indices
                        idx = 1;
                    }
                    res[idx] = c; // Place the character at the current index
                    idx += 2;      // Move to the next available position
                    mp[c]--;       // Decrease the frequency of the placed character
                }
            }
    
            return res; // Return the reorganized string
        }
    };