//
// Created by eduardo on 12/22/20.
//

#include "locale.h"
#ifdef __APPLE__
#include <stdint.h>
typedef uint16_t char16_t;
typedef uint32_t char32_t;
#else
#include <uchar.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>

#if __STDC_UTF_16__ != 1
#error "__STDC_UTF_16__ not defined"
#endif

void locale(void)
{
    setlocale(LC_ALL, "en_US.utf8");
    char input[] = "I ❤️ tacos";
    const size_t input_size = sizeof(input);
    char16_t output[input_size];
    char *p_input = input;
    char *p_end = input + input_size;
    char16_t *p_output = output;
    size_t code;
    mbstate_t state = {0};
    puts(input);
    while ((code = mbrtoc16(p_output, p_input, p_end-p_input, &state)))
    {
        if (code == (size_t)-1 || code == (size_t)-2)
            break;
        else if (code == (size_t)-3)
            p_output++;
        else{
            p_output++;
            p_input += code;
        }
    }
    size_t output_size = p_output - output + 1;
    printf("Converted to %zu UTF-16 code units: [ ", output_size);
    for (size_t i = 0; i < output_size; ++i) printf("%#x ", output[i]);
    puts("]");
}
