/*
1052. Linked List Sorting (25)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
1600
A linked list consists of a series of structures, which are not necessarily adjacent in memory. We 
assume that each structure contains an integer key and a Next pointer to the next structure. Now given 
a linked list, you are supposed to sort the structures according to their key values in increasing 
order.

Input Specification:
Each input file contains one test case. For each case, the first line contains a positive N (< 105) 
and an address of the head node, where N is the total number of nodes in memory and the address of a 
node is a 5-digit positive integer. NULL is represented by -1.
Then N lines follow, each describes a node in the format:
Address Key Next
where Address is the address of the node in memory, Key is an integer in [-105, 105], and Next is the 
address of the next node. It is guaranteed that all the keys are distinct and there is no cycle in the 
linked list starting from the head node.

Output Specification:
For each test case, the output format is the same as that of the input, where N is the total number 
of nodes in the list and all the nodes must be sorted order.

Sample Input:
5 00001
11111 100 -1
00001 0 22222
33333 100000 11111
12345 -1 33333
22222 1000 12345

Sample Output:
5 12345
12345 -1 00001
00001 0 11111
11111 100 22222
22222 1000 33333
33333 100000 -1
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node{
    int address;
    int key;
    int next;
    bool operator < (node n) const {
        return key < n.key;
    }
}no[100001];

int main(){
    int n, head,address,key,next;
    vector<node> nn;
    //freopen("in/in.txt","r",stdin);
    cin >> n >> head;
    for(int i = 0; i < n; i++){
        cin >> address >> key >> next;
        no[address] = {address,key,next};
    }
    while(head != -1){
        nn.push_back(no[head]);
        head = no[head].next;
    }
    if(!nn.empty()){
        sort(nn.begin(),nn.end());
        n = nn.size();
        printf("%d %05d\n",n,nn[0].address);
        for(int i = 0; i < n-1; i++){
            nn[i].next = nn[i+1].address;
            printf("%05d %d %05d\n",nn[i].address,nn[i].key,nn[i].next);
        }
        printf("%05d %d -1\n",nn[n-1].address,nn[n-1].key);
    }else{
        printf("0 -1\n");
    }
    return 0;
}