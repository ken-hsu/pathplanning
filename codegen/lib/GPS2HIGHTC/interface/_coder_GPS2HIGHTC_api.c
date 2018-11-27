/*
 * File: _coder_GPS2HIGHTC_api.c
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 26-Nov-2018 14:19:06
 */

/* Include Files */
#include "tmwtypes.h"
#include "_coder_GPS2HIGHTC_api.h"
#include "_coder_GPS2HIGHTC_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131451U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "GPS2HIGHTC",                        /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T **y_data, int32_T y_size[1]);
static const mxArray *b_emlrt_marshallOut(const real_T u_data[], const int32_T
  u_size[2]);
static int16_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *map,
  const char_T *identifier))[12967201];
static int16_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[12967201];
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T **ret_data, int32_T ret_size[1]);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *Latitude,
  const char_T *identifier, real_T **y_data, int32_T y_size[1]);
static const mxArray *emlrt_marshallOut(const real_T u_data[], const int32_T
  u_size[1]);
static int16_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[12967201];

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
  e_emlrt_marshallIn(sp, emlrtAlias(u), parentId, &r1, y_size);
  *y_data = r1;
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const real_T u_data[]
 *                const int32_T u_size[2]
 * Return Type  : const mxArray *
 */
static const mxArray *b_emlrt_marshallOut(const real_T u_data[], const int32_T
  u_size[2])
{
  const mxArray *y;
  const mxArray *m1;
  static const int32_T iv1[2] = { 0, 0 };

  y = NULL;
  m1 = emlrtCreateNumericArray(2, iv1, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m1, (void *)&u_data[0]);
  emlrtSetDimensions((mxArray *)m1, *(int32_T (*)[2])&u_size[0], 2);
  emlrtAssign(&y, m1);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *map
 *                const char_T *identifier
 * Return Type  : int16_T (*)[12967201]
 */
static int16_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *map,
  const char_T *identifier))[12967201]
{
  int16_T (*y)[12967201];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(map), &thisId);
  emlrtDestroyArray(&map);
  return y;
}
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : int16_T (*)[12967201]
 */
  static int16_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[12967201]
{
  int16_T (*y)[12967201];
  y = f_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real_T **ret_data
 *                int32_T ret_size[1]
 * Return Type  : void
 */
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T **ret_data, int32_T ret_size[1])
{
  static const int32_T dims[1] = { 4000 };

  const boolean_T bv0[1] = { true };

  int32_T iv2[1];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims, &bv0[0],
    iv2);
  ret_size[0] = iv2[0];
  *ret_data = (real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *Latitude
 *                const char_T *identifier
 *                real_T **y_data
 *                int32_T y_size[1]
 * Return Type  : void
 */
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *Latitude,
  const char_T *identifier, real_T **y_data, int32_T y_size[1])
{
  emlrtMsgIdentifier thisId;
  real_T *r0;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(Latitude), &thisId, &r0, y_size);
  *y_data = r0;
  emlrtDestroyArray(&Latitude);
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
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : int16_T (*)[12967201]
 */
static int16_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[12967201]
{
  int16_T (*ret)[12967201];
  static const int32_T dims[2] = { 3601, 3601 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "int16", false, 2U, dims);
  ret = (int16_T (*)[12967201])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
/*
 * Arguments    : const mxArray * const prhs[3]
 *                const mxArray *plhs[2]
 * Return Type  : void
 */
  void GPS2HIGHTC_api(const mxArray * const prhs[3], const mxArray *plhs[2])
{
  real_T (*H_data)[4000];
  real_T (*c_record_data)[8000];
  real_T (*Latitude_data)[4000];
  int32_T Latitude_size[1];
  real_T (*Lontitude_data)[4000];
  int32_T Lontitude_size[1];
  int16_T (*map)[12967201];
  int32_T H_size[1];
  int32_T c_record_size[2];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  H_data = (real_T (*)[4000])mxMalloc(sizeof(real_T [4000]));
  c_record_data = (real_T (*)[8000])mxMalloc(sizeof(real_T [8000]));

  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAlias((const mxArray *)prhs[0]), "Latitude",
                   (real_T **)&Latitude_data, Latitude_size);
  emlrt_marshallIn(&st, emlrtAlias((const mxArray *)prhs[1]), "Lontitude",
                   (real_T **)&Lontitude_data, Lontitude_size);
  map = c_emlrt_marshallIn(&st, emlrtAlias((const mxArray *)prhs[2]), "map");

  /* Invoke the target function */
  GPS2HIGHTC(*Latitude_data, Latitude_size, *Lontitude_data, Lontitude_size,
             *map, *H_data, H_size, *c_record_data, c_record_size);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*H_data, H_size);
  plhs[1] = b_emlrt_marshallOut(*c_record_data, c_record_size);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void GPS2HIGHTC_atexit(void)
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
  GPS2HIGHTC_xil_terminate();
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void GPS2HIGHTC_initialize(void)
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
void GPS2HIGHTC_terminate(void)
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
 * File trailer for _coder_GPS2HIGHTC_api.c
 *
 * [EOF]
 */
