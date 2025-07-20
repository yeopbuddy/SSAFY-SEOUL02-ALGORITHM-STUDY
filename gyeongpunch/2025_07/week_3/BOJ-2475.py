A = map(int, input().split())
num = 0
for i in A:
    num += i*i
num %= 10

print(num)