#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
int N;

int findMinTeam(const std::map<int, std::set<int>> &data)
{
	int min = 2147483646;
	int minFifth = 2147483646;
	int resultTeam = -1;
	for (auto &[team, scores] : data)
	{
		int sum = 0;
		auto itr = scores.begin();

		sum += *itr++;
		sum += *itr++;
		sum += *itr++;
		sum += *itr++;

		int fifth = *itr;
		if (sum < min)
		{
			min = sum;
			minFifth = fifth;
			resultTeam = team;
		}
		else if (sum == min && minFifth > fifth)
		{
			minFifth = fifth;
			resultTeam = team;
		}
	}

	return resultTeam;
}
// map<팀명 ,완주한 사람 수>
// 입력되는 순서대로 일단 입력.

int main(void)
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> N;
		vector<int> input;
		map<int, int> team;
		for (int k = 0; k < N; k++)
		{
			int teamName;
			cin >> teamName;
			team[teamName]++;
			input.push_back(teamName);
		}

		int score = 1;
		map<int, set<int>> validTeam;
		for (auto &name : input)
		{
			if (team[name] == 6)
			{
				validTeam[name].insert(score++);
			}
			else
			{
				continue;
			}
		}

		cout << findMinTeam(validTeam) << endl;
	}
	return 0;
}
