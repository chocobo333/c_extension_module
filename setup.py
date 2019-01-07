from distutils.core import setup, Extension

module = Extension("c_ext",
                   sources=["c_ext_module.c"])

setup(name="c_ext",
      version="1.0",
      description="This is a c extention package",
      ext_modules = [module])
