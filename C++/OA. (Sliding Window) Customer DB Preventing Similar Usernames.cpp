#include <iostream>
#include <vector>

using namespace std;

// Function to compute the p-matching score
int solve(const string& id1, const string& id2, const int p) {
    const int n = (int)id1.size(), m = (int)id2.size(); // Get lengths of userID1 and userID2

    vector<int> cnt2(26); // Frequency array for characters in id2
    int distinct2 = 0;    // Count of distinct characters in id2

    // Populate frequency array for id2 and count distinct characters
    for (const auto c : id2)
        distinct2 += ++cnt2[c - 'a'] == 1; // Increment only if this is the first occurrence of the character

    int ans = 0; // Stores the final p-matching score

    // Iterate over all possible starting indices (0 to p-1)
    for (int i = 0; i < p; i++) {
        vector<int> cnt1(26); // Frequency array for current window in id1
        int match = 0;        // Tracks how many characters match with id2's frequency array
        int left = i;         // Left boundary of the sliding window

        // Iterate through id1 with step size p, forming substrings
        for (int j = i; j < n; j += p) {
            const int c = id1[j] - 'a';  // Convert character to index

            // Update frequency count for current character and track matches
            match += ++cnt1[c] == cnt2[c]; // If frequency matches that of id2, increment match count

            // Ensure we only start checking after forming a full substring of length 'm'
            if ((j - left) / p + 1 < m)
                continue; // Skip until we have enough characters

            // If all distinct characters in the window match, count this as a valid starting index
            ans += match == distinct2;

            // Slide the window: remove the leftmost character and adjust match count
            const int c1 = id1[left] - 'a'; // Character to remove
            match -= cnt1[c1]-- == cnt2[c1]; // If it was previously a match, decrement match count
            left += p; // Move left boundary forward
        }
    }

    return ans; // Return the total valid starting indices
}

// Main function for testing
int main() {
    string userID1 = "accacaa";
    string userID2 = "aac";
    int p = 2;

    cout << "P-matching score: " << solve(userID1, userID2, p) << endl;
    return 0;
}