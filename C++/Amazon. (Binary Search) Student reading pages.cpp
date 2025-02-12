#include <iostream>
#include <vector>
#include <algorithm> // For max_element

using namespace std;

class Solution {
public:
    // Function to find the minimum number of pages per day required to finish all books in given 'days'
    int minimumNumberOfPages(vector<int>& pages, int days) {
        int sum_pages = 0; // Store the sum of all pages in the books

        // Calculate the total sum of pages manually (avoiding std::accumulate)
        for (int page : pages) {
            sum_pages += page;
        }

        int low = sum_pages / days; // A more realistic lower bound instead of starting at 1
        int high = sum_pages; // The worst-case scenario: reading all pages in one day
        int result = high; // Store the minimum possible pages per day

        // Binary search to find the optimal daily page count
        while (low <= high) {
            int mid = low + (high - low) / 2; // Midpoint represents a candidate reading speed
            int days_needed = getDays(pages, mid); // Compute required days for this speed

            if (days_needed <= days) { 
                // If we can finish within 'days', try reducing the max pages per day
                result = mid; 
                high = mid - 1; // Explore smaller values
            } else { 
                // If not possible, increase the minimum reading speed
                low = mid + 1;
            }
        }

        return result; // Return the minimum valid number of pages per day
    }

    // Function to determine how many days are needed to finish all books with a given 'capacity' per day
    int getDays(vector<int>& pages, int capacity) {
        int days_needed = 0; // Total days required

        for (int page : pages) {
            // Compute the number of days required to read 'page' pages at 'capacity' speed
            // This is equivalent to ceil(page / capacity) but avoids floating-point operations
            days_needed += (page + capacity - 1) / capacity;
        }

        return days_needed; // Return the total number of days needed
    }
};

// Main function to test the implementation
int main() {
    Solution sol;
    vector<int> pages = {100, 200, 300, 400}; // Example book pages
    int days = 4; // Number of days available to read

    // Print the minimum number of pages required per day
    cout << "Minimum number of pages per day: " << sol.minimumNumberOfPages(pages, days) << endl;
    return 0;
}