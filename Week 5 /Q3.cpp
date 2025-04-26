#include <iostream>
#include <vector>
using namespace std;

void findCommonElements(vector<int>& arr1, vector<int>& arr2) {
    int m = arr1.size();
    int n = arr2.size();

    int i = 0, j = 0;
    vector<int> common;

    // Two-pointer technique to find common elements
    while (i < m && j < n) {
        if (arr1[i] == arr2[j]) {
            // Add to the result only if it's the first occurrence or unique element
            if (common.empty() || common.back() != arr1[i]) {
                common.push_back(arr1[i]);
            }
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j]) {
            i++;
        }
        else {
            j++;
        }
    }

    // Display the result
    if (common.empty()) {
        cout << "No Common Elements" << endl;
    } else {
        for (int num : common) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    int m, n;
    cin >> m;
    vector<int> arr1(m);
    for (int i = 0; i < m; ++i) {
        cin >> arr1[i];
    }

    cin >> n;
    vector<int> arr2(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr2[i];
    }

    findCommonElements(arr1, arr2);

    return 0;
}
