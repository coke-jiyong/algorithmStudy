#include <iostream>
#include <map>
#include <string>
#define Y 2
#define F 3
#define O 4

using namespace std;
int main(void)
{
    int N;
    string game;

    cin >> N;
    cin >> game;
    map<string, int> map;
    for (int i = 0; i < N; i++)
    {
        string name;
        cin >> name;

        map.insert({name, 1});
    }

    if (!game.compare("Y"))
    {
        cout << map.size() << endl;
    }
    else if (!game.compare("F"))
    {
        cout << map.size() / 2 << endl;
    }
    else
    {
        cout << map.size() / 3 << endl;
    }

    // cout << "map :" << endl;
    // for (auto i : map)
    // {
    //     cout << i.first << " : " << i.second << endl;
    // }

    return 0;
}