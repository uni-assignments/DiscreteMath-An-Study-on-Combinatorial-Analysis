CC=gcc
CFLAGS=-Wall -Wextra
EXEC=./discreta
TMPOUT=discreta.testresult

$(EXEC): ceasars_legions.cpp ceasars_legions.o
	$(CC) $(CFLAGS) ceasars_legions.cpp ceasars_legions.o -o $(EXEC)

ceasars_legions.o: ceasars_legions.cpp 
	$(CC) $(CFLAGS) -c ceasars_legions.cpp -o ceasars_legions.o

test: $(EXEC)
	@bash ./run_tests.sh $(EXEC) $(TMPOUT)

clean: # remove todos os arquivos temporarios que forem gerados pela compilacao
	rm -rf ceasars_legions.o
	rm -rf ceasars_legions
	rm -rf ceasars_legions.testresult
