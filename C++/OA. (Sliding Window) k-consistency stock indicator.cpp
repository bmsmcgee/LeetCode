#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Function to calculate the k-consistency score
int kConsistencyScore(vector<int>& stockPrices, int k) {
    int n = stockPrices.size();
    unordered_map<int, int> freq; // Frequency map to store occurrences of elements in window
    int left = 0, maxLen = 0; // Sliding window pointers and max length
    
    for (int right = 0; right < n; right++) {
        freq[stockPrices[right]]++; // Expand window by including current element
        
        // Find the most frequent element in the window
        int maxFreq = 0;
        for (auto &p : freq) {
            maxFreq = max(maxFreq, p.second);
        }

        // If removals exceed k, shrink the window
        while ((right - left + 1) - maxFreq > k) {
            freq[stockPrices[left]]--; // Remove leftmost element from frequency map
            if (freq[stockPrices[left]] == 0) {
                freq.erase(stockPrices[left]); // Remove from map if count is 0
            }
            left++; // Move left pointer forward
        }

        // Update max length
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

// Main function for testing
int main() {
    vector<int> stock1 = {1, 1, 2, 2, 1, 1, 1}; 
    int k1 = 2;
    cout << kConsistencyScore(stock1, k1) << endl; // Expected Output: 5

    vector<int> stock2 = {3, 3, 3, 1, 3, 3, 3}; 
    int k2 = 1;
    cout << kConsistencyScore(stock2, k2) << endl; // Expected Output: 7

    vector<int> stock3 = {1, 2, 3, 4, 5, 6}; 
    int k3 = 2;
    cout << kConsistencyScore(stock3, k3) << endl; // Expected Output: 3

    return 0;
}