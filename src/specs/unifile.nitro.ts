import { type HybridObject } from 'react-native-nitro-modules'

export interface UniFile extends HybridObject<{ android: 'kotlin' }> {
  uri: string
  fileName?: string
  type?: string
  filePath?: string
  parentFile?: UniFile
  isDirectory: boolean
  isFile: boolean
  extension?: string
  nameWithoutExtension?: string
  displayablePath: string
  exists(): boolean
  findFile(path: string): UniFile | null
  listFiles(): UniFile[]
  deleteFile(): boolean
  createDirectory(displayName: string): UniFile | null
  createFile(displayName: string): UniFile | null
  renameTo(displayName: string): boolean
  lastModified(): string
  length(): string
  canRead(): boolean
  canWrite(): boolean
}

