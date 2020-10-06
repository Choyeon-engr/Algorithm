#include <vector>
#include <map>

using namespace std;

int solution(vector<int> arrows) {
    int answer = 0, x = 0, y = 0;
    map<pair<int, int>, int> vertexVisited;
    map<pair<pair<int, int>, pair<int, int>>, int> edgeVisited;
    int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    
    vertexVisited[{x, y}] = 1;
    
    for (int i = 0; i < arrows.size(); ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            int xPos = x + dx[arrows[i]];
            int yPos = y + dy[arrows[i]];
            
            if(vertexVisited[{xPos, yPos}] == 1)
                if(edgeVisited[{{x, y}, {xPos, yPos}}] == 0 || edgeVisited[{{xPos, yPos}, {x, y}}] == 0)
                    ++answer;
            
            vertexVisited[{xPos, yPos}] = 1;
            
            edgeVisited[{{x, y}, {xPos, yPos}}] = 1;
            edgeVisited[{{xPos, yPos}, {x, y}}] = 1;
            
            x = xPos;
            y = yPos;
        }
    }
    
    return answer;
}
