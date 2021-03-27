#include <algorithm>
#include <cstdio>
#include <numeric>

#define MAXN 100

using namespace std;

int l[MAXN], pcost[MAXN];

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n, c; scanf("%d %d\n", &n, &c);

    if(c < n - 1 || c > (n - 1) * (n + 2) / 2) {
      printf("Case #%d: IMPOSSIBLE\n", tc);
      continue;
    }
    for(int i = 0; i < n - 1; i++) {
      c -= pcost[i] = min(c - (n - 2 - i), n - i);
    }
    iota(l, l + n, 1);
    for(int i = n - 2; i >= 0; i--) {
      reverse(l + i, l + i + pcost[i]);
    }
    printf("Case #%d:", tc);
    for(int i = 0; i < n; i++) {
      printf(" %d", l[i]);
    }
    printf("\n");
  }
  return 0;
}
