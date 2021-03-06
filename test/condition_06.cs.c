/* Generated by re2c */
#line 1 "condition_06.cs.re"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	BSIZE	8192

typedef struct Scanner
{
	FILE			*fp;
	unsigned char	*cur, *tok, *lim, *eof;
	unsigned char 	buffer[BSIZE];
} Scanner;

int fill(Scanner *s, int len)
{
	if (!len)
	{
		s->cur = s->tok = s->lim = s->buffer;
		s->eof = 0;
	}
	if (!s->eof)
	{
		int got, cnt = s->tok - s->buffer;

		if (cnt > 0)
		{
			memcpy(s->buffer, s->tok, s->lim - s->tok);
			s->tok -= cnt;
			s->cur -= cnt;
			s->lim -= cnt;
		}
		cnt = BSIZE - cnt;
		if ((got = fread(s->lim, 1, cnt, s->fp)) != cnt)
		{
			s->eof = &s->lim[got];
		}
		s->lim += got;
	}
	else if (s->cur + len > s->eof)
	{
		return 0; /* not enough input data */
	}
	return -1;
}

void fputl(const char *s, size_t len, FILE *stream)
{
	while(len-- > 0)
	{
		fputc(*s++, stream);
	}
}

#line 57 "<stdout>"

enum YYCONDTYPE {
	EStateNormal,
	EStateComment,
	EStateSkiptoeol,
	EStateString,
};

#line 54 "condition_06.cs.re"

void scan(Scanner *s)
{
	int cond = EStateNormal;
	
	fill(s, 0);

	for(;;)
	{
		s->tok = s->cur;

#line 78 "<stdout>"
		{
			unsigned char yych;
			if (cond < 2) {
				if (cond < 1) {
					goto yyc_Normal;
				} else {
					goto yyc_Comment;
				}
			} else {
				if (cond < 3) {
					goto yyc_Skiptoeol;
				} else {
					goto yyc_String;
				}
			}
/* *********************************** */
yyc_Comment:

			if ((s->lim - s->cur) < 2) { if(fill(s, 2) >= 0) break; }
			yych = *s->cur;
			if (yych != '*') goto yy4;
			++s->cur;
			if ((yych = *s->cur) == '/') goto yy5;
yy3:
#line 149 "condition_06.cs.re"
			{
				goto yyc_Comment;
			}
#line 107 "<stdout>"
yy4:
			yych = *++s->cur;
			goto yy3;
yy5:
			++s->cur;
#line 145 "condition_06.cs.re"
			{
				continue;
			}
#line 117 "<stdout>"
/* *********************************** */
yyc_Normal:
			if ((s->lim - s->cur) < 3) { if(fill(s, 3) >= 0) break; }
			yych = *s->cur;
			if (yych <= '.') {
				if (yych == '"') goto yy12;
				goto yy14;
			} else {
				if (yych <= '/') goto yy11;
				if (yych != '?') goto yy14;
			}
			yych = *(s->tok = ++s->cur);
			if (yych == '?') goto yy19;
yy10:
#line 140 "condition_06.cs.re"
			{
				fputc(*s->tok, stdout);
				continue;
			}
#line 137 "<stdout>"
yy11:
			yych = *++s->cur;
			if (yych == '*') goto yy17;
			if (yych == '/') goto yy15;
			goto yy10;
yy12:
			++s->cur;
#line 134 "condition_06.cs.re"
			{
				fputc(*s->tok, stdout);
				state = EStateString;
				continue;
			}
#line 151 "<stdout>"
yy14:
			yych = *++s->cur;
			goto yy10;
yy15:
			++s->cur;
#line 130 "condition_06.cs.re"
			{
				goto yyc_Skiptoeol;
			}
#line 161 "<stdout>"
yy17:
			++s->cur;
#line 126 "condition_06.cs.re"
			{
				goto yyc_Comment;
			}
#line 168 "<stdout>"
yy19:
			yych = *++s->cur;
			switch (yych) {
			case '!':	goto yy35;
			case '\'':	goto yy33;
			case '(':	goto yy21;
			case ')':	goto yy23;
			case '-':	goto yy37;
			case '/':	goto yy31;
			case '<':	goto yy25;
			case '=':	goto yy29;
			case '>':	goto yy27;
			default:	goto yy20;
			}
yy20:
			s->cur = s->tok;
			goto yy10;
yy21:
			++s->cur;
#line 81 "condition_06.cs.re"
			{
				fputc('[', stdout);
				continue;
			}
#line 193 "<stdout>"
yy23:
			++s->cur;
#line 86 "condition_06.cs.re"
			{
				fputc(']', stdout);
				continue;
			}
#line 201 "<stdout>"
yy25:
			++s->cur;
#line 91 "condition_06.cs.re"
			{
				fputc('{', stdout);
				continue;
			}
#line 209 "<stdout>"
yy27:
			++s->cur;
#line 96 "condition_06.cs.re"
			{
				fputc('}', stdout);
				continue;
			}
#line 217 "<stdout>"
yy29:
			++s->cur;
#line 101 "condition_06.cs.re"
			{
				fputc('#', stdout);
				continue;
			}
#line 225 "<stdout>"
yy31:
			++s->cur;
#line 106 "condition_06.cs.re"
			{
				fputc('\\', stdout);
				continue;
			}
#line 233 "<stdout>"
yy33:
			++s->cur;
#line 111 "condition_06.cs.re"
			{
				fputc('^', stdout);
				continue;
			}
#line 241 "<stdout>"
yy35:
			++s->cur;
#line 116 "condition_06.cs.re"
			{
				fputc('|', stdout);
				continue;
			}
#line 249 "<stdout>"
yy37:
			++s->cur;
#line 121 "condition_06.cs.re"
			{
				fputc('~', stdout);
				continue;
			}
#line 257 "<stdout>"
/* *********************************** */
yyc_Skiptoeol:
			if ((s->lim - s->cur) < 5) { if(fill(s, 5) >= 0) break; }
			yych = *s->cur;
			if (yych <= '>') {
				if (yych == '\n') goto yy44;
				goto yy46;
			} else {
				if (yych <= '?') goto yy41;
				if (yych == '\\') goto yy43;
				goto yy46;
			}
yy41:
			yych = *(s->tok = ++s->cur);
			if (yych == '?') goto yy51;
yy42:
#line 165 "condition_06.cs.re"
			{
				goto yyc_Skiptoeol;
			}
#line 278 "<stdout>"
yy43:
			yych = *(s->tok = ++s->cur);
			if (yych == '\n') goto yy49;
			if (yych == '\r') goto yy47;
			goto yy42;
yy44:
			++s->cur;
#line 161 "condition_06.cs.re"
			{
				continue;
			}
#line 290 "<stdout>"
yy46:
			yych = *++s->cur;
			goto yy42;
yy47:
			yych = *++s->cur;
			if (yych == '\n') goto yy49;
yy48:
			s->cur = s->tok;
			goto yy42;
yy49:
			++s->cur;
#line 157 "condition_06.cs.re"
			{
				goto yyc_Skiptoeol;
			}
#line 306 "<stdout>"
yy51:
			yych = *++s->cur;
			if (yych != '/') goto yy48;
			yych = *++s->cur;
			if (yych == '\n') goto yy54;
			if (yych != '\r') goto yy48;
			yych = *++s->cur;
			if (yych != '\n') goto yy48;
yy54:
			++s->cur;
#line 153 "condition_06.cs.re"
			{
				goto yyc_Skiptoeol;
			}
#line 321 "<stdout>"
/* *********************************** */
yyc_String:
			if ((s->lim - s->cur) < 2) { if(fill(s, 2) >= 0) break; }
			yych = *s->cur;
			if (yych == '"') goto yy60;
			if (yych != '\\') goto yy62;
			++s->cur;
			if ((yych = *s->cur) != '\n') goto yy63;
yy59:
#line 179 "condition_06.cs.re"
			{
				fputc(*s->tok, stdout);
				continue;
			}
#line 336 "<stdout>"
yy60:
			++s->cur;
#line 174 "condition_06.cs.re"
			{
				fputc(*s->tok, stdout);
				continue;
			}
#line 344 "<stdout>"
yy62:
			yych = *++s->cur;
			goto yy59;
yy63:
			++s->cur;
#line 169 "condition_06.cs.re"
			{
				fputl((const char*)s->tok, 2, stdout);
				continue;
			}
#line 355 "<stdout>"
		}
#line 183 "condition_06.cs.re"

	}
}

int main(int argc, char **argv)
{
	Scanner in;
	char c;

	if (argc != 2)
	{
		fprintf(stderr, "%s <file>\n", argv[0]);
		return 1;;
	}

	memset((char*) &in, 0, sizeof(in));

	if (!strcmp(argv[1], "-"))
	{
		in.fp = stdin;
	}
	else if ((in.fp = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "Cannot open file '%s'\n", argv[1]);
		return 1;
	}

	scan(&in);

	if (in.fp != stdin)
	{
		fclose(in.fp);
	}
	return 0;
}
