Trabalho de Programação Dinâmica: Maior Subsequência Comum (LCS)
Descrição
Este repositório contém a implementação do algoritmo para calcular a Maior Subsequência Comum (LCS) entre duas strings, utilizando Programação Dinâmica. O trabalho está dividido em três partes, cada uma responsável por uma abordagem diferente para resolver o problema, como descrito a seguir.

Objetivos do Trabalho
Estudar e implementar o algoritmo para calcular a maior subsequência comum entre duas strings.

Analisar a diferença entre a abordagem recursiva e a abordagem com programação dinâmica.

Contabilizar o número de iterações e o tempo de execução de cada abordagem.

Estrutura do Trabalho
Parte 1: Estudo e Análise do Problema LCS (Maior Subsequência Comum)
Esta parte envolve a pesquisa e descrição teórica do problema da Maior Subsequência Comum (LCS), incluindo:

Descrição do Problema:

O problema consiste em encontrar a maior subsequência comum entre duas strings, onde os caracteres devem aparecer na mesma ordem, mas não precisam ser contíguos.

Exemplo: Para as strings S1 = "AGGTAB" e S2 = "GXTXAYB", a maior subsequência comum é "GTAB", com comprimento 4.

Casos do Problema:

Exemplos simples e mais complexos de LCS, como:

S1 = "ABC", S2 = "ABC", resposta: "ABC".

S1 = "ABCBDAB", S2 = "BDCAB", resposta: "BCAB".

Algoritmo Recursivo (Força Bruta):

Descrição da solução recursiva utilizando todas as combinações possíveis de subsequências, com exemplos detalhados.

Algoritmo com Programação Dinâmica:

Explicação da abordagem de Programação Dinâmica, utilizando uma tabela dp[i][j] que armazena o comprimento da maior subsequência comum entre os prefixos de S1 e S2.

A fórmula de transição é:

java
Copiar
if (S1[i-1] == S2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
else dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
Exemplificação do algoritmo com uma tabela de exemplo.

Parte 2: Implementação do Algoritmo Recursivo (Força Bruta)
Esta parte foca na implementação da solução recursiva para o cálculo do LCS:

Implementação da Função Recursiva:

A função recursiva tenta todas as combinações possíveis de subsequências de S1 e S2 para encontrar a maior subsequência comum.

Exemplo de função:

java
Copiar
if (s1[i] == s2[j]) return 1 + lcs(s1, s2, i - 1, j - 1);
else return max(lcs(s1, s2, i - 1, j), lcs(s1, s2, i, j - 1));
Testes Simples:

Testar strings curtas como S1 = "ABC" e S2 = "ABC", e outros casos parcialmente comuns como S1 = "ABCBDAB" e S2 = "BDCAB".

Contabilização de Iterações e Tempo:

Contabilizar o número de chamadas recursivas (iterações) e calcular o tempo de execução utilizando System.currentTimeMillis().

Exibir o número de interações e o tempo total de execução no print final.

Parte 3: Implementação do Algoritmo com Programação Dinâmica
A última parte envolve a implementação do algoritmo de LCS utilizando programação dinâmica, que é mais eficiente que a solução recursiva.

Implementação com Programação Dinâmica:

Usar uma tabela dp para armazenar os resultados dos subproblemas, onde dp[i][j] representa o comprimento da maior subsequência comum entre S1[0..i-1] e S2[0..j-1].

Preencher a tabela conforme a fórmula de transição:

java
Copiar
if (S1[i-1] == S2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
else dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
Testes com Casos Simples e Complexos:

Testar a implementação com os mesmos casos usados na versão recursiva, incluindo casos mais elaborados, como S1 = "AGGTAB" e S2 = "GXTXAYB".

Contabilização de Iterações e Tempo:

Contabilizar o número de iterações e calcular o tempo de execução.

Exibir o número de interações e o tempo total de execução no final.

Como Usar
1. Clonando o Repositório:
Para começar, clone o repositório utilizando o comando abaixo:

bash
Copiar
git clone https://github.com/usuario/repo.git
2. Compilação e Execução:
Compile o código:

bash
Copiar
javac DistanciaEdicao.java
Execute o programa:

bash
Copiar
java DistanciaEdicao
O programa calculará a Maior Subsequência Comum entre duas strings e exibirá o número de iterações e o tempo de execução para cada abordagem (recursiva e com programação dinâmica).

Arquivos do Projeto
DistanciaEdicaoRecursivo.java: Implementação recursiva (força bruta).

DistanciaEdicao.java: Implementação com programação dinâmica.

README.md: Este arquivo.
