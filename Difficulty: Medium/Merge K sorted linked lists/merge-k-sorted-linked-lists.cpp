/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
 
// Custom comparator for min-heap
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->data > b->data; // Min-heap based on data value
    }
};

Node* mergeKLists(vector<Node*>& arr) {
    priority_queue<Node*, vector<Node*>, Compare> minHeap;

    // Step 1: Push heads of all linked lists into the min-heap
    for (Node* list : arr) {
        if (list) minHeap.push(list);
    }

    Node* dummy = new Node(0); // Dummy node for result linked list
    Node* tail = dummy;

    // Step 2: Extract min and process
    while (!minHeap.empty()) {
        Node* smallest = minHeap.top();
        minHeap.pop();

        tail->next = smallest;
        tail = tail->next;

        if (smallest->next) {
            minHeap.push(smallest->next); // Push next node from the extracted list
        }
    }

    return dummy->next; // Head of the merged sorted linked list
}


};

