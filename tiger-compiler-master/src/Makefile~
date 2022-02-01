p: teste


teste: compilar
	./analisador.run teste.tig


testes: compilar
	for i in `ls -1 testes` ; do echo "<<<<prog $$i>>>>" ; ./analisador.run testes/$$i ; echo "" ; done

clean:
	rm -rf *.o y.tab* lex.yy* *.run *.output


yacc: 
	yacc -d tiger_grm.y

lex:
	lex tiger_lex.l

compilar: lex yacc
	gcc -g -Wall *.c -o analisador.run



ajuda:
	@echo "\n\tTP1 parte 3 - Compiladores I - UFMG 2021/2"
	@echo "\n\tNomes: Breno Pimenta, Lécio Alves"
	@echo "\tAnalisador Sintático\n"
	@echo "\tForma de uso:"
	@echo "\tmake [targets]\n"
	@echo "\tLista de targets:"
	@echo "\t\t: Mostrar esta ajuda"
	@echo "\tteste\t: Executar o analisador em \"teste.tig\""
	@echo "\tyacc\t: Gera e compila o analisador"
	@echo "\ttestes\t: Executar todos os testes na pasta testes"
	@echo "\tclean\t: Remove arquivos\n"


