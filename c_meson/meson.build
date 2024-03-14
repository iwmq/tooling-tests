project('c_meson', 'c',
  version : '0.1',
  default_options : ['warning_level=3'])

exe = executable('c_meson', 'c_meson.c',
  install : true)

test('basic', exe)

c_list_exe = executable('c_list', 'c_list.c',
  install : true)

test('basic', c_list_exe)