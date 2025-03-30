package com.unifile

import androidx.annotation.Keep
import androidx.core.net.toUri
import com.facebook.proguard.annotations.DoNotStrip
import com.hippo.unifile.UniFile
import com.margelo.nitro.unifile.HybridUniFileFactorySpec
import com.margelo.nitro.unifile.HybridUniFileSpec
import com.margelo.nitro.NitroModules

@Suppress("unused")
@Keep
@DoNotStrip
class HybridUniFileFactory : HybridUniFileFactorySpec() {
    override fun fromUri(uri: String): HybridUniFileSpec? {
        val file = UniFile.fromUri(NitroModules.applicationContext, uri.toUri())
        return file?.let { HybridUniFile(it) }
    }
}