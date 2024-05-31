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
 * Inplace: False
 * Time: O(nlogn)
*/

vector<int> mergeSort(vector<int> &v, int start, int end) {
    if (start == end) {
        vector<int> ans;
        ans.push_back(v[start]);
        return ans;
    }
    int mid = start + (end - start)/2;
    vector<int> left = mergeSort(v, start, mid);
    vector<int> right = mergeSort(v, mid+1, end);
    int ptr1 = 0;
    int ptr2 = 0;
    vector<int> ans;
    while(ptr1 < left.size() && ptr2 < right.size()) {
        if (left[ptr1] < right[ptr2]) {
            ans.push_back(left[ptr1]);
            ptr1++;
        } else {
            ans.push_back(right[ptr2]);
            ptr2++;
        }
    }
    if (ptr1 < left.size()) {
        while(ptr1<left.size()) {
            ans.push_back(left[ptr1]);
            ptr1++;
        }
    }
    if (ptr2 < right.size()) {
        while(ptr2 < right.size()) {
            ans.push_back(right[ptr2]);
            ptr2++;
        }
    }
    return ans;
}

void print(vector<int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout<<ans[i]<<", ";
    }
    cout<<endl;
}

int main() {
    vector<int> v = {5, 4, 3, 2 ,1};
    vector<int> ans = mergeSort(v, 0, v.size()-1);
    print(ans);
    return 0;
}