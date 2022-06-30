/*
1007. Maximum Subsequence Sum (25)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
Given a sequence of K integers { N1, N2, ..., NK }. A continuous subsequence is defined to be { Ni, 
Ni+1, ..., Nj } where 1 <= i <= j <= K. The Maximum Subsequence is the continuous subsequence which has 
the largest sum of its elements. For example, given sequence { -2, 11, -4, 13, -5, -2 }, its maximum 
subsequence is { 11, -4, 13 } with the largest sum being 20.
Now you are supposed to find the largest sum, together with the first and the last numbers of the 
maximum subsequence.

Input Specification:
Each input file contains one test case. Each case occupies two lines. The first line contains a positive 
integer K (<= 10000). The second line contains K numbers, separated by a space.

Output Specification:
For each test case, output in one line the largest sum, together with the first and the last numbers of 
the maximum subsequence. The numbers must be separated by one space, but there must be no extra space 
at the end of a line. In case that the maximum subsequence is not unique, output the one with the 
smallest indices i and j (as shown by the sample case). If all the K numbers are negative, then its 
maximum sum is defined to be 0, and you are supposed to output the first and the last numbers of the 
whole sequence.

Sample Input:
10
-10 1 2 3 4 -5 -23 3 7 -21

Sample Output:
10 1 4
*/

#include <iostream>
using namespace std;
const int maxn = 10001;
int a[maxn];
int main(){
    int n,sum = 0,max_sum = 0,start = 0,end,ps = 0,pe = 0;
    //freopen("in/in.txt","r",stdin);
    cin >> n;
    end = n-1;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(sum > 0){
            sum += a[i];
            pe = i;
        }else{
            sum = a[i];
            ps = i;
            pe = i;
        }
        if(sum > max_sum || (sum == 0 && end == n-1)){
            max_sum = sum;
            start = ps;  //当最大和更新时，同时更新start值
            end = pe;
        }
    }
    printf("%d %d %d\n",max_sum,a[start],a[end]);
    return 0;
}