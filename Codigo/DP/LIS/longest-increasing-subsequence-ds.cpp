#include <bits/stdc++.h>
using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()

typedef long long ll;

const ll MOD = 1e9 + 7;

void coordinate_compression(vector<int> &a) {

}

int lis(vector<int> &a) {
    int n = a.size();

    return 0;
}

signed main(){ _

    int n; cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    cout << lis(a) << endl;
}

/* https://cp-algorithms.com/sequences/longest_increasing_subsequence.html#solution-in-on-log-n-with-data-structures

dp[i] = max(1, max(dp[i], dp[j] + 1)), para j < i e a[j] < a[i]

Podemos definir uma array t[] t.q. t[a[i]] = dp[i]

O problema de descobrir dp[i] vira achar o maior valor em um prefixo de t[].

dp[i] = max(t[0...(a[i]-1)] + 1)

O problema de achar o maior valor de um prefixo em uma array que muda é um problema
de SegTree e BIT.

--- Pontos Negativos da Solução
- Implementação Complexa
- a[i] for mt grande --> Coordinate Compression ou Dynamic SegTree
*/