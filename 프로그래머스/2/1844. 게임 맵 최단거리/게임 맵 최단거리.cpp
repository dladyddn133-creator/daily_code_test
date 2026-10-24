#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int bfs(const vector<vector<int>>&maps)
{
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    vector<vector<int>> dist(maps.size(), vector<int>(maps[0].size(), 0));
    
    queue<pair<int, int>> q;
    dist[0][0] = 1;
    q.push({0,0});
    
    while(!q.empty())
    {
        int x=q.front().second;
        int y=q.front().first;
        for(int i=0;i<4;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= maps[0].size() || ny >= maps.size())
            {
                continue;
            }
            
            if(maps[ny][nx] == 0)
                continue;
            
            if(dist[ny][nx] >0)
                continue;
            
            q.push({ny, nx});
            dist[ny][nx]=dist[y][x] + 1;
        }
        if(x == maps[0].size()-1 && y == maps.size()-1)
        {
            return dist[y][x];
        }
        q.pop();
    }
    return -1;
}
int solution(vector<vector<int> > maps)
{
    int answer = 0;
    answer = bfs(maps);
    
    return answer;
}