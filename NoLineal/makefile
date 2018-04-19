PDE.pdf: datos.txt grafica.py
	python grafica.py
datos.txt: adveccion_nl.cpp
	c++ adveccion_nl.cpp
	./a.out > datos.txt
	rm a.out
