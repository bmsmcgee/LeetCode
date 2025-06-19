#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

string ReverseWords(string sentence) {
    // Step 1: Trim leading and trailing spaces
    int left = 0, right = sentence.size() - 1;
    while (left <= right && sentence[left] == ' ') left++;
    while (right >= left && sentence[right] == ' ') right--;
    
    // Step 2: Extract words into a vector
    vector<string> words;
    stringstream ss(sentence.substr(left, right - left + 1));
    string word;
    while (ss >> word) {
        words.push_back(word);
    }

    // Step 3: Reverse the words vector in-place
    int i = 0, j = words.size() - 1;
    while (i < j) {
        swap(words[i], words[j]);
        i++;
        j--;
    }

    // Step 4: Join words into a single string with spaces
    string result;
    for (int k = 0; k < words.size(); ++k) {
        if (k > 0) result += " ";
        result += words[k];
    }

    return result;
}


int main()
{
    vector<string> 
		stringToReverse = {"Hello World",
							"a   string   with   multiple   spaces",
							"Case Sensitive Test 1234",
							"a 1 b 2 c 3 d 4 e 5",
							"     trailing spaces",
							"case test interesting an is this"};

    for (int i = 0; i < stringToReverse.size(); i++)
    {
        cout << i + 1 << ".\tOriginal string: '" << stringToReverse[i] << "'" << endl;
        cout << "\tReversed string: '" << ReverseWords(stringToReverse[i]) << "'" << endl;
        cout << string(100, '-') << endl;
    }
}