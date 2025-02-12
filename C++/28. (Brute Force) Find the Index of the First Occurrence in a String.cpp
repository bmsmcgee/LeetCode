class Solution {
    public:
        // Function to find the first occurrence of 'needle' in 'haystack'
        int strStr(string haystack, string needle) {
            int n = haystack.length();  // Length of the main string (haystack)
            int m = needle.length();    // Length of the substring to be found (needle)
    
            // Loop to check every possible starting position in haystack where needle might occur
            for (int left = 0; left <= n - m; left++) {
                // Inner loop to compare characters of needle with haystack substring
                for (int right = 0; right < m; right++){
                    // If characters mismatch, break out of the inner loop
                    if (needle[right] != haystack[left + right]) {
                        break;
                    }
    
                    // If we have successfully matched all characters of needle, return the starting index
                    if (right == m - 1) {
                        return left;
                    }
                }
            }
    
            // If no match is found, return -1
            return -1;
        }
    };