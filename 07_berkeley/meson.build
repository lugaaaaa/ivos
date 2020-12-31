project('07_berkeley', 'cpp')
thread_dep = dependency('threads')

inc_dir = include_directories(['include', get_option('cli_include_dir')])
src = ['src/main.cpp', 'src/clock.cpp']

executable('berkeley', sources : src,
include_directories : inc_dir, dependencies : thread_dep)
