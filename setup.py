#!/usr/bin/env python

from setuptools import setup, find_packages
from setuptools.extension import Extension
from get_git_version import get_git_version

setup(name='carah',
      version=get_git_version(),
      description='Parts of the sarah library rewritten in C',
      author='Bas Westerbaan',
      author_email='bas@westerbaan.name',
      url='http://github.com/bwesterb/carah/',
      packages=['carah'],
      package_dir={'carah': 'src'},
      ext_modules=[
            Extension('string', ['src/string.c'])
          ]
      )

# vim: et:sta:bs=2:sw=4:
