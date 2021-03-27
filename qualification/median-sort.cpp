#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
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

int x[MAXN];

ll ask(int i1, int i2, int i3) {
  // cerr << "> ask " << (x[i1]) << " " << (x[i2]) << " " << (x[i3]) << endl;
  printf("%d %d %d\n", x[i1], x[i2], x[i3]);
  fflush(stdout);
  ll ans; scanf("%lld", &ans);
  if(ans == -1) exit(0);
  // cerr << "< " << ans << endl;
  return ans == x[i1] ? i1 : ans == x[i2] ? i2 : i3;
}

void answer(int n) {
  // cerr << "> sol " << x[0];
  printf("%d", x[0]);
  for(int i = 1; i < n; i++) {
    // cerr << " " << (x[i]);
    printf(" %d", x[i]);
  }
  // cerr << endl;
  printf("\n");
  fflush(stdout);
  int ans; scanf("%d", &ans);
  if(ans == -1) exit(0);
}

void medianSort(int st, int end, int ref, bool isRefLeft) {
  // cerr << "(" << st << ", " << end << ") start" << endl;
  if(end - st == 1) return;
  if(end - st > 2) {
    swap(x[st], x[ask(st, st + 1, st + 2)]);

    int sep = st + 1;
    // cerr << "(" << st << ", " << end << ") pivot is " << x[st] << ", small is " << x[sep] << endl;
    for(int i = st + 3; i < end; i++) {
      int res = ask(st, sep, i);
      if(res != st) swap(x[++sep], x[i]);
    }
    swap(x[st], x[sep]);

    // cerr << "(" << st << ", " << end << ") after pivot:";
    // for(int i = st; i < end; i++) {
    //   cerr << " " << x[i];
    // }
    // cerr << endl;

    medianSort(st, sep, sep, false);
    medianSort(sep + 1, end, sep, true);
  }
  if(ref != -1) {
    int mid = ask(st, st + 1, ref);
    if((isRefLeft && mid == st + 1) || (!isRefLeft && mid == st)) {
      reverse(x + st, x + end);
    }
  }
  // cerr << "(" << st << ", " << end << ") end:";
  // for(int i = st; i < end; i++) {
  //   cerr << " " << x[i];
  // }
  // cerr << endl;
}

void medianSort2(int st, int end, int ref, bool isRefLeft) {
  // cerr << "(" << st << ", " << end << ") start" << endl;
  if(end - st <= 1) return;
  if(end - st > 2) {
    int sep1 = st, sep2 = end - 1;
    // cerr << "(" << st << ", " << end << ") pivots are " << x[st] << " and " << x[end - 1] << endl;
    for(int i = st + 1; i < sep2; i++) {
      int res = ask(st, end - 1, i);
      if(res == st) swap(x[++sep1], x[i]);
      if(res == end - 1) swap(x[--sep2], x[i--]);
    }
    swap(x[st], x[sep1]);
    swap(x[end - 1], x[sep2]);

    // cerr << "(" << st << ", " << end << ") after pivot:";
    // for(int i = st; i < end; i++) {
    //   cerr << " " << x[i];
    // }
    // cerr << endl;

    medianSort2(st, sep1, sep1, false);
    medianSort2(sep1 + 1, sep2, sep2, false);
    medianSort2(sep2 + 1, end, sep2, true);
  }
  if(ref != -1) {
    int mid = ask(st, st + 1, ref);
    if((isRefLeft && mid == st + 1) || (!isRefLeft && mid == st)) {
      reverse(x + st, x + end);
    }
  }
  // cerr << "(" << st << ", " << end << ") end:";
  // for(int i = st; i < end; i++) {
  //   cerr << " " << x[i];
  // }
  // cerr << endl;
}

int main() {
  int t, n; scanf("%d %d %*d", &t, &n);
  for(int tc = 1; tc <= t; tc++) {
    iota(x, x + n, 1);
    medianSort2(0, n, -1, true);
    answer(n);
  }
  return 0;
}
