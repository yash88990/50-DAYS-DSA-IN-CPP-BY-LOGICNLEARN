// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        // code here
        vector<pair<int,int>> result;
        if(!head)return result;
        Node* left = head, *right = head;
        
        while(right->next){
            right = right->next;
        }
        while(left != right &&right->next != left){
            int sum = left->data + right->data;
            if(sum == target){
                result.push_back({left->data , right->data});
                left=left->next;
                right = right->prev;
            }else if(sum < target){
                
                left = left->next;
            }else{
                right = right->prev;
            }
        }
        return result;
    }
};
























