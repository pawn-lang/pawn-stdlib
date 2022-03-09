#if defined _time_included
	#endinput
#endif
#define _time_included

/**
 * <library name="time" summary="Date/time functions.">
 *   <license>
 *     (c) Copyright 2001-2005, ITB CompuPhase
 *     This file is provided as is (no warranties).
 *   </license>
 *   <summary pawndoc="true">
 *     This library uses the enhanced <em>pawndoc.xsl</em> from
 *     <a href="https://github.com/pawn-lang/pawndoc">pawn-lang/pawndoc</a>.
 *     This XSL has features such as library and markdown support, and will not
 *     render this message when used.
 *   </summary>
 * </library>
 */

#pragma library Time

/**
 * <library>time</library>
 * <summary>Get the current server time.</summary>
 * <param name="hour">The variable to store the hour in, passed by reference (optional=<b><c>0</c></b>)</param>
 * <param name="minute">The variable to store the minute in, passed by reference (optional=<b><c>0</c></b>)</param>
 * <param name="second">The variable to store the seconds in, passed by reference (optional=<b><c>0</c></b>)</param>
 * <seealso name="getdate"/>
 * <returns>The function itself returns a Unix Timestamp.</returns>
 */
native gettime(&hour = 0, &minute = 0, &second = 0);

/**
 * <library>time</library>
 * <summary>Get the current server date.</summary>
 * <param name="year">The variable to store the year in, passed by reference (optional=<b><c>0</c></b>)</param>
 * <param name="month">The variable to store the month in, passed by reference (optional=<b><c>0</c></b>)</param>
 * <param name="day">The variable to store the day in, passed by reference (optional=<b><c>0</c></b>)</param>
 * <seealso name="gettime"/>
 * <returns>The number of days since the start of the year.</returns>
 */
native getdate(&year = 0, &month = 0, &day = 0);

/**
 * <library>time</library>
 * <summary>This function can be used as a replacement for <a href="#GetTickCount">GetTickCount</a>,
 * as it returns the number of milliseconds since the start-up of the server.</summary>
 * <param name="granularity">Upon return, this value contains the number of ticks that the internal
 * system time will tick per second.  This value therefore indicates the accuracy of the return value
 * of this function (optional=<b><c>0</c></b>)</param>
 * <returns>The number of milliseconds since start-up of the system.  For a 32-bit cell, this count
 * overflows after approximately 24 days of continuous operation.</returns>
 */
native tickcount(&granularity = 0);

/**
 * <library>time</library>
 * <summary>A timer event occurred.</summary>
 * <remarks>
 * This function executes after the configured delay or interval expires.  See <c>settimer</c> to
 * set the delay or interval.  Depending on the timing precision of the host, the call may occur
 * later than the delay that was set.
 * <p/>
 * If the timer was set as a "single-shot", it must be ex plicitly set again for a next execution
 * for the <c>@timer</c>function.  If the timer is set to be repetitive, <c>@timer</c> will continue
 * to be called with the set interval until it is disabled with another call to <c>settimer</c>.
 * </remarks>
 * <returns>The return value of this function is currently ignored.</returns>
 */
forward @timer();

/**
 * <library>time</library>
 */
native __settimer(const callback[], milliseconds, bool:multishot) = SetTimer;

/**
 * <library>time</library>
 */
native __killtimer(id) = KillTimer;

/**
 * <library>time</library>
 * <summary>Configure the event timer.</summary>
 * <param name="milliseconds">The number of milliseconds to wait before calling the <c>@timer</c>
 * callback function.  If the timer is repetitive, this is the interval.  When this parameter is 0
 * (zero), the timer is shut off.</param>
 * <param name="singleshot">If <c>false</c>, the timer is a repetitive timer; if <c>true</c> the
 * timer is shut off after invoking the <c>@timer</c> event once.</param>
 * <remarks>
 * See the chapter "Usage" for an example of this function, and the <c>@timer</c> event function.
 * </remarks>
 * <returns>This function always returns 0.</returns>
 */
stock settimer(milliseconds, bool:singleshot = false)
{
	static id = 0;
	if (id)
	{
		__killtimer(id);
	}
	id = 0;
	if (milliseconds)
	{
		id = __settimer("@timer", milliseconds, !singleshot);
	}
	return 0;
}

/**
 * <library>time</library>
 * <summary>Halts execution a number of milliseconds.</summary>
 * <param name="milliseconds">The delay, in milliseconds.</param>
 * <remarks>
 * On some platforms, the <c>sleep</c> instruction also delays for a given number of milliseconds.
 * The difference between the <c>sleep</c> instruction and the <c>delay</c> function is that the
 * <c>delay</c> function does not yield events and the <c>sleep</c> instruction typically yields.
 * When yielding events, any pending events are handled.  As a result, the <c>delay</c> function
 * waits without handling any pending events and the <c>sleep</c> instruction waits and deals with
 * events.
 * </remarks>
 * <returns>This function always returns 0.</returns>
 */
stock delay(milliseconds)
{
	// This arrangement accounts for integer overflows.
	new end = tickcount() + milliseconds;
	while (tickcount() - end < 0)
	{
		// Do nothing.
	}
	return 0;
}

