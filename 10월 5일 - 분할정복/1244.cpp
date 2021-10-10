//
// Created by 김채린 on 2021/10/10.
//

#include <iostream>
#include <vector>

using namespace std;

int toggle(int input) {
    if (input == 0) return 1;
    return 0;
}

int main() {

    // 스위치 개수
    int n;
    cin >> n;

    // 각 스위치의 상태
    vector<int> switch_state(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> switch_state[i];
    }

    // 학생 수
    int m;
    cin >> m;


    // 각 학생이 스위치 조작
    for (int i = 0; i < m; i++) {

        // 성별(남학생 : 1, 여학생 : 2)
        int sex;
        cin >> sex;

        // 학생이 받은 수
        int num;
        cin >> num;

        // 남학생일 경우
        if (sex == 1) {
            for (int j = 1; j <= n; j++) {
                if (j % num == 0)
                    switch_state[j] = toggle(switch_state[j]);
            }
        }

        // 여학생일 경우
        if (sex == 2) {
            switch_state[num] = toggle(switch_state[num]);
            int j = 0;
            while (true) {
                j++;
                if (num + j > n || num - j <= 0 || switch_state[num - j] != switch_state[num + j])
                    break;
                switch_state[num - j] = toggle(switch_state[num - j]);
                switch_state[num + j] = toggle(switch_state[num + j]);
            }

        }

    }

    // 출력
    for (int i = 1; i <= n; i++) {
        cout << switch_state[i] << ' ';
        if (i % 20 == 0)
            cout << '\n';
    }

}