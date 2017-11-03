/********************************************
; File: ProDOS.h
;
;
; Copyright Apple Computer, Inc.1986-90
; All Rights Reserved
;
********************************************/
#ifndef __TYPES__
#include <TYPES.h>
#endif

#ifndef __PRODOS__
#define __PRODOS__

#ifdef __GSOS__ 
 
#undef GetSysPrefs       
#undef BeginSession      
#undef EndSession        
#undef SessionStatus     
#undef ResetCache        
#undef ChangePath        
#undef ClearBackupBit    
#undef Close             
#undef Create            
#undef DControl          
#undef Destroy           
#undef DInfo             
#undef DRead             
#undef DStatus           
#undef DWrite            
#undef EraseDisk         
#undef Flush             
#undef Format            
#undef GetBootVol        
#undef GetDevNumber      
#undef GetDirEntry       
#undef GetEOF            
#undef GetFileInfo       
#undef GetFSTInfo        
#undef GetLevel          
#undef GetMark           
#undef GetName           
#undef GetPrefix         
#undef GetVersion        
#undef Newline           
#undef Null              
#undef Open              
#undef Quit              
#undef Read              
#undef SetEOF            
#undef SetFileInfo       
#undef SetLevel          
#undef SetMark           
#undef SetPrefix         
#undef UnbindInt         
#undef Volume            
#undef Write             
#undef BindInt           
 
#undef ChangePathRec  
#undef CreateRec  
#undef DAccessRec  
#undef DevNumRec  
#undef DInfoRec  
#undef DIORec  
#undef DirEntryRec 
#undef EOFRec 
#undef FileInfoRec  
#undef FormatRec  
#undef FSTInfoRec  
#undef InterruptRec  
#undef IORec  
#undef LevelRec  
#undef NameRec
#undef GetNameRec  
#undef NewlineRec  
#undef OpenRec  
#undef PositionRec  
#undef PrefixRec  
#undef QuitRec  
#undef RefNumRec  
#undef SetPositionRec  
#undef SysPrefRec  
#undef VersionRec  
#undef VolumeRec  
 
#endif 




/* Error Codes */
#define invalidCallNum 0x0001  /* invalid call number */
#define unclaimedIntErr 0x01  /* fatal error - unclaimed interrupt */
#define badPBlockPtr 0x05  /* call pointer out of bounds */
#define pdosActiveErr 0x06  /* ProDOS is active */
#define pdosBusyErr 0x07  /* ProDOS is busy */
#define vcbUnusable 0x0A  /* fatal error - VCB unusable */
#define fcbUnusable 0x0B  /* fatal error - FCB unusable */
#define badBlockZero 0x0C  /* fatal error - block zero allocated illegally */
#define shdwInterruptErr 0x0D  /* fatal error - interrupt occured while I/O shadowing off */
#ifndef devNotFound  /* device not found */
#define devNotFound 0x10
#endif
#define badDevRefNum 0x11  /* invalid device reference number */
#define osVersionErr 0x11  /* Wrong OS version */
#define badReqCode 0x20  /* invalid request code */
#define intTableFull 0x25  /* interrupt table full */
#define invalidOperation 0x26  /* invalid operation */
#define ioError 0x27  /* I/O error */
#define noDevConnect 0x28  /* no device connected */
#define writeProtectErr 0x2B  /* write protect error */
#define diskSwitchErr 0x2E  /* disk switched error */
#define badPathname 0x40  /* invalid pathname syntax */
#define fcbFullErr 0x42  /* FCB full error */
#define badFileRefNum 0x43  /* invalid file reference number */
#ifndef pathNotFound  /* path not found */
#define pathNotFound 0x44
#endif
#define volumeNotFound 0x45  /* volume not found */
#ifndef fileNotFound  /* file not found */
#define fileNotFound 0x46
#endif
#define dupFileName 0x47  /* duplicate file name */
#define volumeFullErr 0x48  /* volume full error */
#define dirFullErr 0x49  /* directory full error */
#define versionErr 0x4A  /* version error (incompatible file format) */
#ifndef badStoreType  /* unsupported (or incorrect) storage type */
#define badStoreType 0x4B
#endif
#ifndef eofEncountered  /* end-of-file encountered */
#define eofEncountered 0x4C
#endif
#define positionRangeErr 0x4D  /* position out of range */
#define accessErr 0x4E  /* access not allowed */
#define fileOpenErr 0x50  /* file is open */
#define dirDamaged 0x51  /* directory structure is damaged */
#define badVolType 0x52  /* unsupported volume type */
#ifndef paramRangeErr  /* parameter out of range */
#define paramRangeErr 0x53
#endif
#define memoryFullErr 0x54  /* out of memory */
#define vcbFullErr 0x55  /* VCB full error */
#define dupVolumeErr 0x57  /* duplicate volume error */
#define notBlkDevErr 0x58  /* not a blocked device */
#ifndef invalidLevel  /* invalid level */
#define invalidLevel 0x59
#endif
#define blkNumRangeErr 0x5A  /* block number out of range */
#define notSameVolErr 0x5B  /* different volumes found on ChangePath call */
#define notExecSysFile 0x5C  /* not an executable system file */
#define osUnavailable 0x5D  /* Operating System/file system not available */
#define deallocateRamErr 0x5E  /* Cannot deallocate /RAM */
#ifndef stackOverflow  /* Return stack overflow */
#define stackOverflow 0x5F
#endif
#define dataUnavailable 0x60  /* Data unavailable */

/* Other Constants */
#define endofDirectory 0x0061
#define P_READ_ENABLE 0x01
#define P_WRITE_ENABLE 0x02
#define P_DESTROY_ENABLE 0x80
#define P_RENAME_ENABLE 0x40
struct BlockRec {
   Word blockDevNum; /*  */
   Ptr blockDataBuffer; /*  */
   Longint blockNum; /*  */
} ;
typedef struct BlockRec BlockRec, *BlockRecPtr;
struct DevNumRec {
   Ptr devName; /*  */
   Word devNum; /*  */
} ;
typedef struct DevNumRec DevNumRec, *DevNumRecPtr;
struct DInfoRec {
   Word devNum; /*  */
   Ptr devName; /*  */
} ;
typedef struct DInfoRec DInfoRec, *DInfoRecPtr;
struct DirEntryRec {
   Word refNum;
   Word flags;
   Word base;
   Word displacement;
   Pointer nameBuffer;
   Word entryNum;
   Word fileType;
   Longint endOfFile;
   LongWord blockCount;
   TimeRec createTime;
   TimeRec modTime;
   Word access;
   LongWord auxType;
   Word fileSysID;
} ;
typedef struct DirEntryRec DirEntryRec, *DirEntryRecPtr;
struct EOFRec {
   Word eofRefNum; /*  */
   Longint eofPosition; /*  */
} ;
typedef struct EOFRec EOFRec, *EOFRecPtr;
struct FileIORec {
   Word fileRefNum; /*  */
   Ptr dataBuffer; /*  */
   Longint requestCount; /*  */
   Longint transferCount; /*  */
} ;
typedef struct FileIORec FileIORec, *FileIORecPtr;
struct FileRec {
   Ptr pathname; /*  */
   Word fAccess; /*  */
   Word fileType; /*  */
   Longint auxType; /*  */
   Word storageType; /*  */
   Word createDate; /*  */
   Word createTime; /*  */
   Word modDate; /*  */
   Word modTime; /*  */
   Longint blocksUsed; /*  */
} ;
typedef struct FileRec FileRec, *FileRecPtr;
struct FormatRec {
   Ptr devName; /* device name pointer */
   Ptr volName; /* device name pointer */
   Word fileSysID; /* file system ID */
} ;
typedef struct FormatRec FormatRec, *FormatRecPtr;
struct EraseDiskRec {
   Ptr devName; /* device name pointer */
   Ptr volName; /* device name pointer */
   Word fileSysID; /* file system ID */
} ;
typedef struct EraseDiskRec EraseDiskRec, *EraseDiskRecPtr;
struct InterruptRec {
   Word intNum; /*  */
   Ptr intCode; /*  */
} ;
typedef struct InterruptRec InterruptRec, *InterruptRecPtr;
struct MarkRec {
   Word markRefNum; /*  */
   LongWord position; /*  */
} ;
typedef struct MarkRec MarkRec, *MarkRecPtr;
struct NewLineRec {
   Word newLRefNum; /*  */
   Word enableMask; /*  */
   Word newlineChar; /*  */
} ;
typedef struct NewLineRec NewLineRec, *NewLineRecPtr;
struct OpenRec {
   Word openRefNum; /*  */
   Ptr openPathname; /*  */
   Handle ioBuffer; /*  */
} ;
typedef struct OpenRec OpenRec, *OpenRecPtr;
struct PathNameRec {
   Ptr pathname; /*  */
   Ptr newPathname; /*  */
} ;
typedef struct PathNameRec PathNameRec, *PathNameRecPtr;
struct PrefixRec {
   Word prefixNum; /*  */
   Ptr prefix; /*  */
} ;
typedef struct PrefixRec PrefixRec, *PrefixRecPtr;
struct QuitRec {
   Ptr quitPathname; /*  */
   Word flags; /*  */
} ;
typedef struct QuitRec QuitRec, *QuitRecPtr;
struct VolumeRec {
   Ptr deviceName; /*  */
   Ptr volName; /*  */
   LongWord totalBlocks; /*  */
   LongWord freeBlocks; /*  */
   Word fileSysID; /*  */
} ;
typedef struct VolumeRec VolumeRec, *VolumeRecPtr;

#ifndef PDosInt
extern pascal void PDosInt(unsigned, void *);
#endif

#define ALLOC_INTERRUPT(pBlockPtr) PDosInt(0x0031,pBlockPtr)
#define CHANGE_PATH(pBlockPtr) PDosInt(0x0004,pBlockPtr)
#define CLEAR_BACKUP_BIT(pBlockPtr) PDosInt(0x000B,pBlockPtr)
#define CLOSE(pBlockPtr) PDosInt(0x0014,pBlockPtr)
#define CREATE(pBlockPtr) PDosInt(0x0001,pBlockPtr)
#define D_INFO(pBlockPtr) PDosInt(0x002C,pBlockPtr)
#define DEALLOC_INTERRUPT(pBlockPtr) PDosInt(0x0032,pBlockPtr)
#define DESTROY(pBlockPtr) PDosInt(0x0002,pBlockPtr)
#define ERASE_DISK(pBlockPtr) PDosInt(0x0025,pBlockPtr)
#define FLUSH(pBlockPtr) PDosInt(0x0015,pBlockPtr)
#define FORMAT(pBlockPtr) PDosInt(0x0024,pBlockPtr)
#define GET_BOOT_VOL(pBlockPtr) PDosInt(0x0028,pBlockPtr)
#define GET_DEV_NUM(pBlockPtr) PDosInt(0x0020,pBlockPtr)
#define GET_DIR_ENTRY(pBlockPtr) PDosInt(0x001C,pBlockPtr)
#define GET_EOF(pBlockPtr) PDosInt(0x0019,pBlockPtr)
#define GET_FILE_INFO(pBlockPtr) PDosInt(0x0006,pBlockPtr)
#define GET_LAST_DEV(pBlockPtr) PDosInt(0x0021,pBlockPtr)
#define GET_LEVEL(pBlockPtr) PDosInt(0x001B,pBlockPtr)
#define GET_MARK(pBlockPtr) PDosInt(0x0017,pBlockPtr)
#define GET_NAME(pBlockPtr) PDosInt(0x0027,pBlockPtr)
#define GET_PREFIX(pBlockPtr) PDosInt(0x000A,pBlockPtr)
#define GET_VERSION(pBlockPtr) PDosInt(0x002A,pBlockPtr)
#define NEWLINE(pBlockPtr) PDosInt(0x0011,pBlockPtr)
#define OPEN(pBlockPtr) PDosInt(0x0010,pBlockPtr)
#define QUIT(pBlockPtr) PDosInt(0x0029,pBlockPtr)
#define READ_BLOCK(pBlockPtr) PDosInt(0x0022,pBlockPtr)
#define READ(pBlockPtr) PDosInt(0x0012,pBlockPtr)
#define SET_EOF(pBlockPtr) PDosInt(0x0018,pBlockPtr)
#define SET_FILE_INFO(pBlockPtr) PDosInt(0x0005,pBlockPtr)
#define SET_LEVEL(pBlockPtr) PDosInt(0x001A,pBlockPtr)
#define SET_MARK(pBlockPtr) PDosInt(0x0016,pBlockPtr)
#define SET_PREFIX(pBlockPtr) PDosInt(0x0009,pBlockPtr)
#define VOLUME(pBlockPtr) PDosInt(0x0008,pBlockPtr)
#define WRITE_BLOCK(pBlockPtr) PDosInt(0x0023,pBlockPtr)
#define WRITE(pBlockPtr) PDosInt(0x0013,pBlockPtr)
#endif
