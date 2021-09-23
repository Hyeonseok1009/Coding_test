#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
int solution(string name) {
    int answer = 0;
    int alpabet = 'Z'-'A'+1; //26글자.
    int prev = -1; int cur = -1;
    int first = 0 ;int second = 0; int last = 0 ;
    int flag = 1;
    for(int i = 0 ; i < name.size() ; i++){
        char tmp = name[i];
        if(tmp != 'A') {
            if(flag == 2){
                second = i;
                last = i;
                flag = 3;
            }
            else if(flag == 1){
                first = i;
                second = i;
                last = i;
                flag = 2;
            }
            else{
                last = i;
            }
        }
        int cha = name[i] - 'A';
        //25,1 24,2, 23,3    13,13
        if(cha > 13) cha = 26 - cha;
        answer += cha;
        //////////////next 알파벳
        //정방향과 역방향을 결정.       
    }
    //첫번째 인덱스, 두번째 인덱스. 마지막 인덱스를 구한다.
    int plus = 0;//aaabv (5) 
    if(flag == 1){
        cout << "A";
        plus =first <= name.size()-first ? first : name.size()-first;
    }
    else {
        plus = last <= first + name.size()`-second? last:first + name.size()-second;
    }
    answer += plus;
    return answer;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string name="ZZAAAZZ";
    int ans = solution(name);
    cout << ans << " ";
    return 0;
}
