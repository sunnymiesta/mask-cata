#pragma once

#include "INode.h"
// #include "WalletSynchronizationContext.h"
#include "WalletSendTransactionContext.h"
#include "WalletLegacyEvent.h"

#include <boost/optional.hpp>

#include <deque>
#include <functional>
#include <memory>

namespace CryptoNote {

class WalletRequest
{
public:
  typedef std::function<void(std::deque<std::unique_ptr<WalletLegacyEvent>>&, std::unique_ptr<WalletRequest>&, std::error_code)> Callback;

  virtual ~WalletRequest() {};

  virtual void perform(INode& node, std::function<void (WalletRequest::Callback, std::error_code)> cb) = 0;
};

class WalletGetRandomOutsByAmountsRequest: public WalletRequest
{
public:
  WalletGetRandomOutsByAmountsRequest(const std::vector<uint64_t>& amounts, uint64_t outsCount, std::shared_ptr<SendTransactionContext> context, Callback cb) :
    m_amounts(amounts), m_outsCount(outsCount), m_context(context), m_cb(cb) {};

  virtual ~WalletGetRandomOutsByAmountsRequest() {};

  virtual void perform(INode& node, std::function<void (WalletRequest::Callback, std::error_code)> cb) override
  {
    node.getRandomOutsByAmounts(std::move(m_amounts), m_outsCount, std::ref(m_context->outs), std::bind(cb, m_cb, std::placeholders::_1));
  };

private:
  std::vector<uint64_t> m_amounts;
  uint64_t m_outsCount;
  std::shared_ptr<SendTransactionContext> m_context;
  Callback m_cb;
};

class WalletRelayTransactionRequest: public WalletRequest
{
public:
  WalletRelayTransactionRequest(const CryptoNote::Transaction& tx, Callback cb) : m_tx(tx), m_cb(cb) {};
  virtual ~WalletRelayTransactionRequest() {};

  virtual void perform(INode& node, std::function<void (WalletRequest::Callback, std::error_code)> cb) override
  {
    node.relayTransaction(m_tx, std::bind(cb, m_cb, std::placeholders::_1));
  }

private:
  CryptoNote::Transaction m_tx;
  Callback m_cb;
};

class WalletRelayDepositTransactionRequest final: public WalletRequest
{
public:
  WalletRelayDepositTransactionRequest(const Transaction& tx, Callback cb) : m_tx(tx), m_cb(cb) {}
  virtual ~WalletRelayDepositTransactionRequest() {}

  virtual void perform(INode& node, std::function<void (WalletRequest::Callback, std::error_code)> cb)
  {
    node.relayTransaction(m_tx, std::bind(cb, m_cb, std::placeholders::_1));
  }

private:
  Transaction m_tx;
  Callback m_cb;
};

} //namespace CryptoNote
