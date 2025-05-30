#include<iostream>
using namespace std;

class Node{
    public:
    int data ;
    Node* next ;
    Node* prev;
    //constructor 
    Node(int d){
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }
    //destructor
    ~Node(){
        int val = this->data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"memory free for "<<val<<endl;
        
    }
};

void insertAtHead(Node* &head , int d){
    //create a node to insert
    Node* temp = new Node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}


void insertAtTail(Node* &tail , int d){
    Node* temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail= temp;
}

void insertAtAnyPosition(Node* &head , Node* &tail , int pos , int d ){
    //pos == 1 
    if(pos ==  1){
        insertAtHead(head , d);
        return;
    }
    Node* curr = head;
    int count = 1 ;
    while(count < pos - 1 ){
        curr = curr->next;
        count++;
    }
    //last position 
    if(curr->next == NULL){
        insertAtTail(tail , d);
        return ;
    }
    //create node to insert
    Node* temp = new Node(d);
    temp ->next = curr->next;
    curr->next->prev = temp;
    temp->prev = curr;
    curr->next = temp;
}

void deleteNode(Node* &head , int pos){
    if(pos ==  1){
        Node* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }else{
        Node* curr = head ;
        Node* prev = NULL;
        int count = 1 ;
        while(count < pos){
            prev = curr;
            curr = curr->next;
            count++;
        }
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
    

void print(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}




int getlength(Node* head){
    int len = 0;
    Node* temp = head;
    while(temp){
        len++;
        temp= temp->next;
    }
    return len;
}

int main(){
        Node* node1 = new Node(10);
        Node* head = node1;
        Node* tail = node1;
        print(head);
        int size = getlength(head);
        cout<<"size is : "<<size<<endl;
        insertAtHead(head , 50);
        print(head);
        size = getlength(head);
        cout<<"size is : "<<size<<endl;
        insertAtHead(head , 60);
        print(head);
        size = getlength(head);
        cout<<"size is : "<<size<<endl;
        insertAtTail(tail , 100);
        print(head);
        size = getlength(head);
        cout<<"size is : "<<size<<endl;
        insertAtAnyPosition(head , tail , 3 , 45);
        print(head);
        size = getlength(head);
        cout<<"size is : "<<size<<endl;
        deleteNode(head , 5);
        print(head);
        
        return 0;
}