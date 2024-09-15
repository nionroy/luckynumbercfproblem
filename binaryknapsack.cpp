#include <bits/stdc++.h>
using namespace std;
#define FastIo ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long int

void solve()
{
    ll item, capacity;
    cin >> item >> capacity;
    vector<ll> weight(item + 1);
    vector<ll> profit(item + 1);

    for (ll i = 1; i <= item; i++) {
        cin >> weight[i];
    }
    for (ll i = 1; i <= item; i++) {
        cin >> profit[i];
    }

    vector<vector<ll>> dptable(item + 1, vector<ll>(capacity + 1, 0));

    for (ll i = 1; i <= item; i++) {
        for (ll j = 1; j <= capacity; j++) {
            if (j >= weight[i]) {
                dptable[i][j] = max(profit[i] + dptable[i - 1][j - weight[i]], dptable[i - 1][j]);
            } else {
                dptable[i][j] = dptable[i - 1][j];
            }
        }
    }

    // Output the final DP table
    cout << "Final dynamic table is : " << endl;
    for (ll i = 0; i <= item; i++) {
        for (ll j = 0; j <= capacity; j++) {
            cout << dptable[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Maximum profit can achieve: " << dptable[item][capacity] << endl;

    // Item selection logic
    cout << "Items chosen: " << endl;
    ll i = item, j = capacity;
    while (i > 0 && j > 0) {
        if (dptable[i][j] == dptable[i - 1][j]) {
            cout << i << " :- " << 0 << endl; // Item not chosen
            i--;
        } else {
            cout << i << " :- " << 1 << endl; // Item chosen
            j -= weight[i];
            i--;
        }
    }
}

int main() {
    FastIo;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

