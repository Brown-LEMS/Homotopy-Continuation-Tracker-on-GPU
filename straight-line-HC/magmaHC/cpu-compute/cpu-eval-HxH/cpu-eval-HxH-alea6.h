#ifndef cpu_eval_HxH_alea6_h
#define cpu_eval_HxH_alea6_h
// ============================================================================
// partial derivative evaluations of the alea6 problem for cpu HC computation
//
// Modifications
//    Chien  21-06-17:   Originally created
//
// ============================================================================
#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <chrono>

// -- cuda --
#include <cuda.h>
#include <cuda_runtime.h>

// -- magma --
#include "flops.h"
#include "magma_v2.h"
#include "magma_lapack.h"
#include "magma_internal.h"
#undef max
#undef min

namespace magmaHCWrapper {

  extern "C"
  void cpu_eval_HxH_alea6(
      magma_int_t s, float t, int N, magmaFloatComplex* s_track,
      const magmaFloatComplex &C0, const magmaFloatComplex &C1, const magmaFloatComplex &C2,
      magmaFloatComplex* s_startCoefs, magmaFloatComplex* s_targetCoefs,
      magmaFloatComplex* r_cgesvA, magmaFloatComplex* r_cgesvB )
  {
    magmaFloatComplex G1 = C0 - t;
magmaFloatComplex G2 = G1 * s_startCoefs[0];
magmaFloatComplex G3 = t * s_targetCoefs[0];
magmaFloatComplex G4 = G2 + G3;
magmaFloatComplex G5 = s_track[0] + s_track[0];
magmaFloatComplex G6 = G4 * G5;
magmaFloatComplex G7 = s_track[3] * G6;
magmaFloatComplex G8 = G1 * s_startCoefs[5];
magmaFloatComplex G9 = t * s_targetCoefs[5];
magmaFloatComplex G10 = G8 + G9;
magmaFloatComplex G11 = s_track[1] * G10;
magmaFloatComplex G12 = s_track[5] * G11;
magmaFloatComplex G13 = G1 * s_startCoefs[11];
magmaFloatComplex G14 = t * s_targetCoefs[11];
magmaFloatComplex G15 = G13 + G14;
magmaFloatComplex G16 = G15 * G5;
magmaFloatComplex G17 = s_track[3] * G16;
magmaFloatComplex G18 = G1 * s_startCoefs[12];
magmaFloatComplex G19 = t * s_targetCoefs[12];
magmaFloatComplex G20 = G18 + G19;
magmaFloatComplex G21 = G20 * G5;
magmaFloatComplex G22 = G17 + G21;
magmaFloatComplex G23 = G1 * s_startCoefs[13];
magmaFloatComplex G24 = t * s_targetCoefs[13];
magmaFloatComplex G25 = G23 + G24;
magmaFloatComplex G26 = s_track[3] * G25;
magmaFloatComplex G27 = s_track[5] * G26;
magmaFloatComplex G28 = G22 + G27;
magmaFloatComplex G29 = s_track[3] * s_track[3];
magmaFloatComplex G30 = G1 * s_startCoefs[15];
magmaFloatComplex G31 = t * s_targetCoefs[15];
magmaFloatComplex G32 = G30 + G31;
magmaFloatComplex G33 = G29 * G32;
magmaFloatComplex G34 = G1 * s_startCoefs[20];
magmaFloatComplex G35 = t * s_targetCoefs[20];
magmaFloatComplex G36 = G34 + G35;
magmaFloatComplex G37 = G36 * G5;
magmaFloatComplex G38 = s_track[2] * G37;
magmaFloatComplex G39 = G1 * s_startCoefs[21];
magmaFloatComplex G40 = t * s_targetCoefs[21];
magmaFloatComplex G41 = G39 + G40;
magmaFloatComplex G42 = s_track[1] * G41;
magmaFloatComplex G43 = s_track[2] * G42;
magmaFloatComplex G44 = G38 + G43;
magmaFloatComplex G45 = G1 * s_startCoefs[22];
magmaFloatComplex G46 = t * s_targetCoefs[22];
magmaFloatComplex G47 = G45 + G46;
magmaFloatComplex G48 = s_track[3] * G47;
magmaFloatComplex G49 = s_track[4] * G48;
magmaFloatComplex G50 = G44 + G49;
magmaFloatComplex G51 = G1 * s_startCoefs[23];
magmaFloatComplex G52 = t * s_targetCoefs[23];
magmaFloatComplex G53 = G51 + G52;
magmaFloatComplex G54 = s_track[3] * G53;
magmaFloatComplex G55 = G50 + G54;
magmaFloatComplex G56 = G1 * s_startCoefs[25];
magmaFloatComplex G57 = t * s_targetCoefs[25];
magmaFloatComplex G58 = G56 + G57;
magmaFloatComplex G59 = s_track[2] * G58;
magmaFloatComplex G60 = s_track[3] * G59;
magmaFloatComplex G61 = G1 * s_startCoefs[1];
magmaFloatComplex G62 = t * s_targetCoefs[1];
magmaFloatComplex G63 = G61 + G62;
magmaFloatComplex G64 = s_track[3] * G63;
magmaFloatComplex G65 = s_track[4] * G64;
magmaFloatComplex G66 = G1 * s_startCoefs[2];
magmaFloatComplex G67 = t * s_targetCoefs[2];
magmaFloatComplex G68 = G66 + G67;
magmaFloatComplex G69 = s_track[3] * G68;
magmaFloatComplex G70 = s_track[5] * G69;
magmaFloatComplex G71 = G65 + G70;
magmaFloatComplex G72 = G10 * s_track[0];
magmaFloatComplex G73 = s_track[5] * G72;
magmaFloatComplex G74 = G1 * s_startCoefs[6];
magmaFloatComplex G75 = t * s_targetCoefs[6];
magmaFloatComplex G76 = G74 + G75;
magmaFloatComplex G77 = s_track[1] + s_track[1];
magmaFloatComplex G78 = G76 * G77;
magmaFloatComplex G79 = s_track[4] * G78;
magmaFloatComplex G80 = G73 + G79;
magmaFloatComplex G81 = G1 * s_startCoefs[7];
magmaFloatComplex G82 = t * s_targetCoefs[7];
magmaFloatComplex G83 = G81 + G82;
magmaFloatComplex G84 = s_track[2] * G83;
magmaFloatComplex G85 = s_track[4] * G84;
magmaFloatComplex G86 = G80 + G85;
magmaFloatComplex G87 = s_track[4] * s_track[4];
magmaFloatComplex G88 = G1 * s_startCoefs[8];
magmaFloatComplex G89 = t * s_targetCoefs[8];
magmaFloatComplex G90 = G88 + G89;
magmaFloatComplex G91 = G87 * G90;
magmaFloatComplex G92 = G86 + G91;
magmaFloatComplex G93 = G20 * G77;
magmaFloatComplex G94 = s_track[4] * G93;
magmaFloatComplex G95 = G29 * G68;
magmaFloatComplex G96 = G94 + G95;
magmaFloatComplex G97 = G1 * s_startCoefs[16];
magmaFloatComplex G98 = t * s_targetCoefs[16];
magmaFloatComplex G99 = G97 + G98;
magmaFloatComplex G100 = G87 * G99;
magmaFloatComplex G101 = G26 + G100;
magmaFloatComplex G102 = G41 * s_track[0];
magmaFloatComplex G103 = s_track[2] * G102;
magmaFloatComplex G104 = G1 * s_startCoefs[24];
magmaFloatComplex G105 = t * s_targetCoefs[24];
magmaFloatComplex G106 = G104 + G105;
magmaFloatComplex G107 = G106 * G77;
magmaFloatComplex G108 = s_track[4] * G107;
magmaFloatComplex G109 = G103 + G108;
magmaFloatComplex G110 = G83 * s_track[1];
magmaFloatComplex G111 = s_track[4] * G110;
magmaFloatComplex G112 = G1 * s_startCoefs[9];
magmaFloatComplex G113 = t * s_targetCoefs[9];
magmaFloatComplex G114 = G112 + G113;
magmaFloatComplex G115 = s_track[2] + s_track[2];
magmaFloatComplex G116 = G114 * G115;
magmaFloatComplex G117 = G111 + G116;
magmaFloatComplex G118 = G1 * s_startCoefs[17];
magmaFloatComplex G119 = t * s_targetCoefs[17];
magmaFloatComplex G120 = G118 + G119;
magmaFloatComplex G121 = s_track[3] * G120;
magmaFloatComplex G122 = G1 * s_startCoefs[18];
magmaFloatComplex G123 = t * s_targetCoefs[18];
magmaFloatComplex G124 = G122 + G123;
magmaFloatComplex G125 = s_track[4] * G124;
magmaFloatComplex G126 = s_track[5] * G125;
magmaFloatComplex G127 = G121 + G126;
magmaFloatComplex G128 = s_track[0] * s_track[0];
magmaFloatComplex G129 = G36 * G128;
magmaFloatComplex G130 = G102 * s_track[1];
magmaFloatComplex G131 = G129 + G130;
magmaFloatComplex G132 = G58 * s_track[0];
magmaFloatComplex G133 = s_track[3] * G132;
magmaFloatComplex G134 = G124 * G115;
magmaFloatComplex G135 = s_track[3] * G134;
magmaFloatComplex G136 = G133 + G135;
magmaFloatComplex G137 = G1 * s_startCoefs[26];
magmaFloatComplex G138 = t * s_targetCoefs[26];
magmaFloatComplex G139 = G137 + G138;
magmaFloatComplex G140 = G139 * G115;
magmaFloatComplex G141 = s_track[5] * G140;
magmaFloatComplex G142 = G136 + G141;
magmaFloatComplex G143 = G1 * s_startCoefs[27];
magmaFloatComplex G144 = t * s_targetCoefs[27];
magmaFloatComplex G145 = G143 + G144;
magmaFloatComplex G146 = G142 + G145;
magmaFloatComplex G147 = G4 * G128;
magmaFloatComplex G148 = G63 * s_track[1];
magmaFloatComplex G149 = s_track[4] * G148;
magmaFloatComplex G150 = G147 + G149;
magmaFloatComplex G151 = G68 * s_track[1];
magmaFloatComplex G152 = s_track[5] * G151;
magmaFloatComplex G153 = G150 + G152;
magmaFloatComplex G154 = G1 * s_startCoefs[3];
magmaFloatComplex G155 = t * s_targetCoefs[3];
magmaFloatComplex G156 = G154 + G155;
magmaFloatComplex G157 = s_track[5] * G156;
magmaFloatComplex G158 = G153 + G157;
magmaFloatComplex G159 = G1 * s_startCoefs[10];
magmaFloatComplex G160 = t * s_targetCoefs[10];
magmaFloatComplex G161 = G159 + G160;
magmaFloatComplex G162 = s_track[4] * G161;
magmaFloatComplex G163 = s_track[5] * G162;
magmaFloatComplex G164 = G15 * G128;
magmaFloatComplex G165 = G25 * s_track[0];
magmaFloatComplex G166 = s_track[5] * G165;
magmaFloatComplex G167 = G164 + G166;
magmaFloatComplex G168 = s_track[3] + s_track[3];
magmaFloatComplex G169 = G151 * G168;
magmaFloatComplex G170 = G167 + G169;
magmaFloatComplex G171 = G32 * s_track[0];
magmaFloatComplex G172 = G171 * G168;
magmaFloatComplex G173 = G25 * s_track[1];
magmaFloatComplex G174 = G172 + G173;
magmaFloatComplex G175 = G120 * s_track[2];
magmaFloatComplex G176 = G174 + G175;
magmaFloatComplex G177 = G1 * s_startCoefs[19];
magmaFloatComplex G178 = t * s_targetCoefs[19];
magmaFloatComplex G179 = G177 + G178;
magmaFloatComplex G180 = G87 * G179;
magmaFloatComplex G181 = G176 + G180;
magmaFloatComplex G182 = G47 * s_track[0];
magmaFloatComplex G183 = s_track[4] * G182;
magmaFloatComplex G184 = G53 * s_track[0];
magmaFloatComplex G185 = G183 + G184;
magmaFloatComplex G186 = G132 * s_track[2];
magmaFloatComplex G187 = s_track[2] * s_track[2];
magmaFloatComplex G188 = G124 * G187;
magmaFloatComplex G189 = G186 + G188;
magmaFloatComplex G190 = G1 * s_startCoefs[28];
magmaFloatComplex G191 = t * s_targetCoefs[28];
magmaFloatComplex G192 = G190 + G191;
magmaFloatComplex G193 = G29+G29+G29;
magmaFloatComplex G194 = G192 * G193;
magmaFloatComplex G195 = G189 + G194;
magmaFloatComplex G196 = G148 * s_track[3];
magmaFloatComplex G197 = G1 * s_startCoefs[4];
magmaFloatComplex G198 = t * s_targetCoefs[4];
magmaFloatComplex G199 = G197 + G198;
magmaFloatComplex G200 = s_track[5] * G199;
magmaFloatComplex G201 = G196 + G200;
magmaFloatComplex G202 = s_track[1] * s_track[1];
magmaFloatComplex G203 = G76 * G202;
magmaFloatComplex G204 = G110 * s_track[2];
magmaFloatComplex G205 = G203 + G204;
magmaFloatComplex G206 = G90 * s_track[1];
magmaFloatComplex G207 = s_track[4] + s_track[4];
magmaFloatComplex G208 = G206 * G207;
magmaFloatComplex G209 = G205 + G208;
magmaFloatComplex G210 = G161 * s_track[3];
magmaFloatComplex G211 = s_track[5] * G210;
magmaFloatComplex G212 = G209 + G211;
magmaFloatComplex G213 = G20 * G202;
magmaFloatComplex G214 = G99 * s_track[1];
magmaFloatComplex G215 = G214 * G207;
magmaFloatComplex G216 = G124 * s_track[2];
magmaFloatComplex G217 = s_track[5] * G216;
magmaFloatComplex G218 = G215 + G217;
magmaFloatComplex G219 = G179 * s_track[3];
magmaFloatComplex G220 = G219 * G207;
magmaFloatComplex G221 = G218 + G220;
magmaFloatComplex G222 = G182 * s_track[3];
magmaFloatComplex G223 = G106 * G202;
magmaFloatComplex G224 = G222 + G223;
magmaFloatComplex G225 = G151 * s_track[3];
magmaFloatComplex G226 = G156 * s_track[3];
magmaFloatComplex G227 = G225 + G226;
magmaFloatComplex G228 = G199 * s_track[4];
magmaFloatComplex G229 = G227 + G228;
magmaFloatComplex G230 = G72 * s_track[1];
magmaFloatComplex G231 = G210 * s_track[4];
magmaFloatComplex G232 = G230 + G231;
magmaFloatComplex G233 = G165 * s_track[3];
magmaFloatComplex G234 = G1 * s_startCoefs[14];
magmaFloatComplex G235 = t * s_targetCoefs[14];
magmaFloatComplex G236 = G234 + G235;
magmaFloatComplex G237 = s_track[5] * s_track[5];
magmaFloatComplex G238 = G237+G237+G237;
magmaFloatComplex G239 = G236 * G238;
magmaFloatComplex G240 = G233 + G239;
magmaFloatComplex G241 = G216 * s_track[4];
magmaFloatComplex G242 = G139 * G187;
magmaFloatComplex G243 = G147 * s_track[3];
magmaFloatComplex G244 = G196 * s_track[4];
magmaFloatComplex G245 = G243 + G244;
magmaFloatComplex G246 = G225 * s_track[5];
magmaFloatComplex G247 = G245 + G246;
magmaFloatComplex G248 = G226 * s_track[5];
magmaFloatComplex G249 = G247 + G248;
magmaFloatComplex G250 = G228 * s_track[5];
magmaFloatComplex G251 = G249 + G250;
magmaFloatComplex G252 = G230 * s_track[5];
magmaFloatComplex G253 = G203 * s_track[4];
magmaFloatComplex G254 = G252 + G253;
magmaFloatComplex G255 = G204 * s_track[4];
magmaFloatComplex G256 = G254 + G255;
magmaFloatComplex G257 = G206 * G87;
magmaFloatComplex G258 = G256 + G257;
magmaFloatComplex G259 = G114 * G187;
magmaFloatComplex G260 = G258 + G259;
magmaFloatComplex G261 = G231 * s_track[5];
magmaFloatComplex G262 = G260 + G261;
magmaFloatComplex G263 = G164 * s_track[3];
magmaFloatComplex G264 = G20 * G128;
magmaFloatComplex G265 = G263 + G264;
magmaFloatComplex G266 = G233 * s_track[5];
magmaFloatComplex G267 = G265 + G266;
magmaFloatComplex G268 = G213 * s_track[4];
magmaFloatComplex G269 = G267 + G268;
magmaFloatComplex G270 = G151 * G29;
magmaFloatComplex G271 = G269 + G270;
magmaFloatComplex G272 = s_track[5]*s_track[5]*s_track[5];
magmaFloatComplex G273 = G236 * G272;
magmaFloatComplex G274 = G271 + G273;
magmaFloatComplex G275 = G171 * G29;
magmaFloatComplex G276 = G173 * s_track[3];
magmaFloatComplex G277 = G275 + G276;
magmaFloatComplex G278 = G214 * G87;
magmaFloatComplex G279 = G277 + G278;
magmaFloatComplex G280 = G175 * s_track[3];
magmaFloatComplex G281 = G279 + G280;
magmaFloatComplex G282 = G241 * s_track[5];
magmaFloatComplex G283 = G281 + G282;
magmaFloatComplex G284 = G219 * G87;
magmaFloatComplex G285 = G283 + G284;
magmaFloatComplex G286 = G129 * s_track[2];
magmaFloatComplex G287 = G130 * s_track[2];
magmaFloatComplex G288 = G286 + G287;
magmaFloatComplex G289 = G222 * s_track[4];
magmaFloatComplex G290 = G288 + G289;
magmaFloatComplex G291 = G184 * s_track[3];
magmaFloatComplex G292 = G290 + G291;
magmaFloatComplex G293 = G223 * s_track[4];
magmaFloatComplex G294 = G292 + G293;
magmaFloatComplex G295 = G186 * s_track[3];
magmaFloatComplex G296 = G188 * s_track[3];
magmaFloatComplex G297 = G295 + G296;
magmaFloatComplex G298 = G242 * s_track[5];
magmaFloatComplex G299 = G297 + G298;
magmaFloatComplex G300 = G145 * s_track[2];
magmaFloatComplex G301 = G299 + G300;
magmaFloatComplex G302 = s_track[3]*s_track[3]*s_track[3];
magmaFloatComplex G303 = G192 * G302;
magmaFloatComplex G304 = G301 + G303;
magmaFloatComplex G305 = G106 * s_track[4];
magmaFloatComplex G306 = G304 + G305;

    r_cgesvA[0] = G7;
    r_cgesvA[1] = G12;
    r_cgesvA[2] = G28;
    r_cgesvA[3] = G33;
    r_cgesvA[4] = G55;
    r_cgesvA[5] = G60;
    r_cgesvB[0] =G251;

    r_cgesvA[6] = G71;
    r_cgesvA[7] = G92;
    r_cgesvA[8] = G96;
    r_cgesvA[9] = G101;
    r_cgesvA[10] = G109;
    r_cgesvA[11] = C2;
    r_cgesvB[1] =G262;

    r_cgesvA[12] = C2;
    r_cgesvA[13] = G117;
    r_cgesvA[14] = C2;
    r_cgesvA[15] = G127;
    r_cgesvA[16] = G131;
    r_cgesvA[17] = G146;
    r_cgesvB[2] =G274;

    r_cgesvA[18] = G158;
    r_cgesvA[19] = G163;
    r_cgesvA[20] = G170;
    r_cgesvA[21] = G181;
    r_cgesvA[22] = G185;
    r_cgesvA[23] = G195;
    r_cgesvB[3] =G285;

    r_cgesvA[24] = G201;
    r_cgesvA[25] = G212;
    r_cgesvA[26] = G213;
    r_cgesvA[27] = G221;
    r_cgesvA[28] = G224;
    r_cgesvA[29] = G106;
    r_cgesvB[4] =G294;

    r_cgesvA[30] = G229;
    r_cgesvA[31] = G232;
    r_cgesvA[32] = G240;
    r_cgesvA[33] = G241;
    r_cgesvA[34] = C2;
    r_cgesvA[35] = G242;
    r_cgesvB[5] =G306;
 
  }
}

#endif
