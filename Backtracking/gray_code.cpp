/*
Gray Code
Problem Description
The gray code is a binary numeral system where two successive values differ in only one bit.
 Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.


Problem Constraints
1 <= n <= 16


Input Format
First argument is an integer n.


Output Format
Return an array of integers representing the gray code sequence.


Example Input
Input 1:
2



Example Output
output 1:
[0,1,3,2]



Example Explanation
Explanation 1:
for n = 2 the gray code sequence is:
    00 - 0
    01 - 1
    11 - 3
    10 - 2
So, return [0,1,3,2].
*/

vector<int> Solution::grayCode(int A) {
    vector <int> ans;
    for(int i=0; i<pow(2,A); i++)
    {
        int temp = i ^ (i >> 1);
        ans.push_back(temp);
    }
    return ans;
}
