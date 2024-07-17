#include <iostream>
using namespace std;
int main()
{
    int coins[3] = {1, 5, 3};
    int change = 5;
    int dp[change + 1] = {0};
    dp[0] = 1;
    for (int j = 0; j < 3; j++)
    {
        for (int i = coins[j]; i <= change; i++)
        {
            dp[i] += dp[i - coins[j]];
        }
    }
    cout << dp[change];
}