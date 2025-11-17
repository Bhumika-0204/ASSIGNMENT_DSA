#include <bits/stdc++.h>
using namespace std;

class SolutionSTL {
public:
    void operations(vector<int>& A, vector<int>& B) {
        priority_queue<int> pq;       // max-heap
        unordered_map<int, int> freq; // to check presence

        // Insert all elements into PQ
        for (int x : A) {
            pq.push(x);
            freq[x]++;
        }

        for (int x : B) {
            if (freq[x] > 0) {
                cout << 1 << " ";

                // print max element
                int maxElem = pq.top();
                cout << maxElem << " ";

                // remove max element
                freq[maxElem]--;
                pq.pop();
            }
            else {
                cout << -1 << " ";
            }
        }
    }
};

int main() {
    int n, m;
    cout << "Enter size of array A: ";
    cin >> n;

    vector<int> A(n);
    cout << "Enter elements of A: ";
    for (int i = 0; i < n; i++) cin >> A[i];

    cout << "Enter size of array B: ";
    cin >> m;

    vector<int> B(m);
    cout << "Enter elements of B: ";
    for (int i = 0; i < m; i++) cin >> B[i];

    SolutionSTL sol;
    sol.operations(A, B);

    return 0;
}
