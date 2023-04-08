firstline = list(map(int, input().split(" ")))
n = firstline[0]
m = firstline[1]

member = [0 for i in range(n)]
#制作并查集
def find(x):
    if member[x]!=x:
        member[x] = find(member[x])
    return member[x]
    
for i in range(1, n):#O(n)
    #输入，初始化并查集
    tmp = int(input())
    member[i] = tmp
    #member.append(tmp)

traitors = dict()
for i in range(m):#O(m)
    traitor = int(input())
    traitors[traitor] = 1
    member[traitor] = traitor

for i in range(n):#O(n*1)
    if member[i] in traitors:#改成O（1）
        member[i] = i

answer = dict()

for i in range(n):#O(n)?
    find(i)

for i in range(n):#O(n*1)
    if member[i] not in answer:
        answer[member[i]] = 1
    else:
        answer[member[i]] += 1

#print("The maxnumber after the 0 is ",maxnum)

print( max(answer.values()))
