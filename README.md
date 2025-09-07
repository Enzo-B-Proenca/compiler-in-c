# Compilador de Mini Pascal

## Especificações léxicas

### Palavras reservadas
- program 
- begin 
- end
- procedure
- if
- then
- else
- while
- do
- and
- or
- not
- var
- integer
- boolean
- true
- false
- write

### Operadores
- \+ 
- \- 
- div
- \*
- and
- or
- not
- <
- \> 
- <>
- <=
- \>=
- :=

### Delimitadores
- (
- )
- ,
- .
- :
- ;

### Tipos de Dados

- **Numerais**: Inteiros (tipo integer)
- **Booleano**: False | True (tipo boolean)

### Comentários

```c
/* comentário */
```

### Variáveis
- Podem ser criados com caracteres alfanuméricos e o caractere ‘\_’. Um identificador não pode começar
com um número, ou seja, é iniciado por uma letra ou ‘\_’ e é seguido de zero ou mais letras, dígitos ou ‘\_’
```c 
Value
company_number

12Val /* inválido */
Ex$ /* inválido */
company-name /* inválido */
```
## Token -> Exp. regulares

#### **Legenda**
e = vazio <br>
**letras_em_negrito**: termo final ou para não confundir com caracteres especiais do regex. Ex: **(** **)** são parênteses que fazem parte da expressão, e não são os mesmos () de quando montamos grupos no regex.<br>
()* -> nenhuma ou mais ocorrências

token | regex
| - | -|
**Números e identificadores**
letra | [a-z \| A-z \| _ ]
digito | [0-9]
bool | true\|false
ID | \<letra>( \<letra> \| \<digito>)*
numero | \<digito>  (\<digito>)*
**Expressões**|
var | \<ID>
exp.simples | [+\|-\|e] \<termo> ( [+\|-\|e] \<termo>)* 
fator | \<var> \| \<numero> \| \<bool> \| (\<exp.simples>)
termo | \<fator> ([* \| div] \<fator>)*
relacao | = \| <> \| < \| <= \| >= \| >
exp | \<exp.simples>[\<relacao>\<exp.simples>\|e]
**Comandos**
args_funcao | [**(**\<ID>\|\<numero>\|\<bool>**)**(**,** **(**\<ID>\|\<numero>\|\<bool>**)** )*\| e] -> ficou confuso, mas quer   dizer ou nenhum argumento, ou apenas um, ou vários separados por vírgula, estando todos eles dentro de ()
funcao | \<ID> **(**\<args_funcao>**)**
atribuicao | \<var> **:=** \<exp>
loop | **while** **(**\<exp>**)** **do** \<comando>
if | **if** **(**\<exp>**)** **then** \<comando> [**else** \<comando> \| e]
comando_composto | **begin** \<comando> ( **;**\<comando> )* **end**
comando | \<atribuicao> \| \<funcao> \| \<comando_composto>  \| \<if> \| \<loop> \| **write(**\<ID>**)**
**Declarações**
tipo | **integer** \| **boolean**
lista_IDs | \<ID> (**,**\<ID>)*
declaracao_vars |  \<lista_IDs> **:** \<tipo>
secao_declaracao_vars |**var** \<declaracao_vars> (**;** \<declaracao_vars>)* **;**
declaracao_funcao | **procedure** \<ID> [\<params_funcao>\|e] **;** \<bloco> -> \<bloco> está definido na próxima seção
secao_declaracao_funcoes | (\<declaracao_funcao>**;**)*
secao_params_funcao | [**var**\|e] \<lista_IDs> **:** \<tipo>
params_funcao |**(**\<secao_params_funcao> (**,**\<secao_params_funcao>)* **)** -> semelhante ao args_funcao
**Principais**
bloco | [\<secao-declaracao_vars>\|e]   [\<secao_declaracao_funcoes>\|e] \<comando_composto>
programa | **program** \<ID> **;** \<bloco>**.**

## Token -> Gramática Livre de Contexto (GLC)
Nesse primeiro momento, vou inserir só os mais complexos. Sendo assim, os que são iguais ao regex, deixarei para colocar depois.

Auxliares:
- \<A>(letras) -> \<letra>\<A> \| e 
- \<D>(dígitos) -> \<digito>\<D> \| e 
- \<An>(alfanuméricos) -> \<A>\<An> | \<D>\<An>
- \<S>(sinais) -> +\<S> | -\<S> \| e
- \<Md>(mult/div) -> (**\*** | div)\<fator>\<Md> \| e
- \<B>(ops. booleanas) -> \<relacao>\<exp.simples> \| e
- \<Args> (Outros argumentos) -> **,** **(**\<ID>\|\<numero>\|\<bool>**)**\<Args> \| e
- \<IDs> (outros IDs) -> **,**\<ID>\<IDs> \| e
- \<Vars> (outras variávies) -> **;** \<declaracao_vars>\<Vars> \| e 
- \<Params> (Outros parâmetros) -> **,**<secao_params_funcao>\<Params> \| e


token | GLC
| - | - |
ID | \<ID> -> \<letra>\<An>
numero | <numero> -> \<digito>\<D>
termo | \<termo> -> \<fator> \<Md>
exp.simples | \<exp.simples> -> \<S>\<termo>\<exp.simples> \| e
exp | \<exp> -> \<exp.simples> \<B>
args_funcao | \<args_funcao> -> **(**\<ID>\|\<numero>\|\<bool>**)**\<Args>
lista_IDs | \<lista_IDs> -> \<ID>\<IDs>
secao_declaracao_vars | \<secao_declaracao_vars> -> **var** \<declaracao_vars>\<Vars>
secao_declaracao_funcoes | \<secao_declaracao_funcoes> -> \<declaracao>**;**\<secao_declaracao_funcoes> \| e
params_funcao | \<params_funcao> -> **(**\<secao_declaracao_funcoes>\<Params>**)**



