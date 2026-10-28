#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  vector<vector<int>> graph{{1, 2}, {0, 3}, {0, 4}, {1}, {2}};

  int start = 0;
  int target = 4;

  vector<bool> visited(5, false);
  vector<int> parent(5, -1);

  queue<int> q;

  visited[start] = true;
  q.push(start);

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    if (cur == target) {
      break;
    }

    for (int next : graph[cur]) {
      if (!visited[next]) {
        visited[next] = true;
        parent[next] = cur;
        q.push(next);
      }
    }
  }

  if (!visited[target]) {
    cout << "No path" << endl;
    return 0;
  }

  vector<int> path;

  for (int cur = target; cur != -1; cur = parent[cur]) {
    path.push_back(cur);
  }

  reverse(path.begin(), path.end());

  for (int node : path) {
    cout << node << " ";
  }
  cout << endl;

  return 0;
}