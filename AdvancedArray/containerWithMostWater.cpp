#include <iostream>
#include <vector>
using namespace std;

class SolutionSTL {
public:
    int maxArea(vector<int>& h) {
        int left = 0, right = h.size() - 1;
        int ans = 0;

        while (left < right) {
            int height = min(h[left], h[right]);//using two pointer approach
            int width = right - left;
            ans = max(ans, height * width);

            if (h[left] < h[right])
                left++;
            else
                right--;
        }
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter number of heights: ";
    cin >> n;

    vector<int> h(n);
    cout << "Enter heights: ";
    for (int i = 0; i < n; i++) cin >> h[i];

    SolutionSTL obj;
    cout << "Maximum area: " << obj.maxArea(h);
}
