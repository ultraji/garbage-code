/*
1109. Group Photo (25)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
Formation is very important when taking a group photo. Given the rules of forming K rows with N people as the following:
* The number of people in each row must be N/K (round down to the nearest integer), with all the extra people (if any) standing in the last row;
* All the people in the rear row must be no shorter than anyone standing in the front rows;
* In each row, the tallest one stands at the central position (which is defined to be the position (m/2+1), where m is the total number of 
people in that row, and the division result must be rounded down to the nearest integer);
* In each row, other people must enter the row in non-increasing order of their heights, alternately taking their positions first to the right 
and then to the left of the tallest one (For example, given five people with their heights 190, 188, 186, 175, and 170, the final formation 
would be 175, 188, 190, 186, and 170. Here we assume that you are facing the group so your left-hand side is the right-hand side of the one 
at the central position.);
* When there are many people having the same height, they must be ordered in alphabetical (increasing) order of their names, and it is 
guaranteed that there is no duplication of names.
Now given the information of a group of people, you are supposed to write a program to output their formation.

Input Specification:
Each input file contains one test case. For each test case, the first line contains two positive integers N (<=10000), the total number of 
people, and K (<=10), the total number of rows. Then N lines follow, each gives the name of a person (no more than 8 English letters without 
space) and his/her height (an integer in [30, 300]).

Output Specification:
For each case, print the formation -- that is, print the names of people in K lines. The names must be separated by exactly one space, but 
there must be no extra space at the end of each line. Note: since you are facing the group, people in the rear rows must be printed above 
the people in the front rows.

Sample Input:
10 3
Tom 188
Mike 170
Eva 168
Tim 160
Joe 190
Ann 168
Bob 175
Nick 186
Amy 160
John 159

Sample Output:
Bob Tom Joe Nick
Ann Mike Eva
Tim Amy John

*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string row[10001];
struct stu{
    string name;
    int height;
    bool operator < (stu s) const {
        if(height == s.height)
            return name < s.name;
        return height > s.height;
    }
}s[10001];

int main(){
    int n,ki,t,r,m;
    cin >> n >> ki;
    t = n/ki;
    r = n%ki;
    for(int i = 0; i < n; i++){
        cin >> s[i].name >> s[i].height;
    }
    sort(s,s+n);
    for(int i = 0; i < n ; r--, i = i+m){
        m = t + (r>0?1:0);
        row[m/2+1] = s[i].name;
        for(int j=i+1,k=m/2; k >= 1; j=j+2, k--){
            row[k] = s[j].name;
        }
        for(int j=i+2,k=m/2+2; k <= m; j=j+2, k++){
            row[k] = s[j].name;
        }
        for(int j = 1; j <= m; j++ ){
            printf("%s%c",row[j].c_str(), (j==m)?'\n':' ');
        }
    }
    return 0;
}