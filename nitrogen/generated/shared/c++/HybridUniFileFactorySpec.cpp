///
/// HybridUniFileFactorySpec.cpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

#include "HybridUniFileFactorySpec.hpp"

namespace margelo::nitro::unifile {

  void HybridUniFileFactorySpec::loadHybridMethods() {
    // load base methods/properties
    HybridObject::loadHybridMethods();
    // load custom methods/properties
    registerHybrids(this, [](Prototype& prototype) {
      prototype.registerHybridMethod("fromUri", &HybridUniFileFactorySpec::fromUri);
    });
  }

} // namespace margelo::nitro::unifile
