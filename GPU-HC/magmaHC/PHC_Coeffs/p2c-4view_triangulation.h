#ifndef P2C_4VIEW_TRIANGULATION_H
#define P2C_4VIEW_TRIANGULATION_H
// ==========================================================================================================================
//
// Modifications
//    Chiang-Heng Chien  24-05-27:   Built from generalized three-view relative pose problem.
//
//> (c) LEMS, Brown University
//> Chiang-Heng Chien (chiang-heng_chien@brown.edu)
// ===========================================================================================================================
#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <chrono>

#include "magma_v2.h"
#include "magma_lapack.h"
#include "magma_internal.h"
#undef max
#undef min

namespace magmaHCWrapper {

  void p2c_4view_triangulation(
    magmaFloatComplex *h_targetParams, magmaFloatComplex *h_startParams, 
    magmaFloatComplex *h_phc_coeffs_Hx, magmaFloatComplex *h_phc_coeffs_Ht
  )
  {
    magmaFloatComplex p1 = h_targetParams[0];
    magmaFloatComplex p2 = h_targetParams[1];
    magmaFloatComplex p3 = h_targetParams[2];
    magmaFloatComplex p4 = h_targetParams[3];
    magmaFloatComplex p5 = h_targetParams[4];
    magmaFloatComplex p6 = h_targetParams[5];
    magmaFloatComplex p7 = h_targetParams[6];
    magmaFloatComplex p8 = h_targetParams[7];
    magmaFloatComplex p9 = h_targetParams[8];
    magmaFloatComplex p10 = h_targetParams[9];
    magmaFloatComplex p11 = h_targetParams[10];
    magmaFloatComplex p12 = h_targetParams[11];
    magmaFloatComplex p13 = h_targetParams[12];
    magmaFloatComplex p14 = h_targetParams[13];
    magmaFloatComplex p15 = h_targetParams[14];
    magmaFloatComplex p16 = h_targetParams[15];
    magmaFloatComplex p17 = h_targetParams[16];
    magmaFloatComplex p18 = h_targetParams[17];
    magmaFloatComplex p19 = h_targetParams[18];
    magmaFloatComplex p20 = h_targetParams[19];
    magmaFloatComplex p21 = h_targetParams[20];
    magmaFloatComplex p22 = h_targetParams[21];
    magmaFloatComplex p23 = h_targetParams[22];
    magmaFloatComplex p24 = h_targetParams[23];
    magmaFloatComplex p25 = h_targetParams[24];
    magmaFloatComplex p26 = h_targetParams[25];
    magmaFloatComplex p27 = h_targetParams[26];
    magmaFloatComplex p28 = h_targetParams[27];
    magmaFloatComplex p29 = h_targetParams[28];
    magmaFloatComplex p30 = h_targetParams[29];
    magmaFloatComplex p31 = h_targetParams[30];
    magmaFloatComplex p32 = h_targetParams[31];
    magmaFloatComplex p33 = h_targetParams[32];
    magmaFloatComplex p34 = h_targetParams[33];
    magmaFloatComplex p35 = h_targetParams[34];
    
    magmaFloatComplex q1 = h_startParams[0];
    magmaFloatComplex q2 = h_startParams[1];
    magmaFloatComplex q3 = h_startParams[2];
    magmaFloatComplex q4 = h_startParams[3];
    magmaFloatComplex q5 = h_startParams[4];
    magmaFloatComplex q6 = h_startParams[5];
    magmaFloatComplex q7 = h_startParams[6];
    magmaFloatComplex q8 = h_startParams[7];
    magmaFloatComplex q9 = h_startParams[8];
    magmaFloatComplex q10 = h_startParams[9];
    magmaFloatComplex q11 = h_startParams[10];
    magmaFloatComplex q12 = h_startParams[11];
    magmaFloatComplex q13 = h_startParams[12];
    magmaFloatComplex q14 = h_startParams[13];
    magmaFloatComplex q15 = h_startParams[14];
    magmaFloatComplex q16 = h_startParams[15];
    magmaFloatComplex q17 = h_startParams[16];
    magmaFloatComplex q18 = h_startParams[17];
    magmaFloatComplex q19 = h_startParams[18];
    magmaFloatComplex q20 = h_startParams[19];
    magmaFloatComplex q21 = h_startParams[20];
    magmaFloatComplex q22 = h_startParams[21];
    magmaFloatComplex q23 = h_startParams[22];
    magmaFloatComplex q24 = h_startParams[23];
    magmaFloatComplex q25 = h_startParams[24];
    magmaFloatComplex q26 = h_startParams[25];
    magmaFloatComplex q27 = h_startParams[26];
    magmaFloatComplex q28 = h_startParams[27];
    magmaFloatComplex q29 = h_startParams[28];
    magmaFloatComplex q30 = h_startParams[29];
    magmaFloatComplex q31 = h_startParams[30];
    magmaFloatComplex q32 = h_startParams[31];
    magmaFloatComplex q33 = h_startParams[32];
    magmaFloatComplex q34 = h_startParams[33];
    magmaFloatComplex q35 = h_startParams[34];

    h_phc_coeffs_Hx[0]=q1;
    h_phc_coeffs_Hx[1]=p1 - q1;
    h_phc_coeffs_Hx[2]=q10;
    h_phc_coeffs_Hx[3]=p10 - q10;
    h_phc_coeffs_Hx[4]=q11;
    h_phc_coeffs_Hx[5]=p11 - q11;
    h_phc_coeffs_Hx[6]=q12;
    h_phc_coeffs_Hx[7]=p12 - q12;
    h_phc_coeffs_Hx[8]=q13;
    h_phc_coeffs_Hx[9]=p13 - q13;
    h_phc_coeffs_Hx[10]=q14;
    h_phc_coeffs_Hx[11]=p14 - q14;
    h_phc_coeffs_Hx[12]=q15;
    h_phc_coeffs_Hx[13]=p15 - q15;
    h_phc_coeffs_Hx[14]=q16;
    h_phc_coeffs_Hx[15]=p16 - q16;
    h_phc_coeffs_Hx[16]=q17;
    h_phc_coeffs_Hx[17]=p17 - q17;
    h_phc_coeffs_Hx[18]=q18;
    h_phc_coeffs_Hx[19]=p18 - q18;
    h_phc_coeffs_Hx[20]=q19;
    h_phc_coeffs_Hx[21]=p19 - q19;
    h_phc_coeffs_Hx[22]=q2;
    h_phc_coeffs_Hx[23]=p2 - q2;
    h_phc_coeffs_Hx[24]=q20;
    h_phc_coeffs_Hx[25]=p20 - q20;
    h_phc_coeffs_Hx[26]=q21;
    h_phc_coeffs_Hx[27]=p21 - q21;
    h_phc_coeffs_Hx[28]=q22;
    h_phc_coeffs_Hx[29]=p22 - q22;
    h_phc_coeffs_Hx[30]=q23;
    h_phc_coeffs_Hx[31]=p23 - q23;
    h_phc_coeffs_Hx[32]=q24;
    h_phc_coeffs_Hx[33]=p24 - q24;
    h_phc_coeffs_Hx[34]=q25;
    h_phc_coeffs_Hx[35]=p25 - q25;
    h_phc_coeffs_Hx[36]=q26;
    h_phc_coeffs_Hx[37]=p26 - q26;
    h_phc_coeffs_Hx[38]=q27;
    h_phc_coeffs_Hx[39]=p27 - q27;
    h_phc_coeffs_Hx[40]=q28;
    h_phc_coeffs_Hx[41]=p28 - q28;
    h_phc_coeffs_Hx[42]=q29;
    h_phc_coeffs_Hx[43]=p29 - q29;
    h_phc_coeffs_Hx[44]=q3;
    h_phc_coeffs_Hx[45]=p3 - q3;
    h_phc_coeffs_Hx[46]=q30;
    h_phc_coeffs_Hx[47]=p30 - q30;
    h_phc_coeffs_Hx[48]=q31;
    h_phc_coeffs_Hx[49]=p31 - q31;
    h_phc_coeffs_Hx[50]=q32;
    h_phc_coeffs_Hx[51]=p32 - q32;
    h_phc_coeffs_Hx[52]=q33;
    h_phc_coeffs_Hx[53]=p33 - q33;
    h_phc_coeffs_Hx[54]=q34;
    h_phc_coeffs_Hx[55]=p34 - q34;
    h_phc_coeffs_Hx[56]=q35;
    h_phc_coeffs_Hx[57]=p35 - q35;
    h_phc_coeffs_Hx[58]=q4;
    h_phc_coeffs_Hx[59]=p4 - q4;
    h_phc_coeffs_Hx[60]=q5;
    h_phc_coeffs_Hx[61]=p5 - q5;
    h_phc_coeffs_Hx[62]=q6;
    h_phc_coeffs_Hx[63]=p6 - q6;
    h_phc_coeffs_Hx[64]=q7;
    h_phc_coeffs_Hx[65]=p7 - q7;
    h_phc_coeffs_Hx[66]=q8;
    h_phc_coeffs_Hx[67]=p8 - q8;
    h_phc_coeffs_Hx[68]=q9;
    h_phc_coeffs_Hx[69]=p9 - q9;
    h_phc_coeffs_Hx[70]=MAGMA_C_ONE;
    h_phc_coeffs_Hx[71]=MAGMA_C_ZERO;

    h_phc_coeffs_Ht[0]=p1 - q1;
    h_phc_coeffs_Ht[1]=p10 - q10;
    h_phc_coeffs_Ht[2]=p11 - q11;
    h_phc_coeffs_Ht[3]=p12 - q12;
    h_phc_coeffs_Ht[4]=p13 - q13;
    h_phc_coeffs_Ht[5]=p14 - q14;
    h_phc_coeffs_Ht[6]=p15 - q15;
    h_phc_coeffs_Ht[7]=p16 - q16;
    h_phc_coeffs_Ht[8]=p17 - q17;
    h_phc_coeffs_Ht[9]=p18 - q18;
    h_phc_coeffs_Ht[10]=p19 - q19;
    h_phc_coeffs_Ht[11]=p2 - q2;
    h_phc_coeffs_Ht[12]=p20 - q20;
    h_phc_coeffs_Ht[13]=p21 - q21;
    h_phc_coeffs_Ht[14]=p22 - q22;
    h_phc_coeffs_Ht[15]=p23 - q23;
    h_phc_coeffs_Ht[16]=p24 - q24;
    h_phc_coeffs_Ht[17]=p25 - q25;
    h_phc_coeffs_Ht[18]=p26 - q26;
    h_phc_coeffs_Ht[19]=p27 - q27;
    h_phc_coeffs_Ht[20]=p28 - q28;
    h_phc_coeffs_Ht[21]=p29 - q29;
    h_phc_coeffs_Ht[22]=p3 - q3;
    h_phc_coeffs_Ht[23]=p30 - q30;
    h_phc_coeffs_Ht[24]=p31 - q31;
    h_phc_coeffs_Ht[25]=p32 - q32;
    h_phc_coeffs_Ht[26]=p33 - q33;
    h_phc_coeffs_Ht[27]=p34 - q34;
    h_phc_coeffs_Ht[28]=p35 - q35;
    h_phc_coeffs_Ht[29]=p4 - q4;
    h_phc_coeffs_Ht[30]=p5 - q5;
    h_phc_coeffs_Ht[31]=p6 - q6;
    h_phc_coeffs_Ht[32]=p7 - q7;
    h_phc_coeffs_Ht[33]=p8 - q8;
    h_phc_coeffs_Ht[34]=p9 - q9;
    h_phc_coeffs_Ht[35]=MAGMA_C_ONE;

  }
} // end of namespace

#endif
