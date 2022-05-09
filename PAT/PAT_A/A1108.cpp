/*
1108. Finding Average (20)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
The basic task is simple: given N real numbers, you are supposed to calculate their average. But what makes it complicated is that some of 
the input numbers might not be legal. A "legal" input is a real number in [-1000, 1000] and is accurate up to no more than 2 decimal places. 
When you calculate the average, those illegal numbers must not be counted in.

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (<=100). Then N numbers are given in the 
next line, separated by one space.

Output Specification:
For each illegal input number, print in a line "ERROR: X is not a legal number" where X is the input. Then finally print in a line the 
result: "The average of K numbers is Y" where K is the number of legal inputs and Y is their average, accurate to 2 decimal places. In case 
the average cannot be calculated, output "Undefined" instead of Y. In case K is only 1, output "The average of 1 number is Y" instead.

Sample Input 1:
7
5 -3.2 aaa 9999 2.3.4 7.123 2.35
Sample Output 1:
ERROR: aaa is not a legal number
ERROR: 9999 is not a legal number
ERROR: 2.3.4 is not a legal number
ERROR: 7.123 is not a legal number
The average of 3 numbers is 1.38

Sample Input 2:
2
aaa -9999
Sample Output 2:
ERROR: aaa is not a legal number
ERROR: -9999 is not a legal number
The average of 0 numbers is Undefined
*/

#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int n, cnt = 0;
    char s1[100],s2[100];
    double result = 0,tmp;
    scanf("%d",&n);
    while(n--){
        bool flag = true;
        scanf("%s ",s1);
        sscanf(s1,"%lf",&tmp);
        sprintf(s2,"%.2lf",tmp);
        for(int i = 0; i < strlen(s1); i++){
            if(s1[i] != s2[i]) flag = false;
        }
        if(!flag || (tmp > 1000 || tmp < -1000)) flag = false;
        if(flag){
            result += tmp;
            cnt ++;
        }else{
            printf("ERROR: %s is not a legal number\n", s1);
        }
    }
    if(cnt != 0){
        printf("The average of %d number%sis %.2lf", cnt, cnt == 1?" ":"s ", result/cnt);
    }else{
        printf("The average of 0 numbers is Undefined");
    }
    return 0;
}