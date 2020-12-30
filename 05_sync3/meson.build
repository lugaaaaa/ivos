project('sync3_05', 'cpp')
thread_dep = dependency('threads')

inc_dir = include_directories(['include', get_option('cli_include_dir')])
src = ['src/main.cpp', 'src/philosopher.cpp', 'src/semaphore.cpp']

executable('dining', sources : src,
include_directories : inc_dir, dependencies : thread_dep)
