#include <string>
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    
    int answer = 1;
    map<string,int > m;
    for(auto a : clothes){
        m[a[1]]++;
    }
    for(auto b : m){
        answer *= (b.second+1);
    }   
    answer -= 1;
    return answer;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<vector<string>> clothes = {{"crowmask", "face"}, {"bluesunglasses", "face"}, {"smoky_makeup", "face"}};
    int ans = solution(clothes);
    cout << ans << " ";
    return 0;
}