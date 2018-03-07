/*
 * SDLCL - SDL Compatibility Library
 * Copyright (C) 2017 Alan Williams <mralert@gmail.com>
 * 
 * Portions taken from SDL 1.2.15
 * Copyright (C) 1997-2012 Sam Latinga <slouken@libsdl.org>
 * 
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <stdlib.h>

#include "SDL2.h"

size_t SDL_iconv(SDL_iconv_t cd,
                 const char **inbuf, size_t *inbytesleft,
                 char **outbuf, size_t *outbytesleft)
{
	return rSDL_iconv(cd, inbuf, inbytesleft, outbuf, outbytesleft);
}

char *SDL_iconv_string(const char *tocode, const char *fromcode, const char *inbuf, size_t inbytesleft)
{
	return rSDL_iconv_string(tocode, fromcode, inbuf, inbytesleft);
}
