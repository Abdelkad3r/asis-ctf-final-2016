#!/usr/bin/python
import socket

ports = [4025, 10619, 31337, 22207]
host = '138.68.152.88'

for i in range(len(ports)):
        print ports[i]
        try:
                s = socket.create_connection((host, ports[i]), 0.3)
        except:
                pass
