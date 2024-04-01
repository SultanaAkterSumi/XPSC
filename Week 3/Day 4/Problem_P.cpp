#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<int>> graph(1000000);
vector<ll> leafs;
void coutntLeafByDFS(ll current, ll parent)
{
    bool child = false;
    for (ll i = 0; i < graph[current].size(); i++)
    {
        if (graph[current][i] == parent)
        {
            continue;
        }
        child = true;
        coutntLeafByDFS(graph[current][i], current);
        leafs[current] += leafs[graph[current][i]];
    }
    if (!child)
        leafs[current] = 1;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, i, j;
        cin >> n;
        for (i = 1; i <= n; i++)
        {
            graph[i].clear();
        }

        leafs.assign(n + 1, 0);

        for (i = 0; i < (n - 1); i++)
        {
            ll vertex1, vertex2;
            cin >> vertex1 >> vertex2;
            graph[vertex1].push_back(vertex2);
            graph[vertex2].push_back(vertex1);
        }
        coutntLeafByDFS(1, -1);

        ll q;
        cin >> q;
        for (i = 0; i < q; i++)
        {
            ll x, y;
            cin >> x >> y;
            cout << leafs[x] * leafs[y] << endl;
        }
    }
    return 0;
}