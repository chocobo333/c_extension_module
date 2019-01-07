#include <Python.h>
#include "c_ext_system.c"

static PyObject* _system(PyObject *self, PyObject *args);

static PyMethodDef c_ext_methods[] = 
{
    {"system", _system, METH_VARARGS, "Execute a shell command."},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef c_ext_module = 
{
    PyModuleDef_HEAD_INIT,
    "c_ext",
    NULL,
    -1,
    c_ext_methods
};

PyMODINIT_FUNC PyInit_c_ext(void)
{
    PyObject *m;

    m = PyModule_Create(&c_ext_module);
    if(m == NULL)
        return NULL;

    SystemError = PyErr_NewException("c_ext.SystemError", NULL, NULL);
    Py_INCREF(SystemError);
    PyModule_AddObject(m, "error", SystemError);
    return m;
}
