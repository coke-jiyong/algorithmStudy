#include <iostream>
#include <cmath>
using namespace std;
int Ax, Ay, Bx, By;

float Distance(pair<int, int> pos1, pair<int, int> pos2)
{
    int x = pos1.first - pos2.first;
    int y = pos1.second - pos2.second;
    x *= x;
    y *= y;
    return sqrt(static_cast<double>(x + y));
}

void input()
{
    cin >> Ax >> Ay >> Bx >> By;
}

void sol()
{
}

int main(void)
{

    input();
    //    sol();
    cout << Distance({Ax, Ay}, {Bx, By}) << endl;
    return 0;
}