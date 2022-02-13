#ifndef cpu_eval_HxH_katsura15_h
#define cpu_eval_HxH_katsura15_h
// ============================================================================
// partial derivative evaluations of the katsura15 problem for cpu HC computation
//
// Modifications
//    Chien  22-01-24:   Originally created
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
  void cpu_eval_HxH_katsura15(
      magma_int_t s, float t, int N, magmaFloatComplex* s_track,
      const magmaFloatComplex &C0, const magmaFloatComplex &C1,
      magmaFloatComplex* s_startCoefs, magmaFloatComplex* s_targetCoefs,
      magmaFloatComplex* r_cgesvA, magmaFloatComplex* r_cgesvB )
  {
magmaFloatComplex G0 = C1 * t;
magmaFloatComplex G1 = C0 + G0;
magmaFloatComplex G2 = G1 * s_startCoefs[0];
magmaFloatComplex G3 = t * s_targetCoefs[0];
magmaFloatComplex G4 = G2 + G3;
magmaFloatComplex G5 = s_track[0] + s_track[0];
magmaFloatComplex G6 = G4 * G5;
magmaFloatComplex G7 = G1 * s_startCoefs[1];
magmaFloatComplex G8 = t * s_targetCoefs[1];
magmaFloatComplex G9 = G7 + G8;
magmaFloatComplex G10 = G6 + G9;
magmaFloatComplex G11 = G1 * s_startCoefs[2];
magmaFloatComplex G12 = t * s_targetCoefs[2];
magmaFloatComplex G13 = G11 + G12;
magmaFloatComplex G14 = s_track[1] * G13;
magmaFloatComplex G15 = s_track[2] * G13;
magmaFloatComplex G16 = s_track[3] * G13;
magmaFloatComplex G17 = s_track[4] * G13;
magmaFloatComplex G18 = s_track[5] * G13;
magmaFloatComplex G19 = s_track[6] * G13;
magmaFloatComplex G20 = s_track[7] * G13;
magmaFloatComplex G21 = s_track[8] * G13;
magmaFloatComplex G22 = s_track[9] * G13;
magmaFloatComplex G23 = s_track[10] * G13;
magmaFloatComplex G24 = s_track[11] * G13;
magmaFloatComplex G25 = s_track[12] * G13;
magmaFloatComplex G26 = s_track[13] * G13;
magmaFloatComplex G27 = s_track[14] * G13;
magmaFloatComplex G28 = s_track[1] + s_track[1];
magmaFloatComplex G29 = G13 * G28;
magmaFloatComplex G30 = G13 * s_track[0];
magmaFloatComplex G31 = G30 + G15;
magmaFloatComplex G32 = G31 + G9;
magmaFloatComplex G33 = G4 * G28;
magmaFloatComplex G34 = G33 + G16;
magmaFloatComplex G35 = G15 + G17;
magmaFloatComplex G36 = G16 + G18;
magmaFloatComplex G37 = G17 + G19;
magmaFloatComplex G38 = G18 + G20;
magmaFloatComplex G39 = G19 + G21;
magmaFloatComplex G40 = G20 + G22;
magmaFloatComplex G41 = G21 + G23;
magmaFloatComplex G42 = G22 + G24;
magmaFloatComplex G43 = G23 + G25;
magmaFloatComplex G44 = G24 + G26;
magmaFloatComplex G45 = G25 + G27;
magmaFloatComplex G46 = s_track[15] * G13;
magmaFloatComplex G47 = G26 + G46;
magmaFloatComplex G48 = s_track[2] + s_track[2];
magmaFloatComplex G49 = G13 * G48;
magmaFloatComplex G50 = G13 * s_track[1];
magmaFloatComplex G51 = G50 + G16;
magmaFloatComplex G52 = G30 + G17;
magmaFloatComplex G53 = G52 + G9;
magmaFloatComplex G54 = G50 + G18;
magmaFloatComplex G55 = G4 * G48;
magmaFloatComplex G56 = G55 + G19;
magmaFloatComplex G57 = G16 + G20;
magmaFloatComplex G58 = G17 + G21;
magmaFloatComplex G59 = G18 + G22;
magmaFloatComplex G60 = G19 + G23;
magmaFloatComplex G61 = G20 + G24;
magmaFloatComplex G62 = G21 + G25;
magmaFloatComplex G63 = G22 + G26;
magmaFloatComplex G64 = G23 + G27;
magmaFloatComplex G65 = G24 + G46;
magmaFloatComplex G66 = s_track[3] + s_track[3];
magmaFloatComplex G67 = G13 * G66;
magmaFloatComplex G68 = G13 * s_track[2];
magmaFloatComplex G69 = G68 + G17;
magmaFloatComplex G70 = G30 + G19;
magmaFloatComplex G71 = G70 + G9;
magmaFloatComplex G72 = G50 + G20;
magmaFloatComplex G73 = G68 + G21;
magmaFloatComplex G74 = G4 * G66;
magmaFloatComplex G75 = G74 + G22;
magmaFloatComplex G76 = G17 + G23;
magmaFloatComplex G77 = G18 + G24;
magmaFloatComplex G78 = G19 + G25;
magmaFloatComplex G79 = G20 + G26;
magmaFloatComplex G80 = G21 + G27;
magmaFloatComplex G81 = G22 + G46;
magmaFloatComplex G82 = s_track[4] + s_track[4];
magmaFloatComplex G83 = G13 * G82;
magmaFloatComplex G84 = G13 * s_track[3];
magmaFloatComplex G85 = G84 + G18;
magmaFloatComplex G86 = G68 + G19;
magmaFloatComplex G87 = G30 + G21;
magmaFloatComplex G88 = G87 + G9;
magmaFloatComplex G89 = G50 + G22;
magmaFloatComplex G90 = G68 + G23;
magmaFloatComplex G91 = G84 + G24;
magmaFloatComplex G92 = G4 * G82;
magmaFloatComplex G93 = G92 + G25;
magmaFloatComplex G94 = G18 + G26;
magmaFloatComplex G95 = G19 + G27;
magmaFloatComplex G96 = G20 + G46;
magmaFloatComplex G97 = s_track[5] + s_track[5];
magmaFloatComplex G98 = G13 * G97;
magmaFloatComplex G99 = G13 * s_track[4];
magmaFloatComplex G100 = G99 + G19;
magmaFloatComplex G101 = G84 + G20;
magmaFloatComplex G102 = G30 + G23;
magmaFloatComplex G103 = G102 + G9;
magmaFloatComplex G104 = G50 + G24;
magmaFloatComplex G105 = G68 + G25;
magmaFloatComplex G106 = G84 + G26;
magmaFloatComplex G107 = G99 + G27;
magmaFloatComplex G108 = G4 * G97;
magmaFloatComplex G109 = G108 + G46;
magmaFloatComplex G110 = s_track[6] + s_track[6];
magmaFloatComplex G111 = G13 * G110;
magmaFloatComplex G112 = G13 * s_track[5];
magmaFloatComplex G113 = G112 + G20;
magmaFloatComplex G114 = G99 + G21;
magmaFloatComplex G115 = G84 + G22;
magmaFloatComplex G116 = G30 + G25;
magmaFloatComplex G117 = G116 + G9;
magmaFloatComplex G118 = G50 + G26;
magmaFloatComplex G119 = G68 + G27;
magmaFloatComplex G120 = G84 + G46;
magmaFloatComplex G121 = G4 * G110;
magmaFloatComplex G122 = s_track[7] + s_track[7];
magmaFloatComplex G123 = G13 * G122;
magmaFloatComplex G124 = G13 * s_track[6];
magmaFloatComplex G125 = G124 + G21;
magmaFloatComplex G126 = G112 + G22;
magmaFloatComplex G127 = G99 + G23;
magmaFloatComplex G128 = G30 + G27;
magmaFloatComplex G129 = G128 + G9;
magmaFloatComplex G130 = G50 + G46;
magmaFloatComplex G131 = G4 * G122;
magmaFloatComplex G132 = s_track[8] + s_track[8];
magmaFloatComplex G133 = G13 * G132;
magmaFloatComplex G134 = G13 * s_track[7];
magmaFloatComplex G135 = G134 + G22;
magmaFloatComplex G136 = G124 + G23;
magmaFloatComplex G137 = G112 + G24;
magmaFloatComplex G138 = G99 + G25;
magmaFloatComplex G139 = G30 + G9;
magmaFloatComplex G140 = s_track[9] + s_track[9];
magmaFloatComplex G141 = G13 * G140;
magmaFloatComplex G142 = G13 * s_track[8];
magmaFloatComplex G143 = G142 + G23;
magmaFloatComplex G144 = G134 + G24;
magmaFloatComplex G145 = G124 + G25;
magmaFloatComplex G146 = G112 + G26;
magmaFloatComplex G147 = s_track[10] + s_track[10];
magmaFloatComplex G148 = G13 * G147;
magmaFloatComplex G149 = G13 * s_track[9];
magmaFloatComplex G150 = G149 + G24;
magmaFloatComplex G151 = G142 + G25;
magmaFloatComplex G152 = G134 + G26;
magmaFloatComplex G153 = G124 + G27;
magmaFloatComplex G154 = G112 + G46;
magmaFloatComplex G155 = s_track[11] + s_track[11];
magmaFloatComplex G156 = G13 * G155;
magmaFloatComplex G157 = G13 * s_track[10];
magmaFloatComplex G158 = G157 + G25;
magmaFloatComplex G159 = G149 + G26;
magmaFloatComplex G160 = G142 + G27;
magmaFloatComplex G161 = G134 + G46;
magmaFloatComplex G162 = s_track[12] + s_track[12];
magmaFloatComplex G163 = G13 * G162;
magmaFloatComplex G164 = G13 * s_track[11];
magmaFloatComplex G165 = G164 + G26;
magmaFloatComplex G166 = G157 + G27;
magmaFloatComplex G167 = G149 + G46;
magmaFloatComplex G168 = s_track[13] + s_track[13];
magmaFloatComplex G169 = G13 * G168;
magmaFloatComplex G170 = G13 * s_track[12];
magmaFloatComplex G171 = G170 + G27;
magmaFloatComplex G172 = G164 + G46;
magmaFloatComplex G173 = s_track[14] + s_track[14];
magmaFloatComplex G174 = G13 * G173;
magmaFloatComplex G175 = G13 * s_track[13];
magmaFloatComplex G176 = G175 + G46;
magmaFloatComplex G177 = s_track[15] + s_track[15];
magmaFloatComplex G178 = G13 * G177;
magmaFloatComplex G179 = G13 * s_track[14];
magmaFloatComplex G180 = s_track[0] * s_track[0];
magmaFloatComplex G181 = G4 * G180;
magmaFloatComplex G182 = G9 * s_track[0];
magmaFloatComplex G183 = G181 + G182;
magmaFloatComplex G184 = s_track[1] * s_track[1];
magmaFloatComplex G185 = G13 * G184;
magmaFloatComplex G186 = G183 + G185;
magmaFloatComplex G187 = s_track[2] * s_track[2];
magmaFloatComplex G188 = G13 * G187;
magmaFloatComplex G189 = G186 + G188;
magmaFloatComplex G190 = s_track[3] * s_track[3];
magmaFloatComplex G191 = G13 * G190;
magmaFloatComplex G192 = G189 + G191;
magmaFloatComplex G193 = s_track[4] * s_track[4];
magmaFloatComplex G194 = G13 * G193;
magmaFloatComplex G195 = G192 + G194;
magmaFloatComplex G196 = s_track[5] * s_track[5];
magmaFloatComplex G197 = G13 * G196;
magmaFloatComplex G198 = G195 + G197;
magmaFloatComplex G199 = s_track[6] * s_track[6];
magmaFloatComplex G200 = G13 * G199;
magmaFloatComplex G201 = G198 + G200;
magmaFloatComplex G202 = s_track[7] * s_track[7];
magmaFloatComplex G203 = G13 * G202;
magmaFloatComplex G204 = G201 + G203;
magmaFloatComplex G205 = s_track[8] * s_track[8];
magmaFloatComplex G206 = G13 * G205;
magmaFloatComplex G207 = G204 + G206;
magmaFloatComplex G208 = s_track[9] * s_track[9];
magmaFloatComplex G209 = G13 * G208;
magmaFloatComplex G210 = G207 + G209;
magmaFloatComplex G211 = s_track[10] * s_track[10];
magmaFloatComplex G212 = G13 * G211;
magmaFloatComplex G213 = G210 + G212;
magmaFloatComplex G214 = s_track[11] * s_track[11];
magmaFloatComplex G215 = G13 * G214;
magmaFloatComplex G216 = G213 + G215;
magmaFloatComplex G217 = s_track[12] * s_track[12];
magmaFloatComplex G218 = G13 * G217;
magmaFloatComplex G219 = G216 + G218;
magmaFloatComplex G220 = s_track[13] * s_track[13];
magmaFloatComplex G221 = G13 * G220;
magmaFloatComplex G222 = G219 + G221;
magmaFloatComplex G223 = s_track[14] * s_track[14];
magmaFloatComplex G224 = G13 * G223;
magmaFloatComplex G225 = G222 + G224;
magmaFloatComplex G226 = s_track[15] * s_track[15];
magmaFloatComplex G227 = G13 * G226;
magmaFloatComplex G228 = G225 + G227;
magmaFloatComplex G229 = G30 * s_track[1];
magmaFloatComplex G230 = G50 * s_track[2];
magmaFloatComplex G231 = G229 + G230;
magmaFloatComplex G232 = G9 * s_track[1];
magmaFloatComplex G233 = G231 + G232;
magmaFloatComplex G234 = G68 * s_track[3];
magmaFloatComplex G235 = G233 + G234;
magmaFloatComplex G236 = G84 * s_track[4];
magmaFloatComplex G237 = G235 + G236;
magmaFloatComplex G238 = G99 * s_track[5];
magmaFloatComplex G239 = G237 + G238;
magmaFloatComplex G240 = G112 * s_track[6];
magmaFloatComplex G241 = G239 + G240;
magmaFloatComplex G242 = G124 * s_track[7];
magmaFloatComplex G243 = G241 + G242;
magmaFloatComplex G244 = G134 * s_track[8];
magmaFloatComplex G245 = G243 + G244;
magmaFloatComplex G246 = G142 * s_track[9];
magmaFloatComplex G247 = G245 + G246;
magmaFloatComplex G248 = G149 * s_track[10];
magmaFloatComplex G249 = G247 + G248;
magmaFloatComplex G250 = G157 * s_track[11];
magmaFloatComplex G251 = G249 + G250;
magmaFloatComplex G252 = G164 * s_track[12];
magmaFloatComplex G253 = G251 + G252;
magmaFloatComplex G254 = G170 * s_track[13];
magmaFloatComplex G255 = G253 + G254;
magmaFloatComplex G256 = G175 * s_track[14];
magmaFloatComplex G257 = G255 + G256;
magmaFloatComplex G258 = G179 * s_track[15];
magmaFloatComplex G259 = G257 + G258;
magmaFloatComplex G260 = G30 * s_track[2];
magmaFloatComplex G261 = G4 * G184;
magmaFloatComplex G262 = G260 + G261;
magmaFloatComplex G263 = G50 * s_track[3];
magmaFloatComplex G264 = G262 + G263;
magmaFloatComplex G265 = G68 * s_track[4];
magmaFloatComplex G266 = G264 + G265;
magmaFloatComplex G267 = G9 * s_track[2];
magmaFloatComplex G268 = G266 + G267;
magmaFloatComplex G269 = G84 * s_track[5];
magmaFloatComplex G270 = G268 + G269;
magmaFloatComplex G271 = G99 * s_track[6];
magmaFloatComplex G272 = G270 + G271;
magmaFloatComplex G273 = G112 * s_track[7];
magmaFloatComplex G274 = G272 + G273;
magmaFloatComplex G275 = G124 * s_track[8];
magmaFloatComplex G276 = G274 + G275;
magmaFloatComplex G277 = G134 * s_track[9];
magmaFloatComplex G278 = G276 + G277;
magmaFloatComplex G279 = G142 * s_track[10];
magmaFloatComplex G280 = G278 + G279;
magmaFloatComplex G281 = G149 * s_track[11];
magmaFloatComplex G282 = G280 + G281;
magmaFloatComplex G283 = G157 * s_track[12];
magmaFloatComplex G284 = G282 + G283;
magmaFloatComplex G285 = G164 * s_track[13];
magmaFloatComplex G286 = G284 + G285;
magmaFloatComplex G287 = G170 * s_track[14];
magmaFloatComplex G288 = G286 + G287;
magmaFloatComplex G289 = G175 * s_track[15];
magmaFloatComplex G290 = G288 + G289;
magmaFloatComplex G291 = G30 * s_track[3];
magmaFloatComplex G292 = G291 + G230;
magmaFloatComplex G293 = G50 * s_track[4];
magmaFloatComplex G294 = G292 + G293;
magmaFloatComplex G295 = G68 * s_track[5];
magmaFloatComplex G296 = G294 + G295;
magmaFloatComplex G297 = G84 * s_track[6];
magmaFloatComplex G298 = G296 + G297;
magmaFloatComplex G299 = G9 * s_track[3];
magmaFloatComplex G300 = G298 + G299;
magmaFloatComplex G301 = G99 * s_track[7];
magmaFloatComplex G302 = G300 + G301;
magmaFloatComplex G303 = G112 * s_track[8];
magmaFloatComplex G304 = G302 + G303;
magmaFloatComplex G305 = G124 * s_track[9];
magmaFloatComplex G306 = G304 + G305;
magmaFloatComplex G307 = G134 * s_track[10];
magmaFloatComplex G308 = G306 + G307;
magmaFloatComplex G309 = G142 * s_track[11];
magmaFloatComplex G310 = G308 + G309;
magmaFloatComplex G311 = G149 * s_track[12];
magmaFloatComplex G312 = G310 + G311;
magmaFloatComplex G313 = G157 * s_track[13];
magmaFloatComplex G314 = G312 + G313;
magmaFloatComplex G315 = G164 * s_track[14];
magmaFloatComplex G316 = G314 + G315;
magmaFloatComplex G317 = G170 * s_track[15];
magmaFloatComplex G318 = G316 + G317;
magmaFloatComplex G319 = G30 * s_track[4];
magmaFloatComplex G320 = G319 + G263;
magmaFloatComplex G321 = G50 * s_track[5];
magmaFloatComplex G322 = G320 + G321;
magmaFloatComplex G323 = G4 * G187;
magmaFloatComplex G324 = G322 + G323;
magmaFloatComplex G325 = G68 * s_track[6];
magmaFloatComplex G326 = G324 + G325;
magmaFloatComplex G327 = G84 * s_track[7];
magmaFloatComplex G328 = G326 + G327;
magmaFloatComplex G329 = G99 * s_track[8];
magmaFloatComplex G330 = G328 + G329;
magmaFloatComplex G331 = G9 * s_track[4];
magmaFloatComplex G332 = G330 + G331;
magmaFloatComplex G333 = G112 * s_track[9];
magmaFloatComplex G334 = G332 + G333;
magmaFloatComplex G335 = G124 * s_track[10];
magmaFloatComplex G336 = G334 + G335;
magmaFloatComplex G337 = G134 * s_track[11];
magmaFloatComplex G338 = G336 + G337;
magmaFloatComplex G339 = G142 * s_track[12];
magmaFloatComplex G340 = G338 + G339;
magmaFloatComplex G341 = G149 * s_track[13];
magmaFloatComplex G342 = G340 + G341;
magmaFloatComplex G343 = G157 * s_track[14];
magmaFloatComplex G344 = G342 + G343;
magmaFloatComplex G345 = G164 * s_track[15];
magmaFloatComplex G346 = G344 + G345;
magmaFloatComplex G347 = G30 * s_track[5];
magmaFloatComplex G348 = G347 + G293;
magmaFloatComplex G349 = G50 * s_track[6];
magmaFloatComplex G350 = G348 + G349;
magmaFloatComplex G351 = G350 + G234;
magmaFloatComplex G352 = G68 * s_track[7];
magmaFloatComplex G353 = G351 + G352;
magmaFloatComplex G354 = G84 * s_track[8];
magmaFloatComplex G355 = G353 + G354;
magmaFloatComplex G356 = G99 * s_track[9];
magmaFloatComplex G357 = G355 + G356;
magmaFloatComplex G358 = G112 * s_track[10];
magmaFloatComplex G359 = G357 + G358;
magmaFloatComplex G360 = G9 * s_track[5];
magmaFloatComplex G361 = G359 + G360;
magmaFloatComplex G362 = G124 * s_track[11];
magmaFloatComplex G363 = G361 + G362;
magmaFloatComplex G364 = G134 * s_track[12];
magmaFloatComplex G365 = G363 + G364;
magmaFloatComplex G366 = G142 * s_track[13];
magmaFloatComplex G367 = G365 + G366;
magmaFloatComplex G368 = G149 * s_track[14];
magmaFloatComplex G369 = G367 + G368;
magmaFloatComplex G370 = G157 * s_track[15];
magmaFloatComplex G371 = G369 + G370;
magmaFloatComplex G372 = G30 * s_track[6];
magmaFloatComplex G373 = G372 + G321;
magmaFloatComplex G374 = G50 * s_track[7];
magmaFloatComplex G375 = G373 + G374;
magmaFloatComplex G376 = G375 + G265;
magmaFloatComplex G377 = G68 * s_track[8];
magmaFloatComplex G378 = G376 + G377;
magmaFloatComplex G379 = G4 * G190;
magmaFloatComplex G380 = G378 + G379;
magmaFloatComplex G381 = G84 * s_track[9];
magmaFloatComplex G382 = G380 + G381;
magmaFloatComplex G383 = G99 * s_track[10];
magmaFloatComplex G384 = G382 + G383;
magmaFloatComplex G385 = G112 * s_track[11];
magmaFloatComplex G386 = G384 + G385;
magmaFloatComplex G387 = G124 * s_track[12];
magmaFloatComplex G388 = G386 + G387;
magmaFloatComplex G389 = G9 * s_track[6];
magmaFloatComplex G390 = G388 + G389;
magmaFloatComplex G391 = G134 * s_track[13];
magmaFloatComplex G392 = G390 + G391;
magmaFloatComplex G393 = G142 * s_track[14];
magmaFloatComplex G394 = G392 + G393;
magmaFloatComplex G395 = G149 * s_track[15];
magmaFloatComplex G396 = G394 + G395;
magmaFloatComplex G397 = G30 * s_track[7];
magmaFloatComplex G398 = G397 + G349;
magmaFloatComplex G399 = G50 * s_track[8];
magmaFloatComplex G400 = G398 + G399;
magmaFloatComplex G401 = G400 + G295;
magmaFloatComplex G402 = G68 * s_track[9];
magmaFloatComplex G403 = G401 + G402;
magmaFloatComplex G404 = G403 + G236;
magmaFloatComplex G405 = G84 * s_track[10];
magmaFloatComplex G406 = G404 + G405;
magmaFloatComplex G407 = G99 * s_track[11];
magmaFloatComplex G408 = G406 + G407;
magmaFloatComplex G409 = G112 * s_track[12];
magmaFloatComplex G410 = G408 + G409;
magmaFloatComplex G411 = G124 * s_track[13];
magmaFloatComplex G412 = G410 + G411;
magmaFloatComplex G413 = G134 * s_track[14];
magmaFloatComplex G414 = G412 + G413;
magmaFloatComplex G415 = G9 * s_track[7];
magmaFloatComplex G416 = G414 + G415;
magmaFloatComplex G417 = G142 * s_track[15];
magmaFloatComplex G418 = G416 + G417;
magmaFloatComplex G419 = G30 * s_track[8];
magmaFloatComplex G420 = G419 + G374;
magmaFloatComplex G421 = G50 * s_track[9];
magmaFloatComplex G422 = G420 + G421;
magmaFloatComplex G423 = G422 + G325;
magmaFloatComplex G424 = G68 * s_track[10];
magmaFloatComplex G425 = G423 + G424;
magmaFloatComplex G426 = G425 + G269;
magmaFloatComplex G427 = G84 * s_track[11];
magmaFloatComplex G428 = G426 + G427;
magmaFloatComplex G429 = G4 * G193;
magmaFloatComplex G430 = G428 + G429;
magmaFloatComplex G431 = G99 * s_track[12];
magmaFloatComplex G432 = G430 + G431;
magmaFloatComplex G433 = G112 * s_track[13];
magmaFloatComplex G434 = G432 + G433;
magmaFloatComplex G435 = G124 * s_track[14];
magmaFloatComplex G436 = G434 + G435;
magmaFloatComplex G437 = G134 * s_track[15];
magmaFloatComplex G438 = G436 + G437;
magmaFloatComplex G439 = G9 * s_track[8];
magmaFloatComplex G440 = G438 + G439;
magmaFloatComplex G441 = G30 * s_track[9];
magmaFloatComplex G442 = G441 + G399;
magmaFloatComplex G443 = G50 * s_track[10];
magmaFloatComplex G444 = G442 + G443;
magmaFloatComplex G445 = G444 + G352;
magmaFloatComplex G446 = G68 * s_track[11];
magmaFloatComplex G447 = G445 + G446;
magmaFloatComplex G448 = G447 + G297;
magmaFloatComplex G449 = G84 * s_track[12];
magmaFloatComplex G450 = G448 + G449;
magmaFloatComplex G451 = G450 + G238;
magmaFloatComplex G452 = G99 * s_track[13];
magmaFloatComplex G453 = G451 + G452;
magmaFloatComplex G454 = G112 * s_track[14];
magmaFloatComplex G455 = G453 + G454;
magmaFloatComplex G456 = G124 * s_track[15];
magmaFloatComplex G457 = G455 + G456;
magmaFloatComplex G458 = G9 * s_track[9];
magmaFloatComplex G459 = G457 + G458;
magmaFloatComplex G460 = G30 * s_track[10];
magmaFloatComplex G461 = G460 + G421;
magmaFloatComplex G462 = G50 * s_track[11];
magmaFloatComplex G463 = G461 + G462;
magmaFloatComplex G464 = G463 + G377;
magmaFloatComplex G465 = G68 * s_track[12];
magmaFloatComplex G466 = G464 + G465;
magmaFloatComplex G467 = G466 + G327;
magmaFloatComplex G468 = G84 * s_track[13];
magmaFloatComplex G469 = G467 + G468;
magmaFloatComplex G470 = G469 + G271;
magmaFloatComplex G471 = G99 * s_track[14];
magmaFloatComplex G472 = G470 + G471;
magmaFloatComplex G473 = G4 * G196;
magmaFloatComplex G474 = G472 + G473;
magmaFloatComplex G475 = G112 * s_track[15];
magmaFloatComplex G476 = G474 + G475;
magmaFloatComplex G477 = G9 * s_track[10];
magmaFloatComplex G478 = G476 + G477;
magmaFloatComplex G479 = G30 * s_track[11];
magmaFloatComplex G480 = G479 + G443;
magmaFloatComplex G481 = G50 * s_track[12];
magmaFloatComplex G482 = G480 + G481;
magmaFloatComplex G483 = G482 + G402;
magmaFloatComplex G484 = G68 * s_track[13];
magmaFloatComplex G485 = G483 + G484;
magmaFloatComplex G486 = G485 + G354;
magmaFloatComplex G487 = G84 * s_track[14];
magmaFloatComplex G488 = G486 + G487;
magmaFloatComplex G489 = G488 + G301;
magmaFloatComplex G490 = G99 * s_track[15];
magmaFloatComplex G491 = G489 + G490;
magmaFloatComplex G492 = G491 + G240;
magmaFloatComplex G493 = G9 * s_track[11];
magmaFloatComplex G494 = G492 + G493;
magmaFloatComplex G495 = G30 * s_track[12];
magmaFloatComplex G496 = G495 + G462;
magmaFloatComplex G497 = G50 * s_track[13];
magmaFloatComplex G498 = G496 + G497;
magmaFloatComplex G499 = G498 + G424;
magmaFloatComplex G500 = G68 * s_track[14];
magmaFloatComplex G501 = G499 + G500;
magmaFloatComplex G502 = G501 + G381;
magmaFloatComplex G503 = G84 * s_track[15];
magmaFloatComplex G504 = G502 + G503;
magmaFloatComplex G505 = G504 + G329;
magmaFloatComplex G506 = G505 + G273;
magmaFloatComplex G507 = G4 * G199;
magmaFloatComplex G508 = G506 + G507;
magmaFloatComplex G509 = G9 * s_track[12];
magmaFloatComplex G510 = G508 + G509;
magmaFloatComplex G511 = G30 * s_track[13];
magmaFloatComplex G512 = G511 + G481;
magmaFloatComplex G513 = G50 * s_track[14];
magmaFloatComplex G514 = G512 + G513;
magmaFloatComplex G515 = G514 + G446;
magmaFloatComplex G516 = G68 * s_track[15];
magmaFloatComplex G517 = G515 + G516;
magmaFloatComplex G518 = G517 + G405;
magmaFloatComplex G519 = G518 + G356;
magmaFloatComplex G520 = G519 + G303;
magmaFloatComplex G521 = G520 + G242;
magmaFloatComplex G522 = G9 * s_track[13];
magmaFloatComplex G523 = G521 + G522;
magmaFloatComplex G524 = G30 * s_track[14];
magmaFloatComplex G525 = G524 + G497;
magmaFloatComplex G526 = G50 * s_track[15];
magmaFloatComplex G527 = G525 + G526;
magmaFloatComplex G528 = G527 + G465;
magmaFloatComplex G529 = G528 + G427;
magmaFloatComplex G530 = G529 + G383;
magmaFloatComplex G531 = G530 + G333;
magmaFloatComplex G532 = G531 + G275;
magmaFloatComplex G533 = G4 * G202;
magmaFloatComplex G534 = G532 + G533;
magmaFloatComplex G535 = G9 * s_track[14];
magmaFloatComplex G536 = G534 + G535;
magmaFloatComplex G537 = G4 * s_track[0];
magmaFloatComplex G538 = G537 + G50;
magmaFloatComplex G539 = G538 + G68;
magmaFloatComplex G540 = G539 + G84;
magmaFloatComplex G541 = G540 + G99;
magmaFloatComplex G542 = G541 + G112;
magmaFloatComplex G543 = G542 + G124;
magmaFloatComplex G544 = G543 + G134;
magmaFloatComplex G545 = G544 + G142;
magmaFloatComplex G546 = G545 + G149;
magmaFloatComplex G547 = G546 + G157;
magmaFloatComplex G548 = G547 + G164;
magmaFloatComplex G549 = G548 + G170;
magmaFloatComplex G550 = G549 + G175;
magmaFloatComplex G551 = G550 + G179;
magmaFloatComplex G552 = G13 * s_track[15];
magmaFloatComplex G553 = G551 + G552;
magmaFloatComplex G554 = G553 + G9;

r_cgesvA[0] = G10;
r_cgesvA[1] = G14;
r_cgesvA[2] = G15;
r_cgesvA[3] = G16;
r_cgesvA[4] = G17;
r_cgesvA[5] = G18;
r_cgesvA[6] = G19;
r_cgesvA[7] = G20;
r_cgesvA[8] = G21;
r_cgesvA[9] = G22;
r_cgesvA[10] = G23;
r_cgesvA[11] = G24;
r_cgesvA[12] = G25;
r_cgesvA[13] = G26;
r_cgesvA[14] = G27;
r_cgesvA[15] = G4;
r_cgesvB[0] =G228;

r_cgesvA[16] = G29;
r_cgesvA[17] = G32;
r_cgesvA[18] = G34;
r_cgesvA[19] = G35;
r_cgesvA[20] = G36;
r_cgesvA[21] = G37;
r_cgesvA[22] = G38;
r_cgesvA[23] = G39;
r_cgesvA[24] = G40;
r_cgesvA[25] = G41;
r_cgesvA[26] = G42;
r_cgesvA[27] = G43;
r_cgesvA[28] = G44;
r_cgesvA[29] = G45;
r_cgesvA[30] = G47;
r_cgesvA[31] = G13;
r_cgesvB[1] =G259;

r_cgesvA[32] = G49;
r_cgesvA[33] = G51;
r_cgesvA[34] = G53;
r_cgesvA[35] = G54;
r_cgesvA[36] = G56;
r_cgesvA[37] = G57;
r_cgesvA[38] = G58;
r_cgesvA[39] = G59;
r_cgesvA[40] = G60;
r_cgesvA[41] = G61;
r_cgesvA[42] = G62;
r_cgesvA[43] = G63;
r_cgesvA[44] = G64;
r_cgesvA[45] = G65;
r_cgesvA[46] = G25;
r_cgesvA[47] = G13;
r_cgesvB[2] =G290;

r_cgesvA[48] = G67;
r_cgesvA[49] = G69;
r_cgesvA[50] = G54;
r_cgesvA[51] = G71;
r_cgesvA[52] = G72;
r_cgesvA[53] = G73;
r_cgesvA[54] = G75;
r_cgesvA[55] = G76;
r_cgesvA[56] = G77;
r_cgesvA[57] = G78;
r_cgesvA[58] = G79;
r_cgesvA[59] = G80;
r_cgesvA[60] = G81;
r_cgesvA[61] = G23;
r_cgesvA[62] = G24;
r_cgesvA[63] = G13;
r_cgesvB[3] =G318;

r_cgesvA[64] = G83;
r_cgesvA[65] = G85;
r_cgesvA[66] = G86;
r_cgesvA[67] = G72;
r_cgesvA[68] = G88;
r_cgesvA[69] = G89;
r_cgesvA[70] = G90;
r_cgesvA[71] = G91;
r_cgesvA[72] = G93;
r_cgesvA[73] = G94;
r_cgesvA[74] = G95;
r_cgesvA[75] = G96;
r_cgesvA[76] = G21;
r_cgesvA[77] = G22;
r_cgesvA[78] = G23;
r_cgesvA[79] = G13;
r_cgesvB[4] =G346;

r_cgesvA[80] = G98;
r_cgesvA[81] = G100;
r_cgesvA[82] = G101;
r_cgesvA[83] = G73;
r_cgesvA[84] = G89;
r_cgesvA[85] = G103;
r_cgesvA[86] = G104;
r_cgesvA[87] = G105;
r_cgesvA[88] = G106;
r_cgesvA[89] = G107;
r_cgesvA[90] = G109;
r_cgesvA[91] = G19;
r_cgesvA[92] = G20;
r_cgesvA[93] = G21;
r_cgesvA[94] = G22;
r_cgesvA[95] = G13;
r_cgesvB[5] =G371;

r_cgesvA[96] = G111;
r_cgesvA[97] = G113;
r_cgesvA[98] = G114;
r_cgesvA[99] = G115;
r_cgesvA[100] = G90;
r_cgesvA[101] = G104;
r_cgesvA[102] = G117;
r_cgesvA[103] = G118;
r_cgesvA[104] = G119;
r_cgesvA[105] = G120;
r_cgesvA[106] = G99;
r_cgesvA[107] = G112;
r_cgesvA[108] = G121;
r_cgesvA[109] = G20;
r_cgesvA[110] = G21;
r_cgesvA[111] = G13;
r_cgesvB[6] =G396;

r_cgesvA[112] = G123;
r_cgesvA[113] = G125;
r_cgesvA[114] = G126;
r_cgesvA[115] = G127;
r_cgesvA[116] = G91;
r_cgesvA[117] = G105;
r_cgesvA[118] = G118;
r_cgesvA[119] = G129;
r_cgesvA[120] = G130;
r_cgesvA[121] = G68;
r_cgesvA[122] = G84;
r_cgesvA[123] = G99;
r_cgesvA[124] = G112;
r_cgesvA[125] = G124;
r_cgesvA[126] = G131;
r_cgesvA[127] = G13;
r_cgesvB[7] =G418;

r_cgesvA[128] = G133;
r_cgesvA[129] = G135;
r_cgesvA[130] = G136;
r_cgesvA[131] = G137;
r_cgesvA[132] = G138;
r_cgesvA[133] = G106;
r_cgesvA[134] = G119;
r_cgesvA[135] = G130;
r_cgesvA[136] = G139;
r_cgesvA[137] = G50;
r_cgesvA[138] = G68;
r_cgesvA[139] = G84;
r_cgesvA[140] = G99;
r_cgesvA[141] = G112;
r_cgesvA[142] = G124;
r_cgesvA[143] = G13;
r_cgesvB[8] =G440;

r_cgesvA[144] = G141;
r_cgesvA[145] = G143;
r_cgesvA[146] = G144;
r_cgesvA[147] = G145;
r_cgesvA[148] = G146;
r_cgesvA[149] = G107;
r_cgesvA[150] = G120;
r_cgesvA[151] = G68;
r_cgesvA[152] = G50;
r_cgesvA[153] = G139;
r_cgesvA[154] = G50;
r_cgesvA[155] = G68;
r_cgesvA[156] = G84;
r_cgesvA[157] = G99;
r_cgesvA[158] = G112;
r_cgesvA[159] = G13;
r_cgesvB[9] =G459;

r_cgesvA[160] = G148;
r_cgesvA[161] = G150;
r_cgesvA[162] = G151;
r_cgesvA[163] = G152;
r_cgesvA[164] = G153;
r_cgesvA[165] = G154;
r_cgesvA[166] = G99;
r_cgesvA[167] = G84;
r_cgesvA[168] = G68;
r_cgesvA[169] = G50;
r_cgesvA[170] = G139;
r_cgesvA[171] = G50;
r_cgesvA[172] = G68;
r_cgesvA[173] = G84;
r_cgesvA[174] = G99;
r_cgesvA[175] = G13;
r_cgesvB[10] =G478;

r_cgesvA[176] = G156;
r_cgesvA[177] = G158;
r_cgesvA[178] = G159;
r_cgesvA[179] = G160;
r_cgesvA[180] = G161;
r_cgesvA[181] = G124;
r_cgesvA[182] = G112;
r_cgesvA[183] = G99;
r_cgesvA[184] = G84;
r_cgesvA[185] = G68;
r_cgesvA[186] = G50;
r_cgesvA[187] = G139;
r_cgesvA[188] = G50;
r_cgesvA[189] = G68;
r_cgesvA[190] = G84;
r_cgesvA[191] = G13;
r_cgesvB[11] =G494;

r_cgesvA[192] = G163;
r_cgesvA[193] = G165;
r_cgesvA[194] = G166;
r_cgesvA[195] = G167;
r_cgesvA[196] = G142;
r_cgesvA[197] = G134;
r_cgesvA[198] = G124;
r_cgesvA[199] = G112;
r_cgesvA[200] = G99;
r_cgesvA[201] = G84;
r_cgesvA[202] = G68;
r_cgesvA[203] = G50;
r_cgesvA[204] = G139;
r_cgesvA[205] = G50;
r_cgesvA[206] = G68;
r_cgesvA[207] = G13;
r_cgesvB[12] =G510;

r_cgesvA[208] = G169;
r_cgesvA[209] = G171;
r_cgesvA[210] = G172;
r_cgesvA[211] = G157;
r_cgesvA[212] = G149;
r_cgesvA[213] = G142;
r_cgesvA[214] = G134;
r_cgesvA[215] = G124;
r_cgesvA[216] = G112;
r_cgesvA[217] = G99;
r_cgesvA[218] = G84;
r_cgesvA[219] = G68;
r_cgesvA[220] = G50;
r_cgesvA[221] = G139;
r_cgesvA[222] = G50;
r_cgesvA[223] = G13;
r_cgesvB[13] =G523;

r_cgesvA[224] = G174;
r_cgesvA[225] = G176;
r_cgesvA[226] = G170;
r_cgesvA[227] = G164;
r_cgesvA[228] = G157;
r_cgesvA[229] = G149;
r_cgesvA[230] = G142;
r_cgesvA[231] = G134;
r_cgesvA[232] = G124;
r_cgesvA[233] = G112;
r_cgesvA[234] = G99;
r_cgesvA[235] = G84;
r_cgesvA[236] = G68;
r_cgesvA[237] = G50;
r_cgesvA[238] = G139;
r_cgesvA[239] = G13;
r_cgesvB[14] =G536;

r_cgesvA[240] = G178;
r_cgesvA[241] = G179;
r_cgesvA[242] = G175;
r_cgesvA[243] = G170;
r_cgesvA[244] = G164;
r_cgesvA[245] = G157;
r_cgesvA[246] = G149;
r_cgesvA[247] = G142;
r_cgesvA[248] = G134;
r_cgesvA[249] = G124;
r_cgesvA[250] = G112;
r_cgesvA[251] = G99;
r_cgesvA[252] = G84;
r_cgesvA[253] = G68;
r_cgesvA[254] = G50;
r_cgesvA[255] = G13;
r_cgesvB[15] =G554;

  }
}

#endif
