#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class SolutionSTL {
public:
    vector<int> asteroidCollision(vector<int>& arr, int n) {
        stack<int> st;

        for (int x : arr) {
            bool destroyed = false;

            while (!st.empty() && x < 0 && st.top() > 0) {
                if (abs(x) > st.top()) {
                    st.pop();
                }
                else if (abs(x) == st.top()) {
                    st.pop();
                    destroyed = true;
                    break;
                }
                else {
                    destroyed = true;
                    break;
                }
            }

            if (!destroyed) st.push(x);
        }

        vector<int> ans(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter asteroids: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    SolutionSTL obj;
    vector<int> res = obj.asteroidCollision(arr, n);

    cout << "Result: ";
    for (int x : res) cout << x << " ";
    cout << endl;

    return 0;
}
