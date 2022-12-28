import matplotlib as plt
import os
import random
import string


def generate_read(n: int):
    with open("reads/read" + str(n) + ".txt", "w") as file:
        file.write(str(n) + '\n')
        for i in range(n):
            name = ''
            phone = ''
            for j in range(10):
                name += random.choice(string.ascii_letters)
                phone += random.choice(string.digits)
            ts = random.randint(0, 1_000_000_000)
            print(name, phone, ts, sep='\n', file=file)


generate_read(10000)
stream = os.fopen("build/e reads/read100.txt write.txt")
print(stream.read())
