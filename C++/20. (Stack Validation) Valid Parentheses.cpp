// Define a class named Solution, which contains the function isValid.
class Solution {
    public:
        // Function to check if the given string `s` has valid parentheses
        bool isValid(string s) {
            // Declare a stack to store open brackets
            stack<char> st;
    
            // Create an unordered_map to map closing brackets to their corresponding opening brackets
            unordered_map<char, char> mp = {
                {')', '('},  // Closing parenthesis maps to opening parenthesis
                {'}', '{'},  // Closing curly brace maps to opening curly brace
                {']', '['}   // Closing square bracket maps to opening square bracket
            };
    
            // Iterate through each character `c` in the string `s`
            for (char c : s) {
                // Check if the character is a closing bracket by looking it up in the map
                if (mp.find(c) == mp.end()) {
                    // If not found in the map, it means `c` is an opening bracket
                    // Push the opening bracket onto the stack
                    st.push(c);
                } 
                // If the stack is not empty and the top element in the stack matches the corresponding opening bracket
                else if (!st.empty() && mp[c] == st.top()) {
                    // If the top of the stack matches the expected opening bracket, pop it
                    st.pop();
                } 
                else {
                    // If the stack is empty or the top of the stack does not match, return false (invalid sequence)
                    return false;
                }
            }
    
            // If the stack is empty at the end, return true (all brackets matched correctly), otherwise return false
            return st.empty();
        }
    };