#pragma once

#include <string>

#include "core/Currency.h"

namespace CryptoNote {

bool validateAddress(const std::string& address, const CryptoNote::Currency& currency);

}
