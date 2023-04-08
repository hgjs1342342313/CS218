#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

void dijkstra(int n, int s, vector<vector<pair<int, int>>>& G, vector<int>& curlen) {
    vector<bool> isShortest(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    curlen[s] = 0;
    pq.emplace(0, s);
    while (!pq.empty()) {
        auto curweight = pq.top().first;
        auto curvertex = pq.top().second;
        pq.pop();
        if (!isShortest[curvertex]) {
            isShortest[curvertex] = true;
            for (int i = 0; i < G[curvertex].size(); i++) {// update all the vertices
            //take the edges with source "curvertex"
                auto vertex = G[curvertex][i].second;
                auto weight = G[curvertex][i].first;
                //if the currlent length of i is greater than updated data, update it
                if (curlen[vertex] > weight + curweight) {
                    curlen[vertex] = weight + curweight;
                    //then, emplace back the new edge
                    pq.emplace(curlen[vertex], G[curvertex][i].second);
                }
            }
        }
    }
}

// change the 2D position to 1D position
// use pos = x * n + y
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n = 0;
    int m = 0;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>(n, make_pair(0x3f3f3f3f, 0x3f3f3f3f)));
    vector<int> curlen(n, 0x3f3f3f3f);
    for (int i = 0; i < n; i++) {
        string inp;
        cin >> inp;
        for (int j = 0; j < n; j++) {
            auto pos = i * n + j;
            graph[pos][pos] = 0;
            if (inp[j] == '-') {
                // set up, down, left, right distance to 1
                if (i > 0) {
                    graph[pos][pos - n] = 1;
                }
                if (i < n - 1) {
                    graph[pos][pos + n] = 1;
                }
                if (j > 0) {
                    graph[pos][pos - 1] = 1;
                }
                if (j < n - 1) {
                    graph[pos][pos + 1] = 1;
                }

            }
            else if (inp[j] == 'b') {
                // set up, down, left, right distance to m
                if (i > 0) {
                    graph[pos][pos - n] = m;
                }
                if (i < n - 1) {
                    graph[pos][pos + n] = m;
                }
                if (j > 0) {
                    graph[pos][pos - 1] = m;
                }
                if (j < n - 1) {
                    graph[pos][pos + 1] = m;
                }

            }
        }
    }
    dijkstra(n * n - 1, 0, graph, curlen);
    cout << curlen[n * n - 1] << endl;

}