#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Function to compute the sum of maximum elements of all subarrays multiplied by their lengths
long long sumOfMaxSubarrays(vector<int>& arr) {
    int n = arr.size(); // Size of the array

    // Arrays to store the index of the nearest greater elements to the left and right
    vector<int> prevGreater(n, -1); // Stores the index of the previous greater element
    vector<int> nextGreater(n, n);  // Stores the index of the next greater element

    stack<int> st; // Stack to keep track of indices for finding nearest greater elements

    // Step 1: Find the previous greater element for each index
    for (int i = 0; i < n; i++) {
        // Maintain a decreasing stack: pop elements that are smaller than the current one
        while (!st.empty() && arr[st.top()] < arr[i]) {
            st.pop();
        }

        // If stack is not empty, the top element is the previous greater element
        prevGreater[i] = (st.empty() ? -1 : st.top());

        // Push the current index onto the stack
        st.push(i);
    }

    // Clear the stack to reuse it for the next greater element search
    while (!st.empty()) {
        st.pop();
    }

    // Step 2: Find the next greater element for each index
    for (int i = n - 1; i >= 0; i--) {
        // Maintain a decreasing stack: pop elements that are smaller or equal to the current one
        while (!st.empty() && arr[st.top()] <= arr[i]) {
            st.pop();
        }

        // If stack is not empty, the top element is the next greater element
        nextGreater[i] = (st.empty() ? n : st.top());

        // Push the current index onto the stack
        st.push(i);
    }

    // Step 3: Compute the final sum of contributions
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        // Compute the number of subarrays where arr[i] is the maximum
        long long leftCount = i - prevGreater[i];   // Number of subarrays ending at 'i' where arr[i] is max
        long long rightCount = nextGreater[i] - i;  // Number of subarrays starting at 'i' where arr[i] is max

        // Contribution of arr[i] to the total sum
        sum += (arr[i] * leftCount * rightCount);
    }

    return sum; // Return the computed sum
}

// Main function to test the implementation
int main() {
    vector<int> arr = {4, 2, 1, 2}; // Example input array

    // Compute and print the sum of maximums of all subarrays multiplied by their length
    cout << "Sum of max of all subarrays multiplied by their length: " << sumOfMaxSubarrays(arr) << endl;
    return 0;
}