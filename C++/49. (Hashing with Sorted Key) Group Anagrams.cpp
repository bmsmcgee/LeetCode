class Solution {
    public:
        // Function to group anagrams together
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            unordered_map<string, vector<string>> mp;  // HashMap to store sorted-word as key and group of anagrams as value
    
            // Iterate through each string in the input list
            for (auto x : strs) {
                string word = x;  // Copy the original string
                sort(word.begin(), word.end());  // Sort the characters to create a unique key for anagrams
                mp[word].push_back(x);  // Store the original string under its sorted version in the map
            }
    
            // Convert the map values into a 2D vector for the final output
            vector<vector<string>> ans;
            for (auto x : mp) {
                ans.push_back(x.second);  // Extract anagram groups from the map and add them to the result
            }
    
            return ans;  // Return the list of grouped anagrams
        }
    };