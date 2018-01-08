/* String functions
 *
 * (c) Copyright 2005, ITB CompuPhase
 * This file is provided as is (no warranties).
 */
#if defined _string_included
  #endinput
#endif
#define _string_included
#pragma library String

native strlen(const string[]);
native strpack(dest[], const source[], maxlength=sizeof dest);
native strunpack(dest[], const source[], maxlength=sizeof dest);
native strcat(dest[], const source[], maxlength=sizeof dest);
stock strcopy(dest[], const source[], maxlength=sizeof dest)
	return strcat((dest[0] = EOS, dest), source, maxlength);

native strmid(dest[], const source[], start, end, maxlength=sizeof dest);
native bool: strins(string[], const substr[], pos, maxlength=sizeof string);
native bool: strdel(string[], start, end);

native strcmp(const string1[], const string2[], bool:ignorecase=false, length=cellmax);
native strfind(const string[], const sub[], bool:ignorecase=false, pos=0);

native strval(const string[]);
native valstr(dest[], value, bool:pack=false);
native bool: ispacked(const string[]);

native format(dest[], size=sizeof dest, const format[], {Float,_}:...);
#define strformat(%0,%1,%2,%3) format(%0,%1,%3)

native uudecode(dest[], const source[], maxlength=sizeof dest);
native uuencode(dest[], const source[], numbytes, maxlength=sizeof dest);
native memcpy(dest[], const source[], index=0, numbytes, maxlength=sizeof dest);

stock bool: strequal(const string1[], const string2[], bool:ignorecase=false, length=cellmax)
	return strcmp(string1, string2, ignorecase, length) == 0;
