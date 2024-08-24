// BankingAppForThreading.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/* 
Objective:
Create a simple multithreaded banking system in C++ that simulates multiple bank accounts, allowing multiple threads to deposit and withdraw money concurrently. 
The goal is to practice using threads, mutexes, and RAII for managing locks safely.

Problem Description:
Bank Account Class: Implement a BankAccount class that represents a single bank account.

It should have:
A private member variable for the balance (e.g., double balance).
A std::mutex to protect access to the balance.
It should provide:
A method to deposit money.
A method to withdraw money.
A method to display the current balance.
Bank Simulation: Create multiple BankAccount objects and multiple threads. Each thread should randomly choose an account and either deposit or withdraw a random amount of money.

Thread Safety: Ensure that the operations on the bank account are thread-safe using mutexes. Use RAII constructs (std::lock_guard or std::unique_lock) to manage locks.

Logging: Add simple logging to see which thread is performing what action (deposit or withdraw) and what the balance is after the operation.*/

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

class BankAccount
{
private:
	double balance;
	std::mutex mtx;
public:
	BankAccount() : balance(0){}
	
	void Deposit(double amount)
	{
		lock_guard<mutex> lock(mtx);
		// Print Thrad ID
		std::cout << "Thread ID: " << std::this_thread::get_id() << " Depositing " << amount << std::endl;
		balance += amount;
	}

	void Withdraw(double amount)
	{
		// Print Thrad ID
		lock_guard<mutex> lock(mtx);
		std::cout << "Thread ID: " << std::this_thread::get_id() << " Withdrawing " << amount << std::endl;
		balance -= amount;
	}

	void DisplayBalance()
	{
		// Print Thrad ID
		lock_guard<mutex> lock(mtx);
		std::cout << "Thread ID: " << std::this_thread::get_id() << " Current balance: " << balance << std::endl;
	}
};

int main()
{
	BankAccount account;
	std::thread t1([&account] {account.Deposit(100); });
	std::thread t2([&account] {account.Withdraw(50); });
	std::thread t3([&account] {account.Deposit(200); });
	std::thread t4([&account] {account.Withdraw(100); });
	std::thread t5([&account] {account.DisplayBalance(); });
	std::thread t6([&account] {account.Deposit(200); });
	std::thread t7([&account] {account.DisplayBalance(); });
	std::thread t8([&account] {account.Deposit(200); });
	std::thread t9([&account] {account.DisplayBalance(); });
	thread t10(&BankAccount::Deposit,&account,520);

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();
	t7.join();
	t8.join();
	t9.join();

	account.DisplayBalance();

	return 0;
}
