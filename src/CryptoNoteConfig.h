#pragma once

#include <cstdint>
#include <initializer_list>
#include "contrib.hpp"

namespace CryptoNote {
namespace parameters {

const uint64_t DIFFICULTY_TARGET                             = 60; // seconds
const uint64_t CRYPTONOTE_MAX_BLOCK_NUMBER                   = 600000000;
const size_t   CRYPTONOTE_MAX_BLOCK_BLOB_SIZE                = 600000000;
const size_t   CRYPTONOTE_MAX_TX_SIZE                        = 1000000000;
const uint64_t CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX       = 0x60ca; // addresses start with "AU"
const size_t   CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW          = 10;
const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT            = DIFFICULTY_TARGET * 3;
const uint64_t CRYPTONOTE_DEFAULT_TX_SPENDABLE_AGE           = 10;

const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW             = 11;

const uint64_t MONEY_SUPPLY                                  = UINT64_C(25000000000);

//LWMA
const size_t   MIN_MIXIN                          	     = 0;
const uint8_t  MANDATORY_MIXIN_BLOCK_VERSION                 = 0;
const uint32_t MIXIN_START_HEIGHT                  	     = 0;
const uint32_t MANDATORY_TRANSACTION                         = 0;
const uint32_t KILL_HEIGHT                                   = 0;
const uint64_t TAIL_EMISSION_REWARD                          = 500;
const size_t   CRYPTONOTE_COIN_VERSION                       = 1;

const size_t   CRYPTONOTE_REWARD_BLOCKS_WINDOW               = 100;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE     = 1000000; //size of block (bytes) after which reward for block calculated using block size
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V2  = 1000000;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V1  = 100000;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_CURRENT = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE;
const size_t   CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE        = 600;
const size_t   CRYPTONOTE_DISPLAY_DECIMAL_POINT              = 4;

// COIN - number of smallest units in one coin
const uint64_t POINT                                         = UINT64_C(10000); // pow(10, 3)
const uint64_t COIN                                          = UINT64_C(100000000); // pow(10, 6)
const uint64_t MINIMUM_FEE                                   = UINT64_C(10000); // pow(10, 4)
const uint64_t DEFAULT_DUST_THRESHOLD                        = UINT64_C(10000); // pow(10, 4)
const unsigned EMISSION_SPEED_FACTOR 			     		 = 24;
static_assert(EMISSION_SPEED_FACTOR <= 8 * sizeof(uint64_t), "Bad EMISSION_SPEED_FACTOR");

const uint64_t EXPECTED_NUMBER_OF_BLOCKS_PER_DAY             = 24 * 60 * 60 / DIFFICULTY_TARGET;
const size_t   DIFFICULTY_WINDOW                             = 60; // blocks
const size_t   DIFFICULTY_WINDOW_V2                          = 150; // blocks

const uint64_t DEPOSIT_MIN_AMOUNT                            = 150 * COIN;
const uint32_t DEPOSIT_MIN_TERM                              = 22000; // ~1 month
const uint32_t DEPOSIT_MAX_TERM                              = 1 * 12 * 100000; // ~1 year
const uint64_t DEPOSIT_MIN_TOTAL_RATE_FACTOR                 = 0; // rate is constant
const uint64_t DEPOSIT_MAX_TOTAL_RATE                        = 20; // percentage rate for DEPOSIT_MAX_TERM
static_assert(DEPOSIT_MIN_TERM > 0, "Bad DEPOSIT_MIN_TERM");
static_assert(DEPOSIT_MIN_TERM <= DEPOSIT_MAX_TERM, "Bad DEPOSIT_MAX_TERM");
static_assert(DEPOSIT_MIN_TERM * DEPOSIT_MAX_TOTAL_RATE > DEPOSIT_MIN_TOTAL_RATE_FACTOR, "Bad DEPOSIT_MIN_TOTAL_RATE_FACTOR or DEPOSIT_MAX_TOTAL_RATE");

const uint64_t MULTIPLIER_FACTOR                             = 250000; // early depositor multiplier
const uint32_t END_MULTIPLIER_BLOCK                          = 3600; // block at which the multiplier ceases to be applied

const size_t   MAX_BLOCK_SIZE_INITIAL                        = 1000000;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR         = 100 * 1024;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_DENOMINATOR       = 365 * 24 * 60 * 60 / DIFFICULTY_TARGET;

const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS     = 1;
const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS    = DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS;

const size_t   CRYPTONOTE_MAX_TX_SIZE_LIMIT                  = (CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE / 4) - CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE;

const uint64_t CRYPTONOTE_MEMPOOL_TX_LIVETIME                = (60 * 60 * 14); // seconds, 14 hours
const uint64_t CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME = (60 * 60 * 24); // seconds, one day
const uint64_t CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL = 7; // CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL * CRYPTONOTE_MEMPOOL_TX_LIVETIME = time to forget tx

const size_t   FUSION_TX_MAX_SIZE                            = CRYPTONOTE_MAX_TX_SIZE_LIMIT * 2;
const size_t   FUSION_TX_MIN_INPUT_COUNT                     = 12;
const size_t   FUSION_TX_MIN_IN_OUT_COUNT_RATIO              = 4;

const uint32_t UPGRADE_HEIGHT_V2                             = 1;
const uint32_t UPGRADE_HEIGHT_V3                             = 2000000;
const unsigned UPGRADE_VOTING_THRESHOLD                      = 90; // percent
const uint32_t UPGRADE_VOTING_WINDOW                         = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY; // blocks
const uint32_t UPGRADE_WINDOW                                = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY; // blocks
static_assert(0 < UPGRADE_VOTING_THRESHOLD && UPGRADE_VOTING_THRESHOLD <= 100, "Bad UPGRADE_VOTING_THRESHOLD");
static_assert(UPGRADE_VOTING_WINDOW > 1, "Bad UPGRADE_VOTING_WINDOW");

const char     CRYPTONOTE_BLOCKS_FILENAME[]                  = "blocks.dat";
const char     CRYPTONOTE_BLOCKINDEXES_FILENAME[]            = "blockindexes.dat";
const char     CRYPTONOTE_BLOCKSCACHE_FILENAME[]             = "blockscache.dat";
const char     CRYPTONOTE_POOLDATA_FILENAME[]                = "poolstate.bin";
const char     P2P_NET_DATA_FILENAME[]                       = "p2pstate.bin";
const char     CRYPTONOTE_BLOCKCHAIN_INDICES_FILENAME[]      = "blockchainindices.dat";
const char     MINER_CONFIG_FILE_NAME[]                      = "miner_conf.json";

} // parameters

const uint64_t START_BLOCK_REWARD                            = (UINT64_C(1000) * parameters::POINT); //PoW reward
const uint64_t ICO_BLOCK_REWARD	                             = (UINT64_C(50) * parameters::COIN); // 20.4 billion ICO
const uint64_t MAX_BLOCK_REWARD                              = (UINT64_C(10) * parameters::COIN); //PoS reward
const uint64_t REWARD_INCREASE_INTERVAL                      = (UINT64_C(264000));

const char     CRYPTONOTE_NAME[]                             = "adina";
const char     GENESIS_COINBASE_TX_HEX[]                     = "010a01ff0001c0843d029b2e4c0281c0b02e7c53291a94d1d0cbff8883f8024f5142ee494ffbbd0880712101b31f8d1ab9e7456d87113ac066fbbd1b4b48a018c8aeef3d994ea0351d155559";
const uint32_t GENESIS_NONCE                                 = 70;
const uint64_t GENESIS_TIMESTAMP                             = 1528086815;

const uint8_t  TRANSACTION_VERSION_1                         = 1;
const uint8_t  TRANSACTION_VERSION_2                         = 2;
const uint8_t  BLOCK_MAJOR_VERSION_1                         = 1;
const uint8_t  BLOCK_MAJOR_VERSION_2                         = 2;
const uint8_t  BLOCK_MAJOR_VERSION_3                         = 3;
const uint8_t  BLOCK_MAJOR_VERSION_4                         = 4;
const uint8_t  BLOCK_MINOR_VERSION_0                         = 0;
const uint8_t  BLOCK_MINOR_VERSION_1                         = 1;

const size_t   BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT        = 10000; // by default, blocks ids count in synchronizing
const size_t   BLOCKS_SYNCHRONIZING_DEFAULT_COUNT            = 128; // by default, blocks count in blocks downloading
const size_t   COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT         = 1000;

const int      P2P_DEFAULT_PORT                              = 15715;
const int      RPC_DEFAULT_PORT                              = 15716;

const size_t   P2P_LOCAL_WHITE_PEERLIST_LIMIT                = 1000;
const size_t   P2P_LOCAL_GRAY_PEERLIST_LIMIT                 = 5000;

const size_t   P2P_CONNECTION_MAX_WRITE_BUFFER_SIZE          = 64 * 1024 * 1024; // 64 MB
const uint32_t P2P_DEFAULT_CONNECTIONS_COUNT                 = 8;
const size_t   P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT     = 70;
const uint32_t P2P_DEFAULT_HANDSHAKE_INTERVAL                = 60; // seconds
const uint32_t P2P_DEFAULT_PACKET_MAX_SIZE                   = 50000000; // 50000000 bytes maximum packet size
const uint32_t P2P_DEFAULT_PEERS_IN_HANDSHAKE                = 250;
const uint32_t P2P_DEFAULT_CONNECTION_TIMEOUT                = 5000; // 5 seconds
const uint32_t P2P_DEFAULT_PING_CONNECTION_TIMEOUT           = 2000; // 2 seconds
const uint64_t P2P_DEFAULT_INVOKE_TIMEOUT                    = 60 * 2 * 1000; // 2 minutes
const size_t   P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT          = 5000; // 5 seconds
const char     P2P_STAT_TRUSTED_PUB_KEY[]                    = "F29507CA78955F37A3B783EE2C5123B8B6A34A0C5CAAE050922C62541614G090";

const std::initializer_list<const char*> SEED_NODES = {
    "144.217.150.133:15715",
    "192.48.88.88:15715",
    "node1.adina.host:15715",
    "node2.adina.host:15715",
    "node3.adina.host:15715",
};

struct CheckpointData {
  uint32_t height;
  const char* blockId;
};

#ifdef __GNUC__
__attribute__((unused))
#endif

// You may add here other checkpoints using the following format:
// {<block height>, "<block hash>"},
const std::initializer_list<CheckpointData> CHECKPOINTS = {
  //{ 1, "1e844d0b4099634cc69fca8778c70926c21859947361a2c482c6824e6c72e8c2" },
  //{ 7, "723c48735906a804c2c7fa01f3282a1a9d06c5d004b870f136f920d6ddc5c8a6" }
};

} // CryptoNote

#define ALLOW_DEBUG_COMMANDS

