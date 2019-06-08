from random import choice

n = int(input())

exp = [10**x for x in range(5)]
for e in exp:
    t = 0
    for _ in range(e):
        tails = 0
        while tails != n:
            t += 1
            if choice('TH') == 'T':
                tails += 1
            else:
                tails = 0
    print(f'Experiments: {e}')
    print(f'Average Value: {t / e}')
