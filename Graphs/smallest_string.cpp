/*
Smallest String
You are given a string A of length N which consists of digits from 0 to 9 and two integer B and C. There are two operations which you can do on a string.
Rotate
Add
You can use Rotate operation to rotate a string clockwise by B positions. For example if B=1 , string "581" will become "158" .
Also you can use Add operation to add number C to all odd indexes of string ( 0 based indexing). For example if C=3 , then string "781" will become "711". Digits post 9 are cycled back to zero. You can use any of the two operation any number of times in any order to return the lexicographical smallest string. Input Format
The first given argument is string A
The second given argument integar B
The third given argument is integar C
Output Format
Return the lexicographical smallest string.
Constraints
0<N<10

0<=C<100

1<=B<=N
For example
A="31"
B=1
C=4
Result: "11"
*/
string rotate(string str, int k)
{
    int m = str.length();
    if(m == k)
        return str;
    string res = "";
    for(int i=m-k; i<m; i++)
        res.push_back(str[i]);
    for(int i=0; i<m-k; i++)
        res.push_back(str[i]);
    return res;
}

string add(string str, int k)
{
    int m = str.length();
    for(int i=0; i<m; i++)
    {
        if(i%2 == 1)
        {
            str[i] = (str[i]-'0' + k)%10 + '0';
        }
    }
    return str;
}

string Solution::SmallestString(string A, int B, int C)
{
    queue <string> q;
    set <string> s;
    q.push(A);
    s.insert(A);
    while(!q.empty())
    {
        string curr = q.front();
        q.pop();
        string first = rotate(curr, B);
        if(s.find(first) == s.end())
        {
            q.push(first);
            s.insert(first);
        }
        string second = add(curr, C);
        if(s.find(second) == s.end())
        {
            q.push(second);
            s.insert(second);
        }
    }
    return *s.begin();
}
