run : bin/tazo
		./bin/tazo

runMem : bin/mem
		./bin/mem

runAnimacion : bin/animacion
		./bin/animacion

runAanimacion : bin/Animacion
		./bin/Animacion

bin/tazo : src/main.cpp
	g++ src/main.cpp -Iinclude -o bin/tazo

bin/mem : src/memoria.cpp
	g++ src/memoria.cpp -Iinclude -o bin/mem

bin/animacion : src/canvas_animated.cpp
	g++ src/canvas_animated.cpp -Iinclude -o bin/animacion -std=c++2a -lftxui-screen -lftxui-dom -lftxui-component

bin/Animacion : src/prueba.cpp
	g++ src/prueba.cpp -Iinclude -o bin/Animacion -std=c++2a -lftxui-screen -lftxui-dom -lftxui-component

assets/mensaje : bin/tazo
	./bin/tazo > assets/mensaje
