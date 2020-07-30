#ifndef INCLUSIVE_H
#define INCLUSIVE_H
/*
  Address interval inclusive bound versions of some C library functions.

  To make inclusive bounds really work we would need some new C library functions.
  In this sections I provide some mockups.  The implementations of these mockups
  might not respect inclusive bound math.


*/
#include <stdint.h>
#include <limits.h>
#include "Continuation.h"

  #define address_t uint64_t
  #define address_bit_length 64

  // address_t_n is the largest address that may be used to access a byte from memory.
  // If this array is implemented over virtual memory, that migth be the largest virtual memory
  //  address, i.e. UINT64_MAX.  That is what I have put here.
  #define address_t_n UINT64_MAX


  #define byte_n_of(type) sizeof(type)-1

  // the n+1 could gt_address_n:
  #define memcpyn(dst ,src ,n) memcpy(dst ,src ,n+1) 
  #define memcmpn(e0 ,e1 ,n) memcmp(e0 ,e1 ,n+1) 
  #define strncmpn(e0 ,e1 ,n) strncmp(e0 ,e1 ,n+1)
  #define str_octet_n(cstring) (strlen(cstring) - 1)

  typedef unsigned __int128 uint128_t;

  // inclusive bound multiply
  // Typically used to find the size in bytes of an array from the size of elements and the index of the last element.
  // c_n = (a_n + 1) * (b_n + 1) - 1
  // c_n = a_n * b_n + a_n + b_n;
  static inline continuation mul_ib(address_t an ,address_t bn ,address_t *cn ,continuation nominal ,continuation gt_address_n){
    uint128_t d_an = an, d_bn = bn, d_cn;
    d_cn = d_an * d_bn + d_an + d_bn;
    if( d_cn > address_t_n ) continue_via_trampoline gt_address_n;
    *cn = d_cn;
    continue_via_trampoline nominal;
  }

  static inline address_t binary_interval_inclusive_upper_bound(address_t byte_n){
    if( byte_n == 0 ) return 1;
    return (1 << (address_bit_length - __builtin_clz(byte_n))) - 1;
  }


#endif
