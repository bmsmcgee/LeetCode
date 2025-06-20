#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool ValidWordAbbreviation(const string& word, const string& abbr) {
    int wordIndex = 0, abbrIndex = 0;

    while (abbrIndex < abbr.size()) {
        // Check if the current character is a digit.
        if (isdigit(abbr[abbrIndex])) {
            // Check if there's a leading zero. If there is, return False.
            if (abbr[abbrIndex] == '0') {
                return false;
            }
            int num = 0;

            while (abbrIndex < abbr.size() && isdigit(abbr[abbrIndex])) {
                num = num * 10 + (abbr[abbrIndex] - '0');
                ++abbrIndex;
            }
            // Skip the number of characters in word as found in abbreviation.
            wordIndex += num;
        } else {
            // Check if characters the match, then increment the pointers. Otherwise return False.
            if (wordIndex >= word.size() || word[wordIndex]!= abbr[abbrIndex]) {
                return false;
            }
            ++wordIndex;
            ++abbrIndex;
        }
    }

    // Check if both indices have reached the end of their respective strings.
    return wordIndex == word.size() && abbrIndex == abbr.size();
}

int main() {
    vector<string> words = {"a", "a", "abcdefghijklmnopqrst", "abcdefghijklmnopqrst", "word", "internationalization", "localization"};
    vector<string> abbreviations = {"a", "b", "a18t", "a19t", "w0rd", "i18n", "l12n"};

    for (size_t i = 0; i < words.size(); ++i) {
        cout << i + 1 << ".\t word: '" << words[i] << "'" << endl;
        cout << "\t abbr: '" << abbreviations[i] << "'\n";
        cout << "\n\t Is '" << abbreviations[i] << "' a valid abbreviation for the word '" << words[i] << "'? ";
        cout << (ValidWordAbbreviation(words[i], abbreviations[i])? "Yes\n" : "No\n");
        cout << "-" << string(100, '-') << "\n";
    }

    return 0;
}