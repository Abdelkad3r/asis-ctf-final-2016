#!/usr/bin/python

from z3 import *

input = [BitVec('input[%d]' % i, ?? for i in range(25)]

_abs = abs

def abs(x):
    return If(x >= 0,x,-x)

def diff(a, b):
	p = 2
	v17 = pow(10, 4) - pow(100, 2) + 1
	r = 100
	for x, y in zip(a, b):
		c = 1
		if type(x-y) in [int, long]:
			print _abs(x-y) ** v17
			c = _abs(x-y) ** v17
		else:
			b = ZeroExt(24, abs(x-y))
			for i in range(v17):
				c *= b
		r += c
		v17 += 1
	
	return r

s = Solver()
s.add(diff(input[0:4], input[5:9]) == 0x17BF26)
s.add(diff(input[0:4][::-1], input[9:13]) == 0x27925A)
s.add(diff(input[0:4], input[13:17][::-1]) == 0x7E3C0)
s.add(diff(input[0:4], input[17:21]) == 0x2A9FA)
s.add(diff(input[0:4], input[21:25]) == diff(input[0:4], input[17:21][::-1]) / 5 - 3028)
prefix = bytearray('ASIS{')
for i in range(len(prefix)):
	s.add(input[i] == prefix[i])

for i in range(len(prefix), len(input)):
	s.add(input[i] & 0x80 == 0)
	s.add(input[i] > 31)

print s.check()
model = s.model()

for i in range(25):
	input[i] = model[input[i]].as_long()

input = bytearray(input) + '}'
print input
print hex(diff(input[0:4], input[5:9]))
exit()
