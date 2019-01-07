from distutils.core import setup, Extension

util = Extension("util",
                  sources=["c_util/util_module.c"])
math = Extension("math",
                  sources=["c_math/math_module.c"])

setup(
      name="c_ext",
      version="1.0",
      description="This is a c extention package",
      author="chocobo333",
      ext_package="c",
      ext_modules=[util, math])
