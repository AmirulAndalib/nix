# This is only conditional to work around
# https://github.com/mesonbuild/meson/issues/13293. It should be
# unconditional.
if not (host_machine.system() == 'windows' and cxx.get_id() == 'gcc')
  deps_private += dependency('threads')
endif

add_project_arguments(
  '-Wdeprecated-copy',
  '-Werror=suggest-override',
  '-Werror=switch',
  '-Werror=switch-enum',
  '-Werror=undef',
  '-Werror=unused-result',
  '-Werror=sign-compare',
  '-Wignored-qualifiers',
  '-Wimplicit-fallthrough',
  '-Wno-deprecated-declarations',
  language : 'cpp',
)

# This is a clang-only option for improving build times.
# It forces the instantiation of templates in the PCH itself and
# not every translation unit it's included in.
# It's available starting from clang 11, which is old enough to not
# bother checking the version.
# This feature helps in particular with the expensive nlohmann::json template
# instantiations in libutil and libstore.
if cxx.get_id() == 'clang'
  add_project_arguments('-fpch-instantiate-templates', language : 'cpp')
endif
