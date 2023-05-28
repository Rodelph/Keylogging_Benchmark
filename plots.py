#!/usr/bin/python3

from os import listdir
from matplotlib import pyplot as plt
import numpy as np
path="/home/swt/Programme/Keylogging_Benchmark/benchmarks/"

files = [f for f in listdir(path) if "txt" in str(f)]
files = sorted(files)
encr = {32:[], 128:[], 512:[], 2048:[]}
decr = {32:[], 128:[], 512:[], 2048:[]}
mem = {32:[], 128:[], 512:[], 2048:[]}

for file in files:
    f = open(path+file, "r")
    for line in f.readlines():
        if "encr" in line:
            encr[int(file.split(".")[0])].append(float(line.split()[-2]))
        if "decr" in line:
            decr[int(file.split(".")[0])].append(float(line.split()[-2]))
        if line[0].isdigit():
            mem[int(file.split(".")[0])].append(int(line))
            
print(mem)

fig, axs = plt.subplots(4, 3)
# print(axs[0])

for i in range(len(axs)):
    aes = [0, 0] + encr[list(encr.keys())[i]][0:3]
    blowfish = encr[list(encr.keys())[i]][3:]
    axs[i, 0].bar(np.arange(5)-0.1, aes, width=0.2, color="orange", label="AES")
    axs[i, 0].bar(np.arange(5)+0.1, blowfish, width=0.2, color="blue", label="Blowfish")
    axs[i, 0].set_ylabel(str(list(encr.keys())[i]) + "\n\n\nTime in ms")
    axs[i, 0].set_xticklabels(["0", "32", "64", "128", "192", "256"])

    aes = [0, 0] + decr[list(decr.keys())[i]][0:3]
    blowfish = decr[list(decr.keys())[i]][3:]
    axs[i, 1].bar(np.arange(5)-0.1, aes, width=0.2, color="orange", label="AES")
    axs[i, 1].bar(np.arange(5)+0.1, blowfish, width=0.2, color="blue", label="Blowfish")
    axs[i, 1].set_ylabel("Time in ms")
    axs[i, 1].set_xticklabels(["0", "32", "64", "128", "192", "256"])

    aes = [0, 0] + mem[list(mem.keys())[i]][0:3]
    blowfish = mem[list(mem.keys())[i]][3:]
    axs[i, 2].bar(np.arange(5)-0.1, aes, width=0.2, color="orange", label="AES")
    axs[i, 2].bar(np.arange(5)+0.1, blowfish, width=0.2, color="blue", label="Blowfish")
    axs[i, 2].set_ylabel("Used memory in Bytes")
    axs[i, 2].set_xticklabels(["0", "32", "64", "128", "192", "256"])
axs[0, 0].set_title("Encryption")
axs[0, 1].set_title("Decryption")
axs[0, 2].set_title("Memory usage")
axs[3, 0].set_xlabel("Key size")
axs[3, 1].set_xlabel("Key size")
axs[3, 2].set_xlabel("Key size")
axs[0, 0].legend(loc='upper left')
plt.show()