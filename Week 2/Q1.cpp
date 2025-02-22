// Given a sorted array of positive integers containing few duplicate elements, design an algorithm
// and implement it using a program to find whether the given key element is present in the array or
// not. If present, then also find the number of copies of given key. (Time Complexity = O(log n))

#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int> &arr, int key, bool findFirst)
{
    int left = 0, right = arr.size() - 1, result = -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
        {
            result = mid;
            if (findFirst)
                right = mid - 1; // Search in the left half
            else
                left = mid + 1; // Search in the right half
        }
        else if (arr[mid] < key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return result;
}
int countOccurrences(const vector<int> &arr, int key)
{
    int firstIndex = binarySearch(arr, key, true);
    if (firstIndex == -1)
        return 0; // Key not found
    int lastIndex = binarySearch(arr, key, false);
    return lastIndex - firstIndex + 1;
}
int main()
{
    int T;
    cin >> T; // Number of test cases
    while (T--)
    {
        int n;
        cin >> n; // Size of array
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int key;
        cin >> key; // Key to be searched
        int count = countOccurrences(arr, key);
        if (count > 0)
            cout << "Present " << count << endl;
        else
            cout << "Not Present" << endl;
    }
    return 0;
}
