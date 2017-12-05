//Alexa Summers, Part three


#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
    queue<float> transactions;
    float balance = 0.0;

    transactions.push(2.99);
    transactions.push(-1.99);
    transactions.push(-11.52);
    transactions.push(22.34);
    transactions.push(85.25);

    while (!transactions.empty())
    {
    cout << transactions.front() << " pushed to account" << endl;
    balance = balance + transactions.front();
    transactions.pop();

    }

    cout << "Final balance: $" << balance << endl;

    return 0;
}
