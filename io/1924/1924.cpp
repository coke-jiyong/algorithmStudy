#include <iostream>
using namespace std;

int main(void)
{
    string days[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    int daysOfmonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int month, day;
    cin >> month >> day;

    for (int i = 1; i < month; i++)
    {
        day += daysOfmonth[i];
    }

    cout << days[day % 7] << endl;

    return 0;
}