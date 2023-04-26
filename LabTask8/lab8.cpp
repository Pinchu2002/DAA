#include <bits/stdc++.h>
 
using namespace std;
#define vi vector<int>
#define lli long long int
#define MAX 1e15
 
int main() 
{
    int n, m;
    cin >> n >> m;
    unordered_map<lli, vector<pair<int, int>>> adj;
    lli u, v, w;
    for(int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
    }
 
    /* we will use dijkstra's algorithm to find shortest distance between the start node and all other nodes */
    vector<lli> d(n+1, MAX);
    /* mark the start node distance as 0 */
    d[1] = 0;
    set<pair<lli, lli>> s;
    s.insert(make_pair(0, 1));
    while(!s.empty())
    {
        /* get the node which is having smallest distance */
        lli p = s.begin()->second;
        /* erase that pair from that set , as it was processed */
        s.erase(s.begin());
 
        /* now traverse through all the edges reached from curr node */
        for(auto e: adj[p])
        {
            if(d[e.first] > d[p] + e.second)
            {
                s.erase(make_pair(d[e.first], e.first));
                d[e.first] = d[p] + e.second;
                s.insert(make_pair(d[e.first], e.first));
            }
        }
    }
 
    for(int i = 1; i <= n; i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;
	return 0;
}