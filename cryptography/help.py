import sys

def help():
    print("""USAGE
      ./mypgp [-xor | -aes | -rsa] [-c | -d] [-b] KEY
      the MESSAGE is read from standard input
DESCRIPTION
       -xor         computation using XOR algorithm
       -aes         computation using AES algorithm
       -rsa         computation using RSA algorithm
       -c           MESSAGE is clear and we want to cipher it
       -d           MESSAGE is ciphered and we want to decipher it
       -b           block mode: for xor and aes, only works on one block
                    MESSAGE and KEY must be of the same size
       -g P Q       for RSA only: generate a public and private key
                    pair from the prime number P and Q""")
    sys.exit(0)
