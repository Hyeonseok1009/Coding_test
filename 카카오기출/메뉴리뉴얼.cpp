#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
map <string,int> m[11];
string tmp(2001,0);
void combinations(int depth,int nexts,int r,string a){
    if(depth == r){
        string a = tmp.substr(0,r);
        cout << a <<" ";
        m[r][a]++;
    }else{
        for(int i = nexts; i < a.size();i++){
            tmp[depth] = a[i];
            combinations(depth+1, i+1, r, a);
        }
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for(auto i : course){
        for(auto str : orders){
            if(str.size() >= i){
                sort(str.begin(),str.end());
                combinations(0,0,i,str);
            }
        }
    }
    int max = 2;
    for(auto i : course){
        for(auto a= m[i].begin() ; a != m[i].end(); a++){
            if(a->second >= max){
                max = a->second;
            }
        }
        for(auto a= m[i].begin() ; a != m[i].end(); a++){
            if(a->second == max){
                answer.push_back(a->first);
            }
        }
        max = 2;
    }
    sort(answer.begin(),answer.end());
    for(auto a : answer) cout << a <<" ";

    return answer;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<string> orders={"XYZ", "XWY", "WXA"};
    vector<int> course={2,3,4};
    vector<string> answer = solution(orders,course);

    //for(auto a : answer) cout << a <<" ";
    return 0;
}