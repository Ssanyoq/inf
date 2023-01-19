import matplotlib.pyplot as plt
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

start = int(input("from: "))
end = int(input("to: "))
step = int(input("with step: "))
# generate_read(100)
# quit()
qs = []
ss = []
odd = []
for j in 's':
    time = [] # x
    amt = [] # y
    for i in range(start, end + 1, step):
        generate_read(i)
        stream = os.popen("build/e reads/read" + str(i) + ".txt write.txt -f 2 -s " + j)
        amt.append(i)
        time.append(int(float(stream.read()) * 1_000_000)) # microseconds
        os.system("rm reads/read" + str(i) + ".txt")
    if j == 'q':
        qs = [time, amt]
        print(*time, sep='\n')
    elif j == 's':
        ss = [time, amt]
        print(*time, sep='\n')
    else:
        odd = [time, amt]
        print(*time, sep='\n')
