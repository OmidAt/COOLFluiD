// Copyright (C) 2012 von Karman Institute for Fluid Dynamics, Belgium
//
// This software is distributed under the terms of the
// GNU Lesser General Public License version 3 (LGPLv3).
// See doc/lgpl.txt and doc/gpl.txt for the license text.

#ifndef COOLFluiD_Numerics_NewtonMethod_CrankNichIntermediate_hh
#define COOLFluiD_Numerics_NewtonMethod_CrankNichIntermediate_hh

//////////////////////////////////////////////////////////////////////////////

#include "NewtonIteratorData.hh"
#include "Framework/DataSocketSink.hh"

//////////////////////////////////////////////////////////////////////////////

namespace COOLFluiD {

  namespace Numerics {

    namespace NewtonMethod {

//////////////////////////////////////////////////////////////////////////////

  /// This class represents a NumericalCommand action to be
  /// sent to Domain to be executed in order to setup the MeshData.
  /// @author Andrea Lani
class CrankNichIntermediate : public NewtonIteratorCom {
public:

  /// Constructor.
  explicit CrankNichIntermediate(std::string name) :
    NewtonIteratorCom(name),
    socket_rhs("rhs"),
    socket_pastRhs("pastRhs")
  {
  }

  /// Destructor.
  ~CrankNichIntermediate()
  {
  }

  /// Execute Processing actions
  void execute();

  /// Returns the DataSocket's that this command needs as sinks
  /// @return a vector of SafePtr with the DataSockets
  virtual std::vector<Common::SafePtr<Framework::BaseDataSocketSink> > needsSockets();

protected:

  // socket for rhs
  Framework::DataSocketSink<CFreal> socket_rhs;

  // socket for past rhs
  Framework::DataSocketSink<CFreal> socket_pastRhs;

}; // class CrankNichIntermediate

//////////////////////////////////////////////////////////////////////////////

    } // namespace NewtonMethod

  } // namespace Numerics

} // namespace COOLFluiD

//////////////////////////////////////////////////////////////////////////////

#endif // COOLFluiD_Numerics_NewtonMethod_CrankNichIntermediate_hh

