// Given an array of nonnegative integers, design an algorithm and a program to count the number
// of pairs of integers such that their difference is equal to a given key, K.
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int countPairsWithDifference(vector<int>& arr, int target) {
    int cnt = 0;
    unordered_map<int, int> freq;  // Stores the frequency of each number
    
    for (int num : arr) {
        // Check if (num - target) exists in map
        if (freq.find(num - target) != freq.end()) 
            cnt += freq[num - target];

        // Check if (num + target) exists in map
        if (freq.find(num + target) != freq.end()) 
            cnt += freq[num + target];

        // Store the frequency of the current number
        freq[num]++;
    }
    
    return cnt;
}

int main() {
    int t;
    cout << "Enter number of test cases: ";
    cin >> t;

    while (t--) {
        int n;
        cout << "Enter size of array: ";
        cin >> n;

        vector<int> arr(n);
        cout << "Enter elements of the array: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int target;
        cout << "Enter target difference: ";
        cin >> target;

        int ans = countPairsWithDifference(arr, target);
        cout << "Number of pairs with difference " << target << ": " << ans << endl;
    }

    return 0;
}

