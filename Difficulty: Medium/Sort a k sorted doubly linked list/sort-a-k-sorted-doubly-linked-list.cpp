// User function Template for C++

/*
// a node of the doubly linked list
class DLLNode
{
public:
    int data;
    DLLNode *next;
    DLLNode *prev;
    DLLNode(int val)
    {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    struct compare {
        bool operator()(DLLNode* a, DLLNode* b) {
            return a->data > b->data;  // Min-heap based on node data
        }
    };

    DLLNode *sortAKSortedDLL(DLLNode *head, int k) {
        if (!head || !head->next) return head;

        // Min-heap (priority queue)
        priority_queue<DLLNode*, vector<DLLNode*>, compare> pq;

        DLLNode* newHead = nullptr;
        DLLNode* last = nullptr;

        // Push first k+1 elements into the heap
        for (int i = 0; head && i <= k; ++i) {
            pq.push(head);
            head = head->next;
        }

        // Process heap and remaining list
        while (!pq.empty()) {
            DLLNode* smallest = pq.top();
            pq.pop();

            // First node becomes new head
            if (!newHead) {
                newHead = smallest;
                newHead->prev = nullptr;
                last = newHead;
            } else {
                last->next = smallest;
                smallest->prev = last;
                last = smallest;
            }

            // Push next node from list if available
            if (head) {
                pq.push(head);
                head = head->next;
            }
        }

        last->next = nullptr; // End the DLL
        return newHead;
    }
};
