/*
K-th character of decrypted string
Given a String A and an integer B. String A is encoded consisting of lowercase English letters and numbers. A is encoded in a way where repetitions of substrings are represented as substring followed by the count of substrings. For example: if the encrypted string is “ab2cd2” and B=4, so the output will be ‘b’ because the decrypted string is “ababcdcd” and 4th character is ‘b’. You have to find and return the Bth character in the decrypted string. Note: Frequency of encrypted substring can be of more than one digit. For example, in “ab12c3”, ab is repeated 12 times. No leading 0 is present in the frequency of substring.
Input Format
The arguments given are string A and integer B.
Output Format
Return the Bth character in the decrypted string.
Constraints
1 <= length of the array <= 10^5
1 < = K < = 10^9
For Example
Input 1:
    A = "ab2c3"
    B = 5
Output 1:
    c
    Decrypted string will be "ababcccc" and 'c' is the fifth character.

Input 2:
    A = "x2y3"
    B = 3
Output 2:
    y
*/
