/*The structure of the class is
class SortedStack{
public:
    stack<int> s;
    void sort();
};
*/

/* The below method sorts the stack s
you are required to complete the below method */
void insertInSortedOrder(stack<int> &s, int element) {
    // Base case: either stack is empty or top element is smaller or equal
    if (s.empty() || s.top() <= element) {
        s.push(element);
        return;
    }

    // Remove top and recur
    int topElement = s.top();
    s.pop();
    insertInSortedOrder(s, element);

    // Push the top element back
    s.push(topElement);
}

void SortedStack ::sort() {
    // Base case
    if (s.empty()) return;

    // Pop top element
    int topElement = s.top();
    s.pop();

    // Recursively sort the remaining stack
    sort();

    // Insert the popped element back in the sorted order
    insertInSortedOrder(s, topElement);
}
