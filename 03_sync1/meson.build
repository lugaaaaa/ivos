project('03_sync1', 'cpp',
        license : ['Boost'],
        version : '0.1',
        default_options : ['cpp_std=c++2a', 'warning_level=3', 'werror=true'])

thread_dep = dependency('threads')

src = ['src/main.cpp', 'src/account.cpp']

inc_dir = include_directories(['include'])


executable('account',
            sources : src,
            dependencies : thread_dep,
            include_directories : inc_dir,
           )
