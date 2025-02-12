#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to check if each string in product_a can be transformed into the corresponding string in product_b
vector<bool> equalProducts(const vector<string>& product_a, const vector<string>& product_b) {
    int n = product_a.size(); // Number of string pairs
    vector<bool> ans(n, false); // Initialize result vector with 'false' for all pairs

    // Iterate through each pair of strings in product_a and product_b
    for (int i = 0; i < n; i++) {
        const string &a = product_a[i]; // String from Team A
        const string &b = product_b[i]; // String from Team B
        
        bool ok = true; // Flag to determine if transformation is possible
        vector<int> mapping(26, -1); // Maps characters from 'a' to 'b' (initialized to -1)
        vector<bool> used(26, false); // Tracks whether a character in 'b' has been assigned
        
        // Iterate through characters in both strings (same length guaranteed)
        for (size_t j = 0; j < a.size(); j++) {
            int idxA = a[j] - 'a'; // Convert character 'a[j]' to a 0-25 index
            int idxB = b[j] - 'a'; // Convert character 'b[j]' to a 0-25 index

            // Case 1: If 'idxA' has not been mapped before, create a new mapping
            if (mapping[idxA] == -1) {
                // If 'idxB' is already mapped to another character, transformation is invalid
                if (used[idxB]) {
                    ok = false; // Conflicting mapping
                    break; // Stop checking further
                }
                mapping[idxA] = idxB; // Assign 'idxA' to 'idxB'
                used[idxB] = true; // Mark 'idxB' as used
            }
            // Case 2: If 'idxA' is already mapped but not to 'idxB', transformation is invalid
            else if (mapping[idxA] != idxB) {
                ok = false;
                break;
            }
        }

        ans[i] = ok; // Store result for the current pair
    }
    
    return ans; // Return results for all string pairs
}

int main() {
    int n;
    cin >> n; // Read number of test cases
    vector<string> product_a(n), product_b(n); // Vectors to store input strings

    // Read all strings for Team A
    for (int i = 0; i < n; i++) {
        cin >> product_a[i];
    }

    // Read all strings for Team B
    for (int i = 0; i < n; i++) {
        cin >> product_b[i];
    }

    // Get results of transformations
    vector<bool> res = equalProducts(product_a, product_b);

    // Print results (1 for possible transformation, 0 otherwise)
    for (bool r : res) {
        cout << (r ? 1 : 0) << "\n";
    }

    return 0;
}