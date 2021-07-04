/*
1012. 数字分类 (20)
时间限制 100 ms
内存限制 65536 kB
代码长度限制 8000 B

给定一系列正整数，请按要求对数字进行分类，并输出以下5个数字：
A1 = 能被5整除的数字中所有偶数的和；
A2 = 将被5除后余1的数字按给出顺序进行交错求和，即计算n1-n2+n3-n4...；
A3 = 被5除后余2的数字的个数；
A4 = 被5除后余3的数字的平均数，精确到小数点后1位；
A5 = 被5除后余4的数字中最大数字。

输入格式：
每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N，随后给出N个不超过1000的待分
类的正整数。数字间以空格分隔。

输出格式：
对给定的N个正整数，按题目要求计算A1~A5并在一行中顺序输出。数字间以空格分隔，但行末不得有多余空格。
若其中某一类数字不存在，则在相应位置输出“N”。

输入样例1：
13 1 2 3 4 5 6 7 8 9 10 20 16 18
输出样例1：
30 11 2 9.7 9

输入样例2：
8 1 2 4 5 6 7 9 16
输出样例2：
N 11 2 N 9
*/

#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int num, N, num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0,cnt2 = 0,cnt4 = 0;
    double aver;
    scanf("%d",&N);
    while(N--){
        scanf("%d",&num);
        switch(num % 5){
            case 0:
                if(num % 2 == 0){
                    num1 += num;
                }
                break;
            case 1:
                if(cnt2++ % 2 == 0){
                    num2 += num;
                }else{
                    num2 -= num;
                }
                break;
            case 2:
                num3 ++;
                break;
            case 3:
                num4 += num;
                cnt4 ++;
                break;
            case 4:
                num5 = max(num,num5);
                break;
        }
    }
    if(cnt4 != 0){
        aver =1.0 * num4 / cnt4;
    }
    if(num1 != 0) 
        printf("%d ",num1);
    else 
        printf("N ");
    if(cnt2 != 0) 
        printf("%d ",num2);
    else 
        printf("N ");
    if(num3 != 0)
        printf("%d ",num3);
    else
        printf("N ");
    if(cnt4 != 0)
        printf("%.1f ",aver);
    else
        printf("N ");
    if(num5 != 0)
        printf("%d",num5);
    else
        printf("N");
    return 0;
}