/*******************************************************************************
 *
 * TRIQS: a Toolbox for Research in Interacting Quantum Systems
 *
 * Copyright (C) 2015 by O. Parcollet
 *
 * TRIQS is free software: you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 *
 * TRIQS is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * TRIQS. If not, see <http://www.gnu.org/licenses/>.
 *
 ******************************************************************************/
#pragma once
namespace triqs {
namespace gfs {
 
 template <typename ... T> struct multivar_eval;

   
  template <> struct multivar_eval<interpol_t::None, interpol_t::None> {
   template <typename G, typename A0, typename A1> 
    auto operator()(G const &g, A0 && a0, A1 && a1) const {
    auto id0 = std::get<0>(g.mesh().components()).get_interpolation_data(interpol_t::None{},a0);
    auto id1 = std::get<1>(g.mesh().components()).get_interpolation_data(interpol_t::None{},a1);
    return 
 g[{id0, id1}];
   }
  };
 
   
  template <> struct multivar_eval<interpol_t::None, interpol_t::None, interpol_t::None> {
   template <typename G, typename A0, typename A1, typename A2> 
    auto operator()(G const &g, A0 && a0, A1 && a1, A2 && a2) const {
    auto id0 = std::get<0>(g.mesh().components()).get_interpolation_data(interpol_t::None{},a0);
    auto id1 = std::get<1>(g.mesh().components()).get_interpolation_data(interpol_t::None{},a1);
    auto id2 = std::get<2>(g.mesh().components()).get_interpolation_data(interpol_t::None{},a2);
    return 
 g[{id0, id1, id2}];
   }
  };
 
   
  template <> struct multivar_eval<interpol_t::None, interpol_t::None, interpol_t::None, interpol_t::None> {
   template <typename G, typename A0, typename A1, typename A2, typename A3> 
    auto operator()(G const &g, A0 && a0, A1 && a1, A2 && a2, A3 && a3) const {
    auto id0 = std::get<0>(g.mesh().components()).get_interpolation_data(interpol_t::None{},a0);
    auto id1 = std::get<1>(g.mesh().components()).get_interpolation_data(interpol_t::None{},a1);
    auto id2 = std::get<2>(g.mesh().components()).get_interpolation_data(interpol_t::None{},a2);
    auto id3 = std::get<3>(g.mesh().components()).get_interpolation_data(interpol_t::None{},a3);
    return 
 g[{id0, id1, id2, id3}];
   }
  };
 
   
  template <> struct multivar_eval<interpol_t::None, interpol_t::Linear1d> {
   template <typename G, typename A0, typename A1> 
    auto operator()(G const &g, A0 && a0, A1 && a1) const {
    auto id0 = std::get<0>(g.mesh().components()).get_interpolation_data(interpol_t::None{},a0);
    auto id1 = std::get<1>(g.mesh().components()).get_interpolation_data(interpol_t::Linear1d{},a1);
    return 
id1.w0 * g[{id0, id1.i0}] +
id1.w1 * g[{id0, id1.i1}];
   }
  };
 
   
  template <> struct multivar_eval<interpol_t::Linear1d, interpol_t::None> {
   template <typename G, typename A0, typename A1> 
    auto operator()(G const &g, A0 && a0, A1 && a1) const {
    auto id0 = std::get<0>(g.mesh().components()).get_interpolation_data(interpol_t::Linear1d{},a0);
    auto id1 = std::get<1>(g.mesh().components()).get_interpolation_data(interpol_t::None{},a1);
    return 
id0.w0 * g[{id0.i0, id1}] +
id0.w1 * g[{id0.i1, id1}];
   }
  };
 
   
  template <> struct multivar_eval<interpol_t::Linear1d, interpol_t::Linear1d> {
   template <typename G, typename A0, typename A1> 
    auto operator()(G const &g, A0 && a0, A1 && a1) const {
    auto id0 = std::get<0>(g.mesh().components()).get_interpolation_data(interpol_t::Linear1d{},a0);
    auto id1 = std::get<1>(g.mesh().components()).get_interpolation_data(interpol_t::Linear1d{},a1);
    return 
id0.w0 * id1.w0 * g[{id0.i0, id1.i0}] +
id0.w0 * id1.w1 * g[{id0.i0, id1.i1}] +
id0.w1 * id1.w0 * g[{id0.i1, id1.i0}] +
id0.w1 * id1.w1 * g[{id0.i1, id1.i1}];
   }
  };
 

}}
