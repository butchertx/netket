// Copyright 2018 The Simons Foundation, Inc. - All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef NETKET_PYNETKET_CC
#define NETKET_PYNETKET_CC

#include <netket.hpp>
#include "Utils/mpi_interface.hpp"  // for MPIInitializer

namespace netket {
using MachineType = std::complex<double>;
using AbMachineType = AbstractMachine<MachineType>;
using AbLayerType = AbstractLayer<MachineType>;
using AbSamplerType = AbstractSampler<AbMachineType>;
}  // namespace netket

#include "Dynamics/pydynamics.hpp"
#include "Graph/pygraph.hpp"
#include "GroundState/pyground_state.hpp"
#include "Hilbert/pyhilbert.hpp"
#include "Machine/pymachine.hpp"
#include "Operator/pyoperator.hpp"
#include "Optimizer/pyoptimizer.hpp"
#include "Output/pyoutput.hpp"
#include "Sampler/pysampler.hpp"
#include "Stats/binning.hpp"
#include "Utils/pyutils.hpp"

namespace netket {

namespace detail {
static MPIInitializer _do_not_use_me_dummy_{};
}  // namespace detail

using ode::AddDynamicsModule;

PYBIND11_MODULE(netket, m) {
  AddDynamicsModule(m);
  AddGraphModule(m);
  AddGroundStateModule(m);
  AddHilbertModule(m);
  AddMachineModule(m);
  AddOperatorModule(m);
  AddOptimizerModule(m);
  AddOutputModule(m);
  AddSamplerModule(m);
  AddUtilsModule(m);
}  // PYBIND11_MODULE

}  // namespace netket

#endif
