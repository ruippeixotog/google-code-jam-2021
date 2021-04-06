import math
import sys
from random import random, uniform

T = 50
NP = 100
NQ = 10000

CHEATER = 42

def sigmoid(x):
  return 1 / (1 + math.exp(-x))

print(T)
print(86)
for tc in range(0, T):
  s = [uniform(-3.0, 3.0) for i in range(0, NP)]
  q = [uniform(-3.0, 3.0) for i in range(0, NQ)]

  for i in range(0, NP):
    res = ""
    for j in range(0, NQ):
      prob = sigmoid(s[i] - q[j])
      if i + 1 == CHEATER and random() < 0.5:
        res += "1"
      else:
        res += "1" if random() < prob else "0"
    print(res)
