/*
1132. Cut Integer (20)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
Cutting an integer means to cut a K digits long integer Z into two integers of (K/2) digits long integers A and B. For example, after cutting 
Z = 167334, we have A = 167 and B = 334. It is interesting to see that Z can be devided by the product of A and B, as 167334 / (167 x 334) = 3. Given an integer Z, you are supposed to test if it is such an integer.

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (<= 20). Then N lines follow, each gives an 
integer Z (10<=Z<=2^31). It is guaranteed that the number of digits of Z is an even number.

Output Specification:
For each case, print a single line "Yes" if it is such a number, or "No" if not.

Sample Input:
3
167334
2333
12345678

Sample Output:
Yes
No
No
*/

#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    string str;
    cin >> n;
    while(n--){
        cin >> str;
        int b = stoi(str.substr(0,str.size()/2));
        int c = stoi(str.substr(str.size()/2));
        if(c != 0 && stoi(str)%(b*c) == 0){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}