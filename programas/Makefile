.DEFAULT_GOAL = risco

memoria.o: ../src/memoria.cpp ../include/memoria.h
	g++ ../src/memoria.cpp -c
registradores.o: ../src/registradores.cpp ../include/registradores.h
	g++ ../src/registradores.cpp -c
ula.o: ../src/ula.cpp ../include/ula.h
	g++ ../src/ula.cpp -c
funcoes.o: ../src/funcoes.cpp ../include/funcoes.h
	g++ ../src/funcoes.cpp -c

risco: risco.cpp memoria.o registradores.o ula.o funcoes.o
	g++ risco.cpp memoria.o registradores.o ula.o funcoes.o -o risco

clear: 
	rm *.o
	rm risco