#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <chrono>

std::queue<int> dataQueue;                // Shared data queue
std::mutex mtx;                           // Mutex to protect shared data
std::condition_variable cv;               // Condition variable for synchronization
bool done = false;                        // Flag to signal when production is done

// Producer function
void producer() {
    for (int i = 0; i < 5; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Simulate work
        std::unique_lock<std::mutex> lock(mtx);
        dataQueue.push(i);                  // Produce data
        std::cout << "Produced: " << i << std::endl;
        cv.notify_one();                    // Notify the consumer
    }
    std::unique_lock<std::mutex> lock(mtx);
    done = true;                            // Signal that production is done
    cv.notify_one();                        // Notify the consumer again
}

// Condition function
bool isDataAvailable() {
    return !dataQueue.empty() || done;
}

// Consumer function
void consumer() {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, isDataAvailable);  // Wait for data or done signal

        while (!dataQueue.empty()) {
            int data = dataQueue.front();
            dataQueue.pop();
            std::cout << "Consumed: " << data << std::endl;
        }

        if (done) {
            break;  // Exit if production is done and queue is empty
        }
    }
}

int main() {
    std::thread prodThread(producer);
    std::thread consThread(consumer);

    prodThread.join();
    consThread.join();

    return 0;
}
