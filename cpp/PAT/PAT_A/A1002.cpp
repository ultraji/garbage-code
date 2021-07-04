/*
1002. A+B for Polynomials (25)

This time, you are supposed to find A+B where A and B are two polynomials.

Input
Each input file contains one test case. Each case occupies 2 lines, and each line contains 
the information of a polynomial: K N1 aN1 N2 aN2 ... NK aNK, where K is the number of nonzero 
terms in the polynomial(多项式), Ni and aNi (i=1, 2, ..., K) are the exponents(指数) and 
coefficients(系数), respectively. It is given that 1 <= K <= 10，0 <= NK < ... < N2 < N1 <=1000.

Output
For each test case you should output the sum of A and B in one line, with the same format as 
the input. Notice that there must be NO extra space at the end of each line. Please be accurate 
to 1 decimal place.

Sample Input
2 1 2.4 0 3.2
2 2 1.5 1 0.5

Sample Output
3 2 1.5 1 2.9 0 3.2
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

double mp[1001];
int main(){
    int n, coe;
    double exp;
    vector<pair<int,double>> r;
    for(int i = 0; i < 2; i++){
        cin >> n;
        while(n--){
            cin >> coe >> exp;
            mp[coe] += exp;
        }
    }
    for(int i = 1000; i >= 0; i--){
        if(mp[i] != 0){
            r.push_back(make_pair(i,mp[i]));
        }
    }
    printf("%d",r.size());
    for(int i = 0; i < r.size(); i++){
        printf(" %d %.1lf",r[i].first,r[i].second);
    }
    return 0;
}