/*
1026. Table Tennis (30)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
A table tennis club has N tables available to the public. The tables are numbered from 1 to N. 
For any pair of players, if there are some tables open when they arrive, they will be assigned 
to the available table with the smallest number. If all the tables are occupied, they will 
have to wait in a queue. It is assumed that every pair of players can play for at most 2 hours.
Your job is to count for everyone in queue their waiting time, and for each table the number 
of players it has served for the day.One thing that makes this procedure a bit complicated 
is that the club reserves some tables for their VIP members. When a VIP table is open, the 
first VIP pair in the queue will have the priviledge to take it. However, if there is no VIP 
in the queue, the next pair of players can take it. On the other hand, if when it is the turn 
of a VIP pair, yet no VIP table is available, they can be assigned as any ordinary players.

Input Specification:
Each input file contains one test case. For each case, the first line contains an integer 
N (<=10000) - the total number of pairs of players. Then N lines follow, each contains 2 
times and a VIP tag: HH:MM:SS - the arriving time, P - the playing time in minutes of a pair 
of players, and tag - which is 1 if they hold a VIP card, or 0 if not. It is guaranteed that 
the arriving time is between 08:00:00 and 21:00:00 while the club is open. It is assumed 
that no two customers arrives at the same time. Following the players' info, there are 2 
positive integers: K (<=100) - the number of tables, and M (< K) - the number of VIP tables. 
The last line contains M table numbers.

Output Specification:
For each test case, first print the arriving time, serving time and the waiting time for each 
pair of players in the format shown by the sample. Then print in a line the number of players 
served by each table. Notice that the output must be listed in chronological order of the 
serving time. The waiting time must be rounded up to an integer minute(s). If one cannot get a
table before the closing time, their information must NOT be printed.

Sample Input:
9
20:52:00 10 0
08:00:00 20 0
08:02:00 30 0
20:51:00 10 0
08:10:00 5 0
08:12:00 10 1
20:50:00 10 0
08:01:30 15 1
20:53:00 10 1
3 1
2

Sample Output:
08:00:00 08:00:00 0
08:01:30 08:01:30 0
08:02:00 08:02:00 0
08:12:00 08:16:30 5
08:10:00 08:20:00 10
20:50:00 20:50:00 0
20:51:00 20:51:00 0
20:52:00 20:52:00 0
3 3 2
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int OPEN_TIME = 8*60*60,END_TIME = 21*60*60;
struct player{
    int start,timeNeed,serveStart;
    int isVIP,isOut;
    bool operator < (player p) const{
        return start < p.start;
    }
}p[10001];
struct table{
    int isVIP,endTime,serveNum;
}t[101];

int main(){
    int n,k,m,tmp,hour,minute,second;;
    vector<int> rq;
    //freopen("in/in.txt","r",stdin);
    cin >> n;
    for(int i = 0; i < n; i++){
        scanf("%d:%d:%d %d %d",&hour,&minute,&second,&tmp,&p[i].isVIP);
        p[i].start = 60*60*hour + 60*minute + second;
        p[i].timeNeed = min(tmp,120)*60;
    }
    sort(p,p+n);
    cin >> k >> m;
    for(int i = 0; i < m; i++){
        cin >> tmp;
        t[tmp].isVIP = 1;
    }
    for(int i = 1; i <= k; i++) t[i].endTime = OPEN_TIME;
    for(int head = 0;head < n && p[head].start < END_TIME;){
        int firstEnd = END_TIME, firstEnd_VIP = END_TIME;
        table *pt = NULL;
        for(int i = 1; i <= k; i++){
            if(t[i].endTime < firstEnd){
                firstEnd = t[i].endTime;
                pt = t+i;
            }
            if(t[i].isVIP && t[i].endTime < firstEnd_VIP){
                firstEnd_VIP = t[i].endTime;
            }
        }
        if(firstEnd >= END_TIME) break;
        int ppp = head;
        bool waitflag = false;
        if(firstEnd > p[ppp].start) waitflag = true;
        if(waitflag && firstEnd_VIP == firstEnd){
            for(int j = head; j < n && p[j].start <= firstEnd; j ++){
                if(p[j].isVIP && !p[j].isOut){
                    ppp = j;
                    break;
                }
            }
        }else{
            bool findVipTable = false;
            if(p[ppp].isVIP){
                for(int i = 1; i <= k; i++){
                    if(t[i].isVIP && t[i].endTime <= p[ppp].start){
                        pt = t+i;
                        findVipTable = true;
                        break;
                    }
                }
            }
            if(!findVipTable){
                for(int i = 1; i <= k; i++){
                    if(t[i].endTime <= p[ppp].start){
                        pt = t+i;
                        break;
                    }
                }
            }
        }
        p[ppp].serveStart = max(p[ppp].start,(*pt).endTime);
        (*pt).endTime = p[ppp].serveStart + p[ppp].timeNeed;
        (*pt).serveNum ++;
        p[ppp].isOut = 1;
        rq.push_back(ppp);
        while(p[head].isOut) head++;
    }
    for(int i = 0; i < rq.size(); i++){
        int st = p[rq[i]].start,est = p[rq[i]].serveStart;
            printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",st/3600,st%3600/60,st%60,est/3600,est%3600/60,est%60,(int)((est-st+30)/60));
    }
    for(int i = 1; i <= k-1; i++){
        printf("%d ",t[i].serveNum);
    }
    printf("%d\n",t[k].serveNum);
    return 0;
}
