/*
1051. Pop Sequence (25)
时间限制
100 ms
内存限制
65536 kB
代码长度限制
16000 B
Given a stack which can keep M numbers at most. Push N numbers in the order of 1, 2, 3, ..., N and pop 
randomly. You are supposed to tell if a given sequence of numbers is a possible pop sequence of the 
stack. For example, if M is 5 and N is 7, we can obtain 1, 2, 3, 4, 5, 6, 7 from the stack, but not 
3, 2, 1, 7, 5, 6, 4.

Input Specification:
Each input file contains one test case. For each case, the first line contains 3 numbers (all no more 
than 1000): M (the maximum capacity of the stack), N (the length of push sequence), and K (the number 
of pop sequences to be checked). Then K lines follow, each contains a pop sequence of N numbers. All 
the numbers in a line are separated by a space.

Output Specification:
For each pop sequence, print in one line "YES" if it is indeed a possible pop sequence of the stack, 
or "NO" if not.

Sample Input:
5 7 5
1 2 3 4 5 6 7
3 2 1 7 5 6 4
7 6 5 4 3 2 1
5 6 4 3 7 2 1
1 7 6 5 4 3 2

Sample Output:
YES
NO
NO
YES
NO
*/

#include <iostream>
using namespace std;
const int MAXN = 1001;
int mp[MAXN];

int main(){
    int cap,n,k,a[MAXN];
    //freopen("in/in.txt","r",stdin);
    cin >> cap >> n >> k;
    while(k--){
        bool flag =  true;
        int maxcap = 1;
        fill(mp,mp+n+1,1);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            for(int j = i-1; j > 0; j--){
                if(a[i] < a[j]){
                    mp[i] = max(mp[j]+1,mp[i]);
                }
            }
            maxcap = max(maxcap,mp[i]);
            if(i-2 >= 0 && a[i-2] > a[i] && a[i] > a[i-1]){
                flag = false;
            }
        }
        if(flag && maxcap <= cap){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}