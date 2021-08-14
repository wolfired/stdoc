/**
 * @file stdoc_io.h
 * @author LinkWu (wjianl@qq.com)
 * @brief 封装 @b stdio.h , 增加中文文档
 * @version 0.0.1
 * @date 2021-08-13
 *
 * @copyright Copyright (c) 2021
 *
 * @defgroup stdio stdio.h
 * @{
 * @defgroup operations_on_files Operations on files
 * @defgroup file_access File access
 * @defgroup formatted_input_output Formatted input/output
 * @defgroup character_input_output Character input/output
 * @defgroup direct_input_output Direct input/output
 * @defgroup file_positioning File positioning
 * @defgroup error_handling Error-handling
 * @} end group stdio
 */

#ifndef STDOC_IO_H
#define STDOC_IO_H

/**
 * @brief @b 删除文件/目录
 * @ingroup operations_on_files
 *
 * @param[in] filename 文件/目录名
 *
 * @return int
 * @retval 0 成功
 * @retval !0 失败, 多数C标准库实现会通过 @b errno 提供系统特定的错误码
 */
int stdoc_remove(const char* filename);

/**
 * @brief @b 修改文件/目录名
 * @ingroup operations_on_files
 *
 * * 如果指定不同目录则执行移动操作
 * * 如果 @p newname 已存在, 操作要么失败要么覆盖, 具体由特定系统与C标准库实现决定
 *
 * @param[in] oldname 文件/目录原名
 * @param[in] newname 文件/目录新名
 *
 * @return int
 * @retval 0 成功
 * @retval !0 失败, 多数C标准库实现会通过 @b errno 提供系统特定的错误码
 */
int stdoc_rename(const char* oldname, const char* newname);

/**
 * @brief @b 创建临时文件
 * @ingroup operations_on_files
 *
 * * 临时文件在调用 @b fclose 或程序正常退出后自动删除
 *
 * @return FILE*
 * @retval !NULL 成功, 指向临时文件的流指针
 * @retval NULL 失败
 */
FILE* stdoc_tmpfile();

/**
 * @brief @b 生成临时文件名
 * @ingroup operations_on_files
 * @deprecated
 *
 * @param[out] str
 *
 * @arg  @b !NULL 指定存放临时文件名的字符数组, 其长度至少 @b L_tmpnam
 * @code{.c}
 *
 *   char buff[L_tmpnam];
 *   stdoc_tmpnam(buff);
 *
 * @endcode
 *
 * @arg  @b NULL 不指定存放临时文件名的字符数组
 *
 * @return char*
 * @retval !NULL 成功
 * * @b NULL == @b str , 返回内部字符数组指定
 * * @b NULL != @b str , 返回 @b str
 * @retval NULL 失败
 */
char* stdoc_tmpnam(char* str);

/**
 * @brief @b 关闭文件
 * @ingroup file_access
 *
 * @param[in] stream
 * @return int
 * @retval 0 成功
 * @retval EOF 失败
 */
int stdoc_fclose(FILE* stream);

/**
 * @brief @b 冲刷流
 * @ingroup file_access
 *
 * @param[in] stream
 * @return int
 * @retval 0 成功
 * @retval EOF 失败,  可通过 @b stdoc_ferror 检查 @b 错误指示符
 *
 * @see stdoc_ferror
 */
int stdoc_fflush(FILE* stream);

/**
 * @brief //TODO @b 打开文件
 * @ingroup file_access
 *
 * @param filename
 * @param mode
 * @return FILE*
 */
FILE* stdoc_fopen(const char* filename, const char* mode);

/**
 * @brief //TODO @b 使用新文件或模式重新打开流
 * @ingroup file_access
 *
 * @param filename
 * @param mode
 * @param stream
 * @return FILE*
 */
FILE* stdoc_freopen(const char* filename, const char* mode, FILE* stream);

/**
 * @brief //TODO @b 设置流缓冲区
 * @ingroup file_access
 *
 * @param stream
 * @param buffer
 */
void stdoc_setbuf(FILE* stream, char* buffer);

/**
 * @brief //TODO @b 更换流缓冲区
 * @ingroup file_access
 *
 * @param stream
 * @param buffer
 * @param mode
 * @param size
 * @return int
 */
int stdoc_setvbuf(FILE* stream, char* buffer, int mode, size_t size);

/**
 * @brief //TODO @b 格式化数据并写入流
 * @ingroup formatted_input_output
 *
 * @param stream
 * @param format
 * @param ...
 * @return int
 */
int stdoc_fprintf(FILE* stream, const char* format, ...);

/**
 * @brief //TODO @b 从流中读取格式化数据
 * @ingroup formatted_input_output
 *
 * @param stream
 * @param format
 * @param ...
 * @return int
 */
int stdoc_fscanf(FILE* stream, const char* format, ...);

/**
 * @brief //TODO @b 打印格式化数据到stdout
 * @ingroup formatted_input_output
 *
 * @param format
 * @param ...
 * @return int
 */
int stdoc_printf(const char* format, ...);

/**
 * @brief //TODO @b 从stdin中读取格式化数据
 * @ingroup formatted_input_output
 *
 * @param format
 * @param ...
 * @return int
 */
int stdoc_scanf(const char* format, ...);

/**
 * @brief //TODO @b 根据变长参数列表格式化数据并写入流
 * @ingroup formatted_input_output
 *
 * @param stream
 * @param format
 * @param arg
 * @return int
 */
int stdoc_vfprintf(FILE* stream, const char* format, va_list arg);

/**
 * @brief //TODO @b 根据变长参数列表从流中读取格式化数据
 * @ingroup formatted_input_output
 *
 * @param stream
 * @param format
 * @param arg
 * @return int
 */
int stdoc_vfscanf(FILE* stream, const char* format, va_list arg);

/**
 * @brief //TODO @b 根据变长参数列表打印格式化数据到 stdout
 * @ingroup formatted_input_output
 *
 * @param format
 * @param arg
 * @return int
 */
int stdoc_vprintf(const char* format, va_list arg);

/**
 * @brief //TODO @b 根据变长参数列表从stdin中读取格式化数据
 * @ingroup formatted_input_output
 *
 * @param format
 * @param arg
 * @return int
 */
int stdoc_vscanf(const char* format, va_list arg);

/**
 * @brief //TODO @b 获取当前流位置
 * @ingroup file_positioning
 *
 * @param stream
 * @param pos
 * @return int
 */
int stdoc_fgetpos(FILE* stream, fpos_t* pos);

/**
 * @brief //TODO @b 重定位流位置指示符
 * @ingroup file_positioning
 *
 * @param stream
 * @param offset
 * @param origin
 * @return int
 */
int stdoc_fseek(FILE* stream, long int offset, int origin);

/**
 * @brief //TODO @b 设置流位置指示符
 * @ingroup file_positioning
 *
 * @param stream
 * @param pos
 * @return int
 */
int stdoc_fsetpos(FILE* stream, const fpos_t* pos);

/**
 * @brief //TODO @b 获取当前流位置
 * @ingroup file_positioning
 *
 * @param stream
 * @return long int
 */
long int stdoc_ftell(FILE* stream);

/**
 * @brief //TODO @b 设置流位置到开始
 * @ingroup file_positioning
 *
 * @param stream
 */
void stdoc_rewind(FILE* stream);

/**
 * @brief //TODO @b 清除错误指示符
 * @ingroup error_handling
 *
 * @param stream
 */
void stdoc_clearerr(FILE* stream);

/**
 * @brief //TODO @b 检查文件结束指示符
 * @ingroup error_handling
 *
 * @param stream
 * @return int
 * @retval 0 未设置文件结束指示符
 * @retval !0 已设置文件结束指示符
 */
int stdoc_feof(FILE* stream);

/**
 * @brief @b 检查错误指示符
 * @ingroup error_handling
 *
 * @param[in] stream
 * @return int
 * @retval 0
 * @retval !0
 */
int stdoc_ferror(FILE* stream);

/**
 * @brief @b 打印错误信息
 * @ingroup error_handling
 *
 * * 把 @b errno 转换成可读文本, 打印到 @b stderr(标准错误流), 可通过 @b str 指定自定义前置提示文本
 * * @b errno 是一个内部变量
 * * 本函数产生的错误信息是 @b 平台依赖 的
 * * @b str 不为 @b null , 则先打印 @b str 然后接一个冒号(:)再接一个空格
 * * 错误信息的最后会加上一个换行符('\\n')
 * * 可能产生 @b errno 的函数被调用后, 就立即调用 @b stdoc_perror 以防止 @b errno 被覆盖
 *
 * @param str
 */
void stdoc_perror(const char* str);

#endif
