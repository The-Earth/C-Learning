a = int(input())
b = []
c = []
while a > 0:
    b.append(str(a % 2))
    a = a // 2

for i in range(len(b)):
    c.append(b[len(b)-1-i])

res = ''.join(c)

print(res)
