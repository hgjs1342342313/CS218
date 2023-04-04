# BIT find invert pair
# Discussed with Tingzhang Cai
# 2023/Apr/3
# https://blog.csdn.net/a2459956664/article/details/51244572
# https://www.bilibili.com/video/BV1LW411e7jo/?spm_id_from=333.337.search-card.all.click&vd_source=abac68af8f49e77b4995808f907fe2b3
# https://blog.csdn.net/qq_41431457/article/details/88945833

n = int(input())
array = input().split(" ")
array = [int(i) for i in array]

c = [0] * (n+1)
ans = 0

# c[i] represents the sum of cnt[i-lowbit(i)+1, i] (number of pairs)
def add(c, i):
    while i<len(c):
        c[i]+=1
        i += i & (-i)

def query(c, i): 
    # query the region of [1, i], and return the number of pairs before i
    prefix_sum = 0
    while i>0:
        prefix_sum += c[i]
        i -= i & (-i)
    return prefix_sum

# get the number of invert pairs
for i in range(n):
    ans += i-query(c, array[i])
    add(c, array[i])

print(ans)