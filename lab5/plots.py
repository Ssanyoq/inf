import matplotlib as plt
import os
import random

def generate_read(n: int):
    with open("read.txt", "w") as file:
        for i in range(n):
            


stream = os.popen("build/e read.txt write.txt")
print(stream.read())