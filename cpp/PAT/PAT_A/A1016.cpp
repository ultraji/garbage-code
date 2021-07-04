/*
1016. Phone Bills (25)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
A long-distance telephone company charges its customers by the following rules:
Making a long-distance call costs a certain amount per minute, depending on the time of day when the 
call is made. When a customer starts connecting a long-distance call, the time will be recorded, and 
so will be the time when the customer hangs up the phone. Every calendar month, a bill is sent to the 
customer for each minute called (at a rate determined by the time of day). Your job is to prepare the 
bills for each month, given a set of phone call records.

Input Specification:
Each input file contains one test case. Each case has two parts: the rate structure, and the phone call 
records.The rate structure consists of a line with 24 non-negative integers denoting the toll 
(cents/minute) from 00:00 - 01:00, the toll from 01:00 - 02:00, and so on for each hour in the day.
The next line contains a positive number N (<= 1000), followed by N lines of records. Each phone call 
record consists of the name of the customer (string of up to 20 characters without space), the time and 
date (mm:dd:hh:mm), and the word "on-line" or "off-line".
For each test case, all dates will be within a single month. Each "on-line" record is paired with the 
chronologically next record for the same customer provided it is an "off-line" record. Any "on-line" 
records that are not paired with an "off-line" record are ignored, as are "off-line" records not paired 
with an "on-line" record. It is guaranteed that at least one call is well paired in the input. You may 
assume that no two records for the same customer have the same time. Times are recorded using a 24-hour 
clock.

Output Specification:
For each test case, you must print a phone bill for each customer.
Bills must be printed in alphabetical order of customers' names. For each customer, first print in a 
line the name of the customer and the month of the bill in the format shown by the sample. Then for 
each time period of a call, print in one line the beginning and ending time and date (dd:hh:mm), the 
lasting time (in minute) and the charge of the call. The calls must be listed in chronological order. 
Finally, print the total charge for the month in the format shown by the sample.

Sample Input:
10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
10
CYLL 01:01:06:01 on-line
CYLL 01:28:16:05 off-line
CYJJ 01:01:07:00 off-line
CYLL 01:01:08:03 off-line
CYJJ 01:01:05:59 on-line
aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
CYLL 01:28:15:41 on-line
aaa 01:05:02:24 on-line
aaa 01:04:23:59 off-line

Sample Output:
CYJJ 01
01:05:59 01:07:00 61 $12.10
Total amount: $12.10
CYLL 01
01:06:01 01:08:03 122 $24.40
28:15:41 28:16:05 24 $3.85
Total amount: $28.25
aaa 01
02:00:01 04:23:59 4318 $638.80
Total amount: $638.80
*/

#include <iostream>
#include <algorithm>
using namespace std;
double pri[24],pri_d = 0;
struct customer{
    string name;
    string tim;
    string status;
    bool operator < (customer c) const {
        if(name == c.name) return tim < c.tim;
        return name < c.name;
    }
}c[1001];

void decode(string &s,int &d,int &h,int &m){
    d = atoi(s.substr(0,2).c_str());
    h = atoi(s.substr(3,2).c_str());
    m = atoi(s.substr(6,2).c_str());
}

void deal(string &start,string &end,int &record_time,double &sum){
    int sd,sh,sm,ed,eh,em;
    decode(start,sd,sh,sm);
    decode(end,ed,eh,em);
    record_time = (ed-sd)*1440 + (eh-sh)*60 + (em-sm);
    if(sm != 0) sum -= sm*pri[sh];
    if(em != 0) sum += em*pri[eh];
    if(sh > eh){
        while(sh < 24) sum += pri[sh++]*60;
        sh = 0;
        sd ++;
    }
    while(sh < eh) sum += pri[sh++]*60;
    sum = (sum + pri_d * (ed-sd))/100;
}

int main(){
    int n;
    //freopen("in/in.txt","r",stdin);
    for(int i = 0; i < 24; i++){
        cin >> pri[i];
        pri_d += pri[i]*60;
    }
    cin >> n;
    for(int i = 0; i < n;i++){
        cin >> c[i].name >> c[i].tim >> c[i].status;
    }
    sort(c,c+n);
    bool flag = false;  //此用户有账单
    string name = "";
    double total_sum = 0;
    for(int i = 0; i < n-1; i++){
        if(c[i+1].name == c[i].name && c[i].status == "on-line" && c[i+1].status == "off-line"){
            if(name != c[i].name){
                name = c[i].name;
                total_sum = 0;
                cout << name << ' ' << c[i].tim.substr(0,2) << endl;
            }
            double sum = 0;
            int record_time = 0;
            string start = c[i].tim.substr(3), end = c[i+1].tim.substr(3);
            deal(start,end,record_time,sum);
            cout << start << ' ' << end << ' ' << record_time;
            printf(" $%.2lf\n",sum);
            total_sum += sum;
            flag = true;
        }
        if((i == n-2 || c[i+1].name != name) && flag){
            printf("Total amount: $%.2lf\n",total_sum);
            flag = false;
        }
    }
    return 0;
}