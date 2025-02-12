#include <iostream>
#include <vector>
#include <algorithm> // For max function

using namespace std;

// Function to determine the minimum starting health needed to complete all rounds
int minStartingHealth(vector<int>& power, int armor) {
    int totalDamage = 0;
    int maxDamage = 0;

    // Compute total damage and find the max damage in any single round
    for (int dmg : power) {
        totalDamage += dmg;
        maxDamage = max(maxDamage, dmg);
    }

    // Compute the minimum required health
    int minHealth = totalDamage - min(armor, maxDamage) + 1;
    
    return minHealth;
}

// Main function for testing
int main() {
    vector<int> power1 = {2, 7, 4, 3}; 
    int armor1 = 5; 
    cout << minStartingHealth(power1, armor1) << endl; // Expected Output: 11

    vector<int> power2 = {10, 5, 3, 2}; 
    int armor2 = 6; 
    cout << minStartingHealth(power2, armor2) << endl; // Expected Output: 14

    vector<int> power3 = {1, 2, 3, 4, 5}; 
    int armor3 = 3; 
    cout << minStartingHealth(power3, armor3) << endl; // Expected Output: 12

    return 0;
}