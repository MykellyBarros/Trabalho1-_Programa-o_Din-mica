# Trabalho de Programação Dinâmica: Maior Subsequência Comum (LCS)

## Descrição

Este repositório contém a implementação do algoritmo para calcular a **Maior Subsequência Comum (LCS)** entre duas strings, utilizando **Programação Dinâmica**. O trabalho está dividido em três partes, cada uma responsável por uma abordagem diferente para resolver o problema, como descrito a seguir.

### Objetivos do Trabalho
- Estudar e implementar o algoritmo para calcular a maior subsequência comum entre duas strings.
- Analisar a diferença entre a abordagem recursiva e a abordagem com programação dinâmica.
- Contabilizar o número de iterações e o tempo de execução de cada abordagem.

### Relatório do trabalho:
[Relatório](https://docs.google.com/document/d/1oCGSp3HqV8tisPUQg3DIExm9MA1UKGghy8l3I5QUiLA/edit?usp=sharing)

## Estrutura do Trabalho

### **Parte 1: Estudo e Análise do Problema LCS (Maior Subsequência Comum)** (Mykelly)

Esta parte envolve a pesquisa e descrição teórica do problema da Maior Subsequência Comum (LCS), incluindo:

1. **Descrição do Problema**:
   O problema consiste em encontrar a maior subsequência comum entre duas strings, onde os caracteres devem aparecer na mesma ordem, mas não precisam ser contíguos.

   **Exemplo**: Para as strings `S1 = "AGGTAB"` e `S2 = "GXTXAYB"`, a maior subsequência comum é `"GTAB"`, com comprimento 4.

2. **Casos do Problema**:
   Exemplos simples e mais complexos de LCS, como:
   - `S1 = "ABC"`, `S2 = "ABC"`, resposta: `"ABC"`.
   - `S1 = "ABCBDAB"`, `S2 = "BDCAB"`, resposta: `"BCAB"`.

3. **Algoritmo Recursivo (Força Bruta)**:
   Descrição da solução recursiva utilizando todas as combinações possíveis de subsequências, com exemplos detalhados.

4. **Algoritmo com Programação Dinâmica**:
   Explicação da abordagem de Programação Dinâmica, utilizando uma tabela `dp[i][j]` que armazena o comprimento da maior subsequência comum entre os prefixos de `S1` e `S2`.

   **Fórmula de transição**:

```java
if (S1[i-1] == S2[j-1]) dp[i][j] = dp[i-1][j-1] + 1; else dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
```
---

### **Parte 2: Implementação do Algoritmo Recursivo (Força Bruta)**

Esta parte foca na implementação da solução recursiva para o cálculo do LCS:

1. **Implementação da Função Recursiva**:
A função recursiva tenta todas as combinações possíveis de subsequências de `S1` e `S2` para encontrar a maior subsequência comum.

**Exemplo de função**:

```java
if (s1[i] == s2[j]) return 1 + lcs(s1, s2, i - 1, j - 1); else return max(lcs(s1, s2, i - 1, j), lcs(s1, s2, i, j - 1));
```

2. **Testes Simples**:
Testar strings curtas como `S1 = "ABC"` e `S2 = "ABC"`, e outros casos parcialmente comuns como `S1 = "ABCBDAB"` e `S2 = "BDCAB"`.

3. **Contabilização de Iterações e Tempo**:
Contabilizar o número de chamadas recursivas (iterações) e calcular o tempo de execução utilizando `System.currentTimeMillis()`.

Exibir o número de interações e o tempo total de execução no print final.

---

### **Parte 3: Implementação do Algoritmo com Programação Dinâmica**

A última parte envolve a implementação do algoritmo de LCS utilizando **programação dinâmica**, que é mais eficiente que a solução recursiva.

1. **Implementação com Programação Dinâmica**:
Usar uma tabela `dp` para armazenar os resultados dos subproblemas, onde `dp[i][j]` representa o comprimento da maior subsequência comum entre `S1[0..i-1]` e `S2[0..j-1]`.

Preencher a tabela conforme a fórmula de transição:

```java
if (S1[i-1] == S2[j-1]) dp[i][j] = dp[i-1][j-1] + 1; else dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
```

2. **Testes com Casos Simples e Complexos**:
Testar a implementação com os mesmos casos usados na versão recursiva, incluindo casos mais elaborados, como `S1 = "AGGTAB"` e `S2 = "GXTXAYB"`.

3. **Contabilização de Iterações e Tempo**:
Contabilizar o número de iterações e calcular o tempo de execução.

Exibir o número de interações e o tempo total de execução no final.
