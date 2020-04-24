/*
Letter Phone
Given a digit string, return all possible letter combinations that the number could represent. A mapping of digit to letters (just like on the telephone buttons) is given below.  The digit 0 maps to 0 itself. The digit 1 maps to 1 itself.
Input: Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Make sure the returned strings are lexicographically sorted.
*/
void fun(map <char, string> &phone, string digits, vector <string> &res, string str, int i)
{
    if(i == digits.length())
    {
        res.push_back(str);
        return;
    }
    string temp = phone[digits[i]];
    for(int j=0; j<temp.length();j++)
    {
        str.push_back(temp[j]);
        fun(phone, digits, res, str, i+1);
        str.pop_back();
    }
}
vector<string> Solution::letterCombinations(string digits)
{
    map <char, string> phone = {{'0',"0"},{'1',"1"},{'2',"abc"}, {'3',"def"}, {'4',"ghi"},{'5',"jkl"}, {'6',"mno"}, {'7',"pqrs"}, {'8',"tuv"}, {'9',"wxyz"}};
    vector <string> res;
    if(digits.length() == 0)
        return res;
    string str = "";
    fun(phone, digits, res, str, 0);
    return res;
}
