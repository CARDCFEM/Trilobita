#include "TrilobitaApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<TrilobitaApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

TrilobitaApp::TrilobitaApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  TrilobitaApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  TrilobitaApp::associateSyntax(_syntax, _action_factory);
}

TrilobitaApp::~TrilobitaApp()
{
}

// External entry point for dynamic application loading
extern "C" void TrilobitaApp__registerApps() { TrilobitaApp::registerApps(); }
void
TrilobitaApp::registerApps()
{
  registerApp(TrilobitaApp);
}

// External entry point for dynamic object registration
extern "C" void TrilobitaApp__registerObjects(Factory & factory) { TrilobitaApp::registerObjects(factory); }
void
TrilobitaApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void TrilobitaApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { TrilobitaApp::associateSyntax(syntax, action_factory); }
void
TrilobitaApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
