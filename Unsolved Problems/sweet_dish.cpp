/*
Sweet dish
Problem Description
Akash has N ingredients and ith ingredients have Ai sweetness. He wants to make a perfect dish using some given ingredients. A dish will be perfect if it has following properties
There is at least one ingredient in the dish whose sweetness value is a prime number.
The total sweetness of the dish must be at least B and at most C.
 Find the number of ways to make the perfect dish.


Problem Constraints
1 <= N <= 18
2 <= A[i] <= 109
2 <= B <= C <= 109


Input Format
First argument is an integer array A denoting the sweetness of the ingredients.
Second argument is an integer B.
Third argument is an integer C.


Output Format
Return an integer denoting the number of ways to make the perfect dish.


Example Input
Input 1:
 A = [2, 2, 4, 5]
 B = 3
 C = 7
 Input 2:
 A = [1, 3, 7, 4]
 B = 5
 C = 8



Example Output
Output 1:
 6
 Output 2:
 5



Example Explanation
Explanation 1:
 There are 6 ways to make dish using the given ingredients: [2, 2], [2, 4], [2, 4], [2, 5], [2, 5], [5].
  Explanation 2:
 There are 5 ways to make dish using the given ingredients: [3, 4], [1, 4], [1, 7], [1, 3, 4], [3, 4].
 */

 
