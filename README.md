# Projeto: Implementação de Vetores Dinâmicos

## Introdução
Este projeto foi desenvolvido como parte do trabalho de Algoritmos do curso de TADS no IFRN - CNAT - DIATINF. O objetivo é implementar uma biblioteca de classes para manipulação de vetores dinâmicos de números inteiros, utilizando duas abordagens diferentes: alocação dinâmica de arrays e listas duplamente ligadas.

## Vetores Dinâmicos
Vetores dinâmicos são estruturas de dados que permitem redimensionamento automático conforme a quantidade de elementos inseridos ou removidos. Eles são amplamente utilizados em várias linguagens de programação devido à sua flexibilidade e eficiência.

## Implementação
O projeto está organizado nas seguintes seções:

### 03.01 - Organização dos arquivos fontes
Os arquivos fontes estão organizados em diretórios específicos para cada tipo de implementação.

### 03.02 - Arrays com alocação dinâmica
Implementação de um vetor dinâmico utilizando arrays com alocação dinâmica, com três políticas de crescimento diferentes.

### 03.03 - Lista ligada
Implementação de um vetor dinâmico utilizando uma lista duplamente ligada.

### 04 - Testes
Casos de testes desenvolvidos para verificar a corretude e desempenho das implementações. Os testes incluem inserção, remoção e busca de elementos em diferentes posições do vetor.

## 05. Resultados
Os resultados dos testes são apresentados em forma de tabelas e gráficos, mostrando o desempenho de cada abordagem em termos de tempo de execução e uso de memória.

## 06. Conclusão
Uma análise comparativa entre as implementações é feita, indicando as vantagens e desvantagens de cada uma, bem como recomendações sobre quando utilizar cada abordagem.

## Como executar os testes
Para compilar e executar os testes, siga as instruções abaixo:

1. Clone este repositório:
    ```sh
    git clone https://github.com/luuiizf/Vetor_Dinamico_Algoritmos.git
    cd Vetor_Dinamico_Algoritmos
    ```

2. Compile os arquivos de teste:
    ```sh
    g++ -o test-pushfront-array-list-01 test-pushfront-array-list-01.cpp
    g++ -o test-pushfront-linked-list-01 test-pushfront-linked-list-01.cpp
    g++ -o test-removeat-array-list-01 test-removeat-array-list-01.cpp
    g++ -o test-removeat-linked-list-01 test-removeat-linked-list-01.cpp
    ```

3. Execute os testes:
    ```sh
    ./test-pushfront-array-list-01
    ./test-pushfront-linked-list-01
    ./test-removeat-array-list-01
    ./test-removeat-linked-list-01
    ```

## Relatório
O relatório detalhado do trabalho está disponível no arquivo `Trabalho de Algoritmos - Vetor dinâmico.pdf` presente neste repositório. Ele contém explicações detalhadas sobre as implementações, os métodos utilizados, os casos de testes e os resultados obtidos.

---

IFRN - CNAT - DIATINF - TADS Algoritmos - 2024.1
