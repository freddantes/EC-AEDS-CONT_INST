# ATIVIDADE CONTANDO INSTRUÇÕES

Olá Michel! Para a execução do arquivo, basta realizar aqueles passos do MakeFile - Make clean, make, make run. Estava fazendo com a implantação do .hpp e .cpp, porém como estava com dúvidas em relação à alocação dinâmica para a matriz, já que o n é variável, e como não foi falado se seria necessário fazer de outra forma, acabei implantando tudo no main mesmo, espero que esteja válido (Obs: Para a próxima lista já irei desconsiderar fazer dessa forma).

Abaixo segue o Relatório com as repostas às perguntas.

<h1>RELATÓRIO</h1>
<h3>Introdução</h3>
A atividade apresentada, tinha como objetivo avaliar a solução proposta ao problema, a fim de medir sua eficácia através do custo computacional incluso no processo. O problema solicitava que fosse gerado uma matriz de números aleatórios NxN, onde N seria introduzido pelo usuário. Após gerada a matriz, seria percorrido o caminho entre o início, elemento [0][0] da matriz, e o fim, elemento [n][n]. A condição para realizar este caminho é sempre a partir do maior valor que faça "fronteira" com o elemento atual, por exemplo, o segundo passo do caminho , que partiu do elemento [0][0], seria ou o [1][0] ou o [0][1]. As regras para as fronteiras são de que o elemento comparado pode estar à esquerda, à direita ou abaixo do elemento atual. Isso muda ao se atingir a linha[n] pois nesse caso o caminho deverá ser sempre para a direita pois não se pode voltar à uma linha superior.

<h3>Desenvolvimento</h3>
Para tal, foi implementado uma entrada no programa, em que usuário informa o valor de N. Com essa informação, é criada uma matriz mat[n][n], e utilizando-se de um laço duplo de for, essa matriz é preenchida com o auxílio da função rand() da biblioteca do C++. Feito isso, também é gerado uma matriz auxiliar chamada cam[n][n] e ela é preenchida com 0 em todos os seus elementos de cam[0][0] até cam[n][n].
Depois de criadas e preenchidas as matrizes, é hora de comparar os valores vizinhos, de modo a selecionar qual seria esse caminho a ser percorrido na matriz para chegar do início ao fim passando pelos maiores valores limítrofes. Para isso são realizadas as comparações, como existem regras diferentes para determinadas áreas da matriz, foi dividido em condicionantes a fim de instruir as regras corretas em cada altura da comparação.
<h4>COLUNA 0</h4>
linha < (n - 1) && coluna = 0:<br>
<img src=https://user-images.githubusercontent.com/85570101/126378619-c9e86d6c-25f5-442d-baf2-cc0c6b7574ec.png>
Aqui, a comparação só pode ser feita com o elemento à direita, ou o elemento abaixo, sendo assim a comparação será apenas com os elementos [i + 1][j] e [i][j + 1].
<h4>COLUNA (N - 1)</h4>
linha < (n - 1) && coluna = (n - 1):<br>
<img src=https://user-images.githubusercontent.com/85570101/126378940-1e871754-1876-46c6-b60c-5ac44fb429fa.png>
Aqui, a comparação só pode ser feita com o elemento à esquerda, ou o elemento abaixo, sendo assim a comparação será apenas com os elementos [i + 1][j] e [i][j - 1].
<h4>LINHA (N - 1)</h4>
linha = (n - 1):<br>
<img src=https://user-images.githubusercontent.com/85570101/126379443-a2a533d3-1449-4cd3-ab47-f39bc0d69ad3.png>
Aqui, a regra e prosseguir o caminho apenas caminhando para a direita, logo não haverá comparação e será considerado como próximo elemento o localizado em [i][j + 1].
<h4>COLUNA MAIOR QUE 0 E MENOR QUE (N - 1) E LINHA MENOR QUE (N - 1)</h4>
linha < (n - 1) && (n - 1) > colunha > 0:<br>
<img src=https://user-images.githubusercontent.com/85570101/126380221-4a918b93-499e-4e73-8cfd-cffc28de7401.png>
Aqui, será realizada a maior comparação, visto que existe a possibilidade de se andar para a direita, esquerda ou para baixo, logo iremos comparar [i + 1][j], [i][j + 1] e [i][j - 1].
<h3>Conclusão</h3>
Realizada a comparação entre os elementos o caminho é traçado considerando os maior valor limítrofe para continuar a sequencia, como foi gerada uma matriz com este caminho e os outros elementos zerados(0), basta realizar a soma dos elementos da matriz que teremos a soma do caminho adotado. Após realizada todas as funções necessárias para chegar ao resultado esperado, obtém-se através de contadores, incrementados durante os processos, a quantidade de vezes em que determinada instrução foi repetida, e é com eles que podemos chegar aos custos computacionais desse algoritmo.
<h4>Custos Computacionais</h4>
Para chegar à função que determina o algoritmo como um todo, devemos considerar as etapas, sendo assim foram:<br>
<ul>
  <li>Preencher Matriz: N(linhas) x N(colunas) => N² é o custo visto que serão preenchidas nxn elementos.</li>
  <li>Preencher Matriz Caminho: N(linhas) x N(colunas) => N² é o custo visto que serão preenchidas nxn elementos.</li>
  <li>Percorre caminho: Condicionantes que variam o N em 2xN, como ele para em [n][n] será de 2N - 1.</li>
  <li>Somar matriz: N(linhas) x N(colunas) => N² é o custo visto que serão preenchidas nxn elementos.</li>
  </ul>
  Com isso o custo computacional desse algoritmo seria 3N²  + 2N - 1.<br>
  

