import sys

# Tableau S-Box pour AES
s_box = [
    [0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76],
    [0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0],
    [0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15],
    [0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75],
    [0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84],
    [0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf],
    [0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8],
    [0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2],
    [0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73],
    [0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb],
    [0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79],
    [0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08],
    [0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a],
    [0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e],
    [0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf],
    [0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16]
]

inv_s_box = [
    [0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb],
    [0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87, 0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb],
    [0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d, 0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e],
    [0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2, 0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25],
    [0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92],
    [0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda, 0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84],
    [0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a, 0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06],
    [0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02, 0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b],
    [0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea, 0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73],
    [0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85, 0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e],
    [0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89, 0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b],
    [0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20, 0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4],
    [0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31, 0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f],
    [0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d, 0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef],
    [0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0, 0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61],
    [0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26, 0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d]
]

rcon = [
    [0x01, 0x00, 0x00, 0x00],
    [0x02, 0x00, 0x00, 0x00],
    [0x04, 0x00, 0x00, 0x00],
    [0x08, 0x00, 0x00, 0x00],
    [0x10, 0x00, 0x00, 0x00],
    [0x20, 0x00, 0x00, 0x00],
    [0x40, 0x00, 0x00, 0x00],
    [0x80, 0x00, 0x00, 0x00],
    [0x1b, 0x00, 0x00, 0x00],
    [0x36, 0x00, 0x00, 0x00]
]

def mult_1(value):
    return value

def mult_2(value):
    return value << 1 if value < 128 else (value << 1) ^ 0x1b

def mult_3(value):
    return mult_2(value) ^ value

def mult_9(value):
    return mult_2(mult_2(mult_2(value))) ^ value

def mult_11(value):
    return mult_2(mult_2(mult_2(value) ^ value)) ^ value

def mult_13(value):
    return mult_2(mult_2(value) ^ value) ^ value

def mult_14(value):
    return mult_2(mult_2(value) ^ mult_2(mult_2(value)))


def findS_boxValue(value:str):
    line = int(value[0], 16)
    col = int(value[1], 16)
    return s_box[line][col]

def findInvS_boxValue(value:str):
    line = int(value[0], 16)
    col = int(value[1], 16)
    return inv_s_box[line][col]

def subBytes(matrix):
    newMatrix = []
    for i in matrix:
        newMatrix.append(bytearray([]))
        for j in i:
            newMatrix[-1].append(findS_boxValue(hex(j)[2:].zfill(2)))
    return newMatrix

def invSubBytes(matrix):
    newMatrix = []
    for i in matrix:
        newMatrix.append(bytearray([]))
        for j in i:
            newMatrix[-1].append(findInvS_boxValue(hex(j)[2:].zfill(2)))
    return newMatrix

def shiftRows(matrix):
    for i in range(len(matrix)):
        matrix[i] = matrix[i][i:] + matrix[i][:i]
    return matrix

def invShiftRows(matrix):
    for i in range(1, 4):
        matrix[i] = matrix[i][-i:] + matrix[i][:-i]
    return matrix

def mixColumns(matrix):
    newMatrix = []
    for i in range(4):
        newMatrix.append(bytearray([0, 0, 0, 0]))
    for i in range(4):
        newMatrix[0][i] = (mult_2(matrix[0][i]) ^ mult_3(matrix[1][i]) ^ mult_1(matrix[2][i]) ^ mult_1(matrix[3][i])) & 0xff
        newMatrix[1][i] = (mult_1(matrix[0][i]) ^ mult_2(matrix[1][i]) ^ mult_3(matrix[2][i]) ^ mult_1(matrix[3][i])) & 0xff
        newMatrix[2][i] = (mult_1(matrix[0][i]) ^ mult_1(matrix[1][i]) ^ mult_2(matrix[2][i]) ^ mult_3(matrix[3][i])) & 0xff
        newMatrix[3][i] = (mult_3(matrix[0][i]) ^ mult_1(matrix[1][i]) ^ mult_1(matrix[2][i]) ^ mult_2(matrix[3][i])) & 0xff
    return newMatrix

def invMixColumns(matrix):
    newMatrix = []
    for i in range(4):
        newMatrix.append(bytearray([0, 0, 0, 0]))

    for i in range(4):
        newMatrix[0][i] = (mult_14(matrix[0][i]) ^ mult_11(matrix[1][i]) ^ mult_13(matrix[2][i]) ^ mult_9(matrix[3][i])) & 0xff
        newMatrix[1][i] = (mult_9(matrix[0][i]) ^ mult_14(matrix[1][i]) ^ mult_11(matrix[2][i]) ^ mult_13(matrix[3][i])) & 0xff
        newMatrix[2][i] = (mult_13(matrix[0][i]) ^ mult_9(matrix[1][i]) ^ mult_14(matrix[2][i]) ^ mult_11(matrix[3][i])) & 0xff
        newMatrix[3][i] = (mult_11(matrix[0][i]) ^ mult_13(matrix[1][i]) ^ mult_9(matrix[2][i]) ^ mult_14(matrix[3][i])) & 0xff
    return newMatrix

def addRoundKey(matrix, roundKey):
    for i in range(len(matrix)):
        for j in range(len(matrix[i])):
            matrix[i][j] ^= roundKey[j][i]
    return matrix

def oneColumnXor(col1, col2):
    newCol = bytearray(4)
    for i in range(4):
        newCol[i] = col1[i] ^ col2[i]
    return newCol

# KEY SCHEDULE
def getkeySchedule(cipherKey):
    matrixList = []
    RconIndex = 0
    matrixIndex = 3

    # add cipher key to matrix
    for i in range(4):
        matrixList.append(bytearray([cipherKey[j][i] for j in range(4)]))

    for _ in range(10): # create 10 round key
        tempColumn = matrixList[matrixIndex] # Wi-1

        # RotWord
        tempColumn = tempColumn[1:] + tempColumn[:1]

        # SubBytes
        tempColumn = bytearray([findS_boxValue(hex(j)[2:].zfill(2)) for j in tempColumn])

        # xor Rcon
        tmp = matrixList[matrixIndex - 3] # Wi-4
        for i in range(4):
            tempColumn[i] = tmp[i] ^ tempColumn[i] ^ rcon[RconIndex][i]
        matrixList.append(tempColumn)

        # generate 3 last column for the round key
        for i in range(3):
            matrixIndex += 1
            col1 = matrixList[matrixIndex] # Wi-1
            col2 = matrixList[matrixIndex - 3] # Wi-4
            matrixList.append(oneColumnXor(col1, col2))
        RconIndex += 1
        matrixIndex += 1

    matrixArray = []

    for i in range(0, len(matrixList), 4):
        matrixArray.append(matrixList[i:i+4])

    return matrixArray


# matrix function
def createMatrix(message):
    message = bytearray.fromhex(message)
    matrixArray = []

    for i in range(0, len(message), 16):
        matrix = []
        for j in range(4):
            column = []
            try:
                for k in range(i + j, i + 16, 4):
                    column.append(message[k])
            except IndexError:
                pass
            matrix.append(bytearray(column))
        matrixArray.append(matrix)

    for i in range(len(matrixArray)):
        for j in range(len(matrixArray[i])):
            for k in range(len(matrixArray[i][j]), 4):
                matrixArray[i][j].append(0)

    return matrixArray


# debug functions
def printOneColumn(matrix):
    for i in matrix:
        print(hex(i)[2:].zfill(2), end=" ")
    print()

def printMatrix(matrix):
    for i in matrix:
        for j in i:
            print(hex(j)[2:].zfill(2), end=" ", file=sys.stderr)
        print(file=sys.stderr)
    print(file=sys.stderr)

# main functions
def encrypt(matrix, keySchedule):
    matrix = addRoundKey(matrix, keySchedule[0])

    for i in range(1, 10):
        matrix = subBytes(matrix)
        matrix = shiftRows(matrix)
        matrix = mixColumns(matrix)
        matrix = addRoundKey(matrix, keySchedule[i])

    matrix = subBytes(matrix)
    matrix = shiftRows(matrix)
    matrix = addRoundKey(matrix, keySchedule[10])

    return matrix

def decrypt(matrix, keySchedule):
    matrix = addRoundKey(matrix, keySchedule[10])

    for i in range(9, 0, -1):
        matrix = invShiftRows(matrix)
        matrix = invSubBytes(matrix)
        matrix = addRoundKey(matrix, keySchedule[i])
        matrix = invMixColumns(matrix)

    matrix = invShiftRows(matrix)
    matrix = invSubBytes(matrix)
    matrix = addRoundKey(matrix, keySchedule[0])

    return matrix

def matrixToString(matrixArray):
    result = bytearray()
    for matrix in matrixArray:
        for col in range(4):
            for row in range(4):
                result.append(matrix[row][col])
    return result.hex()

def aes(mode, message, key):
    matrixArray = createMatrix(message)
    cipherKey = createMatrix(key)

    keySchedule = getkeySchedule(cipherKey[0])

    for i in range(len(matrixArray)):
        if (mode == 0):
            matrixArray[i] = encrypt(matrixArray[i], keySchedule)
        if (mode == 1):
            matrixArray[i] = decrypt(matrixArray[i], keySchedule)

    print(matrixToString(matrixArray))
