/*
 * File: _coder_HIGHT2SLOPE_info.c
 *
 * MATLAB Coder version            : 3.4
 * C/C++ source code generated on  : 26-Nov-2018 14:23:41
 */

/* Include Files */
#include "_coder_HIGHT2SLOPE_info.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : const mxArray *
 */
const mxArray *emlrtMexFcnResolvedFunctionsInfo()
{
  const mxArray *nameCaptureInfo;
  const char * data[8] = {
    "789ced58316fd34018bd56a594a1a802816001c48004957290161258a893b8386a4a9bd495da5495ead8d7e4e89dedda8e4940886eac4c4cfc00c4c6c67f6086"
    "811f8018e10720e1d8b9d4091807129c1262c9babcbce8befb5e9edfd90663d9e53100c049e7fcfc1480ca05e01ed34d3ce341300eda8f4e7eac391ef3e1060f",
    "5adf4fb878dac77f72f0cb269635d54235cb0304abe87e959690e10055a2a8358da251ac4aaa25d675040c646ac4468acbec6282444c514ef301013b802efaa8"
    "1668508dcfe90a92f7d6aa141815f370b9c40f804f9fe701fd4f74a90f0cd067a68919bfc56fc38a4611dc432a340d192e39a32e59159d48aa8ad53214b2f704",
    "31be965b59e563b4b5be9d80fa935daecf3ffad777024cf9f0b985b07addea3115a887578f1a0ab6b182fa556fd287dbeb4dba58d1aa25820effef573dd6cb04"
    "d6f330e3b7b2b90de72faf9a06249a2c11b8cc89392e050bf1eb37122568691a296935882881049720952c2295a0a69b902914d31bf344e883276fb63f70d1fa",
    "2ed2febe5d3dff7e60fdd502e6ebd6776702ea31df31beb6592cf2650e1bfbf336e56f8a9b5cfe81e45bc76a489db075001ffe599f7f7bfed1f5fb2bbf7db9db"
    "af5c3d1ea8d37117379b0cedefa8e6783ab09e8719ffe73e6036a0ee3cd1f9e0e0f1d7d5c1e5dcb0d78b2ac7930ff3bbeb1bf3b712824d0ab733c9644e5b97c1",
    "28c7077dfdea01ebead66fe33edceeb7f6df7bc795056fbcdcba3f3fe851b78b21ba315ed61464c4b0f31067a81289613355c5c4caaace631c32b03cb0dc7fdb"
    "63bd4248ff8cff0ddf34ce59572f38cb04839d82356d14e53ef0ecddc7d13e7054f781b301f5980f19bf62efa7b95dc14e8af9f9bacc5335be5824c2681f18f4",
    "3eb013b0aefefaed5adf72ff52884e8cefc87dd3910ad5f4b44675c9c24e12ffabb9bf16d23fe37bcdfd1f048bde37af5f9c1eeaf73803ad1755ee5714dd286e"
    "3ce2e57222934bd4e7aa12974fa646b9ff7fe4fe9d857ef9ed54884e8cefc87da777d055df47f5fd0e1fd237e37bcd7b4728d721a37c1f8e7a51e57b3995aa2b",
    "89399e2fd6e2b6b024e2cca6511882fbfaef553257a5", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 7808U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/*
 * Arguments    : void
 * Return Type  : mxArray *
 */
mxArray *emlrtMexFcnProperties()
{
  mxArray *xResult;
  mxArray *xEntryPoints;
  const char * fldNames[4] = { "Name", "NumberOfInputs", "NumberOfOutputs",
    "ConstantInputs" };

  mxArray *xInputs;
  const char * b_fldNames[4] = { "Version", "ResolvedFunctions", "EntryPoints",
    "CoverageInfo" };

  xEntryPoints = emlrtCreateStructMatrix(1, 1, 4, fldNames);
  xInputs = emlrtCreateLogicalMatrix(1, 2);
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("HIGHT2SLOPE"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(2.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  xResult = emlrtCreateStructMatrix(1, 1, 4, b_fldNames);
  emlrtSetField(xResult, 0, "Version", emlrtMxCreateString(
    "9.3.0.713579 (R2017b)"));
  emlrtSetField(xResult, 0, "ResolvedFunctions", (mxArray *)
                emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

/*
 * File trailer for _coder_HIGHT2SLOPE_info.c
 *
 * [EOF]
 */
