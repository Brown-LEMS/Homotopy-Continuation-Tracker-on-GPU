#ifndef cpu_eval_HxHt_katsura12_h
#define cpu_eval_HxHt_katsura12_h
// ============================================================================
// partial derivative evaluations of the katsura12 problem for cpu HC computation
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
  void cpu_eval_HxHt_katsura12(
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
magmaFloatComplex G25 = s_track[1] + s_track[1];
magmaFloatComplex G26 = G13 * G25;
magmaFloatComplex G27 = G13 * s_track[0];
magmaFloatComplex G28 = G27 + G15;
magmaFloatComplex G29 = G28 + G9;
magmaFloatComplex G30 = G4 * G25;
magmaFloatComplex G31 = G30 + G16;
magmaFloatComplex G32 = G15 + G17;
magmaFloatComplex G33 = G16 + G18;
magmaFloatComplex G34 = G17 + G19;
magmaFloatComplex G35 = G18 + G20;
magmaFloatComplex G36 = G19 + G21;
magmaFloatComplex G37 = G20 + G22;
magmaFloatComplex G38 = G21 + G23;
magmaFloatComplex G39 = G22 + G24;
magmaFloatComplex G40 = s_track[12] * G13;
magmaFloatComplex G41 = G23 + G40;
magmaFloatComplex G42 = s_track[2] + s_track[2];
magmaFloatComplex G43 = G13 * G42;
magmaFloatComplex G44 = G13 * s_track[1];
magmaFloatComplex G45 = G44 + G16;
magmaFloatComplex G46 = G27 + G17;
magmaFloatComplex G47 = G46 + G9;
magmaFloatComplex G48 = G44 + G18;
magmaFloatComplex G49 = G4 * G42;
magmaFloatComplex G50 = G49 + G19;
magmaFloatComplex G51 = G16 + G20;
magmaFloatComplex G52 = G17 + G21;
magmaFloatComplex G53 = G18 + G22;
magmaFloatComplex G54 = G19 + G23;
magmaFloatComplex G55 = G20 + G24;
magmaFloatComplex G56 = G21 + G40;
magmaFloatComplex G57 = s_track[3] + s_track[3];
magmaFloatComplex G58 = G13 * G57;
magmaFloatComplex G59 = G13 * s_track[2];
magmaFloatComplex G60 = G59 + G17;
magmaFloatComplex G61 = G27 + G19;
magmaFloatComplex G62 = G61 + G9;
magmaFloatComplex G63 = G44 + G20;
magmaFloatComplex G64 = G59 + G21;
magmaFloatComplex G65 = G4 * G57;
magmaFloatComplex G66 = G65 + G22;
magmaFloatComplex G67 = G17 + G23;
magmaFloatComplex G68 = G18 + G24;
magmaFloatComplex G69 = G19 + G40;
magmaFloatComplex G70 = s_track[4] + s_track[4];
magmaFloatComplex G71 = G13 * G70;
magmaFloatComplex G72 = G13 * s_track[3];
magmaFloatComplex G73 = G72 + G18;
magmaFloatComplex G74 = G59 + G19;
magmaFloatComplex G75 = G27 + G21;
magmaFloatComplex G76 = G75 + G9;
magmaFloatComplex G77 = G44 + G22;
magmaFloatComplex G78 = G59 + G23;
magmaFloatComplex G79 = G72 + G24;
magmaFloatComplex G80 = G4 * G70;
magmaFloatComplex G81 = G80 + G40;
magmaFloatComplex G82 = s_track[5] + s_track[5];
magmaFloatComplex G83 = G13 * G82;
magmaFloatComplex G84 = G13 * s_track[4];
magmaFloatComplex G85 = G84 + G19;
magmaFloatComplex G86 = G72 + G20;
magmaFloatComplex G87 = G27 + G23;
magmaFloatComplex G88 = G87 + G9;
magmaFloatComplex G89 = G44 + G24;
magmaFloatComplex G90 = G59 + G40;
magmaFloatComplex G91 = G4 * G82;
magmaFloatComplex G92 = s_track[6] + s_track[6];
magmaFloatComplex G93 = G13 * G92;
magmaFloatComplex G94 = G13 * s_track[5];
magmaFloatComplex G95 = G94 + G20;
magmaFloatComplex G96 = G84 + G21;
magmaFloatComplex G97 = G72 + G22;
magmaFloatComplex G98 = G27 + G40;
magmaFloatComplex G99 = G98 + G9;
magmaFloatComplex G100 = s_track[7] + s_track[7];
magmaFloatComplex G101 = G13 * G100;
magmaFloatComplex G102 = G13 * s_track[6];
magmaFloatComplex G103 = G102 + G21;
magmaFloatComplex G104 = G94 + G22;
magmaFloatComplex G105 = G84 + G23;
magmaFloatComplex G106 = G27 + G9;
magmaFloatComplex G107 = s_track[8] + s_track[8];
magmaFloatComplex G108 = G13 * G107;
magmaFloatComplex G109 = G13 * s_track[7];
magmaFloatComplex G110 = G109 + G22;
magmaFloatComplex G111 = G102 + G23;
magmaFloatComplex G112 = G94 + G24;
magmaFloatComplex G113 = G84 + G40;
magmaFloatComplex G114 = s_track[9] + s_track[9];
magmaFloatComplex G115 = G13 * G114;
magmaFloatComplex G116 = G13 * s_track[8];
magmaFloatComplex G117 = G116 + G23;
magmaFloatComplex G118 = G109 + G24;
magmaFloatComplex G119 = G102 + G40;
magmaFloatComplex G120 = s_track[10] + s_track[10];
magmaFloatComplex G121 = G13 * G120;
magmaFloatComplex G122 = G13 * s_track[9];
magmaFloatComplex G123 = G122 + G24;
magmaFloatComplex G124 = G116 + G40;
magmaFloatComplex G125 = s_track[11] + s_track[11];
magmaFloatComplex G126 = G13 * G125;
magmaFloatComplex G127 = G13 * s_track[10];
magmaFloatComplex G128 = G127 + G40;
magmaFloatComplex G129 = s_track[12] + s_track[12];
magmaFloatComplex G130 = G13 * G129;
magmaFloatComplex G131 = G13 * s_track[11];
magmaFloatComplex G132 = s_track[0] * s_track[0];
magmaFloatComplex G133 = C1 * s_startCoefs[0];
magmaFloatComplex G134 = G133 + s_targetCoefs[0];
magmaFloatComplex G135 = G132 * G134;
magmaFloatComplex G136 = C1 * s_startCoefs[1];
magmaFloatComplex G137 = G136 + s_targetCoefs[1];
magmaFloatComplex G138 = s_track[0] * G137;
magmaFloatComplex G139 = G135 + G138;
magmaFloatComplex G140 = s_track[1] * s_track[1];
magmaFloatComplex G141 = C1 * s_startCoefs[2];
magmaFloatComplex G142 = G141 + s_targetCoefs[2];
magmaFloatComplex G143 = G140 * G142;
magmaFloatComplex G144 = G139 + G143;
magmaFloatComplex G145 = s_track[2] * s_track[2];
magmaFloatComplex G146 = G145 * G142;
magmaFloatComplex G147 = G144 + G146;
magmaFloatComplex G148 = s_track[3] * s_track[3];
magmaFloatComplex G149 = G148 * G142;
magmaFloatComplex G150 = G147 + G149;
magmaFloatComplex G151 = s_track[4] * s_track[4];
magmaFloatComplex G152 = G151 * G142;
magmaFloatComplex G153 = G150 + G152;
magmaFloatComplex G154 = s_track[5] * s_track[5];
magmaFloatComplex G155 = G154 * G142;
magmaFloatComplex G156 = G153 + G155;
magmaFloatComplex G157 = s_track[6] * s_track[6];
magmaFloatComplex G158 = G157 * G142;
magmaFloatComplex G159 = G156 + G158;
magmaFloatComplex G160 = s_track[7] * s_track[7];
magmaFloatComplex G161 = G160 * G142;
magmaFloatComplex G162 = G159 + G161;
magmaFloatComplex G163 = s_track[8] * s_track[8];
magmaFloatComplex G164 = G163 * G142;
magmaFloatComplex G165 = G162 + G164;
magmaFloatComplex G166 = s_track[9] * s_track[9];
magmaFloatComplex G167 = G166 * G142;
magmaFloatComplex G168 = G165 + G167;
magmaFloatComplex G169 = s_track[10] * s_track[10];
magmaFloatComplex G170 = G169 * G142;
magmaFloatComplex G171 = G168 + G170;
magmaFloatComplex G172 = s_track[11] * s_track[11];
magmaFloatComplex G173 = G172 * G142;
magmaFloatComplex G174 = G171 + G173;
magmaFloatComplex G175 = s_track[12] * s_track[12];
magmaFloatComplex G176 = G175 * G142;
magmaFloatComplex G177 = G174 + G176;
magmaFloatComplex G178 = s_track[0] * G142;
magmaFloatComplex G179 = s_track[1] * G178;
magmaFloatComplex G180 = s_track[1] * G142;
magmaFloatComplex G181 = s_track[2] * G180;
magmaFloatComplex G182 = G179 + G181;
magmaFloatComplex G183 = s_track[1] * G137;
magmaFloatComplex G184 = G182 + G183;
magmaFloatComplex G185 = s_track[2] * G142;
magmaFloatComplex G186 = s_track[3] * G185;
magmaFloatComplex G187 = G184 + G186;
magmaFloatComplex G188 = s_track[3] * G142;
magmaFloatComplex G189 = s_track[4] * G188;
magmaFloatComplex G190 = G187 + G189;
magmaFloatComplex G191 = s_track[4] * G142;
magmaFloatComplex G192 = s_track[5] * G191;
magmaFloatComplex G193 = G190 + G192;
magmaFloatComplex G194 = s_track[5] * G142;
magmaFloatComplex G195 = s_track[6] * G194;
magmaFloatComplex G196 = G193 + G195;
magmaFloatComplex G197 = s_track[6] * G142;
magmaFloatComplex G198 = s_track[7] * G197;
magmaFloatComplex G199 = G196 + G198;
magmaFloatComplex G200 = s_track[7] * G142;
magmaFloatComplex G201 = s_track[8] * G200;
magmaFloatComplex G202 = G199 + G201;
magmaFloatComplex G203 = s_track[8] * G142;
magmaFloatComplex G204 = s_track[9] * G203;
magmaFloatComplex G205 = G202 + G204;
magmaFloatComplex G206 = s_track[9] * G142;
magmaFloatComplex G207 = s_track[10] * G206;
magmaFloatComplex G208 = G205 + G207;
magmaFloatComplex G209 = s_track[10] * G142;
magmaFloatComplex G210 = s_track[11] * G209;
magmaFloatComplex G211 = G208 + G210;
magmaFloatComplex G212 = s_track[11] * G142;
magmaFloatComplex G213 = s_track[12] * G212;
magmaFloatComplex G214 = G211 + G213;
magmaFloatComplex G215 = s_track[2] * G178;
magmaFloatComplex G216 = G140 * G134;
magmaFloatComplex G217 = G215 + G216;
magmaFloatComplex G218 = s_track[3] * G180;
magmaFloatComplex G219 = G217 + G218;
magmaFloatComplex G220 = s_track[4] * G185;
magmaFloatComplex G221 = G219 + G220;
magmaFloatComplex G222 = s_track[2] * G137;
magmaFloatComplex G223 = G221 + G222;
magmaFloatComplex G224 = s_track[5] * G188;
magmaFloatComplex G225 = G223 + G224;
magmaFloatComplex G226 = s_track[6] * G191;
magmaFloatComplex G227 = G225 + G226;
magmaFloatComplex G228 = s_track[7] * G194;
magmaFloatComplex G229 = G227 + G228;
magmaFloatComplex G230 = s_track[8] * G197;
magmaFloatComplex G231 = G229 + G230;
magmaFloatComplex G232 = s_track[9] * G200;
magmaFloatComplex G233 = G231 + G232;
magmaFloatComplex G234 = s_track[10] * G203;
magmaFloatComplex G235 = G233 + G234;
magmaFloatComplex G236 = s_track[11] * G206;
magmaFloatComplex G237 = G235 + G236;
magmaFloatComplex G238 = s_track[12] * G209;
magmaFloatComplex G239 = G237 + G238;
magmaFloatComplex G240 = s_track[3] * G178;
magmaFloatComplex G241 = G240 + G181;
magmaFloatComplex G242 = s_track[4] * G180;
magmaFloatComplex G243 = G241 + G242;
magmaFloatComplex G244 = s_track[5] * G185;
magmaFloatComplex G245 = G243 + G244;
magmaFloatComplex G246 = s_track[6] * G188;
magmaFloatComplex G247 = G245 + G246;
magmaFloatComplex G248 = s_track[3] * G137;
magmaFloatComplex G249 = G247 + G248;
magmaFloatComplex G250 = s_track[7] * G191;
magmaFloatComplex G251 = G249 + G250;
magmaFloatComplex G252 = s_track[8] * G194;
magmaFloatComplex G253 = G251 + G252;
magmaFloatComplex G254 = s_track[9] * G197;
magmaFloatComplex G255 = G253 + G254;
magmaFloatComplex G256 = s_track[10] * G200;
magmaFloatComplex G257 = G255 + G256;
magmaFloatComplex G258 = s_track[11] * G203;
magmaFloatComplex G259 = G257 + G258;
magmaFloatComplex G260 = s_track[12] * G206;
magmaFloatComplex G261 = G259 + G260;
magmaFloatComplex G262 = s_track[4] * G178;
magmaFloatComplex G263 = G262 + G218;
magmaFloatComplex G264 = s_track[5] * G180;
magmaFloatComplex G265 = G263 + G264;
magmaFloatComplex G266 = G145 * G134;
magmaFloatComplex G267 = G265 + G266;
magmaFloatComplex G268 = s_track[6] * G185;
magmaFloatComplex G269 = G267 + G268;
magmaFloatComplex G270 = s_track[7] * G188;
magmaFloatComplex G271 = G269 + G270;
magmaFloatComplex G272 = s_track[8] * G191;
magmaFloatComplex G273 = G271 + G272;
magmaFloatComplex G274 = s_track[4] * G137;
magmaFloatComplex G275 = G273 + G274;
magmaFloatComplex G276 = s_track[9] * G194;
magmaFloatComplex G277 = G275 + G276;
magmaFloatComplex G278 = s_track[10] * G197;
magmaFloatComplex G279 = G277 + G278;
magmaFloatComplex G280 = s_track[11] * G200;
magmaFloatComplex G281 = G279 + G280;
magmaFloatComplex G282 = s_track[12] * G203;
magmaFloatComplex G283 = G281 + G282;
magmaFloatComplex G284 = s_track[5] * G178;
magmaFloatComplex G285 = G284 + G242;
magmaFloatComplex G286 = s_track[6] * G180;
magmaFloatComplex G287 = G285 + G286;
magmaFloatComplex G288 = G287 + G186;
magmaFloatComplex G289 = s_track[7] * G185;
magmaFloatComplex G290 = G288 + G289;
magmaFloatComplex G291 = s_track[8] * G188;
magmaFloatComplex G292 = G290 + G291;
magmaFloatComplex G293 = s_track[9] * G191;
magmaFloatComplex G294 = G292 + G293;
magmaFloatComplex G295 = s_track[10] * G194;
magmaFloatComplex G296 = G294 + G295;
magmaFloatComplex G297 = s_track[5] * G137;
magmaFloatComplex G298 = G296 + G297;
magmaFloatComplex G299 = s_track[11] * G197;
magmaFloatComplex G300 = G298 + G299;
magmaFloatComplex G301 = s_track[12] * G200;
magmaFloatComplex G302 = G300 + G301;
magmaFloatComplex G303 = s_track[6] * G178;
magmaFloatComplex G304 = G303 + G264;
magmaFloatComplex G305 = s_track[7] * G180;
magmaFloatComplex G306 = G304 + G305;
magmaFloatComplex G307 = G306 + G220;
magmaFloatComplex G308 = s_track[8] * G185;
magmaFloatComplex G309 = G307 + G308;
magmaFloatComplex G310 = G148 * G134;
magmaFloatComplex G311 = G309 + G310;
magmaFloatComplex G312 = s_track[9] * G188;
magmaFloatComplex G313 = G311 + G312;
magmaFloatComplex G314 = s_track[10] * G191;
magmaFloatComplex G315 = G313 + G314;
magmaFloatComplex G316 = s_track[11] * G194;
magmaFloatComplex G317 = G315 + G316;
magmaFloatComplex G318 = s_track[12] * G197;
magmaFloatComplex G319 = G317 + G318;
magmaFloatComplex G320 = s_track[6] * G137;
magmaFloatComplex G321 = G319 + G320;
magmaFloatComplex G322 = s_track[7] * G178;
magmaFloatComplex G323 = G322 + G286;
magmaFloatComplex G324 = s_track[8] * G180;
magmaFloatComplex G325 = G323 + G324;
magmaFloatComplex G326 = G325 + G244;
magmaFloatComplex G327 = s_track[9] * G185;
magmaFloatComplex G328 = G326 + G327;
magmaFloatComplex G329 = G328 + G189;
magmaFloatComplex G330 = s_track[10] * G188;
magmaFloatComplex G331 = G329 + G330;
magmaFloatComplex G332 = s_track[11] * G191;
magmaFloatComplex G333 = G331 + G332;
magmaFloatComplex G334 = s_track[12] * G194;
magmaFloatComplex G335 = G333 + G334;
magmaFloatComplex G336 = s_track[7] * G137;
magmaFloatComplex G337 = G335 + G336;
magmaFloatComplex G338 = s_track[8] * G178;
magmaFloatComplex G339 = G338 + G305;
magmaFloatComplex G340 = s_track[9] * G180;
magmaFloatComplex G341 = G339 + G340;
magmaFloatComplex G342 = G341 + G268;
magmaFloatComplex G343 = s_track[10] * G185;
magmaFloatComplex G344 = G342 + G343;
magmaFloatComplex G345 = G344 + G224;
magmaFloatComplex G346 = s_track[11] * G188;
magmaFloatComplex G347 = G345 + G346;
magmaFloatComplex G348 = G151 * G134;
magmaFloatComplex G349 = G347 + G348;
magmaFloatComplex G350 = s_track[12] * G191;
magmaFloatComplex G351 = G349 + G350;
magmaFloatComplex G352 = s_track[8] * G137;
magmaFloatComplex G353 = G351 + G352;
magmaFloatComplex G354 = s_track[9] * G178;
magmaFloatComplex G355 = G354 + G324;
magmaFloatComplex G356 = s_track[10] * G180;
magmaFloatComplex G357 = G355 + G356;
magmaFloatComplex G358 = G357 + G289;
magmaFloatComplex G359 = s_track[11] * G185;
magmaFloatComplex G360 = G358 + G359;
magmaFloatComplex G361 = G360 + G246;
magmaFloatComplex G362 = s_track[12] * G188;
magmaFloatComplex G363 = G361 + G362;
magmaFloatComplex G364 = G363 + G192;
magmaFloatComplex G365 = s_track[9] * G137;
magmaFloatComplex G366 = G364 + G365;
magmaFloatComplex G367 = s_track[10] * G178;
magmaFloatComplex G368 = G367 + G340;
magmaFloatComplex G369 = s_track[11] * G180;
magmaFloatComplex G370 = G368 + G369;
magmaFloatComplex G371 = G370 + G308;
magmaFloatComplex G372 = s_track[12] * G185;
magmaFloatComplex G373 = G371 + G372;
magmaFloatComplex G374 = G373 + G270;
magmaFloatComplex G375 = G374 + G226;
magmaFloatComplex G376 = G154 * G134;
magmaFloatComplex G377 = G375 + G376;
magmaFloatComplex G378 = s_track[10] * G137;
magmaFloatComplex G379 = G377 + G378;
magmaFloatComplex G380 = s_track[11] * G178;
magmaFloatComplex G381 = G380 + G356;
magmaFloatComplex G382 = s_track[12] * G180;
magmaFloatComplex G383 = G381 + G382;
magmaFloatComplex G384 = G383 + G327;
magmaFloatComplex G385 = G384 + G291;
magmaFloatComplex G386 = G385 + G250;
magmaFloatComplex G387 = G386 + G195;
magmaFloatComplex G388 = s_track[11] * G137;
magmaFloatComplex G389 = G387 + G388;
magmaFloatComplex G390 = s_track[0] * G134;
magmaFloatComplex G391 = G390 + G180;
magmaFloatComplex G392 = G391 + G185;
magmaFloatComplex G393 = G392 + G188;
magmaFloatComplex G394 = G393 + G191;
magmaFloatComplex G395 = G394 + G194;
magmaFloatComplex G396 = G395 + G197;
magmaFloatComplex G397 = G396 + G200;
magmaFloatComplex G398 = G397 + G203;
magmaFloatComplex G399 = G398 + G206;
magmaFloatComplex G400 = G399 + G209;
magmaFloatComplex G401 = G400 + G212;
magmaFloatComplex G402 = s_track[12] * G142;
magmaFloatComplex G403 = G401 + G402;
magmaFloatComplex G404 = G403 + G137;

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
r_cgesvA[12] = G4;
r_cgesvB[0] = -G177;

r_cgesvA[13] = G26;
r_cgesvA[14] = G29;
r_cgesvA[15] = G31;
r_cgesvA[16] = G32;
r_cgesvA[17] = G33;
r_cgesvA[18] = G34;
r_cgesvA[19] = G35;
r_cgesvA[20] = G36;
r_cgesvA[21] = G37;
r_cgesvA[22] = G38;
r_cgesvA[23] = G39;
r_cgesvA[24] = G41;
r_cgesvA[25] = G13;
r_cgesvB[1] = -G214;

r_cgesvA[26] = G43;
r_cgesvA[27] = G45;
r_cgesvA[28] = G47;
r_cgesvA[29] = G48;
r_cgesvA[30] = G50;
r_cgesvA[31] = G51;
r_cgesvA[32] = G52;
r_cgesvA[33] = G53;
r_cgesvA[34] = G54;
r_cgesvA[35] = G55;
r_cgesvA[36] = G56;
r_cgesvA[37] = G22;
r_cgesvA[38] = G13;
r_cgesvB[2] = -G239;

r_cgesvA[39] = G58;
r_cgesvA[40] = G60;
r_cgesvA[41] = G48;
r_cgesvA[42] = G62;
r_cgesvA[43] = G63;
r_cgesvA[44] = G64;
r_cgesvA[45] = G66;
r_cgesvA[46] = G67;
r_cgesvA[47] = G68;
r_cgesvA[48] = G69;
r_cgesvA[49] = G20;
r_cgesvA[50] = G21;
r_cgesvA[51] = G13;
r_cgesvB[3] = -G261;

r_cgesvA[52] = G71;
r_cgesvA[53] = G73;
r_cgesvA[54] = G74;
r_cgesvA[55] = G63;
r_cgesvA[56] = G76;
r_cgesvA[57] = G77;
r_cgesvA[58] = G78;
r_cgesvA[59] = G79;
r_cgesvA[60] = G81;
r_cgesvA[61] = G18;
r_cgesvA[62] = G19;
r_cgesvA[63] = G20;
r_cgesvA[64] = G13;
r_cgesvB[4] = -G283;

r_cgesvA[65] = G83;
r_cgesvA[66] = G85;
r_cgesvA[67] = G86;
r_cgesvA[68] = G64;
r_cgesvA[69] = G77;
r_cgesvA[70] = G88;
r_cgesvA[71] = G89;
r_cgesvA[72] = G90;
r_cgesvA[73] = G72;
r_cgesvA[74] = G84;
r_cgesvA[75] = G91;
r_cgesvA[76] = G19;
r_cgesvA[77] = G13;
r_cgesvB[5] = -G302;

r_cgesvA[78] = G93;
r_cgesvA[79] = G95;
r_cgesvA[80] = G96;
r_cgesvA[81] = G97;
r_cgesvA[82] = G78;
r_cgesvA[83] = G89;
r_cgesvA[84] = G99;
r_cgesvA[85] = G44;
r_cgesvA[86] = G59;
r_cgesvA[87] = G72;
r_cgesvA[88] = G84;
r_cgesvA[89] = G94;
r_cgesvA[90] = G13;
r_cgesvB[6] = -G321;

r_cgesvA[91] = G101;
r_cgesvA[92] = G103;
r_cgesvA[93] = G104;
r_cgesvA[94] = G105;
r_cgesvA[95] = G79;
r_cgesvA[96] = G90;
r_cgesvA[97] = G44;
r_cgesvA[98] = G106;
r_cgesvA[99] = G44;
r_cgesvA[100] = G59;
r_cgesvA[101] = G72;
r_cgesvA[102] = G84;
r_cgesvA[103] = G13;
r_cgesvB[7] = -G337;

r_cgesvA[104] = G108;
r_cgesvA[105] = G110;
r_cgesvA[106] = G111;
r_cgesvA[107] = G112;
r_cgesvA[108] = G113;
r_cgesvA[109] = G72;
r_cgesvA[110] = G59;
r_cgesvA[111] = G44;
r_cgesvA[112] = G106;
r_cgesvA[113] = G44;
r_cgesvA[114] = G59;
r_cgesvA[115] = G72;
r_cgesvA[116] = G13;
r_cgesvB[8] = -G353;

r_cgesvA[117] = G115;
r_cgesvA[118] = G117;
r_cgesvA[119] = G118;
r_cgesvA[120] = G119;
r_cgesvA[121] = G94;
r_cgesvA[122] = G84;
r_cgesvA[123] = G72;
r_cgesvA[124] = G59;
r_cgesvA[125] = G44;
r_cgesvA[126] = G106;
r_cgesvA[127] = G44;
r_cgesvA[128] = G59;
r_cgesvA[129] = G13;
r_cgesvB[9] = -G366;

r_cgesvA[130] = G121;
r_cgesvA[131] = G123;
r_cgesvA[132] = G124;
r_cgesvA[133] = G109;
r_cgesvA[134] = G102;
r_cgesvA[135] = G94;
r_cgesvA[136] = G84;
r_cgesvA[137] = G72;
r_cgesvA[138] = G59;
r_cgesvA[139] = G44;
r_cgesvA[140] = G106;
r_cgesvA[141] = G44;
r_cgesvA[142] = G13;
r_cgesvB[10] = -G379;

r_cgesvA[143] = G126;
r_cgesvA[144] = G128;
r_cgesvA[145] = G122;
r_cgesvA[146] = G116;
r_cgesvA[147] = G109;
r_cgesvA[148] = G102;
r_cgesvA[149] = G94;
r_cgesvA[150] = G84;
r_cgesvA[151] = G72;
r_cgesvA[152] = G59;
r_cgesvA[153] = G44;
r_cgesvA[154] = G106;
r_cgesvA[155] = G13;
r_cgesvB[11] = -G389;

r_cgesvA[156] = G130;
r_cgesvA[157] = G131;
r_cgesvA[158] = G127;
r_cgesvA[159] = G122;
r_cgesvA[160] = G116;
r_cgesvA[161] = G109;
r_cgesvA[162] = G102;
r_cgesvA[163] = G94;
r_cgesvA[164] = G84;
r_cgesvA[165] = G72;
r_cgesvA[166] = G59;
r_cgesvA[167] = G44;
r_cgesvA[168] = G13;
r_cgesvB[12] = -G404;


  }
}

#endif
