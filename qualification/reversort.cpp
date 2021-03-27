#include <algorithm>
#include <cstdio>

#define MAXN 100

using namespace std;

int l[MAXN];

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n; scanf("%d\n", &n);
    for(int i = 0; i < n; i++)
      scanf("%d", &l[i]);

    int cost = 0;
    for(int i = 0; i < n - 1; i++) {
      int j = min_element(l + i, l + n) - l;
      cost += j - i + 1;
      reverse(l + i, l + j + 1);
    }
    printf("Case #%d: %d\n", tc, cost);
  }
  return 0;
}
