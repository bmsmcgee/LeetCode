class Solution {
    public:
        // Function to convert an integer to its Roman numeral representation
        string intToRoman(int num) {
            // Define the values of Roman numerals in descending order
            vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    
            // Corresponding Roman numeral symbols for each value in the 'values' vector
            vector<string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    
            // Resultant string to store the Roman numeral representation
            string res;
    
            // Iterate through all the defined values, starting from the largest
            for (int i = 0; i < values.size() && num > 0; i++) {
                // While the current value can be subtracted from num, keep adding the corresponding Roman symbol
                while (values[i] <= num) {
                    num -= values[i];   // Reduce num by the current value
                    res += symbols[i];  // Append the corresponding Roman numeral symbol to result
                }
            }
    
            // Return the final Roman numeral representation
            return res;
        }
    };