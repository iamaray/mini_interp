#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

typedef enum
{
    INT_TENSOR,
    FLOAT_TENSOR,
    LONG_TENSOR,
    DOUBLE_TENSOR, 
    CHAR_TENSOR
} TensorType;

typedef struct
{
    union
    {
        struct { int *data; } intTensor;
        struct{ float *data; } floatTensor;
        struct { long *data; } longTensor;
        struct { double *data; } doubleTensor;
        struct { char *data; } charTensor;
    } data;

    int *shape;
    int *stride;
    int ndims;
    int nElts;
    bool contiguous;
    TensorType type;
} Tensor;

/* GENERAL UTILITY */
Tensor *createTensor(TensorType type, int ndims, const int *shape, bool contiguous);
Tensor *reshapeTensor(Tensor *tensor, int new_ndims, const int *new_shape);
Tensor *cloneTensor(const Tensor *tensor);
Tensor *makeContiguous(Tensor *tensor);

void printTensor(const Tensor *tensor);
void freeTensor(Tensor *tensor);

/* INITIALIZATION */
Tensor *tensorFromInts(int *data, const int *shape, int ndims, bool contiguous);
Tensor *tensorFromFloats(float *data, const int *shape, int ndims, bool contiguous);
Tensor *tensorFromLongs(long *data, const int *shape, int ndims, bool contiguous);
Tensor *tensorFromDoubles(double *data, const int *shape, int ndims, bool contiguous);
Tensor *tensorFromChars(char *data, const int *shape, int ndims, bool contiguous);

Tensor *ones(TensorType type, const int *shape, int ndims, bool contiguous);
Tensor *zeros(TensorType type, const int *shape, int ndims, bool contiguous);

/* ACCESS & MODIFY */
int tensorGetIntElement(const Tensor *tensor, const int *indices);
int tensorSetIntElement(const Tensor *tensor, const int *indices, int value);

int tensorGetFloatElement(const Tensor *tensor, const int *indices);
int tensorSetFloattElement(const Tensor *tensor, const int *indices, float value);

int tensorGetLongElement(const Tensor *tensor, const int *indices);
int tensorSetLongElement(const Tensor *tensor, const int *indices, long value);

int tensorGetDoubleElement(const Tensor *tensor, const int *indices);
int tensorSetDoubleElement(const Tensor *tensor, const int *indices, double value);

int tensorGetCharElement(const Tensor *tensor, const int *indices);
int tensorSetCharElement(const Tensor *tensor, const int *indices, char value);