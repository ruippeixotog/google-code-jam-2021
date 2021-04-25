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

int x[MAXN], y[MAXN];

// ll secondNs = pow(10, 9);
// ll minuteNs = 60LL * pow(10, 9); 
// ll hourNs = 360LL * pow(10, 9);
// ll clockNs = 12 * hourNs;

ll clockNs = (12 * 60 * 60 * 1000000000LL);

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    // cerr << "tc " << tc << endl;

    ll p[3]; scanf("%lld %lld %lld\n", &p[0], &p[1], &p[2]);

    vector<vector<ll>> opts = {
      {p[0], p[1], p[2]},
      {p[0], p[2], p[1]},
      {p[1], p[0], p[2]},
      {p[1], p[2], p[0]},
      {p[2], p[0], p[1]},
      {p[2], p[1], p[0]}
    };

    int res = -1;
    for(int k = 0; res == -1 && k < opts.size(); k++) {
      ll mShift = (opts[k][1] - opts[k][0] + clockNs) % clockNs;
      ll sShift = (opts[k][2] - opts[k][0] + clockNs) % clockNs;
      // cerr << "shifts " << mShift << " " << sShift << endl;

      for(int secsAfterMid = 0; secsAfterMid < 12 * 60 * 60; secsAfterMid++) {
        ll h = secsAfterMid * 1000000000LL;
        ll m = (secsAfterMid * 1000000000LL * 12) % clockNs;
        ll s = (secsAfterMid * 1000000000LL * 720) % clockNs;

        // if(secsAfterMid == 6 * 60 * 60 + 30 * 60) {
        //   cerr << "correct answer: " << h << " " << m << " " << s << endl;
        // }

        if(m == (h + mShift) % clockNs && s == (h + sShift) % clockNs) {
          res = secsAfterMid;
          break;
        }
      }
    }

    // cerr << "res " << res << endl;
    printf("Case #%d: %d %d %d %d\n", tc, res / (60 * 60), res / 60 % 60, res % 60, 0);


    // ll res = -1;
    // do {
    //   ll mShift = (p[1] - p[0] + clockNs) % clockNs;
    //   ll sShift = (p[2] - p[0] + clockNs) % clockNs;

    //   for(int h = 0; res == -1 && h < 12; h++) {
    //     ll hLow = h * hourNs, hHigh = (h + 1) * hourNs;
    //     ll mLow = (hLow + mShift) % clockNs, mHigh = (hHigh + mShift) % clockNs;

    //     if(mLow < mHigh) {
    //       while(hLow < hHigh) {
    //         ll hMid = (hLow + hHigh) / 2;
    //         ll mMid = (hMid + mShift) % clockNs;

    //         ll nsInHour = hMid - h * hourNs;

    //         if(mMid * 12 == nsInHour) {
    //           ll sMid = (hMid + sShift) % clockNs;
    //           if(sMid * 12 * 60 == nsInHour) {
    //             res = hMid;
    //           }
    //           break;
    //         } else if (mMid * 12 > nsInHour) {
    //           hHigh = hMid;
    //         } else {
    //           hLow = hMid + 1;
    //         }
    //       }
    //     }
    //   }
    // } while(res == -1 && next_permutation(p, p + 3));

    // printf("Case #%d: %lld %lld %lld %lld\n", tc, res / hourNs, res / minuteNs % 60, res / secondNs % 60, res % 1000000000LL);
  }
  return 0;
}
