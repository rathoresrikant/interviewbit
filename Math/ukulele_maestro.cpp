/*
Ukulele Maestro
Rishik has a very special Ukulele with A frets. He can use atmost 4 fingers to play a chord. Find total number of different chords Rishik can play mod 1000000007. Two chords are different if one of the fret that is pressed in one of the chord is not pressed in other chord. Note: 1 finger can press atmost 1 fret at a time.
Input Format:
    First argument contains single integer A.
Output Format:
    Return a single integer containing total number of chords mod 1000000007.
Constraints:
    1 <= A <= 10^9
For Example:
Example Input 1:
    A = 2
Example Output 1:
    4
Example Explanation 1:
    Chords are = [{}, {1}, {1,2}, {2}]
Input 2:
    A = 6
Output 2:
    57
*/
int Solution::solve(int A) {
    unsigned long long num = A;
    unsigned long long MOD = 1e9 + 7;
    unsigned long long res = (num + 1)%MOD;
    unsigned long long one, two , three;
    if(A <= 4)
        return pow(2, A);
    unsigned long long a = 500000004, b = 166666668, c = 41666667;
    one = (num*(num-1))%MOD;
    two = (one*(num-2))%MOD;
    three = (two*(num-3))%MOD;
    res = (res%MOD + (one*a)%MOD)%MOD;
    res = (res%MOD + (two*b)%MOD)%MOD;
    res = (res%MOD + (three*c)%MOD)%MOD;
    return res%MOD;
}
