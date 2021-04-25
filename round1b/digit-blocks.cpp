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

#define N 20
#define B 15

using namespace std;

typedef long long ll;
typedef long double ld;

int cnt[N];

void reply(int arg) {
  cnt[arg]++;
  // cerr << "ans " << (arg + 1) << endl;
  printf("%d\n", arg + 1);
  fflush(stdout);
}

// int ask(int arg) {
//   printf("%d\n", arg);
//   fflush(stdout);
//   int ans; scanf("%d", &ans);
//   if(ans == -1) exit(0);
//   return ans;
// }

// void answer(int sol) {
//   printf("%d\n", sol);
//   fflush(stdout);
//   int ans; scanf("%d", &ans);
//   if(ans == -1) exit(0);
// }

void check() {
  int ans; scanf("%d", &ans);
  // cerr << "check " << ans << endl;
  if(ans == -1) exit(0);
}

int main() {
  int t; scanf("%d %*d %*d %*lld", &t);
  for(int tc = 1; tc <= t; tc++) {
    memset(cnt, 0, sizeof(cnt));

    for(int i = 0; i < N * B; i++) {
      int val; scanf("%d", &val);
      if(val == -1) exit(0);
      // cerr << "get " << val << endl;

      if(val == 9) {
        int best = -1;
        for(int j = 0; j < N; j++) {
          if(cnt[j] == B) continue;
          if(best == -1 || cnt[best] < cnt[j]) {
            best = j;
          }
        }
        reply(best);

      } else {
        int best = -1, best2 = -1;
        for(int j = 0; j < N; j++) {
          if(cnt[j] == B) continue;
          if(cnt[j] > (val + 1) * 15 / 10) {
            if(best2 == -1 || cnt[j] < cnt[best2]) {
              best2 = j;
            }
          } else {
            if(best == -1 || (cnt[j] > cnt[best])) {
              best = j;
            }
          }
        }
        reply(best != -1 ? best : best2);
      }
    }
  }
  check();
  return 0;
}
