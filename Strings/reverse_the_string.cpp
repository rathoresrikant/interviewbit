/*
Reverse the String
Problem Description
Given a string A of size N. Return the string A after reversing the string word by word. NOTE:
A sequence of non-space characters constitutes a word.
Your reversed string should not contain leading or trailing spaces, even if it is present in the input string.
If there are multiple spaces between words, reduce them to a single space in the reversed string.



Problem Constraints
1 <= N <= 105


Input Format
The only argument given is string A.


Output Format
Return the string A after reversing the string word by word.


Example Input
Input 1:
    A = "the sky is blue"
Input 2:
    A = "this is ib"


Example Output
Output 1:
    "blue is sky the"
Output 2:
    "ib is this"


Example Explanation
Explanation 1:
    We reverse the string word by word so the string becomes "the sky is blue".

*/
void Solution::reverseWords(string &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    stringstream ss(A);
    string word, res;
    vector <string> temp;
    while(ss >> word)
        temp.push_back(word);
    reverse(temp.begin(), temp.end());
    int n = temp.size();
    for(int i=0; i<n; i++)
    {
        res.append(temp[i]);
        res.push_back(' ');
    }
    res.pop_back();
    A.erase();
    A = res;
}
