#include "SpectralFVBaseFunctionTetraP0.hh"

//////////////////////////////////////////////////////////////////////////////

namespace COOLFluiD {

  namespace SpectralFV {

//////////////////////////////////////////////////////////////////////////////

CFuint SpectralFVBaseFunctionTetraP0::_interpolatorID = 0;

//////////////////////////////////////////////////////////////////////////////

SpectralFVBaseFunctionTetraP0::SpectralFVBaseFunctionTetraP0()
{
}

//////////////////////////////////////////////////////////////////////////////

void SpectralFVBaseFunctionTetraP0::computeFaceJacobianDeterminant(
        const std::vector<RealVector>& m_mappedCoord,
        const std::vector<Framework::Node*>& nodes,
        const Framework::IntegratorPattern& pattern,
              std::vector<RealVector>& faceJacobian)
{
    throw Common::ShouldNotBeHereException (FromHere(),"Spectral finite volume base functions should not be used as geometrical shape functions.");
}

//////////////////////////////////////////////////////////////////////////////

RealVector SpectralFVBaseFunctionTetraP0::computeMappedCoordinates(const RealVector& coord,
                                    const std::vector<Framework::Node*>& nodes)
{
  throw Common::ShouldNotBeHereException (FromHere(),"Spectral finite volume base functions should not be used as geometrical shape functions.");
}

//////////////////////////////////////////////////////////////////////////////

RealVector SpectralFVBaseFunctionTetraP0::computeMappedCoordinatesPlus1D(const RealVector& coord,
                                    const std::vector<Framework::Node*>& nodes)
{
  throw Common::ShouldNotBeHereException (FromHere(),"Spectral finite volume base functions should not be used as geometrical shape functions.");
}

//////////////////////////////////////////////////////////////////////////////

  } // namespace SpectralFV

} // namespace COOLFluiD

//////////////////////////////////////////////////////////////////////////////
