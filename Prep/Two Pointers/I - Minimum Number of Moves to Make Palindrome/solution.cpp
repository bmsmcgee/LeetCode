#include <string>
#include <iostream>
#include <vector>

using namespace std;

int MinMovesToMakePalindrome(string s) {
    // Counter to keep trakc of the total number of swaps
    int moves = 0;
    
    // Loop to find a character from the right (s[j]) that
    // matches with a character from the left (s[i])
    for (int i = 0, j = s.size() - 1; i < j; ++i) {
        int k = j;
        for (; k > i; --k){
            // If a matching character is found
            if (s[i] == s[k]) {
                // Move the matching character to the correct position on the right
                for (; k < j; ++k) {
                    swap(s[k], s[k + 1]);
                    // Increment count of swaps
                    ++moves;
                }
                // Move the right pointer inwards
                --j;
                break;
            }
        }
        // If no matching character is found, it must be moved to the center of palindrome
        if (k == i)
            moves += s.size() / 2 - i;
      }
      return moves;
}

// Driver code
int main() {
    vector<string> strings = {"ccxx", "arcacer", "w", "ooooooo", "eggeekgbbeg"};
    
    for (int i = 0; i < strings.size(); ++i) {
        cout << i + 1 << ".\ts: " << strings[i] << endl;
        cout << "\tMoves: " << MinMovesToMakePalindrome(strings[i]) << endl;
        cout << string(100, '-') << endl;
    }

    return 0;
}