from distutils.core import Extension, setup
from Cython.Build import cythonize

ext = Extension(
    name="cyTest",
    sources=["cyTestC.pyx"]
)

setup(ext_modules=cythonize(ext, language_level=3))

# run with python3 <this_file>.py build_ext --inplace

# generate html with cython -a <file>.pyx
