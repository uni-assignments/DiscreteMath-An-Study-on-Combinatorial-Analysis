CC=gcc
EXEC=./discreta
TMPOUT=discreta.testresult

$(EXEC): ceasars_legions.c 
	$(CC) ceasars_legions.c  -o $(EXEC)

test: $(EXEC)
	@bash ./run_tests.sh $(EXEC) $(TMPOUT)

clean: # remove todos os arquivos temporarios que forem gerados pela compilacao
	rm -rf ceasars_legions.o
	rm -rf discreta
	rm -rf ceasars_legions.testresult
