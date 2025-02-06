class Solution {
    public:
        // Function to convert a Roman numeral string to an integer
        int romanToInt(string s) {
            // Map to store the integer values of individual Roman numeral characters
            map<char, int> val{
                {'I', 1}, 
                {'V', 5},
                {'X', 10},
                {'L', 50},
                {'C', 100},
                {'D', 500},
                {'M', 1000}
            };
    
            // Variable to store the final converted integer value
            int sum = 0;
    
            // Iterate through the given Roman numeral string
            for (int i = 0; i < s.length(); i++) {
                // Get the current Roman numeral character
                char currentSymbol = s[i];
                // Retrieve its corresponding integer value from the map
                int currentValue = val[currentSymbol];
                // Variable to store the value of the next Roman numeral (default is 0)
                int nextVal = 0;
    
                // Check if there's a next character in the string to avoid out-of-bounds access
                if (i + 1 < s.length()) {
                    char nextSymbol = s[i + 1];
                    nextVal = val[nextSymbol]; // Get the integer value of the next character
                }
    
                // If the current numeral is smaller than the next one, it means it's part of a subtractive pair (e.g., IV, IX, XL)
                if (currentValue < nextVal) {
                    sum += (nextVal - currentValue); // Add the adjusted value to sum
                    i++; // Skip the next character since it has already been processed
                } else {
                    sum += currentValue; // Otherwise, just add the current numeral's value
                }
            }
            
            // Return the computed integer value
            return sum;
        }
    };