/*
1009. Product of Polynomials (25)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
This time, you are supposed to find A*B where A and B are two polynomials.

Input Specification:
Each input file contains one test case. Each case occupies 2 lines, and each line contains the 
information of a polynomial: K N1 aN1 N2 aN2 ... NK aNK, where K is the number of nonzero terms in the 
polynomial, Ni and aNi (i=1, 2, ..., K) are the exponents and coefficients, respectively. It is given 
that 1 <= K <= 10, 0 <= NK < ... < N2 < N1 <=1000.

Output Specification:
For each test case you should output the product of A and B in one line, with the same format as the 
input. Notice that there must be NO extra space at the end of each line. Please be accurate up to 1 
decimal place.

Sample Input
2 1 2.4 0 3.2
2 2 1.5 1 0.5

Sample Output
3 3 3.6 2 6.0 1 1.6
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;
double a[2][1001],c[2002];
int maxn[3] = {0};

int main(){
    int ex,k,n;
    double co;
    vector<pair<int,double> > v; 
    //freopen("in/in.txt","r",stdin);
    fill(a[0],a[0]+2002,0);
    fill(c,c+2002,0);
    for(int i = 0; i < 2; i++){
        scanf("%d",&k);
        for(int j = 0; j < k; j++){
            scanf("%d %lf",&ex,&co);
            a[i][ex] = co;
            maxn[i] = max(ex,maxn[i]);
        }
    }
    for(int i = 0; i <= maxn[0]; i++)
        for(int j = 0; j <= maxn[1]; j++)
            if(a[0][i] != 0 && a[1][j] != 0){
                c[i+j] += a[0][i] * a[1][j];
                maxn[2] =  max(maxn[2],i+j);
            }
    for(int i = maxn[2]; i >= 0; i--){
        if(c[i] != 0) v.push_back(make_pair(i,c[i]));
    }
    n = v.size();
    printf("%d",n);
    for(int i = 0; i < n; i++)
        printf(" %d %.1lf",v[i].first,v[i].second);
    printf("\n");
    return 0;
}