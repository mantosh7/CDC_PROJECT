// 232. Implement Queue using Stacks
class MyQueue {
    private:
        queue<int> input;
        queue<int> output;
    
    public:
        MyQueue() {}
    
        void push(int x) {
            input.push(x);
        }
    
        int pop() {
            peek();
            int val = output.front();
            output.pop();
            return val;
        }
    
        int peek() {
            if (output.empty()) {
                while (!input.empty()) {
                    output.push(input.front());
                    input.pop();
                }
            }
            return output.front();
        }
    
        bool empty() {
            return input.empty() && output.empty();
        }
    };
    
    
    // 622. Design Circular Queue
    class MyCircularQueue {
    private:
        vector<int> v;
        int start = 0, len = 0;
    public:
        MyCircularQueue(int k): v(k) {}
        bool enQueue(int value) {
            if (isFull()) return false;
            v[(start + len++) % v.size()] = value;
            return true;
        }
        bool deQueue() {
            if (isEmpty()) return false;
            start = (start + 1) % v.size();
            --len;
            return true;
        }
        int Front() {
            if (isEmpty()) return -1;
            return v[start];
        }
        int Rear() {
            if (isEmpty()) return -1;
            return v[(start + len - 1) % v.size()];
        }
        bool isEmpty() {
            return !len;
        }
        bool isFull() {
            return len == v.size();
        }
    };
    
    
    // 239. Sliding Window Maximum
    class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            vector<int> res;
            deque<int> deque;
    
            for (int idx = 0; idx < nums.size(); idx++) {
                int num = nums[idx];
    
                while (!deque.empty() && deque.back() < num) {
                    deque.pop_back();
                }
                deque.push_back(num);
    
                if (idx >= k && nums[idx - k] == deque.front()) {
                    deque.pop_front();
                }
    
                if (idx >= k - 1) {
                    res.push_back(deque.front());
                }
            }
    
            return res;        
        }
    };