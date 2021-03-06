/*
 * SSHTunnels - A program for generating and maintaining SSH Tunnels
 *
 * log.h
 *     - Logging functions.
 *
 * Copyright (C) 2015 Alex Markley
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 * 
 */

//Only process this header once.
#ifndef __SSHTUNNELS_LOG_H

#include <stdio.h>
#include <stdarg.h>

//Valid log levels.
enum
	{
	STL_ERROR,
	STL_WARNING,
	STL_INFO,
	STL_RESERVED
	};

//Should we even bother dumping INFO messages?
//If this is TRUE, don't generate any info messages regardless of
//the MB setting above.
#define STL_SUPRESS_ALL_INFO FALSE //(Can be TRUE or FALSE).

//If SSHTunnels is built with syslog support, you can specify STL_OUTPUT_SYSLOG (basically a null FILE *) to refer to SYSLOG output
#define STL_OUTPUT_SYSLOG NULL

//direct messages to stderr by default
#define STL_OUTPUT_DEFAULT stderr

//Message formatting buffer size incrementation.
#define STL_BUFFERLEN_STEP 128

FILE *stl_logoutput(int query, FILE *newdest);
void stl_loginit(char *name);
void stl(int status, char *message_format, ...); //Now supports printf() format conversion.

#define __SSHTUNNELS_LOG_H
#endif

