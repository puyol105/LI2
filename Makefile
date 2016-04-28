CFLAGS= -Wall -Wextra -ansi -pedantic -O2
OBJS=$(patsubst %.c,%.o,$(wildcard *.c))

prot:$(OBJS)
		$(CC) $(CFLAGS) -o prot $(OBJS) $(LIBS)

doc:$(OBJS)
		doxygen

limpar:
	rm prot *.o

remover:
	rm -r html
	rm -r latex

pdf:
	pdflatex relatorio.tex