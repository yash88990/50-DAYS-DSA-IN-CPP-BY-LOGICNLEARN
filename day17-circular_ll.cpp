// Online C++ compiler to run C++ program online
#include <iostream>
#include<map>
using namespace std;
class Node{
    public:
    int data ;
    Node* next;
    
    //constructor
    Node(int d){
        this->data = d;
        this->next = NULL;
    }
    
};

bool isCircular(Node* &tail ){
    if(tail == NULL)return true;
    Node* temp = tail->next;
    while(temp != tail && temp != NULL){
        temp = temp->next;
    }
    if(temp = tail)return true;
    return false;
}

bool detectloop(Node* &tail ){
    if(tail == NULL)return false;
    map<Node* , bool> visited;
    Node* temp = tail;
    while(temp != NULL){
        //cycle is pressent 
        if(visited[temp] == true)return true;
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
    
}
void insertNode(Node* &tail , int d , int element){
    if(tail == NULL){
        Node* newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else{
        Node* curr = tail;
        while(curr->data != element){
            curr = curr->next;
        }
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void deleteNode(Node* &tail , int value){
    Node* prev = tail;
    Node* curr = prev->next;
    while(curr->data != value){
        prev = curr;
        curr= curr->next;
    }
    prev->next = curr->next;
    //jab node 1 hi ho 
    if(curr == prev)tail = NULL;
    if(tail == curr )tail = prev;
    curr->next  =  NULL;
    delete curr;
}

void print(Node* tail){
    Node* temp = tail;
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    while(temp != tail);
    cout<<endl;
}


int main() {
    
    Node* node1 = new Node(20);
    Node* tail = node1;
    node1->next = node1;
    print(tail);
    
    insertNode(tail , 40 , 20);
    print(tail);
    insertNode(tail , 60 , 20);
    
    
    print(tail);
    insertNode(tail , 100 , 60);
    print(tail);
    
    // deleteNode(tail , 60);
    // print(tail);
    
    if(isCircular)cout<<"cycle is present "<<endl;
    else cout<<"not a cycle found"<<endl;
    
    if(detectloop)cout<<"cycle is present "<<endl;
    else cout<<"not a cycle found"<<endl;
    
    
    
    
    return 0;
}





class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || !head->next )return false;
        ListNode *slow = head , *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast)return true;
        }
        return false;
    }
};



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head ||  !head->next)return NULL;
        ListNode *slow = head , *fast = head;
        //dect cycle or not 
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                //cycle present hai 
                slow = head;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};


/*************************************************
    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

*************************************************/

Node *removeLoop(Node *head)
{
    // Write your code here.
    if(!head || !head->next)return head;
    Node * slow = head , *fast = head;
    bool iscycle = false;

    while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
            iscycle =  true;
            break;
            }
    }

    //check start node
    if (iscycle){
        slow = head ;
        // Node* prev = NULL;
        while(slow != fast){
            // prev = fast;
            slow = slow->next;
            fast = fast->next;

        }
        while(fast->next != slow){
            fast = fast->next;
        }
        fast->next = NULL;
    }
    return head;
}