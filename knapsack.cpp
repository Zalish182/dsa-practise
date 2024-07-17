#include <iostream>
using namespace std;
int main()
{
    int n = 4;
    int weight[5] = {0, 3, 2, 5, 4};
    int profit[5] = {0, 4, 3, 6, 5};
    int capacity = 5;
    int k[n + 1][capacity + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            if (i == 0 || w == 0)
                k[i][w] = 0;
            else if (weight[i] > w)
                k[i][w] = k[i - 1][w];
            else
                k[i][w] = max(k[i - 1][w], k[i - 1][w - weight[i]] + profit[i]);
        }
    }
    cout << k[n][capacity];
}