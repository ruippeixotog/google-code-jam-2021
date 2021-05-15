#include <algorithm>
#include <cstdio>
#include <cstring>

#define MAXN 20
#define MAXU 20
#define MAXY 500

using namespace std;

int u[MAXN];

int u2[MAXY];

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n, a, b; scanf("%d %d %d", &n, &a, &b);
    for(int i = 0; i < n; i++)
      scanf("%d", &u[i]);

    bool possible = false;
    int y = 0;
    for(; !possible && y < MAXY; y++) {
      memset(u2, 0, sizeof(u2));
      u2[y] = 1;

      possible = true;
      for(int i = max(y, n - 1); i >= 0; i--) {
        if(i < n) u2[i] -= u[i];
        if(u2[i] < 0) { possible = false; break; }
        
        if(i - a >= 0) u2[i - a] += min(MAXN * MAXU, u2[i]);
        if(i - b >= 0) u2[i - b] += min(MAXN * MAXU, u2[i]);
      }
    }
    if(y == MAXY) printf("Case #%d: IMPOSSIBLE\n", tc);
    else printf("Case #%d: %d\n", tc, y);
  }
  return 0;
}
