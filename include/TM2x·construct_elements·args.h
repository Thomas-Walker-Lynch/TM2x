
struct{
  TM2x *tape;
  address_t element_n;  // number of elements
  address_t element_byte_n; // index of last byte in element
  continuation nominal;
  continuation alloc_fail;
  continuation index_gt_n;
} TM2x·construct_bytes·args;
