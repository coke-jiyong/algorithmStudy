#include <iostream>
using namespace std;

int main()
{
    string N;
    cin >> N;
    string answer;
    for (char &i : N)
    {
        int charInt = i - '0';
        if (charInt == 0)
        {
            answer += "000";
            continue;
        }
        string tmp;
        for (int i = 4; i >= 1; i /= 2)
        {
            tmp += (charInt / i + '0');
            charInt %= i;
        }
        answer += tmp;
    }
    size_t pos = answer.find_first_not_of('0');
    if (pos != string::npos)
        answer = answer.substr(pos);
    else
        answer = '0';
    cout << answer << endl;
    return 0;
}