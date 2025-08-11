#include <bits/stdc++.h>
using namespace std; 

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()

typedef long long ll;

const ll MOD = 1e9 + 7;

// Coordinate Compreesion
void coordinate_compression(vector<int> &a) {
    set<int> s; // Conjunto para armazenar todos os números únicos
    for (auto x : a) s.insert(x);

    int index = 0;
    map<int, int> mp; // Map para armazenar os novos elementos
    
    set<int>::iterator itr;
    for (itr = s.begin(); itr != s.end(); itr++) {
        index++;
        mp[*itr] = index;
    }

    // Alterando o valor de a
    for (int i = 0; i < a.size(); i++) {
        a[i] = mp[a[i]];
    }
}

// BIT ou SegTree
struct fenw {
    int n;
    vector<int> bit;

    fenw() {}
    fenw(int size) {
        n = size;
        bit.assign(size + 1, 0);
    }
    // query do prefixo a[0] + a[1] + ... + a[r]
    int qry(int r) {
        int ans = 0;
        for (int i = r + 1; i > 0; i -= i & -i) // i & -i retorna os bits menos signativos de i 
            ans += bit[i];
        return ans;
    }

    // atualiza o valor a[r] = x
    void upd(int r, int x) {
        for (int i = r + 1; i <= n; i += i & -i) bit[i] += x;
    }
};

int lis(vector<int> &a) {
    coordinate_compression(a);

    int n = a.size();

    fenw tree(n + 1);
    for (int i = 0; i < n; i++) {
        tree.upd(a[i], n);
    }

    int ans = tree.qry(n);

    return ans;
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