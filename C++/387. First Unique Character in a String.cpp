class Solution {
    public:
        // Function to find the index of the first non-repeating character in a string
        int firstUniqChar(string s) {
            unordered_map<char, int> mp;  // Hash map to store character frequencies
    
            // Step 1: Count occurrences of each character in the string
            for (char c : s) {
                mp[c]++;  // Increment frequency count for each character
            }
    
            // Step 2: Iterate through the string again to find the first unique character
            for (int i = 0; i < s.size(); i++) {
                if (mp[s[i]] == 1) {  // If character appears only once, return its index
                    return i;
                }
            }
    
            return -1;  // If no unique character is found, return -1
        }
    };