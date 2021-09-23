#include <string>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    vector<int> ptr(times.size(),1);
    int cnt = 0;
    priority_queue <pair<long long, int>, vector< pair<long long, int> > ,greater<pair<long long, int>>  > q;
    for(int i = 0 ; i < times.size() ;i++){
        q.push({(long long)times[i]*ptr[i],i});
    }
    for(int j = 0 ; j < n ;j++){
        int time = q.top().first;
        cout << time <<" ";
        int x = q.top().second;
        q.pop();
        if(j == n-1){
            answer = time;
        }else{
            ptr[x]++;
            q.push({(long long)times[x]*ptr[x],x});
        }
    }
    return answer;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> times = {7,10};
    int n = 6;
    long long ans = solution(n,times);
    cout << ans << " ";
    return 0;
}