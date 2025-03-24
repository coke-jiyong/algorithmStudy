#include <iostream>
#include <set>
using namespace std;
void print_result(set<int> s)
{
    for (set<int>::iterator i = s.begin(); i != s.end(); i++)
    {
        cout << *i << endl;
    }
}
int main(void)
{
    set<int> s;
    int sum = 0;
    for (int i = 0; i < 9; i++)
    {
        int in;
        cin >> in;
        s.insert(in);

        sum += in;
        if (sum == 100)
        {
            for (set<int>::iterator i = s.begin(); i != s.end(); i++)
            {
                cout << *i << '\n';
            }
            return 0;
        }
    }

    for (set<int>::iterator i = s.begin(); i != s.end(); i++)
    {
        for (set<int>::iterator j = s.begin(); j != s.end(); j++)
        {
            if (sum - *i - *j == 100)
            {
                s.erase(*i);
                s.erase(*j);
                print_result(s);
                return 0;
            }
        }
    }

    // sum = 0;
    // for (set<int>::iterator i = s.begin(); i != s.end(); i++)
    // {

    // }

    return 0;
}