
DIGIT [0-9]
BOOL  [True|False]
HEX   0[x|X][DIGIT|a-f|A-F]+
SCI   E[+][DIGIT]+
FLOAT [+|-]?(DIGIT+[.])?[DIGIT]+
STR   ["][.^"]["]
%%


>=|<=|>|<|==|!=|=		return "OP_REL";

&&|!				return "OP_LOG";
||				return "OP_LOG";
+|-|/|*|%			return "OP_ALG";
;|,|.|[|]|{|}|(|)		return "SIMBOL";
{DIGIT}|{HEX}                   return "INT";	
{BOOL}                          return "BOOLEAN";			
{FLOAT}                         return "FLOAT";
























%%
