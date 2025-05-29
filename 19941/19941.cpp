#include <iostream>

using namespace std;
int N, K, answer;
string str;
void input()
{
    cin >> N >> K;
    cin >> str;
}
void sol()
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 'P')
        {
            bool flag = false;
            for (int j = K; j != 0; j--) // left
            {
                if (i - j >= 0 && str[i - j] == 'H')
                {
                    answer++;
                    str[i - j] = 'E';
                    flag = true;
                    break;
                }
            }
            if (!flag)
            {
                for (int j = 1; j <= K; j++) // right
                {
                    if (i + j < str.length() && str[i + j] == 'H')
                    {
                        answer++;
                        str[i + j] = 'E';
                        break;
                    }
                }
            }
        }
    }
}
int main(void)
{
    input();
    sol();
    cout << answer << endl;
    return 0;
}