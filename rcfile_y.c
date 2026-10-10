/* A Bison parser, made by GNU Bison 3.7.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON 30704

/* Bison version string.  */
#define YYBISON_VERSION "3.7.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "../rcfile_y.y"

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

#line 127 "../rcfile_y.c"

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
#ifndef YY_YY__RCFILE_Y_H_INCLUDED
# define YY_YY__RCFILE_Y_H_INCLUDED
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
    FOLDER = 273,                  /* FOLDER  */
    SMTPHOST = 274,                /* SMTPHOST  */
    FETCHDOMAINS = 275,            /* FETCHDOMAINS  */
    MDA = 276,                     /* MDA  */
    BSMTP = 277,                   /* BSMTP  */
    LMTP = 278,                    /* LMTP  */
    SMTPADDRESS = 279,             /* SMTPADDRESS  */
    SMTPNAME = 280,                /* SMTPNAME  */
    SPAMRESPONSE = 281,            /* SPAMRESPONSE  */
    PRECONNECT = 282,              /* PRECONNECT  */
    POSTCONNECT = 283,             /* POSTCONNECT  */
    LIMIT = 284,                   /* LIMIT  */
    WARNINGS = 285,                /* WARNINGS  */
    INTERFACE = 286,               /* INTERFACE  */
    MONITOR = 287,                 /* MONITOR  */
    PLUGIN = 288,                  /* PLUGIN  */
    PLUGOUT = 289,                 /* PLUGOUT  */
    IS = 290,                      /* IS  */
    HERE = 291,                    /* HERE  */
    THERE = 292,                   /* THERE  */
    TO = 293,                      /* TO  */
    MAP = 294,                     /* MAP  */
    BATCHLIMIT = 295,              /* BATCHLIMIT  */
    FETCHLIMIT = 296,              /* FETCHLIMIT  */
    FETCHSIZELIMIT = 297,          /* FETCHSIZELIMIT  */
    FASTUIDL = 298,                /* FASTUIDL  */
    EXPUNGE = 299,                 /* EXPUNGE  */
    PROPERTIES = 300,              /* PROPERTIES  */
    SET = 301,                     /* SET  */
    LOGFILE = 302,                 /* LOGFILE  */
    DAEMON = 303,                  /* DAEMON  */
    SYSLOG = 304,                  /* SYSLOG  */
    IDFILE = 305,                  /* IDFILE  */
    PIDFILE = 306,                 /* PIDFILE  */
    INVISIBLE = 307,               /* INVISIBLE  */
    POSTMASTER = 308,              /* POSTMASTER  */
    BOUNCEMAIL = 309,              /* BOUNCEMAIL  */
    SPAMBOUNCE = 310,              /* SPAMBOUNCE  */
    SOFTBOUNCE = 311,              /* SOFTBOUNCE  */
    SHOWDOTS = 312,                /* SHOWDOTS  */
    BADHEADER = 313,               /* BADHEADER  */
    ACCEPT = 314,                  /* ACCEPT  */
    REJECT_ = 315,                 /* REJECT_  */
    PROTO = 316,                   /* PROTO  */
    AUTHTYPE = 317,                /* AUTHTYPE  */
    STRING = 318,                  /* STRING  */
    NUMBER = 319,                  /* NUMBER  */
    NO = 320,                      /* NO  */
    KEEP = 321,                    /* KEEP  */
    FLUSH = 322,                   /* FLUSH  */
    LIMITFLUSH = 323,              /* LIMITFLUSH  */
    FETCHALL = 324,                /* FETCHALL  */
    REWRITE = 325,                 /* REWRITE  */
    FORCECR = 326,                 /* FORCECR  */
    STRIPCR = 327,                 /* STRIPCR  */
    PASS8BITS = 328,               /* PASS8BITS  */
    DROPSTATUS = 329,              /* DROPSTATUS  */
    DROPDELIVERED = 330,           /* DROPDELIVERED  */
    DNS = 331,                     /* DNS  */
    SERVICE = 332,                 /* SERVICE  */
    PORT = 333,                    /* PORT  */
    UIDL = 334,                    /* UIDL  */
    INTERVAL = 335,                /* INTERVAL  */
    MIMEDECODE = 336,              /* MIMEDECODE  */
    IDLE = 337,                    /* IDLE  */
    CHECKALIAS = 338,              /* CHECKALIAS  */
    SSL = 339,                     /* SSL  */
    SSLKEY = 340,                  /* SSLKEY  */
    SSLCERT = 341,                 /* SSLCERT  */
    SSLPROTO = 342,                /* SSLPROTO  */
    SSLCERTCK = 343,               /* SSLCERTCK  */
    SSLCERTFILE = 344,             /* SSLCERTFILE  */
    SSLCERTPATH = 345,             /* SSLCERTPATH  */
    SSLCOMMONNAME = 346,           /* SSLCOMMONNAME  */
    SSLFINGERPRINT = 347,          /* SSLFINGERPRINT  */
    PRINCIPAL = 348,               /* PRINCIPAL  */
    ESMTPNAME = 349,               /* ESMTPNAME  */
    ESMTPPASSWORD = 350,           /* ESMTPPASSWORD  */
    TRACEPOLLS = 351               /* TRACEPOLLS  */
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
#define FOLDER 273
#define SMTPHOST 274
#define FETCHDOMAINS 275
#define MDA 276
#define BSMTP 277
#define LMTP 278
#define SMTPADDRESS 279
#define SMTPNAME 280
#define SPAMRESPONSE 281
#define PRECONNECT 282
#define POSTCONNECT 283
#define LIMIT 284
#define WARNINGS 285
#define INTERFACE 286
#define MONITOR 287
#define PLUGIN 288
#define PLUGOUT 289
#define IS 290
#define HERE 291
#define THERE 292
#define TO 293
#define MAP 294
#define BATCHLIMIT 295
#define FETCHLIMIT 296
#define FETCHSIZELIMIT 297
#define FASTUIDL 298
#define EXPUNGE 299
#define PROPERTIES 300
#define SET 301
#define LOGFILE 302
#define DAEMON 303
#define SYSLOG 304
#define IDFILE 305
#define PIDFILE 306
#define INVISIBLE 307
#define POSTMASTER 308
#define BOUNCEMAIL 309
#define SPAMBOUNCE 310
#define SOFTBOUNCE 311
#define SHOWDOTS 312
#define BADHEADER 313
#define ACCEPT 314
#define REJECT_ 315
#define PROTO 316
#define AUTHTYPE 317
#define STRING 318
#define NUMBER 319
#define NO 320
#define KEEP 321
#define FLUSH 322
#define LIMITFLUSH 323
#define FETCHALL 324
#define REWRITE 325
#define FORCECR 326
#define STRIPCR 327
#define PASS8BITS 328
#define DROPSTATUS 329
#define DROPDELIVERED 330
#define DNS 331
#define SERVICE 332
#define PORT 333
#define UIDL 334
#define INTERVAL 335
#define MIMEDECODE 336
#define IDLE 337
#define CHECKALIAS 338
#define SSL 339
#define SSLKEY 340
#define SSLCERT 341
#define SSLPROTO 342
#define SSLCERTCK 343
#define SSLCERTFILE 344
#define SSLCERTPATH 345
#define SSLCOMMONNAME 346
#define SSLFINGERPRINT 347
#define PRINCIPAL 348
#define ESMTPNAME 349
#define ESMTPPASSWORD 350
#define TRACEPOLLS 351

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 57 "../rcfile_y.y"

  int proto;
  int number;
  char *sval;

#line 378 "../rcfile_y.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY__RCFILE_Y_H_INCLUDED  */
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
  YYSYMBOL_FOLDER = 18,                    /* FOLDER  */
  YYSYMBOL_SMTPHOST = 19,                  /* SMTPHOST  */
  YYSYMBOL_FETCHDOMAINS = 20,              /* FETCHDOMAINS  */
  YYSYMBOL_MDA = 21,                       /* MDA  */
  YYSYMBOL_BSMTP = 22,                     /* BSMTP  */
  YYSYMBOL_LMTP = 23,                      /* LMTP  */
  YYSYMBOL_SMTPADDRESS = 24,               /* SMTPADDRESS  */
  YYSYMBOL_SMTPNAME = 25,                  /* SMTPNAME  */
  YYSYMBOL_SPAMRESPONSE = 26,              /* SPAMRESPONSE  */
  YYSYMBOL_PRECONNECT = 27,                /* PRECONNECT  */
  YYSYMBOL_POSTCONNECT = 28,               /* POSTCONNECT  */
  YYSYMBOL_LIMIT = 29,                     /* LIMIT  */
  YYSYMBOL_WARNINGS = 30,                  /* WARNINGS  */
  YYSYMBOL_INTERFACE = 31,                 /* INTERFACE  */
  YYSYMBOL_MONITOR = 32,                   /* MONITOR  */
  YYSYMBOL_PLUGIN = 33,                    /* PLUGIN  */
  YYSYMBOL_PLUGOUT = 34,                   /* PLUGOUT  */
  YYSYMBOL_IS = 35,                        /* IS  */
  YYSYMBOL_HERE = 36,                      /* HERE  */
  YYSYMBOL_THERE = 37,                     /* THERE  */
  YYSYMBOL_TO = 38,                        /* TO  */
  YYSYMBOL_MAP = 39,                       /* MAP  */
  YYSYMBOL_BATCHLIMIT = 40,                /* BATCHLIMIT  */
  YYSYMBOL_FETCHLIMIT = 41,                /* FETCHLIMIT  */
  YYSYMBOL_FETCHSIZELIMIT = 42,            /* FETCHSIZELIMIT  */
  YYSYMBOL_FASTUIDL = 43,                  /* FASTUIDL  */
  YYSYMBOL_EXPUNGE = 44,                   /* EXPUNGE  */
  YYSYMBOL_PROPERTIES = 45,                /* PROPERTIES  */
  YYSYMBOL_SET = 46,                       /* SET  */
  YYSYMBOL_LOGFILE = 47,                   /* LOGFILE  */
  YYSYMBOL_DAEMON = 48,                    /* DAEMON  */
  YYSYMBOL_SYSLOG = 49,                    /* SYSLOG  */
  YYSYMBOL_IDFILE = 50,                    /* IDFILE  */
  YYSYMBOL_PIDFILE = 51,                   /* PIDFILE  */
  YYSYMBOL_INVISIBLE = 52,                 /* INVISIBLE  */
  YYSYMBOL_POSTMASTER = 53,                /* POSTMASTER  */
  YYSYMBOL_BOUNCEMAIL = 54,                /* BOUNCEMAIL  */
  YYSYMBOL_SPAMBOUNCE = 55,                /* SPAMBOUNCE  */
  YYSYMBOL_SOFTBOUNCE = 56,                /* SOFTBOUNCE  */
  YYSYMBOL_SHOWDOTS = 57,                  /* SHOWDOTS  */
  YYSYMBOL_BADHEADER = 58,                 /* BADHEADER  */
  YYSYMBOL_ACCEPT = 59,                    /* ACCEPT  */
  YYSYMBOL_REJECT_ = 60,                   /* REJECT_  */
  YYSYMBOL_PROTO = 61,                     /* PROTO  */
  YYSYMBOL_AUTHTYPE = 62,                  /* AUTHTYPE  */
  YYSYMBOL_STRING = 63,                    /* STRING  */
  YYSYMBOL_NUMBER = 64,                    /* NUMBER  */
  YYSYMBOL_NO = 65,                        /* NO  */
  YYSYMBOL_KEEP = 66,                      /* KEEP  */
  YYSYMBOL_FLUSH = 67,                     /* FLUSH  */
  YYSYMBOL_LIMITFLUSH = 68,                /* LIMITFLUSH  */
  YYSYMBOL_FETCHALL = 69,                  /* FETCHALL  */
  YYSYMBOL_REWRITE = 70,                   /* REWRITE  */
  YYSYMBOL_FORCECR = 71,                   /* FORCECR  */
  YYSYMBOL_STRIPCR = 72,                   /* STRIPCR  */
  YYSYMBOL_PASS8BITS = 73,                 /* PASS8BITS  */
  YYSYMBOL_DROPSTATUS = 74,                /* DROPSTATUS  */
  YYSYMBOL_DROPDELIVERED = 75,             /* DROPDELIVERED  */
  YYSYMBOL_DNS = 76,                       /* DNS  */
  YYSYMBOL_SERVICE = 77,                   /* SERVICE  */
  YYSYMBOL_PORT = 78,                      /* PORT  */
  YYSYMBOL_UIDL = 79,                      /* UIDL  */
  YYSYMBOL_INTERVAL = 80,                  /* INTERVAL  */
  YYSYMBOL_MIMEDECODE = 81,                /* MIMEDECODE  */
  YYSYMBOL_IDLE = 82,                      /* IDLE  */
  YYSYMBOL_CHECKALIAS = 83,                /* CHECKALIAS  */
  YYSYMBOL_SSL = 84,                       /* SSL  */
  YYSYMBOL_SSLKEY = 85,                    /* SSLKEY  */
  YYSYMBOL_SSLCERT = 86,                   /* SSLCERT  */
  YYSYMBOL_SSLPROTO = 87,                  /* SSLPROTO  */
  YYSYMBOL_SSLCERTCK = 88,                 /* SSLCERTCK  */
  YYSYMBOL_SSLCERTFILE = 89,               /* SSLCERTFILE  */
  YYSYMBOL_SSLCERTPATH = 90,               /* SSLCERTPATH  */
  YYSYMBOL_SSLCOMMONNAME = 91,             /* SSLCOMMONNAME  */
  YYSYMBOL_SSLFINGERPRINT = 92,            /* SSLFINGERPRINT  */
  YYSYMBOL_PRINCIPAL = 93,                 /* PRINCIPAL  */
  YYSYMBOL_ESMTPNAME = 94,                 /* ESMTPNAME  */
  YYSYMBOL_ESMTPPASSWORD = 95,             /* ESMTPPASSWORD  */
  YYSYMBOL_TRACEPOLLS = 96,                /* TRACEPOLLS  */
  YYSYMBOL_YYACCEPT = 97,                  /* $accept  */
  YYSYMBOL_rcfile = 98,                    /* rcfile  */
  YYSYMBOL_statement_list = 99,            /* statement_list  */
  YYSYMBOL_optmap = 100,                   /* optmap  */
  YYSYMBOL_statement = 101,                /* statement  */
  YYSYMBOL_define_server = 102,            /* define_server  */
  YYSYMBOL_serverspecs = 103,              /* serverspecs  */
  YYSYMBOL_alias_list = 104,               /* alias_list  */
  YYSYMBOL_domain_list = 105,              /* domain_list  */
  YYSYMBOL_serv_option = 106,              /* serv_option  */
  YYSYMBOL_userspecs = 107,                /* userspecs  */
  YYSYMBOL_explicits = 108,                /* explicits  */
  YYSYMBOL_explicitdef = 109,              /* explicitdef  */
  YYSYMBOL_userdef = 110,                  /* userdef  */
  YYSYMBOL_user0opts = 111,                /* user0opts  */
  YYSYMBOL_user1opts = 112,                /* user1opts  */
  YYSYMBOL_mapping_list = 113,             /* mapping_list  */
  YYSYMBOL_mapping = 114,                  /* mapping  */
  YYSYMBOL_folder_list = 115,              /* folder_list  */
  YYSYMBOL_smtp_list = 116,                /* smtp_list  */
  YYSYMBOL_fetch_list = 117,               /* fetch_list  */
  YYSYMBOL_num_list = 118,                 /* num_list  */
  YYSYMBOL_user_option = 119               /* user_option  */
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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYLAST   333

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  97
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  154
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  225

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   351


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
      95,    96
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
     319,   320,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   335,   342,   343,   344,   345,   346,
     347,   348,   349,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   364,   365,   367,   368,   369,
     370,   371,   372,   373,   375
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
  "PASSWORD", "FOLDER", "SMTPHOST", "FETCHDOMAINS", "MDA", "BSMTP", "LMTP",
  "SMTPADDRESS", "SMTPNAME", "SPAMRESPONSE", "PRECONNECT", "POSTCONNECT",
  "LIMIT", "WARNINGS", "INTERFACE", "MONITOR", "PLUGIN", "PLUGOUT", "IS",
  "HERE", "THERE", "TO", "MAP", "BATCHLIMIT", "FETCHLIMIT",
  "FETCHSIZELIMIT", "FASTUIDL", "EXPUNGE", "PROPERTIES", "SET", "LOGFILE",
  "DAEMON", "SYSLOG", "IDFILE", "PIDFILE", "INVISIBLE", "POSTMASTER",
  "BOUNCEMAIL", "SPAMBOUNCE", "SOFTBOUNCE", "SHOWDOTS", "BADHEADER",
  "ACCEPT", "REJECT_", "PROTO", "AUTHTYPE", "STRING", "NUMBER", "NO",
  "KEEP", "FLUSH", "LIMITFLUSH", "FETCHALL", "REWRITE", "FORCECR",
  "STRIPCR", "PASS8BITS", "DROPSTATUS", "DROPDELIVERED", "DNS", "SERVICE",
  "PORT", "UIDL", "INTERVAL", "MIMEDECODE", "IDLE", "CHECKALIAS", "SSL",
  "SSLKEY", "SSLCERT", "SSLPROTO", "SSLCERTCK", "SSLCERTFILE",
  "SSLCERTPATH", "SSLCOMMONNAME", "SSLFINGERPRINT", "PRINCIPAL",
  "ESMTPNAME", "ESMTPPASSWORD", "TRACEPOLLS", "$accept", "rcfile",
  "statement_list", "optmap", "statement", "define_server", "serverspecs",
  "alias_list", "domain_list", "serv_option", "userspecs", "explicits",
  "explicitdef", "userdef", "user0opts", "user1opts", "mapping_list",
  "mapping", "folder_list", "smtp_list", "fetch_list", "num_list",
  "user_option", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351
};
#endif

#define YYPACT_NINF (-114)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-86)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      54,  -114,   -55,   -16,   268,    41,    54,  -114,  -114,  -114,
    -114,    15,    15,    15,  -114,    15,    15,  -114,    15,  -114,
    -114,  -114,  -114,    86,  -114,  -114,    -5,  -114,    47,    55,
      48,    60,    62,    63,  -114,  -114,  -114,  -114,  -114,  -114,
      64,    66,    67,    31,    72,    80,   -32,    68,    82,    84,
      85,    87,    89,    91,    92,  -114,    93,    94,    95,    97,
      98,    99,   105,   107,   109,   110,   111,   112,   113,   114,
     115,   116,   132,   133,   136,    -4,   119,  -114,  -114,  -114,
    -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,    51,   140,
    -114,   141,  -114,  -114,  -114,  -114,   143,   145,   146,  -114,
     147,   148,   149,   150,   151,   167,   168,  -114,  -114,    88,
     135,  -114,  -114,   199,  -114,  -114,  -114,  -114,  -114,  -114,
    -114,  -114,  -114,   169,  -114,   170,  -114,  -114,  -114,  -114,
    -114,  -114,   172,  -114,    69,   -29,  -114,  -114,  -114,   173,
    -114,   175,  -114,   182,  -114,  -114,  -114,  -114,  -114,   183,
    -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,    13,    65,
     123,    73,  -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,
    -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,
    -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,
    -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,
    -114,  -114,  -114,    28,  -114,  -114,   199,   226,  -114,  -114,
    -114,  -114,  -114,   185,  -114,  -114,  -114,  -114,  -114,  -114,
    -114,  -114,  -114,  -114,  -114
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
       0,     0,     0,     0,     0,   109,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,    64,     0,     0,
      47,     0,   122,   123,    49,   124,     0,     0,     0,   128,
       0,     0,     0,     0,     0,     0,     0,    67,    33,    27,
      72,    73,    79,    71,    81,    19,     8,    11,     9,    10,
      12,    39,    34,    38,    36,    40,    42,    46,    41,    55,
      56,    58,     0,    59,    76,     0,    83,   100,    87,   101,
      89,   102,    91,   103,   107,   108,   104,   105,    93,   106,
     110,   111,   147,   148,    60,    61,    62,    63,    85,    98,
      85,    96,   152,   149,   150,   151,   153,   154,    69,    70,
      66,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,    65,    48,   143,   144,    50,   145,   146,    68,    51,
      52,    53,    54,   125,   126,   127,   129,   130,   131,   132,
      43,    44,    45,     0,    28,    74,    75,     0,    82,    35,
      37,    57,    78,     0,    77,    84,    88,    90,    92,    94,
      99,    97,    95,    80,    86
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -114,  -114,  -114,    33,   152,  -114,  -114,  -114,  -114,    40,
    -114,  -114,   139,  -114,  -114,  -114,    49,   -22,  -114,  -114,
    -114,  -114,  -113
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,    28,     7,     8,    26,   123,   125,   108,
     109,   110,   111,   112,   206,   113,   135,   136,   139,   141,
     143,   149,   114
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     208,    40,    41,    42,    43,    44,    45,   214,     9,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,   131,   132,    68,   160,    69,    70,    71,    72,    73,
      74,    24,   170,   126,   127,    29,    30,    10,    31,    32,
     220,    33,   213,    75,    27,   168,   169,     1,     2,     3,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   128,   223,    40,    41,    42,    43,    44,    45,
       4,   221,    46,    47,   181,   -85,   212,   182,   213,   222,
     115,   185,   117,   215,   189,   190,   159,   161,   116,    63,
      64,    65,    66,   118,   188,   119,   120,   121,   160,   122,
     124,   133,   -85,   170,   129,    34,   160,   215,    35,   215,
      36,    37,    38,    39,   130,   134,    75,   137,   138,   204,
     140,    48,   142,   203,   144,   145,   146,   147,    25,   148,
     150,   151,   213,   152,    87,    88,    89,    90,    91,   153,
     154,    94,   155,   156,   157,   158,   160,     0,   162,   163,
     164,   104,   105,   106,   107,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   165,   166,   182,   167,
     183,   184,   185,   186,   191,   192,   193,   187,   194,   195,
     196,   197,   198,   199,   200,   188,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
     201,   202,   209,   210,    67,   211,   216,    68,   217,    69,
      70,    71,    72,    73,    74,   218,     0,   219,   224,   205,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   207,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,     0,     0,     0,     0,     0,
      92,    93,     0,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,     0,     0,     0,     0,     0,   183,   184,     0,
     186,     0,     0,    11,   187,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,     0,     0,     0,     0,
       0,     0,     0,    23
};

static const yytype_int16 yycheck[] =
{
     113,     6,     7,     8,     9,    10,    11,    36,    63,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    63,    64,    38,    63,    40,    41,    42,    43,    44,
      45,     0,    14,    12,    13,    12,    13,    63,    15,    16,
      37,    18,    39,    58,    39,    59,    60,     3,     4,     5,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    61,   206,     6,     7,     8,     9,    10,    11,
      46,    36,    14,    15,    76,    36,    37,    79,    39,    36,
      63,    83,    64,   135,    63,    64,    67,    68,    63,    31,
      32,    33,    34,    63,    96,    63,    63,    63,    63,    63,
      63,    63,    63,    14,    62,    49,    63,   159,    52,   161,
      54,    55,    56,    57,    64,    63,    58,    63,    63,   109,
      63,    16,    63,    65,    63,    63,    63,    63,     6,    64,
      63,    63,    39,    64,    76,    77,    78,    79,    80,    64,
      63,    83,    63,    63,    63,    63,    63,    -1,    64,    64,
      64,    93,    94,    95,    96,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    64,    64,    79,    63,
      81,    82,    83,    84,    64,    64,    63,    88,    63,    63,
      63,    63,    63,    63,    63,    96,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      63,    63,    63,    63,    35,    63,    63,    38,    63,    40,
      41,    42,    43,    44,    45,    63,    -1,    64,    63,   110,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,
      81,    82,    -1,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    -1,    -1,    -1,    -1,    -1,    81,    82,    -1,
      84,    -1,    -1,    45,    88,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    65
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,    46,    98,    99,   101,   102,    63,
      63,    45,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    65,     0,   101,   103,    39,   100,   100,
     100,   100,   100,   100,    49,    52,    54,    55,    56,    57,
       6,     7,     8,     9,    10,    11,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    38,    40,
      41,    42,    43,    44,    45,    58,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,   106,   107,
     108,   109,   110,   112,   119,    63,    63,    64,    63,    63,
      63,    63,    63,   104,    63,   105,    12,    13,    61,    62,
      64,    63,    64,    63,    63,   113,   114,    63,    63,   115,
      63,   116,    63,   117,    63,    63,    63,    63,    64,   118,
      63,    63,    64,    64,    63,    63,    63,    63,    63,   113,
      63,   113,    64,    64,    64,    64,    64,    63,    59,    60,
      14,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    79,    81,    82,    83,    84,    88,    96,    63,
      64,    64,    64,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    65,   106,   109,   111,    65,   119,    63,
      63,    63,    37,    39,    36,   114,    63,    63,    63,    64,
      37,    36,    36,   119,    63
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    97,    98,    98,    99,    99,   100,   100,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   102,
     102,   102,   103,   103,   104,   104,   105,   105,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   107,   107,   108,   108,   109,   110,   110,   110,   111,
     111,   112,   112,   113,   113,   114,   114,   115,   115,   116,
     116,   117,   117,   118,   118,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


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
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yykind)
    {
    case YYSYMBOL_STRING: /* STRING  */
#line 85 "../rcfile_y.y"
            { free (((*yyvaluep).sval)); }
#line 1417 "../rcfile_y.c"
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
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
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
#line 100 "../rcfile_y.y"
                                                {run.logfile = prependdir ((yyvsp[0].sval), rcfiledir); free((yyvsp[0].sval));}
#line 1685 "../rcfile_y.c"
    break;

  case 9: /* statement: SET IDFILE optmap STRING  */
#line 101 "../rcfile_y.y"
                                                {run.idfile = prependdir ((yyvsp[0].sval), rcfiledir); free((yyvsp[0].sval));}
#line 1691 "../rcfile_y.c"
    break;

  case 10: /* statement: SET PIDFILE optmap STRING  */
#line 102 "../rcfile_y.y"
                                                {run.pidfile = prependdir ((yyvsp[0].sval), rcfiledir); free((yyvsp[0].sval));}
#line 1697 "../rcfile_y.c"
    break;

  case 11: /* statement: SET DAEMON optmap NUMBER  */
#line 103 "../rcfile_y.y"
                                                {run.poll_interval = (yyvsp[0].number);}
#line 1703 "../rcfile_y.c"
    break;

  case 12: /* statement: SET POSTMASTER optmap STRING  */
#line 104 "../rcfile_y.y"
                                                {run.postmaster = (yyvsp[0].sval);}
#line 1709 "../rcfile_y.c"
    break;

  case 13: /* statement: SET BOUNCEMAIL  */
#line 105 "../rcfile_y.y"
                                                {run.bouncemail = TRUE;}
#line 1715 "../rcfile_y.c"
    break;

  case 14: /* statement: SET NO BOUNCEMAIL  */
#line 106 "../rcfile_y.y"
                                                {run.bouncemail = FALSE;}
#line 1721 "../rcfile_y.c"
    break;

  case 15: /* statement: SET SPAMBOUNCE  */
#line 107 "../rcfile_y.y"
                                                {run.spambounce = TRUE;}
#line 1727 "../rcfile_y.c"
    break;

  case 16: /* statement: SET NO SPAMBOUNCE  */
#line 108 "../rcfile_y.y"
                                                {run.spambounce = FALSE;}
#line 1733 "../rcfile_y.c"
    break;

  case 17: /* statement: SET SOFTBOUNCE  */
#line 109 "../rcfile_y.y"
                                                {run.softbounce = TRUE;}
#line 1739 "../rcfile_y.c"
    break;

  case 18: /* statement: SET NO SOFTBOUNCE  */
#line 110 "../rcfile_y.y"
                                                {run.softbounce = FALSE;}
#line 1745 "../rcfile_y.c"
    break;

  case 19: /* statement: SET PROPERTIES optmap STRING  */
#line 111 "../rcfile_y.y"
                                                {run.properties = (yyvsp[0].sval);}
#line 1751 "../rcfile_y.c"
    break;

  case 20: /* statement: SET SYSLOG  */
#line 112 "../rcfile_y.y"
                                                {run.use_syslog = TRUE;}
#line 1757 "../rcfile_y.c"
    break;

  case 21: /* statement: SET NO SYSLOG  */
#line 113 "../rcfile_y.y"
                                                {run.use_syslog = FALSE;}
#line 1763 "../rcfile_y.c"
    break;

  case 22: /* statement: SET INVISIBLE  */
#line 114 "../rcfile_y.y"
                                                {run.invisible = TRUE;}
#line 1769 "../rcfile_y.c"
    break;

  case 23: /* statement: SET NO INVISIBLE  */
#line 115 "../rcfile_y.y"
                                                {run.invisible = FALSE;}
#line 1775 "../rcfile_y.c"
    break;

  case 24: /* statement: SET SHOWDOTS  */
#line 116 "../rcfile_y.y"
                                                {run.showdots = FLAG_TRUE;}
#line 1781 "../rcfile_y.c"
    break;

  case 25: /* statement: SET NO SHOWDOTS  */
#line 117 "../rcfile_y.y"
                                                {run.showdots = FLAG_FALSE;}
#line 1787 "../rcfile_y.c"
    break;

  case 26: /* statement: define_server serverspecs  */
#line 125 "../rcfile_y.y"
                                                        {record_current();}
#line 1793 "../rcfile_y.c"
    break;

  case 28: /* statement: define_server serverspecs userspecs serv_option  */
#line 130 "../rcfile_y.y"
                        {yyerror(GT_("server option after user options"));}
#line 1799 "../rcfile_y.c"
    break;

  case 29: /* define_server: POLL STRING  */
#line 133 "../rcfile_y.y"
                                        {reset_server((yyvsp[0].sval), FALSE); free((yyvsp[0].sval));}
#line 1805 "../rcfile_y.c"
    break;

  case 30: /* define_server: SKIP STRING  */
#line 134 "../rcfile_y.y"
                                        {reset_server((yyvsp[0].sval), TRUE);  free((yyvsp[0].sval));}
#line 1811 "../rcfile_y.c"
    break;

  case 31: /* define_server: DEFAULTS  */
#line 135 "../rcfile_y.y"
                                        {reset_server("defaults", FALSE);}
#line 1817 "../rcfile_y.c"
    break;

  case 34: /* alias_list: STRING  */
#line 142 "../rcfile_y.y"
                                        {save_str(&current.server.akalist,(yyvsp[0].sval),0); free((yyvsp[0].sval));}
#line 1823 "../rcfile_y.c"
    break;

  case 35: /* alias_list: alias_list STRING  */
#line 143 "../rcfile_y.y"
                                        {save_str(&current.server.akalist,(yyvsp[0].sval),0); free((yyvsp[0].sval));}
#line 1829 "../rcfile_y.c"
    break;

  case 36: /* domain_list: STRING  */
#line 146 "../rcfile_y.y"
                                        {save_str(&current.server.localdomains,(yyvsp[0].sval),0); free((yyvsp[0].sval));}
#line 1835 "../rcfile_y.c"
    break;

  case 37: /* domain_list: domain_list STRING  */
#line 147 "../rcfile_y.y"
                                        {save_str(&current.server.localdomains,(yyvsp[0].sval),0); free((yyvsp[0].sval));}
#line 1841 "../rcfile_y.c"
    break;

  case 39: /* serv_option: VIA STRING  */
#line 151 "../rcfile_y.y"
                                        {current.server.via = (yyvsp[0].sval);}
#line 1847 "../rcfile_y.c"
    break;

  case 41: /* serv_option: PROTOCOL PROTO  */
#line 153 "../rcfile_y.y"
                                        {current.server.protocol = (yyvsp[0].proto);}
#line 1853 "../rcfile_y.c"
    break;

  case 42: /* serv_option: PROTOCOL KPOP  */
#line 154 "../rcfile_y.y"
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
#line 1869 "../rcfile_y.c"
    break;

  case 43: /* serv_option: PRINCIPAL STRING  */
#line 165 "../rcfile_y.y"
                                        {current.server.principal = (yyvsp[0].sval);}
#line 1875 "../rcfile_y.c"
    break;

  case 44: /* serv_option: ESMTPNAME STRING  */
#line 166 "../rcfile_y.y"
                                        {current.server.esmtp_name = (yyvsp[0].sval);}
#line 1881 "../rcfile_y.c"
    break;

  case 45: /* serv_option: ESMTPPASSWORD STRING  */
#line 167 "../rcfile_y.y"
                                        {current.server.esmtp_password = (yyvsp[0].sval);}
#line 1887 "../rcfile_y.c"
    break;

  case 46: /* serv_option: PROTOCOL SDPS  */
#line 168 "../rcfile_y.y"
                                        {
#ifdef SDPS_ENABLE
					    current.server.protocol = P_POP3;
					    current.server.sdps = TRUE;
#else
					    yyerror(GT_("SDPS not enabled."));
#endif /* SDPS_ENABLE */
					}
#line 1900 "../rcfile_y.c"
    break;

  case 47: /* serv_option: UIDL  */
#line 176 "../rcfile_y.y"
                                        {current.server.uidl = FLAG_TRUE;}
#line 1906 "../rcfile_y.c"
    break;

  case 48: /* serv_option: NO UIDL  */
#line 177 "../rcfile_y.y"
                                        {current.server.uidl  = FLAG_FALSE;}
#line 1912 "../rcfile_y.c"
    break;

  case 49: /* serv_option: CHECKALIAS  */
#line 178 "../rcfile_y.y"
                                        {current.server.checkalias = FLAG_TRUE;}
#line 1918 "../rcfile_y.c"
    break;

  case 50: /* serv_option: NO CHECKALIAS  */
#line 179 "../rcfile_y.y"
                                        {current.server.checkalias  = FLAG_FALSE;}
#line 1924 "../rcfile_y.c"
    break;

  case 51: /* serv_option: SERVICE STRING  */
#line 180 "../rcfile_y.y"
                                        {
					current.server.service = (yyvsp[0].sval);
					}
#line 1932 "../rcfile_y.c"
    break;

  case 52: /* serv_option: SERVICE NUMBER  */
#line 183 "../rcfile_y.y"
                                        {
					int port = (yyvsp[0].number);
					char buf[10];
					snprintf(buf, sizeof buf, "%d", port);
					current.server.service = xstrdup(buf);
		}
#line 1943 "../rcfile_y.c"
    break;

  case 53: /* serv_option: PORT NUMBER  */
#line 189 "../rcfile_y.y"
                                        {
					int port = (yyvsp[0].number);
					char buf[10];
					snprintf(buf, sizeof buf, "%d", port);
					current.server.service = xstrdup(buf);
		}
#line 1954 "../rcfile_y.c"
    break;

  case 54: /* serv_option: INTERVAL NUMBER  */
#line 196 "../rcfile_y.y"
                        {current.server.interval = (yyvsp[0].number);}
#line 1960 "../rcfile_y.c"
    break;

  case 55: /* serv_option: AUTHENTICATE AUTHTYPE  */
#line 198 "../rcfile_y.y"
                        {current.server.authenticate = (yyvsp[0].proto);}
#line 1966 "../rcfile_y.c"
    break;

  case 56: /* serv_option: TIMEOUT NUMBER  */
#line 200 "../rcfile_y.y"
                        {current.server.timeout = (yyvsp[0].number);}
#line 1972 "../rcfile_y.c"
    break;

  case 57: /* serv_option: ENVELOPE NUMBER STRING  */
#line 202 "../rcfile_y.y"
                                        {
					    current.server.envelope = (yyvsp[0].sval);
					    current.server.envskip = (yyvsp[-1].number);
					}
#line 1981 "../rcfile_y.c"
    break;

  case 58: /* serv_option: ENVELOPE STRING  */
#line 207 "../rcfile_y.y"
                                        {
					    current.server.envelope = (yyvsp[0].sval);
					    current.server.envskip = 0;
					}
#line 1990 "../rcfile_y.c"
    break;

  case 59: /* serv_option: QVIRTUAL STRING  */
#line 212 "../rcfile_y.y"
                                        {current.server.qvirtual = (yyvsp[0].sval);}
#line 1996 "../rcfile_y.c"
    break;

  case 60: /* serv_option: INTERFACE STRING  */
#line 213 "../rcfile_y.y"
                                        {
#ifdef CAN_MONITOR
					interface_parse((yyvsp[0].sval), &current.server);
#else
					fprintf(stderr, GT_("fetchmail: interface option is only supported under Linux (without IPv6) and FreeBSD\n"));
#endif
					free((yyvsp[0].sval));
					}
#line 2009 "../rcfile_y.c"
    break;

  case 61: /* serv_option: MONITOR STRING  */
#line 221 "../rcfile_y.y"
                                        {
#ifdef CAN_MONITOR
					current.server.monitor = (yyvsp[0].sval);
#else
					fprintf(stderr, GT_("fetchmail: monitor option is only supported under Linux (without IPv6) and FreeBSD\n"));
					free((yyvsp[0].sval));
#endif
					}
#line 2022 "../rcfile_y.c"
    break;

  case 62: /* serv_option: PLUGIN STRING  */
#line 229 "../rcfile_y.y"
                                        { current.server.plugin = (yyvsp[0].sval); }
#line 2028 "../rcfile_y.c"
    break;

  case 63: /* serv_option: PLUGOUT STRING  */
#line 230 "../rcfile_y.y"
                                        { current.server.plugout = (yyvsp[0].sval); }
#line 2034 "../rcfile_y.c"
    break;

  case 64: /* serv_option: DNS  */
#line 231 "../rcfile_y.y"
                                        {current.server.dns = FLAG_TRUE;}
#line 2040 "../rcfile_y.c"
    break;

  case 65: /* serv_option: NO DNS  */
#line 232 "../rcfile_y.y"
                                        {current.server.dns = FLAG_FALSE;}
#line 2046 "../rcfile_y.c"
    break;

  case 66: /* serv_option: NO ENVELOPE  */
#line 233 "../rcfile_y.y"
                                        {current.server.envelope = STRING_DISABLED;}
#line 2052 "../rcfile_y.c"
    break;

  case 67: /* serv_option: TRACEPOLLS  */
#line 234 "../rcfile_y.y"
                                        {current.server.tracepolls = FLAG_TRUE;}
#line 2058 "../rcfile_y.c"
    break;

  case 68: /* serv_option: NO TRACEPOLLS  */
#line 235 "../rcfile_y.y"
                                        {current.server.tracepolls = FLAG_FALSE;}
#line 2064 "../rcfile_y.c"
    break;

  case 69: /* serv_option: BADHEADER ACCEPT  */
#line 236 "../rcfile_y.y"
                                        {current.server.badheader = BHACCEPT;}
#line 2070 "../rcfile_y.c"
    break;

  case 70: /* serv_option: BADHEADER REJECT_  */
#line 237 "../rcfile_y.y"
                                        {current.server.badheader = BHREJECT;}
#line 2076 "../rcfile_y.c"
    break;

  case 71: /* userspecs: user1opts  */
#line 240 "../rcfile_y.y"
                                        {record_current(); user_reset();}
#line 2082 "../rcfile_y.c"
    break;

  case 73: /* explicits: explicitdef  */
#line 244 "../rcfile_y.y"
                                        {record_current(); user_reset();}
#line 2088 "../rcfile_y.c"
    break;

  case 74: /* explicits: explicits explicitdef  */
#line 245 "../rcfile_y.y"
                                        {record_current(); user_reset();}
#line 2094 "../rcfile_y.c"
    break;

  case 76: /* userdef: USERNAME STRING  */
#line 251 "../rcfile_y.y"
                                        {current.remotename = (yyvsp[0].sval);}
#line 2100 "../rcfile_y.c"
    break;

  case 78: /* userdef: USERNAME STRING THERE  */
#line 253 "../rcfile_y.y"
                                        {current.remotename = (yyvsp[-1].sval);}
#line 2106 "../rcfile_y.c"
    break;

  case 85: /* mapping: STRING  */
#line 268 "../rcfile_y.y"
                                        {if (0 == strcmp((yyvsp[0].sval), "*")) {
					      current.wildcard = TRUE;
					  } else {
					    save_str_pair(&current.localnames, (yyvsp[0].sval), NULL);
					  }
					 free((yyvsp[0].sval));}
#line 2117 "../rcfile_y.c"
    break;

  case 86: /* mapping: STRING MAP STRING  */
#line 274 "../rcfile_y.y"
                                        {save_str_pair(&current.localnames, (yyvsp[-2].sval), (yyvsp[0].sval)); free((yyvsp[-2].sval)); free((yyvsp[0].sval));}
#line 2123 "../rcfile_y.c"
    break;

  case 87: /* folder_list: STRING  */
#line 277 "../rcfile_y.y"
                                        {save_str(&current.mailboxes,(yyvsp[0].sval),0); free((yyvsp[0].sval));}
#line 2129 "../rcfile_y.c"
    break;

  case 88: /* folder_list: folder_list STRING  */
#line 278 "../rcfile_y.y"
                                        {save_str(&current.mailboxes,(yyvsp[0].sval),0); free((yyvsp[0].sval));}
#line 2135 "../rcfile_y.c"
    break;

  case 89: /* smtp_list: STRING  */
#line 281 "../rcfile_y.y"
                                        {save_str(&current.smtphunt, (yyvsp[0].sval),TRUE); free((yyvsp[0].sval));}
#line 2141 "../rcfile_y.c"
    break;

  case 90: /* smtp_list: smtp_list STRING  */
#line 282 "../rcfile_y.y"
                                        {save_str(&current.smtphunt, (yyvsp[0].sval),TRUE); free((yyvsp[0].sval));}
#line 2147 "../rcfile_y.c"
    break;

  case 91: /* fetch_list: STRING  */
#line 285 "../rcfile_y.y"
                                        {save_str(&current.domainlist, (yyvsp[0].sval),TRUE); free((yyvsp[0].sval));}
#line 2153 "../rcfile_y.c"
    break;

  case 92: /* fetch_list: fetch_list STRING  */
#line 286 "../rcfile_y.y"
                                        {save_str(&current.domainlist, (yyvsp[0].sval),TRUE); free((yyvsp[0].sval));}
#line 2159 "../rcfile_y.c"
    break;

  case 93: /* num_list: NUMBER  */
#line 290 "../rcfile_y.y"
                        {
			    struct idlist *id;
			    id = save_str(&current.antispam,STRING_DUMMY,0);
			    id->val.status.num = (yyvsp[0].number);
			}
#line 2169 "../rcfile_y.c"
    break;

  case 94: /* num_list: num_list NUMBER  */
#line 296 "../rcfile_y.y"
                        {
			    struct idlist *id;
			    id = save_str(&current.antispam,STRING_DUMMY,0);
			    id->val.status.num = (yyvsp[0].number);
			}
#line 2179 "../rcfile_y.c"
    break;

  case 99: /* user_option: IS STRING THERE  */
#line 308 "../rcfile_y.y"
                                        {current.remotename  = (yyvsp[-1].sval);}
#line 2185 "../rcfile_y.c"
    break;

  case 100: /* user_option: PASSWORD STRING  */
#line 309 "../rcfile_y.y"
                                        {current.password    = (yyvsp[0].sval);}
#line 2191 "../rcfile_y.c"
    break;

  case 104: /* user_option: SMTPADDRESS STRING  */
#line 313 "../rcfile_y.y"
                                        {current.smtpaddress = (yyvsp[0].sval);}
#line 2197 "../rcfile_y.c"
    break;

  case 105: /* user_option: SMTPNAME STRING  */
#line 314 "../rcfile_y.y"
                                        {current.smtpname =    (yyvsp[0].sval);}
#line 2203 "../rcfile_y.c"
    break;

  case 107: /* user_option: MDA STRING  */
#line 316 "../rcfile_y.y"
                                        {current.mda         = (yyvsp[0].sval);}
#line 2209 "../rcfile_y.c"
    break;

  case 108: /* user_option: BSMTP STRING  */
#line 317 "../rcfile_y.y"
                                        {current.bsmtp       = prependdir ((yyvsp[0].sval), rcfiledir); free((yyvsp[0].sval));}
#line 2215 "../rcfile_y.c"
    break;

  case 109: /* user_option: LMTP  */
#line 318 "../rcfile_y.y"
                                        {current.listener    = LMTP_MODE;}
#line 2221 "../rcfile_y.c"
    break;

  case 110: /* user_option: PRECONNECT STRING  */
#line 319 "../rcfile_y.y"
                                        {current.preconnect  = (yyvsp[0].sval);}
#line 2227 "../rcfile_y.c"
    break;

  case 111: /* user_option: POSTCONNECT STRING  */
#line 320 "../rcfile_y.y"
                                        {current.postconnect = (yyvsp[0].sval);}
#line 2233 "../rcfile_y.c"
    break;

  case 112: /* user_option: KEEP  */
#line 322 "../rcfile_y.y"
                                        {current.keep        = FLAG_TRUE;}
#line 2239 "../rcfile_y.c"
    break;

  case 113: /* user_option: FLUSH  */
#line 323 "../rcfile_y.y"
                                        {current.flush       = FLAG_TRUE;}
#line 2245 "../rcfile_y.c"
    break;

  case 114: /* user_option: LIMITFLUSH  */
#line 324 "../rcfile_y.y"
                                        {current.limitflush  = FLAG_TRUE;}
#line 2251 "../rcfile_y.c"
    break;

  case 115: /* user_option: FETCHALL  */
#line 325 "../rcfile_y.y"
                                        {current.fetchall    = FLAG_TRUE;}
#line 2257 "../rcfile_y.c"
    break;

  case 116: /* user_option: REWRITE  */
#line 326 "../rcfile_y.y"
                                        {current.rewrite     = FLAG_TRUE;}
#line 2263 "../rcfile_y.c"
    break;

  case 117: /* user_option: FORCECR  */
#line 327 "../rcfile_y.y"
                                        {current.forcecr     = FLAG_TRUE;}
#line 2269 "../rcfile_y.c"
    break;

  case 118: /* user_option: STRIPCR  */
#line 328 "../rcfile_y.y"
                                        {current.stripcr     = FLAG_TRUE;}
#line 2275 "../rcfile_y.c"
    break;

  case 119: /* user_option: PASS8BITS  */
#line 329 "../rcfile_y.y"
                                        {current.pass8bits   = FLAG_TRUE;}
#line 2281 "../rcfile_y.c"
    break;

  case 120: /* user_option: DROPSTATUS  */
#line 330 "../rcfile_y.y"
                                        {current.dropstatus  = FLAG_TRUE;}
#line 2287 "../rcfile_y.c"
    break;

  case 121: /* user_option: DROPDELIVERED  */
#line 331 "../rcfile_y.y"
                                        {current.dropdelivered = FLAG_TRUE;}
#line 2293 "../rcfile_y.c"
    break;

  case 122: /* user_option: MIMEDECODE  */
#line 332 "../rcfile_y.y"
                                        {current.mimedecode  = FLAG_TRUE;}
#line 2299 "../rcfile_y.c"
    break;

  case 123: /* user_option: IDLE  */
#line 333 "../rcfile_y.y"
                                        {current.idle        = FLAG_TRUE;}
#line 2305 "../rcfile_y.c"
    break;

  case 124: /* user_option: SSL  */
#line 335 "../rcfile_y.y"
                                        {
#ifdef SSL_ENABLE
		    current.use_ssl = FLAG_TRUE;
#else
		    yyerror(GT_("SSL is not enabled"));
#endif 
		}
#line 2317 "../rcfile_y.c"
    break;

  case 125: /* user_option: SSLKEY STRING  */
#line 342 "../rcfile_y.y"
                                        {current.sslkey = prependdir ((yyvsp[0].sval), rcfiledir); free((yyvsp[0].sval));}
#line 2323 "../rcfile_y.c"
    break;

  case 126: /* user_option: SSLCERT STRING  */
#line 343 "../rcfile_y.y"
                                        {current.sslcert = prependdir ((yyvsp[0].sval), rcfiledir); free((yyvsp[0].sval));}
#line 2329 "../rcfile_y.c"
    break;

  case 127: /* user_option: SSLPROTO STRING  */
#line 344 "../rcfile_y.y"
                                        {current.sslproto = (yyvsp[0].sval);}
#line 2335 "../rcfile_y.c"
    break;

  case 128: /* user_option: SSLCERTCK  */
#line 345 "../rcfile_y.y"
                                        {current.sslcertck = FLAG_TRUE;}
#line 2341 "../rcfile_y.c"
    break;

  case 129: /* user_option: SSLCERTFILE STRING  */
#line 346 "../rcfile_y.y"
                                        {current.sslcertfile = prependdir((yyvsp[0].sval), rcfiledir); free((yyvsp[0].sval));}
#line 2347 "../rcfile_y.c"
    break;

  case 130: /* user_option: SSLCERTPATH STRING  */
#line 347 "../rcfile_y.y"
                                        {current.sslcertpath = prependdir((yyvsp[0].sval), rcfiledir); free((yyvsp[0].sval));}
#line 2353 "../rcfile_y.c"
    break;

  case 131: /* user_option: SSLCOMMONNAME STRING  */
#line 348 "../rcfile_y.y"
                                        {current.sslcommonname = (yyvsp[0].sval);}
#line 2359 "../rcfile_y.c"
    break;

  case 132: /* user_option: SSLFINGERPRINT STRING  */
#line 349 "../rcfile_y.y"
                                        {current.sslfingerprint = (yyvsp[0].sval);}
#line 2365 "../rcfile_y.c"
    break;

  case 133: /* user_option: NO KEEP  */
#line 351 "../rcfile_y.y"
                                        {current.keep        = FLAG_FALSE;}
#line 2371 "../rcfile_y.c"
    break;

  case 134: /* user_option: NO FLUSH  */
#line 352 "../rcfile_y.y"
                                        {current.flush       = FLAG_FALSE;}
#line 2377 "../rcfile_y.c"
    break;

  case 135: /* user_option: NO LIMITFLUSH  */
#line 353 "../rcfile_y.y"
                                        {current.limitflush  = FLAG_FALSE;}
#line 2383 "../rcfile_y.c"
    break;

  case 136: /* user_option: NO FETCHALL  */
#line 354 "../rcfile_y.y"
                                        {current.fetchall    = FLAG_FALSE;}
#line 2389 "../rcfile_y.c"
    break;

  case 137: /* user_option: NO REWRITE  */
#line 355 "../rcfile_y.y"
                                        {current.rewrite     = FLAG_FALSE;}
#line 2395 "../rcfile_y.c"
    break;

  case 138: /* user_option: NO FORCECR  */
#line 356 "../rcfile_y.y"
                                        {current.forcecr     = FLAG_FALSE;}
#line 2401 "../rcfile_y.c"
    break;

  case 139: /* user_option: NO STRIPCR  */
#line 357 "../rcfile_y.y"
                                        {current.stripcr     = FLAG_FALSE;}
#line 2407 "../rcfile_y.c"
    break;

  case 140: /* user_option: NO PASS8BITS  */
#line 358 "../rcfile_y.y"
                                        {current.pass8bits   = FLAG_FALSE;}
#line 2413 "../rcfile_y.c"
    break;

  case 141: /* user_option: NO DROPSTATUS  */
#line 359 "../rcfile_y.y"
                                        {current.dropstatus  = FLAG_FALSE;}
#line 2419 "../rcfile_y.c"
    break;

  case 142: /* user_option: NO DROPDELIVERED  */
#line 360 "../rcfile_y.y"
                                        {current.dropdelivered = FLAG_FALSE;}
#line 2425 "../rcfile_y.c"
    break;

  case 143: /* user_option: NO MIMEDECODE  */
#line 361 "../rcfile_y.y"
                                        {current.mimedecode  = FLAG_FALSE;}
#line 2431 "../rcfile_y.c"
    break;

  case 144: /* user_option: NO IDLE  */
#line 362 "../rcfile_y.y"
                                        {current.idle        = FLAG_FALSE;}
#line 2437 "../rcfile_y.c"
    break;

  case 145: /* user_option: NO SSL  */
#line 364 "../rcfile_y.y"
                                        {current.use_ssl     = FLAG_FALSE;}
#line 2443 "../rcfile_y.c"
    break;

  case 146: /* user_option: NO SSLCERTCK  */
#line 365 "../rcfile_y.y"
                                        {current.sslcertck   = FLAG_FALSE;}
#line 2449 "../rcfile_y.c"
    break;

  case 147: /* user_option: LIMIT NUMBER  */
#line 367 "../rcfile_y.y"
                                        {current.limit       = NUM_VALUE_IN((yyvsp[0].number));}
#line 2455 "../rcfile_y.c"
    break;

  case 148: /* user_option: WARNINGS NUMBER  */
#line 368 "../rcfile_y.y"
                                        {current.warnings    = NUM_VALUE_IN((yyvsp[0].number));}
#line 2461 "../rcfile_y.c"
    break;

  case 149: /* user_option: FETCHLIMIT NUMBER  */
#line 369 "../rcfile_y.y"
                                        {current.fetchlimit  = NUM_VALUE_IN((yyvsp[0].number));}
#line 2467 "../rcfile_y.c"
    break;

  case 150: /* user_option: FETCHSIZELIMIT NUMBER  */
#line 370 "../rcfile_y.y"
                                        {current.fetchsizelimit = NUM_VALUE_IN((yyvsp[0].number));}
#line 2473 "../rcfile_y.c"
    break;

  case 151: /* user_option: FASTUIDL NUMBER  */
#line 371 "../rcfile_y.y"
                                        {current.fastuidl    = NUM_VALUE_IN((yyvsp[0].number));}
#line 2479 "../rcfile_y.c"
    break;

  case 152: /* user_option: BATCHLIMIT NUMBER  */
#line 372 "../rcfile_y.y"
                                        {current.batchlimit  = NUM_VALUE_IN((yyvsp[0].number));}
#line 2485 "../rcfile_y.c"
    break;

  case 153: /* user_option: EXPUNGE NUMBER  */
#line 373 "../rcfile_y.y"
                                        {current.expunge     = NUM_VALUE_IN((yyvsp[0].number));}
#line 2491 "../rcfile_y.c"
    break;

  case 154: /* user_option: PROPERTIES STRING  */
#line 375 "../rcfile_y.y"
                                        {current.properties  = (yyvsp[0].sval);}
#line 2497 "../rcfile_y.c"
    break;


#line 2501 "../rcfile_y.c"

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
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
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

#line 377 "../rcfile_y.y"


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
