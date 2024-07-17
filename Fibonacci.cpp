
#include <iostream>
using namespace std;
long long int dp[100];
long long int fibonacci(int n)
{
    if (dp[n] != -1)
        return dp[n];
    dp[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return dp[n];
}
int main()
{
    for (int i = 0; i < 100; i++)
        dp[i] = -1;
    dp[0] = 0;
    dp[1] = 1;
    cout << fibonacci(99);
}
