# MelhoresQuestoesProva
### Problema:
 Considere que você precisa fazer uma avaliação com n questões numeradas por 1,2,…,n. Cada questão i vale pi pontos. Você deve responder as questões em ordem, mas é permitido "pular'' (não fazer) algumas questões. A razão que o levaria a essa 
 escolha é que embora você possa resolver a questão i e obter pi pontos, algumas questões são tão frustrantes que depois de resolvidas você não será capaz de resolver qualquer uma das fi questões seguintes. Suponha que você tenha os valores pi
 e fi para cada uma das n questões. O objetivo é escolher um conjunto de questões que maximize o total de pontos. 

Seja S(i) o total máximo de pontos que pode ser obtido nas questões i até n. Essa pontuação é obtida de um conjunto de questões que incluem ou não i; no primeiro caso, a melhor pontuação é pi+S(i+1+fi), no segundo caso, a melhor pontuação é S(i+1) com isso, o objetivo é computar S(1).

