
/*
Copy elements at index of the given tape, to the location specified by dst_element_pt.

Our attention is focused on the tape, so we call this a 'read' operation.

*/
  
TM2x·index·read:{
  TM2x *tape                = TM2x·index·read·args.tape;              
  address_t index           = TM2x·index·read·args.index;         
  address_t element_n       = TM2x·index·read·args.element_byte_n;
  address_t element_byte_n  = TM2x·index·read·args.element_byte_n;
  void *dst_element_pt      = TM2x·index·read·args.dst_element_pt;    
  continuation nominal      = TM2x·index·read·args.nominal;
  continuation index_gt_n   = TM2x·index·read·args.index_gt_n;

  #include "inclusive·mul_ib·args.h"


    address_t byte_n;
    inclusive·mul_ib·args.an = element_n;
    inclusive·mul_ib·args.bn = element_byte_n;
    inclusive·mul_ib·args.cn = &byte_n;
    inclusive·mul_ib·args.nominal = &&mul_ib·nominal;
    inclusive·mul_ib·args.overflow = index_gt_n;
    #include "inclusive·mul_ib.h"
    continue_from inclusive·mul_ib;



  void *src_element_pt;
  #include "TM2x·index·to_pt·args.h"
  TM2x·index·to_pt·args.tape           = tape;
  TM2x·index·to_pt·args.index          = index;     
  TM2x·index·to_pt·args.element_byte_n = element_byte_n;
  TM2x·index·to_pt·args.pt             = &src_element_pt;              
  TM2x·index·to_pt·args.nominal        = &&index_nominal;        
  TM2x·index·to_pt·args.index_gt_n     = index_gt_n;
  #include "TM2x·index·to_pt.h"
  continue_from TM2x·index·to_pt;

  index_nominal:{


    mul_ib·nominal:{
      if( 

    }
    

    memcpyn(dst_element_pt, src_element_pt, element_byte_n);
    cend;
  }

  cend;
}
