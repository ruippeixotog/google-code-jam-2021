#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long ll;

const ll secondNs = 1000000000LL;
const ll minuteNs = 60 * secondNs; 
const ll hourNs = 60 * minuteNs;
const ll clockNs = 12 * hourNs;

ll bs(ll hLow, ll hHigh, ll mShift, ll sShift) {
  while(hLow < hHigh) {
    ll hMid = (hLow + hHigh) / 2;
    ll mMid = (hMid + mShift) % clockNs;
    ll sMid = (hMid + sShift) % clockNs;

    if(mMid == hMid % hourNs * 12) {
      return sMid == hMid % minuteNs * 12 * 60 ? hMid : -1;
    } else if (hMid % hourNs * 12 > mMid) {
      hHigh = hMid;
    } else {
      hLow = hMid + 1;
    }
  }
  return -1;
}

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    ll p[3]; scanf("%lld %lld %lld\n", &p[0], &p[1], &p[2]);

    ll res = -1;
    int ord[] = {0, 1, 2};
    do {
      ll mShift = (p[ord[1]] - p[ord[0]] + clockNs) % clockNs;
      ll sShift = (p[ord[2]] - p[ord[0]] + clockNs) % clockNs;

      for(int h = 0; res == -1 && h < 12; h++) {
        ll hLow = h * hourNs, hHigh = (h + 1) * hourNs;
        ll mLow = (hLow + mShift) % clockNs, mHigh = (hHigh + mShift) % clockNs;

        if(mLow < mHigh) {
          res = bs(hLow, hHigh, mShift, sShift);
        } else {
          res = bs(hLow, hHigh - mHigh, mShift, sShift);
          if(res == -1) {
            res = bs(hHigh - mHigh, hHigh, mShift, sShift);
          }
        }
      }
    } while(res == -1 && next_permutation(p, p + 3));

    printf("Case #%d: %lld %lld %lld %lld\n", tc,
      res / hourNs % 12,
      res / minuteNs % 60,
      res / secondNs % 60,
      res % secondNs
    );
  }
  return 0;
}
