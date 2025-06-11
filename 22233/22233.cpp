#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
int N, M;
map<string, bool> m;
vector<string> v;
void input();
void sol();

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    input();
    return 0;
}

void input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        m[str] = true;
    }
    for (int i = 0; i < M; i++)
    {
        string str;
        cin >> str;
        int index = 0;
        while (1)
        {
            int findIdx = str.find(',');
            if (findIdx == string::npos)
            {
                v.push_back(str.substr(index));
                break;
            }
            v.push_back(str.substr(index, findIdx - index));
            index = findIdx + 1;
        }
    }
}

void sol(int score)
{
}