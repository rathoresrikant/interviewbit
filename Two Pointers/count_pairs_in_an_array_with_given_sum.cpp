/*
Count of pairs with the given sum
Given a sorted array of distinct integers A and an integer B, find and return how many pair of integers ( A[i], A[j] ) such that i != j have sum equal to B.
Input Format
The first argument given is the integer array A.
The second argument given is integer B.
Output Format
Return the number of pairs for which sum is equal to B.
Constraints
1 <= length of the array <= 100000
1 <= A[i] <= 10^9
1 <= B <= 10^9
For Example
Input 1:
    A = [1, 2, 3, 4, 5]
    B = 5
Output 1:
    2

Input 2:
    A = [5, 10, 20, 100, 105]
    B = 110
Output 2:
    2
*/
int Solution::solve(vector<int> &A, int B) {
    int n = A.size(), res = 0, a, b, temp1, temp2, count;
    for(int i=0, j = n-1; i<j; )
    {
        if(A[i]+A[j] < B)
            i++;
        else
        if(A[i]+A[j] > B)
            j--;
        else
        if(A[i]+A[j] == B)
        {
            if(A[i] != A[j])
            {
                a = 0, b = 0, temp1 = A[i], temp2 = A[j];
                while(A[i] == temp1)
                {
                    i++;
                    a++;
                }
                while(A[j] == temp2)
                {
                    j--;
                    b++;
                }
                res += a*b;
            }
            else
            {
                count = (j-i+1);
                res += (count*(count-1))/2;
                j = i - 1;
            }
        }
    }
    return res;
}
