#include <iostream>
#include <vector>

using namespace std;

// Helper function to convert a vector<int> to a string
string VectorToString(const vector<int>& vec) {
    string result = "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        result += to_string(vec[i]);
        if (i != vec.size() - 1) result += ", ";
    }
    result += "]";
    return result;
}

vector<int> SortColors(vector<int>& colors) {
    // Initialize the start, current, and end pointers
    int start = 0;
    int current = 0;
    int end = colors.size() - 1;

    // Iterate through the list until the current pointer exceeds the end pointer
    while (current <= end) {
        if (colors[current] == 0) {
            // If the current element is 0 (red), swap it with the element at the start pointer
            // This ensures the red element is placed at the beginning of the array
            swap(colors[start], colors[current]);
            // Move both the start and current pointers one position forward
            current++;
            start++;
        } else if (colors[current] == 1) {
            // If the current element is 1 (white), just move the current pointer one position forward
            current++;
        } else {
            // If the current element is 2 (blue), swap it with the element at the end pointer
            // This pushes the blue element to the end of the array
            swap(colors[current], colors[end]);
            // Move the end pointer one position backward
            end--;
        }
    }

    return colors;
}


// Driver code
int main() {
    vector<vector<int>> inputs = {
        {0, 1, 0},
        {1, 1, 0, 2},
        {2, 1, 1, 0, 0},
        {2, 2, 2, 0, 1, 0},
        {2, 1, 1, 0, 1, 0, 2}
    };

    for (int i = 0; i < inputs.size(); i++) {
        cout << i + 1 << ".\tcolors: " << VectorToString(inputs[i]);
        cout << "\n\n\tThe sorted array is: " << VectorToString(SortColors(inputs[i]));
        cout << "\n" << std::string(100, '-') << std::endl;
    }
    return 0;
}