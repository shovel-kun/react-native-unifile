import { NitroModules } from 'react-native-nitro-modules'
import type { UniFileFactory as UniFileFactorySpec } from './specs/unifilefactory.nitro'
import type { UniFile } from './specs/unifile.nitro'

const UniFileFactory =
  NitroModules.createHybridObject<UniFileFactorySpec>('UniFileFactory')

const fromUri = (uri: string) => UniFileFactory.fromUri(uri)

export { fromUri, type UniFile }
