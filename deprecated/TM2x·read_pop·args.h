
struct{
   TM2x·Tape *tape ;
   void *dst_element_pt ;
   address_t element_byte_n;
   continuation nominal;
   continuation pop_last;
   continuation alloc_fail;
} TM2x·read_pop;
