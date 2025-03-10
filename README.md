/*
   Simulação de uma rede social onde os usuarios podem ser registrar
   livremente e estabelecer relacionamentos de amizades uns com os 
   outros.
   
   Os usuários tem seus nomes armazenados em um vetor unidimensional.
   
   Os relacionamentos são registrados em uma matriz de adjacências 
   (como um grafo).
   
   Assim, por exemplo, um usuário de nome "Asdrúbal" é registrado na
   posição 0 do vetor usuarios. "Jambira" é registrada na posição 1 
   do mesmo vetor.
   
   A relação de amizade entre ambos é representada por um valor 1 na
   matriz relacionamentos (linha 0 e coluna 1) e também por um valor
   1 na linha 1 e coluna 0.
   
   Afinal, se Asdrúbal é amigo de Jambira também é verdade que Jambira
   é igualmente amiga de Asdrúbal.
   
   Usuário inicialmente é um vetor de 4 posições e relacionamentos é uma
   matriz 4 X 4.
   
   Caso seja necessário cadastrar um quinto usuário, tanto o vetor quanto 
   a matriz deverão ser ampliados dinâmicamente. O vetor usuário possuirá
   5 posições e a matriz relacionamentos será de dimensão 5 x 5.
   
   20-02-2025 (quarta-feira).
   
*/
