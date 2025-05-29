// //1 . Insertion In A Singly Linked List

// // Node * insert(Node * head, int n, int pos, int val) {
// //     // Write your code here
// //     //when pos is invalid means < 0
// //     if(pos < 0 ){
// //         cout<<"Invalid position "<<endl;
// //         return head;
// //     }
// //     //if pos == 0 menas 1st position(head)
// //     if(pos == 0){
// //         Node* temp = new Node(val);
// //         temp->next = head;
// //         head = temp;
// //         return head;
// //     }
// //     //if pos > 0 
// //     Node* prev = head;
// //     int count = 0 ;
// //     while( count < pos - 1 && prev != NULL){
// //         prev = prev ->next;
// //         count++;
// //     }
// //     //if pos > size of linked list
// //     if(prev == NULL){
// //         cout<<"Invalid position"<<endl;
// //         return head;
// //     }
// //     Node* temp = new Node(val);
// //     temp->next = prev->next;
// //     prev->next = temp;
// //     return head;
// // }







// //  Delete Node In A Linked List


// void deleteNode(LinkedListNode<int> * node) {
//     // Write your code here.
//     if(node == NULL || node->next == NULL)return;
//     LinkedListNode<int>* nextnode = node->next;
//     node->data = nextnode->data;
//     node->next = nextnode->next;

//     delete nextnode;
    


// }





// 2095. Delete the Middle Node of a Linked List


// class Solution {
// public:
//     ListNode* deleteMiddle(ListNode* head) {
//         if(head == NULL || head->next == NULL)return NULL;
//         int count = 0 ;
//         ListNode* temp = head;
//         while(temp){
//             count++;
//             temp= temp->next;
            
//         }
//         int  mid = count / 2 ;
//         temp = head;
        
//         for(int i = 0 ; i < mid - 1; i++){
//             temp = temp->next;
//         }
//         ListNode* nodetodelete = temp->next;
//         temp->next = temp->next->next;
//         delete nodetodelete;

//         return head;
        

//     }
// };





// Count nodes of linked list

// int length(Node *head)
// {
// 	//Write your code here
//     int count = 1 ;
//     Node* current = head;
//     while(current ->next != NULL){
//         count++;
//         current = current->next;
//     }
//     return count;
    
// }

// Search in Linked List

// class Solution {
//   public:
//     // Function to count nodes of a linked list.
//     bool searchKey(int n, Node* head, int key) {
//         // Code here
//         if(!head)return false;
//         Node* curr = head;
//         while(curr){
//             if(curr->data == key)return true;
//             curr= curr->next;
//         }
//         return false;
//     }
// };



// 876. Middle of the Linked List
// class Solution {
// public:
//     ListNode* middleNode(ListNode* head) {
//         ListNode* slow = head ;
//         ListNode* fast = head;
//         while(fast != NULL && fast->next != NULL){
//             slow = slow->next;
//             fast = fast->next->next;
//         }
//         return slow;
//     }
// };


// 206. Reverse Linked List

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         if(head == NULL || head ->next == NULL)return head;
//         ListNode* curr  = head ,* prev = NULL;
//         while(curr){
//             ListNode* temp = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = temp;
//         }
//         return prev;
//     }
// };


// 234. Palindrome Linked List

// class Solution {
// public:
// ListNode* reverseList(ListNode* head) {
//         if(head == NULL || head ->next == NULL)return head;
//         ListNode* curr  = head ,* prev = NULL;
//         while(curr){
//             ListNode* temp = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = temp;
//         }
//         return prev;
//     }
//     bool isPalindrome(ListNode* head) {
//         if(!head || !head->next)return true;
//         //find middle 
//         ListNode* slow = head ;
//         ListNode* fast = head;
//         while(fast != NULL && fast->next != NULL){
//             slow = slow->next;
//             fast = fast->next->next;
//         }
//         //reverse half
//         ListNode* secondhalf = reverseList(slow);
//         //comapre 
//         ListNode* firsthalf = head;
//         ListNode *temp = secondhalf;
//         while(temp){
//             if(firsthalf->val != temp->val)return false;
//             firsthalf = firsthalf->next;
//             temp = temp->next;
//         }
//         return true;
        

//     }
// };

// Sort a linked list of 0s, 1s and 2s

// class Solution {
//   public:
//     Node* segregate(Node* head) {
//         // code here
//         int count[3] = {0,0,0};
//         Node* curr = head;
//         while(curr){
//             count[curr->data]++;
//             curr= curr->next;
//         }
//         curr = head;
//         int i = 0;
//         while(curr){
//             if(count[i] == 0)i++;
//             else{
//                 curr->data = i;
//                 count[i]--;
//                 curr = curr->next;
//             }
//         }
//         return head;
//     }
// };


// 2. Add Two Numbers

// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode* dummy = new ListNode(0);
//         ListNode* current = dummy;
//         int carry = 0;
//         while(l1 || l2 || carry){
//             int sum = carry;
//             if(l1){
//                 sum += l1->val;
//                 l1=l1->next;
//             }
//             if(l2){
//                 sum += l2->val;
//                 l2 = l2->next;
//             }
//             carry  = sum /10;
//             current->next = new ListNode(sum % 10);
//             current = current->next;

//         }
//         return dummy->next;
//     }
// };