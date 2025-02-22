// Given an unsorted array of integers, design an algorithm and a program to sort the array using
// insertion sort. Your program should be able to find number of comparisons and shifts ( shifts -
// total number of times the array elements are shifted from their place) required for sorting the
// array.
#include<iostream>
#include <vector>
using namespace std;
void insertionSort(vector <int> arr)
{
    int shifts = 0;
    int comparisons = 0;
    int temp;
    for(int i = 1 ; i < arr.size() ; i++)
    {
        temp = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > temp)
        {
            arr[j+1] = arr[j];
            shifts++;
            comparisons++;
            j--;
        }
        arr[j+1] = temp;
        shifts++;
    }
    for(int i = 0 ; i < arr.size() ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Number of comparisons: " << comparisons << endl;
    cout << "Number of shifts: " << shifts << endl;
}
int main()
{
    int t;
    cout << "Enter number of test cases : ";
    cin >> t;
    while(t--)
    {
        int n;
        cout << "Enter size of the array : ";
        cin >> n;
        vector <int> arr(n);
        cout << "Enter elements of the array : ";
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        insertionSort(arr);
    }
    return 0;
}
