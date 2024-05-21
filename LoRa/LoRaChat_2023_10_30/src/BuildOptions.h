#ifndef _LORAMESHER_BUILD_OPTIONS_H
#define _LORAMESHER_BUILD_OPTIONS_H

static const char* LM_TAG = "LoRaMesher";

// Set LoRa pins
#ifndef LORA_CS
#define LORA_CS 8
#endif

#ifndef LORA_IRQ
#define LORA_IRQ 14
#endif

#ifndef LORA_RST
#define LORA_RST 12
#endif

#ifndef LORA_IO1
#define LORA_IO1 13
#endif

// LoRa band definition
// 433E6 for Asia
// 866E6 for Europe
// 915E6 for North America
#define LM_BAND 869.900F
#define LM_BANDWIDTH 125.0
#define LM_LORASF 9U
#define LM_CODING_RATE 7U
#define LM_PREAMBLE_LENGTH 8U
#define LM_POWER 2
#define LM_DUTY_CYCLE 100

//Syncronization Word that identifies the mesh network
#define LM_SYNC_WORD 19U

// Comment this line if you want to remove the crc for each packet
#define LM_ADDCRC_PAYLOAD

// Routing table max size
#define RTMAXSIZE 256

//MAX packet size per packet
//If exceed it will be automatically separated through multiple packets 
//In bytes (226 bytes [UE max allowed with SF7 and 125khz])
//MAX payload size for hello packets = MAXPACKETSIZE - 6 bytes of header
//MAX payload size for data packets = MAXPACKETSIZE - 6 bytes of header - 2 bytes of via
//MAX payload size for reliable and large packets = MAXPACKETSIZE - 6 bytes of header - 2 bytes of via - 3 of control packet
#define MAXPACKETSIZE 100

// Packet types
#define NEED_ACK_P 0b00000011
#define DATA_P     0b00000010
#define HELLO_P    0b00000100
#define ACK_P      0b00001010
#define XL_DATA_P  0b00010010
#define LOST_P     0b00100010
#define SYNC_P     0b01000010

// Packet configuration
#define BROADCAST_ADDR 0xFFFF
#define DEFAULT_PRIORITY 20
#define MAX_PRIORITY 40

//Definition Times in seconds
#define HELLO_PACKETS_DELAY 30  // FF was: 120
#define DEFAULT_TIMEOUT HELLO_PACKETS_DELAY*5
#define MIN_TIMEOUT 20

//Maximum times that a sequence of packets reach the timeout
#define MAX_TIMEOUTS 10
#define MAX_RESEND_PACKET 3
#define MAX_TRY_BEFORE_SEND 5

//Role Types
#define ROLE_DEFAULT 0b00000000
#define ROLE_GATEWAY 0b00000001
//Free Role Types from 0b00000010 to 0b10000000

// Define if is testing
#define TESTING

#endif