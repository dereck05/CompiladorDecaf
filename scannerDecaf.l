
DIGIT [0-9]
HEX   0[x|X][DIGITa-fA-F]+

%%


>=|<=|>|<|==|!=|=		return "OP_REL";

&&|!				return "OP_LOG";
||				return "OP_LOG";
+|-|/|*|%			return "OP_ALG";
;|,|.|[|]|{|}|(|)		return "SIMBOL";				

























%%
