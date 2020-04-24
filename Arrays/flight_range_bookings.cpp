/*
Flight Range Bookings
Problem Description
There is a company CorpFly which only takes booking from corporates. They have A flights and they are numbered from 1 to A. Corporate bookings are of the following form (i, j, K). This implies book K seats each on every flight numbered between i and j (inclusive). Given a 2-D array B of size M * 3 denoting a sequence of these bookings from corporates, your job is to tell the number of seats booked on each of the A flights. NOTE: Assume the number of seats in every flight is infinite.


Problem Constraints
1 <= A <= 2 * 105 1 <= i <= j <= A 1 <= M <= 105


Input Format
First argument is an integer A.
Second argument is a 2-D array B of size M * 3.


Output Format
Return an integer array denoting the number of seats booked on each of the A flights.


Example Input
A = 5
B = [ [1, 2, 10],
      [2, 3, 20],
      [2, 5, 25] ]


Example Output
[10, 55, 45, 25, 25]


Example Explanation
=> First booking books 10 seats on flights 1 to 2(1 and 2). Final bookings in each flight after first booking: [10, 10, 0, 0, 0]
=> Second booking books 20 seats on flights 2 to 3(2 and 3). Final bookings in each flight after second booking: [10, 30, 20, 0, 0]
=> Third booking books 25 seats on flights 2 to 5(2,3,4,5). Final bookings in each flight after third booking: [10, 55, 45, 25, 25]
*/

vector<int> Solution::solve(int A, vector<vector<int> > &B) {
    vector <int> booking(A+1,0);
    int n = B.size(), m = B[0].size(), source, destination, price;
    for(int i=0; i<n; i++)
    {
        source = B[i][0] - 1, destination = B[i][1] - 1, price = B[i][2];
        booking[source] += price;
        booking[destination+1] -= price;
    }
    for(int i=1; i<A; i++)
        booking[i] += booking[i-1];
    booking.pop_back();
    return booking;
}
