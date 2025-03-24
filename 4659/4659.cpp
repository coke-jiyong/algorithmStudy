#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool whats_al(char a)
{ // true -> 모음 false -> 자음
    if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
    {
        return true;
    }
    return false;
}
// 모음(a,e,i,o,u) 하나를 반드시 포함하여야 한다.
bool check_1(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
        {
            return true;
        }
    }
    return false;
}
// 모음이 3개 혹은 자음이 3개 연속으로 오면 안 된다.
bool check_2(string str)
{
    int len = str.length();
    bool *res = new bool[len];
    for (int i = 0; i < len; i++)
    {
        res[i] = whats_al(str[i]);
    }

    for (int i = 0; i < len; i++)
    {
        int a = i + 1;
        int b = i + 2;
        if (a > len - 1 || b > len - 1)
        {
            return true;
        }

        if (res[i] == res[a])
        {
            if (res[a] == res[b])
            {
                return false;
            }
        }
    }
    return true;
}
// 같은 글자가 연속적으로 두번 오면 안되나, ee 와 oo는 허용한다.
bool check_3(string str)
{
    int len = str.length();

    for (int i = 0; i < len; i++)
    {
        if (i + 1 > len - 1)
            return true;

        if (str[i] == str[i + 1])
        {
            if (str[i] == 'e' || str[i] == 'o')
                continue;

            return false;
        }
    }
    return true;
}

int main(void)
{
    string str;
    while (1)
    {
        cin >> str;
        if (!str.compare("end"))
            break;

        if (check_1(str) && check_2(str) && check_3(str))
        {
            cout << '<' << str << '>' << " is acceptable.\n";
        }
        else
        {
            cout << '<' << str << '>' << " is not acceptable.\n";
        }
    }

    return 0;
}
