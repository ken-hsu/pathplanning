/*
 * File: _coder_HIGHT2SLOPE_api.c
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 26-Nov-2018 14:23:41
 */

/* Include Files */
#include "tmwtypes.h"
#include "_coder_HIGHT2SLOPE_api.h"
#include "_coder_HIGHT2SLOPE_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131451U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "HIGHT2SLOPE",                       /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T **y_data, int32_T y_size[1]);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T **ret_data, int32_T ret_size[1]);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *hight, const
  char_T *identifier, real_T **y_data, int32_T y_size[1]);
static const mxArray *emlrt_marshallOut(const real_T u_data[], const int32_T
  u_size[1]);

/* Function Definitions */

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real_T **y_data
 *                int32_T y_size[1]
 * Return Type  : void
 */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T **y_data, int32_T y_size[1])
{
  real_T *r1;
  c_emlrt_marshallIn(sp, emlrtAlias(u), parentId, &r1, y_size);
  *y_data = r1;
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real_T **ret_data
 *                int32_T ret_size[1]
 * Return Type  : void
 */
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T **ret_data, int32_T ret_size[1])
{
  static const int32_T dims[1] = { 4000 };

  const boolean_T bv0[1] = { true };

  int32_T iv1[1];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims, &bv0[0],
    iv1);
  ret_size[0] = iv1[0];
  *ret_data = (real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *hight
 *                const char_T *identifier
 *                real_T **y_data
 *                int32_T y_size[1]
 * Return Type  : void
 */
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *hight, const
  char_T *identifier, real_T **y_data, int32_T y_size[1])
{
  emlrtMsgIdentifier thisId;
  real_T *r0;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(hight), &thisId, &r0, y_size);
  *y_data = r0;
  emlrtDestroyArray(&hight);
}

/*
 * Arguments    : const real_T u_data[]
 *                const int32_T u_size[1]
 * Return Type  : const mxArray *
 */
static const mxArray *emlrt_marshallOut(const real_T u_data[], const int32_T
  u_size[1])
{
  const mxArray *y;
  const mxArray *m0;
  static const int32_T iv0[1] = { 0 };

  y = NULL;
  m0 = emlrtCreateNumericArray(1, iv0, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m0, (void *)&u_data[0]);
  emlrtSetDimensions((mxArray *)m0, *(int32_T (*)[1])&u_size[0], 1);
  emlrtAssign(&y, m0);
  return y;
}

/*
 * Arguments    : const mxArray * const prhs[2]
 *                const mxArray *plhs[1]
 * Return Type  : void
 */
void HIGHT2SLOPE_api(const mxArray * const prhs[2], const mxArray *plhs[1])
{
  real_T (*slope_data)[3999];
  real_T (*hight_data)[4000];
  int32_T hight_size[1];
  real_T (*dis_data)[4000];
  int32_T dis_size[1];
  int32_T slope_size[1];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  slope_data = (real_T (*)[3999])mxMalloc(sizeof(real_T [3999]));

  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAlias((const mxArray *)prhs[0]), "hight", (real_T **)
                   &hight_data, hight_size);
  emlrt_marshallIn(&st, emlrtAlias((const mxArray *)prhs[1]), "dis", (real_T **)
                   &dis_data, dis_size);

  /* Invoke the target function */
  HIGHT2SLOPE(*hight_data, hight_size, *dis_data, dis_size, *slope_data,
              slope_size);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*slope_data, slope_size);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void HIGHT2SLOPE_atexit(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  HIGHT2SLOPE_xil_terminate();
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void HIGHT2SLOPE_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void HIGHT2SLOPE_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * File trailer for _coder_HIGHT2SLOPE_api.c
 *
 * [EOF]
 */
