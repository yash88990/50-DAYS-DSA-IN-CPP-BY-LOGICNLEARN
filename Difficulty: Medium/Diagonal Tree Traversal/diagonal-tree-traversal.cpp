/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
    vector<int> diagonal(Node *root) {
        // code here
        queue<Node*>q;
        vector<int>ans;
        q.push(root);
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            while(temp){
                ans.push_back(temp->data);
                if(temp->left)q.push(temp->left);
                temp = temp->right;
            }
            
        }
        return ans;
    }
};