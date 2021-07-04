/*
1096. Consecutive Factors (20)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
Among all the factors of a positive integer N, there may exist several consecutive numbers. For example, 630 can be factored as 3*5*6*7, 
where 5, 6, and 7 are the three consecutive numbers. Now given any positive N, you are supposed to find the maximum number of consecutive 
factors, and list the smallest sequence of the consecutive factors.

Input Specification:
Each input file contains one test case, which gives the integer N (1<N<2^31).

Output Specification:
For each test case, print in the first line the maximum number of consecutive factors. Then in the second line, print the smallest sequence 
of the consecutive factors in the format "factor[1]*factor[2]*...*factor[k]", where the factors are listed in increasing order, and 1 is NOT 
included.

Sample Input:
630

Sample Output:
3
5*6*7
*/

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
vector<int> v,r;
int main(){
    int n, m, maxSize = 0;
    cin >> n;
    m = n;
    for(int i = 2; i <= sqrt(n)+3; i++){    //超过sqrt(n) 只可能出现最长为1的
        if(m >= i && m%i == 0){
            v.push_back(i);
            m /= i;
        }else{
            if(v.size() > 0) i = v[0];
            if(v.size() > maxSize){
                maxSize = v.size();
                r.swap(v);
            }
            v.clear();
            m = n;
        }
    }
    if(maxSize != 0){
        printf("%d\n",maxSize);
        for(int i = 0; i < maxSize; i++){
            printf("%d%c", r[i], (i==maxSize-1)?'\n':'*');
        }
    }else{
        printf("1\n%d", n);
    }
    return 0;
}