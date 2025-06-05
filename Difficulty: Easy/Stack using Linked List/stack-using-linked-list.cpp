class MyStack {
  private:
    StackNode *top;

  public:
    void push(int x) {
        // code here
        StackNode* newNode = new StackNode(x);
        newNode->next = top;
        top = newNode;
        
    }

    int pop() {
        
        // code here
        if(top == NULL)return -1;
        else{
            int popped = top->data;
            StackNode* temp = top;
            top = top->next;
            delete  temp;
            return popped;
        }
    }

    MyStack() { top = NULL; }
};