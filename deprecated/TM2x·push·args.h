
struct{
  TM2x·Tape *tape;
  void *element_base_pt;
  address_t element_byte_n;
  continuation nominal;
  continuation alloc_fail;
} TM2x·push;
