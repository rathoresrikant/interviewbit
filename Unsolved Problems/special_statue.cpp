/*
Special statue
Problem Description
You are given N statues. The height of ith statue is given by Ai.

For the statues to be special, there should be no two consecutive statues of the same height.

If the given statues are not special, you can change the height of the statues. You can increase the height of the ith statue by 1 but have to pay Bi amount of money. Calculate the minimum amount of money you have to spend to make the statues special.

NOTE: The height of the statue can be increased any number of times(possibly 0).



Problem Constraints
1 <= N <= 100000 1 <= A[i] <= 100000 1 <= B[i] <= 10000


Input Format
First argument is an integer array A of size N denoting the height of the statues.
Second argument is an integer array B of size N.


Output Format
Return an integer denoting the minimum amount of money you have to spend to make the statues special.


Example Input
A = [2, 1, 1, 3, 4]
B = [3, 3, 5, 3, 10]


Example Output
5


Example Explanation
Since statues 2 and 3 are of same height. If we increase the height of statue 3 by 1.
So the amount of money spend is 5 and no two consecutive statues of same height.
 If we increase the height of statue 2 by 1, then the height of statues will be [2, 2, 1, 3, 4].
So we have to again increase the height of statue 1 so the height becomes [2, 3, 1, 3, 4].
But for this, the amount of money spend is 6. Minimum amount spend is 5.
*/
