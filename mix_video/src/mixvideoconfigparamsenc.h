/*
 INTEL CONFIDENTIAL
 Copyright 2009 Intel Corporation All Rights Reserved.
 The source code contained or described herein and all documents related to the source code ("Material") are owned by Intel Corporation or its suppliers or licensors. Title to the Material remains with Intel Corporation or its suppliers and licensors. The Material contains trade secrets and proprietary and confidential information of Intel or its suppliers and licensors. The Material is protected by worldwide copyright and trade secret laws and treaty provisions. No part of the Material may be used, copied, reproduced, modified, published, uploaded, posted, transmitted, distributed, or disclosed in any way without Intel’s prior express written permission.

 No license under any patent, copyright, trade secret or other intellectual property right is granted to or conferred upon you by disclosure or delivery of the Materials, either expressly, by implication, inducement, estoppel or otherwise. Any license under such intellectual property rights must be express and approved by Intel in writing.
 */

#ifndef __MIX_VIDEOCONFIGPARAMSENC_H__
#define __MIX_VIDEOCONFIGPARAMSENC_H__

#include <mixvideoconfigparams.h>
#include "mixvideodef.h"

/**
 * MIX_TYPE_VIDEOCONFIGPARAMSENC:
 *
 * Get type of class.
 */
#define MIX_TYPE_VIDEOCONFIGPARAMSENC (mix_videoconfigparamsenc_get_type ())

/**
 * MIX_VIDEOCONFIGPARAMSENC:
 * @obj: object to be type-casted.
 */
#define MIX_VIDEOCONFIGPARAMSENC(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), MIX_TYPE_VIDEOCONFIGPARAMSENC, MixVideoConfigParamsEnc))

/**
 * MIX_IS_VIDEOCONFIGPARAMSENC:
 * @obj: an object.
 *
 * Checks if the given object is an instance of #MixParams
 */
#define MIX_IS_VIDEOCONFIGPARAMSENC(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), MIX_TYPE_VIDEOCONFIGPARAMSENC))

/**
 * MIX_VIDEOCONFIGPARAMSENC_CLASS:
 * @klass: class to be type-casted.
 */
#define MIX_VIDEOCONFIGPARAMSENC_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), MIX_TYPE_VIDEOCONFIGPARAMSENC, MixVideoConfigParamsEncClass))

/**
 * MIX_IS_VIDEOCONFIGPARAMSENC_CLASS:
 * @klass: a class.
 *
 * Checks if the given class is #MixParamsClass
 */
#define MIX_IS_VIDEOCONFIGPARAMSENC_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), MIX_TYPE_VIDEOCONFIGPARAMSENC))

/**
 * MIX_VIDEOCONFIGPARAMSENC_GET_CLASS:
 * @obj: a #MixParams object.
 *
 * Get the class instance of the object.
 */
#define MIX_VIDEOCONFIGPARAMSENC_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), MIX_TYPE_VIDEOCONFIGPARAMSENC, MixVideoConfigParamsEncClass))

typedef struct _MixVideoConfigParamsEnc MixVideoConfigParamsEnc;
typedef struct _MixVideoConfigParamsEncClass MixVideoConfigParamsEncClass;

/**
 * MixVideoConfigParamsEnc:
 *
 * MI-X VideoConfig Parameter object
 */
struct _MixVideoConfigParamsEnc {
	/*< public > */
	MixVideoConfigParams parent;

	/*< public > */
	//MixIOVec header;

	/* the type of the following members will be changed after MIX API doc is ready */

	/* Encoding profile */
	MixProfile profile;

	/* Raw format to be encoded */
	MixRawTargetFormat raw_format;

	/* Rate control mode */
	MixRateControl rate_control;  	

	/* Bitrate when rate control is used */
	guint bitrate;
	
	/* Numerator of frame rate */
	guint frame_rate_num;
	
	/* Denominator of frame rate */
	guint frame_rate_denom;
	
	/* The initial QP value */
	guint initial_qp;
	
	/* The minimum QP value */
	guint min_qp;
	
	/* Number of frames between key frames (GOP size) */
	guint intra_period;
	
	/* Width of video frame */
	guint16 picture_width;
	
	/* Height of the video frame */
	guint16 picture_height;	

	/* Mime type, reserved */
	GString * mime_type;
	
	/* Encode target format */
	MixEncodeTargetFormat encode_format;

	/* Size of the pool of MixBuffer objects */
	guint mixbuffer_pool_size;

	/* Are buffers shared between capture and encoding drivers */
	gboolean share_buf_mode;	

	/* Array of frame IDs created by capture library */
	gulong *	ci_frame_id;
	
	/* Size of the array ci_frame_id */
	guint	ci_frame_num;
	
	/* < private > */
	gulong draw;
	
	/*< public > */
	
	/* Indicates whether MixVideoFrames suitable for displaying 
	 * need to be enqueued for retrieval using mix_video_get_frame() */
	gboolean need_display;
	
	/* Reserved for future use */
	void *reserved1;
	
	/* Reserved for future use */	
	void *reserved2;
	
	/* Reserved for future use */	
	void *reserved3;
	
	/* Reserved for future use */	
	void *reserved4;
};

/**
 * MixVideoConfigParamsEncClass:
 *
 * MI-X VideoConfig object class
 */
struct _MixVideoConfigParamsEncClass {
	/*< public > */
	MixVideoConfigParamsClass parent_class;

	/* class members */
};

/**
 * mix_videoconfigparamsenc_get_type:
 * @returns: type
 *
 * Get the type of object.
 */
GType mix_videoconfigparamsenc_get_type(void);

/**
 * mix_videoconfigparamsenc_new:
 * @returns: A newly allocated instance of #MixVideoConfigParamsEnc
 *
 * Use this method to create new instance of #MixVideoConfigParamsEnc
 */
MixVideoConfigParamsEnc *mix_videoconfigparamsenc_new(void);
/**
 * mix_videoconfigparamsenc_ref:
 * @mix: object to add reference
 * @returns: the #MixVideoConfigParamsEnc instance where reference count has been increased.
 *
 * Add reference count.
 */
MixVideoConfigParamsEnc *mix_videoconfigparamsenc_ref(MixVideoConfigParamsEnc * mix);

/**
 * mix_videoconfigparamsenc_unref:
 * @obj: object to unref.
 *
 * Decrement reference count of the object.
 */
#define mix_videoconfigparamsenc_unref(obj) mix_params_unref(MIX_PARAMS(obj))

/* Class Methods */

/**
 * mix_videoconfigparamsenc_set_mime_type:
 * @obj: #MixVideoConfigParamsEnc object
 * @mime_type: Mime type
 * @returns: <link linkend="MixVideo-mixvideodef">Common Video Error Return Codes</link>
 *
 * Set mime type
 */
MIX_RESULT mix_videoconfigparamsenc_set_mime_type(MixVideoConfigParamsEnc * obj,
		const gchar * mime_type);

/**
 * mix_videoconfigparamsenc_get_mime_type:
 * @obj: #MixVideoConfigParamsEnc object
 * @mime_type: Mime type to be returned
 * @returns: <link linkend="MixVideo-mixvideodef">Common Video Error Return Codes</link>
 *
 * Get mime type
 * 
 * <note>
 * Caller is responsible to g_free *mime_type
 * </note> 
 */
MIX_RESULT mix_videoconfigparamsenc_get_mime_type(MixVideoConfigParamsEnc * obj,
		gchar ** mime_type);


/**
 * mix_videoconfigparamsenc_set_frame_rate:
 * @obj: #MixVideoConfigParamsEnc object
 * @frame_rate_num: Numerator of frame rate
 * @frame_rate_denom: Denominator of frame rate
 * @returns: <link linkend="MixVideo-mixvideodef">Common Video Error Return Codes</link>
 *
 * Set frame rate
 */
MIX_RESULT mix_videoconfigparamsenc_set_frame_rate(MixVideoConfigParamsEnc * obj,
		guint frame_rate_num, guint frame_rate_denom);

/**
 * mix_videoconfigparamsenc_get_frame_rate:
 * @obj: #MixVideoConfigParamsEnc object
 * @frame_rate_num: Numerator of frame rate to be returned
 * @frame_rate_denom: Denominator of frame rate to be returned
 * @returns: <link linkend="MixVideo-mixvideodef">Common Video Error Return Codes</link>
 *
 * Get frame rate
 */
MIX_RESULT mix_videoconfigparamsenc_get_frame_rate(MixVideoConfigParamsEnc * obj,
		guint * frame_rate_num, guint * frame_rate_denom);

/**
 * mix_videoconfigparamsenc_set_picture_res:
 * @obj: #MixVideoConfigParamsEnc object
 * @picture_width: Width of video frame
 * @picture_height: Height of the video frame
 * @returns: <link linkend="MixVideo-mixvideodef">Common Video Error Return Codes</link>
 *
 * Set width and height of video frame
 */
MIX_RESULT mix_videoconfigparamsenc_set_picture_res(MixVideoConfigParamsEnc * obj,
		guint picture_width, guint picture_height);

/**
 * mix_videoconfigparamsenc_get_picture_res:
 * @obj: #MixVideoConfigParamsEnc object
 * @picture_width: Width of video frame to be returned
 * @picture_height: Height of the video frame to be returned
 * @returns: <link linkend="MixVideo-mixvideodef">Common Video Error Return Codes</link>
 *
 * Get width and height of video frame
 */
MIX_RESULT mix_videoconfigparamsenc_get_picture_res(MixVideoConfigParamsEnc * obj,
		guint * picture_width, guint * picture_height);

/**
 * mix_videoconfigparamsenc_set_encode_format:
 * @obj: #MixVideoConfigParamsEnc object
 * @encode_format: Encode target format
 * @returns: <link linkend="MixVideo-mixvideodef">Common Video Error Return Codes</link>
 *
 * Set Encode target format
 */
MIX_RESULT mix_videoconfigparamsenc_set_encode_format (MixVideoConfigParamsEnc * obj,
		MixEncodeTargetFormat encode_format);

/**
 * mix_videoconfigparamsenc_get_encode_format:
 * @obj: #MixVideoConfigParamsEnc object
 * @encode_format: Encode target format to be returned
 * @returns: <link linkend="MixVideo-mixvideodef">Common Video Error Return Codes</link>
 *
 * Get Encode target format
 */
MIX_RESULT mix_videoconfigparamsenc_get_encode_format (MixVideoConfigParamsEnc * obj,
		MixEncodeTargetFormat * encode_format);

/**
 * mix_videoconfigparamsenc_set_bit_rate:
 * @obj: #MixVideoConfigParamsEnc object
 * @bps: bitrate
 * @returns: <link linkend="MixVideo-mixvideodef">Common Video Error Return Codes</link>
 *
 * Set bitrate
 */
MIX_RESULT mix_videoconfigparamsenc_set_bit_rate (MixVideoConfigParamsEnc * obj,
        guint bps);

/**
 * mix_videoconfigparamsenc_get_bit_rate:
 * @obj: #MixVideoConfigParamsEnc object
 * @bps: bitrate to be returned
 * @returns: <link linkend="MixVideo-mixvideodef">Common Video Error Return Codes</link>
 *
 * Get bitrate
 */
MIX_RESULT mix_videoconfigparamsenc_get_bit_rate (MixVideoConfigParamsEnc * obj,
        guint *bps);

/**
 * mix_videoconfigparamsenc_set_init_qp:
 * @obj: #MixVideoConfigParamsEnc object
 * @initial_qp: The initial QP value
 * @returns: <link linkend="MixVideo-mixvideodef">Common Video Error Return Codes</link>
 *
 * Set The initial QP value
 */
MIX_RESULT mix_videoconfigparamsenc_set_init_qp (MixVideoConfigParamsEnc * obj,
        guint initial_qp);

/**
 * mix_videoconfigparamsenc_get_init_qp:
 * @obj: #MixVideoConfigParamsEnc object
 * @initial_qp: The initial QP value to be returned
 * @returns: <link linkend="MixVideo-mixvideodef">Common Video Error Return Codes</link>
 *
 * Get The initial QP value
 */
MIX_RESULT mix_videoconfigparamsenc_get_init_qp (MixVideoConfigParamsEnc * obj,
        guint *initial_qp);

/**
 * mix_videoconfigparamsenc_set_min_qp:
 * @obj: #MixVideoConfigParamsEnc object
 * @min_qp: The minimum QP value
 * @returns: <link linkend="MixVideo-mixvideodef">Common Video Error Return Codes</link>
 *
 * Set The minimum QP value
 */
MIX_RESULT mix_videoconfigparamsenc_set_min_qp (MixVideoConfigParamsEnc * obj,
        guint min_qp);

/**
 * mix_videoconfigparamsenc_get_min_qp:
 * @obj: #MixVideoConfigParamsEnc object
 * @min_qp: The minimum QP value to be returned
 * @returns: <link linkend="MixVideo-mixvideodef">Common Video Error Return Codes</link>
 *
 * Get The minimum QP value
 */
MIX_RESULT mix_videoconfigparamsenc_get_min_qp(MixVideoConfigParamsEnc * obj,
        guint *min_qp);

/**
 * mix_videoconfigparamsenc_set_intra_period:
 * @obj: #MixVideoConfigParamsEnc object
 * @intra_period: Number of frames between key frames (GOP size)
 * @returns: <link linkend="MixVideo-mixvideodef">Common Video Error Return Codes</link>
 *
 * Set Number of frames between key frames (GOP size)
 */
MIX_RESULT mix_videoconfigparamsenc_set_intra_period (MixVideoConfigParamsEnc * obj,
        guint intra_period);

/**
 * mix_videoconfigparamsenc_get_intra_period:
 * @obj: #MixVideoConfigParamsEnc object
 * @intra_period: Number of frames between key frames (GOP size) to be returned
 * @returns: <link linkend="MixVideo-mixvideodef">Common Video Error Return Codes</link>
 *
 * Get Number of frames between key frames (GOP size)
 */
MIX_RESULT mix_videoconfigparamsenc_get_intra_period (MixVideoConfigParamsEnc * obj,
        guint *intra_period);

/**
 * mix_videoconfigparamsenc_set_buffer_pool_size:
 * @obj: #MixVideoConfigParamsEnc object
 * @bufpoolsize: Size of the pool of #MixBuffer objects
 * @returns: <link linkend="MixVideo-mixvideodef">Common Video Error Return Codes</link>
 *
 * Set Size of the pool of #MixBuffer objects
 */
MIX_RESULT mix_videoconfigparamsenc_set_buffer_pool_size(MixVideoConfigParamsEnc * obj,
		guint bufpoolsize);

/**
 * mix_videoconfigparamsenc_set_buffer_pool_size:
 * @obj: #MixVideoConfigParamsEnc object
 * @bufpoolsize: Size of the pool of #MixBuffer objects to be returned
 * @returns: <link linkend="MixVideo-mixvideodef">Common Video Error Return Codes</link>
 *
 * Get Size of the pool of #MixBuffer objects
 */
MIX_RESULT mix_videoconfigparamsenc_get_buffer_pool_size(MixVideoConfigParamsEnc * obj,
		guint *bufpoolsize);

/**
 * mix_videoconfigparamsenc_set_share_buf_mode:
 * @obj: #MixVideoConfigParamsEnc object
 * @share_buf_mod: A flag to indicate whether buffers are shared 
 *                 between capture and encoding drivers or not
 * @returns: <link linkend="MixVideo-mixvideodef">Common Video Error Return Codes</link>
 *
 * Set the flag that indicates whether buffers are shared between capture and encoding drivers or not
 */
MIX_RESULT mix_videoconfigparamsenc_set_share_buf_mode (MixVideoConfigParamsEnc * obj,
		gboolean share_buf_mod);

/**
 * mix_videoconfigparamsenc_get_share_buf_mode:
 * @obj: #MixVideoConfigParamsEnc object
 * @share_buf_mod: the flag to be returned that indicates whether buffers 
 *                 are shared between capture and encoding drivers or not
 * @returns: <link linkend="MixVideo-mixvideodef">Common Video Error Return Codes</link>
 *
 * Get the flag that indicates whether buffers are shared between capture and encoding drivers or not
 */
MIX_RESULT mix_videoconfigparamsenc_get_share_buf_mode(MixVideoConfigParamsEnc * obj,
		gboolean *share_buf_mod);

/**
 * mix_videoconfigparamsenc_set_ci_frame_info:
 * @obj: #MixVideoConfigParamsEnc object
 * @ci_frame_id: Array of frame IDs created by capture library * 
 * @ci_frame_num: Size of the array ci_frame_id 
 * @returns: <link linkend="MixVideo-mixvideodef">Common Video Error Return Codes</link>
 *
 * Set CI frame information
 */
MIX_RESULT mix_videoconfigparamsenc_set_ci_frame_info(MixVideoConfigParamsEnc * obj, 
		gulong *	ci_frame_id, guint  ci_frame_num);

/**
 * mix_videoconfigparamsenc_get_ci_frame_info:
 * @obj: #MixVideoConfigParamsEnc object
 * @ci_frame_id: Array of frame IDs created by capture library to be returned 
 * @ci_frame_num: Size of the array ci_frame_id to be returned
 * @returns: <link linkend="MixVideo-mixvideodef">Common Video Error Return Codes</link>
 *
 * Get CI frame information
 * <note>
 * Caller is responsible to g_free *ci_frame_id
 * </note> 
 */
MIX_RESULT mix_videoconfigparamsenc_get_ci_frame_info (MixVideoConfigParamsEnc * obj,
		gulong * *ci_frame_id, guint *ci_frame_num);


/**
 * mix_videoconfigparamsenc_set_drawable:
 * @obj: #MixVideoConfigParamsEnc object
 * @draw: drawable 
 * @returns: <link linkend="MixVideo-mixvideodef">Common Video Error Return Codes</link>
 *
 * Set drawable
 */
MIX_RESULT mix_videoconfigparamsenc_set_drawable (MixVideoConfigParamsEnc * obj, 
		gulong draw);

/**
 * mix_videoconfigparamsenc_get_drawable:
 * @obj: #MixVideoConfigParamsEnc object
 * @draw: drawable to be returned 
 * @returns: <link linkend="MixVideo-mixvideodef">Common Video Error Return Codes</link>
 *
 * Get drawable
 */
MIX_RESULT mix_videoconfigparamsenc_get_drawable (MixVideoConfigParamsEnc * obj,
        gulong *draw);

/**
 * mix_videoconfigparamsenc_set_need_display:
 * @obj: #MixVideoConfigParamsEnc object
 * @need_display: Flag to indicates whether MixVideoFrames suitable for displaying 
 *                need to be enqueued for retrieval using mix_video_get_frame()
 * @returns: <link linkend="MixVideo-mixvideodef">Common Video Error Return Codes</link>
 *
 * Set the flag used to indicate whether MixVideoFrames suitable for displaying 
 * need to be enqueued for retrieval using mix_video_get_frame()
 */
MIX_RESULT mix_videoconfigparamsenc_set_need_display (
        MixVideoConfigParamsEnc * obj, gboolean need_display);


/**
 * mix_videoconfigparamsenc_get_need_display:
 * @obj: #MixVideoConfigParamsEnc object
 * @need_display: A flag to be returned to indicates whether MixVideoFrames suitable for displaying 
 *                need to be enqueued for retrieval using mix_video_get_frame()
 * @returns: <link linkend="MixVideo-mixvideodef">Common Video Error Return Codes</link>
 *
 * Get the flag used to indicate whether MixVideoFrames suitable for displaying 
 * need to be enqueued for retrieval using mix_video_get_frame()
 */
MIX_RESULT mix_videoconfigparamsenc_get_need_display(MixVideoConfigParamsEnc * obj,
		gboolean *need_display);

/**
 * mix_videoconfigparamsenc_set_rate_control:
 * @obj: #MixVideoConfigParamsEnc object
 * @rcmode: Rate control mode  
 * @returns: <link linkend="MixVideo-mixvideodef">Common Video Error Return Codes</link>
 *
 * Set Rate control mode 
 */
MIX_RESULT mix_videoconfigparamsenc_set_rate_control(MixVideoConfigParamsEnc * obj,
		MixRateControl rcmode);

/**
 * mix_videoconfigparamsenc_set_rate_control:
 * @obj: #MixVideoConfigParamsEnc object
 * @rcmode: Rate control mode to be returned  
 * @returns: <link linkend="MixVideo-mixvideodef">Common Video Error Return Codes</link>
 *
 * Get Rate control mode 
 */
MIX_RESULT mix_videoconfigparamsenc_get_rate_control(MixVideoConfigParamsEnc * obj,
		MixRateControl * rcmode);

/**
 * mix_videoconfigparamsenc_set_raw_format:
 * @obj: #MixVideoConfigParamsEnc object
 * @raw_format: Raw format to be encoded  
 * @returns: <link linkend="MixVideo-mixvideodef">Common Video Error Return Codes</link>
 *
 * Set Raw format to be encoded 
 */
MIX_RESULT mix_videoconfigparamsenc_set_raw_format (MixVideoConfigParamsEnc * obj,
		MixRawTargetFormat raw_format);

/**
 * mix_videoconfigparamsenc_get_raw_format:
 * @obj: #MixVideoConfigParamsEnc object
 * @raw_format: Raw format to be returned  
 * @returns: <link linkend="MixVideo-mixvideodef">Common Video Error Return Codes</link>
 *
 * Get Raw format 
 */
MIX_RESULT mix_videoconfigparamsenc_get_raw_format (MixVideoConfigParamsEnc * obj,
		MixRawTargetFormat * raw_format);

/**
 * mix_videoconfigparamsenc_set_profile:
 * @obj: #MixVideoConfigParamsEnc object
 * @profile: Encoding profile  
 * @returns: <link linkend="MixVideo-mixvideodef">Common Video Error Return Codes</link>
 *
 * Set Encoding profile 
 */
MIX_RESULT mix_videoconfigparamsenc_set_profile (MixVideoConfigParamsEnc * obj,
		MixProfile profile);

/**
 * mix_videoconfigparamsenc_get_profile:
 * @obj: #MixVideoConfigParamsEnc object
 * @profile: Encoding profile to be returned  
 * @returns: <link linkend="MixVideo-mixvideodef">Common Video Error Return Codes</link>
 *
 * Get Encoding profile 
 */
MIX_RESULT mix_videoconfigparamsenc_get_profile (MixVideoConfigParamsEnc * obj,
		MixProfile * profile);

/* TODO: Add getters and setters for other properties */

#endif /* __MIX_VIDEOCONFIGPARAMSENC_H__ */

