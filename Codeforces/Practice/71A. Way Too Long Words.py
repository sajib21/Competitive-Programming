n = int(input())

while n > 0 :
    n -= 1
    word = input()
    sz = len(word)
    if sz > 10 :
        print(word[0] + str(sz-2) + word[sz-1])
    else :
        print(word)

