#include <algorithm>
#include <cmath>
#include <cstdio>
#include <map>
#include <vector>

using namespace std;

map<int, int> _factMem;
int largestPrimeFactor(int k) {
  if(_factMem[k]) return _factMem[k];

  for(int i = 2; i <= (int) sqrt(k); i++) {
    if(k % i != 0) continue;
    return _factMem[k] = largestPrimeFactor(k / i);
  }
  return _factMem[k] = k;
}

int getMax(int target, bool isFirst);

int getMaxAux(int target, vector<int>& facts, int k, int mult, bool isFirst) {
  if(k == facts.size()) {
    if(mult == 1 || (isFirst && mult == 2)) return 0;
    if(mult == target) return 1;
    return (target - mult) % mult != 0 ? 0 :
      1 + getMax((target - mult) / mult, false);
  }
  return max(
    getMaxAux(target, facts, k + 1, mult, isFirst),
    getMaxAux(target, facts, k + 1, mult * facts[k], isFirst)
  );
}

int getMax(int target, bool isFirst) {
  vector<int> facts;
  int rest = target;
  while(rest > 1) {
    int fct = largestPrimeFactor(rest);
    facts.push_back(fct);
    rest /= fct;
  }
  return getMaxAux(target, facts, 0, 1, isFirst);
}

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n; scanf("%d\n", &n);
    printf("Case #%d: %d\n", tc, getMax(n, true));
  }
  return 0;
}
