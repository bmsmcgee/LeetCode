#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Helper function that calculates the sum of squared digits
int SumOfSquaredDigits(int number) {
  int totalSum = 0;

  while (number > 0) {
    int digit = number % 10;
    number = floor(number / 10);
    totalSum += (digit * digit);
  }

  return totalSum;
}

bool IsHappyNumber(int n) {
  int slowPointer = n;
  int fastPointer = SumOfSquaredDigits(n);

  while (fastPointer != 1 && slowPointer != fastPointer) {
    slowPointer = SumOfSquaredDigits(slowPointer);
    fastPointer = SumOfSquaredDigits(SumOfSquaredDigits(fastPointer));
  }

  fastPointer == 1 ? return true : return false;
}

// Driver code
int main()
{
    vector<int> inputs = {1, 5, 19, 25, 7};
    for (int i = 0; i < inputs.size(); i++)
    {
        cout << i + 1 << ".\tInput Number: " << inputs[i] << "\n";
        bool result = IsHappyNumber(inputs[i]);
        cout << "\n\tIs it a happy number? ";
        if (result)
            cout << "True\n";
        else
            cout << "False\n";
        cout << string(100, '-') << "\n";
    }
}
