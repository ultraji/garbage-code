/*
1059. Prime Factors (25)
时间限制
100 ms
内存限制
65536 kB
代码长度限制
16000 B
Given any positive integer N, you are supposed to find all of its prime factors, and write them in the format N = p1^k1 * p2^k2 *…*pm^km.

Input Specification:
Each input file contains one test case which gives a positive integer N in the range of long int.

Output Specification:
Factor N in the format N = p1^k1 * p2^k2 *…*pm^km, where pi's are prime factors of N in increasing order, and the exponent ki is the number 
of pi -- hence when there is only one pi, ki is 1 and must NOT be printed out.

Sample Input:
97532468

Sample Output:
97532468=2^2*11*17*101*1291
*/

#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(){
    int n,num,cnt = 0;
    vector<pair<int,int> > pf;
    scanf("%d",&n);
    num = n;
    for(int i = 2; i <= num; i++){
        while(true){
            if(num%i == 0){
                cnt ++;
                num = num/i;
            }else{
                if(cnt != 0){
                    pf.push_back(make_pair(i,cnt));
                }
                cnt = 0;
                break;
            }
        }
    }
    if(n!=1){
        printf("%d=",n);
        num = pf.size()-1;
        for(int i = 0; i < num; i++){
            printf("%d",pf[i].first);
            if(pf[i].second != 1){
                printf("^%d",pf[i].second);
            }
            printf("*");
        }
        printf("%d",pf[num].first);
        if(pf[num].second != 1){
            printf("^%d",pf[num].second);
        }
    }else{
        printf("1=1");
    }
    return 0;
}