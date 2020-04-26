/*
Window String
Problem Description
Given a string A and a string B, find the window with minimum length in A which will contain all the characters in T in linear time complexity.
Note that when the count of a character C in T is N, then the count of C in minimum window in A should be at least N. Note:
If there is no such window in A that covers all characters in B, return the empty string.
If there are multiple such windows, return the first occurring minimum window ( with minimum start index )



Problem Constraints
1 <= size(A), size(B) <= 106


Input Format
First argument is a string A.
Second argument is a string B.


Output Format
Return a string denoting the minimum window.


Example Input
A = "ADOBECODEBANC"
B = "ABC"


Example Output
"BANC"


Example Explanation
"BANC" is a substring of A which contains all characters of B.
*/
string Solution::minWindow(string str, string arr)
{
  unordered_map <char, int> mp_arr, mp_str;
  int n = arr.length();
  for(int i=0; i<n; i++)
  {
    mp_arr[arr[i]]++;
  }
  int m = str.length(),res = INT_MAX;
  string ans = "";
  for(int i=0,j=0; i<m && j<m; j++)
  {
     mp_str[str[j]]++;
     bool valid = true;
     for(auto it : mp_arr)
     {
        if(mp_str[it.first] < it.second)
        {
          valid = false;
        }
     }
     if(valid)
     {
        while(mp_str[str[i]] > mp_arr[str[i]])
        {
          mp_str[str[i]]--;
          i++;
        }
        if(j-i+1 < res)
        {
           ans = str.substr(i, j-i+1);
           res = j-i+1;
        }
     }
  }
  return ans;
}
