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
            theWidth = 0;
            theHeight = 0;
            memset(&buffer, 0, 0x6d4);
            if (unk_0x20 != 0) {
                delete this->unk_0x20;
                this->unk_0x20 = 0;
            }
            rotation = 0;
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

        BOOL JpegDecoder::waitCaptured() {
            OSWaitSemaphore(&mSemaphore);
            return unk_0x708 == 2;
        }

        int JpegDecoder::readStreamCallback(void* param_1, u16* param_2, u32 param_3) {
            memcpy(param_1, (void*)(unk_0x08 + this->unk_0x10), (u32)param_2);
            unk_0x10 = unk_0x10 + (int)param_2;
            return 0;
        }

        void JpegDecoder::calc_capture_size(int widthWithoutRotation, int heightWithoutRotation) {
            u32 uVar1;
            int width;
            u32 uVar4;
            int height;

            switch (rotation) {
                case 2:
                    width = heightWithoutRotation;
                    height = widthWithoutRotation;
                    break;
                case 1:
                    width = widthWithoutRotation;
                    height = heightWithoutRotation;
                    break;
                case 0:
                    width = heightWithoutRotation;
                    height = widthWithoutRotation;
                    break;
                default:
                    width = widthWithoutRotation;
                    height = heightWithoutRotation;
                    break;
            }
            if (width > 0x200) {
                uVar4 = (height << 9) / width;
                theWidth = 0x200;
                uVar1 = uVar4 & 0xffff;
                theHeight = uVar4;
                if (0x1c8 < uVar1) {
                    theHeight = 0x1c8;
                    theWidth = 0x39000 / uVar1;
                }
            } else {
                if (height > 0x1c8) {
                    theHeight = 0x1c8;
                    uVar4 = (width * 0x1c8) / height;
                    uVar1 = uVar4 & 0xffff;
                    theWidth = uVar4;
                    if (0x200 < uVar1) {
                        theWidth = 0x200;
                        theHeight = 0x39000 / uVar1;
                    }
                } else {
                    theWidth = width;
                    theHeight = height;
                }
            }
            theWidth = theWidth + 7 & 0xfff8;
            theHeight = theHeight + 7 & 0xfff8;
        }
    }  // namespace utility
}  // namespace ipl
