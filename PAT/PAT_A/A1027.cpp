/*
1027. Colors in Mars (20)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
People in Mars represent the colors in their computers in a similar way as the Earth people. That is, a color is represented by a 
6-digit number, where the first 2 digits are for Red, the middle 2 digits for Green, and the last 2 digits for Blue. The only 
difference is that they use radix 13 (0-9 and A-C) instead of 16. Now given a color in three decimal numbers (each between 0 and 
168), you are supposed to output their Mars RGB values.

Input
Each input file contains one test case which occupies a line containing the three decimal color values.

Output
For each test case you should output the Mars RGB value in the following format: first output "#", then followed by a 6-digit number 
where all the English characters must be upper-cased. If a single color is only 1-digit long, you must print a "0" to the left.

Sample Input
15 43 71

Sample Output
#123456
*/

#include <iostream>
#include <string>
using namespace std;
const char tr[17] = "0123456789ABCDEF";

void transfer(int num,string &m){
    char a[3] = {'\0'};
    a[0] = tr[num/13];
    a[1] = tr[num%13];
    m = a;

}

int main(){
    int r1,g1,b1;
    string r2="",g2="",b2="";
    cin >> r1 >> g1 >> b1;
    transfer(r1,r2);
    transfer(g1,g2);
    transfer(b1,b2);
    cout << '#' << r2 << g2 << b2 << endl;
    return 0;
}