#pragma once

#include "base/CryptoNoteBasic.h"
#include "core/Difficulty.h"

namespace CryptoNote {
  struct IMinerHandler {
    virtual bool handle_block_found(Block& b) = 0;
    virtual bool get_block_template(Block& b, const AccountPublicAddress& adr, difficulty_type& diffic, uint32_t& height, const BinaryArray& ex_nonce) = 0;

  protected:
    ~IMinerHandler(){};
  };
}
