/* 
 INTEL CONFIDENTIAL
 Copyright 2009 Intel Corporation All Rights Reserved. 
 The source code contained or described herein and all documents related to the source code ("Material") are owned by Intel Corporation or its suppliers or licensors. Title to the Material remains with Intel Corporation or its suppliers and licensors. The Material contains trade secrets and proprietary and confidential information of Intel or its suppliers and licensors. The Material is protected by worldwide copyright and trade secret laws and treaty provisions. No part of the Material may be used, copied, reproduced, modified, published, uploaded, posted, transmitted, distributed, or disclosed in any way without Intel’s prior express written permission.

 No license under any patent, copyright, trade secret or other intellectual property right is granted to or conferred upon you by disclosure or delivery of the Materials, either expressly, by implication, inducement, estoppel or otherwise. Any license under such intellectual property rights must be express and approved by Intel in writing.
*/

#ifndef __MIX_DRMPARAMS_H__
#define __MIX_DRMPARAMS_H__


#include "mixparams.h"

/**
 * MIX_DRMPARAMS:
 * @obj: object to be type-casted.
 */
#define MIX_DRMPARAMS(obj) (reinterpret_cast<MixDrmParams*>(obj))

/**
 * MIX_IS_DRMPARAMS:
 * @obj: an object.
 * 
 * Checks if the given object is an instance of #MixParams
 */
#define MIX_IS_DRMPARAMS(obj) (NULL != MIX_DRMPARAMS(obj))

/**
 * MixDrmParams:
 *
 * MI-X Drm Parameter object
 */
class MixDrmParams : public MixParams {
public:
  MixDrmParams();
  virtual ~MixDrmParams();
  virtual MixParams * dup () const;
};

/**
 * mix_drmparams_new:
 * @returns: A newly allocated instance of #MixDrmParams
 * 
 * Use this method to create new instance of #MixDrmParams
 */
MixDrmParams *mix_drmparams_new(void);

/**
 * mix_drmparams_ref:
 * @mix: object to add reference
 * @returns: the MixDrmParams instance where reference count has been increased.
 * 
 * Add reference count.
 */
MixDrmParams *mix_drmparams_ref(MixDrmParams *mix);

/**
 * mix_drmparams_unref:
 * @obj: object to unref.
 * 
 * Decrement reference count of the object.
 */
#define mix_drmparams_unref(obj) mix_params_unref(MIX_PARAMS(obj))

/* Class Methods */


#endif /* __MIX_DRMPARAMS_H__ */
