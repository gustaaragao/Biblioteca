#include <bits/stdc++.h>
using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

#define MAX_N 1000000

ll dp[MAX_N + 1];
ll first[MAX_N + 1]; // Armazena a primeira moeda necessária para gerar a soma X

ll coins[3] = {1, 3, 4};

signed main(){ _
    dp[0] = 0;
    for (int x = 1; x <= MAX_N; x++) {
        dp[x] = INT_MAX;
        for (auto c : coins) {
            // if (x - c >= 0) {
            //     dp[x] = min(dp[x], dp[x-c] + 1);
            // }
            if (x - c >= 0 && (dp[x-c] + 1) < dp[x]) {
                dp[x] = dp[x-c] + 1;
                first[x] = c; // Isso é útil para exibir as moedas que geram a soma X
            }
        }
    }

    int t; cin >> t;
    while (t--) {
        int x; cin >> x;
        // Exibindo a solução ótima --> Retorna -1 caso não tenha solução ótima
        cout << ((dp[x] == INT_MAX) ? -1 : dp[x]) << endl;

        // Exibindo o conjunto ótimo para a soma x
        if (dp[x] != INT_MAX) {
            while (x > 0) {
                cout << first[x] << " ";
                x -= first[x];
            }
            cout << endl;
        }
    }    
}

/*
https://cses.fi/problemset/task/1634/

Coin Problem do CPH: https://usaco.guide/CPH.pdf#page=75
Consiste em minimizar quantidade de moedas escolhidas do conjunto C
para atingir uma soma x.

Coin Problem do CPH: https://usaco.guide/CPH.pdf#page=75
Consiste em minimizar quantidade de moedas escolhidas do conjunto C
para atingir uma soma x.

solve(x) = INF,                    x < 0
            0,                     x = 0
            min(solve(x - c) + 1), x > 0 (c pertence a C)
*/