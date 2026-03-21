from setuptools import find_packages
from setuptools import setup

setup(
    name='workload_nodes',
    version='0.0.0',
    packages=find_packages(
        include=('workload_nodes', 'workload_nodes.*')),
)
