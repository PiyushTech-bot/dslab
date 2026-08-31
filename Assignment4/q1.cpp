#include <iostream>
using namespace std;

class BankAccount
{
private:
    string account_number;
    string account_holder;
    float balance;

public:
    BankAccount(string acc_num, string holder, float initial_balance)
    {
        account_number = acc_num;
        account_holder = holder;
        balance = initial_balance;
    }
    void deposit(float amount)
    {
        if (amount <= 0)
            cout << "Error! Insufficient amount detected." << endl;
        else
        {
            balance += amount;
            cout << "Deposit Success!" << endl;
        }
    }
    void withdraw(float amount)
    {
        if (amount <= 0)
            cout << "Error! Insufficient amount detected." << endl;
        else if (amount > balance)
            cout << "Error! Insufficient balance." << endl;
        else
        {
            balance -= amount;
            cout << "Withdrawal Successfull!" << endl;
        }
    }
    float get_balance()
    {
        return balance;
    }
    void display_summary()
    {
        cout << "Account Number: " << account_number << endl;
        cout << "Account Holder: " << account_holder << endl;
        cout << "Account Balance: " << balance << endl;
    }
};
int main()
{
    BankAccount acc("ACC1001", "Alice", 500.0);
    acc.deposit(200);
    acc.withdraw(100);
    acc.get_balance();
    acc.display_summary();
    return 0;
}