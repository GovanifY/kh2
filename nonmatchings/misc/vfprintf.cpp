typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;
typedef signed long long s64;

typedef struct {
    char* iov_base;
    int iov_len;
} iovec_ee;

typedef struct {
    unsigned char _pad0[12];
    u16 _flags;
    s16 _file;
    void* _data;
} FILE_ee;

extern "C" {
extern void** func_003037e8(void);
extern int func_003015f8(FILE_ee* fp);
extern int func_002ffc50(FILE_ee* fp, const char* fmt, u32* ap);
extern int func_002ffc08(FILE_ee* fp, void* uio);
extern int func_00303958(const void* a, int* b, const char* c, const void* d, int* e);
extern int func_002ff3fc(const char* s);
extern char* func_00303988(const char* s, int ch, int maxlen);
extern char* func_003012d8(void* reent, u64 d, int ndig, int flags, char* buf,
                           int* decpt, int fmtch, int* sign);
extern int func_00301480(char* buf, int exp, int fmtch);
extern int func_00304d68(u64 d);
extern int func_00304db0(u64 d);
extern int func_003142e0(u64 d, int zero);
extern u64 func_00313498(u64 x, int base);
extern u64 func_00312db8(u64 x, int base);

extern const char D_00307928[];
extern const char D_00307938[];
extern const char D_00307948[];
extern const char D_00307950[];
extern const char D_00307968[];
extern const char D_00307970[];
extern const char D_00307990[];
extern const void* D_00305c48;
extern const void* D_003060b4;
}

enum {
    FL_ALT    = 0x0001,
    FL_PREFIX = 0x0002,
    FL_LADJUST= 0x0004,
    FL_LONGDBL= 0x0008,
    FL_LONG   = 0x0010,
    FL_SHORT  = 0x0040,
    FL_DOT    = 0x0080,
    FL_FPT    = 0x0100
};

#define PRINT(ptr, len)                                          \
    do {                                                         \
        ((iovec_ee*)iov_ptr)->iov_base = (char*)(ptr);           \
        ((iovec_ee*)iov_ptr)->iov_len = (len);                   \
        iov_ptr += 8;                                            \
        F.suio_iovcnt++;                                         \
        F.suio_resid += (len);                                   \
        if (F.suio_iovcnt >= 8) {                                \
            if (func_002ffc08(fp, &F.suio_iov) != 0) goto error;\
            iov_ptr = (char*)iov;                                \
        }                                                        \
    } while (0)

#define PAD(n, tbl)           \
    do {                      \
        int _n;               \
        _n = (n);             \
        while (_n > 16) {     \
            PRINT((tbl), 16); \
            _n -= 16;         \
        }                     \
        if (_n > 0) {         \
            PRINT((tbl), _n); \
        }                     \
    } while (0)

extern "C" int func_002ffd78(void* reent, FILE_ee* fp, const char* fmt,
                             u32* ap) {
    /* Stack layout to match target:
     * sp+0:   F.sign
     * sp+1:   F.dtoa_buf[15]
     * sp+16:  F.expbuf[16]
     * sp+32:  F.suio_iov
     * sp+36:  F.suio_iovcnt
     * sp+40:  F.suio_resid
     * sp+48:  iov[8]  (8-byte aligned)
     * sp+112: numbuf[348] (352-byte GCC slot)
     * sp+464: ox[2]   (16-byte GCC slot)
     * sp+480: slot480
     * sp+484: slot484
     * sp+488: slot488 (decpt)
     * sp+492: pad492  (sign)
     * sp+496: save_reent
     * sp+500: save_fp
     * sp+504: save_ap
     * sp+508: flags
     * sp+512: nprinted
     * sp+516: width
     * sp+520: localech
     * sp+528: ulval (u64)
     * sp+536: slot536
     * sp+540: prec
     * sp+544: xdigtab
     * sp+560: saved regs
     */
    struct {
        char sign;         /* sp+0 */
        char dtoa_buf[15]; /* sp+1..15 */
        char expbuf[16];   /* sp+16..31 */
        /* sp+32: suio packed here */
        iovec_ee* suio_iov;   /* sp+32 */
        int suio_iovcnt;      /* sp+36 */
        int suio_resid;       /* sp+40 */
        int suio_pad;         /* sp+44 - padding to make iov 8-byte aligned at sp+48 */
    } F;

    iovec_ee iov[8];   /* sp+48..111 */

    char numbuf[348];  /* sp+112..459 (GCC allocates 352-byte slot) */
    char ox[2];        /* sp+464..465 (GCC allocates 16-byte slot) */

    int slot480;       /* sp+480 */
    int slot484;       /* sp+484 */
    int slot488;       /* sp+488 - decpt output from func_003012d8 */
    int pad492;        /* sp+492 - sign output from func_003012d8 */
    int save_reent;    /* sp+496 */
    int save_fp;       /* sp+500 */
    int save_ap;       /* sp+504 */
    int flags;         /* sp+508 */
    int nprinted;      /* sp+512 */
    int width;         /* sp+516 */
    int localech;      /* sp+520 */
    u64 ulval;         /* sp+528 */
    int slot536;       /* sp+536 */
    int prec;          /* sp+540 */
    int xdigtab;       /* sp+544 */

    int size;
    int realsz;
    int fieldsz;
    int ch;

    char* cp;
    const char* start;
    char* iov_ptr;
    void** tmp;

    save_reent = (int)reent;
    save_fp = (int)fp;
    save_ap = (int)ap;

    tmp = func_003037e8();
    localech = (int)tmp[0];

    ulval = 0;
    slot480 = 0;
    slot484 = 0;
    xdigtab = 0;
    slot536 = 0;

    if ((fp->_flags & 0x8) == 0 || fp->_data == 0) {
        if (func_003015f8(fp) != 0) {
            return -1;
        }
    }

    if ((fp->_flags & 0x1a) == 0x0a) {
        if (fp->_file >= 0) {
            return func_002ffc50(fp, fmt, ap);
        }
    }

    F.suio_resid = 0;
    F.suio_iov = iov;
    F.suio_iovcnt = 0;
    iov_ptr = (char*)iov;
    nprinted = 0;

again:
    start = fmt;

    /* Scan for '%' or null using func_00303958 per character */
    {
        int res;
        for (;;) {
            res = func_00303958(D_00305c48, &slot480, fmt, D_003060b4, &slot484);
            if (res <= 0) {
                /* null terminator */
                {
                    int n = (int)(fmt - start);
                    if (n != 0) {
                        PRINT((char*)start, n);
                        nprinted += n;
                    }
                }
                goto finish;
            }
            if (slot480 == '%') break;
            fmt += res;
        }
    }

    /* found '%', print literal prefix */
    {
        int n = (int)(fmt - start);
        if (n != 0) {
            PRINT((char*)start, n);
            nprinted += n;
        }
    }

    fmt++;  /* advance past '%' */
    F.sign = 0;
    flags = 0;
    prec = 0;
    width = 0;

reswitch:
    ch = (unsigned char)*fmt++;
    switch (ch - ' ') {
        case 0: /* ' ' */
            if (F.sign == 0) F.sign = ' ';
            goto reswitch;

        case 3: /* '#' */
            flags |= FL_ALT;
            goto reswitch;

        case 10: /* '*' */
            width = *(s32*)ap;
            ap += 2;
            if (width < 0) {
                width = -width;
                flags |= FL_LADJUST;
            }
            goto reswitch;

        case 11: /* '+' */
            F.sign = '+';
            goto reswitch;

        case 13: /* '-' */
            flags |= FL_LADJUST;
            goto reswitch;

        case 14: /* '.' */
            flags |= FL_DOT;
            prec = 0;
            if (*fmt == '*') {
                fmt++;
                prec = *(s32*)ap;
                ap += 2;
                if (prec < 0) prec = -1;
            } else {
                while ((unsigned)(*fmt - '0') < 10U) {
                    prec = prec * 10 + (*fmt - '0');
                    fmt++;
                }
            }
            goto reswitch;

        case 16: /* '0' */
            if (F.sign == 0) F.sign = '0';
            goto reswitch;

        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
            width = ch - '0';
            while ((unsigned)(*fmt - '0') < 10U) {
                width = width * 10 + (*fmt - '0');
                fmt++;
            }
            goto reswitch;

        case 36: /* 'D' */
            flags |= FL_LONG;
            ch = 'd';
            goto signed_common;

        case 44: /* 'L' */
            flags |= FL_LONGDBL;
            goto reswitch;

        case 56: /* 'X' */
            xdigtab = (int)D_00307950;
            goto hex_common;

        case 67: /* 'c' */
            ox[0] = (char)(*(u32*)ap);
            ap += 2;
            cp = ox;
            size = 1;
            F.sign = 0;
            goto string_common;

        case 68: /* 'd' */
        case 73: /* 'i' */
        signed_common:
            if (flags & FL_LONG) {
                ulval = *(s64*)ap;
                ap += 2;
            } else if (flags & FL_SHORT) {
                ulval = (s16)(*(s32*)ap);
                ap += 2;
            } else {
                ulval = (s32)(*(s32*)ap);
                ap += 2;
            }
            if ((s64)ulval < 0) {
                F.sign = '-';
                ulval = (u64)(-(s64)ulval);
            }
            goto number_base10;

        case 69: /* 'e' */
        case 70: /* 'f' */
        case 71: /* 'g' */
        case 37: /* 'E' */
        case 39: /* 'G' */
            if (prec < 0) {
                if (ch == 'g' || ch == 'G')
                    prec = 1;
                else
                    prec = 6;
            }

            ulval = *(u64*)ap;
            ap += 2;

            if (func_00304d68(ulval)) {
                if (func_003142e0(ulval, 0) < 0) F.sign = '-';
                cp = (char*)D_00307968;
                size = 3;
                F.sign = 0;
                goto string_common;
            }

            if (func_00304db0(ulval)) {
                cp = (char*)D_00307970;
                size = 3;
                F.sign = 0;
                goto string_common;
            }

            flags |= FL_FPT;
            cp = func_003012d8((void*)save_reent, ulval, prec, flags,
                               F.dtoa_buf, &slot488, ch, &pad492);
            if (pad492) F.sign = '-';

            if ((ch == 'g' || ch == 'G') && (slot488 < -3 || slot488 > prec)) {
                ch = (ch == 'g') ? 'e' : 'E';
            }

            if (ch == 'e' || ch == 'E') {
                int ndig = slot488 - 1;
                slot536 = func_00301480(F.expbuf, ndig, ch);
                if (pad492 < 2)
                    size = slot536 + pad492;
                else
                    size = slot536;
                goto string_common;
            }

            size = func_002ff3fc(cp);
            goto string_common;

        case 72: /* 'h' */
            flags |= FL_SHORT;
            goto reswitch;

        case 76: /* 'l' */
            flags |= FL_LONG;
            if (*fmt == 'l') {
                fmt++;
                flags |= FL_LONG;
            }
            goto reswitch;

        case 78: /* 'n' */
            {
                void* np = *(void**)ap;
                ap += 2;
                if (flags & FL_SHORT)
                    *(s16*)np = (s16)nprinted;
                else
                    *(s32*)np = (s32)nprinted;
            }
            goto again;

        case 79: /* 'o' */
            if (flags & FL_LONG) {
                ulval = *(u64*)ap;
                ap += 2;
            } else if (flags & FL_SHORT) {
                ulval = (u16)(*(u32*)ap);
                ap += 2;
            } else {
                ulval = *(u32*)ap;
                ap += 2;
            }
            goto number_base8;

        case 80: /* 'p' */
            ulval = *(u32*)ap;
            ap += 2;
            flags |= FL_PREFIX;
            xdigtab = (int)D_00307948;
            goto number_base16;

        case 81: /* 'q' */
            flags |= FL_LONG;
            goto reswitch;

        case 83: /* 's' */
            cp = *(char**)ap;
            ap += 2;
            if (cp == 0) cp = (char*)D_00307990;
            if (prec >= 0) {
                char* endp = func_00303988(cp, 0, prec);
                if (endp)
                    size = (int)(endp - cp);
                else
                    size = prec;
            } else {
                size = func_002ff3fc(cp);
            }
            goto string_common;

        case 85: /* 'u' */
            if (flags & FL_LONG) {
                ulval = *(u64*)ap;
                ap += 2;
            } else if (flags & FL_SHORT) {
                ulval = (u16)(*(u32*)ap);
                ap += 2;
            } else {
                ulval = *(u32*)ap;
                ap += 2;
            }
            goto number_base10;

        case 88: /* 'x' */
            xdigtab = (int)D_00307948;
        hex_common:
            if (flags & FL_LONG) {
                ulval = *(u64*)ap;
                ap += 2;
            } else if (flags & FL_SHORT) {
                ulval = (u16)(*(u32*)ap);
                ap += 2;
            } else {
                ulval = *(u32*)ap;
                ap += 2;
            }
            if ((flags & FL_ALT) && ulval != 0) flags |= FL_PREFIX;
            goto number_base16;

        case 90: /* 'z' */
            flags |= FL_LONG;
            goto reswitch;

        default:
            ox[0] = (char)ch;
            cp = ox;
            size = 1;
            F.sign = 0;
            goto string_common;
    }

number_base10:
    {
        char* ep = numbuf + 348;
        cp = ep;
        if (prec == 0 && ulval == 0) {
            goto number_done;
        }
        if (ulval < 10) {
            *--cp = (char)(ulval + '0');
        } else {
            do {
                u64 q = func_00313498(ulval, 10);
                u64 r = func_00312db8(ulval, 10);
                *--cp = (char)(r + '0');
                ulval = q;
            } while (ulval != 0);
        }
        goto number_done;
    }

number_base8:
    {
        char* ep = numbuf + 348;
        cp = ep;
        if (prec == 0 && ulval == 0) {
            if ((flags & FL_ALT)) {
                *--cp = '0';
            }
            goto number_done;
        }
        do {
            *--cp = (char)((ulval & 7) + '0');
            ulval >>= 3;
        } while (ulval != 0);
        if ((flags & FL_ALT) && *cp != '0') {
            *--cp = '0';
        }
        goto number_done;
    }

number_base16:
    {
        char* ep = numbuf + 348;
        cp = ep;
        if (prec == 0 && ulval == 0) {
            goto number_done;
        }
        {
            char* xd = (char*)xdigtab;
            do {
                *--cp = xd[(int)(ulval & 15)];
                ulval >>= 4;
            } while (ulval != 0);
        }
        goto number_done;
    }

number_done:
    size = (int)((numbuf + 348) - cp);

number_output:
    realsz = size;
    if (prec > realsz) realsz = prec;
    if (F.sign)
        realsz++;
    else if (flags & FL_PREFIX)
        realsz += 2;

    fieldsz = realsz;
    if (width > fieldsz) fieldsz = width;

    if (!(flags & (FL_LADJUST|FL_DOT)) && F.sign != '0') PAD(width - realsz, D_00307928);

    if (F.sign && F.sign != '0') PRINT(&F.sign, 1);

    if (flags & FL_PREFIX) {
        ox[0] = '0';
        ox[1] = (xdigtab == (int)D_00307950) ? 'X' : 'x';
        PRINT(ox, 2);
    }

    if (!(flags & (FL_LADJUST|FL_DOT)) && F.sign == '0') PAD(width - realsz, D_00307938);

    PAD(prec - size, D_00307938);
    PRINT(cp, size);

    if (flags & FL_LADJUST) PAD(width - realsz, D_00307928);

    nprinted += fieldsz;

    if (F.suio_resid != 0) {
        if (func_002ffc08(fp, &F.suio_iov) != 0) goto error;
        iov_ptr = (char*)iov;
        F.suio_iovcnt = 0;
        F.suio_resid = 0;
    }
    F.suio_iovcnt = 0;
    goto again;

string_common:
    realsz = size;
    if (F.sign) realsz++;

    fieldsz = realsz;
    if (width > fieldsz) fieldsz = width;

    if (!(flags & FL_LADJUST)) PAD(width - realsz, D_00307928);

    if (F.sign) PRINT(&F.sign, 1);

    if (flags & FL_FPT) {
        /* Floating-point output based on target assembly analysis */
        int decpt = slot488;
        int dsign = pad492;
        int ndig = pad492;

        if (ch == 'e' || ch == 'E') {
            /* e/E format: output digit.mantissa eXX */
            if (func_003142e0(ulval, 0)) {
                /* non-finite? use cp string */
                PRINT(cp, size - slot536);
            } else {
                /* finite: first digit + '.' then rest */
                ox[0] = *cp++;
                ox[1] = '.';
                PRINT(ox, 2);
                if (pad492 < 2)
                    PRINT(cp, pad492);
                else
                    PRINT(cp, 0);
            }
            PRINT(F.expbuf, slot536);
        } else if (ch == 'f') {
            /* f format */
            if (func_003142e0(ulval, 0)) {
                /* non-finite: sign + nan/inf string */
                PRINT(cp, size);
            } else {
                /* finite: use dtoa output */
                if (decpt <= 0) {
                    ox[0] = '0';
                    PRINT(ox, 1);
                    if (prec > 0 || (flags & FL_ALT)) {
                        PRINT((char*)localech, 1);
                        PAD(-decpt, D_00307938);
                        if (prec + decpt > 0)
                            PRINT(cp, prec + decpt);
                    }
                } else {
                    int lead = (decpt > size) ? size : decpt;
                    PRINT(cp, lead);
                    cp += lead;
                    if (prec > 0 || (flags & FL_ALT)) {
                        PRINT((char*)localech, 1);
                        PRINT(cp, prec - lead < 0 ? 0 : prec - lead);
                    }
                }
            }
        } else {
            /* g/G format */
            PRINT(cp, size);
        }
    } else {
        PRINT(cp, size);
    }

    if (flags & FL_LADJUST) PAD(width - realsz, D_00307928);

    nprinted += fieldsz;

    if (F.suio_resid != 0) {
        if (func_002ffc08(fp, &F.suio_iov) != 0) goto error;
        iov_ptr = (char*)iov;
        F.suio_iovcnt = 0;
        F.suio_resid = 0;
    }
    F.suio_iovcnt = 0;
    goto again;

finish:
    if (F.suio_resid != 0) {
        if (func_002ffc08(fp, &F.suio_iov) != 0) goto error;
    }
    return nprinted;

error:
    return -1;
}
