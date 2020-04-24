/*
Painter's Partition Problem
Problem Description
Given 2 integers A and B and an array of integers C of size N. Element C[i] represents length of ith board.
You have to paint all N boards [C0, C1, C2, C3 … CN-1]. There are A painters available and each of them takes B units of time to paint 1 unit of board.
 Calculate and return minimum time required to paint all boards under the constraints that any painter will only paint contiguous sections of board. NOTE:
1. 2 painters cannot share a board to paint. That is to say, a board cannot be painted partially by one painter, and partially by another.
2. A painter will only paint contiguous boards. Which means a configuration where painter 1 paints board 1 and 3 but not 2 is invalid.

Return the ans % 10000003.


Problem Constraints
1 <= A <= 1000
1 <= B <= 106
1 <= N <= 105
1 <= C[i] <= 106


Input Format
The first argument given is the integer A.
The second argument given is the integer B.
The third argument given is the integer array C.


Output Format
Return minimum time required to paint all boards under the constraints that any painter will only paint contiguous sections of board % 10000003.


Example Input
Input 1:
 A = 2
 B = 5
 C = [1, 10]
Input 2:
 A = 10
 B = 1
 C = [1, 8, 11, 3]



Example Output
Output 1:
 50
Output 2:
 11



Example Explanation
Explanation 1:
 Possibility 1:- One painter paints both blocks, time taken = 55 units.
 Possibility 2:- Painter 1 paints block 1, painter 2 paints block 2, time take = max(5, 50) = 50
 There are no other distinct ways to paint boards.
 ans = 50%10000003
Explanation 2:
 Each block is painted by a painter so, Painter 1 paints block 1, painter 2 paints block 2, painter 3 paints block 3
 and painter 4 paints block 4, time taken = max(1, 8, 11, 3) = 11
 ans = 11%10000003
 */

 bool isPossible(int A, int B, vector<int> &C,long long int X)
 {
     int n=C.size();
     long long int t=X;
     int i=0,cnt=1;
     while(i<n){
         if(cnt>A)
          return false;
         if(C[i]>t){
             cnt++;
             t=X;
         }
         else{
             t=t-C[i];
             i++;
         }
     }
     return true;
 }
 int Solution::paint(int A, int B, vector<int> &C) {
     int n=C.size();
     long long int sum=0;
     for(int i=0;i<n;i++)
         sum=sum%10000003+C[i]%10000003;
     long long int low=0,high=sum*B;
     long long int ans=high%10000003;
     while(low<=high){
         long long int mid=low+(high-low)/2;
         if(isPossible(A,B,C,mid/B)){
             ans=mid%10000003;
             high=mid-1;
         }
         else low=mid+1;
     }
     return ans%10000003;
 }
 
