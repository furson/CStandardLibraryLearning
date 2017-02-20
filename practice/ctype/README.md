字符判断 -> 程序过长 -> 引入标准库字符判断函数 -> 程序时间决定于判断函数 -> 引入宏代替函数

{
	引入宏的问题：
	1、展开巨大
	2、展开为subexpression（使用圆括号）
	3、某些参数可能不执行或执行多次
}

转换表：宏集合
#define _XXXMASK 0x...
#define isxxx(c) (_Ctyptab[c] & _XXXMASK)

_Ctypetab：转换表索引
弊端：不在定义域内的宏参数可能访问转换表之外的空间
isxxx(c)预想处理的是unsiged char 或 EOF
区域设置：详见第六章，可通过setlocale改变
##Usage
字符类别：
数字 0 - 9
十六进制数字 0 - 9 A - F a - f
小写字母 a - z（"c" locale）
大写字母 A - Z（"c" locale）
字母 小写字母或大写字母 （"c" locale）
字母数字 字母或数字
图形字符 占据一个打印位置
标点符号 非字母的图形字符，至少为29个
打印字符 图形字符或空格符' '
空格 空格符' '和5个标准控制字符 FF, NL, CR, HT, VT
控制字符 FF, NL, CR, HT, VT, BS, BEL
见image2-1
isalnum "alphanumeric"
isalpha "alphabetic"
iscntrl "controlbyte" FF, NL, CR, HT, VT, BS, BEL
isdigit
isgraph characters that display when printed
islower (Don't assume that every lowercase letter has a corresponding uppercate letter, or conversely.
isprint characters that occupy one print position when written to a printer
ispunct an open-ended set of characters, even in the "c" locale.
isspace In the "c" locale, you use this function to identify any of the characters that alter the print position, when written to a display device, without displaying a graphic.
isupper
isxdigit
tolower Don't assume that you can convert an uppercase letter to its corresponding lowercase letter simply by adding or subtracting a constant value. (only happens in ASCII and EBCDIC)
toupper
##implementation
