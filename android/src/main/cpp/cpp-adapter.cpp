#include <jni.h>
#include "UnifileOnLoad.hpp"

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void*) {
  return margelo::nitro::unifile::initialize(vm);
}
