class Solution {
    public:
        // Function to compare two version numbers
        int compareVersion(string version1, string version2) {
            int i = 0, j = 0;  // Pointers for version1 and version2
    
            // Iterate through both version strings
            while (i < version1.size() || j < version2.size()) {
                int v1 = 0, v2 = 0;  // Stores numerical values of version segments
    
                // Extract numerical value of the current segment in version1
                while (i < version1.size() && version1[i] != '.') {
                    v1 = v1 * 10 + (version1[i] - '0');  // Convert char to int and accumulate
                    i++;
                }
    
                // Extract numerical value of the current segment in version2
                while (j < version2.size() && version2[j] != '.') {
                    v2 = v2 * 10 + (version2[j] - '0');  // Convert char to int and accumulate
                    j++;
                }
    
                // Compare the extracted version numbers
                if (v1 > v2) {
                    return 1;  // version1 is greater
                } else if (v1 < v2) {
                    return -1; // version2 is greater
                }
    
                // Move past the '.' separator for both versions
                i++;
                j++;
            }
    
            return 0;  // Both versions are equal
        }
    };