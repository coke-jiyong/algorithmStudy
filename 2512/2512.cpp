#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
int main(void)
{
    cin >> N;
    vector<int> req(N);
    for (int i = 0; i < N; i++)
    {
        cin >> req[i];
    }
    int M;
    cin >> M;
    sort(req.begin(), req.end());

    int end = req[N - 1];
    for (; 0 <= end; end--)
    {
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            if (req[i] >= end)
            {
                sum += end;
            }
            else
            {
                sum += req[i];
            }
        }
        if (sum <= M)
        {
            cout << end << endl;
            break;
        }
    }
    return 0;
}
// int N;
// int main(void)
// {
//     cin >> N;
//     vector<int> req(N);
//     for (int i = 0; i < N; i++)
//     {
//         cin >> req[i];
//     }
//     int M;
//     cin >> M;
//     sort(req.begin(), req.end());

//     int left = 0;
//     int right = req[N - 1];

//     while (left <= right)
//     {
//         int sum = 0;
//         int mid = (left + right) / 2;

//         for (int i = 0; i < N; i++)
//         {
//             if (req[i] < mid)
//             {
//                 sum += req[i];
//             }
//             else
//             {
//                 sum += mid;
//             }
//         }
//         if (sum <= M)
//         {
//             left = mid + 1;
//         }
//         else
//         {
//             right = mid - 1;
//         }
//     }
//     cout << right << endl;
//     return 0;
// }