#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <stdlib.h>
#include "misc.h"

typedef void **SQ·Ptr; 
#define SQ·Sequence __label__
#define SQ·continue(c) goto c;
#define SQ·def(c) goto SQ·##c;c:{
#define SQ·end(c) abort();} SQ·##c:;

// actual argument data
typedef struct {
} SQ·Args;

// pointers to places to put result data
typedef struct {
} SQ·Ress;

// connections
typedef struct {
} SQ·Lnks;

// a link to a sequence for indirect calls
typedef struct{
  SQ·Ptr sequence;
  SQ·Args *args;
  SQ·Ress *ress;
  SQ·Lnks *lnks;
} SQ·Lnk;

#define SQ·continue_indirect(lnk) \
  SQ·lnk  = (SQ·Lnk *)&(lnk);                \
  SQ·continue(*SQ·lnk->sequence);


#endif
