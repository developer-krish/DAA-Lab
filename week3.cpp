// Given an unsorted array of integers, design an algorithm and a program to sort the array using
// insertion sort. Your program should be able to find number of comparisons and shifts ( shifts -
// total number of times the array elements are shifted from their place) required for sorting the
// array.

// #include<iostream>
// #include <vector>
// using namespace std;
// void insertionSort(vector <int> arr)
// {
//     int shifts = 0;
//     int comparisons = 0;
//     int temp;
//     for(int i = 1 ; i < arr.size() ; i++)
//     {
//         temp = arr[i];
//         int j = i - 1;
//         while(j >= 0 && arr[j] > temp)
//         {
//             arr[j+1] = arr[j];
//             shifts++;
//             comparisons++;
//             j--;
//         }
//         arr[j+1] = temp;
//         shifts++;
//     }
//     for(int i = 0 ; i < arr.size() ; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
//     cout << "Number of comparisons: " << comparisons << endl;
//     cout << "Number of shifts: " << shifts << endl;
// }
// int main()
// {
//     int t;
//     cout << "Enter number of test cases : ";
//     cin >> t;
//     while(t--)
//     {
//         int n;
//         cout << "Enter size of the array : ";
//         cin >> n;
//         vector <int> arr(n);
//         cout << "Enter elements of the array : ";
//         for(int i = 0; i < n; i++)
//         {
//             cin >> arr[i];
//         }
//         insertionSort(arr);
//     }
//     return 0;
// }


// ----------------------------------------------------------------------------------------------------------------------------------------
// Given an unsorted array of integers, design an algorithm and implement a program to sort this
// array using selection sort. Your program should also find number of comparisons and number of
// swaps required.

// #include<iostream>
// #include <vector>
// using namespace std;
// void selectionSort(vector <int> arr)
// {
//     int min;
//     int swapC = 0;
//     int comparisons = 0;
//     for(int i = 0 ; i < arr.size() - 1 ; i++)
//     {
//         min = i;
//         for(int j = i+1 ; j < arr.size() ; j++)
//         {
//             if(arr[j] < arr[min])
//                 min = j;
//              comparisons++;
            
//         }
//         swap(arr[i], arr[min]);
//         swapC++;
         
//     }
//     for(int i = 0 ; i < arr.size() ; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
//     cout << "Number of comparisons are : " << comparisons << endl;
//     cout << "Number of swaps are : " << swapC << endl;
// }
// int main()
// {
//     int t;
//     cout << "Enter number of test cases : ";
//     cin >> t;
//     while(t--)
//     {
//         int n;
//         cout << "Enter size of the array : ";
//         cin >> n;
//         vector <int> arr(n);
//         cout << "Enter elements of the array : ";
//         for(int i = 0; i < n; i++)
//         {
//             cin >> arr[i];
//         }
//         selectionSort(arr);
//     }
//     return 0;
// }


// ----------------------------------------------------------------------------------------------------------------------------------------

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
