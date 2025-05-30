#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class teamInfo
{
    int ID;
    vector<int> questions;
    int numberOfSubmissions;
    int lastSubmiisions;
    int totalScore;

public:
    teamInfo(int _ID) : ID(_ID)
    {
        questions.resize(101);
        numberOfSubmissions = 0;
        totalScore = 0;
        lastSubmiisions = 0;
    }
    void set_info(int qNum, int score, int time)
    {
        if (questions[qNum] < score)
        {
            totalScore -= questions[qNum];
            questions[qNum] = score;
            totalScore += questions[qNum];
        }
        numberOfSubmissions++;
        lastSubmiisions = time;
    }
    int get_id() { return ID; }
    int get_total_score() { return totalScore; }
    int get_number_of_submissions() { return numberOfSubmissions; }
    int get_last_submission() { return lastSubmiisions; }
};

vector<teamInfo> teams;
int t; // 내 팀ID

bool is_exist(int id)
{
    for (auto &i : teams)
        if (i.get_id() == id)
            return true;
    return false;
}

void input()
{
    int n; // 팀 개수 3~100
    int k; // 문제 개수 3~100
    int m; // 로그 개수 3~10000
    cin >> n >> k >> t >> m;
    for (int j = 0; j < m; j++)
    {
        int teamId, question, score;
        cin >> teamId >> question >> score;
        if (is_exist(teamId))
        {
            for (auto &team : teams)
            {
                if (team.get_id() == teamId)
                {
                    team.set_info(question, score, j);
                    break;
                }
            }
        }
        else
        {
            teamInfo t = teamInfo(teamId);
            t.set_info(question, score, j);
            teams.push_back(t);
        }
    }
}

bool cmp(teamInfo a, teamInfo b)
{
    int aScore = a.get_total_score();
    int bScore = b.get_total_score();
    if (aScore == bScore)
    {
        int aSub = a.get_number_of_submissions();
        int bSub = b.get_number_of_submissions();
        if (aSub == bSub)
        {
            int aLast = a.get_last_submission();
            int bLast = b.get_last_submission();
            return aLast < bLast;
        }
        else
            return aSub < bSub;
    }
    else
        return aScore > bScore;
}

void debug(vector<teamInfo> v)
{
    int rank = 1;
    for (auto &i : v)
        cout << rank++ << "등 " << "ID: " << i.get_id() << " score: " << i.get_total_score() << " 제출횟수: " << i.get_number_of_submissions() << " 제출시간: " << i.get_last_submission() << endl;
}

void sol()
{
    sort(teams.begin(), teams.end(), cmp);
    // debug(teams);
    int rank = 1;
    for (auto &team : teams)
    {
        if (team.get_id() == t)
        {
            cout << rank << endl;
            break;
        }
        rank++;
    }
    teams.clear();
}
int main(void)
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        input();
        sol();
    }
    return 0;
}