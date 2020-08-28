#ifndef SINC_FILTERS_H
#define SINC_FILTERS_H
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include"header.h"

class sinc_filters
{

    public:
            sinc_filters();

            double		*sine_sinc_mul_cosine_sinc(double *sine_sinc,double *cosine_sinc,int size_sinc_symbol,double **output );
            double		*sine_sinc_filter(int sampling_frequncy,double alpha,double **sine_sinc_output,int *size_sine_sinc_output);
            double 		*cosine_sinc_filter(int sampling_frequncy,double alpha,double **cosine_sinc_output,int *size_sine_sinc_output );
    private:
            void 		 find(int *input,int *index_arr,int input_size,int *output_size);
            double 		 abs(double input);
};


#endif // SINC_FILTERS_H
