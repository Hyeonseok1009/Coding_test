#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    // 다익스트라
    // 거리가 가장 가까운 정점을 선택해서 ,
    // 그 정점을 거쳐서 가는 것이 더 가까우면, 갱신한다.
    vector <int> graph[20000];
    for(int i = 0 ; i < edge.size() ; i++){
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }
    vector <int> dis(n+1,2147000000);
    vector <int> check(n+1,0);
    dis[1] = 0;
    for(int i = 1 ; i <= n ;i++){
        int minidx = 0;
        for(int j = 1 ; j <= n ;j++){
            if(check[j] == 0 && dis[minidx] > dis[j]) {
                minidx = j;
            }
        }
        if(minidx == 0) break;
        check[minidx] = 1;
        for(int i = 0 ; i < graph[minidx].size();i++){
             dis[graph[minidx][i]] = min(dis[graph[minidx][i]], dis[minidx] +1);
        }
    }
    int max= 0;
    for(int i = 1; i <dis.size(); i++){
        if(max < dis[i] ) max = dis[i];
    }
    for(int i = 1; i <dis.size(); i++){
        if( max == dis[i] )answer++;
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
     vector<vector<int>> edge = {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}}	;
    int n = 6;
    int ans = solution(n, edge);
    cout << ans << " ";
    return 0;
}