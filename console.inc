/* String functions
 *
 * (c) Copyright 1998-2011, ITB CompuPhase
 * This file is provided as is (no warranties).
 */
#if defined _console_included
  #endinput
#endif
#define _console_included
#pragma library Console

// Don't define "printf" twice.
#tryinclude <a_samp>
#if defined _samp_included
	#endinput
#endif

native print(const string[]);
native printf(const format[], {Float,_}:...);
