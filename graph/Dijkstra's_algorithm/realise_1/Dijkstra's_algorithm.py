# work with matrix

from math import inf

N, S = map(int, input().split())  # N >= 1, 0 <= S <= N - 1
# length of graph, start point

rng = range(N)  # for optimization

matrix = [list(map(int, input().split())) for _ in rng]
# initialization matrix
# -1 if vertexes haven'ts edge

not_used = [True for _ in rng]  # visited points

dist = [inf for i in rng]  # path to points
dist[S] = 0

for i in rng:
    index_to_use = -1

    for j in rng:
        if not_used[j] and (index_to_use == -1 or dist[j] < dist[index_to_use]):
            index_to_use = j
    #  find not used point with smallest path

    for j in rng:
        if j != index_to_use and matrix[index_to_use][j] != -1:
            dist[j] = min(dist[j], dist[index_to_use] + matrix[index_to_use][j])
    #  find min

    not_used[index_to_use] = False

for num, i in enumerate(dist):
    print(num, i, sep=" => ")
