/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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

#line 267 "rcfile_y.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_RCFILE_Y_H_INCLUDED  */
