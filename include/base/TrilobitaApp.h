#ifndef TRILOBITAAPP_H
#define TRILOBITAAPP_H

#include "MooseApp.h"

class TrilobitaApp;

template<>
InputParameters validParams<TrilobitaApp>();

class TrilobitaApp : public MooseApp
{
public:
  TrilobitaApp(InputParameters parameters);
  virtual ~TrilobitaApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* TRILOBITAAPP_H */
