/*
1103. Integer Factorization (30)
时间限制
1200 ms
内存限制
65536 kB
代码长度限制
16000 B
The K-P factorization of a positive integer N is to write N as the sum of the P-th power of K positive integers. You are supposed to write a 
program to find the K-P factorization of N for any positive integers N, K and P.

Input Specification:
Each input file contains one test case which gives in a line the three positive integers N (<=400), K (<=N) and P (1<P<=7). The numbers in a 
line are separated by a space.

Output Specification:
For each case, if the solution exists, output in the format:
N = n1^P + ... nK^P
where ni (i=1, ... K) is the i-th factor. All the factors must be printed in non-increasing order.

Note: the solution may not be unique. For example, the 5-2 factorization of 169 has 9 solutions, such as 12^2 + 4^2 + 2^2 + 2^2 + 1^2, 
or 11^2 + 6^2 + 2^2 + 2^2 + 2^2, or more. You must output the one with the maximum sum of the factors. If there is a tie, the largest 
factor sequence must be chosen -- sequence { a1, a2, ... aK } is said to be larger than { b1, b2, ... bK } if there exists 1<=L<=K such 
that ai=bi for i<L and aL>bL
If there is no solution, simple output "Impossible".

Sample Input 1:
169 5 2
Sample Output 1:
169 = 6^2 + 6^2 + 6^2 + 6^2 + 5^2

Sample Input 2:
169 167 3
Sample Output 2:
Impossible
*/

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
vector<int> v, r;
int powArr[400];
int n, k, p ,maxSum = -1;
void findFactor(int st, int nt, int kt, int maxSumt){
    if( nt == n && kt == k ){
        if(maxSumt > maxSum){
            r = v;
            maxSum = maxSumt;
        }
        return;
    }
    if(nt > n || kt > k ) return;
    for( ;st >= 1; st--){
        v.push_back(st);
        findFactor(st, nt+powArr[st], kt+1, maxSumt+st);
        v.pop_back();
    }

}

int main(){
    int st, nt = 0, kt = 0, maxSumt = 0;
    cin >> n >> k >> p;
    for(st = 1; powArr[st-1] < n; st++){
        powArr[st] = pow(st, p) + 0.1;       //蜜汁bug  //pow(5,2) =(int)=> 24
    }
    st--;
    findFactor(st, nt, kt, maxSumt);
    if(!r.empty()){
        printf("%d = %d^%d", n, r[0], p);
        for(int i = 1; i < r.size(); i++){
            printf(" + %d^%d", r[i], p);
        }
    }else{
        printf("Impossible");
    }
    return 0;
}