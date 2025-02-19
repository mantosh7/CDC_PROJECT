// Q. Reverse First K Elements of a Queue
class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        stack<int> s;
        
        // Step 1: Push the first k elements into the stack
        for(int i = 0; i < k; i++) {
            s.push(q.front());
            q.pop();
        }
        
        // Step 2: Enqueue the elements from the stack back into the queue
        while(!s.empty()) {
            q.push(s.top());
            s.pop();
        }
        
        // Step 3: Move the remaining elements from the front to the back
        int n = q.size() - k;
        while(n--) {
            q.push(q.front());
            q.pop();
        }
        
        return q;
    }
};