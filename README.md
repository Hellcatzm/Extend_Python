# Extend Python with C
实际上ctypes、Python C API或者基于API的Cython，逻辑都是：<br>
`接收Python对象`->`转换为C对象`->`调用C函数`->`返回值转换为Python对象`->`返回`<br>
的流程，较为值得关切的几点是：<br>
指针传参问题<br>
数组传递问题<br>
结构体传递问题<br>
高级一点情况会考虑如何绕过GIL提升速度<br>
