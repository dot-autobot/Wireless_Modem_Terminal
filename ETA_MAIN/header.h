#ifndef HEADER_H
#define HEADER_H

#define PI 3.1416


struct im_num
{
    double *I;
    double *Q;
    int  im_n_size;
};

struct matrix
{
    double **matrix;
    int row;
    int col;
};
struct host_info
{
    int port;
    int size;
    char IP[100];

};
struct packet
{
    char  *p_ptr;
    int modulation;
    int  size;
};

#endif // HEADER_H
