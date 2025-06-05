//  implement a stack using array 
#include <iostream>
using namespace std;
class stack{
    public:
    int *arr;
    int size;
    int top;
    stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int ele){
         if(size - top > 1){
             top++;
              arr[top] = ele;
         }else
             cout<<"stack overflow"<<endl;
    }
    void peek(){
        if(top >= 0 && top < size){
            cout<< arr[top]<<endl;
        }
        else{
            cout<<"empty stack"<<endl;
            return ;
        }
    }
    void pop(){
        if(top >= 0)top--;
        else cout<<"stack underflow"<<endl;
    }
    bool empty(){
        if(top == -1)return true;
        else return false;
    }
};

int main() {
    stack s(5);
    s.push(10);
    s.peek();
    cout<<s.empty();
    return 0;
}







// 2. implemtn a stack using vector
#include<iostream>
#include<vector>
using namespace std;
class stack{
    vector<int>v;
    public:
    void push(int ele){
        v.push_back(ele);
        
    }
    void pop(){
        v.pop_back();
        
    }
    int peek(){
        return v[v.size() - 1];
        
    }
    bool empty(){
        return v.size() == 0;
     
    }
    
};


int main(){
    stack s;
    s.push(23);
    s.push(45);
    s.push(456);
    s.push(452);
    // s.pop();
    // cout<<s.empty()<<endl;
    // cout<<s.peek()<<endl;
    while(!s.empty()){
        cout<<s.peek()<<" ";
        s.pop();
    }
    
}




//3 implement a stack using linked list
#include<iostream>
using namespace std;
struct node{
    int data ;
    node* next;
    node(int d){
        this->data = d;
        this->next = NULL;
    }
    
};

class stack{
    private:
    node* top;
    public:
    stack(){
        top = NULL;
    }
    
    void push(int val){
        node* newNode = new node(val);
        newNode->next = top;
        top = newNode;
        cout<<val<<"  pushed to stack"<<endl;
    }
    
    bool isempty(){
        return top == NULL;
    }
    
    void pop(){
        if(isempty()){
            cout<<"stack underflow "<<endl;
            return;
        }
        node* temp = top;
        top = top->next;
        cout<<temp->data<<" popped from stack "<<endl;
        delete temp;
    }
    int peek(){
        if(isempty()){
            cout<<"empty stack"<<endl;
            return -1;
        }
        return top->data;
    }
    
};
int main(){
    stack s;
    s.push(10);
    s.push(46);
    s.pop();
    cout<< s.peek();
}












// gfg    https://www.geeksforgeeks.org/problems/implement-stack-using-array/1

/*
class MyStack
{
private:
    int arr[1000];
    int top;
public:
    MyStack(){top=-1;}
    int pop();
    void push(int);
};
*/

void MyStack ::push(int x) {
    // Your Code
    if(top == 999)return;
    arr[++top] = x;
}

// Function to remove an item from top of the stack.
int MyStack ::pop() {
    // Your Code
    if(top == -1)return -1;
    return arr[top--];
}
