#ifndef IPL_UTILITY_JPEG_DECODER
#define IPL_UTILITY_JPEG_DECODER

#include "utility/iplCapture.h"
#include <revolution/types.h>

#include <egg/core.h>

namespace ipl {
    namespace utility {
        class JpegDecoder {
        public:
            JpegDecoder(EGG::Heap* heap);

            BOOL decodeJpg(EGG::Heap* heap, u8* buffer, u32 length);
            BOOL encodeOdh(EGG::Heap* heap, u8* buffer, u32 length);

            BOOL waitCaptured();

            BOOL makeRawData();

            void clear();

        private:
            undefined4 unk_0x00;
            undefined4 unk_0x04;
            undefined4 unk_0x08;
            undefined4 unk_0x0c;
            undefined4 unk_0x10;
            undefined4 unk_0x14;
            undefined4 unk_0x18;
            undefined2 unk_0x1c;
            undefined2 unk_0x1e;
            Capture* unk_0x20;
            undefined4 unk_0x24;
            u8 buffer[0x6d4];
            OSSemaphore mSemaphore;
            undefined4 unk_0x708;
            undefined4 unk_0x70c;
        };
    }  // namespace utility
}  // namespace ipl

#endif  // IPL_UTILITY_JPEG_DECODER
