#include <Python.h>
#include "util_system.c"

static PyObject* _system(PyObject *self, PyObject *args);

static PyMethodDef util_methods[] = 
{
    {"system", _system, METH_VARARGS, "Execute a shell command."},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef util_module = 
{
    PyModuleDef_HEAD_INIT,
    "util",
    NULL,
    -1,
    util_methods
};

PyMODINIT_FUNC PyInit_util(void)
{
    PyObject *m;

    m = PyModule_Create(&util_module);
    if(m == NULL)
        return NULL;

    SystemError = PyErr_NewException("util.SystemError", NULL, NULL);
    Py_INCREF(SystemError);
    PyModule_AddObject(m, "SystemError", SystemError);
    return m;
}
