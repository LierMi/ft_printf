# ft_printf

A reimplementation of C's `printf`, packaged as a static library (`libftprintf.a`). It handles the common conversions and returns the number of characters written — matching the real `printf` **byte for byte**, including its return value.

```c
int ft_printf(const char *format, ...);
```

## Supported conversions

| Specifier | Prints |
|-----------|--------|
| `%c` | a single character |
| `%s` | a string (`(null)` if the pointer is `NULL`) |
| `%d` / `%i` | a signed decimal integer |
| `%u` | an unsigned decimal integer |
| `%x` / `%X` | an unsigned integer in lower / upper-case hexadecimal |
| `%p` | a pointer address |
| `%%` | a literal `%` |

## How it works

`ft_printf` scans the format string character by character. On a `%` it reads the following specifier and dispatches to the matching handler (`ft_handle_format`), pulling the next argument with `va_arg`. Everything else is printed as-is.

A running counter tracks the total number of characters written and becomes the return value. If a write fails, the counter is set to `-1` and output stops, so the return value reports the error the way the real `printf` does.

One cross-platform detail: a `NULL` pointer (`%p`) is printed as `(nil)` on Linux and `0x0` on macOS, matching each platform's own libc.

## Build & use

```bash
make          # builds libftprintf.a
```

Link it into your program and include the header:

```bash
cc main.c -L. -lftprintf -o main
```

```c
#include "ft_printf.h"

int main(void)
{
    int len = ft_printf("Hello %s, %d in hex is %x\n", "world", 255, 255);
    ft_printf("(printed %d characters)\n", len);
    return (0);
}
```

## Verified

- Compiles clean with `-Wall -Wextra -Werror`.
- Output is **byte-for-byte identical to the system `printf`** across `%c %s %d %i %u %x %X %p %%`, including edge cases: `INT_MIN`, a `NULL` string (`(null)`), a `NULL` pointer (`(nil)`), zero values, and large unsigned values.
- The return value (characters written) matches `printf` in every tested case.

---

# ft_printf

C 语言 `printf` 的重新实现，打包成静态库 `libftprintf.a`。支持常用转换符，并返回输出的字符数——与真实 `printf` **逐字节一致**，连返回值都对得上。

```c
int ft_printf(const char *format, ...);
```

## 支持的转换符

| 转换符 | 输出 |
|--------|------|
| `%c` | 单个字符 |
| `%s` | 字符串（指针为 `NULL` 时输出 `(null)`） |
| `%d` / `%i` | 有符号十进制整数 |
| `%u` | 无符号十进制整数 |
| `%x` / `%X` | 无符号整数的小写 / 大写十六进制 |
| `%p` | 指针地址 |
| `%%` | 字面量 `%` |

## 实现思路

`ft_printf` 逐字符扫描格式串，遇到 `%` 就读取后面的转换符，分发给对应的处理函数（`ft_handle_format`），并用 `va_arg` 取下一个参数；其余字符原样输出。

一个计数器统计累计输出的字符数，作为返回值。若写入失败，计数器置为 `-1` 并停止输出，使返回值能像真实 `printf` 一样反映错误。

一个跨平台细节：`%p` 的 `NULL` 指针在 Linux 上输出 `(nil)`、在 macOS 上输出 `0x0`，与各平台自带 libc 行为一致。

## 编译与使用

```bash
make          # 生成 libftprintf.a
```

链接进自己的程序并引入头文件：

```bash
cc main.c -L. -lftprintf -o main
```

```c
#include "ft_printf.h"

int main(void)
{
    int len = ft_printf("Hello %s, %d in hex is %x\n", "world", 255, 255);
    ft_printf("(printed %d characters)\n", len);
    return (0);
}
```

## 已验证

- `-Wall -Wextra -Werror` 编译零警告。
- 在 `%c %s %d %i %u %x %X %p %%` 上输出与系统 `printf` **逐字节完全一致**，含边界情况：`INT_MIN`、`NULL` 字符串（`(null)`）、`NULL` 指针（`(nil)`）、零值、大无符号数。
- 返回值（输出字符数）在所有测试用例中与 `printf` 一致。
