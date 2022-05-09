/*
1086. Tree Traversals Again (25)
时间限制
200 ms
内存限制
65536 kB
代码长度限制
16000 B
An inorder binary tree traversal can be implemented in a non-recursive way with a stack. For example, suppose that when a 6-node binary tree 
(with the keys numbered from 1 to 6) is traversed, the stack operations are: push(1); push(2); push(3); pop(); pop(); push(4); pop(); pop(); 
push(5); push(6); pop(); pop(). Then a unique binary tree (shown in Figure 1) can be generated from this sequence of operations. Your task is 
to give the postorder traversal sequence of this tree.

Input Specification:
Each input file contains one test case. For each case, the first line contains a positive integer N (<=30) which is the total number of nodes 
in a tree (and hence the nodes are numbered from 1 to N). Then 2N lines follow, each describes a stack operation in the format: "Push X" where 
X is the index of the node being pushed onto the stack; or "Pop" meaning to pop one node from the stack.

Output Specification:
For each test case, print the postorder traversal sequence of the corresponding tree in one line. A solution is guaranteed to exist. All the 
numbers must be separated by exactly one space, and there must be no extra space at the end of the line.

Sample Input:
6
Push 1
Push 2
Push 3
Pop
Pop
Push 4
Pop
Pop
Push 5
Push 6
Pop
Pop

Sample Output:
3 4 2 6 5 1
*/

#include <iostream>
#include <stack>
using namespace std;
int pre[31], in[31], post[31], n, a, m = 0;

void traversal(int s1,int e1,int s2,int e2){
    if(s1 > e1){
        return;
    }else if(s1 == e1){
        post[m++] = pre[s1];
    }else{
        int pos = pre[s1], p = s2;
        while(in[p] != pos) p++;
        traversal(s1+1, s1+p-s2, s2, p-1);
        traversal(s1+p+1-s2, e1, p+1, e2);
        post[m++] = pos;
    }
}

int main(){
    stack<int> s;
    string str;
    cin >> n;
    for(int i = 0, j = 0, k = 0; i < 2*n; i++){
        cin >> str;
        if(str == "Push"){
            cin >> a;
            s.push(a);
            pre[j++] = a;
        }else{
            in[k++] = s.top();
            s.pop();
        }
    }
    traversal(0,n-1,0,n-1);
    for(int i = 0; i < n; i++){
        printf("%d%c",post[i],i==n-1?'\n':' ');
    }
    return 0;
}