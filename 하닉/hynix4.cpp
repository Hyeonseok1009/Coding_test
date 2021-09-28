#include <vector>
#include <queue>
#include <iostream>
#define pii pair<int,int>
using namespace std;

vector< vector< pii >> adjList(100);
int ch[30];
int minn = 2147000000;
int maxx = 0; 
struct Edge{
	int e;
	int val;
	Edge(int a, int b){
		e=a;
		val=b;
	}
	bool operator<(const Edge &b)const{
		return val>b.val;
	}
};

//[[1,2,3][1,3,3],[2,3,2]]
int solution(vector<vector<int>> dist, int pos1, int pos2) {
    priority_queue<Edge> Q;
    int res = 0;
    for (vector<int> d : dist) {
        // bidirectional graph
        adjList[d[0]].push_back({d[1], d[2]});
        adjList[d[1]].push_back({d[0], d[2]});
		if(minn > d[0]) minn = d[0];
		if(minn > d[1]) minn = d[1];
		if(maxx < d[0]) maxx = d[0];
		if(maxx < d[1]) maxx = d[1];
    }
    Q.push(Edge(pos1, 0));
    Q.push(Edge(pos2, 0));
	ch[pos1] = 1;
	ch[pos2] = 1;
	while(1){
		Edge tmp=Q.top();
		Q.pop();
		int v=tmp.e;
		int cost=tmp.val; 
		if(ch[v]==0){
			res+=cost;
			ch[v] = 1;
			cout <<cost<<" ";
		}	
		int flag = 1;
		for(int i = minn; i <= maxx; i++){
			if(ch[i] == 0){
				flag = 0;
				break;
			}
		}
		if(flag) break;
		for(int i= 0; i<adjList[v].size(); i++){
			if(ch[adjList[v][i].first] == 0)
				Q.push(Edge(adjList[v][i].first, adjList[v][i].second));
		}
	}

    return res;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   // vector<vector<int>> dist = {{1,2,3},{1,3,3},{2,3,2}};
	vector<vector<int>> dist = {{1,2,1},{1,3,3},{1,4,3},{2,3,2},{2,4,3},{3,4,2}};

    int pos1 = 1;
	int pos2 = 3;

    int ans = solution(dist, pos1, pos2);
   // cout << ans << " ";
    return 0;
}