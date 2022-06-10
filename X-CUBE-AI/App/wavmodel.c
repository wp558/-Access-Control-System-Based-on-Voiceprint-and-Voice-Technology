/**
  ******************************************************************************
  * @file    wavmodel.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Thu Sep 30 03:57:13 2021
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2018 STMicroelectronics.
  * All rights reserved.
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */


#include "wavmodel.h"

#include "ai_platform_interface.h"
#include "ai_math_helpers.h"

#include "core_common.h"
#include "layers.h"



#undef AI_TOOLS_VERSION_MAJOR
#undef AI_TOOLS_VERSION_MINOR
#undef AI_TOOLS_VERSION_MICRO
#define AI_TOOLS_VERSION_MAJOR 5
#define AI_TOOLS_VERSION_MINOR 2
#define AI_TOOLS_VERSION_MICRO 0


#undef AI_TOOLS_API_VERSION_MAJOR
#undef AI_TOOLS_API_VERSION_MINOR
#undef AI_TOOLS_API_VERSION_MICRO
#define AI_TOOLS_API_VERSION_MAJOR 1
#define AI_TOOLS_API_VERSION_MINOR 3
#define AI_TOOLS_API_VERSION_MICRO 0

#undef AI_NET_OBJ_INSTANCE
#define AI_NET_OBJ_INSTANCE g_wavmodel
 
#undef AI_WAVMODEL_MODEL_SIGNATURE
#define AI_WAVMODEL_MODEL_SIGNATURE     "d28ba9aa319591dcd2b987f477b7121a"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     "(rev-5.2.0)"
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Thu Sep 30 03:57:13 2021"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_WAVMODEL_N_BATCHES
#define AI_WAVMODEL_N_BATCHES         (1)

/**  Forward network declaration section  *************************************/
AI_STATIC ai_network AI_NET_OBJ_INSTANCE;


/**  Forward network array declarations  **************************************/
AI_STATIC ai_array conv2_scratch0_array;   /* Array #0 */
AI_STATIC ai_array conv1_scratch0_array;   /* Array #1 */
AI_STATIC ai_array FC2_bias_array;   /* Array #2 */
AI_STATIC ai_array FC2_weights_array;   /* Array #3 */
AI_STATIC ai_array FC1_bias_array;   /* Array #4 */
AI_STATIC ai_array FC1_weights_array;   /* Array #5 */
AI_STATIC ai_array conv2_bias_array;   /* Array #6 */
AI_STATIC ai_array conv2_weights_array;   /* Array #7 */
AI_STATIC ai_array conv1_bias_array;   /* Array #8 */
AI_STATIC ai_array conv1_weights_array;   /* Array #9 */
AI_STATIC ai_array input_0_output_array;   /* Array #10 */
AI_STATIC ai_array conv1_output_array;   /* Array #11 */
AI_STATIC ai_array conv2_output_array;   /* Array #12 */
AI_STATIC ai_array FC1_output_array;   /* Array #13 */
AI_STATIC ai_array FC1_nl_output_array;   /* Array #14 */
AI_STATIC ai_array FC2_output_array;   /* Array #15 */
AI_STATIC ai_array FC2_nl_output_array;   /* Array #16 */


/**  Forward network tensor declarations  *************************************/
AI_STATIC ai_tensor conv2_scratch0;   /* Tensor #0 */
AI_STATIC ai_tensor conv1_scratch0;   /* Tensor #1 */
AI_STATIC ai_tensor FC2_bias;   /* Tensor #2 */
AI_STATIC ai_tensor FC2_weights;   /* Tensor #3 */
AI_STATIC ai_tensor FC1_bias;   /* Tensor #4 */
AI_STATIC ai_tensor FC1_weights;   /* Tensor #5 */
AI_STATIC ai_tensor conv2_bias;   /* Tensor #6 */
AI_STATIC ai_tensor conv2_weights;   /* Tensor #7 */
AI_STATIC ai_tensor conv1_bias;   /* Tensor #8 */
AI_STATIC ai_tensor conv1_weights;   /* Tensor #9 */
AI_STATIC ai_tensor input_0_output;   /* Tensor #10 */
AI_STATIC ai_tensor conv1_output;   /* Tensor #11 */
AI_STATIC ai_tensor conv2_output;   /* Tensor #12 */
AI_STATIC ai_tensor conv2_output0;   /* Tensor #13 */
AI_STATIC ai_tensor FC1_output;   /* Tensor #14 */
AI_STATIC ai_tensor FC1_nl_output;   /* Tensor #15 */
AI_STATIC ai_tensor FC2_output;   /* Tensor #16 */
AI_STATIC ai_tensor FC2_nl_output;   /* Tensor #17 */


/**  Forward network tensor chain declarations  *******************************/
AI_STATIC_CONST ai_tensor_chain conv1_chain;   /* Chain #0 */
AI_STATIC_CONST ai_tensor_chain conv2_chain;   /* Chain #1 */
AI_STATIC_CONST ai_tensor_chain FC1_chain;   /* Chain #2 */
AI_STATIC_CONST ai_tensor_chain FC1_nl_chain;   /* Chain #3 */
AI_STATIC_CONST ai_tensor_chain FC2_chain;   /* Chain #4 */
AI_STATIC_CONST ai_tensor_chain FC2_nl_chain;   /* Chain #5 */


/**  Forward network layer declarations  **************************************/
AI_STATIC ai_layer_conv2d_nl_pool conv1_layer; /* Layer #0 */
AI_STATIC ai_layer_conv2d_nl_pool conv2_layer; /* Layer #1 */
AI_STATIC ai_layer_dense FC1_layer; /* Layer #2 */
AI_STATIC ai_layer_nl FC1_nl_layer; /* Layer #3 */
AI_STATIC ai_layer_dense FC2_layer; /* Layer #4 */
AI_STATIC ai_layer_nl FC2_nl_layer; /* Layer #5 */


/**  Array declarations section  **********************************************/
/* Array#0 */
AI_ARRAY_OBJ_DECLARE(
  conv2_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 5120, AI_STATIC)

/* Array#1 */
AI_ARRAY_OBJ_DECLARE(
  conv1_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2640, AI_STATIC)

/* Array#2 */
AI_ARRAY_OBJ_DECLARE(
  FC2_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3, AI_STATIC)

/* Array#3 */
AI_ARRAY_OBJ_DECLARE(
  FC2_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 384, AI_STATIC)

/* Array#4 */
AI_ARRAY_OBJ_DECLARE(
  FC1_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#5 */
AI_ARRAY_OBJ_DECLARE(
  FC1_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 819200, AI_STATIC)

/* Array#6 */
AI_ARRAY_OBJ_DECLARE(
  conv2_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#7 */
AI_ARRAY_OBJ_DECLARE(
  conv2_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2304, AI_STATIC)

/* Array#8 */
AI_ARRAY_OBJ_DECLARE(
  conv1_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8, AI_STATIC)

/* Array#9 */
AI_ARRAY_OBJ_DECLARE(
  conv1_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 72, AI_STATIC)

/* Array#10 */
AI_ARRAY_OBJ_DECLARE(
  input_0_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 4342, AI_STATIC)

/* Array#11 */
AI_ARRAY_OBJ_DECLARE(
  conv1_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 7872, AI_STATIC)

/* Array#12 */
AI_ARRAY_OBJ_DECLARE(
  conv2_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 6400, AI_STATIC)

/* Array#13 */
AI_ARRAY_OBJ_DECLARE(
  FC1_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#14 */
AI_ARRAY_OBJ_DECLARE(
  FC1_nl_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#15 */
AI_ARRAY_OBJ_DECLARE(
  FC2_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3, AI_STATIC)

/* Array#16 */
AI_ARRAY_OBJ_DECLARE(
  FC2_nl_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 3, AI_STATIC)

/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  conv2_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 80, 2), AI_STRIDE_INIT(4, 4, 4, 128, 10240),
  1, &conv2_scratch0_array, NULL)

/* Tensor #1 */
AI_TENSOR_OBJ_DECLARE(
  conv1_scratch0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 165, 2), AI_STRIDE_INIT(4, 4, 4, 32, 5280),
  1, &conv1_scratch0_array, NULL)

/* Tensor #2 */
AI_TENSOR_OBJ_DECLARE(
  FC2_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 1, 1), AI_STRIDE_INIT(4, 4, 4, 12, 12),
  1, &FC2_bias_array, NULL)

/* Tensor #3 */
AI_TENSOR_OBJ_DECLARE(
  FC2_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 128, 3, 1, 1), AI_STRIDE_INIT(4, 4, 512, 1536, 1536),
  1, &FC2_weights_array, NULL)

/* Tensor #4 */
AI_TENSOR_OBJ_DECLARE(
  FC1_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &FC1_bias_array, NULL)

/* Tensor #5 */
AI_TENSOR_OBJ_DECLARE(
  FC1_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 6400, 128, 1, 1), AI_STRIDE_INIT(4, 4, 25600, 3276800, 3276800),
  1, &FC1_weights_array, NULL)

/* Tensor #6 */
AI_TENSOR_OBJ_DECLARE(
  conv2_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2_bias_array, NULL)

/* Tensor #7 */
AI_TENSOR_OBJ_DECLARE(
  conv2_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 8, 3, 3, 32), AI_STRIDE_INIT(4, 4, 32, 96, 288),
  1, &conv2_weights_array, NULL)

/* Tensor #8 */
AI_TENSOR_OBJ_DECLARE(
  conv1_bias, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv1_bias_array, NULL)

/* Tensor #9 */
AI_TENSOR_OBJ_DECLARE(
  conv1_weights, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 8), AI_STRIDE_INIT(4, 4, 4, 12, 36),
  1, &conv1_weights_array, NULL)

/* Tensor #10 */
AI_TENSOR_OBJ_DECLARE(
  input_0_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 167, 26), AI_STRIDE_INIT(4, 4, 4, 4, 668),
  1, &input_0_output_array, NULL)

/* Tensor #11 */
AI_TENSOR_OBJ_DECLARE(
  conv1_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 82, 12), AI_STRIDE_INIT(4, 4, 4, 32, 2624),
  1, &conv1_output_array, NULL)

/* Tensor #12 */
AI_TENSOR_OBJ_DECLARE(
  conv2_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 40, 5), AI_STRIDE_INIT(4, 4, 4, 128, 5120),
  1, &conv2_output_array, NULL)

/* Tensor #13 */
AI_TENSOR_OBJ_DECLARE(
  conv2_output0, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 6400, 1, 1), AI_STRIDE_INIT(4, 4, 4, 25600, 25600),
  1, &conv2_output_array, NULL)

/* Tensor #14 */
AI_TENSOR_OBJ_DECLARE(
  FC1_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &FC1_output_array, NULL)

/* Tensor #15 */
AI_TENSOR_OBJ_DECLARE(
  FC1_nl_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &FC1_nl_output_array, NULL)

/* Tensor #16 */
AI_TENSOR_OBJ_DECLARE(
  FC2_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 1, 1), AI_STRIDE_INIT(4, 4, 4, 12, 12),
  1, &FC2_output_array, NULL)

/* Tensor #17 */
AI_TENSOR_OBJ_DECLARE(
  FC2_nl_output, AI_STATIC,
  0x0, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 1, 1), AI_STRIDE_INIT(4, 4, 4, 12, 12),
  1, &FC2_nl_output_array, NULL)



/**  Layer declarations section  **********************************************/


AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv1_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &input_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv1_weights, &conv1_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv1_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv1_layer, 0,
  OPTIMIZED_CONV2D_TYPE,
  conv2d_nl_pool, forward_conv2d_nl_pool,
  &AI_NET_OBJ_INSTANCE, &conv2_layer, AI_STATIC,
  .tensors = &conv1_chain, 
  .groups = 1, 
  .nl_func = nl_func_relu_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_size = AI_SHAPE_2D_INIT(2, 2), 
  .pool_stride = AI_SHAPE_2D_INIT(2, 2), 
  .pool_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_func = pool_func_mp_array_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2_weights, &conv2_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2_layer, 2,
  OPTIMIZED_CONV2D_TYPE,
  conv2d_nl_pool, forward_conv2d_nl_pool,
  &AI_NET_OBJ_INSTANCE, &FC1_layer, AI_STATIC,
  .tensors = &conv2_chain, 
  .groups = 1, 
  .nl_func = nl_func_relu_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_size = AI_SHAPE_2D_INIT(2, 2), 
  .pool_stride = AI_SHAPE_2D_INIT(2, 2), 
  .pool_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_func = pool_func_mp_array_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  FC1_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2_output0),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &FC1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &FC1_weights, &FC1_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  FC1_layer, 5,
  DENSE_TYPE,
  dense, forward_dense,
  &AI_NET_OBJ_INSTANCE, &FC1_nl_layer, AI_STATIC,
  .tensors = &FC1_chain, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  FC1_nl_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &FC1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &FC1_nl_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  FC1_nl_layer, 5,
  NL_TYPE,
  nl, forward_relu,
  &AI_NET_OBJ_INSTANCE, &FC2_layer, AI_STATIC,
  .tensors = &FC1_nl_chain, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  FC2_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &FC1_nl_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &FC2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &FC2_weights, &FC2_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  FC2_layer, 6,
  DENSE_TYPE,
  dense, forward_dense,
  &AI_NET_OBJ_INSTANCE, &FC2_nl_layer, AI_STATIC,
  .tensors = &FC2_chain, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  FC2_nl_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &FC2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &FC2_nl_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  FC2_nl_layer, 6,
  NL_TYPE,
  nl, forward_sm,
  &AI_NET_OBJ_INSTANCE, &FC2_nl_layer, AI_STATIC,
  .tensors = &FC2_nl_chain, 
)


AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 3288524, 1,
                     NULL),
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 57216, 1,
                     NULL),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_WAVMODEL_IN_NUM, &input_0_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_WAVMODEL_OUT_NUM, &FC2_nl_output),
  &conv1_layer, 0, NULL)



AI_DECLARE_STATIC
ai_bool wavmodel_configure_activations(
  ai_network* net_ctx, const ai_buffer* activation_buffer)
{
  AI_ASSERT(net_ctx &&  activation_buffer && activation_buffer->data)

  ai_ptr activations = AI_PTR(AI_PTR_ALIGN(activation_buffer->data, AI_WAVMODEL_ACTIVATIONS_ALIGNMENT));
  AI_ASSERT(activations)
  AI_UNUSED(net_ctx)

  {
    /* Updating activations (byte) offsets */
    conv2_scratch0_array.data = AI_PTR(activations + 36736);
    conv2_scratch0_array.data_start = AI_PTR(activations + 36736);
    conv1_scratch0_array.data = AI_PTR(activations + 36736);
    conv1_scratch0_array.data_start = AI_PTR(activations + 36736);
    input_0_output_array.data = AI_PTR(NULL);
    input_0_output_array.data_start = AI_PTR(NULL);
    conv1_output_array.data = AI_PTR(activations + 5248);
    conv1_output_array.data_start = AI_PTR(activations + 5248);
    conv2_output_array.data = AI_PTR(activations + 0);
    conv2_output_array.data_start = AI_PTR(activations + 0);
    FC1_output_array.data = AI_PTR(activations + 25600);
    FC1_output_array.data_start = AI_PTR(activations + 25600);
    FC1_nl_output_array.data = AI_PTR(activations + 0);
    FC1_nl_output_array.data_start = AI_PTR(activations + 0);
    FC2_output_array.data = AI_PTR(activations + 512);
    FC2_output_array.data_start = AI_PTR(activations + 512);
    FC2_nl_output_array.data = AI_PTR(NULL);
    FC2_nl_output_array.data_start = AI_PTR(NULL);
    
  }
  return true;
}



AI_DECLARE_STATIC
ai_bool wavmodel_configure_weights(
  ai_network* net_ctx, const ai_buffer* weights_buffer)
{
  AI_ASSERT(net_ctx &&  weights_buffer && weights_buffer->data)

  ai_ptr weights = AI_PTR(weights_buffer->data);
  AI_ASSERT(weights)
  AI_UNUSED(net_ctx)

  {
    /* Updating weights (byte) offsets */
    
    FC2_bias_array.format |= AI_FMT_FLAG_CONST;
    FC2_bias_array.data = AI_PTR(weights + 3288512);
    FC2_bias_array.data_start = AI_PTR(weights + 3288512);
    FC2_weights_array.format |= AI_FMT_FLAG_CONST;
    FC2_weights_array.data = AI_PTR(weights + 3286976);
    FC2_weights_array.data_start = AI_PTR(weights + 3286976);
    FC1_bias_array.format |= AI_FMT_FLAG_CONST;
    FC1_bias_array.data = AI_PTR(weights + 3286464);
    FC1_bias_array.data_start = AI_PTR(weights + 3286464);
    FC1_weights_array.format |= AI_FMT_FLAG_CONST;
    FC1_weights_array.data = AI_PTR(weights + 9664);
    FC1_weights_array.data_start = AI_PTR(weights + 9664);
    conv2_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2_bias_array.data = AI_PTR(weights + 9536);
    conv2_bias_array.data_start = AI_PTR(weights + 9536);
    conv2_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2_weights_array.data = AI_PTR(weights + 320);
    conv2_weights_array.data_start = AI_PTR(weights + 320);
    conv1_bias_array.format |= AI_FMT_FLAG_CONST;
    conv1_bias_array.data = AI_PTR(weights + 288);
    conv1_bias_array.data_start = AI_PTR(weights + 288);
    conv1_weights_array.format |= AI_FMT_FLAG_CONST;
    conv1_weights_array.data = AI_PTR(weights + 0);
    conv1_weights_array.data_start = AI_PTR(weights + 0);
  }

  return true;
}


/**  PUBLIC APIs SECTION  *****************************************************/

AI_API_ENTRY
ai_bool ai_wavmodel_get_info(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if ( report && net_ctx )
  {
    ai_network_report r = {
      .model_name        = AI_WAVMODEL_MODEL_NAME,
      .model_signature   = AI_WAVMODEL_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = {AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR,
                            AI_TOOLS_API_VERSION_MICRO, 0x0},

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 3062485,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .activations       = AI_STRUCT_INIT,
      .params            = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x0,
    };

    if ( !ai_platform_api_get_network_report(network, &r) ) return false;

    *report = r;
    return true;
  }

  return false;
}

AI_API_ENTRY
ai_error ai_wavmodel_get_error(ai_handle network)
{
  return ai_platform_network_get_error(network);
}

AI_API_ENTRY
ai_error ai_wavmodel_create(
  ai_handle* network, const ai_buffer* network_config)
{
  return ai_platform_network_create(
    network, network_config, 
    &AI_NET_OBJ_INSTANCE,
    AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR, AI_TOOLS_API_VERSION_MICRO);
}

AI_API_ENTRY
ai_handle ai_wavmodel_destroy(ai_handle network)
{
  return ai_platform_network_destroy(network);
}

AI_API_ENTRY
ai_bool ai_wavmodel_init(
  ai_handle network, const ai_network_params* params)
{
  ai_network* net_ctx = ai_platform_network_init(network, params);
  if ( !net_ctx ) return false;

  ai_bool ok = true;
  ok &= wavmodel_configure_weights(net_ctx, &params->params);
  ok &= wavmodel_configure_activations(net_ctx, &params->activations);

  ok &= ai_platform_network_post_init(network);

  return ok;
}


AI_API_ENTRY
ai_i32 ai_wavmodel_run(
  ai_handle network, const ai_buffer* input, ai_buffer* output)
{
  return ai_platform_network_process(network, input, output);
}

AI_API_ENTRY
ai_i32 ai_wavmodel_forward(ai_handle network, const ai_buffer* input)
{
  return ai_platform_network_process(network, input, NULL);
}




#undef AI_WAVMODEL_MODEL_SIGNATURE
#undef AI_NET_OBJ_INSTANCE
#undef AI_TOOLS_VERSION_MAJOR
#undef AI_TOOLS_VERSION_MINOR
#undef AI_TOOLS_VERSION_MICRO
#undef AI_TOOLS_API_VERSION_MAJOR
#undef AI_TOOLS_API_VERSION_MINOR
#undef AI_TOOLS_API_VERSION_MICRO
#undef AI_TOOLS_DATE_TIME
#undef AI_TOOLS_COMPILE_TIME

