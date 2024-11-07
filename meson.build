project('nibbler', 'cpp')

subdir('src')

executable('nibbler',
		'src/main.cpp',
		'src/utils.cpp',
		'src/Game.cpp',
		dependencies : [raylib_dep, sdl2_dep, sfml_dep],
		install : true
)