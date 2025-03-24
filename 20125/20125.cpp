#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

pair<int, int> print_heart_pos(string *arr, int N)
{
    pair<int, int> pos;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < arr[i].length(); j++)
        {
            if (arr[i][j] == '*')
            {
                pos.first = i + 1;
                pos.second = j;
                // cout << "Heart position : ";
                cout << i + 1 + 1 << ' ' << j + 1 << endl;
                return pos;
            }
        }
    }
    return pos;
}

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

    pair<int, int> heartPos = print_heart_pos(arr, N);
    int left = 0;
    for (int i = 0; i < arr[0].length(); i++)
    {
        if (i == heartPos.second)
            break;
        if (arr[heartPos.first][i] == '*')
            left++;
    }
    // cout << "left : " << left << endl;
    cout << left << ' ';

    int right = 0;
    for (int i = heartPos.second + 1; i < arr[0].length(); i++)
    {
        if (arr[heartPos.first][i] != '*')
            break;
        right++;
    }

    // cout << "right : " << right << endl;
    cout << right << ' ';

    int waist = 0;
    int leftFoot = 0, rightFoot = 0;
    for (int i = heartPos.first + 1; i < N; i++)
    {
        if (arr[i][heartPos.second] != '*')
        {
            // 오른,왼다리 구하고 브레이크
            for (int j = i; j < N; j++)
            {
                if (arr[j][heartPos.second - 1] == '*')
                    leftFoot++;

                if (arr[j][heartPos.second + 1] == '*')
                    rightFoot++;
            }

            break;
        }
        waist++;
    }

    // cout << "waist : " << waist << endl;
    cout << waist << ' ';
    // cout << "left foot : " << leftFoot << endl;
    cout << leftFoot << ' ';
    // cout << "right foot : " << rightFoot << endl;
    cout << rightFoot << endl;
    delete[] arr;

    return 0;
}