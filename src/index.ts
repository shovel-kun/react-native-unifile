import { NitroModules } from 'react-native-nitro-modules'
import type { UniFileFactory as UniFileFactorySpec } from './specs/unifilefactory.nitro'

const UniFile =
  NitroModules.createHybridObject<UniFileFactorySpec>('UniFileFactory')

const fromUri = (uri: string) => UniFile.fromUri(uri)

export { fromUri }

