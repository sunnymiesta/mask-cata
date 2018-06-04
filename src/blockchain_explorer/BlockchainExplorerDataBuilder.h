#pragma once

#include <vector>
#include <array>

#include "ICryptoNoteProtocolQuery.h"
#include "ICore.h"
#include "BlockchainExplorerData.h"

namespace CryptoNote {

class BlockchainExplorerDataBuilder
{
public:
  BlockchainExplorerDataBuilder(CryptoNote::ICore& core, CryptoNote::ICryptoNoteProtocolQuery& protocol);

  BlockchainExplorerDataBuilder(const BlockchainExplorerDataBuilder&) = delete;
  BlockchainExplorerDataBuilder(BlockchainExplorerDataBuilder&&) = delete;

  BlockchainExplorerDataBuilder& operator=(const BlockchainExplorerDataBuilder&) = delete;
  BlockchainExplorerDataBuilder& operator=(BlockchainExplorerDataBuilder&&) = delete;

  bool fillBlockDetails(const Block& block, BlockDetails& blockDetails);
  bool fillTransactionDetails(const Transaction &tx, TransactionDetails& txRpcInfo, uint64_t timestamp = 0);

  static bool getPaymentId(const Transaction& transaction, Crypto::Hash& paymentId);

private:
  bool getMixin(const Transaction& transaction, uint64_t& mixin);
  bool fillTxExtra(const std::vector<uint8_t>& rawExtra, TransactionExtraDetails& extraDetails);
  size_t median(std::vector<size_t>& v);

  CryptoNote::ICore& core;
  CryptoNote::ICryptoNoteProtocolQuery& protocol;
};
}
