/*
1067. Sort with Swap(0,*) (25)
时间限制
150 ms
内存限制
65536 kB
代码长度限制
16000 B
Given any permutation of the numbers {0, 1, 2,..., N-1}, it is easy to sort them in increasing order. 
But what if Swap(0, *) is the ONLY operation that is allowed to use? For example, to sort {4, 0, 2, 1, 
3} we may apply the swap operations in the following way:
Swap(0, 1) => {4, 1, 2, 0, 3}
Swap(0, 3) => {4, 1, 2, 3, 0}
Swap(0, 4) => {0, 1, 2, 3, 4}
Now you are asked to find the minimum number of swaps need to sort the given permutation of the first 
N nonnegative integers.

Input Specification:
Each input file contains one test case, which gives a positive N (<=10^5) followed by a permutation 
sequence of {0, 1, ..., N-1}. All the numbers in a line are separated by a space.

Output Specification:
For each case, simply print in a line the minimum number of swaps need to sort the given permutation.

Sample Input:
10 3 5 7 2 6 4 9 0 8 1

Sample Output:
9
*/

/*
这是组合数学中的圈问题，可以把数组中的位置关系看成图的拓扑关系。
例如A[3]={2,0,1},2在0的位置，0在1的位置，1在2的位置，那么把它们画成图的拓扑结构的话，
就是一个环（圈），即2->0->1->2。
这样的条件（排列成环（圈））用文字描述为：
1、位置和位置上的数字或字符存在一一对应关系；
2、每个数字或字符都不在自己应有的位置上；
上例我们通过交换1和0，再交换2和0，即可正确排序，次数为2.
一个排序总可以划分为不同的环（圈），独立成圈的不需要交换；
总结满足上述条件的规律：
一个长度为m的圈，如果包含0，则交换(m -1)次可以恢复所有的数到原位
一个长度为m的圈，如果不包含0，则交换(m+ 1) 次可以恢复所有的数到原位
*/


#include <iostream>
using namespace std;
int arr[100001],vis[100001];
int main(){
    int cnt = 0,n = 0;
    //freopen("in/in.txt","r",stdin);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++){
        if(vis[i] == 0){
            int p = i,flag = 1;
            if(p == arr[p]){
                vis[p] = 1;
            }else{
                while(!vis[p]){
                    cnt ++;
                    vis[p] = 1;
                    if(arr[p] == 0) flag = -1;
                    p = arr[p];
                }
                cnt += flag;
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}