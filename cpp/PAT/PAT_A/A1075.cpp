/*
1075. PAT Judge (25)
时间限制
200 ms
内存限制
65536 kB
代码长度限制
16000 B
The ranklist of PAT is generated from the status list, which shows the scores of the submittions. This time you are supposed to generate the 
ranklist for PAT.

Input Specification:
Each input file contains one test case. For each case, the first line contains 3 positive integers, N (<=104), the total number of users, 
K (<=5), the total number of problems, and M (<=10^5), the total number of submittions. It is then assumed that the user id's are 5-digit 
numbers from 00001 to N, and the problem id's are from 1 to K. The next line contains K positive integers p[i] (i=1, ..., K), where p[i] 
corresponds to the full mark of the i-th problem. Then M lines follow, each gives the information of a submittion in the following format:
user_id problem_id partial_score_obtained
where partial_score_obtained is either -1 if the submittion cannot even pass the compiler, or is an integer in the range [0, p[problem_id]]. 
All the numbers in a line are separated by a space.

Output Specification:
For each test case, you are supposed to output the ranklist in the following format:
rank user_id total_score s[1] ... s[K]
where rank is calculated according to the total_score, and all the users with the same total_score obtain the same rank; and s[i] is the 
partial score obtained for the i-th problem. If a user has never submitted a solution for a problem, then "-" must be printed at the 
corresponding position. If a user has submitted several solutions to solve one problem, then the highest score will be counted.
The ranklist must be printed in non-decreasing order of the ranks. For those who have the same rank, users must be sorted in nonincreasing 
order according to the number of perfectly solved problems. And if there is still a tie, then they must be printed in increasing order of 
their id's. For those who has never submitted any solution that can pass the compiler, or has never submitted any solution, they must NOT 
be shown on the ranklist. It is guaranteed that at least one user can be shown on the ranklist.

Sample Input:
7 4 20
20 25 25 30
00002 2 12
00007 4 17
00005 1 19
00007 2 25
00005 1 20
00002 2 2
00005 1 15
00001 1 18
00004 3 25
00002 2 25
00005 3 22
00006 4 -1
00001 2 18
00002 1 20
00004 1 15
00002 4 18
00001 3 4
00001 4 2
00005 2 -1
00004 2 0

Sample Output:
1 00002 63 20 25 - 18
2 00005 42 20 0 22 -
2 00007 42 - 25 - 17
2 00001 42 18 18 4 2
5 00004 40 15 0 25 -
*/

//s.g[0]    ->  总分
//s.n       ->  完全解决的题数

// 各题分数：
//  -2      表示为无任何提交
//  -1      表示为提交的代码编译不通过
//  >= 0    表示为有效提交

//总分为-1时，表示为该用户无任何有效提交。

//rk[i] 表示 分数为i的人数；
//故 r = r[100]+...+r[i+1] 表示比分数i高的人数有r人，即分数为i的学生排名为r+1；

//容易出错点:只要有有效提交，就应该被输出，包括(总分得0分的人)。
#include <iostream>
#include <algorithm>
using namespace std;
int p[6], rk[101], r = 1, st = 100;
struct student{
    int id, g[6], n;
    bool operator < (student s) const {
        if(g[0] == s.g[0]){
            if(n == s.n){
                return id < s.id;
            }
            return n > s.n;
        }
        return g[0] > s.g[0];
    }
}s[100001];

int main(){
    int n, k, m, id, pi, g;
    //freopen("in/in.txt","r",stdin);
    scanf("%d %d %d",&n, &k, &m);
    for(int i = 1; i <= k; i++){
        scanf("%d", &p[i]);
    }
    for(int i = 0; i <= n; i++){
        s[i].id = i;
        for(int j = 1; j <= k; j++)     //默认总分为0分
            s[i].g[j] = -2;             //初始化每道题都为无任何提交状态
    }
    while(m--){
        scanf("%d %d %d", &id, &pi, &g);
        if(g > s[id].g[pi]){
            s[id].g[pi] = g;
            if(s[id].g[pi] == p[pi]) s[id].n ++;
        }
    }
    for(int i = 1; i <= n; i++){
        int cnt = 0;
        for(int j = 1; j <= k; j++){
            if(s[i].g[j] >= 0){
                s[i].g[0] += s[i].g[j];
                cnt ++;
            }
        }
        if(cnt){
            rk[s[i].g[0]] ++;
        }else{
            s[i].g[0] = -1; //cnt 为 0 时 表示成绩全为 -1 或 -2;
        }
    }
    sort(s+1,s+n+1);
    for(int i = 1; i <= n; i++){
        if(s[i].g[0] != -1){
            for(; st > s[i].g[0]; st--) r += rk[st];
            printf("%d %05d", r, s[i].id);
            for(int j = 0; j <= k; j++){
                if(s[i].g[j] != -2 ){
                    printf(" %d",(s[i].g[j]==-1)? 0 : s[i].g[j]);
                }else{
                    printf(" -");
                }
            }
            printf("\n");
        }
    }
    return 0;
}