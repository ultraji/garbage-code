/*
1085 Perfect Sequence （25 分）
Given a sequence of positive integers and another positive integer p. The sequence is 
said to be a perfect sequence if M≤m×p where M and m are the maximum and minimum numbers 
in the sequence, respectively.

Now given a sequence and a parameter p, you are supposed to find from the sequence as 
many numbers as possible to form a perfect subsequence.

Input Specification:
Each input file contains one test case. For each case, the first line contains two positive 
integers N and p, where N (≤10^5) is the number of integers in the sequence, and p (≤10^9) 
is the parameter. In the second line there are N positive integers, each is no greater 
than 10^9.

Output Specification:
For each test case, print in one line the maximum number of integers that can be chosen to 
form a perfect subsequence.

Sample Input:
10 8
2 3 20 4 5 1 6 7 8 9

Sample Output:
8
*/

#include <iostream>
#include <algorithm>
using namespace std;

double num[100005];

int main()
{
    int n, p, len = 1;
    scanf("%d %d", &n, &p);
    for (int i = 0; i < n; i++){
        scanf("%lf", &num[i]);
    }
    sort(num, num+n);
    for (int i = 0; i < n; i++){
        int j = i + len;
        if(j == n){
            break;
        }
        for (; j < n && num[j] <=  num[i] * p; j++);
        if(len < j - i){
            len = j - i;
        }
    }
    printf("%d", len);
    return 0;
}
