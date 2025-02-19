// 242. Valid Anagram
class Solution {
    public:
        bool isAnagram(string s, string t) {
            vector<int> hash(26,0);
            if(s.size()!=t.size()) return false;
            for(int i=0;i<s.size();i++)
            {
                hash[s[i]-'a']++;
                hash[t[i]-'a']--;
            }
            for(auto i:hash)
            {
                if(i!=0) return false;
            }
            return true;
        }
    };
    
    
    // 344. Reverse String
    class Solution {
    public:
        void reverseString(vector<char>& s) {
            for(int i=0;i<s.size()/2;i++)
            {
                swap(s[i],s[s.size()-i-1]);
            }
        }
    };
    
    
    // 28. Find the Index of the First Occurrence in a String
    class Solution {
    public:
        int strStr(string haystack, string needle) {
            int n=needle.size();
            int h=haystack.size();
            for(int i=0;i<=h-n;i++)
            {
                if(needle==haystack.substr(i,n)) return i;
            }  
            return -1;
        }
    };
    
    
    // 387. First Unique Character in a String
    class Solution {
    public:
        int firstUniqChar(string s) {
            vector<int> hash(26,0);
            for(int i=0;i<s.size();i++)
            {
                hash[s[i]-'a']++;
            }
            for(int i=0;i<s.size();i++)
            {
                if(hash[s[i]-'a']==1) return i;
            }
            return -1;
        }
    };