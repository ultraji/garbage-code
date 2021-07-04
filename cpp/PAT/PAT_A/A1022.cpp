/*
1022. Digital Library (30)
时间限制
1000 ms
内存限制
65536 kB
代码长度限制
16000 B
A Digital Library contains millions of books, stored according to their titles, authors, key 
words of their abstracts, publishers, and published years. Each book is assigned an unique 
7-digit number as its ID. Given any query from a reader, you are supposed to output the 
resulting books, sorted in increasing order of their ID's.

Input Specification:
Each input file contains one test case. For each case, the first line contains a positive 
integer N (<=10000) which is the total number of books. Then N blocks follow, each contains 
the information of a book in 6 lines:

Line #1: the 7-digit ID number;
Line #2: the book title -- a string of no more than 80 characters;
Line #3: the author -- a string of no more than 80 characters;
Line #4: the key words -- each word is a string of no more than 10 characters without 
   any white space, and the keywords are separated by exactly one space;
Line #5: the publisher -- a string of no more than 80 characters;
Line #6: the published year -- a 4-digit number which is in the range [1000, 3000].
It is assumed that each book belongs to one author only, and contains no more than 5 key 
words; there are no more than 1000 distinct key words in total; and there are no more than 
1000 distinct publishers.

After the book information, there is a line containing a positive integer M (<=1000) which 
is the number of user's search queries. Then M lines follow, each in one of the formats 
shown below:
1: a book title
2: name of an author
3: a key word
4: name of a publisher
5: a 4-digit number representing the year
Output Specification:

For each query, first print the original query in a line, then output the resulting book ID's 
in increasing order, each occupying a line. If no book is found, print "Not Found" instead.
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <map>
using namespace std;
map<string,vector<int> > mp[6];

int main(){
    int n,ID,qid;
    string str,kw;
    //freopen("in/in.txt","r",stdin);
    cin >> n;
    while(n--){
        cin >>ID;
        getchar();
        for(int i = 1; i <= 5; i++){
            getline(cin,str);
            if(i == 3){
                stringstream ss(str);
                while(ss>>kw) mp[3][kw].push_back(ID);
            }else{
                mp[i][str].push_back(ID);
            }
        }
    }
    cin >> n;
    getchar();
    while(n--){
        getline(cin,str);
        cout << str << endl;
        qid = atoi(str.substr(0,1).c_str());
        kw = str.substr(3);
        int k = mp[qid][kw].size();
        if(k == 0){
            printf("Not Found\n");
        }else{
            sort(mp[qid][kw].begin(),mp[qid][kw].end());
            for(int i = 0; i < k; i++){
                printf("%07d\n",mp[qid][kw][i]);
            }
        }
    }
    return 0;
}