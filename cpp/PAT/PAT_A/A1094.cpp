/*
1094. The Largest Generation (25)
keywords: 层序遍历

A family hierarchy is usually presented by a pedigree tree where all the nodes on the same level belong to the same generation. Your task is 
to find the generation with the largest population.

Input Specification:
Each input file contains one test case. Each case starts with two positive integers N (<100) which is the total number of family members in 
the tree (and hence assume that all the members are numbered from 01 to N), and M (<N) which is the number of family members who have 
children. Then M lines follow, each contains the information of a family member in the following format:
ID K ID[1] ID[2] ... ID[K]
where ID is a two-digit number representing a family member, K (>0) is the number of his/her children, followed by a sequence of two-digit 
ID's of his/her children. For the sake of simplicity, let us fix the root ID to be 01. All the numbers in a line are separated by a space.

Output Specification:
For each test case, print in one line the largest population number and the level of the corresponding generation. It is assumed that such 
a generation is unique, and the root level is defined to be 1.

Sample Input:
23 13
21 1 23
01 4 03 02 04 05
03 3 06 07 08
06 2 12 13
13 1 21
08 2 15 16
02 2 09 10
11 2 19 20
17 1 22
05 1 11
07 1 14
09 1 17
10 1 18

Sample Output:
9 4
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int level[101],cnt[101];
vector<int> v[101];
int main(){
    queue<int> q;
    int n, m, k, id, tmp;
    cin >> n >> m;
    for(int i = 0; i < m; i ++){
        cin >> id >> k;
        for(int j = 0; j < k; j++){
            cin >> tmp;
            v[id].push_back(tmp);
        }
    }
    q.push(1);
    level[1] = 1;
    while(!q.empty()){
        id = q.front();
        cnt[level[id]] ++;
        q.pop();
        for(int i = 0; i < v[id].size(); i++){
            level[v[id][i]] = level[id] + 1;
            q.push(v[id][i]);
        }
    }
    k = 1;
    for(int i = 2; i <= level[id]; i++){
        if(cnt[i] > cnt[k]) k = i;
    }
    printf("%d %d", cnt[k], k);
    return 0;
}