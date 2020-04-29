/*
N integers containing only 1,2 and 3
Given an integer A. Find and Return first positive A integers in ascending order containing only digits 1,2 and 3. NOTE: all the A integers will fit in 32 bit integer.
Input Format
The only argument given is integer A.
Output Format
Find and Return first positive A integers in ascending order containing only digits 1,2 and 3.
Constraints
1 <= A <= 29500
For Example
Input 1:
    A = 3
Output 1:
    [1, 2, 3]

Input 2:
    A = 7
Output 2:
    [1, 2, 3, 11, 12, 13, 21]
*/
vector<int> Solution::solve(int A)
{
    priority_queue <int, vector<int>, greater<int>> pq;
    vector <int> res;
    if(A == 1)
        return {1};
    if(A == 2)
        return {1, 2};
    if(A == 3)
        return {1, 2, 3};
    int count = 3;
    pq.push(1);
    pq.push(2);
    pq.push(3);
    while(count < A)
    {
        int curr = pq.top();
        pq.pop();
        res.push_back(curr);
        pq.push(curr*10 + 1);
        pq.push(curr*10 + 2);
        pq.push(curr*10 + 3);
        count += 3;
    }
    int i = res.size();
    for(i; i<A; i++)
    {
        int curr = pq.top();
        pq.pop();
        res.push_back(curr);
    }
    return res;
}
