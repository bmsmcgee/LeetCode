#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Function to determine the target index for each request
vector<int> findRequestTarget(const int n, const vector<int>& requests) {
    vector<int> assigned(n); // Keeps track of how many times each index has been assigned
    unordered_map<int, int> next; // Maps request count to the next available index
    vector<int> ret; 
    ret.reserve(requests.size()); // Preallocate memory for efficiency

    // Process each request
    for (const auto r : requests) {
        const int cnt = assigned[r]; // Get the current count of assignments for request 'r'
        const int idx = next[cnt];   // Determine the next available index based on count
        
        ret.push_back(idx);  // Store the target index in the result vector
        assigned[idx]++;      // Increment the assignment count for this index
        next[cnt]++;          // Move to the next available index for this count
    }
    return ret;
}

// Main function to test the implementation
int main() {
    vector<int> result1 = findRequestTarget(5, {3, 2, 3, 2, 4}); // Expected: {0,1,2,0,3}
    vector<int> result2 = findRequestTarget(4, {0, 1, 2, 3});    // Expected: {0,1,2,3}

    // Print the results
    for (int val : result1) {
        cout << val << " ";
    }
    cout << endl;

    for (int val : result2) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}