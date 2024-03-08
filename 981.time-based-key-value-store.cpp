/*
 * @lc app=leetcode id=981 lang=cpp
 *
 * [981] Time Based Key-Value Store
 * Learnings: 
 * 1. map has concept of lower_bound/upper_bound.
 * lower_bound => value greater than or equal to current value.
 * upper_bound => value greater than current value.
 * 2. Since in this problem we need to find values less than or 
 * equal to. We leverage iterator power.
 * it = map.lower_bound(timestamp);
 * return if it is equal else
 * it--
 * Since it-- won't work on map.begin(). Additionally check the 
 * key condition.
 * if (it->first < timestamp) {
 *  return it->second;
 * } else {
 *  return "";
 * }
 * 
 * 3. Syntactical Sugar => 
 * map[key][timestamp] = value;
 * 
 */

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */


// @lc code=start
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
class TimeMap {
public:
    map<string, map<int, string>> mp;
    TimeMap() { 
    }
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp]=value;
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key)!=mp.end()){
            auto it=mp[key].lower_bound(timestamp);
        
        if(it->first==timestamp){
            return it->second;
        }  

        it--;
        if(it->first < timestamp){
            return it->second;
        }
        }
        return "";      
    }
};
// @lc code=end

