/*
Shortest Unique Prefix
Problem Description
Given a list of N words. Find shortest unique prefix to represent each word in the list. NOTE: Assume that no word is prefix of another. In other words, the representation is always possible


Problem Constraints
1 <= Sum of length of all words <= 106


Input Format
First and only argument is a string array of size N.


Output Format
Return a string array B where B[i] denotes the shortest unique prefix to represent the ith word.


Example Input
Input 1:
 A = ["zebra", "dog", "duck", "dove"]
Input 2:
A = ["apple", "ball", "cat"]



Example Output
Output 1:
 ["z", "dog", "du", "dov"]
Output 2:
 ["a", "b", "c"]



Example Explanation
Explanation 1:
 Shortest unique prefix of each word is:
 For word "zebra", we can only use "z" as "z" is not any prefix of any other word given.
 For word "dog", we have to use "dog" as "d" and "do" are prefixes of "dov".
 For word "du", we have to use "du" as "d" is prefix of "dov" and "dog".
 For word "dov", we have to use "dov" as "d" and do" are prefixes of "dog".

Explanation 2:
 "a", "b" and c" are not prefixes of any other word. So, we can use of first letter of each to represent.
*/
class Solution:
    # @param A : list of integers
    # @return an integer
    def solve(self, A):
        answer = 0
        for i in range(32)[::-1]:
            answer <<= 1
            prefixes = {num >> i for num in A}
            answer += any(answer^1 ^ p in prefixes for p in prefixes)
        return answer
struct TrieNode
{
    TrieNode *children[26];
    bool isEndOfWord;
    int count;
};

TrieNode *getNode()
{
    TrieNode *new_node = new TrieNode();
    for(int i=0; i<26; i++)
        new_node->children[i] = NULL;
    new_node->isEndOfWord = false;
    new_node->count = 0;
    return new_node;
}

void insert(string str, TrieNode *root)
{
    int m = str.length();
    TrieNode *pcrawl = root;
    for(int i=0; i<m; i++)
    {
        int index = str[i] - 'a';
        if(pcrawl->children[index] == NULL)
        {
            pcrawl->children[index] = getNode();
            pcrawl->children[index]->count = 0;
        }
        else
        {
            pcrawl->children[index]->count += 1;
        }
        pcrawl = pcrawl->children[index];
    }
    pcrawl->isEndOfWord = true;
}

string shortestPrefix(string str, TrieNode *root)
{
    string res = "";
    int m = str.length();
    TrieNode *pcrawl = root;
    for(int i=0; i<m; i++)
    {
        int index = str[i] - 'a';
        res.push_back(str[i]);
        pcrawl = pcrawl->children[index];
        if(pcrawl->count == 0)
            break;
    }
    return res;
}
vector<string> Solution::prefix(vector<string> &A) {
    int n = A.size();
    TrieNode *root = getNode();
    for(int i=0; i<n; i++)
        insert(A[i],root);
    vector <string> res;
    for(int i=0; i<n; i++)
    {
        res.push_back(shortestPrefix(A[i], root));
    }
    return res;
}
