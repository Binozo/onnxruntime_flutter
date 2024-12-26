// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once

#include <stdint.h>
#include <stddef.h>

#if defined(__CYGWIN__) || defined(__MINGW32__)
#define ORTX_API_CALL __stdcall
#elif defined(_WIN32)
#define ORTX_API_CALL _stdcall
#define ORTX_MUST_USE_RESULT
#elif __APPLE__
#define ORTX_API_CALL
// To make symbols visible on macOS/iOS
#define ORTX_MUST_USE_RESULT __attribute__((warn_unused_result))
#else
#define ORTX_API_CALL
#define ORTX_MUST_USE_RESULT
#endif

typedef enum {
  kOrtxOK = 0,
  kOrtxErrorInvalidArgument = 1,
  kOrtxErrorOutOfMemory = 2,
  kOrtxErrorInvalidFile = 3,
  kOrtxErrorCorruptData = 4,
  kOrtxErrorNotFound = 5,
  kOrtxErrorAlreadyExists = 6,
  kOrtxErrorOutOfRange = 7,
  kOrtxErrorNotImplemented = 8,
  kOrtxErrorInternal = 9,
  kOrtxErrorUnknown = 1000
} extError_t;

typedef enum {
  kOrtxUnknownType = 0,
  kOrtxFloat = 1,
  kOrtxDouble = 2,
  kOrtxString = 3,
  kOrtxBool = 4,
  kOrtxComplex64 = 5,
  kOrtxComplex128 = 6,
  kOrtxBFloat16 = 7,
  kOrtxUint8 = 8,
  kOrtxInt8 = 9,
  kOrtxUint16 = 10,
  kOrtxInt16 = 11,
  kOrtxInt32 = 12,
  kOrtxUint32 = 13,
  kOrtxInt64 = 14,
  kOrtxUint64 = 15,
  kOrtxFloat16 = 16
} extDataType_t;