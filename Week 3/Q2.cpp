// Given an unsorted array of integers, design an algorithm and implement a program to sort this
// array using selection sort. Your program should also find number of comparisons and number of
// swaps required.

#include<iostream>
#include <vector>
using namespace std;
void selectionSort(vector <int> arr)
{
    int min;
    int swapC = 0;
    int comparisons = 0;
    for(int i = 0 ; i < arr.size() - 1 ; i++)
    {
        min = i;
        for(int j = i+1 ; j < arr.size() ; j++)
        {
            if(arr[j] < arr[min])
                min = j;
             comparisons++;
            
        }
        swap(arr[i], arr[min]);
        swapC++;
         
    }
    for(int i = 0 ; i < arr.size() ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Number of comparisons are : " << comparisons << endl;
    cout << "Number of swaps are : " << swapC << endl;
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
        selectionSort(arr);
    }
    return 0;
}


