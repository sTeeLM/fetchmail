/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "rcfile_y.y"

/*
 * rcfile_y.y -- Run control file parser for fetchmail
 *
 * For license terms, see the file COPYING in this directory.
 */

#include "config.h"
#include "fetchmail.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/file.h>
#if defined(HAVE_SYS_WAIT_H)
#include <sys/wait.h>
#endif
#include <sys/stat.h>
#include <errno.h>
#if defined(STDC_HEADERS)
#include <stdlib.h>
#endif
#if defined(HAVE_UNISTD_H)
#include <unistd.h>
#endif
#include <string.h>

#if defined(__CYGWIN__)
#include <sys/cygwin.h>
#endif /* __CYGWIN__ */

#include "fetchmail.h"
#include "i18n.h"
  
/* parser reads these */
char *rcfile;			/* path name of rc file */
struct query cmd_opts;		/* where to put command-line info */

/* parser sets these */
struct query *querylist;	/* head of server list (globally visible) */

static struct query current;	/* current server record */
static int prc_errflag;
static struct hostdata *leadentry;
static flag trailer;

static void record_current(void);
static void user_reset(void);
static void reset_server(const char *name, int skip);

/* these should be of size PATH_MAX */
char currentwd[1024] = "", rcfiledir[1024] = "";

/* using Bison, this arranges that yydebug messages will show actual tokens */
extern char * yytext;
#define YYPRINT(fp, type, val)	fprintf(fp, " = \"%s\"", yytext)

#line 127 "rcfile_y.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_RCFILE_Y_H_INCLUDED
# define YY_YY_RCFILE_Y_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    DEFAULTS = 258,                /* DEFAULTS  */
    POLL = 259,                    /* POLL  */
    SKIP = 260,                    /* SKIP  */
    VIA = 261,                     /* VIA  */
    AKA = 262,                     /* AKA  */
    LOCALDOMAINS = 263,            /* LOCALDOMAINS  */
    PROTOCOL = 264,                /* PROTOCOL  */
    AUTHENTICATE = 265,            /* AUTHENTICATE  */
    TIMEOUT = 266,                 /* TIMEOUT  */
    KPOP = 267,                    /* KPOP  */
    SDPS = 268,                    /* SDPS  */
    ENVELOPE = 269,                /* ENVELOPE  */
    QVIRTUAL = 270,                /* QVIRTUAL  */
    USERNAME = 271,                /* USERNAME  */
    PASSWORD = 272,                /* PASSWORD  */
    IMAP_ID = 273,                 /* IMAP_ID  */
    FOLDER = 274,                  /* FOLDER  */
    SMTPHOST = 275,                /* SMTPHOST  */
    FETCHDOMAINS = 276,            /* FETCHDOMAINS  */
    MDA = 277,                     /* MDA  */
    BSMTP = 278,                   /* BSMTP  */
    LMTP = 279,                    /* LMTP  */
    SMTPADDRESS = 280,             /* SMTPADDRESS  */
    SMTPNAME = 281,                /* SMTPNAME  */
    SPAMRESPONSE = 282,            /* SPAMRESPONSE  */
    PRECONNECT = 283,              /* PRECONNECT  */
    POSTCONNECT = 284,             /* POSTCONNECT  */
    LIMIT = 285,                   /* LIMIT  */
    WARNINGS = 286,                /* WARNINGS  */
    INTERFACE = 287,               /* INTERFACE  */
    MONITOR = 288,                 /* MONITOR  */
    PLUGIN = 289,                  /* PLUGIN  */
    PLUGOUT = 290,                 /* PLUGOUT  */
    IS = 291,                      /* IS  */
    HERE = 292,                    /* HERE  */
    THERE = 293,                   /* THERE  */
    TO = 294,                      /* TO  */
    MAP = 295,                     /* MAP  */
    BATCHLIMIT = 296,              /* BATCHLIMIT  */
    FETCHLIMIT = 297,              /* FETCHLIMIT  */
    FETCHSIZELIMIT = 298,          /* FETCHSIZELIMIT  */
    FASTUIDL = 299,                /* FASTUIDL  */
    EXPUNGE = 300,                 /* EXPUNGE  */
    PROPERTIES = 301,              /* PROPERTIES  */
    SET = 302,                     /* SET  */
    LOGFILE = 303,                 /* LOGFILE  */
    DAEMON = 304,                  /* DAEMON  */
    SYSLOG = 305,                  /* SYSLOG  */
    IDFILE = 306,                  /* IDFILE  */
    PIDFILE = 307,                 /* PIDFILE  */
    INVISIBLE = 308,               /* INVISIBLE  */
    POSTMASTER = 309,              /* POSTMASTER  */
    BOUNCEMAIL = 310,              /* BOUNCEMAIL  */
    SPAMBOUNCE = 311,              /* SPAMBOUNCE  */
    SOFTBOUNCE = 312,              /* SOFTBOUNCE  */
    SHOWDOTS = 313,                /* SHOWDOTS  */
    BADHEADER = 314,               /* BADHEADER  */
    ACCEPT = 315,                  /* ACCEPT  */
    REJECT_ = 316,                 /* REJECT_  */
    PROTO = 317,                   /* PROTO  */
    AUTHTYPE = 318,                /* AUTHTYPE  */
    STRING = 319,                  /* STRING  */
    NUMBER = 320,                  /* NUMBER  */
    NO = 321,                      /* NO  */
    KEEP = 322,                    /* KEEP  */
    FLUSH = 323,                   /* FLUSH  */
    LIMITFLUSH = 324,              /* LIMITFLUSH  */
    FETCHALL = 325,                /* FETCHALL  */
    REWRITE = 326,                 /* REWRITE  */
    FORCECR = 327,                 /* FORCECR  */
    STRIPCR = 328,                 /* STRIPCR  */
    PASS8BITS = 329,               /* PASS8BITS  */
    DROPSTATUS = 330,              /* DROPSTATUS  */
    DROPDELIVERED = 331,           /* DROPDELIVERED  */
    DNS = 332,                     /* DNS  */
    SERVICE = 333,                 /* SERVICE  */
    PORT = 334,                    /* PORT  */
    UIDL = 335,                    /* UIDL  */
    INTERVAL = 336,                /* INTERVAL  */
    MIMEDECODE = 337,              /* MIMEDECODE  */
    IDLE = 338,                    /* IDLE  */
    CHECKALIAS = 339,              /* CHECKALIAS  */
    SSL = 340,                     /* SSL  */
    SSLKEY = 341,                  /* SSLKEY  */
    SSLCERT = 342,                 /* SSLCERT  */
    SSLPROTO = 343,                /* SSLPROTO  */
    SSLCERTCK = 344,               /* SSLCERTCK  */
    SSLCERTFILE = 345,             /* SSLCERTFILE  */
    SSLCERTPATH = 346,             /* SSLCERTPATH  */
    SSLCOMMONNAME = 347,           /* SSLCOMMONNAME  */
    SSLFINGERPRINT = 348,          /* SSLFINGERPRINT  */
    PRINCIPAL = 349,               /* PRINCIPAL  */
    ESMTPNAME = 350,               /* ESMTPNAME  */
    ESMTPPASSWORD = 351,           /* ESMTPPASSWORD  */
    TRACEPOLLS = 352               /* TRACEPOLLS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define DEFAULTS 258
#define POLL 259
#define SKIP 260
#define VIA 261
#define AKA 262
#define LOCALDOMAINS 263
#define PROTOCOL 264
#define AUTHENTICATE 265
#define TIMEOUT 266
#define KPOP 267
#define SDPS 268
#define ENVELOPE 269
#define QVIRTUAL 270
#define USERNAME 271
#define PASSWORD 272
#define IMAP_ID 273
#define FOLDER 274
#define SMTPHOST 275
#define FETCHDOMAINS 276
#define MDA 277
#define BSMTP 278
#define LMTP 279
#define SMTPADDRESS 280
#define SMTPNAME 281
#define SPAMRESPONSE 282
#define PRECONNECT 283
#define POSTCONNECT 284
#define LIMIT 285
#define WARNINGS 286
#define INTERFACE 287
#define MONITOR 288
#define PLUGIN 289
#define PLUGOUT 290
#define IS 291
#define HERE 292
#define THERE 293
#define TO 294
#define MAP 295
#define BATCHLIMIT 296
#define FETCHLIMIT 297
#define FETCHSIZELIMIT 298
#define FASTUIDL 299
#define EXPUNGE 300
#define PROPERTIES 301
#define SET 302
#define LOGFILE 303
#define DAEMON 304
#define SYSLOG 305
#define IDFILE 306
#define PIDFILE 307
#define INVISIBLE 308
#define POSTMASTER 309
#define BOUNCEMAIL 310
#define SPAMBOUNCE 311
#define SOFTBOUNCE 312
#define SHOWDOTS 313
#define BADHEADER 314
#define ACCEPT 315
#define REJECT_ 316
#define PROTO 317
#define AUTHTYPE 318
#define STRING 319
#define NUMBER 320
#define NO 321
#define KEEP 322
#define FLUSH 323
#define LIMITFLUSH 324
#define FETCHALL 325
#define REWRITE 326
#define FORCECR 327
#define STRIPCR 328
#define PASS8BITS 329
#define DROPSTATUS 330
#define DROPDELIVERED 331
#define DNS 332
#define SERVICE 333
#define PORT 334
#define UIDL 335
#define INTERVAL 336
#define MIMEDECODE 337
#define IDLE 338
#define CHECKALIAS 339
#define SSL 340
#define SSLKEY 341
#define SSLCERT 342
#define SSLPROTO 343
#define SSLCERTCK 344
#define SSLCERTFILE 345
#define SSLCERTPATH 346
#define SSLCOMMONNAME 347
#define SSLFINGERPRINT 348
#define PRINCIPAL 349
#define ESMTPNAME 350
#define ESMTPPASSWORD 351
#define TRACEPOLLS 352

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 57 "rcfile_y.y"

  int proto;
  int number;
  char *sval;

#line 380 "rcfile_y.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_RCFILE_Y_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_DEFAULTS = 3,                   /* DEFAULTS  */
  YYSYMBOL_POLL = 4,                       /* POLL  */
  YYSYMBOL_SKIP = 5,                       /* SKIP  */
  YYSYMBOL_VIA = 6,                        /* VIA  */
  YYSYMBOL_AKA = 7,                        /* AKA  */
  YYSYMBOL_LOCALDOMAINS = 8,               /* LOCALDOMAINS  */
  YYSYMBOL_PROTOCOL = 9,                   /* PROTOCOL  */
  YYSYMBOL_AUTHENTICATE = 10,              /* AUTHENTICATE  */
  YYSYMBOL_TIMEOUT = 11,                   /* TIMEOUT  */
  YYSYMBOL_KPOP = 12,                      /* KPOP  */
  YYSYMBOL_SDPS = 13,                      /* SDPS  */
  YYSYMBOL_ENVELOPE = 14,                  /* ENVELOPE  */
  YYSYMBOL_QVIRTUAL = 15,                  /* QVIRTUAL  */
  YYSYMBOL_USERNAME = 16,                  /* USERNAME  */
  YYSYMBOL_PASSWORD = 17,                  /* PASSWORD  */
  YYSYMBOL_IMAP_ID = 18,                   /* IMAP_ID  */
  YYSYMBOL_FOLDER = 19,                    /* FOLDER  */
  YYSYMBOL_SMTPHOST = 20,                  /* SMTPHOST  */
  YYSYMBOL_FETCHDOMAINS = 21,              /* FETCHDOMAINS  */
  YYSYMBOL_MDA = 22,                       /* MDA  */
  YYSYMBOL_BSMTP = 23,                     /* BSMTP  */
  YYSYMBOL_LMTP = 24,                      /* LMTP  */
  YYSYMBOL_SMTPADDRESS = 25,               /* SMTPADDRESS  */
  YYSYMBOL_SMTPNAME = 26,                  /* SMTPNAME  */
  YYSYMBOL_SPAMRESPONSE = 27,              /* SPAMRESPONSE  */
  YYSYMBOL_PRECONNECT = 28,                /* PRECONNECT  */
  YYSYMBOL_POSTCONNECT = 29,               /* POSTCONNECT  */
  YYSYMBOL_LIMIT = 30,                     /* LIMIT  */
  YYSYMBOL_WARNINGS = 31,                  /* WARNINGS  */
  YYSYMBOL_INTERFACE = 32,                 /* INTERFACE  */
  YYSYMBOL_MONITOR = 33,                   /* MONITOR  */
  YYSYMBOL_PLUGIN = 34,                    /* PLUGIN  */
  YYSYMBOL_PLUGOUT = 35,                   /* PLUGOUT  */
  YYSYMBOL_IS = 36,                        /* IS  */
  YYSYMBOL_HERE = 37,                      /* HERE  */
  YYSYMBOL_THERE = 38,                     /* THERE  */
  YYSYMBOL_TO = 39,                        /* TO  */
  YYSYMBOL_MAP = 40,                       /* MAP  */
  YYSYMBOL_BATCHLIMIT = 41,                /* BATCHLIMIT  */
  YYSYMBOL_FETCHLIMIT = 42,                /* FETCHLIMIT  */
  YYSYMBOL_FETCHSIZELIMIT = 43,            /* FETCHSIZELIMIT  */
  YYSYMBOL_FASTUIDL = 44,                  /* FASTUIDL  */
  YYSYMBOL_EXPUNGE = 45,                   /* EXPUNGE  */
  YYSYMBOL_PROPERTIES = 46,                /* PROPERTIES  */
  YYSYMBOL_SET = 47,                       /* SET  */
  YYSYMBOL_LOGFILE = 48,                   /* LOGFILE  */
  YYSYMBOL_DAEMON = 49,                    /* DAEMON  */
  YYSYMBOL_SYSLOG = 50,                    /* SYSLOG  */
  YYSYMBOL_IDFILE = 51,                    /* IDFILE  */
  YYSYMBOL_PIDFILE = 52,                   /* PIDFILE  */
  YYSYMBOL_INVISIBLE = 53,                 /* INVISIBLE  */
  YYSYMBOL_POSTMASTER = 54,                /* POSTMASTER  */
  YYSYMBOL_BOUNCEMAIL = 55,                /* BOUNCEMAIL  */
  YYSYMBOL_SPAMBOUNCE = 56,                /* SPAMBOUNCE  */
  YYSYMBOL_SOFTBOUNCE = 57,                /* SOFTBOUNCE  */
  YYSYMBOL_SHOWDOTS = 58,                  /* SHOWDOTS  */
  YYSYMBOL_BADHEADER = 59,                 /* BADHEADER  */
  YYSYMBOL_ACCEPT = 60,                    /* ACCEPT  */
  YYSYMBOL_REJECT_ = 61,                   /* REJECT_  */
  YYSYMBOL_PROTO = 62,                     /* PROTO  */
  YYSYMBOL_AUTHTYPE = 63,                  /* AUTHTYPE  */
  YYSYMBOL_STRING = 64,                    /* STRING  */
  YYSYMBOL_NUMBER = 65,                    /* NUMBER  */
  YYSYMBOL_NO = 66,                        /* NO  */
  YYSYMBOL_KEEP = 67,                      /* KEEP  */
  YYSYMBOL_FLUSH = 68,                     /* FLUSH  */
  YYSYMBOL_LIMITFLUSH = 69,                /* LIMITFLUSH  */
  YYSYMBOL_FETCHALL = 70,                  /* FETCHALL  */
  YYSYMBOL_REWRITE = 71,                   /* REWRITE  */
  YYSYMBOL_FORCECR = 72,                   /* FORCECR  */
  YYSYMBOL_STRIPCR = 73,                   /* STRIPCR  */
  YYSYMBOL_PASS8BITS = 74,                 /* PASS8BITS  */
  YYSYMBOL_DROPSTATUS = 75,                /* DROPSTATUS  */
  YYSYMBOL_DROPDELIVERED = 76,             /* DROPDELIVERED  */
  YYSYMBOL_DNS = 77,                       /* DNS  */
  YYSYMBOL_SERVICE = 78,                   /* SERVICE  */
  YYSYMBOL_PORT = 79,                      /* PORT  */
  YYSYMBOL_UIDL = 80,                      /* UIDL  */
  YYSYMBOL_INTERVAL = 81,                  /* INTERVAL  */
  YYSYMBOL_MIMEDECODE = 82,                /* MIMEDECODE  */
  YYSYMBOL_IDLE = 83,                      /* IDLE  */
  YYSYMBOL_CHECKALIAS = 84,                /* CHECKALIAS  */
  YYSYMBOL_SSL = 85,                       /* SSL  */
  YYSYMBOL_SSLKEY = 86,                    /* SSLKEY  */
  YYSYMBOL_SSLCERT = 87,                   /* SSLCERT  */
  YYSYMBOL_SSLPROTO = 88,                  /* SSLPROTO  */
  YYSYMBOL_SSLCERTCK = 89,                 /* SSLCERTCK  */
  YYSYMBOL_SSLCERTFILE = 90,               /* SSLCERTFILE  */
  YYSYMBOL_SSLCERTPATH = 91,               /* SSLCERTPATH  */
  YYSYMBOL_SSLCOMMONNAME = 92,             /* SSLCOMMONNAME  */
  YYSYMBOL_SSLFINGERPRINT = 93,            /* SSLFINGERPRINT  */
  YYSYMBOL_PRINCIPAL = 94,                 /* PRINCIPAL  */
  YYSYMBOL_ESMTPNAME = 95,                 /* ESMTPNAME  */
  YYSYMBOL_ESMTPPASSWORD = 96,             /* ESMTPPASSWORD  */
  YYSYMBOL_TRACEPOLLS = 97,                /* TRACEPOLLS  */
  YYSYMBOL_YYACCEPT = 98,                  /* $accept  */
  YYSYMBOL_rcfile = 99,                    /* rcfile  */
  YYSYMBOL_statement_list = 100,           /* statement_list  */
  YYSYMBOL_optmap = 101,                   /* optmap  */
  YYSYMBOL_statement = 102,                /* statement  */
  YYSYMBOL_define_server = 103,            /* define_server  */
  YYSYMBOL_serverspecs = 104,              /* serverspecs  */
  YYSYMBOL_alias_list = 105,               /* alias_list  */
  YYSYMBOL_domain_list = 106,              /* domain_list  */
  YYSYMBOL_serv_option = 107,              /* serv_option  */
  YYSYMBOL_userspecs = 108,                /* userspecs  */
  YYSYMBOL_explicits = 109,                /* explicits  */
  YYSYMBOL_explicitdef = 110,              /* explicitdef  */
  YYSYMBOL_userdef = 111,                  /* userdef  */
  YYSYMBOL_user0opts = 112,                /* user0opts  */
  YYSYMBOL_user1opts = 113,                /* user1opts  */
  YYSYMBOL_mapping_list = 114,             /* mapping_list  */
  YYSYMBOL_mapping = 115,                  /* mapping  */
  YYSYMBOL_folder_list = 116,              /* folder_list  */
  YYSYMBOL_smtp_list = 117,                /* smtp_list  */
  YYSYMBOL_fetch_list = 118,               /* fetch_list  */
  YYSYMBOL_num_list = 119,                 /* num_list  */
  YYSYMBOL_user_option = 120               /* user_option  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  24
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   336

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  98
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  155
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  227

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   352


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    89,    89,    90,    93,    94,    97,    97,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   125,   126,   129,   133,
     134,   135,   138,   139,   142,   143,   146,   147,   150,   151,
     152,   153,   154,   165,   166,   167,   168,   176,   177,   178,
     179,   180,   183,   189,   195,   197,   199,   201,   206,   212,
     213,   221,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   240,   241,   244,   245,   248,   251,   252,   253,   256,
     257,   260,   261,   264,   265,   268,   274,   277,   278,   281,
     282,   285,   286,   289,   295,   303,   304,   305,   306,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   334,   336,   343,   344,   345,   346,
     347,   348,   349,   350,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   365,   366,   368,   369,
     370,   371,   372,   373,   374,   376
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "DEFAULTS", "POLL",
  "SKIP", "VIA", "AKA", "LOCALDOMAINS", "PROTOCOL", "AUTHENTICATE",
  "TIMEOUT", "KPOP", "SDPS", "ENVELOPE", "QVIRTUAL", "USERNAME",
  "PASSWORD", "IMAP_ID", "FOLDER", "SMTPHOST", "FETCHDOMAINS", "MDA",
  "BSMTP", "LMTP", "SMTPADDRESS", "SMTPNAME", "SPAMRESPONSE", "PRECONNECT",
  "POSTCONNECT", "LIMIT", "WARNINGS", "INTERFACE", "MONITOR", "PLUGIN",
  "PLUGOUT", "IS", "HERE", "THERE", "TO", "MAP", "BATCHLIMIT",
  "FETCHLIMIT", "FETCHSIZELIMIT", "FASTUIDL", "EXPUNGE", "PROPERTIES",
  "SET", "LOGFILE", "DAEMON", "SYSLOG", "IDFILE", "PIDFILE", "INVISIBLE",
  "POSTMASTER", "BOUNCEMAIL", "SPAMBOUNCE", "SOFTBOUNCE", "SHOWDOTS",
  "BADHEADER", "ACCEPT", "REJECT_", "PROTO", "AUTHTYPE", "STRING",
  "NUMBER", "NO", "KEEP", "FLUSH", "LIMITFLUSH", "FETCHALL", "REWRITE",
  "FORCECR", "STRIPCR", "PASS8BITS", "DROPSTATUS", "DROPDELIVERED", "DNS",
  "SERVICE", "PORT", "UIDL", "INTERVAL", "MIMEDECODE", "IDLE",
  "CHECKALIAS", "SSL", "SSLKEY", "SSLCERT", "SSLPROTO", "SSLCERTCK",
  "SSLCERTFILE", "SSLCERTPATH", "SSLCOMMONNAME", "SSLFINGERPRINT",
  "PRINCIPAL", "ESMTPNAME", "ESMTPPASSWORD", "TRACEPOLLS", "$accept",
  "rcfile", "statement_list", "optmap", "statement", "define_server",
  "serverspecs", "alias_list", "domain_list", "serv_option", "userspecs",
  "explicits", "explicitdef", "userdef", "user0opts", "user1opts",
  "mapping_list", "mapping", "folder_list", "smtp_list", "fetch_list",
  "num_list", "user_option", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-129)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-86)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      54,  -129,   -57,   -32,   270,    47,    54,  -129,  -129,  -129,
    -129,    13,    13,    13,  -129,    13,    13,  -129,    13,  -129,
    -129,  -129,  -129,    86,  -129,  -129,    -5,  -129,    -4,    55,
      61,    56,    63,    64,  -129,  -129,  -129,  -129,  -129,  -129,
      66,    67,    68,    31,    72,    75,    -9,    81,    82,    83,
      85,    87,    88,    90,    92,    93,  -129,    94,    95,    96,
      98,    99,   100,   106,   108,   110,   111,   112,   113,   114,
     115,   116,   117,   133,   134,   137,    53,   120,  -129,  -129,
    -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,    51,
     141,  -129,   142,  -129,  -129,  -129,  -129,   144,   146,   147,
    -129,   148,   149,   150,   151,   152,   169,   170,  -129,  -129,
      89,   163,  -129,  -129,   201,  -129,  -129,  -129,  -129,  -129,
    -129,  -129,  -129,  -129,   171,  -129,   172,  -129,  -129,  -129,
    -129,  -129,  -129,   174,  -129,    69,    65,  -129,  -129,  -129,
    -129,   175,  -129,   177,  -129,   184,  -129,  -129,  -129,  -129,
    -129,   185,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,
      12,    73,   124,    74,  -129,  -129,  -129,  -129,  -129,  -129,
    -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,
    -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,
    -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,  -129,
    -129,  -129,  -129,  -129,  -129,    28,  -129,  -129,   201,   228,
    -129,  -129,  -129,  -129,  -129,   187,  -129,  -129,  -129,  -129,
    -129,  -129,  -129,  -129,  -129,  -129,  -129
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,    31,     0,     0,     0,     0,     3,     4,    32,    29,
      30,     7,     7,     7,    20,     7,     7,    22,     7,    13,
      15,    17,    24,     0,     1,     5,    26,     6,     0,     0,
       0,     0,     0,     0,    21,    23,    14,    16,    18,    25,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   110,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,    64,     0,
       0,    47,     0,   123,   124,    49,   125,     0,     0,     0,
     129,     0,     0,     0,     0,     0,     0,     0,    67,    33,
      27,    72,    73,    79,    71,    81,    19,     8,    11,     9,
      10,    12,    39,    34,    38,    36,    40,    42,    46,    41,
      55,    56,    58,     0,    59,    76,     0,    83,   100,   101,
      87,   102,    89,   103,    91,   104,   108,   109,   105,   106,
      93,   107,   111,   112,   148,   149,    60,    61,    62,    63,
      85,    98,    85,    96,   153,   150,   151,   152,   154,   155,
      69,    70,    66,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,    65,    48,   144,   145,    50,   146,   147,
      68,    51,    52,    53,    54,   126,   127,   128,   130,   131,
     132,   133,    43,    44,    45,     0,    28,    74,    75,     0,
      82,    35,    37,    57,    78,     0,    77,    84,    88,    90,
      92,    94,    99,    97,    95,    80,    86
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -129,  -129,  -129,    33,   154,  -129,  -129,  -129,  -129,    40,
    -129,  -129,    42,  -129,  -129,  -129,    49,  -128,  -129,  -129,
    -129,  -129,  -114
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,     6,    28,     7,     8,    26,   124,   126,   109,
     110,   111,   112,   113,   208,   114,   136,   137,   141,   143,
     145,   151,   115
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     210,    40,    41,    42,    43,    44,    45,     9,   217,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    10,   217,    69,   217,    70,    71,    72,    73,
      74,    75,   172,   127,   128,    29,    30,    24,    31,    32,
     222,    33,   215,    27,    76,   132,   133,     1,     2,     3,
     116,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   129,   225,    40,    41,    42,    43,    44,
      45,     4,   216,    46,    47,   183,   -85,   214,   184,   215,
     223,   224,   187,   170,   171,   191,   192,   161,   163,   117,
     119,    64,    65,    66,    67,   190,   118,   120,   121,   162,
     122,   123,   125,   -85,   172,   130,    34,   162,   162,    35,
     131,    36,    37,    38,    39,   134,   135,   138,    76,   139,
     206,   140,   142,   207,   144,   205,   146,   147,   148,   149,
      25,   150,   152,   153,   215,   154,    88,    89,    90,    91,
      92,   155,   156,    95,   157,   158,   159,   160,   162,    48,
     164,   165,   166,   105,   106,   107,   108,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   167,   168,
     184,   169,   185,   186,   187,   188,   193,   194,   195,   189,
     196,   197,   198,   199,   200,   201,   202,   190,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,   203,   204,   211,   212,    68,   213,   218,
      69,   219,    70,    71,    72,    73,    74,    75,   220,     0,
     221,   226,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   209,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,     0,     0,
       0,     0,     0,    93,    94,     0,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,     0,     0,     0,     0,     0,
     185,   186,     0,   188,     0,     0,    11,   189,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,     0,
       0,     0,     0,     0,     0,     0,    23
};

static const yytype_int16 yycheck[] =
{
     114,     6,     7,     8,     9,    10,    11,    64,   136,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    64,   161,    39,   163,    41,    42,    43,    44,
      45,    46,    14,    12,    13,    12,    13,     0,    15,    16,
      38,    18,    40,    40,    59,    64,    65,     3,     4,     5,
      64,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    62,   208,     6,     7,     8,     9,    10,
      11,    47,    37,    14,    15,    77,    37,    38,    80,    40,
      37,    37,    84,    60,    61,    64,    65,    68,    69,    64,
      64,    32,    33,    34,    35,    97,    65,    64,    64,    64,
      64,    64,    64,    64,    14,    63,    50,    64,    64,    53,
      65,    55,    56,    57,    58,    64,    64,    64,    59,    64,
     110,    64,    64,   111,    64,    66,    64,    64,    64,    64,
       6,    65,    64,    64,    40,    65,    77,    78,    79,    80,
      81,    65,    64,    84,    64,    64,    64,    64,    64,    16,
      65,    65,    65,    94,    95,    96,    97,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    65,    65,
      80,    64,    82,    83,    84,    85,    65,    65,    64,    89,
      64,    64,    64,    64,    64,    64,    64,    97,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    64,    64,    64,    64,    36,    64,    64,
      39,    64,    41,    42,    43,    44,    45,    46,    64,    -1,
      65,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    -1,    -1,
      -1,    -1,    -1,    82,    83,    -1,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,
      82,    83,    -1,    85,    -1,    -1,    46,    89,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    66
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,    47,    99,   100,   102,   103,    64,
      64,    46,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    66,     0,   102,   104,    40,   101,   101,
     101,   101,   101,   101,    50,    53,    55,    56,    57,    58,
       6,     7,     8,     9,    10,    11,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    39,
      41,    42,    43,    44,    45,    46,    59,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,   107,
     108,   109,   110,   111,   113,   120,    64,    64,    65,    64,
      64,    64,    64,    64,   105,    64,   106,    12,    13,    62,
      63,    65,    64,    65,    64,    64,   114,   115,    64,    64,
      64,   116,    64,   117,    64,   118,    64,    64,    64,    64,
      65,   119,    64,    64,    65,    65,    64,    64,    64,    64,
      64,   114,    64,   114,    65,    65,    65,    65,    65,    64,
      60,    61,    14,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    80,    82,    83,    84,    85,    89,
      97,    64,    65,    65,    65,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    66,   107,   110,   112,    66,
     120,    64,    64,    64,    38,    40,    37,   115,    64,    64,
      64,    65,    38,    37,    37,   120,    64
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    98,    99,    99,   100,   100,   101,   101,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   103,
     103,   103,   104,   104,   105,   105,   106,   106,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   108,   108,   109,   109,   110,   111,   111,   111,   112,
     112,   113,   113,   114,   114,   115,   115,   116,   116,   117,
     117,   118,   118,   119,   119,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     1,     0,     4,     4,
       4,     4,     4,     2,     3,     2,     3,     2,     3,     4,
       2,     3,     2,     3,     2,     3,     2,     3,     4,     2,
       2,     1,     0,     2,     1,     2,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     1,     2,     1,
       2,     2,     2,     2,     2,     2,     2,     3,     2,     2,
       2,     2,     2,     2,     1,     2,     2,     1,     2,     2,
       2,     1,     1,     1,     2,     2,     2,     3,     3,     0,
       2,     1,     2,     1,     2,     1,     3,     1,     2,     1,
       2,     1,     2,     1,     2,     3,     2,     3,     2,     3,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     1,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yykind)
    {
    case YYSYMBOL_STRING: /* STRING  */
#line 85 "rcfile_y.y"
            { free (((*yyvaluep).sval)); }
#line 1416 "rcfile_y.c"
        break;

      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 8: /* statement: SET LOGFILE optmap STRING  */
#line 100 "rcfile_y.y"
                                                {run.logfile = prependdir ((yyvsp[0].sval), rcfiledir); free((yyvsp[0].sval));}
#line 1686 "rcfile_y.c"
    break;

  case 9: /* statement: SET IDFILE optmap STRING  */
#line 101 "rcfile_y.y"
                                                {run.idfile = prependdir ((yyvsp[0].sval), rcfiledir); free((yyvsp[0].sval));}
#line 1692 "rcfile_y.c"
    break;

  case 10: /* statement: SET PIDFILE optmap STRING  */
#line 102 "rcfile_y.y"
                                                {run.pidfile = prependdir ((yyvsp[0].sval), rcfiledir); free((yyvsp[0].sval));}
#line 1698 "rcfile_y.c"
    break;

  case 11: /* statement: SET DAEMON optmap NUMBER  */
#line 103 "rcfile_y.y"
                                                {run.poll_interval = (yyvsp[0].number);}
#line 1704 "rcfile_y.c"
    break;

  case 12: /* statement: SET POSTMASTER optmap STRING  */
#line 104 "rcfile_y.y"
                                                {run.postmaster = (yyvsp[0].sval);}
#line 1710 "rcfile_y.c"
    break;

  case 13: /* statement: SET BOUNCEMAIL  */
#line 105 "rcfile_y.y"
                                                {run.bouncemail = TRUE;}
#line 1716 "rcfile_y.c"
    break;

  case 14: /* statement: SET NO BOUNCEMAIL  */
#line 106 "rcfile_y.y"
                                                {run.bouncemail = FALSE;}
#line 1722 "rcfile_y.c"
    break;

  case 15: /* statement: SET SPAMBOUNCE  */
#line 107 "rcfile_y.y"
                                                {run.spambounce = TRUE;}
#line 1728 "rcfile_y.c"
    break;

  case 16: /* statement: SET NO SPAMBOUNCE  */
#line 108 "rcfile_y.y"
                                                {run.spambounce = FALSE;}
#line 1734 "rcfile_y.c"
    break;

  case 17: /* statement: SET SOFTBOUNCE  */
#line 109 "rcfile_y.y"
                                                {run.softbounce = TRUE;}
#line 1740 "rcfile_y.c"
    break;

  case 18: /* statement: SET NO SOFTBOUNCE  */
#line 110 "rcfile_y.y"
                                                {run.softbounce = FALSE;}
#line 1746 "rcfile_y.c"
    break;

  case 19: /* statement: SET PROPERTIES optmap STRING  */
#line 111 "rcfile_y.y"
                                                {run.properties = (yyvsp[0].sval);}
#line 1752 "rcfile_y.c"
    break;

  case 20: /* statement: SET SYSLOG  */
#line 112 "rcfile_y.y"
                                                {run.use_syslog = TRUE;}
#line 1758 "rcfile_y.c"
    break;

  case 21: /* statement: SET NO SYSLOG  */
#line 113 "rcfile_y.y"
                                                {run.use_syslog = FALSE;}
#line 1764 "rcfile_y.c"
    break;

  case 22: /* statement: SET INVISIBLE  */
#line 114 "rcfile_y.y"
                                                {run.invisible = TRUE;}
#line 1770 "rcfile_y.c"
    break;

  case 23: /* statement: SET NO INVISIBLE  */
#line 115 "rcfile_y.y"
                                                {run.invisible = FALSE;}
#line 1776 "rcfile_y.c"
    break;

  case 24: /* statement: SET SHOWDOTS  */
#line 116 "rcfile_y.y"
                                                {run.showdots = FLAG_TRUE;}
#line 1782 "rcfile_y.c"
    break;

  case 25: /* statement: SET NO SHOWDOTS  */
#line 117 "rcfile_y.y"
                                                {run.showdots = FLAG_FALSE;}
#line 1788 "rcfile_y.c"
    break;

  case 26: /* statement: define_server serverspecs  */
#line 125 "rcfile_y.y"
                                                        {record_current();}
#line 1794 "rcfile_y.c"
    break;

  case 28: /* statement: define_server serverspecs userspecs serv_option  */
#line 130 "rcfile_y.y"
                        {yyerror(GT_("server option after user options"));}
#line 1800 "rcfile_y.c"
    break;

  case 29: /* define_server: POLL STRING  */
#line 133 "rcfile_y.y"
                                        {reset_server((yyvsp[0].sval), FALSE); free((yyvsp[0].sval));}
#line 1806 "rcfile_y.c"
    break;

  case 30: /* define_server: SKIP STRING  */
#line 134 "rcfile_y.y"
                                        {reset_server((yyvsp[0].sval), TRUE);  free((yyvsp[0].sval));}
#line 1812 "rcfile_y.c"
    break;

  case 31: /* define_server: DEFAULTS  */
#line 135 "rcfile_y.y"
                                        {reset_server("defaults", FALSE);}
#line 1818 "rcfile_y.c"
    break;

  case 34: /* alias_list: STRING  */
#line 142 "rcfile_y.y"
                                        {save_str(&current.server.akalist,(yyvsp[0].sval),0); free((yyvsp[0].sval));}
#line 1824 "rcfile_y.c"
    break;

  case 35: /* alias_list: alias_list STRING  */
#line 143 "rcfile_y.y"
                                        {save_str(&current.server.akalist,(yyvsp[0].sval),0); free((yyvsp[0].sval));}
#line 1830 "rcfile_y.c"
    break;

  case 36: /* domain_list: STRING  */
#line 146 "rcfile_y.y"
                                        {save_str(&current.server.localdomains,(yyvsp[0].sval),0); free((yyvsp[0].sval));}
#line 1836 "rcfile_y.c"
    break;

  case 37: /* domain_list: domain_list STRING  */
#line 147 "rcfile_y.y"
                                        {save_str(&current.server.localdomains,(yyvsp[0].sval),0); free((yyvsp[0].sval));}
#line 1842 "rcfile_y.c"
    break;

  case 39: /* serv_option: VIA STRING  */
#line 151 "rcfile_y.y"
                                        {current.server.via = (yyvsp[0].sval);}
#line 1848 "rcfile_y.c"
    break;

  case 41: /* serv_option: PROTOCOL PROTO  */
#line 153 "rcfile_y.y"
                                        {current.server.protocol = (yyvsp[0].proto);}
#line 1854 "rcfile_y.c"
    break;

  case 42: /* serv_option: PROTOCOL KPOP  */
#line 154 "rcfile_y.y"
                                        {
					    current.server.protocol = P_POP3;

					    if (current.server.authenticate == A_PASSWORD)
#ifdef KERBEROS_V5
						current.server.authenticate = A_KERBEROS_V5;
#else
						current.server.authenticate = A_KERBEROS_V4;
#endif /* KERBEROS_V5 */
					    current.server.service = KPOP_PORT;
					}
#line 1870 "rcfile_y.c"
    break;

  case 43: /* serv_option: PRINCIPAL STRING  */
#line 165 "rcfile_y.y"
                                        {current.server.principal = (yyvsp[0].sval);}
#line 1876 "rcfile_y.c"
    break;

  case 44: /* serv_option: ESMTPNAME STRING  */
#line 166 "rcfile_y.y"
                                        {current.server.esmtp_name = (yyvsp[0].sval);}
#line 1882 "rcfile_y.c"
    break;

  case 45: /* serv_option: ESMTPPASSWORD STRING  */
#line 167 "rcfile_y.y"
                                        {current.server.esmtp_password = (yyvsp[0].sval);}
#line 1888 "rcfile_y.c"
    break;

  case 46: /* serv_option: PROTOCOL SDPS  */
#line 168 "rcfile_y.y"
                                        {
#ifdef SDPS_ENABLE
					    current.server.protocol = P_POP3;
					    current.server.sdps = TRUE;
#else
					    yyerror(GT_("SDPS not enabled."));
#endif /* SDPS_ENABLE */
					}
#line 1901 "rcfile_y.c"
    break;

  case 47: /* serv_option: UIDL  */
#line 176 "rcfile_y.y"
                                        {current.server.uidl = FLAG_TRUE;}
#line 1907 "rcfile_y.c"
    break;

  case 48: /* serv_option: NO UIDL  */
#line 177 "rcfile_y.y"
                                        {current.server.uidl  = FLAG_FALSE;}
#line 1913 "rcfile_y.c"
    break;

  case 49: /* serv_option: CHECKALIAS  */
#line 178 "rcfile_y.y"
                                        {current.server.checkalias = FLAG_TRUE;}
#line 1919 "rcfile_y.c"
    break;

  case 50: /* serv_option: NO CHECKALIAS  */
#line 179 "rcfile_y.y"
                                        {current.server.checkalias  = FLAG_FALSE;}
#line 1925 "rcfile_y.c"
    break;

  case 51: /* serv_option: SERVICE STRING  */
#line 180 "rcfile_y.y"
                                        {
					current.server.service = (yyvsp[0].sval);
					}
#line 1933 "rcfile_y.c"
    break;

  case 52: /* serv_option: SERVICE NUMBER  */
#line 183 "rcfile_y.y"
                                        {
					int port = (yyvsp[0].number);
					char buf[10];
					snprintf(buf, sizeof buf, "%d", port);
					current.server.service = xstrdup(buf);
		}
#line 1944 "rcfile_y.c"
    break;

  case 53: /* serv_option: PORT NUMBER  */
#line 189 "rcfile_y.y"
                                        {
					int port = (yyvsp[0].number);
					char buf[10];
					snprintf(buf, sizeof buf, "%d", port);
					current.server.service = xstrdup(buf);
		}
#line 1955 "rcfile_y.c"
    break;

  case 54: /* serv_option: INTERVAL NUMBER  */
#line 196 "rcfile_y.y"
                        {current.server.interval = (yyvsp[0].number);}
#line 1961 "rcfile_y.c"
    break;

  case 55: /* serv_option: AUTHENTICATE AUTHTYPE  */
#line 198 "rcfile_y.y"
                        {current.server.authenticate = (yyvsp[0].proto);}
#line 1967 "rcfile_y.c"
    break;

  case 56: /* serv_option: TIMEOUT NUMBER  */
#line 200 "rcfile_y.y"
                        {current.server.timeout = (yyvsp[0].number);}
#line 1973 "rcfile_y.c"
    break;

  case 57: /* serv_option: ENVELOPE NUMBER STRING  */
#line 202 "rcfile_y.y"
                                        {
					    current.server.envelope = (yyvsp[0].sval);
					    current.server.envskip = (yyvsp[-1].number);
					}
#line 1982 "rcfile_y.c"
    break;

  case 58: /* serv_option: ENVELOPE STRING  */
#line 207 "rcfile_y.y"
                                        {
					    current.server.envelope = (yyvsp[0].sval);
					    current.server.envskip = 0;
					}
#line 1991 "rcfile_y.c"
    break;

  case 59: /* serv_option: QVIRTUAL STRING  */
#line 212 "rcfile_y.y"
                                        {current.server.qvirtual = (yyvsp[0].sval);}
#line 1997 "rcfile_y.c"
    break;

  case 60: /* serv_option: INTERFACE STRING  */
#line 213 "rcfile_y.y"
                                        {
#ifdef CAN_MONITOR
					interface_parse((yyvsp[0].sval), &current.server);
#else
					fprintf(stderr, GT_("fetchmail: interface option is only supported under Linux (without IPv6) and FreeBSD\n"));
#endif
					free((yyvsp[0].sval));
					}
#line 2010 "rcfile_y.c"
    break;

  case 61: /* serv_option: MONITOR STRING  */
#line 221 "rcfile_y.y"
                                        {
#ifdef CAN_MONITOR
					current.server.monitor = (yyvsp[0].sval);
#else
					fprintf(stderr, GT_("fetchmail: monitor option is only supported under Linux (without IPv6) and FreeBSD\n"));
					free((yyvsp[0].sval));
#endif
					}
#line 2023 "rcfile_y.c"
    break;

  case 62: /* serv_option: PLUGIN STRING  */
#line 229 "rcfile_y.y"
                                        { current.server.plugin = (yyvsp[0].sval); }
#line 2029 "rcfile_y.c"
    break;

  case 63: /* serv_option: PLUGOUT STRING  */
#line 230 "rcfile_y.y"
                                        { current.server.plugout = (yyvsp[0].sval); }
#line 2035 "rcfile_y.c"
    break;

  case 64: /* serv_option: DNS  */
#line 231 "rcfile_y.y"
                                        {current.server.dns = FLAG_TRUE;}
#line 2041 "rcfile_y.c"
    break;

  case 65: /* serv_option: NO DNS  */
#line 232 "rcfile_y.y"
                                        {current.server.dns = FLAG_FALSE;}
#line 2047 "rcfile_y.c"
    break;

  case 66: /* serv_option: NO ENVELOPE  */
#line 233 "rcfile_y.y"
                                        {current.server.envelope = STRING_DISABLED;}
#line 2053 "rcfile_y.c"
    break;

  case 67: /* serv_option: TRACEPOLLS  */
#line 234 "rcfile_y.y"
                                        {current.server.tracepolls = FLAG_TRUE;}
#line 2059 "rcfile_y.c"
    break;

  case 68: /* serv_option: NO TRACEPOLLS  */
#line 235 "rcfile_y.y"
                                        {current.server.tracepolls = FLAG_FALSE;}
#line 2065 "rcfile_y.c"
    break;

  case 69: /* serv_option: BADHEADER ACCEPT  */
#line 236 "rcfile_y.y"
                                        {current.server.badheader = BHACCEPT;}
#line 2071 "rcfile_y.c"
    break;

  case 70: /* serv_option: BADHEADER REJECT_  */
#line 237 "rcfile_y.y"
                                        {current.server.badheader = BHREJECT;}
#line 2077 "rcfile_y.c"
    break;

  case 71: /* userspecs: user1opts  */
#line 240 "rcfile_y.y"
                                        {record_current(); user_reset();}
#line 2083 "rcfile_y.c"
    break;

  case 73: /* explicits: explicitdef  */
#line 244 "rcfile_y.y"
                                        {record_current(); user_reset();}
#line 2089 "rcfile_y.c"
    break;

  case 74: /* explicits: explicits explicitdef  */
#line 245 "rcfile_y.y"
                                        {record_current(); user_reset();}
#line 2095 "rcfile_y.c"
    break;

  case 76: /* userdef: USERNAME STRING  */
#line 251 "rcfile_y.y"
                                        {current.remotename = (yyvsp[0].sval);}
#line 2101 "rcfile_y.c"
    break;

  case 78: /* userdef: USERNAME STRING THERE  */
#line 253 "rcfile_y.y"
                                        {current.remotename = (yyvsp[-1].sval);}
#line 2107 "rcfile_y.c"
    break;

  case 85: /* mapping: STRING  */
#line 268 "rcfile_y.y"
                                        {if (0 == strcmp((yyvsp[0].sval), "*")) {
					      current.wildcard = TRUE;
					  } else {
					    save_str_pair(&current.localnames, (yyvsp[0].sval), NULL);
					  }
					 free((yyvsp[0].sval));}
#line 2118 "rcfile_y.c"
    break;

  case 86: /* mapping: STRING MAP STRING  */
#line 274 "rcfile_y.y"
                                        {save_str_pair(&current.localnames, (yyvsp[-2].sval), (yyvsp[0].sval)); free((yyvsp[-2].sval)); free((yyvsp[0].sval));}
#line 2124 "rcfile_y.c"
    break;

  case 87: /* folder_list: STRING  */
#line 277 "rcfile_y.y"
                                        {save_str(&current.mailboxes,(yyvsp[0].sval),0); free((yyvsp[0].sval));}
#line 2130 "rcfile_y.c"
    break;

  case 88: /* folder_list: folder_list STRING  */
#line 278 "rcfile_y.y"
                                        {save_str(&current.mailboxes,(yyvsp[0].sval),0); free((yyvsp[0].sval));}
#line 2136 "rcfile_y.c"
    break;

  case 89: /* smtp_list: STRING  */
#line 281 "rcfile_y.y"
                                        {save_str(&current.smtphunt, (yyvsp[0].sval),TRUE); free((yyvsp[0].sval));}
#line 2142 "rcfile_y.c"
    break;

  case 90: /* smtp_list: smtp_list STRING  */
#line 282 "rcfile_y.y"
                                        {save_str(&current.smtphunt, (yyvsp[0].sval),TRUE); free((yyvsp[0].sval));}
#line 2148 "rcfile_y.c"
    break;

  case 91: /* fetch_list: STRING  */
#line 285 "rcfile_y.y"
                                        {save_str(&current.domainlist, (yyvsp[0].sval),TRUE); free((yyvsp[0].sval));}
#line 2154 "rcfile_y.c"
    break;

  case 92: /* fetch_list: fetch_list STRING  */
#line 286 "rcfile_y.y"
                                        {save_str(&current.domainlist, (yyvsp[0].sval),TRUE); free((yyvsp[0].sval));}
#line 2160 "rcfile_y.c"
    break;

  case 93: /* num_list: NUMBER  */
#line 290 "rcfile_y.y"
                        {
			    struct idlist *id;
			    id = save_str(&current.antispam,STRING_DUMMY,0);
			    id->val.status.num = (yyvsp[0].number);
			}
#line 2170 "rcfile_y.c"
    break;

  case 94: /* num_list: num_list NUMBER  */
#line 296 "rcfile_y.y"
                        {
			    struct idlist *id;
			    id = save_str(&current.antispam,STRING_DUMMY,0);
			    id->val.status.num = (yyvsp[0].number);
			}
#line 2180 "rcfile_y.c"
    break;

  case 99: /* user_option: IS STRING THERE  */
#line 308 "rcfile_y.y"
                                        {current.remotename  = (yyvsp[-1].sval);}
#line 2186 "rcfile_y.c"
    break;

  case 100: /* user_option: PASSWORD STRING  */
#line 309 "rcfile_y.y"
                                        {current.password    = (yyvsp[0].sval);}
#line 2192 "rcfile_y.c"
    break;

  case 101: /* user_option: IMAP_ID STRING  */
#line 310 "rcfile_y.y"
                                        {current.imap_id     = (yyvsp[0].sval);}
#line 2198 "rcfile_y.c"
    break;

  case 105: /* user_option: SMTPADDRESS STRING  */
#line 314 "rcfile_y.y"
                                        {current.smtpaddress = (yyvsp[0].sval);}
#line 2204 "rcfile_y.c"
    break;

  case 106: /* user_option: SMTPNAME STRING  */
#line 315 "rcfile_y.y"
                                        {current.smtpname =    (yyvsp[0].sval);}
#line 2210 "rcfile_y.c"
    break;

  case 108: /* user_option: MDA STRING  */
#line 317 "rcfile_y.y"
                                        {current.mda         = (yyvsp[0].sval);}
#line 2216 "rcfile_y.c"
    break;

  case 109: /* user_option: BSMTP STRING  */
#line 318 "rcfile_y.y"
                                        {current.bsmtp       = prependdir ((yyvsp[0].sval), rcfiledir); free((yyvsp[0].sval));}
#line 2222 "rcfile_y.c"
    break;

  case 110: /* user_option: LMTP  */
#line 319 "rcfile_y.y"
                                        {current.listener    = LMTP_MODE;}
#line 2228 "rcfile_y.c"
    break;

  case 111: /* user_option: PRECONNECT STRING  */
#line 320 "rcfile_y.y"
                                        {current.preconnect  = (yyvsp[0].sval);}
#line 2234 "rcfile_y.c"
    break;

  case 112: /* user_option: POSTCONNECT STRING  */
#line 321 "rcfile_y.y"
                                        {current.postconnect = (yyvsp[0].sval);}
#line 2240 "rcfile_y.c"
    break;

  case 113: /* user_option: KEEP  */
#line 323 "rcfile_y.y"
                                        {current.keep        = FLAG_TRUE;}
#line 2246 "rcfile_y.c"
    break;

  case 114: /* user_option: FLUSH  */
#line 324 "rcfile_y.y"
                                        {current.flush       = FLAG_TRUE;}
#line 2252 "rcfile_y.c"
    break;

  case 115: /* user_option: LIMITFLUSH  */
#line 325 "rcfile_y.y"
                                        {current.limitflush  = FLAG_TRUE;}
#line 2258 "rcfile_y.c"
    break;

  case 116: /* user_option: FETCHALL  */
#line 326 "rcfile_y.y"
                                        {current.fetchall    = FLAG_TRUE;}
#line 2264 "rcfile_y.c"
    break;

  case 117: /* user_option: REWRITE  */
#line 327 "rcfile_y.y"
                                        {current.rewrite     = FLAG_TRUE;}
#line 2270 "rcfile_y.c"
    break;

  case 118: /* user_option: FORCECR  */
#line 328 "rcfile_y.y"
                                        {current.forcecr     = FLAG_TRUE;}
#line 2276 "rcfile_y.c"
    break;

  case 119: /* user_option: STRIPCR  */
#line 329 "rcfile_y.y"
                                        {current.stripcr     = FLAG_TRUE;}
#line 2282 "rcfile_y.c"
    break;

  case 120: /* user_option: PASS8BITS  */
#line 330 "rcfile_y.y"
                                        {current.pass8bits   = FLAG_TRUE;}
#line 2288 "rcfile_y.c"
    break;

  case 121: /* user_option: DROPSTATUS  */
#line 331 "rcfile_y.y"
                                        {current.dropstatus  = FLAG_TRUE;}
#line 2294 "rcfile_y.c"
    break;

  case 122: /* user_option: DROPDELIVERED  */
#line 332 "rcfile_y.y"
                                        {current.dropdelivered = FLAG_TRUE;}
#line 2300 "rcfile_y.c"
    break;

  case 123: /* user_option: MIMEDECODE  */
#line 333 "rcfile_y.y"
                                        {current.mimedecode  = FLAG_TRUE;}
#line 2306 "rcfile_y.c"
    break;

  case 124: /* user_option: IDLE  */
#line 334 "rcfile_y.y"
                                        {current.idle        = FLAG_TRUE;}
#line 2312 "rcfile_y.c"
    break;

  case 125: /* user_option: SSL  */
#line 336 "rcfile_y.y"
                                        {
#ifdef SSL_ENABLE
		    current.use_ssl = FLAG_TRUE;
#else
		    yyerror(GT_("SSL is not enabled"));
#endif 
		}
#line 2324 "rcfile_y.c"
    break;

  case 126: /* user_option: SSLKEY STRING  */
#line 343 "rcfile_y.y"
                                        {current.sslkey = prependdir ((yyvsp[0].sval), rcfiledir); free((yyvsp[0].sval));}
#line 2330 "rcfile_y.c"
    break;

  case 127: /* user_option: SSLCERT STRING  */
#line 344 "rcfile_y.y"
                                        {current.sslcert = prependdir ((yyvsp[0].sval), rcfiledir); free((yyvsp[0].sval));}
#line 2336 "rcfile_y.c"
    break;

  case 128: /* user_option: SSLPROTO STRING  */
#line 345 "rcfile_y.y"
                                        {current.sslproto = (yyvsp[0].sval);}
#line 2342 "rcfile_y.c"
    break;

  case 129: /* user_option: SSLCERTCK  */
#line 346 "rcfile_y.y"
                                        {current.sslcertck = FLAG_TRUE;}
#line 2348 "rcfile_y.c"
    break;

  case 130: /* user_option: SSLCERTFILE STRING  */
#line 347 "rcfile_y.y"
                                        {current.sslcertfile = prependdir((yyvsp[0].sval), rcfiledir); free((yyvsp[0].sval));}
#line 2354 "rcfile_y.c"
    break;

  case 131: /* user_option: SSLCERTPATH STRING  */
#line 348 "rcfile_y.y"
                                        {current.sslcertpath = prependdir((yyvsp[0].sval), rcfiledir); free((yyvsp[0].sval));}
#line 2360 "rcfile_y.c"
    break;

  case 132: /* user_option: SSLCOMMONNAME STRING  */
#line 349 "rcfile_y.y"
                                        {current.sslcommonname = (yyvsp[0].sval);}
#line 2366 "rcfile_y.c"
    break;

  case 133: /* user_option: SSLFINGERPRINT STRING  */
#line 350 "rcfile_y.y"
                                        {current.sslfingerprint = (yyvsp[0].sval);}
#line 2372 "rcfile_y.c"
    break;

  case 134: /* user_option: NO KEEP  */
#line 352 "rcfile_y.y"
                                        {current.keep        = FLAG_FALSE;}
#line 2378 "rcfile_y.c"
    break;

  case 135: /* user_option: NO FLUSH  */
#line 353 "rcfile_y.y"
                                        {current.flush       = FLAG_FALSE;}
#line 2384 "rcfile_y.c"
    break;

  case 136: /* user_option: NO LIMITFLUSH  */
#line 354 "rcfile_y.y"
                                        {current.limitflush  = FLAG_FALSE;}
#line 2390 "rcfile_y.c"
    break;

  case 137: /* user_option: NO FETCHALL  */
#line 355 "rcfile_y.y"
                                        {current.fetchall    = FLAG_FALSE;}
#line 2396 "rcfile_y.c"
    break;

  case 138: /* user_option: NO REWRITE  */
#line 356 "rcfile_y.y"
                                        {current.rewrite     = FLAG_FALSE;}
#line 2402 "rcfile_y.c"
    break;

  case 139: /* user_option: NO FORCECR  */
#line 357 "rcfile_y.y"
                                        {current.forcecr     = FLAG_FALSE;}
#line 2408 "rcfile_y.c"
    break;

  case 140: /* user_option: NO STRIPCR  */
#line 358 "rcfile_y.y"
                                        {current.stripcr     = FLAG_FALSE;}
#line 2414 "rcfile_y.c"
    break;

  case 141: /* user_option: NO PASS8BITS  */
#line 359 "rcfile_y.y"
                                        {current.pass8bits   = FLAG_FALSE;}
#line 2420 "rcfile_y.c"
    break;

  case 142: /* user_option: NO DROPSTATUS  */
#line 360 "rcfile_y.y"
                                        {current.dropstatus  = FLAG_FALSE;}
#line 2426 "rcfile_y.c"
    break;

  case 143: /* user_option: NO DROPDELIVERED  */
#line 361 "rcfile_y.y"
                                        {current.dropdelivered = FLAG_FALSE;}
#line 2432 "rcfile_y.c"
    break;

  case 144: /* user_option: NO MIMEDECODE  */
#line 362 "rcfile_y.y"
                                        {current.mimedecode  = FLAG_FALSE;}
#line 2438 "rcfile_y.c"
    break;

  case 145: /* user_option: NO IDLE  */
#line 363 "rcfile_y.y"
                                        {current.idle        = FLAG_FALSE;}
#line 2444 "rcfile_y.c"
    break;

  case 146: /* user_option: NO SSL  */
#line 365 "rcfile_y.y"
                                        {current.use_ssl     = FLAG_FALSE;}
#line 2450 "rcfile_y.c"
    break;

  case 147: /* user_option: NO SSLCERTCK  */
#line 366 "rcfile_y.y"
                                        {current.sslcertck   = FLAG_FALSE;}
#line 2456 "rcfile_y.c"
    break;

  case 148: /* user_option: LIMIT NUMBER  */
#line 368 "rcfile_y.y"
                                        {current.limit       = NUM_VALUE_IN((yyvsp[0].number));}
#line 2462 "rcfile_y.c"
    break;

  case 149: /* user_option: WARNINGS NUMBER  */
#line 369 "rcfile_y.y"
                                        {current.warnings    = NUM_VALUE_IN((yyvsp[0].number));}
#line 2468 "rcfile_y.c"
    break;

  case 150: /* user_option: FETCHLIMIT NUMBER  */
#line 370 "rcfile_y.y"
                                        {current.fetchlimit  = NUM_VALUE_IN((yyvsp[0].number));}
#line 2474 "rcfile_y.c"
    break;

  case 151: /* user_option: FETCHSIZELIMIT NUMBER  */
#line 371 "rcfile_y.y"
                                        {current.fetchsizelimit = NUM_VALUE_IN((yyvsp[0].number));}
#line 2480 "rcfile_y.c"
    break;

  case 152: /* user_option: FASTUIDL NUMBER  */
#line 372 "rcfile_y.y"
                                        {current.fastuidl    = NUM_VALUE_IN((yyvsp[0].number));}
#line 2486 "rcfile_y.c"
    break;

  case 153: /* user_option: BATCHLIMIT NUMBER  */
#line 373 "rcfile_y.y"
                                        {current.batchlimit  = NUM_VALUE_IN((yyvsp[0].number));}
#line 2492 "rcfile_y.c"
    break;

  case 154: /* user_option: EXPUNGE NUMBER  */
#line 374 "rcfile_y.y"
                                        {current.expunge     = NUM_VALUE_IN((yyvsp[0].number));}
#line 2498 "rcfile_y.c"
    break;

  case 155: /* user_option: PROPERTIES STRING  */
#line 376 "rcfile_y.y"
                                        {current.properties  = (yyvsp[0].sval);}
#line 2504 "rcfile_y.c"
    break;


#line 2508 "rcfile_y.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 378 "rcfile_y.y"


/* lexer interface */
extern char *rcfile;
extern int prc_lineno;
extern char *yytext;
extern FILE *yyin;

static struct query *hosttail;	/* where to add new elements */

void yyerror (const char *s)
/* report a syntax error */
{
    report_at_line(stderr, 0, rcfile, prc_lineno, GT_("%s at %s"), s, 
		   (yytext && yytext[0]) ? yytext : GT_("end of input"));
    prc_errflag++;
}

/** check that a configuration file is secure, returns PS_* status codes */
int prc_filecheck(const char *pathname,
		  const flag securecheck /** shortcuts permission, filetype and uid tests if false */)
{
#ifndef __EMX__
    struct stat statbuf;

    errno = 0;

    /* special case useful for debugging purposes */
    if (strcmp("/dev/null", pathname) == 0)
	return(PS_SUCCESS);

    /* pass through the special name for stdin */
    if (strcmp("-", pathname) == 0)
	return(PS_SUCCESS);

    /* the run control file must have the same uid as the REAL uid of this 
       process, it must have permissions no greater than 600, and it must not 
       be a symbolic link.  We check these conditions here. */

    if (stat(pathname, &statbuf) < 0) {
	if (errno == ENOENT) 
	    return(PS_SUCCESS);
	else {
	    report(stderr, "lstat: %s: %s\n", pathname, strerror(errno));
	    return(PS_IOERR);
	}
    }

    if (!securecheck)	return PS_SUCCESS;

    if (!S_ISREG(statbuf.st_mode))
    {
	fprintf(stderr, GT_("File %s must be a regular file.\n"), pathname);
	return(PS_IOERR);
    }

#ifndef __BEOS__
#ifdef __CYGWIN__
    if (cygwin_internal(CW_CHECK_NTSEC, pathname))
#endif /* __CYGWIN__ */
    if (statbuf.st_mode & (S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH | S_IXOTH))
    {
	fprintf(stderr, GT_("File %s must have no more than -rwx------ (0700) permissions.\n"), 
		pathname);
	return(PS_IOERR);
    }
#endif /* __BEOS__ */

#ifdef HAVE_GETEUID
    if (statbuf.st_uid != geteuid())
#else
    if (statbuf.st_uid != getuid())
#endif /* HAVE_GETEUID */
    {
	fprintf(stderr, GT_("File %s must be owned by you.\n"), pathname);
	return(PS_IOERR);
    }
#endif
    return(PS_SUCCESS);
}

int prc_parse_file (const char *pathname, const flag securecheck)
/* digest the configuration into a linked list of host records */
{
    prc_errflag = 0;
    querylist = hosttail = (struct query *)NULL;

    errno = 0;

    /* Check that the file is secure */
    if ( (prc_errflag = prc_filecheck(pathname, securecheck)) != 0 )
	return(prc_errflag);

    /*
     * Croak if the configuration directory does not exist.
     * This probably means an NFS mount failed and we can't
     * see a configuration file that ought to be there.
     * Question: is this a portable check? It's not clear
     * that all implementations of lstat() will return ENOTDIR
     * rather than plain ENOENT in this case...
     */
    if (errno == ENOTDIR)
	return(PS_IOERR);
    else if (errno == ENOENT)
	return(PS_SUCCESS);

    /* Open the configuration file and feed it to the lexer. */
    if (strcmp(pathname, "-") == 0)
	yyin = stdin;
    else if ((yyin = fopen(pathname,"r")) == (FILE *)NULL) {
	report(stderr, "open: %s: %s\n", pathname, strerror(errno));
	return(PS_IOERR);
    }

    yyparse();		/* parse entire file */

    if (yyin != stdin)
       fclose(yyin);	/* not checking this should be safe, file mode was r */

    if (prc_errflag) 
	return(PS_SYNTAX);
    else
	return(PS_SUCCESS);
}

static void reset_server(const char *name, int skip)
/* clear the entire global record and initialize it with a new name */
{
    trailer = FALSE;
    memset(&current,'\0',sizeof(current));
    current.smtp_socket = -1;
    current.server.pollname = xstrdup(name);
    current.server.skip = skip;
    current.server.principal = (char *)NULL;
}


static void user_reset(void)
/* clear the global current record (user parameters) used by the parser */
{
    struct hostdata save;

    /*
     * Purpose of this code is to initialize the new server block, but
     * preserve whatever server name was previously set.  Also
     * preserve server options unless the command-line explicitly
     * overrides them.
     */
    save = current.server;

    memset(&current, '\0', sizeof(current));
    current.smtp_socket = -1;

    current.server = save;
}

/** append a host record to the host list */
struct query *hostalloc(struct query *init /** pointer to block containing
					       initial values */)
{
    struct query *node;

    /* allocate new node */
    node = (struct query *) xmalloc(sizeof(struct query));

    /* initialize it */
    if (init)
	memcpy(node, init, sizeof(struct query));
    else
    {
	memset(node, '\0', sizeof(struct query));
	node->smtp_socket = -1;
    }

    /* append to end of list */
    if (hosttail != (struct query *) 0)
	hosttail->next = node;	/* list contains at least one element */
    else
	querylist = node;	/* list is empty */
    hosttail = node;

    if (trailer)
	node->server.lead_server = leadentry;
    else
    {
	node->server.lead_server = NULL;
	leadentry = &node->server;
    }

    return(node);
}

static void record_current(void)
/* register current parameters and append to the host list */
{
    (void) hostalloc(&current);
    trailer = TRUE;
}

char *prependdir (const char *file, const char *dir)
/* if a filename is relative to dir, convert it to an absolute path */
{
    char *newfile;
    if (!file[0] ||			/* null path */
	file[0] == '/' ||		/* absolute path */
	strcmp(file, "-") == 0 ||	/* stdin/stdout */
	!dir[0])			/* we don't HAVE_GETCWD */
	return xstrdup (file);
    newfile = (char *)xmalloc (strlen (dir) + 1 + strlen (file) + 1);
    if (dir[strlen(dir) - 1] != '/')
	sprintf (newfile, "%s/%s", dir, file);
    else
	sprintf (newfile, "%s%s", dir, file);
    return newfile;
}

/* rcfile_y.y ends here */
