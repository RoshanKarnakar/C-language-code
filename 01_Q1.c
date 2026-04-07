#include <stdio.h>

int adc_to_percent(int adc, int adc_max, int *out_percent) {
    // 1. Validate inputs and null pointer
    if (out_percent == NULL || adc_max <= 0 || adc < 0 || adc > adc_max) {
        return -1;
    }

    long temp = ((long)adc * 100);
    int result = (int)((temp + (adc_max / 2)) / adc_max);

    if (result > 100) {
        result = 100;
    } else if (result < 0) {
        result = 0;
    }

    *out_percent = result;
    return 0;
}
