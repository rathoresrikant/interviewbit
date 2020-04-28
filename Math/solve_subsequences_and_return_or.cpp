/*
Solve sub-sequences and return OR
Problem Description
A subsequence is a sequence that can be derived from another sequence by deleting some elements without changing the order of the remaining elements. For example, the sequence {2, 3, 5} is a subsequence of {1, 2, 3, 4, 5} obtained after removal of elements {1, 4}. Given is an array of integers A of size N. An array of size N can have (2^N - 1) number of non empty subsequences. For the given function:
 solve (int subsequence[]) {
    int count[];    //array initialised to 0.
    for(int i = 0; i &amp;lt; subsequence.length; i++) {
        number = subsequence[i];
        for(int j = 2; j &amp;lt;= number; j++) {
            if(number % j == 0) {
                count[j]++;
                if(count[j] == subsequence.length)  return 0;
            }
        }
    }
    return 1;
}
If all the subsequences of the array A are passed in the above function. What will be the bitwise OR of all the returned values from the given function.


Problem Constraints
1 <= length of the array <= 100000
1 <= A[i] <= 109


Input Format
The only argument given is the integer array A.


Output Format
Return the bitwise OR of all the returned values.


Example Input
Example Input 1:
 A = [1, 2, 3]
Example Input 2:
 A = [2, 4, 6, 8]



Example Output
Example Output 1:
 1
Example Output 2:
 0



Example Explanation
Explanation 1:
 If you pass {1} in function, it return 1. as A|1 = 1. answer will be 1.
 */
 int Solution::solve(vector<int> &A) {
     // If there are atleast two elements whose gcd is 1, return 1 else return 0
     int n = A.size(), m = *max_element(A.begin(), A.end()), count, num;
     vector <int> arr;
     map <int, int> mp;
     // Prime factorization of m
     while (m % 2 == 0)
     {
         if(mp[2] == 0)
             arr.push_back(2);
         mp[2]++;
         m = m/2;
     }
     for (int i = 3; i <= sqrt(m); i = i + 2)
     {
         while (m % i == 0)
         {
             if(mp[i] == 0)
                 arr.push_back(i);
             mp[i]++;;
             m = m/i;
         }
     }
     if (m > 2)
     {
         if(mp[m] == 0)
         arr.push_back(m);
         mp[m]++;
     }
     for(int i = 0; i < arr.size(); i++)
     {
         count = 0;
         for(int j=0; j<n; j++)
         {
             if(A[j]%arr[i] == 0)
             count++;
         }
         if(count == n)
             return 0;
     }
     return 1;
 }
