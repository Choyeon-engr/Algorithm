#include <vector>

using namespace std;

int max(int a, int b, int c)
{
    if (a >= b)
    {
        if (a >= c)
            return a;
        else
            return c;
    }
    else
    {
        if (b >= c)
            return b;
        else
            return c;
    }
}

vector<int> solution(vector<int> answers)
{
    vector<int> answer;
    int answerSheet1[5] = {1, 2, 3, 4, 5};
    int answerSheet2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int answerSheet3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int score1 = 0, score2 = 0, score3 = 0, maxScore;
    
    for (int i = 0; i < answers.size(); ++i)
    {
        if (answerSheet1[i % 5] == answers[i])  { ++score1; }
        if (answerSheet2[i % 8] == answers[i])  { ++score2; }
        if (answerSheet3[i % 10] == answers[i]) { ++score3; }
    }
    
    maxScore = max(score1, score2, score3);
    
    if (score1 == maxScore) { answer.emplace_back(1); }
    if (score2 == maxScore) { answer.emplace_back(2); }
    if (score3 == maxScore) { answer.emplace_back(3); }
    
    return answer;
}
