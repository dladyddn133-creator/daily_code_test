#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int bfs(vector<string>& storage, vector<string>& requests, vector<vector<bool>>& visited)
{
    vector<int> dx={1, -1, 0, 0};
    vector<int> dy={0, 0, 1, -1};
    queue<pair<int, int>> next;
    queue<pair<int, int>> remove;
    for(const auto& r: requests)
    {
        vector<vector<bool>> current_visited(visited.size(), vector<bool>(visited[0].size(), false));
        if(r.size()==1)
        {
            next.push({0,0});
        }
        while(r.size()==1 && !next.empty())
        {
            for(int i=0;i<4;i++)
            {
                int nx = next.front().second + dx[i];
                int ny = next.front().first + dy[i];
                
                if(nx<0 || nx >=visited[0].size() || ny<0 || ny>=visited.size())
                    continue;
                if(visited[ny][nx]==true && current_visited[ny][nx]==false)
                {
                    current_visited[ny][nx]=true;
                    next.push({ny,nx});
                }
                if(visited[ny][nx]==false && current_visited[ny][nx]==false && storage[ny-1][nx-1]==r[0])
                {
                    current_visited[ny][nx]=true;
                    remove.push({ny,nx});
                }
            }
            next.pop();
        }
        while(!remove.empty())
        {
            int x=remove.front().second;
            int y=remove.front().first;
            visited[y][x]=true;
            remove.pop();
        }
        if(r.size()==2)
        {
            for(int i=1;i<visited.size()-1;i++)
            {
                for(int j=1;j<visited[0].size()-1;j++)
                {
                    if(storage[i-1][j-1]==r[0])
                    {
                        visited[i][j]=true;
                    }
                }
            }
        }
    }
    int result=0;
    for(int i=0;i<visited.size();i++)
    {
        for(int j=0;j<visited[0].size();j++)
        {
            if(visited[i][j]==false)
                result++;
        }
    }
    return result;
}
int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    vector<vector<bool>> visited(storage.size()+2, vector<bool>(storage[0].size()+2, true));
    for(int i=1;i<visited.size()-1;i++)
    {
        for(int j=1;j<visited[0].size()-1;j++)
        {
            visited[i][j]=false;
        }
    }
    answer = bfs(storage, requests, visited);
    
    
    
    return answer;
}