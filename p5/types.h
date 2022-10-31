// typedef
typedef uint<8> PORT_ID_T;
typedef uint<8> INTF_ID_T;
typedef uint<32> IPV4_ADDR_T;
typedef uint<48> MAC_ADDR_T;
typedef uint<2> STATUS_T;// status (0,1,2,3): hit, miss, error, nolookup

typedef uint<9>  egressSpec_t;

// /* netcache header field types */
// typedef uint<NETCACHE_KEY_WIDTH> key_t;
// typedef uint<NETCACHE_VALUE_WIDTH_MAX> value_t;
// typedef uint<NETCACHE_VTABLE_SIZE_WIDTH> vtableIdx_t;
// typedef uint<NETCACHE_VTABLE_NUM> vtablebitmap_t;
// typedef uint<KEY_IDX_WIDTH> keyIdx_t;



// define
#define ETHERTYPE_IPV4 0x0800
#define IP_PROTOCOL_IPV4 4
#define IP_PROTOCOL_TCP 6
#define IP_PROTOCOL_UDP 17

#define UDP_HDR_LENGTH 8
#define IPV4_HDR_LENGTH 20
#define ETH_HDR_LENGTH 14

/* maximum number of bits of netcache fields */
#define NETCACHE_VALUE_WIDTH_MAX 64
#define NETCACHE_KEY_WIDTH 32


#define NUM_CACHE 65536
#define CACHE_IDX_WIDTH 16

const uint<16> NETCACHE_PORT = 50000;
// client(query)  src(50000)->dst switch
// client(reply) dst<-src(50000) switch 
// switch src(50000)->dst server(query)
// switch dst<-(50000)src server(reply)

/* current query supported types */
const uint<8> READ_QUERY = 0x00;
const uint<8> WRITE_QUERY = 0x01;
const uint<8> DELETE_QUERY = 0x02;
const uint<8> HOT_READ_QUERY= 0x03;
const uint<8> UPDATE_COMPLETE = 0x04;
const uint<8> DELETE_COMPLETE = 0x05;
const uint<8> CACHED_UPDATE = 0x06;
const uint<8> UPDATE_COMPLETE_OK = 0x07;