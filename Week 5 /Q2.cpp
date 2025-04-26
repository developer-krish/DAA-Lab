#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findPairWithSum(vector<int>& arr, int key) {
    int n = arr.size();
    sort(arr.begin(), arr.end());

    int left = 0, right = n - 1;
    bool found = false;
    while (left < right) {
        int sum = arr[left] + arr[right];

        if (sum == key) {
            cout << arr[left] << " " << arr[right] << endl;
            found = true;
            return;  
        }
        if (sum < key) {
            left++;  
        } else {
            right--;  
        }
    }

    if (!found) {
        cout << "No Such Elements Exist" << endl;
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, key;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        cin >> key;
        findPairWithSum(arr, key);
    }

    return 0;
}
