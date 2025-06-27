/* structure for a node
struct Node
{
    int data;
    struct Node *next;
}; */

/* Function to print nodes in a given Circular linked list */
void printList(struct Node *head) {
    // code here
    if(!head)return;
    Node* start = head;
    do{
        cout<<head->data<<" ";
        head = head->next;
    }while(head != start);
}