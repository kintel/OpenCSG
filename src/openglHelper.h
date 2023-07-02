// OpenCSG - library for image-based CSG rendering for OpenGL
// Copyright (C) 2002-2022, Florian Kirsch,
// Hasso-Plattner-Institute at the University of Potsdam, Germany
//
// This library is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110 - 1301 USA.

//
// openglHelper.h 
//
// trivial OpenGL stuff
//

#ifndef __OpenCSG__opengl_helper_h__
#define __OpenCSG__opengl_helper_h__

#include "opencsgConfig.h"
#include "area.h"

#ifdef USE_GLAD
  #ifdef _WIN32
    #include <windows.h>
  #endif
  #include "glad/gl.h"
#else
  #include <GL/glew.h>
#endif // USE_GLAD

#ifdef __APPLE__
  #include <OpenGL/glu.h>
#else
  #include <GL/glu.h>
#endif

#ifdef USE_GLAD
  #define hasGLExtension(ext) GLAD_GL_## ext
#else
  #define hasGLExtension(ext) glewIsSupported(#ext)
#endif

namespace OpenCSG {

    namespace OpenGL {

        extern GLfloat projection[16];
            // copy of the projection matrix during CSG computation
        extern GLfloat modelview[16];
            // copy of the modelview matrix during CSG computation
        extern int canvasPos[4];
            // copy of the viewport size during CSG computation

        extern int stencilBits;
            // number of stencil bits in the pbuffer
        extern unsigned int stencilMax;
            // the number where the stencil value would "wrap around" to zero
        extern unsigned int stencilMask;
            // stencilMax - 1

        extern int scissorPos[4];
            // copy of the scissor settings for CSG computation

        void scissor(const PCArea& area);
            // enables scissoring into area (given in pixel coordinates) 

        void drawQuad();
            // renders a full screen quad

    } // namespace OpenGL

} // namespace OpenCSG

#endif // __OpenCSG__opengl_helper_h__
