#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> chayuk(n+1,0);
    for(auto a : lost){
        chayuk[a]--;
    }
    for(auto a : reserve){
        chayuk[a]++;
    }
    for(int i = 1 ; i<= n ;i++){
        if(chayuk[i] == -1){
            if(i>1 && chayuk[i-1] == 1){
                chayuk[i-1] = 0;
                chayuk[i]++;
            }else if(i <n && chayuk[i+1] == 1){
                chayuk[i+1] = 0;
                chayuk[i]++;    
            }
        }
    }
    chayuk[0] = -1;
    for(auto a : chayuk){
        //cout << a <<" ";
        if(a >=0) answer++;
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> lost = {3};
    vector<int> reserve = {1};
    int n = 3;
    int ans = solution(n, lost, reserve);
    cout << ans << " ";
    return 0;
}