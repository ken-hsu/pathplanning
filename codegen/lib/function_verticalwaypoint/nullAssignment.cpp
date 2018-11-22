//
// File: nullAssignment.cpp
//
// MATLAB Coder version            : 3.4
// C/C++ source code generated on  : 22-Nov-2018 20:56:40
//

// Include Files
#include "rt_nonfinite.h"
#include "function_verticalwaypoint.h"
#include "nullAssignment.h"
#include "function_verticalwaypoint_emxutil.h"

// Function Declarations
static void b_nullAssignment(emxArray_real_T *x, const emxArray_int32_T *idx);

// Function Definitions

//
// Arguments    : emxArray_real_T *x
//                const emxArray_int32_T *idx
// Return Type  : void
//
static void b_nullAssignment(emxArray_real_T *x, const emxArray_int32_T *idx)
{
  emxArray_boolean_T *b;
  int nxin;
  int k0;
  int nxout;
  int k;
  emxArray_real_T *b_x;
  emxInit_boolean_T1(&b, 2);
  nxin = x->size[0];
  k0 = b->size[0] * b->size[1];
  b->size[0] = 1;
  b->size[1] = x->size[0];
  emxEnsureCapacity_boolean_T1(b, k0);
  nxout = x->size[0];
  for (k0 = 0; k0 < nxout; k0++) {
    b->data[k0] = false;
  }

  for (k = 1; k <= idx->size[0]; k++) {
    b->data[idx->data[k - 1] - 1] = true;
  }

  k0 = 0;
  for (k = 1; k <= b->size[1]; k++) {
    k0 += b->data[k - 1];
  }

  nxout = x->size[0] - k0;
  k0 = -1;
  for (k = 1; k <= nxin; k++) {
    if ((k > b->size[1]) || (!b->data[k - 1])) {
      k0++;
      x->data[k0] = x->data[k - 1];
    }
  }

  emxFree_boolean_T(&b);
  if (1 > nxout) {
    nxout = 0;
  }

  emxInit_real_T1(&b_x, 1);
  k0 = b_x->size[0];
  b_x->size[0] = nxout;
  emxEnsureCapacity_real_T1(b_x, k0);
  for (k0 = 0; k0 < nxout; k0++) {
    b_x->data[k0] = x->data[k0];
  }

  k0 = x->size[0];
  x->size[0] = b_x->size[0];
  emxEnsureCapacity_real_T1(x, k0);
  nxout = b_x->size[0];
  for (k0 = 0; k0 < nxout; k0++) {
    x->data[k0] = b_x->data[k0];
  }

  emxFree_real_T(&b_x);
}

//
// Arguments    : emxArray_real_T *x
//                const emxArray_int32_T *idx
// Return Type  : void
//
void c_nullAssignment(emxArray_real_T *x, const emxArray_int32_T *idx)
{
  int nrowx;
  emxArray_boolean_T *b;
  int nrows;
  int i;
  int loop_ub;
  emxArray_real_T *b_x;
  int k;
  nrowx = x->size[0];
  if (idx->size[0] == 1) {
    nrows = x->size[0] - 1;
    for (loop_ub = 0; loop_ub < 3; loop_ub++) {
      for (i = idx->data[0]; i < nrowx; i++) {
        x->data[(i + x->size[0] * loop_ub) - 1] = x->data[i + x->size[0] *
          loop_ub];
      }
    }
  } else {
    emxInit_boolean_T1(&b, 2);
    i = b->size[0] * b->size[1];
    b->size[0] = 1;
    b->size[1] = x->size[0];
    emxEnsureCapacity_boolean_T1(b, i);
    loop_ub = x->size[0];
    for (i = 0; i < loop_ub; i++) {
      b->data[i] = false;
    }

    for (k = 1; k <= idx->size[0]; k++) {
      b->data[idx->data[k - 1] - 1] = true;
    }

    nrows = 0;
    for (k = 1; k <= b->size[1]; k++) {
      nrows += b->data[k - 1];
    }

    nrows = x->size[0] - nrows;
    i = 0;
    for (k = 1; k <= nrowx; k++) {
      if ((k > b->size[1]) || (!b->data[k - 1])) {
        for (loop_ub = 0; loop_ub < 3; loop_ub++) {
          x->data[i + x->size[0] * loop_ub] = x->data[(k + x->size[0] * loop_ub)
            - 1];
        }

        i++;
      }
    }

    emxFree_boolean_T(&b);
  }

  if (1 > nrows) {
    loop_ub = 0;
  } else {
    loop_ub = nrows;
  }

  emxInit_real_T(&b_x, 2);
  i = b_x->size[0] * b_x->size[1];
  b_x->size[0] = loop_ub;
  b_x->size[1] = 3;
  emxEnsureCapacity_real_T(b_x, i);
  for (i = 0; i < 3; i++) {
    for (nrows = 0; nrows < loop_ub; nrows++) {
      b_x->data[nrows + b_x->size[0] * i] = x->data[nrows + x->size[0] * i];
    }
  }

  i = x->size[0] * x->size[1];
  x->size[0] = b_x->size[0];
  x->size[1] = 3;
  emxEnsureCapacity_real_T(x, i);
  for (i = 0; i < 3; i++) {
    loop_ub = b_x->size[0];
    for (nrows = 0; nrows < loop_ub; nrows++) {
      x->data[nrows + x->size[0] * i] = b_x->data[nrows + b_x->size[0] * i];
    }
  }

  emxFree_real_T(&b_x);
}

//
// Arguments    : const emxArray_real_T *x
//                const emxArray_int32_T *idx
//                emxArray_real_T *b_x
// Return Type  : void
//
void nullAssignment(const emxArray_real_T *x, const emxArray_int32_T *idx,
                    emxArray_real_T *b_x)
{
  int i2;
  int loop_ub;
  i2 = b_x->size[0];
  b_x->size[0] = x->size[0];
  emxEnsureCapacity_real_T1(b_x, i2);
  loop_ub = x->size[0];
  for (i2 = 0; i2 < loop_ub; i2++) {
    b_x->data[i2] = x->data[i2];
  }

  b_nullAssignment(b_x, idx);
}

//
// File trailer for nullAssignment.cpp
//
// [EOF]
//
