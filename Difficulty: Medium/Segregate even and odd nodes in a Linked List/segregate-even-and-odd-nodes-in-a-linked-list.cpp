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
        // code here
        if(!head)return head;
        Node* evenStart = NULL , *evenEnd = NULL, *oddStart = NULL , *oddEnd = NULL;
        Node* curr = head;
        while(curr){
            //check for val 
            int val = curr->data;
            //check for even or odd
            //even value
            if(val % 2 == 0){
                //check for firsst node
                if(!evenStart){
                    evenStart = curr;
                    evenEnd = evenStart;
                }else{
                    //means we have some node
                    evenEnd->next = curr;
                    evenEnd = evenEnd->next;
                }
                
            }else{//odd vaue
                if(!oddStart){
                    oddStart = curr;
                    oddEnd = oddStart;
                }else{
                    oddEnd->next = curr;
                    oddEnd = oddEnd->next;
                }
            }
            curr = curr->next;
        }
        //if we dont have evenstart menas in linke dlist we dont have even value
        if(!evenStart)return oddStart;
        //connect them
        evenEnd ->next = oddStart;
        //terminate the list
        oddEnd->next = NULL;
        //return teh final answer after connecting 
        return evenStart;
        
        
    }
};













