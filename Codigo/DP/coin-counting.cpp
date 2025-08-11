#include <bits/stdc++.h>
using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const ll MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

#define MAXN 1000000

ll dp[MAXN + 1];

int coins[3] = {1, 3, 4};

signed main(){ _
    dp[0] = 1;
    for (int x = 1; x <= MAXN; x++) {
        for (auto c : coins) {
            if (x - c >= 0) {
                dp[x] = (dp[x] + dp[x - c]) % MOD;
            }
        }
    }

    int t; cin >> t;
    while (t--) {
        int x; cin >> x;
    
        cout << dp[x] << endl;
    }  
}

/* 
Esse problema consiste em contar o número de formas que podemos gerar
a soma x a partir de um conjunto C = {c1, c2, ..., ci} de moedas.

solve(x) =  0,                    x < 0
            1,                     x = 0
            sum(solve(x - c)), x > 0 (c pertence a C)

Dica: Desenhe uma árvore para entender melhor o problema!
        x
x-1    x-3  x-4

https://usaco.guide/CPH.pdf#page=79
*/