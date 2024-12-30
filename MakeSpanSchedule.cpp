#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 10005;

vector<int> adj[MAX]; // adjacency list for precedence constraints
int d[MAX]; // durations
int inDegree[MAX]; // number of incoming edges for each task
int f[MAX]; // earliest finish time for each task

int main() {
    int n, m;
    cin >> n >> m;
    
    // read durations
    for(int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    
    // read precedence constraints
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        inDegree[y]++;
    }
    
    // topological sort using queue
    queue<int> q;
    
    // add tasks with no prerequisites to queue
    for(int i = 1; i <= n; i++) {
        if(inDegree[i] == 0) {
            q.push(i);
            f[i] = d[i]; // earliest finish time is just duration
        }
    }
    
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        
        // process all tasks that depend on current task
        for(int next : adj[curr]) {
            // update earliest finish time
            f[next] = max(f[next], f[curr] + d[next]);
            
            inDegree[next]--;
            if(inDegree[next] == 0) {
                q.push(next);
            }
        }
    }
    
    // find maximum finish time among all tasks
    int result = 0;
    for(int i = 1; i <= n; i++) {
        result = max(result, f[i]);
    }
    
    cout << result << endl;
    
    return 0;
}