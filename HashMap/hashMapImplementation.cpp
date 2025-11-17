#include <bits/stdc++.h>
using namespace std;

class MyHashMap {
public:
    static const int SIZE = 1000;   // bucket size
    vector<pair<int,int>> buckets[SIZE];

    int hashFunction(int key) {
        return key % SIZE;
    }

    void put(int key, int value) {
        int h = hashFunction(key);
        for (auto &p : buckets[h]) {
            if (p.first == key) {
                p.second = value;   // update
                return;
            }
        }
        buckets[h].push_back({key, value});
    }

    int get(int key) {
        int h = hashFunction(key);
        for (auto &p : buckets[h])
            if (p.first == key) return p.second;
        return -1;
    }

    void removeKey(int key) {
        int h = hashFunction(key);
        for (int i = 0; i < buckets[h].size(); i++) {
            if (buckets[h][i].first == key) {
                buckets[h].erase(buckets[h].begin() + i);
                return;
            }
        }
    }
};

int main() {
    MyHashMap mp;

    int n;
    cout << "Enter number of operations: ";
    cin >> n;

    cout << "Choose operations:\n1 put\n2 get\n3 remove\n";

    while (n--) {
        int type;
        cin >> type;

        if (type == 1) {
            int key, value;
            cout << "Enter key and value: ";
            cin >> key >> value;
            mp.put(key, value);
        }
        else if (type == 2) {
            int key;
            cout << "Enter key: ";
            cin >> key;
            cout << "Value = " << mp.get(key) << "\n";
        }
        else if (type == 3) {
            int key;
            cout << "Enter key: ";
            cin >> key;
            mp.removeKey(key);
        }
    }

    return 0;
}
