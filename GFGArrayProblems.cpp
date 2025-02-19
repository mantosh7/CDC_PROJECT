// Q. Subarray with Given Sum
class Solution {
    public:
        int subArraySum(vector<int>& arr, int k) {
            // code here.
            map<int,int> m;
            int count=0,sum=0;
            for(int i=0;i<arr.size();i++)
            {
                sum+=arr[i];
                int rem=sum-k;
                if(sum==k) count++;
                if(m.find(rem)!=m.end())
                {
                    count+=m[sum-k];
                }
                m[sum]++;
            }
            return count;
        }
    };
    
    
    // Q. Majority Element
    class Solution {
    public:
        int majorityElement(vector<int>& arr) {
            sort(arr.begin(),arr.end());
            // your code here
            int num=arr[0],count=0;
            for(int i=0;i<arr.size();i++)
            {
                if(num==arr[i])
                {
                    count++;
                    if(count>arr.size()/2)
                    {
                        return num;
                    }
                }
                else
                {
                    num=arr[i];
                    count=1;
                }
            }
            return -1;
        }
    };
    
    
    // Q. Leaders in an Array
    class Solution {
    // Function to find the leaders in the array.
    public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        stack<int> st;
        vector<int> v;
        for(int i=arr.size()-1;i>=0;i--)
        {
            if(st.empty()||arr[i]>=st.top())
            {
                st.push(arr[i]);
            }
        }
        while(!st.empty())
        {
            int x=st.top();
            st.pop();
            v.push_back(x);
        }
        return v;
    }
    };