/*
Anagrams
Problem Description
Given an array A of N strings, return all groups of strings that are anagrams. Represent a group by a list of integers representing the index(1-based) in the original list. Look at the sample case for clarification. NOTE: Anagram : a word, phrase, or name formed by rearranging the letters of another, such as 'spar', formed from 'rasp'.


Problem Constraints
1 <= N <= 104
1 <= |A[i]| <= 104
Each string consists only of lowercase characters.
Sum of length of all the strings doesn't exceed 107


Input Format
Single Argument A which is an array of strings.


Output Format
Return a two-dimensional array where each row describes a group. Note: Ordering of the result :
You should not change the relative ordering of the strings within the group suppose within a group containing A[i] and A[j], A[i] comes before A[j] if i < j.


Example Input
A = [cat, dog, god, tca]


Example Output
[ [1, 4],
  [2, 3] ]


Example Explanation
"cat" and "tca" are anagrams which correspond to index 1 and 4 and "dog" and "god" are another set of anagrams which correspond to index 2 and 3.
The indices are 1 based ( the first element has index 1 instead of index 0).
*/
vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    int n = A.size();
    vector <string> arr;
    arr = A;
    for(int i=0; i<n; i++)
        sort(arr[i].begin(), arr[i].end());
    unordered_map <string, int> mp;
    vector <int>  res[n];
    int k = 1;
    for(int i=0; i<n; i++)
    {
        if(mp[arr[i]] == 0)
        {
            mp[arr[i]] = k;
            res[mp[arr[i]]-1].push_back(i+1);
            k++;
        }
        else
        {
            res[mp[arr[i]]-1].push_back(i+1);
        }
    }
    vector <vector <int> > ans;
    for(int i=0; i<k-1; i++)
    {
        vector <int> v;
        for(int j=0; j<res[i].size(); j++)
            v.push_back(res[i][j]);
        ans.push_back(v);
    }
    return ans;
}
