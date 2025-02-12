class Solution {
public:
    // Function to convert a string to an integer (mimicking atoi function)
    int myAtoi(string s) {
        int sign = 1;  // Variable to store the sign of the number (+1 for positive, -1 for negative)
        int res = 0;   // Variable to store the resulting integer
        int idx = 0;   // Index to iterate through the string
        int n = s.size();  // Length of the input string

        // Step 1: Ignore leading whitespaces
        while (idx < n && s[idx] == ' ') {
            idx++;  
        }

        // Step 2: Handle optional sign character ('+' or '-')
        if (idx < n && s[idx] == '-') {
            sign = -1;  // If '-' is found, update the sign to negative
            idx++;
        } else if (idx < n && s[idx] == '+') {
            idx++;  // If '+' is found, simply move to the next character
        }

        // Step 3: Process numerical digits
        while (idx < n && isdigit(s[idx])) {
            int digit = s[idx] - '0';  // Convert character to integer

            // Step 4: Handle integer overflow/underflow cases
            if ((res > INT_MAX / 10) || (res == INT_MAX / 10 && digit > INT_MAX % 10)) {
                return sign == 1 ? INT_MAX : INT_MIN;  // Clamp value within 32-bit integer range
            }

            // Step 5: Accumulate the number
            res = 10 * res + digit;
            idx++;
        }

        // Step 6: Apply sign and return the result
        return sign * res;
    }
};