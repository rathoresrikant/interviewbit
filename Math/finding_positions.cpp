/*
Finding Position
Problem Description
Given an integer A which denotes the number of people standing in the queue.
A selection process follows a rule where people standing on even positions are selected. Of the selected people a queue is formed and again out of these only people on even position are selected.

This continues until we are left with one person. Find and return the position of that person in the original queue.


Problem Constraints
1 <= A <= 109


Input Format
The only argument given is integer A.


Output Format
Return the position of the last selected person in the original queue.


Example Input
 A = 10


Example Output
 8


Example Explanation
 Initially,people at 2, 4, 6, 8, 10 position are selected.
 Then 4, 8 are selected since 4 at 2nd position and 8 at 4th position in the new queue.
 Finally 8 is selected.
*/
int Solution::solve(int A) {
    return pow(2,floor(log2(A)));
}
