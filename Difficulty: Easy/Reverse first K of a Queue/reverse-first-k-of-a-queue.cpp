
class Solution {
public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        if(k <= 0 || q.empty()) return q;
        int n = q.size();
        if(k > n)return q;
        
        stack<int> s;

        for(int i = 0; i < k; i++) {
            s.push(q.front());
            q.pop();
        }

        // Step 2: Enqueue stack elements at rear of queue
        while(!s.empty()) {
            q.push(s.top());
            s.pop();
        }

        // Step 3: Move remaining (n-k) elements to rear to maintain order
        for(int i = 0; i < n - k; i++) {
            q.push(q.front());
            q.pop();
        }

        return q;
    }
};
