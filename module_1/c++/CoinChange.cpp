/*
    Title : Coin Change Leetcode Link : https
    : // leetcode.com/problems/coin-change/

      Problem
    : You are given coins of different denominations and a total amount of money
          amount
              .Write a function to compute the fewest number of coins that you
                  need to make up that amount.If that amount of money cannot be
                      made up by any combination of the coins,
    return -1.

           Input : coins : List[int] = > denominations of coins available amount
    : int = > amount of change to make Output : int =
                > minimum number of coins needed

                      Execution : python coin_change.py */

#include <iostream>
#include <vector>
using namespace std;
// O(nd) time | O(n) space
int coinChange(vector<int> &coins, int amount) {

  int max = amount + 1;
  vector<int> dp(amount + 1, max);
  dp[0] = 0;
  for (int i = 1; i <= amount; i++) {
    for (int j = 0; j < coins.size(); j++) {
      if (coins[j] <= i) {
        dp[i] = min(dp[i], dp[i - coins[j]] + 1);
      }
    }
  }
  return dp[amount] > amount ? -1 : dp[amount];
}
int main() {
  vector<int> coins = {1, 5, 10};

  cout << coinChange(coins, 7) << endl;
}
