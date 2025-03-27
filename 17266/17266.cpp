#include <iostream>
#include <vector>
using namespace std;

int N, M;
// 0부터 pos[0] 이나 pos[len-1] 부터 N이 max 라면 / 2 하면 안됨.
// 즉 pos[0]이 max거나 , N - pos[len-1] 이 max라면 / 2하지 않는다.

//
int get_long_way(const vector<int> &pos)
{
    int len = pos.size();
    int max = N - pos[len - 1];

    if (len == 0)
    {
        return pos[0] > max ? pos[0] : max;
    }

    int firstPosFromFirst = pos[0];
    int lastPosFromLast = N - pos[len - 1];
    int standard = 0;
    for (int i = 0; i < len; i++)
    {
        int r = pos[i] - standard;
        if (r > max)
        {
            max = r;
        }
        standard = pos[i];
    }

    if (max == firstPosFromFirst || max == lastPosFromLast)
    {
        return max;
    }

    int currentMax = max % 2 == 0 ? max / 2 : max / 2 + 1;
    max = firstPosFromFirst > lastPosFromLast ? firstPosFromFirst : lastPosFromLast;

    if (currentMax >= max)
    {
        return currentMax;
    }
    else
    {
        return max;
    }
}

int main(void)
{
    // 굴다리 모든 길 0 ~ N
    // 가로등 설치할 개수 M, 위치 x
    // 가로등의 높이는 모두 같아야하고 정수.
    //  가로등의 위치 x 는 오름차순으로 입력받고 중복되지않으며 정수.

    cin >> N >> M;

    vector<int> pos;
    for (int i = 0; i < M; i++)
    {
        int k;
        cin >> k;
        pos.push_back(k);
    }

    int longWay = get_long_way(pos);
    cout << longWay << endl;
    return 0;
}
