n = input().split("+")
n.sort()
sol = ""

for i in range(len(n)):
    if i != 0: sol += "+"
    sol += n[i]

print(sol)