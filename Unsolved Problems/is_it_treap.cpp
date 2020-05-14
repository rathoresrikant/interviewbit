/*
Is it treap?
Problem Description
You are given an empty array. Process Q queries of the following problems:
1 X 0: insert X at the back of the array
2 A B: find the count of numbers in the range [A, B] in the array.
Return an integer array denoting the answer of each query.


Problem Constraints
1 <= Q <= 2*105
1 <= X <= 109
1 <= A <= B <= 109



Input Format
First and only argument of input contains a Q x 3 integer matrix, each row denoting a query.


Output Format
Return an integer array denoting the answer of each query.


Example Input
Input 1:
   A = [
        [1, 2, 0]
        [1, 5, 0]
        [2, 1, 10]
        [1, 5, 0]
        [2, 2, 5]
       ]
Input 2:
   A = [
        [2, 1, 2]
        [1, 2, 0]
        [2, 3, 4]
        [1, 4, 0]
       ]



Example Output
Output 1:
    [2, 3]
Output 2:
    [0, 0]



Example Explanation
Explanation 1:
    [1, 2, 0]: insert 2 in array, array becomes [2]
    [1, 5, 0]: insert 5 in array, array becomes [2, 5]
    [2, 1, 10]: [2,5] both lie in [1, 10], so return 2
    [1, 5, 0]: insert 5 in array, array becomes [2, 5, 5]
    [2, 2, 5]: all 3 elements lie in [2,5], so return 3
*/
