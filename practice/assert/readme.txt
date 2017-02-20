产品代码中使用宏并不是好习惯，错误恢复永远比提示信息有效。

宏NDEBUG，如果包含<assert.h>的地方没有定义宏NDEBUG，那么该头文件就会将宏assert定义为活动形式。反之则定义为静止形式。
Ex.
宏assert定义为静止形式
#define NDEBUG
#include <assert.h>

宏assert定义为活动形式
#undef NDEBUG
#include <assert.h>

上述方法可以随时切换assert的状态，但当重新调试时需要手动更改。将NDEBUG的定义放在make文件中会更好。
Ex.
tassert:tassert
	gcc tassert.c -o tassert -D NDEBUG 或 gcc -DNDEBUG tassert.c -o tassert

.PHONY:clean
clean:
	-rm tassert

以上的命令写入makefile中相当于定义一个NDEBUG



#undef放在开头没有任何副作用，故可以用作良性取消定义
书本实现的assert.h见相应文件，书中给出了一种实现方式：
#define assert (test) if (!(test)) \
 fprintf (stderr, "Assertion failed: %s, file %s, line %i\n", \
  #test, __FILE__, __LINE__)	/*UNACEEPTABLE!*/
1、C语言标准库头文件在设计上是相互独立的，互相应该不会包含其他头文件。
2、宏不能直接调用库的任何输出函数。(不懂的部分：A program can define macros that rename any of the names from another header, provided it doesn't include that header. That mandates that the macro call a function with a secret name to do the actual output.
3、assert宏应该最终展开为一个void expression, 因为程序员很可能在他们的程序中写出像(assert(0 < x), x < y)这样的代码，而上面的实现版本中使用if语句显然不行，展开后会导致程序语法错误。

书中实现代码辅助宏_VAL与_STR
内置宏__LINE__并没有扩展成字符串字面量，它是一个十进制常量，所以先用_VAL将__LINE__替换成十进制常量，然后用_STR将十进制常量变为字符串字面量。至于二者的实现，在本章中未提及。

P.S. 我原来以为assert.h就算写出来也不能用，后面发现可以，原因在于其第一句#undef assert将系统中的宏取消了，所以可以使用自己的定义的文件，只需要加入进编译指令中即可。

