parametrosCompilacao=-Wall -Wextra -Wshadow
nomePrograma=trab

all: $(nomePrograma)

$(nomePrograma): main.o ordenacao.o
	gcc -o $(nomePrograma) main.o ordenacao.o $(parametrosCompilacao)

main.o: main.c
	gcc -c main.c $(parametrosCompilacao)

ordenacao.o: ordenacao.h ordenacao.c
	gcc -c ordenacao.c $(parametrosCompilacao)

auxiliar.o: auxiliar.h auxiliar.c
	gcc -c auxiliar.c $(parametrosCompilacao)

clean:
	rm -f *.o *.gch $(nomePrograma)
