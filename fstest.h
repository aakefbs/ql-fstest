/************************************************************************
 *
 * Filesystem stress and verify
 *
 * Authors: Goswin von Brederlow <brederlo@informatik.uni-tuebingen.de>
 *          Bernd Schubert <bernd.schubert@fastmail.fm>
 *
 * Copyright (C) 2007 Q-leap Networks, Goswin von Brederlow
 *               2010 DataDirect Networks, Bernd Schubert
 *
 *    This program is free software; you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation; either version 2 of the License, or
 *    (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program; if not, write to the Free Software
 *    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307
 *    USA
 *
 ************************************************************************/

#ifndef __FSTEST_H__
#define __FSTEST_H__

#include <unistd.h>
#include <getopt.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>
#include <sys/statvfs.h>
#include <stdint.h>
#include <time.h>
#include <fcntl.h>
#include <pthread.h>

#include <iostream>
#include <sstream>
#include <cassert>
#include <vector>
#include <cstring>
#include <stdint.h>

using namespace std;

#include "dir.h"
#include "file.h"
#include "filesystem.h"

#define QL_FSTEST_MIN_NUM_FILES 22
#define QL_FSTEST_DEFAULT_NUM_FILES 1000

extern int do_exit(const char* func, const char *file, unsigned line, int code);

#if DEBUG > 2
static inline void print_return(const char* func, const char *file, unsigned line, int value=0)
{
	fprintf(stderr, "%s() %s:%d return %d\n", func, file, line, value);
}
#else
#define print_return(func, file, line, value)
#endif

#define EXIT(x) do_exit(__func__, __FILE__, __LINE__, x)

#define RETURN(x)  	\
	do {		\
		print_return(__func__, __FILE__, __LINE__, (int) x); 	\
		return x;						\
	} while (0)

// return void
#define RETURNV  	\
	do {		\
		print_return(__func__, __FILE__, __LINE__, 0); 	\
		return;						\
	} while (0)

static const uint64_t KILO = 1024;
static const uint64_t MEGA = 1024 * 1024;
static const uint64_t GIGA = 1024 * 1024 * 1024;

#endif // __FS_TEST_H__
