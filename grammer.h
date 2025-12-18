#define grammer_H
#define grammer_H

class grammer
{

private:
	
	

 public:
  TypeOfToken symbol;
  void CorrectGrammar(TypeOfToken t);
  void SyntaxError(TypeOfToken t);
  void StartSymbol();
  void stmt();
  void expr();
  void comp_stmt();
  void cond();
  grammer();
  ~grammer();

};

