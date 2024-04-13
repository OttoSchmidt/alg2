parametrosCompilacao=-Wall #-Wshadow
nomePrograma=trab

all: $(nomePrograma)

$(nomePrograma): main.o ordenacao.o
	gcc -g -o $(nomePrograma) main.o ordenacao.o $(parametrosCompilacao)

main.o: main.c
	gcc -g -c main.c $(parametrosCompilacao)

ordenacao.o: ordenacao.h ordenacao.c
	gcc -g -c ordenacao.c $(parametrosCompilacao)

clean:
	rm -f *.o *.gch $(nomePrograma)
