#include <iostream>
using namespace std;

class SolutionNoSTL {
public:
    int maxProfit(int prices[], int n) {
        int minPrice = 1e9;
        int maxProfit = 0;

        for (int i = 0; i < n; i++) {
            if (prices[i] < minPrice)
                minPrice = prices[i];
            else {
                int profit = prices[i] - minPrice;
                if (profit > maxProfit)
                    maxProfit = profit;
            }
        }
        return maxProfit;
    }
};

int main() {
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    int prices[10000];
    cout << "Enter prices: ";
    for (int i = 0; i < n; i++) cin >> prices[i];

    SolutionNoSTL obj;
    cout << "Maximum Profit: " << obj.maxProfit(prices, n);
}
