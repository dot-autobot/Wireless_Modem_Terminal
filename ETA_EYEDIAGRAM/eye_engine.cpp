 #include "eye_engine.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "header.h"
#include "sinc_filters.h"
#include <QTime>
#include <QtTest/QTest>
#include <eyediagram.h>
#define  TEST
extern double doub[268];

double randn(double mu,double sigma);
double VAR(char *dptr,int size);

eye_engine::eye_engine(int _num_of_symbols,int _sampling_frequncy,double _alpha ):
 num_of_symbols(_num_of_symbols),
 sampling_frequncy(_sampling_frequncy),
 alpha(_alpha)
 {  myque = new wqueue;
    thread_bussy=0;
    mutex_data_from_udp =0;
    xx  = new QVector<double>;
    yy  = new QVector<double>;
 }


void eye_engine::run()
{

       int i;
       int j;
       int count_samples;
       double tt=-1;
       double *up_sample_sig;
       int     up_sample_sig_size;
       double *convolved_sig;
       int     convolved_sig_size;
       double *to_be_free;
       matrix r_m,eye;


        while(1)
        {

            {
#ifdef RELEASE
                to_be_free=  myque->remove();
                up_sample_signal(  to_be_free,num_of_symbols,sampling_frequncy,&up_sample_sig,&up_sample_sig_size);
#endif

#ifdef TEST
                this->num_of_symbols  = 100;
                this->alpha = .6;
                up_sample_signal( doub,num_of_symbols,sampling_frequncy,&up_sample_sig,&up_sample_sig_size);
#endif
                sine_sinc_filter(  sampling_frequncy, alpha,  &sine_sinc_op,&alpha_symbol_size);
                cosine_sinc_filter(sampling_frequncy, alpha,  &cosine_sinc_op,&alpha_symbol_size);
                sine_sinc_mul_cosine_sinc(sine_sinc_op,cosine_sinc_op,alpha_symbol_size,&alpha_op);


                convl(up_sample_sig,up_sample_sig_size,this->alpha_op,this->alpha_symbol_size,&convolved_sig,&convolved_sig_size);
                reshap_matrix(convolved_sig,convolved_sig_size,sampling_frequncy*2,num_of_symbols*sampling_frequncy/20,  &eye);

                printf("r[%d]c[%d]\n",eye.row,eye.col);
                 for(i=5;i<  eye.col;i++)
                 {
                    QCoreApplication::processEvents(QEventLoop::AllEvents);

                    for(j=0;j<eye.row;j++)
                    {
                        xx->push_back(j);
                        yy->push_back(eye.matrix[j][i] );
                    }

                    EyeDiagram::getInstence()->call_back(i,xx,yy);

                    for(j=0;j<eye.row;j++)
                    {
                         xx->pop_front();
                         yy->pop_front();
                    }
                 }

                 EyeDiagram::getInstence()->show_eye();

                 free( to_be_free);
             }
        }
}

void eye_engine::data_from_udp_socket(char *dptr, int data_size, int sampling_frequncy)
{

    int count_samples;


    this->sampling_frequncy =sampling_frequncy;
    this->num_of_symbols = data_size/2;


    udp_input_data_symbols  = (double*)malloc(sizeof(double)*data_size/2);

     for(count_samples=0;count_samples< this->num_of_symbols; count_samples++)
    {
         QCoreApplication::processEvents(QEventLoop::AllEvents);
#ifdef TEST
         udp_input_data_symbols[count_samples] =    (((double)(*(((short int*)dptr)+count_samples)))/32768)  + randn(0,EyeDiagram::getInstence()->get_var());//VAR(dptr,data_size/2))  ;
#endif


#ifdef  RELEASE
         udp_input_data_symbols[count_samples] =    (((double)(*(((short int*)dptr)+count_samples)))/32768);
#endif
    }

     myque->add(udp_input_data_symbols);


}

eye_engine::~eye_engine()
{
}


double *eye_engine::convl(double *input, int input_size, double *h, int h_size, double **output,int *output_size)
{   int n;
    int k;


    *output_size = input_size + h_size -1;

    *output = (double*)malloc(sizeof(double)**output_size);
    for(n=0;n<*output_size;n++)
    {
        (*output)[n] =0;
    }
    for(n=0;n<*output_size;n++)
    {
        for(k=0;k<=n;k++)
        {
            if(k <input_size && (n-k)<h_size)
                (*output)[n] =(*output)[n] + ( input[k] *h[n-k]);
            if(k >input_size || (n-k)>h_size)
                (*output)[n] =(*output)[n]  ;
        }
    }

    return  *output;
}

void eye_engine::init_parameters(int _num_of_symbols, int _sampling_frequncy, double _alpha)
{
    this->num_of_symbols = _num_of_symbols;
    this->sampling_frequncy = _sampling_frequncy;
    this->alpha = _alpha;
}


double randn(double mu,double sigma)
{
    double u1,u2,w,mult;
    static double x1,x2;
    static int call =0;
    if(call==1)
    {
        call = !call;
        return (mu+sigma*(double)x2);
    }
    do
    {
        u1 = -1 + ((double)rand()/0x7FFF)*2;
        u2 = -1 + ((double)rand()/0x7FFF)*2;
        w = pow(u1,2)+pow(u2,2);

    }while(w>=1 || w==0);
    mult = sqrt(-2*log(w)/w);
    x1 = u1*mult;
    x2 = u2*mult;
    call = !call;
    return (mu+sigma*(double)x1);
}

double VAR(char *dptr,int size)
{
    int i;
    double m2,m1,av=0,pav=0;


    for(i=0;i<(size );i++)
    {
        av = av+((double)((short*)dptr)[i] /32767);
        m1  = av/size ;
    }
    for(i=0;i<(size );i++)
    {
        pav = pav+(((double)((short*)dptr)[i])/32767)*(((double)((short*)dptr)[i])/32767);
    }

    m2  = pav/size ;

    return m2-pow(m1,2);
}


double doub[268] ={1
                   ,0.500000
                   ,0.500000
                   ,0.500000
                   ,-1.50000
                   ,1.500000
                   ,0.500000
                   ,-1.50000
                   ,-0.50000
                   ,1.500000
                   ,-1.50000
                   ,1.500000
                   ,0.500000
                   ,0.500000
                   ,0.500000
                   ,-1.50000
                   ,-0.50000
                   ,0.500000
                   ,0.500000
                   ,0.500000
                   ,0.500000
                   ,0.500000
                   ,-1.50000
                   ,1.500000
                   ,0.500000
                   ,-1.50000
                   ,1.500000
                   ,0.500000
                   ,-1.50000
                   ,1.500000
                   ,-1.50000
                   ,-0.5000000
                   ,-0.5000000
                   ,-0.5000000
                   ,-0.5000000
                   ,1.50000000
                   ,-1.5000000
                   ,-0.5000000
                   ,-0.5000000
                   ,1.50000000
                   ,-1.5000000
                   ,1.50000000
                   ,0.50000000
                   ,0.50000000
                   ,-1.5000000
                   ,1.50000000
                   ,0.50000000
                   ,-1.5000000
                   ,-0.5000000
                   ,-0.5000000
                   ,1.50000000000000
                   ,-1.50000000000000
                   ,1.50000000000000
                   ,0.500000000000000
                   ,0.500000000000000
                   ,-1.50000000000000
                   ,-0.500000000000000
                   ,1.50000000000000
                   ,-1.50000000000000
                   ,-0.500000000000000
                   ,-0.500000000000000
                   ,-0.500000000000000
                   ,1.50000000000000
                   ,0.500000000000000
                   ,0.500000000000000
                   ,0.500000000000000
                   ,-1.50000000000000
                   ,-0.500000000000000
                   ,-0.500000000000000
                   ,1.50000000000000
                   ,0.500000000000000
                   ,-1.50000000000000
                   ,-0.500000000000000
                   ,-0.500000000000000
                   ,1.50000000000000
                   ,0.500000000000000
                   ,-1.50000000000000
                   ,-0.500000000000000
                   ,-0.500000000000000
                   ,1.50000000000000
                   ,-1.50000000000000
                   ,1.50000000000000
                   ,-1.50000000000000
                   ,1.50000000000000
                   ,0.500000000000000
                   ,0.500000000000000
                   ,0.500000000000000
                   ,0.500000000000000
                   ,-1.50000000000000
                   ,1.50000000000000
                   ,-1.50000000000000
                   ,-0.500000000000000
                   ,-0.500000000000000
                   ,1.50000000000000
                   ,-1.50000000000000
                   ,1.50000000000000
                   ,0.500000000000000
                   ,0.500000000000000
                   ,0.500000000000000};
