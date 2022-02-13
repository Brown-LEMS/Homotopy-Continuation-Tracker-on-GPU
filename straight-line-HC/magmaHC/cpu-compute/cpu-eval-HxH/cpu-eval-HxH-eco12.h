#ifndef cpu_eval_HxH_echo12_h
#define cpu_eval_HxH_echo12_h
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
  void cpu_eval_HxH_echo12(
      magma_int_t s, float t, int N, magmaFloatComplex* s_track,
      const magmaFloatComplex &C0, const magmaFloatComplex &C1, const magmaFloatComplex &C2,
      magmaFloatComplex* s_startCoefs, magmaFloatComplex* s_targetCoefs,
      magmaFloatComplex* r_cgesvA, magmaFloatComplex* r_cgesvB )
  {
    magmaFloatComplex G1 = C0 - t;
magmaFloatComplex G2 = G1 * s_startCoefs[0];
magmaFloatComplex G3 = t * s_targetCoefs[0];
magmaFloatComplex G4 = G2 + G3;
magmaFloatComplex G5 = s_track[1] * G4;
magmaFloatComplex G6 = s_track[11] * G5;
magmaFloatComplex G7 = s_track[11] * G4;
magmaFloatComplex G8 = G6 + G7;
magmaFloatComplex G9 = s_track[2] * G4;
magmaFloatComplex G10 = s_track[11] * G9;
magmaFloatComplex G11 = s_track[3] * G4;
magmaFloatComplex G12 = s_track[11] * G11;
magmaFloatComplex G13 = s_track[4] * G4;
magmaFloatComplex G14 = s_track[11] * G13;
magmaFloatComplex G15 = s_track[5] * G4;
magmaFloatComplex G16 = s_track[11] * G15;
magmaFloatComplex G17 = s_track[6] * G4;
magmaFloatComplex G18 = s_track[11] * G17;
magmaFloatComplex G19 = s_track[7] * G4;
magmaFloatComplex G20 = s_track[11] * G19;
magmaFloatComplex G21 = s_track[8] * G4;
magmaFloatComplex G22 = s_track[11] * G21;
magmaFloatComplex G23 = s_track[9] * G4;
magmaFloatComplex G24 = s_track[11] * G23;
magmaFloatComplex G25 = s_track[10] * G4;
magmaFloatComplex G26 = s_track[11] * G25;
magmaFloatComplex G27 = G4 * s_track[0];
magmaFloatComplex G28 = s_track[11] * G27;
magmaFloatComplex G29 = G28 + G10;
magmaFloatComplex G30 = G12 + G7;
magmaFloatComplex G31 = G4 * s_track[1];
magmaFloatComplex G32 = s_track[11] * G31;
magmaFloatComplex G33 = G32 + G12;
magmaFloatComplex G34 = G28 + G14;
magmaFloatComplex G35 = G16 + G7;
magmaFloatComplex G36 = G4 * s_track[2];
magmaFloatComplex G37 = s_track[11] * G36;
magmaFloatComplex G38 = G37 + G14;
magmaFloatComplex G39 = G32 + G16;
magmaFloatComplex G40 = G28 + G18;
magmaFloatComplex G41 = G20 + G7;
magmaFloatComplex G42 = G4 * s_track[3];
magmaFloatComplex G43 = s_track[11] * G42;
magmaFloatComplex G44 = G43 + G16;
magmaFloatComplex G45 = G37 + G18;
magmaFloatComplex G46 = G32 + G20;
magmaFloatComplex G47 = G28 + G22;
magmaFloatComplex G48 = G24 + G7;
magmaFloatComplex G49 = G4 * s_track[4];
magmaFloatComplex G50 = s_track[11] * G49;
magmaFloatComplex G51 = G50 + G18;
magmaFloatComplex G52 = G43 + G20;
magmaFloatComplex G53 = G37 + G22;
magmaFloatComplex G54 = G32 + G24;
magmaFloatComplex G55 = G28 + G26;
magmaFloatComplex G56 = G4 * s_track[5];
magmaFloatComplex G57 = s_track[11] * G56;
magmaFloatComplex G58 = G57 + G20;
magmaFloatComplex G59 = G50 + G22;
magmaFloatComplex G60 = G43 + G24;
magmaFloatComplex G61 = G37 + G26;
magmaFloatComplex G62 = G4 * s_track[6];
magmaFloatComplex G63 = s_track[11] * G62;
magmaFloatComplex G64 = G63 + G22;
magmaFloatComplex G65 = G57 + G24;
magmaFloatComplex G66 = G50 + G26;
magmaFloatComplex G67 = G4 * s_track[7];
magmaFloatComplex G68 = s_track[11] * G67;
magmaFloatComplex G69 = G68 + G24;
magmaFloatComplex G70 = G63 + G26;
magmaFloatComplex G71 = G4 * s_track[8];
magmaFloatComplex G72 = s_track[11] * G71;
magmaFloatComplex G73 = G72 + G26;
magmaFloatComplex G74 = G4 * s_track[9];
magmaFloatComplex G75 = s_track[11] * G74;
magmaFloatComplex G76 = G27 * s_track[1];
magmaFloatComplex G77 = G76 + G27;
magmaFloatComplex G78 = G31 * s_track[2];
magmaFloatComplex G79 = G77 + G78;
magmaFloatComplex G80 = G36 * s_track[3];
magmaFloatComplex G81 = G79 + G80;
magmaFloatComplex G82 = G42 * s_track[4];
magmaFloatComplex G83 = G81 + G82;
magmaFloatComplex G84 = G49 * s_track[5];
magmaFloatComplex G85 = G83 + G84;
magmaFloatComplex G86 = G56 * s_track[6];
magmaFloatComplex G87 = G85 + G86;
magmaFloatComplex G88 = G62 * s_track[7];
magmaFloatComplex G89 = G87 + G88;
magmaFloatComplex G90 = G67 * s_track[8];
magmaFloatComplex G91 = G89 + G90;
magmaFloatComplex G92 = G71 * s_track[9];
magmaFloatComplex G93 = G91 + G92;
magmaFloatComplex G94 = G74 * s_track[10];
magmaFloatComplex G95 = G93 + G94;
magmaFloatComplex G96 = G27 * s_track[2];
magmaFloatComplex G97 = G31 * s_track[3];
magmaFloatComplex G98 = G96 + G97;
magmaFloatComplex G99 = G98 + G31;
magmaFloatComplex G100 = G36 * s_track[4];
magmaFloatComplex G101 = G99 + G100;
magmaFloatComplex G102 = G42 * s_track[5];
magmaFloatComplex G103 = G101 + G102;
magmaFloatComplex G104 = G49 * s_track[6];
magmaFloatComplex G105 = G103 + G104;
magmaFloatComplex G106 = G56 * s_track[7];
magmaFloatComplex G107 = G105 + G106;
magmaFloatComplex G108 = G62 * s_track[8];
magmaFloatComplex G109 = G107 + G108;
magmaFloatComplex G110 = G67 * s_track[9];
magmaFloatComplex G111 = G109 + G110;
magmaFloatComplex G112 = G71 * s_track[10];
magmaFloatComplex G113 = G111 + G112;
magmaFloatComplex G114 = G27 * s_track[3];
magmaFloatComplex G115 = G31 * s_track[4];
magmaFloatComplex G116 = G114 + G115;
magmaFloatComplex G117 = G36 * s_track[5];
magmaFloatComplex G118 = G116 + G117;
magmaFloatComplex G119 = G118 + G36;
magmaFloatComplex G120 = G42 * s_track[6];
magmaFloatComplex G121 = G119 + G120;
magmaFloatComplex G122 = G49 * s_track[7];
magmaFloatComplex G123 = G121 + G122;
magmaFloatComplex G124 = G56 * s_track[8];
magmaFloatComplex G125 = G123 + G124;
magmaFloatComplex G126 = G62 * s_track[9];
magmaFloatComplex G127 = G125 + G126;
magmaFloatComplex G128 = G67 * s_track[10];
magmaFloatComplex G129 = G127 + G128;
magmaFloatComplex G130 = G27 * s_track[4];
magmaFloatComplex G131 = G31 * s_track[5];
magmaFloatComplex G132 = G130 + G131;
magmaFloatComplex G133 = G36 * s_track[6];
magmaFloatComplex G134 = G132 + G133;
magmaFloatComplex G135 = G42 * s_track[7];
magmaFloatComplex G136 = G134 + G135;
magmaFloatComplex G137 = G136 + G42;
magmaFloatComplex G138 = G49 * s_track[8];
magmaFloatComplex G139 = G137 + G138;
magmaFloatComplex G140 = G56 * s_track[9];
magmaFloatComplex G141 = G139 + G140;
magmaFloatComplex G142 = G62 * s_track[10];
magmaFloatComplex G143 = G141 + G142;
magmaFloatComplex G144 = G27 * s_track[5];
magmaFloatComplex G145 = G31 * s_track[6];
magmaFloatComplex G146 = G144 + G145;
magmaFloatComplex G147 = G36 * s_track[7];
magmaFloatComplex G148 = G146 + G147;
magmaFloatComplex G149 = G42 * s_track[8];
magmaFloatComplex G150 = G148 + G149;
magmaFloatComplex G151 = G49 * s_track[9];
magmaFloatComplex G152 = G150 + G151;
magmaFloatComplex G153 = G152 + G49;
magmaFloatComplex G154 = G56 * s_track[10];
magmaFloatComplex G155 = G153 + G154;
magmaFloatComplex G156 = G27 * s_track[6];
magmaFloatComplex G157 = G31 * s_track[7];
magmaFloatComplex G158 = G156 + G157;
magmaFloatComplex G159 = G36 * s_track[8];
magmaFloatComplex G160 = G158 + G159;
magmaFloatComplex G161 = G42 * s_track[9];
magmaFloatComplex G162 = G160 + G161;
magmaFloatComplex G163 = G49 * s_track[10];
magmaFloatComplex G164 = G162 + G163;
magmaFloatComplex G165 = G164 + G56;
magmaFloatComplex G166 = G27 * s_track[7];
magmaFloatComplex G167 = G31 * s_track[8];
magmaFloatComplex G168 = G166 + G167;
magmaFloatComplex G169 = G36 * s_track[9];
magmaFloatComplex G170 = G168 + G169;
magmaFloatComplex G171 = G42 * s_track[10];
magmaFloatComplex G172 = G170 + G171;
magmaFloatComplex G173 = G172 + G62;
magmaFloatComplex G174 = G27 * s_track[8];
magmaFloatComplex G175 = G31 * s_track[9];
magmaFloatComplex G176 = G174 + G175;
magmaFloatComplex G177 = G36 * s_track[10];
magmaFloatComplex G178 = G176 + G177;
magmaFloatComplex G179 = G178 + G67;
magmaFloatComplex G180 = G27 * s_track[9];
magmaFloatComplex G181 = G31 * s_track[10];
magmaFloatComplex G182 = G180 + G181;
magmaFloatComplex G183 = G182 + G71;
magmaFloatComplex G184 = G27 * s_track[10];
magmaFloatComplex G185 = G184 + G74;
magmaFloatComplex G186 = G4 * s_track[10];
magmaFloatComplex G187 = G76 * s_track[11];
magmaFloatComplex G188 = G27 * s_track[11];
magmaFloatComplex G189 = G187 + G188;
magmaFloatComplex G190 = G78 * s_track[11];
magmaFloatComplex G191 = G189 + G190;
magmaFloatComplex G192 = G80 * s_track[11];
magmaFloatComplex G193 = G191 + G192;
magmaFloatComplex G194 = G82 * s_track[11];
magmaFloatComplex G195 = G193 + G194;
magmaFloatComplex G196 = G84 * s_track[11];
magmaFloatComplex G197 = G195 + G196;
magmaFloatComplex G198 = G86 * s_track[11];
magmaFloatComplex G199 = G197 + G198;
magmaFloatComplex G200 = G88 * s_track[11];
magmaFloatComplex G201 = G199 + G200;
magmaFloatComplex G202 = G90 * s_track[11];
magmaFloatComplex G203 = G201 + G202;
magmaFloatComplex G204 = G92 * s_track[11];
magmaFloatComplex G205 = G203 + G204;
magmaFloatComplex G206 = G94 * s_track[11];
magmaFloatComplex G207 = G205 + G206;
magmaFloatComplex G208 = G1 * s_startCoefs[1];
magmaFloatComplex G209 = t * s_targetCoefs[1];
magmaFloatComplex G210 = G208 + G209;
magmaFloatComplex G211 = G207 + G210;
magmaFloatComplex G212 = G96 * s_track[11];
magmaFloatComplex G213 = G97 * s_track[11];
magmaFloatComplex G214 = G212 + G213;
magmaFloatComplex G215 = G31 * s_track[11];
magmaFloatComplex G216 = G214 + G215;
magmaFloatComplex G217 = G100 * s_track[11];
magmaFloatComplex G218 = G216 + G217;
magmaFloatComplex G219 = G102 * s_track[11];
magmaFloatComplex G220 = G218 + G219;
magmaFloatComplex G221 = G104 * s_track[11];
magmaFloatComplex G222 = G220 + G221;
magmaFloatComplex G223 = G106 * s_track[11];
magmaFloatComplex G224 = G222 + G223;
magmaFloatComplex G225 = G108 * s_track[11];
magmaFloatComplex G226 = G224 + G225;
magmaFloatComplex G227 = G110 * s_track[11];
magmaFloatComplex G228 = G226 + G227;
magmaFloatComplex G229 = G112 * s_track[11];
magmaFloatComplex G230 = G228 + G229;
magmaFloatComplex G231 = G1 * s_startCoefs[2];
magmaFloatComplex G232 = t * s_targetCoefs[2];
magmaFloatComplex G233 = G231 + G232;
magmaFloatComplex G234 = G230 + G233;
magmaFloatComplex G235 = G114 * s_track[11];
magmaFloatComplex G236 = G115 * s_track[11];
magmaFloatComplex G237 = G235 + G236;
magmaFloatComplex G238 = G117 * s_track[11];
magmaFloatComplex G239 = G237 + G238;
magmaFloatComplex G240 = G36 * s_track[11];
magmaFloatComplex G241 = G239 + G240;
magmaFloatComplex G242 = G120 * s_track[11];
magmaFloatComplex G243 = G241 + G242;
magmaFloatComplex G244 = G122 * s_track[11];
magmaFloatComplex G245 = G243 + G244;
magmaFloatComplex G246 = G124 * s_track[11];
magmaFloatComplex G247 = G245 + G246;
magmaFloatComplex G248 = G126 * s_track[11];
magmaFloatComplex G249 = G247 + G248;
magmaFloatComplex G250 = G128 * s_track[11];
magmaFloatComplex G251 = G249 + G250;
magmaFloatComplex G252 = G1 * s_startCoefs[3];
magmaFloatComplex G253 = t * s_targetCoefs[3];
magmaFloatComplex G254 = G252 + G253;
magmaFloatComplex G255 = G251 + G254;
magmaFloatComplex G256 = G130 * s_track[11];
magmaFloatComplex G257 = G131 * s_track[11];
magmaFloatComplex G258 = G256 + G257;
magmaFloatComplex G259 = G133 * s_track[11];
magmaFloatComplex G260 = G258 + G259;
magmaFloatComplex G261 = G135 * s_track[11];
magmaFloatComplex G262 = G260 + G261;
magmaFloatComplex G263 = G42 * s_track[11];
magmaFloatComplex G264 = G262 + G263;
magmaFloatComplex G265 = G138 * s_track[11];
magmaFloatComplex G266 = G264 + G265;
magmaFloatComplex G267 = G140 * s_track[11];
magmaFloatComplex G268 = G266 + G267;
magmaFloatComplex G269 = G142 * s_track[11];
magmaFloatComplex G270 = G268 + G269;
magmaFloatComplex G271 = G1 * s_startCoefs[4];
magmaFloatComplex G272 = t * s_targetCoefs[4];
magmaFloatComplex G273 = G271 + G272;
magmaFloatComplex G274 = G270 + G273;
magmaFloatComplex G275 = G144 * s_track[11];
magmaFloatComplex G276 = G145 * s_track[11];
magmaFloatComplex G277 = G275 + G276;
magmaFloatComplex G278 = G147 * s_track[11];
magmaFloatComplex G279 = G277 + G278;
magmaFloatComplex G280 = G149 * s_track[11];
magmaFloatComplex G281 = G279 + G280;
magmaFloatComplex G282 = G151 * s_track[11];
magmaFloatComplex G283 = G281 + G282;
magmaFloatComplex G284 = G49 * s_track[11];
magmaFloatComplex G285 = G283 + G284;
magmaFloatComplex G286 = G154 * s_track[11];
magmaFloatComplex G287 = G285 + G286;
magmaFloatComplex G288 = G1 * s_startCoefs[5];
magmaFloatComplex G289 = t * s_targetCoefs[5];
magmaFloatComplex G290 = G288 + G289;
magmaFloatComplex G291 = G287 + G290;
magmaFloatComplex G292 = G156 * s_track[11];
magmaFloatComplex G293 = G157 * s_track[11];
magmaFloatComplex G294 = G292 + G293;
magmaFloatComplex G295 = G159 * s_track[11];
magmaFloatComplex G296 = G294 + G295;
magmaFloatComplex G297 = G161 * s_track[11];
magmaFloatComplex G298 = G296 + G297;
magmaFloatComplex G299 = G163 * s_track[11];
magmaFloatComplex G300 = G298 + G299;
magmaFloatComplex G301 = G56 * s_track[11];
magmaFloatComplex G302 = G300 + G301;
magmaFloatComplex G303 = G1 * s_startCoefs[6];
magmaFloatComplex G304 = t * s_targetCoefs[6];
magmaFloatComplex G305 = G303 + G304;
magmaFloatComplex G306 = G302 + G305;
magmaFloatComplex G307 = G166 * s_track[11];
magmaFloatComplex G308 = G167 * s_track[11];
magmaFloatComplex G309 = G307 + G308;
magmaFloatComplex G310 = G169 * s_track[11];
magmaFloatComplex G311 = G309 + G310;
magmaFloatComplex G312 = G171 * s_track[11];
magmaFloatComplex G313 = G311 + G312;
magmaFloatComplex G314 = G62 * s_track[11];
magmaFloatComplex G315 = G313 + G314;
magmaFloatComplex G316 = G1 * s_startCoefs[7];
magmaFloatComplex G317 = t * s_targetCoefs[7];
magmaFloatComplex G318 = G316 + G317;
magmaFloatComplex G319 = G315 + G318;
magmaFloatComplex G320 = G174 * s_track[11];
magmaFloatComplex G321 = G175 * s_track[11];
magmaFloatComplex G322 = G320 + G321;
magmaFloatComplex G323 = G177 * s_track[11];
magmaFloatComplex G324 = G322 + G323;
magmaFloatComplex G325 = G67 * s_track[11];
magmaFloatComplex G326 = G324 + G325;
magmaFloatComplex G327 = G1 * s_startCoefs[8];
magmaFloatComplex G328 = t * s_targetCoefs[8];
magmaFloatComplex G329 = G327 + G328;
magmaFloatComplex G330 = G326 + G329;
magmaFloatComplex G331 = G180 * s_track[11];
magmaFloatComplex G332 = G181 * s_track[11];
magmaFloatComplex G333 = G331 + G332;
magmaFloatComplex G334 = G71 * s_track[11];
magmaFloatComplex G335 = G333 + G334;
magmaFloatComplex G336 = G1 * s_startCoefs[9];
magmaFloatComplex G337 = t * s_targetCoefs[9];
magmaFloatComplex G338 = G336 + G337;
magmaFloatComplex G339 = G335 + G338;
magmaFloatComplex G340 = G184 * s_track[11];
magmaFloatComplex G341 = G74 * s_track[11];
magmaFloatComplex G342 = G340 + G341;
magmaFloatComplex G343 = G1 * s_startCoefs[10];
magmaFloatComplex G344 = t * s_targetCoefs[10];
magmaFloatComplex G345 = G343 + G344;
magmaFloatComplex G346 = G342 + G345;
magmaFloatComplex G347 = G186 * s_track[11];
magmaFloatComplex G348 = G1 * s_startCoefs[11];
magmaFloatComplex G349 = t * s_targetCoefs[11];
magmaFloatComplex G350 = G348 + G349;
magmaFloatComplex G351 = G347 + G350;
magmaFloatComplex G352 = G27 + G31;
magmaFloatComplex G353 = G352 + G36;
magmaFloatComplex G354 = G353 + G42;
magmaFloatComplex G355 = G354 + G49;
magmaFloatComplex G356 = G355 + G56;
magmaFloatComplex G357 = G356 + G62;
magmaFloatComplex G358 = G357 + G67;
magmaFloatComplex G359 = G358 + G71;
magmaFloatComplex G360 = G359 + G74;
magmaFloatComplex G361 = G360 + G186;
magmaFloatComplex G362 = G361 + G4;

    r_cgesvA[0] = G8;
r_cgesvA[1] = G10;
r_cgesvA[2] = G12;
r_cgesvA[3] = G14;
r_cgesvA[4] = G16;
r_cgesvA[5] = G18;
r_cgesvA[6] = G20;
r_cgesvA[7] = G22;
r_cgesvA[8] = G24;
r_cgesvA[9] = G26;
r_cgesvA[10] = C2;
r_cgesvA[11] = G4;
r_cgesvB[0] =G211;

r_cgesvA[12] = G29;
r_cgesvA[13] = G30;
r_cgesvA[14] = G14;
r_cgesvA[15] = G16;
r_cgesvA[16] = G18;
r_cgesvA[17] = G20;
r_cgesvA[18] = G22;
r_cgesvA[19] = G24;
r_cgesvA[20] = G26;
r_cgesvA[21] = C2;
r_cgesvA[22] = C2;
r_cgesvA[23] = G4;
r_cgesvB[1] =G234;

r_cgesvA[24] = G33;
r_cgesvA[25] = G34;
r_cgesvA[26] = G35;
r_cgesvA[27] = G18;
r_cgesvA[28] = G20;
r_cgesvA[29] = G22;
r_cgesvA[30] = G24;
r_cgesvA[31] = G26;
r_cgesvA[32] = C2;
r_cgesvA[33] = C2;
r_cgesvA[34] = C2;
r_cgesvA[35] = G4;
r_cgesvB[2] =G255;

r_cgesvA[36] = G38;
r_cgesvA[37] = G39;
r_cgesvA[38] = G40;
r_cgesvA[39] = G41;
r_cgesvA[40] = G22;
r_cgesvA[41] = G24;
r_cgesvA[42] = G26;
r_cgesvA[43] = C2;
r_cgesvA[44] = C2;
r_cgesvA[45] = C2;
r_cgesvA[46] = C2;
r_cgesvA[47] = G4;
r_cgesvB[3] =G274;

r_cgesvA[48] = G44;
r_cgesvA[49] = G45;
r_cgesvA[50] = G46;
r_cgesvA[51] = G47;
r_cgesvA[52] = G48;
r_cgesvA[53] = G26;
r_cgesvA[54] = C2;
r_cgesvA[55] = C2;
r_cgesvA[56] = C2;
r_cgesvA[57] = C2;
r_cgesvA[58] = C2;
r_cgesvA[59] = G4;
r_cgesvB[4] =G291;

r_cgesvA[60] = G51;
r_cgesvA[61] = G52;
r_cgesvA[62] = G53;
r_cgesvA[63] = G54;
r_cgesvA[64] = G55;
r_cgesvA[65] = G7;
r_cgesvA[66] = C2;
r_cgesvA[67] = C2;
r_cgesvA[68] = C2;
r_cgesvA[69] = C2;
r_cgesvA[70] = C2;
r_cgesvA[71] = G4;
r_cgesvB[5] =G306;

r_cgesvA[72] = G58;
r_cgesvA[73] = G59;
r_cgesvA[74] = G60;
r_cgesvA[75] = G61;
r_cgesvA[76] = G32;
r_cgesvA[77] = G28;
r_cgesvA[78] = G7;
r_cgesvA[79] = C2;
r_cgesvA[80] = C2;
r_cgesvA[81] = C2;
r_cgesvA[82] = C2;
r_cgesvA[83] = G4;
r_cgesvB[6] =G319;

r_cgesvA[84] = G64;
r_cgesvA[85] = G65;
r_cgesvA[86] = G66;
r_cgesvA[87] = G43;
r_cgesvA[88] = G37;
r_cgesvA[89] = G32;
r_cgesvA[90] = G28;
r_cgesvA[91] = G7;
r_cgesvA[92] = C2;
r_cgesvA[93] = C2;
r_cgesvA[94] = C2;
r_cgesvA[95] = G4;
r_cgesvB[7] =G330;

r_cgesvA[96] = G69;
r_cgesvA[97] = G70;
r_cgesvA[98] = G57;
r_cgesvA[99] = G50;
r_cgesvA[100] = G43;
r_cgesvA[101] = G37;
r_cgesvA[102] = G32;
r_cgesvA[103] = G28;
r_cgesvA[104] = G7;
r_cgesvA[105] = C2;
r_cgesvA[106] = C2;
r_cgesvA[107] = G4;
r_cgesvB[8] =G339;

r_cgesvA[108] = G73;
r_cgesvA[109] = G68;
r_cgesvA[110] = G63;
r_cgesvA[111] = G57;
r_cgesvA[112] = G50;
r_cgesvA[113] = G43;
r_cgesvA[114] = G37;
r_cgesvA[115] = G32;
r_cgesvA[116] = G28;
r_cgesvA[117] = G7;
r_cgesvA[118] = C2;
r_cgesvA[119] = G4;
r_cgesvB[9] =G346;

r_cgesvA[120] = G75;
r_cgesvA[121] = G72;
r_cgesvA[122] = G68;
r_cgesvA[123] = G63;
r_cgesvA[124] = G57;
r_cgesvA[125] = G50;
r_cgesvA[126] = G43;
r_cgesvA[127] = G37;
r_cgesvA[128] = G32;
r_cgesvA[129] = G28;
r_cgesvA[130] = G7;
r_cgesvA[131] = G4;
r_cgesvB[10] =G351;

r_cgesvA[132] = G95;
r_cgesvA[133] = G113;
r_cgesvA[134] = G129;
r_cgesvA[135] = G143;
r_cgesvA[136] = G155;
r_cgesvA[137] = G165;
r_cgesvA[138] = G173;
r_cgesvA[139] = G179;
r_cgesvA[140] = G183;
r_cgesvA[141] = G185;
r_cgesvA[142] = G186;
r_cgesvA[143] = C2;
r_cgesvB[11] =G362;

  }
}

#endif
