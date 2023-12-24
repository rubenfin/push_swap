import random

arr = [i for i in range(1, 501)]

random.shuffle(arr)
for i, el in enumerate(arr):
    end_char = '' if i == len(arr) - 1 else ' '
    print(f'{el}{end_char}', end="")
