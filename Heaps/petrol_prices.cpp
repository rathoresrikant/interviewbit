/*
Petrol prices
Rishik go to IB office on N days on his bike which consume exactly 1 litre petrol every day but his bike can only store at max B Litre of petrol. You are given petrol prices for all N days as integer array A. Find Minimum cost that could occur to rishik if he chooses optimal quantity to refuel everyday. Note:
Refueling station is very very close to rishik home. So, he can reach there from home at 0 petrol. but, he cannot go to office with 0 fuel.
Initially bike has 0 fuel.
Input Format:
    First argument contains an integer array A denoting petrol prices for N days.
    Second argument contains an integer B denoting Bike capacity.
Output Format:
    Return a single integer denoting minimum cost
Constraints:
1 <= B <= N <= 100000
1 <= A[i] <=20000
For Example:
Example Input 1:
    A = [5, 6, 3, 4, 2, 1] , B = 2
Example Output 1:
    19
Example Explanation:
    Quantity of petrol filled each day = [2, 0, 2, 0, 1, 1]. This gives minimum cost.
*/
int Solution::solve(vector<int> &A, int B) {
    int n = A.size(), ans = 0;
    priority_queue <pair<int, int> > pq;
    for(int i=0; i<n; i++)
    {
        pq.push(make_pair(-A[i], i));
        while(pq.top().second <= (i-B))
            pq.pop();
        ans = ans - pq.top().first;
    }
    return ans;
}
