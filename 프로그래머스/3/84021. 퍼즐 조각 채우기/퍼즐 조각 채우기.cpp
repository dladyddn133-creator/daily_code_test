#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

using Shape = vector<vector<pair<int, int>>>; 

void normalization(vector<pair<int, int>>& member)
{
    int min_x=100000;
    int min_y=100000;
    
    for(const auto& m : member)
    {
        min_x=min(min_x, m.second);
        min_y=min(min_y, m.first);
    }
    for(auto& m : member)
    {
        m.second -= min_x;
        m.first -= min_y;
    }
    sort(member.begin(),member.end());
}
Shape shape_bfs(vector<vector<int>>& game_board)
{
    Shape members;
    
    int h = game_board.size();
    int w = game_board[0].size();
    vector<int> dx={1, -1, 0, 0};
    vector<int> dy={0, 0, 1, -1};
    
    queue<pair<int, int>> next;
    // vector<vector<bool>> visited(game_board.size(), vector<bool>(game_board[0].size(), false));
    
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            vector<pair<int, int>> member;
            if(game_board[i][j]==0)
            {
                member.push_back({i, j});
                game_board[i][j]=1;    
                next.push({i,j});
            }
            while(!next.empty())
            {
                for(int k=0;k<4;k++)
                {
                    int x = next.front().second;
                    int y = next.front().first;
                    
                    int nx = x+dx[k];
                    int ny = y+dy[k];
                    
                    if(nx<0 || nx>=w || ny<0 || ny>=h)
                        continue;
                    
                    if(game_board[ny][nx]==1)
                        continue;
                    
                    if(game_board[ny][nx]==0)
                    {
                        member.push_back({ny, nx});
                        game_board[ny][nx]=1;    
                        next.push({ny,nx});
                    }
                }
                next.pop();
            }
            if(member.size() !=0)
                members.push_back(member);
        }
    }
    for(auto& member : members)
    {
        normalization(member);
    }
    
    return members;
}
Shape shape_bfs_table(vector<vector<int>>& table_board)
{
    Shape members;
    
    int h = table_board.size();
    int w = table_board[0].size();
    vector<int> dx={1, -1, 0, 0};
    vector<int> dy={0, 0, 1, -1};
    
    queue<pair<int, int>> next;
    // vector<vector<bool>> visited(game_board.size(), vector<bool>(game_board[0].size(), false));
    
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            vector<pair<int, int>> member;
            if(table_board[i][j]==1)
            {
                member.push_back({i, j});
                table_board[i][j]=0;    
                next.push({i,j});
            }
            while(!next.empty())
            {
                for(int k=0;k<4;k++)
                {
                    int x = next.front().second;
                    int y = next.front().first;
                    
                    int nx = x+dx[k];
                    int ny = y+dy[k];
                    
                    if(nx<0 || nx>=w || ny<0 || ny>=h)
                        continue;
                    
                    if(table_board[ny][nx]==0)
                        continue;
                    
                    if(table_board[ny][nx]==1)
                    {
                        member.push_back({ny, nx});
                        table_board[ny][nx]=0;    
                        next.push({ny,nx});
                    }
                }
                next.pop();
            }
            if(member.size() !=0)
                members.push_back(member);
        }
    }
    for(auto& member : members)
    {
        normalization(member);
    }
    
    return members;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    Shape game_shape = shape_bfs(game_board);
    Shape table_shape = shape_bfs_table(table);
    
    vector<bool> match(game_shape.size(), false);
    vector<bool> match_table(table_shape.size(), false);
    int index_match=0;
    int index_mtable=0;
    
    for(const auto& gs : game_shape)
    {
        index_mtable=0;
        for(auto& ts : table_shape)
        {
            for(int i=0;i<4;i++)
            {
                if(match[index_match]==false && match_table[index_mtable]==false && gs==ts)
                {
                    match[index_match]=true;
                    match_table[index_mtable]=true;
                    answer+=ts.size();
                }
                else if(match[index_match]==false && match_table[index_mtable]==false && gs!=ts)
                {
                    for(auto& t: ts)
                    {
                        int x=t.second;
                        int y=t.first;
                        t.second = -y;
                        t.first = x;
                    }
                    normalization(ts);
                }
            }
            index_mtable++;
        }
        index_match++;
    }
    
    return answer;
}