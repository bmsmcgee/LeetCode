class Solution {
    public:
        // Function to find the most common non-banned word in a paragraph
        string mostCommonWord(string paragraph, vector<string>& banned) {
            // Hash map to store the frequency of each word
            unordered_map<string, int> mp;
            
            // Hash set to store banned words for quick lookup
            unordered_set<string> b(banned.begin(), banned.end());
    
            string res;   // Stores the most common valid word
            string word;  // Temporary variable to construct words
    
            // Iterate through each character in the paragraph
            for (char &c : paragraph) {
                if (isalpha(c)) {  // Check if the character is a letter
                    word += tolower(c);  // Convert to lowercase and build the word
                } else if (!word.empty()) {  
                    // If the current character is not a letter and a word has been built
                    
                    // If the word is **not in the banned set**, update its frequency
                    if (!b.count(word) && ++mp[word] > mp[res]) {
                        res = word;  // Update the most common word if this one has a higher frequency
                    }
                    word.clear();  // Clear the word buffer for the next word
                }
            }
    
            // Handle the last word (if paragraph doesn't end with punctuation)
            if (!word.empty() && !b.count(word) && ++mp[word] > mp[res]) {
                res = word;  // Update the most common word
            }
    
            return res;  // Return the most frequently occurring non-banned word
        }
    };