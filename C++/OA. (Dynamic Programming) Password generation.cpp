#include <iostream>
#include <vector>

using namespace std;

// Function to count the number of secured substrings
int countSecuredStrings(const string& s, const string& t) {
    constexpr int mod = 1e9 + 7; // Large prime modulus to prevent overflow
    const int n = (int)s.size(), m = (int)t.size(); // Lengths of strings s and t

    vector<int> dp(m + 1); // DP array to store counts of secured substrings
    int p2 = 1; // Stores powers of 2, representing the number of ways to form subsequences

    // Iterate backwards over string s
    for (int i = n - 1; i >= 0; i--) {
        dp[m] = p2 - 1; // Initialize dp[m] as p2 - 1 to track subsequences count

        // Compare characters of s with t
        for (int j = 0; j < m; j++) {
            if (s[i] > t[j]) {
                // If s[i] is greater than t[j], add current power of 2 to dp[j]
                dp[j] = (dp[j] + p2) % mod;
            } else if (s[i] == t[j]) {
                // If characters match, propagate dp[j + 1] forward
                dp[j] = (dp[j] + dp[j + 1]) % mod;
            }
        }

        // Update power of 2 for the next iteration
        p2 = p2 * 2 % mod;
    }

    return dp[0]; // Return the total count of secured strings
}

// Main function for testing
int main() {
    cout << countSecuredStrings("aba", "ab") << endl; // Expected Output: 3
    cout << countSecuredStrings("bab", "ab") << endl; // Expected Output: 5
    return 0;
}