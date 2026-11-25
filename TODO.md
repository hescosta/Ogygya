TODO:
1. Ajeitar o mapa (ele está desenhado na vertical)
2. Desenhar os diferentes elementos do mapa

-----

O que deve ser feito? Basicamente tudo...

Temos que começar pelo início: o mapa (matriz)

Não precisamos nos preocupar com menu e outros detalhes agora, depois podemos implementa-los. O mais importante é a logica basica do jogo, que se baseia em elementos interagindo num mapa, numa matriz.

#1. Fazer uma mapa no raylib com matrizes

O raylib parece não ter uma maneira padrão de construir uma grade de células, portanto devemos utilizar uma matriz pra representar a grade e o estado de cada célula, e utilizar o raylib para fazer uma representação gŕafica dessa grade. 


####Update!

Já fiz o main.c ler um arquivo de texto (mapa.txt) e desenhar o mapa na tela.
O problema é que o mapa está na vertical, e ainda não descubri o porquê...
