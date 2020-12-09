.DEFAULT_GOAL = ramses

memoria.o: ../src/memoria.cpp ../include/memoria.h
	g++ ../src/memoria.cpp -c
registradores.o: ../src/registradores.cpp ../include/registradores.h
	g++ ../src/registradores.cpp -c
ula.o: ../src/ula.cpp ../include/ula.h
	g++ ../src/ula.cpp -c

ramses: ramses.cpp memoria.o registradores.o ula.o
	g++ ramses.cpp memoria.o registradores.o ula.o -o ramses

clear: 
	rm *.o
	rm ramses