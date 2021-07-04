/*
1012. The Best Rank (25)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
To evaluate the performance of our first year CS majored students, we consider their grades of three 
courses only: C - C Programming Language, M - Mathematics (Calculus or Linear Algebra), and E - English. 
At the mean time, we encourage students by emphasizing on their best ranks -- that is, among the four 
ranks with respect to the three courses and the average grade, we print the best rank for each student.
For example, The grades of C, M, E and A - Average of 4 students are given as the following:
StudentID  C  M  E  A
310101     98 85 88 90
310102     70 95 88 84
310103     82 87 94 88
310104     91 91 91 91
Then the best ranks for all the students are No.1 since the 1st one has done the best in C Programming 
Language, while the 2nd one in Mathematics, the 3rd one in English, and the last one in average.

Input
Each input file contains one test case. Each case starts with a line containing 2 numbers N and M 
(<=2000), which are the total number of students, and the number of students who would check their 
ranks, respectively. Then N lines follow, each contains a student ID which is a string of 6 digits,
 followed by the three integer grades (in the range of [0, 100]) of that student in the order of C, 
M and E. Then there are M lines, each containing a student ID.

Output
For each of the M students, print in one line the best rank for him/her, and the symbol of the 
corresponding rank, separated by a space.The priorities of the ranking methods are ordered as 
A > C > M > E. Hence if there are two or more ways for a student to obtain the same best rank, output 
the one with the highest priority.
If a student is not on the grading list, simply output "N/A".

Sample Input
5 6
310101 98 85 88
310102 70 95 88
310103 82 87 94
310104 91 91 91
310105 85 90 90
310101
310102
310103
310104
310105
999999

Sample Output
1 C
1 M
1 E
1 A
3 A
N/A
*/

#include <iostream>
#include <map>
using namespace std;
const char clas[4] = {'A','C','M','E'};
int dp[4][101]={0}; //用来记录每科的各个分数的人数,从100往下加到某人的分数(如 99)时，即排名为 1+dp[100]+dp[99]+dp[98]
struct student{
    int id;
    int sco[4];
    int rank[4];
}s[2001];

int main(){
    int n1,n2,id,c,m,e,a;
    map<int,pair<int,char> > mp;
    //freopen("in/in.txt","r",stdin);
    scanf("%d %d",&n1,&n2);
    for(int i = 0; i < n1; i++){
        scanf("%d %d %d %d",&id,&c,&m,&e);
        a = (c+m+e+1)/3;
        dp[0][a] ++;
        dp[1][c] ++;
        dp[2][m] ++;
        dp[3][e] ++;
        s[i] = {id,a,c,m,e,1,1,1,1};
    }
    for(int i = 0; i < n1; i++){
        int best = 2001,cla;
        for(int j = 0; j < 4; j++){
            for(int k = 100; k > s[i].sco[j]; k--)
                s[i].rank[j] += dp[j][k];
            if(best > s[i].rank[j]){
                best = s[i].rank[j];
                cla = j;
            }
        }
        mp[s[i].id] = make_pair(best,clas[cla]);    //记录当前学生的最好排名和科目
    }
    for(int i = 0; i < n2; i++){
        scanf("%d",&id);
        if(mp.find(id) == mp.end()) printf("N/A\n");
        else printf("%d %c\n",mp[id].first,mp[id].second);
    }
    return 0;
}