raylib_dep = dependency('raylib')
sdl2_dep = dependency('sdl2')
sfml_dep = dependency('sfml-all')


shared_library('raylib',
			'Raylib.cpp',
			dependencies : raylib_dep,
			install : true
)

shared_library('sdl2',
			'SDL.cpp',
			dependencies : sdl2_dep,
			install : true
)

shared_library('sfml',
			'SFML.cpp',
			dependencies : sfml_dep,
			install : true
)