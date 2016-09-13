__int64 __fastcall main(__int64 a1, char **a2, char **a3)
{
  char *v3; // rax@3
  char *v4; // rbx@3
  char *v5; // rax@3
  signed int v6; // ebx@4
  unsigned __int64 v8; // rbx@8
  unsigned __int64 v9; // rdx@8
  __int64 v10; // rbx@13
  size_t v11; // r12@22
  __int64 v12; // rax@25
  unsigned __int8 v13; // cf@27
  unsigned __int64 v14; // rdx@27
  unsigned __int64 v15; // r14@28
  void *v16; // rbp@28
  __int64 v17; // r13@29
  __int64 v18; // r13@30
  char *v19; // rdx@33
  unsigned __int64 i; // rax@34
  char v21; // cl@35
  char v22; // si@35
  __int64 v23; // rbx@37
  char *v24; // rdi@47
  char *v25; // rdx@48
  unsigned __int64 j; // rax@49
  char v27; // cl@50
  char v28; // si@50
  __int64 v29; // rbx@52
  __int64 v30; // rbx@59
  char *v31; // rdx@66
  unsigned __int64 k; // rax@67
  char v33; // cl@68
  char v34; // si@68
  __int64 v35; // rbp@70
  __int64 v36; // rbx@70
  __int64 v37; // rbx@106
  buf input; // [sp+0h] [bp-428h]@1
  buf v39; // [sp+20h] [bp-408h]@13
  buf v40; // [sp+40h] [bp-3E8h]@13
  buf a1a; // [sp+60h] [bp-3C8h]@13
  buf a2a; // [sp+80h] [bp-3A8h]@13
  buf v43; // [sp+A0h] [bp-388h]@37
  buf v44; // [sp+C0h] [bp-368h]@37
  buf v45; // [sp+E0h] [bp-348h]@52
  buf v46; // [sp+100h] [bp-328h]@52
  buf v47; // [sp+120h] [bp-308h]@59
  buf v48; // [sp+140h] [bp-2E8h]@59
  buf v49; // [sp+160h] [bp-2C8h]@70
  buf v50; // [sp+180h] [bp-2A8h]@70
  buf v51; // [sp+1A0h] [bp-288h]@70
  buf v52; // [sp+1C0h] [bp-268h]@3
  char v53; // [sp+1E0h] [bp-248h]@1
  char v54; // [sp+258h] [bp-1D0h]@1
  char v55; // [sp+300h] [bp-128h]@2

  input.start = 0LL;
  input.end = 0LL;
  input.ptr = 0LL;
  std::basic_ifstream<char,std::char_traits<char>>::basic_ifstream(&v53, "key.txt", 8LL);
  if ( !(unsigned __int8)std::__basic_file<char>::is_open(&v54) )
  {
    puts("key file not found, sorry ...\r");
    v6 = 2;
    goto LABEL_5;
  }
  if ( !(v55 & 7) )
  {
    std::istream::seekg(&v53, 0LL, 2LL);
    v8 = std::istream::tellg((std::istream *)&v53);
    v9 = input.end - input.start;
    if ( v8 <= input.end - input.start )
    {
      if ( v8 < input.end - input.start )
        input.end = v8 + input.start;
      goto LABEL_11;
    }
    v11 = v8 - v9;
    if ( v8 == v9 )
    {
LABEL_11:
      std::istream::seekg(&v53, 0LL, 0LL);
      std::istream::read((std::istream *)&v53, (char *)input.start, v8);
      goto LABEL_3;
    }
    if ( v11 <= input.ptr - input.end )
    {
      memset((void *)input.end, 0, v8 - v9);
      input.end += v11;
      goto LABEL_11;
    }
    if ( v11 > ~v9 )
    {
      v37 = std::__throw_length_error("vector::_M_default_append");
      if ( v40.start )
        operator delete((void *)v40.start);
      if ( v39.start )
        operator delete((void *)v39.start);
      std::basic_ifstream<char,std::char_traits<char>>::~basic_ifstream(&v53);
      if ( input.start )
        operator delete((void *)input.start);
      _Unwind_Resume(v37);
    }
    v12 = v8 - v9;
    if ( v9 >= v11 )
      v12 = input.end - input.start;
    v13 = __CFADD__(v12, v9);
    v14 = v12 + v9;
    if ( v13 )
    {
      v15 = -1LL;
    }
    else
    {
      v15 = 0LL;
      v16 = 0LL;
      if ( !v14 )
        goto LABEL_29;
      v15 = v14;
    }
    v16 = (void *)operator new(v15);
LABEL_29:
    v17 = input.end - input.start;
    if ( input.end == input.start )
    {
      memset(v16, 0, v11);
      v18 = (__int64)v16 + v11;
      if ( !input.start )
      {
LABEL_32:
        input.start = (__int64)v16;
        input.end = v18;
        input.ptr = (__int64)v16 + v15;
        goto LABEL_11;
      }
    }
    else
    {
      memmove(v16, (const void *)input.start, input.end - input.start);
      v24 = (char *)v16 + v17;
      v18 = (__int64)v16 + v17 + v11;
      memset(v24, 0, v11);
    }
    operator delete((void *)input.start);
    goto LABEL_32;
  }
LABEL_3:
  LOBYTE(v52.start) = 10;
  v3 = sub_401B30(input.start, (_BYTE *)input.end, (char *)&v52);
  buf_to_str(&input, v3, (char *)input.end);
  v4 = (char *)input.end;
  LOBYTE(v52.start) = 13;
  v5 = sub_401B30(input.start, (_BYTE *)input.end, (char *)&v52);
  buf_to_str(&input, v5, v4);
  if ( 97 * (input.end - input.start) != 2522 )
  {
LABEL_4:
    puts("Sorry, try harder!\r");
    v6 = 1;
    goto LABEL_5;
  }
  bufinit((__int64)&v39, (const void *)input.start, input.start + 4);
  bufinit((__int64)&v40, (const void *)(input.start + 5), input.start + 9);
  bufcpy((int *)&a2a, (__int64)&v40);
  bufcpy((int *)&a1a, (__int64)&v39);
  v10 = diff(&a1a, &a2a);
  if ( a1a.start )
    operator delete((void *)a1a.start);
  if ( a2a.start )
    operator delete((void *)a2a.start);
  if ( v10 != 0x17BF26 )
  {
LABEL_18:
    if ( v40.start )
      operator delete((void *)v40.start);
    if ( v39.start )
      operator delete((void *)v39.start);
    goto LABEL_4;
  }
  bufinit((__int64)&a1a, (const void *)(input.start + 9), input.start + 13);
  bufcpy((int *)&a2a, (__int64)&v39);
  v19 = (char *)a2a.start;
  if ( a2a.start != a2a.end )
  {
    for ( i = a2a.end - 1; i > (unsigned __int64)v19; *(_BYTE *)(i + 1) = v21 )
    {
      v21 = *v19;
      v22 = *(_BYTE *)i;
      ++v19;
      --i;
      *(v19 - 1) = v22;
    }
  }
  bufcpy((int *)&v44, (__int64)&a1a);
  bufcpy((int *)&v43, (__int64)&a2a);
  v23 = diff(&v43, &v44);
  if ( v43.start )
    operator delete((void *)v43.start);
  if ( v44.start )
    operator delete((void *)v44.start);
  if ( v23 != 0x27925A )
  {
LABEL_42:
    if ( a2a.start )
      operator delete((void *)a2a.start);
    if ( a1a.start )
      operator delete((void *)a1a.start);
    goto LABEL_18;
  }
  bufinit((__int64)&v44, (const void *)(input.start + 13), input.start + 17);
  v25 = (char *)v44.start;
  if ( v44.start != v44.end )
  {
    for ( j = v44.end - 1; j > (unsigned __int64)v25; *(_BYTE *)(j + 1) = v27 )
    {
      v27 = *v25;
      v28 = *(_BYTE *)j;
      ++v25;
      --j;
      *(v25 - 1) = v28;
    }
  }
  bufcpy((int *)&v46, (__int64)&v44);
  bufcpy((int *)&v45, (__int64)&v39);
  v29 = diff(&v45, &v46);
  if ( v45.start )
    operator delete((void *)v45.start);
  if ( v46.start )
    operator delete((void *)v46.start);
  if ( v29 != 517056 )
  {
LABEL_57:
    if ( v44.start )
      operator delete((void *)v44.start);
    goto LABEL_42;
  }
  bufinit((__int64)&v46, (const void *)(input.start + 17), input.start + 21);
  bufcpy((int *)&v48, (__int64)&v46);
  bufcpy((int *)&v47, (__int64)&v39);
  v30 = diff(&v47, &v48);
  if ( v47.start )
    operator delete((void *)v47.start);
  if ( v48.start )
    operator delete((void *)v48.start);
  if ( v30 != 174586 )
  {
LABEL_64:
    if ( v46.start )
      operator delete((void *)v46.start);
    goto LABEL_57;
  }
  v31 = (char *)v46.start;
  if ( v46.start != v46.end )
  {
    for ( k = v46.end - 1; k > (unsigned __int64)v31; *(_BYTE *)(k + 1) = v33 )
    {
      v33 = *v31;
      v34 = *(_BYTE *)k;
      ++v31;
      --k;
      *(v31 - 1) = v34;
    }
  }
  bufinit((__int64)&v48, (const void *)(input.start + 21), input.start + 25);
  bufcpy((int *)&v50, (__int64)&v48);
  bufcpy((int *)&v49, (__int64)&v39);
  v35 = diff(&v49, &v50);
  bufcpy((int *)&v52, (__int64)&v46);
  bufcpy((int *)&v51, (__int64)&v39);
  v36 = diff(&v51, &v52) / 5 - 3028;
  if ( v51.start )
    operator delete((void *)v51.start);
  if ( v52.start )
    operator delete((void *)v52.start);
  if ( v49.start )
    operator delete((void *)v49.start);
  if ( v50.start )
    operator delete((void *)v50.start);
  if ( v35 != v36 )
  {
    if ( v48.start )
      operator delete((void *)v48.start);
    goto LABEL_64;
  }
  puts("gj, you find the right flag :)\r");
  if ( v48.start )
    operator delete((void *)v48.start);
  if ( v46.start )
    operator delete((void *)v46.start);
  if ( v44.start )
    operator delete((void *)v44.start);
  if ( a2a.start )
    operator delete((void *)a2a.start);
  if ( a1a.start )
    operator delete((void *)a1a.start);
  if ( v40.start )
    operator delete((void *)v40.start);
  if ( v39.start )
    operator delete((void *)v39.start);
  v6 = 0;
LABEL_5:
  std::basic_ifstream<char,std::char_traits<char>>::~basic_ifstream(&v53);
  if ( input.start )
    operator delete((void *)input.start);
  return (unsigned int)v6;
}
