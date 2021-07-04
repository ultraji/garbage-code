/*
1038. Recover the Smallest Number (30)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
Given a collection of number segments, you are supposed to recover the smallest number from them. For example, given {32, 321, 3214, 
0229, 87}, we can recover many numbers such like 32-321-3214-0229-87 or 0229-32-87-321-3214 with respect to different orders of 
combinations of these segments, and the smallest number is 0229-321-3214-32-87.

Input Specification:
Each input file contains one test case. Each case gives a positive integer N (<=10000) followed by N number segments. Each segment 
contains a non-negative integer of no more than 8 digits. All the numbers in a line are separated by a space.

Output Specification:
For each test case, print the smallest number in one line. Do not output leading zeros.

Sample Input:
5 32 321 3214 0229 87

Sample Output:
22932132143287
*/

#include <iostream>
#include <algorithm>
using namespace std;
string s[10001];
bool cmp(string &s1,string &s2){
    return s1+s2 < s2+s1;
}

int main(){
    int n;
    string r;
    //freopen("in/in.txt","r",stdin);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    sort(s,s+n,cmp);
    for(int i = 0; i < n; i++){
        r += s[i];
    }
    while(r[0] == '0') r.erase(0,1);
    if(r == "") printf("0");
    else cout << r;
    return 0;
}