// Given an unsorted array of positive integers, design an algorithm and implement it using a
// program to find whether there are any duplicate elements in the array or not. (use sorting) (Time
// Complexity = O(n log n))

#include<iostream>
#include <vector>
using namespace std;

void quickSort(vector <int>& arr, int lb, int ub)
{
    int i = lb, j = ub;
    int pivot  = arr[lb];
    if(ub <= lb)
       return;
    while(i < j)
    {
        while(arr[i] <= pivot && i < j)
        {
            i++;
        }
        while(arr[j] > pivot)
        {
            j--;
        }
        if(i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    arr[lb] = arr[j];
    arr[j] = pivot;
    quickSort(arr, lb, j - 1);
    quickSort(arr, j + 1, ub);
}
int main()
{
    int t, flag;
    cout << "Enter number of test cases : ";
    cin >> t;
    while(t--)
    {
        flag = 0;
        int n;
        cout << "Enter size of the array : ";
        cin >> n;
        vector <int> arr(n);
        cout << "Enter elements of the array : ";
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        quickSort(arr, 0, n-1);
        for(int i = 0 ; i < arr.size() - 1 ; i++)
        {
            if(arr[i] == arr[i + 1])
            {
                flag = 1;
                break;
            }
        }
        if(flag == 1)
           cout << "Duplicate Present";
        else
           cout << "No Duplicate Present";
    }
    return 0;
}
