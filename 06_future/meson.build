project('future_06', 'cpp')
thread_dep = dependency('threads')

inc_dir = include_directories(['include'])
src = ['src/main.cpp']

executable('factoring', sources : src,
include_directories : inc_dir, dependencies : thread_dep)
