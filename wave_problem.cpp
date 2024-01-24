#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int main() {
    std::vector<std::vector<int>> matrix = {
        {0,-20,0,0},
        {0,0,0,0},
        {0,-1,70,0},
        {0,0,0,0}
    };
    std::queue<std::pair<int, int>> q;
    std::pair<int, int> result_pair;
    std::pair<int, int> start_pair = {1, 0};
    q.push(start_pair);

    std::vector<int> position_x = {-1, 0, 1, 0};
    std::vector<int> position_y = {0, -1, 0, 1};

    while(!q.empty()) {
        std::pair<int, int> current_c = q.front();
        q.pop();
        for (int i = 0; i < position_x.size(); ++i) {
            int X = current_c.first + position_x[i];
            int Y = current_c.second + position_y[i];
            if (X >= 0 && X < matrix.size() && Y >= 0 && Y < matrix.size()) {
                if (matrix[Y][X] == 0){
                    if (matrix[current_c.second][current_c.first] == -20) {
                        matrix[Y][X] = 1;
                    }
                    else {
                        matrix[Y][X] = matrix[current_c.second][current_c.first] + 1;
                    }
                    q.push({X, Y});
                }
                else if (matrix[Y][X] == 70) {
                    while (!q.empty()) q.pop();
                    result_pair = current_c;
                }
            }
        }
    }
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix.size(); ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::vector<std::pair<int, int>> way;

    int current_x = result_pair.first;
    int current_y = result_pair.second;

    way.push_back({current_x, current_y});

    while (matrix[current_y][current_x] != -20) {
        for (int i = 0; i < position_x.size(); ++i) {
            int X = current_x + position_x[i];
            int Y = current_y + position_y[i];

            if (X >= 0 && X < matrix.size() && Y >= 0 && Y < matrix.size() && matrix[Y][X] < matrix[current_y][current_x]) {
                current_x = X;
                current_y = Y;
                way.push_back({X, Y});
                break;
            }
        }
    }
    std::reverse(way.begin(), way.end());

    //Result

    for (int i = 0; i < way.size(); ++i) {
        std::cout << "(" << way[i].first << "," << way[i].second << ")" << std::endl;
    }
    return 0;
}