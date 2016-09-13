# asis-ctf-final-2016

+ Crypto - SRPP:
  - When getting 'A', he is checking: 'A != 0' and 'A != N', he doesn't check: '0 < A' and 'A < N'.
  - When you send 'A' a multiple of 'N', then: 's = pow(A * pow(verifier, u, N), b, N) = 0'
  - No need to know 'verifier', so we can send: 'A = 2 * N'
  - The only unknown parameter is 'verifier' because it depends on the password
  - But when you use: 'A = 2 * N', you will eliminate it from the equation.
  - so i wrote script for that after understood it (Check srpp.py).
  - Finally i got the FLAG: ASIS{7bdb4b540699ef341f4a3b32469cd3f6}
./d0ne

+ Reverse - Internet Of What?:
  - There are many strings, common path is "lwip": /home/factoreal/.arduino15/packages/esp8266/hardware/esp8266/2.3.0/cores/esp8266/abi.cpp
  - This is ESP8266 firmware for ARDUINO supported in IDA: https://github.com/themadinventor/ida-xtensa
  - Check it too: https://habrahabr.ru/post/255153/ and https://habrahabr.ru/post/255135/
  - It xref's found: (Check xref's file)
  - After understand the xref's and wrote the python script for knocking, you will find the IP address for flag page:
    http://138.68.152.88
  - Check it: http://prntscr.com/chj2e5
  - FLAG is: ASIS{The_first_person_to_prove_that_cow_milk_is_drinkable_was_very_very_thirsty} 
./d0ne

+ Reverse - Pretty Shallow:
  - Decompile it and read the C script: (Check pretty_shallow_diff.c and pretty_shallow_main.c)
  - After understand the C code you will be know that: FLAG length is: 26
  - After understood it, I wrote the python script for that by using Z3 Solver: (Check pretty_shallow.py)
  - FLAG is: ASIS{ilove_simpleflags___}
./d0ne
