#Autoria
[Matheus Alves de Andrade](https://github.com/MatheusAlvesA)
matheuseejam@hotmail.com

Link para o repositório no github: https://github.com/MatheusAlvesA/Projeto_Lista

#Introdução
Esse projeto foi proposto pelo porfessor da diciplina de Linguagem de programação 1
do curso de BTI da UFRN periodo 2016.1.
Aqui estão implemetadas algumas das classes mais importantes do stl; vector,
lista encadeada comum e lista duplamente encadeada.

#Como compilar
Um arquivo makefile está disponivel,
Para compilar o Vector use "make VECTOR"
Para compilar a Lista comum use "make LISTA"
Para compilar a Lista duplamente encadeada use "make DLISTA"
um executavel será gerado para cada compilação, estarão dentro da pasta bin/

#O que foi feito
As três classes foram implementadas e testadas de diversas formas, durante os testes erros foram corrigidos,
mas isso não garante que o programa esteja perfeito, podem existir erros remanecentes. Usar uniq_ptr é recomendavél
para um projeto que lide tão frequentemente com alocaçao dinâmica de memória e ponteiros, mas ele não foi usado,
ao invez disso a destrução dos objetos é feita manualmente pela função delete nativa do C++.