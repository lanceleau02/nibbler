project('nibbler', 'cpp')

src = ['src/main.cpp', 'src/Raylib.cpp', 'src/SDL.cpp', 'src/SFML.cpp']

raylib_dep = dependency('raylib')
sdl_dep = dependency('sdl2')
sfml_dep = dependency('sfml-all')

inc = include_directories('include')

# subdir('include')
# subdir('src')

raylib = shared_library('raylib',
						'src/Raylib.cpp',
						include_directories: inc,
						install : true
)

executable('nibbler',
			sources : src,
			dependencies : [raylib_dep, sdl_dep, sfml_dep],
			include_directories : inc,
			link_with : raylib
)