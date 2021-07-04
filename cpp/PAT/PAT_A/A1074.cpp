/*
1074. Reversing Linked List (25)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
Given a constant K and a singly linked list L, you are supposed to reverse the links of every K elements on L. For example, given L being 
1→2→3→4→5→6, if K = 3, then you must output 3→2→1→6→5→4; if K = 4, you must output 4→3→2→1→5→6.

Input Specification:
Each input file contains one test case. For each case, the first line contains the address of the first node, a positive N (<= 10^5) which is 
the total number of nodes, and a positive K (<=N) which is the length of the sublist to be reversed. The address of a node is a 5-digit 
nonnegative integer, and NULL is represented by -1.
Then N lines follow, each describes a node in the format:
Address Data Next
where Address is the position of the node, Data is an integer, and Next is the position of the next node.

Output Specification:
For each case, output the resulting ordered linked list. Each node occupies a line, and is printed in the same format as in the input.

Sample Input:
00100 6 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218

Sample Output:
00000 4 33218
33218 3 12309
12309 2 00100
00100 1 99999
99999 5 68237
68237 6 -1
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node{
    int data,next;
}no[100001];
vector<pair<int,int> > v;
int main(){
    int addr, data, next, p, head, n, m;
    cin >> head >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> addr >> data >> next;
        no[addr] = {data,next};
    }
    for(p = head; p != -1; p = no[p].next){
        v.push_back(make_pair(p, no[p].data));
    }
    n = v.size();
    for(int i = 0; i < n-n%m; i += m){
        reverse(v.begin()+i,v.begin()+i+m);
    }
    for(int i = 0; i < n-1; i++){
        printf("%05d %d %05d\n", v[i].first, v[i].second, v[i+1].first);
    }
    printf("%05d %d -1", v[n-1].first, v[n-1].second);
    return 0;
}