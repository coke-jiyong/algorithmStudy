#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
int main(void)
{
    int N;
    cin >> N;
    string *arr;

    arr = new string[N];

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++)
        cout << arr[i] << endl;
}