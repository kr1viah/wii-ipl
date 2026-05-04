#include "utility/iplJpegDecoder.h"
#include "utility/iplCapture.h"

namespace ipl {
    namespace utility {
        void JpegDecoder::clear() {
            unk_0x708 = 0;
            unk_0x24 = 0;
            unk_0x08 = 0;
            unk_0x0c = 0;
            unk_0x10 = 0;
            unk_0x14 = 0;
            unk_0x18 = 0;
            unk_0x1c = 0;
            unk_0x1e = 0;
            memset(&buffer, 0, 0x6d4);
            if (unk_0x20 != 0) {
                delete this->unk_0x20;
                this->unk_0x20 = 0;
            }
            unk_0x70c = 0;
        }

        JpegDecoder::JpegDecoder(EGG::Heap* heap) {
            unk_0x08 = 0;
            unk_0x0c = 0;
            unk_0x10 = 0;
            unk_0x20 = 0;
            unk_0x24 = 0;
            unk_0x708 = 0;
            unk_0x00 = (int)(operator new[](0x1c00, heap, 0x20));

            unk_0x04 = (int)(operator new[](0x10040, heap, 0x20));
            clear();
            OSInitSemaphore(&mSemaphore, 0);
        }
    }  // namespace utility
}  // namespace ipl
