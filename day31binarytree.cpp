// Online C++ compiler to run C++ program online
#include <iostream>
#include<queue>
#include<stack>
using namespace std;
class Node{
    public:
    int data ;
    Node* left , *right;
    Node(int d ){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};




Node* buildTree(Node* root){
    cout<<"enter the data here :"<<endl;
    int data;
    cin>>data;
    root = new Node(data);
    if(data == -1 )return NULL;
    cout<<"enter the data for inserting in left of :"<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"enter the data for inserting in right of "<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}



void levelOrderTraversal(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* front = q.front();
        q.pop();
        if(front == NULL){
              cout<<endl;
              if(!q.empty()) q.push(NULL);
        }else{
             cout<<front->data <<" ";
            if(front->left)q.push(front->left);
            if(front->right)q.push(front->right);
        }
    }
}

void reverseLevelOrderTraversal(Node* root){
    queue<Node*>q;
    stack<Node*> s;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* front = q.front();
        q.pop();
        if(front == NULL){
            s.push(NULL);
              if(!q.empty()) q.push(NULL);
        }else{
             s.push(front);
            if(front->left)q.push(front->left);
            if(front->right)q.push(front->right);
        }
    }
    while(!s.empty()){
        Node* front = s.top();
        s.pop();
        if(front == NULL)cout<<endl;
        else cout<<front->data<<" ";
    }
}


void preorderTraversal(Node* root){
    //preorder:-> N L R
    //base caase 
    if(!root)return;
    //first node le lo
    cout<<root->data<<" ";
    //second left me chale jao
    preorderTraversal(root->left);
    //third right me chle jao
    preorderTraversal(root->right);
}

void preorderIterativeTraversal(Node* root){
    if(root == NULL)return;
    stack<Node*> s;
    s.push(root);
    while( !s.empty()){
        // node ko print kro
        Node* curr = s.top();
        s.pop();
        cout<<curr->data<<" ";
        //right me jao
       if(curr->right)s.push(curr->right);
       //left me jao
       if(curr->left)s.push(curr->left);
    }
}

void inorderTraversal(Node* root){
    //inorder:-> L N R
    //base caase 
    if(!root)return;
    inorderTraversal(root->left); // left
    cout<<root->data<<" "; // node
    inorderTraversal(root->right); //right
}

void inorderIterativeTraversal(Node* root){
    if(root == NULL)return;
    stack<Node*> s;
    Node* curr = root;
    while(curr || !s.empty()){
        //left me jao
        while(curr){
            s.push(curr);
            curr = curr->left;
        }
        // node ko print kro
        curr = s.top();
        s.pop();
        cout<<curr->data<<" ";
        //right me jao
        curr = curr->right;
    }
}

void postorderTraversal(Node* root){
    if(!root)return;
    postorderTraversal(root->left); // left
  
    postorderTraversal(root->right); //right
      cout<<root->data<<" "; // node
}
void postorderiterativetraversal(Node* root){
    if(root == NULL)return;
    stack<Node*> s1 , s2;
    s1.push(root);
    while(!s1.empty()){
        Node* curr = s1.top();
        s1.pop();
        s2.push(curr);
        if(curr->left)s1.push(curr->left);
        if(curr->right)s1.push(curr->right);
    }
    while(!s2.empty()){
        cout<<s2.top()->data<<" ";
        s2.pop();
        
    }
    
    
}


void buildTreeLevelWise(Node* &root){
    queue<Node*> q;
    cout<<"enter the data: ";
    int data ;
    cin>>data;
    root = new Node(data);
    q.push(root);
    while(!q.empty()){
        Node* front = q.front();
        q.pop();
        cout<<"enter data for left of "<<front->data<<endl;
        int leftdata ;
        cin>>leftdata;
        if(leftdata != -1){
            front->left = new Node(leftdata);
            q.push(front->left);
        }
         cout<<"enter data for right of "<<front->data<<endl;
        int rightdata ;
        cin>>rightdata;
        if(rightdata != -1){
            front->right = new Node(rightdata);
            q.push(front->right);
        }
    }
}


int main() {
    // Write C++ code here
   Node* root = NULL;
   //create a binary tree
   // 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
   // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1 
   root = buildTree(root);
   //levelOrderTraversal 
   cout<<endl<<"print binary tree in level order: "<<endl;
   levelOrderTraversal(root);
   cout<<"printing binary tree in reverse leve order:_" <<endl;
   reverseLevelOrderTraversal(root);
   cout<<endl<<"printing preorderd traversal"<<endl;
   preorderTraversal(root);
   cout<<endl<<"printing preorderd  iterative way traversal"<<endl;
   preorderIterativeTraversal(root);
   cout<<endl<<"printing inorder traversal"<<endl;
   inorderTraversal(root);
    cout<<endl<<"printing inorder iterative way  traversal"<<endl;
   inorderIterativeTraversal(root);
   cout<<endl<<"printing postorder traversal"<<endl;
   postorderTraversal(root);
   cout<<endl<<"printing postorder iterative way traversal"<<endl;
   postorderiterativetraversal(root);
   cout<<endl<<"make level wise tree"<<endl;
   root = NULL;
   buildTreeLevelWise(root);
   cout<<endl<<"print binary tree in level order: "<<endl;
   levelOrderTraversal(root);
   
   cout<<endl<<"printing preorderd  iterative way traversal"<<endl;
   preorderTraversal(root);
   

    return 0;

    
    
}











