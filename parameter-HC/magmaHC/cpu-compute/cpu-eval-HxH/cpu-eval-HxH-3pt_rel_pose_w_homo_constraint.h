#ifndef cpu_eval_HxH_3pt_rel_pose_w_homo_constraint_h
#define cpu_eval_HxH_3pt_rel_pose_w_homo_constraint_h
// ============================================================================
// partial derivative evaluations of the 3-point relative pose estimation with 
// homography constraint problem
//
// Modifications
//    Chien  22-01-02:   Originally created
//
// ============================================================================
#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <chrono>

// -- magma --
#include "flops.h"
#include "magma_v2.h"
#include "magma_lapack.h"
#include "magma_internal.h"
#undef max
#undef min

namespace magmaHCWrapper {

  extern "C"
  void cpu_eval_HxH_3pt_rel_pose_w_homo_constraint(
      magma_int_t s, float t, int N, magmaFloatComplex* s_track,
      const magmaFloatComplex &C0, const magmaFloatComplex &C1, const magmaFloatComplex &C2,
      magmaFloatComplex* s_startCoefs, magmaFloatComplex* s_targetCoefs,
      magmaFloatComplex* r_cgesvA, magmaFloatComplex* r_cgesvB )
  {
    magmaFloatComplex G0 = C1 * t;
magmaFloatComplex G1 = C0 + G0;
magmaFloatComplex G2 = G1 * s_startCoefs[15];
magmaFloatComplex G3 = t * s_targetCoefs[15];
magmaFloatComplex G4 = G2 + G3;
magmaFloatComplex G5 = G1 * s_startCoefs[0];
magmaFloatComplex G6 = t * s_targetCoefs[0];
magmaFloatComplex G7 = G5 + G6;
magmaFloatComplex G8 = s_track[7] * s_track[5];
magmaFloatComplex G9 = G7 * G8;
magmaFloatComplex G10 = G4 * G9;
magmaFloatComplex G11 = G1 * s_startCoefs[12];
magmaFloatComplex G12 = t * s_targetCoefs[12];
magmaFloatComplex G13 = G11 + G12;
magmaFloatComplex G14 = G7 * s_track[5];
magmaFloatComplex G15 = G13 * G14;
magmaFloatComplex G16 = C1 * G15;
magmaFloatComplex G17 = G10 + G16;
magmaFloatComplex G18 = s_track[6] * s_track[5];
magmaFloatComplex G19 = G7 * G18;
magmaFloatComplex G20 = G4 * G19;
magmaFloatComplex G21 = C1 * G20;
magmaFloatComplex G22 = G1 * s_startCoefs[9];
magmaFloatComplex G23 = t * s_targetCoefs[9];
magmaFloatComplex G24 = G22 + G23;
magmaFloatComplex G25 = G24 * G14;
magmaFloatComplex G26 = G21 + G25;
magmaFloatComplex G27 = G1 * s_startCoefs[16];
magmaFloatComplex G28 = t * s_targetCoefs[16];
magmaFloatComplex G29 = G27 + G28;
magmaFloatComplex G30 = G1 * s_startCoefs[1];
magmaFloatComplex G31 = t * s_targetCoefs[1];
magmaFloatComplex G32 = G30 + G31;
magmaFloatComplex G33 = G32 * G8;
magmaFloatComplex G34 = G29 * G33;
magmaFloatComplex G35 = G1 * s_startCoefs[13];
magmaFloatComplex G36 = t * s_targetCoefs[13];
magmaFloatComplex G37 = G35 + G36;
magmaFloatComplex G38 = G32 * s_track[5];
magmaFloatComplex G39 = G37 * G38;
magmaFloatComplex G40 = C1 * G39;
magmaFloatComplex G41 = G34 + G40;
magmaFloatComplex G42 = G32 * G18;
magmaFloatComplex G43 = G29 * G42;
magmaFloatComplex G44 = C1 * G43;
magmaFloatComplex G45 = G1 * s_startCoefs[10];
magmaFloatComplex G46 = t * s_targetCoefs[10];
magmaFloatComplex G47 = G45 + G46;
magmaFloatComplex G48 = G47 * G38;
magmaFloatComplex G49 = G44 + G48;
magmaFloatComplex G50 = G1 * s_startCoefs[17];
magmaFloatComplex G51 = t * s_targetCoefs[17];
magmaFloatComplex G52 = G50 + G51;
magmaFloatComplex G53 = G1 * s_startCoefs[2];
magmaFloatComplex G54 = t * s_targetCoefs[2];
magmaFloatComplex G55 = G53 + G54;
magmaFloatComplex G56 = G55 * G8;
magmaFloatComplex G57 = G52 * G56;
magmaFloatComplex G58 = G1 * s_startCoefs[14];
magmaFloatComplex G59 = t * s_targetCoefs[14];
magmaFloatComplex G60 = G58 + G59;
magmaFloatComplex G61 = G55 * s_track[5];
magmaFloatComplex G62 = G60 * G61;
magmaFloatComplex G63 = C1 * G62;
magmaFloatComplex G64 = G57 + G63;
magmaFloatComplex G65 = G55 * G18;
magmaFloatComplex G66 = G52 * G65;
magmaFloatComplex G67 = C1 * G66;
magmaFloatComplex G68 = G1 * s_startCoefs[11];
magmaFloatComplex G69 = t * s_targetCoefs[11];
magmaFloatComplex G70 = G68 + G69;
magmaFloatComplex G71 = G70 * G61;
magmaFloatComplex G72 = G67 + G71;
magmaFloatComplex G73 = s_track[0] + s_track[0];
magmaFloatComplex G74 = G1 * s_startCoefs[3];
magmaFloatComplex G75 = t * s_targetCoefs[3];
magmaFloatComplex G76 = G74 + G75;
magmaFloatComplex G77 = G76 * G8;
magmaFloatComplex G78 = G4 * G77;
magmaFloatComplex G79 = G76 * s_track[5];
magmaFloatComplex G80 = G13 * G79;
magmaFloatComplex G81 = C1 * G80;
magmaFloatComplex G82 = G78 + G81;
magmaFloatComplex G83 = G76 * G18;
magmaFloatComplex G84 = G4 * G83;
magmaFloatComplex G85 = C1 * G84;
magmaFloatComplex G86 = G24 * G79;
magmaFloatComplex G87 = G85 + G86;
magmaFloatComplex G88 = G1 * s_startCoefs[4];
magmaFloatComplex G89 = t * s_targetCoefs[4];
magmaFloatComplex G90 = G88 + G89;
magmaFloatComplex G91 = G90 * G8;
magmaFloatComplex G92 = G29 * G91;
magmaFloatComplex G93 = G90 * s_track[5];
magmaFloatComplex G94 = G37 * G93;
magmaFloatComplex G95 = C1 * G94;
magmaFloatComplex G96 = G92 + G95;
magmaFloatComplex G97 = G90 * G18;
magmaFloatComplex G98 = G29 * G97;
magmaFloatComplex G99 = C1 * G98;
magmaFloatComplex G100 = G47 * G93;
magmaFloatComplex G101 = G99 + G100;
magmaFloatComplex G102 = G1 * s_startCoefs[5];
magmaFloatComplex G103 = t * s_targetCoefs[5];
magmaFloatComplex G104 = G102 + G103;
magmaFloatComplex G105 = G104 * G8;
magmaFloatComplex G106 = G52 * G105;
magmaFloatComplex G107 = G104 * s_track[5];
magmaFloatComplex G108 = G60 * G107;
magmaFloatComplex G109 = C1 * G108;
magmaFloatComplex G110 = G106 + G109;
magmaFloatComplex G111 = G104 * G18;
magmaFloatComplex G112 = G52 * G111;
magmaFloatComplex G113 = C1 * G112;
magmaFloatComplex G114 = G70 * G107;
magmaFloatComplex G115 = G113 + G114;
magmaFloatComplex G116 = s_track[1] + s_track[1];
magmaFloatComplex G117 = G1 * s_startCoefs[6];
magmaFloatComplex G118 = t * s_targetCoefs[6];
magmaFloatComplex G119 = G117 + G118;
magmaFloatComplex G120 = G119 * G8;
magmaFloatComplex G121 = G4 * G120;
magmaFloatComplex G122 = G119 * s_track[5];
magmaFloatComplex G123 = G13 * G122;
magmaFloatComplex G124 = C1 * G123;
magmaFloatComplex G125 = G121 + G124;
magmaFloatComplex G126 = G119 * G18;
magmaFloatComplex G127 = G4 * G126;
magmaFloatComplex G128 = C1 * G127;
magmaFloatComplex G129 = G24 * G122;
magmaFloatComplex G130 = G128 + G129;
magmaFloatComplex G131 = G1 * s_startCoefs[7];
magmaFloatComplex G132 = t * s_targetCoefs[7];
magmaFloatComplex G133 = G131 + G132;
magmaFloatComplex G134 = G133 * G8;
magmaFloatComplex G135 = G29 * G134;
magmaFloatComplex G136 = G133 * s_track[5];
magmaFloatComplex G137 = G37 * G136;
magmaFloatComplex G138 = C1 * G137;
magmaFloatComplex G139 = G135 + G138;
magmaFloatComplex G140 = G133 * G18;
magmaFloatComplex G141 = G29 * G140;
magmaFloatComplex G142 = C1 * G141;
magmaFloatComplex G143 = G47 * G136;
magmaFloatComplex G144 = G142 + G143;
magmaFloatComplex G145 = G1 * s_startCoefs[8];
magmaFloatComplex G146 = t * s_targetCoefs[8];
magmaFloatComplex G147 = G145 + G146;
magmaFloatComplex G148 = G147 * G8;
magmaFloatComplex G149 = G52 * G148;
magmaFloatComplex G150 = G147 * s_track[5];
magmaFloatComplex G151 = G60 * G150;
magmaFloatComplex G152 = C1 * G151;
magmaFloatComplex G153 = G149 + G152;
magmaFloatComplex G154 = G147 * G18;
magmaFloatComplex G155 = G52 * G154;
magmaFloatComplex G156 = C1 * G155;
magmaFloatComplex G157 = G70 * G150;
magmaFloatComplex G158 = G156 + G157;
magmaFloatComplex G159 = s_track[2] + s_track[2];
magmaFloatComplex G160 = G4 * G76;
magmaFloatComplex G161 = C1 * G160;
magmaFloatComplex G162 = G4 * G7;
magmaFloatComplex G163 = G29 * G90;
magmaFloatComplex G164 = C1 * G163;
magmaFloatComplex G165 = G29 * G32;
magmaFloatComplex G166 = G52 * G104;
magmaFloatComplex G167 = C1 * G166;
magmaFloatComplex G168 = G52 * G55;
magmaFloatComplex G169 = s_track[3] + s_track[3];
magmaFloatComplex G170 = C1 * G162;
magmaFloatComplex G171 = C1 * G165;
magmaFloatComplex G172 = C1 * G168;
magmaFloatComplex G173 = s_track[4] + s_track[4];
magmaFloatComplex G174 = s_track[7] * s_track[0];
magmaFloatComplex G175 = G7 * G174;
magmaFloatComplex G176 = G4 * G175;
magmaFloatComplex G177 = G7 * s_track[0];
magmaFloatComplex G178 = G13 * G177;
magmaFloatComplex G179 = C1 * G178;
magmaFloatComplex G180 = G176 + G179;
magmaFloatComplex G181 = s_track[7] * s_track[1];
magmaFloatComplex G182 = G76 * G181;
magmaFloatComplex G183 = G4 * G182;
magmaFloatComplex G184 = G180 + G183;
magmaFloatComplex G185 = G76 * s_track[1];
magmaFloatComplex G186 = G13 * G185;
magmaFloatComplex G187 = C1 * G186;
magmaFloatComplex G188 = G184 + G187;
magmaFloatComplex G189 = s_track[7] * s_track[2];
magmaFloatComplex G190 = G119 * G189;
magmaFloatComplex G191 = G4 * G190;
magmaFloatComplex G192 = G188 + G191;
magmaFloatComplex G193 = G119 * s_track[2];
magmaFloatComplex G194 = G13 * G193;
magmaFloatComplex G195 = C1 * G194;
magmaFloatComplex G196 = G192 + G195;
magmaFloatComplex G197 = s_track[6] * s_track[0];
magmaFloatComplex G198 = G7 * G197;
magmaFloatComplex G199 = G4 * G198;
magmaFloatComplex G200 = C1 * G199;
magmaFloatComplex G201 = G24 * G177;
magmaFloatComplex G202 = G200 + G201;
magmaFloatComplex G203 = s_track[6] * s_track[1];
magmaFloatComplex G204 = G76 * G203;
magmaFloatComplex G205 = G4 * G204;
magmaFloatComplex G206 = C1 * G205;
magmaFloatComplex G207 = G202 + G206;
magmaFloatComplex G208 = G24 * G185;
magmaFloatComplex G209 = G207 + G208;
magmaFloatComplex G210 = s_track[6] * s_track[2];
magmaFloatComplex G211 = G119 * G210;
magmaFloatComplex G212 = G4 * G211;
magmaFloatComplex G213 = C1 * G212;
magmaFloatComplex G214 = G209 + G213;
magmaFloatComplex G215 = G24 * G193;
magmaFloatComplex G216 = G214 + G215;
magmaFloatComplex G217 = G32 * G174;
magmaFloatComplex G218 = G29 * G217;
magmaFloatComplex G219 = G32 * s_track[0];
magmaFloatComplex G220 = G37 * G219;
magmaFloatComplex G221 = C1 * G220;
magmaFloatComplex G222 = G218 + G221;
magmaFloatComplex G223 = G90 * G181;
magmaFloatComplex G224 = G29 * G223;
magmaFloatComplex G225 = G222 + G224;
magmaFloatComplex G226 = G90 * s_track[1];
magmaFloatComplex G227 = G37 * G226;
magmaFloatComplex G228 = C1 * G227;
magmaFloatComplex G229 = G225 + G228;
magmaFloatComplex G230 = G133 * G189;
magmaFloatComplex G231 = G29 * G230;
magmaFloatComplex G232 = G229 + G231;
magmaFloatComplex G233 = G133 * s_track[2];
magmaFloatComplex G234 = G37 * G233;
magmaFloatComplex G235 = C1 * G234;
magmaFloatComplex G236 = G232 + G235;
magmaFloatComplex G237 = G32 * G197;
magmaFloatComplex G238 = G29 * G237;
magmaFloatComplex G239 = C1 * G238;
magmaFloatComplex G240 = G47 * G219;
magmaFloatComplex G241 = G239 + G240;
magmaFloatComplex G242 = G90 * G203;
magmaFloatComplex G243 = G29 * G242;
magmaFloatComplex G244 = C1 * G243;
magmaFloatComplex G245 = G241 + G244;
magmaFloatComplex G246 = G47 * G226;
magmaFloatComplex G247 = G245 + G246;
magmaFloatComplex G248 = G133 * G210;
magmaFloatComplex G249 = G29 * G248;
magmaFloatComplex G250 = C1 * G249;
magmaFloatComplex G251 = G247 + G250;
magmaFloatComplex G252 = G47 * G233;
magmaFloatComplex G253 = G251 + G252;
magmaFloatComplex G254 = G55 * G174;
magmaFloatComplex G255 = G52 * G254;
magmaFloatComplex G256 = G55 * s_track[0];
magmaFloatComplex G257 = G60 * G256;
magmaFloatComplex G258 = C1 * G257;
magmaFloatComplex G259 = G255 + G258;
magmaFloatComplex G260 = G104 * G181;
magmaFloatComplex G261 = G52 * G260;
magmaFloatComplex G262 = G259 + G261;
magmaFloatComplex G263 = G104 * s_track[1];
magmaFloatComplex G264 = G60 * G263;
magmaFloatComplex G265 = C1 * G264;
magmaFloatComplex G266 = G262 + G265;
magmaFloatComplex G267 = G147 * G189;
magmaFloatComplex G268 = G52 * G267;
magmaFloatComplex G269 = G266 + G268;
magmaFloatComplex G270 = G147 * s_track[2];
magmaFloatComplex G271 = G60 * G270;
magmaFloatComplex G272 = C1 * G271;
magmaFloatComplex G273 = G269 + G272;
magmaFloatComplex G274 = G55 * G197;
magmaFloatComplex G275 = G52 * G274;
magmaFloatComplex G276 = C1 * G275;
magmaFloatComplex G277 = G70 * G256;
magmaFloatComplex G278 = G276 + G277;
magmaFloatComplex G279 = G104 * G203;
magmaFloatComplex G280 = G52 * G279;
magmaFloatComplex G281 = C1 * G280;
magmaFloatComplex G282 = G278 + G281;
magmaFloatComplex G283 = G70 * G263;
magmaFloatComplex G284 = G282 + G283;
magmaFloatComplex G285 = G147 * G210;
magmaFloatComplex G286 = G52 * G285;
magmaFloatComplex G287 = C1 * G286;
magmaFloatComplex G288 = G284 + G287;
magmaFloatComplex G289 = G70 * G270;
magmaFloatComplex G290 = G288 + G289;
magmaFloatComplex G291 = s_track[0] * s_track[5];
magmaFloatComplex G292 = G7 * G291;
magmaFloatComplex G293 = G4 * G292;
magmaFloatComplex G294 = C1 * G293;
magmaFloatComplex G295 = s_track[1] * s_track[5];
magmaFloatComplex G296 = G76 * G295;
magmaFloatComplex G297 = G4 * G296;
magmaFloatComplex G298 = C1 * G297;
magmaFloatComplex G299 = G294 + G298;
magmaFloatComplex G300 = s_track[2] * s_track[5];
magmaFloatComplex G301 = G119 * G300;
magmaFloatComplex G302 = G4 * G301;
magmaFloatComplex G303 = C1 * G302;
magmaFloatComplex G304 = G299 + G303;
magmaFloatComplex G305 = G32 * G291;
magmaFloatComplex G306 = G29 * G305;
magmaFloatComplex G307 = C1 * G306;
magmaFloatComplex G308 = G90 * G295;
magmaFloatComplex G309 = G29 * G308;
magmaFloatComplex G310 = C1 * G309;
magmaFloatComplex G311 = G307 + G310;
magmaFloatComplex G312 = G133 * G300;
magmaFloatComplex G313 = G29 * G312;
magmaFloatComplex G314 = C1 * G313;
magmaFloatComplex G315 = G311 + G314;
magmaFloatComplex G316 = G55 * G291;
magmaFloatComplex G317 = G52 * G316;
magmaFloatComplex G318 = C1 * G317;
magmaFloatComplex G319 = G104 * G295;
magmaFloatComplex G320 = G52 * G319;
magmaFloatComplex G321 = C1 * G320;
magmaFloatComplex G322 = G318 + G321;
magmaFloatComplex G323 = G147 * G300;
magmaFloatComplex G324 = G52 * G323;
magmaFloatComplex G325 = C1 * G324;
magmaFloatComplex G326 = G322 + G325;
magmaFloatComplex G327 = G293 + G297;
magmaFloatComplex G328 = G327 + G302;
magmaFloatComplex G329 = G306 + G309;
magmaFloatComplex G330 = G329 + G313;
magmaFloatComplex G331 = G317 + G320;
magmaFloatComplex G332 = G331 + G324;
magmaFloatComplex G333 = G291 * s_track[7];
magmaFloatComplex G334 = G333 * G7;
magmaFloatComplex G335 = G334 * G4;
magmaFloatComplex G336 = G291 * G7;
magmaFloatComplex G337 = G336 * G13;
magmaFloatComplex G338 = C1 * G337;
magmaFloatComplex G339 = G335 + G338;
magmaFloatComplex G340 = G295 * s_track[7];
magmaFloatComplex G341 = G340 * G76;
magmaFloatComplex G342 = G341 * G4;
magmaFloatComplex G343 = G339 + G342;
magmaFloatComplex G344 = G295 * G76;
magmaFloatComplex G345 = G344 * G13;
magmaFloatComplex G346 = C1 * G345;
magmaFloatComplex G347 = G343 + G346;
magmaFloatComplex G348 = G300 * s_track[7];
magmaFloatComplex G349 = G348 * G119;
magmaFloatComplex G350 = G349 * G4;
magmaFloatComplex G351 = G347 + G350;
magmaFloatComplex G352 = G300 * G119;
magmaFloatComplex G353 = G352 * G13;
magmaFloatComplex G354 = C1 * G353;
magmaFloatComplex G355 = G351 + G354;
magmaFloatComplex G356 = s_track[3] * G76;
magmaFloatComplex G357 = G356 * G4;
magmaFloatComplex G358 = C1 * G357;
magmaFloatComplex G359 = G355 + G358;
magmaFloatComplex G360 = s_track[4] * G7;
magmaFloatComplex G361 = G360 * G4;
magmaFloatComplex G362 = C1 * G361;
magmaFloatComplex G363 = G359 + G362;
magmaFloatComplex G364 = G119 * G13;
magmaFloatComplex G365 = G363 + G364;
magmaFloatComplex G366 = G291 * s_track[6];
magmaFloatComplex G367 = G366 * G7;
magmaFloatComplex G368 = G367 * G4;
magmaFloatComplex G369 = C1 * G368;
magmaFloatComplex G370 = G336 * G24;
magmaFloatComplex G371 = G369 + G370;
magmaFloatComplex G372 = G295 * s_track[6];
magmaFloatComplex G373 = G372 * G76;
magmaFloatComplex G374 = G373 * G4;
magmaFloatComplex G375 = C1 * G374;
magmaFloatComplex G376 = G371 + G375;
magmaFloatComplex G377 = G344 * G24;
magmaFloatComplex G378 = G376 + G377;
magmaFloatComplex G379 = G300 * s_track[6];
magmaFloatComplex G380 = G379 * G119;
magmaFloatComplex G381 = G380 * G4;
magmaFloatComplex G382 = C1 * G381;
magmaFloatComplex G383 = G378 + G382;
magmaFloatComplex G384 = G352 * G24;
magmaFloatComplex G385 = G383 + G384;
magmaFloatComplex G386 = s_track[3] * G7;
magmaFloatComplex G387 = G386 * G4;
magmaFloatComplex G388 = G385 + G387;
magmaFloatComplex G389 = s_track[4] * G76;
magmaFloatComplex G390 = G389 * G4;
magmaFloatComplex G391 = C1 * G390;
magmaFloatComplex G392 = G388 + G391;
magmaFloatComplex G393 = G119 * G24;
magmaFloatComplex G394 = C1 * G393;
magmaFloatComplex G395 = G392 + G394;
magmaFloatComplex G396 = G333 * G32;
magmaFloatComplex G397 = G396 * G29;
magmaFloatComplex G398 = G291 * G32;
magmaFloatComplex G399 = G398 * G37;
magmaFloatComplex G400 = C1 * G399;
magmaFloatComplex G401 = G397 + G400;
magmaFloatComplex G402 = G340 * G90;
magmaFloatComplex G403 = G402 * G29;
magmaFloatComplex G404 = G401 + G403;
magmaFloatComplex G405 = G295 * G90;
magmaFloatComplex G406 = G405 * G37;
magmaFloatComplex G407 = C1 * G406;
magmaFloatComplex G408 = G404 + G407;
magmaFloatComplex G409 = G348 * G133;
magmaFloatComplex G410 = G409 * G29;
magmaFloatComplex G411 = G408 + G410;
magmaFloatComplex G412 = G300 * G133;
magmaFloatComplex G413 = G412 * G37;
magmaFloatComplex G414 = C1 * G413;
magmaFloatComplex G415 = G411 + G414;
magmaFloatComplex G416 = s_track[3] * G90;
magmaFloatComplex G417 = G416 * G29;
magmaFloatComplex G418 = C1 * G417;
magmaFloatComplex G419 = G415 + G418;
magmaFloatComplex G420 = s_track[4] * G32;
magmaFloatComplex G421 = G420 * G29;
magmaFloatComplex G422 = C1 * G421;
magmaFloatComplex G423 = G419 + G422;
magmaFloatComplex G424 = G133 * G37;
magmaFloatComplex G425 = G423 + G424;
magmaFloatComplex G426 = G366 * G32;
magmaFloatComplex G427 = G426 * G29;
magmaFloatComplex G428 = C1 * G427;
magmaFloatComplex G429 = G398 * G47;
magmaFloatComplex G430 = G428 + G429;
magmaFloatComplex G431 = G372 * G90;
magmaFloatComplex G432 = G431 * G29;
magmaFloatComplex G433 = C1 * G432;
magmaFloatComplex G434 = G430 + G433;
magmaFloatComplex G435 = G405 * G47;
magmaFloatComplex G436 = G434 + G435;
magmaFloatComplex G437 = G379 * G133;
magmaFloatComplex G438 = G437 * G29;
magmaFloatComplex G439 = C1 * G438;
magmaFloatComplex G440 = G436 + G439;
magmaFloatComplex G441 = G412 * G47;
magmaFloatComplex G442 = G440 + G441;
magmaFloatComplex G443 = s_track[3] * G32;
magmaFloatComplex G444 = G443 * G29;
magmaFloatComplex G445 = G442 + G444;
magmaFloatComplex G446 = s_track[4] * G90;
magmaFloatComplex G447 = G446 * G29;
magmaFloatComplex G448 = C1 * G447;
magmaFloatComplex G449 = G445 + G448;
magmaFloatComplex G450 = G133 * G47;
magmaFloatComplex G451 = C1 * G450;
magmaFloatComplex G452 = G449 + G451;
magmaFloatComplex G453 = G333 * G55;
magmaFloatComplex G454 = G453 * G52;
magmaFloatComplex G455 = G291 * G55;
magmaFloatComplex G456 = G455 * G60;
magmaFloatComplex G457 = C1 * G456;
magmaFloatComplex G458 = G454 + G457;
magmaFloatComplex G459 = G340 * G104;
magmaFloatComplex G460 = G459 * G52;
magmaFloatComplex G461 = G458 + G460;
magmaFloatComplex G462 = G295 * G104;
magmaFloatComplex G463 = G462 * G60;
magmaFloatComplex G464 = C1 * G463;
magmaFloatComplex G465 = G461 + G464;
magmaFloatComplex G466 = G348 * G147;
magmaFloatComplex G467 = G466 * G52;
magmaFloatComplex G468 = G465 + G467;
magmaFloatComplex G469 = G300 * G147;
magmaFloatComplex G470 = G469 * G60;
magmaFloatComplex G471 = C1 * G470;
magmaFloatComplex G472 = G468 + G471;
magmaFloatComplex G473 = s_track[3] * G104;
magmaFloatComplex G474 = G473 * G52;
magmaFloatComplex G475 = C1 * G474;
magmaFloatComplex G476 = G472 + G475;
magmaFloatComplex G477 = s_track[4] * G55;
magmaFloatComplex G478 = G477 * G52;
magmaFloatComplex G479 = C1 * G478;
magmaFloatComplex G480 = G476 + G479;
magmaFloatComplex G481 = G147 * G60;
magmaFloatComplex G482 = G480 + G481;
magmaFloatComplex G483 = G366 * G55;
magmaFloatComplex G484 = G483 * G52;
magmaFloatComplex G485 = C1 * G484;
magmaFloatComplex G486 = G455 * G70;
magmaFloatComplex G487 = G485 + G486;
magmaFloatComplex G488 = G372 * G104;
magmaFloatComplex G489 = G488 * G52;
magmaFloatComplex G490 = C1 * G489;
magmaFloatComplex G491 = G487 + G490;
magmaFloatComplex G492 = G462 * G70;
magmaFloatComplex G493 = G491 + G492;
magmaFloatComplex G494 = G379 * G147;
magmaFloatComplex G495 = G494 * G52;
magmaFloatComplex G496 = C1 * G495;
magmaFloatComplex G497 = G493 + G496;
magmaFloatComplex G498 = G469 * G70;
magmaFloatComplex G499 = G497 + G498;
magmaFloatComplex G500 = s_track[3] * G55;
magmaFloatComplex G501 = G500 * G52;
magmaFloatComplex G502 = G499 + G501;
magmaFloatComplex G503 = s_track[4] * G104;
magmaFloatComplex G504 = G503 * G52;
magmaFloatComplex G505 = C1 * G504;
magmaFloatComplex G506 = G502 + G505;
magmaFloatComplex G507 = G147 * G70;
magmaFloatComplex G508 = C1 * G507;
magmaFloatComplex G509 = G506 + G508;
magmaFloatComplex G510 = s_track[0] * s_track[0];
magmaFloatComplex G511 = s_track[1] * s_track[1];
magmaFloatComplex G512 = G510 + G511;
magmaFloatComplex G513 = s_track[2] * s_track[2];
magmaFloatComplex G514 = G512 + G513;
magmaFloatComplex G515 = C1 + G514;
magmaFloatComplex G516 = s_track[3] * s_track[3];
magmaFloatComplex G517 = s_track[4] * s_track[4];
magmaFloatComplex G518 = G516 + G517;
magmaFloatComplex G519 = C1 + G518;

    r_cgesvA[0] = G17;
    r_cgesvA[1] = G26;
    r_cgesvA[2] = G41;
    r_cgesvA[3] = G49;
    r_cgesvA[4] = G64;
    r_cgesvA[5] = G72;
    r_cgesvA[6] = G73;
    r_cgesvA[7] = C2;
    r_cgesvB[0] =G365;

    r_cgesvA[8] = G82;
    r_cgesvA[9] = G87;
    r_cgesvA[10] = G96;
    r_cgesvA[11] = G101;
    r_cgesvA[12] = G110;
    r_cgesvA[13] = G115;
    r_cgesvA[14] = G116;
    r_cgesvA[15] = C2;
    r_cgesvB[1] =G395;

    r_cgesvA[16] = G125;
    r_cgesvA[17] = G130;
    r_cgesvA[18] = G139;
    r_cgesvA[19] = G144;
    r_cgesvA[20] = G153;
    r_cgesvA[21] = G158;
    r_cgesvA[22] = G159;
    r_cgesvA[23] = C2;
    r_cgesvB[2] =G425;

    r_cgesvA[24] = G161;
    r_cgesvA[25] = G162;
    r_cgesvA[26] = G164;
    r_cgesvA[27] = G165;
    r_cgesvA[28] = G167;
    r_cgesvA[29] = G168;
    r_cgesvA[30] = C2;
    r_cgesvA[31] = G169;
    r_cgesvB[3] =G452;

    r_cgesvA[32] = G170;
    r_cgesvA[33] = G161;
    r_cgesvA[34] = G171;
    r_cgesvA[35] = G164;
    r_cgesvA[36] = G172;
    r_cgesvA[37] = G167;
    r_cgesvA[38] = C2;
    r_cgesvA[39] = G173;
    r_cgesvB[4] =G482;

    r_cgesvA[40] = G196;
    r_cgesvA[41] = G216;
    r_cgesvA[42] = G236;
    r_cgesvA[43] = G253;
    r_cgesvA[44] = G273;
    r_cgesvA[45] = G290;
    r_cgesvA[46] = C2;
    r_cgesvA[47] = C2;
    r_cgesvB[5] =G509;

    r_cgesvA[48] = C2;
    r_cgesvA[49] = G304;
    r_cgesvA[50] = C2;
    r_cgesvA[51] = G315;
    r_cgesvA[52] = C2;
    r_cgesvA[53] = G326;
    r_cgesvA[54] = C2;
    r_cgesvA[55] = C2;
    r_cgesvB[6] =G515;

    r_cgesvA[56] = G328;
    r_cgesvA[57] = C2;
    r_cgesvA[58] = G330;
    r_cgesvA[59] = C2;
    r_cgesvA[60] = G332;
    r_cgesvA[61] = C2;
    r_cgesvA[62] = C2;
    r_cgesvA[63] = C2;
    r_cgesvB[7] =G519;

  }
}

#endif
