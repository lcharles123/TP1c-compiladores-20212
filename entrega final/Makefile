p: ajuda

teste: compilar
	./analisador.run testes/teste.tig

testes: compilar
	for i in `ls -1 testes` ; do echo "<<<<prog $$i>>>>" ; ./analisador.run testes/$$i ; echo "" ; done

clean:
	rm -rf *.o tiger.tab* lex.yy* y.tab.* *.run *.output


yacc: 
	#yacc -v tiger.y 
	yacc -d tiger.y 
lex:
	lex tiger.l

compilar: lex yacc
	gcc -g -Wall tabela.c absyn.c lex.yy.c y.tab.c imprimir.c -o analisador.run



ajuda:
	@echo "\n\tTP1 parte 3 - Compiladores I - UFMG 2021/2"
	@echo "\n\tNomes: Breno Pimenta, Lécio Alves"
	@echo "\tCompilador com Analisadores sintático e semântico.\n"
	@echo "\tForma de uso:"
	@echo "\tmake [targets]\n"
	@echo "\tLista de targets:"
	@echo "\t\t: Mostrar esta ajuda"
	@echo "\tteste\t: Executar o analisador em \"teste.tig\""
	@echo "\tyacc\t: Gera e compila o analisador"
	@echo "\ttestes\t: Executar todos os testes na pasta testes"
	@echo "\tclean\t: Remove arquivos\n"


