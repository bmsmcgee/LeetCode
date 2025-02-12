class Solution {
    public:
        int maxSubstringLength(string s) {
            // Vectors to track the first and last occurrence of each character in the string
            vector<int> first(26, -1); // Stores the first occurrence index of each character ('a' to 'z'), initialized to -1
            vector<int> last(26); // Stores the last occurrence index of each character ('a' to 'z')
            
            int n = s.length(); // Length of the input string
    
            // Iterate through the string to determine the first and last occurrence of each character
            for (int i = 0; i < n; ++i) {
                int j = s[i] - 'a'; // Convert character to index (0 for 'a', 1 for 'b', ..., 25 for 'z')
                
                if (first[j] == -1) { // If this character appears for the first time in the string
                    first[j] = i; // Set its first occurrence index
                }
                last[j] = i; // Update the last occurrence index of this character
            }
    
            int ans = -1; // Variable to store the maximum valid substring length
    
            // Iterate through each character ('a' to 'z')
            for (int k = 0; k < 26; ++k) {
                int i = first[k]; // Get the first occurrence index of character 'k'
    
                if (i == -1) { // If this character does not exist in the string, skip it
                    continue;
                }
    
                int mx = last[k]; // Get the last occurrence index of character 'k'
    
                // Expand the window starting from index 'i'
                for (int j = i; j < n; ++j) {
                    int a = first[s[j] - 'a']; // Get the first occurrence index of character at 's[j]'
                    int b = last[s[j] - 'a']; // Get the last occurrence index of character at 's[j]'
    
                    if (a < i) { // If a character appears before 'i', break (invalid substring)
                        break;
                    }
    
                    mx = max(mx, b); // Update the maximum right boundary
    
                    // Check if the current substring is valid and update the answer
                    if (mx == j && j - i + 1 < n) {
                        ans = max(ans, j - i + 1);
                    }
                }
            }
            
            return ans; // Return the maximum valid substring length
        }
    };