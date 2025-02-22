// Given a sorted array of positive integers containing few duplicate elements, design an algorithm
// and implement it using a program to find whether the given key element is present in the array or
// not. If present, then also find the number of copies of given key. (Time Complexity = O(log n))


// #include <iostream>
// #include <vector>
// using namespace std;

// int binarySearch(const vector<int> &arr, int key, bool findFirst)
// {
//     int left = 0, right = arr.size() - 1, result = -1;
//     while (left <= right)
//     {
//         int mid = left + (right - left) / 2;
//         if (arr[mid] == key)
//         {
//             result = mid;
//             if (findFirst)
//                 right = mid - 1; // Search in the left half
//             else
//                 left = mid + 1; // Search in the right half
//         }
//         else if (arr[mid] < key)
//         {
//             left = mid + 1;
//         }
//         else
//         {
//             right = mid - 1;
//         }
//     }
//     return result;
// }
// int countOccurrences(const vector<int> &arr, int key)
// {
//     int firstIndex = binarySearch(arr, key, true);
//     if (firstIndex == -1)
//         return 0; // Key not found
//     int lastIndex = binarySearch(arr, key, false);
//     return lastIndex - firstIndex + 1;
// }
// int main()
// {
//     int T;
//     cin >> T; // Number of test cases
//     while (T--)
//     {
//         int n;
//         cin >> n; // Size of array
//         vector<int> arr(n);
//         for (int i = 0; i < n; i++)
//         {
//             cin >> arr[i];
//         }
//         int key;
//         cin >> key; // Key to be searched
//         int count = countOccurrences(arr, key);
//         if (count > 0)
//             cout << "Present " << count << endl;
//         else
//             cout << "Not Present" << endl;
//     }
//     return 0;
// }


// ----------------------------------------------------------------------------------------------------------------


// Given a sorted array of positive integers, design an algorithm and implement it using a program
// to find three indices i, j, k such that arr[i] + arr[j] = arr[k].

// #include<iostream>
// #include <vector>
// using namespace std;
// void findIndex(vector <int> arr)
// {
//     for(int k = 2 ; k < arr.size() ; k++)
//     {
//         int  i = 0, j = k - 1;
//         while(i < j)
//         {
//             if(arr[i] + arr[j] == arr[k])
//             {
//                 cout << i + 1  << " " << j + 1 << " " << k + 1 << endl;
//                 return;
//             }
//             else if(arr[i] + arr[j] < arr[k])
//                 i++;
//             else 
//                 j--;
//         }
//     }
//     cout << "No sequence found" << endl;
// }
// int main()
// {
//     int t;
//     cout << "Enter number of test cases : ";
//     cin >> t;
//     while(t--)
//     {
//         int n;
//         cout << "Enter size of array for Test case " << t + 1 << " : ";
//         cin >> n;
//         vector <int> arr(n);
//         for(int i = 0 ; i < n ; i++)
//         {
//             cin >> arr[i];
//         }
//         findIndex(arr);
//     }
//     return 0;
// }


// ----------------------------------------------------------------------------------------------------------------
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

