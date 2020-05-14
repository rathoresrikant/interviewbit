/*
Clean Code
Given a C++ code. You have to clean the code in following manner.
Remove the comments from the code
Remove the empty lines, i.e lines with spaces, tabs and new line character only.
Print the code after cleaning it. Note: In C++ multiline comments start with /* and end with */ and single line comments start with //.
*/
/*
 Input Format
First line contains the integer N, number of lines of codes.
Next N lines contains the string, where each line represents a C++ code line.
Output Format
You have to print the M lines of C++ code after removing the comments and empty lines.
Constraints
1 <= N <= 100000
0 <= length of each line <= 100
Test Case 1
Input:

    5
    #include<iostrem>
    int main() {
        //hello world
        return 0;
    }

Output:

    #include<iostrem>
    int main() {
        return 0;
      }
*/
