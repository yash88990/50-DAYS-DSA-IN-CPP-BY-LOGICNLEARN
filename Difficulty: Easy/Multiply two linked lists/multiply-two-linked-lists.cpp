/* Linked list node structure
struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/

/*The method multiplies
two  linked lists l1 and l2
and returns their product*/


const long long MOD = 1000000007;





// Solution class containing the function
class solution {
public:
    // Function to multiply two linked lists
    long long multiplyTwoLists(Node* first, Node* second) {
        // Modulo value as mentioned in the problem
        long long MOD = 1000000007;

        // Initialize variables to store numbers
        long long num1 = 0, num2 = 0;

        // Traverse the first linked list and construct the number
        while (first != nullptr) {
            num1 = (num1 * 10 + first->data) % MOD;
            first = first->next;
        }

        // Traverse the second linked list and construct the number
        while (second != nullptr) {
            num2 = (num2 * 10 + second->data) % MOD;
            second = second->next;
        }

        // Multiply the two numbers and take modulo
        return (num1 * num2) % MOD;
    }

// Function to create a linked list from a list of integers
Node* createLinkedList(vector<int> arr) {
    Node* head = nullptr;
    Node* temp = nullptr;

    for (int i = 0; i < arr.size(); ++i) {
        if (head == nullptr) {
            head = new Node(arr[i]);
            temp = head;
        } else {
            temp->next = new Node(arr[i]);
            temp = temp->next;
        }
    }
    return head;
};


};



