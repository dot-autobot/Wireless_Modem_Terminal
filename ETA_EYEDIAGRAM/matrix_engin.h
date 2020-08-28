#ifndef MATRIX_ENGIN_H
#define MATRIX_ENGIN_H
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include"header.h"


class matrix_engin
{

    public:
            matrix_engin();

            void		*reshap_matrix(double *dptr,int size,int row,int col,matrix *output);
            void		*matrix_two_to_one_d(matrix *input,double *output);
            void		*matrix_transpos(matrix *input_matrix,matrix *output_matrix);
            void		*up_sample_signal(double *dataptr,int lengh,int fs,double **output,int *size_output);
            void 		 print_matrix(matrix in);

};


#endif // MATRIX_ENGIN_H
