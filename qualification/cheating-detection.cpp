#include <algorithm>
#include <cstdio>
#include <cstring>
#include <numeric>

#define NP 100
#define NQ 10000

using namespace std;

char answers[NP][NQ + 1];

int qCnt[NQ], sCnt[NP];
int order[NQ];

int main() {
  int t; scanf("%d %*d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    for(int i = 0; i < NP; i++)
      scanf("%s", answers[i]);

    memset(sCnt, 0, sizeof(sCnt));
    memset(qCnt, 0, sizeof(qCnt));
    for(int i = 0; i < NP; i++) {
      for(int j = 0; j < NQ; j++) {
        sCnt[i] += answers[i][j] == '1';
        qCnt[j] += answers[i][j] == '1';
      }
    }

    iota(order, order + NQ, 0);
    sort(order, order + NQ, [](int j1, int j2) {
      return qCnt[j1] < qCnt[j2];
    });

    double bestScore = 0;
    int bestIdx = 0;
    for(int i = 0; i < NP; i++) {
      int corrects = 0;
      double score = 0;
      for(int j = 0; j < NQ; j++) {
        if(answers[i][order[j]] == '1') corrects++;
        else score += corrects;
      }
      score /= min(sCnt[i], NQ - sCnt[i]);
      if(score > bestScore) {
        bestScore = score;
        bestIdx = i;
      }
    }
    printf("Case #%d: %d\n", tc, bestIdx + 1);
  }
  return 0;
}
