# Compilador de Mini Pascal


## Token -> Exp. regulares

#### **Legenda**
e = vazio <br>
**letras_em_negrito**: termo final ou para não confundir com caracteres especiais do regex. Ex: **(** **)** são parênteses que fazem parte da expressão, e não são os mesmos () de quando montamos grupos no regex.<br>
()* -> nenhuma ou mais ocorrências

token | regex
| - | -|
**Numeros e identificadores**
letra | [a-z \| A-z \| _ ]
digito | [0-9]
bool | true\|false
ID | \<letra>( \<letra> \| \<digito>)*
numero | \<digito>  (\<digito>)*
**Expressoes**|
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
**Declaracoes**
tipo | **integer** \| **boolean**
lista_IDs | \<ID> (**,**\<ID>)*
declaracao_vars | **var** \<lista_IDs> **:** \<tipo>
secao_declaracao_vars | **var** \<declaracao_vars> (**;** \<declaracao_vars>)*
declaracao_funcao | **procedure** \<ID> [\<params_funcao>\|e] **;** \<bloco> -> Bloco está na próxima seção
secao_declaracao_funcoes | (\<declaracao_funcao>**;**)*
secao_params_funcao | [**var**\|e] \<lista_IDs> **:** \<tipo>
params_funcao |**(**\<secao_params_funcao> (**,**\<secao_params_funcao>)* **)** -> semelhante ao args_funcao
**Principais**
bloco | [\<secao-declaracao_vars>\|e]   [\<secao_declaracao_funcoes>\|e] \<comando_composto>
programa | **program** \<ID> **;** \<bloco>**.**

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




