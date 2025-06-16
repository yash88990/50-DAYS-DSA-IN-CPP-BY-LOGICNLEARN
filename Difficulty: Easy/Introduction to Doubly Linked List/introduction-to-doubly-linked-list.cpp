// User function Template for C++

/*
class Node{
public:
    Node* prev;
    int data;
    Node* next;

    Node()
    {
        prev = NULL;
        data = 0;
        next = NULL;
    }

    Node(int value)
    {
        prev = NULL;
        data = value;
        next = NULL;
    }
};*/

class Solution {
  public:

    Node* constructDLL(vector<int>& arr) {
        if (arr.empty()) return nullptr;

        // Create the head node
        Node* head = new Node(arr[0]);
        Node* prev = head;

        // Build the rest of the DLL
        for (int i = 1; i < arr.size(); ++i) {
            Node* curr = new Node(arr[i]);
            prev->next = curr;
            curr->prev = prev;
            prev = curr;
        }

        return head;
    }
};
