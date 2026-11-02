// Q1. Fibonacci Staircase (DP) · [2:31](https://youtu.be/D04Aq-txMy8?t=151)
// Find the minimum cost to climb from step 1 to step N when every jump must be a Fibonacci length.

// * A staircase has N steps numbered 1 to N. You start on step 1 and want to reach step N.
// * From step i you may jump ahead only by a Fibonacci number: i+1, i+2, i+3, i+5, i+8, i+13, … The landing step must not exceed N.
// * A jump of length k costs A + B × k. A is a fixed cost per jump, B is the cost per step jumped.

// Input: three integers N, A and B.
// Output: the minimum total cost to reach step N.
// Constraints: not shown in the video.
// Example

// ```
// Input:  N = 10, A = 5, B = 2
// Output: 28
// ```

// Path 1 → 2 → 10 uses jumps of 1 and 8: (5 + 2×1) + (5 + 2×8) = 7 + 21 = 28. Path 1 → 3 → 8 → 10 (jumps 2, 5, 2) costs 33, so 28 is the minimum.




#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n , a , b;
    cin >> n >> a >> b;
    
    vector<int> fib;
    long long fib1 = 1;
    long long fib2 = 2;
    while(true){
        if(fib1 > n - 1) break;
        fib.push_back(fib1);
        long long fib3 = fib1 + fib2;
        fib1 = fib2;
        fib2 = fib3;
    }
    
    vector<long long> dp(n + 1 ,LLONG_MAX );
    
    dp[1] = 0;
    for(long long i = 2 ; i <= n ;i++){
        for(long long f : fib){
            if(i - f < 1) break;
            if(dp[i-f] != LLONG_MAX){
                dp[i] = min(dp[i] , dp[i - f] + a + b * f);
            }
        }
    }
    cout << dp[n] << endl;
}