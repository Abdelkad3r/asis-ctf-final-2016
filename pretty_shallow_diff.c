__int64 __fastcall diff(buf *a1, buf *a2)
{
  buf *v2; // r12@1
  buf *v3; // r13@1
  __int64 v4; // rdx@1
  __int64 v5; // rdx@1
  __int64 v6; // rdi@1
  __int64 v7; // rcx@1
  unsigned __int64 v8; // rax@1
  unsigned __int64 v9; // rbp@4
  signed int v10; // esi@5
  signed __int64 v11; // rdx@5
  unsigned __int64 v12; // rax@5
  __int64 result; // rax@8
  __int64 v14; // [sp+0h] [bp-B8h]@1
  char v15; // [sp+10h] [bp-A8h]@1
  char v16; // [sp+20h] [bp-98h]@1
  char v17; // [sp+30h] [bp-88h]@1
  _QWORD *v18; // [sp+38h] [bp-80h]@5
  char v19; // [sp+40h] [bp-78h]@1
  char v20; // [sp+50h] [bp-68h]@1
  char v21; // [sp+60h] [bp-58h]@1
  __int64 *v22; // [sp+68h] [bp-50h]@1
  char v23; // [sp+70h] [bp-48h]@1
  int v24; // [sp+74h] [bp-44h]@8
  __int64 *v25; // [sp+78h] [bp-40h]@8
  char v26; // [sp+80h] [bp-38h]@5

  v2 = a1;
  v3 = a2;
  __gmpz_init_set_si((__int64)&v23, 100LL);
  __gmpz_init_set_si((__int64)&v14, 10LL);
  __gmpz_init_set_si((__int64)&v15, 13LL);
  __gmpz_init_set_si((__int64)&v16, 9LL);
  __gmpz_init_set_si((__int64)&v17, 100LL);
  __gmpz_init_set_si((__int64)&v19, 125LL);
  __gmpz_init_set_si((__int64)&v20, 123LL);
  __gmpz_init_set_si((__int64)&v21, 0LL);
  __gmpz_sub((__int64)&v21, (__int64)&v15, (__int64)&v16);
  v4 = *v22;
  __gmpz_pow_ui((__int64)&v16, (__int64)&v14);
  __gmpz_sub((__int64)&v21, (__int64)&v19, (__int64)&v20);
  v5 = *v22;
  __gmpz_pow_ui((__int64)&v15, (__int64)&v17);
  __gmpz_sub((__int64)&v17, (__int64)&v16, (__int64)&v15);
  v6 = a2->start;
  v7 = v2->start;
  v8 = a2->end - a2->start;
  if ( v8 > v2->end - v2->start )
    v8 = v2->end - v2->start;
  if ( v8 )
  {
    v9 = 0LL;
    do
    {
      v10 = *(_BYTE *)(v7 + v9) - *(_BYTE *)(v6 + v9);
      __gmpz_init_set_si((__int64)&v26, ((v10 >> 31) ^ v10) - (v10 >> 31));
      v11 = *v18 + 1LL;
      ++v9;
      __gmpz_pow_ui((__int64)&v21, (__int64)&v26);
      __gmpz_add(&v23, &v23, &v21);
      __gmpz_add_ui(&v17, &v17, 1LL);
      v6 = v3->start;
      v7 = v2->start;
      v12 = v2->end - v2->start;
      if ( v12 > v3->end - v3->start )
        v12 = v3->end - v3->start;
    }
    while ( v9 < v12 );
  }
  result = *v25;
  if ( !v24 )
    result = 0LL;
  return result;
}
