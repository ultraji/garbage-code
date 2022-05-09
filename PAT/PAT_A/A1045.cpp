/*
1045. Favorite Color Stripe (30)
时间限制
200 ms
内存限制
65536 kB
代码长度限制
16000 B
Eva is trying to make her own color stripe out of a given one. She would like to keep only her favorite 
colors in her favorite order by cutting off those unwanted pieces and sewing the remaining parts 
together to form her favorite color stripe.
It is said that a normal human eye can distinguish about less than 200 different colors, so Eva's 
favorite colors are limited. However the original stripe could be very long, and Eva would like to have 
the remaining favorite stripe with the maximum length. So she needs your help to find her the best 
result.
Note that the solution might not be unique, but you only have to tell her the maximum length. For 
example, given a stripe of colors {2 2 4 1 5 5 6 3 1 1 5 6}. If Eva's favorite colors are given in her 
favorite order as {2 3 1 5 6}, then she has 4 possible best solutions {2 2 1 1 1 5 6}, {2 2 1 5 5 5 6}, 
{2 2 1 5 5 6 6}, and {2 2 3 1 1 5 6}.

Input Specification:
Each input file contains one test case. For each case, the first line contains a positive integer 
N (<=200) which is the total number of colors involved (and hence the colors are numbered from 1 to N). 
Then the next line starts with a positive integer M (<=200) followed by M Eva's favorite color numbers 
given in her favorite order. Finally the third line starts with a positive integer L (<=10000) which is 
the length of the given stripe, followed by L colors on the stripe. All the numbers in a line are 
separated by a space.

Output Specification:
For each test case, simply print in a line the maximum length of Eva's favorite stripe.

Sample Input:
6
5 2 3 1 5 6
12 2 2 4 1 5 5 6 3 1 1 5 6
Sample Output:
7
*/

#include <iostream>
using namespace std;
int dp[10001],index[10001],col[10001],fav[201],mp[201];

int main(){
    int n,m,l,maxlen;
    cin >> n >> m;
    for(int i = 0 ; i < m; i++){
        cin >> fav[i];
        mp[fav[i]] = i+1;
    }
    cin >> l;
    for(int i = 0 ; i < l; i++){
        cin >> col[i];
        int k = mp[col[i]];
        if(k == 0){
            dp[i] = 0;
        }else{
            dp[i] = 1;
            for(int j = i-1; j >= 0; j--){
                if(mp[col[j]] <= k){
                    dp[i] = max(dp[j]+1,dp[i]);
                }
            }
            maxlen = max(maxlen,dp[i]);
        }
    }
    printf("%d",maxlen);
    return 0;
}