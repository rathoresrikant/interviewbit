/*
Largest Coprime Divisor
Problem Description
You are given two positive numbers A and B . You need to find the maximum valued integer X such that:
X divides A i.e. A % X = 0
X and B are co-prime i.e. gcd(X, B) = 1



Problem Constraints
1 <= A,B <= 109


Input Format
First argument is an integer A.
Second argument is an integer B.


Output Format
Return an integer maximum value of X as descibed above.


Example Input
 A=30, B=12


Example Output
 5


Example Explanation
 All divisors of A are (1,2,3,5,6,10,15,30).
 The maximum value is 5 such that A%5==0 and gcd(5,12)=1
*/
int Solution::cpFact(int A, int B) {
    /*
    int n = max(A, B);
    if(__gcd(A,B) == 1)
        return A;
    vector <int > sieve(n+1, 0), spf(n+1);
    for(int i=1; i<=n; i++)
        spf[i] = i;
    sieve[1] = 1;
    for(int i=2; i*i <= n; i++)
    {
        if(sieve[i] == 0)
        {
            for(int j = i; i*j <= n; j++)
            {
                if(sieve[i*j] == 0)
                {
                    sieve[i*j] = 1;
                    spf[i*j] = i;
                }
            }
        }
    }
    vector <int> arr;
    map <int, int> mp;
    while( A != 1)
    {
        if(mp[spf[A]] == 0)
            arr.push_back(spf[A]);
        mp[spf[A]]++;
        A = A/spf[A];
    }
    while( B != 1)
    {
        mp[spf[B]] = 0;
        B = B/spf[B];
    }
    */
    if(__gcd(A,B) == 1)
        return A;
    vector <int> arr;
    map <int, int> mp;
    // Prime factorization of A
    while (A % 2 == 0)
    {
        if(mp[2] == 0)
            arr.push_back(2);
        mp[2]++;
        A = A/2;
    }
    for (int i = 3; i <= sqrt(A); i = i + 2)
    {
        while (A % i == 0)
        {
            if(mp[i] == 0)
                arr.push_back(i);
            mp[i]++;;
            A = A/i;
        }
    }
    if (A > 2)
    {
        if(mp[A] == 0)
        arr.push_back(A);
        mp[A]++;
    }

    // Prime factorization of B
    while (B % 2 == 0)
    {
        mp[2] = 0;
        B = B/2;
    }
    for (int i = 3; i <= sqrt(B); i = i + 2)
    {
        while (B % i == 0)
        {
            mp[i] = 0;
            B = B/i;
        }
    }
    if (B > 2)
        mp[B] = 0;
    int ans = 1;
    for(int i=0; i<arr.size(); i++)
        ans = ans * pow(arr[i],mp[arr[i]]);
    return ans;
}
