/*
Longest Special Substring
Problem Description
Given a string A of size N consisting of lowercase alphabets. There are two types of characters: Normal and Special. A character is Normal if its value is 0 and Special if its value is 1. Whether a character is normal or special, it is given by an integer array B of size 26 consisting only of 0 and 1. Each value in B corresponds to the lowercase character. NOTE: First value of B will correspond to the value of character 'a' and last value will correspond to 'z'.  Return the length of the longest substring of A that contains at most C special characters.


Problem Constraints
1 <= N <= 105
1 <= C <= 105


Input Format
First argument is a string A of size N.
Second argument is an integer array B of length 26.
Third argument is an integer C.


Output Format
Return an integer denoting the length of longest substring of A that contains at most C special characters.


Example Input
Input 1:
 A = "rishabhkejariwal"
 B = [0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0]
 C = 2



Example Output
Output 1:
 10



Example Explanation
Explanation 1:
Array B denotes the type of character from [a-z].
Alphabet is aligned with the value of B
26 alphabets are = "abcdefghijklmnopqrstuvwxyz"
B = [0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0]
Value of alphabet 'a' = 0, 'b' = 1, 'c' = 1, 'd' = 0 ........ 'y' = 1, 'z' = 0.
Now, longest substring which consist of atmost 2 special characters is "hkejariwal" and the length is 10.
*/
