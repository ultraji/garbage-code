/*
1141 PAT Ranking of Institutions （25 分）
After each PAT, the PAT Center will announce the ranking of institutions based on their 
students' performances. Now you are asked to generate the ranklist.

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive 
integer N (≤10^5), which is the number of testees. Then N lines follow, each gives the 
information of a testee in the following format:

ID Score School
where ID is a string of 6 characters with the first one representing the test level: 
B stands for the basic level, A the advanced level and T the top level; Score is an integer 
in [0, 100]; and School is the institution code which is a string of no more than 6 English 
letters (case insensitive). Note: it is guaranteed that ID is unique for each testee.

Output Specification:
For each case, first print in a line the total number of institutions. Then output the 
ranklist of institutions in nondecreasing order of their ranks in the following format:
Rank School TWS Ns
where Rank is the rank (start from 1) of the institution; School is the institution code 
(all in lower case); ; TWS is the total weighted score which is defined to be the integer 
part of ScoreB/1.5 + ScoreA + ScoreT*1.5, where ScoreX is the total score of the testees 
belong to this institution on level X; and Ns is the total number of testees who belong to 
this institution.

The institutions are ranked according to their TWS. If there is a tie, the institutions are 
supposed to have the same rank, and they shall be printed in ascending order of Ns. If there 
is still a tie, they shall be printed in alphabetical order of their codes.

Sample Input:
10
A57908 85 Au
B57908 54 LanX
A37487 60 au
T28374 67 CMU
T32486 24 hypu
A66734 92 cmu
B76378 71 AU
A47780 45 lanx
A72809 100 pku
A03274 45 hypu

Sample Output:
5
1 cmu 192 2
1 au 192 3
3 pku 100 1
4 hypu 81 2
4 lanx 81 2
*/

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct school{
    string name;
    double score;
    int num;
    int rank;
    bool operator < (school s) const {
        if(int(score) == int(s.score)){
            if(num == s.num){
                return name < s.name;
            }
            return num < s.num;
        }
        return int(score) > int(s.score);
    }
};

int main(){
    int n;
    double score;
    string num, sh_name;
    map<string, school> m;
    vector<school> v;
    cin >> n;
    getchar();
    for(int i = 0; i < n; i++){
        cin >> num >> score >> sh_name;
        if(num[0] == 'B'){
            score /= 1.5;
        }else if(num[0] == 'T'){
            score *= 1.5;
        }
        transform(sh_name.begin(), sh_name.end(), sh_name.begin(), ::tolower);
        m[sh_name].score += score;
        m[sh_name].num ++;
    }
    for(auto it : m){
        v.push_back({it.first, it.second.score, it.second.num, 1});
    }
    sort(v.begin(), v.end());
    cout << v.size() << endl;
    for(int i = 0; i < v.size(); i++){
        if(i == 0 || int(v[i].score) != int(v[i-1].score)){
            v[i].rank = i+1;
        }else{
            v[i].rank =  v[i-1].rank;
        }
        cout << v[i].rank << ' ' << v[i].name << ' ' << int(v[i].score) << ' ' << v[i].num << endl;
    }
    return 0;
}