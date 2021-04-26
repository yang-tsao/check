import math
import bisect
ac = '.`^,:;!i><@+/-?][}{1)(|/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&%$'
n = int(input())
l = [list(map(float, input().split())) for i in range(n)]
x, y = map(int, input().split())
m = [[0]*y for i in range(x)]
L = []
for i in range(x-1, -1, -1):
    for j in range(y):
        for cg in l:
            m[i][j] += math.e**(1j*math.atan2(i-cg[1], j-cg[0])) * \
                cg[2]/((i-cg[1])**2+(j-cg[0])**2)
        m[i][j] = abs(m[i][j])
        L.append(m[i][j])
L.sort()
for i in range(x-1, -1, -1):
    for j in range(y):
        print(ac[int(bisect.bisect_left(L, m[i][j])/len(L)*len(ac))], end='')
    print()
