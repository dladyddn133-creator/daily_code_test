#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    vector<vector<int>> route(n+1,vector(m+1,0));
    // route[1][1]=1;
    for(const auto& p : puddles)
    {
        route[p[1]][p[0]] = -1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i==1&&j==1)
            {
                route[1][1]=1;
            }
            else if(route[i][j]<0)
            {
                route[i][j]=0;
            }
            else
            {
                route[i][j]=(route[i][j-1]+route[i-1][j])%1000000007;
            }
        }
    }
    answer = route[n][m]%1000000007;
    
    return answer;
}