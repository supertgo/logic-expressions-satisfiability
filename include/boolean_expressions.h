#include <string>
#ifndef BOOL_EXPR
#define BOOL_EXPR


/**
 * Determinar a precedência de um operador lógico.
 *
 * Atribui um valor numérico a 'op' representando sua precedência.
 * - '||' (disjunção) recebe uma precedência de 1.
 * - '&&' (conjunção) recebe uma precedência de 2.
 * - '!' (negação) recebe uma precedência de 3.
 * Operadores desconhecidos retornam 0.
 *
 * @param op O operador a ser avaliado.
 * @return Um valor não assinado representando a precedência do operador.
 */
unsigned int precedence(char op);

/**
 * Aplicar um operador lógico a dois valores inteiros.
 *
 * Esta função aplica um operador lógico a dois valores inteiros 'a' e 'b'
 * com base no operador especificado ('op'). Ela retorna o resultado da
 * operação.
 *
 * @param a O primeiro valor inteiro.
 * @param b O segundo valor inteiro.
 * @param op O operador lógico a ser aplicado ('||' para disjunção, '&&' para
 * conjunção, '!' para negação).
 * @return O resultado da operação com o operador especificado:
 *         - Se 'op' for '||' (disjunção), a função retorna 'a || b'.
 *         - Se 'op' for '&&' (conjunção), a função retorna 'a && b'.
 *         - Se 'op' for '!' (negação), a função retorna '!a'.
 *         - Se 'op' for desconhecido, a função retorna -1.
 */
int applyOp(int a, int b, char op);

/**
 * Retorna o valor numérico de um caractere no padrão ASCII.
 *
 * Esta função recebe um caractere 'c' que representa um dígito no padrão ASCII
 * e retorna o valor numérico correspondente a esse dígito.
 *
 * @param c O caractere que representa um dígito no padrão ASCII.
 * @return O valor numérico correspondente ao dígito representado por 'c'.
 */
int returnASCIIDigit(const char c);

/**
 * Avaliar uma expressão lógica com valores fornecidos.
 *
 * Esta função recebe uma expressão lógica no formato de string 'expression'
 * e um conjunto de valores 'expression_values' para as variáveis da expressão.
 * Ela avalia a expressão lógica usando os valores fornecidos e retorna o
 * resultado.
 *
 * @param expression A expressão lógica a ser avaliada (por exemplo, "(0 & 1 |
 * 2").
 * @param expression_values Uma string contendo os valores das variáveis na
 * expressão no mesmo formato das variáveis (por exemplo, "1,0,1").
 * @return O resultado da avaliação da expressão lógica com os valores
 * fornecidos.
 *         - Retorna 1 para verdadeiro.
 *         - Retorna 0 para falso.
 *         - Retorna -1 em caso de erro, como expressão malformada ou valores
 * ausentes.
 */
int evaluate(const char *expression, const char *expression_values);

unsigned int
find_next_quantificator_pos_after_index(std::string expression, int index);
#endif // !DEBUG
