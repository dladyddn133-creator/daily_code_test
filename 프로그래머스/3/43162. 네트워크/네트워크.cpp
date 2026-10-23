#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void bfs(const vector<vector<int>>&computers, vector<int>& visited, int start, int n)
{
    queue<int> q;
    q.push(start);
    while(!q.empty())
    {
        for(int i=0;i<n;i++)
        {
            if(computers[q.front()][i]==1 && visited[i]==0)
            {
                q.push(i);
            }
        }
        visited[q.front()]=1;
        q.pop();
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<int> visited(n,0);
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0)
        {
            bfs(computers, visited, i, n);
            count++;
        }
    }
    answer = count;
    return answer;
}