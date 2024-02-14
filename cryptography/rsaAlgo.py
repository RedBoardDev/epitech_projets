import math

def fromLittleEndian(key:str):
    return int.from_bytes(bytes.fromhex(key), 'little')

def rsaEncrypt(message, key):
    m = fromLittleEndian(message)
    key = key.split('-')
    e = fromLittleEndian(key[0])
    n = fromLittleEndian(key[1])
    x = pow(m, e, n)
    print(toLittleEndian(x))

def rsaDecrypt(message, key):
    x = fromLittleEndian(message)
    key = key.split('-')
    d = fromLittleEndian(key[0])
    n = fromLittleEndian(key[1])
    m = pow(x, d, n)
    print(toLittleEndian(m))

def rsa(mode, message, key):
    if mode == 0:
        rsaEncrypt(message, key)
    elif mode == 1:
        rsaDecrypt(message, key)

def toLittleEndian(a:int):
    bytes = a.to_bytes((a.bit_length() + 7) // 8, 'little')
    res = ""
    for byte in bytes:
        res += format(byte, '02x')
    return res

def getE(phin, p, q):
    e = max(p, q) + 1
    while (True):
        if (math.gcd(e, phin) == 1):
            break
        e += 1
    return e

def getD(e, phin):
    v = 1
    while v % e != 0:
        v += phin
    return v // e

def generateRSAKeys(p, q):
    p = fromLittleEndian(p)
    q = fromLittleEndian(q)
    n = p * q
    phin = (p - 1) * (q - 1)
    e = 65537
    d = getD(e, phin)
    print(f"public key: {toLittleEndian(e)}-{toLittleEndian(n)}")
    print(f"private key: {toLittleEndian(d)}-{toLittleEndian(n)}")
