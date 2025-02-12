#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// Function to find the longest self-sufficient proper substring length
int longestSelfSufficientSubstring(const string& fullString) {
    int n = fullString.size(); // Get the length of the string

    // If the string is too short to have a proper substring, return 0
    if (n <= 1) return 0;

    unordered_map<char, int> fullFreq; // Stores frequency of each character in fullString

    // Count the occurrences of each character in fullString
    for (char c : fullString) {
        fullFreq[c]++;
    }

    int maxLength = 0; // Stores the length of the longest self-sufficient substring found

    // Iterate through all possible starting points of substrings
    for (int start = 0; start < n; start++) {
        unordered_map<char, int> subFreq; // Stores character frequencies in the current substring
        unordered_set<char> usedOutside;  // Tracks characters that appear outside the substring

        // Expand the substring from 'start' to 'end'
        for (int end = start; end < n; end++) {
            char c = fullString[end]; // Current character in the substring
            subFreq[c]++; // Increment frequency count for the substring

            // If all occurrences of 'c' are now inside the substring, remove from 'usedOutside'
            if (subFreq[c] == fullFreq[c]) {
                usedOutside.erase(c);
            } else {
                usedOutside.insert(c); // If 'c' still exists outside, add it to 'usedOutside'
            }

            // Check if the substring is valid:
            // 1. It should be a proper substring (not the full string)
            // 2. No characters inside the substring should exist outside
            if (end - start + 1 < n && usedOutside.empty()) {
                maxLength = max(maxLength, end - start + 1);
            }
        }
    }

    return maxLength; // Return the longest valid substring length
}

// Main function to test the implementation
int main() {
    // Test cases
    string test1 = "abcab"; // Expected Output: 3 ("bca" or "cab")
    string test2 = "aaaa";  // Expected Output: 0 (no valid substring)
    string test3 = "abcd";  // Expected Output: 3 (e.g., "abc", "bcd")

    // Run the function on the test cases and print the results
    cout << longestSelfSufficientSubstring(test1) << endl;
    cout << longestSelfSufficientSubstring(test2) << endl;
    cout << longestSelfSufficientSubstring(test3) << endl;

    return 0;
}