#ifndef EYE_ENGINE_H
#define EYE_ENGINE_H
#include <QTime>
#include "header.h"
#include "matrix_engin.h"
#include<QThread>
#include "sinc_filters.h"
#include <queue.h>



class eye_engine : public QThread ,public matrix_engin,public sinc_filters
{
    Q_OBJECT
public:
    eye_engine(int _num_of_symbols,int _sampling_frequncy,double _alpha);
    double  *convl(double *input, int input_size, double *h, int h_size, double **output,int *output_size);
    void     init_parameters(int _num_of_symbols,int _sampling_frequncy,double _alpha);
    void     run();
    void     data_from_udp_socket(char *dptr,int data_size, int sampling_frequncy);
    virtual ~eye_engine();



private :
       int       num_of_symbols;
       int		 sampling_frequncy;
       int  	 alpha_symbol_size;
       double    alpha;
       double 	*sine_sinc_op;
       double 	*cosine_sinc_op;
       double 	*alpha_op;
       double   *conv_output;
       int       mutex_data_from_udp;
       int       thread_bussy;
       double   *udp_input_data_symbols;
       int      *udp_input_data_symbols_size;
       QVector<double> *xx,*yy  ;

       wqueue    *myque;
       QTime t;

};

#endif // EYE_ENGINE_H
