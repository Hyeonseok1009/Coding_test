#include <string>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;
int solution(vector<int> scoville, int K) {
    int answer = 0;
    //priority_queue 에 모든 값을 집어 넣고, 두개 뺀뒤, 연산후, 두개를 더한다.
    priority_queue< int, vector<int>, greater<int> > q;
    for(auto a : scoville){
        q.push(a);
    }
    int x1;
    int x2;
    int y = 0;
    
    while(1){
        if(q.top() > K) break;
        if(q.size() < 2){
            answer = -1;
            break;
        }
        x1 = q.top();
        q.pop();
        x2 = q.top();
        q.pop();
        y = x1 + x2*2;
        q.push(y);
        answer++;
    }
    return answer;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> scoville = {1, 2, 3, 9, 10, 12};
    int k = 7;
    int ans = solution(scoville,k);
    cout << ans << " ";
    return 0;
}