#include <bits/stdc++.h>
using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const ll MOD = 1e9 + 7;

#define MAXN 1000000

ll dp[MAXN + 1];
int visited[MAXN + 1];
ll first[MAXN + 1];

ll coins[3] = {1, 3, 4};

ll solve(int x) {
    if (x < 0) return INT_MAX;
    if (x == 0) return 0;
    if (visited[x]) return dp[x];
    int best = INT_MAX;
    for (auto c : coins) {
        // best = min(best, solve(x - c) + 1);
        if (solve(x - c) + 1 < best) {
            best = solve(x - c) + 1;
            first[x] = c;
        }
    }
    visited[x] = true;
    return dp[x] = best;
}

signed main(){ _
    int t; cin >> t;
    while (t--) {
        int x; cin >> x;
        
        ll ans = solve(x);

        // Exibindo a solução ótima --> Retorna -1 caso não tenha solução ótima
        cout << ((ans == INT_MAX) ? -1 : ans) << endl;

        // Exibindo o conjunto ótimo para a soma x
        if (ans != INT_MAX) {
            while (x > 0) {
                cout << first[x] << " ";
                x -= first[x];
            }
            cout << endl;
        }
    }    
}

/*
Coin Problem do CPH: https://usaco.guide/CPH.pdf#page=75
Consiste em minimizar quantidade de moedas escolhidas do conjunto C
para atingir uma soma x.

solve(x) = INF,                    x < 0
            0,                     x = 0
            min(solve(x - c) + 1), x > 0 (c pertence a C)
*/        