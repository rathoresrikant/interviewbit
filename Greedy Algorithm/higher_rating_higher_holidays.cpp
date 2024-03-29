/*
Higher rating higher holidays.
Scooby's summer vacations are about to start. Scooby and all his school friends are sitting in the class in a single line.
Every one in the class has a rating depending on their performance in InterviewBit contests. Number of holidays a child will get is dependent on the child's relative performance. The teacher is kind and wants to give atleast one holiday to each child. If two children are sitting next to each other then the child with higher rating should always get more holidays. The teacher however wants to minimize the sum of holidays give to each child. Help the teacher in distributing holidays to children. Constraints:
Number of children in class 1<='N'<=100000
Rating of each child 1<=R<=100000
Input: Each test case contains an integer array . This array gives the rating of the ith child. Output: Return a single integer corresponding to the minimum sum of holidays given to children. Example: Input:
3 1 2 2
Output:
4
Explanation:
Hence optimal distribution will be 1,2,1.
*/
int Solution::solve(vector<int> &A) {
    int n = A.size(), res = 0;
    vector <int> candies(n);
    candies[0] = 1;
    for(int i=1; i<n; i++)
    {
        if(A[i] > A[i-1])
            candies[i] = candies[i-1] + 1;
        else
            candies[i] = 1;
    }
    for(int i=n-2; i>=0; i--)
    {
        if(A[i] > A[i+1])
            candies[i] = max(candies[i],candies[i+1] + 1);
    }
    for(int i=0; i<n; i++)
        res += candies[i];
    return res;
}
