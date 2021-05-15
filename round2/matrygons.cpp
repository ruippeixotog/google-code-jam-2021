#include <algorithm>
#include <cmath>
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

int x[MAXN], y[MAXN];

// Integer factorization - O(sqrt(k))
map<int, int> _factMem;
int largestPrimeFactor(int k) {
  if(_factMem[k]) return _factMem[k];

  for(int i = 2; i <= (int) sqrt(k); i++) {
    if(k % i != 0) continue;
    return _factMem[k] = max(largestPrimeFactor(i), largestPrimeFactor(k / i));
  }
  return _factMem[k] = k;
}

int getMax(int target, bool isFirst);

int getMaxAux(int target, vector<int>& facts, int idx, int mult, bool isFirst) {
  if(idx == facts.size()) {
    if(mult == 1 || (isFirst && mult == 2)) return 0;
    if(mult == target) return 1;
    if((target - mult) % mult != 0) return 0;
    // cerr << "trying fact " << mult << " on target " << target << endl;
    return 1 + getMax((target - mult) / mult, false);
  }
  return max(
    getMaxAux(target, facts, idx + 1, mult, isFirst),
    getMaxAux(target, facts, idx + 1, mult * facts[idx], isFirst)
  );
}

map<pair<int, bool>, int> _maxMem;
int getMax(int target, bool isFirst) {
  if(_maxMem[{target, isFirst}]) return _maxMem[{target, isFirst}];

  vector<int> facts;
  int rest = target;
  while(rest > 1) {
    int fct = largestPrimeFactor(rest);
    facts.push_back(fct);
    rest /= fct;
  }
  return _maxMem[{target, isFirst}] = getMaxAux(target, facts, 0, 1, isFirst);
}

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    // cerr << "case " << tc << endl;

    int n; scanf("%d\n", &n);
    printf("Case #%d: %d\n", tc, getMax(n, true));
  }
  return 0;
}
