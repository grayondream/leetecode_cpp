#include "ios_include.hpp"

/*
 * @brief 两个点之间的曼哈顿距离
 */
int mdistance(int x1, int x2, int y1, int y2) { return abs(x1 - x2) + abs(y1 - y2); }

/*
 * @brief 最小生成树，使用prim算法
 */
int minCostConnectPoints(vector<vector<int>> &points) {
    int len = points.size();
    vector<vector<int>> dis_matrix(len, vector<int>(len, 0)); //图的邻接矩阵表示
    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            dis_matrix[i][j] = mdistance(points[j][0], points[i][0], points[j][1], points[i][1]);
            dis_matrix[j][i] = mdistance(points[j][0], points[i][0], points[j][1], points[i][1]);
        }
    }

    vector<int> tree_distance(len, -1); //保存当前生成树和所有节点的最小距离，距离为0表示该节点已经在树上
    unordered_set<int> untree;          //未加入到树中的节点
    for (int i = 1; i < len; i++) {
        untree.insert(i);
    }

    //将第0个点加入到树中;
    for (int i = 0; i < len; i++) {
        tree_distance[i] = dis_matrix[0][i];
    }

    int ret_dis = 0;
    //之后逐个寻找当前未加入到树中的最小距离节点然后将该节点加入到树中
    while (!untree.empty()) {
        //寻找和当前树距离最小的节点;
        cout << tree_distance << endl;
        int min_id = 0;
        int min_dis = INT32_MAX;
        for (auto i : untree) {
            if (tree_distance[i] == 0)
                continue;

            if (min_dis > tree_distance[i]) {
                min_dis = tree_distance[i];
                min_id = i;
            }
        }

        //将min_id加入到树中，并将该节点从未加入节点中删除
        ret_dis += min_dis;
        tree_distance[min_id] = 0;
        untree.erase(min_id);

        //更新最小距离
        for (auto i : untree) {
            int dis = dis_matrix[min_id][i];
            tree_distance[i] = min(tree_distance[i], dis);
        }
    }

    return ret_dis;
}

void test_1584() {
    vector<vector<int>> pts{{0, 0}, {1, 1}, {1, 0}, {-1, 1}};
    int ret = minCostConnectPoints(pts);
    cout << ret << endl;
}