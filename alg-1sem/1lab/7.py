t = int(input())
for napravleniya in range(1 , t+1):
    n = int(input())
    minimum = 0
    maximum = 100
    for scores in range(n):
        s, num = input().split()
        num = int(num)
        if s=='>=':
            minimum = max(15, num , minimum)
        if s == '<=':
            maximum = min(30 , num , maximum)
        if minimum <= maximum:
            print(max(minimum , 15))
        else:
            maximum = -1
            print(-1)


