// User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node* divide(Node* head) {
        if (!head) return nullptr;

        Node* evenStart = nullptr;
        Node* evenEnd = nullptr;
        Node* oddStart = nullptr;
        Node* oddEnd = nullptr;

        Node* curr = head;

        while (curr) {
            int val = curr->data;

            if (val % 2 == 0) { // even node
                if (!evenStart) {
                    evenStart = curr;
                    evenEnd = evenStart;
                } else {
                    evenEnd->next = curr;
                    evenEnd = evenEnd->next;
                }
            } else { // odd node
                if (!oddStart) {
                    oddStart = curr;
                    oddEnd = oddStart;
                } else {
                    oddEnd->next = curr;
                    oddEnd = oddEnd->next;
                }
            }
            curr = curr->next;
        }

        // If no even nodes, return odd list as is
        if (!evenStart) return oddStart;

        // Connect even list to odd list
        evenEnd->next = oddStart;

        // End the list
        if (oddEnd) oddEnd->next = nullptr;

        return evenStart;
    }
};
