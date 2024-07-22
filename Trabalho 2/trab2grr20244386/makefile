parametrosCompilacao=-Wall -Wextra -Wshadow
nomePrograma=trab2grr20244386

all: $(nomePrograma)

$(nomePrograma): main.o auxiliar.o ordenacao.o pilha.o
	gcc -g -o $(nomePrograma) main.o auxiliar.o ordenacao.o pilha.o $(parametrosCompilacao)

main.o: main.c
	gcc -g -c main.c $(parametrosCompilacao)

auxiliar.o: auxiliar.h auxiliar.c
	gcc -g -c auxiliar.c $(parametrosCompilacao)

ordenacao.o: ordenacao.h ordenacao.c
	gcc -g -c ordenacao.c $(parametrosCompilacao)

pilha.o: pilha.h pilha.c
	gcc -g -c pilha.c $(parametrosCompilacao)

clean:
	rm -f *.o *.gch $(nomePrograma)
