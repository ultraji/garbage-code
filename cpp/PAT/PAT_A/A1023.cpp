/*
1023. Have Fun with Numbers (20)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
Notice that the number 123456789 is a 9-digit number consisting exactly the numbers from 1 to 9, with no 
duplication. Double it we will obtain 246913578, which happens to be another 9-digit number consisting 
exactly the numbers from 1 to 9, only in a different permutation. Check to see the result if we double it 
again!
Now you are suppose to check if there are more numbers with this property. That is, double a given number 
with k digits, you are to tell if the resulting number consists of only a permutation of the digits in the 
original number.

Input Specification:
Each input file contains one test case. Each case contains one positive integer with no more than 20 digits.

Output Specification:

For each test case, first print in a line "Yes" if doubling the input number gives a number that consists 
of only a permutation of the digits in the original number, or "No" if not. Then in the next line, print 
the doubled number.

Sample Input:
1234567899
Sample Output:
Yes
2469135798
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int mp[2][10];

int main(){
    bool flag = true;
    int sl,c;
    char a[23];
    fill(mp[0],mp[0]+20,0);
    //freopen("in/in.txt","r",stdin);
    gets(a);
    sl = strlen(a);
    reverse(a,a+sl);
    c = 0;
    for(int i = 0; i < sl; i++){
        mp[0][a[i]-'0'] ++;
        a[i] = (a[i]-'0')*2 + c;
        c = a[i]/10;
        a[i] = a[i]%10 + '0';
    }
    if(c != 0){
         a[sl] = c + '0';
         sl += 1;
         a[sl] = '\0';
         flag = false;
    }
    reverse(a,a+sl);
    if(flag){
        for(int i = 0; i < sl; i++) mp[1][a[i]-'0'] ++;
        for(int i = 0; i < 10; i++){
            if(mp[0][i] != mp[1][i]){
                flag = false;
                break;
            }
        }
    }
    if(flag){
        puts("Yes");
    }else{
        puts("No");
    }
    puts(a);
    return 0;
}