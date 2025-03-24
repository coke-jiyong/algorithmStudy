#include <iostream>
#include <cstring>

using namespace std;

int main(void)
{
    string str;
    char result[26] = {0};
    cin >> str;

    for (auto i : str)
    {
        result[i - 'a'] += 1;
    }

    for (auto i : result)
    {
        cout << (int)i << ' ';
    }
    return 0;
}