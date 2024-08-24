#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

timed_mutex g_mutex; // Using timed mutex

void try_lock_for_example(const char* msg)
{
	unique_lock<timed_mutex> lock(g_mutex,defer_lock); //Using unique_lock to lock the mutex so that dont need to unlock it manually
	// Using defer_lock so that we can lock the mutex later
	if(lock.try_lock_for(chrono::seconds(1))) // Trying to aquire the lock for 1 second. try_lock_for tries to aquire the lock for the specified time
		cout << msg << endl;
	else
		cout << "Could not get the lock" << endl;

}

void try_lock_until_example(const char* msg)
{
	unique_lock<timed_mutex> lock(g_mutex,defer_lock);
	if(lock.try_lock_until(chrono::steady_clock::now() + chrono::seconds(1))) // Trying to aquire the lock until the particular timepoint
		cout << msg << endl;
	else
		cout << "Could not get the lock" << endl;

}

void try_lock_example(const char* msg)
{
	unique_lock<timed_mutex> lock(g_mutex,defer_lock);
	if(lock.try_lock()) // Trying to aquire the lock
		cout << msg << endl;
	else
		cout << "Could not get the lock" << endl;

}

void try_lock_without_unique_lock_example(const char* msg)
{
	if (g_mutex.try_lock_for(chrono::seconds(1))) {
		cout << msg << endl;
		g_mutex.unlock(); // Unlocking the mutex
	}
	else
		cout << "Could not get the lock" << endl;

}

int main()
{
	thread t1(try_lock_for_example, "Hello from t1");
	thread t2(try_lock_for_example, "Hello from t2");
	t1.join();
	t2.join();
	cout << "Main thread" << endl;
	thread t3(try_lock_until_example, "Hello from t3");
	thread t4(try_lock_until_example, "Hello from t4");
	t3.join();
	t4.join();

	return 0;
}
