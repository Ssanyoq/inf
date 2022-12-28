import matplotlib as plt
import os

stream = os.popen("build/e read.txt write.txt")
print(stream.read())