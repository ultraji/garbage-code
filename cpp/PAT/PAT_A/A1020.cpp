/*
1020. Tree Traversals (25)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
Suppose that all the keys in a binary tree are distinct positive 
integers. Given the postorder and inorder traversal sequences, you are 
supposed to output the level order traversal sequence of the 
corresponding binary tree.

Input Specification:
Each input file contains one test case. For each case, the first line 
gives a positive integer N (<=30), the total number of nodes in the 
binary tree. The second line gives the postorder sequence and the 
third line gives the inorder sequence. All the numbers in a line are 
separated by a space.

Output Specification:
For each test case, print in one line the level order traversal 
sequence of the corresponding binary tree. All the numbers in a line 
must be separated by exactly one space, and there must be no extra 
space at the end of the line.

Sample Input:
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7

Sample Output:
4 1 6 3 5 7 2
*/

#include <iostream>
#include <queue>
using namespace std;
const int MAXN = 40;
typedef struct node{
    int data;
    node* left;
    node* right;
}*bt;

void fun(int post[],int s1,int e1,int in[],int s2,int e2,bt &t){
    if(s1 > e1) return; //输入数组长度为-1
    t = new node;
    t->left = NULL;
    t->right = NULL;
    t->data = post[e1];
    if(s1 == e1) return;//输入数组长度为 1
    int i = s2,l = 0;//输入数组长度大于 1
    for(; in[i] != post[e1]; i++,l++);
    fun(post,s1,s1+l-1,in,s2,i-1,t->left);
    fun(post,s1+l,e1-1,in,i+1,e2,t->right); 
}

int main(){
    bt t = NULL;
    int n,post[MAXN],in[MAXN],lev[MAXN];
    //freopen("in/in.txt","r",stdin);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> post[i];
    for(int i = 0; i < n; i++) cin >> in[i];
    fun(post,0,n-1,in,0,n-1,t);
    queue<bt> q;
    q.push(t);
    int i = 0;
    while(!q.empty()){
        t = q.front();
        lev[i++] = t->data;
        q.pop();
        if(t->left != NULL) q.push(t->left);
        if(t->right != NULL) q.push(t->right);
    }
    for(int i = 0; i < n-1; i++)
        printf("%d ",lev[i]);
    printf("%d\n",lev[n-1]);
    return 0;
}