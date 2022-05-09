/*
1025. PAT Ranking (25)
时间限制
200 ms
内存限制
65536 kB
代码长度限制
16000 B
Programming Ability Test (PAT) is organized by the College of Computer Science and Technology of Zhejiang 
University. Each test is supposed to run simultaneously in several places, and the ranklists will be merged 
immediately after the test. Now it is your job to write a program to correctly merge all the ranklists and 
generate the final rank.

Input Specification:
Each input file contains one test case. For each case, the first line contains a positive number N (<=100), 
the number of test locations. Then N ranklists follow, each starts with a line containing a positive 
integer K (<=300), the number of testees, and then K lines containing the registration number (a 13-digit 
number) and the total score of each testee. All the numbers in a line are separated by a space.

Output Specification:
For each test case, first print in one line the total number of testees. Then print the final ranklist in 
the following format:
registration_number final_rank location_number local_rank
The locations are numbered from 1 to N. The output must be sorted in nondecreasing order of the final 
ranks. The testees with the same score must have the same rank, and the output must be sorted in 
nondecreasing order of their registration numbers.

Sample Input:
2
5
1234567890001 95
1234567890005 100
1234567890003 95
1234567890002 77
1234567890004 85
4
1234567890013 65
1234567890011 25
1234567890014 100
1234567890012 85

Sample Output:
9
1234567890005 1 1 1
1234567890014 1 2 1
1234567890001 3 1 2
1234567890003 3 1 2
1234567890004 5 1 4
1234567890012 5 2 2
1234567890002 7 1 5
1234567890013 8 2 3
1234567890011 9 2 4
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct testee{
    string num;
    int score;
    int loc;
    int local_rank;
    int final_rank;
    bool operator < (testee t) const {
        if(final_rank == t.final_rank){
            return num < t.num;
        }
        return final_rank < t.final_rank;
    }
}t[30001];
int f_r[101] = {0},l_r[301][101];

int main(){
    int n,k = 0,score,total = 0;
    string num;
    //freopen("in/in.txt","r",stdin);
    cin >> n;
    int j = 0;
    for(int i = 1; i <= n; i++){
        cin >> k;
        total += k;
        for(; j < total; j++){
            cin >> num >> score;
            l_r[i][score] ++;
            f_r[score] ++;
            t[j] = {num,score,i,0,0};
        }
    }
    for(int i = 0; i < total; i++){
        int fr  = 1,lr = 1;
        for(int s = 100; s>t[i].score; s--){
            fr += f_r[s];
            lr += l_r[t[i].loc][s];
        }
        t[i].final_rank = fr;
        t[i].local_rank = lr;
    }
    sort(t,t+total);
    cout << total << endl;
    for(int i = 0; i < total; i++){
        cout << t[i].num << ' ' << t[i].final_rank << ' ' << t[i].loc << ' ' << t[i].local_rank << endl;
    }
    return 0;
}