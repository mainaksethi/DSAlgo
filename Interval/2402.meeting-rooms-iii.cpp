/*
 * @lc app=leetcode id=2402 lang=cpp
 *
 * Description: 
 * 1. Using heap among intervals. 
 */

// @lc code=start
class Solution {
public:

    struct Node {
        int room;
        int finishDuration;
        Node(int room, int finishDuration): room(room), finishDuration(finishDuration) {};
    };

    struct comp {
        bool operator()(Node &node1, Node &node2) {
            if(node1.finishDuration == node2.finishDuration) {
                return node1.room > node2.room;
            }
            return node1.finishDuration > node2.finishDuration;
        }
    };

    struct comp2 {
        bool operator()(vector<int> &v1, vector<int> &v2) {
            return v1[0] < v2[0];
        }
    };

    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<Node, vector<Node>, comp> pq;
        set<int> freeRooms;
        sort(meetings.begin(), meetings.end(), comp2());
        vector<int> meetingCount(n, 0);
        for (int i =0; i < n; i++) {
            freeRooms.insert(i);
        }
        for (int i = 0; i < meetings.size(); i++) {
            // cout<<"meeting="<<meetings[i][0]<<","<<meetings[i][1];
            int start_time = meetings[i][0];
            // empty priority_queue
            while(!pq.empty() && pq.top().finishDuration <= start_time) {
                Node n = pq.top();
                pq.pop();
                freeRooms.insert(n.room);
            }
            int newMeetingRoom = -1;
            if (freeRooms.size() != 0) {
                auto it = freeRooms.begin();
                newMeetingRoom = *it;
                pq.push(Node(newMeetingRoom, meetings[i][1]));
                freeRooms.erase(it);
                // cout<<"Meeting room from free rooms = "<<newMeetingRoom<<endl;
            } else {
                Node bestAvailableRoom = pq.top();
                pq.pop();
                newMeetingRoom = bestAvailableRoom.room;
                int newFinishDuration = bestAvailableRoom.finishDuration + (meetings[i][1]-meetings[i][0]);
                pq.push(Node(newMeetingRoom, newFinishDuration));
                // cout<<"Meeting room from non-empty rooms = "<<newMeetingRoom<<endl;
            }
            meetingCount[newMeetingRoom]++;
        }
        int maxVal = INT_MIN;
        int ans = -1;
        for (int i = 0; i < meetingCount.size(); i++) {
            if (maxVal < meetingCount[i]) {
                maxVal = meetingCount[i];
                ans = i;
            }
        }
        return ans;
    }
};// @lc code=end

