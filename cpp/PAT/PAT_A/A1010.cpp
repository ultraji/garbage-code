/*
1010. Radix (25)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
Given a pair of positive integers, for example, 6 and 110, can this equation 6 = 110 be true? The answer 
is "yes", if 6 is a decimal number and 110 is a binary number.Now for any pair of positive integers N1 
and N2, your task is to find the radix of one number while that of the other is given.

Input Specification:
Each input file contains one test case. Each case occupies a line which contains 4 positive integers:
N1 N2 tag radix
Here N1 and N2 each has no more than 10 digits. A digit is less than its radix and is chosen from the 
set {0-9, a-z} where 0-9 represent the decimal numbers 0-9, and a-z represent the decimal numbers 10-35. 
The last number "radix" is the radix of N1 if "tag" is 1, or of N2 if "tag" is 2.

Output Specification:
For each test case, print in one line the radix of the other number so that the equation N1 = N2 is true. 
If the equation is impossible, print "Impossible". If the solution is not unique, output the smallest 
possible radix.

Sample Input 1:
6 110 1 10
Sample Output 1:
2

Sample Input 2:
1 ab 1 2
Sample Output 2:
Impossible
*/
#include <iostream>
#include <string>
using namespace std;

int myatoi(char a){
    if(a >= 'a') return a-'a'+10;
    return a - '0';
}

long long decode(string &str,long long redix){
    long long num = 0;
    for(int i = 0; i < str.size(); i++){
        num = num * redix + myatoi(str[i]);
        if(num < 0) return -1;
    }
    return num;
}

long long findRedix(string &str,long long num){
    long long right = num + 1,left = 0,mid,n;
    for(int i = 0; i < str.size(); i++) 
        if(left < myatoi(str[i])) left = myatoi(str[i]);
    left += 1;
    while(left <= right){
        mid = (left + right)/2;
        n = decode(str,mid);
        if( n == num) return mid;
        if( n > num || n == -1){
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    return -1;
}

int main(){
    string str1,str2;
    int tag,r = 0;
    long long num,redix;
    //freopen("in/in.txt","r",stdin);
    cin >> str1 >> str2 >> tag >> redix;
    if(tag == 2) str1.swap(str2);
    num = decode(str1,redix);
    r = findRedix(str2,num);
    if(r != -1) printf("%d\n",r);
    else printf("Impossible\n");
    return 0;
}