#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    const int INF = 1000000;
    
    vector<vector<pair<int, int>>> graph(N+1);
    
    vector<int>dist(N+1, INF);
    
    for(const auto& r : road)
    {
        //{마을번호, 이동시간}
        graph[r[0]].push_back({r[1], r[2]});
        graph[r[1]].push_back({r[0], r[2]});
    }
    dist[1] = 0;
    
    //{이동시간, 마을번호}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    pq.push({0, 1});
    while(!pq.empty())
    {
        int current_dist = pq.top().first; //->이동시간
        int current = pq.top().second; //->마을번호
        pq.pop();
        if (current_dist > dist[current])
            continue;
        
        
        for(const auto&g : graph[current])
        {
            int next = g.first;
            int next_cost = g.second;
            int new_dist = next_cost + current_dist;
            if(dist[next] > new_dist)
            {    
                dist[next] = new_dist;
                pq.push({dist[next], next});
            }
        }
        
    }
    int count=0;
    for(int i=1;i<N+1;i++)
    {
        if(dist[i]<=K)
            count++;
    }
    answer = count;
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}