/*
1034. Head of a Gang (30)
时间限制
100 ms
内存限制
65536 kB
代码长度限制
16000 B
One way that the police finds the head of a gang is to check people's phone calls. If there is a phone call between A and B, we say 
that A and B is related. The weight of a relation is defined to be the total time length of all the phone calls made between the two 
persons. A "Gang" is a cluster of more than 2 persons who are related to each other with total relation weight being greater than a 
given threshold K. In each gang, the one with maximum total weight is the head. Now given a list of phone calls, you are supposed to 
find the gangs and the heads.

Input Specification:
Each input file contains one test case. For each case, the first line contains two positive numbers N and K (both less than or equal 
to 1000), the number of phone calls and the weight threshold, respectively. Then N lines follow, each in the following format:
Name1 Name2 Time
where Name1 and Name2 are the names of people at the two ends of the call, and Time is the length of the call. A name is a string of 
three capital letters chosen from A-Z. A time length is a positive integer which is no more than 1000 minutes.

Output Specification:
For each test case, first print in a line the total number of gangs. Then for each gang, print in a line the name of the head and 
the total number of the members. It is guaranteed that the head is unique for each gang. The output must be sorted according to the 
alphabetical order of the names of the heads.

Sample Input 1:
8 59
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
Sample Output 1:
2
AAA 3
GGG 3

Sample Input 2:
8 70
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
Sample Output 2:
0
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int MAXN = 26*26*26;
int weight[MAXN],father[MAXN],num[MAXN],maxw[MAXN],head[MAXN],we_all[MAXN];

int hashFun(string &s){
    return (s[0]-'A')*26*26+(s[1]-'A')*26+(s[2]-'A');
}

int findFather(int n){
    while(n != father[n]) n = father[n];
    return n;
}

void Union(int a,int b){
    int fa = findFather(a);
    int fb = findFather(b);
    if(fa != fb){
        father[fb] = fa;
        num[fa] += num[fb];
    }
}

int main(){
    int n,k,phone_time;
    string str1,str2;
    char name[4] = {'\0'};
    set<int> s,r;
    fill(num,num+MAXN,1);
    for(int i = 0; i < MAXN; i++)
        father[i] = i;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> str1 >> str2 >> phone_time;
        int a = hashFun(str1), b = hashFun(str2); 
        s.insert(a);
        s.insert(b);
        weight[a] += phone_time;
        weight[b] += phone_time;
        Union(a,b);
    }
    for(auto it = s.begin(); it != s.end(); it++){
        int a =  findFather(*it);
        if(num[a] > 2){                             //认定为帮派的首要条件 人数大于2
            we_all[a] += weight[*it];
            if(we_all[a]/2 > k) r.insert(a);        //帮派通话时长超过 阈值；认定为帮派
            if(weight[*it] > maxw[a]){              //找到帮派中的头目
                maxw[a] = weight[*it];
                head[a] = *it;
            }
        }
    }
    printf("%d\n",r.size());
    for(auto it = r.begin(); it != r.end(); it++){
        name[0] = head[*it]/(26*26)+'A';
        name[1] = head[*it]/26%26+'A';
        name[2] = head[*it]%26+'A';
        printf("%s %d\n",name,num[*it]);
    }
    return 0;
}