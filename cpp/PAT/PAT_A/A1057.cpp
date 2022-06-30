/*
1057. Stack (30)
时间限制
150 ms
内存限制
65536 kB
代码长度限制
16000 B
Stack is one of the most fundamental data structures, which is based on the principle of Last In First 
Out (LIFO). The basic operations include Push (inserting an element onto the top position) and Pop 
(deleting the top element). Now you are supposed to implement a stack with an extra operation: 
PeekMedian -- return the median value of all the elements in the stack. With N elements, the median 
value is defined to be the (N/2)-th smallest element if N is even, or ((N+1)/2)-th if N is odd.

Input Specification:
Each input file contains one test case. For each case, the first line contains a positive integer N 
(<= 105). Then N lines follow, each contains a command in one of the following 3 formats:
Push key
Pop
PeekMedian
where key is a positive integer no more than 105.

Output Specification:
For each Push command, insert key into the stack and output nothing. For each Pop or PeekMedian command, 
print in a line the corresponding returned value. If the command is invalid, print "Invalid" instead.

Sample Input:
17
Pop
PeekMedian
Push 3
PeekMedian
Push 2
PeekMedian
Push 1
PeekMedian
Pop
Pop
Push 5
Push 4
PeekMedian
Pop
Pop
Pop
Pop

Sample Output:
Invalid
Invalid
3
2
2
1
2
4
4
5
3
Invalid
*/

#include <iostream>
using namespace std;
int s[100001];
int main(){
    int n, num, top = -1;
    string str;
    cin >> n;
    while(n--){
        cin >> str;
        if(str == "Pop"){
            if(top != -1){
                printf("%d\n",s[top--]);
            }else{
                printf("Invalid\n");
            }
        }else if(str == "PeekMedian"){
            if(top != -1){
                printf("%d\n");
            }else{
                printf("Invalid\n");
            }
        }else{
            cin >> num;
            s[++top] = num;
        }
    }
    return 0;
}