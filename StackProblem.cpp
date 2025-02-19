
// 20. Valid Parenthesis
class Solution {
    public:
        bool isValid(string s) {
            stack<char> st;
            for(int i=0;i<s.size();i++)
            {
                char c=s[i];
                if(c=='('||c=='{'||c=='['||st.empty()) st.push(c);
                else if(c==')'&&st.top()=='(') st.pop();
                else if(c=='}'&&st.top()=='{') st.pop();
                else if(c==']'&&st.top()=='[') st.pop();
                else return false;
            }
            return st.empty();
        }
    };
    
    
    // 225. Implement Stack using Queues
    class MyStack {
    private:
        std::queue<int> q;
    public:
        MyStack() {}
        
        void push(int x) {
            q.push(x);
            int s=q.size();
            for(int i=0;i<s-1;i++)
            {
                q.push(q.front());
                q.pop();
            }
        }
        
        int pop() {
            int  x=q.front();
            q.pop();
            return x;
        }
        
        int top() {
            return q.front();
        }
        
        bool empty() {
            return q.empty();
        }
    };
    
    /**
     * Your MyStack object will be instantiated and called as such:
     * MyStack* obj = new MyStack();
     * obj->push(x);
     * int param_2 = obj->pop();
     * int param_3 = obj->top();
     * bool param_4 = obj->empty();
     */
    
    
    // 496. Next Greater Element I
    class Solution {
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            stack<int> st;
            unordered_map<int,int> m;
            for(int i=nums2.size()-1;i>=0;i--)
            {
                while(!st.empty()&&nums2[i]>=st.top())
                {
                    st.pop();
                }
                m[nums2[i]]=st.empty()?-1:st.top();
                st.push(nums2[i]);
            }
            for(int i=0;i<nums1.size();i++)
            {
                nums1[i]=m[nums1[i]];
            }
            return nums1;
        }
    };
    
    
    // 1991. Find the Middle Index in Array
    class Solution {
    public:
        int getSum(vector<int> nums)
        {
            int sum = 0;
            for (int num : nums)
                sum += num;
            return sum;
        }
    
        int findMiddleIndex(vector<int>& nums) {
            int leftSum=0;
            int rightSum=getSum(nums);
            for (int i=0; i<nums.size(); i++)
            {
                rightSum-=nums[i];
                if(leftSum==rightSum)
                    return i;
                leftSum += nums[i];
            }
            return -1;
        }
    };
    