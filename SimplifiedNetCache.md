# Simplified Netcache

Only Focus on data plane programming

## topology

1client(or more) -> netcache switch -> 1 server

## Netcache protocol

shortened key,value's width to 32/64 to satisfy archetecture

only focus on READ_QUERY, WRITE_QUERY, DELETE_QUERY

READ_QUERY:

            ingress              |      egress
    key ->      ->  set idx meta | -> packet.value = cache[meta.idx] -> ret_packet_to_sender
        |exist? |valid?          |
        ->      ->  no_action    | -> no_action(go through to server)

WRITE_QUERY:
    
    TODO

DELETE_QUERY:

            ingress              |      egress
    key ->      ->  set valid=0  | -> clear cache[meta.idx] -> go through to server
        |exist? |valid?          |
        ->      ->  no_action    | -> no_action(not cached, go through to server)

