#include <algorithm>
#include <cstdio>
#include <numeric>
#include <utility>

#define MAXN 50

using namespace std;

int x[MAXN];

int ask(int i1, int i2, int i3) {
  printf("%d %d %d\n", x[i1], x[i2], x[i3]);
  fflush(stdout);
  int ans; scanf("%d", &ans);
  if(ans == -1) exit(0);
  return ans == x[i1] ? i1 : ans == x[i2] ? i2 : i3;
}

void answer(int n) {
  printf("%d", x[0]);
  for(int i = 1; i < n; i++) {
    printf(" %d", x[i]);
  }
  printf("\n");
  fflush(stdout);
  int ans; scanf("%d", &ans);
  if(ans == -1) exit(0);
}

void medianSort(int st, int end, int ref, bool isRefLeft) {
  if(end - st <= 1) return;
  if(end - st > 2) {
    int sep1 = st, sep2 = end - 1;
    for(int i = st + 1; i < sep2; i++) {
      int res = ask(st, end - 1, i);
      if(res == st) swap(x[++sep1], x[i]);
      if(res == end - 1) swap(x[--sep2], x[i--]);
    }
    swap(x[st], x[sep1]);
    swap(x[end - 1], x[sep2]);

    medianSort(st, sep1, sep1, false);
    medianSort(sep1 + 1, sep2, sep2, false);
    medianSort(sep2 + 1, end, sep2, true);
  }
  if(ref != -1) {
    int mid = ask(st, st + 1, ref);
    if((isRefLeft && mid == st + 1) || (!isRefLeft && mid == st)) {
      reverse(x + st, x + end);
    }
  }
}

int main() {
  int t, n; scanf("%d %d %*d", &t, &n);
  for(int tc = 1; tc <= t; tc++) {
    iota(x, x + n, 1);
    medianSort(0, n, -1, true);
    answer(n);
  }
  return 0;
}
