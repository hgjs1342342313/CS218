def find(x):
    if arr[x] != x:
        arr[x] = find(arr[x])
    return arr[x]
    
def union(a, b):
    arr[find(a)] = find(b)

inp = input().split()
n, m = int(inp[0]), int(inp[1])
arr = [0]
for i in range(1, n):
    parent = int(input())
    arr.append(parent)

traitors = dict()
for i in range(m):
    traitor = int(input())
    traitors[traitor] = 1
    arr[traitor] = traitor

# find traitors' family
for i in range(n):
    if arr[i] in traitors:
        arr[i] = i

# union-find all nodes
for i in range(n):
    find(i)
#print(arr)
# get the largest group
mp = {}
for i in range(n):
    if arr[i] not in mp:
        mp[arr[i]] = 1
    else:
        mp[arr[i]] += 1
print(max(mp.values()))