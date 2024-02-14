def xor(mode, message, key):
    messageHex = bytes.fromhex(message)
    keyHex = bytes.fromhex(key)
    messageHexLen = len(messageHex)

    result = bytearray(messageHexLen)
    keyIndex = 0
    for i in range(messageHexLen):
        result[i] = messageHex[i] ^ keyHex[keyIndex]
        keyIndex += 1
        if keyIndex >= len(keyHex):
            keyIndex = 0
    print(result.hex())
