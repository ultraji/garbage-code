/*
1056. Mice and Rice (25)
时间限制
100 ms
内存限制
65536 kB
代码长度限制
16000 B
Mice and Rice is the name of a programming contest in which each programmer must write a piece of code 
to control the movements of a mouse in a given map. The goal of each mouse is to eat as much rice as 
possible in order to become a FatMouse.
First the playing order is randomly decided for NP programmers. Then every NG programmers are grouped in a 
match. The fattest mouse in a group wins and enters the next turn. All the losers in this turn are 
ranked the same. Every NG winners are then grouped in the next match until a final winner is determined.
For the sake of simplicity, assume that the weight of each mouse is fixed once the programmer submits 
his/her code. Given the weights of all the mice and the initial playing order, you are supposed to 
output the ranks for the programmers.

Input Specification:
Each input file contains one test case. For each case, the first line contains 2 positive integers: NP 
and NG (<= 1000), the number of programmers and the maximum number of mice in a group, respectively. If 
there are less than NG mice at the end of the player's list, then all the mice left will be put into the 
last group. The second line contains NP distinct non-negative numbers Wi (i=0,...NP-1) where each Wi is 
the weight of the i-th mouse respectively. The third line gives the initial playing order which is a 
permutation of 0,...NP-1 (assume that the programmers are numbered from 0 to NP-1). All the numbers in a 
line are separated by a space.

Output Specification:
For each test case, print the final ranks in a line. The i-th number is the rank of the i-th programmer, 
and all the numbers must be separated by a space, with no extra space at the end of the line.

Sample Input:
11 3
25 18 0 46 37 3 19 22 57 56 10
6 0 8 7 10 5 9 1 4 2 3

Sample Output:
5 5 5 2 5 5 5 3 1 3 5
*/

#include <iostream>
#include <queue>
using namespace std;
int mice[1001],ranks[1001];
vector<int> q[1001]; //q[i]表示第i轮
int main(){
    int np,ng,tmp,r = 0;
    cin >> np >> ng;
    for(int i = 0; i < np; i++){
        cin >> mice[i];
    }
    for(int i = 0; i < np; i++){
        cin >> tmp;
        q[r].push_back(tmp);
    }
    int win = -1,maxMice = 0,cnt = 0;
    while(q[r].size() != 1){
        for(int i = 0; i < ng && cnt < q[r].size(); cnt ++,i++){
            if(mice[q[r][cnt]] > maxMice){
                maxMice = mice[q[r][cnt]];
                win = q[r][cnt];
            }
        }
        q[r+1].push_back(win);  //将胜者加入下一轮
        ranks[win] = r+1;
        if(cnt == q[r].size()){ //该r轮结束，r++ 进入下一轮
            r++;cnt = 0;
        }
        maxMice = 0;
    }
    for(int i = 0; i < np; i++){
        printf("%d%c",q[ranks[i]+1].size()+1,i == np-1?'\n':' ');
    }
    return 0;
}