package com.unifile

import androidx.annotation.Keep
import com.facebook.proguard.annotations.DoNotStrip
import com.margelo.nitro.unifile.HybridUniFileSpec
import com.hippo.unifile.UniFile
import com.margelo.nitro.core.Promise

@Keep
@DoNotStrip
class HybridUniFile(val unifile: UniFile): HybridUniFileSpec() {
    override var uri: String = unifile.uri.toString()
    override var fileName: String? = unifile.name
    override var filePath: String? = unifile.uri.toString()
    override var parentFile: HybridUniFileSpec? = unifile.parentFile?.let { HybridUniFile(it) }
    override var type: String? = unifile.type
    override var isDirectory: Boolean = unifile.isDirectory
    override var isFile: Boolean = unifile.isFile

    // qol extensions
    override var extension: String? = fileName?.substringAfterLast('.')
    override var nameWithoutExtension: String? = fileName?.substringBeforeLast('.')
    override var displayablePath: String = filePath ?: unifile.uri.toString()

    override fun exists(): Boolean = unifile.exists()

    override fun deleteFile(): Boolean = unifile.delete()

    override fun createFile(displayName: String): HybridUniFileSpec? {
        return unifile.createFile(displayName)?.let { HybridUniFile(it) }
    }

    override fun createDirectory(displayName: String): HybridUniFileSpec? {
        unifile.openOutputStream()
        return unifile.createDirectory(displayName)?.let { HybridUniFile(it) }
    }

    override fun renameTo(displayName: String): Boolean = unifile.renameTo(displayName)

    override fun lastModified(): String = unifile.lastModified().toString()

    override fun length(): String = unifile.length().toString()

    override fun canRead(): Boolean = unifile.canRead()

    override fun canWrite(): Boolean = unifile.canWrite()

    override fun findFile(path: String): HybridUniFileSpec? {
        return unifile.findFile(path).let { it?.let { HybridUniFile(it) } }
    }

    override fun listFiles(): Array<HybridUniFileSpec> {
        return unifile.listFiles()?.map { HybridUniFile(it) }?.toTypedArray() ?: arrayOf()
    }

    fun readAsString(): String? {
        return try {
            unifile.openInputStream().use { inputStream ->
                inputStream.bufferedReader().use { reader ->
                    reader.readText()
                }
            }
        } catch (e: Exception) {
            e.printStackTrace()
            null
        }
    }

    fun readAsStringAsync(): Promise<String?> {
        return try {
            Promise.async {
                unifile.openInputStream().use { inputStream ->
                    inputStream.bufferedReader().use { reader ->
                        reader.readText()
                    }
                }
            }
        } catch (e: Exception) {
            e.printStackTrace()
            Promise.rejected(e)
        }
    }

    //override fun listFiles(filter: FilenameFilter): Array<HybridUniFileSpec> {
    //    //unifile.listFiles(FilenameFilter { dir, name -> true })
    //    return unifile.listFiles(filter)?.map { HybridUniFile(it) }?.toTypedArray() ?: arrayOf()
    //}
}
