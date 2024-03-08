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
struct Node {
    int val;
    Node* next;
    Node(): val(-1), next(NULL) {};
    Node(int val): val(val), next(NULL) {};
    Node(int val, Node* next): val(val), next(next) {};
};

class LinkedList { 
    public: 
    Node* head = new Node();

    void insertInHead(int val) {
        Node* node = new Node(val);
        Node* next_node = head->next;
        head->next = node;
        node->next = next_node;
        return;
    }

    void print() {
        Node* start = head->next;
        while(start != NULL) {
            cout<<start->val<<",";
            start = start->next;
        }
        cout<<endl;
    }
};

int main() { 
    LinkedList list;
    list.insertInHead(1);
    list.insertInHead(2);
    list.insertInHead(3);
    list.print();
    return 0;
}