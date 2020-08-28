#include "sinc_filters.h"

sinc_filters::sinc_filters()
{

}

double * sinc_filters::sine_sinc_mul_cosine_sinc(double *sine_sinc,double *cosine_sinc,int size_sinc_symbol,double **output )
{
    int i		=	0;
  *output 	= 	new double[ size_sinc_symbol];

    for(i=0;i<size_sinc_symbol;i++)
    {
        (*output)[i] = sine_sinc[i]*cosine_sinc[i];
    }

    return (*output);
   }

double*  sinc_filters::sine_sinc_filter(int sampling_frequncy,double alpha,double **sine_sinc_output,int *size_sine_sinc_output)
{
        int	 	i;
        int 	num_of_iterations 	   = 	((sampling_frequncy*sampling_frequncy*2)+1);
        int 	from_find_size;
        double 	sampling_time	  	   = 	1/(double)sampling_frequncy;
        double 	f 				   	   =	-sampling_frequncy;
        int 	*to_find   	       	   = 	(int*)		malloc((num_of_iterations+10)*sizeof(int));
        int 	*from_find    	       =   	(int*)		malloc((num_of_iterations+10)*sizeof(int));
        double 	*sine_sinc_num	       = 	(double*)   malloc((num_of_iterations+10)*sizeof(double));
        double 	*sine_sinc_deno        =	(double*)	malloc((num_of_iterations+10)*sizeof(double));
                *sine_sinc_output      = 	(double*)	malloc((num_of_iterations+10)*sizeof(double));

        for(f=-sampling_frequncy,i=0;f<=sampling_frequncy;f+=sampling_time,i++)
        {
             sine_sinc_num[i]  = sin(PI*f);
             sine_sinc_deno[i]  = PI*f;
        }

        *size_sine_sinc_output = i;

        for(i=0;i<*size_sine_sinc_output;i++)
        {
            to_find[i] = abs(sine_sinc_deno[i]) < 0.001;
        }

        find(to_find,from_find,*size_sine_sinc_output,&from_find_size);

         for(i=0;i<*size_sine_sinc_output;i++)
        {
             (*sine_sinc_output)[i] = sine_sinc_num[i]/sine_sinc_deno[i];
        }

         for(i=0;i<from_find_size;i++)
        {
             (*sine_sinc_output)[from_find[i]] = 1;
        }

        free(sine_sinc_num);
        free(sine_sinc_deno);
        free(to_find);
        free(from_find);

        return  (*sine_sinc_output);
}

double * sinc_filters::cosine_sinc_filter(int sampling_frequncy,double alpha,double **cosine_sinc_output,int *size_sine_sinc_output )
{

        int 		i;
        int 		num_of_iterations 	= 	((sampling_frequncy*sampling_frequncy*2)+1);
        int 		from_find_size;
        double 		sampling_time 	    = 	1/(double)sampling_frequncy;
        double 		f 					= 	-sampling_frequncy;
        int 		*to_find    		= 	(int*)		malloc((num_of_iterations +10)*sizeof(int));
        int 		*from_find    		= 	(int*)		malloc((num_of_iterations +10)*sizeof(int));
        double 		*cosine_sinc_num	= 	(double*)	malloc((num_of_iterations +10)*sizeof(double));
        double 		*cosine_sinc_deno  	= 	(double*)	malloc((num_of_iterations +10)*sizeof(double));
                    *cosine_sinc_output	= 	(double*)	malloc((num_of_iterations +10)*sizeof(double));



        for(f=-sampling_frequncy,i=0;f<=sampling_frequncy;f+=sampling_time,i++)
        {
            cosine_sinc_num[i]   =  cos( alpha*PI*f);
            cosine_sinc_deno[i]  =  (1 - ((2*f* alpha)*(2*f* alpha))) ;
        }

        *size_sine_sinc_output = i;

        for(i=0;i<*size_sine_sinc_output;i++)
        {
            to_find[i] = abs(cosine_sinc_deno[i]) < 0.001;
        }

        find(to_find,from_find,*size_sine_sinc_output,&from_find_size);


        for(i=0;i<*size_sine_sinc_output;i++)
        {
            (*cosine_sinc_output)[i] = cosine_sinc_num[i]/cosine_sinc_deno[i];
        }

        for(i=0;i<from_find_size;i++)
        {
            (*cosine_sinc_output)[from_find[i]] = PI/4;
        }

        free(cosine_sinc_num);
        free(cosine_sinc_deno);
        free(to_find);
        free(from_find);
        return  (*cosine_sinc_output);
}

double sinc_filters::abs(double input)
{
        if(input<0)
        return -input;
        return input;
}

void sinc_filters::find(int *input,int *index_arr,int input_size,int *output_size)
{
       int i=0;
       int j=0;
       for(i=0,j=0;i<input_size;i++)
       {
            if(input[i] !=0)
            index_arr[j++]=i;
       }

       *output_size = j;
 }
