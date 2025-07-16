#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

vector<string> findRepeatedDnaSequences(string s) {
    unordered_map<char, int> toInt = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
    vector<int> encodedSequence;
    for (char c : s) {
        encodedSequence.push_back(toInt[c]);
    }

    const int k = 10;
    int n = s.size();

    if (n <= k) return {};

    const int a = 4;
    int h = 0;
    unordered_set<int> seenHashes;
    unordered_set<string> output;
    int a_k = 1;

    // Encode the first k characters
    for (int i = 0; i < k; ++i) {
        h = h * a + encodedSequence[i];
        a_k *= a;
    }

    seenHashes.insert(h);

    for (int start = 1; start <= n - k; ++start) {
        h = h * a - encodedSequence[start - 1] * a_k + encodedSequence[start + k - 1];

        if (seenHashes.count(h)) {
            output.insert(s.substr(start, k));
        } else {
            seenHashes.insert(h);
        }
    }

    return vector<string>(output.begin(), output.end());
}

// Driver code
int main() {
    vector<string> testCases = {
        "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
        "AAAAAAAAAAAAA",
        "ACGTACGTACGTACGTACGTACGTACGTACGT",
        "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG",
        "GTACGTACGTACGCCCCCCCCGGGGG"
    };

    for (size_t i = 0; i < testCases.size(); ++i) {
        cout << i + 1 << ".\tInput: \"" << testCases[i] << "\""<<endl;

        vector<string> result = findRepeatedDnaSequences(testCases[i]);
        cout << "\n\tOutput: [";
        for (size_t j = 0; j < result.size(); ++j) {
            cout << "\"";
            cout << result[j];
            cout << "\"";
            if (j < result.size() - 1) cout << ", ";
        }
        cout << "]\n" << string(100, '-') <<endl;
    }

    return 0;
}
