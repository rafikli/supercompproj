#include <iostream>
#include <string>

int heuristic(int x, int y, int x1, int y1) {
    return abs(x - x1) + abs(y - y1);
}
int main() {
    int n;
    std::cin >> n;
    int *x = new int[n];
    int *y = new int[n];
    int *visited = new int[n];

    for (int i = 0; i < n; i++) {
        std::cin >> x[i];
        std::cin >> y[i];
    }
    int temp = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0){
        for (int j = 0; j < n; j++) {
            if (visited[j] == 0) {
                if (heuristic(x[i], y[i], x[j], y[j]) > heuristic(x[temp], y[temp], x[i], y[i])) {
                    temp = j;
                }
            }
        }
        visited[temp] = 1;
        std::cout << temp << "\n";
        }
    }
    return 0;
    }