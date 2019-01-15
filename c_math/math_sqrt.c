#include <Python.h>

static PyObject *_sqrt(PyObject *self, PyObject *args)
{

    double a;

    if (!PyArg_ParseTuple(args, "d", &a))
        return NULL;

    long long int temp = 0x5fe6eb50c7b537aal - (*(long long int *)&a >> 1);
    double value = *(double *)&temp;

    const double half = 0.5 * a;

    value *= (1.5 - (half * value * value));
    value *= (1.5 - (half * value * value));
    value *= (1.5 - (half * value * value));
    value *= (1.5 - (half * value * value));
    value *= (1.5 - (half * value * value));

    return PyFloat_FromDouble(a * value);
}