#include <stdarg.h>
#include <stdio.h>

#include "stdoc_io.h"

int stdoc_remove(const char* filename) { return remove(filename); }

int stdoc_rename(const char* oldname, const char* newname) { return rename(oldname, newname); }

FILE* stdoc_tmpfile() { return tmpfile(); };

char* stdoc_tmpnam(char* str) { return tmpnam(str); };

int stdoc_fclose(FILE* stream) { return fclose(stream); }

int stdoc_fflush(FILE* stream) { return fflush(stream); }

FILE* stdoc_fopen(const char* filename, const char* mode) { return fopen(filename, mode); }

FILE* stdoc_freopen(const char* filename, const char* mode, FILE* stream) { return freopen(filename, mode, stream); }

void stdoc_setbuf(FILE* stream, char* buffer) { setbuf(stream, buffer); }

int stdoc_setvbuf(FILE* stream, char* buffer, int mode, size_t size) { return setvbuf(stream, buffer, mode, size); }

int stdoc_fprintf(FILE* stream, const char* format, ...) {
    va_list arg;
    va_start(arg, format);
    int result = stdoc_vfprintf(stream, format, arg);
    va_end(arg);
    return result;
}

int stdoc_fscanf(FILE* stream, const char* format, ...) {
    va_list arg;
    va_start(arg, format);
    int result = stdoc_vfscanf(stream, format, arg);
    va_end(arg);
    return result;
}

int stdoc_printf(const char* format, ...) {
    va_list arg;
    va_start(arg, format);
    int result = stdoc_vprintf(format, arg);
    va_end(arg);
    return result;
}

int stdoc_scanf(const char* format, ...) {
    va_list arg;
    va_start(arg, format);
    int result = stdoc_vscanf(format, arg);
    va_end(arg);
    return result;
}

int stdoc_vfprintf(FILE* stream, const char* format, va_list arg) { return vfprintf(stream, format, arg); }

int stdoc_vfscanf(FILE* stream, const char* format, va_list arg) { return vfscanf(stream, format, arg); }

int stdoc_vprintf(const char* format, va_list arg) { return vprintf(format, arg); }

int stdoc_vscanf(const char* format, va_list arg) { return vscanf(format, arg); }

int stdoc_fgetpos(FILE* stream, fpos_t* pos) { return fgetpos(stream, pos); }

int stdoc_fseek(FILE* stream, long int offset, int origin) { return fseek(stream, offset, origin); }

int stdoc_fsetpos(FILE* stream, const fpos_t* pos) { return fsetpos(stream, pos); }

long int stdoc_ftell(FILE* stream) { return ftell(stream); }

void stdoc_rewind(FILE* stream) { rewind(stream); }

void stdoc_clearerr(FILE* stream) { clearerr(stream); }

int stdoc_feof(FILE* stream) { return feof(stream); }

int stdoc_ferror(FILE* stream) { return ferror(stream); }

void stdoc_perror(const char* str) { perror(str); }
