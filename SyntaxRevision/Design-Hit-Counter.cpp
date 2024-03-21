/**
 * Premium Problem: Databricks
 * Design a hit counter which counts the number of hits received in the past 5 minutes (i.e., the past 300 seconds).

Your system should accept a timestamp parameter (in seconds granularity), and you may assume that calls are being made to the system in chronological order (i.e., timestamp is monotonically increasing). Several hits may arrive roughly at the same time.

Implement the HitCounter class:

HitCounter() Initializes the object of the hit counter system.
void hit(int timestamp) Records a hit that happened at timestamp (in seconds). Several hits may happen at the same timestamp.
int getHits(int timestamp) Returns the number of hits in the past 5 minutes from timestamp (i.e., the past 300 seconds).
 

Example 1:

Input
["HitCounter", "hit", "hit", "hit", "getHits", "hit", "getHits", "getHits"]
[[], [1], [2], [3], [4], [300], [300], [301]]
Output
[null, null, null, null, 3, null, 4, 3]

*/

/**
 * Learning: 
 * For custom data-structure in map requires default constructor.
 * Define default constructor of Node.
*/

class HitCounter {
struct Node {
    int start;
    int end;
    Node() : start(0), end(0) {};
    Node(int start, int end): start(start), end(end) {};
};

public:

    map<int, Node> mp;
    int count = 0;

    HitCounter() {
        
    }
    
    void hit(int timestamp) {
        count++;
        if (mp.find(timestamp) == mp.end()) {
            mp.insert({timestamp, Node(count, count)});
        } else {
            Node n = mp[timestamp];
            mp.erase(timestamp);
            mp.insert({timestamp, Node(n.start, count)});
        }
    }
    
    int getHits(int timestamp) {
        if (mp.size() == 0) {
            return 0;
        }
        int upper = timestamp;
        int lower = timestamp - 300+1;
        auto upperIt = mp.upper_bound(upper);
        upperIt--;
        auto lowerIt = mp.lower_bound(lower);
        if (lowerIt == mp.end()) {
            return 0;
        }
        return (upperIt->second).end - (lowerIt->second).start + 1;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */