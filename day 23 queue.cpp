// Online C++ compiler to run C++ program online
#include <iostream>
#include<queue>
using namespace std;
int main() {
    //decalre a queue
    queue<int>q;
    q.push(30);
    cout<<q.front()<<endl;
    q.push(50);
    cout<<q.front()<<endl;
    q.pop();
    q.pop();
    cout<<q.front()<<endl;
    cout<<q.empty()<<endl;
    

    return 0;
}























// Online C++ compiler to run C++ program online
#include <iostream>
#include<vector>
using namespace std;
class deque{
    private:
    vector<int> arr;
    int front , rear , size , currsize;
    public:
      deque(int n){
          size = n;
          arr.resize(size);
          front = rear = -1;
          currsize = 0;
      }
      bool pushfront(int x){
          if(isfull())return false;
          if(isempty())front = rear = 0;
          else{
              front = (front - 1 + size ) % size;
          }
          arr[front] = x;
          currsize++;
          return true;
      }
      bool pushrear(int x){
          if(isfull())return -1;
          if(isempty())front = rear = 0;
          else{
              rear = (rear+1)% size;
          }
          arr[rear] = x;
          currsize++;
          return true;
      }
      int poprear(){
          if(isempty())return -1;
          int popped = arr[rear];
          if(front == rear )rear = front = -1;
          else{
              rear = (rear -1 +  size)%size;
          }
          currsize--;
          return popped;
      }
      int popfront(){
          if(isempty())return -1;
          int popped = arr[front];
          if(front == rear)front = rear = -1;
          else{
              front = (front + 1 )%size;
              
          }
          currsize--;
          return popped;
      }
      bool isempty(){
          return currsize == 0;
      }
      bool isfull(){
          return currsize == size;
      }
      int getfront(){
          if(isempty())return -1;
          return arr[front];
      }
      int getrear(){
          if(isempty())return -1;
          return arr[rear];
      }
};
int main() {
    //decalre a queue
    deque q(5);
    q.pushfront(30);
    cout<<q.getfront()<<endl;
    q.pushrear(50);
    cout<<q.getfront()<<endl; //30 50
    
    q.poprear(); // 30 
    cout<<q.getfront()<<endl;
    
    

    return 0;
}
