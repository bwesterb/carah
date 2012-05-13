#include <Python.h>

static PyObject*
string_to_hex(PyObject* self, PyObject* args)
{
        PyObject* ret;
        const char *s;
        int l;
        char* buf;
        int i;

        if (!PyArg_ParseTuple(args, "s#", &s, &l))
                return NULL;

        buf = malloc(l*2);

        for (i = 0; i < l; i++) {
                char high, low;
                high = s[i] / 16;
                low = s[i] % 16;

                buf[2*i] = high < 10 ? 48 + high : 87 + high;
                buf[2*i+1] = low < 10 ? 48 + low : 87 + low;
        }

        ret = Py_BuildValue("s#", buf, l * 2);
        free(buf);

        return ret;
}

static PyMethodDef StringMethods[] = {
        {"to_hex", string_to_hex, METH_VARARGS,
                "Convert string to hexadecimal string"},
        {NULL, NULL, 0, NULL}
};

PyMODINIT_FUNC
initstring(void)
{
        PyObject *m;

        Py_InitModule("string", StringMethods);
}
