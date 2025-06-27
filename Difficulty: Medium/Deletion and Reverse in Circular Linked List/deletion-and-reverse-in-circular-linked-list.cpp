class Solution {
  public:
    // Function to reverse a circular linked list
    Node* reverse(Node* head) {
        // code here
        if(!head || !head->next)return head;
        Node* prev = NULL;
        Node* curr = head;
        Node* next;
        do{
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }while(curr != head);
        
        head->next = prev;
        head = prev;
        return head;
    }

    // Function to delete a node from the circular linked list
    Node* deleteNode(Node* head, int key) {
        
        // code here
        if(!head)return NULL;
        //delete the head node
        if(head ->data == key){
            //if only one node
            if(head->next == head){
                delete head;
                return NULL;
            }
            // more than one node 
            Node* last = head;
            while(last->next != head)last = last->next;
            last->next = head->next;
            Node* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        //now delete the any other node
        Node* prev = NULL;
        Node* curr = head;
        while(curr->next != head){
            if(curr->data == key){
                prev->next = curr->next;
                delete curr;
                return head;
            }
            prev = curr;
            curr = curr->next;
        }
        return head;
        
    }
};









