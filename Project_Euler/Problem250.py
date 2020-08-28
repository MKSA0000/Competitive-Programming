def test1():
    N = 250
    MOD = 250
    lists = [x ** x % MOD for x in range(N)]
    print(lists)


def test2(x,y):
    print((x ** x + y ** y) % 250)

if __name__ == '__main__':
    test1()
    #test2(1,249)