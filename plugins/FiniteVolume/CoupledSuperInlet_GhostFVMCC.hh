#ifndef COOLFluiD_Numerics_FiniteVolume_CoupledSuperInlet_GhostFVMCC_hh
#define COOLFluiD_Numerics_FiniteVolume_CoupledSuperInlet_GhostFVMCC_hh

//////////////////////////////////////////////////////////////////////////////

#include "FiniteVolume/FVMCC_BC.hh"
#include "Framework/VectorialFunction.hh"
#include "Common/CFMap.hh"

//////////////////////////////////////////////////////////////////////////////

namespace COOLFluiD {

  namespace Numerics {

    namespace FiniteVolume {

//////////////////////////////////////////////////////////////////////////////

/**
 * This class represents a command to implement a
 * coupled boundary condition for a supersonic inlet (transfering face values
 * (using Ghost as type of data to transfer))
 *
 * @author Thomas Wuilbaut
 *
 */

class CoupledSuperInlet_GhostFVMCC : public FVMCC_BC {
public:

  /**
   * Defines the Config Option's of this class
   * @param options a OptionList where to add the Option's
   */
  static void defineConfigOptions(Config::OptionList& options);

  /**
   * Constructor
   */
  CoupledSuperInlet_GhostFVMCC(const std::string& name);

  /**
   * Default destructor
   */
  ~CoupledSuperInlet_GhostFVMCC();

  /**
   * Configuration of the command
   */
  virtual void configure ( Config::ConfigArgs& args );

  /**
   * Set up private data and data of the aggregated classes
   * in this command before processing phase
   */
  void setup();

  /**
   * Apply boundary condition on the given face
   */
  void setGhostState(Framework::GeometricEntity *const face);

  /**
   * Returns the DataSocket's that this command needs as sinks
   * @return a vector of SafePtr with the DataSockets
   */
  std::vector<Common::SafePtr<Framework::BaseDataSocketSink> > needsSockets();

 private: // data

  /// the dynamic sockets in this Command
  Framework::DynamicDataSocketSet<> _sockets;

  // name of the datahandle containing the nodal values
  std::string _interfaceName;

  // a vector of string to hold the functions
  std::vector<std::string> _functions;

  // a vector of string to hold the functions
  std::vector<std::string> _vars;

  // the VectorialFunction to use
  Framework::VectorialFunction _vFunction;

}; // end of class CoupledSuperInlet_GhostFVMCC

//////////////////////////////////////////////////////////////////////////////

    } // namespace FiniteVolume

  } // namespace Numerics

} // namespace COOLFluiD

//////////////////////////////////////////////////////////////////////////////

#endif // COOLFluiD_Numerics_FiniteVolume_CoupledSuperInlet_GhostFVMCC_hh
