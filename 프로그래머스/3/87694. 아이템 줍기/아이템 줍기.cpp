#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int bfs(const vector<vector<int>>&board, int do_cx, int do_cy, int do_ix, int do_iy)
{
    queue<pair<int, int>> q;
    vector<vector<int>> dist(102,vector<int>(102,0));
    vector<vector<int>> visited(102,vector<int>(102,0));
    q.push({do_cy, do_cx});
    visited[do_cy][do_cx]=1;
    
    vector<int> dx = {1,-1,0,0};
    vector<int> dy = {0,0,1,-1};
    
    while(!q.empty())
    {
        int x=q.front().second;
        int y=q.front().first;
        for(int i=0;i<4;i++)
        {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(board[ny][nx] == 0)
                continue;
            if(visited[ny][nx]==1)
                continue;
            visited[ny][nx]=1;
            dist[ny][nx]=dist[y][x]+1;
            q.push({ny,nx});
        }
        if(x== do_ix && y == do_iy)
            return dist[y][x]/2;
        q.pop();
    }
    return 0;
}
int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    vector<vector<int>> double_rectangle = rectangle;
    for(auto& do_re : double_rectangle)
    {
        for(int i=0;i<4;i++)
        {
            do_re[i]*=2;
        }
    }
    vector<vector<int>> board(102,vector<int>(102,0));
    for(const auto& do_re : double_rectangle)
    {
        for(int i=do_re[0];i<=do_re[2];i++)
        {
            for(int j=do_re[1];j<=do_re[3];j++)
            {
                board[j][i]=1;
            }
        }
    }
    for(const auto& do_re : double_rectangle)
    {
        for(int i=do_re[0]+1;i<do_re[2];i++)
        {
            for(int j=do_re[1]+1;j<do_re[3];j++)
            {
                board[j][i]=0;
            }
        }
    }
    answer = bfs(board, 2*characterX, 2*characterY, 2*itemX, 2*itemY);
    
    return answer;
}