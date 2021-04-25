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

#define MAXN 5000
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef long double ld;

int u[MAXN];

ll u2[MAXN];

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n, a, b; scanf("%d %d %d", &n, &a, &b);
    for(int i = 0; i < n; i++)
      scanf("%d", &u[i]);

    // cerr << "start" << endl;

    int low = 0, high = 50;
    while(low < high) {
      int mid = (low + high) / 2;

      // cerr << "here " << low << " " << high << " " << mid << endl;
      memset(u2, 0, sizeof(u2));
      u2[mid] = 1;

      bool possible = true;
      for(int i = max(mid, n - 1); i >= 0; i--) {
        // cerr << "u2[" << i << "] = " << u2[i] << endl;

        if(i < n) {
          if(u2[i] < u[i]) {
            // cerr << "don't have " << i << endl;
            possible = false; break;
          }
          u2[i] -= u[i];
        }
        if(i - 1 >= 0) u2[i - 1] += u2[i];
        if(i - 2 >= 0) u2[i - 2] += u2[i];
      }

      // cerr << "possible " << possible << endl;

      if(possible) high = mid;
      else low = mid + 1;
    }
    printf("Case #%d: %d\n", tc, low + 1);
  }
  return 0;
}
