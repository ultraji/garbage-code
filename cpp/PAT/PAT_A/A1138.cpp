/*
1138. Postorder Traversal (25)
keywords: 树的遍历

Suppose that all the keys in a binary tree are distinct positive integers. Given the preorder and inorder traversal sequences, you are 
supposed to output the first number of the postorder traversal sequence of the corresponding binary tree.

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (<=50000), the total number of nodes in the 
binary tree. The second line gives the preorder sequence and the third line gives the inorder sequence. All the numbers in a line are 
separated by a space.

Output Specification:
For each test case, print in one line the first number of the postorder traversal sequence of the corresponding binary tree.

Sample Input:
7
1 2 3 4 5 6 7
2 3 1 5 4 7 6
Sample Output:
3
*/

#include <iostream>
using namespace std;
int pre[50001],in[50001];
int main(){
    int n,s1 = 0,e1,s2 = 0,e2;
    cin >> n;
    e1 = e2 = n-1;
    for(int i = 0; i < n; i++)
        cin >> pre[i];
    for(int i = 0; i < n; i++)
        cin >> in[i];
    while(s1 != e1){
        int pos = pre[s1], p = s2;
        while(in[p] != pos) p++;
        if(p == s2){
            s2 = s2+1;
        }else{
            e2 = p-1;
        }
        s1 = s1+1;
        e1 = e2-s2+s1;
    }
    printf("%d",pre[s1]);
    return 0;
}