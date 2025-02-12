#include <iostream>
#include <vector>
#include <algorithm> // For max_element

using namespace std;

class Solution {
public:
    // Function to find the minimum eating speed required to finish all piles within 'h' hours
    int minEatingSpeed(vector<int>& piles, int h) {     
        // The possible eating speed ranges from 1 banana per hour to the maximum pile size
        int left = 1, right = *max_element(piles.begin(), piles.end());

        // Apply Binary Search on the possible eating speed values
        while (left < right) {
            int middle = (left + right) / 2;  // Midpoint of the current range
            int hourSpent = 0;  // To count the total hours required for this speed

            // Calculate the total hours required to eat all the piles at 'middle' speed
            for (int pile : piles) {
                // Each pile takes 'pile / middle' full hours + 1 extra if there are leftovers
                hourSpent += pile / middle + (pile % middle != 0);
            }

            // If we can finish eating all bananas within 'h' hours, try a slower eating speed
            if (hourSpent <= h) {
                right = middle;  // Reduce the maximum speed and search in the lower range
            } else {
                left = middle + 1;  // Increase the minimum speed as the current one is too slow
            }
        }

        return right; // The minimum valid speed to eat all piles within 'h' hours
    }
};

// Example usage
int main() {
    Solution sol;
    vector<int> piles = {3, 6, 7, 11};  // Example pile sizes
    int h = 8;  // Example time constraint in hours
    cout << "Minimum eating speed: " << sol.minEatingSpeed(piles, h) << endl;
    return 0;
}