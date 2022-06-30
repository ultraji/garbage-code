/*
1118. Birds in Forest (25)
时间限制
150 ms
内存限制
65536 kB
代码长度限制
16000 B
Some scientists took pictures of thousands of birds in a forest. Assume that all the birds appear in the same picture belong to the same 
tree. You are supposed to help the scientists to count the maximum number of trees in the forest, and for any pair of birds, tell if they 
are on the same tree.

Input Specification:
Each input file contains one test case. For each case, the first line contains a positive number N (<= 10^4) which is the number of pictures. 
Then N lines follow, each describes a picture in the format:
K B1 B2 ... BK
where K is the number of birds in this picture, and Bi's are the indices of birds. It is guaranteed that the birds in all the pictures are 
numbered continuously from 1 to some number that is no more than 10^4.
After the pictures there is a positive number Q (<= 10^4) which is the number of queries. Then Q lines follow, each contains the indices of 
two birds.

Output Specification:
For each test case, first output in a line the maximum possible number of trees and the number of birds. Then for each query, print in a 
line "Yes" if the two birds belong to the same tree, or "No" if not.

Sample Input:
4
3 10 1 2
2 3 4
4 1 5 7 8
3 9 6 4
2
10 5
3 7

Sample Output:
2 10
Yes
No
*/

#include <iostream>
using namespace std;
const int MAXN = 10001;
int mp[MAXN],father[MAXN];      //mp存鸟所在的图片，father将属于同一个树的图片并起来

void fatherInit(int n){
    for(int i = 1; i <= n; i++) father[i] = i;
}

int findFather(int x){
    while(father[x] != x) x = father[x];
    return x;
}

void Union(int a,int b){
    int fa = findFather(a);
    int fb = findFather(b);
    if(fa != fb) father[fa] = fb;
}

int main(){
    int n, k, a, b, bridNum = 0, treeNum = 0;
    scanf("%d",&n);
    fatherInit(n);
    for(int i = 1; i <= n; i++){
        scanf("%d",&k);
        while(k--){
            scanf("%d",&b);
            if(b > bridNum) bridNum = b;
            if(mp[b] == 0){
                mp[b] = i;
            }else{
                Union(mp[b],i);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(i == father[i]) treeNum ++;
    }
    printf("%d %d\n", treeNum, bridNum);
    scanf("%d",&k);
    while(k--){
        scanf("%d %d",&a,&b);
        if(findFather(mp[a]) == findFather(mp[b])){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}