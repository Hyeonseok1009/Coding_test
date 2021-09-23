#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    //1. �۾��� ���� �Ϸ� ��¥
    //2. �ճ�¥ ���� ũ�� �״��, ������ �ճ�¥�� ������
    //3. ��ȸ ���鼭 ���� ���� ������ ī��Ʈ �ؼ� �信���� ��ȯ
         // �ٸ��� ��ȯ�ؾߴ�. ��谪�� �׻� �����ؾߴ�

    //1. �۾� �� ���� �Ϸ� ��¥
    vector<int> perfect_day;
    for(int i = 0 ; i <progresses.size(); i++){
        int tmp = ceil((100 - progresses[i]) /(float)speeds[i]);
        if(i >0){
            if(perfect_day[i-1] > tmp) tmp = perfect_day[i-1];
        }
        perfect_day.push_back(tmp);
    }
    int tmp = perfect_day[0];
    int cnt = 1;
    for(int i = 1 ; i <perfect_day.size(); i++){
        if(perfect_day[i] == perfect_day[i-1]){
            cnt++;
            if(i == perfect_day.size()-1){
                answer.push_back(cnt);
            }
        }else{
            answer.push_back(cnt);
            cnt = 1;
            if(i == perfect_day.size()-1){
                answer.push_back(cnt);
            }
        }
    }
    
    return answer;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> progresses = {95, 90, 99, 99, 80, 99};
    vector<int> speeds = {1, 1, 1, 1, 1, 1};

    vector<int> ans = solution(progresses, speeds);
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    return 0;
}