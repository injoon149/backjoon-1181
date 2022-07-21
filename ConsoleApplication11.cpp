#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


//구조체 만들고 구조체 변수를 sort에 대입 --> 정렬 가능하다.
struct MyFunctor {
	bool operator()(string a, string b) const
	{
		if (a.size() == b.size())
		{
			return a < b;
		}
		else return a.size() < b.size();
	}
};

int main()
{
	MyFunctor mf;
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int a = 0;
	cin >> a;
	vector <string> v;
	string s = "";
	

	//내가 좋아하는 flag 기법 --> 같은 게 있으면 flag를 올려 마지막에 flag가 올라가 있는지
	//내려가 있는지 판단하여 vector에 넣을지 안넣을지 결정한다.
	for (int i = 0; i < a; i++)
	{
		int flag = 0;
		cin >> s;
		for (int j=0; j<v.size(); j++)
		{
			if (v[j] == s)
			{
				flag = 1;
				break;
			}
			else
			{
				continue;
			}
		}
		if (flag == 0)
		{
			v.push_back(s);
		}
	}
	//정렬
	sort(v.begin(), v.end(), mf);

	for (auto iter = v.begin(); iter != v.end(); iter++)
	{
		cout << *iter << '\n';
	}

	return 0;
}