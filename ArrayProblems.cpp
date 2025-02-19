// 1. Two Sum
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            map<int,int> m;
            for(int i=0;i<nums.size();i++)
            {
                int a=nums[i];
                int n=target-a;
                if(m.find(n)!=m.end())
                {
                    return {m[n],i};
                }
                m[a]=i;
            }
            return {-1,-1};
        }
    };
    
    
    // 53. Maximum Subarray
    class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int maxi=INT_MIN;
            int sum=0;
            for(int i=0;i<nums.size();i++)
            {
                sum+=nums[i];
                maxi=max(sum,maxi);
                if(sum<0) sum=0;
            }
            return maxi;
        }
    };
    
    
    // 724. Find Pivot Index
    class Solution {
    public:
        int pivotIndex(vector<int>& nums) {
            int total=accumulate(nums.begin(),nums.end(),0);
            int leftSum=0;
            for(int i=0;i<nums.size();i++)
            {
                int rightSum=total-leftSum-nums[i];
                if(rightSum==leftSum) return i;
                leftSum+=nums[i];
            }
            return -1;
        }
    };
    
    
    // 66. Plus One
    class Solution {
    public:
        vector<int> plusOne(vector<int>& digits) {
            int carry=1;
            int n=digits.size();
            vector<int> v(n+1);
            for(int i=0;i<v.size()-1;i++)
            {
                v[i]=(digits[n-i-1]+carry)%10; 
                if(digits[n-i-1]+carry>9) carry=1;
                else carry=0;
            }
            if(carry==1) v[n]=1;
            else v.resize(n);
            reverse(v.begin(),v.end());
            return v;
        }
    };