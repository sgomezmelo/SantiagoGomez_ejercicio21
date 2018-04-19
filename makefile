PDE.pdf: datos.txt grafica.py
	python grafica.py
datos.txt: adveccion.cpp
	c++ adveccion.cpp
	./a.out > datos.txt
	rm a.out
