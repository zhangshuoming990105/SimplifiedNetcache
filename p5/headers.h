#include "types.h"

struct ETHER_S {
  MAC_ADDR_T dstMac;
  MAC_ADDR_T srcMac;
  uint<16> etherType;
};

struct IPV4_S {
  uint<4> version;
  uint<4> ihl;
  uint<8> tos;
  uint<16> total_len;
  uint<16> identification;
  uint<3> flags;
  uint<13> frgOffset;
  uint<8> ttl;
  uint<8> protocol;
  uint<16> hdrChecksum;
  IPV4_ADDR_T srcAddr;
  IPV4_ADDR_T dstAddr;
};

struct UDP_S {
  uint<16> srcPort;
  uint<16> dstPort;
  uint<16> hdrLength;
  uint<16> checksum;
};

struct TCP_S {
  uint<16> srcPort;
  uint<16> dstPort;
  uint<32> seqNo;
  uint<32> ackNo;
  uint<4> dataOffset;
  uint<6> res;
  uint<6> flags;
  uint<16> window;
  uint<16> checksum;
  uint<16> urgentPtr;
};

struct NETCACHE_S {
  uint<8> op;
  uint<32> seq;
  uint<NETCACHE_KEY_WIDTH> key;
  uint<NETCACHE_VALUE_WIDTH_MAX> value;
};

struct METADATA_S {
  vtableBitmap_t vt_bitmap;
  vtableIdx_t vt_idx;

  uint<BLOOM_IDX_WIDTH> bloom_idx1;
  uint<BLOOM_IDX_WIDTH> bloom_idx2;
  uint<BLOOM_IDX_WIDTH> bloom_idx3;

  uint<SKETCH_CELL_BIT_WIDTH> key_cnt;

  keyIdx_t key_idx;

  uint<1> hot_query;

  fwd_metadata_t fwd_metadata;
  uint<16> tcpLength;

  // newly added
  uint<1> cache_exist;
  uint<1> cache_valid;
  uint<CACHE_IDX_WIDTH> cache_idx;
};

// header must be instantiated
header ETHER_S Ethernet;
header IPV4_S IPv4;
header UDP_S UDP;
header TCP_S TCP;
header NETCACHE_S NETCACHE;
METADATA_S meta;
