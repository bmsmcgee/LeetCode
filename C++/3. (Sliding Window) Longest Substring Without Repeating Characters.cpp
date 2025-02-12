class Solution {
public:
    // Function to find the length of the longest substring without repeating characters
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> chars; // Hash map to store character frequency in the current window

        int left = 0;  // Left pointer for the sliding window
        int right = 0; // Right pointer for the sliding window
        int res = 0;   // Variable to store the length of the longest substring found

        // Iterate through the string using the right pointer
        while (right < s.length()) {
            char r = s[right]; // Current character at the right pointer
            chars[r]++;        // Increment its frequency in the hash map

            // If the character appears more than once, shrink the window from the left
            while (chars[r] > 1) {
                char l = s[left]; // Character at the left pointer
                chars[l]--;       // Reduce its count in the map
                left++;           // Move the left pointer forward
            }

            // Update the result with the maximum length of the substring found so far
            res = max(res, right - left + 1);

            right++; // Expand the window by moving the right pointer forward
        }

        return res; // Return the maximum length of a substring without repeating characters
    }
};