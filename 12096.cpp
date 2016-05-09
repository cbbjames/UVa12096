//#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<iostream>
#include<string>
#include<cctype>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<map>
#include<stack>
#include<cstdio>
#define ALL(x) x.begin(), x.end()
#define INS(x) inserter(x,x.begin())
using namespace std;
typedef set<int> Set;
map<Set, int> IDcache;
vector<Set>Setcache;
int ID(Set x)
{
	if (IDcache.count(x))
		return IDcache[x];
	Setcache.push_back(x);
	return IDcache[x] = Setcache.size() - 1;
}
int main()
{
	stack<int> s;
	int n = 0;
	cin >> n;
	int m=0;
	
	for (int i = 0; i < n; i++)
	{
		cin>>m;
		for (int j = 0; j < m; j++)
		{
		string p;
		cin >> p;
		if (p[0] == 'P')
			s.push(ID(Set()));
		else if (p[0] == 'D')
			s.push(s.top());
		else
		{
			Set x1 = Setcache[s.top()]; s.pop();
			Set x2 = Setcache[s.top()]; s.pop();
			Set x;
			if (p[0] == 'U')
				set_union(ALL(x1), ALL(x2), INS(x));
			if (p[0] == 'I')
				set_intersection(ALL(x1), ALL(x2), INS(x));
			if (p[0] == 'A')
			{
				x = x2; 
				x.insert(ID(x1));
			}
			s.push(ID(x));
		}
		cout << Setcache[s.top()].size() << endl;
		}
		printf("***\n");
	}
	//system("PAUSE");
	return 0;
}