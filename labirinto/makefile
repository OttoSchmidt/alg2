parametrosCompilacao=-Wall -Wextra 
nomePrograma=labirinto

all: $(nomePrograma)

$(nomePrograma): main.o labirinto.o pilha.o
	gcc -g -o $(nomePrograma) main.o labirinto.o pilha.o $(parametrosCompilacao)

main.o: main.c
	gcc -g -c main.c $(parametrosCompilacao)

labirinto.o: labirinto.h labirinto.c
	gcc -g -c labirinto.c $(parametrosCompilacao)

pilha.o: pilha.h pilha.c
	gcc -g -c pilha.c $(parametrosCompilacao)

clean:
	rm -f *.o *.gch $(nomePrograma)
