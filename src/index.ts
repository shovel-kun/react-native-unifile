import { NitroModules } from 'react-native-nitro-modules'
import type { Unifile as UnifileSpec } from './specs/unifile.nitro'

export const Unifile =
  NitroModules.createHybridObject<UnifileSpec>('Unifile')