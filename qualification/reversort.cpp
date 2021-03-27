#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

#define MAXN 2000
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef long double ld;

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
      // cerr << "L = ";
      // for(int k = 0; k < n; k++) {
      //   cerr << l[k] << " ";
      // }
      // cerr << endl;
    }
    printf("Case #%d: %d\n", tc, cost);
  }
  return 0;
}
