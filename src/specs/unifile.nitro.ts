import { type HybridObject } from 'react-native-nitro-modules'

export interface Unifile extends HybridObject<{ android: 'kotlin' }> {
  sum(num1: number, num2: number): number
}