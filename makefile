all:
	g++ -std=c++11 -g -DSFML_STATIC *.cpp -L . -l sfml-graphics-s-d -l sfml-window-s-d -l sfml-system-s-d -lSDL -lfreetype -lGL -lGLEW -lxcb -lX11 -lXrandr -lX11-xcb -lpthread -ljpeg -lGLU -lsndfile -lm -lopenal -lxcb-randr -ludev -lxcb-image -lpthread -I ../SFML-2.3.2/include/ -o ok
ex:
	g++ -std=c++11 -g -DSFML_STATIC test.c -L . -l sfml-graphics-s-d -l sfml-window-s-d -l sfml-system-s-d -lSDL -lfreetype -lGL -lGLEW -lxcb -lX11 -lXrandr -lX11-xcb -lpthread -ljpeg -lGLU -lsndfile -lm -lopenal -lxcb-randr -ludev -lxcb-image -lpthread -I ../SFML-2.3.2/include/ -o ok
main:
	g++ -std=c++11 -g -DSFML_STATIC main.cpp about.cpp economy.cpp recipe.cpp product.cpp save.cpp n2s.cpp -L . -l sfml-graphics-s-d -l sfml-window-s-d -l sfml-system-s-d -lSDL -lfreetype -lGL -lGLEW -lxcb -lX11 -lXrandr -lX11-xcb -lpthread -ljpeg -lGLU -lsndfile -lm -lopenal -lxcb-randr -ludev -lxcb-image -lpthread -I ../SFML-2.3.2/include/ -o ok
