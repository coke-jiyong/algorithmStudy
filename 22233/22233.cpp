#include <iostream>
#include <unordered_set>
using namespace std;
int N, M;
unordered_set<string> keyword;
void input();

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
        keyword.insert(str);
    }

    for (int i = 0; i < M; i++)
    {
        string str;
        cin >> str;
        string tmp;
        for (int j = 0; j < str.length(); j++)
        {
            if (str[j] != ',')
                tmp += str[j];
            else
            {
                if (keyword.find(tmp) != keyword.end())
                    keyword.erase(tmp);
                tmp = "";
            }
        }
        cout << "tmp: " << tmp << endl;
        cout << keyword.size() << endl;
    }
}
