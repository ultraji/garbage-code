/*
1107. Social Clusters (30)
时间限制
1000 ms
内存限制
65536 kB
代码长度限制
16000 B
When register on a social network, you are always asked to specify your hobbies in order to find some potential friends with the same hobbies. 
A "social cluster" is a set of people who have some of their hobbies in common. You are supposed to find all the clusters.

Input Specification:
Each input file contains one test case. For each test case, the first line contains a positive integer N (<=1000), the total number of people 
in a social network. Hence the people are numbered from 1 to N. Then N lines follow, each gives the hobby list of a person in the format:
Ki: hi[1] hi[2] ... hi[Ki]
where Ki (>0) is the number of hobbies, and hi[j] is the index of the j-th hobby, which is an integer in [1, 1000].

Output Specification:
For each case, print in one line the total number of clusters in the network. Then in the second line, print the numbers of people in the 
clusters in non-increasing order. The numbers must be separated by exactly one space, and there must be no extra space at the end of the 
line.

Sample Input:
8
3: 2 7 10
1: 4
2: 5 3
1: 4
1: 3
1: 4
4: 6 8 1 5
1: 4

Sample Output:
3
4 3 1
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 1001;
int father[MAXN], peo[MAXN], mp[MAXN];

bool cmp(int a, int b) {
	return a > b;
}

int findFather(int a) {
	while (a != father[a]) a = father[a];
	return a;
}

void Union(int a, int b) {
	int fa = findFather(a);
	int fb = findFather(b);
	if (fa != fb) {
		father[fa] = fb;
	}
}

int main(){
	int n, k, a, b;
	vector<int> v;
	scanf("%d", &n);
	for(int i = 0; i < MAXN; i++) {
		father[i] = i;
	}
	for(int i = 0; i < n; i++){
		scanf("%d: %d", &k, &a);
		peo[i] = a;					//假设每个人都是以第一个兴趣的社交社团
		for(int j = 0; j < k - 1; j++) {
			scanf("%d", &b);
		    Union(a, b);			//将兴趣并起来
		}
	}
	for(int i = 0; i < n; i++) {
		peo[i] = findFather(peo[i]);
	    mp[peo[i]] ++;
	}
	for(int i = 1; i < 1001; i++) {
		if (mp[i] != 0) v.push_back(mp[i]);
	}
	printf("%d\n", v.size());
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++) {
		printf("%d%c", v[i], (i == v.size() - 1) ? '\n' : ' ');
	}
    return 0;
}