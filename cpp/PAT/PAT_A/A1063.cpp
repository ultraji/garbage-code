/*
1063. Set Similarity (25)
时间限制 300 ms
内存限制 65536 kB
代码长度限制 16000 B
Given two sets of integers, the similarity of the sets is defined to be Nc/Nt*100%, where Nc is the 
number of distinct common numbers shared by the two sets, and Nt is the total number of distinct 
numbers in the two sets. Your job is to calculate the similarity of any given pair of sets.

Input Specification:
Each input file contains one test case. Each case first gives a positive integer N (<=50) which is the 
total number of sets. Then N lines follow, each gives a set with a positive M (<=104) and followed by M 
integers in the range [0, 109]. After the input of sets, a positive integer K (<=2000) is given, followed 
by K lines of queries. Each query gives a pair of set numbers (the sets are numbered from 1 to N). All 
the numbers in a line are separated by a space.

Output Specification:
For each query, print in one line the similarity of the sets, in the percentage form accurate up to 1 
decimal place.

Sample Input:
3
3 99 87 101
4 87 101 5 87
7 99 101 18 5 135 18 99
2
1 2
1 3

Sample Output:
50.0%
33.3%
*/

#include <stdio.h>
#include <set>
using namespace std;

int main(){
    set<int> a[51];
    int c,n,tmp,l1,l2;
    scanf("%d",&c);
    for(int i = 1; i <= c; i++){
        scanf("%d",&n);
        for(int j = 0; j < n; j++){
            scanf("%d",&tmp);
            a[i].insert(tmp);
        }
    }
    scanf("%d",&c);
    for(int i = 0; i < c; i++){
        int count = 0;
        scanf("%d %d",&l1,&l2);
        set<int>::iterator it = a[l1].begin(),jt = a[l2].begin();
        while(it != a[l1].end() && jt != a[l2].end() ){
            if(*it < *jt ){
                it ++;
            }else if(*it > *jt){
                jt ++;
            }else{
                it ++;
                jt ++;
            }
            count ++;
        }
        while(it != a[l1].end()){
            it ++; count ++;
        }
        while(jt != a[l2].end()){
            jt ++; count ++;
        }
        printf("%.1f%%\n",100.0*(a[l1].size() +a[l2].size() - count)/count);
    }
    return 0;
}