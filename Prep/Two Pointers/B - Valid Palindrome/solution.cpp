#include <iostream>
#include <cctype>

using namespace std;

bool IsPalindrome(string s) {
    int left = 0, right = s.length() - 1;

    while (left < right) {
        while (left < right && !isalnum(s[left])) {
            left++;
        }
    
        while (left < right && !isalnum(s[right])) {
            right--;
        }

        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }
        
        left++;
        right--;
    }

    return true;
}

int main() {
    string testCases[] = {
        "A man, a plan, a canal: Panama",
        "race a car",
        "1A@2!3 23!2@a1",
        "No 'x' in Nixon",
        "12321"
    };

    for (string test : testCases) {
        cout << "\tString: " << test << "\n";
        bool result = IsPalindrome(test);
        cout << "\n\tResult: " << (result ? "True" : "False") << "\n";
        cout << string(100, '-') << "\n";
    }
}
