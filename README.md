Busca-Pelo-Vizinho-Mais-Proximo
===============================

    Busca-Pelo-Vizinho-Mais-Proximo
    
Uma estratégia possível é a busca pelo vizinho mais próximo. Neste
caso, escolhemos a cada passo o vizinho ainda não visitado que apresente
o menor custo (não devemos repetir cidades, sob o risco de introduzir
ciclos, como nas buscas não ponderadas).
Esta estratégia equivale à busca irrevogável e, portanto, não garante
encontrar um caminho, muito menos o de menor custo.

Para este exemplo foi usado um arquivo .txt, que é especificado da seguinte forma :

1     este é o nó inicial.
4      este é o no final.
10      essa é a quantidade de linha que vem a seguir.
1 2 3    o primeiro  numero é o no de partida, o segundo é o no vizinho e o 3º numero é o custo dele
1 3 7           ||
1 3 8           ||
2 3 4           ||
2 8 6           ||
3 2 5           ||
3 3 8           ||
3 7 9           || 
3 6 4           ||
3 5 2           ||
