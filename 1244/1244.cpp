#include <iostream>
#include <map>
using namespace std;

int studentN;
int N;
bool change_status(bool i)
{
    if (i)
        return false;
    else
        return true;
}
void man(bool arr[100], int num)
{
    for (int i = 1; i < N + 1; i++)
    {
        if (i % num == 0)
        {
            arr[i] = change_status(arr[i]);
        }
    }
}

void woman(bool arr[100], int num)
{
    int i = 1;
    while (arr[num - i] == arr[num + i])
    {
        if (num - i < 0 || num + i > N)
        {
            break;
        }
        arr[num - i] = change_status(arr[num - i]);
        arr[num + i] = change_status(arr[num + i]);
        i++;
    }
    arr[num] = change_status(arr[num]);
}

int main(void)
{
    cin >> N;
    bool arr[100];
    for (int i = 1; i < N + 1; i++)
    {
        cin >> arr[i];
    }

    cin >> studentN;
    for (int i = 0; i < studentN; i++)
    {
        int gender, num;
        cin >> gender >> num;

        if (gender == 1)
        {
            man(arr, num);
        }
        else
        {
            woman(arr, num);
        }
    }

    for (int i = 1; i < N + 1; i++)
    {
        cout << arr[i] << ' ';
        if (i % 20 == 0)
            cout << '\n';
    }

    return 0;
}