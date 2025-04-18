///
/// UnifileOnLoad.cpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

#ifndef BUILDING_UNIFILE_WITH_GENERATED_CMAKE_PROJECT
#error UnifileOnLoad.cpp is not being built with the autogenerated CMakeLists.txt project. Is a different CMakeLists.txt building this?
#endif

#include "UnifileOnLoad.hpp"

#include <jni.h>
#include <fbjni/fbjni.h>
#include <NitroModules/HybridObjectRegistry.hpp>

#include "JHybridUniFileSpec.hpp"
#include "JHybridUniFileFactorySpec.hpp"
#include <NitroModules/JNISharedPtr.hpp>
#include <NitroModules/DefaultConstructableObject.hpp>

namespace margelo::nitro::unifile {

int initialize(JavaVM* vm) {
  using namespace margelo::nitro;
  using namespace margelo::nitro::unifile;
  using namespace facebook;

  return facebook::jni::initialize(vm, [] {
    // Register native JNI methods
    margelo::nitro::unifile::JHybridUniFileSpec::registerNatives();
    margelo::nitro::unifile::JHybridUniFileFactorySpec::registerNatives();

    // Register Nitro Hybrid Objects
    HybridObjectRegistry::registerHybridObjectConstructor(
      "UniFile",
      []() -> std::shared_ptr<HybridObject> {
        static DefaultConstructableObject<JHybridUniFileSpec::javaobject> object("com/unifile/HybridUniFile");
        auto instance = object.create();
        auto globalRef = jni::make_global(instance);
        return JNISharedPtr::make_shared_from_jni<JHybridUniFileSpec>(globalRef);
      }
    );
    HybridObjectRegistry::registerHybridObjectConstructor(
      "UniFileFactory",
      []() -> std::shared_ptr<HybridObject> {
        static DefaultConstructableObject<JHybridUniFileFactorySpec::javaobject> object("com/unifile/HybridUniFileFactory");
        auto instance = object.create();
        auto globalRef = jni::make_global(instance);
        return JNISharedPtr::make_shared_from_jni<JHybridUniFileFactorySpec>(globalRef);
      }
    );
  });
}

} // namespace margelo::nitro::unifile
