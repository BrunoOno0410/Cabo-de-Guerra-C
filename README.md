# Jogo de cabo de guerra

Este é um jogo de cabo de guerra simples que pode ser jogado por duas equipes. Cada equipe tem um número de jogadores, que são representados pelas variáveis `q1` e `q2`. A posição da corda é representada pela variável `p`.

O código começa inicializando as variáveis e criando um mutex. Em seguida, entra em um loop onde cria novas threads para cada equipe. O número de threads criadas depende dos valores de `q1` e `q2`.

As threads de cada equipe, em seguida, entram em um loop onde elas decrementam `p` ou incrementam `p`, respectivamente. Quando `p` chega a 0 ou 73, a equipe correspondente vence o jogo.

O código também inclui uma função chamada `usleep`, que é usada para criar um atraso entre cada iteração do loop. Isso é feito para tornar o jogo mais realista.

O código é bem organizado e fácil de entender. Ele usa uma variedade de construções de programação C, incluindo variáveis, loops, funções e threads.

Aqui está uma breve explicação de cada função:

* `proinicio`: Esta função é chamada pela thread da equipe ProInicio. Ela decrementa `p` e atualiza o array `cabo`.
* `profim`: Esta função é chamada pela thread da equipe Profim. Ela incrementa `p` e atualiza o array `cabo`.
* `main`: Esta é a função principal do programa. Ela inicializa as variáveis, cria as threads e entra no loop principal.

