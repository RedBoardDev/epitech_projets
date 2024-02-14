import sys
import xorAlgo
import aesAlgo
import rsaAlgo

def hubAlgo(algoType, mode, blockMode, key):
    # print("algoType:", algoType, "mode:", mode, "blockMode:", blockMode, "key:", key)
    message = ""
    message = sys.stdin.read().strip()
    if blockMode == 1 and algoType == 2:
        raise Exception("RSA does not support block mode")
    if blockMode == 1 and len(message) != len(key):
        raise Exception("Key and message must have the same length")
    if (algoType == 0):
        xorAlgo.xor(mode, message, key)
    elif (algoType == 1):
        aesAlgo.aes(mode, message, key)
    elif (algoType == 2):
        rsaAlgo.rsa(mode, message, key)
