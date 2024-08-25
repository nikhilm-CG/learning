#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

class Singleton {
private:
    Singleton() {}
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    static Singleton* instance;
    static std::mutex mtx;

public:
    static Singleton* getInstance() {
        if (instance == nullptr) { // First check (no locking)
            lock_guard<mutex> lock(mtx); // Locking
            if (instance == nullptr) { // Second check (with locking)
                instance = new Singleton();
            }
        }
        return instance;
    }
};

// Initialize static members
Singleton* Singleton::instance = nullptr;
std::mutex Singleton::mtx;

int main() {
    Singleton* s = Singleton::getInstance();
    return 0;
}
