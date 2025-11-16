#include <iostream>
using namespace std;

class SingleObject {
private:
    static SingleObject* instance;
    SingleObject() {
        cout << "Single object created!\n";
    }

public:
    static SingleObject* getInstance() {
        if (instance == nullptr) {
            instance = new SingleObject();
        }
        return instance;
    }

    void show() {
        cout << "This is the only object.\n";
    }
};

SingleObject* SingleObject::instance = nullptr;

int main() {
    SingleObject* a = SingleObject::getInstance();
    SingleObject* b = SingleObject::getInstance();

    a->show();

    cout << "Are both objects same? " << (a == b) << endl;

    return 0;
}
