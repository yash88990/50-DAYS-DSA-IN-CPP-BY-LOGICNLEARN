#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        //constructor
        Node(int data){
            this->data = data;
            this->next = NULL;
        }

        //destructor
        ~Node(){
            int value = this->data;
            //memory free
            if(this->next != NULL){
                delete next;
                this->next = NULL;
            }
            cout<<"memory free from node with data   "<<value<<endl;
        }
};

void insertAtHead(Node* &head , int d){
    //create a new node 
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail , int d){
    //create a new node
    Node* temp = new Node(d);
    tail->next = temp ;
    tail = temp;
}

void insertAtAnyPosition(Node* &head , Node* &tail , int pos , int d ){
     //insert at head(pos == 1)
    if(pos == 1){
        insertAtHead(head , d);
        return;
    }

    Node* temp = head;
    int count = 1 ;
    while(count < pos - 1 ){
        temp = temp->next;
        count++;
    }
    
    //insert at tail(pos == length + 1)
    if(temp->next == NULL){
        insertAtTail(tail , d);
        return;
    }

    //insert at any position
    //create a new node to insert
    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}


void deleteNode(Node* &head , int pos){
    if(pos == 1){
        Node* temp = head;
        head = head->next;
        //memory free
        temp->next = NULL;
        delete temp;
    }else{
        //pos kuchh v ho skta h 1 ko chhodkr
        Node* curr = head;
        int count = 1;
        while(count < pos - 1 ){
            curr = curr->next;
            count++;
        }
        Node* temp = curr->next;
        curr->next = curr->next->next;
        temp->next = NULL;
        delete temp;

    }
}

void print(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main(){
    Node* node1 = new Node(10);
    //head pointed to node1
    Node* head = node1; 
    Node* tail = node1;
    print(head);
    insertAtHead(head, 20);
    print(head);
    insertAtHead(head, 70);
    print(head);
    insertAtTail(tail , 80);
    print(head);
    insertAtTail(tail , 90);
    print(head);

    insertAtAnyPosition(head , tail , 6 , 200);
    print(head);
    insertAtAnyPosition(head , tail , 1, 4);
    print(head);
    insertAtAnyPosition(head , tail , 1, 4546);
    print(head);

    deleteNode(head ,1);
    print(head);

    deleteNode(head , 2);
    print(head);

    deleteNode(head , 3);
    print(head);

    deleteNode(head , 6);
    print(head);

    
    return 0;

}
