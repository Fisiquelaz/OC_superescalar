Trabalho da segunda unidade de Organização de Computadores

/* operação | tipo_recebimento | reg destino | reg1 | reg2 */
/* operacao | tipo_recebimento | reg destino | constante | constante*/

4 bits | 1 bit | 5 bits | (5 bits | 5 bits)(5 bits | 5 bits)

/* operação | tipo_recebimento | endereco_memoria | reg destino/fonte */
/* operacao | tipo_recebimento | endereco_memoria | constante*/

4 bits | 1 bit | 8 bits | (5 bits)(7 bits)


/*
* Operações:
* 0000 -> NOP
* 0001 -> STR
* 0010 -> LDR
* 0011 -> ADD
* 0100 -> SUB
* 0101 -> OR
* 0110 -> AND
* 0111 -> NOT
* 1000 -> XOR
* 1001 -> NEG
* 1010 -> SHR
* 1011 -> SHL
*/

/*
* Tipos de recebimento:
* 0 -> registrador
* 1 -> constante
*/