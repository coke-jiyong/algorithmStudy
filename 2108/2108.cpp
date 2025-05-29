#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
vector<int> nums;
int N;

void input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        nums.push_back(n);
    }
}

int median()
{
    vector<int> v(nums);
    sort(v.begin(), v.end());
    cout << v[N / 2] << endl;
    return *--v.end() - *v.begin();
}

void avg()
{
    int n = 0;
    for (auto &i : nums)
        n += i;
    float answer = static_cast<float>(n) / N;
    int result = round(answer);
    if (result < 1 && result > -1)
        cout << 0 << endl;
    else
        cout << result << endl;
}

void mode()
{
    map<int, int> m;
    set<int> s;
    for (auto &i : nums)
        m[i]++;
    int max = 0;
    for (const auto &[key, value] : m)
        max = max < value ? value : max;
    for (const auto &[key, value] : m)
        if (value == max)
            s.insert(key);

    auto i = s.begin();
    if (s.size() == 1)
        cout << *i << endl;
    else
        cout << *++i << endl;
}

int main(void)
{
    input();
    avg();
    int range = median();
    mode();
    cout << range << endl;
    return 0;
}