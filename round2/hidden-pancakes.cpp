#include <cstdio>
#include <map>
#include <set>
#include <vector>

#define MAXN 100000
#define MOD 1000000007

using namespace std;

typedef long long ll;

inline ll mmul(ll a, ll b) { return (a * b) % MOD; }
inline ll madd(ll a, ll b) { return (a + b) % MOD; }
inline ll msub(ll a, ll b) { return (a + MOD - b) % MOD; }

ll mpow(ll a, ll p) {
  if(p == 0) return 1;
  ll halfPow = mpow(a, p / 2);
  return mmul(halfPow, p % 2 ? mmul(a, halfPow) : halfPow);
}

// modular inverse exists only if MOD is prime (or coprime to a)
inline ll minv(ll a) { return mpow(a, MOD - 2); }
inline ll mdiv(ll a, ll b) { return mmul(a, minv(b)); }

vector<ll> _mfactMem(1, 1);
ll mfact(ll a) {
  if(a >= MOD) return 0;
  while(a >= _mfactMem.size())
    _mfactMem.push_back(mmul(_mfactMem.size(), _mfactMem.back()));
  return _mfactMem[a];
}

ll mcomb(ll n, ll k) {
  if (n == 0 && k == 0) return 1;
  ll ni = n % MOD, ki = k % MOD;
  if (ni < ki) return 0;
  ll comb = mmul(mfact(ni), mmul(minv(mfact(ki)), minv(mfact(ni - ki))));
  return mcomb(n / MOD, k / MOD) * comb;
}

// -----------------------------------------------

int v[MAXN];

map<int, set<int>> smaller;

pair<ll, int> calculate(int k) {
  ll res = 1; int sz = 0;
  for(int k2 : smaller[k]) {
    auto subres = calculate(k2);
    res = mmul(res, subres.first);
    res = mmul(res, mcomb(sz + subres.second, sz));
    sz += subres.second;
  }
  return {res, 1 + sz};
}

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n; scanf("%d\n", &n);
    for(int i = 0; i < n; i++) {
      scanf("%d\n", &v[i]);
    }

    smaller.clear();
    bool valid = v[0] == 1;
    vector<int> visible = {0};
    for(int i = 1; valid && i < n; i++) {
      if(v[i] > visible.size() + 1) {
        valid = false;
        break;
      }
      if(v[i] == 1) {
        smaller[i].insert(visible[0]);
      } else if(v[i] == visible.size() + 1) {
        smaller[visible[visible.size() - 1]].insert(i);
      } else {
        smaller[visible[v[i] - 2]].erase(visible[v[i] - 1]);
        smaller[visible[v[i] - 2]].insert(i);
        smaller[i].insert(visible[v[i] - 1]);
      }
      visible.resize(v[i] - 1);
      visible.push_back(i);
    }
    printf("Case #%d: %lld\n", tc, valid ? calculate(visible[0]).first : 0);
  }
  return 0;
}
