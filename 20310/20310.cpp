#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
string S;
string zero = "";
string one = "";
void input();
void sol();

int main(void)
{
    input();
    sol();
    return 0;
}

void input()
{
    cin >> S;

    for (auto &c : S)
    {
        if (c == '0')
            zero.push_back(c);
        else
            one.push_back(c);
    }
}

void sol()
{
    int len = zero.length();
    for (int i = 0; i < len / 2; i++)
        zero.pop_back();

    len = one.length();
    for (int i = 0; i < len / 2; i++)
        one.pop_back();

    cout << zero << one << endl;
    return;
}