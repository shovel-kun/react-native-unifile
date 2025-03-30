import { type HybridObject } from 'react-native-nitro-modules'
import { type UniFile } from './unifile.nitro'

export interface UniFileFactory extends HybridObject<{ android: 'kotlin' }> {
  fromUri(uri: string): UniFile | null
}
