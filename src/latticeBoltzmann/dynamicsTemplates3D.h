/* This file is part of the Palabos library.
 *
 * Copyright (C) 2011-2015 FlowKit Sarl
 * Route d'Oron 2
 * 1010 Lausanne, Switzerland
 * E-mail contact: contact@flowkit.com
 *
 * The most recent release of Palabos can be downloaded at 
 * <http://www.palabos.org/>
 *
 * The library Palabos is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * The library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/** \file
 * 3D specialization of dynamicsTemplates functions.
 */

#ifndef DYNAMICS_TEMPLATES_3D_H
#define DYNAMICS_TEMPLATES_3D_H

#include "core/globalDefs.h"
#include "latticeBoltzmann/nearestNeighborLattices3D.h"
#include "latticeBoltzmann/geometricOperationTemplates.h"

namespace plb {

template<typename T>
struct neqPiD3Q27 {

    typedef SymmetricTensorImpl<T,3> S;

    static T fromPiToFneq0(Array<T,6> const& pi) {
        return (T)4./(T)3 * (
                 -(T)1./(T)3*pi[S::xx] - (T)1./(T)3*pi[S::yy] - (T)1./(T)3*pi[S::zz]
               );
    }

    static T fromPiToFneq1(Array<T,6> const& pi) {
        return (T)1./(T)3 * (
                  (T)2./(T)3*pi[S::xx] - (T)1./(T)3*pi[S::yy] - (T)1./(T)3*pi[S::zz]
               );
    }

    static T fromPiToFneq2(Array<T,6> const& pi) {
        return (T)1./(T)3 * (
                  -(T)1./(T)3*pi[S::xx] + (T)2./(T)3*pi[S::yy] - (T)1./(T)3*pi[S::zz]
               );
    }

    static T fromPiToFneq3(Array<T,6> const& pi) {
        return (T)1./(T)3 * (
                  -(T)1./(T)3*pi[S::xx] - (T)1./(T)3*pi[S::yy] + (T)2./(T)3*pi[S::zz]
               );
    }

    static T fromPiToFneq4(Array<T,6> const& pi) {
        return (T)1./(T)12 * (
                  (T)2 * pi[S::xy]
                  + (T)2./(T)3*pi[S::xx] + (T)2./(T)3*pi[S::yy] - (T)1./(T)3*pi[S::zz]
               );
    }

    static T fromPiToFneq5(Array<T,6> const& pi) {
        return (T)1./(T)12 * (
                  - (T)2 * pi[S::xy]
                  + (T)2./(T)3*pi[S::xx] + (T)2./(T)3*pi[S::yy] - (T)1./(T)3*pi[S::zz]
               );
    }

    static T fromPiToFneq6(Array<T,6> const& pi) {
        return (T)1./(T)12 * (
                  (T)2 * pi[S::xz]
                  + (T)2./(T)3*pi[S::xx] - (T)1./(T)3*pi[S::yy] + (T)2./(T)3*pi[S::zz]
               );
    }

    static T fromPiToFneq7(Array<T,6> const& pi) {
        return (T)1./(T)12 * (
                  - (T)2 * pi[S::xz]
                  + (T)2./(T)3*pi[S::xx] - (T)1./(T)3*pi[S::yy] + (T)2./(T)3*pi[S::zz]
               );
    }

    static T fromPiToFneq8(Array<T,6> const& pi) {
        return (T)1./(T)12 * (
                  (T)2 * pi[S::yz]
                  - (T)1./(T)3*pi[S::xx] + (T)2./(T)3*pi[S::yy] + (T)2./(T)3*pi[S::zz]
               );
    }

    static T fromPiToFneq9(Array<T,6> const& pi) {
        return (T)1./(T)12 * (
                  - (T)2 * pi[S::yz]
                  - (T)1./(T)3*pi[S::xx] + (T)2./(T)3*pi[S::yy] + (T)2./(T)3*pi[S::zz]
               );
    }

    static T fromPiToFneq10(Array<T,6> const& pi) {
        return (T)1./(T)48 * (
                  + (T)2*pi[S::xy] + (T)2*pi[S::xz] + (T)2*pi[S::yz]
                  + (T)2./(T)3*pi[S::xx] + (T)2./(T)3*pi[S::yy] + (T)2./(T)3*pi[S::zz]
               );
    }

    static T fromPiToFneq11(Array<T,6> const& pi) {
        return (T)1./(T)48 * (
                  + (T)2*pi[S::xy] - (T)2*pi[S::xz] - (T)2*pi[S::yz]
                  + (T)2./(T)3*pi[S::xx] + (T)2./(T)3*pi[S::yy] + (T)2./(T)3*pi[S::zz]
               );
    }

    static T fromPiToFneq12(Array<T,6> const& pi) {
        return (T)1./(T)48 * (
                  - (T)2*pi[S::xy] + (T)2*pi[S::xz] - (T)2*pi[S::yz]
                  + (T)2./(T)3*pi[S::xx] + (T)2./(T)3*pi[S::yy] + (T)2./(T)3*pi[S::zz]
               );
    }

    static T fromPiToFneq13(Array<T,6> const& pi) {
        return (T)1./(T)48 * (
                  - (T)2*pi[S::xy] - (T)2*pi[S::xz] + (T)2*pi[S::yz]
                  + (T)2./(T)3*pi[S::xx] + (T)2./(T)3*pi[S::yy] + (T)2./(T)3*pi[S::zz]
               );
    }

};

// Efficient specialization for D3Q27 lattice
template<typename T>
struct dynamicsTemplatesImpl<T, descriptors::D3Q27DescriptorBase<T> > {
    
typedef descriptors::D3Q27DescriptorBase<T> D;

static T computePsiComplete(T omega) {
    T psi = T();
    if (omega > (T)1.6) {
        psi = (T)268.6859874851167*omega*omega*omega*omega-(T)1985.459929800400*omega*omega*omega+(T)5484.318345082302*omega*omega-(T)6706.888267019511*omega+(T)3063.206792351146;
    } else {
        psi = (T)0.1443148188258688*omega*omega*omega*omega+(T)0.1750827109999415*omega*omega*omega-(T)1.876945936794341*omega*omega+(T)2.249503042453559*omega;
    }
    if (psi > (T)2) psi = (T)2;
    return psi;
}

static T computePsiTruncated(T omega) {
    T psi = T();
    if (omega > (T)1.6) {
        psi = (T)177.9622278700708*omega*omega*omega*omega-(T)1315.199667473755*omega*omega*omega+(T)3633.679427864156*omega*omega-(T)4443.837134552950*omega+(T)2029.158251518184;
    } else {
        psi = (T)0.1627868025840013*omega*omega*omega*omega+(T)0.1448455498822147*omega*omega*omega-(T)1.873528835351911*omega*omega+(T)2.256060637042019*omega;
    }
    if (psi > (T)2) psi = (T)2;
    return psi;
}

static T bgk_ma2_equilibrium(plint iPop, T rhoBar, T invRho, Array<T,3> const& j, T jSqr ) {
    T c_j = D::c[iPop][0]*j[0] + D::c[iPop][1]*j[1] + D::c[iPop][2]*j[2];
    return D::t[iPop] * ( rhoBar + 3.*c_j + invRho*(4.5*c_j*c_j - 1.5*jSqr) );
}

static T complete_bgk_ma2_equilibrium(plint iPop, T rhoBar, T invRho, Array<T,D::d> const& j, T jSqr ) {
    T c_j = D::c[iPop][0]*j[0] + D::c[iPop][1]*j[1] + D::c[iPop][2]*j[2];
    T cs = std::sqrt(D::cs2);
    T cs_mcx = ((T)cs-(T)D::c[iPop][0]);
    T cs_pcx = ((T)cs+(T)D::c[iPop][0]);
    
    T cs_mcy = ((T)cs-(T)D::c[iPop][1]);
    T cs_pcy = ((T)cs+(T)D::c[iPop][1]);
    
    T cs_mcz = ((T)cs-(T)D::c[iPop][2]);
    T cs_pcz = ((T)cs+(T)D::c[iPop][2]);
      
    T invCs6 = D::invCs2*D::invCs2*D::invCs2;
    T H10 = -(T)D::c[iPop][1]*cs_mcx*cs_pcx;
    H10 *= (T)0.5*invCs6;
    
    T H11 = -(T)D::c[iPop][2]*cs_mcx*cs_pcx;
    H11 *= (T)0.5*invCs6;
    
    T H12 = -(T)D::c[iPop][0]*cs_mcy*cs_pcy;
    H12 *= (T)0.5*invCs6;
    
    T H13 = -(T)D::c[iPop][0]*cs_mcz*cs_pcz;
    H13 *= (T)0.5*invCs6;
    
    T H14 = -(T)D::c[iPop][1]*cs_mcz*cs_pcz;
    H14 *= (T)0.5*invCs6;
    
    T H15 = -(T)D::c[iPop][2]*cs_mcy*cs_pcy;
    H15 *= (T)0.5*invCs6;
    
    T H16 = (T)D::c[iPop][0]*(T)D::c[iPop][1]*(T)D::c[iPop][2];
    H16 *= invCs6;
    
    T invCs8 = D::invCs2*invCs6;
    T H17 = cs_mcy*cs_pcy*cs_mcx*cs_pcx;
    H17 *= (T)0.25*invCs8;
    T H18 = cs_mcz*cs_pcz*cs_mcx*cs_pcx;
    H18 *= (T)0.25*invCs8;
    T H19 = cs_mcz*cs_pcz*cs_mcy*cs_pcy;
    H19 *= (T)0.25*invCs8;
    T H20 = -(T)D::c[iPop][0]*(T)D::c[iPop][1]*cs_mcz*cs_pcz;
    H20 *= (T)0.5*invCs8;
    T H21 = -(T)D::c[iPop][0]*(T)D::c[iPop][2]*cs_mcy*cs_pcy;
    H21 *= (T)0.5*invCs8;
    T H22 = -(T)D::c[iPop][1]*(T)D::c[iPop][2]*cs_mcx*cs_pcx;
    H22 *= (T)0.5*invCs8;
    
    T invCs10 = D::invCs2*invCs8;
    T H23 = (T)D::c[iPop][1]*cs_mcz*cs_pcz*cs_mcx*cs_pcx;
    H23 *= (T)0.25*invCs10;
    T H24 = (T)D::c[iPop][2]*cs_mcy*cs_pcy*cs_mcx*cs_pcx;
    H24 *= (T)0.25*invCs10;
    T H25 = (T)D::c[iPop][0]*cs_mcz*cs_pcz*cs_mcy*cs_pcy;
    H25 *= (T)0.25*invCs10;
    
    T invCs12 = D::invCs2*invCs10;
    T H26 = -cs_mcz*cs_pcz*cs_mcy*cs_pcy*cs_mcx*cs_pcx;
    H26 *= (T)0.125*invCs12;
    
    T ux = j[0]*invRho;
    T uy = j[1]*invRho;
    T uz = j[2]*invRho;
    
    T ux2 = ux*ux; T uy2 = uy*uy; T uz2 = uz*uz;
    
    T aEq10 = j[1]*ux2;
    T aEq11 = j[2]*ux2;
    T aEq12 = j[0]*uy2;
    T aEq13 = j[0]*uz2;
    T aEq14 = j[1]*uz2;
    T aEq15 = j[2]*uy2;
    T aEq16 = j[0]*uy*uz;
    T aEq17 = j[0]*ux*uy2;
    T aEq18 = j[0]*ux*uz2;
    T aEq19 = j[1]*uy*uz2;
    T aEq20 = j[0]*uy*uz2;
    T aEq21 = j[0]*uy2*uz;
    T aEq22 = j[2]*ux2*uy;
    T aEq23 = j[1]*ux2*uz2;
    T aEq24 = j[2]*ux2*uy2;
    T aEq25 = j[0]*uy2*uz2;
    T aEq26 = j[0]*ux*uy2*uz2;


    
    return D::t[iPop] * ( rhoBar + 3.*c_j + invRho*(4.5*c_j*c_j - 1.5*jSqr) 
        + H10 * aEq10 + H11 * aEq11 + H12 * aEq12 + H13 * aEq13 + H14 * aEq14 + H15 * aEq15 
        + H16 * aEq16 + H17 * aEq17 + H18 * aEq18 + H19 * aEq19 + H20 * aEq20 
        + H21 * aEq21 + H22 * aEq22 + H23 * aEq23 + H24 * aEq24 + H25 * aEq25 + H26 * aEq26) ;
}

static void bgk_ma2_equilibria( T rhoBar, T invRho, Array<T,D::d> const& j,
                                T jSqr, Array<T,D::q>& eqPop )
{
    T t0 = D::t[0];
    T t1 = D::t[1];
    T t4 = D::t[4];
    T t10 = D::t[10];

    T kx     = (T)3 * j[0];
    T ky     = (T)3 * j[1];
    T kz     = (T)3 * j[2];
    T kxSqr_ = invRho / (T)2 * kx*kx;
    T kySqr_ = invRho / (T)2 * ky*ky;
    T kzSqr_ = invRho / (T)2 * kz*kz;
    T kxky_  = invRho * kx*ky;
    T kxkz_  = invRho * kx*kz;
    T kykz_  = invRho * ky*kz;

    T C1 = rhoBar + invRho*(T)3*jSqr;
    T C2, C3;

    // i=0
    C3 = -kxSqr_ - kySqr_ - kzSqr_;
    eqPop[0] = t0 * (C1+C3);

    // i=1 and i=14
    C2 = -kx;
    C3 = -kySqr_ - kzSqr_;
    eqPop[1]  = t1 * (C1+C2+C3);
    eqPop[14] = t1 * (C1-C2+C3);

    // i=2 and i=15
    C2 = -ky;
    C3 = -kxSqr_ - kzSqr_;
    eqPop[2]  = t1 * (C1+C2+C3);
    eqPop[15] = t1 * (C1-C2+C3);

    // i=3 and i=16
    C2 = -kz;
    C3 = -kxSqr_ - kySqr_;
    eqPop[3]  = t1 * (C1+C2+C3);
    eqPop[16] = t1 * (C1-C2+C3);

    // i=4 and i=17
    C2 = -kx - ky;
    C3 = kxky_ - kzSqr_;
    eqPop[4]  = t4 * (C1+C2+C3);
    eqPop[17] = t4 * (C1-C2+C3);

    // i=5 and i=18
    C2 = -kx + ky;
    C3 = -kxky_ - kzSqr_;
    eqPop[5]  = t4 * (C1+C2+C3);
    eqPop[18] = t4 * (C1-C2+C3);

    // i=6 and i=19
    C2 = -kx - kz;
    C3 = kxkz_ - kySqr_;
    eqPop[6]  = t4 * (C1+C2+C3);
    eqPop[19] = t4 * (C1-C2+C3);

    // i=7 and i=20
    C2 = -kx + kz;
    C3 = -kxkz_ - kySqr_;
    eqPop[7]  = t4 * (C1+C2+C3);
    eqPop[20] = t4 * (C1-C2+C3);

    // i=8 and i=21
    C2 = -ky - kz;
    C3 = kykz_ - kxSqr_;
    eqPop[8]  = t4 * (C1+C2+C3);
    eqPop[21] = t4 * (C1-C2+C3);

    // i=9 and i=22
    C2 = -ky + kz;
    C3 = -kykz_ - kxSqr_;
    eqPop[9]  = t4 * (C1+C2+C3);
    eqPop[22] = t4 * (C1-C2+C3);

    // i=10 and i=23
    C2 = -kx -ky -kz;
    C3 = kxky_ + kxkz_ + kykz_;
    eqPop[10] = t10 * (C1+C2+C3);
    eqPop[23] = t10 * (C1-C2+C3);

    // i=11 and i=24
    C2 = -kx -ky +kz;
    C3 = kxky_ - kxkz_ - kykz_;
    eqPop[11] = t10 * (C1+C2+C3);
    eqPop[24] = t10 * (C1-C2+C3);

    // i=12 and i=25
    C2 = -kx +ky -kz;
    C3 = -kxky_ + kxkz_ - kykz_;
    eqPop[12] = t10 * (C1+C2+C3);
    eqPop[25] = t10 * (C1-C2+C3);

    // i=13 and i=26
    C2 = -kx +ky +kz;
    C3 = -kxky_ - kxkz_ + kykz_;
    eqPop[13] = t10 * (C1+C2+C3);
    eqPop[26] = t10 * (C1-C2+C3);
}

// because of an huge gain in computational efficiency the rhoBar trick is not used....
// t[iPop] is removed manually at the end of the computation.
static void complete_bgk_ma2_equilibria( T rhoBar, T invRho, Array<T,D::d> const& j,
                                         T jSqr, Array<T,D::q>& eqPop )
{
    T ux = j[0]*invRho;
    T uy = j[1]*invRho;
    T uz = j[2]*invRho;
    
    T rho = D::fullRho(rhoBar);
    
    T threeUx = (T)3*ux;
    T threeUy = (T)3*uy;
    T threeUz = (T)3*uz;
    
    T threeUx2_m2 = (threeUx*ux-(T)2);
    T threeUy2_m2 = (threeUy*uy-(T)2);
    T threeUz2_m2 = (threeUz*uz-(T)2);
    
    T largeUx_m = threeUx2_m2+(T)3;
    T largeUx_p = largeUx_m+threeUx;
    largeUx_m -= threeUx;
    
    T largeUy_m = threeUy2_m2+(T)3;
    T largeUy_p = largeUy_m+threeUy;
    largeUy_m -= threeUy;
    
    T largeUz_m = threeUz2_m2+(T)3;
    T largeUz_p = largeUz_m+threeUz;
    largeUz_m -= threeUz;
    
    T prefact = D::cs2 * D::cs2 * D::cs2 * rho;
    eqPop[0] = -prefact*threeUz2_m2*threeUy2_m2*threeUx2_m2;
    
    prefact *= (T)0.5;
    T prefactThreeUz2_m2 = prefact*threeUz2_m2;
    T prefactThreeUx2_m2 = prefact*threeUx2_m2;
    
    T C1 = prefactThreeUz2_m2*threeUy2_m2;
    eqPop[1]  = C1*largeUx_m;
    eqPop[14] = C1*largeUx_p;
    
    C1 = prefactThreeUz2_m2*threeUx2_m2;
    eqPop[2]  = C1*largeUy_m;
    eqPop[15] = C1*largeUy_p;
    
    C1 = prefactThreeUx2_m2*threeUy2_m2;
    eqPop[3]  = C1*largeUz_m;
    eqPop[16] = C1*largeUz_p;
    
    prefact *= (T)0.5;
    T prefactLargeUx_m = prefact*largeUx_m;
    T prefactLargeUx_p = prefact*largeUx_p;
    
    C1 = -prefactLargeUx_m*threeUz2_m2;
    eqPop[4]  = C1*largeUy_m;
    eqPop[5]  = C1*largeUy_p;
    
    C1 = -prefactLargeUx_p*threeUz2_m2;
    eqPop[17] = C1*largeUy_p;
    eqPop[18] = C1*largeUy_m;
    
    C1 = -prefactLargeUx_m*threeUy2_m2;
    eqPop[6]  = C1*largeUz_m;
    eqPop[7]  = C1*largeUz_p;
    
    C1 = -prefactLargeUx_p*threeUy2_m2;
    eqPop[19] = C1*largeUz_p;
    eqPop[20] = C1*largeUz_m;
    
    prefactThreeUx2_m2 *= (T)0.5;
    T uz_m_uy_m = largeUz_m*largeUy_m;
    T uz_p_uy_p = largeUz_p*largeUy_p;
    T uz_p_uy_m = largeUz_p*largeUy_m;
    T uz_m_uy_p = largeUz_m*largeUy_p;
    eqPop[8]  = -prefactThreeUx2_m2*uz_m_uy_m;
    eqPop[21] = -prefactThreeUx2_m2*uz_p_uy_p;
    
    eqPop[9]  = -prefactThreeUx2_m2*uz_p_uy_m;
    eqPop[22] = -prefactThreeUx2_m2*uz_m_uy_p;
    
    prefactLargeUx_m *= (T)0.5;
    prefactLargeUx_p *= (T)0.5;
    
    eqPop[10] = prefactLargeUx_m*uz_m_uy_m;
    eqPop[23] = prefactLargeUx_p*uz_p_uy_p;
    
    eqPop[11] = prefactLargeUx_m*uz_p_uy_m;
    eqPop[24] = prefactLargeUx_p*uz_m_uy_p;
    
    eqPop[12] = prefactLargeUx_m*uz_m_uy_p;
    eqPop[25] = prefactLargeUx_p*uz_p_uy_m;
    
    eqPop[13] = prefactLargeUx_m*uz_p_uy_p;
    eqPop[26] = prefactLargeUx_p*uz_m_uy_m;
    
    for (plint iPop = 0; iPop < D::q; ++iPop) eqPop[iPop] = fBar<T,descriptors::D3Q27Descriptor>(eqPop[iPop],iPop);
}

static T bgk_ma2_collision_base(Array<T,D::q>& f, T rhoBar, Array<T,3> const& j, T omega, T invRho ) {
    T one_m_omega = (T)1 - omega;
    T t0_omega = D::t[0] * omega;
    T t1_omega = D::t[1] * omega;
    T t4_omega = D::t[4] * omega;
    T t10_omega = D::t[10] * omega;

    T jSqr   = j[0]*j[0] + j[1]*j[1] + j[2]*j[2];
    T kx     = (T)3 * j[0];
    T ky     = (T)3 * j[1];
    T kz     = (T)3 * j[2];
    T kxSqr_ = invRho / (T)2 * kx*kx;
    T kySqr_ = invRho / (T)2 * ky*ky;
    T kzSqr_ = invRho / (T)2 * kz*kz;
    T kxky_  = invRho * kx*ky;
    T kxkz_  = invRho * kx*kz;
    T kykz_  = invRho * ky*kz;

    T C1 = rhoBar + invRho*(T)3*jSqr;
    T C2, C3;

    // i=0
    C3 = -kxSqr_ - kySqr_ - kzSqr_;
    f[0] *= one_m_omega; f[0] += t0_omega * (C1+C3);

    // i=1 and i=14
    C2 = -kx;
    C3 = -kySqr_ - kzSqr_;
    f[1]  *= one_m_omega; f[1]  += t1_omega * (C1+C2+C3);
    f[14] *= one_m_omega; f[14] += t1_omega * (C1-C2+C3);

    // i=2 and i=15
    C2 = -ky;
    C3 = -kxSqr_ - kzSqr_;
    f[2]  *= one_m_omega; f[2]  += t1_omega * (C1+C2+C3);
    f[15] *= one_m_omega; f[15] += t1_omega * (C1-C2+C3);

    // i=3 and i=16
    C2 = -kz;
    C3 = -kxSqr_ - kySqr_;
    f[3]  *= one_m_omega; f[3]  += t1_omega * (C1+C2+C3);
    f[16] *= one_m_omega; f[16] += t1_omega * (C1-C2+C3);

    // i=4 and i=17
    C2 = -kx - ky;
    C3 = kxky_ - kzSqr_;
    f[4]  *= one_m_omega; f[4]  += t4_omega * (C1+C2+C3);
    f[17] *= one_m_omega; f[17] += t4_omega * (C1-C2+C3);

    // i=5 and i=18
    C2 = -kx + ky;
    C3 = -kxky_ - kzSqr_;
    f[5]  *= one_m_omega; f[5]  += t4_omega * (C1+C2+C3);
    f[18] *= one_m_omega; f[18] += t4_omega * (C1-C2+C3);

    // i=6 and i=19
    C2 = -kx - kz;
    C3 = kxkz_ - kySqr_;
    f[6]  *= one_m_omega; f[6]  += t4_omega * (C1+C2+C3);
    f[19] *= one_m_omega; f[19] += t4_omega * (C1-C2+C3);

    // i=7 and i=20
    C2 = -kx + kz;
    C3 = -kxkz_ - kySqr_;
    f[7]  *= one_m_omega; f[7]  += t4_omega * (C1+C2+C3);
    f[20] *= one_m_omega; f[20] += t4_omega * (C1-C2+C3);

    // i=8 and i=21
    C2 = -ky - kz;
    C3 = kykz_ - kxSqr_;
    f[8]  *= one_m_omega; f[8]  += t4_omega * (C1+C2+C3);
    f[21] *= one_m_omega; f[21] += t4_omega * (C1-C2+C3);

    // i=9 and i=22
    C2 = -ky + kz;
    C3 = -kykz_ - kxSqr_;
    f[9]  *= one_m_omega; f[9]  += t4_omega * (C1+C2+C3);
    f[22] *= one_m_omega; f[22] += t4_omega * (C1-C2+C3);

    // i=10 and i=23
    C2 = -kx -ky -kz;
    C3 = kxky_ + kxkz_ + kykz_;
    f[10] *= one_m_omega; f[10] += t10_omega * (C1+C2+C3);
    f[23] *= one_m_omega; f[23] += t10_omega * (C1-C2+C3);

    // i=11 and i=24
    C2 = -kx -ky +kz;
    C3 = kxky_ - kxkz_ - kykz_;
    f[11] *= one_m_omega; f[11] += t10_omega * (C1+C2+C3);
    f[24] *= one_m_omega; f[24] += t10_omega * (C1-C2+C3);

    // i=12 and i=25
    C2 = -kx +ky -kz;
    C3 = -kxky_ + kxkz_ - kykz_;
    f[12] *= one_m_omega; f[12] += t10_omega * (C1+C2+C3);
    f[25] *= one_m_omega; f[25] += t10_omega * (C1-C2+C3);

    // i=13 and i=26
    C2 = -kx +ky +kz;
    C3 = -kxky_ - kxkz_ + kykz_;
    f[13] *= one_m_omega; f[13] += t10_omega * (C1+C2+C3);
    f[26] *= one_m_omega; f[26] += t10_omega * (C1-C2+C3);

    return invRho*invRho*jSqr;
}

static T anechoic_ma2_collision_base(Array<T,D::q>& f, T rhoBar, 
    Array<T,3> const& j, T omega, T invRho, T delta, T rhoBar_target ,Array<T,3> j_target) {
    T jSqr = j[0]*j[0]+j[1]*j[1]+j[2]*j[2];
    Array<T,D::q> fEq;
    complete_bgk_ma2_equilibria( rhoBar, invRho, j, jSqr, fEq );

    std::cout << "Here!!!" << std::endl;
    
    T one_m_omega = (T)1 - omega;
    f *= one_m_omega;
    f += fEq*omega;

    return invRho*invRho*jSqr;
}

// because of an huge gain in computational efficiency the rhoBar trick is not used....
// t[iPop] is removed manually at the end of the computation
static T complete_bgk_ma2_collision_base(Array<T,D::q>& f, T rhoBar, T invRho, Array<T,D::d> const& j, T omega ) {
    T jSqr = j[0]*j[0]+j[1]*j[1]+j[2]*j[2];
    Array<T,D::q> fEq;
    complete_bgk_ma2_equilibria( rhoBar, invRho, j, jSqr, fEq );
    
    T one_m_omega = (T)1 - omega;
    f *= one_m_omega;
    f += fEq*omega;

    return invRho*invRho*jSqr;
}

static void complete_ma2_equilibrium_moments( T rhoBar, T invRho, Array<T,D::d> const& j,
                                              Array<T,D::q>& momEq )
{
    T ux = j[0]*invRho;
    T uy = j[1]*invRho;
    T uz = j[2]*invRho;
    
    momEq[0]=rhoBar;
    momEq[1]=j[0];
    momEq[2]=j[1];
    momEq[3]=j[2];
    momEq[4]=j[0]*ux;
    momEq[5]=j[0]*uy;
    momEq[6]=j[0]*uz;

    momEq[7]=j[1]*uy;
    momEq[8]=j[1]*uz;
    momEq[9]=j[2]*uz;

    momEq[10]=momEq[4]*uy;
    momEq[11]=momEq[4]*uz;

    momEq[12]=momEq[5]*uy;
    momEq[13]=momEq[6]*uz;

    momEq[14]=momEq[8]*uz;
    momEq[15]=momEq[7]*uz;

    momEq[16]=momEq[5]*uz;

    momEq[17]=momEq[10]*uy;
    momEq[18]=momEq[11]*uz;
    momEq[19]=momEq[15]*uz;

    momEq[20]=momEq[16]*uz;
    momEq[21]=momEq[16]*uy;
    momEq[22]=momEq[16]*ux;

    momEq[23]=momEq[22]*uz;
    momEq[24]=momEq[22]*uy;
    momEq[25]=momEq[20]*uy;
    momEq[26]=momEq[25]*ux;
}

static void truncated_ma2_equilibrium_moments( T rhoBar, T invRho, Array<T,D::d> const& j,
                                               Array<T,D::q>& momEq )
{
    T ux = j[0]*invRho;
    T uy = j[1]*invRho;
    T uz = j[2]*invRho;
    
    momEq.resetToZero();
    
    momEq[0]=rhoBar;
    momEq[1]=j[0];
    momEq[2]=j[1];
    momEq[3]=j[2];
    momEq[4]=j[0]*ux;
    momEq[5]=j[0]*uy;
    momEq[6]=j[0]*uz;

    momEq[7]=j[1]*uy;
    momEq[8]=j[1]*uz;
    momEq[9]=j[2]*uz;
}

static void addSmagorinskyMoments( Array<T,D::q>& momEq, const Array<T,6> &strain, T cSmago )
{
    typedef SymmetricTensorImpl<T,3> S;
    
    T rho = D::fullRho(momEq[0]);
    
    T sNorm = std::sqrt((T)2*SymmetricTensorImpl<T,3>::tensorNormSqr(strain));
    T smagoFactor = -(T)2*rho * cSmago * cSmago * sNorm;
    
    T ux2 = smagoFactor * strain[S::xx];
    T uy2 = smagoFactor * strain[S::yy];
    T uz2 = smagoFactor * strain[S::zz];
    
    T uxuy = smagoFactor * strain[S::xy];
    T uyuz = smagoFactor * strain[S::yz];
    T uxuz = smagoFactor * strain[S::xz];
    
    momEq[4] += ux2;
    momEq[5] += uxuy;
    momEq[6] += uxuz;

    momEq[7] += uy2;
    momEq[8] += uyuz;
    momEq[9] += uz2;
}

static void complete_ma2_moments( Array<T,D::q>& f, Array<T,D::q>& mom )
{
    T jxNeq_0 = f[1]+f[6]+f[7];
    T jxNeq_1 = f[4]+f[10]+f[11];
    T jxNeq_2 = f[5]+f[12]+f[13];
    T jxNeq = jxNeq_0+jxNeq_1+jxNeq_2;
    
    T jyNeq_0 = f[2]+f[4]+f[18];
    T jyNeq_1 = f[8]+f[10]+f[26];
    T jyNeq_2 = f[9]+f[11]+f[25];
    T jyNeq = jyNeq_0+jyNeq_2+jyNeq_1;

    T jzNeq_0 = f[3]+f[8]+f[22];
    T jzNeq_1 = f[6]+f[10]+f[12];
    T jzNeq_2 = f[20]+f[24]+f[26];
    T jzNeq = jzNeq_0+jzNeq_1+jzNeq_2;

    T jzPos_0 = f[9]+f[16]+f[21];
    T jzPos_1 = f[19]+f[23]+f[25];
    T jzPos_2 = f[7]+f[11]+f[13];
    T jzPos = jzPos_0+jzPos_2+jzPos_1;

    T jxPos_0 = f[14]+f[19]+f[20];
    T jxPos_1 = f[17]+f[23]+f[24];
    T jxPos_2 = f[18]+f[25]+f[26];
    T jxPos = jxPos_0+jxPos_1+jxPos_2;

    T jyPos_0 = f[5]+f[15]+f[17];
    T jyPos_1 = f[13]+f[21]+f[23];
    T jyPos_2 = f[12]+f[22]+f[24];
    T jyPos = jyPos_0+jyPos_2+jyPos_1;

    T jzPrime = f[0]+f[2]+f[15];
    T jxPrime = f[0]+f[3]+f[16];
    T jyPrime = f[0]+f[1]+f[14];

    T jx0 = jzPrime+jzNeq_0+jzPos_0;
    T jy0 = jxPrime+jxNeq_0+jxPos_0;
    T jz0 = jyPrime+jyNeq_0+jyPos_0;

    mom[0] = jx0+jxNeq+jxPos;

    mom[1] = -jxNeq+jxPos;
    mom[2] = -jyNeq+jyPos;
    mom[3] = -jzNeq+jzPos;

    mom[4] = D::cs2*(-3*jx0+2*mom[0]);
    mom[7] = D::cs2*(-3*jy0+2*mom[0]);
    mom[9] = D::cs2*(-3*jz0+2*mom[0]);
    
    mom[5] = jxNeq_1+jxPos_1-jxNeq_2-jxPos_2;
    mom[6] = jzNeq_1+jzPos_1-jzPos_2-jzNeq_2;
    mom[8] = jyNeq_1+jyPos_1-jyNeq_2-jyPos_2;

    T f_2_8_9 = f[2]+f[8]+f[9];
    T f_15_21_22 = f[15]+f[21]+f[22];
    T sym  = -jxNeq_1+jxPos_1;
    T asym = jxNeq_2-jxPos_2;
    mom[10] = D::cs2*(f_2_8_9-f_15_21_22+2*(sym + asym)); 
    mom[12] = D::cs2*(jxNeq_0-jxPos_0+2*(sym - asym)); 

    mom[23] = D::cs2*(-3*(f[2]-f[15])+2*(jyNeq_0-jyPos_0+mom[10]));

    T f_1_4_5 = f[1]+f[4]+f[5];
    T f_14_17_18 = f[14]+f[17]+f[18];
    sym  = -jzNeq_1+jzPos_1;
    asym =  jzPos_2-jzNeq_2;
    mom[11] = D::cs2*(jzNeq_0-jzPos_0+2*(sym+asym)); 
    mom[13] = D::cs2*(f_1_4_5-f_14_17_18+2*(sym - asym)); 

    mom[25] = D::cs2*(-3*(f[1]-f[14])+2*(f_1_4_5-f_14_17_18+mom[12]));
    
    T f_3_6_20 = f[3]+f[6]+f[20];
    T f_7_16_19 = f[7]+f[16]+f[19];
    mom[24] = D::cs2*(-3*(f[3]-f[16])+2*(f_3_6_20-f_7_16_19+mom[11]));

    sym  = -jyNeq_1+jyPos_1;
    asym = -jyNeq_2+jyPos_2;
    mom[14] = D::cs2*(jyNeq_0-jyPos_0+2*(sym + asym)); 
    mom[15] = D::cs2*(f_3_6_20-f_7_16_19+2*(sym - asym)); 


    mom[16] = f[11]+f[12]+f[23]+f[26]-f[10]-f[13]-f[24]-f[25];

    mom[17] = D::cs2*D::cs2*(7*jxPrime-2*(f_2_8_9+f_15_21_22)+4*(mom[0]-jx0)-6*jy0);
    mom[18] = D::cs2*D::cs2*(7*jzPrime-2*(f_1_4_5+f_14_17_18)+4*(mom[0]-jz0)-6*jx0);
    mom[19] = D::cs2*D::cs2*(7*jyPrime-2*(f_3_6_20+f_7_16_19)+4*(mom[0]-jy0)-6*jz0);

    mom[20] = D::cs2*(-3*(f[4]+f[17]-f[5]-f[18])+2*mom[5]);
    mom[21] = D::cs2*(-3*(f[6]+f[19]-f[7]-f[20])+2*mom[6]);
    mom[22] = D::cs2*(-3*(f[8]+f[21]-f[9]-f[22])+2*mom[8]);

    mom[26] = D::cs2*D::cs2*D::cs2*(-(T)27*f[0]+14*(jxPrime+jyPrime+jzPrime)
        +4*(jyPrime-f_1_4_5 -f_2_8_9-f_14_17_18-jy0-f_15_21_22)
        +8*(mom[0]-jx0-jy0-jz0));

}

static void complete_ma2_populations( Array<T,D::q>& a, Array<T,D::q>& f )
{
     f[0] = a[0]-(T)1.5*(a[4]+a[7]+a[9])+(T)2.25*(a[17]+a[18]+a[19])-(T)3.375*a[26];
     
     T sym  = a[0]+(T)3*a[4]-(T)1.5*a[7]-(T)1.5*a[9]-(T)4.5*a[17]-(T)4.5*a[18]+(T)2.25*a[19]+(T)6.75*a[26];
     T asym = -(T)3*a[1]+(T)4.5*a[12]+(T)4.5*a[13]-(T)6.75*a[25];
     f[1]  = sym+asym;
     f[14] = sym-asym;
     
     sym  = a[0]-(T)1.5*a[4]+(T)3*a[7]-(T)1.5*a[9]-(T)4.5*a[17]+(T)2.25*a[18]-(T)4.5*a[19]+(T)6.75*a[26];
     asym = -(T)3*a[2]+(T)4.5*a[10]+(T)4.5*a[14]-(T)6.75*a[23];
     f[2]  = sym+asym;
     f[15] = sym-asym;
     
     sym  = a[0]-(T)1.5*a[4]-(T)1.5*a[7]+(T)3*a[9]+(T)2.25*a[17]-(T)4.5*a[18]-(T)4.5*a[19]+(T)6.75*a[26];
     asym = -(T)3*a[3]+(T)4.5*a[11]+(T)4.5*a[15]-(T)6.75*a[24];
     f[3]  = sym+asym;
     f[16] = sym-asym;
     
     sym  = a[0]+(T)3*a[4]+(T)9*a[5]+(T)3*a[7]-(T)1.5*a[9]+(T)9*a[17]-(T)4.5*a[18]-(T)4.5*a[19]-(T)13.5*a[20]-(T)13.5*a[26];
     asym = -(T)3*a[1]-(T)3*a[2]-(T)9*a[10]-(T)9*a[12]+(T)4.5*a[13]+(T)4.5*a[14]+(T)13.5*a[23]+(T)13.5*a[25];
     f[4]  = sym+asym;
     f[17] = sym-asym;
     
     sym  = a[0]+(T)3*a[4]-(T)9*a[5]+(T)3*a[7]-(T)1.5*a[9]+(T)9*a[17]-(T)4.5*a[18]-(T)4.5*a[19]+(T)13.5*a[20]-(T)13.5*a[26];
     asym = -(T)3*a[1]+(T)3*a[2]+(T)9*a[10]-(T)9*a[12]+(T)4.5*a[13]-(T)4.5*a[14]-(T)13.5*a[23]+(T)13.5*a[25];
     f[5]  = sym+asym;
     f[18] = sym-asym;
     
     sym  = a[0]+(T)3*a[4]+(T)9*a[6]-(T)1.5*a[7]+(T)3*a[9]-(T)4.5*a[17]+(T)9*a[18]-(T)4.5*a[19]-(T)13.5*a[21]-(T)13.5*a[26];
     asym = -(T)3*a[1]-(T)3*a[3]-(T)9*a[11]+(T)4.5*a[12]-(T)9*a[13]+(T)4.5*a[15]+(T)13.5*a[24]+(T)13.5*a[25];
     f[6]  = sym+asym;
     f[19] = sym-asym;
     
     sym  = a[0]+(T)3*a[4]-(T)9*a[6]-(T)1.5*a[7]+(T)3*a[9]-(T)4.5*a[17]+(T)9*a[18]-(T)4.5*a[19]+(T)13.5*a[21]-(T)13.5*a[26];
     asym = -(T)3*a[1]+(T)3*a[3]+(T)9*a[11]+(T)4.5*a[12]-(T)9*a[13]-(T)4.5*a[15]-(T)13.5*a[24]+(T)13.5*a[25];
     f[7]  = sym+asym;
     f[20] = sym-asym;
     
     sym  = a[0]-(T)1.5*a[4]+(T)3*a[7]+(T)9*a[8]+(T)3*a[9]-(T)4.5*a[17]-(T)4.5*a[18]+(T)9*a[19]-(T)13.5*a[22]-(T)13.5*a[26];
     asym = -(T)3*a[2]-(T)3*a[3]+(T)4.5*a[10]+(T)4.5*a[11]-(T)9*a[14]-(T)9*a[15]+(T)13.5*a[23]+(T)13.5*a[24];
     f[8]  = sym+asym;
     f[21] = sym-asym;
     
     sym  = a[0]-(T)1.5*a[4]+(T)3*a[7]-(T)9*a[8]+(T)3*a[9]-(T)4.5*a[17]-(T)4.5*a[18]+(T)9*a[19]+(T)13.5*a[22]-(T)13.5*a[26];
     asym = -(T)3*a[2]+(T)3*a[3]+(T)4.5*a[10]-(T)4.5*a[11]-(T)9*a[14]+(T)9*a[15]+(T)13.5*a[23]-(T)13.5*a[24];
     f[9]  = sym+asym;
     f[22] = sym-asym;
     
     sym  = a[0]+(T)27.*a[26]+(T)27.*a[21]+(T)27.*a[22]+(T)9*a[17]+(T)9*a[18]+(T)9*a[19]+(T)27.*a[20]+(T)3*a[9]+(T)3*a[4]+(T)9*a[5]+(T)9*a[6]+(T)3*a[7]+(T)9*a[8];
     asym = -(T)27.*a[24]-(T)27.*a[25]-(T)27.*a[23]-(T)9*a[10]-(T)9*a[11]-(T)9*a[12]-(T)9*a[13]-(T)9*a[14]-(T)9*a[15]-(T)27.*a[16]-(T)3*a[1]-(T)3*a[2]-(T)3*a[3];
     f[10] = sym+asym;
     f[23] = sym-asym;
     
     sym  = a[0]+(T)27.*a[26]-(T)27.*a[21]-(T)27.*a[22]+(T)9*a[17]+(T)9*a[18]+(T)9*a[19]+(T)27.*a[20]+(T)3*a[9]+(T)3*a[4]+(T)9*a[5]-(T)9*a[6]+(T)3*a[7]-(T)9*a[8];
     asym = (T)27.*a[24]-(T)27.*a[25]-(T)27.*a[23]-(T)9*a[10]+(T)9*a[11]-(T)9*a[12]-(T)9*a[13]-(T)9*a[14]+(T)9*a[15]+(T)27.*a[16]-(T)3*a[1]-(T)3*a[2]+(T)3*a[3];
     f[11] = sym+asym;
     f[24] = sym-asym;
     
     sym  = a[0]+(T)27.*a[26]+(T)27.*a[21]-(T)27.*a[22]+(T)9*a[17]+(T)9*a[18]+(T)9*a[19]-(T)27.*a[20]+(T)3*a[9]+(T)3*a[4]-(T)9*a[5]+(T)9*a[6]+(T)3*a[7]-(T)9*a[8];
     asym = -(T)27.*a[24]-(T)27.*a[25]+(T)27.*a[23]+(T)9*a[10]-(T)9*a[11]-(T)9*a[12]-(T)9*a[13]+(T)9*a[14]-(T)9*a[15]+(T)27.*a[16]-(T)3*a[1]+(T)3*a[2]-(T)3*a[3];
     f[12] = sym+asym;
     f[25] = sym-asym;
     
     sym  = a[0]+(T)27.*a[26]-(T)27.*a[21]+(T)27.*a[22]+(T)9*a[17]+(T)9*a[18]+(T)9*a[19]-(T)27.*a[20]+(T)3*a[9]+(T)3*a[4]-(T)9*a[5]-(T)9*a[6]+(T)3*a[7]+(T)9*a[8];
     asym = (T)27.*a[24]-(T)27.*a[25]+(T)27.*a[23]+(T)9*a[10]+(T)9*a[11]-(T)9*a[12]-(T)9*a[13]+(T)9*a[14]+(T)9*a[15]-(T)27.*a[16]-(T)3*a[1]+(T)3*a[2]+(T)3*a[3];
     f[13] = sym+asym;
     f[26] = sym-asym;
     
     for (plint iPop = 0; iPop < D::q; ++iPop) f[iPop] *= D::t[iPop];
}

static void complete_bgk_ma2_regularize(Array<T,D::q> &f, T rhoBar, T invRho, Array<T,D::d> const& j, T jSqr,
                                        Array<T,SymmetricTensorImpl<T,D::d>::n> const& piNeq, T omega, T omegaNonPhys, plint iPhys) 
{
    T omegaRatio = omega / omegaNonPhys;
    
    complete_bgk_ma2_equilibria( rhoBar, invRho, j, jSqr, f);
    T ux = j[0]*invRho;
    T uy = j[1]*invRho;
    T uz = j[2]*invRho;
    
    T ux2 = ux*ux; T uy2 = uy*uy; T uz2 = uz*uz;
    
    Array<T,D::q> aOne;
    aOne[10] = (2*ux*piNeq[1]+uy*piNeq[0]);
    aOne[11] = (2*ux*piNeq[2]+uz*piNeq[0]);
    aOne[12] = (ux*piNeq[3]+2*uy*piNeq[1]);
    aOne[13] = (ux*piNeq[5]+2*uz*piNeq[2]);
    aOne[14] = (uy*piNeq[5]+2*uz*piNeq[4]);
    aOne[15] = (2*uy*piNeq[4]+uz*piNeq[3]);
    aOne[16] = (ux*piNeq[4]+uy*piNeq[2]+uz*piNeq[1]);
    
    aOne[17] = (ux2*piNeq[3]+4*ux*uy*piNeq[1]+uy2*piNeq[0]);
    aOne[18] = (ux2*piNeq[5]+4*ux*uz*piNeq[2]+uz2*piNeq[0]);
    aOne[19] = (uy2*piNeq[5]+4*uy*uz*piNeq[4]+uz2*piNeq[3]);
    aOne[20] = (ux*uy*piNeq[5]+2*ux*uz*piNeq[4]+2*uy*uz*piNeq[2]+uz2*piNeq[1]);
    aOne[21] = (2*ux*uy*piNeq[4]+ux*uz*piNeq[3]+uy2*piNeq[2]+2*uy*uz*piNeq[1]);
    aOne[22] = (ux2*piNeq[4]+2*ux*uy*piNeq[2]+2*ux*uz*piNeq[1]+uy*uz*piNeq[0]);
    
    aOne[23] = (ux2*uy*piNeq[5]+2*ux2*uz*piNeq[4]+4*ux*uy*uz*piNeq[2]+2*ux*uz2*piNeq[1]+uy*uz2*piNeq[0]);
    aOne[24] = (2*ux2*uy*piNeq[4]+ux2*uz*piNeq[3]+2*ux*uy2*piNeq[2]+4*ux*uy*uz*piNeq[1]+uy2*uz*piNeq[0]);
    aOne[25] = (ux*uy2*piNeq[5]+4*ux*uy*uz*piNeq[4]+ux*uz2*piNeq[3]+2*uy2*uz*piNeq[2]+2*uy*uz2*piNeq[1]);
    
    aOne[26] = (ux2*uy2*piNeq[5]+4*ux2*uy*uz*piNeq[4]+ux2*uz2*piNeq[3]+4*ux*uy2*uz*piNeq[2]+4*ux*uy*uz2*piNeq[1]+uy2*uz2*piNeq[0]);
    
    for (plint iPop = iPhys+1; iPop < D::q; ++iPop) aOne[iPop] *= omegaRatio;
    
    T cs4 = D::cs2*D::cs2;
    T cs4over2 = (T)0.5*cs4;
    T cs4over4 = (T)0.25*cs4;
    T cs4over8 = (T)0.125*cs4;
    
    T cs2over2 = (T)0.5*D::cs2;
    T cs2over4 = (T)0.25*D::cs2;
    T cs2over8 = (T)0.125*D::cs2;
    
    f[0]  += -(T)4*cs4*(piNeq[0]+piNeq[3]+piNeq[5])+(T)2*D::cs2*(aOne[17]+aOne[18]+aOne[19])-aOne[26];
    
    T C1 = cs4*((T)2*piNeq[0]-piNeq[3]-piNeq[5])-D::cs2*(aOne[17]+aOne[18])+cs2over2*aOne[19]+(T)0.5*aOne[26];
    T C2 = D::cs2*(aOne[12]+aOne[13])-(T)0.5*aOne[25];
    f[1]  += C1+C2;
    f[14] += C1-C2;
    
    C1 = cs4*(-piNeq[0]+(T)2*piNeq[3]-piNeq[5])-D::cs2*(aOne[17]+aOne[19])+cs2over2*aOne[18]+(T)0.5*aOne[26];
    C2 = D::cs2*(aOne[10]+aOne[14])-(T)0.5*aOne[23];
    f[2]  += C1 + C2;
    f[15] += C1 - C2;
 
    C1 = -cs4*(piNeq[0]+piNeq[3]-(T)2*piNeq[5])+cs2over2*aOne[17]-D::cs2*(aOne[18]+aOne[19])+(T)0.5*aOne[26];
    C2 = D::cs2*(aOne[11]+aOne[15])-(T)0.5*aOne[24];
    f[3]  += C1 + C2;
    f[16] += C1 - C2;
    
    C1 = cs4over2*(piNeq[0]+piNeq[3]) + cs2over2*(piNeq[1]+aOne[17]) - cs4over4*piNeq[5] - cs2over4*(aOne[18]+aOne[19]) - (T)0.25*(aOne[20]+aOne[26]);
    C2 = -cs2over2*(aOne[10]+aOne[12])+cs2over4*(aOne[13]+aOne[14])+(T)0.25*(aOne[23]+aOne[25]);
    f[4]  += C1+C2;
    f[17] += C1-C2;

    C1 = cs4over2*(piNeq[0]+piNeq[3]) - cs2over2*(piNeq[1]-aOne[17]) - cs4over4*piNeq[5] - cs2over4*(aOne[18]+aOne[19]) + (T)0.25*(aOne[20]-aOne[26]);
    C2 = cs2over2*(aOne[10]-aOne[12])+cs2over4*(aOne[13]-aOne[14])-(T)0.25*(aOne[23]-aOne[25]);
    f[5]  += C1 + C2;
    f[18] += C1 - C2;
    
    C1 = cs4over2*(piNeq[0]+piNeq[5])+cs2over2*(piNeq[2]+aOne[18]) - cs4over4*piNeq[3] + cs2over4*(-aOne[17]-aOne[19]) + (T)0.25*(-aOne[21]-aOne[26]);
    C2 = cs2over2*(-aOne[11]-aOne[13]) + cs2over4*(aOne[12]+aOne[15]) + (T)0.25*(+aOne[24]+aOne[25]);
    f[6]  += C1+C2;
    f[19] += C1-C2;
    
    C1 = cs4over2*(piNeq[0]+piNeq[5])+cs2over2*(-piNeq[2]+aOne[18])-cs4over4*piNeq[3]+cs2over4*(-aOne[17]-aOne[19])+(T)0.25*( aOne[21]-aOne[26]);
    C2 = cs2over2*( aOne[11]-aOne[13])+cs2over4*( aOne[12]-aOne[15])+(T)0.25*(-aOne[24]+aOne[25]);
    f[7]  += C1+C2;
    f[20] += C1-C2;
    
    f[8]  += -cs4over4*piNeq[0]+cs4over2*(piNeq[3]+piNeq[5])+cs2over2*( piNeq[4]-aOne[14]-aOne[15]+aOne[19])+cs2over4*( aOne[10]+aOne[11]-aOne[17]-aOne[18])+(T)0.25*(-aOne[22]+aOne[23]+aOne[24]-aOne[26]);
    f[21] += -cs4over4*piNeq[0]+cs4over2*(piNeq[3]+piNeq[5])+cs2over2*( piNeq[4]+aOne[14]+aOne[15]+aOne[19])+cs2over4*(-aOne[10]-aOne[11]-aOne[17]-aOne[18])+(T)0.25*(-aOne[22]-aOne[23]-aOne[24]-aOne[26]);
    f[9]  += -cs4over4*piNeq[0]+cs4over2*(piNeq[3]+piNeq[5])+cs2over2*(-piNeq[4]-aOne[14]+aOne[15]+aOne[19])+cs2over4*( aOne[10]-aOne[11]-aOne[17]-aOne[18])+(T)0.25*( aOne[22]+aOne[23]-aOne[24]-aOne[26]);
    f[22] += -cs4over4*piNeq[0]+cs4over2*(piNeq[3]+piNeq[5])+cs2over2*(-piNeq[4]+aOne[14]-aOne[15]+aOne[19])+cs2over4*(-aOne[10]+aOne[11]-aOne[17]-aOne[18])+(T)0.25*( aOne[22]-aOne[23]+aOne[24]-aOne[26]);
    
    f[10] += (T)0.125*(-aOne[16]+aOne[20]+aOne[21]+aOne[22]-aOne[23]-aOne[24]-aOne[25]+aOne[26])+cs2over8*(aOne[19]-aOne[15]+aOne[17]+aOne[18]-aOne[11]-aOne[12]-aOne[13]-aOne[14]+piNeq[4]+piNeq[1]+piNeq[2]-aOne[10])+cs4over8*(piNeq[5]+piNeq[0]+piNeq[3]);
    f[23] += (T)0.125*(+aOne[16]+aOne[20]+aOne[21]+aOne[22]+aOne[23]+aOne[24]+aOne[25]+aOne[26])+cs2over8*(aOne[19]+aOne[15]+aOne[17]+aOne[18]+aOne[11]+aOne[12]+aOne[13]+aOne[14]+piNeq[4]+piNeq[1]+piNeq[2]+aOne[10])+cs4over8*(piNeq[5]+piNeq[0]+piNeq[3]);
    
    f[11] += (T)0.125*(+aOne[16]+aOne[20]-aOne[21]-aOne[22]-aOne[23]+aOne[24]-aOne[25]+aOne[26])+cs2over8*(aOne[19]+aOne[15]+aOne[17]+aOne[18]+aOne[11]-aOne[12]-aOne[13]-aOne[14]-piNeq[4]+piNeq[1]-piNeq[2]-aOne[10])+cs4over8*(piNeq[5]+piNeq[0]+piNeq[3]);
    f[24] += (T)0.125*(-aOne[16]+aOne[20]-aOne[21]-aOne[22]+aOne[23]-aOne[24]+aOne[25]+aOne[26])+cs2over8*(aOne[19]-aOne[15]+aOne[17]+aOne[18]-aOne[11]+aOne[12]+aOne[13]+aOne[14]-piNeq[4]+piNeq[1]-piNeq[2]+aOne[10])+cs4over8*(piNeq[5]+piNeq[0]+piNeq[3]);
    
    f[12] += (T)0.125*(+aOne[16]-aOne[20]+aOne[21]-aOne[22]+aOne[23]-aOne[24]-aOne[25]+aOne[26])+cs2over8*(aOne[19]-aOne[15]+aOne[17]+aOne[18]-aOne[11]-aOne[12]-aOne[13]+aOne[14]-piNeq[4]-piNeq[1]+piNeq[2]+aOne[10])+cs4over8*(piNeq[5]+piNeq[0]+piNeq[3]);
    f[25] += (T)0.125*(-aOne[16]-aOne[20]+aOne[21]-aOne[22]-aOne[23]+aOne[24]+aOne[25]+aOne[26])+cs2over8*(aOne[19]+aOne[15]+aOne[17]+aOne[18]+aOne[11]+aOne[12]+aOne[13]-aOne[14]-piNeq[4]-piNeq[1]+piNeq[2]-aOne[10])+cs4over8*(piNeq[5]+piNeq[0]+piNeq[3]);
    
    f[13] += (T)0.125*(-aOne[16]-aOne[20]-aOne[21]+aOne[22]+aOne[23]+aOne[24]-aOne[25]+aOne[26])+cs2over8*(aOne[19]+aOne[15]+aOne[17]+aOne[18]+aOne[11]-aOne[12]-aOne[13]+aOne[14]+piNeq[4]-piNeq[1]-piNeq[2]+aOne[10])+cs4over8*(piNeq[5]+piNeq[0]+piNeq[3]);
    f[26] += (T)0.125*(+aOne[16]-aOne[20]-aOne[21]+aOne[22]-aOne[23]-aOne[24]+aOne[25]+aOne[26])+cs2over8*(aOne[19]-aOne[15]+aOne[17]+aOne[18]-aOne[11]+aOne[12]+aOne[13]-aOne[14]+piNeq[4]-piNeq[1]-piNeq[2]-aOne[10])+cs4over8*(piNeq[5]+piNeq[0]+piNeq[3]);
}

static void computeInvMmNeqToPop(const Array<T,D::q> &mNeq, Array<T,D::q> &f) {

    T m_17_18_19 = mNeq[17]+mNeq[18]+mNeq[19];
    T m_4_7_9 = mNeq[4]+mNeq[7]+mNeq[9];
    f[0]  -= D::t[0] *(-mNeq[0]+(T)1.5*m_4_7_9-2.25*m_17_18_19+3.375*mNeq[26]);

    T c1 = -mNeq[0]-6.75*mNeq[26];
    T sym = c1+(T)1.5*(mNeq[7]+mNeq[9])-3*mNeq[4]+4.5*(mNeq[17]+mNeq[18])-2.25*mNeq[19];
    T asym = 3*mNeq[1]-4.5*(mNeq[12]+mNeq[13])+6.75*mNeq[25];
    f[1]  -= D::t[1] *(sym+asym);
    f[14] -= D::t[14]*(sym-asym);

    sym = c1+(T)1.5*(mNeq[4]+mNeq[9])-3*mNeq[7]-2.25*mNeq[18]+4.5*(mNeq[17]+mNeq[19]);
    asym = 3*mNeq[2]-4.5*(mNeq[10]+mNeq[14])+6.75*mNeq[23];
    f[2]  -= D::t[2] *(sym+asym);
    f[15] -= D::t[15]*(sym-asym);

    sym = c1+(T)1.5*(mNeq[4]+mNeq[7])-3*mNeq[9]-2.25*mNeq[17]+4.5*(mNeq[18]+mNeq[19]);
    asym = 3*mNeq[3]-4.5*(mNeq[11]+mNeq[15])+6.75*mNeq[24];
    f[3]  -= D::t[3] *(sym+asym);
    f[16] -= D::t[16]*(sym-asym);
    
    c1 = -mNeq[0]+(T)1.5*mNeq[9]-3*(mNeq[4]+mNeq[7])+4.5*(mNeq[18]+mNeq[19])-9*mNeq[17]+13.5*mNeq[26];
    T c2 = -9*mNeq[5]+13.5*mNeq[20];

    T c3 =  3*mNeq[1]-4.5*mNeq[13]+9*mNeq[12]-13.5*mNeq[25];
    T c4 =  3*mNeq[2]-4.5*mNeq[14]+9*mNeq[10]-13.5*mNeq[23];
    sym = c1+c2;

    asym = c3+c4;
    f[4]  -= D::t[4] *(sym+asym);
    f[17] -= D::t[17]*(sym-asym);

    sym  = c1-c2;
    asym = c3-c4;
    f[5]  -= D::t[5] *(sym+asym);
    f[18] -= D::t[18]*(sym-asym);

    c1 = -mNeq[0]+(T)1.5*mNeq[7]-3*(mNeq[4]+mNeq[9])+4.5*(mNeq[17]+mNeq[19])-9*mNeq[18]+13.5*mNeq[26];
    c2 = -9*mNeq[6]+13.5*mNeq[21];

    c3 = 3*mNeq[1]-4.5*mNeq[12]+9*mNeq[13]-13.5*mNeq[25];
    c4 = 3*mNeq[3]-4.5*mNeq[15]+9*mNeq[11]-13.5*mNeq[24];

    sym = c1+c2;
    asym = c3+c4;
    f[6]  -= D::t[6] *(sym+asym);
    f[19] -= D::t[19]*(sym-asym);

    sym  = c1-c2;
    asym = c3-c4;
    f[7]  -= D::t[7] *(sym+asym);
    f[20] -= D::t[20]*(sym-asym);

    c1 = -mNeq[0]+(T)1.5*mNeq[4]-3*(mNeq[7]+mNeq[9])+4.5*(mNeq[17]+mNeq[18])-9*mNeq[19]+13.5*mNeq[26];
    c2 = -9*mNeq[8]+13.5*mNeq[22];

    c3 = 3*mNeq[2]-4.5*mNeq[10]+9*mNeq[14]-13.5*mNeq[23];
    c4 = 3*mNeq[3]-4.5*mNeq[11]+9*mNeq[15]-13.5*mNeq[24];
    sym  = c1+c2 ;
    asym = c3+c4;
    f[8]  -= D::t[8] *(sym+asym);
    f[21] -= D::t[21]*(sym-asym);

    sym  = c1-c2;
    asym = c3-c4;
    f[9]  -= D::t[9] *(sym+asym);
    f[22] -= D::t[22]*(sym-asym);

    c1 = -mNeq[0]-3*m_4_7_9;

    c2 = -9*(mNeq[5]+m_17_18_19)-(T)27*(mNeq[20]+mNeq[26]);
    c3 = -9*(mNeq[6]+mNeq[8])-(T)27*(mNeq[21]+mNeq[22]);

    c4   = 3*(mNeq[1]+mNeq[2])+9*(mNeq[10]+mNeq[12]+mNeq[13]+mNeq[14])+(T)27*(mNeq[23]+mNeq[25]);
    T c5 = 3*mNeq[3]+9*(mNeq[11]+mNeq[15])+(T)27*(mNeq[16]+mNeq[24]);

    sym  = c1+c2+c3;
    asym = c4+c5;
    f[10] -= D::t[10]*(sym+asym);
    f[23] -= D::t[23]*(sym-asym);

    sym  = c1+c2-c3;
    asym = c4-c5;
    f[11] -= D::t[11]*(sym+asym);
    f[24] -= D::t[24]*(sym-asym);

    c2 = 9*( mNeq[5]-m_17_18_19)+(T)27*(mNeq[20]-mNeq[26]);
    c3 = 9*(-mNeq[6]+mNeq[8])+(T)27*(-mNeq[21]+mNeq[22]);

    c4 = 3*(mNeq[1]-mNeq[2])-9*(mNeq[10]-mNeq[12]-mNeq[13]+mNeq[14])-(T)27*(mNeq[23]-mNeq[25]);
    c5 = 3*(mNeq[3])-9*(-mNeq[11]-mNeq[15])-(T)27*(mNeq[16]-mNeq[24]);

    sym = c1+c2+c3;
    asym = c4+c5;
    f[12] -= D::t[12]*(sym+asym);
    f[25] -= D::t[25]*(sym-asym);

    sym = c1+c2-c3;
    asym = c4-c5;
    f[13] -= D::t[13]*(sym+asym);
    f[26] -= D::t[26]*(sym-asym);
}

static void computeInvMmNeqToPopNoRhoJ(const Array<T,D::q> &mNeq, Array<T,D::q> &f) {

    T m_17_18_19 = mNeq[17]+mNeq[18]+mNeq[19];
    T m_4_7_9 = mNeq[4]+mNeq[7]+mNeq[9];
    f[0]  -= D::t[0] *(+(T)1.5*m_4_7_9-2.25*m_17_18_19+3.375*mNeq[26]);

    T c1 = -6.75*mNeq[26];
    T sym = c1+(T)1.5*(mNeq[7]+mNeq[9])-3*mNeq[4]+4.5*(mNeq[17]+mNeq[18])-2.25*mNeq[19];
    T asym = -4.5*(mNeq[12]+mNeq[13])+6.75*mNeq[25];
    f[1]  -= D::t[1] *(sym+asym);
    f[14] -= D::t[14]*(sym-asym);

    sym = c1+(T)1.5*(mNeq[4]+mNeq[9])-3*mNeq[7]-2.25*mNeq[18]+4.5*(mNeq[17]+mNeq[19]);
    asym = -4.5*(mNeq[10]+mNeq[14])+6.75*mNeq[23];
    f[2]  -= D::t[2] *(sym+asym);
    f[15] -= D::t[15]*(sym-asym);

    sym = c1+(T)1.5*(mNeq[4]+mNeq[7])-3*mNeq[9]-2.25*mNeq[17]+4.5*(mNeq[18]+mNeq[19]);
    asym = -4.5*(mNeq[11]+mNeq[15])+6.75*mNeq[24];
    f[3]  -= D::t[3] *(sym+asym);
    f[16] -= D::t[16]*(sym-asym);
    
    c1 = +(T)1.5*mNeq[9]-3*(mNeq[4]+mNeq[7])+4.5*(mNeq[18]+mNeq[19])-9*mNeq[17]+13.5*mNeq[26];
    T c2 = -9*mNeq[5]+13.5*mNeq[20];

    T c3 =  -4.5*mNeq[13]+9*mNeq[12]-13.5*mNeq[25];
    T c4 =  -4.5*mNeq[14]+9*mNeq[10]-13.5*mNeq[23];
    sym = c1+c2;

    asym = c3+c4;
    f[4]  -= D::t[4] *(sym+asym);
    f[17] -= D::t[17]*(sym-asym);

    sym  = c1-c2;
    asym = c3-c4;
    f[5]  -= D::t[5] *(sym+asym);
    f[18] -= D::t[18]*(sym-asym);

    c1 = +(T)1.5*mNeq[7]-3*(mNeq[4]+mNeq[9])+4.5*(mNeq[17]+mNeq[19])-9*mNeq[18]+13.5*mNeq[26];
    c2 = -9*mNeq[6]+13.5*mNeq[21];

    c3 = -4.5*mNeq[12]+9*mNeq[13]-13.5*mNeq[25];
    c4 = -4.5*mNeq[15]+9*mNeq[11]-13.5*mNeq[24];

    sym = c1+c2;
    asym = c3+c4;
    f[6]  -= D::t[6] *(sym+asym);
    f[19] -= D::t[19]*(sym-asym);

    sym  = c1-c2;
    asym = c3-c4;
    f[7]  -= D::t[7] *(sym+asym);
    f[20] -= D::t[20]*(sym-asym);

    c1 = +(T)1.5*mNeq[4]-3*(mNeq[7]+mNeq[9])+4.5*(mNeq[17]+mNeq[18])-9*mNeq[19]+13.5*mNeq[26];
    c2 = -9*mNeq[8]+13.5*mNeq[22];

    c3 = -4.5*mNeq[10]+9*mNeq[14]-13.5*mNeq[23];
    c4 = -4.5*mNeq[11]+9*mNeq[15]-13.5*mNeq[24];
    sym  = c1+c2 ;
    asym = c3+c4;
    f[8]  -= D::t[8] *(sym+asym);
    f[21] -= D::t[21]*(sym-asym);

    sym  = c1-c2;
    asym = c3-c4;
    f[9]  -= D::t[9] *(sym+asym);
    f[22] -= D::t[22]*(sym-asym);

    c1 = -3*m_4_7_9;

    c2 = -9*(mNeq[5]+m_17_18_19)-(T)27*(mNeq[20]+mNeq[26]);
    c3 = -9*(mNeq[6]+mNeq[8])-(T)27*(mNeq[21]+mNeq[22]);

    c4   = 9*(mNeq[10]+mNeq[12]+mNeq[13]+mNeq[14])+(T)27*(mNeq[23]+mNeq[25]);
    T c5 = 9*(mNeq[11]+mNeq[15])+(T)27*(mNeq[16]+mNeq[24]);

    sym  = c1+c2+c3;
    asym = c4+c5;
    f[10] -= D::t[10]*(sym+asym);
    f[23] -= D::t[23]*(sym-asym);

    sym  = c1+c2-c3;
    asym = c4-c5;
    f[11] -= D::t[11]*(sym+asym);
    f[24] -= D::t[24]*(sym-asym);

    c2 = 9*( mNeq[5]-m_17_18_19)+(T)27*(mNeq[20]-mNeq[26]);
    c3 = 9*(-mNeq[6]+mNeq[8])+(T)27*(-mNeq[21]+mNeq[22]);

    c4 = -9*(mNeq[10]-mNeq[12]-mNeq[13]+mNeq[14])-(T)27*(mNeq[23]-mNeq[25]);
    c5 = -9*(-mNeq[11]-mNeq[15])-(T)27*(mNeq[16]-mNeq[24]);

    sym = c1+c2+c3;
    asym = c4+c5;
    f[12] -= D::t[12]*(sym+asym);
    f[25] -= D::t[25]*(sym-asym);

    sym = c1+c2-c3;
    asym = c4-c5;
    f[13] -= D::t[13]*(sym+asym);
    f[26] -= D::t[26]*(sym-asym);
}


static T complete_mrt_ma2_collision_base(Array<T,D::q>& f, T omega, T omegaNonPhys, plint iPhys) {
    Array<T,D::q> mNeq, mEq;
    complete_ma2_moments(f, mNeq);
    T invRho = D::invRho(mNeq[0]);
    complete_ma2_equilibrium_moments(mNeq[0], invRho, Array<T,D::d>(mNeq[1],mNeq[2],mNeq[3]), mEq);
    
    T jSqr = mNeq[1]*mNeq[1] + mNeq[2]*mNeq[2] + mNeq[3]*mNeq[3];
    
    for (plint iPop = 1+D::d; iPop <= iPhys; ++iPop) {
        mNeq[iPop] -= mEq[iPop];
        mNeq[iPop] *= -omega;
    }
    
    for (plint iPop = iPhys+1; iPop < D::q; ++iPop) {
        mNeq[iPop] -= mEq[iPop];
        mNeq[iPop] *= -omegaNonPhys;
    }
        
    computeInvMmNeqToPopNoRhoJ(mNeq,f);
    
    return invRho*invRho*jSqr;
}

static void complete_neq_ma2_moments_from_phys_moments(Array<T,D::q>& mNeq, T rhoBar, T invRho, const Array<T,D::d> &j, 
                    const Array<T,SymmetricTensorImpl<T,D::d>::n> &piNeq, T omega, T omegaNonPhys) 
{
    T omegaRatio = omega / omegaNonPhys;
    mNeq[0] = T();

    mNeq[1] = T();
    mNeq[2] = T();
    mNeq[3] = T();

    mNeq[4] = piNeq[0];
    mNeq[5] = piNeq[1];
    mNeq[6] = piNeq[2];
    mNeq[7] = piNeq[3];
    mNeq[8] = piNeq[4];
    mNeq[9] = piNeq[5];

    T ux = j[0]*invRho; 
    T uy = j[1]*invRho;
    T uz = j[2]*invRho; T uz2 = uz*uz;


    T c1 = ux*piNeq[4]+uy*piNeq[2];
    mNeq[10] = omegaRatio*(2*ux*piNeq[1]+uy*piNeq[0]);
    mNeq[11] = omegaRatio*(2*ux*piNeq[2]+uz*piNeq[0]);
    mNeq[12] = omegaRatio*(ux*piNeq[3]+2*uy*piNeq[1]);
    mNeq[13] = omegaRatio*(ux*piNeq[5]+2*uz*piNeq[2]);
    mNeq[14] = omegaRatio*(uy*piNeq[5]+2*uz*piNeq[4]);
    mNeq[15] = omegaRatio*(2*uy*piNeq[4]+uz*piNeq[3]);
    mNeq[16] = omegaRatio*(c1+uz*piNeq[1]);

    mNeq[17] = ux*mNeq[12]+uy*mNeq[10];
    mNeq[18] = ux*mNeq[13]+uz*mNeq[11];
    mNeq[19] = uy*mNeq[14]+uz*mNeq[15];
    T c2 = c1 + uy*piNeq[2];
    T c3 = c1 + ux*piNeq[4];
    T c4 = ux*uy*piNeq[5];
    T c5 = c4+2*uz*c1;
    mNeq[20] = omegaRatio*(c4+uz*c1)+uz*mNeq[16];
    mNeq[21] = omegaRatio*uy*c3+uz*mNeq[12];
    mNeq[22] = omegaRatio*ux*c2+uz*mNeq[9];
    mNeq[23] = omegaRatio*ux*(c4+uz*c2)+uz*mNeq[22];
    mNeq[24] = 2*omegaRatio*ux*uy*c1+uz*mNeq[17];
    mNeq[25] = omegaRatio*uy*c5+uz2*mNeq[12];
    mNeq[26] = omegaRatio*ux*uy*c5+uz*mNeq[24];
}

static void computeInvMmNeq(const Array<T,D::q> &mNeq, Array<T,D::q> &f) {

    T m_17_18_19 = mNeq[17]+mNeq[18]+mNeq[19];
    T m_4_7_9 = mNeq[4]+mNeq[7]+mNeq[9];
    f[0]  = -D::t[0] *(-mNeq[0]+(T)1.5*m_4_7_9-2.25*m_17_18_19+3.375*mNeq[26]);

    T c1 = -mNeq[0]-6.75*mNeq[26];
    T sym = c1+(T)1.5*(mNeq[7]+mNeq[9])-3*mNeq[4]+4.5*(mNeq[17]+mNeq[18])-2.25*mNeq[19];
    T asym = 3*mNeq[1]-4.5*(mNeq[12]+mNeq[13])+6.75*mNeq[25];
    f[1]  = -D::t[1] *(sym+asym);
    f[14] = -D::t[14]*(sym-asym);

    sym = c1+(T)1.5*(mNeq[4]+mNeq[9])-3*mNeq[7]-2.25*mNeq[18]+4.5*(mNeq[17]+mNeq[19]);
    asym = 3*mNeq[2]-4.5*(mNeq[10]+mNeq[14])+6.75*mNeq[23];
    f[2]  = -D::t[2] *(sym+asym);
    f[15] = -D::t[15]*(sym-asym);

    sym = c1+(T)1.5*(mNeq[4]+mNeq[7])-3*mNeq[9]-2.25*mNeq[17]+4.5*(mNeq[18]+mNeq[19]);
    asym = 3*mNeq[3]-4.5*(mNeq[11]+mNeq[15])+6.75*mNeq[24];
    f[3]  = -D::t[3] *(sym+asym);
    f[16] = -D::t[16]*(sym-asym);
    
    c1 = -mNeq[0]+(T)1.5*mNeq[9]-3*(mNeq[4]+mNeq[7])+4.5*(mNeq[18]+mNeq[19])-9*mNeq[17]+13.5*mNeq[26];
    T c2 = -9*mNeq[5]+13.5*mNeq[20];

    T c3 =  3*mNeq[1]-4.5*mNeq[13]+9*mNeq[12]-13.5*mNeq[25];
    T c4 =  3*mNeq[2]-4.5*mNeq[14]+9*mNeq[10]-13.5*mNeq[23];
    sym = c1+c2;

    asym = c3+c4;
    f[4]  = -D::t[4] *(sym+asym);
    f[17] = -D::t[17]*(sym-asym);

    sym  = c1-c2;
    asym = c3-c4;
    f[5]  = -D::t[5] *(sym+asym);
    f[18] = -D::t[18]*(sym-asym);

    c1 = -mNeq[0]+(T)1.5*mNeq[7]-3*(mNeq[4]+mNeq[9])+4.5*(mNeq[17]+mNeq[19])-9*mNeq[18]+13.5*mNeq[26];
    c2 = -9*mNeq[6]+13.5*mNeq[21];

    c3 = 3*mNeq[1]-4.5*mNeq[12]+9*mNeq[13]-13.5*mNeq[25];
    c4 = 3*mNeq[3]-4.5*mNeq[15]+9*mNeq[11]-13.5*mNeq[24];

    sym = c1+c2;
    asym = c3+c4;
    f[6]  = -D::t[6] *(sym+asym);
    f[19] = -D::t[19]*(sym-asym);

    sym  = c1-c2;
    asym = c3-c4;
    f[7]  = -D::t[7] *(sym+asym);
    f[20] = -D::t[20]*(sym-asym);

    c1 = -mNeq[0]+(T)1.5*mNeq[4]-3*(mNeq[7]+mNeq[9])+4.5*(mNeq[17]+mNeq[18])-9*mNeq[19]+13.5*mNeq[26];
    c2 = -9*mNeq[8]+13.5*mNeq[22];

    c3 = 3*mNeq[2]-4.5*mNeq[10]+9*mNeq[14]-13.5*mNeq[23];
    c4 = 3*mNeq[3]-4.5*mNeq[11]+9*mNeq[15]-13.5*mNeq[24];
    sym  = c1+c2 ;
    asym = c3+c4;
    f[8]  = -D::t[8] *(sym+asym);
    f[21] = -D::t[21]*(sym-asym);

    sym  = c1-c2;
    asym = c3-c4;
    f[9]  = -D::t[9] *(sym+asym);
    f[22] = -D::t[22]*(sym-asym);

    c1 = -mNeq[0]-3*m_4_7_9;

    c2 = -9*(mNeq[5]+m_17_18_19)-(T)27*(mNeq[20]+mNeq[26]);
    c3 = -9*(mNeq[6]+mNeq[8])-(T)27*(mNeq[21]+mNeq[22]);

    c4   = 3*(mNeq[1]+mNeq[2])+9*(mNeq[10]+mNeq[12]+mNeq[13]+mNeq[14])+(T)27*(mNeq[23]+mNeq[25]);
    T c5 = 3*mNeq[3]+9*(mNeq[11]+mNeq[15])+(T)27*(mNeq[16]+mNeq[24]);

    sym  = c1+c2+c3;
    asym = c4+c5;
    f[10] = -D::t[10]*(sym+asym);
    f[23] = -D::t[23]*(sym-asym);

    sym  = c1+c2-c3;
    asym = c4-c5;
    f[11] = -D::t[11]*(sym+asym);
    f[24] = -D::t[24]*(sym-asym);

    c2 = 9*( mNeq[5]-m_17_18_19)+(T)27*(mNeq[20]-mNeq[26]);
    c3 = 9*(-mNeq[6]+mNeq[8])+(T)27*(-mNeq[21]+mNeq[22]);

    c4 = 3*(mNeq[1]-mNeq[2])-9*(mNeq[10]-mNeq[12]-mNeq[13]+mNeq[14])-(T)27*(mNeq[23]-mNeq[25]);
    c5 = 3*(mNeq[3])-9*(-mNeq[11]-mNeq[15])-(T)27*(mNeq[16]-mNeq[24]);

    sym = c1+c2+c3;
    asym = c4+c5;
    f[12] = -D::t[12]*(sym+asym);
    f[25] = -D::t[25]*(sym-asym);

    sym = c1+c2-c3;
    asym = c4-c5;
    f[13] = -D::t[13]*(sym+asym);
    f[26] = -D::t[26]*(sym-asym);
}

static T complete_regularized_mrt_ma2_collision_base(Array<T,D::q>& f, T rhoBar, const Array<T,D::d> &j, const Array<T,SymmetricTensorImpl<T,D::d>::n> &piNeq, T omega, T omegaNonPhys, plint iPhys) {
    Array<T,D::q> mNeq, mEq;
    // T rhoBar; 
    // Array<T,D::d> j;
    // Array<T,SymmetricTensorImpl<T,D::d>::n> piNeq;
    // momentTemplatesImpl<T,D>::compute_rhoBar_j_PiNeq(f,rhoBar,j,piNeq);
    T jSqr = j[0]*j[0] + j[1]*j[1] + j[2]*j[2];
    T invRho = D::invRho(rhoBar);

    complete_neq_ma2_moments_from_phys_moments(mNeq, rhoBar, invRho, j, piNeq, omega, omegaNonPhys);

    complete_ma2_equilibrium_moments(rhoBar, invRho, j, mEq);
    
    
    for (plint iPop = 0; iPop < 1+D::d; ++iPop) {
        mNeq[iPop] = mEq[iPop];
    }

    T one_m_omega = ((T)1-omega);
    for (plint iPop = 1+D::d; iPop <= iPhys; ++iPop) {
        mNeq[iPop] *= one_m_omega;
        mNeq[iPop] += mEq[iPop];
    }
    
    one_m_omega = ((T)1-omegaNonPhys);
    for (plint iPop = iPhys+1; iPop < D::q; ++iPop) {
        mNeq[iPop] *= one_m_omega;
        mNeq[iPop] += mEq[iPop];
    }
        
    computeInvMmNeq(mNeq,f);
    return invRho*invRho*jSqr;
}


static T consistent_smagorinsky_complete_regularized_mrt_ma2_collision_base(Array<T,D::q>& f, T cSmago, T omega, T omegaNonPhys, plint iPhys) {
    Array<T,D::q> mNeq, mEq;
    T rhoBar; 
    Array<T,D::d> j;
    Array<T,SymmetricTensorImpl<T,D::d>::n> piNeq;
    momentTemplatesImpl<T,D>::compute_rhoBar_j_PiNeq(f,rhoBar,j,piNeq);
    T jSqr = j[0]*j[0] + j[1]*j[1] + j[2]*j[2];
    T invRho = D::invRho(rhoBar);

    complete_neq_ma2_moments_from_phys_moments(mNeq, rhoBar, invRho, j, piNeq, omega, omegaNonPhys);

    complete_ma2_equilibrium_moments(rhoBar, invRho, j, mEq);

    Array<T,SymmetricTensorImpl<T,D::d>::n> S = 
        computeStrainRate(rhoBar, invRho, j, mNeq, cSmago, (T)1/omega);
    addSmagorinskyMoments( mEq, S, cSmago );
    
    
    for (plint iPop = 0; iPop < 1+D::d; ++iPop) {
        mNeq[iPop] = mEq[iPop];
    }

    T one_m_omega = ((T)1-omega);
    for (plint iPop = 1+D::d; iPop <= iPhys; ++iPop) {
        mNeq[iPop] *= one_m_omega;
        mNeq[iPop] += mEq[iPop];
    }
    
    one_m_omega = ((T)1-omegaNonPhys);
    for (plint iPop = iPhys+1; iPop < D::q; ++iPop) {
        mNeq[iPop] *= one_m_omega;
        mNeq[iPop] += mEq[iPop];
    }
        
    computeInvMmNeq(mNeq,f);
    return invRho*invRho*jSqr;
}


static T truncated_mrt_ma2_collision_base(Array<T,D::q>& f, T omega, T omegaNonPhys, plint iPhys) {
    Array<T,D::q> mNeq, mEq;
    complete_ma2_moments(f, mNeq);
    T invRho = D::invRho(mNeq[0]);
    truncated_ma2_equilibrium_moments(mNeq[0], invRho, Array<T,D::d>(mNeq[1],mNeq[2],mNeq[3]), mEq);
    
    T jSqr = mNeq[1]*mNeq[1] + mNeq[2]*mNeq[2] + mNeq[3]*mNeq[3];
    
    for (plint iPop = 1+D::d; iPop <= iPhys; ++iPop) {
        mNeq[iPop] -= mEq[iPop];
        mNeq[iPop] *= -omega;
    }
    
    for (plint iPop = iPhys+1; iPop < D::q; ++iPop) {
        mNeq[iPop] -= mEq[iPop];
        mNeq[iPop] *= -omegaNonPhys;
    }
        
    computeInvMmNeqToPopNoRhoJ(mNeq,f);
    
    return invRho*invRho*jSqr;
}

static Array<T,SymmetricTensorImpl<T,D::d>::n> computeStrainRate(T rhoBar, T invRho, const Array<T,D::d> &j, const Array<T,D::q> &mom, T cSmago, T tau) {
    typedef SymmetricTensorImpl<T,D::d> S;
    Array<T,S::n> piNeq;
    piNeq[S::xx] = mom[4+S::xx]-j[0]*j[0]*invRho;
    piNeq[S::xy] = mom[4+S::xy]-j[0]*j[1]*invRho;
    piNeq[S::xz] = mom[4+S::xz]-j[0]*j[2]*invRho;
    piNeq[S::yy] = mom[4+S::yy]-j[1]*j[1]*invRho;
    piNeq[S::yz] = mom[4+S::yz]-j[1]*j[2]*invRho;
    piNeq[S::zz] = mom[4+S::zz]-j[2]*j[2]*invRho;
    
    T rho = D::fullRho(rhoBar);
    
    T normPiNeq = std::sqrt((T)2*SymmetricTensorImpl<T,D::d>::tensorNormSqr(piNeq));
    normPiNeq *= (T)2*rho*util::sqr<T>(D::cs2*cSmago*cSmago);
    
    if (normPiNeq != T()) { // test to avoid division per 0
        piNeq = -(T)(-rho*tau*D::cs2+std::sqrt(util::sqr<T>(rho*tau*D::cs2)+normPiNeq)) / normPiNeq * piNeq;
    }

    return piNeq;
}

static T complete_mrt_smagorinsky_ma2_collision_base(Array<T,D::q>& f, T cSmago, T omega, T omegaNonPhys, plint iPhys) {
    Array<T,D::q> mNeq, mEq;
    complete_ma2_moments(f, mNeq);
    T rhoBar = mNeq[0];
    T invRho = D::invRho(mNeq[0]);
    Array<T,D::d> j(mNeq[1],mNeq[2],mNeq[3]);
    complete_ma2_equilibrium_moments(rhoBar, invRho, j, mEq);
    
    Array<T,SymmetricTensorImpl<T,D::d>::n> S = 
        computeStrainRate(rhoBar, invRho, j, mNeq, cSmago, (T)1/omega);
    
    addSmagorinskyMoments( mEq, S, cSmago );
    
    T jSqr = mNeq[1]*mNeq[1] + mNeq[2]*mNeq[2] + mNeq[3]*mNeq[3];
    
    for (plint iPop = 1+D::d; iPop <= iPhys; ++iPop) {
        mNeq[iPop] -= mEq[iPop];
        mNeq[iPop] *= -omega;
    }
    
    for (plint iPop = iPhys+1; iPop < D::q; ++iPop) {
        mNeq[iPop] -= mEq[iPop];
        mNeq[iPop] *= -omegaNonPhys;
    }
        
    computeInvMmNeqToPopNoRhoJ(mNeq,f);
    
    return invRho*invRho*jSqr;
}

static T truncated_mrt_smagorinsky_ma2_collision_base(Array<T,D::q>& f, T cSmago, T omega, T omegaNonPhys, plint iPhys) {
    Array<T,D::q> mNeq, mEq;
    complete_ma2_moments(f, mNeq);
    T rhoBar = mNeq[0];
    T invRho = D::invRho(mNeq[0]);
    Array<T,D::d> j(mNeq[1],mNeq[2],mNeq[3]);
    truncated_ma2_equilibrium_moments(mNeq[0], invRho, Array<T,D::d>(mNeq[1],mNeq[2],mNeq[3]), mEq);
    
    Array<T,SymmetricTensorImpl<T,D::d>::n> S = 
        computeStrainRate(rhoBar, invRho, j, mNeq, cSmago, (T)1/omega);
    
    addSmagorinskyMoments( mEq, S, cSmago );
    
    T jSqr = mNeq[1]*mNeq[1] + mNeq[2]*mNeq[2] + mNeq[3]*mNeq[3];
    
    for (plint iPop = 1+D::d; iPop <= iPhys; ++iPop) {
        mNeq[iPop] -= mEq[iPop];
        mNeq[iPop] *= -omega;
    }
    
    for (plint iPop = iPhys+1; iPop < D::q; ++iPop) {
        mNeq[iPop] -= mEq[iPop];
        mNeq[iPop] *= -omegaNonPhys;
    }
        
    computeInvMmNeqToPopNoRhoJ(mNeq,f);
    
    return invRho*invRho*jSqr;
}

static T complete_mrt_ma2_ext_rhoBar_j_collision_base(Array<T,D::q>& f, T rhoBar, Array<T,D::d> const &j, T omega, T omegaNonPhys, plint iPhys) {
    Array<T,D::q> mNeq, mEq;
    complete_ma2_moments(f, mNeq);
    T invRho = D::invRho(rhoBar);
    complete_ma2_equilibrium_moments(rhoBar, invRho, j, mEq);
    
    T jSqr = j[0]*j[0]+j[1]*j[1]+j[2]*j[2];
    
//     mNeq -= mEq;
    
//     plint iPhys = 16; // max moment to relax with omega
    for (plint iPop = 0; iPop <= iPhys; ++iPop) {
        mNeq[iPop] -= mEq[iPop];
        mNeq[iPop] *= -omega;
    }
    
    for (plint iPop = iPhys+1; iPop < D::q; ++iPop) {
        mNeq[iPop] -= mEq[iPop];
        mNeq[iPop] *= -omegaNonPhys;
    }
        
    computeInvMmNeqToPop(mNeq,f);
    
    return invRho*invRho*jSqr;
}


static T truncated_mrt_ma2_ext_rhoBar_j_collision_base(Array<T,D::q>& f, T rhoBar, Array<T,D::d> const &j, T omega, T omegaNonPhys, plint iPhys) {
    Array<T,D::q> mNeq, mEq;
    complete_ma2_moments(f, mNeq);
    T invRho = D::invRho(rhoBar);
    truncated_ma2_equilibrium_moments(rhoBar, invRho, j, mEq);
    
    T jSqr = j[0]*j[0]+j[1]*j[1]+j[2]*j[2];
    
//     mNeq -= mEq;
    
//     plint iPhys = 16; // max moment to relax with omega
    for (plint iPop = 0; iPop <= iPhys; ++iPop) {
        mNeq[iPop] -= mEq[iPop];
        mNeq[iPop] *= -omega;
    }
    
    for (plint iPop = iPhys+1; iPop < D::q; ++iPop) {
        mNeq[iPop] -= mEq[iPop];
        mNeq[iPop] *= -omegaNonPhys;
    }
        
    computeInvMmNeqToPop(mNeq,f);
    
    return invRho*invRho*jSqr;
}

static T complete_mrt_smagorinsky_ma2_ext_rhoBar_j_collision_base(Array<T,D::q>& f, T rhoBar, Array<T,D::d> const &j, T cSmago, T omega, T omegaNonPhys, plint iPhys) {
    Array<T,D::q> mNeq, mEq;
    complete_ma2_moments(f, mNeq);
    T invRho = D::invRho(rhoBar);
    complete_ma2_equilibrium_moments(rhoBar, invRho, j, mEq);

    Array<T,SymmetricTensorImpl<T,D::d>::n> S = 
        computeStrainRate(mNeq[0], D::invRho(mNeq[0]), Array<T,D::d>(mNeq[1],mNeq[2],mNeq[3]), mNeq, cSmago, (T)1/omega);
    
    addSmagorinskyMoments( mEq, S, cSmago );
    
    
    T jSqr = j[0]*j[0]+j[1]*j[1]+j[2]*j[2];
    
    // iPhys max moment to relax with omega
    for (plint iPop = 0; iPop <= iPhys; ++iPop) {
        mNeq[iPop] -= mEq[iPop];
        mNeq[iPop] *= -omega;
    }
    
    for (plint iPop = iPhys+1; iPop < D::q; ++iPop) {
        mNeq[iPop] -= mEq[iPop];
        mNeq[iPop] *= -omegaNonPhys;
    }
        
    computeInvMmNeqToPop(mNeq,f);
    
    return invRho*invRho*jSqr;
}

static T truncated_mrt_smagorinsky_ma2_ext_rhoBar_j_collision_base(Array<T,D::q>& f, T rhoBar, Array<T,D::d> const &j, T cSmago, T omega, T omegaNonPhys, plint iPhys) {
    Array<T,D::q> mNeq, mEq;
    complete_ma2_moments(f, mNeq);
    T invRho = D::invRho(rhoBar);
    truncated_ma2_equilibrium_moments(rhoBar, invRho, j, mEq);
    
    Array<T,SymmetricTensorImpl<T,D::d>::n> S = 
        computeStrainRate(mNeq[0], D::invRho(mNeq[0]), Array<T,D::d>(mNeq[1],mNeq[2],mNeq[3]), mNeq, cSmago, (T)1/omega);
    
    addSmagorinskyMoments( mEq, S, cSmago );
    
    
    T jSqr = j[0]*j[0]+j[1]*j[1]+j[2]*j[2];
    
    // iPhys max moment to relax with omega
    for (plint iPop = 0; iPop <= iPhys; ++iPop) {
        mNeq[iPop] -= mEq[iPop];
        mNeq[iPop] *= -omega;
    }
    
    for (plint iPop = iPhys+1; iPop < D::q; ++iPop) {
        mNeq[iPop] -= mEq[iPop];
        mNeq[iPop] *= -omegaNonPhys;
    }
        
    computeInvMmNeqToPop(mNeq,f);
    
    return invRho*invRho*jSqr;
}

static T bgk_ma2_collision(Array<T,D::q>& f, T rhoBar, Array<T,3> const& j, T omega) {
    T invRho = D::invRho(rhoBar);
    const T jSqr = VectorTemplateImpl<T,D::d>::normSqr(j);
    for (plint iPop=0; iPop < D::q; ++iPop) {
        f[iPop] *= (T)1-omega;
        f[iPop] += omega * dynamicsTemplatesImpl<T,D>::bgk_ma2_equilibrium (
                                iPop, rhoBar, invRho, j, jSqr );
    }
    return jSqr*invRho*invRho;
    //return bgk_ma2_collision_base(f, rhoBar, j, omega, D::invRho(rhoBar));
}

static T complete_bgk_ma2_collision(Array<T,D::q>& f, T rhoBar, T invRho, Array<T,3> const& j, T omega) {
    return complete_bgk_ma2_collision_base(f, rhoBar, invRho, j, omega);
}

static T complete_mrt_ma2_collision(Array<T,D::q>& f, T omega, T omegaNonPhys, plint iPhys) {
    return complete_mrt_ma2_collision_base(f, omega, omegaNonPhys, iPhys);
}

static T complete_regularized_mrt_ma2_collision(Array<T,D::q>& f, T rhoBar, const Array<T,D::d> &j, const Array<T,SymmetricTensorImpl<T,D::d>::n> &piNeq, T omega, T omegaNonPhys, plint iPhys) {
    return complete_regularized_mrt_ma2_collision_base(f, rhoBar, j, piNeq, omega, omegaNonPhys, iPhys);
}

static T consistent_smagorinsky_complete_regularized_mrt_ma2_collision(Array<T,D::q>& f, T cSmago, T omega, T omegaNonPhys, plint iPhys) {
    return consistent_smagorinsky_complete_regularized_mrt_ma2_collision_base(f, cSmago, omega, omegaNonPhys, iPhys);
}

static T complete_mrt_ma2_ext_rhoBar_j_collision(Array<T,D::q>& f, T rhoBar, Array<T,D::d> const& j, T omega, T omegaNonPhys, plint iPhys) {
    return complete_mrt_ma2_ext_rhoBar_j_collision_base(f, rhoBar, j, omega, omegaNonPhys, iPhys);
}

static T truncated_mrt_ma2_collision(Array<T,D::q>& f, T omega, T omegaNonPhys, plint iPhys) {
    return truncated_mrt_ma2_collision_base(f, omega, omegaNonPhys, iPhys);
}

static T truncated_mrt_ma2_ext_rhoBar_j_collision(Array<T,D::q>& f, T rhoBar, Array<T,D::d> const& j, T omega, T omegaNonPhys, plint iPhys) {
    return truncated_mrt_ma2_ext_rhoBar_j_collision_base(f, rhoBar, j, omega, omegaNonPhys, iPhys);
}

static T complete_mrt_smagorinsky_ma2_collision(Array<T,D::q>& f, T cSmago, T omega, T omegaNonPhys, plint iPhys) {
    return complete_mrt_smagorinsky_ma2_collision_base(f, cSmago, omega, omegaNonPhys, iPhys);
}

static T complete_mrt_smagorinsky_ma2_ext_rhoBar_j_collision(Array<T,D::q>& f, T rhoBar, Array<T,D::d> const& j, T cSmago, T omega, T omegaNonPhys, plint iPhys) {
    return complete_mrt_smagorinsky_ma2_ext_rhoBar_j_collision_base(f, rhoBar, j, cSmago, omega, omegaNonPhys, iPhys);
}

static T truncated_mrt_smagorinsky_ma2_collision(Array<T,D::q>& f, T cSmago, T omega, T omegaNonPhys, plint iPhys) {
    return truncated_mrt_smagorinsky_ma2_collision_base(f, cSmago, omega, omegaNonPhys, iPhys);
}

static T truncated_mrt_smagorinsky_ma2_ext_rhoBar_j_collision(Array<T,D::q>& f, T rhoBar, Array<T,D::d> const& j, T cSmago, T omega, T omegaNonPhys, plint iPhys) {
    return truncated_mrt_smagorinsky_ma2_ext_rhoBar_j_collision_base(f, rhoBar, j, cSmago, omega, omegaNonPhys, iPhys);
}

static T anechoic_ma2_collision(Array<T,D::q>& f, T rhoBar, 
    Array<T,3> const& j, T omega, T delta, T rhoBar_target, Array<T,3> j_target) {
    return anechoic_ma2_collision_base(f, rhoBar, j, omega, D::invRho(rhoBar), delta, 
    rhoBar_target, j_target);
}

static T bgk_inc_collision(Array<T,D::q>& f, T rhoBar, Array<T,3> const& j, T omega, T invRho0=(T)1 ) {
    return bgk_ma2_collision_base(f, rhoBar, j, omega, invRho0);
}

static T rlb_collision(Array<T,D::q>& f, T rhoBar, T invRho, Array<T,3> const& j, Array<T,6> const& PiNeq, T omega ) {
    typedef dynamicsTemplatesImpl<T, descriptors::D3Q27DescriptorBase<T> > DH;
    const T jSqr = j[0]*j[0] + j[1]*j[1] + j[2]*j[2];

    T piNeq0 = neqPiD3Q27<T>::fromPiToFneq0(PiNeq);
    T piNeq1 = neqPiD3Q27<T>::fromPiToFneq1(PiNeq);
    T piNeq2 = neqPiD3Q27<T>::fromPiToFneq2(PiNeq);
    T piNeq3 = neqPiD3Q27<T>::fromPiToFneq3(PiNeq);
    T piNeq4 = neqPiD3Q27<T>::fromPiToFneq4(PiNeq);
    T piNeq5 = neqPiD3Q27<T>::fromPiToFneq5(PiNeq);
    T piNeq6 = neqPiD3Q27<T>::fromPiToFneq6(PiNeq);
    T piNeq7 = neqPiD3Q27<T>::fromPiToFneq7(PiNeq);
    T piNeq8 = neqPiD3Q27<T>::fromPiToFneq8(PiNeq);
    T piNeq9 = neqPiD3Q27<T>::fromPiToFneq9(PiNeq);
    T piNeq10 = neqPiD3Q27<T>::fromPiToFneq10(PiNeq);
    T piNeq11 = neqPiD3Q27<T>::fromPiToFneq11(PiNeq);
    T piNeq12 = neqPiD3Q27<T>::fromPiToFneq12(PiNeq);
    T piNeq13 = neqPiD3Q27<T>::fromPiToFneq13(PiNeq);

    f[0]  = DH::bgk_ma2_equilibrium(0, rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq0;
    f[1]  = DH::bgk_ma2_equilibrium(1, rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq1;
    f[2]  = DH::bgk_ma2_equilibrium(2, rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq2;
    f[3]  = DH::bgk_ma2_equilibrium(3, rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq3;
    f[4]  = DH::bgk_ma2_equilibrium(4, rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq4;
    f[5]  = DH::bgk_ma2_equilibrium(5, rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq5;
    f[6]  = DH::bgk_ma2_equilibrium(6, rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq6;
    f[7]  = DH::bgk_ma2_equilibrium(7, rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq7;
    f[8]  = DH::bgk_ma2_equilibrium(8, rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq8;
    f[9]  = DH::bgk_ma2_equilibrium(9, rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq9;
    f[10]  = DH::bgk_ma2_equilibrium(10, rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq10;
    f[11]  = DH::bgk_ma2_equilibrium(11, rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq11;
    f[12]  = DH::bgk_ma2_equilibrium(12, rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq12;
    f[13]  = DH::bgk_ma2_equilibrium(13, rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq13;
    f[14]  = DH::bgk_ma2_equilibrium(14, rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq1;
    f[15]  = DH::bgk_ma2_equilibrium(15, rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq2;
    f[16]  = DH::bgk_ma2_equilibrium(16, rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq3;
    f[17]  = DH::bgk_ma2_equilibrium(17, rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq4;
    f[18]  = DH::bgk_ma2_equilibrium(18, rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq5;
    f[19]  = DH::bgk_ma2_equilibrium(19, rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq6;
    f[20]  = DH::bgk_ma2_equilibrium(20, rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq7;
    f[21]  = DH::bgk_ma2_equilibrium(21, rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq8;
    f[22]  = DH::bgk_ma2_equilibrium(22, rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq9;
    f[23]  = DH::bgk_ma2_equilibrium(23, rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq10;
    f[24]  = DH::bgk_ma2_equilibrium(24, rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq11;
    f[25]  = DH::bgk_ma2_equilibrium(25, rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq12;
    f[26]  = DH::bgk_ma2_equilibrium(26, rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq13;

    return jSqr*invRho*invRho;
}

static T bgk_ma2_constRho_collision(Array<T,D::q>& f, T rhoBar, Array<T,D::d> const& j, T ratioRho, T omega) {
    T invRho = D::invRho(rhoBar);
    const T jSqr = j[0]*j[0] + j[1]*j[1] + j[2]*j[2];
    for (plint iPop=0; iPop < D::q; ++iPop) {
        T feq = bgk_ma2_equilibrium(iPop, rhoBar, invRho, j, jSqr );
        f[iPop] =
          ratioRho*feq + D::t[iPop]*(ratioRho-(T)1) +
          ((T)1-omega)*(f[iPop]-feq);
    }
    return jSqr*invRho*invRho;
}

static T precond_bgk_ma2_equilibrium(plint iPop, T rhoBar, T invRho, Array<T,3> const& j, T jSqr, T invGamma ) {
    T c_j = D::c[iPop][0]*j[0] + D::c[iPop][1]*j[1] + D::c[iPop][2]*j[2];
    return D::t[iPop] * ( rhoBar + (T)3*c_j + invGamma*invRho*((T)4.5*c_j*c_j - (T)1.5*jSqr) );
}

static T precond_bgk_ma2_collision_base (
        Array<T,D::q>& f, T rhoBar, Array<T,3> const& j, T omega, T invGamma, bool incompressible )
{
    T invRho = incompressible ? (T)1 : D::invRho(rhoBar);
    T one_m_omega = (T)1 - omega;
    T t0_omega = D::t[0] * omega;
    T t1_omega = D::t[1] * omega;
    T t4_omega = D::t[4] * omega;
    T t10_omega = D::t[10] * omega;

    T jSqr   = j[0]*j[0] + j[1]*j[1] + j[2]*j[2];
    T kx     = (T)3 * j[0];
    T ky     = (T)3 * j[1];
    T kz     = (T)3 * j[2];
    T kxSqr_ = invGamma* invRho / (T)2 * kx*kx;
    T kySqr_ = invGamma* invRho / (T)2 * ky*ky;
    T kzSqr_ = invGamma* invRho / (T)2 * kz*kz;
    T kxky_  = invGamma* invRho * kx*ky;
    T kxkz_  = invGamma* invRho * kx*kz;
    T kykz_  = invGamma* invRho * ky*kz;

    T C1 = rhoBar + invGamma*invRho*(T)3*jSqr;
    T C2, C3;

    // i=0
    C3 = -kxSqr_ - kySqr_ - kzSqr_;
    f[0] *= one_m_omega; f[0] += t0_omega * (C1+C3);

    // i=1 and i=14
    C2 = -kx;
    C3 = -kySqr_ - kzSqr_;
    f[1]  *= one_m_omega; f[1]  += t1_omega * (C1+C2+C3);
    f[14] *= one_m_omega; f[14] += t1_omega * (C1-C2+C3);

    // i=2 and i=15
    C2 = -ky;
    C3 = -kxSqr_ - kzSqr_;
    f[2]  *= one_m_omega; f[2]  += t1_omega * (C1+C2+C3);
    f[15] *= one_m_omega; f[15] += t1_omega * (C1-C2+C3);

    // i=3 and i=16
    C2 = -kz;
    C3 = -kxSqr_ - kySqr_;
    f[3]  *= one_m_omega; f[3]  += t1_omega * (C1+C2+C3);
    f[16] *= one_m_omega; f[16] += t1_omega * (C1-C2+C3);

    // i=4 and i=17
    C2 = -kx - ky;
    C3 = kxky_ - kzSqr_;
    f[4]  *= one_m_omega; f[4]  += t4_omega * (C1+C2+C3);
    f[17] *= one_m_omega; f[17] += t4_omega * (C1-C2+C3);

    // i=5 and i=18
    C2 = -kx + ky;
    C3 = -kxky_ - kzSqr_;
    f[5]  *= one_m_omega; f[5]  += t4_omega * (C1+C2+C3);
    f[18] *= one_m_omega; f[18] += t4_omega * (C1-C2+C3);

    // i=6 and i=19
    C2 = -kx - kz;
    C3 = kxkz_ - kySqr_;
    f[6]  *= one_m_omega; f[6]  += t4_omega * (C1+C2+C3);
    f[19] *= one_m_omega; f[19] += t4_omega * (C1-C2+C3);

    // i=7 and i=20
    C2 = -kx + kz;
    C3 = -kxkz_ - kySqr_;
    f[7]  *= one_m_omega; f[7]  += t4_omega * (C1+C2+C3);
    f[20] *= one_m_omega; f[20] += t4_omega * (C1-C2+C3);

    // i=8 and i=21
    C2 = -ky - kz;
    C3 = kykz_ - kxSqr_;
    f[8]  *= one_m_omega; f[8]  += t4_omega * (C1+C2+C3);
    f[21] *= one_m_omega; f[21] += t4_omega * (C1-C2+C3);

    // i=9 and i=22
    C2 = -ky + kz;
    C3 = -kykz_ - kxSqr_;
    f[9]  *= one_m_omega; f[9]  += t4_omega * (C1+C2+C3);
    f[22] *= one_m_omega; f[22] += t4_omega * (C1-C2+C3);

    // i=10 and i=23
    C2 = -kx -ky -kz;
    C3 = kxky_ + kxkz_ + kykz_;
    f[10] *= one_m_omega; f[10] += t10_omega * (C1+C2+C3);
    f[23] *= one_m_omega; f[23] += t10_omega * (C1-C2+C3);

    // i=11 and i=24
    C2 = -kx -ky +kz;
    C3 = kxky_ - kxkz_ - kykz_;
    f[11] *= one_m_omega; f[11] += t10_omega * (C1+C2+C3);
    f[24] *= one_m_omega; f[24] += t10_omega * (C1-C2+C3);

    // i=12 and i=25
    C2 = -kx +ky -kz;
    C3 = -kxky_ + kxkz_ - kykz_;
    f[12] *= one_m_omega; f[12] += t10_omega * (C1+C2+C3);
    f[25] *= one_m_omega; f[25] += t10_omega * (C1-C2+C3);

    // i=13 and i=26
    C2 = -kx +ky +kz;
    C3 = -kxky_ - kxkz_ + kykz_;
    f[13] *= one_m_omega; f[13] += t10_omega * (C1+C2+C3);
    f[26] *= one_m_omega; f[26] += t10_omega * (C1-C2+C3);

    return invRho*invRho*jSqr;
}

static T precond_bgk_ma2_collision(Array<T,D::q>& f, T rhoBar, Array<T,3> const& j, T omega, T invGamma) {
    T invRho = D::invRho(rhoBar);
    const T jSqr = VectorTemplateImpl<T,D::d>::normSqr(j);
    for (plint iPop=0; iPop < D::q; ++iPop) {
        f[iPop] *= (T)1-omega;
        f[iPop] += omega * dynamicsTemplatesImpl<T,D>::precond_bgk_ma2_equilibrium (
                                iPop, rhoBar, invRho, j, jSqr, invGamma );
    }
    return jSqr*invRho*invRho;
    //return bgk_ma2_collision_base(f, rhoBar, j, omega, false);
}

};  //struct dynamicsTemplatesImpl<D3Q27DescriptorBase>


template<typename T>
struct neqPiD3Q19 {

    typedef SymmetricTensorImpl<T,3> S;

    static T fromPiToFneq0(Array<T,6> const& pi) {
        return (T)3./(T)2 * (
                 -(T)1./(T)3*pi[S::xx] - (T)1./(T)3*pi[S::yy] - (T)1./(T)3*pi[S::zz]
               );
    }

    static T fromPiToFneq1(Array<T,6> const& pi) {
        return (T)1./(T)4 * (
                  (T)2./(T)3*pi[S::xx] - (T)1./(T)3*pi[S::yy] - (T)1./(T)3*pi[S::zz]
               );
    }

    static T fromPiToFneq2(Array<T,6> const& pi) {
        return (T)1./(T)4 * (
                 -(T)1./(T)3*pi[S::xx] + (T)2./(T)3*pi[S::yy] - (T)1./(T)3*pi[S::zz]
               );
    }

    static T fromPiToFneq3(Array<T,6> const& pi) {
        return (T)1./(T)4 * (
                 -(T)1./(T)3*pi[S::xx] - (T)1./(T)3*pi[S::yy] + (T)2./(T)3*pi[S::zz]
               );
    }

    static T fromPiToFneq4(Array<T,6> const& pi) {
        return (T)1./(T)8 * (
                  (T)2./(T)3*pi[S::xx] + (T)2./(T)3*pi[S::yy] - (T)1./(T)3*pi[S::zz]
                  + (T)2*pi[S::xy]
               );
    }

    static T fromPiToFneq5(Array<T,6> const& pi) {
        return (T)1./(T)8 * (
                  (T)2./(T)3*pi[S::xx] + (T)2./(T)3*pi[S::yy] - (T)1./(T)3*pi[S::zz]
                  - (T)2*pi[S::xy]
               );
    }

    static T fromPiToFneq6(Array<T,6> const& pi) {
        return (T)1./(T)8 * (
                  (T)2./(T)3*pi[S::xx] - (T)1./(T)3*pi[S::yy] + (T)2./(T)3*pi[S::zz]
                  + (T)2*pi[S::xz]
               );
    }

    static T fromPiToFneq7(Array<T,6> const& pi) {
        return (T)1./(T)8 * (
                  (T)2./(T)3*pi[S::xx] - (T)1./(T)3*pi[S::yy] + (T)2./(T)3*pi[S::zz]
                  - (T)2*pi[S::xz]
               );
    }

    static T fromPiToFneq8(Array<T,6> const& pi) {
        return (T)1./(T)8 * (
                 -(T)1./(T)3*pi[S::xx] + (T)2./(T)3*pi[S::yy] + (T)2./(T)3*pi[S::zz]
                  + (T)2*pi[S::yz]
               );
    }

    static T fromPiToFneq9(Array<T,6> const& pi) {
        return (T)1./(T)8 * (
                 -(T)1./(T)3*pi[S::xx] + (T)2./(T)3*pi[S::yy] + (T)2./(T)3*pi[S::zz]
                  - (T)2*pi[S::yz]
               );
    }

};  // struct neqPiD3Q19



// Efficient specialization for D3Q19 lattice
template<typename T>
struct dynamicsTemplatesImpl<T, descriptors::D3Q19DescriptorBase<T> > {

typedef descriptors::D3Q19DescriptorBase<T> D;

static T computePsiTruncated(T omega) {
    T psi = T();
    if (omega > (T)1.6) {
        psi = (T)230.9821107648567*omega*omega*omega*omega-(T)1706.434271552770*omega*omega*omega+(T)4713.652548693073*omega*omega-(T)5765.345248835891*omega+(T)2633.840703083939;
    } else {
        psi = (T)0.2155340964307518*omega*omega*omega*omega-(T)0.1436184333209376*omega*omega*omega-(T)1.356839670585176*omega*omega+(T)1.936038021508263*omega;
    }
    if (psi > (T)2) psi = (T)2;
    return psi;
}

static T bgk_ma2_equilibrium(plint iPop, T rhoBar, T invRho, Array<T,3> const& j, T jSqr ) {
    T c_j = D::c[iPop][0]*j[0] + D::c[iPop][1]*j[1] + D::c[iPop][2]*j[2];
    return D::t[iPop] * ( rhoBar + (T)3.*c_j + invRho*((T)4.5*c_j*c_j - (T)1.5*jSqr) );
}

static void bgk_ma2_equilibria( T rhoBar, T invRho, Array<T,D::d> const& j,
                                T jSqr, Array<T,D::q>& eqPop )
{
    T t0 = D::t[0];
    T t1 = D::t[1];
    T t4 = D::t[4];

    T kx     = (T)3 * j[0];
    T ky     = (T)3 * j[1];
    T kz     = (T)3 * j[2];
    T kxSqr_ = invRho / (T)2 * kx*kx;
    T kySqr_ = invRho / (T)2 * ky*ky;
    T kzSqr_ = invRho / (T)2 * kz*kz;
    T kxky_  = invRho * kx*ky;
    T kxkz_  = invRho * kx*kz;
    T kykz_  = invRho * ky*kz;

    T C1 = rhoBar + invRho*(T)3*jSqr;
    T C2, C3;

    // i=0
    C3 = -kxSqr_ - kySqr_ - kzSqr_;
    eqPop[0] = t0 * (C1+C3);

    // i=1 and i=10
    C2 = -kx;
    C3 = -kySqr_ - kzSqr_;
    eqPop[1]  = t1 * (C1+C2+C3);
    eqPop[10] = t1 * (C1-C2+C3);

    // i=2 and i=11
    C2 = -ky;
    C3 = -kxSqr_ - kzSqr_;
    eqPop[2]  = t1 * (C1+C2+C3);
    eqPop[11] = t1 * (C1-C2+C3);

    // i=3 and i=12
    C2 = -kz;
    C3 = -kxSqr_ - kySqr_;
    eqPop[3]  = t1 * (C1+C2+C3);
    eqPop[12] = t1 * (C1-C2+C3);

    // i=4 and i=13
    C2 = -kx - ky;
    C3 = kxky_ - kzSqr_;
    eqPop[4]  = t4 * (C1+C2+C3);
    eqPop[13] = t4 * (C1-C2+C3);

    // i=5 and i=14
    C2 = -kx + ky;
    C3 = -kxky_ - kzSqr_;
    eqPop[5]  = t4 * (C1+C2+C3);
    eqPop[14] = t4 * (C1-C2+C3);

    // i=6 and i=15
    C2 = -kx - kz;
    C3 = kxkz_ - kySqr_;
    eqPop[6]  = t4 * (C1+C2+C3);
    eqPop[15] = t4 * (C1-C2+C3);

    // i=7 and i=16
    C2 = -kx + kz;
    C3 = -kxkz_ - kySqr_;
    eqPop[7]  = t4 * (C1+C2+C3);
    eqPop[16] = t4 * (C1-C2+C3);

    // i=8 and i=17
    C2 = -ky - kz;
    C3 = kykz_ - kxSqr_;
    eqPop[8]  = t4 * (C1+C2+C3);
    eqPop[17] = t4 * (C1-C2+C3);

    // i=9 and i=18
    C2 = -ky + kz;
    C3 = -kykz_ - kxSqr_;
    eqPop[9]  = t4 * (C1+C2+C3);
    eqPop[18] = t4 * (C1-C2+C3);
}

static void truncated_ma2_equilibrium_moments( T rhoBar, T invRho, Array<T,D::d> const& j,
                                               Array<T,D::q>& momEq )
{
    T ux = j[0]*invRho;
    T uy = j[1]*invRho;
    T uz = j[2]*invRho;
    
    momEq.resetToZero();
    
    momEq[0]=rhoBar;
    momEq[1]=j[0];
    momEq[2]=j[1];
    momEq[3]=j[2];
    momEq[4]=j[0]*ux;
    momEq[5]=j[0]*uy;
    momEq[6]=j[0]*uz;

    momEq[7]=j[1]*uy;
    momEq[8]=j[1]*uz;
    momEq[9]=j[2]*uz;
}

static void complete_ma2_moments( Array<T,D::q>& f, Array<T,D::q>& mom )
{
    T f_4_5_6_7     = f[4]+f[5]+f[6]+f[7];
    T f_13_14_15_16 = f[13]+f[14]+f[15]+f[16];
    T f_1_2_3_10_11_12 = f[1]+f[2]+f[3]+f[10]+f[11]+f[12];
    T f_8_9_17_18 = f[8]+f[9]+f[17]+f[18];

    mom[0] = f[0]+f_1_2_3_10_11_12+f_4_5_6_7+f_8_9_17_18+f_13_14_15_16;

    T f_m6_7_15_m16 = -f[6]+f[7]+f[15]-f[16];
    T f_4_5_13_14 = f[4]+f[5]+f[13]+f[14];
    T f_6_7_15_16 = f[6]+f[7]+f[15]+f[16];

    T f_m4_5_13_m14 = -f[4]+f[5]+f[13]-f[14];
    T f_m8_m9_17_18 = -f[8]-f[9]+f[17]+f[18];
    T f_m8_9_17_m18 = -f[8]+f[9]+f[17]-f[18];

    mom[1] = -f[1]+f[10]-f_4_5_6_7+f_13_14_15_16;
    mom[2] = -f[2]+f[11]+f_m4_5_13_m14 + f_m8_m9_17_18;
    mom[3] = -f[3]+f[12]+f_m6_7_15_m16 + f_m8_9_17_m18;

    mom[4] = D::cs2*(-f[0]-f_1_2_3_10_11_12+(T)3*(f[1]+f[10])-f_8_9_17_18+(T)2*(f_4_5_6_7+f_13_14_15_16));
    mom[7] = D::cs2*(-f[0]-f_1_2_3_10_11_12+(T)3*(f[2]+f[11])-f_6_7_15_16+(T)2*(f_4_5_13_14+f_8_9_17_18));
    mom[9] = D::cs2*(-f[0]-f_1_2_3_10_11_12+(T)3*(f[3]+f[12])-f_4_5_13_14+(T)2*(f_6_7_15_16+f_8_9_17_18));

    mom[5] = f[4]-f[5]+f[13]-f[14];
    mom[6] = f[6]-f[7]+f[15]-f[16];
    mom[8] = f[8]-f[9]+f[17]-f[18];

    mom[10] = D::cs2*(f_m4_5_13_m14 + f_m8_m9_17_18+(T)2*(f[2]-f[11]));
    mom[11] = D::cs2*(-f_4_5_6_7+f_13_14_15_16+(T)2*(f[1]-f[10]));
    mom[12] = D::cs2*(f_m6_7_15_m16+f_m8_9_17_m18+(T)2*(f[3]-f[12]));

    mom[13] = f_m4_5_13_m14 - f_m8_m9_17_18;
    mom[14] =  f[4]+f[5]-f[13]-f[14] -f[6]-f[7]+f[15]+f[16];
    mom[15] =  -f_m6_7_15_m16 +f_m8_9_17_m18;

    mom[16] = D::cs2*D::cs2*(-f_1_2_3_10_11_12+(T)0.5*(f[0]+f_4_5_6_7+f_8_9_17_18+f_13_14_15_16));
    mom[17] = D::cs2*D::cs2*( (T)1.5*(f[1]+f[10])+f_8_9_17_18+(T)0.5*(-f_1_2_3_10_11_12-f_4_5_6_7-f_13_14_15_16));

    mom[18] = (T)0.25*D::cs2*(f[2]+f[11]-f[3]-f[12]-f_4_5_13_14+f_6_7_15_16);
}

static void computeInvMmNeqToPop(const Array<T,D::q> &mNeq, Array<T,D::q> &f) {
    f[0] -= D::t[0]*(-mNeq[0]+(T)1.5*(mNeq[4]+mNeq[7]+mNeq[9])-(T)3*mNeq[16]);

    T sym  = -mNeq[0]-(T)3*mNeq[4]+(T)1.5*(mNeq[7]+mNeq[9])+(T)6*mNeq[16]-(T)27*mNeq[17];
    T asym = (T)3*mNeq[1]-(T)9*mNeq[11];
    f[1]  -= D::t[1]  * (sym+asym);
    f[10] -= D::t[10] * (sym-asym);

    sym  = -mNeq[0]+(T)1.5*mNeq[4]-(T)3*mNeq[7]+(T)1.5*mNeq[9]+(T)6*mNeq[16]+13.5*mNeq[17]-(T)27*mNeq[18];
    asym = +(T)3*mNeq[2]-(T)9*mNeq[10];
    f[2]  -= D::t[2]  * (sym + asym);
    f[11] -= D::t[11] * (sym - asym);

    sym  = -mNeq[0]+(T)1.5*mNeq[4]+(T)1.5*mNeq[7]-(T)3*mNeq[9]+(T)6*mNeq[16]+13.5*mNeq[17]+(T)27*mNeq[18];
    asym = +(T)3*mNeq[3]-(T)9*mNeq[12];
    f[3]  -= D::t[3]  * (sym + asym);
    f[12] -= D::t[12] * (sym - asym);

    sym  = -mNeq[0]-(T)3*mNeq[4]-(T)9*mNeq[5]-(T)3*mNeq[7]+(T)1.5*mNeq[9]-(T)3*mNeq[16]+13.5*mNeq[17]+(T)27*mNeq[18];
    asym = +(T)3*mNeq[1]+(T)3*mNeq[2]+(T)4.5*(mNeq[10]+mNeq[11]+mNeq[13]-mNeq[14]);
    f[4]  -= D::t[4]  * (sym + asym);
    f[13] -= D::t[13] * (sym - asym);

    sym  = -mNeq[0]-(T)3*mNeq[4]+(T)9*mNeq[5]-(T)3*mNeq[7]+(T)1.5*mNeq[9]-(T)3*mNeq[16]+13.5*mNeq[17]+(T)27*mNeq[18];
    asym = +(T)3*mNeq[1]-(T)3*mNeq[2]-(T)4.5*(mNeq[10]-mNeq[11]+mNeq[13]+mNeq[14]);
    f[5]  -= D::t[5]  * (sym + asym);
    f[14] -= D::t[14] * (sym - asym);
    
    sym  = -mNeq[0]-(T)3*mNeq[4]-(T)9*mNeq[6]+(T)1.5*mNeq[7]-(T)3*mNeq[9]-(T)3*mNeq[16]+13.5*mNeq[17]-(T)27*mNeq[18];
    asym = +(T)3*mNeq[1]+(T)3*mNeq[3]+(T)4.5*(mNeq[11]+mNeq[12]+mNeq[14]-mNeq[15]);
    f[6]  -= D::t[6]  * (sym + asym);
    f[15] -= D::t[15] * (sym - asym);

    sym  = -mNeq[0]-(T)3*mNeq[4]+(T)9*mNeq[6]+(T)1.5*mNeq[7]-(T)3*mNeq[9]-(T)3*mNeq[16]+13.5*mNeq[17]-(T)27*mNeq[18];
    asym = +(T)3*mNeq[1]-(T)3*mNeq[3]+(T)4.5*(mNeq[11]-mNeq[12]+mNeq[14]+mNeq[15]);
    f[7]  -= D::t[7]  * (sym + asym);
    f[16] -= D::t[16] * (sym - asym);

    sym  = -mNeq[0]+(T)1.5*mNeq[4]-(T)3*mNeq[7]-(T)9*mNeq[8]-(T)3*mNeq[9]-(T)3*mNeq[16]-(T)27*mNeq[17];
    asym = +(T)3*mNeq[2]+(T)3*mNeq[3]+(T)4.5*(mNeq[10]+mNeq[12]-mNeq[13]+mNeq[15]);
    f[8]  -= D::t[8]  * (sym + asym);
    f[17] -= D::t[17] * (sym - asym);

    sym  = -mNeq[0]+(T)1.5*mNeq[4]-(T)3*mNeq[7]+(T)9*mNeq[8]-(T)3*mNeq[9]-(T)3*mNeq[16]-(T)27*mNeq[17];
    asym = +(T)3*mNeq[2]-(T)3*mNeq[3]+(T)4.5*(mNeq[10]-mNeq[12]-mNeq[13]-mNeq[15]);
    f[9]  -= D::t[9]  * (sym + asym);
    f[18] -= D::t[18] * (sym - asym);
}

static void computeInvMmNeqToPopNoRhoJ(const Array<T,D::q> &mNeq, Array<T,D::q> &f) {
    f[0] -= D::t[0]*(+(T)1.5*(mNeq[4]+mNeq[7]+mNeq[9])-(T)3*mNeq[16]);

    T sym  = -(T)3*mNeq[4]+(T)1.5*(mNeq[7]+mNeq[9])+(T)6*mNeq[16]-(T)27*mNeq[17];
    T asym = -(T)9*mNeq[11];
    f[1]  -= D::t[1]  * (sym+asym);
    f[10] -= D::t[10] * (sym-asym);

    sym  = +(T)1.5*mNeq[4]-(T)3*mNeq[7]+(T)1.5*mNeq[9]+(T)6*mNeq[16]+13.5*mNeq[17]-(T)27*mNeq[18];
    asym = -(T)9*mNeq[10];
    f[2]  -= D::t[2]  * (sym + asym);
    f[11] -= D::t[11] * (sym - asym);

    sym  = +(T)1.5*mNeq[4]+(T)1.5*mNeq[7]-(T)3*mNeq[9]+(T)6*mNeq[16]+13.5*mNeq[17]+(T)27*mNeq[18];
    asym = -(T)9*mNeq[12];
    f[3]  -= D::t[3]  * (sym + asym);
    f[12] -= D::t[12] * (sym - asym);

    sym  = -(T)3*mNeq[4]-(T)9*mNeq[5]-(T)3*mNeq[7]+(T)1.5*mNeq[9]-(T)3*mNeq[16]+13.5*mNeq[17]+(T)27*mNeq[18];
    asym = +(T)4.5*(mNeq[10]+mNeq[11]+mNeq[13]-mNeq[14]);
    f[4]  -= D::t[4]  * (sym + asym);
    f[13] -= D::t[13] * (sym - asym);

    sym  = -(T)3*mNeq[4]+(T)9*mNeq[5]-(T)3*mNeq[7]+(T)1.5*mNeq[9]-(T)3*mNeq[16]+13.5*mNeq[17]+(T)27*mNeq[18];
    asym = -(T)4.5*(mNeq[10]-mNeq[11]+mNeq[13]+mNeq[14]);
    f[5]  -= D::t[5]  * (sym + asym);
    f[14] -= D::t[14] * (sym - asym);
    
    sym  = -(T)3*mNeq[4]-(T)9*mNeq[6]+(T)1.5*mNeq[7]-(T)3*mNeq[9]-(T)3*mNeq[16]+13.5*mNeq[17]-(T)27*mNeq[18];
    asym = +(T)4.5*(mNeq[11]+mNeq[12]+mNeq[14]-mNeq[15]);
    f[6]  -= D::t[6]  * (sym + asym);
    f[15] -= D::t[15] * (sym - asym);

    sym  = -(T)3*mNeq[4]+(T)9*mNeq[6]+(T)1.5*mNeq[7]-(T)3*mNeq[9]-(T)3*mNeq[16]+13.5*mNeq[17]-(T)27*mNeq[18];
    asym = +(T)4.5*(mNeq[11]-mNeq[12]+mNeq[14]+mNeq[15]);
    f[7]  -= D::t[7]  * (sym + asym);
    f[16] -= D::t[16] * (sym - asym);

    sym  = +(T)1.5*mNeq[4]-(T)3*mNeq[7]-(T)9*mNeq[8]-(T)3*mNeq[9]-(T)3*mNeq[16]-(T)27*mNeq[17];
    asym = +(T)4.5*(mNeq[10]+mNeq[12]-mNeq[13]+mNeq[15]);
    f[8]  -= D::t[8]  * (sym + asym);
    f[17] -= D::t[17] * (sym - asym);

    sym  = +(T)1.5*mNeq[4]-(T)3*mNeq[7]+(T)9*mNeq[8]-(T)3*mNeq[9]-(T)3*mNeq[16]-(T)27*mNeq[17];
    asym = +(T)4.5*(mNeq[10]-mNeq[12]-mNeq[13]-mNeq[15]);
    f[9]  -= D::t[9]  * (sym + asym);
    f[18] -= D::t[18] * (sym - asym);
}

static Array<T,SymmetricTensorImpl<T,D::d>::n> computeStrainRate(T rhoBar, T invRho, const Array<T,D::d> &j, const Array<T,D::q> &mom, T cSmago, T tau) {
    typedef SymmetricTensorImpl<T,D::d> S;
    Array<T,S::n> piNeq;
    piNeq[S::xx] = mom[4+S::xx]-j[0]*j[0]*invRho;
    piNeq[S::xy] = mom[4+S::xy]-j[0]*j[1]*invRho;
    piNeq[S::xz] = mom[4+S::xz]-j[0]*j[2]*invRho;
    piNeq[S::yy] = mom[4+S::yy]-j[1]*j[1]*invRho;
    piNeq[S::yz] = mom[4+S::yz]-j[1]*j[2]*invRho;
    piNeq[S::zz] = mom[4+S::zz]-j[2]*j[2]*invRho;
    
    T rho = D::fullRho(rhoBar);
    
    T normPiNeq = std::sqrt((T)2*SymmetricTensorImpl<T,D::d>::tensorNormSqr(piNeq));
    normPiNeq *= (T)2*rho*util::sqr<T>(D::cs2*cSmago*cSmago);
    
    if (normPiNeq != T()) { // test to avoid division per 0
        piNeq = -(-rho*tau*D::cs2+std::sqrt(util::sqr<T>(rho*tau*D::cs2)+normPiNeq)) / normPiNeq * piNeq;
    }

    return piNeq;
}

static void addSmagorinskyMoments( Array<T,D::q>& momEq, const Array<T,6> &strain, T cSmago )
{
    typedef SymmetricTensorImpl<T,3> S;
    
    T rho = D::fullRho(momEq[0]);
    
    T sNorm = std::sqrt((T)2*SymmetricTensorImpl<T,3>::tensorNormSqr(strain));
    T smagoFactor = -(T)2*rho * cSmago * cSmago * sNorm;
    
    T ux2 = smagoFactor * strain[S::xx];
    T uy2 = smagoFactor * strain[S::yy];
    T uz2 = smagoFactor * strain[S::zz];
    
    T uxuy = smagoFactor * strain[S::xy];
    T uyuz = smagoFactor * strain[S::yz];
    T uxuz = smagoFactor * strain[S::xz];
    
    momEq[4] += ux2;
    momEq[5] += uxuy;
    momEq[6] += uxuz;

    momEq[7] += uy2;
    momEq[8] += uyuz;
    momEq[9] += uz2;
}

static T bgk_ma2_collision_base(Array<T,D::q>& f, T rhoBar, Array<T,3> const& j, T omega, T invRho) {
    T one_m_omega = (T)1 - omega;
    T t0_omega = D::t[0] * omega;
    T t1_omega = D::t[1] * omega;
    T t4_omega = D::t[4] * omega;

    T jSqr   = j[0]*j[0] + j[1]*j[1] + j[2]*j[2];
    T kx     = (T)3 * j[0];
    T ky     = (T)3 * j[1];
    T kz     = (T)3 * j[2];
    T kxSqr_ = invRho / (T)2 * kx*kx;
    T kySqr_ = invRho / (T)2 * ky*ky;
    T kzSqr_ = invRho / (T)2 * kz*kz;
    T kxky_  = invRho * kx*ky;
    T kxkz_  = invRho * kx*kz;
    T kykz_  = invRho * ky*kz;

    T C1 = rhoBar + invRho*(T)3*jSqr;
    T C2, C3;

    // i=0
    C3 = -kxSqr_ - kySqr_ - kzSqr_;
    f[0] *= one_m_omega; f[0] += t0_omega * (C1+C3);

    // i=1 and i=10
    C2 = -kx;
    C3 = -kySqr_ - kzSqr_;
    f[1]  *= one_m_omega; f[1]  += t1_omega * (C1+C2+C3);
    f[10] *= one_m_omega; f[10] += t1_omega * (C1-C2+C3);

    // i=2 and i=11
    C2 = -ky;
    C3 = -kxSqr_ - kzSqr_;
    f[2]  *= one_m_omega; f[2]  += t1_omega * (C1+C2+C3);
    f[11] *= one_m_omega; f[11] += t1_omega * (C1-C2+C3);

    // i=3 and i=12
    C2 = -kz;
    C3 = -kxSqr_ - kySqr_;
    f[3]  *= one_m_omega; f[3]  += t1_omega * (C1+C2+C3);
    f[12] *= one_m_omega; f[12] += t1_omega * (C1-C2+C3);

    // i=4 and i=13
    C2 = -kx - ky;
    C3 = kxky_ - kzSqr_;
    f[4]  *= one_m_omega; f[4]  += t4_omega * (C1+C2+C3);
    f[13] *= one_m_omega; f[13] += t4_omega * (C1-C2+C3);

    // i=5 and i=14
    C2 = -kx + ky;
    C3 = -kxky_ - kzSqr_;
    f[5]  *= one_m_omega; f[5]  += t4_omega * (C1+C2+C3);
    f[14] *= one_m_omega; f[14] += t4_omega * (C1-C2+C3);

    // i=6 and i=15
    C2 = -kx - kz;
    C3 = kxkz_ - kySqr_;
    f[6]  *= one_m_omega; f[6]  += t4_omega * (C1+C2+C3);
    f[15] *= one_m_omega; f[15] += t4_omega * (C1-C2+C3);

    // i=7 and i=16
    C2 = -kx + kz;
    C3 = -kxkz_ - kySqr_;
    f[7]  *= one_m_omega; f[7]  += t4_omega * (C1+C2+C3);
    f[16] *= one_m_omega; f[16] += t4_omega * (C1-C2+C3);

    // i=8 and i=17
    C2 = -ky - kz;
    C3 = kykz_ - kxSqr_;
    f[8]  *= one_m_omega; f[8]  += t4_omega * (C1+C2+C3);
    f[17] *= one_m_omega; f[17] += t4_omega * (C1-C2+C3);

    // i=9 and i=18
    C2 = -ky + kz;
    C3 = -kykz_ - kxSqr_;
    f[9]  *= one_m_omega; f[9]  += t4_omega * (C1+C2+C3);
    f[18] *= one_m_omega; f[18] += t4_omega * (C1-C2+C3);

    return invRho*invRho*jSqr;
}

static T truncated_mrt_ma2_collision_base(Array<T,D::q>& f, T omega, T omegaNonPhys, plint iPhys) {
    Array<T,D::q> mNeq, mEq;
    complete_ma2_moments(f, mNeq);
    T invRho = D::invRho(mNeq[0]);
    truncated_ma2_equilibrium_moments(mNeq[0], invRho, Array<T,D::d>(mNeq[1],mNeq[2],mNeq[3]), mEq);
    
    T jSqr = mNeq[1]*mNeq[1] + mNeq[2]*mNeq[2] + mNeq[3]*mNeq[3];
    
    for (plint iPop = 1+D::d; iPop <= iPhys; ++iPop) {
        mNeq[iPop] -= mEq[iPop];
        mNeq[iPop] *= -omega;
    }
    
    for (plint iPop = iPhys+1; iPop < D::q; ++iPop) {
        mNeq[iPop] -= mEq[iPop];
        mNeq[iPop] *= -omegaNonPhys;
    }
        
    computeInvMmNeqToPopNoRhoJ(mNeq,f);
    
    return invRho*invRho*jSqr;
}

static T truncated_mrt_ma2_ext_rhoBar_j_collision_base(Array<T,D::q>& f, T rhoBar, Array<T,D::d> const &j, T omega, T omegaNonPhys, plint iPhys) {
    Array<T,D::q> mNeq, mEq;
    complete_ma2_moments(f, mNeq);
    T invRho = D::invRho(rhoBar);
    truncated_ma2_equilibrium_moments(rhoBar, invRho, j, mEq);
    
    T jSqr = j[0]*j[0]+j[1]*j[1]+j[2]*j[2];
    
//     plint iPhys = 16; // max moment to relax with omega
    for (plint iPop = 0; iPop <= iPhys; ++iPop) {
        mNeq[iPop] -= mEq[iPop];
        mNeq[iPop] *= -omega;
    }
    
    for (plint iPop = iPhys+1; iPop < D::q; ++iPop) {
        mNeq[iPop] -= mEq[iPop];
        mNeq[iPop] *= -omegaNonPhys;
    }
        
    computeInvMmNeqToPop(mNeq,f);
    
    return invRho*invRho*jSqr;
}

static T truncated_mrt_smagorinsky_ma2_collision_base(Array<T,D::q>& f, T cSmago, T omega, T omegaNonPhys, plint iPhys) {
    Array<T,D::q> mNeq, mEq;
    complete_ma2_moments(f, mNeq);
    T invRho = D::invRho(mNeq[0]);
    truncated_ma2_equilibrium_moments(mNeq[0], invRho, Array<T,D::d>(mNeq[1],mNeq[2],mNeq[3]), mEq);

    Array<T,SymmetricTensorImpl<T,D::d>::n> S = 
        computeStrainRate(mNeq[0], invRho, Array<T,D::d>(mNeq[1],mNeq[2],mNeq[3]), mNeq, cSmago, (T)1/omega);
    
    addSmagorinskyMoments( mEq, S, cSmago );
    
    T jSqr = mNeq[1]*mNeq[1] + mNeq[2]*mNeq[2] + mNeq[3]*mNeq[3];
    
    for (plint iPop = 1+D::d; iPop <= iPhys; ++iPop) {
        mNeq[iPop] -= mEq[iPop];
        mNeq[iPop] *= -omega;
    }
    
    for (plint iPop = iPhys+1; iPop < D::q; ++iPop) {
        mNeq[iPop] -= mEq[iPop];
        mNeq[iPop] *= -omegaNonPhys;
    }
        
    computeInvMmNeqToPopNoRhoJ(mNeq,f);
    
    return invRho*invRho*jSqr;
}

static T truncated_mrt_smagorinsky_ma2_ext_rhoBar_j_collision_base(Array<T,D::q>& f, T rhoBar, Array<T,D::d> const &j, T cSmago, T omega, T omegaNonPhys, plint iPhys) {
    Array<T,D::q> mNeq, mEq;
    complete_ma2_moments(f, mNeq);
    T invRho = D::invRho(rhoBar);
    truncated_ma2_equilibrium_moments(rhoBar, invRho, j, mEq);
    
    Array<T,SymmetricTensorImpl<T,D::d>::n> S = 
        computeStrainRate(mNeq[0], D::invRho(mNeq[0]), Array<T,D::d>(mNeq[1],mNeq[2],mNeq[3]), mNeq, cSmago, (T)1/omega);
    
    addSmagorinskyMoments( mEq, S, cSmago );
    
    
    T jSqr = j[0]*j[0]+j[1]*j[1]+j[2]*j[2];
    
    // iPhys max moment to relax with omega
    for (plint iPop = 0; iPop <= iPhys; ++iPop) {
        mNeq[iPop] -= mEq[iPop];
        mNeq[iPop] *= -omega;
    }
    
    for (plint iPop = iPhys+1; iPop < D::q; ++iPop) {
        mNeq[iPop] -= mEq[iPop];
        mNeq[iPop] *= -omegaNonPhys;
    }
        
    computeInvMmNeqToPop(mNeq,f);
    
    return invRho*invRho*jSqr;
}


static T bgk_ma2_collision(Array<T,D::q>& f, T rhoBar, Array<T,3> const& j, T omega) {
    return bgk_ma2_collision_base(f, rhoBar, j, omega, D::invRho(rhoBar));
}

static T bgk_inc_collision(Array<T,D::q>& f, T rhoBar, Array<T,3> const& j, T omega, T invRho0=(T)1 ) {
    return bgk_ma2_collision_base(f, rhoBar, j, omega, invRho0);
}

static T truncated_mrt_ma2_collision(Array<T,D::q>& f, T omega, T omegaNonPhys, plint iPhys) {
    return truncated_mrt_ma2_collision_base(f, omega, omegaNonPhys, iPhys);
}

static T truncated_mrt_ma2_ext_rhoBar_j_collision(Array<T,D::q>& f, T rhoBar, Array<T,D::d> const& j, T omega, T omegaNonPhys, plint iPhys) {
    return truncated_mrt_ma2_ext_rhoBar_j_collision_base(f, rhoBar, j, omega, omegaNonPhys, iPhys);
}

static T truncated_mrt_smagorinsky_ma2_collision(Array<T,D::q>& f, T cSmago, T omega, T omegaNonPhys, plint iPhys) {
    return truncated_mrt_smagorinsky_ma2_collision_base(f, cSmago, omega, omegaNonPhys, iPhys);
}

static T truncated_mrt_smagorinsky_ma2_ext_rhoBar_j_collision(Array<T,D::q>& f, T rhoBar, Array<T,D::d> const& j, T cSmago, T omega, T omegaNonPhys, plint iPhys) {
    return truncated_mrt_smagorinsky_ma2_ext_rhoBar_j_collision_base(f, rhoBar, j, cSmago, omega, omegaNonPhys, iPhys);
}

static T rlb_collision(Array<T,D::q>& f, T rhoBar, T invRho, Array<T,3> const& j, Array<T,6> const& PiNeq, T omega ) {
    typedef dynamicsTemplatesImpl<T, descriptors::D3Q19DescriptorBase<T> > DH;
    const T jSqr = j[0]*j[0] + j[1]*j[1] + j[2]*j[2];

    T piNeq0 = neqPiD3Q19<T>::fromPiToFneq0(PiNeq);
    T piNeq1 = neqPiD3Q19<T>::fromPiToFneq1(PiNeq);
    T piNeq2 = neqPiD3Q19<T>::fromPiToFneq2(PiNeq);
    T piNeq3 = neqPiD3Q19<T>::fromPiToFneq3(PiNeq);
    T piNeq4 = neqPiD3Q19<T>::fromPiToFneq4(PiNeq);
    T piNeq5 = neqPiD3Q19<T>::fromPiToFneq5(PiNeq);
    T piNeq6 = neqPiD3Q19<T>::fromPiToFneq6(PiNeq);
    T piNeq7 = neqPiD3Q19<T>::fromPiToFneq7(PiNeq);
    T piNeq8 = neqPiD3Q19<T>::fromPiToFneq8(PiNeq);
    T piNeq9 = neqPiD3Q19<T>::fromPiToFneq9(PiNeq);

    f[0]  = DH::bgk_ma2_equilibrium(0, rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq0;
    f[1]  = DH::bgk_ma2_equilibrium(1, rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq1;
    f[2]  = DH::bgk_ma2_equilibrium(2, rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq2;
    f[3]  = DH::bgk_ma2_equilibrium(3, rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq3;
    f[4]  = DH::bgk_ma2_equilibrium(4, rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq4;
    f[5]  = DH::bgk_ma2_equilibrium(5, rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq5;
    f[6]  = DH::bgk_ma2_equilibrium(6, rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq6;
    f[7]  = DH::bgk_ma2_equilibrium(7, rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq7;
    f[8]  = DH::bgk_ma2_equilibrium(8, rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq8;
    f[9]  = DH::bgk_ma2_equilibrium(9, rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq9;
    f[10]  = DH::bgk_ma2_equilibrium(10, rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq1;
    f[11]  = DH::bgk_ma2_equilibrium(11, rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq2;
    f[12]  = DH::bgk_ma2_equilibrium(12, rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq3;
    f[13]  = DH::bgk_ma2_equilibrium(13, rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq4;
    f[14]  = DH::bgk_ma2_equilibrium(14, rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq5;
    f[15]  = DH::bgk_ma2_equilibrium(15, rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq6;
    f[16]  = DH::bgk_ma2_equilibrium(16, rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq7;
    f[17]  = DH::bgk_ma2_equilibrium(17, rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq8;
    f[18]  = DH::bgk_ma2_equilibrium(18, rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq9;
    return jSqr*invRho*invRho;
}

static T bgk_ma2_constRho_collision (
        Array<T,D::q>& f, T rhoBar, Array<T,D::d> const& j, T ratioRho, T omega )
{
    T invRho = D::invRho(rhoBar);
    const T jSqr = j[0]*j[0] + j[1]*j[1] + j[2]*j[2];
    for (plint iPop=0; iPop < D::q; ++iPop) {
        T feq = bgk_ma2_equilibrium(iPop, rhoBar, invRho, j, jSqr );
        f[iPop] =
          ratioRho*feq + D::t[iPop]*(ratioRho-(T)1) +
          ((T)1-omega)*(f[iPop]-feq);
    }
    return jSqr*invRho*invRho;
}


static T precond_bgk_ma2_equilibrium(plint iPop, T rhoBar, T invRho, Array<T,3> const& j, T jSqr, T invGamma ) {
    T c_j = D::c[iPop][0]*j[0] + D::c[iPop][1]*j[1] + D::c[iPop][2]*j[2];
    return D::t[iPop] * ( rhoBar + 3.*c_j + invGamma*invRho*(4.5*c_j*c_j - 1.5*jSqr) );
}

static T precond_bgk_ma2_collision_base( Array<T,D::q>& f, T rhoBar, Array<T,3> const& j, T omega,
                                         T invGamma, bool incompressible )
{
    T invRho = incompressible ? (T)1 : D::invRho(rhoBar);
    T one_m_omega = (T)1 - omega;
    T t0_omega = D::t[0] * omega;
    T t1_omega = D::t[1] * omega;
    T t4_omega = D::t[4] * omega;

    T jSqr   = j[0]*j[0] + j[1]*j[1] + j[2]*j[2];
    T kx     = (T)3 * j[0];
    T ky     = (T)3 * j[1];
    T kz     = (T)3 * j[2];
    T kxSqr_ = invGamma* invRho / (T)2 * kx*kx;
    T kySqr_ = invGamma* invRho / (T)2 * ky*ky;
    T kzSqr_ = invGamma* invRho / (T)2 * kz*kz;
    T kxky_  = invGamma* invRho * kx*ky;
    T kxkz_  = invGamma* invRho * kx*kz;
    T kykz_  = invGamma* invRho * ky*kz;

    T C1 = rhoBar + invGamma*invRho*(T)3*jSqr;
    T C2, C3;

    // i=0
    C3 = -kxSqr_ - kySqr_ - kzSqr_;
    f[0] *= one_m_omega; f[0] += t0_omega * (C1+C3);

    // i=1 and i=10
    C2 = -kx;
    C3 = -kySqr_ - kzSqr_;
    f[1]  *= one_m_omega; f[1]  += t1_omega * (C1+C2+C3);
    f[10] *= one_m_omega; f[10] += t1_omega * (C1-C2+C3);

    // i=2 and i=11
    C2 = -ky;
    C3 = -kxSqr_ - kzSqr_;
    f[2]  *= one_m_omega; f[2]  += t1_omega * (C1+C2+C3);
    f[11] *= one_m_omega; f[11] += t1_omega * (C1-C2+C3);

    // i=3 and i=12
    C2 = -kz;
    C3 = -kxSqr_ - kySqr_;
    f[3]  *= one_m_omega; f[3]  += t1_omega * (C1+C2+C3);
    f[12] *= one_m_omega; f[12] += t1_omega * (C1-C2+C3);

    // i=4 and i=13
    C2 = -kx - ky;
    C3 = kxky_ - kzSqr_;
    f[4]  *= one_m_omega; f[4]  += t4_omega * (C1+C2+C3);
    f[13] *= one_m_omega; f[13] += t4_omega * (C1-C2+C3);

    // i=5 and i=14
    C2 = -kx + ky;
    C3 = -kxky_ - kzSqr_;
    f[5]  *= one_m_omega; f[5]  += t4_omega * (C1+C2+C3);
    f[14] *= one_m_omega; f[14] += t4_omega * (C1-C2+C3);

    // i=6 and i=15
    C2 = -kx - kz;
    C3 = kxkz_ - kySqr_;
    f[6]  *= one_m_omega; f[6]  += t4_omega * (C1+C2+C3);
    f[15] *= one_m_omega; f[15] += t4_omega * (C1-C2+C3);

    // i=7 and i=16
    C2 = -kx + kz;
    C3 = -kxkz_ - kySqr_;
    f[7]  *= one_m_omega; f[7]  += t4_omega * (C1+C2+C3);
    f[16] *= one_m_omega; f[16] += t4_omega * (C1-C2+C3);

    // i=8 and i=17
    C2 = -ky - kz;
    C3 = kykz_ - kxSqr_;
    f[8]  *= one_m_omega; f[8]  += t4_omega * (C1+C2+C3);
    f[17] *= one_m_omega; f[17] += t4_omega * (C1-C2+C3);

    // i=9 and i=18
    C2 = -ky + kz;
    C3 = -kykz_ - kxSqr_;
    f[9]  *= one_m_omega; f[9]  += t4_omega * (C1+C2+C3);
    f[18] *= one_m_omega; f[18] += t4_omega * (C1-C2+C3);

    return invRho*invRho*jSqr;
}

static T precond_bgk_ma2_collision(Array<T,D::q>& f, T rhoBar, Array<T,3> const& j, T omega, T invGamma)
{
    return precond_bgk_ma2_collision_base(f, rhoBar, j, omega, invGamma, false);
}

};  //struct dynamicsTemplatesImpl<D3Q19DescriptorBase>


/// Compute Pi tensor efficiently on D3Q15 lattice
template<typename T>
struct neqPiD3Q15 {

    typedef SymmetricTensorImpl<T,3> S;

    static T fromPiToFneq0(Array<T,6> const& pi) {
        return -(T)1./(T)3*pi[S::xx] - (T)1./(T)3*pi[S::yy] - (T)1./(T)3*pi[S::zz];
    }

    static T fromPiToFneq1(Array<T,6> const& pi) {
        return (T)1./(T)2 * (
                  (T)2./(T)3*pi[S::xx] - (T)1./(T)3*pi[S::yy] - (T)1./(T)3*pi[S::zz]
               );
    }

    static T fromPiToFneq2(Array<T,6> const& pi) {
        return (T)1./(T)2 * (
                 -(T)1./(T)3*pi[S::xx] + (T)2./(T)3*pi[S::yy] - (T)1./(T)3*pi[S::zz]
               );
    }

    static T fromPiToFneq3(Array<T,6> const& pi) {
        return (T)1./(T)2 * (
                 -(T)1./(T)3*pi[S::xx] - (T)1./(T)3*pi[S::yy] + (T)2./(T)3*pi[S::zz]
               );
    }

    static T fromPiToFneq4(Array<T,6> const& pi) {
        return (T)1./(T)16 * (
                  (T)2./(T)3*pi[S::xx] + (T)2./(T)3*pi[S::yy] + (T)2./(T)3*pi[S::zz]
                  + pi[S::xy] + pi[S::xz] + pi[S::yz]
               );
    }

    static T fromPiToFneq5(Array<T,6> const& pi) {
        return (T)1./(T)16 * (
                  (T)2./(T)3*pi[S::xx] + (T)2./(T)3*pi[S::yy] + (T)2./(T)3*pi[S::zz]
                  + pi[S::xy] - pi[S::xz] - pi[S::yz]
               );
    }

    static T fromPiToFneq6(Array<T,6> const& pi) {
        return (T)1./(T)16 * (
                  (T)2./(T)3*pi[S::xx] + (T)2./(T)3*pi[S::yy] + (T)2./(T)3*pi[S::zz]
                  - pi[S::xy] + pi[S::xz] - pi[S::yz]
               );
    }

    static T fromPiToFneq7(Array<T,6> const& pi) {
        return (T)1./(T)16 * (
                  (T)2./(T)3*pi[S::xx] + (T)2./(T)3*pi[S::yy] + (T)2./(T)3*pi[S::zz]
                  - pi[S::xy] - pi[S::xz] + pi[S::yz]
               );
    }

};  // struct neqPiD3Q15


// Efficient specialization for D3Q15 lattice
template<typename T>
struct dynamicsTemplatesImpl<T, descriptors::D3Q15DescriptorBase<T> > {

typedef descriptors::D3Q15DescriptorBase<T> D;

static T computePsiTruncated(T omega) {
    T psi = T();
    if (omega > (T)1.6) {
        psi = 100.1865060434029*omega*omega*omega*omega-738.0484628214889*omega*omega*omega+2029.504859915939*omega*omega-2465.410637079084*omega+1116.205440371878;
    } else {
        psi = -.1941813472036123*omega*omega*omega*omega+1.839142984158318*omega*omega*omega-4.542040615751992*omega*omega+3.739828693512141*omega;
    }
    if (psi > (T)2) psi = (T)2;
    return psi;
}

static T bgk_ma2_equilibrium(plint iPop, T rhoBar, T invRho, Array<T,3> const& j, T jSqr ) {
    T c_j = D::c[iPop][0]*j[0] + D::c[iPop][1]*j[1] + D::c[iPop][2]*j[2];
    return D::t[iPop] * ( rhoBar + 3.*c_j + invRho*(4.5*c_j*c_j - 1.5*jSqr) );
}

static void truncated_ma2_equilibrium_moments( T rhoBar, T invRho, Array<T,D::d> const& j,
                                               Array<T,D::q>& momEq )
{
    T ux = j[0]*invRho;
    T uy = j[1]*invRho;
    T uz = j[2]*invRho;
    
    momEq.resetToZero();
    
    momEq[0]=rhoBar;
    momEq[1]=j[0];
    momEq[2]=j[1];
    momEq[3]=j[2];
    momEq[4]=j[0]*ux;
    momEq[5]=j[0]*uy;
    momEq[6]=j[0]*uz;

    momEq[7]=j[1]*uy;
    momEq[8]=j[1]*uz;
    momEq[9]=j[2]*uz;
}

static void complete_ma2_moments( Array<T,D::q>& f, Array<T,D::q>& mom )
{
    T f_11_12_13_14 = f[11]+f[12]+f[13]+f[14];
    T f_4_5_6_7 = f[4]+f[5]+f[6]+f[7];
    T f_1_2_3_8_9_10 = f[1]+f[2]+f[3]+f[8]+f[9]+f[10];
    mom[0] = f[0]+f_1_2_3_8_9_10+f_4_5_6_7+f_11_12_13_14;

    T f_11_12_m13_m14 = f[11]+f[12]-f[13]-f[14];
    T f_11_m12_13_m14 = f[11]-f[12]+f[13]-f[14];

    T f_m4_m5_6_7 = -f[4]-f[5]+f[6]+f[7];
    T f_m4_5_m6_7 = -f[4]+f[5]-f[6]+f[7];

    mom[1] = -f[1]-f_4_5_6_7+f[8]+f_11_12_13_14;
    mom[2] = -f[2]+f_m4_m5_6_7+f[9]+f_11_12_m13_m14;
    mom[3] = -f[3]+f_m4_5_m6_7+f[10]+f_11_m12_13_m14;

    T f_11_m12_m13_14 = f[11]-f[12]-f[13]+f[14];
    T f_4_m5_m6_7 = f[4]-f[5]-f[6]+f[7];
    mom[5] = -f_m4_m5_6_7+f_11_12_m13_m14;
    mom[6] = -f_m4_5_m6_7+f_11_m12_13_m14;
    mom[8] = f_4_m5_m6_7+f_11_m12_m13_14;

    mom[4] = D::cs2*(-f[0]-f_1_2_3_8_9_10+(T)3*(f[1]+f[8])+(T)2*(f_4_5_6_7+f_11_12_13_14));
    mom[7] = D::cs2*(-f[0]-f_1_2_3_8_9_10+(T)3*(f[2]+f[9])+(T)2*(f_4_5_6_7+f_11_12_13_14));
    mom[9] = D::cs2*(-f[0]-f_1_2_3_8_9_10+(T)3*(f[3]+f[10])+(T)2*(f_4_5_6_7+f_11_12_13_14));
    

    mom[10] = (T)2*D::cs2*(f[2]-f[9]+(T)2*(f_m4_m5_6_7+f_11_12_m13_m14));
    mom[11] = (T)2*D::cs2*(f[1]-f[8]+(T)2*(-f_4_5_6_7+f_11_12_13_14));
    mom[12] = (T)2*D::cs2*(f[3]-f[10]+(T)2*(f_m4_5_m6_7+f_11_m12_13_m14));

    mom[13] = D::cs2*(-f_1_2_3_8_9_10+(T)2*(f[0]+f_4_5_6_7+f_11_12_13_14));

    mom[14] = -f_4_m5_m6_7+f_11_m12_m13_14;
}

static void computeInvMmNeqToPop(const Array<T,D::q> &mNeq, Array<T,D::q> &f) {
    f[0]  -= D::t[0]*(-mNeq[0]+(T)1.5*mNeq[4]+(T)1.5*mNeq[7]+(T)1.5*mNeq[9]-(T)3*mNeq[13]);

    T sym  = -mNeq[0]-(T)3*mNeq[4]+(T)1.5*mNeq[7]+(T)1.5*mNeq[9]+(T)1.5*mNeq[13];
    T asym = (T)3*mNeq[1]-2.25*mNeq[11];
    f[1]  -= D::t[1]*(sym + asym);
    f[8]  -= D::t[8]*(sym - asym);

    sym  = -mNeq[0]+(T)1.5*mNeq[4]-(T)3*mNeq[7]+(T)1.5*mNeq[9]+(T)1.5*mNeq[13];
    asym = (T)3*mNeq[2]-2.25*mNeq[10];
    f[2]  -= D::t[2]*(sym + asym);
    f[9]  -= D::t[9]*(sym - asym);

    sym  = -mNeq[0]+(T)1.5*mNeq[4]+(T)1.5*mNeq[7]-(T)3*mNeq[9]+(T)1.5*mNeq[13];
    asym = (T)3*mNeq[3]-2.25*mNeq[12];
    f[3]  -= D::t[3] *(sym+asym);
    f[10] -= D::t[10]*(sym-asym);

    sym  = -mNeq[0]-(T)3*mNeq[4]-(T)9*mNeq[5]-(T)9*mNeq[6]-(T)3*mNeq[7]-(T)9*mNeq[8]-(T)3*mNeq[9]-(T)3*mNeq[13];
    asym = (T)3*mNeq[1]+(T)3*mNeq[2]+(T)3*mNeq[3]+4.5*mNeq[10]+4.5*mNeq[11]+4.5*mNeq[12]+(T)9*mNeq[14];
    f[4]  -= D::t[4] *(sym+asym);
    f[11] -= D::t[11]*(sym-asym);

    sym  = -mNeq[0]-(T)3*mNeq[4]-(T)9*mNeq[5]+(T)9*mNeq[6]-(T)3*mNeq[7]+(T)9*mNeq[8]-(T)3*mNeq[9]-(T)3*mNeq[13];
    asym = (T)3*mNeq[1]+(T)3*mNeq[2]-(T)3*mNeq[3]+4.5*mNeq[10]+4.5*mNeq[11]-4.5*mNeq[12]-(T)9*mNeq[14];
    f[5]  -= D::t[5] *(sym+asym);
    f[12] -= D::t[12]*(sym-asym);

    sym  = -mNeq[0]-(T)3*mNeq[4]+(T)9*mNeq[5]-(T)9*mNeq[6]-(T)3*mNeq[7]+(T)9*mNeq[8]-(T)3*mNeq[9]-(T)3*mNeq[13];
    asym = (T)3*mNeq[1]-(T)3*mNeq[2]+(T)3*mNeq[3]-4.5*mNeq[10]+4.5*mNeq[11]+4.5*mNeq[12]-(T)9*mNeq[14];
    f[6]  -= D::t[6] *(sym+asym);
    f[13] -= D::t[13]*(sym-asym);

    sym  = -mNeq[0]-(T)3*mNeq[4]+(T)9*mNeq[5]+(T)9*mNeq[6]-(T)3*mNeq[7]-(T)9*mNeq[8]-(T)3*mNeq[9]-(T)3*mNeq[13];
    asym = (T)3*mNeq[1]-(T)3*mNeq[2]-(T)3*mNeq[3]-4.5*mNeq[10]+4.5*mNeq[11]-4.5*mNeq[12]+(T)9*mNeq[14];
    f[7]  -= D::t[7] *(sym+asym);
    f[14] -= D::t[14]*(sym-asym);
}

static void computeInvMmNeqToPopNoRhoJ(const Array<T,D::q> &mNeq, Array<T,D::q> &f) {
    f[0]  -= D::t[0]*((T)1.5*mNeq[4]+(T)1.5*mNeq[7]+(T)1.5*mNeq[9]-(T)3*mNeq[13]);

    T sym  = -(T)3*mNeq[4]+(T)1.5*mNeq[7]+(T)1.5*mNeq[9]+(T)1.5*mNeq[13];
    T asym = -2.25*mNeq[11];
    f[1]  -= D::t[1]*(sym + asym);
    f[8]  -= D::t[8]*(sym - asym);

    sym  = +(T)1.5*mNeq[4]-(T)3*mNeq[7]+(T)1.5*mNeq[9]+(T)1.5*mNeq[13];
    asym = -2.25*mNeq[10];
    f[2]  -= D::t[2]*(sym + asym);
    f[9]  -= D::t[9]*(sym - asym);

    sym  = +(T)1.5*mNeq[4]+(T)1.5*mNeq[7]-(T)3*mNeq[9]+(T)1.5*mNeq[13];
    asym = -2.25*mNeq[12];
    f[3]  -= D::t[3] *(sym+asym);
    f[10] -= D::t[10]*(sym-asym);

    sym  = -(T)3*mNeq[4]-(T)9*mNeq[5]-(T)9*mNeq[6]-(T)3*mNeq[7]-(T)9*mNeq[8]-(T)3*mNeq[9]-(T)3*mNeq[13];
    asym = +4.5*mNeq[10]+4.5*mNeq[11]+4.5*mNeq[12]+(T)9*mNeq[14];
    f[4]  -= D::t[4] *(sym+asym);
    f[11] -= D::t[11]*(sym-asym);

    sym  = -(T)3*mNeq[4]-(T)9*mNeq[5]+(T)9*mNeq[6]-(T)3*mNeq[7]+(T)9*mNeq[8]-(T)3*mNeq[9]-(T)3*mNeq[13];
    asym = +4.5*mNeq[10]+4.5*mNeq[11]-4.5*mNeq[12]-(T)9*mNeq[14];
    f[5]  -= D::t[5] *(sym+asym);
    f[12] -= D::t[12]*(sym-asym);

    sym  = -(T)3*mNeq[4]+(T)9*mNeq[5]-(T)9*mNeq[6]-(T)3*mNeq[7]+(T)9*mNeq[8]-(T)3*mNeq[9]-(T)3*mNeq[13];
    asym = -4.5*mNeq[10]+4.5*mNeq[11]+4.5*mNeq[12]-(T)9*mNeq[14];
    f[6]  -= D::t[6] *(sym+asym);
    f[13] -= D::t[13]*(sym-asym);

    sym  = -(T)3*mNeq[4]+(T)9*mNeq[5]+(T)9*mNeq[6]-(T)3*mNeq[7]-(T)9*mNeq[8]-(T)3*mNeq[9]-(T)3*mNeq[13];
    asym = -4.5*mNeq[10]+4.5*mNeq[11]-4.5*mNeq[12]+(T)9*mNeq[14];
    f[7]  -= D::t[7] *(sym+asym);
    f[14] -= D::t[14]*(sym-asym);
}

static void bgk_ma2_equilibria( T rhoBar, T invRho, Array<T,D::d> const& j,
                                T jSqr, Array<T,D::q>& eqPop )
{
    T t0 = D::t[0];
    T t1 = D::t[1];
    T t4 = D::t[4];

    T kx     = (T)3 * j[0];
    T ky     = (T)3 * j[1];
    T kz     = (T)3 * j[2];
    T kxSqr_ = invRho / (T)2 * kx*kx;
    T kySqr_ = invRho / (T)2 * ky*ky;
    T kzSqr_ = invRho / (T)2 * kz*kz;
    T kxky_  = invRho * kx*ky;
    T kxkz_  = invRho * kx*kz;
    T kykz_  = invRho * ky*kz;

    T C1 = rhoBar + invRho*(T)3*jSqr;
    T C2, C3;

    // i=0
    C3 = -kxSqr_ - kySqr_ - kzSqr_;
    eqPop[0] = t0 * (C1+C3);

    // i=1 and i=8
    C2 = -kx;
    C3 = -kySqr_ - kzSqr_;
    eqPop[1]  = t1 * (C1+C2+C3);
    eqPop[8]  = t1 * (C1-C2+C3);

    // i=2 and i=9
    C2 = -ky;
    C3 = -kxSqr_ - kzSqr_;
    eqPop[2]  = t1 * (C1+C2+C3);
    eqPop[9]  = t1 * (C1-C2+C3);

    // i=3 and i=10
    C2 = -kz;
    C3 = -kxSqr_ - kySqr_;
    eqPop[3]  = t1 * (C1+C2+C3);
    eqPop[10] = t1 * (C1-C2+C3);

    // i=4 and i=11
    C2 = -kx -ky -kz;
    C3 = kxky_ + kxkz_ + kykz_;
    eqPop[4]  = t4 * (C1+C2+C3);
    eqPop[11] = t4 * (C1-C2+C3);

    // i=5 and i=12
    C2 = -kx -ky +kz;
    C3 = kxky_ - kxkz_ - kykz_;
    eqPop[5]  = t4 * (C1+C2+C3);
    eqPop[12] = t4 * (C1-C2+C3);

    // i=6 and i=13
    C2 = -kx +ky -kz;
    C3 = -kxky_ + kxkz_ - kykz_;
    eqPop[6]  = t4 * (C1+C2+C3);
    eqPop[13] = t4 * (C1-C2+C3);

    // i=7 and i=14
    C2 = -kx +ky +kz;
    C3 = -kxky_ - kxkz_ + kykz_;
    eqPop[7]  = t4 * (C1+C2+C3);
    eqPop[14] = t4 * (C1-C2+C3);
}

static void addSmagorinskyMoments( Array<T,D::q>& momEq, const Array<T,6> &strain, T cSmago )
{
    typedef SymmetricTensorImpl<T,3> S;
    
    T rho = D::fullRho(momEq[0]);
    
    T sNorm = std::sqrt((T)2*SymmetricTensorImpl<T,3>::tensorNormSqr(strain));
    T smagoFactor = -(T)2*rho * cSmago * cSmago * sNorm;
    
    T ux2 = smagoFactor * strain[S::xx];
    T uy2 = smagoFactor * strain[S::yy];
    T uz2 = smagoFactor * strain[S::zz];
    
    T uxuy = smagoFactor * strain[S::xy];
    T uyuz = smagoFactor * strain[S::yz];
    T uxuz = smagoFactor * strain[S::xz];
    
    momEq[4] += ux2;
    momEq[5] += uxuy;
    momEq[6] += uxuz;

    momEq[7] += uy2;
    momEq[8] += uyuz;
    momEq[9] += uz2;
}

static Array<T,SymmetricTensorImpl<T,D::d>::n> computeStrainRate(T rhoBar, T invRho, const Array<T,D::d> &j, const Array<T,D::q> &mom, T cSmago, T tau) {
    typedef SymmetricTensorImpl<T,D::d> S;
    Array<T,S::n> piNeq;
    piNeq[S::xx] = mom[4+S::xx]-j[0]*j[0]*invRho;
    piNeq[S::xy] = mom[4+S::xy]-j[0]*j[1]*invRho;
    piNeq[S::xz] = mom[4+S::xz]-j[0]*j[2]*invRho;
    piNeq[S::yy] = mom[4+S::yy]-j[1]*j[1]*invRho;
    piNeq[S::yz] = mom[4+S::yz]-j[1]*j[2]*invRho;
    piNeq[S::zz] = mom[4+S::zz]-j[2]*j[2]*invRho;
    
    T rho = D::fullRho(rhoBar);
    
    T normPiNeq = std::sqrt((T)2*SymmetricTensorImpl<T,D::d>::tensorNormSqr(piNeq));
    normPiNeq *= (T)2*rho*util::sqr<T>(D::cs2*cSmago*cSmago);
    
    if (normPiNeq != T()) { // test to avoid division per 0
        piNeq = -(-rho*tau*D::cs2+std::sqrt(util::sqr<T>(rho*tau*D::cs2)+normPiNeq)) / normPiNeq * piNeq;
    }

    return piNeq;
}

static T bgk_ma2_collision_base(Array<T,D::q>& f, T rhoBar, Array<T,3> const& j, T omega, T invRho ) {
    T one_m_omega = (T)1 - omega;
    T t0_omega = D::t[0] * omega;
    T t1_omega = D::t[1] * omega;
    T t4_omega = D::t[4] * omega;

    T jSqr   = j[0]*j[0] + j[1]*j[1] + j[2]*j[2];
    T kx     = (T)3 * j[0];
    T ky     = (T)3 * j[1];
    T kz     = (T)3 * j[2];
    T kxSqr_ = invRho / (T)2 * kx*kx;
    T kySqr_ = invRho / (T)2 * ky*ky;
    T kzSqr_ = invRho / (T)2 * kz*kz;
    T kxky_  = invRho * kx*ky;
    T kxkz_  = invRho * kx*kz;
    T kykz_  = invRho * ky*kz;

    T C1 = rhoBar + invRho*(T)3*jSqr;
    T C2, C3;

    // i=0
    C3 = -kxSqr_ - kySqr_ - kzSqr_;
    f[0] *= one_m_omega; f[0] += t0_omega * (C1+C3);

    // i=1 and i=8
    C2 = -kx;
    C3 = -kySqr_ - kzSqr_;
    f[1]  *= one_m_omega; f[1]  += t1_omega * (C1+C2+C3);
    f[8]  *= one_m_omega; f[8]  += t1_omega * (C1-C2+C3);

    // i=2 and i=9
    C2 = -ky;
    C3 = -kxSqr_ - kzSqr_;
    f[2]  *= one_m_omega; f[2]  += t1_omega * (C1+C2+C3);
    f[9]  *= one_m_omega; f[9]  += t1_omega * (C1-C2+C3);

    // i=3 and i=10
    C2 = -kz;
    C3 = -kxSqr_ - kySqr_;
    f[3]  *= one_m_omega; f[3]  += t1_omega * (C1+C2+C3);
    f[10] *= one_m_omega; f[10] += t1_omega * (C1-C2+C3);

    // i=4 and i=11
    C2 = -kx -ky -kz;
    C3 = kxky_ + kxkz_ + kykz_;
    f[4]  *= one_m_omega; f[4]  += t4_omega * (C1+C2+C3);
    f[11] *= one_m_omega; f[11] += t4_omega * (C1-C2+C3);

    // i=5 and i=12
    C2 = -kx -ky +kz;
    C3 = kxky_ - kxkz_ - kykz_;
    f[5]  *= one_m_omega; f[5]  += t4_omega * (C1+C2+C3);
    f[12] *= one_m_omega; f[12] += t4_omega * (C1-C2+C3);

    // i=6 and i=13
    C2 = -kx +ky -kz;
    C3 = -kxky_ + kxkz_ - kykz_;
    f[6]  *= one_m_omega; f[6]  += t4_omega * (C1+C2+C3);
    f[13] *= one_m_omega; f[13] += t4_omega * (C1-C2+C3);

    // i=7 and i=14
    C2 = -kx +ky +kz;
    C3 = -kxky_ - kxkz_ + kykz_;
    f[7]  *= one_m_omega; f[7]  += t4_omega * (C1+C2+C3);
    f[14] *= one_m_omega; f[14] += t4_omega * (C1-C2+C3);

    return invRho*invRho*jSqr;
}

static T truncated_mrt_ma2_collision_base(Array<T,D::q>& f, T omega, T omegaNonPhys, plint iPhys) {
    Array<T,D::q> mNeq, mEq;
    complete_ma2_moments(f, mNeq);
    T invRho = D::invRho(mNeq[0]);
    truncated_ma2_equilibrium_moments(mNeq[0], invRho, Array<T,D::d>(mNeq[1],mNeq[2],mNeq[3]), mEq);
    
    T jSqr = mNeq[1]*mNeq[1] + mNeq[2]*mNeq[2] + mNeq[3]*mNeq[3];
    
    for (plint iPop = 1+D::d; iPop <= iPhys; ++iPop) {
        mNeq[iPop] -= mEq[iPop];
        mNeq[iPop] *= -omega;
    }
    
    for (plint iPop = iPhys+1; iPop < D::q; ++iPop) {
        mNeq[iPop] -= mEq[iPop];
        mNeq[iPop] *= -omegaNonPhys;
    }
        
    computeInvMmNeqToPopNoRhoJ(mNeq,f);
    
    return invRho*invRho*jSqr;
}

static T truncated_mrt_ma2_ext_rhoBar_j_collision_base(Array<T,D::q>& f, T rhoBar, Array<T,D::d> const &j, T omega, T omegaNonPhys, plint iPhys) {
    Array<T,D::q> mNeq, mEq;
    complete_ma2_moments(f, mNeq);
    T invRho = D::invRho(rhoBar);
    truncated_ma2_equilibrium_moments(rhoBar, invRho, j, mEq);
    
    T jSqr = j[0]*j[0]+j[1]*j[1]+j[2]*j[2];
    
//     plint iPhys = 16; // max moment to relax with omega
    for (plint iPop = 0; iPop <= iPhys; ++iPop) {
        mNeq[iPop] -= mEq[iPop];
        mNeq[iPop] *= -omega;
    }
    
    for (plint iPop = iPhys+1; iPop < D::q; ++iPop) {
        mNeq[iPop] -= mEq[iPop];
        mNeq[iPop] *= -omegaNonPhys;
    }
        
    computeInvMmNeqToPop(mNeq,f);
    
    return invRho*invRho*jSqr;
}

static T truncated_mrt_smagorinsky_ma2_collision_base(Array<T,D::q>& f, T cSmago, T omega, T omegaNonPhys, plint iPhys) {
    Array<T,D::q> mNeq, mEq;
    complete_ma2_moments(f, mNeq);
    T invRho = D::invRho(mNeq[0]);
    truncated_ma2_equilibrium_moments(mNeq[0], invRho, Array<T,D::d>(mNeq[1],mNeq[2],mNeq[3]), mEq);
    Array<T,SymmetricTensorImpl<T,D::d>::n> S = 
        computeStrainRate(mNeq[0], D::invRho(mNeq[0]), Array<T,D::d>(mNeq[1],mNeq[2],mNeq[3]), mNeq, cSmago, (T)1/omega);
    
    addSmagorinskyMoments( mEq, S, cSmago );
    
    T jSqr = mNeq[1]*mNeq[1] + mNeq[2]*mNeq[2] + mNeq[3]*mNeq[3];
    
    for (plint iPop = 1+D::d; iPop <= iPhys; ++iPop) {
        mNeq[iPop] -= mEq[iPop];
        mNeq[iPop] *= -omega;
    }
    
    for (plint iPop = iPhys+1; iPop < D::q; ++iPop) {
        mNeq[iPop] -= mEq[iPop];
        mNeq[iPop] *= -omegaNonPhys;
    }
        
    computeInvMmNeqToPopNoRhoJ(mNeq,f);
    
    return invRho*invRho*jSqr;
}

static T truncated_mrt_smagorinsky_ma2_ext_rhoBar_j_collision_base(Array<T,D::q>& f, T rhoBar, Array<T,D::d> const &j, T cSmago, T omega, T omegaNonPhys, plint iPhys) {
    Array<T,D::q> mNeq, mEq;
    complete_ma2_moments(f, mNeq);
    T invRho = D::invRho(rhoBar);
    truncated_ma2_equilibrium_moments(rhoBar, invRho, j, mEq);
    
    Array<T,SymmetricTensorImpl<T,D::d>::n> S = 
        computeStrainRate(mNeq[0], D::invRho(mNeq[0]), Array<T,D::d>(mNeq[1],mNeq[2],mNeq[3]), mNeq, cSmago, (T)1/omega);
    
    addSmagorinskyMoments( mEq, S, cSmago );
    
    
    T jSqr = j[0]*j[0]+j[1]*j[1]+j[2]*j[2];
    
    // iPhys max moment to relax with omega
    for (plint iPop = 0; iPop <= iPhys; ++iPop) {
        mNeq[iPop] -= mEq[iPop];
        mNeq[iPop] *= -omega;
    }
    
    for (plint iPop = iPhys+1; iPop < D::q; ++iPop) {
        mNeq[iPop] -= mEq[iPop];
        mNeq[iPop] *= -omegaNonPhys;
    }
        
    computeInvMmNeqToPop(mNeq,f);
    
    return invRho*invRho*jSqr;
}

static T bgk_ma2_collision(Array<T,D::q>& f, T rhoBar, Array<T,3> const& j, T omega) {
    return bgk_ma2_collision_base(f, rhoBar, j, omega, D::invRho(rhoBar));
}

static T bgk_inc_collision(Array<T,D::q>& f, T rhoBar, Array<T,3> const& j, T omega, T invRho0=(T)1 ) {
    return bgk_ma2_collision_base(f, rhoBar, j, omega, invRho0);
}

static T truncated_mrt_ma2_collision(Array<T,D::q>& f, T omega, T omegaNonPhys, plint iPhys) {
    return truncated_mrt_ma2_collision_base(f, omega, omegaNonPhys, iPhys);
}

static T truncated_mrt_ma2_ext_rhoBar_j_collision(Array<T,D::q>& f, T rhoBar, Array<T,D::d> const& j, T omega, T omegaNonPhys, plint iPhys) {
    return truncated_mrt_ma2_ext_rhoBar_j_collision_base(f, rhoBar, j, omega, omegaNonPhys, iPhys);
}

static T truncated_mrt_smagorinsky_ma2_collision(Array<T,D::q>& f, T cSmago, T omega, T omegaNonPhys, plint iPhys) {
    return truncated_mrt_smagorinsky_ma2_collision_base(f, cSmago, omega, omegaNonPhys, iPhys);
}

static T truncated_mrt_smagorinsky_ma2_ext_rhoBar_j_collision(Array<T,D::q>& f, T rhoBar, Array<T,D::d> const& j, T cSmago, T omega, T omegaNonPhys, plint iPhys) {
    return truncated_mrt_smagorinsky_ma2_ext_rhoBar_j_collision_base(f, rhoBar, j, cSmago, omega, omegaNonPhys, iPhys);
}

static T rlbCollision(Array<T,D::q>& f, T rhoBar, T invRho, Array<T,3> const& j, Array<T,6> const& PiNeq, T omega) {
    typedef dynamicsTemplatesImpl<T, descriptors::D3Q15DescriptorBase<T> > DH;
    const T jSqr = j[0]*j[0] + j[1]*j[1] + j[2]*j[2];

    T piNeq0 = neqPiD3Q15<T>::fromPiToFneq0(PiNeq);
    T piNeq1 = neqPiD3Q15<T>::fromPiToFneq1(PiNeq);
    T piNeq2 = neqPiD3Q15<T>::fromPiToFneq2(PiNeq);
    T piNeq3 = neqPiD3Q15<T>::fromPiToFneq3(PiNeq);
    T piNeq4 = neqPiD3Q15<T>::fromPiToFneq4(PiNeq);
    T piNeq5 = neqPiD3Q15<T>::fromPiToFneq5(PiNeq);
    T piNeq6 = neqPiD3Q15<T>::fromPiToFneq6(PiNeq);
    T piNeq7 = neqPiD3Q15<T>::fromPiToFneq7(PiNeq);

    f[0]  = DH::bgk_ma2_equilibrium(0, rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq0;
    f[1]  = DH::bgk_ma2_equilibrium(1, rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq1;
    f[2]  = DH::bgk_ma2_equilibrium(2, rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq2;
    f[3]  = DH::bgk_ma2_equilibrium(3, rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq3;
    f[4]  = DH::bgk_ma2_equilibrium(4, rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq4;
    f[5]  = DH::bgk_ma2_equilibrium(5, rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq5;
    f[6]  = DH::bgk_ma2_equilibrium(6, rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq6;
    f[7]  = DH::bgk_ma2_equilibrium(7, rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq7;
    f[8]  = DH::bgk_ma2_equilibrium(8, rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq1;
    f[9]  = DH::bgk_ma2_equilibrium(9, rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq2;
    f[10]  = DH::bgk_ma2_equilibrium(10,rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq3;
    f[11]  = DH::bgk_ma2_equilibrium(11,rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq4;
    f[12]  = DH::bgk_ma2_equilibrium(12,rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq5;
    f[13]  = DH::bgk_ma2_equilibrium(13,rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq6;
    f[14]  = DH::bgk_ma2_equilibrium(14,rhoBar, invRho, j, jSqr)
                   + ((T)1-omega) * piNeq7;
    return jSqr*invRho*invRho;
}

static T bgk_ma2_constRho_collision(Array<T,D::q>& f, T rhoBar, Array<T,D::d> const& j, T ratioRho, T omega) {
    T invRho = D::invRho(rhoBar);
    const T jSqr = j[0]*j[0] + j[1]*j[1] + j[2]*j[2];
    for (plint iPop=0; iPop < D::q; ++iPop) {
        T feq = bgk_ma2_equilibrium(iPop, rhoBar, invRho, j, jSqr );
        f[iPop] =
          ratioRho*feq + D::t[iPop]*(ratioRho-(T)1) +
          ((T)1-omega)*(f[iPop]-feq);
    }
    return jSqr*invRho*invRho;
}


static T precond_bgk_ma2_equilibrium(plint iPop, T rhoBar, T invRho, Array<T,3> const& j, T jSqr, T invGamma )
{
    T c_j = D::c[iPop][0]*j[0] + D::c[iPop][1]*j[1] + D::c[iPop][2]*j[2];
    return D::t[iPop] * ( rhoBar + 3.*c_j + invGamma*invRho*(4.5*c_j*c_j - 1.5*jSqr) );
}

static T precond_bgk_ma2_collision_base (
        Array<T,D::q>& f, T rhoBar, Array<T,3> const& j, T omega, T invGamma, bool incompressible )
{
    T invRho = incompressible ? (T)1 : D::invRho(rhoBar);
    T one_m_omega = (T)1 - omega;
    T t0_omega = D::t[0] * omega;
    T t1_omega = D::t[1] * omega;
    T t4_omega = D::t[4] * omega;

    T jSqr   = j[0]*j[0] + j[1]*j[1] + j[2]*j[2];
    T kx     = (T)3 * j[0];
    T ky     = (T)3 * j[1];
    T kz     = (T)3 * j[2];
    T kxSqr_ = invGamma* invRho / (T)2 * kx*kx;
    T kySqr_ = invGamma* invRho / (T)2 * ky*ky;
    T kzSqr_ = invGamma* invRho / (T)2 * kz*kz;
    T kxky_  = invGamma* invRho * kx*ky;
    T kxkz_  = invGamma* invRho * kx*kz;
    T kykz_  = invGamma* invRho * ky*kz;

    T C1 = rhoBar + invGamma*invRho*(T)3*jSqr;
    T C2, C3;

    // i=0
    C3 = -kxSqr_ - kySqr_ - kzSqr_;
    f[0] *= one_m_omega; f[0] += t0_omega * (C1+C3);

    // i=1 and i=8
    C2 = -kx;
    C3 = -kySqr_ - kzSqr_;
    f[1]  *= one_m_omega; f[1]  += t1_omega * (C1+C2+C3);
    f[8]  *= one_m_omega; f[8]  += t1_omega * (C1-C2+C3);

    // i=2 and i=9
    C2 = -ky;
    C3 = -kxSqr_ - kzSqr_;
    f[2]  *= one_m_omega; f[2]  += t1_omega * (C1+C2+C3);
    f[9]  *= one_m_omega; f[9]  += t1_omega * (C1-C2+C3);

    // i=3 and i=10
    C2 = -kz;
    C3 = -kxSqr_ - kySqr_;
    f[3]  *= one_m_omega; f[3]  += t1_omega * (C1+C2+C3);
    f[10] *= one_m_omega; f[10] += t1_omega * (C1-C2+C3);

    // i=4 and i=11
    C2 = -kx -ky -kz;
    C3 = kxky_ + kxkz_ + kykz_;
    f[4]  *= one_m_omega; f[4]  += t4_omega * (C1+C2+C3);
    f[11] *= one_m_omega; f[11] += t4_omega * (C1-C2+C3);

    // i=5 and i=12
    C2 = -kx -ky +kz;
    C3 = kxky_ - kxkz_ - kykz_;
    f[5]  *= one_m_omega; f[5]  += t4_omega * (C1+C2+C3);
    f[12] *= one_m_omega; f[12] += t4_omega * (C1-C2+C3);

    // i=6 and i=13
    C2 = -kx +ky -kz;
    C3 = -kxky_ + kxkz_ - kykz_;
    f[6]  *= one_m_omega; f[6]  += t4_omega * (C1+C2+C3);
    f[13] *= one_m_omega; f[13] += t4_omega * (C1-C2+C3);

    // i=7 and i=14
    C2 = -kx +ky +kz;
    C3 = -kxky_ - kxkz_ + kykz_;
    f[7]  *= one_m_omega; f[7]  += t4_omega * (C1+C2+C3);
    f[14] *= one_m_omega; f[14] += t4_omega * (C1-C2+C3);

    return invRho*invRho*jSqr;
}

static T precond_bgk_ma2_collision(Array<T,D::q>& f, T rhoBar, Array<T,3> const& j, T omega, T invGamma)
{
    return precond_bgk_ma2_collision_base(f, rhoBar, j, omega, invGamma, false);
}


};  //struct dynamicsTemplatesImpl<D3Q15DescriptorBase>

}  // namespace plb

#endif  // DYNAMICS_TEMPLATES_3D_H
