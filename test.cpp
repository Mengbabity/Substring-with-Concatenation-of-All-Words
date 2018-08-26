#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
	vector<int> findSubstring(string s, vector<string> words) {
		if (s.size() == 0 || !words.size())
			return {};

		vector<int> res;
		map<string, int> dict;
		int n = words.size();
		int m = words[0].size();

		for (int i = 0; i < n; i++)
		{
			dict[words[i]]++;
		}

		for (int i = 0; i < m; i++)
		{
			int left = i;
			int count = 0;
			map<string, int> tdict;
			for (int j = i; j <= s.size() - m; j += m)
			{
				string str = s.substr(j, m);
				if (dict.count(str)) 
				{
					tdict[str]++;
					if (tdict[str] <= dict[str])
						count++;
					else 
					{
						while (tdict[str] > dict[str]) 
						{
							string str1 = s.substr(left, m);
							tdict[str1]--;
							if (tdict[str1] < dict[str1]) 
								count--;
							left += m;
						}
					}
					if (count == n) 
					{
						res.push_back(left);
						tdict[s.substr(left, m)]--;
						count--;
						left += m;
					}
				}
				else 
				{
					tdict.clear();
					count = 0;
					left = j + m;
				}
			}
		}
		return res;
	}
};

int main()
{
	Solution s;
	s.findSubstring("barfoofoofoothefoobarman", { "foo","bar" });
	return 0;
}
