#include <iostream>
#include <vector>
using namespace std;

class SolutionSTL {
public:
    int trap(vector<int>& h) {
        int left = 0, right = h.size() - 1;
        int leftMax = 0, rightMax = 0, water = 0;

        while (left < right) {
            if (h[left] < h[right]) {
                if (h[left] >= leftMax)
                    leftMax = h[left];
                else
                    water += leftMax - h[left];
                left++;
            } else {
                if (h[right] >= rightMax)
                    rightMax = h[right];
                else
                    water += rightMax - h[right];
                right--;
            }
        }
        return water;
    }
};

int main() {
    int n;
    cout << "Enter number of bars: ";
    cin >> n;

    vector<int> h(n);
    cout << "Enter heights: ";
    for (int i = 0; i < n; i++) cin >> h[i];

    SolutionSTL obj;
    cout << "Trapped water: " << obj.trap(h);
}
