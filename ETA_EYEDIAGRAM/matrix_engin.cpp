#include "matrix_engin.h"

matrix_engin::matrix_engin()
{
}

void		*matrix_engin::reshap_matrix(double *dptr,int size,int row,int col,matrix *output)
{
    int i,j,k;

    if(size == (row*col) && (output ==0))
    {
        return 0;
    }
    matrix temp;
    output->matrix = (double**)malloc(sizeof(double*)*row);
    output->row=row;
    output->col=col;

    for(i=0;i<row;i++)
    {
        output->matrix[i] = (double*)malloc(sizeof(double)*col);
    }

    for(i=0,k=0;i<col;i++)
    {
        for(j=0;j<row;j++)
        {
            output->matrix[j][i] = dptr[k++];
        }
    }
    //matrix_transpos(&temp,output);
    return output;
  }

void 		*matrix_engin::matrix_two_to_one_d(matrix *input,double *output)
{
    int i,j,k;

    for(i=0,k=0;i<input->col;i++)
    {
        for(j=0;j<input->row;j++)
        {
            output[k++] = input->matrix[j][i];
        }
      }

    return output;
}

/***************************************************************************************************************
 *
 *
 *
 *
 *
 *
 ****************************************************************************************************************/

void		*matrix_engin::matrix_transpos(matrix *input_matrix,matrix *output_matrix)
{

    int i,j;
    double **tmatrix  = (double**)malloc(sizeof(double*)*input_matrix->col);

    for(i=0;i<input_matrix->col;i++)
    {
         tmatrix[i] = (double*) malloc(sizeof(double)*input_matrix->row);
    }

    (output_matrix)->matrix =tmatrix;
    (output_matrix)->col = input_matrix->row;
    (output_matrix)->row = input_matrix->col;

    for(i=0;i<(output_matrix)->row;i++)
    {

      for(j=0;j<(output_matrix)->col;j++)
      {
       (output_matrix)->matrix[i][j] = input_matrix->matrix[j][i];
      }
    }

   //  print_matrix(*output_matrix);

    return 	(output_matrix);
}

void		*matrix_engin::up_sample_signal(double *dataptr,int lengh,int fs,double **output,int *size_output)
{

    int i,j;
    double **p      =  (double**)malloc(fs*sizeof(double*));

    matrix  temp_m;

            temp_m.matrix=p;
            temp_m.row = fs;
            temp_m.col = lengh;

            *output = (double*)malloc(sizeof(double)*temp_m.row*temp_m.col);

    for(i=0;i<fs;i++)
    {
        p[i] =  (double*) malloc(lengh*sizeof(double));
    }

    for(i =0;i<fs;i++)
    {
        for(j=0;j<lengh;j++)
        {

            if(i==0)
                p[i][j] = dataptr[j];
            else
                p[i][j] = 0;
        }
    }

    *size_output = temp_m.col*temp_m.row;
    matrix_two_to_one_d(&temp_m,*output);

    return	*output;
}


void		 matrix_engin::print_matrix(matrix in)
{
        int i,j;
        for(i=0;i<in.row;i++)
        {
            for(j=0;j<in.col;j++)
            {
                printf("%lf",in.matrix[i][j]);
             }
             printf("\n");
         }
         printf("\n");
}
