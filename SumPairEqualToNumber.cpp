#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    int n, M;
    cin >> n >> M;
    vector<int> arr(n);
    unordered_set<int> seen;
    int count = 0;

    // Reading array elements
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Finding pairs (i, j) such that ai + aj = M
    for (int i = 0; i < n; ++i) {
        int complement = M - arr[i];
        
        // Check if the complement exists in the set and has been processed before
        if (seen.count(complement)) {
            count++;
        }
        
        // Add the current element to the set
        seen.insert(arr[i]);
    }

    cout << count << endl;
    return 0;
}
