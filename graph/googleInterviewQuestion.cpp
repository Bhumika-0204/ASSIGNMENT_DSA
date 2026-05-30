#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    struct Node {
        int x, y;
    };

    static Node* next(vector<vector<char>>& grid, int x, int y) {

        int m = grid.size();
        int n = grid[0].size();

        char dir = grid[x][y];

        if (dir == 'R') y++;
        else if (dir == 'L') y--;
        else if (dir == 'U') x--;
        else if (dir == 'D') x++;

        if (x < 0 || y < 0 || x >= m || y >= n)
            return nullptr;

        return new Node{x, y};
    }

    static bool canReach(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        Node* slow = new Node{0, 0};
        Node* fast = new Node{0, 0};

        while (true) {
            slow = next(grid, slow->x, slow->y);

            fast = next(grid, fast->x, fast->y);
            if (fast != nullptr)
                fast = next(grid, fast->x, fast->y);

            if (slow == nullptr || fast == nullptr)
                return false;

            if ((slow->x == m - 1 && slow->y == n - 1) ||
                (fast->x == m - 1 && fast->y == n - 1))
                return true;

            if (slow->x == fast->x && slow->y == fast->y)
                return false;
        }
    }
};

int main() {

    vector<vector<char>> grid = {
        {'R','R','D','R'},
        {'D','L','D','L'},
        {'U','D','L','L'},
        {'U','R','R','R'}
    };

    cout << (Solution::canReach(grid) ? "true" : "false");

    return 0;
}