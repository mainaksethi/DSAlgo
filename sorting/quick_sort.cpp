#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
using namespace std;

/**
 * Implementation of merge-sort.
 * Inplace: True
 * Time: O(nlogn)
 * Time: WorseCase O(N^2)
*/

void quickSort(vector<int> &v, int start, int end) {
    if (start >= end) {
        return;
    }
    int firstElementGreaterThanPivot = start;
    for (int i = start; i < end; i++) {
        if (v[i] <= v[end]) {
            int c = v[i];
            v[i] = v[firstElementGreaterThanPivot];
            v[firstElementGreaterThanPivot] = c;
            firstElementGreaterThanPivot++;
        }
    }
    int c = v[end];
    v[end] = v[firstElementGreaterThanPivot];
    v[firstElementGreaterThanPivot] = c;
    quickSort(v, start, firstElementGreaterThanPivot-1);
    quickSort(v, firstElementGreaterThanPivot+1, end);
    return;
}

void print(vector<int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout<<ans[i]<<", ";
    }
    cout<<endl;
}

int main() {
    vector<int> v = {5, 4, 1, 2, 3};
    quickSort(v, 0, v.size()-1);
    print(v);
    return 0;
}