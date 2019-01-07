#include <Python.h>
#include "util_error.h"

static PyObject* _system(PyObject *self, PyObject *args)
{
    const char *command;
    int sts;

    if(!PyArg_ParseTuple(args, "s", &command))
        return NULL;
    sts = system(command);
    if(sts < 0)
    {
        PyErr_SetString(SystemError, "System command failed.");
        return NULL;
    }
    return PyLong_FromLong(sts);
}

