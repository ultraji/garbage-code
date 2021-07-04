/*
1033. To Fill or Not to Fill (25)
时间限制 100 ms
内存限制 65536 kB
代码长度限制 16000 B
With highways available, driving a car from Hangzhou to any other city is easy. But since 
the tank capacity of a car is limited, we have to find gas stations on the way from time 
to time. Different gas station may give different price. You are asked to carefully design 
the cheapest route to go.

Input Specification
Each input file contains one test case. For each case, the first line contains 4 positive 
numbers: Cmax (<= 100), the maximum capacity of the tank; D (<=30000), the distance between 
Hangzhou and the destination city; Davg (<=20), the average distance per unit gas that the 
car can run; and N (<= 500), the total number of gas stations. Then N lines follow, each 
contains a pair of non-negative numbers: Pi, the unit gas price, and Di (<=D), the distance 
between this station and Hangzhou, for i=1,...N. All the numbers in a line are separated 
by a space.

Output Specification:
For each test case, print the cheapest price in a line, accurate up to 2 decimal places. It 
is assumed that the tank is empty at the beginning. If it is impossible to reach the 
destination, print "The maximum travel distance = X" where X is the maximum possible distance 
the car can run, accurate up to 2 decimal places.

Sample Input 1:
50 1300 12 8
6.00 1250
7.00 600
7.00 150
7.10 0
7.20 200
7.50 400
7.30 1000
6.85 300
Sample Output 1:
749.17

Sample Input 2:
50 1300 12 2
7.10 0
7.00 600
Sample Output 2:
The maximum travel distance = 1200.00
*/


/*
我的思路是 记录每一段加油站的起点di，和加满油情况下停止的位置end，
对所有di和end 去重排序
例如 输入样例1就可以看作
0~150,150~200,200~300,300~400,400~600,600~750,......
若该段在 若干加油站 的di~end范围内，该段的油价取这些加油站中最便宜的油价
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;

struct Station{
    double pi = 0;
    double di;      //该加油站的起点
    double end;     //在该加油站的加满油的情况下能到的最远距离
};
bool cmp(Station s1,Station s2){
    return s1.di < s2.di;
}

int main(){
    double Cmax,D,Davg;
    int N;
    Station sta[520];
    while(cin >> Cmax >> D >> Davg >> N){
        vector<double> duans;       //set 不支持double类型的去重排序，故需要自己实现
        for(int i = 0; i < N; i++){
            cin >> sta[i].pi >> sta[i].di;
            sta[i].end = sta[i].di + Cmax * Davg > D ? D : (sta[i].di + Cmax * Davg);
            duans.push_back(sta[i].di);
            duans.push_back(sta[i].end);
        }
        sta[N].di = D;      //加入终点，油价为0
        N++;
        sort(sta, sta + N, cmp);

        bool flag = true;
        if(sta[0].di > 0){//若起点没有加油站
            flag = false;
            printf("The maximum travel distance = 0.00");
        }
        for(int i = 0; i < N-1 && flag; i ++ ){
            if(sta[i+1].di - sta[i].di > Cmax * Davg){
                flag = false;
                printf("The maximum travel distance = %.2f\n", sta[i].di + Cmax * Davg);
                break;
            }
        }
        if(flag){
            double price = 0;
            sort(duans.begin(),duans.end());
            for(vector<double>::iterator it = duans.begin() + 1; it != duans.end(); ){
                if(*it == *(it-1))
                    duans.erase(it);
                else
                    it ++;
            }
            for(int i = 0; i < duans.size() - 1; i++){//把每一段的油价加起来
                double min = 999999;    //e....
                for(int j = 0; j < N - 1; j++){//获得最小油价
                    if(sta[j].di <= duans[i] && sta[j].end >= duans[i + 1]){
                        if(sta[j].pi <= min){
                            min = sta[j].pi;
                        }
                    }
                }
                price += min * (duans[i+1] - duans[i]) / Davg;
            }
            printf("%.2f\n",price);
        }
    }
    return 0;
}