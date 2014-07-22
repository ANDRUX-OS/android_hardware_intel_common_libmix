/* INTEL CONFIDENTIAL
* Copyright (c) 2009-2011 Intel Corporation.  All rights reserved.
*
* The source code contained or described herein and all documents
* related to the source code ("Material") are owned by Intel
* Corporation or its suppliers or licensors.  Title to the
* Material remains with Intel Corporation or its suppliers and
* licensors.  The Material contains trade secrets and proprietary
* and confidential information of Intel or its suppliers and
* licensors. The Material is protected by worldwide copyright and
* trade secret laws and treaty provisions.  No part of the Material
* may be used, copied, reproduced, modified, published, uploaded,
* posted, transmitted, distributed, or disclosed in any way without
* Intel's prior express written permission.
*
* No license under any patent, copyright, trade secret or other
* intellectual property right is granted to or conferred upon you
* by disclosure or delivery of the Materials, either expressly, by
* implication, inducement, estoppel or otherwise. Any license
* under such intellectual property rights must be express and
* approved by Intel in writing.
*
*/

#include "VideoDecoderWMV.h"
#include "VideoDecoderMPEG4.h"
#include "VideoDecoderAVC.h"
#include "VideoDecoderPAVC.h"
#ifdef USE_INTEL_SECURE_AVC
#include "VideoDecoderAVCSecure.h"
#endif
#ifdef USE_HW_VP8
#include "VideoDecoderVP8.h"
#endif
#include "VideoDecoderHost.h"
#include "VideoDecoderTrace.h"
#include <string.h>

IVideoDecoder* createVideoDecoder(const char* mimeType) {
    if (mimeType == NULL) {
        ETRACE("NULL mime type.");
        return NULL;
    }

    if (strcasecmp(mimeType, "video/wmv") == 0 ||
        strcasecmp(mimeType, "video/vc1") == 0 ||
        strcasecmp(mimeType, "video/x-ms-wmv") == 0) {
        VideoDecoderWMV *p = new VideoDecoderWMV(mimeType);
        return (IVideoDecoder *)p;
    } else if (strcasecmp(mimeType, "video/avc") == 0 ||
               strcasecmp(mimeType, "video/h264") == 0) {
        VideoDecoderAVC *p = new VideoDecoderAVC(mimeType);
        return (IVideoDecoder *)p;
    } else if (strcasecmp(mimeType, "video/mp4v-es") == 0 ||
               strcasecmp(mimeType, "video/mpeg4") == 0 ||
               strcasecmp(mimeType, "video/h263") == 0 ||
               strcasecmp(mimeType, "video/3gpp") == 0) {
        VideoDecoderMPEG4 *p = new VideoDecoderMPEG4(mimeType);
        return (IVideoDecoder *)p;
    } else if (strcasecmp(mimeType, "video/pavc") == 0) {
        VideoDecoderAVC *p = new VideoDecoderPAVC(mimeType);
        return (IVideoDecoder *)p;
    }
#ifdef USE_INTEL_SECURE_AVC
    else if (strcasecmp(mimeType, "video/avc-secure") == 0) {
        VideoDecoderAVC *p = new VideoDecoderAVCSecure(mimeType);
        return (IVideoDecoder *)p;
    }
#endif
#ifdef USE_HW_VP8
    else if (strcasecmp(mimeType, "video/vp8") == 0 ||
        strcasecmp(mimeType, "video/x-vnd.on2.vp8") == 0) {
        VideoDecoderVP8 *p = new VideoDecoderVP8(mimeType);
        return (IVideoDecoder *)p;
    }
#endif
    else {
        ETRACE("Unknown mime type: %s", mimeType);
    }
    return NULL;
}

void releaseVideoDecoder(IVideoDecoder* p) {
    if (p) {
        const VideoFormatInfo *info  = p->getFormatInfo();
        if (info && info->mimeType) {
            ITRACE("Deleting decoder for %s", info->mimeType);
        }
    }
    delete p;
}


