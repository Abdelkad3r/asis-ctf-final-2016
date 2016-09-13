#coded by Abdelkader
#!/usr/bin/python

import socket, sys, hashlib

def lstring(s, p):
    line = ""
    i = s.recv(1)
    line += i
    sys.stdout.write(i)
    while line.find(p) == -1:
        i = s.recv(1)
        line += i
        sys.stdout.write(i)
    return line

def brute(suffix, prefix):
    chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
    for i1 in chars:
        for i2 in chars:
            for i3 in chars:
                for i4 in chars:
                    s = i1+i2+i3+i4+suffix
                    if hashlib.sha512(s).hexdigest().startswith(prefix):
                        return i1+i2+i3+i4

def Hash(*args):
    a = ':'.join(str(a) for a in args)
    return int(hashlib.sha256(a).hexdigest(), 16)

def main():
    try:
        s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    except (socket.error, msg):
        print ('[!]Failed to create socket. Error code: ' + str(msg[0]))
        return
    try:
        s.connect(("srpp.asis-ctf.ir", 22778))
    except:
        print ('[!] Unable to resolve.')
        print ('[!] Closing SOCK_STREAM and exiting.')
        s.close()
        return
    lstring(s,"SHA512")
    result = lstring(s, "Enter X: ")
    suffix = result[6:28]
    prefix = result[46:78]
    X = brute(suffix, prefix)
    s.send(X+"\n")
    print X
    while True:
        lstring(s, 'params = (N, g, k) = ')
        result = lstring(s, ')')
        N,g,k = result[1:-1].split(', ')
        N = int(N[:-1])
        g = int(g)
        k = int(k[:-1])
        lstring(s, ' as "email, A": '+'\n')
        A = 2*N
        email = 'admin@asis-ctf.ir'
        s.send("%s,%d\n" % (email, A))
        print "%s,%d\n" % (email, A)
        lstring(s, '(salt,  public_ephemeral) = ')
        result = lstring(s, ')')
        salt,B = result[1:-1].split(', ')
        salt = salt.decode('base64')
        B = int(B)

        lstring(s, 'Send the session key: ' + '\n')
        K_client = Hash(0)
        s.send("%d\n"%K_client)
        print "%d\n"%K_client

        lstring(s, 'Send a POC of session key: ' + '\n')
        M_client = Hash(Hash(N).__xor__(Hash(g)), Hash(email), salt, A, B, K_client)
        # M_client = 43388321209941149759420236104888244958223766953174235657296806338137402595305
        s.send("%d\n"%M_client)
        print "%d\n"%M_client

main()
