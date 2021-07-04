/*
1014. Waiting in Line (30)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
Suppose a bank has N windows open for service. There is a yellow line in front of the windows which 
devides the waiting area into two parts. The rules for the customers to wait in line are:
The space inside the yellow line in front of each window is enough to contain a line with M customers. 
Hence when all the N lines are full, all the customers after (and including) the (NM+1)st one will have 
to wait in a line behind the yellow line.Each customer will choose the shortest line to wait in when 
crossing the yellow line. If there are two or more lines with the same length, the customer will always 
choose the window with the smallest number.Customer[i] will take T[i] minutes to have his/her 
transaction processed.The first N customers are assumed to be served at 8:00am.Now given the processing 
time of each customer, you are supposed to tell the exact time at which a customer has his/her business 
done.
For example, suppose that a bank has 2 windows and each window may have 2 custmers waiting inside the 
yellow line. There are 5 customers waiting with transactions taking 1, 2, 6, 4 and 3 minutes,
respectively. At 08:00 in the morning, customer1 is served at window1 while customer2 is served at 
window2. Customer3 will wait in front of window1 and customer4 will wait in front of window2. Customer5 
will wait behind the yellow line.
At 08:01, customer1 is done and customer5 enters the line in front of window1 since that line seems 
shorter now. Customer2 will leave at 08:02, customer4 at 08:06, customer3 at 08:07, and finally 
customer5 at 08:10.

Input
Each input file contains one test case. Each case starts with a line containing 4 positive integers: 
N (<=20, number of windows), M (<=10, the maximum capacity of each line inside the yellow line), K 
(<=1000, number of customers), and Q (<=1000, number of customer queries).
The next line contains K positive integers, which are the processing time of the K customers.
The last line contains Q positive integers, which represent the customers who are asking about the time 
they can have their transactions done. The customers are numbered from 1 to K.

Output
For each of the Q customers, print in one line the time at which his/her transaction is finished, in the 
format HH:MM where HH is in [08, 17] and MM is in [00, 59]. Note that since the bank is closed everyday 
after 17:00, for those customers who cannot be served before 17:00, you must output "Sorry" instead.

Sample Input
2 2 7 5
1 2 6 4 3 534 2
3 4 5 6 7

Sample Output
08:07
08:06
08:10
17:00
Sorry
*/

#include <iostream>
#include <queue>
using namespace std;
int t[1001],sta[21],fin[1001];

int main(){
    int n,m,k,q;
    queue<pair<int,int> > qu[21];
    //freopen("in/in.txt","r",stdin);
    fill(fin,fin+1001,-1);
    fill(sta,sta+21,0);
    scanf("%d %d %d %d",&n,&m,&k,&q);
    int i = 1;
    while(1){
        for(;i <= k; i++){
            int mi = m,whichin = -1;
            for(int j = 0; j < n; j++){
                if(qu[j].size() < m && qu[j].size() < mi){
                    mi = qu[j].size();
                    whichin = j;
                }
            }
            if(mi == m) break; //当 n*m 即黄线内塞满时跳出
            scanf("%d",&t[i]);
            qu[whichin].push(make_pair(t[i],i));
        }

        int mi = 1000000,whichout = -1; //找到最早结束的客户，弹出
        for(int j = 0; j < n; j++){
            if(!qu[j].empty() && qu[j].front().first + sta[j]< mi){
                mi = qu[j].front().first + sta[j];
                whichout = j;
            }
        }
        if(mi == 1000000) break; //黄线内全空时结束
        if(sta[whichout] < 540) fin[qu[whichout].front().second] = mi;
        sta[whichout] = mi;
        qu[whichout].pop();

    }
    for(int i = 0; i < q; i++){
        int j;
        scanf("%d",&j);
        if(fin[j] != -1){
            printf("%02d:%02d\n",8+fin[j]/60,fin[j]%60);
        }else{
            printf("Sorry\n");
        }
    }
    return 0;
}