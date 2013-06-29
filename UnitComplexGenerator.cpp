

#include <iostream>
#include <fstream>
#include <vector>


using std::pair;
using std::endl;
using std::ofstream;
using std::vector;


struct __Object
{
public:

  __Object() { }
  virtual ~__Object() { }

public:

  virtual void GenerateClassHeader( ofstream &o ) const = 0;

};


struct __Type : __Object
{

  char __T;

public:

  __Type( char ___T ) : __T( ___T ) { }
  virtual ~__Type() { }

public:

  void GenerateClassHeader( ofstream &o ) const;

};

struct __Simplifier
{

  char __E;
  __Object const &__T;

public:

  __Simplifier( __Object const &___T ) : __T( ___T ) { }
  ~__Simplifier() { }

public:

  void GenerateClassHeader( ofstream & ) const;

};


struct __ProductSimplifier : __Object
{

  __Simplifier __L;
  __Simplifier __R;

public:

  __ProductSimplifier(   __Simplifier const &___L, __Simplifier const &___R ) :
    __L( ___L ),
    __R( ___R )
    { }

  virtual ~__ProductSimplifier() { }


public:

  void GenerateClassHeader( ofstream & ) const;

};

typedef vector<pair<char,char> > PairCharVector;
typedef vector<PairCharVector> PairCharVectorVector;


struct __TemplateBody
{
  
  PairCharVector __T;

public:

  __TemplateBody( PairCharVector const &___T ) : __T( ___T ) { }
  ~__TemplateBody() { }

public:

  void Generate( ofstream & ) const;

};


void __Type::GenerateClassHeader( ofstream &o ) const
{
  o << __T;
}

void __Simplifier::GenerateClassHeader( ofstream &o ) const
{
  o << "Simplifier<";
  __T.GenerateClassHeader( o );
  o << ',' << __E << ">";
}

void __ProductSimplifier::GenerateClassHeader( ofstream &o ) const
{
  __L.GenerateClassHeader( o );
  __R.GenerateClassHeader( o );
}

void __TemplateBody::Generate( ofstream &o ) const
{
  o << "template<";

  for( int i = 0; i < __T.size(); ++i )
    o << "typename " << __T[i].first << ", ";

  for( i = 0; i < __T.size() - 1; ++i )
    o << "Integer " << __T[i].second << ", ";

  o << "Integer " << __T.back().second << '>';


  o << "class ProductSimplifier<";


}

PairCharVector GenerateType( int level, int currentlevel )
{

  return PairCharVector();
}

PairCharVector GenerateExponent( int level )
{

  return PairCharVector();
}

PairCharVectorVector GenerateType( int level )
{

  return PairCharVectorVector();
}


void GenerateUnitComplex( int maxLevel )
{

  


}
