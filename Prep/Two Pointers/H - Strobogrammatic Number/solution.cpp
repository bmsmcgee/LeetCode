#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

// Function to check if a number is strobogrammatic
bool IsStrobogrammatic(const string& num) 
{
    // Dictionary to map digits to their corresponding rotations
    unordered_map<char, char> dict = {{'0', '0'}, {'1', '1'}, {'8', '8'}, {'6', '9'}, {'9', '6'}};
    // Initialize pointers for the two ends of the string
    int left = 0;
    int right = num.size() - 1;

    // Iterate while the left pointer is less than or equal to the right pointer
    while (left <= right) {
        // Check if the current digit is valid and matches its corresponding rotated value
        if (dict.find(num[left]) == dict.end() || dict[num[left]] != num[right]) {
            // Return False if the number is not strobogrammatic            
            return false;
        }
        // Move pointers towards the center
        left++;
        right--;
    }
    // Return True if all digit pairs are valid
    return true;
}

// Driver code
int main() {
    vector<string> nums = {
        "609",
        "88",
        "962",
        "101",
        "123"
    };

    int i = 0;
    for (const auto& num : nums) {
        cout << i + 1 << ".\tnum: " << num << endl;
        cout << "\n\tIs strobogrammatic: " << (IsStrobogrammatic(num) ? "true" : "false") << endl;
        cout << string(100, '-') << endl;
        i++;
    }

    return 0;
}