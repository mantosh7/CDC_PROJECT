// Q. Check if String is a Rotation of Another
class Solution {
    public:
      // Function to check if two strings are rotations of each other or not.
      bool areRotations(string &s1, string &s2) {
          // Your code here
          if(s1.size()!=s2.size()) return false;
          string temp=s1+s1;
          return temp.find(s2)!=string::npos;
      }
  };
  
  
  // Q. Remove Adjacent Duplicates
  class Solution {
  public:
      vector<int> removeDuplicate(vector<int>& arr) {
          // code here
          vector<int> v,hash(100,0);
          for(int i=0;i<arr.size();i++)
          {
              hash[arr[i]]++;
              if(hash[arr[i]]==1) v.push_back(arr[i]);
          }
          return v;
      }
  };