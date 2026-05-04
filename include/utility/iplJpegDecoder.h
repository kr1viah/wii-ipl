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
            int readStreamCallback(void*, u16*, u32);
            void makeRawData();
            int get_orientation();
            u32 get_resolution(int, int);
            void calc_capture_size(int, int);

            void clear();

        private:
            undefined4 unk_0x00;
            undefined4 unk_0x04;
            undefined4 unk_0x08;
            undefined4 unk_0x0c;
            undefined4 unk_0x10;
            undefined4 unk_0x14;
            undefined4 unk_0x18;
            undefined2 theWidth;   //?
            undefined2 theHeight;  //?
            Capture* unk_0x20;
            undefined4 unk_0x24;
            u8 buffer[0x6d4];
            OSSemaphore mSemaphore;
            undefined4 unk_0x708;
            undefined4 rotation;  //?
        };
    }  // namespace utility
}  // namespace ipl

#endif  // IPL_UTILITY_JPEG_DECODER
