#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool FindNextPermutation(vector<char>& digits) {
    // Step 1: Find the first digit that is smaller than the digit after it
    int i = digits.size() - 2;
    while (i >= 0 && digits[i] >= digits[i + 1]) {
        i--;
    }
    if (i == -1) {
        return false;
    }

    // Step 2: Find the next largest digit to swap with digits[i]
    int j = digits.size() - 1;
    while (digits[j] <= digits[i]) {
        j--;
    }

    // Step 3: Swap and reverse the rest to get the smallest next permutation
    swap(digits[i], digits[j]);
    reverse(digits.begin() + i + 1, digits.end());
    return true;
}

string FindNextPalindrome(string numStr) {
    int n = numStr.size();

    if (n == 1) {
        return "";
    }

    int halfLength = n / 2;
    vector<char> leftHalf(numStr.begin(), numStr.begin() + halfLength);

    // Step 1: Get the next permutation for the left half
    if (!FindNextPermutation(leftHalf)) {
        return "";
    }

    // Step 2: Form the next palindrome by mirroring the left half
    string nextPalindrome;
    if (n % 2 == 0) {
        nextPalindrome = string(leftHalf.begin(), leftHalf.end()) + string(leftHalf.rbegin(), leftHalf.rend());
    } else {
        nextPalindrome = string(leftHalf.begin(), leftHalf.end()) + numStr[halfLength] + string(leftHalf.rbegin(), leftHalf.rend());
    }

    // Step 3: Ensure the result is larger than the original number
    if (nextPalindrome > numStr) {
        return nextPalindrome;
    }
    return "";
}

int main() {
    vector<string> testCases = {"1221", "54345", "999", "12321", "89798"};

    for (int i = 0; i < testCases.size(); ++i) {
        cout << i + 1 << ".\t Original palindrome: '" << testCases[i] << "'" << endl;
        string nextPalindrome = FindNextPalindrome(testCases[i]);
        cout << "\t Next greater palindrome: '" << nextPalindrome << "'" << endl;
        cout << string(100, '-') << endl;
    }

    return 0;
}
