/*
Day of the week
Given three integers A, B and C, find and return the day of the week for the given date A/B/C where A represents the date, B represents the month and C represents the year. Assume that Jan 1st 1 AD is a Monday in Gregorian calendar. February has 28 days(excluding leap years when it has 29 days). Leap year is a year that is either (divisible by 400) or (divisible by 4 and not divisible by 100).
Input Format
The 3 arguments given are the integers A, B and C.
Output Format
Return the day of the year as a string of lower case english alphabets.
Answer will be one of the following {sunday, monday, tuesday, wednesday, thursday, friday, saturday}.
Constraints
1 <= A <= 31
1 <= B <= 12
1990 <= C <= 2100
For Example
Input 1:
    A = 19
    B = 4
    C = 2019
Output 1:
    friday

Input 2:
    A = 7
    B = 10
    C = 1996
Output 2:
    monday
*/
string Solution::solve(int A, int B, int C) {
    string res[] = {"sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday"};
    int day[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    C -= B < 3;
    int days = C + C/4 - C/100 + C/400 + day[B-1] + A;
    return res[days%7];
}
