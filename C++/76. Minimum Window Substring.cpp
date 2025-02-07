class Solution {
    public:
        // Function to find the minimum window substring in 's' that contains all characters of 't'
        string minWindow(string s, string t) {
            int m = s.length();  // Length of the main string 's'
            int n = t.length();  // Length of the target string 't'
    
            // Edge case: if 't' is empty, 's' is empty, or 't' is longer than 's', return ""
            if (n == 0 || m == 0 || n > m) {
                return "";
            }
    
            // Step 1: Create a frequency map for all characters in 't'
            unordered_map<char, int> tChars;
            for (char c : t) {
                tChars[c]++;  // Count occurrences of each character in 't'
            }
    
            int req = tChars.size();  // Number of unique characters in 't' that need to be matched
            int left = 0, unique = 0; // Left pointer for sliding window, 'unique' tracks matched characters
    
            unordered_map<char, int> window; // Map to track character frequency in the current window
    
            // Array to store the minimum window details: [window size, left index, right index]
            int ans[3] = {-1, 0, 0};
    
            // Step 2: Expand the right pointer to find a valid window
            for (int right = 0; right < m; right++) {
                char c = s[right]; // Current character
                window[c]++; // Increase the frequency count of the current character in the window
    
                // If the character is in 't' and its count matches the required count, increase 'unique'
                if (tChars.find(c) != tChars.end() && window[c] == tChars[c]) {
                    unique++;
                }
    
                // Step 3: Shrink the window from the left to find the smallest valid window
                while (left <= right && unique == req) {
                    c = s[left];  // Current character at the left pointer
    
                    // Update the minimum window if the current one is smaller
                    if (ans[0] == -1 || right - left + 1 < ans[0]) {
                        ans[0] = right - left + 1; // Window size
                        ans[1] = left;  // Start index of the window
                        ans[2] = right; // End index of the window
                    }
    
                    window[c]--; // Reduce the count of the left character
    
                    // If a required character falls below the needed count, reduce 'unique'
                    if (tChars.find(c) != tChars.end() && window[c] < tChars[c]) {
                        unique--;
                    }
    
                    left++; // Move the left pointer to shrink the window
                }
            }
    
            // Step 4: Return the minimum window substring or an empty string if no valid window exists
            return ans[0] == -1 ? "" : s.substr(ans[1], ans[2] - ans[1] + 1);
        }
    };