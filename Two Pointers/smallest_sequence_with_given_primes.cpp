/*
Smallest sequence with given Primes
Given three prime number(p1, p2, p3) and an integer k. Find the first(smallest) k integers which have only p1, p2, p3 or a combination of them as their prime factors. Example: Input :
Prime numbers : [2,3,5]
k : 5 If primes are given as p1=2, p2=3 and p3=5 and k is given as 5, then the sequence of first 5 integers will be:
 Output:
{2,3,4,5,6} Explanation :
4 = p1 * p1 ( 2 * 2 ) 6 = p1 * p2 ( 2 * 3 ) Note: The sequence should be sorted in ascending order
*/
vector<int> Solution::solve(int A, int B, int C, int D) {
    int i = 0,  j = 0, k = 0, a, b, c, minm, n;
    vector <int> arr;
    arr.push_back(1);
    while(D > 0)
    {
        a = A*arr[i], b = B*arr[j], c = C*arr[k];
        minm = min(a,min(b,c));
        n = arr.size() - 1;
        if(minm == a)
        {
            if(arr[n] != minm)
            {
                arr.push_back(minm);
                D--;
            }
            i++;
        }
        else
        if(minm == b)
        {
            if(arr[n] != minm)
            {
                arr.push_back(minm);
                D--;
            }
            j++;
        }
        else
        if(minm == c)
        {
            if(arr[n] != minm)
            {
                D--;
                arr.push_back(minm);
            }
            k++;
        }
    }
    n = arr.size();
    for(int i=0; i<n-1; i++)
    arr[i] = arr[i+1];
    arr.pop_back();
    return arr;


}
