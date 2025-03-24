#include <iostream>
#include <set>
#include <vector>
#include <string>
using namespace std;
int arr[26];
int main(void)
{
    int n;
    cin >> n;
    vector<char> v;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        v.push_back(str[0]);
    }
    // cout << "-----------" << endl;
    // cout << 'z' - 'a' << endl;
    for (int i = 0; i < n; i++)
    {
        arr[v[i] - 'a']++;
    }
    int chk = 0;
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] >= 5)
        {
            cout << (char)(i + 'a');
            chk = 1;
        }
    }
    if (!chk)
    {
        cout << "PREDAJA";
    }

    return 0;
}