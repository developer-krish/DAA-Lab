// Given a sorted array of positive integers, design an algorithm and implement it using a program
// to find three indices i, j, k such that arr[i] + arr[j] = arr[k].

#include<iostream>
#include <vector>
using namespace std;
void findIndex(vector <int> arr)
{
    for(int k = 2 ; k < arr.size() ; k++)
    {
        int  i = 0, j = k - 1;
        while(i < j)
        {
            if(arr[i] + arr[j] == arr[k])
            {
                cout << i + 1  << " " << j + 1 << " " << k + 1 << endl;
                return;
            }
            else if(arr[i] + arr[j] < arr[k])
                i++;
            else 
                j--;
        }
    }
    cout << "No sequence found" << endl;
}
int main()
{
    int t;
    cout << "Enter number of test cases : ";
    cin >> t;
    while(t--)
    {
        int n;
        cout << "Enter size of array for Test case " << t + 1 << " : ";
        cin >> n;
        vector <int> arr(n);
        for(int i = 0 ; i < n ; i++)
        {
            cin >> arr[i];
        }
        findIndex(arr);
    }
    return 0;
}
