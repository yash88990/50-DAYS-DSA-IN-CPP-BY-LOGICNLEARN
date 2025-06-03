class MyStack {
  private:
    StackNode *top;

  public:
     // Function to push an element onto the stack
    void push(int x) {
        StackNode* new_node = new StackNode(x);
        // if(!new_node) return;
        new_node->next = top;
        top = new_node;
    }

    // Function to remove and return the top element of the stack
    int pop() {
        if(top == NULL) return -1; 
        else {
            int popped = top->data;
            StackNode* temp = top;
            top = top->next;
            delete temp;
            return popped;
        }
    }

    MyStack() { top = NULL; }
};