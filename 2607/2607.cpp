#include <iostream>
#include <vector>
using namespace std;
int N;
string base;
int baseCheck[26];
void input()
{
    cin >> N;
    cin >> base;
    for (int i = 0; i < base.length(); i++)
        baseCheck[base[i] - 'A']++;
}

void sol()
{
    int answer = 0;
    string cmpStr;
    for (int o = 0; o < N - 1; o++)
    {
        cin >> cmpStr;
        int cmpStrChk[26] = {0};
        for (int i = 0; i < cmpStr.length(); i++)
            cmpStrChk[cmpStr[i] - 'A']++;
        int cnt = 0;
        for (int i = 0; i < 26; i++)
            cnt += abs(baseCheck[i] - cmpStrChk[i]);
        if (cnt == 0 || cnt == 1 || (cnt == 2 && cmpStr.length() == base.length()))
            answer++;
    }
    cout << answer << endl;
}

int main(void)
{
    input();
    sol();
    return 0;
}