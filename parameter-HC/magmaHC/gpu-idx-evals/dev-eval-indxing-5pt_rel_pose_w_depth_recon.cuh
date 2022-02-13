#ifndef dev_eval_indxing_5pt_rel_pose_w_depth_recon_cuh_
#define dev_eval_indxing_5pt_rel_pose_w_depth_recon_cuh_
// ============================================================================
// Device function for evaluating the parallel indexing for Hx, Ht, and H of
// 5pt_rel_pose_w_depth_recon problem
//
// Modifications
//    Chien  21-12-31:   Originally created
//
// ============================================================================
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstring>

// -- cuda included --
#include <cuda_runtime.h>

// -- magma included --
#include "flops.h"
#include "magma_v2.h"
#include "magma_lapack.h"
#include "magma_internal.h"
#undef max
#undef min
#include "magma_templates.h"
#include "sync.cuh"
#undef max
#undef min
#include "shuffle.cuh"
#undef max
#undef min
#include "batched_kernel_param.h"

namespace magmaHCWrapper {

    // -- compute the linear interpolations of parameters of phc --
    template<int N, int N_2>
    __device__ __inline__ void
    eval_parameter_homotopy(
        const int tx, float t, 
        magmaFloatComplex *s_phc_coeffs_Hx, magmaFloatComplex *s_phc_coeffs_Ht,
        const magmaFloatComplex __restrict__ *d_phc_coeffs_Hx,
        const magmaFloatComplex __restrict__ *d_phc_coeffs_Ht )
    {
        // =============================================================================
        // -- parameter homotopy of Hx --
        // -- floor(44/16) = 2 --
        #pragma unroll
        for (int i = 0; i < 2; i++) {
            s_phc_coeffs_Hx[ tx + i * N ] = d_phc_coeffs_Hx[ tx*2 + i*N_2] 
                                          + d_phc_coeffs_Hx[ tx*2 + 1 + i*N_2 ] * t;
        }

        // -- the remaining parts --
        // -- 44 - 16*2 = 12 --
        // -- N_2 * 2 = 64 --
        // -- last s_phc_coeffs_Hx from the above for-loop: 16*2 = 32
        if (tx < 12) {
          s_phc_coeffs_Hx[ tx + 32 ] = d_phc_coeffs_Hx[ tx*2 + 64] 
                                     + d_phc_coeffs_Hx[ tx*2 + 1 + 64] * t;
        }

        // =============================================================================
        // -- parameter homotopy of Ht --
        // -- floor(44/16) = 2 --
        #pragma unroll
        for (int i = 0; i < 2; i++) {
            s_phc_coeffs_Ht[ tx + i * N ] = d_phc_coeffs_Ht[ tx + i * N ];
        }

        // -- the remaining parts --
        // -- 44 - 16*2 = 12 --
        // -- N * 2 = 32 --
        // -- last s_phc_coeffs_Ht from the above for-loop: 16*2 = 32
        if (tx < 3) {
          s_phc_coeffs_Ht[ tx + 32 ] = d_phc_coeffs_Ht[ tx + 32 ];
        }

    }

    // -- Hx parallel indexing --
    template<int N, int max_terms, int max_parts, int max_terms_parts, int N_max_terms_parts>
    __device__ __inline__ void
    eval_Jacobian_5pt_rel_pose_w_depth_recon(
        const int tx, magmaFloatComplex *s_track, magmaFloatComplex r_cgesvA[N],
        const int* __restrict__ d_Hx_idx, magmaFloatComplex *s_phc_coeffs )
    {
      //#pragma unroll
      for(int i = 0; i < N; i++) {
        r_cgesvA[i] = MAGMA_C_ZERO;

        //#pragma unroll
        for(int j = 0; j < max_terms; j++) {
          r_cgesvA[i] += d_Hx_idx[j*max_parts + i*max_terms_parts + tx*N_max_terms_parts] 
                       * s_track[ d_Hx_idx[j*max_parts + 1 + i*max_terms_parts + tx*N_max_terms_parts] ]
                       * s_track[ d_Hx_idx[j*max_parts + 2 + i*max_terms_parts + tx*N_max_terms_parts] ] 
                       * s_phc_coeffs[ d_Hx_idx[j*max_parts + 3 + i*max_terms_parts + tx*N_max_terms_parts] ];
        }
      }
    }

    // -- Ht parallel indexing --
    template<int N, int max_terms, int max_parts, int max_terms_parts>
    __device__ __inline__ void
    eval_Ht_5pt_rel_pose_w_depth_recon(
        const int tx, magmaFloatComplex *s_track, magmaFloatComplex &r_cgesvB,
        const int* __restrict__ d_Ht_idx, magmaFloatComplex *s_phc_coeffs)
    {
      r_cgesvB = MAGMA_C_ZERO;
      //#pragma unroll
      for (int i = 0; i < max_terms; i++) {
        r_cgesvB -= d_Ht_idx[i*max_parts + tx*max_terms_parts] 
                  * s_track[ d_Ht_idx[i*max_parts + 1 + tx*max_terms_parts] ] 
                  * s_track[ d_Ht_idx[i*max_parts + 2 + tx*max_terms_parts] ] 
                  * s_track[ d_Ht_idx[i*max_parts + 3 + tx*max_terms_parts] ]  
                  * s_phc_coeffs[ d_Ht_idx[i*max_parts + 4 + tx*max_terms_parts] ];
      }
    }

    // -- H parallel indexing --
    template<int N, int max_terms, int max_parts, int max_terms_parts>
    __device__ __inline__ void
    eval_H_5pt_rel_pose_w_depth_recon(
        const int tx, magmaFloatComplex *s_track, magmaFloatComplex &r_cgesvB,
        const int* __restrict__ d_Ht_idx, magmaFloatComplex *s_phc_coeffs)
    {
      r_cgesvB = MAGMA_C_ZERO;
      //#pragma unroll
      for (int i = 0; i < max_terms; i++) {
        r_cgesvB += d_Ht_idx[i*max_parts + tx*max_terms_parts] 
                  * s_track[ d_Ht_idx[i*max_parts + 1 + tx*max_terms_parts] ] 
                  * s_track[ d_Ht_idx[i*max_parts + 2 + tx*max_terms_parts] ] 
                  * s_track[ d_Ht_idx[i*max_parts + 3 + tx*max_terms_parts] ] 
                  * s_phc_coeffs[ d_Ht_idx[i*max_parts + 4 + tx*max_terms_parts] ];
      }
    }
}

#endif
