import random

n = 10000
with open("data/dataset.txt", "w") as f:
    f.write(str(n) + "\n")
    f.write(" ".join(str(random.randint(1, 1000000)) for _ in range(n)) + "\n")
