#include <bits/stdc++.h>
using namespace std;

int solve(string &s) {

    int n = s.size();

    // firstPos[c] and lastPos[c] store the first and last occurrence
    // of the character c in the string. If c doesn't appear, both remain -1.
    vector<int> firstPos(26, -1), lastPos(26, -1);

    // Fill firstPos and lastPos for each character
    for (int i = 0; i < n; i++) {
        int c = s[i] - 'a';
        if (firstPos[c] == -1) {
            firstPos[c] = i;      // first time we see character c
        }
        lastPos[c] = i;          // keep updating last position
    }

    // Build a prefix frequency table so we can quickly count how many times
    // each letter appears in any substring s[L..R].
    // prefixFreq[c][i] = how many times character c appears in s[0..i-1].
    vector<vector<int>> prefixFreq(26, vector<int>(n + 1, 0));
    for (int i = 0; i < n; i++) {
        int c = s[i] - 'a';
        for (int letter = 0; letter < 26; letter++) {
            prefixFreq[letter][i + 1] = prefixFreq[letter][i];
        }
        prefixFreq[c][i + 1]++;
    }

    int best = 0; // Will track the length of the longest valid substring

    // Check each letter's "span" [start..end] = [firstPos[c]..lastPos[c]].
    // That span includes all occurrences of character c.
    // If that span is self-sufficient (and not the entire string),
    // update 'best' if it's longer than the current 'best'.
    for (int c = 0; c < 26; c++) {
        if (firstPos[c] == -1) {
            continue; // This letter doesn't appear at all
        }
        int start = firstPos[c];
        int end   = lastPos[c];
        int length = end - start + 1;

        // The substring must be proper (not the entire string).
        if (length == n) {
            continue;
        }

        // We'll check if every letter that appears in s[start..end]
        // is fully contained in that same range.
        bool valid = true;
        for (int letter = 0; letter < 26; letter++) {
            // Count how many times 'letter' appears within [start..end].
            int countInRange = prefixFreq[letter][end + 1] - prefixFreq[letter][start];
            if (countInRange > 0) {
                // If 'letter' appears here, verify its entire range
                // is inside [start..end].
                if (firstPos[letter] < start || lastPos[letter] > end) {
                    valid = false;
                    break;
                }
            }
        }

        if (valid) {
            best = max(best, length);
        }
    }

    // If no valid substring was found that is smaller than the entire string, best remains 0.
    cout << best << endl;
    return best;
}
