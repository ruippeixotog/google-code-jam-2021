#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

#define MAXS 1000
#define INF 0x3f3f3f3f

using namespace std;

int cost[MAXS][2];

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int x, y; scanf("%d %d\n", &x, &y);
    string s; cin >> s;

    memset(cost, INF, sizeof(cost));
    for(int i = 0; i < s.size(); i++) {
      if(s[i] == 'C' || s[i] == '?') {
        cost[i][0] = i == 0 ? 0 :
          min(cost[i][0], min(cost[i - 1][0], cost[i - 1][1] + y));
      }
      if(s[i] == 'J' || s[i] == '?') {
        cost[i][1] = i == 0 ? 0 :
          min(cost[i][1], min(cost[i - 1][1], cost[i - 1][0] + x));
      }
    }
    int res = min(cost[s.size() - 1][0], cost[s.size() - 1][1]);
    printf("Case #%d: %d\n", tc, res);
  }
  return 0;
}
