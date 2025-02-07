class Solution {
    public:
        // Function to convert an integer to its English words representation
        string numberToWords(int num) {
            if (num == 0) return "Zero"; // Special case: If number is 0, return "Zero"
            
            // Array to store large number suffixes
            string bigString[] = {"Thousand", "Million", "Billion"};
    
            // Convert the last three digits first (ones, tens, hundreds place)
            string result = numberToWordsHelper(num % 1000);
            num /= 1000; // Remove processed last three digits
    
            // Process each group of three digits (thousands, millions, billions)
            for (int i = 0; i < 3; ++i) {
                if (num > 0 && num % 1000 > 0) {
                    result = numberToWordsHelper(num % 1000) + bigString[i] + " " + result;
                }
                num /= 1000; // Move to the next group of three digits
            }
    
            // Remove trailing space and return the result
            return result.empty() ? result : result.substr(0, result.size() - 1);
        }
    
        // Helper function to convert numbers up to 999 into words
        string numberToWordsHelper(int num) {
            // Arrays to store English words for digits, teens, and tens place values
            string digitString[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
            string teenString[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
            string tenString[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    
            string result = "";
    
            // Handle hundreds place (if present)
            if (num > 99) {
                result += digitString[num / 100] + " Hundred ";
            }
            
            num %= 100; // Remove the hundreds place
            
            // Handle numbers between 10 and 19 (special case for "teens")
            if (num < 20 && num > 9) {
                result += teenString[num - 10] + " ";
            } else {
                // Handle tens place (20, 30, 40, ..., 90)
                if (num >= 20) {
                    result += tenString[num / 10] + " ";
                }
                num %= 10; // Remove the tens place
                
                // Handle ones place (1-9)
                if (num > 0) {
                    result += digitString[num] + " ";
                }
            }
            
            return result;
        }
    };