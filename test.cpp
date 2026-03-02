#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cctype>

using namespace std;

// 状态结构体：火人位置, 冰人位置, 当前步数
struct State {
    int f, i, dist;
};

int R, C;
vector<string> grid;
// 记录访问过的状态: [火人位置][冰人位置]
// 25*25 = 625，所以数组大小设为 625x625
int visited[625][625];

// 辅助函数：获取坐标对应的索引
int get_idx(int r, int c) { return r * C + c; }

// 辅助函数：判断某人是否踩在某个门对应的【任意一个】开关上
bool isOnSwitch(int pos_idx, char door_type) {
    char target_switch = tolower(door_type);
    int r = pos_idx / C, c = pos_idx % C;
    return grid[r][c] == target_switch;
}

// 核心规则检查
bool isValid(int f1, int i1, int f2, int i2) {
    int fr2 = f2 / C, fc2 = f2 % C;
    int ir2 = i2 / C, ic2 = i2 % C;

    // 1. 边界与墙壁检查
    if (fr2 < 0 || fr2 >= R || fc2 < 0 || fc2 >= C || grid[fr2][fc2] == '#') return false;
    if (ir2 < 0 || ir2 >= R || ic2 < 0 || ic2 >= C || grid[ir2][ic2] == '#') return false;

    // 2. 检查所有可能的门 (A, B, C)
    for (char door : {'A', 'B', 'C'}) {
        bool f_involve = (grid[f1 / C][f1 % C] == door || grid[fr2][fc2] == door);
        bool i_involve = (grid[i1 / C][i1 % C] == door || grid[ir2][ic2] == door);

        // 门通行规则：如果有人在这一步涉及门（起点或终点是门）
        if (f_involve || i_involve) {
            bool switch_active_S0 = (isOnSwitch(f1, door) || isOnSwitch(i1, door));
            bool switch_active_S1 = (isOnSwitch(f2, door) || isOnSwitch(i2, door));
            if (!switch_active_S0 || !switch_active_S1) return false;
        }

        // 开关保护规则：如果 Sn 时刻有人在门上，另一人在对应开关上
        // 检查火人在门，冰人在开关的情况
        if (grid[f1 / C][f1 % C] == door && isOnSwitch(i1, door)) {
            if (i1 != i2) return false; // 踩开关的人不能动
        }
        // 检查冰人在门，火人在开关的情况
        if (grid[i1 / C][i1 % C] == door && isOnSwitch(f1, door)) {
            if (f1 != f2) return false; // 踩开关的人不能动
        }
    }
    return true;
}

int main() {
    if (!(cin >> R >> C)) return 0;
    int start_f = -1, start_i = -1, target = -1;
    grid.resize(R);

    for (int r = 0; r < R; ++r) {
        cin >> grid[r];
        for (int c = 0; c < C; ++c) {
            if (grid[r][c] == 'F') start_f = get_idx(r, c);
            if (grid[r][c] == 'I') start_i = get_idx(r, c);
            if (grid[r][c] == 'X') target = get_idx(r, c);
        }
    }

    // 初始化访问数组
    for (int i = 0; i < 625; ++i)
        for (int j = 0; j < 625; ++j) visited[i][j] = 0;

    queue<State> q;
    q.push({start_f, start_i, 0});
    visited[start_f][start_i] = 1;

    int dr[] = {0, 0, 0, 1, -1}; // 不动, 右, 左, 下, 上
    int dc[] = {0, 1, -1, 0, 0};

    while (!q.empty()) {
        State curr = q.front();
        q.pop();

        // 终点判断：两人都在 X
        if (curr.f == target && curr.i == target) {
            cout << curr.dist << endl;
            return 0;
        }

        // 尝试 5x5 = 25 种移动组合
        for (int fi = 0; fi < 5; ++fi) {
            for (int ii = 0; ii < 5; ++ii) {
                int nf_r = (curr.f / C) + dr[fi], nf_c = (curr.f % C) + dc[fi];
                int ni_r = (curr.i / C) + dr[ii], ni_c = (curr.i % C) + dc[ii];
                
                int next_f = get_idx(nf_r, nf_c);
                int next_i = get_idx(ni_r, ni_c);

                // 越界预判，防止 isValid 数组溢出
                if (nf_r < 0 || nf_r >= R || nf_c < 0 || nf_c >= C) continue;
                if (ni_r < 0 || ni_r >= R || ni_c < 0 || ni_c >= C) continue;

                if (!visited[next_f][next_i] && isValid(curr.f, curr.i, next_f, next_i)) {
                    visited[next_f][next_i] = 1;
                    q.push({next_f, next_i, curr.dist + 1});
                }
            }
        }
    }

    cout << -1 << endl;
    return 0;
}