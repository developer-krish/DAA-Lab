#include <iostream>
#include <vector>
using namespace std;

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
        vector <char> arr(n);
        cout << "Enter elements of the array : ";
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector <int> count(26, 0);
        for(int i = 0 ; i < n ; i++)
        {
            (count[arr[i] - 'a'])++;
        }
        int maxi = 0;
        int indx = 0;
        for(int i = 0 ; i < 26 ; i++)
        {
            if(maxi < count[i])
            {
                maxi = count[i];
                indx = i;
            }   
        }
        char element  = 'a' + indx;
        if(maxi == 1)
           cout << "No Duplicates Found";
        else
           cout << element << " - " << maxi;
    }
    return 0;
}
