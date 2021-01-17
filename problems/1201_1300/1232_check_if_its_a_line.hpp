#include "ios_include.hpp"

/*
 * @brief 在一个 XY 坐标系中有一些点，我们用数组 coordinates 来分别记录它们的坐标，其中 coordinates[i] = [x, y] 表示横坐标为 x、纵坐标为
 * y 的点。请你来判断，这些点是否在该坐标系中属于同一条直线上，是则返回 true，否则请返回 false。
 * @note 利用斜率计算即可(y1 - y)(x2 - x) = (x1 - x)(y2 - y)
 */
bool checkStraightLine(vector<vector<int>> &coordinates) {
    int len = coordinates.size();
    if (2 == len)
        return true;
    int x = coordinates[0][0], y = coordinates[0][1]; //锚点
    int x1 = coordinates[1][0], y1 = coordinates[1][1];
    int yy1 = y1 - y, xx1 = x1 - x;
    for (int i = 2; i < len; i++) {
        int x2 = coordinates[i][0], y2 = coordinates[i][1];
        if (yy1 * (x2 - x) != xx1 * (y2 - y))
            return false;
    }

    return true;
}