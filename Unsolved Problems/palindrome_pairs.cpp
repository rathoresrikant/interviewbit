/*
Palindrome Pairs
Given a list of unique words A, find all pairs of distinct indices (i,j) in the given list such that concatenation of the two words, i.e. A[i] + A[j] is a palindrome. Note: A string is a palindrome if it reads the same backward as forward.
Input Format
The only argument given is the integer array A.
Output Format
Return the list of all pairs of distinct indices such that concatenation of the two words, i.e. A[i] + A[j] is a palindrome.
You can return the list in any order.
Constraints
1 <= length of the list A <= 1000
100 <= lenght of words in list A <= 100
For Example
Input 1:
    A = ["abcd", "dcba", "lls", "s", "sssll"]
Output 1:
    [ [0,1], [1,0], [3,2], [2,4] ]

Input 2:
    A = ["abc", "sa", "xy", "as" ]
Output 2:
    [ [1,3], [3,1] ]
*/
