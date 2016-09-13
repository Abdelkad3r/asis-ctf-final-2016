# asis-ctf-final-2016

+ Crypto - SRPP:
  - When getting 'A', he is checking: 'A != 0' and 'A != N', he doesn't check: '0 < A' and 'A < N'.
  - When you send 'A' a multiple of 'N', then: 's = pow(A * pow(verifier, u, N), b, N) = 0'
  - No need to know 'verifier', so we can send: 'A = 2 * N'
  - The only unknown parameter is 'verifier' because it depends on the password
  - But when you use: 'A = 2 * N', you will eliminate it from the equation.
  - so i wrote script for that after understood it (srpp.py).
  - Finally i got the FLAG: ASIS{7bdb4b540699ef341f4a3b32469cd3f6}
