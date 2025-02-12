class Solution {
    public:
        // Function to check if a number is a perfect square
        bool isPerfectSquare(int num) {
            // Step 1: Handle small cases
            if (num < 2) {
                return true; // 0 and 1 are perfect squares
            }
    
            // Step 2: Initialize the approximation value (starting point for Newton's method)
            long x = num / 2; 
    
            // Step 3: Newton-Raphson Method (Iteratively refine the approximation)
            while (x * x > num) {
                x = (x + num / x) / 2; // Update approximation using Newton's formula
            }
    
            // Step 4: Check if the computed value is an exact square root
            return (x * x == num);
        }
    };