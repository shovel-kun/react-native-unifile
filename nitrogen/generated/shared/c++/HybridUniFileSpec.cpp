///
/// HybridUniFileSpec.cpp
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2025 Marc Rousavy @ Margelo
///

#include "HybridUniFileSpec.hpp"

namespace margelo::nitro::unifile {

  void HybridUniFileSpec::loadHybridMethods() {
    // load base methods/properties
    HybridObject::loadHybridMethods();
    // load custom methods/properties
    registerHybrids(this, [](Prototype& prototype) {
      prototype.registerHybridGetter("uri", &HybridUniFileSpec::getUri);
      prototype.registerHybridSetter("uri", &HybridUniFileSpec::setUri);
      prototype.registerHybridGetter("fileName", &HybridUniFileSpec::getFileName);
      prototype.registerHybridSetter("fileName", &HybridUniFileSpec::setFileName);
      prototype.registerHybridGetter("type", &HybridUniFileSpec::getType);
      prototype.registerHybridSetter("type", &HybridUniFileSpec::setType);
      prototype.registerHybridGetter("filePath", &HybridUniFileSpec::getFilePath);
      prototype.registerHybridSetter("filePath", &HybridUniFileSpec::setFilePath);
      prototype.registerHybridGetter("parentFile", &HybridUniFileSpec::getParentFile);
      prototype.registerHybridSetter("parentFile", &HybridUniFileSpec::setParentFile);
      prototype.registerHybridGetter("isDirectory", &HybridUniFileSpec::getIsDirectory);
      prototype.registerHybridSetter("isDirectory", &HybridUniFileSpec::setIsDirectory);
      prototype.registerHybridGetter("isFile", &HybridUniFileSpec::getIsFile);
      prototype.registerHybridSetter("isFile", &HybridUniFileSpec::setIsFile);
      prototype.registerHybridGetter("extension", &HybridUniFileSpec::getExtension);
      prototype.registerHybridSetter("extension", &HybridUniFileSpec::setExtension);
      prototype.registerHybridGetter("nameWithoutExtension", &HybridUniFileSpec::getNameWithoutExtension);
      prototype.registerHybridSetter("nameWithoutExtension", &HybridUniFileSpec::setNameWithoutExtension);
      prototype.registerHybridGetter("displayablePath", &HybridUniFileSpec::getDisplayablePath);
      prototype.registerHybridSetter("displayablePath", &HybridUniFileSpec::setDisplayablePath);
      prototype.registerHybridMethod("exists", &HybridUniFileSpec::exists);
      prototype.registerHybridMethod("findFile", &HybridUniFileSpec::findFile);
      prototype.registerHybridMethod("listFiles", &HybridUniFileSpec::listFiles);
      prototype.registerHybridMethod("deleteFile", &HybridUniFileSpec::deleteFile);
      prototype.registerHybridMethod("createDirectory", &HybridUniFileSpec::createDirectory);
      prototype.registerHybridMethod("createFile", &HybridUniFileSpec::createFile);
      prototype.registerHybridMethod("renameTo", &HybridUniFileSpec::renameTo);
      prototype.registerHybridMethod("lastModified", &HybridUniFileSpec::lastModified);
      prototype.registerHybridMethod("length", &HybridUniFileSpec::length);
      prototype.registerHybridMethod("canRead", &HybridUniFileSpec::canRead);
      prototype.registerHybridMethod("canWrite", &HybridUniFileSpec::canWrite);
    });
  }

} // namespace margelo::nitro::unifile
