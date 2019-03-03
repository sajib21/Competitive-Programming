word = input()

sz = len(word)

word = word.lower()

ans = ""

for i in range(sz):
    if word[i] == 'y' or word[i] == 'a' or word[i] == 'e' or word[i] == 'i' or word[i] == 'o' or word[i] == 'u':
        continue
    ans += "." + word[i]

print(ans)




