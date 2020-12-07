.DEFAULT_GOAL = superescalar

memoria.o: ../src/memoria.cpp ../include/memoria.h
	g++ ../src/memoria.cpp -c
registradores.o: ../src/registradores.cpp ../include/registradores.h
	g++ ../src/registradores.cpp -c
ula.o: ../src/ula.cpp ../include/ula.h
	g++ ../src/ula.cpp -c
funcoes.o: ../src/funcoes.cpp ../include/funcoes.h
	g++ ../src/funcoes.cpp -c

superescalar: superescalar.cpp memoria.o registradores.o ula.o funcoes.o
	g++ superescalar.cpp memoria.o registradores.o ula.o funcoes.o -o superescalar

clear: 
	rm *.o
	rm superescalar