# Packetizer

### Problem
To extract packetized raw data from a continuous data stream. For example a data stream from an exchange.

### Description
Imagine a continuous stream of data coming in through a socket or a connection in raw format. At every repeated intervals, it calls your function with whatever data it has available until that instant.

```
void onDataReceived(const char* buffer, unsigned int length);
```

Extract every packet (do not decode the packet itself) from this raw stream and pass it to the decoder's callback give below.

```
void decodeData(const char* buffer, unsinged int length);
```

Rules

* Each packet will be of different sizes.
* The protocol is bound by a key value pair. While every packet starts with the key of NAME, the end of packet is signaled by the key END, and its value will be the calculated checksum of that entire packet.

### Example
##### 1st Invocation
NAME=AAPL|BID=150|ASK=151|END=8989899|NAME=AMZN|BID=992|END=3289328|NAME=FB|TRADE=212|END=23892389|NAME=AAPL|TRADE=147.7|END=7879348|NAME=GOGL|ASK=861.3|END=7879898|NAME=AMZN

#### 2nd Invocation
|BID=951|TRADE=980|END=898923|NAM

##### 3rd Invocation
E=AAPL|BI

##### 4th Invocation
D=161|TRADE=141|VOLUME=898434|CAP=600B|END=89283981|NAME=FB|VOLUME=

#### Extracted Packets
NAME=AAPL|BID=150|ASK=151|END=8989899|<br />
NAME=AMZN|BID=992|END=3289328|<br />
NAME=FB|TRADE=212|END=23892389|<br />
NAME=AAPL|TRADE=147.7|END=7879348|<br />
NAME=GOGL|ASK=861.3|END=7879898|<br />
NAME=AMZN|BID=951|TRADE=980|END=898923|<br />
NAME=AAPL|BID=161|TRADE=141|VOLUME=898434|CAP=600B|END=89283981|<br />

<i>Remarks: It has several edge cases that needs to be thought of, which makes it a good question to guage a candidates' thinking and problem solving approach. This problem can be made simpler by specifying the end of packet using a delimiter (for example, 0xAF). </i>