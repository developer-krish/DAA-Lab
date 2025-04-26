#include <iostream>
#include <vector>
using namespace std;

void merge(vector <int>& arr, int l, int mid, int h)
{
    int i = l, j = mid + 1, k = l;
    vector <int> solution(h-l+1);
    while (i <= mid && j <= h)
    {
        if (arr[i] < arr[j])
        {
            solution[k++] = arr[i++];
        }
        else
        {
            solution[k++] = arr[j++];
        }
    }
    while (i <= mid) // copying if elements are remaining
    {
        solution[k++] = arr[i++];
    }
    while (j <= h) // copying if elements are remaining
    {
        solution[k++] = arr[j++];
    }
    for (i = l; i <= h; i++) // copy elements to original array
    {
        arr[i] = solution[i];
    }
}
void Merge_sort(vector<int>&arr, int lb, int ub)
{
    int mid = 0;
    if (lb < ub)
    {
        mid = (lb + ub) / 2;
        Merge_sort(arr, lb, mid);
        Merge_sort(arr, mid + 1, ub);
        merge(arr, lb, mid, ub);
    }
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
        Merge_sort(arr, 0, n - 1);
        for(int i = 0 ; i < n ; i++)
        {
            cout << arr[i] << " ";
        }
    }
}
