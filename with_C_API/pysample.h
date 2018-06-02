/* pysample.h */
#include "Python.h"
#include "sample.h"
#ifdef __cplusplus
extern "C" {
#endif

/* Public API Table */
/* 这里最重要的部分是函数指针表 _PointAPIMethods.
   它会在导出模块时被初始化，然后导入模块时被查找到。 */
typedef struct {
  Point *(*aspoint)(PyObject *);
  PyObject *(*frompoint)(Point *, int);
} _PointAPIMethods;

#ifndef PYSAMPLE_MODULE  //<---pysample.c:4
/* Method table in external module */
static _PointAPIMethods *_point_api = 0;

/* Import the API table from sample, import_sample() 被用来指向胶囊导入并初始化这个指针 */
static int import_sample(void) {  //<---ptexample.c:46
	// 需提供属性名（比如sample._point_api），会一次性找到胶囊对象并提取出指针来。
  _point_api = (_PointAPIMethods *) PyCapsule_Import("sample._point_api",0);  //<---pysample.c:250
  return (_point_api != NULL) ? 1 : 0;
}

/* Macros to implement the programming interface */
#define PyPoint_AsPoint(obj) (_point_api->aspoint)(obj)
#define PyPoint_FromPoint(obj) (_point_api->frompoint)(obj)
#endif

#ifdef __cplusplus
}
#endif
