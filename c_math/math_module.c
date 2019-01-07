#include <Python.h>
#include "math_fibs.c"

static PyMethodDef math_methods[] = 
{
    // {"system", _system, METH_VARARGS, "Execute a shell command."},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef math_module = 
{
    PyModuleDef_HEAD_INIT,
    "math",
    NULL,
    -1,
    math_methods
};

PyMODINIT_FUNC PyInit_math(void)
{
    PyObject *m;

    m = PyModule_Create(&math_module);
    if(m == NULL)
        return NULL;

    fibsType.tp_new = PyType_GenericNew;
    if(PyType_Ready(&fibsType) < 0)
        return NULL;
    Py_INCREF(&fibsType);
    PyModule_AddObject(m, "fibs", (PyObject*)&fibsType);
    
    return m;
}