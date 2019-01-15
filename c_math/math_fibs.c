#include <Python.h>

typedef struct
{
    PyObject_HEAD
    int cur;
    int max;
    long n_1;
    long n_2;
}fibs;

static void fibs_dealloc(fibs* self)
{
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static int fibs_init(fibs* self, PyObject *args, PyObject *kwds)
{
    if(!PyArg_ParseTuple(args, "i",&(self->max)))
        return -1;
    self->cur = 0;
    self->n_1 = 1;
    self->n_2 = 1;
    
    return 0;
}


static PyObject* fibs_iter(PyObject *self)
{
    Py_INCREF(self);
    fibs *_self = (fibs*)self;
    _self->cur = 0;
    _self->n_1 = 1;
    _self->n_2 = 1;
    return self;
}

static PyObject* fibs_next(PyObject *self)
{
    fibs *_self = (fibs*)self;
    if(_self->cur == _self->max)
    {
        PyErr_SetNone(PyExc_StopIteration);
        return NULL;
    }
    if(_self->cur < 2)
    {
        _self->cur++;
        return PyLong_FromLong(1);
    }
    else
    {
        long ret = _self->n_1 + _self->n_2;
        _self->n_2 = _self->n_1;
        _self->n_1 = ret;
        _self->cur++;

        return PyLong_FromLong(ret);
    }
}

static PyTypeObject fibsType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "c.math.fibs",             /* tp_name */
    sizeof(fibs), /* tp_basicsize */
    0,                         /* tp_itemsize */
    (destructor)fibs_dealloc,                         /* tp_dealloc */
    0,                         /* tp_print */
    0,                         /* tp_getattr */
    0,                         /* tp_setattr */
    0,                         /* tp_reserved */
    0,                         /* tp_repr */
    0,                         /* tp_as_number */
    0,                         /* tp_as_sequence */
    0,                         /* tp_as_mapping */
    0,                         /* tp_hash  */
    0,                         /* tp_call */
    0,                         /* tp_str */
    0,                         /* tp_getattro */
    0,                         /* tp_setattro */
    0,                         /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,        /* tp_flags */
    "iterator of fibs",           /* tp_doc */

    0,                         /* tp_traverse */
    0,                         /* tp_clear */
    0,                         /* tp_richcompare */
    0,                         /* tp_weaklistoffset */
    fibs_iter,                         /* tp_iter */
    fibs_next,                         /* tp_iternext */
    0,             /* tp_methods */
    0,             /* tp_members */
    0,                         /* tp_getset */
    0,                         /* tp_base */
    0,                         /* tp_dict */
    0,                         /* tp_descr_get */
    0,                         /* tp_descr_set */
    0,                         /* tp_dictoffset */
    (initproc)fibs_init,      /* tp_init */
    0,                         /* tp_alloc */
    0,                 /* tp_new */
};