/**
 * A good data-structure to revise multiple concepts. 
 * 
 * 1. Insert map into vector. 
 * 2. use lower-bound in map.
 * 3. prev(it) as syntax for previous iterator.
 */

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

class SnapshotArray {
public:
    int snap_id;
    vector<map<int, int>> arr;
    SnapshotArray(int length) {
        for (int i = 0; i < length; i++) {
            map<int, int> snapMap;
            // insertion in map
            snapMap.insert({0, 0});
            arr.push_back(snapMap);
        }
        snap_id = 0;
    }
    
    void set(int index, int val) {
        if (arr[index].find(snap_id) != arr[index].end()) {
            arr[index].erase(snap_id);
        }
        arr[index].insert({snap_id, val});
    }
    
    int snap() {
        return snap_id++;
    }
    
    void print() {
        for (int i = 0; i < arr.size(); i++) {
            cout<<i<<""<<endl;
            for (auto it = arr[i].begin(); it != arr[i].end(); it++) {
                cout<<it->first<<"--"<<it->second<<endl;
            }
            cout<<endl;
        }
        return;
    }
    
    int get(int index, int snap_id) {
        // print();
        auto it = arr[index].upper_bound(snap_id);
        return prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
