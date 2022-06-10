#include <rt_ai_wavmodel_model.h>
#include <rt_ai.h>
#include <rt_ai_log.h>

static rt_ai_t model = NULL;

int ai_run_complete_flag = 0;
void ai_run_complete(void *arg){
    *(int*)arg = 1;
}

int recognize(float* mfcc_data){
    rt_err_t result = RT_EOK;
    int prediction = 0;
    float* input_data0 = mfcc_data;

    rt_ai_buffer_t *work_buffer = rt_malloc(RT_AI_WAVMODEL_WORK_BUFFER_BYTES+RT_AI_WAVMODEL_IN_TOTAL_SIZE_BYTES+\
            RT_AI_WAVMODEL_OUT_TOTAL_SIZE_BYTES);

    model = rt_ai_find(RT_AI_WAVMODEL_MODEL_NAME);  // 找寻AI模型
    if(!model) {rt_kprintf("ai model find err\r\n"); return -1;}


    result = rt_ai_init(model , work_buffer);
    if (result != 0) {rt_kprintf("ai init err\r\n"); return -1;}

    rt_memcpy(model->input[0], input_data0, RT_AI_WAVMODEL_IN_1_SIZE_BYTES);
    result = rt_ai_run(model, ai_run_complete, &ai_run_complete_flag);  // 运行AI模型
    if (result != 0) {rt_kprintf("ai model run err\r\n"); return -1;}


    if(ai_run_complete_flag){
        float *out = (float *)rt_ai_output(model, 0);
        for(int i = 0 ; i < 3 ; i++){       // 得出识别结果
            if(out[i] > out[prediction]){
                prediction = i;
            }
        }
        AI_LOG("The Wav specker prediction is : %f\n", prediction);
        printf("%f\n%f\n%f\n",out[0],out[1],out[2]);
    }
    return prediction;
}
