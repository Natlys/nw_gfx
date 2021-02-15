
static void load_GL_VERSION_1_0(GLADloadproc load) {
	if (!GLAD_GL_VERSION_1_0) return;
	glad_glCullFace = (PFNGLCULLFACEPROC)load("glCullFace");
	glad_glFrontFace = (PFNGLFRONTFACEPROC)load("glFrontFace");
	glad_glHint = (PFNGLHINTPROC)load("glHint");
	glad_glLineWidth = (PFNGLLINEWIDTHPROC)load("glLineWidth");
	glad_glPointSize = (PFNGLPOINTSIZEPROC)load("glPointSize");
	glad_glPolygonMode = (PFNGLPOLYGONMODEPROC)load("glPolygonMode");
	glad_glScissor = (PFNGLSCISSORPROC)load("glScissor");
	glad_glTexParameterf = (PFNGLTEXPARAMETERFPROC)load("glTexParameterf");
	glad_glTexParameterfv = (PFNGLTEXPARAMETERFVPROC)load("glTexParameterfv");
	glad_glTexParameteri = (PFNGLTEXPARAMETERIPROC)load("glTexParameteri");
	glad_glTexParameteriv = (PFNGLTEXPARAMETERIVPROC)load("glTexParameteriv");
	glad_glTexImage1D = (PFNGLTEXIMAGE1DPROC)load("glTexImage1D");
	glad_glTexImage2D = (PFNGLTEXIMAGE2DPROC)load("glTexImage2D");
	glad_glDrawBuffer = (PFNGLDRAWBUFFERPROC)load("glDrawBuffer");
	glad_glClear = (PFNGLCLEARPROC)load("glClear");
	glad_glClearColor = (PFNGLCLEARCOLORPROC)load("glClearColor");
	glad_glClearStencil = (PFNGLCLEARSTENCILPROC)load("glClearStencil");
	glad_glClearDepth = (PFNGLCLEARDEPTHPROC)load("glClearDepth");
	glad_glStencilMask = (PFNGLSTENCILMASKPROC)load("glStencilMask");
	glad_glColorMask = (PFNGLCOLORMASKPROC)load("glColorMask");
	glad_glDepthMask = (PFNGLDEPTHMASKPROC)load("glDepthMask");
	glad_glDisable = (PFNGLDISABLEPROC)load("glDisable");
	glad_glEnable = (PFNGLENABLEPROC)load("glEnable");
	glad_glFinish = (PFNGLFINISHPROC)load("glFinish");
	glad_glFlush = (PFNGLFLUSHPROC)load("glFlush");
	glad_glBlendFunc = (PFNGLBLENDFUNCPROC)load("glBlendFunc");
	glad_glLogicOp = (PFNGLLOGICOPPROC)load("glLogicOp");
	glad_glStencilFunc = (PFNGLSTENCILFUNCPROC)load("glStencilFunc");
	glad_glStencilOp = (PFNGLSTENCILOPPROC)load("glStencilOp");
	glad_glDepthFunc = (PFNGLDEPTHFUNCPROC)load("glDepthFunc");
	glad_glPixelStoref = (PFNGLPIXELSTOREFPROC)load("glPixelStoref");
	glad_glPixelStorei = (PFNGLPIXELSTOREIPROC)load("glPixelStorei");
	glad_glReadBuffer = (PFNGLREADBUFFERPROC)load("glReadBuffer");
	glad_glReadPixels = (PFNGLREADPIXELSPROC)load("glReadPixels");
	glad_glGetBooleanv = (PFNGLGETBOOLEANVPROC)load("glGetBooleanv");
	glad_glGetDoublev = (PFNGLGETDOUBLEVPROC)load("glGetDoublev");
	glad_glGetError = (PFNGLGETERRORPROC)load("glGetError");
	glad_glGetFloatv = (PFNGLGETFLOATVPROC)load("glGetFloatv");
	glad_glGetIntegerv = (PFNGLGETINTEGERVPROC)load("glGetIntegerv");
	glad_glGetString = (PFNGLGETSTRINGPROC)load("glGetString");
	glad_glGetTexImage = (PFNGLGETTEXIMAGEPROC)load("glGetTexImage");
	glad_glGetTexParameterfv = (PFNGLGETTEXPARAMETERFVPROC)load("glGetTexParameterfv");
	glad_glGetTexParameteriv = (PFNGLGETTEXPARAMETERIVPROC)load("glGetTexParameteriv");
	glad_glGetTexLevelParameterfv = (PFNGLGETTEXLEVELPARAMETERFVPROC)load("glGetTexLevelParameterfv");
	glad_glGetTexLevelParameteriv = (PFNGLGETTEXLEVELPARAMETERIVPROC)load("glGetTexLevelParameteriv");
	glad_glIsEnabled = (PFNGLISENABLEDPROC)load("glIsEnabled");
	glad_glDepthRange = (PFNGLDEPTHRANGEPROC)load("glDepthRange");
	glad_glViewport = (PFNGLVIEWPORTPROC)load("glViewport");
	glad_glNewList = (PFNGLNEWLISTPROC)load("glNewList");
	glad_glEndList = (PFNGLENDLISTPROC)load("glEndList");
	glad_glCallList = (PFNGLCALLLISTPROC)load("glCallList");
	glad_glCallLists = (PFNGLCALLLISTSPROC)load("glCallLists");
	glad_glDeleteLists = (PFNGLDELETELISTSPROC)load("glDeleteLists");
	glad_glGenLists = (PFNGLGENLISTSPROC)load("glGenLists");
	glad_glListBase = (PFNGLLISTBASEPROC)load("glListBase");
	glad_glBegin = (PFNGLBEGINPROC)load("glBegin");
	glad_glBitmap = (PFNGLBITMAPPROC)load("glBitmap");
	glad_glColor3b = (PFNGLCOLOR3BPROC)load("glColor3b");
	glad_glColor3bv = (PFNGLCOLOR3BVPROC)load("glColor3bv");
	glad_glColor3d = (PFNGLCOLOR3DPROC)load("glColor3d");
	glad_glColor3dv = (PFNGLCOLOR3DVPROC)load("glColor3dv");
	glad_glColor3f = (PFNGLCOLOR3FPROC)load("glColor3f");
	glad_glColor3fv = (PFNGLCOLOR3FVPROC)load("glColor3fv");
	glad_glColor3i = (PFNGLCOLOR3IPROC)load("glColor3i");
	glad_glColor3iv = (PFNGLCOLOR3IVPROC)load("glColor3iv");
	glad_glColor3s = (PFNGLCOLOR3SPROC)load("glColor3s");
	glad_glColor3sv = (PFNGLCOLOR3SVPROC)load("glColor3sv");
	glad_glColor3ub = (PFNGLCOLOR3UBPROC)load("glColor3ub");
	glad_glColor3ubv = (PFNGLCOLOR3UBVPROC)load("glColor3ubv");
	glad_glColor3ui = (PFNGLCOLOR3UIPROC)load("glColor3ui");
	glad_glColor3uiv = (PFNGLCOLOR3UIVPROC)load("glColor3uiv");
	glad_glColor3us = (PFNGLCOLOR3USPROC)load("glColor3us");
	glad_glColor3usv = (PFNGLCOLOR3USVPROC)load("glColor3usv");
	glad_glColor4b = (PFNGLCOLOR4BPROC)load("glColor4b");
	glad_glColor4bv = (PFNGLCOLOR4BVPROC)load("glColor4bv");
	glad_glColor4d = (PFNGLCOLOR4DPROC)load("glColor4d");
	glad_glColor4dv = (PFNGLCOLOR4DVPROC)load("glColor4dv");
	glad_glColor4f = (PFNGLCOLOR4FPROC)load("glColor4f");
	glad_glColor4fv = (PFNGLCOLOR4FVPROC)load("glColor4fv");
	glad_glColor4i = (PFNGLCOLOR4IPROC)load("glColor4i");
	glad_glColor4iv = (PFNGLCOLOR4IVPROC)load("glColor4iv");
	glad_glColor4s = (PFNGLCOLOR4SPROC)load("glColor4s");
	glad_glColor4sv = (PFNGLCOLOR4SVPROC)load("glColor4sv");
	glad_glColor4ub = (PFNGLCOLOR4UBPROC)load("glColor4ub");
	glad_glColor4ubv = (PFNGLCOLOR4UBVPROC)load("glColor4ubv");
	glad_glColor4ui = (PFNGLCOLOR4UIPROC)load("glColor4ui");
	glad_glColor4uiv = (PFNGLCOLOR4UIVPROC)load("glColor4uiv");
	glad_glColor4us = (PFNGLCOLOR4USPROC)load("glColor4us");
	glad_glColor4usv = (PFNGLCOLOR4USVPROC)load("glColor4usv");
	glad_glEdgeFlag = (PFNGLEDGEFLAGPROC)load("glEdgeFlag");
	glad_glEdgeFlagv = (PFNGLEDGEFLAGVPROC)load("glEdgeFlagv");
	glad_glEnd = (PFNGLENDPROC)load("glEnd");
	glad_glIndexd = (PFNGLINDEXDPROC)load("glIndexd");
	glad_glIndexdv = (PFNGLINDEXDVPROC)load("glIndexdv");
	glad_glIndexf = (PFNGLINDEXFPROC)load("glIndexf");
	glad_glIndexfv = (PFNGLINDEXFVPROC)load("glIndexfv");
	glad_glIndexi = (PFNGLINDEXIPROC)load("glIndexi");
	glad_glIndexiv = (PFNGLINDEXIVPROC)load("glIndexiv");
	glad_glIndexs = (PFNGLINDEXSPROC)load("glIndexs");
	glad_glIndexsv = (PFNGLINDEXSVPROC)load("glIndexsv");
	glad_glNormal3b = (PFNGLNORMAL3BPROC)load("glNormal3b");
	glad_glNormal3bv = (PFNGLNORMAL3BVPROC)load("glNormal3bv");
	glad_glNormal3d = (PFNGLNORMAL3DPROC)load("glNormal3d");
	glad_glNormal3dv = (PFNGLNORMAL3DVPROC)load("glNormal3dv");
	glad_glNormal3f = (PFNGLNORMAL3FPROC)load("glNormal3f");
	glad_glNormal3fv = (PFNGLNORMAL3FVPROC)load("glNormal3fv");
	glad_glNormal3i = (PFNGLNORMAL3IPROC)load("glNormal3i");
	glad_glNormal3iv = (PFNGLNORMAL3IVPROC)load("glNormal3iv");
	glad_glNormal3s = (PFNGLNORMAL3SPROC)load("glNormal3s");
	glad_glNormal3sv = (PFNGLNORMAL3SVPROC)load("glNormal3sv");
	glad_glRasterPos2d = (PFNGLRASTERPOS2DPROC)load("glRasterPos2d");
	glad_glRasterPos2dv = (PFNGLRASTERPOS2DVPROC)load("glRasterPos2dv");
	glad_glRasterPos2f = (PFNGLRASTERPOS2FPROC)load("glRasterPos2f");
	glad_glRasterPos2fv = (PFNGLRASTERPOS2FVPROC)load("glRasterPos2fv");
	glad_glRasterPos2i = (PFNGLRASTERPOS2IPROC)load("glRasterPos2i");
	glad_glRasterPos2iv = (PFNGLRASTERPOS2IVPROC)load("glRasterPos2iv");
	glad_glRasterPos2s = (PFNGLRASTERPOS2SPROC)load("glRasterPos2s");
	glad_glRasterPos2sv = (PFNGLRASTERPOS2SVPROC)load("glRasterPos2sv");
	glad_glRasterPos3d = (PFNGLRASTERPOS3DPROC)load("glRasterPos3d");
	glad_glRasterPos3dv = (PFNGLRASTERPOS3DVPROC)load("glRasterPos3dv");
	glad_glRasterPos3f = (PFNGLRASTERPOS3FPROC)load("glRasterPos3f");
	glad_glRasterPos3fv = (PFNGLRASTERPOS3FVPROC)load("glRasterPos3fv");
	glad_glRasterPos3i = (PFNGLRASTERPOS3IPROC)load("glRasterPos3i");
	glad_glRasterPos3iv = (PFNGLRASTERPOS3IVPROC)load("glRasterPos3iv");
	glad_glRasterPos3s = (PFNGLRASTERPOS3SPROC)load("glRasterPos3s");
	glad_glRasterPos3sv = (PFNGLRASTERPOS3SVPROC)load("glRasterPos3sv");
	glad_glRasterPos4d = (PFNGLRASTERPOS4DPROC)load("glRasterPos4d");
	glad_glRasterPos4dv = (PFNGLRASTERPOS4DVPROC)load("glRasterPos4dv");
	glad_glRasterPos4f = (PFNGLRASTERPOS4FPROC)load("glRasterPos4f");
	glad_glRasterPos4fv = (PFNGLRASTERPOS4FVPROC)load("glRasterPos4fv");
	glad_glRasterPos4i = (PFNGLRASTERPOS4IPROC)load("glRasterPos4i");
	glad_glRasterPos4iv = (PFNGLRASTERPOS4IVPROC)load("glRasterPos4iv");
	glad_glRasterPos4s = (PFNGLRASTERPOS4SPROC)load("glRasterPos4s");
	glad_glRasterPos4sv = (PFNGLRASTERPOS4SVPROC)load("glRasterPos4sv");
	glad_glRectd = (PFNGLRECTDPROC)load("glRectd");
	glad_glRectdv = (PFNGLRECTDVPROC)load("glRectdv");
	glad_glRectf = (PFNGLRECTFPROC)load("glRectf");
	glad_glRectfv = (PFNGLRECTFVPROC)load("glRectfv");
	glad_glRecti = (PFNGLRECTIPROC)load("glRecti");
	glad_glRectiv = (PFNGLRECTIVPROC)load("glRectiv");
	glad_glRects = (PFNGLRECTSPROC)load("glRects");
	glad_glRectsv = (PFNGLRECTSVPROC)load("glRectsv");
	glad_glTexCoord1d = (PFNGLTEXCOORD1DPROC)load("glTexCoord1d");
	glad_glTexCoord1dv = (PFNGLTEXCOORD1DVPROC)load("glTexCoord1dv");
	glad_glTexCoord1f = (PFNGLTEXCOORD1FPROC)load("glTexCoord1f");
	glad_glTexCoord1fv = (PFNGLTEXCOORD1FVPROC)load("glTexCoord1fv");
	glad_glTexCoord1i = (PFNGLTEXCOORD1IPROC)load("glTexCoord1i");
	glad_glTexCoord1iv = (PFNGLTEXCOORD1IVPROC)load("glTexCoord1iv");
	glad_glTexCoord1s = (PFNGLTEXCOORD1SPROC)load("glTexCoord1s");
	glad_glTexCoord1sv = (PFNGLTEXCOORD1SVPROC)load("glTexCoord1sv");
	glad_glTexCoord2d = (PFNGLTEXCOORD2DPROC)load("glTexCoord2d");
	glad_glTexCoord2dv = (PFNGLTEXCOORD2DVPROC)load("glTexCoord2dv");
	glad_glTexCoord2f = (PFNGLTEXCOORD2FPROC)load("glTexCoord2f");
	glad_glTexCoord2fv = (PFNGLTEXCOORD2FVPROC)load("glTexCoord2fv");
	glad_glTexCoord2i = (PFNGLTEXCOORD2IPROC)load("glTexCoord2i");
	glad_glTexCoord2iv = (PFNGLTEXCOORD2IVPROC)load("glTexCoord2iv");
	glad_glTexCoord2s = (PFNGLTEXCOORD2SPROC)load("glTexCoord2s");
	glad_glTexCoord2sv = (PFNGLTEXCOORD2SVPROC)load("glTexCoord2sv");
	glad_glTexCoord3d = (PFNGLTEXCOORD3DPROC)load("glTexCoord3d");
	glad_glTexCoord3dv = (PFNGLTEXCOORD3DVPROC)load("glTexCoord3dv");
	glad_glTexCoord3f = (PFNGLTEXCOORD3FPROC)load("glTexCoord3f");
	glad_glTexCoord3fv = (PFNGLTEXCOORD3FVPROC)load("glTexCoord3fv");
	glad_glTexCoord3i = (PFNGLTEXCOORD3IPROC)load("glTexCoord3i");
	glad_glTexCoord3iv = (PFNGLTEXCOORD3IVPROC)load("glTexCoord3iv");
	glad_glTexCoord3s = (PFNGLTEXCOORD3SPROC)load("glTexCoord3s");
	glad_glTexCoord3sv = (PFNGLTEXCOORD3SVPROC)load("glTexCoord3sv");
	glad_glTexCoord4d = (PFNGLTEXCOORD4DPROC)load("glTexCoord4d");
	glad_glTexCoord4dv = (PFNGLTEXCOORD4DVPROC)load("glTexCoord4dv");
	glad_glTexCoord4f = (PFNGLTEXCOORD4FPROC)load("glTexCoord4f");
	glad_glTexCoord4fv = (PFNGLTEXCOORD4FVPROC)load("glTexCoord4fv");
	glad_glTexCoord4i = (PFNGLTEXCOORD4IPROC)load("glTexCoord4i");
	glad_glTexCoord4iv = (PFNGLTEXCOORD4IVPROC)load("glTexCoord4iv");
	glad_glTexCoord4s = (PFNGLTEXCOORD4SPROC)load("glTexCoord4s");
	glad_glTexCoord4sv = (PFNGLTEXCOORD4SVPROC)load("glTexCoord4sv");
	glad_glVertex2d = (PFNGLVERTEX2DPROC)load("glVertex2d");
	glad_glVertex2dv = (PFNGLVERTEX2DVPROC)load("glVertex2dv");
	glad_glVertex2f = (PFNGLVERTEX2FPROC)load("glVertex2f");
	glad_glVertex2fv = (PFNGLVERTEX2FVPROC)load("glVertex2fv");
	glad_glVertex2i = (PFNGLVERTEX2IPROC)load("glVertex2i");
	glad_glVertex2iv = (PFNGLVERTEX2IVPROC)load("glVertex2iv");
	glad_glVertex2s = (PFNGLVERTEX2SPROC)load("glVertex2s");
	glad_glVertex2sv = (PFNGLVERTEX2SVPROC)load("glVertex2sv");
	glad_glVertex3d = (PFNGLVERTEX3DPROC)load("glVertex3d");
	glad_glVertex3dv = (PFNGLVERTEX3DVPROC)load("glVertex3dv");
	glad_glVertex3f = (PFNGLVERTEX3FPROC)load("glVertex3f");
	glad_glVertex3fv = (PFNGLVERTEX3FVPROC)load("glVertex3fv");
	glad_glVertex3i = (PFNGLVERTEX3IPROC)load("glVertex3i");
	glad_glVertex3iv = (PFNGLVERTEX3IVPROC)load("glVertex3iv");
	glad_glVertex3s = (PFNGLVERTEX3SPROC)load("glVertex3s");
	glad_glVertex3sv = (PFNGLVERTEX3SVPROC)load("glVertex3sv");
	glad_glVertex4d = (PFNGLVERTEX4DPROC)load("glVertex4d");
	glad_glVertex4dv = (PFNGLVERTEX4DVPROC)load("glVertex4dv");
	glad_glVertex4f = (PFNGLVERTEX4FPROC)load("glVertex4f");
	glad_glVertex4fv = (PFNGLVERTEX4FVPROC)load("glVertex4fv");
	glad_glVertex4i = (PFNGLVERTEX4IPROC)load("glVertex4i");
	glad_glVertex4iv = (PFNGLVERTEX4IVPROC)load("glVertex4iv");
	glad_glVertex4s = (PFNGLVERTEX4SPROC)load("glVertex4s");
	glad_glVertex4sv = (PFNGLVERTEX4SVPROC)load("glVertex4sv");
	glad_glClipPlane = (PFNGLCLIPPLANEPROC)load("glClipPlane");
	glad_glColorMaterial = (PFNGLCOLORMATERIALPROC)load("glColorMaterial");
	glad_glFogf = (PFNGLFOGFPROC)load("glFogf");
	glad_glFogfv = (PFNGLFOGFVPROC)load("glFogfv");
	glad_glFogi = (PFNGLFOGIPROC)load("glFogi");
	glad_glFogiv = (PFNGLFOGIVPROC)load("glFogiv");
	glad_glLightf = (PFNGLLIGHTFPROC)load("glLightf");
	glad_glLightfv = (PFNGLLIGHTFVPROC)load("glLightfv");
	glad_glLighti = (PFNGLLIGHTIPROC)load("glLighti");
	glad_glLightiv = (PFNGLLIGHTIVPROC)load("glLightiv");
	glad_glLightModelf = (PFNGLLIGHTMODELFPROC)load("glLightModelf");
	glad_glLightModelfv = (PFNGLLIGHTMODELFVPROC)load("glLightModelfv");
	glad_glLightModeli = (PFNGLLIGHTMODELIPROC)load("glLightModeli");
	glad_glLightModeliv = (PFNGLLIGHTMODELIVPROC)load("glLightModeliv");
	glad_glLineStipple = (PFNGLLINESTIPPLEPROC)load("glLineStipple");
	glad_glMaterialf = (PFNGLMATERIALFPROC)load("glMaterialf");
	glad_glMaterialfv = (PFNGLMATERIALFVPROC)load("glMaterialfv");
	glad_glMateriali = (PFNGLMATERIALIPROC)load("glMateriali");
	glad_glMaterialiv = (PFNGLMATERIALIVPROC)load("glMaterialiv");
	glad_glPolygonStipple = (PFNGLPOLYGONSTIPPLEPROC)load("glPolygonStipple");
	glad_glShadeModel = (PFNGLSHADEMODELPROC)load("glShadeModel");
	glad_glTexEnvf = (PFNGLTEXENVFPROC)load("glTexEnvf");
	glad_glTexEnvfv = (PFNGLTEXENVFVPROC)load("glTexEnvfv");
	glad_glTexEnvi = (PFNGLTEXENVIPROC)load("glTexEnvi");
	glad_glTexEnviv = (PFNGLTEXENVIVPROC)load("glTexEnviv");
	glad_glTexGend = (PFNGLTEXGENDPROC)load("glTexGend");
	glad_glTexGendv = (PFNGLTEXGENDVPROC)load("glTexGendv");
	glad_glTexGenf = (PFNGLTEXGENFPROC)load("glTexGenf");
	glad_glTexGenfv = (PFNGLTEXGENFVPROC)load("glTexGenfv");
	glad_glTexGeni = (PFNGLTEXGENIPROC)load("glTexGeni");
	glad_glTexGeniv = (PFNGLTEXGENIVPROC)load("glTexGeniv");
	glad_glFeedbackBuffer = (PFNGLFEEDBACKBUFFERPROC)load("glFeedbackBuffer");
	glad_glSelectBuffer = (PFNGLSELECTBUFFERPROC)load("glSelectBuffer");
	glad_glRenderMode = (PFNGLRENDERMODEPROC)load("glRenderMode");
	glad_glInitNames = (PFNGLINITNAMESPROC)load("glInitNames");
	glad_glLoadName = (PFNGLLOADNAMEPROC)load("glLoadName");
	glad_glPassThrough = (PFNGLPASSTHROUGHPROC)load("glPassThrough");
	glad_glPopName = (PFNGLPOPNAMEPROC)load("glPopName");
	glad_glPushName = (PFNGLPUSHNAMEPROC)load("glPushName");
	glad_glClearAccum = (PFNGLCLEARACCUMPROC)load("glClearAccum");
	glad_glClearIndex = (PFNGLCLEARINDEXPROC)load("glClearIndex");
	glad_glIndexMask = (PFNGLINDEXMASKPROC)load("glIndexMask");
	glad_glAccum = (PFNGLACCUMPROC)load("glAccum");
	glad_glPopAttrib = (PFNGLPOPATTRIBPROC)load("glPopAttrib");
	glad_glPushAttrib = (PFNGLPUSHATTRIBPROC)load("glPushAttrib");
	glad_glMap1d = (PFNGLMAP1DPROC)load("glMap1d");
	glad_glMap1f = (PFNGLMAP1FPROC)load("glMap1f");
	glad_glMap2d = (PFNGLMAP2DPROC)load("glMap2d");
	glad_glMap2f = (PFNGLMAP2FPROC)load("glMap2f");
	glad_glMapGrid1d = (PFNGLMAPGRID1DPROC)load("glMapGrid1d");
	glad_glMapGrid1f = (PFNGLMAPGRID1FPROC)load("glMapGrid1f");
	glad_glMapGrid2d = (PFNGLMAPGRID2DPROC)load("glMapGrid2d");
	glad_glMapGrid2f = (PFNGLMAPGRID2FPROC)load("glMapGrid2f");
	glad_glEvalCoord1d = (PFNGLEVALCOORD1DPROC)load("glEvalCoord1d");
	glad_glEvalCoord1dv = (PFNGLEVALCOORD1DVPROC)load("glEvalCoord1dv");
	glad_glEvalCoord1f = (PFNGLEVALCOORD1FPROC)load("glEvalCoord1f");
	glad_glEvalCoord1fv = (PFNGLEVALCOORD1FVPROC)load("glEvalCoord1fv");
	glad_glEvalCoord2d = (PFNGLEVALCOORD2DPROC)load("glEvalCoord2d");
	glad_glEvalCoord2dv = (PFNGLEVALCOORD2DVPROC)load("glEvalCoord2dv");
	glad_glEvalCoord2f = (PFNGLEVALCOORD2FPROC)load("glEvalCoord2f");
	glad_glEvalCoord2fv = (PFNGLEVALCOORD2FVPROC)load("glEvalCoord2fv");
	glad_glEvalMesh1 = (PFNGLEVALMESH1PROC)load("glEvalMesh1");
	glad_glEvalPoint1 = (PFNGLEVALPOINT1PROC)load("glEvalPoint1");
	glad_glEvalMesh2 = (PFNGLEVALMESH2PROC)load("glEvalMesh2");
	glad_glEvalPoint2 = (PFNGLEVALPOINT2PROC)load("glEvalPoint2");
	glad_glAlphaFunc = (PFNGLALPHAFUNCPROC)load("glAlphaFunc");
	glad_glPixelZoom = (PFNGLPIXELZOOMPROC)load("glPixelZoom");
	glad_glPixelTransferf = (PFNGLPIXELTRANSFERFPROC)load("glPixelTransferf");
	glad_glPixelTransferi = (PFNGLPIXELTRANSFERIPROC)load("glPixelTransferi");
	glad_glPixelMapfv = (PFNGLPIXELMAPFVPROC)load("glPixelMapfv");
	glad_glPixelMapuiv = (PFNGLPIXELMAPUIVPROC)load("glPixelMapuiv");
	glad_glPixelMapusv = (PFNGLPIXELMAPUSVPROC)load("glPixelMapusv");
	glad_glCopyPixels = (PFNGLCOPYPIXELSPROC)load("glCopyPixels");
	glad_glDrawPixels = (PFNGLDRAWPIXELSPROC)load("glDrawPixels");
	glad_glGetClipPlane = (PFNGLGETCLIPPLANEPROC)load("glGetClipPlane");
	glad_glGetLightfv = (PFNGLGETLIGHTFVPROC)load("glGetLightfv");
	glad_glGetLightiv = (PFNGLGETLIGHTIVPROC)load("glGetLightiv");
	glad_glGetMapdv = (PFNGLGETMAPDVPROC)load("glGetMapdv");
	glad_glGetMapfv = (PFNGLGETMAPFVPROC)load("glGetMapfv");
	glad_glGetMapiv = (PFNGLGETMAPIVPROC)load("glGetMapiv");
	glad_glGetMaterialfv = (PFNGLGETMATERIALFVPROC)load("glGetMaterialfv");
	glad_glGetMaterialiv = (PFNGLGETMATERIALIVPROC)load("glGetMaterialiv");
	glad_glGetPixelMapfv = (PFNGLGETPIXELMAPFVPROC)load("glGetPixelMapfv");
	glad_glGetPixelMapuiv = (PFNGLGETPIXELMAPUIVPROC)load("glGetPixelMapuiv");
	glad_glGetPixelMapusv = (PFNGLGETPIXELMAPUSVPROC)load("glGetPixelMapusv");
	glad_glGetPolygonStipple = (PFNGLGETPOLYGONSTIPPLEPROC)load("glGetPolygonStipple");
	glad_glGetTexEnvfv = (PFNGLGETTEXENVFVPROC)load("glGetTexEnvfv");
	glad_glGetTexEnviv = (PFNGLGETTEXENVIVPROC)load("glGetTexEnviv");
	glad_glGetTexGendv = (PFNGLGETTEXGENDVPROC)load("glGetTexGendv");
	glad_glGetTexGenfv = (PFNGLGETTEXGENFVPROC)load("glGetTexGenfv");
	glad_glGetTexGeniv = (PFNGLGETTEXGENIVPROC)load("glGetTexGeniv");
	glad_glIsList = (PFNGLISLISTPROC)load("glIsList");
	glad_glFrustum = (PFNGLFRUSTUMPROC)load("glFrustum");
	glad_glLoadIdentity = (PFNGLLOADIDENTITYPROC)load("glLoadIdentity");
	glad_glLoadMatrixf = (PFNGLLOADMATRIXFPROC)load("glLoadMatrixf");
	glad_glLoadMatrixd = (PFNGLLOADMATRIXDPROC)load("glLoadMatrixd");
	glad_glMatrixMode = (PFNGLMATRIXMODEPROC)load("glMatrixMode");
	glad_glMultMatrixf = (PFNGLMULTMATRIXFPROC)load("glMultMatrixf");
	glad_glMultMatrixd = (PFNGLMULTMATRIXDPROC)load("glMultMatrixd");
	glad_glOrtho = (PFNGLORTHOPROC)load("glOrtho");
	glad_glPopMatrix = (PFNGLPOPMATRIXPROC)load("glPopMatrix");
	glad_glPushMatrix = (PFNGLPUSHMATRIXPROC)load("glPushMatrix");
	glad_glRotated = (PFNGLROTATEDPROC)load("glRotated");
	glad_glRotatef = (PFNGLROTATEFPROC)load("glRotatef");
	glad_glScaled = (PFNGLSCALEDPROC)load("glScaled");
	glad_glScalef = (PFNGLSCALEFPROC)load("glScalef");
	glad_glTranslated = (PFNGLTRANSLATEDPROC)load("glTranslated");
	glad_glTranslatef = (PFNGLTRANSLATEFPROC)load("glTranslatef");
}
static void load_GL_VERSION_1_1(GLADloadproc load) {
	if (!GLAD_GL_VERSION_1_1) return;
	glad_glDrawArrays = (PFNGLDRAWARRAYSPROC)load("glDrawArrays");
	glad_glDrawElements = (PFNGLDRAWELEMENTSPROC)load("glDrawElements");
	glad_glGetPointerv = (PFNGLGETPOINTERVPROC)load("glGetPointerv");
	glad_glPolygonOffset = (PFNGLPOLYGONOFFSETPROC)load("glPolygonOffset");
	glad_glCopyTexImage1D = (PFNGLCOPYTEXIMAGE1DPROC)load("glCopyTexImage1D");
	glad_glCopyTexImage2D = (PFNGLCOPYTEXIMAGE2DPROC)load("glCopyTexImage2D");
	glad_glCopyTexSubImage1D = (PFNGLCOPYTEXSUBIMAGE1DPROC)load("glCopyTexSubImage1D");
	glad_glCopyTexSubImage2D = (PFNGLCOPYTEXSUBIMAGE2DPROC)load("glCopyTexSubImage2D");
	glad_glTexSubImage1D = (PFNGLTEXSUBIMAGE1DPROC)load("glTexSubImage1D");
	glad_glTexSubImage2D = (PFNGLTEXSUBIMAGE2DPROC)load("glTexSubImage2D");
	glad_glBindTexture = (PFNGLBINDTEXTUREPROC)load("glBindTexture");
	glad_glDeleteTextures = (PFNGLDELETETEXTURESPROC)load("glDeleteTextures");
	glad_glGenTextures = (PFNGLGENTEXTURESPROC)load("glGenTextures");
	glad_glIsTexture = (PFNGLISTEXTUREPROC)load("glIsTexture");
	glad_glArrayElement = (PFNGLARRAYELEMENTPROC)load("glArrayElement");
	glad_glColorPointer = (PFNGLCOLORPOINTERPROC)load("glColorPointer");
	glad_glDisableClientState = (PFNGLDISABLECLIENTSTATEPROC)load("glDisableClientState");
	glad_glEdgeFlagPointer = (PFNGLEDGEFLAGPOINTERPROC)load("glEdgeFlagPointer");
	glad_glEnableClientState = (PFNGLENABLECLIENTSTATEPROC)load("glEnableClientState");
	glad_glIndexPointer = (PFNGLINDEXPOINTERPROC)load("glIndexPointer");
	glad_glInterleavedArrays = (PFNGLINTERLEAVEDARRAYSPROC)load("glInterleavedArrays");
	glad_glNormalPointer = (PFNGLNORMALPOINTERPROC)load("glNormalPointer");
	glad_glTexCoordPointer = (PFNGLTEXCOORDPOINTERPROC)load("glTexCoordPointer");
	glad_glVertexPointer = (PFNGLVERTEXPOINTERPROC)load("glVertexPointer");
	glad_glAreTexturesResident = (PFNGLARETEXTURESRESIDENTPROC)load("glAreTexturesResident");
	glad_glPrioritizeTextures = (PFNGLPRIORITIZETEXTURESPROC)load("glPrioritizeTextures");
	glad_glIndexub = (PFNGLINDEXUBPROC)load("glIndexub");
	glad_glIndexubv = (PFNGLINDEXUBVPROC)load("glIndexubv");
	glad_glPopClientAttrib = (PFNGLPOPCLIENTATTRIBPROC)load("glPopClientAttrib");
	glad_glPushClientAttrib = (PFNGLPUSHCLIENTATTRIBPROC)load("glPushClientAttrib");
}
static void load_GL_VERSION_1_2(GLADloadproc load) {
	if (!GLAD_GL_VERSION_1_2) return;
	glad_glDrawRangeElements = (PFNGLDRAWRANGEELEMENTSPROC)load("glDrawRangeElements");
	glad_glTexImage3D = (PFNGLTEXIMAGE3DPROC)load("glTexImage3D");
	glad_glTexSubImage3D = (PFNGLTEXSUBIMAGE3DPROC)load("glTexSubImage3D");
	glad_glCopyTexSubImage3D = (PFNGLCOPYTEXSUBIMAGE3DPROC)load("glCopyTexSubImage3D");
}
static void load_GL_VERSION_1_3(GLADloadproc load) {
	if (!GLAD_GL_VERSION_1_3) return;
	glad_glActiveTexture = (PFNGLACTIVETEXTUREPROC)load("glActiveTexture");
	glad_glSampleCoverage = (PFNGLSAMPLECOVERAGEPROC)load("glSampleCoverage");
	glad_glCompressedTexImage3D = (PFNGLCOMPRESSEDTEXIMAGE3DPROC)load("glCompressedTexImage3D");
	glad_glCompressedTexImage2D = (PFNGLCOMPRESSEDTEXIMAGE2DPROC)load("glCompressedTexImage2D");
	glad_glCompressedTexImage1D = (PFNGLCOMPRESSEDTEXIMAGE1DPROC)load("glCompressedTexImage1D");
	glad_glCompressedTexSubImage3D = (PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC)load("glCompressedTexSubImage3D");
	glad_glCompressedTexSubImage2D = (PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)load("glCompressedTexSubImage2D");
	glad_glCompressedTexSubImage1D = (PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC)load("glCompressedTexSubImage1D");
	glad_glGetCompressedTexImage = (PFNGLGETCOMPRESSEDTEXIMAGEPROC)load("glGetCompressedTexImage");
	glad_glClientActiveTexture = (PFNGLCLIENTACTIVETEXTUREPROC)load("glClientActiveTexture");
	glad_glMultiTexCoord1d = (PFNGLMULTITEXCOORD1DPROC)load("glMultiTexCoord1d");
	glad_glMultiTexCoord1dv = (PFNGLMULTITEXCOORD1DVPROC)load("glMultiTexCoord1dv");
	glad_glMultiTexCoord1f = (PFNGLMULTITEXCOORD1FPROC)load("glMultiTexCoord1f");
	glad_glMultiTexCoord1fv = (PFNGLMULTITEXCOORD1FVPROC)load("glMultiTexCoord1fv");
	glad_glMultiTexCoord1i = (PFNGLMULTITEXCOORD1IPROC)load("glMultiTexCoord1i");
	glad_glMultiTexCoord1iv = (PFNGLMULTITEXCOORD1IVPROC)load("glMultiTexCoord1iv");
	glad_glMultiTexCoord1s = (PFNGLMULTITEXCOORD1SPROC)load("glMultiTexCoord1s");
	glad_glMultiTexCoord1sv = (PFNGLMULTITEXCOORD1SVPROC)load("glMultiTexCoord1sv");
	glad_glMultiTexCoord2d = (PFNGLMULTITEXCOORD2DPROC)load("glMultiTexCoord2d");
	glad_glMultiTexCoord2dv = (PFNGLMULTITEXCOORD2DVPROC)load("glMultiTexCoord2dv");
	glad_glMultiTexCoord2f = (PFNGLMULTITEXCOORD2FPROC)load("glMultiTexCoord2f");
	glad_glMultiTexCoord2fv = (PFNGLMULTITEXCOORD2FVPROC)load("glMultiTexCoord2fv");
	glad_glMultiTexCoord2i = (PFNGLMULTITEXCOORD2IPROC)load("glMultiTexCoord2i");
	glad_glMultiTexCoord2iv = (PFNGLMULTITEXCOORD2IVPROC)load("glMultiTexCoord2iv");
	glad_glMultiTexCoord2s = (PFNGLMULTITEXCOORD2SPROC)load("glMultiTexCoord2s");
	glad_glMultiTexCoord2sv = (PFNGLMULTITEXCOORD2SVPROC)load("glMultiTexCoord2sv");
	glad_glMultiTexCoord3d = (PFNGLMULTITEXCOORD3DPROC)load("glMultiTexCoord3d");
	glad_glMultiTexCoord3dv = (PFNGLMULTITEXCOORD3DVPROC)load("glMultiTexCoord3dv");
	glad_glMultiTexCoord3f = (PFNGLMULTITEXCOORD3FPROC)load("glMultiTexCoord3f");
	glad_glMultiTexCoord3fv = (PFNGLMULTITEXCOORD3FVPROC)load("glMultiTexCoord3fv");
	glad_glMultiTexCoord3i = (PFNGLMULTITEXCOORD3IPROC)load("glMultiTexCoord3i");
	glad_glMultiTexCoord3iv = (PFNGLMULTITEXCOORD3IVPROC)load("glMultiTexCoord3iv");
	glad_glMultiTexCoord3s = (PFNGLMULTITEXCOORD3SPROC)load("glMultiTexCoord3s");
	glad_glMultiTexCoord3sv = (PFNGLMULTITEXCOORD3SVPROC)load("glMultiTexCoord3sv");
	glad_glMultiTexCoord4d = (PFNGLMULTITEXCOORD4DPROC)load("glMultiTexCoord4d");
	glad_glMultiTexCoord4dv = (PFNGLMULTITEXCOORD4DVPROC)load("glMultiTexCoord4dv");
	glad_glMultiTexCoord4f = (PFNGLMULTITEXCOORD4FPROC)load("glMultiTexCoord4f");
	glad_glMultiTexCoord4fv = (PFNGLMULTITEXCOORD4FVPROC)load("glMultiTexCoord4fv");
	glad_glMultiTexCoord4i = (PFNGLMULTITEXCOORD4IPROC)load("glMultiTexCoord4i");
	glad_glMultiTexCoord4iv = (PFNGLMULTITEXCOORD4IVPROC)load("glMultiTexCoord4iv");
	glad_glMultiTexCoord4s = (PFNGLMULTITEXCOORD4SPROC)load("glMultiTexCoord4s");
	glad_glMultiTexCoord4sv = (PFNGLMULTITEXCOORD4SVPROC)load("glMultiTexCoord4sv");
	glad_glLoadTransposeMatrixf = (PFNGLLOADTRANSPOSEMATRIXFPROC)load("glLoadTransposeMatrixf");
	glad_glLoadTransposeMatrixd = (PFNGLLOADTRANSPOSEMATRIXDPROC)load("glLoadTransposeMatrixd");
	glad_glMultTransposeMatrixf = (PFNGLMULTTRANSPOSEMATRIXFPROC)load("glMultTransposeMatrixf");
	glad_glMultTransposeMatrixd = (PFNGLMULTTRANSPOSEMATRIXDPROC)load("glMultTransposeMatrixd");
}
static void load_GL_VERSION_1_4(GLADloadproc load) {
	if (!GLAD_GL_VERSION_1_4) return;
	glad_glBlendFuncSeparate = (PFNGLBLENDFUNCSEPARATEPROC)load("glBlendFuncSeparate");
	glad_glMultiDrawArrays = (PFNGLMULTIDRAWARRAYSPROC)load("glMultiDrawArrays");
	glad_glMultiDrawElements = (PFNGLMULTIDRAWELEMENTSPROC)load("glMultiDrawElements");
	glad_glPointParameterf = (PFNGLPOINTPARAMETERFPROC)load("glPointParameterf");
	glad_glPointParameterfv = (PFNGLPOINTPARAMETERFVPROC)load("glPointParameterfv");
	glad_glPointParameteri = (PFNGLPOINTPARAMETERIPROC)load("glPointParameteri");
	glad_glPointParameteriv = (PFNGLPOINTPARAMETERIVPROC)load("glPointParameteriv");
	glad_glFogCoordf = (PFNGLFOGCOORDFPROC)load("glFogCoordf");
	glad_glFogCoordfv = (PFNGLFOGCOORDFVPROC)load("glFogCoordfv");
	glad_glFogCoordd = (PFNGLFOGCOORDDPROC)load("glFogCoordd");
	glad_glFogCoorddv = (PFNGLFOGCOORDDVPROC)load("glFogCoorddv");
	glad_glFogCoordPointer = (PFNGLFOGCOORDPOINTERPROC)load("glFogCoordPointer");
	glad_glSecondaryColor3b = (PFNGLSECONDARYCOLOR3BPROC)load("glSecondaryColor3b");
	glad_glSecondaryColor3bv = (PFNGLSECONDARYCOLOR3BVPROC)load("glSecondaryColor3bv");
	glad_glSecondaryColor3d = (PFNGLSECONDARYCOLOR3DPROC)load("glSecondaryColor3d");
	glad_glSecondaryColor3dv = (PFNGLSECONDARYCOLOR3DVPROC)load("glSecondaryColor3dv");
	glad_glSecondaryColor3f = (PFNGLSECONDARYCOLOR3FPROC)load("glSecondaryColor3f");
	glad_glSecondaryColor3fv = (PFNGLSECONDARYCOLOR3FVPROC)load("glSecondaryColor3fv");
	glad_glSecondaryColor3i = (PFNGLSECONDARYCOLOR3IPROC)load("glSecondaryColor3i");
	glad_glSecondaryColor3iv = (PFNGLSECONDARYCOLOR3IVPROC)load("glSecondaryColor3iv");
	glad_glSecondaryColor3s = (PFNGLSECONDARYCOLOR3SPROC)load("glSecondaryColor3s");
	glad_glSecondaryColor3sv = (PFNGLSECONDARYCOLOR3SVPROC)load("glSecondaryColor3sv");
	glad_glSecondaryColor3ub = (PFNGLSECONDARYCOLOR3UBPROC)load("glSecondaryColor3ub");
	glad_glSecondaryColor3ubv = (PFNGLSECONDARYCOLOR3UBVPROC)load("glSecondaryColor3ubv");
	glad_glSecondaryColor3ui = (PFNGLSECONDARYCOLOR3UIPROC)load("glSecondaryColor3ui");
	glad_glSecondaryColor3uiv = (PFNGLSECONDARYCOLOR3UIVPROC)load("glSecondaryColor3uiv");
	glad_glSecondaryColor3us = (PFNGLSECONDARYCOLOR3USPROC)load("glSecondaryColor3us");
	glad_glSecondaryColor3usv = (PFNGLSECONDARYCOLOR3USVPROC)load("glSecondaryColor3usv");
	glad_glSecondaryColorPointer = (PFNGLSECONDARYCOLORPOINTERPROC)load("glSecondaryColorPointer");
	glad_glWindowPos2d = (PFNGLWINDOWPOS2DPROC)load("glWindowPos2d");
	glad_glWindowPos2dv = (PFNGLWINDOWPOS2DVPROC)load("glWindowPos2dv");
	glad_glWindowPos2f = (PFNGLWINDOWPOS2FPROC)load("glWindowPos2f");
	glad_glWindowPos2fv = (PFNGLWINDOWPOS2FVPROC)load("glWindowPos2fv");
	glad_glWindowPos2i = (PFNGLWINDOWPOS2IPROC)load("glWindowPos2i");
	glad_glWindowPos2iv = (PFNGLWINDOWPOS2IVPROC)load("glWindowPos2iv");
	glad_glWindowPos2s = (PFNGLWINDOWPOS2SPROC)load("glWindowPos2s");
	glad_glWindowPos2sv = (PFNGLWINDOWPOS2SVPROC)load("glWindowPos2sv");
	glad_glWindowPos3d = (PFNGLWINDOWPOS3DPROC)load("glWindowPos3d");
	glad_glWindowPos3dv = (PFNGLWINDOWPOS3DVPROC)load("glWindowPos3dv");
	glad_glWindowPos3f = (PFNGLWINDOWPOS3FPROC)load("glWindowPos3f");
	glad_glWindowPos3fv = (PFNGLWINDOWPOS3FVPROC)load("glWindowPos3fv");
	glad_glWindowPos3i = (PFNGLWINDOWPOS3IPROC)load("glWindowPos3i");
	glad_glWindowPos3iv = (PFNGLWINDOWPOS3IVPROC)load("glWindowPos3iv");
	glad_glWindowPos3s = (PFNGLWINDOWPOS3SPROC)load("glWindowPos3s");
	glad_glWindowPos3sv = (PFNGLWINDOWPOS3SVPROC)load("glWindowPos3sv");
	glad_glBlendColor = (PFNGLBLENDCOLORPROC)load("glBlendColor");
	glad_glBlendEquation = (PFNGLBLENDEQUATIONPROC)load("glBlendEquation");
}
static void load_GL_VERSION_1_5(GLADloadproc load) {
	if (!GLAD_GL_VERSION_1_5) return;
	glad_glGenQueries = (PFNGLGENQUERIESPROC)load("glGenQueries");
	glad_glDeleteQueries = (PFNGLDELETEQUERIESPROC)load("glDeleteQueries");
	glad_glIsQuery = (PFNGLISQUERYPROC)load("glIsQuery");
	glad_glBeginQuery = (PFNGLBEGINQUERYPROC)load("glBeginQuery");
	glad_glEndQuery = (PFNGLENDQUERYPROC)load("glEndQuery");
	glad_glGetQueryiv = (PFNGLGETQUERYIVPROC)load("glGetQueryiv");
	glad_glGetQueryObjectiv = (PFNGLGETQUERYOBJECTIVPROC)load("glGetQueryObjectiv");
	glad_glGetQueryObjectuiv = (PFNGLGETQUERYOBJECTUIVPROC)load("glGetQueryObjectuiv");
	glad_glBindBuffer = (PFNGLBINDBUFFERPROC)load("glBindBuffer");
	glad_glDeleteBuffers = (PFNGLDELETEBUFFERSPROC)load("glDeleteBuffers");
	glad_glGenBuffers = (PFNGLGENBUFFERSPROC)load("glGenBuffers");
	glad_glIsBuffer = (PFNGLISBUFFERPROC)load("glIsBuffer");
	glad_glBufferData = (PFNGLBUFFERDATAPROC)load("glBufferData");
	glad_glBufferSubData = (PFNGLBUFFERSUBDATAPROC)load("glBufferSubData");
	glad_glGetBufferSubData = (PFNGLGETBUFFERSUBDATAPROC)load("glGetBufferSubData");
	glad_glMapBuffer = (PFNGLMAPBUFFERPROC)load("glMapBuffer");
	glad_glUnmapBuffer = (PFNGLUNMAPBUFFERPROC)load("glUnmapBuffer");
	glad_glGetBufferParameteriv = (PFNGLGETBUFFERPARAMETERIVPROC)load("glGetBufferParameteriv");
	glad_glGetBufferPointerv = (PFNGLGETBUFFERPOINTERVPROC)load("glGetBufferPointerv");
}
static void load_GL_VERSION_2_0(GLADloadproc load) {
	if (!GLAD_GL_VERSION_2_0) return;
	glad_glBlendEquationSeparate = (PFNGLBLENDEQUATIONSEPARATEPROC)load("glBlendEquationSeparate");
	glad_glDrawBuffers = (PFNGLDRAWBUFFERSPROC)load("glDrawBuffers");
	glad_glStencilOpSeparate = (PFNGLSTENCILOPSEPARATEPROC)load("glStencilOpSeparate");
	glad_glStencilFuncSeparate = (PFNGLSTENCILFUNCSEPARATEPROC)load("glStencilFuncSeparate");
	glad_glStencilMaskSeparate = (PFNGLSTENCILMASKSEPARATEPROC)load("glStencilMaskSeparate");
	glad_glAttachShader = (PFNGLATTACHSHADERPROC)load("glAttachShader");
	glad_glBindAttribLocation = (PFNGLBINDATTRIBLOCATIONPROC)load("glBindAttribLocation");
	glad_glCompileShader = (PFNGLCOMPILESHADERPROC)load("glCompileShader");
	glad_glCreateProgram = (PFNGLCREATEPROGRAMPROC)load("glCreateProgram");
	glad_glCreateShader = (PFNGLCREATESHADERPROC)load("glCreateShader");
	glad_glDeleteProgram = (PFNGLDELETEPROGRAMPROC)load("glDeleteProgram");
	glad_glDeleteShader = (PFNGLDELETESHADERPROC)load("glDeleteShader");
	glad_glDetachShader = (PFNGLDETACHSHADERPROC)load("glDetachShader");
	glad_glDisableVertexAttribArray = (PFNGLDISABLEVERTEXATTRIBARRAYPROC)load("glDisableVertexAttribArray");
	glad_glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC)load("glEnableVertexAttribArray");
	glad_glGetActiveAttrib = (PFNGLGETACTIVEATTRIBPROC)load("glGetActiveAttrib");
	glad_glGetActiveUniform = (PFNGLGETACTIVEUNIFORMPROC)load("glGetActiveUniform");
	glad_glGetAttachedShaders = (PFNGLGETATTACHEDSHADERSPROC)load("glGetAttachedShaders");
	glad_glGetAttribLocation = (PFNGLGETATTRIBLOCATIONPROC)load("glGetAttribLocation");
	glad_glGetProgramiv = (PFNGLGETPROGRAMIVPROC)load("glGetProgramiv");
	glad_glGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC)load("glGetProgramInfoLog");
	glad_glGetShaderiv = (PFNGLGETSHADERIVPROC)load("glGetShaderiv");
	glad_glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC)load("glGetShaderInfoLog");
	glad_glGetShaderSource = (PFNGLGETSHADERSOURCEPROC)load("glGetShaderSource");
	glad_glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC)load("glGetUniformLocation");
	glad_glGetUniformfv = (PFNGLGETUNIFORMFVPROC)load("glGetUniformfv");
	glad_glGetUniformiv = (PFNGLGETUNIFORMIVPROC)load("glGetUniformiv");
	glad_glGetVertexAttribdv = (PFNGLGETVERTEXATTRIBDVPROC)load("glGetVertexAttribdv");
	glad_glGetVertexAttribfv = (PFNGLGETVERTEXATTRIBFVPROC)load("glGetVertexAttribfv");
	glad_glGetVertexAttribiv = (PFNGLGETVERTEXATTRIBIVPROC)load("glGetVertexAttribiv");
	glad_glGetVertexAttribPointerv = (PFNGLGETVERTEXATTRIBPOINTERVPROC)load("glGetVertexAttribPointerv");
	glad_glIsProgram = (PFNGLISPROGRAMPROC)load("glIsProgram");
	glad_glIsShader = (PFNGLISSHADERPROC)load("glIsShader");
	glad_glLinkProgram = (PFNGLLINKPROGRAMPROC)load("glLinkProgram");
	glad_glShaderSource = (PFNGLSHADERSOURCEPROC)load("glShaderSource");
	glad_glUseProgram = (PFNGLUSEPROGRAMPROC)load("glUseProgram");
	glad_glUniform1f = (PFNGLUNIFORM1FPROC)load("glUniform1f");
	glad_glUniform2f = (PFNGLUNIFORM2FPROC)load("glUniform2f");
	glad_glUniform3f = (PFNGLUNIFORM3FPROC)load("glUniform3f");
	glad_glUniform4f = (PFNGLUNIFORM4FPROC)load("glUniform4f");
	glad_glUniform1i = (PFNGLUNIFORM1IPROC)load("glUniform1i");
	glad_glUniform2i = (PFNGLUNIFORM2IPROC)load("glUniform2i");
	glad_glUniform3i = (PFNGLUNIFORM3IPROC)load("glUniform3i");
	glad_glUniform4i = (PFNGLUNIFORM4IPROC)load("glUniform4i");
	glad_glUniform1fv = (PFNGLUNIFORM1FVPROC)load("glUniform1fv");
	glad_glUniform2fv = (PFNGLUNIFORM2FVPROC)load("glUniform2fv");
	glad_glUniform3fv = (PFNGLUNIFORM3FVPROC)load("glUniform3fv");
	glad_glUniform4fv = (PFNGLUNIFORM4FVPROC)load("glUniform4fv");
	glad_glUniform1iv = (PFNGLUNIFORM1IVPROC)load("glUniform1iv");
	glad_glUniform2iv = (PFNGLUNIFORM2IVPROC)load("glUniform2iv");
	glad_glUniform3iv = (PFNGLUNIFORM3IVPROC)load("glUniform3iv");
	glad_glUniform4iv = (PFNGLUNIFORM4IVPROC)load("glUniform4iv");
	glad_glUniformMatrix2fv = (PFNGLUNIFORMMATRIX2FVPROC)load("glUniformMatrix2fv");
	glad_glUniformMatrix3fv = (PFNGLUNIFORMMATRIX3FVPROC)load("glUniformMatrix3fv");
	glad_glUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC)load("glUniformMatrix4fv");
	glad_glValidateProgram = (PFNGLVALIDATEPROGRAMPROC)load("glValidateProgram");
	glad_glVertexAttrib1d = (PFNGLVERTEXATTRIB1DPROC)load("glVertexAttrib1d");
	glad_glVertexAttrib1dv = (PFNGLVERTEXATTRIB1DVPROC)load("glVertexAttrib1dv");
	glad_glVertexAttrib1f = (PFNGLVERTEXATTRIB1FPROC)load("glVertexAttrib1f");
	glad_glVertexAttrib1fv = (PFNGLVERTEXATTRIB1FVPROC)load("glVertexAttrib1fv");
	glad_glVertexAttrib1s = (PFNGLVERTEXATTRIB1SPROC)load("glVertexAttrib1s");
	glad_glVertexAttrib1sv = (PFNGLVERTEXATTRIB1SVPROC)load("glVertexAttrib1sv");
	glad_glVertexAttrib2d = (PFNGLVERTEXATTRIB2DPROC)load("glVertexAttrib2d");
	glad_glVertexAttrib2dv = (PFNGLVERTEXATTRIB2DVPROC)load("glVertexAttrib2dv");
	glad_glVertexAttrib2f = (PFNGLVERTEXATTRIB2FPROC)load("glVertexAttrib2f");
	glad_glVertexAttrib2fv = (PFNGLVERTEXATTRIB2FVPROC)load("glVertexAttrib2fv");
	glad_glVertexAttrib2s = (PFNGLVERTEXATTRIB2SPROC)load("glVertexAttrib2s");
	glad_glVertexAttrib2sv = (PFNGLVERTEXATTRIB2SVPROC)load("glVertexAttrib2sv");
	glad_glVertexAttrib3d = (PFNGLVERTEXATTRIB3DPROC)load("glVertexAttrib3d");
	glad_glVertexAttrib3dv = (PFNGLVERTEXATTRIB3DVPROC)load("glVertexAttrib3dv");
	glad_glVertexAttrib3f = (PFNGLVERTEXATTRIB3FPROC)load("glVertexAttrib3f");
	glad_glVertexAttrib3fv = (PFNGLVERTEXATTRIB3FVPROC)load("glVertexAttrib3fv");
	glad_glVertexAttrib3s = (PFNGLVERTEXATTRIB3SPROC)load("glVertexAttrib3s");
	glad_glVertexAttrib3sv = (PFNGLVERTEXATTRIB3SVPROC)load("glVertexAttrib3sv");
	glad_glVertexAttrib4Nbv = (PFNGLVERTEXATTRIB4NBVPROC)load("glVertexAttrib4Nbv");
	glad_glVertexAttrib4Niv = (PFNGLVERTEXATTRIB4NIVPROC)load("glVertexAttrib4Niv");
	glad_glVertexAttrib4Nsv = (PFNGLVERTEXATTRIB4NSVPROC)load("glVertexAttrib4Nsv");
	glad_glVertexAttrib4Nub = (PFNGLVERTEXATTRIB4NUBPROC)load("glVertexAttrib4Nub");
	glad_glVertexAttrib4Nubv = (PFNGLVERTEXATTRIB4NUBVPROC)load("glVertexAttrib4Nubv");
	glad_glVertexAttrib4Nuiv = (PFNGLVERTEXATTRIB4NUIVPROC)load("glVertexAttrib4Nuiv");
	glad_glVertexAttrib4Nusv = (PFNGLVERTEXATTRIB4NUSVPROC)load("glVertexAttrib4Nusv");
	glad_glVertexAttrib4bv = (PFNGLVERTEXATTRIB4BVPROC)load("glVertexAttrib4bv");
	glad_glVertexAttrib4d = (PFNGLVERTEXATTRIB4DPROC)load("glVertexAttrib4d");
	glad_glVertexAttrib4dv = (PFNGLVERTEXATTRIB4DVPROC)load("glVertexAttrib4dv");
	glad_glVertexAttrib4f = (PFNGLVERTEXATTRIB4FPROC)load("glVertexAttrib4f");
	glad_glVertexAttrib4fv = (PFNGLVERTEXATTRIB4FVPROC)load("glVertexAttrib4fv");
	glad_glVertexAttrib4iv = (PFNGLVERTEXATTRIB4IVPROC)load("glVertexAttrib4iv");
	glad_glVertexAttrib4s = (PFNGLVERTEXATTRIB4SPROC)load("glVertexAttrib4s");
	glad_glVertexAttrib4sv = (PFNGLVERTEXATTRIB4SVPROC)load("glVertexAttrib4sv");
	glad_glVertexAttrib4ubv = (PFNGLVERTEXATTRIB4UBVPROC)load("glVertexAttrib4ubv");
	glad_glVertexAttrib4uiv = (PFNGLVERTEXATTRIB4UIVPROC)load("glVertexAttrib4uiv");
	glad_glVertexAttrib4usv = (PFNGLVERTEXATTRIB4USVPROC)load("glVertexAttrib4usv");
	glad_glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC)load("glVertexAttribPointer");
}
static void load_GL_VERSION_2_1(GLADloadproc load) {
	if (!GLAD_GL_VERSION_2_1) return;
	glad_glUniformMatrix2x3fv = (PFNGLUNIFORMMATRIX2X3FVPROC)load("glUniformMatrix2x3fv");
	glad_glUniformMatrix3x2fv = (PFNGLUNIFORMMATRIX3X2FVPROC)load("glUniformMatrix3x2fv");
	glad_glUniformMatrix2x4fv = (PFNGLUNIFORMMATRIX2X4FVPROC)load("glUniformMatrix2x4fv");
	glad_glUniformMatrix4x2fv = (PFNGLUNIFORMMATRIX4X2FVPROC)load("glUniformMatrix4x2fv");
	glad_glUniformMatrix3x4fv = (PFNGLUNIFORMMATRIX3X4FVPROC)load("glUniformMatrix3x4fv");
	glad_glUniformMatrix4x3fv = (PFNGLUNIFORMMATRIX4X3FVPROC)load("glUniformMatrix4x3fv");
}
static void load_GL_VERSION_3_0(GLADloadproc load) {
	if (!GLAD_GL_VERSION_3_0) return;
	glad_glColorMaski = (PFNGLCOLORMASKIPROC)load("glColorMaski");
	glad_glGetBooleani_v = (PFNGLGETBOOLEANI_VPROC)load("glGetBooleani_v");
	glad_glGetIntegeri_v = (PFNGLGETINTEGERI_VPROC)load("glGetIntegeri_v");
	glad_glEnablei = (PFNGLENABLEIPROC)load("glEnablei");
	glad_glDisablei = (PFNGLDISABLEIPROC)load("glDisablei");
	glad_glIsEnabledi = (PFNGLISENABLEDIPROC)load("glIsEnabledi");
	glad_glBeginTransformFeedback = (PFNGLBEGINTRANSFORMFEEDBACKPROC)load("glBeginTransformFeedback");
	glad_glEndTransformFeedback = (PFNGLENDTRANSFORMFEEDBACKPROC)load("glEndTransformFeedback");
	glad_glBindBufferRange = (PFNGLBINDBUFFERRANGEPROC)load("glBindBufferRange");
	glad_glBindBufferBase = (PFNGLBINDBUFFERBASEPROC)load("glBindBufferBase");
	glad_glTransformFeedbackVaryings = (PFNGLTRANSFORMFEEDBACKVARYINGSPROC)load("glTransformFeedbackVaryings");
	glad_glGetTransformFeedbackVarying = (PFNGLGETTRANSFORMFEEDBACKVARYINGPROC)load("glGetTransformFeedbackVarying");
	glad_glClampColor = (PFNGLCLAMPCOLORPROC)load("glClampColor");
	glad_glBeginConditionalRender = (PFNGLBEGINCONDITIONALRENDERPROC)load("glBeginConditionalRender");
	glad_glEndConditionalRender = (PFNGLENDCONDITIONALRENDERPROC)load("glEndConditionalRender");
	glad_glVertexAttribIPointer = (PFNGLVERTEXATTRIBIPOINTERPROC)load("glVertexAttribIPointer");
	glad_glGetVertexAttribIiv = (PFNGLGETVERTEXATTRIBIIVPROC)load("glGetVertexAttribIiv");
	glad_glGetVertexAttribIuiv = (PFNGLGETVERTEXATTRIBIUIVPROC)load("glGetVertexAttribIuiv");
	glad_glVertexAttribI1i = (PFNGLVERTEXATTRIBI1IPROC)load("glVertexAttribI1i");
	glad_glVertexAttribI2i = (PFNGLVERTEXATTRIBI2IPROC)load("glVertexAttribI2i");
	glad_glVertexAttribI3i = (PFNGLVERTEXATTRIBI3IPROC)load("glVertexAttribI3i");
	glad_glVertexAttribI4i = (PFNGLVERTEXATTRIBI4IPROC)load("glVertexAttribI4i");
	glad_glVertexAttribI1ui = (PFNGLVERTEXATTRIBI1UIPROC)load("glVertexAttribI1ui");
	glad_glVertexAttribI2ui = (PFNGLVERTEXATTRIBI2UIPROC)load("glVertexAttribI2ui");
	glad_glVertexAttribI3ui = (PFNGLVERTEXATTRIBI3UIPROC)load("glVertexAttribI3ui");
	glad_glVertexAttribI4ui = (PFNGLVERTEXATTRIBI4UIPROC)load("glVertexAttribI4ui");
	glad_glVertexAttribI1iv = (PFNGLVERTEXATTRIBI1IVPROC)load("glVertexAttribI1iv");
	glad_glVertexAttribI2iv = (PFNGLVERTEXATTRIBI2IVPROC)load("glVertexAttribI2iv");
	glad_glVertexAttribI3iv = (PFNGLVERTEXATTRIBI3IVPROC)load("glVertexAttribI3iv");
	glad_glVertexAttribI4iv = (PFNGLVERTEXATTRIBI4IVPROC)load("glVertexAttribI4iv");
	glad_glVertexAttribI1uiv = (PFNGLVERTEXATTRIBI1UIVPROC)load("glVertexAttribI1uiv");
	glad_glVertexAttribI2uiv = (PFNGLVERTEXATTRIBI2UIVPROC)load("glVertexAttribI2uiv");
	glad_glVertexAttribI3uiv = (PFNGLVERTEXATTRIBI3UIVPROC)load("glVertexAttribI3uiv");
	glad_glVertexAttribI4uiv = (PFNGLVERTEXATTRIBI4UIVPROC)load("glVertexAttribI4uiv");
	glad_glVertexAttribI4bv = (PFNGLVERTEXATTRIBI4BVPROC)load("glVertexAttribI4bv");
	glad_glVertexAttribI4sv = (PFNGLVERTEXATTRIBI4SVPROC)load("glVertexAttribI4sv");
	glad_glVertexAttribI4ubv = (PFNGLVERTEXATTRIBI4UBVPROC)load("glVertexAttribI4ubv");
	glad_glVertexAttribI4usv = (PFNGLVERTEXATTRIBI4USVPROC)load("glVertexAttribI4usv");
	glad_glGetUniformuiv = (PFNGLGETUNIFORMUIVPROC)load("glGetUniformuiv");
	glad_glBindFragDataLocation = (PFNGLBINDFRAGDATALOCATIONPROC)load("glBindFragDataLocation");
	glad_glGetFragDataLocation = (PFNGLGETFRAGDATALOCATIONPROC)load("glGetFragDataLocation");
	glad_glUniform1ui = (PFNGLUNIFORM1UIPROC)load("glUniform1ui");
	glad_glUniform2ui = (PFNGLUNIFORM2UIPROC)load("glUniform2ui");
	glad_glUniform3ui = (PFNGLUNIFORM3UIPROC)load("glUniform3ui");
	glad_glUniform4ui = (PFNGLUNIFORM4UIPROC)load("glUniform4ui");
	glad_glUniform1uiv = (PFNGLUNIFORM1UIVPROC)load("glUniform1uiv");
	glad_glUniform2uiv = (PFNGLUNIFORM2UIVPROC)load("glUniform2uiv");
	glad_glUniform3uiv = (PFNGLUNIFORM3UIVPROC)load("glUniform3uiv");
	glad_glUniform4uiv = (PFNGLUNIFORM4UIVPROC)load("glUniform4uiv");
	glad_glTexParameterIiv = (PFNGLTEXPARAMETERIIVPROC)load("glTexParameterIiv");
	glad_glTexParameterIuiv = (PFNGLTEXPARAMETERIUIVPROC)load("glTexParameterIuiv");
	glad_glGetTexParameterIiv = (PFNGLGETTEXPARAMETERIIVPROC)load("glGetTexParameterIiv");
	glad_glGetTexParameterIuiv = (PFNGLGETTEXPARAMETERIUIVPROC)load("glGetTexParameterIuiv");
	glad_glClearBufferiv = (PFNGLCLEARBUFFERIVPROC)load("glClearBufferiv");
	glad_glClearBufferuiv = (PFNGLCLEARBUFFERUIVPROC)load("glClearBufferuiv");
	glad_glClearBufferfv = (PFNGLCLEARBUFFERFVPROC)load("glClearBufferfv");
	glad_glClearBufferfi = (PFNGLCLEARBUFFERFIPROC)load("glClearBufferfi");
	glad_glGetStringi = (PFNGLGETSTRINGIPROC)load("glGetStringi");
	glad_glIsRenderbuffer = (PFNGLISRENDERBUFFERPROC)load("glIsRenderbuffer");
	glad_glBindRenderbuffer = (PFNGLBINDRENDERBUFFERPROC)load("glBindRenderbuffer");
	glad_glDeleteRenderbuffers = (PFNGLDELETERENDERBUFFERSPROC)load("glDeleteRenderbuffers");
	glad_glGenRenderbuffers = (PFNGLGENRENDERBUFFERSPROC)load("glGenRenderbuffers");
	glad_glRenderbufferStorage = (PFNGLRENDERBUFFERSTORAGEPROC)load("glRenderbufferStorage");
	glad_glGetRenderbufferParameteriv = (PFNGLGETRENDERBUFFERPARAMETERIVPROC)load("glGetRenderbufferParameteriv");
	glad_glIsFramebuffer = (PFNGLISFRAMEBUFFERPROC)load("glIsFramebuffer");
	glad_glBindFramebuffer = (PFNGLBINDFRAMEBUFFERPROC)load("glBindFramebuffer");
	glad_glDeleteFramebuffers = (PFNGLDELETEFRAMEBUFFERSPROC)load("glDeleteFramebuffers");
	glad_glGenFramebuffers = (PFNGLGENFRAMEBUFFERSPROC)load("glGenFramebuffers");
	glad_glCheckFramebufferStatus = (PFNGLCHECKFRAMEBUFFERSTATUSPROC)load("glCheckFramebufferStatus");
	glad_glFramebufferTexture1D = (PFNGLFRAMEBUFFERTEXTURE1DPROC)load("glFramebufferTexture1D");
	glad_glFramebufferTexture2D = (PFNGLFRAMEBUFFERTEXTURE2DPROC)load("glFramebufferTexture2D");
	glad_glFramebufferTexture3D = (PFNGLFRAMEBUFFERTEXTURE3DPROC)load("glFramebufferTexture3D");
	glad_glFramebufferRenderbuffer = (PFNGLFRAMEBUFFERRENDERBUFFERPROC)load("glFramebufferRenderbuffer");
	glad_glGetFramebufferAttachmentParameteriv = (PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC)load("glGetFramebufferAttachmentParameteriv");
	glad_glGenerateMipmap = (PFNGLGENERATEMIPMAPPROC)load("glGenerateMipmap");
	glad_glBlitFramebuffer = (PFNGLBLITFRAMEBUFFERPROC)load("glBlitFramebuffer");
	glad_glRenderbufferStorageMultisample = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC)load("glRenderbufferStorageMultisample");
	glad_glFramebufferTextureLayer = (PFNGLFRAMEBUFFERTEXTURELAYERPROC)load("glFramebufferTextureLayer");
	glad_glMapBufferRange = (PFNGLMAPBUFFERRANGEPROC)load("glMapBufferRange");
	glad_glFlushMappedBufferRange = (PFNGLFLUSHMAPPEDBUFFERRANGEPROC)load("glFlushMappedBufferRange");
	glad_glBindVertexArray = (PFNGLBINDVERTEXARRAYPROC)load("glBindVertexArray");
	glad_glDeleteVertexArrays = (PFNGLDELETEVERTEXARRAYSPROC)load("glDeleteVertexArrays");
	glad_glGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC)load("glGenVertexArrays");
	glad_glIsVertexArray = (PFNGLISVERTEXARRAYPROC)load("glIsVertexArray");
}
static void load_GL_VERSION_3_1(GLADloadproc load) {
	if (!GLAD_GL_VERSION_3_1) return;
	glad_glDrawArraysInstanced = (PFNGLDRAWARRAYSINSTANCEDPROC)load("glDrawArraysInstanced");
	glad_glDrawElementsInstanced = (PFNGLDRAWELEMENTSINSTANCEDPROC)load("glDrawElementsInstanced");
	glad_glTexBuffer = (PFNGLTEXBUFFERPROC)load("glTexBuffer");
	glad_glPrimitiveRestartIndex = (PFNGLPRIMITIVERESTARTINDEXPROC)load("glPrimitiveRestartIndex");
	glad_glCopyBufferSubData = (PFNGLCOPYBUFFERSUBDATAPROC)load("glCopyBufferSubData");
	glad_glGetUniformIndices = (PFNGLGETUNIFORMINDICESPROC)load("glGetUniformIndices");
	glad_glGetActiveUniformsiv = (PFNGLGETACTIVEUNIFORMSIVPROC)load("glGetActiveUniformsiv");
	glad_glGetActiveUniformName = (PFNGLGETACTIVEUNIFORMNAMEPROC)load("glGetActiveUniformName");
	glad_glGetUniformBlockIndex = (PFNGLGETUNIFORMBLOCKINDEXPROC)load("glGetUniformBlockIndex");
	glad_glGetActiveUniformBlockiv = (PFNGLGETACTIVEUNIFORMBLOCKIVPROC)load("glGetActiveUniformBlockiv");
	glad_glGetActiveUniformBlockName = (PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC)load("glGetActiveUniformBlockName");
	glad_glUniformBlockBinding = (PFNGLUNIFORMBLOCKBINDINGPROC)load("glUniformBlockBinding");
	glad_glBindBufferRange = (PFNGLBINDBUFFERRANGEPROC)load("glBindBufferRange");
	glad_glBindBufferBase = (PFNGLBINDBUFFERBASEPROC)load("glBindBufferBase");
	glad_glGetIntegeri_v = (PFNGLGETINTEGERI_VPROC)load("glGetIntegeri_v");
}
static void load_GL_VERSION_3_2(GLADloadproc load) {
	if (!GLAD_GL_VERSION_3_2) return;
	glad_glDrawElementsBaseVertex = (PFNGLDRAWELEMENTSBASEVERTEXPROC)load("glDrawElementsBaseVertex");
	glad_glDrawRangeElementsBaseVertex = (PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC)load("glDrawRangeElementsBaseVertex");
	glad_glDrawElementsInstancedBaseVertex = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC)load("glDrawElementsInstancedBaseVertex");
	glad_glMultiDrawElementsBaseVertex = (PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC)load("glMultiDrawElementsBaseVertex");
	glad_glProvokingVertex = (PFNGLPROVOKINGVERTEXPROC)load("glProvokingVertex");
	glad_glFenceSync = (PFNGLFENCESYNCPROC)load("glFenceSync");
	glad_glIsSync = (PFNGLISSYNCPROC)load("glIsSync");
	glad_glDeleteSync = (PFNGLDELETESYNCPROC)load("glDeleteSync");
	glad_glClientWaitSync = (PFNGLCLIENTWAITSYNCPROC)load("glClientWaitSync");
	glad_glWaitSync = (PFNGLWAITSYNCPROC)load("glWaitSync");
	glad_glGetInteger64v = (PFNGLGETINTEGER64VPROC)load("glGetInteger64v");
	glad_glGetSynciv = (PFNGLGETSYNCIVPROC)load("glGetSynciv");
	glad_glGetInteger64i_v = (PFNGLGETINTEGER64I_VPROC)load("glGetInteger64i_v");
	glad_glGetBufferParameteri64v = (PFNGLGETBUFFERPARAMETERI64VPROC)load("glGetBufferParameteri64v");
	glad_glFramebufferTexture = (PFNGLFRAMEBUFFERTEXTUREPROC)load("glFramebufferTexture");
	glad_glTexImage2DMultisample = (PFNGLTEXIMAGE2DMULTISAMPLEPROC)load("glTexImage2DMultisample");
	glad_glTexImage3DMultisample = (PFNGLTEXIMAGE3DMULTISAMPLEPROC)load("glTexImage3DMultisample");
	glad_glGetMultisamplefv = (PFNGLGETMULTISAMPLEFVPROC)load("glGetMultisamplefv");
	glad_glSampleMaski = (PFNGLSAMPLEMASKIPROC)load("glSampleMaski");
}
static void load_GL_VERSION_3_3(GLADloadproc load) {
	if (!GLAD_GL_VERSION_3_3) return;
	glad_glBindFragDataLocationIndexed = (PFNGLBINDFRAGDATALOCATIONINDEXEDPROC)load("glBindFragDataLocationIndexed");
	glad_glGetFragDataIndex = (PFNGLGETFRAGDATAINDEXPROC)load("glGetFragDataIndex");
	glad_glGenSamplers = (PFNGLGENSAMPLERSPROC)load("glGenSamplers");
	glad_glDeleteSamplers = (PFNGLDELETESAMPLERSPROC)load("glDeleteSamplers");
	glad_glIsSampler = (PFNGLISSAMPLERPROC)load("glIsSampler");
	glad_glBindSampler = (PFNGLBINDSAMPLERPROC)load("glBindSampler");
	glad_glSamplerParameteri = (PFNGLSAMPLERPARAMETERIPROC)load("glSamplerParameteri");
	glad_glSamplerParameteriv = (PFNGLSAMPLERPARAMETERIVPROC)load("glSamplerParameteriv");
	glad_glSamplerParameterf = (PFNGLSAMPLERPARAMETERFPROC)load("glSamplerParameterf");
	glad_glSamplerParameterfv = (PFNGLSAMPLERPARAMETERFVPROC)load("glSamplerParameterfv");
	glad_glSamplerParameterIiv = (PFNGLSAMPLERPARAMETERIIVPROC)load("glSamplerParameterIiv");
	glad_glSamplerParameterIuiv = (PFNGLSAMPLERPARAMETERIUIVPROC)load("glSamplerParameterIuiv");
	glad_glGetSamplerParameteriv = (PFNGLGETSAMPLERPARAMETERIVPROC)load("glGetSamplerParameteriv");
	glad_glGetSamplerParameterIiv = (PFNGLGETSAMPLERPARAMETERIIVPROC)load("glGetSamplerParameterIiv");
	glad_glGetSamplerParameterfv = (PFNGLGETSAMPLERPARAMETERFVPROC)load("glGetSamplerParameterfv");
	glad_glGetSamplerParameterIuiv = (PFNGLGETSAMPLERPARAMETERIUIVPROC)load("glGetSamplerParameterIuiv");
	glad_glQueryCounter = (PFNGLQUERYCOUNTERPROC)load("glQueryCounter");
	glad_glGetQueryObjecti64v = (PFNGLGETQUERYOBJECTI64VPROC)load("glGetQueryObjecti64v");
	glad_glGetQueryObjectui64v = (PFNGLGETQUERYOBJECTUI64VPROC)load("glGetQueryObjectui64v");
	glad_glVertexAttribDivisor = (PFNGLVERTEXATTRIBDIVISORPROC)load("glVertexAttribDivisor");
	glad_glVertexAttribP1ui = (PFNGLVERTEXATTRIBP1UIPROC)load("glVertexAttribP1ui");
	glad_glVertexAttribP1uiv = (PFNGLVERTEXATTRIBP1UIVPROC)load("glVertexAttribP1uiv");
	glad_glVertexAttribP2ui = (PFNGLVERTEXATTRIBP2UIPROC)load("glVertexAttribP2ui");
	glad_glVertexAttribP2uiv = (PFNGLVERTEXATTRIBP2UIVPROC)load("glVertexAttribP2uiv");
	glad_glVertexAttribP3ui = (PFNGLVERTEXATTRIBP3UIPROC)load("glVertexAttribP3ui");
	glad_glVertexAttribP3uiv = (PFNGLVERTEXATTRIBP3UIVPROC)load("glVertexAttribP3uiv");
	glad_glVertexAttribP4ui = (PFNGLVERTEXATTRIBP4UIPROC)load("glVertexAttribP4ui");
	glad_glVertexAttribP4uiv = (PFNGLVERTEXATTRIBP4UIVPROC)load("glVertexAttribP4uiv");
	glad_glVertexP2ui = (PFNGLVERTEXP2UIPROC)load("glVertexP2ui");
	glad_glVertexP2uiv = (PFNGLVERTEXP2UIVPROC)load("glVertexP2uiv");
	glad_glVertexP3ui = (PFNGLVERTEXP3UIPROC)load("glVertexP3ui");
	glad_glVertexP3uiv = (PFNGLVERTEXP3UIVPROC)load("glVertexP3uiv");
	glad_glVertexP4ui = (PFNGLVERTEXP4UIPROC)load("glVertexP4ui");
	glad_glVertexP4uiv = (PFNGLVERTEXP4UIVPROC)load("glVertexP4uiv");
	glad_glTexCoordP1ui = (PFNGLTEXCOORDP1UIPROC)load("glTexCoordP1ui");
	glad_glTexCoordP1uiv = (PFNGLTEXCOORDP1UIVPROC)load("glTexCoordP1uiv");
	glad_glTexCoordP2ui = (PFNGLTEXCOORDP2UIPROC)load("glTexCoordP2ui");
	glad_glTexCoordP2uiv = (PFNGLTEXCOORDP2UIVPROC)load("glTexCoordP2uiv");
	glad_glTexCoordP3ui = (PFNGLTEXCOORDP3UIPROC)load("glTexCoordP3ui");
	glad_glTexCoordP3uiv = (PFNGLTEXCOORDP3UIVPROC)load("glTexCoordP3uiv");
	glad_glTexCoordP4ui = (PFNGLTEXCOORDP4UIPROC)load("glTexCoordP4ui");
	glad_glTexCoordP4uiv = (PFNGLTEXCOORDP4UIVPROC)load("glTexCoordP4uiv");
	glad_glMultiTexCoordP1ui = (PFNGLMULTITEXCOORDP1UIPROC)load("glMultiTexCoordP1ui");
	glad_glMultiTexCoordP1uiv = (PFNGLMULTITEXCOORDP1UIVPROC)load("glMultiTexCoordP1uiv");
	glad_glMultiTexCoordP2ui = (PFNGLMULTITEXCOORDP2UIPROC)load("glMultiTexCoordP2ui");
	glad_glMultiTexCoordP2uiv = (PFNGLMULTITEXCOORDP2UIVPROC)load("glMultiTexCoordP2uiv");
	glad_glMultiTexCoordP3ui = (PFNGLMULTITEXCOORDP3UIPROC)load("glMultiTexCoordP3ui");
	glad_glMultiTexCoordP3uiv = (PFNGLMULTITEXCOORDP3UIVPROC)load("glMultiTexCoordP3uiv");
	glad_glMultiTexCoordP4ui = (PFNGLMULTITEXCOORDP4UIPROC)load("glMultiTexCoordP4ui");
	glad_glMultiTexCoordP4uiv = (PFNGLMULTITEXCOORDP4UIVPROC)load("glMultiTexCoordP4uiv");
	glad_glNormalP3ui = (PFNGLNORMALP3UIPROC)load("glNormalP3ui");
	glad_glNormalP3uiv = (PFNGLNORMALP3UIVPROC)load("glNormalP3uiv");
	glad_glColorP3ui = (PFNGLCOLORP3UIPROC)load("glColorP3ui");
	glad_glColorP3uiv = (PFNGLCOLORP3UIVPROC)load("glColorP3uiv");
	glad_glColorP4ui = (PFNGLCOLORP4UIPROC)load("glColorP4ui");
	glad_glColorP4uiv = (PFNGLCOLORP4UIVPROC)load("glColorP4uiv");
	glad_glSecondaryColorP3ui = (PFNGLSECONDARYCOLORP3UIPROC)load("glSecondaryColorP3ui");
	glad_glSecondaryColorP3uiv = (PFNGLSECONDARYCOLORP3UIVPROC)load("glSecondaryColorP3uiv");
}
static void load_GL_VERSION_4_0(GLADloadproc load) {
	if (!GLAD_GL_VERSION_4_0) return;
	glad_glMinSampleShading = (PFNGLMINSAMPLESHADINGPROC)load("glMinSampleShading");
	glad_glBlendEquationi = (PFNGLBLENDEQUATIONIPROC)load("glBlendEquationi");
	glad_glBlendEquationSeparatei = (PFNGLBLENDEQUATIONSEPARATEIPROC)load("glBlendEquationSeparatei");
	glad_glBlendFunci = (PFNGLBLENDFUNCIPROC)load("glBlendFunci");
	glad_glBlendFuncSeparatei = (PFNGLBLENDFUNCSEPARATEIPROC)load("glBlendFuncSeparatei");
	glad_glDrawArraysIndirect = (PFNGLDRAWARRAYSINDIRECTPROC)load("glDrawArraysIndirect");
	glad_glDrawElementsIndirect = (PFNGLDRAWELEMENTSINDIRECTPROC)load("glDrawElementsIndirect");
	glad_glUniform1d = (PFNGLUNIFORM1DPROC)load("glUniform1d");
	glad_glUniform2d = (PFNGLUNIFORM2DPROC)load("glUniform2d");
	glad_glUniform3d = (PFNGLUNIFORM3DPROC)load("glUniform3d");
	glad_glUniform4d = (PFNGLUNIFORM4DPROC)load("glUniform4d");
	glad_glUniform1dv = (PFNGLUNIFORM1DVPROC)load("glUniform1dv");
	glad_glUniform2dv = (PFNGLUNIFORM2DVPROC)load("glUniform2dv");
	glad_glUniform3dv = (PFNGLUNIFORM3DVPROC)load("glUniform3dv");
	glad_glUniform4dv = (PFNGLUNIFORM4DVPROC)load("glUniform4dv");
	glad_glUniformMatrix2dv = (PFNGLUNIFORMMATRIX2DVPROC)load("glUniformMatrix2dv");
	glad_glUniformMatrix3dv = (PFNGLUNIFORMMATRIX3DVPROC)load("glUniformMatrix3dv");
	glad_glUniformMatrix4dv = (PFNGLUNIFORMMATRIX4DVPROC)load("glUniformMatrix4dv");
	glad_glUniformMatrix2x3dv = (PFNGLUNIFORMMATRIX2X3DVPROC)load("glUniformMatrix2x3dv");
	glad_glUniformMatrix2x4dv = (PFNGLUNIFORMMATRIX2X4DVPROC)load("glUniformMatrix2x4dv");
	glad_glUniformMatrix3x2dv = (PFNGLUNIFORMMATRIX3X2DVPROC)load("glUniformMatrix3x2dv");
	glad_glUniformMatrix3x4dv = (PFNGLUNIFORMMATRIX3X4DVPROC)load("glUniformMatrix3x4dv");
	glad_glUniformMatrix4x2dv = (PFNGLUNIFORMMATRIX4X2DVPROC)load("glUniformMatrix4x2dv");
	glad_glUniformMatrix4x3dv = (PFNGLUNIFORMMATRIX4X3DVPROC)load("glUniformMatrix4x3dv");
	glad_glGetUniformdv = (PFNGLGETUNIFORMDVPROC)load("glGetUniformdv");
	glad_glGetSubroutineUniformLocation = (PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC)load("glGetSubroutineUniformLocation");
	glad_glGetSubroutineIndex = (PFNGLGETSUBROUTINEINDEXPROC)load("glGetSubroutineIndex");
	glad_glGetActiveSubroutineUniformiv = (PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC)load("glGetActiveSubroutineUniformiv");
	glad_glGetActiveSubroutineUniformName = (PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC)load("glGetActiveSubroutineUniformName");
	glad_glGetActiveSubroutineName = (PFNGLGETACTIVESUBROUTINENAMEPROC)load("glGetActiveSubroutineName");
	glad_glUniformSubroutinesuiv = (PFNGLUNIFORMSUBROUTINESUIVPROC)load("glUniformSubroutinesuiv");
	glad_glGetUniformSubroutineuiv = (PFNGLGETUNIFORMSUBROUTINEUIVPROC)load("glGetUniformSubroutineuiv");
	glad_glGetProgramStageiv = (PFNGLGETPROGRAMSTAGEIVPROC)load("glGetProgramStageiv");
	glad_glPatchParameteri = (PFNGLPATCHPARAMETERIPROC)load("glPatchParameteri");
	glad_glPatchParameterfv = (PFNGLPATCHPARAMETERFVPROC)load("glPatchParameterfv");
	glad_glBindTransformFeedback = (PFNGLBINDTRANSFORMFEEDBACKPROC)load("glBindTransformFeedback");
	glad_glDeleteTransformFeedbacks = (PFNGLDELETETRANSFORMFEEDBACKSPROC)load("glDeleteTransformFeedbacks");
	glad_glGenTransformFeedbacks = (PFNGLGENTRANSFORMFEEDBACKSPROC)load("glGenTransformFeedbacks");
	glad_glIsTransformFeedback = (PFNGLISTRANSFORMFEEDBACKPROC)load("glIsTransformFeedback");
	glad_glPauseTransformFeedback = (PFNGLPAUSETRANSFORMFEEDBACKPROC)load("glPauseTransformFeedback");
	glad_glResumeTransformFeedback = (PFNGLRESUMETRANSFORMFEEDBACKPROC)load("glResumeTransformFeedback");
	glad_glDrawTransformFeedback = (PFNGLDRAWTRANSFORMFEEDBACKPROC)load("glDrawTransformFeedback");
	glad_glDrawTransformFeedbackStream = (PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC)load("glDrawTransformFeedbackStream");
	glad_glBeginQueryIndexed = (PFNGLBEGINQUERYINDEXEDPROC)load("glBeginQueryIndexed");
	glad_glEndQueryIndexed = (PFNGLENDQUERYINDEXEDPROC)load("glEndQueryIndexed");
	glad_glGetQueryIndexediv = (PFNGLGETQUERYINDEXEDIVPROC)load("glGetQueryIndexediv");
}
static void load_GL_VERSION_4_1(GLADloadproc load) {
	if (!GLAD_GL_VERSION_4_1) return;
	glad_glReleaseShaderCompiler = (PFNGLRELEASESHADERCOMPILERPROC)load("glReleaseShaderCompiler");
	glad_glShaderBinary = (PFNGLSHADERBINARYPROC)load("glShaderBinary");
	glad_glGetShaderPrecisionFormat = (PFNGLGETSHADERPRECISIONFORMATPROC)load("glGetShaderPrecisionFormat");
	glad_glDepthRangef = (PFNGLDEPTHRANGEFPROC)load("glDepthRangef");
	glad_glClearDepthf = (PFNGLCLEARDEPTHFPROC)load("glClearDepthf");
	glad_glGetProgramBinary = (PFNGLGETPROGRAMBINARYPROC)load("glGetProgramBinary");
	glad_glProgramBinary = (PFNGLPROGRAMBINARYPROC)load("glProgramBinary");
	glad_glProgramParameteri = (PFNGLPROGRAMPARAMETERIPROC)load("glProgramParameteri");
	glad_glUseProgramStages = (PFNGLUSEPROGRAMSTAGESPROC)load("glUseProgramStages");
	glad_glActiveShaderProgram = (PFNGLACTIVESHADERPROGRAMPROC)load("glActiveShaderProgram");
	glad_glCreateShaderProgramv = (PFNGLCREATESHADERPROGRAMVPROC)load("glCreateShaderProgramv");
	glad_glBindProgramPipeline = (PFNGLBINDPROGRAMPIPELINEPROC)load("glBindProgramPipeline");
	glad_glDeleteProgramPipelines = (PFNGLDELETEPROGRAMPIPELINESPROC)load("glDeleteProgramPipelines");
	glad_glGenProgramPipelines = (PFNGLGENPROGRAMPIPELINESPROC)load("glGenProgramPipelines");
	glad_glIsProgramPipeline = (PFNGLISPROGRAMPIPELINEPROC)load("glIsProgramPipeline");
	glad_glGetProgramPipelineiv = (PFNGLGETPROGRAMPIPELINEIVPROC)load("glGetProgramPipelineiv");
	glad_glProgramUniform1i = (PFNGLPROGRAMUNIFORM1IPROC)load("glProgramUniform1i");
	glad_glProgramUniform1iv = (PFNGLPROGRAMUNIFORM1IVPROC)load("glProgramUniform1iv");
	glad_glProgramUniform1f = (PFNGLPROGRAMUNIFORM1FPROC)load("glProgramUniform1f");
	glad_glProgramUniform1fv = (PFNGLPROGRAMUNIFORM1FVPROC)load("glProgramUniform1fv");
	glad_glProgramUniform1d = (PFNGLPROGRAMUNIFORM1DPROC)load("glProgramUniform1d");
	glad_glProgramUniform1dv = (PFNGLPROGRAMUNIFORM1DVPROC)load("glProgramUniform1dv");
	glad_glProgramUniform1ui = (PFNGLPROGRAMUNIFORM1UIPROC)load("glProgramUniform1ui");
	glad_glProgramUniform1uiv = (PFNGLPROGRAMUNIFORM1UIVPROC)load("glProgramUniform1uiv");
	glad_glProgramUniform2i = (PFNGLPROGRAMUNIFORM2IPROC)load("glProgramUniform2i");
	glad_glProgramUniform2iv = (PFNGLPROGRAMUNIFORM2IVPROC)load("glProgramUniform2iv");
	glad_glProgramUniform2f = (PFNGLPROGRAMUNIFORM2FPROC)load("glProgramUniform2f");
	glad_glProgramUniform2fv = (PFNGLPROGRAMUNIFORM2FVPROC)load("glProgramUniform2fv");
	glad_glProgramUniform2d = (PFNGLPROGRAMUNIFORM2DPROC)load("glProgramUniform2d");
	glad_glProgramUniform2dv = (PFNGLPROGRAMUNIFORM2DVPROC)load("glProgramUniform2dv");
	glad_glProgramUniform2ui = (PFNGLPROGRAMUNIFORM2UIPROC)load("glProgramUniform2ui");
	glad_glProgramUniform2uiv = (PFNGLPROGRAMUNIFORM2UIVPROC)load("glProgramUniform2uiv");
	glad_glProgramUniform3i = (PFNGLPROGRAMUNIFORM3IPROC)load("glProgramUniform3i");
	glad_glProgramUniform3iv = (PFNGLPROGRAMUNIFORM3IVPROC)load("glProgramUniform3iv");
	glad_glProgramUniform3f = (PFNGLPROGRAMUNIFORM3FPROC)load("glProgramUniform3f");
	glad_glProgramUniform3fv = (PFNGLPROGRAMUNIFORM3FVPROC)load("glProgramUniform3fv");
	glad_glProgramUniform3d = (PFNGLPROGRAMUNIFORM3DPROC)load("glProgramUniform3d");
	glad_glProgramUniform3dv = (PFNGLPROGRAMUNIFORM3DVPROC)load("glProgramUniform3dv");
	glad_glProgramUniform3ui = (PFNGLPROGRAMUNIFORM3UIPROC)load("glProgramUniform3ui");
	glad_glProgramUniform3uiv = (PFNGLPROGRAMUNIFORM3UIVPROC)load("glProgramUniform3uiv");
	glad_glProgramUniform4i = (PFNGLPROGRAMUNIFORM4IPROC)load("glProgramUniform4i");
	glad_glProgramUniform4iv = (PFNGLPROGRAMUNIFORM4IVPROC)load("glProgramUniform4iv");
	glad_glProgramUniform4f = (PFNGLPROGRAMUNIFORM4FPROC)load("glProgramUniform4f");
	glad_glProgramUniform4fv = (PFNGLPROGRAMUNIFORM4FVPROC)load("glProgramUniform4fv");
	glad_glProgramUniform4d = (PFNGLPROGRAMUNIFORM4DPROC)load("glProgramUniform4d");
	glad_glProgramUniform4dv = (PFNGLPROGRAMUNIFORM4DVPROC)load("glProgramUniform4dv");
	glad_glProgramUniform4ui = (PFNGLPROGRAMUNIFORM4UIPROC)load("glProgramUniform4ui");
	glad_glProgramUniform4uiv = (PFNGLPROGRAMUNIFORM4UIVPROC)load("glProgramUniform4uiv");
	glad_glProgramUniformMatrix2fv = (PFNGLPROGRAMUNIFORMMATRIX2FVPROC)load("glProgramUniformMatrix2fv");
	glad_glProgramUniformMatrix3fv = (PFNGLPROGRAMUNIFORMMATRIX3FVPROC)load("glProgramUniformMatrix3fv");
	glad_glProgramUniformMatrix4fv = (PFNGLPROGRAMUNIFORMMATRIX4FVPROC)load("glProgramUniformMatrix4fv");
	glad_glProgramUniformMatrix2dv = (PFNGLPROGRAMUNIFORMMATRIX2DVPROC)load("glProgramUniformMatrix2dv");
	glad_glProgramUniformMatrix3dv = (PFNGLPROGRAMUNIFORMMATRIX3DVPROC)load("glProgramUniformMatrix3dv");
	glad_glProgramUniformMatrix4dv = (PFNGLPROGRAMUNIFORMMATRIX4DVPROC)load("glProgramUniformMatrix4dv");
	glad_glProgramUniformMatrix2x3fv = (PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC)load("glProgramUniformMatrix2x3fv");
	glad_glProgramUniformMatrix3x2fv = (PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC)load("glProgramUniformMatrix3x2fv");
	glad_glProgramUniformMatrix2x4fv = (PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC)load("glProgramUniformMatrix2x4fv");
	glad_glProgramUniformMatrix4x2fv = (PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC)load("glProgramUniformMatrix4x2fv");
	glad_glProgramUniformMatrix3x4fv = (PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC)load("glProgramUniformMatrix3x4fv");
	glad_glProgramUniformMatrix4x3fv = (PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC)load("glProgramUniformMatrix4x3fv");
	glad_glProgramUniformMatrix2x3dv = (PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC)load("glProgramUniformMatrix2x3dv");
	glad_glProgramUniformMatrix3x2dv = (PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC)load("glProgramUniformMatrix3x2dv");
	glad_glProgramUniformMatrix2x4dv = (PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC)load("glProgramUniformMatrix2x4dv");
	glad_glProgramUniformMatrix4x2dv = (PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC)load("glProgramUniformMatrix4x2dv");
	glad_glProgramUniformMatrix3x4dv = (PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC)load("glProgramUniformMatrix3x4dv");
	glad_glProgramUniformMatrix4x3dv = (PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC)load("glProgramUniformMatrix4x3dv");
	glad_glValidateProgramPipeline = (PFNGLVALIDATEPROGRAMPIPELINEPROC)load("glValidateProgramPipeline");
	glad_glGetProgramPipelineInfoLog = (PFNGLGETPROGRAMPIPELINEINFOLOGPROC)load("glGetProgramPipelineInfoLog");
	glad_glVertexAttribL1d = (PFNGLVERTEXATTRIBL1DPROC)load("glVertexAttribL1d");
	glad_glVertexAttribL2d = (PFNGLVERTEXATTRIBL2DPROC)load("glVertexAttribL2d");
	glad_glVertexAttribL3d = (PFNGLVERTEXATTRIBL3DPROC)load("glVertexAttribL3d");
	glad_glVertexAttribL4d = (PFNGLVERTEXATTRIBL4DPROC)load("glVertexAttribL4d");
	glad_glVertexAttribL1dv = (PFNGLVERTEXATTRIBL1DVPROC)load("glVertexAttribL1dv");
	glad_glVertexAttribL2dv = (PFNGLVERTEXATTRIBL2DVPROC)load("glVertexAttribL2dv");
	glad_glVertexAttribL3dv = (PFNGLVERTEXATTRIBL3DVPROC)load("glVertexAttribL3dv");
	glad_glVertexAttribL4dv = (PFNGLVERTEXATTRIBL4DVPROC)load("glVertexAttribL4dv");
	glad_glVertexAttribLPointer = (PFNGLVERTEXATTRIBLPOINTERPROC)load("glVertexAttribLPointer");
	glad_glGetVertexAttribLdv = (PFNGLGETVERTEXATTRIBLDVPROC)load("glGetVertexAttribLdv");
	glad_glViewportArrayv = (PFNGLVIEWPORTARRAYVPROC)load("glViewportArrayv");
	glad_glViewportIndexedf = (PFNGLVIEWPORTINDEXEDFPROC)load("glViewportIndexedf");
	glad_glViewportIndexedfv = (PFNGLVIEWPORTINDEXEDFVPROC)load("glViewportIndexedfv");
	glad_glScissorArrayv = (PFNGLSCISSORARRAYVPROC)load("glScissorArrayv");
	glad_glScissorIndexed = (PFNGLSCISSORINDEXEDPROC)load("glScissorIndexed");
	glad_glScissorIndexedv = (PFNGLSCISSORINDEXEDVPROC)load("glScissorIndexedv");
	glad_glDepthRangeArrayv = (PFNGLDEPTHRANGEARRAYVPROC)load("glDepthRangeArrayv");
	glad_glDepthRangeIndexed = (PFNGLDEPTHRANGEINDEXEDPROC)load("glDepthRangeIndexed");
	glad_glGetFloati_v = (PFNGLGETFLOATI_VPROC)load("glGetFloati_v");
	glad_glGetDoublei_v = (PFNGLGETDOUBLEI_VPROC)load("glGetDoublei_v");
}
static void load_GL_VERSION_4_2(GLADloadproc load) {
	if (!GLAD_GL_VERSION_4_2) return;
	glad_glDrawArraysInstancedBaseInstance = (PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC)load("glDrawArraysInstancedBaseInstance");
	glad_glDrawElementsInstancedBaseInstance = (PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC)load("glDrawElementsInstancedBaseInstance");
	glad_glDrawElementsInstancedBaseVertexBaseInstance = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC)load("glDrawElementsInstancedBaseVertexBaseInstance");
	glad_glGetInternalformativ = (PFNGLGETINTERNALFORMATIVPROC)load("glGetInternalformativ");
	glad_glGetActiveAtomicCounterBufferiv = (PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC)load("glGetActiveAtomicCounterBufferiv");
	glad_glBindImageTexture = (PFNGLBINDIMAGETEXTUREPROC)load("glBindImageTexture");
	glad_glMemoryBarrier = (PFNGLMEMORYBARRIERPROC)load("glMemoryBarrier");
	glad_glTexStorage1D = (PFNGLTEXSTORAGE1DPROC)load("glTexStorage1D");
	glad_glTexStorage2D = (PFNGLTEXSTORAGE2DPROC)load("glTexStorage2D");
	glad_glTexStorage3D = (PFNGLTEXSTORAGE3DPROC)load("glTexStorage3D");
	glad_glDrawTransformFeedbackInstanced = (PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC)load("glDrawTransformFeedbackInstanced");
	glad_glDrawTransformFeedbackStreamInstanced = (PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC)load("glDrawTransformFeedbackStreamInstanced");
}
static void load_GL_VERSION_4_3(GLADloadproc load) {
	if (!GLAD_GL_VERSION_4_3) return;
	glad_glClearBufferData = (PFNGLCLEARBUFFERDATAPROC)load("glClearBufferData");
	glad_glClearBufferSubData = (PFNGLCLEARBUFFERSUBDATAPROC)load("glClearBufferSubData");
	glad_glDispatchCompute = (PFNGLDISPATCHCOMPUTEPROC)load("glDispatchCompute");
	glad_glDispatchComputeIndirect = (PFNGLDISPATCHCOMPUTEINDIRECTPROC)load("glDispatchComputeIndirect");
	glad_glCopyImageSubData = (PFNGLCOPYIMAGESUBDATAPROC)load("glCopyImageSubData");
	glad_glFramebufferParameteri = (PFNGLFRAMEBUFFERPARAMETERIPROC)load("glFramebufferParameteri");
	glad_glGetFramebufferParameteriv = (PFNGLGETFRAMEBUFFERPARAMETERIVPROC)load("glGetFramebufferParameteriv");
	glad_glGetInternalformati64v = (PFNGLGETINTERNALFORMATI64VPROC)load("glGetInternalformati64v");
	glad_glInvalidateTexSubImage = (PFNGLINVALIDATETEXSUBIMAGEPROC)load("glInvalidateTexSubImage");
	glad_glInvalidateTexImage = (PFNGLINVALIDATETEXIMAGEPROC)load("glInvalidateTexImage");
	glad_glInvalidateBufferSubData = (PFNGLINVALIDATEBUFFERSUBDATAPROC)load("glInvalidateBufferSubData");
	glad_glInvalidateBufferData = (PFNGLINVALIDATEBUFFERDATAPROC)load("glInvalidateBufferData");
	glad_glInvalidateFramebuffer = (PFNGLINVALIDATEFRAMEBUFFERPROC)load("glInvalidateFramebuffer");
	glad_glInvalidateSubFramebuffer = (PFNGLINVALIDATESUBFRAMEBUFFERPROC)load("glInvalidateSubFramebuffer");
	glad_glMultiDrawArraysIndirect = (PFNGLMULTIDRAWARRAYSINDIRECTPROC)load("glMultiDrawArraysIndirect");
	glad_glMultiDrawElementsIndirect = (PFNGLMULTIDRAWELEMENTSINDIRECTPROC)load("glMultiDrawElementsIndirect");
	glad_glGetProgramInterfaceiv = (PFNGLGETPROGRAMINTERFACEIVPROC)load("glGetProgramInterfaceiv");
	glad_glGetProgramResourceIndex = (PFNGLGETPROGRAMRESOURCEINDEXPROC)load("glGetProgramResourceIndex");
	glad_glGetProgramResourceName = (PFNGLGETPROGRAMRESOURCENAMEPROC)load("glGetProgramResourceName");
	glad_glGetProgramResourceiv = (PFNGLGETPROGRAMRESOURCEIVPROC)load("glGetProgramResourceiv");
	glad_glGetProgramResourceLocation = (PFNGLGETPROGRAMRESOURCELOCATIONPROC)load("glGetProgramResourceLocation");
	glad_glGetProgramResourceLocationIndex = (PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC)load("glGetProgramResourceLocationIndex");
	glad_glShaderStorageBlockBinding = (PFNGLSHADERSTORAGEBLOCKBINDINGPROC)load("glShaderStorageBlockBinding");
	glad_glTexBufferRange = (PFNGLTEXBUFFERRANGEPROC)load("glTexBufferRange");
	glad_glTexStorage2DMultisample = (PFNGLTEXSTORAGE2DMULTISAMPLEPROC)load("glTexStorage2DMultisample");
	glad_glTexStorage3DMultisample = (PFNGLTEXSTORAGE3DMULTISAMPLEPROC)load("glTexStorage3DMultisample");
	glad_glTextureView = (PFNGLTEXTUREVIEWPROC)load("glTextureView");
	glad_glBindVertexBuffer = (PFNGLBINDVERTEXBUFFERPROC)load("glBindVertexBuffer");
	glad_glVertexAttribFormat = (PFNGLVERTEXATTRIBFORMATPROC)load("glVertexAttribFormat");
	glad_glVertexAttribIFormat = (PFNGLVERTEXATTRIBIFORMATPROC)load("glVertexAttribIFormat");
	glad_glVertexAttribLFormat = (PFNGLVERTEXATTRIBLFORMATPROC)load("glVertexAttribLFormat");
	glad_glVertexAttribBinding = (PFNGLVERTEXATTRIBBINDINGPROC)load("glVertexAttribBinding");
	glad_glVertexBindingDivisor = (PFNGLVERTEXBINDINGDIVISORPROC)load("glVertexBindingDivisor");
	glad_glDebugMessageControl = (PFNGLDEBUGMESSAGECONTROLPROC)load("glDebugMessageControl");
	glad_glDebugMessageInsert = (PFNGLDEBUGMESSAGEINSERTPROC)load("glDebugMessageInsert");
	glad_glDebugMessageCallback = (PFNGLDEBUGMESSAGECALLBACKPROC)load("glDebugMessageCallback");
	glad_glGetDebugMessageLog = (PFNGLGETDEBUGMESSAGELOGPROC)load("glGetDebugMessageLog");
	glad_glPushDebugGroup = (PFNGLPUSHDEBUGGROUPPROC)load("glPushDebugGroup");
	glad_glPopDebugGroup = (PFNGLPOPDEBUGGROUPPROC)load("glPopDebugGroup");
	glad_glObjectLabel = (PFNGLOBJECTLABELPROC)load("glObjectLabel");
	glad_glGetObjectLabel = (PFNGLGETOBJECTLABELPROC)load("glGetObjectLabel");
	glad_glObjectPtrLabel = (PFNGLOBJECTPTRLABELPROC)load("glObjectPtrLabel");
	glad_glGetObjectPtrLabel = (PFNGLGETOBJECTPTRLABELPROC)load("glGetObjectPtrLabel");
	glad_glGetPointerv = (PFNGLGETPOINTERVPROC)load("glGetPointerv");
	glad_glGetPointerv = (PFNGLGETPOINTERVPROC)load("glGetPointerv");
}
static void load_GL_VERSION_4_4(GLADloadproc load) {
	if (!GLAD_GL_VERSION_4_4) return;
	glad_glBufferStorage = (PFNGLBUFFERSTORAGEPROC)load("glBufferStorage");
	glad_glClearTexImage = (PFNGLCLEARTEXIMAGEPROC)load("glClearTexImage");
	glad_glClearTexSubImage = (PFNGLCLEARTEXSUBIMAGEPROC)load("glClearTexSubImage");
	glad_glBindBuffersBase = (PFNGLBINDBUFFERSBASEPROC)load("glBindBuffersBase");
	glad_glBindBuffersRange = (PFNGLBINDBUFFERSRANGEPROC)load("glBindBuffersRange");
	glad_glBindTextures = (PFNGLBINDTEXTURESPROC)load("glBindTextures");
	glad_glBindSamplers = (PFNGLBINDSAMPLERSPROC)load("glBindSamplers");
	glad_glBindImageTextures = (PFNGLBINDIMAGETEXTURESPROC)load("glBindImageTextures");
	glad_glBindVertexBuffers = (PFNGLBINDVERTEXBUFFERSPROC)load("glBindVertexBuffers");
}
static void load_GL_VERSION_4_5(GLADloadproc load) {
	if (!GLAD_GL_VERSION_4_5) return;
	glad_glClipControl = (PFNGLCLIPCONTROLPROC)load("glClipControl");
	glad_glCreateTransformFeedbacks = (PFNGLCREATETRANSFORMFEEDBACKSPROC)load("glCreateTransformFeedbacks");
	glad_glTransformFeedbackBufferBase = (PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC)load("glTransformFeedbackBufferBase");
	glad_glTransformFeedbackBufferRange = (PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC)load("glTransformFeedbackBufferRange");
	glad_glGetTransformFeedbackiv = (PFNGLGETTRANSFORMFEEDBACKIVPROC)load("glGetTransformFeedbackiv");
	glad_glGetTransformFeedbacki_v = (PFNGLGETTRANSFORMFEEDBACKI_VPROC)load("glGetTransformFeedbacki_v");
	glad_glGetTransformFeedbacki64_v = (PFNGLGETTRANSFORMFEEDBACKI64_VPROC)load("glGetTransformFeedbacki64_v");
	glad_glCreateBuffers = (PFNGLCREATEBUFFERSPROC)load("glCreateBuffers");
	glad_glNamedBufferStorage = (PFNGLNAMEDBUFFERSTORAGEPROC)load("glNamedBufferStorage");
	glad_glNamedBufferData = (PFNGLNAMEDBUFFERDATAPROC)load("glNamedBufferData");
	glad_glNamedBufferSubData = (PFNGLNAMEDBUFFERSUBDATAPROC)load("glNamedBufferSubData");
	glad_glCopyNamedBufferSubData = (PFNGLCOPYNAMEDBUFFERSUBDATAPROC)load("glCopyNamedBufferSubData");
	glad_glClearNamedBufferData = (PFNGLCLEARNAMEDBUFFERDATAPROC)load("glClearNamedBufferData");
	glad_glClearNamedBufferSubData = (PFNGLCLEARNAMEDBUFFERSUBDATAPROC)load("glClearNamedBufferSubData");
	glad_glMapNamedBuffer = (PFNGLMAPNAMEDBUFFERPROC)load("glMapNamedBuffer");
	glad_glMapNamedBufferRange = (PFNGLMAPNAMEDBUFFERRANGEPROC)load("glMapNamedBufferRange");
	glad_glUnmapNamedBuffer = (PFNGLUNMAPNAMEDBUFFERPROC)load("glUnmapNamedBuffer");
	glad_glFlushMappedNamedBufferRange = (PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC)load("glFlushMappedNamedBufferRange");
	glad_glGetNamedBufferParameteriv = (PFNGLGETNAMEDBUFFERPARAMETERIVPROC)load("glGetNamedBufferParameteriv");
	glad_glGetNamedBufferParameteri64v = (PFNGLGETNAMEDBUFFERPARAMETERI64VPROC)load("glGetNamedBufferParameteri64v");
	glad_glGetNamedBufferPointerv = (PFNGLGETNAMEDBUFFERPOINTERVPROC)load("glGetNamedBufferPointerv");
	glad_glGetNamedBufferSubData = (PFNGLGETNAMEDBUFFERSUBDATAPROC)load("glGetNamedBufferSubData");
	glad_glCreateFramebuffers = (PFNGLCREATEFRAMEBUFFERSPROC)load("glCreateFramebuffers");
	glad_glNamedFramebufferRenderbuffer = (PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC)load("glNamedFramebufferRenderbuffer");
	glad_glNamedFramebufferParameteri = (PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC)load("glNamedFramebufferParameteri");
	glad_glNamedFramebufferTexture = (PFNGLNAMEDFRAMEBUFFERTEXTUREPROC)load("glNamedFramebufferTexture");
	glad_glNamedFramebufferTextureLayer = (PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC)load("glNamedFramebufferTextureLayer");
	glad_glNamedFramebufferDrawBuffer = (PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC)load("glNamedFramebufferDrawBuffer");
	glad_glNamedFramebufferDrawBuffers = (PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC)load("glNamedFramebufferDrawBuffers");
	glad_glNamedFramebufferReadBuffer = (PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC)load("glNamedFramebufferReadBuffer");
	glad_glInvalidateNamedFramebufferData = (PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC)load("glInvalidateNamedFramebufferData");
	glad_glInvalidateNamedFramebufferSubData = (PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC)load("glInvalidateNamedFramebufferSubData");
	glad_glClearNamedFramebufferiv = (PFNGLCLEARNAMEDFRAMEBUFFERIVPROC)load("glClearNamedFramebufferiv");
	glad_glClearNamedFramebufferuiv = (PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC)load("glClearNamedFramebufferuiv");
	glad_glClearNamedFramebufferfv = (PFNGLCLEARNAMEDFRAMEBUFFERFVPROC)load("glClearNamedFramebufferfv");
	glad_glClearNamedFramebufferfi = (PFNGLCLEARNAMEDFRAMEBUFFERFIPROC)load("glClearNamedFramebufferfi");
	glad_glBlitNamedFramebuffer = (PFNGLBLITNAMEDFRAMEBUFFERPROC)load("glBlitNamedFramebuffer");
	glad_glCheckNamedFramebufferStatus = (PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC)load("glCheckNamedFramebufferStatus");
	glad_glGetNamedFramebufferParameteriv = (PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC)load("glGetNamedFramebufferParameteriv");
	glad_glGetNamedFramebufferAttachmentParameteriv = (PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC)load("glGetNamedFramebufferAttachmentParameteriv");
	glad_glCreateRenderbuffers = (PFNGLCREATERENDERBUFFERSPROC)load("glCreateRenderbuffers");
	glad_glNamedRenderbufferStorage = (PFNGLNAMEDRENDERBUFFERSTORAGEPROC)load("glNamedRenderbufferStorage");
	glad_glNamedRenderbufferStorageMultisample = (PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC)load("glNamedRenderbufferStorageMultisample");
	glad_glGetNamedRenderbufferParameteriv = (PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC)load("glGetNamedRenderbufferParameteriv");
	glad_glCreateTextures = (PFNGLCREATETEXTURESPROC)load("glCreateTextures");
	glad_glTextureBuffer = (PFNGLTEXTUREBUFFERPROC)load("glTextureBuffer");
	glad_glTextureBufferRange = (PFNGLTEXTUREBUFFERRANGEPROC)load("glTextureBufferRange");
	glad_glTextureStorage1D = (PFNGLTEXTURESTORAGE1DPROC)load("glTextureStorage1D");
	glad_glTextureStorage2D = (PFNGLTEXTURESTORAGE2DPROC)load("glTextureStorage2D");
	glad_glTextureStorage3D = (PFNGLTEXTURESTORAGE3DPROC)load("glTextureStorage3D");
	glad_glTextureStorage2DMultisample = (PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC)load("glTextureStorage2DMultisample");
	glad_glTextureStorage3DMultisample = (PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC)load("glTextureStorage3DMultisample");
	glad_glTextureSubImage1D = (PFNGLTEXTURESUBIMAGE1DPROC)load("glTextureSubImage1D");
	glad_glTextureSubImage2D = (PFNGLTEXTURESUBIMAGE2DPROC)load("glTextureSubImage2D");
	glad_glTextureSubImage3D = (PFNGLTEXTURESUBIMAGE3DPROC)load("glTextureSubImage3D");
	glad_glCompressedTextureSubImage1D = (PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC)load("glCompressedTextureSubImage1D");
	glad_glCompressedTextureSubImage2D = (PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC)load("glCompressedTextureSubImage2D");
	glad_glCompressedTextureSubImage3D = (PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC)load("glCompressedTextureSubImage3D");
	glad_glCopyTextureSubImage1D = (PFNGLCOPYTEXTURESUBIMAGE1DPROC)load("glCopyTextureSubImage1D");
	glad_glCopyTextureSubImage2D = (PFNGLCOPYTEXTURESUBIMAGE2DPROC)load("glCopyTextureSubImage2D");
	glad_glCopyTextureSubImage3D = (PFNGLCOPYTEXTURESUBIMAGE3DPROC)load("glCopyTextureSubImage3D");
	glad_glTextureParameterf = (PFNGLTEXTUREPARAMETERFPROC)load("glTextureParameterf");
	glad_glTextureParameterfv = (PFNGLTEXTUREPARAMETERFVPROC)load("glTextureParameterfv");
	glad_glTextureParameteri = (PFNGLTEXTUREPARAMETERIPROC)load("glTextureParameteri");
	glad_glTextureParameterIiv = (PFNGLTEXTUREPARAMETERIIVPROC)load("glTextureParameterIiv");
	glad_glTextureParameterIuiv = (PFNGLTEXTUREPARAMETERIUIVPROC)load("glTextureParameterIuiv");
	glad_glTextureParameteriv = (PFNGLTEXTUREPARAMETERIVPROC)load("glTextureParameteriv");
	glad_glGenerateTextureMipmap = (PFNGLGENERATETEXTUREMIPMAPPROC)load("glGenerateTextureMipmap");
	glad_glBindTextureUnit = (PFNGLBINDTEXTUREUNITPROC)load("glBindTextureUnit");
	glad_glGetTextureImage = (PFNGLGETTEXTUREIMAGEPROC)load("glGetTextureImage");
	glad_glGetCompressedTextureImage = (PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC)load("glGetCompressedTextureImage");
	glad_glGetTextureLevelParameterfv = (PFNGLGETTEXTURELEVELPARAMETERFVPROC)load("glGetTextureLevelParameterfv");
	glad_glGetTextureLevelParameteriv = (PFNGLGETTEXTURELEVELPARAMETERIVPROC)load("glGetTextureLevelParameteriv");
	glad_glGetTextureParameterfv = (PFNGLGETTEXTUREPARAMETERFVPROC)load("glGetTextureParameterfv");
	glad_glGetTextureParameterIiv = (PFNGLGETTEXTUREPARAMETERIIVPROC)load("glGetTextureParameterIiv");
	glad_glGetTextureParameterIuiv = (PFNGLGETTEXTUREPARAMETERIUIVPROC)load("glGetTextureParameterIuiv");
	glad_glGetTextureParameteriv = (PFNGLGETTEXTUREPARAMETERIVPROC)load("glGetTextureParameteriv");
	glad_glCreateVertexArrays = (PFNGLCREATEVERTEXARRAYSPROC)load("glCreateVertexArrays");
	glad_glDisableVertexArrayAttrib = (PFNGLDISABLEVERTEXARRAYATTRIBPROC)load("glDisableVertexArrayAttrib");
	glad_glEnableVertexArrayAttrib = (PFNGLENABLEVERTEXARRAYATTRIBPROC)load("glEnableVertexArrayAttrib");
	glad_glVertexArrayElementBuffer = (PFNGLVERTEXARRAYELEMENTBUFFERPROC)load("glVertexArrayElementBuffer");
	glad_glVertexArrayVertexBuffer = (PFNGLVERTEXARRAYVERTEXBUFFERPROC)load("glVertexArrayVertexBuffer");
	glad_glVertexArrayVertexBuffers = (PFNGLVERTEXARRAYVERTEXBUFFERSPROC)load("glVertexArrayVertexBuffers");
	glad_glVertexArrayAttribBinding = (PFNGLVERTEXARRAYATTRIBBINDINGPROC)load("glVertexArrayAttribBinding");
	glad_glVertexArrayAttribFormat = (PFNGLVERTEXARRAYATTRIBFORMATPROC)load("glVertexArrayAttribFormat");
	glad_glVertexArrayAttribIFormat = (PFNGLVERTEXARRAYATTRIBIFORMATPROC)load("glVertexArrayAttribIFormat");
	glad_glVertexArrayAttribLFormat = (PFNGLVERTEXARRAYATTRIBLFORMATPROC)load("glVertexArrayAttribLFormat");
	glad_glVertexArrayBindingDivisor = (PFNGLVERTEXARRAYBINDINGDIVISORPROC)load("glVertexArrayBindingDivisor");
	glad_glGetVertexArrayiv = (PFNGLGETVERTEXARRAYIVPROC)load("glGetVertexArrayiv");
	glad_glGetVertexArrayIndexediv = (PFNGLGETVERTEXARRAYINDEXEDIVPROC)load("glGetVertexArrayIndexediv");
	glad_glGetVertexArrayIndexed64iv = (PFNGLGETVERTEXARRAYINDEXED64IVPROC)load("glGetVertexArrayIndexed64iv");
	glad_glCreateSamplers = (PFNGLCREATESAMPLERSPROC)load("glCreateSamplers");
	glad_glCreateProgramPipelines = (PFNGLCREATEPROGRAMPIPELINESPROC)load("glCreateProgramPipelines");
	glad_glCreateQueries = (PFNGLCREATEQUERIESPROC)load("glCreateQueries");
	glad_glGetQueryBufferObjecti64v = (PFNGLGETQUERYBUFFEROBJECTI64VPROC)load("glGetQueryBufferObjecti64v");
	glad_glGetQueryBufferObjectiv = (PFNGLGETQUERYBUFFEROBJECTIVPROC)load("glGetQueryBufferObjectiv");
	glad_glGetQueryBufferObjectui64v = (PFNGLGETQUERYBUFFEROBJECTUI64VPROC)load("glGetQueryBufferObjectui64v");
	glad_glGetQueryBufferObjectuiv = (PFNGLGETQUERYBUFFEROBJECTUIVPROC)load("glGetQueryBufferObjectuiv");
	glad_glMemoryBarrierByRegion = (PFNGLMEMORYBARRIERBYREGIONPROC)load("glMemoryBarrierByRegion");
	glad_glGetTextureSubImage = (PFNGLGETTEXTURESUBIMAGEPROC)load("glGetTextureSubImage");
	glad_glGetCompressedTextureSubImage = (PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC)load("glGetCompressedTextureSubImage");
	glad_glGetGraphicsResetStatus = (PFNGLGETGRAPHICSRESETSTATUSPROC)load("glGetGraphicsResetStatus");
	glad_glGetnCompressedTexImage = (PFNGLGETNCOMPRESSEDTEXIMAGEPROC)load("glGetnCompressedTexImage");
	glad_glGetnTexImage = (PFNGLGETNTEXIMAGEPROC)load("glGetnTexImage");
	glad_glGetnUniformdv = (PFNGLGETNUNIFORMDVPROC)load("glGetnUniformdv");
	glad_glGetnUniformfv = (PFNGLGETNUNIFORMFVPROC)load("glGetnUniformfv");
	glad_glGetnUniformiv = (PFNGLGETNUNIFORMIVPROC)load("glGetnUniformiv");
	glad_glGetnUniformuiv = (PFNGLGETNUNIFORMUIVPROC)load("glGetnUniformuiv");
	glad_glReadnPixels = (PFNGLREADNPIXELSPROC)load("glReadnPixels");
	glad_glGetnMapdv = (PFNGLGETNMAPDVPROC)load("glGetnMapdv");
	glad_glGetnMapfv = (PFNGLGETNMAPFVPROC)load("glGetnMapfv");
	glad_glGetnMapiv = (PFNGLGETNMAPIVPROC)load("glGetnMapiv");
	glad_glGetnPixelMapfv = (PFNGLGETNPIXELMAPFVPROC)load("glGetnPixelMapfv");
	glad_glGetnPixelMapuiv = (PFNGLGETNPIXELMAPUIVPROC)load("glGetnPixelMapuiv");
	glad_glGetnPixelMapusv = (PFNGLGETNPIXELMAPUSVPROC)load("glGetnPixelMapusv");
	glad_glGetnPolygonStipple = (PFNGLGETNPOLYGONSTIPPLEPROC)load("glGetnPolygonStipple");
	glad_glGetnColorTable = (PFNGLGETNCOLORTABLEPROC)load("glGetnColorTable");
	glad_glGetnConvolutionFilter = (PFNGLGETNCONVOLUTIONFILTERPROC)load("glGetnConvolutionFilter");
	glad_glGetnSeparableFilter = (PFNGLGETNSEPARABLEFILTERPROC)load("glGetnSeparableFilter");
	glad_glGetnHistogram = (PFNGLGETNHISTOGRAMPROC)load("glGetnHistogram");
	glad_glGetnMinmax = (PFNGLGETNMINMAXPROC)load("glGetnMinmax");
	glad_glTextureBarrier = (PFNGLTEXTUREBARRIERPROC)load("glTextureBarrier");
}
static void load_GL_APPLE_element_array(GLADloadproc load) {
	if (!GLAD_GL_APPLE_element_array) return;
	glad_glElementPointerAPPLE = (PFNGLELEMENTPOINTERAPPLEPROC)load("glElementPointerAPPLE");
	glad_glDrawElementArrayAPPLE = (PFNGLDRAWELEMENTARRAYAPPLEPROC)load("glDrawElementArrayAPPLE");
	glad_glDrawRangeElementArrayAPPLE = (PFNGLDRAWRANGEELEMENTARRAYAPPLEPROC)load("glDrawRangeElementArrayAPPLE");
	glad_glMultiDrawElementArrayAPPLE = (PFNGLMULTIDRAWELEMENTARRAYAPPLEPROC)load("glMultiDrawElementArrayAPPLE");
	glad_glMultiDrawRangeElementArrayAPPLE = (PFNGLMULTIDRAWRANGEELEMENTARRAYAPPLEPROC)load("glMultiDrawRangeElementArrayAPPLE");
}
static void load_GL_AMD_multi_draw_indirect(GLADloadproc load) {
	if (!GLAD_GL_AMD_multi_draw_indirect) return;
	glad_glMultiDrawArraysIndirectAMD = (PFNGLMULTIDRAWARRAYSINDIRECTAMDPROC)load("glMultiDrawArraysIndirectAMD");
	glad_glMultiDrawElementsIndirectAMD = (PFNGLMULTIDRAWELEMENTSINDIRECTAMDPROC)load("glMultiDrawElementsIndirectAMD");
}
static void load_GL_SGIX_tag_sample_buffer(GLADloadproc load) {
	if (!GLAD_GL_SGIX_tag_sample_buffer) return;
	glad_glTagSampleBufferSGIX = (PFNGLTAGSAMPLEBUFFERSGIXPROC)load("glTagSampleBufferSGIX");
}
static void load_GL_NV_point_sprite(GLADloadproc load) {
	if (!GLAD_GL_NV_point_sprite) return;
	glad_glPointParameteriNV = (PFNGLPOINTPARAMETERINVPROC)load("glPointParameteriNV");
	glad_glPointParameterivNV = (PFNGLPOINTPARAMETERIVNVPROC)load("glPointParameterivNV");
}
static void load_GL_ATI_separate_stencil(GLADloadproc load) {
	if (!GLAD_GL_ATI_separate_stencil) return;
	glad_glStencilOpSeparateATI = (PFNGLSTENCILOPSEPARATEATIPROC)load("glStencilOpSeparateATI");
	glad_glStencilFuncSeparateATI = (PFNGLSTENCILFUNCSEPARATEATIPROC)load("glStencilFuncSeparateATI");
}
static void load_GL_EXT_texture_buffer_object(GLADloadproc load) {
	if (!GLAD_GL_EXT_texture_buffer_object) return;
	glad_glTexBufferEXT = (PFNGLTEXBUFFEREXTPROC)load("glTexBufferEXT");
}
static void load_GL_ARB_vertex_blend(GLADloadproc load) {
	if (!GLAD_GL_ARB_vertex_blend) return;
	glad_glWeightbvARB = (PFNGLWEIGHTBVARBPROC)load("glWeightbvARB");
	glad_glWeightsvARB = (PFNGLWEIGHTSVARBPROC)load("glWeightsvARB");
	glad_glWeightivARB = (PFNGLWEIGHTIVARBPROC)load("glWeightivARB");
	glad_glWeightfvARB = (PFNGLWEIGHTFVARBPROC)load("glWeightfvARB");
	glad_glWeightdvARB = (PFNGLWEIGHTDVARBPROC)load("glWeightdvARB");
	glad_glWeightubvARB = (PFNGLWEIGHTUBVARBPROC)load("glWeightubvARB");
	glad_glWeightusvARB = (PFNGLWEIGHTUSVARBPROC)load("glWeightusvARB");
	glad_glWeightuivARB = (PFNGLWEIGHTUIVARBPROC)load("glWeightuivARB");
	glad_glWeightPointerARB = (PFNGLWEIGHTPOINTERARBPROC)load("glWeightPointerARB");
	glad_glVertexBlendARB = (PFNGLVERTEXBLENDARBPROC)load("glVertexBlendARB");
}
static void load_GL_OVR_multiview(GLADloadproc load) {
	if (!GLAD_GL_OVR_multiview) return;
	glad_glFramebufferTextureMultiviewOVR = (PFNGLFRAMEBUFFERTEXTUREMULTIVIEWOVRPROC)load("glFramebufferTextureMultiviewOVR");
}
static void load_GL_ARB_program_interface_query(GLADloadproc load) {
	if (!GLAD_GL_ARB_program_interface_query) return;
	glad_glGetProgramInterfaceiv = (PFNGLGETPROGRAMINTERFACEIVPROC)load("glGetProgramInterfaceiv");
	glad_glGetProgramResourceIndex = (PFNGLGETPROGRAMRESOURCEINDEXPROC)load("glGetProgramResourceIndex");
	glad_glGetProgramResourceName = (PFNGLGETPROGRAMRESOURCENAMEPROC)load("glGetProgramResourceName");
	glad_glGetProgramResourceiv = (PFNGLGETPROGRAMRESOURCEIVPROC)load("glGetProgramResourceiv");
	glad_glGetProgramResourceLocation = (PFNGLGETPROGRAMRESOURCELOCATIONPROC)load("glGetProgramResourceLocation");
	glad_glGetProgramResourceLocationIndex = (PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC)load("glGetProgramResourceLocationIndex");
}
static void load_GL_EXT_index_func(GLADloadproc load) {
	if (!GLAD_GL_EXT_index_func) return;
	glad_glIndexFuncEXT = (PFNGLINDEXFUNCEXTPROC)load("glIndexFuncEXT");
}
static void load_GL_NV_shader_buffer_load(GLADloadproc load) {
	if (!GLAD_GL_NV_shader_buffer_load) return;
	glad_glMakeBufferResidentNV = (PFNGLMAKEBUFFERRESIDENTNVPROC)load("glMakeBufferResidentNV");
	glad_glMakeBufferNonResidentNV = (PFNGLMAKEBUFFERNONRESIDENTNVPROC)load("glMakeBufferNonResidentNV");
	glad_glIsBufferResidentNV = (PFNGLISBUFFERRESIDENTNVPROC)load("glIsBufferResidentNV");
	glad_glMakeNamedBufferResidentNV = (PFNGLMAKENAMEDBUFFERRESIDENTNVPROC)load("glMakeNamedBufferResidentNV");
	glad_glMakeNamedBufferNonResidentNV = (PFNGLMAKENAMEDBUFFERNONRESIDENTNVPROC)load("glMakeNamedBufferNonResidentNV");
	glad_glIsNamedBufferResidentNV = (PFNGLISNAMEDBUFFERRESIDENTNVPROC)load("glIsNamedBufferResidentNV");
	glad_glGetBufferParameterui64vNV = (PFNGLGETBUFFERPARAMETERUI64VNVPROC)load("glGetBufferParameterui64vNV");
	glad_glGetNamedBufferParameterui64vNV = (PFNGLGETNAMEDBUFFERPARAMETERUI64VNVPROC)load("glGetNamedBufferParameterui64vNV");
	glad_glGetIntegerui64vNV = (PFNGLGETINTEGERUI64VNVPROC)load("glGetIntegerui64vNV");
	glad_glUniformui64NV = (PFNGLUNIFORMUI64NVPROC)load("glUniformui64NV");
	glad_glUniformui64vNV = (PFNGLUNIFORMUI64VNVPROC)load("glUniformui64vNV");
	glad_glGetUniformui64vNV = (PFNGLGETUNIFORMUI64VNVPROC)load("glGetUniformui64vNV");
	glad_glProgramUniformui64NV = (PFNGLPROGRAMUNIFORMUI64NVPROC)load("glProgramUniformui64NV");
	glad_glProgramUniformui64vNV = (PFNGLPROGRAMUNIFORMUI64VNVPROC)load("glProgramUniformui64vNV");
}
static void load_GL_EXT_color_subtable(GLADloadproc load) {
	if (!GLAD_GL_EXT_color_subtable) return;
	glad_glColorSubTableEXT = (PFNGLCOLORSUBTABLEEXTPROC)load("glColorSubTableEXT");
	glad_glCopyColorSubTableEXT = (PFNGLCOPYCOLORSUBTABLEEXTPROC)load("glCopyColorSubTableEXT");
}
static void load_GL_SUNX_constant_data(GLADloadproc load) {
	if (!GLAD_GL_SUNX_constant_data) return;
	glad_glFinishTextureSUNX = (PFNGLFINISHTEXTURESUNXPROC)load("glFinishTextureSUNX");
}
static void load_GL_EXT_multi_draw_arrays(GLADloadproc load) {
	if (!GLAD_GL_EXT_multi_draw_arrays) return;
	glad_glMultiDrawArraysEXT = (PFNGLMULTIDRAWARRAYSEXTPROC)load("glMultiDrawArraysEXT");
	glad_glMultiDrawElementsEXT = (PFNGLMULTIDRAWELEMENTSEXTPROC)load("glMultiDrawElementsEXT");
}
static void load_GL_ARB_shader_atomic_counters(GLADloadproc load) {
	if (!GLAD_GL_ARB_shader_atomic_counters) return;
	glad_glGetActiveAtomicCounterBufferiv = (PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC)load("glGetActiveAtomicCounterBufferiv");
}
static void load_GL_NV_conditional_render(GLADloadproc load) {
	if (!GLAD_GL_NV_conditional_render) return;
	glad_glBeginConditionalRenderNV = (PFNGLBEGINCONDITIONALRENDERNVPROC)load("glBeginConditionalRenderNV");
	glad_glEndConditionalRenderNV = (PFNGLENDCONDITIONALRENDERNVPROC)load("glEndConditionalRenderNV");
}
static void load_GL_MESA_resize_buffers(GLADloadproc load) {
	if (!GLAD_GL_MESA_resize_buffers) return;
	glad_glResizeBuffersMESA = (PFNGLRESIZEBUFFERSMESAPROC)load("glResizeBuffersMESA");
}
static void load_GL_ARB_texture_view(GLADloadproc load) {
	if (!GLAD_GL_ARB_texture_view) return;
	glad_glTextureView = (PFNGLTEXTUREVIEWPROC)load("glTextureView");
}
static void load_GL_ARB_map_buffer_range(GLADloadproc load) {
	if (!GLAD_GL_ARB_map_buffer_range) return;
	glad_glMapBufferRange = (PFNGLMAPBUFFERRANGEPROC)load("glMapBufferRange");
	glad_glFlushMappedBufferRange = (PFNGLFLUSHMAPPEDBUFFERRANGEPROC)load("glFlushMappedBufferRange");
}
static void load_GL_EXT_convolution(GLADloadproc load) {
	if (!GLAD_GL_EXT_convolution) return;
	glad_glConvolutionFilter1DEXT = (PFNGLCONVOLUTIONFILTER1DEXTPROC)load("glConvolutionFilter1DEXT");
	glad_glConvolutionFilter2DEXT = (PFNGLCONVOLUTIONFILTER2DEXTPROC)load("glConvolutionFilter2DEXT");
	glad_glConvolutionParameterfEXT = (PFNGLCONVOLUTIONPARAMETERFEXTPROC)load("glConvolutionParameterfEXT");
	glad_glConvolutionParameterfvEXT = (PFNGLCONVOLUTIONPARAMETERFVEXTPROC)load("glConvolutionParameterfvEXT");
	glad_glConvolutionParameteriEXT = (PFNGLCONVOLUTIONPARAMETERIEXTPROC)load("glConvolutionParameteriEXT");
	glad_glConvolutionParameterivEXT = (PFNGLCONVOLUTIONPARAMETERIVEXTPROC)load("glConvolutionParameterivEXT");
	glad_glCopyConvolutionFilter1DEXT = (PFNGLCOPYCONVOLUTIONFILTER1DEXTPROC)load("glCopyConvolutionFilter1DEXT");
	glad_glCopyConvolutionFilter2DEXT = (PFNGLCOPYCONVOLUTIONFILTER2DEXTPROC)load("glCopyConvolutionFilter2DEXT");
	glad_glGetConvolutionFilterEXT = (PFNGLGETCONVOLUTIONFILTEREXTPROC)load("glGetConvolutionFilterEXT");
	glad_glGetConvolutionParameterfvEXT = (PFNGLGETCONVOLUTIONPARAMETERFVEXTPROC)load("glGetConvolutionParameterfvEXT");
	glad_glGetConvolutionParameterivEXT = (PFNGLGETCONVOLUTIONPARAMETERIVEXTPROC)load("glGetConvolutionParameterivEXT");
	glad_glGetSeparableFilterEXT = (PFNGLGETSEPARABLEFILTEREXTPROC)load("glGetSeparableFilterEXT");
	glad_glSeparableFilter2DEXT = (PFNGLSEPARABLEFILTER2DEXTPROC)load("glSeparableFilter2DEXT");
}
static void load_GL_NV_vertex_attrib_integer_64bit(GLADloadproc load) {
	if (!GLAD_GL_NV_vertex_attrib_integer_64bit) return;
	glad_glVertexAttribL1i64NV = (PFNGLVERTEXATTRIBL1I64NVPROC)load("glVertexAttribL1i64NV");
	glad_glVertexAttribL2i64NV = (PFNGLVERTEXATTRIBL2I64NVPROC)load("glVertexAttribL2i64NV");
	glad_glVertexAttribL3i64NV = (PFNGLVERTEXATTRIBL3I64NVPROC)load("glVertexAttribL3i64NV");
	glad_glVertexAttribL4i64NV = (PFNGLVERTEXATTRIBL4I64NVPROC)load("glVertexAttribL4i64NV");
	glad_glVertexAttribL1i64vNV = (PFNGLVERTEXATTRIBL1I64VNVPROC)load("glVertexAttribL1i64vNV");
	glad_glVertexAttribL2i64vNV = (PFNGLVERTEXATTRIBL2I64VNVPROC)load("glVertexAttribL2i64vNV");
	glad_glVertexAttribL3i64vNV = (PFNGLVERTEXATTRIBL3I64VNVPROC)load("glVertexAttribL3i64vNV");
	glad_glVertexAttribL4i64vNV = (PFNGLVERTEXATTRIBL4I64VNVPROC)load("glVertexAttribL4i64vNV");
	glad_glVertexAttribL1ui64NV = (PFNGLVERTEXATTRIBL1UI64NVPROC)load("glVertexAttribL1ui64NV");
	glad_glVertexAttribL2ui64NV = (PFNGLVERTEXATTRIBL2UI64NVPROC)load("glVertexAttribL2ui64NV");
	glad_glVertexAttribL3ui64NV = (PFNGLVERTEXATTRIBL3UI64NVPROC)load("glVertexAttribL3ui64NV");
	glad_glVertexAttribL4ui64NV = (PFNGLVERTEXATTRIBL4UI64NVPROC)load("glVertexAttribL4ui64NV");
	glad_glVertexAttribL1ui64vNV = (PFNGLVERTEXATTRIBL1UI64VNVPROC)load("glVertexAttribL1ui64vNV");
	glad_glVertexAttribL2ui64vNV = (PFNGLVERTEXATTRIBL2UI64VNVPROC)load("glVertexAttribL2ui64vNV");
	glad_glVertexAttribL3ui64vNV = (PFNGLVERTEXATTRIBL3UI64VNVPROC)load("glVertexAttribL3ui64vNV");
	glad_glVertexAttribL4ui64vNV = (PFNGLVERTEXATTRIBL4UI64VNVPROC)load("glVertexAttribL4ui64vNV");
	glad_glGetVertexAttribLi64vNV = (PFNGLGETVERTEXATTRIBLI64VNVPROC)load("glGetVertexAttribLi64vNV");
	glad_glGetVertexAttribLui64vNV = (PFNGLGETVERTEXATTRIBLUI64VNVPROC)load("glGetVertexAttribLui64vNV");
	glad_glVertexAttribLFormatNV = (PFNGLVERTEXATTRIBLFORMATNVPROC)load("glVertexAttribLFormatNV");
}
static void load_GL_EXT_paletted_texture(GLADloadproc load) {
	if (!GLAD_GL_EXT_paletted_texture) return;
	glad_glColorTableEXT = (PFNGLCOLORTABLEEXTPROC)load("glColorTableEXT");
	glad_glGetColorTableEXT = (PFNGLGETCOLORTABLEEXTPROC)load("glGetColorTableEXT");
	glad_glGetColorTableParameterivEXT = (PFNGLGETCOLORTABLEPARAMETERIVEXTPROC)load("glGetColorTableParameterivEXT");
	glad_glGetColorTableParameterfvEXT = (PFNGLGETCOLORTABLEPARAMETERFVEXTPROC)load("glGetColorTableParameterfvEXT");
}
static void load_GL_ARB_texture_buffer_object(GLADloadproc load) {
	if (!GLAD_GL_ARB_texture_buffer_object) return;
	glad_glTexBufferARB = (PFNGLTEXBUFFERARBPROC)load("glTexBufferARB");
}
static void load_GL_ATI_pn_triangles(GLADloadproc load) {
	if (!GLAD_GL_ATI_pn_triangles) return;
	glad_glPNTrianglesiATI = (PFNGLPNTRIANGLESIATIPROC)load("glPNTrianglesiATI");
	glad_glPNTrianglesfATI = (PFNGLPNTRIANGLESFATIPROC)load("glPNTrianglesfATI");
}
static void load_GL_SGIX_flush_raster(GLADloadproc load) {
	if (!GLAD_GL_SGIX_flush_raster) return;
	glad_glFlushRasterSGIX = (PFNGLFLUSHRASTERSGIXPROC)load("glFlushRasterSGIX");
}
static void load_GL_EXT_light_texture(GLADloadproc load) {
	if (!GLAD_GL_EXT_light_texture) return;
	glad_glApplyTextureEXT = (PFNGLAPPLYTEXTUREEXTPROC)load("glApplyTextureEXT");
	glad_glTextureLightEXT = (PFNGLTEXTURELIGHTEXTPROC)load("glTextureLightEXT");
	glad_glTextureMaterialEXT = (PFNGLTEXTUREMATERIALEXTPROC)load("glTextureMaterialEXT");
}
static void load_GL_AMD_draw_buffers_blend(GLADloadproc load) {
	if (!GLAD_GL_AMD_draw_buffers_blend) return;
	glad_glBlendFuncIndexedAMD = (PFNGLBLENDFUNCINDEXEDAMDPROC)load("glBlendFuncIndexedAMD");
	glad_glBlendFuncSeparateIndexedAMD = (PFNGLBLENDFUNCSEPARATEINDEXEDAMDPROC)load("glBlendFuncSeparateIndexedAMD");
	glad_glBlendEquationIndexedAMD = (PFNGLBLENDEQUATIONINDEXEDAMDPROC)load("glBlendEquationIndexedAMD");
	glad_glBlendEquationSeparateIndexedAMD = (PFNGLBLENDEQUATIONSEPARATEINDEXEDAMDPROC)load("glBlendEquationSeparateIndexedAMD");
}
static void load_GL_APPLE_texture_range(GLADloadproc load) {
	if (!GLAD_GL_APPLE_texture_range) return;
	glad_glTextureRangeAPPLE = (PFNGLTEXTURERANGEAPPLEPROC)load("glTextureRangeAPPLE");
	glad_glGetTexParameterPointervAPPLE = (PFNGLGETTEXPARAMETERPOINTERVAPPLEPROC)load("glGetTexParameterPointervAPPLE");
}
static void load_GL_EXT_texture_array(GLADloadproc load) {
	if (!GLAD_GL_EXT_texture_array) return;
	glad_glFramebufferTextureLayerEXT = (PFNGLFRAMEBUFFERTEXTURELAYEREXTPROC)load("glFramebufferTextureLayerEXT");
}
static void load_GL_NV_texture_barrier(GLADloadproc load) {
	if (!GLAD_GL_NV_texture_barrier) return;
	glad_glTextureBarrierNV = (PFNGLTEXTUREBARRIERNVPROC)load("glTextureBarrierNV");
}
static void load_GL_ARB_vertex_type_2_10_10_10_rev(GLADloadproc load) {
	if (!GLAD_GL_ARB_vertex_type_2_10_10_10_rev) return;
	glad_glVertexAttribP1ui = (PFNGLVERTEXATTRIBP1UIPROC)load("glVertexAttribP1ui");
	glad_glVertexAttribP1uiv = (PFNGLVERTEXATTRIBP1UIVPROC)load("glVertexAttribP1uiv");
	glad_glVertexAttribP2ui = (PFNGLVERTEXATTRIBP2UIPROC)load("glVertexAttribP2ui");
	glad_glVertexAttribP2uiv = (PFNGLVERTEXATTRIBP2UIVPROC)load("glVertexAttribP2uiv");
	glad_glVertexAttribP3ui = (PFNGLVERTEXATTRIBP3UIPROC)load("glVertexAttribP3ui");
	glad_glVertexAttribP3uiv = (PFNGLVERTEXATTRIBP3UIVPROC)load("glVertexAttribP3uiv");
	glad_glVertexAttribP4ui = (PFNGLVERTEXATTRIBP4UIPROC)load("glVertexAttribP4ui");
	glad_glVertexAttribP4uiv = (PFNGLVERTEXATTRIBP4UIVPROC)load("glVertexAttribP4uiv");
	glad_glVertexP2ui = (PFNGLVERTEXP2UIPROC)load("glVertexP2ui");
	glad_glVertexP2uiv = (PFNGLVERTEXP2UIVPROC)load("glVertexP2uiv");
	glad_glVertexP3ui = (PFNGLVERTEXP3UIPROC)load("glVertexP3ui");
	glad_glVertexP3uiv = (PFNGLVERTEXP3UIVPROC)load("glVertexP3uiv");
	glad_glVertexP4ui = (PFNGLVERTEXP4UIPROC)load("glVertexP4ui");
	glad_glVertexP4uiv = (PFNGLVERTEXP4UIVPROC)load("glVertexP4uiv");
	glad_glTexCoordP1ui = (PFNGLTEXCOORDP1UIPROC)load("glTexCoordP1ui");
	glad_glTexCoordP1uiv = (PFNGLTEXCOORDP1UIVPROC)load("glTexCoordP1uiv");
	glad_glTexCoordP2ui = (PFNGLTEXCOORDP2UIPROC)load("glTexCoordP2ui");
	glad_glTexCoordP2uiv = (PFNGLTEXCOORDP2UIVPROC)load("glTexCoordP2uiv");
	glad_glTexCoordP3ui = (PFNGLTEXCOORDP3UIPROC)load("glTexCoordP3ui");
	glad_glTexCoordP3uiv = (PFNGLTEXCOORDP3UIVPROC)load("glTexCoordP3uiv");
	glad_glTexCoordP4ui = (PFNGLTEXCOORDP4UIPROC)load("glTexCoordP4ui");
	glad_glTexCoordP4uiv = (PFNGLTEXCOORDP4UIVPROC)load("glTexCoordP4uiv");
	glad_glMultiTexCoordP1ui = (PFNGLMULTITEXCOORDP1UIPROC)load("glMultiTexCoordP1ui");
	glad_glMultiTexCoordP1uiv = (PFNGLMULTITEXCOORDP1UIVPROC)load("glMultiTexCoordP1uiv");
	glad_glMultiTexCoordP2ui = (PFNGLMULTITEXCOORDP2UIPROC)load("glMultiTexCoordP2ui");
	glad_glMultiTexCoordP2uiv = (PFNGLMULTITEXCOORDP2UIVPROC)load("glMultiTexCoordP2uiv");
	glad_glMultiTexCoordP3ui = (PFNGLMULTITEXCOORDP3UIPROC)load("glMultiTexCoordP3ui");
	glad_glMultiTexCoordP3uiv = (PFNGLMULTITEXCOORDP3UIVPROC)load("glMultiTexCoordP3uiv");
	glad_glMultiTexCoordP4ui = (PFNGLMULTITEXCOORDP4UIPROC)load("glMultiTexCoordP4ui");
	glad_glMultiTexCoordP4uiv = (PFNGLMULTITEXCOORDP4UIVPROC)load("glMultiTexCoordP4uiv");
	glad_glNormalP3ui = (PFNGLNORMALP3UIPROC)load("glNormalP3ui");
	glad_glNormalP3uiv = (PFNGLNORMALP3UIVPROC)load("glNormalP3uiv");
	glad_glColorP3ui = (PFNGLCOLORP3UIPROC)load("glColorP3ui");
	glad_glColorP3uiv = (PFNGLCOLORP3UIVPROC)load("glColorP3uiv");
	glad_glColorP4ui = (PFNGLCOLORP4UIPROC)load("glColorP4ui");
	glad_glColorP4uiv = (PFNGLCOLORP4UIVPROC)load("glColorP4uiv");
	glad_glSecondaryColorP3ui = (PFNGLSECONDARYCOLORP3UIPROC)load("glSecondaryColorP3ui");
	glad_glSecondaryColorP3uiv = (PFNGLSECONDARYCOLORP3UIVPROC)load("glSecondaryColorP3uiv");
}
static void load_GL_3DFX_tbuffer(GLADloadproc load) {
	if (!GLAD_GL_3DFX_tbuffer) return;
	glad_glTbufferMask3DFX = (PFNGLTBUFFERMASK3DFXPROC)load("glTbufferMask3DFX");
}
static void load_GL_GREMEDY_frame_terminator(GLADloadproc load) {
	if (!GLAD_GL_GREMEDY_frame_terminator) return;
	glad_glFrameTerminatorGREMEDY = (PFNGLFRAMETERMINATORGREMEDYPROC)load("glFrameTerminatorGREMEDY");
}
static void load_GL_ARB_blend_func_extended(GLADloadproc load) {
	if (!GLAD_GL_ARB_blend_func_extended) return;
	glad_glBindFragDataLocationIndexed = (PFNGLBINDFRAGDATALOCATIONINDEXEDPROC)load("glBindFragDataLocationIndexed");
	glad_glGetFragDataIndex = (PFNGLGETFRAGDATAINDEXPROC)load("glGetFragDataIndex");
}
static void load_GL_EXT_separate_shader_objects(GLADloadproc load) {
	if (!GLAD_GL_EXT_separate_shader_objects) return;
	glad_glUseShaderProgramEXT = (PFNGLUSESHADERPROGRAMEXTPROC)load("glUseShaderProgramEXT");
	glad_glActiveProgramEXT = (PFNGLACTIVEPROGRAMEXTPROC)load("glActiveProgramEXT");
	glad_glCreateShaderProgramEXT = (PFNGLCREATESHADERPROGRAMEXTPROC)load("glCreateShaderProgramEXT");
	glad_glActiveShaderProgramEXT = (PFNGLACTIVESHADERPROGRAMEXTPROC)load("glActiveShaderProgramEXT");
	glad_glBindProgramPipelineEXT = (PFNGLBINDPROGRAMPIPELINEEXTPROC)load("glBindProgramPipelineEXT");
	glad_glCreateShaderProgramvEXT = (PFNGLCREATESHADERPROGRAMVEXTPROC)load("glCreateShaderProgramvEXT");
	glad_glDeleteProgramPipelinesEXT = (PFNGLDELETEPROGRAMPIPELINESEXTPROC)load("glDeleteProgramPipelinesEXT");
	glad_glGenProgramPipelinesEXT = (PFNGLGENPROGRAMPIPELINESEXTPROC)load("glGenProgramPipelinesEXT");
	glad_glGetProgramPipelineInfoLogEXT = (PFNGLGETPROGRAMPIPELINEINFOLOGEXTPROC)load("glGetProgramPipelineInfoLogEXT");
	glad_glGetProgramPipelineivEXT = (PFNGLGETPROGRAMPIPELINEIVEXTPROC)load("glGetProgramPipelineivEXT");
	glad_glIsProgramPipelineEXT = (PFNGLISPROGRAMPIPELINEEXTPROC)load("glIsProgramPipelineEXT");
	glad_glProgramParameteriEXT = (PFNGLPROGRAMPARAMETERIEXTPROC)load("glProgramParameteriEXT");
	glad_glProgramUniform1fEXT = (PFNGLPROGRAMUNIFORM1FEXTPROC)load("glProgramUniform1fEXT");
	glad_glProgramUniform1fvEXT = (PFNGLPROGRAMUNIFORM1FVEXTPROC)load("glProgramUniform1fvEXT");
	glad_glProgramUniform1iEXT = (PFNGLPROGRAMUNIFORM1IEXTPROC)load("glProgramUniform1iEXT");
	glad_glProgramUniform1ivEXT = (PFNGLPROGRAMUNIFORM1IVEXTPROC)load("glProgramUniform1ivEXT");
	glad_glProgramUniform2fEXT = (PFNGLPROGRAMUNIFORM2FEXTPROC)load("glProgramUniform2fEXT");
	glad_glProgramUniform2fvEXT = (PFNGLPROGRAMUNIFORM2FVEXTPROC)load("glProgramUniform2fvEXT");
	glad_glProgramUniform2iEXT = (PFNGLPROGRAMUNIFORM2IEXTPROC)load("glProgramUniform2iEXT");
	glad_glProgramUniform2ivEXT = (PFNGLPROGRAMUNIFORM2IVEXTPROC)load("glProgramUniform2ivEXT");
	glad_glProgramUniform3fEXT = (PFNGLPROGRAMUNIFORM3FEXTPROC)load("glProgramUniform3fEXT");
	glad_glProgramUniform3fvEXT = (PFNGLPROGRAMUNIFORM3FVEXTPROC)load("glProgramUniform3fvEXT");
	glad_glProgramUniform3iEXT = (PFNGLPROGRAMUNIFORM3IEXTPROC)load("glProgramUniform3iEXT");
	glad_glProgramUniform3ivEXT = (PFNGLPROGRAMUNIFORM3IVEXTPROC)load("glProgramUniform3ivEXT");
	glad_glProgramUniform4fEXT = (PFNGLPROGRAMUNIFORM4FEXTPROC)load("glProgramUniform4fEXT");
	glad_glProgramUniform4fvEXT = (PFNGLPROGRAMUNIFORM4FVEXTPROC)load("glProgramUniform4fvEXT");
	glad_glProgramUniform4iEXT = (PFNGLPROGRAMUNIFORM4IEXTPROC)load("glProgramUniform4iEXT");
	glad_glProgramUniform4ivEXT = (PFNGLPROGRAMUNIFORM4IVEXTPROC)load("glProgramUniform4ivEXT");
	glad_glProgramUniformMatrix2fvEXT = (PFNGLPROGRAMUNIFORMMATRIX2FVEXTPROC)load("glProgramUniformMatrix2fvEXT");
	glad_glProgramUniformMatrix3fvEXT = (PFNGLPROGRAMUNIFORMMATRIX3FVEXTPROC)load("glProgramUniformMatrix3fvEXT");
	glad_glProgramUniformMatrix4fvEXT = (PFNGLPROGRAMUNIFORMMATRIX4FVEXTPROC)load("glProgramUniformMatrix4fvEXT");
	glad_glUseProgramStagesEXT = (PFNGLUSEPROGRAMSTAGESEXTPROC)load("glUseProgramStagesEXT");
	glad_glValidateProgramPipelineEXT = (PFNGLVALIDATEPROGRAMPIPELINEEXTPROC)load("glValidateProgramPipelineEXT");
	glad_glProgramUniform1uiEXT = (PFNGLPROGRAMUNIFORM1UIEXTPROC)load("glProgramUniform1uiEXT");
	glad_glProgramUniform2uiEXT = (PFNGLPROGRAMUNIFORM2UIEXTPROC)load("glProgramUniform2uiEXT");
	glad_glProgramUniform3uiEXT = (PFNGLPROGRAMUNIFORM3UIEXTPROC)load("glProgramUniform3uiEXT");
	glad_glProgramUniform4uiEXT = (PFNGLPROGRAMUNIFORM4UIEXTPROC)load("glProgramUniform4uiEXT");
	glad_glProgramUniform1uivEXT = (PFNGLPROGRAMUNIFORM1UIVEXTPROC)load("glProgramUniform1uivEXT");
	glad_glProgramUniform2uivEXT = (PFNGLPROGRAMUNIFORM2UIVEXTPROC)load("glProgramUniform2uivEXT");
	glad_glProgramUniform3uivEXT = (PFNGLPROGRAMUNIFORM3UIVEXTPROC)load("glProgramUniform3uivEXT");
	glad_glProgramUniform4uivEXT = (PFNGLPROGRAMUNIFORM4UIVEXTPROC)load("glProgramUniform4uivEXT");
	glad_glProgramUniformMatrix4fvEXT = (PFNGLPROGRAMUNIFORMMATRIX4FVEXTPROC)load("glProgramUniformMatrix4fvEXT");
	glad_glProgramUniformMatrix2x3fvEXT = (PFNGLPROGRAMUNIFORMMATRIX2X3FVEXTPROC)load("glProgramUniformMatrix2x3fvEXT");
	glad_glProgramUniformMatrix3x2fvEXT = (PFNGLPROGRAMUNIFORMMATRIX3X2FVEXTPROC)load("glProgramUniformMatrix3x2fvEXT");
	glad_glProgramUniformMatrix2x4fvEXT = (PFNGLPROGRAMUNIFORMMATRIX2X4FVEXTPROC)load("glProgramUniformMatrix2x4fvEXT");
	glad_glProgramUniformMatrix4x2fvEXT = (PFNGLPROGRAMUNIFORMMATRIX4X2FVEXTPROC)load("glProgramUniformMatrix4x2fvEXT");
	glad_glProgramUniformMatrix3x4fvEXT = (PFNGLPROGRAMUNIFORMMATRIX3X4FVEXTPROC)load("glProgramUniformMatrix3x4fvEXT");
	glad_glProgramUniformMatrix4x3fvEXT = (PFNGLPROGRAMUNIFORMMATRIX4X3FVEXTPROC)load("glProgramUniformMatrix4x3fvEXT");
}
static void load_GL_NV_texture_multisample(GLADloadproc load) {
	if (!GLAD_GL_NV_texture_multisample) return;
	glad_glTexImage2DMultisampleCoverageNV = (PFNGLTEXIMAGE2DMULTISAMPLECOVERAGENVPROC)load("glTexImage2DMultisampleCoverageNV");
	glad_glTexImage3DMultisampleCoverageNV = (PFNGLTEXIMAGE3DMULTISAMPLECOVERAGENVPROC)load("glTexImage3DMultisampleCoverageNV");
	glad_glTextureImage2DMultisampleNV = (PFNGLTEXTUREIMAGE2DMULTISAMPLENVPROC)load("glTextureImage2DMultisampleNV");
	glad_glTextureImage3DMultisampleNV = (PFNGLTEXTUREIMAGE3DMULTISAMPLENVPROC)load("glTextureImage3DMultisampleNV");
	glad_glTextureImage2DMultisampleCoverageNV = (PFNGLTEXTUREIMAGE2DMULTISAMPLECOVERAGENVPROC)load("glTextureImage2DMultisampleCoverageNV");
	glad_glTextureImage3DMultisampleCoverageNV = (PFNGLTEXTUREIMAGE3DMULTISAMPLECOVERAGENVPROC)load("glTextureImage3DMultisampleCoverageNV");
}
static void load_GL_ARB_shader_objects(GLADloadproc load) {
	if (!GLAD_GL_ARB_shader_objects) return;
	glad_glDeleteObjectARB = (PFNGLDELETEOBJECTARBPROC)load("glDeleteObjectARB");
	glad_glGetHandleARB = (PFNGLGETHANDLEARBPROC)load("glGetHandleARB");
	glad_glDetachObjectARB = (PFNGLDETACHOBJECTARBPROC)load("glDetachObjectARB");
	glad_glCreateShaderObjectARB = (PFNGLCREATESHADEROBJECTARBPROC)load("glCreateShaderObjectARB");
	glad_glShaderSourceARB = (PFNGLSHADERSOURCEARBPROC)load("glShaderSourceARB");
	glad_glCompileShaderARB = (PFNGLCOMPILESHADERARBPROC)load("glCompileShaderARB");
	glad_glCreateProgramObjectARB = (PFNGLCREATEPROGRAMOBJECTARBPROC)load("glCreateProgramObjectARB");
	glad_glAttachObjectARB = (PFNGLATTACHOBJECTARBPROC)load("glAttachObjectARB");
	glad_glLinkProgramARB = (PFNGLLINKPROGRAMARBPROC)load("glLinkProgramARB");
	glad_glUseProgramObjectARB = (PFNGLUSEPROGRAMOBJECTARBPROC)load("glUseProgramObjectARB");
	glad_glValidateProgramARB = (PFNGLVALIDATEPROGRAMARBPROC)load("glValidateProgramARB");
	glad_glUniform1fARB = (PFNGLUNIFORM1FARBPROC)load("glUniform1fARB");
	glad_glUniform2fARB = (PFNGLUNIFORM2FARBPROC)load("glUniform2fARB");
	glad_glUniform3fARB = (PFNGLUNIFORM3FARBPROC)load("glUniform3fARB");
	glad_glUniform4fARB = (PFNGLUNIFORM4FARBPROC)load("glUniform4fARB");
	glad_glUniform1iARB = (PFNGLUNIFORM1IARBPROC)load("glUniform1iARB");
	glad_glUniform2iARB = (PFNGLUNIFORM2IARBPROC)load("glUniform2iARB");
	glad_glUniform3iARB = (PFNGLUNIFORM3IARBPROC)load("glUniform3iARB");
	glad_glUniform4iARB = (PFNGLUNIFORM4IARBPROC)load("glUniform4iARB");
	glad_glUniform1fvARB = (PFNGLUNIFORM1FVARBPROC)load("glUniform1fvARB");
	glad_glUniform2fvARB = (PFNGLUNIFORM2FVARBPROC)load("glUniform2fvARB");
	glad_glUniform3fvARB = (PFNGLUNIFORM3FVARBPROC)load("glUniform3fvARB");
	glad_glUniform4fvARB = (PFNGLUNIFORM4FVARBPROC)load("glUniform4fvARB");
	glad_glUniform1ivARB = (PFNGLUNIFORM1IVARBPROC)load("glUniform1ivARB");
	glad_glUniform2ivARB = (PFNGLUNIFORM2IVARBPROC)load("glUniform2ivARB");
	glad_glUniform3ivARB = (PFNGLUNIFORM3IVARBPROC)load("glUniform3ivARB");
	glad_glUniform4ivARB = (PFNGLUNIFORM4IVARBPROC)load("glUniform4ivARB");
	glad_glUniformMatrix2fvARB = (PFNGLUNIFORMMATRIX2FVARBPROC)load("glUniformMatrix2fvARB");
	glad_glUniformMatrix3fvARB = (PFNGLUNIFORMMATRIX3FVARBPROC)load("glUniformMatrix3fvARB");
	glad_glUniformMatrix4fvARB = (PFNGLUNIFORMMATRIX4FVARBPROC)load("glUniformMatrix4fvARB");
	glad_glGetObjectParameterfvARB = (PFNGLGETOBJECTPARAMETERFVARBPROC)load("glGetObjectParameterfvARB");
	glad_glGetObjectParameterivARB = (PFNGLGETOBJECTPARAMETERIVARBPROC)load("glGetObjectParameterivARB");
	glad_glGetInfoLogARB = (PFNGLGETINFOLOGARBPROC)load("glGetInfoLogARB");
	glad_glGetAttachedObjectsARB = (PFNGLGETATTACHEDOBJECTSARBPROC)load("glGetAttachedObjectsARB");
	glad_glGetUniformLocationARB = (PFNGLGETUNIFORMLOCATIONARBPROC)load("glGetUniformLocationARB");
	glad_glGetActiveUniformARB = (PFNGLGETACTIVEUNIFORMARBPROC)load("glGetActiveUniformARB");
	glad_glGetUniformfvARB = (PFNGLGETUNIFORMFVARBPROC)load("glGetUniformfvARB");
	glad_glGetUniformivARB = (PFNGLGETUNIFORMIVARBPROC)load("glGetUniformivARB");
	glad_glGetShaderSourceARB = (PFNGLGETSHADERSOURCEARBPROC)load("glGetShaderSourceARB");
}
static void load_GL_ARB_framebuffer_object(GLADloadproc load) {
	if (!GLAD_GL_ARB_framebuffer_object) return;
	glad_glIsRenderbuffer = (PFNGLISRENDERBUFFERPROC)load("glIsRenderbuffer");
	glad_glBindRenderbuffer = (PFNGLBINDRENDERBUFFERPROC)load("glBindRenderbuffer");
	glad_glDeleteRenderbuffers = (PFNGLDELETERENDERBUFFERSPROC)load("glDeleteRenderbuffers");
	glad_glGenRenderbuffers = (PFNGLGENRENDERBUFFERSPROC)load("glGenRenderbuffers");
	glad_glRenderbufferStorage = (PFNGLRENDERBUFFERSTORAGEPROC)load("glRenderbufferStorage");
	glad_glGetRenderbufferParameteriv = (PFNGLGETRENDERBUFFERPARAMETERIVPROC)load("glGetRenderbufferParameteriv");
	glad_glIsFramebuffer = (PFNGLISFRAMEBUFFERPROC)load("glIsFramebuffer");
	glad_glBindFramebuffer = (PFNGLBINDFRAMEBUFFERPROC)load("glBindFramebuffer");
	glad_glDeleteFramebuffers = (PFNGLDELETEFRAMEBUFFERSPROC)load("glDeleteFramebuffers");
	glad_glGenFramebuffers = (PFNGLGENFRAMEBUFFERSPROC)load("glGenFramebuffers");
	glad_glCheckFramebufferStatus = (PFNGLCHECKFRAMEBUFFERSTATUSPROC)load("glCheckFramebufferStatus");
	glad_glFramebufferTexture1D = (PFNGLFRAMEBUFFERTEXTURE1DPROC)load("glFramebufferTexture1D");
	glad_glFramebufferTexture2D = (PFNGLFRAMEBUFFERTEXTURE2DPROC)load("glFramebufferTexture2D");
	glad_glFramebufferTexture3D = (PFNGLFRAMEBUFFERTEXTURE3DPROC)load("glFramebufferTexture3D");
	glad_glFramebufferRenderbuffer = (PFNGLFRAMEBUFFERRENDERBUFFERPROC)load("glFramebufferRenderbuffer");
	glad_glGetFramebufferAttachmentParameteriv = (PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC)load("glGetFramebufferAttachmentParameteriv");
	glad_glGenerateMipmap = (PFNGLGENERATEMIPMAPPROC)load("glGenerateMipmap");
	glad_glBlitFramebuffer = (PFNGLBLITFRAMEBUFFERPROC)load("glBlitFramebuffer");
	glad_glRenderbufferStorageMultisample = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC)load("glRenderbufferStorageMultisample");
	glad_glFramebufferTextureLayer = (PFNGLFRAMEBUFFERTEXTURELAYERPROC)load("glFramebufferTextureLayer");
}
static void load_GL_ATI_envmap_bumpmap(GLADloadproc load) {
	if (!GLAD_GL_ATI_envmap_bumpmap) return;
	glad_glTexBumpParameterivATI = (PFNGLTEXBUMPPARAMETERIVATIPROC)load("glTexBumpParameterivATI");
	glad_glTexBumpParameterfvATI = (PFNGLTEXBUMPPARAMETERFVATIPROC)load("glTexBumpParameterfvATI");
	glad_glGetTexBumpParameterivATI = (PFNGLGETTEXBUMPPARAMETERIVATIPROC)load("glGetTexBumpParameterivATI");
	glad_glGetTexBumpParameterfvATI = (PFNGLGETTEXBUMPPARAMETERFVATIPROC)load("glGetTexBumpParameterfvATI");
}
static void load_GL_ATI_map_object_buffer(GLADloadproc load) {
	if (!GLAD_GL_ATI_map_object_buffer) return;
	glad_glMapObjectBufferATI = (PFNGLMAPOBJECTBUFFERATIPROC)load("glMapObjectBufferATI");
	glad_glUnmapObjectBufferATI = (PFNGLUNMAPOBJECTBUFFERATIPROC)load("glUnmapObjectBufferATI");
}
static void load_GL_ARB_robustness(GLADloadproc load) {
	if (!GLAD_GL_ARB_robustness) return;
	glad_glGetGraphicsResetStatusARB = (PFNGLGETGRAPHICSRESETSTATUSARBPROC)load("glGetGraphicsResetStatusARB");
	glad_glGetnTexImageARB = (PFNGLGETNTEXIMAGEARBPROC)load("glGetnTexImageARB");
	glad_glReadnPixelsARB = (PFNGLREADNPIXELSARBPROC)load("glReadnPixelsARB");
	glad_glGetnCompressedTexImageARB = (PFNGLGETNCOMPRESSEDTEXIMAGEARBPROC)load("glGetnCompressedTexImageARB");
	glad_glGetnUniformfvARB = (PFNGLGETNUNIFORMFVARBPROC)load("glGetnUniformfvARB");
	glad_glGetnUniformivARB = (PFNGLGETNUNIFORMIVARBPROC)load("glGetnUniformivARB");
	glad_glGetnUniformuivARB = (PFNGLGETNUNIFORMUIVARBPROC)load("glGetnUniformuivARB");
	glad_glGetnUniformdvARB = (PFNGLGETNUNIFORMDVARBPROC)load("glGetnUniformdvARB");
	glad_glGetnMapdvARB = (PFNGLGETNMAPDVARBPROC)load("glGetnMapdvARB");
	glad_glGetnMapfvARB = (PFNGLGETNMAPFVARBPROC)load("glGetnMapfvARB");
	glad_glGetnMapivARB = (PFNGLGETNMAPIVARBPROC)load("glGetnMapivARB");
	glad_glGetnPixelMapfvARB = (PFNGLGETNPIXELMAPFVARBPROC)load("glGetnPixelMapfvARB");
	glad_glGetnPixelMapuivARB = (PFNGLGETNPIXELMAPUIVARBPROC)load("glGetnPixelMapuivARB");
	glad_glGetnPixelMapusvARB = (PFNGLGETNPIXELMAPUSVARBPROC)load("glGetnPixelMapusvARB");
	glad_glGetnPolygonStippleARB = (PFNGLGETNPOLYGONSTIPPLEARBPROC)load("glGetnPolygonStippleARB");
	glad_glGetnColorTableARB = (PFNGLGETNCOLORTABLEARBPROC)load("glGetnColorTableARB");
	glad_glGetnConvolutionFilterARB = (PFNGLGETNCONVOLUTIONFILTERARBPROC)load("glGetnConvolutionFilterARB");
	glad_glGetnSeparableFilterARB = (PFNGLGETNSEPARABLEFILTERARBPROC)load("glGetnSeparableFilterARB");
	glad_glGetnHistogramARB = (PFNGLGETNHISTOGRAMARBPROC)load("glGetnHistogramARB");
	glad_glGetnMinmaxARB = (PFNGLGETNMINMAXARBPROC)load("glGetnMinmaxARB");
}
static void load_GL_NV_pixel_data_range(GLADloadproc load) {
	if (!GLAD_GL_NV_pixel_data_range) return;
	glad_glPixelDataRangeNV = (PFNGLPIXELDATARANGENVPROC)load("glPixelDataRangeNV");
	glad_glFlushPixelDataRangeNV = (PFNGLFLUSHPIXELDATARANGENVPROC)load("glFlushPixelDataRangeNV");
}
static void load_GL_EXT_framebuffer_blit(GLADloadproc load) {
	if (!GLAD_GL_EXT_framebuffer_blit) return;
	glad_glBlitFramebufferEXT = (PFNGLBLITFRAMEBUFFEREXTPROC)load("glBlitFramebufferEXT");
}
static void load_GL_ARB_gpu_shader_fp64(GLADloadproc load) {
	if (!GLAD_GL_ARB_gpu_shader_fp64) return;
	glad_glUniform1d = (PFNGLUNIFORM1DPROC)load("glUniform1d");
	glad_glUniform2d = (PFNGLUNIFORM2DPROC)load("glUniform2d");
	glad_glUniform3d = (PFNGLUNIFORM3DPROC)load("glUniform3d");
	glad_glUniform4d = (PFNGLUNIFORM4DPROC)load("glUniform4d");
	glad_glUniform1dv = (PFNGLUNIFORM1DVPROC)load("glUniform1dv");
	glad_glUniform2dv = (PFNGLUNIFORM2DVPROC)load("glUniform2dv");
	glad_glUniform3dv = (PFNGLUNIFORM3DVPROC)load("glUniform3dv");
	glad_glUniform4dv = (PFNGLUNIFORM4DVPROC)load("glUniform4dv");
	glad_glUniformMatrix2dv = (PFNGLUNIFORMMATRIX2DVPROC)load("glUniformMatrix2dv");
	glad_glUniformMatrix3dv = (PFNGLUNIFORMMATRIX3DVPROC)load("glUniformMatrix3dv");
	glad_glUniformMatrix4dv = (PFNGLUNIFORMMATRIX4DVPROC)load("glUniformMatrix4dv");
	glad_glUniformMatrix2x3dv = (PFNGLUNIFORMMATRIX2X3DVPROC)load("glUniformMatrix2x3dv");
	glad_glUniformMatrix2x4dv = (PFNGLUNIFORMMATRIX2X4DVPROC)load("glUniformMatrix2x4dv");
	glad_glUniformMatrix3x2dv = (PFNGLUNIFORMMATRIX3X2DVPROC)load("glUniformMatrix3x2dv");
	glad_glUniformMatrix3x4dv = (PFNGLUNIFORMMATRIX3X4DVPROC)load("glUniformMatrix3x4dv");
	glad_glUniformMatrix4x2dv = (PFNGLUNIFORMMATRIX4X2DVPROC)load("glUniformMatrix4x2dv");
	glad_glUniformMatrix4x3dv = (PFNGLUNIFORMMATRIX4X3DVPROC)load("glUniformMatrix4x3dv");
	glad_glGetUniformdv = (PFNGLGETUNIFORMDVPROC)load("glGetUniformdv");
}
static void load_GL_NV_command_list(GLADloadproc load) {
	if (!GLAD_GL_NV_command_list) return;
	glad_glCreateStatesNV = (PFNGLCREATESTATESNVPROC)load("glCreateStatesNV");
	glad_glDeleteStatesNV = (PFNGLDELETESTATESNVPROC)load("glDeleteStatesNV");
	glad_glIsStateNV = (PFNGLISSTATENVPROC)load("glIsStateNV");
	glad_glStateCaptureNV = (PFNGLSTATECAPTURENVPROC)load("glStateCaptureNV");
	glad_glGetCommandHeaderNV = (PFNGLGETCOMMANDHEADERNVPROC)load("glGetCommandHeaderNV");
	glad_glGetStageIndexNV = (PFNGLGETSTAGEINDEXNVPROC)load("glGetStageIndexNV");
	glad_glDrawCommandsNV = (PFNGLDRAWCOMMANDSNVPROC)load("glDrawCommandsNV");
	glad_glDrawCommandsAddressNV = (PFNGLDRAWCOMMANDSADDRESSNVPROC)load("glDrawCommandsAddressNV");
	glad_glDrawCommandsStatesNV = (PFNGLDRAWCOMMANDSSTATESNVPROC)load("glDrawCommandsStatesNV");
	glad_glDrawCommandsStatesAddressNV = (PFNGLDRAWCOMMANDSSTATESADDRESSNVPROC)load("glDrawCommandsStatesAddressNV");
	glad_glCreateCommandListsNV = (PFNGLCREATECOMMANDLISTSNVPROC)load("glCreateCommandListsNV");
	glad_glDeleteCommandListsNV = (PFNGLDELETECOMMANDLISTSNVPROC)load("glDeleteCommandListsNV");
	glad_glIsCommandListNV = (PFNGLISCOMMANDLISTNVPROC)load("glIsCommandListNV");
	glad_glListDrawCommandsStatesClientNV = (PFNGLLISTDRAWCOMMANDSSTATESCLIENTNVPROC)load("glListDrawCommandsStatesClientNV");
	glad_glCommandListSegmentsNV = (PFNGLCOMMANDLISTSEGMENTSNVPROC)load("glCommandListSegmentsNV");
	glad_glCompileCommandListNV = (PFNGLCOMPILECOMMANDLISTNVPROC)load("glCompileCommandListNV");
	glad_glCallCommandListNV = (PFNGLCALLCOMMANDLISTNVPROC)load("glCallCommandListNV");
}
static void load_GL_EXT_vertex_weighting(GLADloadproc load) {
	if (!GLAD_GL_EXT_vertex_weighting) return;
	glad_glVertexWeightfEXT = (PFNGLVERTEXWEIGHTFEXTPROC)load("glVertexWeightfEXT");
	glad_glVertexWeightfvEXT = (PFNGLVERTEXWEIGHTFVEXTPROC)load("glVertexWeightfvEXT");
	glad_glVertexWeightPointerEXT = (PFNGLVERTEXWEIGHTPOINTEREXTPROC)load("glVertexWeightPointerEXT");
}
static void load_GL_GREMEDY_string_marker(GLADloadproc load) {
	if (!GLAD_GL_GREMEDY_string_marker) return;
	glad_glStringMarkerGREMEDY = (PFNGLSTRINGMARKERGREMEDYPROC)load("glStringMarkerGREMEDY");
}
static void load_GL_EXT_subtexture(GLADloadproc load) {
	if (!GLAD_GL_EXT_subtexture) return;
	glad_glTexSubImage1DEXT = (PFNGLTEXSUBIMAGE1DEXTPROC)load("glTexSubImage1DEXT");
	glad_glTexSubImage2DEXT = (PFNGLTEXSUBIMAGE2DEXTPROC)load("glTexSubImage2DEXT");
}
static void load_GL_EXT_gpu_program_parameters(GLADloadproc load) {
	if (!GLAD_GL_EXT_gpu_program_parameters) return;
	glad_glProgramEnvParameters4fvEXT = (PFNGLPROGRAMENVPARAMETERS4FVEXTPROC)load("glProgramEnvParameters4fvEXT");
	glad_glProgramLocalParameters4fvEXT = (PFNGLPROGRAMLOCALPARAMETERS4FVEXTPROC)load("glProgramLocalParameters4fvEXT");
}
static void load_GL_NV_evaluators(GLADloadproc load) {
	if (!GLAD_GL_NV_evaluators) return;
	glad_glMapControlPointsNV = (PFNGLMAPCONTROLPOINTSNVPROC)load("glMapControlPointsNV");
	glad_glMapParameterivNV = (PFNGLMAPPARAMETERIVNVPROC)load("glMapParameterivNV");
	glad_glMapParameterfvNV = (PFNGLMAPPARAMETERFVNVPROC)load("glMapParameterfvNV");
	glad_glGetMapControlPointsNV = (PFNGLGETMAPCONTROLPOINTSNVPROC)load("glGetMapControlPointsNV");
	glad_glGetMapParameterivNV = (PFNGLGETMAPPARAMETERIVNVPROC)load("glGetMapParameterivNV");
	glad_glGetMapParameterfvNV = (PFNGLGETMAPPARAMETERFVNVPROC)load("glGetMapParameterfvNV");
	glad_glGetMapAttribParameterivNV = (PFNGLGETMAPATTRIBPARAMETERIVNVPROC)load("glGetMapAttribParameterivNV");
	glad_glGetMapAttribParameterfvNV = (PFNGLGETMAPATTRIBPARAMETERFVNVPROC)load("glGetMapAttribParameterfvNV");
	glad_glEvalMapsNV = (PFNGLEVALMAPSNVPROC)load("glEvalMapsNV");
}
static void load_GL_SGIS_texture_filter4(GLADloadproc load) {
	if (!GLAD_GL_SGIS_texture_filter4) return;
	glad_glGetTexFilterFuncSGIS = (PFNGLGETTEXFILTERFUNCSGISPROC)load("glGetTexFilterFuncSGIS");
	glad_glTexFilterFuncSGIS = (PFNGLTEXFILTERFUNCSGISPROC)load("glTexFilterFuncSGIS");
}
static void load_GL_AMD_performance_monitor(GLADloadproc load) {
	if (!GLAD_GL_AMD_performance_monitor) return;
	glad_glGetPerfMonitorGroupsAMD = (PFNGLGETPERFMONITORGROUPSAMDPROC)load("glGetPerfMonitorGroupsAMD");
	glad_glGetPerfMonitorCountersAMD = (PFNGLGETPERFMONITORCOUNTERSAMDPROC)load("glGetPerfMonitorCountersAMD");
	glad_glGetPerfMonitorGroupStringAMD = (PFNGLGETPERFMONITORGROUPSTRINGAMDPROC)load("glGetPerfMonitorGroupStringAMD");
	glad_glGetPerfMonitorCounterStringAMD = (PFNGLGETPERFMONITORCOUNTERSTRINGAMDPROC)load("glGetPerfMonitorCounterStringAMD");
	glad_glGetPerfMonitorCounterInfoAMD = (PFNGLGETPERFMONITORCOUNTERINFOAMDPROC)load("glGetPerfMonitorCounterInfoAMD");
	glad_glGenPerfMonitorsAMD = (PFNGLGENPERFMONITORSAMDPROC)load("glGenPerfMonitorsAMD");
	glad_glDeletePerfMonitorsAMD = (PFNGLDELETEPERFMONITORSAMDPROC)load("glDeletePerfMonitorsAMD");
	glad_glSelectPerfMonitorCountersAMD = (PFNGLSELECTPERFMONITORCOUNTERSAMDPROC)load("glSelectPerfMonitorCountersAMD");
	glad_glBeginPerfMonitorAMD = (PFNGLBEGINPERFMONITORAMDPROC)load("glBeginPerfMonitorAMD");
	glad_glEndPerfMonitorAMD = (PFNGLENDPERFMONITORAMDPROC)load("glEndPerfMonitorAMD");
	glad_glGetPerfMonitorCounterDataAMD = (PFNGLGETPERFMONITORCOUNTERDATAAMDPROC)load("glGetPerfMonitorCounterDataAMD");
}
static void load_GL_EXT_stencil_clear_tag(GLADloadproc load) {
	if (!GLAD_GL_EXT_stencil_clear_tag) return;
	glad_glStencilClearTagEXT = (PFNGLSTENCILCLEARTAGEXTPROC)load("glStencilClearTagEXT");
}
static void load_GL_NV_present_video(GLADloadproc load) {
	if (!GLAD_GL_NV_present_video) return;
	glad_glPresentFrameKeyedNV = (PFNGLPRESENTFRAMEKEYEDNVPROC)load("glPresentFrameKeyedNV");
	glad_glPresentFrameDualFillNV = (PFNGLPRESENTFRAMEDUALFILLNVPROC)load("glPresentFrameDualFillNV");
	glad_glGetVideoivNV = (PFNGLGETVIDEOIVNVPROC)load("glGetVideoivNV");
	glad_glGetVideouivNV = (PFNGLGETVIDEOUIVNVPROC)load("glGetVideouivNV");
	glad_glGetVideoi64vNV = (PFNGLGETVIDEOI64VNVPROC)load("glGetVideoi64vNV");
	glad_glGetVideoui64vNV = (PFNGLGETVIDEOUI64VNVPROC)load("glGetVideoui64vNV");
}
static void load_GL_SGIX_framezoom(GLADloadproc load) {
	if (!GLAD_GL_SGIX_framezoom) return;
	glad_glFrameZoomSGIX = (PFNGLFRAMEZOOMSGIXPROC)load("glFrameZoomSGIX");
}
static void load_GL_ARB_draw_elements_base_vertex(GLADloadproc load) {
	if (!GLAD_GL_ARB_draw_elements_base_vertex) return;
	glad_glDrawElementsBaseVertex = (PFNGLDRAWELEMENTSBASEVERTEXPROC)load("glDrawElementsBaseVertex");
	glad_glDrawRangeElementsBaseVertex = (PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC)load("glDrawRangeElementsBaseVertex");
	glad_glDrawElementsInstancedBaseVertex = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC)load("glDrawElementsInstancedBaseVertex");
	glad_glMultiDrawElementsBaseVertex = (PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC)load("glMultiDrawElementsBaseVertex");
}
static void load_GL_NV_transform_feedback(GLADloadproc load) {
	if (!GLAD_GL_NV_transform_feedback) return;
	glad_glBeginTransformFeedbackNV = (PFNGLBEGINTRANSFORMFEEDBACKNVPROC)load("glBeginTransformFeedbackNV");
	glad_glEndTransformFeedbackNV = (PFNGLENDTRANSFORMFEEDBACKNVPROC)load("glEndTransformFeedbackNV");
	glad_glTransformFeedbackAttribsNV = (PFNGLTRANSFORMFEEDBACKATTRIBSNVPROC)load("glTransformFeedbackAttribsNV");
	glad_glBindBufferRangeNV = (PFNGLBINDBUFFERRANGENVPROC)load("glBindBufferRangeNV");
	glad_glBindBufferOffsetNV = (PFNGLBINDBUFFEROFFSETNVPROC)load("glBindBufferOffsetNV");
	glad_glBindBufferBaseNV = (PFNGLBINDBUFFERBASENVPROC)load("glBindBufferBaseNV");
	glad_glTransformFeedbackVaryingsNV = (PFNGLTRANSFORMFEEDBACKVARYINGSNVPROC)load("glTransformFeedbackVaryingsNV");
	glad_glActiveVaryingNV = (PFNGLACTIVEVARYINGNVPROC)load("glActiveVaryingNV");
	glad_glGetVaryingLocationNV = (PFNGLGETVARYINGLOCATIONNVPROC)load("glGetVaryingLocationNV");
	glad_glGetActiveVaryingNV = (PFNGLGETACTIVEVARYINGNVPROC)load("glGetActiveVaryingNV");
	glad_glGetTransformFeedbackVaryingNV = (PFNGLGETTRANSFORMFEEDBACKVARYINGNVPROC)load("glGetTransformFeedbackVaryingNV");
	glad_glTransformFeedbackStreamAttribsNV = (PFNGLTRANSFORMFEEDBACKSTREAMATTRIBSNVPROC)load("glTransformFeedbackStreamAttribsNV");
}
static void load_GL_NV_fragment_program(GLADloadproc load) {
	if (!GLAD_GL_NV_fragment_program) return;
	glad_glProgramNamedParameter4fNV = (PFNGLPROGRAMNAMEDPARAMETER4FNVPROC)load("glProgramNamedParameter4fNV");
	glad_glProgramNamedParameter4fvNV = (PFNGLPROGRAMNAMEDPARAMETER4FVNVPROC)load("glProgramNamedParameter4fvNV");
	glad_glProgramNamedParameter4dNV = (PFNGLPROGRAMNAMEDPARAMETER4DNVPROC)load("glProgramNamedParameter4dNV");
	glad_glProgramNamedParameter4dvNV = (PFNGLPROGRAMNAMEDPARAMETER4DVNVPROC)load("glProgramNamedParameter4dvNV");
	glad_glGetProgramNamedParameterfvNV = (PFNGLGETPROGRAMNAMEDPARAMETERFVNVPROC)load("glGetProgramNamedParameterfvNV");
	glad_glGetProgramNamedParameterdvNV = (PFNGLGETPROGRAMNAMEDPARAMETERDVNVPROC)load("glGetProgramNamedParameterdvNV");
}
static void load_GL_AMD_stencil_operation_extended(GLADloadproc load) {
	if (!GLAD_GL_AMD_stencil_operation_extended) return;
	glad_glStencilOpValueAMD = (PFNGLSTENCILOPVALUEAMDPROC)load("glStencilOpValueAMD");
}
static void load_GL_ARB_instanced_arrays(GLADloadproc load) {
	if (!GLAD_GL_ARB_instanced_arrays) return;
	glad_glVertexAttribDivisorARB = (PFNGLVERTEXATTRIBDIVISORARBPROC)load("glVertexAttribDivisorARB");
}
static void load_GL_ARB_get_texture_sub_image(GLADloadproc load) {
	if (!GLAD_GL_ARB_get_texture_sub_image) return;
	glad_glGetTextureSubImage = (PFNGLGETTEXTURESUBIMAGEPROC)load("glGetTextureSubImage");
	glad_glGetCompressedTextureSubImage = (PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC)load("glGetCompressedTextureSubImage");
}
static void load_GL_KHR_robustness(GLADloadproc load) {
	if (!GLAD_GL_KHR_robustness) return;
	glad_glGetGraphicsResetStatus = (PFNGLGETGRAPHICSRESETSTATUSPROC)load("glGetGraphicsResetStatus");
	glad_glReadnPixels = (PFNGLREADNPIXELSPROC)load("glReadnPixels");
	glad_glGetnUniformfv = (PFNGLGETNUNIFORMFVPROC)load("glGetnUniformfv");
	glad_glGetnUniformiv = (PFNGLGETNUNIFORMIVPROC)load("glGetnUniformiv");
	glad_glGetnUniformuiv = (PFNGLGETNUNIFORMUIVPROC)load("glGetnUniformuiv");
	glad_glGetGraphicsResetStatusKHR = (PFNGLGETGRAPHICSRESETSTATUSKHRPROC)load("glGetGraphicsResetStatusKHR");
	glad_glReadnPixelsKHR = (PFNGLREADNPIXELSKHRPROC)load("glReadnPixelsKHR");
	glad_glGetnUniformfvKHR = (PFNGLGETNUNIFORMFVKHRPROC)load("glGetnUniformfvKHR");
	glad_glGetnUniformivKHR = (PFNGLGETNUNIFORMIVKHRPROC)load("glGetnUniformivKHR");
	glad_glGetnUniformuivKHR = (PFNGLGETNUNIFORMUIVKHRPROC)load("glGetnUniformuivKHR");
}
static void load_GL_AMD_sparse_texture(GLADloadproc load) {
	if (!GLAD_GL_AMD_sparse_texture) return;
	glad_glTexStorageSparseAMD = (PFNGLTEXSTORAGESPARSEAMDPROC)load("glTexStorageSparseAMD");
	glad_glTextureStorageSparseAMD = (PFNGLTEXTURESTORAGESPARSEAMDPROC)load("glTextureStorageSparseAMD");
}
static void load_GL_ARB_clip_control(GLADloadproc load) {
	if (!GLAD_GL_ARB_clip_control) return;
	glad_glClipControl = (PFNGLCLIPCONTROLPROC)load("glClipControl");
}
static void load_GL_NV_fragment_coverage_to_color(GLADloadproc load) {
	if (!GLAD_GL_NV_fragment_coverage_to_color) return;
	glad_glFragmentCoverageColorNV = (PFNGLFRAGMENTCOVERAGECOLORNVPROC)load("glFragmentCoverageColorNV");
}
static void load_GL_NV_fence(GLADloadproc load) {
	if (!GLAD_GL_NV_fence) return;
	glad_glDeleteFencesNV = (PFNGLDELETEFENCESNVPROC)load("glDeleteFencesNV");
	glad_glGenFencesNV = (PFNGLGENFENCESNVPROC)load("glGenFencesNV");
	glad_glIsFenceNV = (PFNGLISFENCENVPROC)load("glIsFenceNV");
	glad_glTestFenceNV = (PFNGLTESTFENCENVPROC)load("glTestFenceNV");
	glad_glGetFenceivNV = (PFNGLGETFENCEIVNVPROC)load("glGetFenceivNV");
	glad_glFinishFenceNV = (PFNGLFINISHFENCENVPROC)load("glFinishFenceNV");
	glad_glSetFenceNV = (PFNGLSETFENCENVPROC)load("glSetFenceNV");
}
static void load_GL_ARB_texture_buffer_range(GLADloadproc load) {
	if (!GLAD_GL_ARB_texture_buffer_range) return;
	glad_glTexBufferRange = (PFNGLTEXBUFFERRANGEPROC)load("glTexBufferRange");
}
static void load_GL_SUN_mesh_array(GLADloadproc load) {
	if (!GLAD_GL_SUN_mesh_array) return;
	glad_glDrawMeshArraysSUN = (PFNGLDRAWMESHARRAYSSUNPROC)load("glDrawMeshArraysSUN");
}
static void load_GL_ARB_vertex_attrib_binding(GLADloadproc load) {
	if (!GLAD_GL_ARB_vertex_attrib_binding) return;
	glad_glBindVertexBuffer = (PFNGLBINDVERTEXBUFFERPROC)load("glBindVertexBuffer");
	glad_glVertexAttribFormat = (PFNGLVERTEXATTRIBFORMATPROC)load("glVertexAttribFormat");
	glad_glVertexAttribIFormat = (PFNGLVERTEXATTRIBIFORMATPROC)load("glVertexAttribIFormat");
	glad_glVertexAttribLFormat = (PFNGLVERTEXATTRIBLFORMATPROC)load("glVertexAttribLFormat");
	glad_glVertexAttribBinding = (PFNGLVERTEXATTRIBBINDINGPROC)load("glVertexAttribBinding");
	glad_glVertexBindingDivisor = (PFNGLVERTEXBINDINGDIVISORPROC)load("glVertexBindingDivisor");
}
static void load_GL_ARB_framebuffer_no_attachments(GLADloadproc load) {
	if (!GLAD_GL_ARB_framebuffer_no_attachments) return;
	glad_glFramebufferParameteri = (PFNGLFRAMEBUFFERPARAMETERIPROC)load("glFramebufferParameteri");
	glad_glGetFramebufferParameteriv = (PFNGLGETFRAMEBUFFERPARAMETERIVPROC)load("glGetFramebufferParameteriv");
}
static void load_GL_ARB_cl_event(GLADloadproc load) {
	if (!GLAD_GL_ARB_cl_event) return;
	glad_glCreateSyncFromCLeventARB = (PFNGLCREATESYNCFROMCLEVENTARBPROC)load("glCreateSyncFromCLeventARB");
}
static void load_GL_OES_single_precision(GLADloadproc load) {
	if (!GLAD_GL_OES_single_precision) return;
	glad_glClearDepthfOES = (PFNGLCLEARDEPTHFOESPROC)load("glClearDepthfOES");
	glad_glClipPlanefOES = (PFNGLCLIPPLANEFOESPROC)load("glClipPlanefOES");
	glad_glDepthRangefOES = (PFNGLDEPTHRANGEFOESPROC)load("glDepthRangefOES");
	glad_glFrustumfOES = (PFNGLFRUSTUMFOESPROC)load("glFrustumfOES");
	glad_glGetClipPlanefOES = (PFNGLGETCLIPPLANEFOESPROC)load("glGetClipPlanefOES");
	glad_glOrthofOES = (PFNGLORTHOFOESPROC)load("glOrthofOES");
}
static void load_GL_NV_primitive_restart(GLADloadproc load) {
	if (!GLAD_GL_NV_primitive_restart) return;
	glad_glPrimitiveRestartNV = (PFNGLPRIMITIVERESTARTNVPROC)load("glPrimitiveRestartNV");
	glad_glPrimitiveRestartIndexNV = (PFNGLPRIMITIVERESTARTINDEXNVPROC)load("glPrimitiveRestartIndexNV");
}
static void load_GL_SUN_global_alpha(GLADloadproc load) {
	if (!GLAD_GL_SUN_global_alpha) return;
	glad_glGlobalAlphaFactorbSUN = (PFNGLGLOBALALPHAFACTORBSUNPROC)load("glGlobalAlphaFactorbSUN");
	glad_glGlobalAlphaFactorsSUN = (PFNGLGLOBALALPHAFACTORSSUNPROC)load("glGlobalAlphaFactorsSUN");
	glad_glGlobalAlphaFactoriSUN = (PFNGLGLOBALALPHAFACTORISUNPROC)load("glGlobalAlphaFactoriSUN");
	glad_glGlobalAlphaFactorfSUN = (PFNGLGLOBALALPHAFACTORFSUNPROC)load("glGlobalAlphaFactorfSUN");
	glad_glGlobalAlphaFactordSUN = (PFNGLGLOBALALPHAFACTORDSUNPROC)load("glGlobalAlphaFactordSUN");
	glad_glGlobalAlphaFactorubSUN = (PFNGLGLOBALALPHAFACTORUBSUNPROC)load("glGlobalAlphaFactorubSUN");
	glad_glGlobalAlphaFactorusSUN = (PFNGLGLOBALALPHAFACTORUSSUNPROC)load("glGlobalAlphaFactorusSUN");
	glad_glGlobalAlphaFactoruiSUN = (PFNGLGLOBALALPHAFACTORUISUNPROC)load("glGlobalAlphaFactoruiSUN");
}
static void load_GL_EXT_texture_object(GLADloadproc load) {
	if (!GLAD_GL_EXT_texture_object) return;
	glad_glAreTexturesResidentEXT = (PFNGLARETEXTURESRESIDENTEXTPROC)load("glAreTexturesResidentEXT");
	glad_glBindTextureEXT = (PFNGLBINDTEXTUREEXTPROC)load("glBindTextureEXT");
	glad_glDeleteTexturesEXT = (PFNGLDELETETEXTURESEXTPROC)load("glDeleteTexturesEXT");
	glad_glGenTexturesEXT = (PFNGLGENTEXTURESEXTPROC)load("glGenTexturesEXT");
	glad_glIsTextureEXT = (PFNGLISTEXTUREEXTPROC)load("glIsTextureEXT");
	glad_glPrioritizeTexturesEXT = (PFNGLPRIORITIZETEXTURESEXTPROC)load("glPrioritizeTexturesEXT");
}
static void load_GL_AMD_name_gen_delete(GLADloadproc load) {
	if (!GLAD_GL_AMD_name_gen_delete) return;
	glad_glGenNamesAMD = (PFNGLGENNAMESAMDPROC)load("glGenNamesAMD");
	glad_glDeleteNamesAMD = (PFNGLDELETENAMESAMDPROC)load("glDeleteNamesAMD");
	glad_glIsNameAMD = (PFNGLISNAMEAMDPROC)load("glIsNameAMD");
}
static void load_GL_ARB_buffer_storage(GLADloadproc load) {
	if (!GLAD_GL_ARB_buffer_storage) return;
	glad_glBufferStorage = (PFNGLBUFFERSTORAGEPROC)load("glBufferStorage");
}
static void load_GL_APPLE_vertex_program_evaluators(GLADloadproc load) {
	if (!GLAD_GL_APPLE_vertex_program_evaluators) return;
	glad_glEnableVertexAttribAPPLE = (PFNGLENABLEVERTEXATTRIBAPPLEPROC)load("glEnableVertexAttribAPPLE");
	glad_glDisableVertexAttribAPPLE = (PFNGLDISABLEVERTEXATTRIBAPPLEPROC)load("glDisableVertexAttribAPPLE");
	glad_glIsVertexAttribEnabledAPPLE = (PFNGLISVERTEXATTRIBENABLEDAPPLEPROC)load("glIsVertexAttribEnabledAPPLE");
	glad_glMapVertexAttrib1dAPPLE = (PFNGLMAPVERTEXATTRIB1DAPPLEPROC)load("glMapVertexAttrib1dAPPLE");
	glad_glMapVertexAttrib1fAPPLE = (PFNGLMAPVERTEXATTRIB1FAPPLEPROC)load("glMapVertexAttrib1fAPPLE");
	glad_glMapVertexAttrib2dAPPLE = (PFNGLMAPVERTEXATTRIB2DAPPLEPROC)load("glMapVertexAttrib2dAPPLE");
	glad_glMapVertexAttrib2fAPPLE = (PFNGLMAPVERTEXATTRIB2FAPPLEPROC)load("glMapVertexAttrib2fAPPLE");
}
static void load_GL_ARB_multi_bind(GLADloadproc load) {
	if (!GLAD_GL_ARB_multi_bind) return;
	glad_glBindBuffersBase = (PFNGLBINDBUFFERSBASEPROC)load("glBindBuffersBase");
	glad_glBindBuffersRange = (PFNGLBINDBUFFERSRANGEPROC)load("glBindBuffersRange");
	glad_glBindTextures = (PFNGLBINDTEXTURESPROC)load("glBindTextures");
	glad_glBindSamplers = (PFNGLBINDSAMPLERSPROC)load("glBindSamplers");
	glad_glBindImageTextures = (PFNGLBINDIMAGETEXTURESPROC)load("glBindImageTextures");
	glad_glBindVertexBuffers = (PFNGLBINDVERTEXBUFFERSPROC)load("glBindVertexBuffers");
}
static void load_GL_SGIX_list_priority(GLADloadproc load) {
	if (!GLAD_GL_SGIX_list_priority) return;
	glad_glGetListParameterfvSGIX = (PFNGLGETLISTPARAMETERFVSGIXPROC)load("glGetListParameterfvSGIX");
	glad_glGetListParameterivSGIX = (PFNGLGETLISTPARAMETERIVSGIXPROC)load("glGetListParameterivSGIX");
	glad_glListParameterfSGIX = (PFNGLLISTPARAMETERFSGIXPROC)load("glListParameterfSGIX");
	glad_glListParameterfvSGIX = (PFNGLLISTPARAMETERFVSGIXPROC)load("glListParameterfvSGIX");
	glad_glListParameteriSGIX = (PFNGLLISTPARAMETERISGIXPROC)load("glListParameteriSGIX");
	glad_glListParameterivSGIX = (PFNGLLISTPARAMETERIVSGIXPROC)load("glListParameterivSGIX");
}
static void load_GL_NV_vertex_buffer_unified_memory(GLADloadproc load) {
	if (!GLAD_GL_NV_vertex_buffer_unified_memory) return;
	glad_glBufferAddressRangeNV = (PFNGLBUFFERADDRESSRANGENVPROC)load("glBufferAddressRangeNV");
	glad_glVertexFormatNV = (PFNGLVERTEXFORMATNVPROC)load("glVertexFormatNV");
	glad_glNormalFormatNV = (PFNGLNORMALFORMATNVPROC)load("glNormalFormatNV");
	glad_glColorFormatNV = (PFNGLCOLORFORMATNVPROC)load("glColorFormatNV");
	glad_glIndexFormatNV = (PFNGLINDEXFORMATNVPROC)load("glIndexFormatNV");
	glad_glTexCoordFormatNV = (PFNGLTEXCOORDFORMATNVPROC)load("glTexCoordFormatNV");
	glad_glEdgeFlagFormatNV = (PFNGLEDGEFLAGFORMATNVPROC)load("glEdgeFlagFormatNV");
	glad_glSecondaryColorFormatNV = (PFNGLSECONDARYCOLORFORMATNVPROC)load("glSecondaryColorFormatNV");
	glad_glFogCoordFormatNV = (PFNGLFOGCOORDFORMATNVPROC)load("glFogCoordFormatNV");
	glad_glVertexAttribFormatNV = (PFNGLVERTEXATTRIBFORMATNVPROC)load("glVertexAttribFormatNV");
	glad_glVertexAttribIFormatNV = (PFNGLVERTEXATTRIBIFORMATNVPROC)load("glVertexAttribIFormatNV");
	glad_glGetIntegerui64i_vNV = (PFNGLGETINTEGERUI64I_VNVPROC)load("glGetIntegerui64i_vNV");
}
static void load_GL_ARB_clear_texture(GLADloadproc load) {
	if (!GLAD_GL_ARB_clear_texture) return;
	glad_glClearTexImage = (PFNGLCLEARTEXIMAGEPROC)load("glClearTexImage");
	glad_glClearTexSubImage = (PFNGLCLEARTEXSUBIMAGEPROC)load("glClearTexSubImage");
}
static void load_GL_NV_blend_equation_advanced(GLADloadproc load) {
	if (!GLAD_GL_NV_blend_equation_advanced) return;
	glad_glBlendParameteriNV = (PFNGLBLENDPARAMETERINVPROC)load("glBlendParameteriNV");
	glad_glBlendBarrierNV = (PFNGLBLENDBARRIERNVPROC)load("glBlendBarrierNV");
}
static void load_GL_SGIS_sharpen_texture(GLADloadproc load) {
	if (!GLAD_GL_SGIS_sharpen_texture) return;
	glad_glSharpenTexFuncSGIS = (PFNGLSHARPENTEXFUNCSGISPROC)load("glSharpenTexFuncSGIS");
	glad_glGetSharpenTexFuncSGIS = (PFNGLGETSHARPENTEXFUNCSGISPROC)load("glGetSharpenTexFuncSGIS");
}
static void load_GL_ARB_vertex_program(GLADloadproc load) {
	if (!GLAD_GL_ARB_vertex_program) return;
	glad_glVertexAttrib1dARB = (PFNGLVERTEXATTRIB1DARBPROC)load("glVertexAttrib1dARB");
	glad_glVertexAttrib1dvARB = (PFNGLVERTEXATTRIB1DVARBPROC)load("glVertexAttrib1dvARB");
	glad_glVertexAttrib1fARB = (PFNGLVERTEXATTRIB1FARBPROC)load("glVertexAttrib1fARB");
	glad_glVertexAttrib1fvARB = (PFNGLVERTEXATTRIB1FVARBPROC)load("glVertexAttrib1fvARB");
	glad_glVertexAttrib1sARB = (PFNGLVERTEXATTRIB1SARBPROC)load("glVertexAttrib1sARB");
	glad_glVertexAttrib1svARB = (PFNGLVERTEXATTRIB1SVARBPROC)load("glVertexAttrib1svARB");
	glad_glVertexAttrib2dARB = (PFNGLVERTEXATTRIB2DARBPROC)load("glVertexAttrib2dARB");
	glad_glVertexAttrib2dvARB = (PFNGLVERTEXATTRIB2DVARBPROC)load("glVertexAttrib2dvARB");
	glad_glVertexAttrib2fARB = (PFNGLVERTEXATTRIB2FARBPROC)load("glVertexAttrib2fARB");
	glad_glVertexAttrib2fvARB = (PFNGLVERTEXATTRIB2FVARBPROC)load("glVertexAttrib2fvARB");
	glad_glVertexAttrib2sARB = (PFNGLVERTEXATTRIB2SARBPROC)load("glVertexAttrib2sARB");
	glad_glVertexAttrib2svARB = (PFNGLVERTEXATTRIB2SVARBPROC)load("glVertexAttrib2svARB");
	glad_glVertexAttrib3dARB = (PFNGLVERTEXATTRIB3DARBPROC)load("glVertexAttrib3dARB");
	glad_glVertexAttrib3dvARB = (PFNGLVERTEXATTRIB3DVARBPROC)load("glVertexAttrib3dvARB");
	glad_glVertexAttrib3fARB = (PFNGLVERTEXATTRIB3FARBPROC)load("glVertexAttrib3fARB");
	glad_glVertexAttrib3fvARB = (PFNGLVERTEXATTRIB3FVARBPROC)load("glVertexAttrib3fvARB");
	glad_glVertexAttrib3sARB = (PFNGLVERTEXATTRIB3SARBPROC)load("glVertexAttrib3sARB");
	glad_glVertexAttrib3svARB = (PFNGLVERTEXATTRIB3SVARBPROC)load("glVertexAttrib3svARB");
	glad_glVertexAttrib4NbvARB = (PFNGLVERTEXATTRIB4NBVARBPROC)load("glVertexAttrib4NbvARB");
	glad_glVertexAttrib4NivARB = (PFNGLVERTEXATTRIB4NIVARBPROC)load("glVertexAttrib4NivARB");
	glad_glVertexAttrib4NsvARB = (PFNGLVERTEXATTRIB4NSVARBPROC)load("glVertexAttrib4NsvARB");
	glad_glVertexAttrib4NubARB = (PFNGLVERTEXATTRIB4NUBARBPROC)load("glVertexAttrib4NubARB");
	glad_glVertexAttrib4NubvARB = (PFNGLVERTEXATTRIB4NUBVARBPROC)load("glVertexAttrib4NubvARB");
	glad_glVertexAttrib4NuivARB = (PFNGLVERTEXATTRIB4NUIVARBPROC)load("glVertexAttrib4NuivARB");
	glad_glVertexAttrib4NusvARB = (PFNGLVERTEXATTRIB4NUSVARBPROC)load("glVertexAttrib4NusvARB");
	glad_glVertexAttrib4bvARB = (PFNGLVERTEXATTRIB4BVARBPROC)load("glVertexAttrib4bvARB");
	glad_glVertexAttrib4dARB = (PFNGLVERTEXATTRIB4DARBPROC)load("glVertexAttrib4dARB");
	glad_glVertexAttrib4dvARB = (PFNGLVERTEXATTRIB4DVARBPROC)load("glVertexAttrib4dvARB");
	glad_glVertexAttrib4fARB = (PFNGLVERTEXATTRIB4FARBPROC)load("glVertexAttrib4fARB");
	glad_glVertexAttrib4fvARB = (PFNGLVERTEXATTRIB4FVARBPROC)load("glVertexAttrib4fvARB");
	glad_glVertexAttrib4ivARB = (PFNGLVERTEXATTRIB4IVARBPROC)load("glVertexAttrib4ivARB");
	glad_glVertexAttrib4sARB = (PFNGLVERTEXATTRIB4SARBPROC)load("glVertexAttrib4sARB");
	glad_glVertexAttrib4svARB = (PFNGLVERTEXATTRIB4SVARBPROC)load("glVertexAttrib4svARB");
	glad_glVertexAttrib4ubvARB = (PFNGLVERTEXATTRIB4UBVARBPROC)load("glVertexAttrib4ubvARB");
	glad_glVertexAttrib4uivARB = (PFNGLVERTEXATTRIB4UIVARBPROC)load("glVertexAttrib4uivARB");
	glad_glVertexAttrib4usvARB = (PFNGLVERTEXATTRIB4USVARBPROC)load("glVertexAttrib4usvARB");
	glad_glVertexAttribPointerARB = (PFNGLVERTEXATTRIBPOINTERARBPROC)load("glVertexAttribPointerARB");
	glad_glEnableVertexAttribArrayARB = (PFNGLENABLEVERTEXATTRIBARRAYARBPROC)load("glEnableVertexAttribArrayARB");
	glad_glDisableVertexAttribArrayARB = (PFNGLDISABLEVERTEXATTRIBARRAYARBPROC)load("glDisableVertexAttribArrayARB");
	glad_glProgramStringARB = (PFNGLPROGRAMSTRINGARBPROC)load("glProgramStringARB");
	glad_glBindProgramARB = (PFNGLBINDPROGRAMARBPROC)load("glBindProgramARB");
	glad_glDeleteProgramsARB = (PFNGLDELETEPROGRAMSARBPROC)load("glDeleteProgramsARB");
	glad_glGenProgramsARB = (PFNGLGENPROGRAMSARBPROC)load("glGenProgramsARB");
	glad_glProgramEnvParameter4dARB = (PFNGLPROGRAMENVPARAMETER4DARBPROC)load("glProgramEnvParameter4dARB");
	glad_glProgramEnvParameter4dvARB = (PFNGLPROGRAMENVPARAMETER4DVARBPROC)load("glProgramEnvParameter4dvARB");
	glad_glProgramEnvParameter4fARB = (PFNGLPROGRAMENVPARAMETER4FARBPROC)load("glProgramEnvParameter4fARB");
	glad_glProgramEnvParameter4fvARB = (PFNGLPROGRAMENVPARAMETER4FVARBPROC)load("glProgramEnvParameter4fvARB");
	glad_glProgramLocalParameter4dARB = (PFNGLPROGRAMLOCALPARAMETER4DARBPROC)load("glProgramLocalParameter4dARB");
	glad_glProgramLocalParameter4dvARB = (PFNGLPROGRAMLOCALPARAMETER4DVARBPROC)load("glProgramLocalParameter4dvARB");
	glad_glProgramLocalParameter4fARB = (PFNGLPROGRAMLOCALPARAMETER4FARBPROC)load("glProgramLocalParameter4fARB");
	glad_glProgramLocalParameter4fvARB = (PFNGLPROGRAMLOCALPARAMETER4FVARBPROC)load("glProgramLocalParameter4fvARB");
	glad_glGetProgramEnvParameterdvARB = (PFNGLGETPROGRAMENVPARAMETERDVARBPROC)load("glGetProgramEnvParameterdvARB");
	glad_glGetProgramEnvParameterfvARB = (PFNGLGETPROGRAMENVPARAMETERFVARBPROC)load("glGetProgramEnvParameterfvARB");
	glad_glGetProgramLocalParameterdvARB = (PFNGLGETPROGRAMLOCALPARAMETERDVARBPROC)load("glGetProgramLocalParameterdvARB");
	glad_glGetProgramLocalParameterfvARB = (PFNGLGETPROGRAMLOCALPARAMETERFVARBPROC)load("glGetProgramLocalParameterfvARB");
	glad_glGetProgramivARB = (PFNGLGETPROGRAMIVARBPROC)load("glGetProgramivARB");
	glad_glGetProgramStringARB = (PFNGLGETPROGRAMSTRINGARBPROC)load("glGetProgramStringARB");
	glad_glGetVertexAttribdvARB = (PFNGLGETVERTEXATTRIBDVARBPROC)load("glGetVertexAttribdvARB");
	glad_glGetVertexAttribfvARB = (PFNGLGETVERTEXATTRIBFVARBPROC)load("glGetVertexAttribfvARB");
	glad_glGetVertexAttribivARB = (PFNGLGETVERTEXATTRIBIVARBPROC)load("glGetVertexAttribivARB");
	glad_glGetVertexAttribPointervARB = (PFNGLGETVERTEXATTRIBPOINTERVARBPROC)load("glGetVertexAttribPointervARB");
	glad_glIsProgramARB = (PFNGLISPROGRAMARBPROC)load("glIsProgramARB");
}
static void load_GL_ARB_vertex_buffer_object(GLADloadproc load) {
	if (!GLAD_GL_ARB_vertex_buffer_object) return;
	glad_glBindBufferARB = (PFNGLBINDBUFFERARBPROC)load("glBindBufferARB");
	glad_glDeleteBuffersARB = (PFNGLDELETEBUFFERSARBPROC)load("glDeleteBuffersARB");
	glad_glGenBuffersARB = (PFNGLGENBUFFERSARBPROC)load("glGenBuffersARB");
	glad_glIsBufferARB = (PFNGLISBUFFERARBPROC)load("glIsBufferARB");
	glad_glBufferDataARB = (PFNGLBUFFERDATAARBPROC)load("glBufferDataARB");
	glad_glBufferSubDataARB = (PFNGLBUFFERSUBDATAARBPROC)load("glBufferSubDataARB");
	glad_glGetBufferSubDataARB = (PFNGLGETBUFFERSUBDATAARBPROC)load("glGetBufferSubDataARB");
	glad_glMapBufferARB = (PFNGLMAPBUFFERARBPROC)load("glMapBufferARB");
	glad_glUnmapBufferARB = (PFNGLUNMAPBUFFERARBPROC)load("glUnmapBufferARB");
	glad_glGetBufferParameterivARB = (PFNGLGETBUFFERPARAMETERIVARBPROC)load("glGetBufferParameterivARB");
	glad_glGetBufferPointervARB = (PFNGLGETBUFFERPOINTERVARBPROC)load("glGetBufferPointervARB");
}
static void load_GL_NV_vertex_array_range(GLADloadproc load) {
	if (!GLAD_GL_NV_vertex_array_range) return;
	glad_glFlushVertexArrayRangeNV = (PFNGLFLUSHVERTEXARRAYRANGENVPROC)load("glFlushVertexArrayRangeNV");
	glad_glVertexArrayRangeNV = (PFNGLVERTEXARRAYRANGENVPROC)load("glVertexArrayRangeNV");
}
static void load_GL_SGIX_fragment_lighting(GLADloadproc load) {
	if (!GLAD_GL_SGIX_fragment_lighting) return;
	glad_glFragmentColorMaterialSGIX = (PFNGLFRAGMENTCOLORMATERIALSGIXPROC)load("glFragmentColorMaterialSGIX");
	glad_glFragmentLightfSGIX = (PFNGLFRAGMENTLIGHTFSGIXPROC)load("glFragmentLightfSGIX");
	glad_glFragmentLightfvSGIX = (PFNGLFRAGMENTLIGHTFVSGIXPROC)load("glFragmentLightfvSGIX");
	glad_glFragmentLightiSGIX = (PFNGLFRAGMENTLIGHTISGIXPROC)load("glFragmentLightiSGIX");
	glad_glFragmentLightivSGIX = (PFNGLFRAGMENTLIGHTIVSGIXPROC)load("glFragmentLightivSGIX");
	glad_glFragmentLightModelfSGIX = (PFNGLFRAGMENTLIGHTMODELFSGIXPROC)load("glFragmentLightModelfSGIX");
	glad_glFragmentLightModelfvSGIX = (PFNGLFRAGMENTLIGHTMODELFVSGIXPROC)load("glFragmentLightModelfvSGIX");
	glad_glFragmentLightModeliSGIX = (PFNGLFRAGMENTLIGHTMODELISGIXPROC)load("glFragmentLightModeliSGIX");
	glad_glFragmentLightModelivSGIX = (PFNGLFRAGMENTLIGHTMODELIVSGIXPROC)load("glFragmentLightModelivSGIX");
	glad_glFragmentMaterialfSGIX = (PFNGLFRAGMENTMATERIALFSGIXPROC)load("glFragmentMaterialfSGIX");
	glad_glFragmentMaterialfvSGIX = (PFNGLFRAGMENTMATERIALFVSGIXPROC)load("glFragmentMaterialfvSGIX");
	glad_glFragmentMaterialiSGIX = (PFNGLFRAGMENTMATERIALISGIXPROC)load("glFragmentMaterialiSGIX");
	glad_glFragmentMaterialivSGIX = (PFNGLFRAGMENTMATERIALIVSGIXPROC)load("glFragmentMaterialivSGIX");
	glad_glGetFragmentLightfvSGIX = (PFNGLGETFRAGMENTLIGHTFVSGIXPROC)load("glGetFragmentLightfvSGIX");
	glad_glGetFragmentLightivSGIX = (PFNGLGETFRAGMENTLIGHTIVSGIXPROC)load("glGetFragmentLightivSGIX");
	glad_glGetFragmentMaterialfvSGIX = (PFNGLGETFRAGMENTMATERIALFVSGIXPROC)load("glGetFragmentMaterialfvSGIX");
	glad_glGetFragmentMaterialivSGIX = (PFNGLGETFRAGMENTMATERIALIVSGIXPROC)load("glGetFragmentMaterialivSGIX");
	glad_glLightEnviSGIX = (PFNGLLIGHTENVISGIXPROC)load("glLightEnviSGIX");
}
static void load_GL_NV_framebuffer_multisample_coverage(GLADloadproc load) {
	if (!GLAD_GL_NV_framebuffer_multisample_coverage) return;
	glad_glRenderbufferStorageMultisampleCoverageNV = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLECOVERAGENVPROC)load("glRenderbufferStorageMultisampleCoverageNV");
}
static void load_GL_EXT_timer_query(GLADloadproc load) {
	if (!GLAD_GL_EXT_timer_query) return;
	glad_glGetQueryObjecti64vEXT = (PFNGLGETQUERYOBJECTI64VEXTPROC)load("glGetQueryObjecti64vEXT");
	glad_glGetQueryObjectui64vEXT = (PFNGLGETQUERYOBJECTUI64VEXTPROC)load("glGetQueryObjectui64vEXT");
}
static void load_GL_NV_bindless_texture(GLADloadproc load) {
	if (!GLAD_GL_NV_bindless_texture) return;
	glad_glGetTextureHandleNV = (PFNGLGETTEXTUREHANDLENVPROC)load("glGetTextureHandleNV");
	glad_glGetTextureSamplerHandleNV = (PFNGLGETTEXTURESAMPLERHANDLENVPROC)load("glGetTextureSamplerHandleNV");
	glad_glMakeTextureHandleResidentNV = (PFNGLMAKETEXTUREHANDLERESIDENTNVPROC)load("glMakeTextureHandleResidentNV");
	glad_glMakeTextureHandleNonResidentNV = (PFNGLMAKETEXTUREHANDLENONRESIDENTNVPROC)load("glMakeTextureHandleNonResidentNV");
	glad_glGetImageHandleNV = (PFNGLGETIMAGEHANDLENVPROC)load("glGetImageHandleNV");
	glad_glMakeImageHandleResidentNV = (PFNGLMAKEIMAGEHANDLERESIDENTNVPROC)load("glMakeImageHandleResidentNV");
	glad_glMakeImageHandleNonResidentNV = (PFNGLMAKEIMAGEHANDLENONRESIDENTNVPROC)load("glMakeImageHandleNonResidentNV");
	glad_glUniformHandleui64NV = (PFNGLUNIFORMHANDLEUI64NVPROC)load("glUniformHandleui64NV");
	glad_glUniformHandleui64vNV = (PFNGLUNIFORMHANDLEUI64VNVPROC)load("glUniformHandleui64vNV");
	glad_glProgramUniformHandleui64NV = (PFNGLPROGRAMUNIFORMHANDLEUI64NVPROC)load("glProgramUniformHandleui64NV");
	glad_glProgramUniformHandleui64vNV = (PFNGLPROGRAMUNIFORMHANDLEUI64VNVPROC)load("glProgramUniformHandleui64vNV");
	glad_glIsTextureHandleResidentNV = (PFNGLISTEXTUREHANDLERESIDENTNVPROC)load("glIsTextureHandleResidentNV");
	glad_glIsImageHandleResidentNV = (PFNGLISIMAGEHANDLERESIDENTNVPROC)load("glIsImageHandleResidentNV");
}
static void load_GL_KHR_debug(GLADloadproc load) {
	if (!GLAD_GL_KHR_debug) return;
	glad_glDebugMessageControl = (PFNGLDEBUGMESSAGECONTROLPROC)load("glDebugMessageControl");
	glad_glDebugMessageInsert = (PFNGLDEBUGMESSAGEINSERTPROC)load("glDebugMessageInsert");
	glad_glDebugMessageCallback = (PFNGLDEBUGMESSAGECALLBACKPROC)load("glDebugMessageCallback");
	glad_glGetDebugMessageLog = (PFNGLGETDEBUGMESSAGELOGPROC)load("glGetDebugMessageLog");
	glad_glPushDebugGroup = (PFNGLPUSHDEBUGGROUPPROC)load("glPushDebugGroup");
	glad_glPopDebugGroup = (PFNGLPOPDEBUGGROUPPROC)load("glPopDebugGroup");
	glad_glObjectLabel = (PFNGLOBJECTLABELPROC)load("glObjectLabel");
	glad_glGetObjectLabel = (PFNGLGETOBJECTLABELPROC)load("glGetObjectLabel");
	glad_glObjectPtrLabel = (PFNGLOBJECTPTRLABELPROC)load("glObjectPtrLabel");
	glad_glGetObjectPtrLabel = (PFNGLGETOBJECTPTRLABELPROC)load("glGetObjectPtrLabel");
	glad_glGetPointerv = (PFNGLGETPOINTERVPROC)load("glGetPointerv");
	glad_glDebugMessageControlKHR = (PFNGLDEBUGMESSAGECONTROLKHRPROC)load("glDebugMessageControlKHR");
	glad_glDebugMessageInsertKHR = (PFNGLDEBUGMESSAGEINSERTKHRPROC)load("glDebugMessageInsertKHR");
	glad_glDebugMessageCallbackKHR = (PFNGLDEBUGMESSAGECALLBACKKHRPROC)load("glDebugMessageCallbackKHR");
	glad_glGetDebugMessageLogKHR = (PFNGLGETDEBUGMESSAGELOGKHRPROC)load("glGetDebugMessageLogKHR");
	glad_glPushDebugGroupKHR = (PFNGLPUSHDEBUGGROUPKHRPROC)load("glPushDebugGroupKHR");
	glad_glPopDebugGroupKHR = (PFNGLPOPDEBUGGROUPKHRPROC)load("glPopDebugGroupKHR");
	glad_glObjectLabelKHR = (PFNGLOBJECTLABELKHRPROC)load("glObjectLabelKHR");
	glad_glGetObjectLabelKHR = (PFNGLGETOBJECTLABELKHRPROC)load("glGetObjectLabelKHR");
	glad_glObjectPtrLabelKHR = (PFNGLOBJECTPTRLABELKHRPROC)load("glObjectPtrLabelKHR");
	glad_glGetObjectPtrLabelKHR = (PFNGLGETOBJECTPTRLABELKHRPROC)load("glGetObjectPtrLabelKHR");
	glad_glGetPointervKHR = (PFNGLGETPOINTERVKHRPROC)load("glGetPointervKHR");
}
static void load_GL_ATI_vertex_attrib_array_object(GLADloadproc load) {
	if (!GLAD_GL_ATI_vertex_attrib_array_object) return;
	glad_glVertexAttribArrayObjectATI = (PFNGLVERTEXATTRIBARRAYOBJECTATIPROC)load("glVertexAttribArrayObjectATI");
	glad_glGetVertexAttribArrayObjectfvATI = (PFNGLGETVERTEXATTRIBARRAYOBJECTFVATIPROC)load("glGetVertexAttribArrayObjectfvATI");
	glad_glGetVertexAttribArrayObjectivATI = (PFNGLGETVERTEXATTRIBARRAYOBJECTIVATIPROC)load("glGetVertexAttribArrayObjectivATI");
}
static void load_GL_EXT_geometry_shader4(GLADloadproc load) {
	if (!GLAD_GL_EXT_geometry_shader4) return;
	glad_glProgramParameteriEXT = (PFNGLPROGRAMPARAMETERIEXTPROC)load("glProgramParameteriEXT");
}
static void load_GL_EXT_bindable_uniform(GLADloadproc load) {
	if (!GLAD_GL_EXT_bindable_uniform) return;
	glad_glUniformBufferEXT = (PFNGLUNIFORMBUFFEREXTPROC)load("glUniformBufferEXT");
	glad_glGetUniformBufferSizeEXT = (PFNGLGETUNIFORMBUFFERSIZEEXTPROC)load("glGetUniformBufferSizeEXT");
	glad_glGetUniformOffsetEXT = (PFNGLGETUNIFORMOFFSETEXTPROC)load("glGetUniformOffsetEXT");
}
static void load_GL_KHR_blend_equation_advanced(GLADloadproc load) {
	if (!GLAD_GL_KHR_blend_equation_advanced) return;
	glad_glBlendBarrierKHR = (PFNGLBLENDBARRIERKHRPROC)load("glBlendBarrierKHR");
}
static void load_GL_ATI_element_array(GLADloadproc load) {
	if (!GLAD_GL_ATI_element_array) return;
	glad_glElementPointerATI = (PFNGLELEMENTPOINTERATIPROC)load("glElementPointerATI");
	glad_glDrawElementArrayATI = (PFNGLDRAWELEMENTARRAYATIPROC)load("glDrawElementArrayATI");
	glad_glDrawRangeElementArrayATI = (PFNGLDRAWRANGEELEMENTARRAYATIPROC)load("glDrawRangeElementArrayATI");
}
static void load_GL_SGIX_reference_plane(GLADloadproc load) {
	if (!GLAD_GL_SGIX_reference_plane) return;
	glad_glReferencePlaneSGIX = (PFNGLREFERENCEPLANESGIXPROC)load("glReferencePlaneSGIX");
}
static void load_GL_EXT_stencil_two_side(GLADloadproc load) {
	if (!GLAD_GL_EXT_stencil_two_side) return;
	glad_glActiveStencilFaceEXT = (PFNGLACTIVESTENCILFACEEXTPROC)load("glActiveStencilFaceEXT");
}
static void load_GL_NV_explicit_multisample(GLADloadproc load) {
	if (!GLAD_GL_NV_explicit_multisample) return;
	glad_glGetMultisamplefvNV = (PFNGLGETMULTISAMPLEFVNVPROC)load("glGetMultisamplefvNV");
	glad_glSampleMaskIndexedNV = (PFNGLSAMPLEMASKINDEXEDNVPROC)load("glSampleMaskIndexedNV");
	glad_glTexRenderbufferNV = (PFNGLTEXRENDERBUFFERNVPROC)load("glTexRenderbufferNV");
}
static void load_GL_IBM_static_data(GLADloadproc load) {
	if (!GLAD_GL_IBM_static_data) return;
	glad_glFlushStaticDataIBM = (PFNGLFLUSHSTATICDATAIBMPROC)load("glFlushStaticDataIBM");
}
static void load_GL_EXT_texture_perturb_normal(GLADloadproc load) {
	if (!GLAD_GL_EXT_texture_perturb_normal) return;
	glad_glTextureNormalEXT = (PFNGLTEXTURENORMALEXTPROC)load("glTextureNormalEXT");
}
static void load_GL_EXT_point_parameters(GLADloadproc load) {
	if (!GLAD_GL_EXT_point_parameters) return;
	glad_glPointParameterfEXT = (PFNGLPOINTPARAMETERFEXTPROC)load("glPointParameterfEXT");
	glad_glPointParameterfvEXT = (PFNGLPOINTPARAMETERFVEXTPROC)load("glPointParameterfvEXT");
}
static void load_GL_PGI_misc_hints(GLADloadproc load) {
	if (!GLAD_GL_PGI_misc_hints) return;
	glad_glHintPGI = (PFNGLHINTPGIPROC)load("glHintPGI");
}
static void load_GL_ARB_vertex_shader(GLADloadproc load) {
	if (!GLAD_GL_ARB_vertex_shader) return;
	glad_glVertexAttrib1fARB = (PFNGLVERTEXATTRIB1FARBPROC)load("glVertexAttrib1fARB");
	glad_glVertexAttrib1sARB = (PFNGLVERTEXATTRIB1SARBPROC)load("glVertexAttrib1sARB");
	glad_glVertexAttrib1dARB = (PFNGLVERTEXATTRIB1DARBPROC)load("glVertexAttrib1dARB");
	glad_glVertexAttrib2fARB = (PFNGLVERTEXATTRIB2FARBPROC)load("glVertexAttrib2fARB");
	glad_glVertexAttrib2sARB = (PFNGLVERTEXATTRIB2SARBPROC)load("glVertexAttrib2sARB");
	glad_glVertexAttrib2dARB = (PFNGLVERTEXATTRIB2DARBPROC)load("glVertexAttrib2dARB");
	glad_glVertexAttrib3fARB = (PFNGLVERTEXATTRIB3FARBPROC)load("glVertexAttrib3fARB");
	glad_glVertexAttrib3sARB = (PFNGLVERTEXATTRIB3SARBPROC)load("glVertexAttrib3sARB");
	glad_glVertexAttrib3dARB = (PFNGLVERTEXATTRIB3DARBPROC)load("glVertexAttrib3dARB");
	glad_glVertexAttrib4fARB = (PFNGLVERTEXATTRIB4FARBPROC)load("glVertexAttrib4fARB");
	glad_glVertexAttrib4sARB = (PFNGLVERTEXATTRIB4SARBPROC)load("glVertexAttrib4sARB");
	glad_glVertexAttrib4dARB = (PFNGLVERTEXATTRIB4DARBPROC)load("glVertexAttrib4dARB");
	glad_glVertexAttrib4NubARB = (PFNGLVERTEXATTRIB4NUBARBPROC)load("glVertexAttrib4NubARB");
	glad_glVertexAttrib1fvARB = (PFNGLVERTEXATTRIB1FVARBPROC)load("glVertexAttrib1fvARB");
	glad_glVertexAttrib1svARB = (PFNGLVERTEXATTRIB1SVARBPROC)load("glVertexAttrib1svARB");
	glad_glVertexAttrib1dvARB = (PFNGLVERTEXATTRIB1DVARBPROC)load("glVertexAttrib1dvARB");
	glad_glVertexAttrib2fvARB = (PFNGLVERTEXATTRIB2FVARBPROC)load("glVertexAttrib2fvARB");
	glad_glVertexAttrib2svARB = (PFNGLVERTEXATTRIB2SVARBPROC)load("glVertexAttrib2svARB");
	glad_glVertexAttrib2dvARB = (PFNGLVERTEXATTRIB2DVARBPROC)load("glVertexAttrib2dvARB");
	glad_glVertexAttrib3fvARB = (PFNGLVERTEXATTRIB3FVARBPROC)load("glVertexAttrib3fvARB");
	glad_glVertexAttrib3svARB = (PFNGLVERTEXATTRIB3SVARBPROC)load("glVertexAttrib3svARB");
	glad_glVertexAttrib3dvARB = (PFNGLVERTEXATTRIB3DVARBPROC)load("glVertexAttrib3dvARB");
	glad_glVertexAttrib4fvARB = (PFNGLVERTEXATTRIB4FVARBPROC)load("glVertexAttrib4fvARB");
	glad_glVertexAttrib4svARB = (PFNGLVERTEXATTRIB4SVARBPROC)load("glVertexAttrib4svARB");
	glad_glVertexAttrib4dvARB = (PFNGLVERTEXATTRIB4DVARBPROC)load("glVertexAttrib4dvARB");
	glad_glVertexAttrib4ivARB = (PFNGLVERTEXATTRIB4IVARBPROC)load("glVertexAttrib4ivARB");
	glad_glVertexAttrib4bvARB = (PFNGLVERTEXATTRIB4BVARBPROC)load("glVertexAttrib4bvARB");
	glad_glVertexAttrib4ubvARB = (PFNGLVERTEXATTRIB4UBVARBPROC)load("glVertexAttrib4ubvARB");
	glad_glVertexAttrib4usvARB = (PFNGLVERTEXATTRIB4USVARBPROC)load("glVertexAttrib4usvARB");
	glad_glVertexAttrib4uivARB = (PFNGLVERTEXATTRIB4UIVARBPROC)load("glVertexAttrib4uivARB");
	glad_glVertexAttrib4NbvARB = (PFNGLVERTEXATTRIB4NBVARBPROC)load("glVertexAttrib4NbvARB");
	glad_glVertexAttrib4NsvARB = (PFNGLVERTEXATTRIB4NSVARBPROC)load("glVertexAttrib4NsvARB");
	glad_glVertexAttrib4NivARB = (PFNGLVERTEXATTRIB4NIVARBPROC)load("glVertexAttrib4NivARB");
	glad_glVertexAttrib4NubvARB = (PFNGLVERTEXATTRIB4NUBVARBPROC)load("glVertexAttrib4NubvARB");
	glad_glVertexAttrib4NusvARB = (PFNGLVERTEXATTRIB4NUSVARBPROC)load("glVertexAttrib4NusvARB");
	glad_glVertexAttrib4NuivARB = (PFNGLVERTEXATTRIB4NUIVARBPROC)load("glVertexAttrib4NuivARB");
	glad_glVertexAttribPointerARB = (PFNGLVERTEXATTRIBPOINTERARBPROC)load("glVertexAttribPointerARB");
	glad_glEnableVertexAttribArrayARB = (PFNGLENABLEVERTEXATTRIBARRAYARBPROC)load("glEnableVertexAttribArrayARB");
	glad_glDisableVertexAttribArrayARB = (PFNGLDISABLEVERTEXATTRIBARRAYARBPROC)load("glDisableVertexAttribArrayARB");
	glad_glBindAttribLocationARB = (PFNGLBINDATTRIBLOCATIONARBPROC)load("glBindAttribLocationARB");
	glad_glGetActiveAttribARB = (PFNGLGETACTIVEATTRIBARBPROC)load("glGetActiveAttribARB");
	glad_glGetAttribLocationARB = (PFNGLGETATTRIBLOCATIONARBPROC)load("glGetAttribLocationARB");
	glad_glGetVertexAttribdvARB = (PFNGLGETVERTEXATTRIBDVARBPROC)load("glGetVertexAttribdvARB");
	glad_glGetVertexAttribfvARB = (PFNGLGETVERTEXATTRIBFVARBPROC)load("glGetVertexAttribfvARB");
	glad_glGetVertexAttribivARB = (PFNGLGETVERTEXATTRIBIVARBPROC)load("glGetVertexAttribivARB");
	glad_glGetVertexAttribPointervARB = (PFNGLGETVERTEXATTRIBPOINTERVARBPROC)load("glGetVertexAttribPointervARB");
}
static void load_GL_ARB_tessellation_shader(GLADloadproc load) {
	if (!GLAD_GL_ARB_tessellation_shader) return;
	glad_glPatchParameteri = (PFNGLPATCHPARAMETERIPROC)load("glPatchParameteri");
	glad_glPatchParameterfv = (PFNGLPATCHPARAMETERFVPROC)load("glPatchParameterfv");
}
static void load_GL_EXT_draw_buffers2(GLADloadproc load) {
	if (!GLAD_GL_EXT_draw_buffers2) return;
	glad_glColorMaskIndexedEXT = (PFNGLCOLORMASKINDEXEDEXTPROC)load("glColorMaskIndexedEXT");
	glad_glGetBooleanIndexedvEXT = (PFNGLGETBOOLEANINDEXEDVEXTPROC)load("glGetBooleanIndexedvEXT");
	glad_glGetIntegerIndexedvEXT = (PFNGLGETINTEGERINDEXEDVEXTPROC)load("glGetIntegerIndexedvEXT");
	glad_glEnableIndexedEXT = (PFNGLENABLEINDEXEDEXTPROC)load("glEnableIndexedEXT");
	glad_glDisableIndexedEXT = (PFNGLDISABLEINDEXEDEXTPROC)load("glDisableIndexedEXT");
	glad_glIsEnabledIndexedEXT = (PFNGLISENABLEDINDEXEDEXTPROC)load("glIsEnabledIndexedEXT");
}
static void load_GL_ARB_vertex_attrib_64bit(GLADloadproc load) {
	if (!GLAD_GL_ARB_vertex_attrib_64bit) return;
	glad_glVertexAttribL1d = (PFNGLVERTEXATTRIBL1DPROC)load("glVertexAttribL1d");
	glad_glVertexAttribL2d = (PFNGLVERTEXATTRIBL2DPROC)load("glVertexAttribL2d");
	glad_glVertexAttribL3d = (PFNGLVERTEXATTRIBL3DPROC)load("glVertexAttribL3d");
	glad_glVertexAttribL4d = (PFNGLVERTEXATTRIBL4DPROC)load("glVertexAttribL4d");
	glad_glVertexAttribL1dv = (PFNGLVERTEXATTRIBL1DVPROC)load("glVertexAttribL1dv");
	glad_glVertexAttribL2dv = (PFNGLVERTEXATTRIBL2DVPROC)load("glVertexAttribL2dv");
	glad_glVertexAttribL3dv = (PFNGLVERTEXATTRIBL3DVPROC)load("glVertexAttribL3dv");
	glad_glVertexAttribL4dv = (PFNGLVERTEXATTRIBL4DVPROC)load("glVertexAttribL4dv");
	glad_glVertexAttribLPointer = (PFNGLVERTEXATTRIBLPOINTERPROC)load("glVertexAttribLPointer");
	glad_glGetVertexAttribLdv = (PFNGLGETVERTEXATTRIBLDVPROC)load("glGetVertexAttribLdv");
}
static void load_GL_EXT_texture_filter_minmax(GLADloadproc load) {
	if (!GLAD_GL_EXT_texture_filter_minmax) return;
	glad_glRasterSamplesEXT = (PFNGLRASTERSAMPLESEXTPROC)load("glRasterSamplesEXT");
}
static void load_GL_AMD_interleaved_elements(GLADloadproc load) {
	if (!GLAD_GL_AMD_interleaved_elements) return;
	glad_glVertexAttribParameteriAMD = (PFNGLVERTEXATTRIBPARAMETERIAMDPROC)load("glVertexAttribParameteriAMD");
}
static void load_GL_ARB_fragment_program(GLADloadproc load) {
	if (!GLAD_GL_ARB_fragment_program) return;
	glad_glProgramStringARB = (PFNGLPROGRAMSTRINGARBPROC)load("glProgramStringARB");
	glad_glBindProgramARB = (PFNGLBINDPROGRAMARBPROC)load("glBindProgramARB");
	glad_glDeleteProgramsARB = (PFNGLDELETEPROGRAMSARBPROC)load("glDeleteProgramsARB");
	glad_glGenProgramsARB = (PFNGLGENPROGRAMSARBPROC)load("glGenProgramsARB");
	glad_glProgramEnvParameter4dARB = (PFNGLPROGRAMENVPARAMETER4DARBPROC)load("glProgramEnvParameter4dARB");
	glad_glProgramEnvParameter4dvARB = (PFNGLPROGRAMENVPARAMETER4DVARBPROC)load("glProgramEnvParameter4dvARB");
	glad_glProgramEnvParameter4fARB = (PFNGLPROGRAMENVPARAMETER4FARBPROC)load("glProgramEnvParameter4fARB");
	glad_glProgramEnvParameter4fvARB = (PFNGLPROGRAMENVPARAMETER4FVARBPROC)load("glProgramEnvParameter4fvARB");
	glad_glProgramLocalParameter4dARB = (PFNGLPROGRAMLOCALPARAMETER4DARBPROC)load("glProgramLocalParameter4dARB");
	glad_glProgramLocalParameter4dvARB = (PFNGLPROGRAMLOCALPARAMETER4DVARBPROC)load("glProgramLocalParameter4dvARB");
	glad_glProgramLocalParameter4fARB = (PFNGLPROGRAMLOCALPARAMETER4FARBPROC)load("glProgramLocalParameter4fARB");
	glad_glProgramLocalParameter4fvARB = (PFNGLPROGRAMLOCALPARAMETER4FVARBPROC)load("glProgramLocalParameter4fvARB");
	glad_glGetProgramEnvParameterdvARB = (PFNGLGETPROGRAMENVPARAMETERDVARBPROC)load("glGetProgramEnvParameterdvARB");
	glad_glGetProgramEnvParameterfvARB = (PFNGLGETPROGRAMENVPARAMETERFVARBPROC)load("glGetProgramEnvParameterfvARB");
	glad_glGetProgramLocalParameterdvARB = (PFNGLGETPROGRAMLOCALPARAMETERDVARBPROC)load("glGetProgramLocalParameterdvARB");
	glad_glGetProgramLocalParameterfvARB = (PFNGLGETPROGRAMLOCALPARAMETERFVARBPROC)load("glGetProgramLocalParameterfvARB");
	glad_glGetProgramivARB = (PFNGLGETPROGRAMIVARBPROC)load("glGetProgramivARB");
	glad_glGetProgramStringARB = (PFNGLGETPROGRAMSTRINGARBPROC)load("glGetProgramStringARB");
	glad_glIsProgramARB = (PFNGLISPROGRAMARBPROC)load("glIsProgramARB");
}
static void load_GL_ARB_texture_storage(GLADloadproc load) {
	if (!GLAD_GL_ARB_texture_storage) return;
	glad_glTexStorage1D = (PFNGLTEXSTORAGE1DPROC)load("glTexStorage1D");
	glad_glTexStorage2D = (PFNGLTEXSTORAGE2DPROC)load("glTexStorage2D");
	glad_glTexStorage3D = (PFNGLTEXSTORAGE3DPROC)load("glTexStorage3D");
}
static void load_GL_ARB_copy_image(GLADloadproc load) {
	if (!GLAD_GL_ARB_copy_image) return;
	glad_glCopyImageSubData = (PFNGLCOPYIMAGESUBDATAPROC)load("glCopyImageSubData");
}
static void load_GL_SGIS_pixel_texture(GLADloadproc load) {
	if (!GLAD_GL_SGIS_pixel_texture) return;
	glad_glPixelTexGenParameteriSGIS = (PFNGLPIXELTEXGENPARAMETERISGISPROC)load("glPixelTexGenParameteriSGIS");
	glad_glPixelTexGenParameterivSGIS = (PFNGLPIXELTEXGENPARAMETERIVSGISPROC)load("glPixelTexGenParameterivSGIS");
	glad_glPixelTexGenParameterfSGIS = (PFNGLPIXELTEXGENPARAMETERFSGISPROC)load("glPixelTexGenParameterfSGIS");
	glad_glPixelTexGenParameterfvSGIS = (PFNGLPIXELTEXGENPARAMETERFVSGISPROC)load("glPixelTexGenParameterfvSGIS");
	glad_glGetPixelTexGenParameterivSGIS = (PFNGLGETPIXELTEXGENPARAMETERIVSGISPROC)load("glGetPixelTexGenParameterivSGIS");
	glad_glGetPixelTexGenParameterfvSGIS = (PFNGLGETPIXELTEXGENPARAMETERFVSGISPROC)load("glGetPixelTexGenParameterfvSGIS");
}
static void load_GL_SGIX_instruments(GLADloadproc load) {
	if (!GLAD_GL_SGIX_instruments) return;
	glad_glGetInstrumentsSGIX = (PFNGLGETINSTRUMENTSSGIXPROC)load("glGetInstrumentsSGIX");
	glad_glInstrumentsBufferSGIX = (PFNGLINSTRUMENTSBUFFERSGIXPROC)load("glInstrumentsBufferSGIX");
	glad_glPollInstrumentsSGIX = (PFNGLPOLLINSTRUMENTSSGIXPROC)load("glPollInstrumentsSGIX");
	glad_glReadInstrumentsSGIX = (PFNGLREADINSTRUMENTSSGIXPROC)load("glReadInstrumentsSGIX");
	glad_glStartInstrumentsSGIX = (PFNGLSTARTINSTRUMENTSSGIXPROC)load("glStartInstrumentsSGIX");
	glad_glStopInstrumentsSGIX = (PFNGLSTOPINSTRUMENTSSGIXPROC)load("glStopInstrumentsSGIX");
}
static void load_GL_ARB_shader_storage_buffer_object(GLADloadproc load) {
	if (!GLAD_GL_ARB_shader_storage_buffer_object) return;
	glad_glShaderStorageBlockBinding = (PFNGLSHADERSTORAGEBLOCKBINDINGPROC)load("glShaderStorageBlockBinding");
}
static void load_GL_EXT_blend_minmax(GLADloadproc load) {
	if (!GLAD_GL_EXT_blend_minmax) return;
	glad_glBlendEquationEXT = (PFNGLBLENDEQUATIONEXTPROC)load("glBlendEquationEXT");
}
static void load_GL_ARB_base_instance(GLADloadproc load) {
	if (!GLAD_GL_ARB_base_instance) return;
	glad_glDrawArraysInstancedBaseInstance = (PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC)load("glDrawArraysInstancedBaseInstance");
	glad_glDrawElementsInstancedBaseInstance = (PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC)load("glDrawElementsInstancedBaseInstance");
	glad_glDrawElementsInstancedBaseVertexBaseInstance = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC)load("glDrawElementsInstancedBaseVertexBaseInstance");
}
static void load_GL_ARB_ES3_1_compatibility(GLADloadproc load) {
	if (!GLAD_GL_ARB_ES3_1_compatibility) return;
	glad_glMemoryBarrierByRegion = (PFNGLMEMORYBARRIERBYREGIONPROC)load("glMemoryBarrierByRegion");
}
static void load_GL_EXT_texture_integer(GLADloadproc load) {
	if (!GLAD_GL_EXT_texture_integer) return;
	glad_glTexParameterIivEXT = (PFNGLTEXPARAMETERIIVEXTPROC)load("glTexParameterIivEXT");
	glad_glTexParameterIuivEXT = (PFNGLTEXPARAMETERIUIVEXTPROC)load("glTexParameterIuivEXT");
	glad_glGetTexParameterIivEXT = (PFNGLGETTEXPARAMETERIIVEXTPROC)load("glGetTexParameterIivEXT");
	glad_glGetTexParameterIuivEXT = (PFNGLGETTEXPARAMETERIUIVEXTPROC)load("glGetTexParameterIuivEXT");
	glad_glClearColorIiEXT = (PFNGLCLEARCOLORIIEXTPROC)load("glClearColorIiEXT");
	glad_glClearColorIuiEXT = (PFNGLCLEARCOLORIUIEXTPROC)load("glClearColorIuiEXT");
}
static void load_GL_ARB_texture_multisample(GLADloadproc load) {
	if (!GLAD_GL_ARB_texture_multisample) return;
	glad_glTexImage2DMultisample = (PFNGLTEXIMAGE2DMULTISAMPLEPROC)load("glTexImage2DMultisample");
	glad_glTexImage3DMultisample = (PFNGLTEXIMAGE3DMULTISAMPLEPROC)load("glTexImage3DMultisample");
	glad_glGetMultisamplefv = (PFNGLGETMULTISAMPLEFVPROC)load("glGetMultisamplefv");
	glad_glSampleMaski = (PFNGLSAMPLEMASKIPROC)load("glSampleMaski");
}
static void load_GL_AMD_gpu_shader_int64(GLADloadproc load) {
	if (!GLAD_GL_AMD_gpu_shader_int64) return;
	glad_glUniform1i64NV = (PFNGLUNIFORM1I64NVPROC)load("glUniform1i64NV");
	glad_glUniform2i64NV = (PFNGLUNIFORM2I64NVPROC)load("glUniform2i64NV");
	glad_glUniform3i64NV = (PFNGLUNIFORM3I64NVPROC)load("glUniform3i64NV");
	glad_glUniform4i64NV = (PFNGLUNIFORM4I64NVPROC)load("glUniform4i64NV");
	glad_glUniform1i64vNV = (PFNGLUNIFORM1I64VNVPROC)load("glUniform1i64vNV");
	glad_glUniform2i64vNV = (PFNGLUNIFORM2I64VNVPROC)load("glUniform2i64vNV");
	glad_glUniform3i64vNV = (PFNGLUNIFORM3I64VNVPROC)load("glUniform3i64vNV");
	glad_glUniform4i64vNV = (PFNGLUNIFORM4I64VNVPROC)load("glUniform4i64vNV");
	glad_glUniform1ui64NV = (PFNGLUNIFORM1UI64NVPROC)load("glUniform1ui64NV");
	glad_glUniform2ui64NV = (PFNGLUNIFORM2UI64NVPROC)load("glUniform2ui64NV");
	glad_glUniform3ui64NV = (PFNGLUNIFORM3UI64NVPROC)load("glUniform3ui64NV");
	glad_glUniform4ui64NV = (PFNGLUNIFORM4UI64NVPROC)load("glUniform4ui64NV");
	glad_glUniform1ui64vNV = (PFNGLUNIFORM1UI64VNVPROC)load("glUniform1ui64vNV");
	glad_glUniform2ui64vNV = (PFNGLUNIFORM2UI64VNVPROC)load("glUniform2ui64vNV");
	glad_glUniform3ui64vNV = (PFNGLUNIFORM3UI64VNVPROC)load("glUniform3ui64vNV");
	glad_glUniform4ui64vNV = (PFNGLUNIFORM4UI64VNVPROC)load("glUniform4ui64vNV");
	glad_glGetUniformi64vNV = (PFNGLGETUNIFORMI64VNVPROC)load("glGetUniformi64vNV");
	glad_glGetUniformui64vNV = (PFNGLGETUNIFORMUI64VNVPROC)load("glGetUniformui64vNV");
	glad_glProgramUniform1i64NV = (PFNGLPROGRAMUNIFORM1I64NVPROC)load("glProgramUniform1i64NV");
	glad_glProgramUniform2i64NV = (PFNGLPROGRAMUNIFORM2I64NVPROC)load("glProgramUniform2i64NV");
	glad_glProgramUniform3i64NV = (PFNGLPROGRAMUNIFORM3I64NVPROC)load("glProgramUniform3i64NV");
	glad_glProgramUniform4i64NV = (PFNGLPROGRAMUNIFORM4I64NVPROC)load("glProgramUniform4i64NV");
	glad_glProgramUniform1i64vNV = (PFNGLPROGRAMUNIFORM1I64VNVPROC)load("glProgramUniform1i64vNV");
	glad_glProgramUniform2i64vNV = (PFNGLPROGRAMUNIFORM2I64VNVPROC)load("glProgramUniform2i64vNV");
	glad_glProgramUniform3i64vNV = (PFNGLPROGRAMUNIFORM3I64VNVPROC)load("glProgramUniform3i64vNV");
	glad_glProgramUniform4i64vNV = (PFNGLPROGRAMUNIFORM4I64VNVPROC)load("glProgramUniform4i64vNV");
	glad_glProgramUniform1ui64NV = (PFNGLPROGRAMUNIFORM1UI64NVPROC)load("glProgramUniform1ui64NV");
	glad_glProgramUniform2ui64NV = (PFNGLPROGRAMUNIFORM2UI64NVPROC)load("glProgramUniform2ui64NV");
	glad_glProgramUniform3ui64NV = (PFNGLPROGRAMUNIFORM3UI64NVPROC)load("glProgramUniform3ui64NV");
	glad_glProgramUniform4ui64NV = (PFNGLPROGRAMUNIFORM4UI64NVPROC)load("glProgramUniform4ui64NV");
	glad_glProgramUniform1ui64vNV = (PFNGLPROGRAMUNIFORM1UI64VNVPROC)load("glProgramUniform1ui64vNV");
	glad_glProgramUniform2ui64vNV = (PFNGLPROGRAMUNIFORM2UI64VNVPROC)load("glProgramUniform2ui64vNV");
	glad_glProgramUniform3ui64vNV = (PFNGLPROGRAMUNIFORM3UI64VNVPROC)load("glProgramUniform3ui64vNV");
	glad_glProgramUniform4ui64vNV = (PFNGLPROGRAMUNIFORM4UI64VNVPROC)load("glProgramUniform4ui64vNV");
}
static void load_GL_AMD_vertex_shader_tessellator(GLADloadproc load) {
	if (!GLAD_GL_AMD_vertex_shader_tessellator) return;
	glad_glTessellationFactorAMD = (PFNGLTESSELLATIONFACTORAMDPROC)load("glTessellationFactorAMD");
	glad_glTessellationModeAMD = (PFNGLTESSELLATIONMODEAMDPROC)load("glTessellationModeAMD");
}
static void load_GL_ARB_invalidate_subdata(GLADloadproc load) {
	if (!GLAD_GL_ARB_invalidate_subdata) return;
	glad_glInvalidateTexSubImage = (PFNGLINVALIDATETEXSUBIMAGEPROC)load("glInvalidateTexSubImage");
	glad_glInvalidateTexImage = (PFNGLINVALIDATETEXIMAGEPROC)load("glInvalidateTexImage");
	glad_glInvalidateBufferSubData = (PFNGLINVALIDATEBUFFERSUBDATAPROC)load("glInvalidateBufferSubData");
	glad_glInvalidateBufferData = (PFNGLINVALIDATEBUFFERDATAPROC)load("glInvalidateBufferData");
	glad_glInvalidateFramebuffer = (PFNGLINVALIDATEFRAMEBUFFERPROC)load("glInvalidateFramebuffer");
	glad_glInvalidateSubFramebuffer = (PFNGLINVALIDATESUBFRAMEBUFFERPROC)load("glInvalidateSubFramebuffer");
}
static void load_GL_EXT_index_material(GLADloadproc load) {
	if (!GLAD_GL_EXT_index_material) return;
	glad_glIndexMaterialEXT = (PFNGLINDEXMATERIALEXTPROC)load("glIndexMaterialEXT");
}
static void load_GL_INTEL_parallel_arrays(GLADloadproc load) {
	if (!GLAD_GL_INTEL_parallel_arrays) return;
	glad_glVertexPointervINTEL = (PFNGLVERTEXPOINTERVINTELPROC)load("glVertexPointervINTEL");
	glad_glNormalPointervINTEL = (PFNGLNORMALPOINTERVINTELPROC)load("glNormalPointervINTEL");
	glad_glColorPointervINTEL = (PFNGLCOLORPOINTERVINTELPROC)load("glColorPointervINTEL");
	glad_glTexCoordPointervINTEL = (PFNGLTEXCOORDPOINTERVINTELPROC)load("glTexCoordPointervINTEL");
}
static void load_GL_ATI_draw_buffers(GLADloadproc load) {
	if (!GLAD_GL_ATI_draw_buffers) return;
	glad_glDrawBuffersATI = (PFNGLDRAWBUFFERSATIPROC)load("glDrawBuffersATI");
}
static void load_GL_SGIX_pixel_texture(GLADloadproc load) {
	if (!GLAD_GL_SGIX_pixel_texture) return;
	glad_glPixelTexGenSGIX = (PFNGLPIXELTEXGENSGIXPROC)load("glPixelTexGenSGIX");
}
static void load_GL_ARB_timer_query(GLADloadproc load) {
	if (!GLAD_GL_ARB_timer_query) return;
	glad_glQueryCounter = (PFNGLQUERYCOUNTERPROC)load("glQueryCounter");
	glad_glGetQueryObjecti64v = (PFNGLGETQUERYOBJECTI64VPROC)load("glGetQueryObjecti64v");
	glad_glGetQueryObjectui64v = (PFNGLGETQUERYOBJECTUI64VPROC)load("glGetQueryObjectui64v");
}
static void load_GL_NV_parameter_buffer_object(GLADloadproc load) {
	if (!GLAD_GL_NV_parameter_buffer_object) return;
	glad_glProgramBufferParametersfvNV = (PFNGLPROGRAMBUFFERPARAMETERSFVNVPROC)load("glProgramBufferParametersfvNV");
	glad_glProgramBufferParametersIivNV = (PFNGLPROGRAMBUFFERPARAMETERSIIVNVPROC)load("glProgramBufferParametersIivNV");
	glad_glProgramBufferParametersIuivNV = (PFNGLPROGRAMBUFFERPARAMETERSIUIVNVPROC)load("glProgramBufferParametersIuivNV");
}
static void load_GL_ARB_direct_state_access(GLADloadproc load) {
	if (!GLAD_GL_ARB_direct_state_access) return;
	glad_glCreateTransformFeedbacks = (PFNGLCREATETRANSFORMFEEDBACKSPROC)load("glCreateTransformFeedbacks");
	glad_glTransformFeedbackBufferBase = (PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC)load("glTransformFeedbackBufferBase");
	glad_glTransformFeedbackBufferRange = (PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC)load("glTransformFeedbackBufferRange");
	glad_glGetTransformFeedbackiv = (PFNGLGETTRANSFORMFEEDBACKIVPROC)load("glGetTransformFeedbackiv");
	glad_glGetTransformFeedbacki_v = (PFNGLGETTRANSFORMFEEDBACKI_VPROC)load("glGetTransformFeedbacki_v");
	glad_glGetTransformFeedbacki64_v = (PFNGLGETTRANSFORMFEEDBACKI64_VPROC)load("glGetTransformFeedbacki64_v");
	glad_glCreateBuffers = (PFNGLCREATEBUFFERSPROC)load("glCreateBuffers");
	glad_glNamedBufferStorage = (PFNGLNAMEDBUFFERSTORAGEPROC)load("glNamedBufferStorage");
	glad_glNamedBufferData = (PFNGLNAMEDBUFFERDATAPROC)load("glNamedBufferData");
	glad_glNamedBufferSubData = (PFNGLNAMEDBUFFERSUBDATAPROC)load("glNamedBufferSubData");
	glad_glCopyNamedBufferSubData = (PFNGLCOPYNAMEDBUFFERSUBDATAPROC)load("glCopyNamedBufferSubData");
	glad_glClearNamedBufferData = (PFNGLCLEARNAMEDBUFFERDATAPROC)load("glClearNamedBufferData");
	glad_glClearNamedBufferSubData = (PFNGLCLEARNAMEDBUFFERSUBDATAPROC)load("glClearNamedBufferSubData");
	glad_glMapNamedBuffer = (PFNGLMAPNAMEDBUFFERPROC)load("glMapNamedBuffer");
	glad_glMapNamedBufferRange = (PFNGLMAPNAMEDBUFFERRANGEPROC)load("glMapNamedBufferRange");
	glad_glUnmapNamedBuffer = (PFNGLUNMAPNAMEDBUFFERPROC)load("glUnmapNamedBuffer");
	glad_glFlushMappedNamedBufferRange = (PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC)load("glFlushMappedNamedBufferRange");
	glad_glGetNamedBufferParameteriv = (PFNGLGETNAMEDBUFFERPARAMETERIVPROC)load("glGetNamedBufferParameteriv");
	glad_glGetNamedBufferParameteri64v = (PFNGLGETNAMEDBUFFERPARAMETERI64VPROC)load("glGetNamedBufferParameteri64v");
	glad_glGetNamedBufferPointerv = (PFNGLGETNAMEDBUFFERPOINTERVPROC)load("glGetNamedBufferPointerv");
	glad_glGetNamedBufferSubData = (PFNGLGETNAMEDBUFFERSUBDATAPROC)load("glGetNamedBufferSubData");
	glad_glCreateFramebuffers = (PFNGLCREATEFRAMEBUFFERSPROC)load("glCreateFramebuffers");
	glad_glNamedFramebufferRenderbuffer = (PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC)load("glNamedFramebufferRenderbuffer");
	glad_glNamedFramebufferParameteri = (PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC)load("glNamedFramebufferParameteri");
	glad_glNamedFramebufferTexture = (PFNGLNAMEDFRAMEBUFFERTEXTUREPROC)load("glNamedFramebufferTexture");
	glad_glNamedFramebufferTextureLayer = (PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC)load("glNamedFramebufferTextureLayer");
	glad_glNamedFramebufferDrawBuffer = (PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC)load("glNamedFramebufferDrawBuffer");
	glad_glNamedFramebufferDrawBuffers = (PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC)load("glNamedFramebufferDrawBuffers");
	glad_glNamedFramebufferReadBuffer = (PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC)load("glNamedFramebufferReadBuffer");
	glad_glInvalidateNamedFramebufferData = (PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC)load("glInvalidateNamedFramebufferData");
	glad_glInvalidateNamedFramebufferSubData = (PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC)load("glInvalidateNamedFramebufferSubData");
	glad_glClearNamedFramebufferiv = (PFNGLCLEARNAMEDFRAMEBUFFERIVPROC)load("glClearNamedFramebufferiv");
	glad_glClearNamedFramebufferuiv = (PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC)load("glClearNamedFramebufferuiv");
	glad_glClearNamedFramebufferfv = (PFNGLCLEARNAMEDFRAMEBUFFERFVPROC)load("glClearNamedFramebufferfv");
	glad_glClearNamedFramebufferfi = (PFNGLCLEARNAMEDFRAMEBUFFERFIPROC)load("glClearNamedFramebufferfi");
	glad_glBlitNamedFramebuffer = (PFNGLBLITNAMEDFRAMEBUFFERPROC)load("glBlitNamedFramebuffer");
	glad_glCheckNamedFramebufferStatus = (PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC)load("glCheckNamedFramebufferStatus");
	glad_glGetNamedFramebufferParameteriv = (PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC)load("glGetNamedFramebufferParameteriv");
	glad_glGetNamedFramebufferAttachmentParameteriv = (PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC)load("glGetNamedFramebufferAttachmentParameteriv");
	glad_glCreateRenderbuffers = (PFNGLCREATERENDERBUFFERSPROC)load("glCreateRenderbuffers");
	glad_glNamedRenderbufferStorage = (PFNGLNAMEDRENDERBUFFERSTORAGEPROC)load("glNamedRenderbufferStorage");
	glad_glNamedRenderbufferStorageMultisample = (PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC)load("glNamedRenderbufferStorageMultisample");
	glad_glGetNamedRenderbufferParameteriv = (PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC)load("glGetNamedRenderbufferParameteriv");
	glad_glCreateTextures = (PFNGLCREATETEXTURESPROC)load("glCreateTextures");
	glad_glTextureBuffer = (PFNGLTEXTUREBUFFERPROC)load("glTextureBuffer");
	glad_glTextureBufferRange = (PFNGLTEXTUREBUFFERRANGEPROC)load("glTextureBufferRange");
	glad_glTextureStorage1D = (PFNGLTEXTURESTORAGE1DPROC)load("glTextureStorage1D");
	glad_glTextureStorage2D = (PFNGLTEXTURESTORAGE2DPROC)load("glTextureStorage2D");
	glad_glTextureStorage3D = (PFNGLTEXTURESTORAGE3DPROC)load("glTextureStorage3D");
	glad_glTextureStorage2DMultisample = (PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC)load("glTextureStorage2DMultisample");
	glad_glTextureStorage3DMultisample = (PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC)load("glTextureStorage3DMultisample");
	glad_glTextureSubImage1D = (PFNGLTEXTURESUBIMAGE1DPROC)load("glTextureSubImage1D");
	glad_glTextureSubImage2D = (PFNGLTEXTURESUBIMAGE2DPROC)load("glTextureSubImage2D");
	glad_glTextureSubImage3D = (PFNGLTEXTURESUBIMAGE3DPROC)load("glTextureSubImage3D");
	glad_glCompressedTextureSubImage1D = (PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC)load("glCompressedTextureSubImage1D");
	glad_glCompressedTextureSubImage2D = (PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC)load("glCompressedTextureSubImage2D");
	glad_glCompressedTextureSubImage3D = (PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC)load("glCompressedTextureSubImage3D");
	glad_glCopyTextureSubImage1D = (PFNGLCOPYTEXTURESUBIMAGE1DPROC)load("glCopyTextureSubImage1D");
	glad_glCopyTextureSubImage2D = (PFNGLCOPYTEXTURESUBIMAGE2DPROC)load("glCopyTextureSubImage2D");
	glad_glCopyTextureSubImage3D = (PFNGLCOPYTEXTURESUBIMAGE3DPROC)load("glCopyTextureSubImage3D");
	glad_glTextureParameterf = (PFNGLTEXTUREPARAMETERFPROC)load("glTextureParameterf");
	glad_glTextureParameterfv = (PFNGLTEXTUREPARAMETERFVPROC)load("glTextureParameterfv");
	glad_glTextureParameteri = (PFNGLTEXTUREPARAMETERIPROC)load("glTextureParameteri");
	glad_glTextureParameterIiv = (PFNGLTEXTUREPARAMETERIIVPROC)load("glTextureParameterIiv");
	glad_glTextureParameterIuiv = (PFNGLTEXTUREPARAMETERIUIVPROC)load("glTextureParameterIuiv");
	glad_glTextureParameteriv = (PFNGLTEXTUREPARAMETERIVPROC)load("glTextureParameteriv");
	glad_glGenerateTextureMipmap = (PFNGLGENERATETEXTUREMIPMAPPROC)load("glGenerateTextureMipmap");
	glad_glBindTextureUnit = (PFNGLBINDTEXTUREUNITPROC)load("glBindTextureUnit");
	glad_glGetTextureImage = (PFNGLGETTEXTUREIMAGEPROC)load("glGetTextureImage");
	glad_glGetCompressedTextureImage = (PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC)load("glGetCompressedTextureImage");
	glad_glGetTextureLevelParameterfv = (PFNGLGETTEXTURELEVELPARAMETERFVPROC)load("glGetTextureLevelParameterfv");
	glad_glGetTextureLevelParameteriv = (PFNGLGETTEXTURELEVELPARAMETERIVPROC)load("glGetTextureLevelParameteriv");
	glad_glGetTextureParameterfv = (PFNGLGETTEXTUREPARAMETERFVPROC)load("glGetTextureParameterfv");
	glad_glGetTextureParameterIiv = (PFNGLGETTEXTUREPARAMETERIIVPROC)load("glGetTextureParameterIiv");
	glad_glGetTextureParameterIuiv = (PFNGLGETTEXTUREPARAMETERIUIVPROC)load("glGetTextureParameterIuiv");
	glad_glGetTextureParameteriv = (PFNGLGETTEXTUREPARAMETERIVPROC)load("glGetTextureParameteriv");
	glad_glCreateVertexArrays = (PFNGLCREATEVERTEXARRAYSPROC)load("glCreateVertexArrays");
	glad_glDisableVertexArrayAttrib = (PFNGLDISABLEVERTEXARRAYATTRIBPROC)load("glDisableVertexArrayAttrib");
	glad_glEnableVertexArrayAttrib = (PFNGLENABLEVERTEXARRAYATTRIBPROC)load("glEnableVertexArrayAttrib");
	glad_glVertexArrayElementBuffer = (PFNGLVERTEXARRAYELEMENTBUFFERPROC)load("glVertexArrayElementBuffer");
	glad_glVertexArrayVertexBuffer = (PFNGLVERTEXARRAYVERTEXBUFFERPROC)load("glVertexArrayVertexBuffer");
	glad_glVertexArrayVertexBuffers = (PFNGLVERTEXARRAYVERTEXBUFFERSPROC)load("glVertexArrayVertexBuffers");
	glad_glVertexArrayAttribBinding = (PFNGLVERTEXARRAYATTRIBBINDINGPROC)load("glVertexArrayAttribBinding");
	glad_glVertexArrayAttribFormat = (PFNGLVERTEXARRAYATTRIBFORMATPROC)load("glVertexArrayAttribFormat");
	glad_glVertexArrayAttribIFormat = (PFNGLVERTEXARRAYATTRIBIFORMATPROC)load("glVertexArrayAttribIFormat");
	glad_glVertexArrayAttribLFormat = (PFNGLVERTEXARRAYATTRIBLFORMATPROC)load("glVertexArrayAttribLFormat");
	glad_glVertexArrayBindingDivisor = (PFNGLVERTEXARRAYBINDINGDIVISORPROC)load("glVertexArrayBindingDivisor");
	glad_glGetVertexArrayiv = (PFNGLGETVERTEXARRAYIVPROC)load("glGetVertexArrayiv");
	glad_glGetVertexArrayIndexediv = (PFNGLGETVERTEXARRAYINDEXEDIVPROC)load("glGetVertexArrayIndexediv");
	glad_glGetVertexArrayIndexed64iv = (PFNGLGETVERTEXARRAYINDEXED64IVPROC)load("glGetVertexArrayIndexed64iv");
	glad_glCreateSamplers = (PFNGLCREATESAMPLERSPROC)load("glCreateSamplers");
	glad_glCreateProgramPipelines = (PFNGLCREATEPROGRAMPIPELINESPROC)load("glCreateProgramPipelines");
	glad_glCreateQueries = (PFNGLCREATEQUERIESPROC)load("glCreateQueries");
	glad_glGetQueryBufferObjecti64v = (PFNGLGETQUERYBUFFEROBJECTI64VPROC)load("glGetQueryBufferObjecti64v");
	glad_glGetQueryBufferObjectiv = (PFNGLGETQUERYBUFFEROBJECTIVPROC)load("glGetQueryBufferObjectiv");
	glad_glGetQueryBufferObjectui64v = (PFNGLGETQUERYBUFFEROBJECTUI64VPROC)load("glGetQueryBufferObjectui64v");
	glad_glGetQueryBufferObjectuiv = (PFNGLGETQUERYBUFFEROBJECTUIVPROC)load("glGetQueryBufferObjectuiv");
}
static void load_GL_ARB_uniform_buffer_object(GLADloadproc load) {
	if (!GLAD_GL_ARB_uniform_buffer_object) return;
	glad_glGetUniformIndices = (PFNGLGETUNIFORMINDICESPROC)load("glGetUniformIndices");
	glad_glGetActiveUniformsiv = (PFNGLGETACTIVEUNIFORMSIVPROC)load("glGetActiveUniformsiv");
	glad_glGetActiveUniformName = (PFNGLGETACTIVEUNIFORMNAMEPROC)load("glGetActiveUniformName");
	glad_glGetUniformBlockIndex = (PFNGLGETUNIFORMBLOCKINDEXPROC)load("glGetUniformBlockIndex");
	glad_glGetActiveUniformBlockiv = (PFNGLGETACTIVEUNIFORMBLOCKIVPROC)load("glGetActiveUniformBlockiv");
	glad_glGetActiveUniformBlockName = (PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC)load("glGetActiveUniformBlockName");
	glad_glUniformBlockBinding = (PFNGLUNIFORMBLOCKBINDINGPROC)load("glUniformBlockBinding");
	glad_glBindBufferRange = (PFNGLBINDBUFFERRANGEPROC)load("glBindBufferRange");
	glad_glBindBufferBase = (PFNGLBINDBUFFERBASEPROC)load("glBindBufferBase");
	glad_glGetIntegeri_v = (PFNGLGETINTEGERI_VPROC)load("glGetIntegeri_v");
}
static void load_GL_NV_transform_feedback2(GLADloadproc load) {
	if (!GLAD_GL_NV_transform_feedback2) return;
	glad_glBindTransformFeedbackNV = (PFNGLBINDTRANSFORMFEEDBACKNVPROC)load("glBindTransformFeedbackNV");
	glad_glDeleteTransformFeedbacksNV = (PFNGLDELETETRANSFORMFEEDBACKSNVPROC)load("glDeleteTransformFeedbacksNV");
	glad_glGenTransformFeedbacksNV = (PFNGLGENTRANSFORMFEEDBACKSNVPROC)load("glGenTransformFeedbacksNV");
	glad_glIsTransformFeedbackNV = (PFNGLISTRANSFORMFEEDBACKNVPROC)load("glIsTransformFeedbackNV");
	glad_glPauseTransformFeedbackNV = (PFNGLPAUSETRANSFORMFEEDBACKNVPROC)load("glPauseTransformFeedbackNV");
	glad_glResumeTransformFeedbackNV = (PFNGLRESUMETRANSFORMFEEDBACKNVPROC)load("glResumeTransformFeedbackNV");
	glad_glDrawTransformFeedbackNV = (PFNGLDRAWTRANSFORMFEEDBACKNVPROC)load("glDrawTransformFeedbackNV");
}
static void load_GL_EXT_blend_color(GLADloadproc load) {
	if (!GLAD_GL_EXT_blend_color) return;
	glad_glBlendColorEXT = (PFNGLBLENDCOLOREXTPROC)load("glBlendColorEXT");
}
static void load_GL_EXT_histogram(GLADloadproc load) {
	if (!GLAD_GL_EXT_histogram) return;
	glad_glGetHistogramEXT = (PFNGLGETHISTOGRAMEXTPROC)load("glGetHistogramEXT");
	glad_glGetHistogramParameterfvEXT = (PFNGLGETHISTOGRAMPARAMETERFVEXTPROC)load("glGetHistogramParameterfvEXT");
	glad_glGetHistogramParameterivEXT = (PFNGLGETHISTOGRAMPARAMETERIVEXTPROC)load("glGetHistogramParameterivEXT");
	glad_glGetMinmaxEXT = (PFNGLGETMINMAXEXTPROC)load("glGetMinmaxEXT");
	glad_glGetMinmaxParameterfvEXT = (PFNGLGETMINMAXPARAMETERFVEXTPROC)load("glGetMinmaxParameterfvEXT");
	glad_glGetMinmaxParameterivEXT = (PFNGLGETMINMAXPARAMETERIVEXTPROC)load("glGetMinmaxParameterivEXT");
	glad_glHistogramEXT = (PFNGLHISTOGRAMEXTPROC)load("glHistogramEXT");
	glad_glMinmaxEXT = (PFNGLMINMAXEXTPROC)load("glMinmaxEXT");
	glad_glResetHistogramEXT = (PFNGLRESETHISTOGRAMEXTPROC)load("glResetHistogramEXT");
	glad_glResetMinmaxEXT = (PFNGLRESETMINMAXEXTPROC)load("glResetMinmaxEXT");
}
static void load_GL_EXT_polygon_offset(GLADloadproc load) {
	if (!GLAD_GL_EXT_polygon_offset) return;
	glad_glPolygonOffsetEXT = (PFNGLPOLYGONOFFSETEXTPROC)load("glPolygonOffsetEXT");
}
static void load_GL_SGIS_point_parameters(GLADloadproc load) {
	if (!GLAD_GL_SGIS_point_parameters) return;
	glad_glPointParameterfSGIS = (PFNGLPOINTPARAMETERFSGISPROC)load("glPointParameterfSGIS");
	glad_glPointParameterfvSGIS = (PFNGLPOINTPARAMETERFVSGISPROC)load("glPointParameterfvSGIS");
}
static void load_GL_EXT_direct_state_access(GLADloadproc load) {
	if (!GLAD_GL_EXT_direct_state_access) return;
	glad_glMatrixLoadfEXT = (PFNGLMATRIXLOADFEXTPROC)load("glMatrixLoadfEXT");
	glad_glMatrixLoaddEXT = (PFNGLMATRIXLOADDEXTPROC)load("glMatrixLoaddEXT");
	glad_glMatrixMultfEXT = (PFNGLMATRIXMULTFEXTPROC)load("glMatrixMultfEXT");
	glad_glMatrixMultdEXT = (PFNGLMATRIXMULTDEXTPROC)load("glMatrixMultdEXT");
	glad_glMatrixLoadIdentityEXT = (PFNGLMATRIXLOADIDENTITYEXTPROC)load("glMatrixLoadIdentityEXT");
	glad_glMatrixRotatefEXT = (PFNGLMATRIXROTATEFEXTPROC)load("glMatrixRotatefEXT");
	glad_glMatrixRotatedEXT = (PFNGLMATRIXROTATEDEXTPROC)load("glMatrixRotatedEXT");
	glad_glMatrixScalefEXT = (PFNGLMATRIXSCALEFEXTPROC)load("glMatrixScalefEXT");
	glad_glMatrixScaledEXT = (PFNGLMATRIXSCALEDEXTPROC)load("glMatrixScaledEXT");
	glad_glMatrixTranslatefEXT = (PFNGLMATRIXTRANSLATEFEXTPROC)load("glMatrixTranslatefEXT");
	glad_glMatrixTranslatedEXT = (PFNGLMATRIXTRANSLATEDEXTPROC)load("glMatrixTranslatedEXT");
	glad_glMatrixFrustumEXT = (PFNGLMATRIXFRUSTUMEXTPROC)load("glMatrixFrustumEXT");
	glad_glMatrixOrthoEXT = (PFNGLMATRIXORTHOEXTPROC)load("glMatrixOrthoEXT");
	glad_glMatrixPopEXT = (PFNGLMATRIXPOPEXTPROC)load("glMatrixPopEXT");
	glad_glMatrixPushEXT = (PFNGLMATRIXPUSHEXTPROC)load("glMatrixPushEXT");
	glad_glClientAttribDefaultEXT = (PFNGLCLIENTATTRIBDEFAULTEXTPROC)load("glClientAttribDefaultEXT");
	glad_glPushClientAttribDefaultEXT = (PFNGLPUSHCLIENTATTRIBDEFAULTEXTPROC)load("glPushClientAttribDefaultEXT");
	glad_glTextureParameterfEXT = (PFNGLTEXTUREPARAMETERFEXTPROC)load("glTextureParameterfEXT");
	glad_glTextureParameterfvEXT = (PFNGLTEXTUREPARAMETERFVEXTPROC)load("glTextureParameterfvEXT");
	glad_glTextureParameteriEXT = (PFNGLTEXTUREPARAMETERIEXTPROC)load("glTextureParameteriEXT");
	glad_glTextureParameterivEXT = (PFNGLTEXTUREPARAMETERIVEXTPROC)load("glTextureParameterivEXT");
	glad_glTextureImage1DEXT = (PFNGLTEXTUREIMAGE1DEXTPROC)load("glTextureImage1DEXT");
	glad_glTextureImage2DEXT = (PFNGLTEXTUREIMAGE2DEXTPROC)load("glTextureImage2DEXT");
	glad_glTextureSubImage1DEXT = (PFNGLTEXTURESUBIMAGE1DEXTPROC)load("glTextureSubImage1DEXT");
	glad_glTextureSubImage2DEXT = (PFNGLTEXTURESUBIMAGE2DEXTPROC)load("glTextureSubImage2DEXT");
	glad_glCopyTextureImage1DEXT = (PFNGLCOPYTEXTUREIMAGE1DEXTPROC)load("glCopyTextureImage1DEXT");
	glad_glCopyTextureImage2DEXT = (PFNGLCOPYTEXTUREIMAGE2DEXTPROC)load("glCopyTextureImage2DEXT");
	glad_glCopyTextureSubImage1DEXT = (PFNGLCOPYTEXTURESUBIMAGE1DEXTPROC)load("glCopyTextureSubImage1DEXT");
	glad_glCopyTextureSubImage2DEXT = (PFNGLCOPYTEXTURESUBIMAGE2DEXTPROC)load("glCopyTextureSubImage2DEXT");
	glad_glGetTextureImageEXT = (PFNGLGETTEXTUREIMAGEEXTPROC)load("glGetTextureImageEXT");
	glad_glGetTextureParameterfvEXT = (PFNGLGETTEXTUREPARAMETERFVEXTPROC)load("glGetTextureParameterfvEXT");
	glad_glGetTextureParameterivEXT = (PFNGLGETTEXTUREPARAMETERIVEXTPROC)load("glGetTextureParameterivEXT");
	glad_glGetTextureLevelParameterfvEXT = (PFNGLGETTEXTURELEVELPARAMETERFVEXTPROC)load("glGetTextureLevelParameterfvEXT");
	glad_glGetTextureLevelParameterivEXT = (PFNGLGETTEXTURELEVELPARAMETERIVEXTPROC)load("glGetTextureLevelParameterivEXT");
	glad_glTextureImage3DEXT = (PFNGLTEXTUREIMAGE3DEXTPROC)load("glTextureImage3DEXT");
	glad_glTextureSubImage3DEXT = (PFNGLTEXTURESUBIMAGE3DEXTPROC)load("glTextureSubImage3DEXT");
	glad_glCopyTextureSubImage3DEXT = (PFNGLCOPYTEXTURESUBIMAGE3DEXTPROC)load("glCopyTextureSubImage3DEXT");
	glad_glBindMultiTextureEXT = (PFNGLBINDMULTITEXTUREEXTPROC)load("glBindMultiTextureEXT");
	glad_glMultiTexCoordPointerEXT = (PFNGLMULTITEXCOORDPOINTEREXTPROC)load("glMultiTexCoordPointerEXT");
	glad_glMultiTexEnvfEXT = (PFNGLMULTITEXENVFEXTPROC)load("glMultiTexEnvfEXT");
	glad_glMultiTexEnvfvEXT = (PFNGLMULTITEXENVFVEXTPROC)load("glMultiTexEnvfvEXT");
	glad_glMultiTexEnviEXT = (PFNGLMULTITEXENVIEXTPROC)load("glMultiTexEnviEXT");
	glad_glMultiTexEnvivEXT = (PFNGLMULTITEXENVIVEXTPROC)load("glMultiTexEnvivEXT");
	glad_glMultiTexGendEXT = (PFNGLMULTITEXGENDEXTPROC)load("glMultiTexGendEXT");
	glad_glMultiTexGendvEXT = (PFNGLMULTITEXGENDVEXTPROC)load("glMultiTexGendvEXT");
	glad_glMultiTexGenfEXT = (PFNGLMULTITEXGENFEXTPROC)load("glMultiTexGenfEXT");
	glad_glMultiTexGenfvEXT = (PFNGLMULTITEXGENFVEXTPROC)load("glMultiTexGenfvEXT");
	glad_glMultiTexGeniEXT = (PFNGLMULTITEXGENIEXTPROC)load("glMultiTexGeniEXT");
	glad_glMultiTexGenivEXT = (PFNGLMULTITEXGENIVEXTPROC)load("glMultiTexGenivEXT");
	glad_glGetMultiTexEnvfvEXT = (PFNGLGETMULTITEXENVFVEXTPROC)load("glGetMultiTexEnvfvEXT");
	glad_glGetMultiTexEnvivEXT = (PFNGLGETMULTITEXENVIVEXTPROC)load("glGetMultiTexEnvivEXT");
	glad_glGetMultiTexGendvEXT = (PFNGLGETMULTITEXGENDVEXTPROC)load("glGetMultiTexGendvEXT");
	glad_glGetMultiTexGenfvEXT = (PFNGLGETMULTITEXGENFVEXTPROC)load("glGetMultiTexGenfvEXT");
	glad_glGetMultiTexGenivEXT = (PFNGLGETMULTITEXGENIVEXTPROC)load("glGetMultiTexGenivEXT");
	glad_glMultiTexParameteriEXT = (PFNGLMULTITEXPARAMETERIEXTPROC)load("glMultiTexParameteriEXT");
	glad_glMultiTexParameterivEXT = (PFNGLMULTITEXPARAMETERIVEXTPROC)load("glMultiTexParameterivEXT");
	glad_glMultiTexParameterfEXT = (PFNGLMULTITEXPARAMETERFEXTPROC)load("glMultiTexParameterfEXT");
	glad_glMultiTexParameterfvEXT = (PFNGLMULTITEXPARAMETERFVEXTPROC)load("glMultiTexParameterfvEXT");
	glad_glMultiTexImage1DEXT = (PFNGLMULTITEXIMAGE1DEXTPROC)load("glMultiTexImage1DEXT");
	glad_glMultiTexImage2DEXT = (PFNGLMULTITEXIMAGE2DEXTPROC)load("glMultiTexImage2DEXT");
	glad_glMultiTexSubImage1DEXT = (PFNGLMULTITEXSUBIMAGE1DEXTPROC)load("glMultiTexSubImage1DEXT");
	glad_glMultiTexSubImage2DEXT = (PFNGLMULTITEXSUBIMAGE2DEXTPROC)load("glMultiTexSubImage2DEXT");
	glad_glCopyMultiTexImage1DEXT = (PFNGLCOPYMULTITEXIMAGE1DEXTPROC)load("glCopyMultiTexImage1DEXT");
	glad_glCopyMultiTexImage2DEXT = (PFNGLCOPYMULTITEXIMAGE2DEXTPROC)load("glCopyMultiTexImage2DEXT");
	glad_glCopyMultiTexSubImage1DEXT = (PFNGLCOPYMULTITEXSUBIMAGE1DEXTPROC)load("glCopyMultiTexSubImage1DEXT");
	glad_glCopyMultiTexSubImage2DEXT = (PFNGLCOPYMULTITEXSUBIMAGE2DEXTPROC)load("glCopyMultiTexSubImage2DEXT");
	glad_glGetMultiTexImageEXT = (PFNGLGETMULTITEXIMAGEEXTPROC)load("glGetMultiTexImageEXT");
	glad_glGetMultiTexParameterfvEXT = (PFNGLGETMULTITEXPARAMETERFVEXTPROC)load("glGetMultiTexParameterfvEXT");
	glad_glGetMultiTexParameterivEXT = (PFNGLGETMULTITEXPARAMETERIVEXTPROC)load("glGetMultiTexParameterivEXT");
	glad_glGetMultiTexLevelParameterfvEXT = (PFNGLGETMULTITEXLEVELPARAMETERFVEXTPROC)load("glGetMultiTexLevelParameterfvEXT");
	glad_glGetMultiTexLevelParameterivEXT = (PFNGLGETMULTITEXLEVELPARAMETERIVEXTPROC)load("glGetMultiTexLevelParameterivEXT");
	glad_glMultiTexImage3DEXT = (PFNGLMULTITEXIMAGE3DEXTPROC)load("glMultiTexImage3DEXT");
	glad_glMultiTexSubImage3DEXT = (PFNGLMULTITEXSUBIMAGE3DEXTPROC)load("glMultiTexSubImage3DEXT");
	glad_glCopyMultiTexSubImage3DEXT = (PFNGLCOPYMULTITEXSUBIMAGE3DEXTPROC)load("glCopyMultiTexSubImage3DEXT");
	glad_glEnableClientStateIndexedEXT = (PFNGLENABLECLIENTSTATEINDEXEDEXTPROC)load("glEnableClientStateIndexedEXT");
	glad_glDisableClientStateIndexedEXT = (PFNGLDISABLECLIENTSTATEINDEXEDEXTPROC)load("glDisableClientStateIndexedEXT");
	glad_glGetFloatIndexedvEXT = (PFNGLGETFLOATINDEXEDVEXTPROC)load("glGetFloatIndexedvEXT");
	glad_glGetDoubleIndexedvEXT = (PFNGLGETDOUBLEINDEXEDVEXTPROC)load("glGetDoubleIndexedvEXT");
	glad_glGetPointerIndexedvEXT = (PFNGLGETPOINTERINDEXEDVEXTPROC)load("glGetPointerIndexedvEXT");
	glad_glEnableIndexedEXT = (PFNGLENABLEINDEXEDEXTPROC)load("glEnableIndexedEXT");
	glad_glDisableIndexedEXT = (PFNGLDISABLEINDEXEDEXTPROC)load("glDisableIndexedEXT");
	glad_glIsEnabledIndexedEXT = (PFNGLISENABLEDINDEXEDEXTPROC)load("glIsEnabledIndexedEXT");
	glad_glGetIntegerIndexedvEXT = (PFNGLGETINTEGERINDEXEDVEXTPROC)load("glGetIntegerIndexedvEXT");
	glad_glGetBooleanIndexedvEXT = (PFNGLGETBOOLEANINDEXEDVEXTPROC)load("glGetBooleanIndexedvEXT");
	glad_glCompressedTextureImage3DEXT = (PFNGLCOMPRESSEDTEXTUREIMAGE3DEXTPROC)load("glCompressedTextureImage3DEXT");
	glad_glCompressedTextureImage2DEXT = (PFNGLCOMPRESSEDTEXTUREIMAGE2DEXTPROC)load("glCompressedTextureImage2DEXT");
	glad_glCompressedTextureImage1DEXT = (PFNGLCOMPRESSEDTEXTUREIMAGE1DEXTPROC)load("glCompressedTextureImage1DEXT");
	glad_glCompressedTextureSubImage3DEXT = (PFNGLCOMPRESSEDTEXTURESUBIMAGE3DEXTPROC)load("glCompressedTextureSubImage3DEXT");
	glad_glCompressedTextureSubImage2DEXT = (PFNGLCOMPRESSEDTEXTURESUBIMAGE2DEXTPROC)load("glCompressedTextureSubImage2DEXT");
	glad_glCompressedTextureSubImage1DEXT = (PFNGLCOMPRESSEDTEXTURESUBIMAGE1DEXTPROC)load("glCompressedTextureSubImage1DEXT");
	glad_glGetCompressedTextureImageEXT = (PFNGLGETCOMPRESSEDTEXTUREIMAGEEXTPROC)load("glGetCompressedTextureImageEXT");
	glad_glCompressedMultiTexImage3DEXT = (PFNGLCOMPRESSEDMULTITEXIMAGE3DEXTPROC)load("glCompressedMultiTexImage3DEXT");
	glad_glCompressedMultiTexImage2DEXT = (PFNGLCOMPRESSEDMULTITEXIMAGE2DEXTPROC)load("glCompressedMultiTexImage2DEXT");
	glad_glCompressedMultiTexImage1DEXT = (PFNGLCOMPRESSEDMULTITEXIMAGE1DEXTPROC)load("glCompressedMultiTexImage1DEXT");
	glad_glCompressedMultiTexSubImage3DEXT = (PFNGLCOMPRESSEDMULTITEXSUBIMAGE3DEXTPROC)load("glCompressedMultiTexSubImage3DEXT");
	glad_glCompressedMultiTexSubImage2DEXT = (PFNGLCOMPRESSEDMULTITEXSUBIMAGE2DEXTPROC)load("glCompressedMultiTexSubImage2DEXT");
	glad_glCompressedMultiTexSubImage1DEXT = (PFNGLCOMPRESSEDMULTITEXSUBIMAGE1DEXTPROC)load("glCompressedMultiTexSubImage1DEXT");
	glad_glGetCompressedMultiTexImageEXT = (PFNGLGETCOMPRESSEDMULTITEXIMAGEEXTPROC)load("glGetCompressedMultiTexImageEXT");
	glad_glMatrixLoadTransposefEXT = (PFNGLMATRIXLOADTRANSPOSEFEXTPROC)load("glMatrixLoadTransposefEXT");
	glad_glMatrixLoadTransposedEXT = (PFNGLMATRIXLOADTRANSPOSEDEXTPROC)load("glMatrixLoadTransposedEXT");
	glad_glMatrixMultTransposefEXT = (PFNGLMATRIXMULTTRANSPOSEFEXTPROC)load("glMatrixMultTransposefEXT");
	glad_glMatrixMultTransposedEXT = (PFNGLMATRIXMULTTRANSPOSEDEXTPROC)load("glMatrixMultTransposedEXT");
	glad_glNamedBufferDataEXT = (PFNGLNAMEDBUFFERDATAEXTPROC)load("glNamedBufferDataEXT");
	glad_glNamedBufferSubDataEXT = (PFNGLNAMEDBUFFERSUBDATAEXTPROC)load("glNamedBufferSubDataEXT");
	glad_glMapNamedBufferEXT = (PFNGLMAPNAMEDBUFFEREXTPROC)load("glMapNamedBufferEXT");
	glad_glUnmapNamedBufferEXT = (PFNGLUNMAPNAMEDBUFFEREXTPROC)load("glUnmapNamedBufferEXT");
	glad_glGetNamedBufferParameterivEXT = (PFNGLGETNAMEDBUFFERPARAMETERIVEXTPROC)load("glGetNamedBufferParameterivEXT");
	glad_glGetNamedBufferPointervEXT = (PFNGLGETNAMEDBUFFERPOINTERVEXTPROC)load("glGetNamedBufferPointervEXT");
	glad_glGetNamedBufferSubDataEXT = (PFNGLGETNAMEDBUFFERSUBDATAEXTPROC)load("glGetNamedBufferSubDataEXT");
	glad_glProgramUniform1fEXT = (PFNGLPROGRAMUNIFORM1FEXTPROC)load("glProgramUniform1fEXT");
	glad_glProgramUniform2fEXT = (PFNGLPROGRAMUNIFORM2FEXTPROC)load("glProgramUniform2fEXT");
	glad_glProgramUniform3fEXT = (PFNGLPROGRAMUNIFORM3FEXTPROC)load("glProgramUniform3fEXT");
	glad_glProgramUniform4fEXT = (PFNGLPROGRAMUNIFORM4FEXTPROC)load("glProgramUniform4fEXT");
	glad_glProgramUniform1iEXT = (PFNGLPROGRAMUNIFORM1IEXTPROC)load("glProgramUniform1iEXT");
	glad_glProgramUniform2iEXT = (PFNGLPROGRAMUNIFORM2IEXTPROC)load("glProgramUniform2iEXT");
	glad_glProgramUniform3iEXT = (PFNGLPROGRAMUNIFORM3IEXTPROC)load("glProgramUniform3iEXT");
	glad_glProgramUniform4iEXT = (PFNGLPROGRAMUNIFORM4IEXTPROC)load("glProgramUniform4iEXT");
	glad_glProgramUniform1fvEXT = (PFNGLPROGRAMUNIFORM1FVEXTPROC)load("glProgramUniform1fvEXT");
	glad_glProgramUniform2fvEXT = (PFNGLPROGRAMUNIFORM2FVEXTPROC)load("glProgramUniform2fvEXT");
	glad_glProgramUniform3fvEXT = (PFNGLPROGRAMUNIFORM3FVEXTPROC)load("glProgramUniform3fvEXT");
	glad_glProgramUniform4fvEXT = (PFNGLPROGRAMUNIFORM4FVEXTPROC)load("glProgramUniform4fvEXT");
	glad_glProgramUniform1ivEXT = (PFNGLPROGRAMUNIFORM1IVEXTPROC)load("glProgramUniform1ivEXT");
	glad_glProgramUniform2ivEXT = (PFNGLPROGRAMUNIFORM2IVEXTPROC)load("glProgramUniform2ivEXT");
	glad_glProgramUniform3ivEXT = (PFNGLPROGRAMUNIFORM3IVEXTPROC)load("glProgramUniform3ivEXT");
	glad_glProgramUniform4ivEXT = (PFNGLPROGRAMUNIFORM4IVEXTPROC)load("glProgramUniform4ivEXT");
	glad_glProgramUniformMatrix2fvEXT = (PFNGLPROGRAMUNIFORMMATRIX2FVEXTPROC)load("glProgramUniformMatrix2fvEXT");
	glad_glProgramUniformMatrix3fvEXT = (PFNGLPROGRAMUNIFORMMATRIX3FVEXTPROC)load("glProgramUniformMatrix3fvEXT");
	glad_glProgramUniformMatrix4fvEXT = (PFNGLPROGRAMUNIFORMMATRIX4FVEXTPROC)load("glProgramUniformMatrix4fvEXT");
	glad_glProgramUniformMatrix2x3fvEXT = (PFNGLPROGRAMUNIFORMMATRIX2X3FVEXTPROC)load("glProgramUniformMatrix2x3fvEXT");
	glad_glProgramUniformMatrix3x2fvEXT = (PFNGLPROGRAMUNIFORMMATRIX3X2FVEXTPROC)load("glProgramUniformMatrix3x2fvEXT");
	glad_glProgramUniformMatrix2x4fvEXT = (PFNGLPROGRAMUNIFORMMATRIX2X4FVEXTPROC)load("glProgramUniformMatrix2x4fvEXT");
	glad_glProgramUniformMatrix4x2fvEXT = (PFNGLPROGRAMUNIFORMMATRIX4X2FVEXTPROC)load("glProgramUniformMatrix4x2fvEXT");
	glad_glProgramUniformMatrix3x4fvEXT = (PFNGLPROGRAMUNIFORMMATRIX3X4FVEXTPROC)load("glProgramUniformMatrix3x4fvEXT");
	glad_glProgramUniformMatrix4x3fvEXT = (PFNGLPROGRAMUNIFORMMATRIX4X3FVEXTPROC)load("glProgramUniformMatrix4x3fvEXT");
	glad_glTextureBufferEXT = (PFNGLTEXTUREBUFFEREXTPROC)load("glTextureBufferEXT");
	glad_glMultiTexBufferEXT = (PFNGLMULTITEXBUFFEREXTPROC)load("glMultiTexBufferEXT");
	glad_glTextureParameterIivEXT = (PFNGLTEXTUREPARAMETERIIVEXTPROC)load("glTextureParameterIivEXT");
	glad_glTextureParameterIuivEXT = (PFNGLTEXTUREPARAMETERIUIVEXTPROC)load("glTextureParameterIuivEXT");
	glad_glGetTextureParameterIivEXT = (PFNGLGETTEXTUREPARAMETERIIVEXTPROC)load("glGetTextureParameterIivEXT");
	glad_glGetTextureParameterIuivEXT = (PFNGLGETTEXTUREPARAMETERIUIVEXTPROC)load("glGetTextureParameterIuivEXT");
	glad_glMultiTexParameterIivEXT = (PFNGLMULTITEXPARAMETERIIVEXTPROC)load("glMultiTexParameterIivEXT");
	glad_glMultiTexParameterIuivEXT = (PFNGLMULTITEXPARAMETERIUIVEXTPROC)load("glMultiTexParameterIuivEXT");
	glad_glGetMultiTexParameterIivEXT = (PFNGLGETMULTITEXPARAMETERIIVEXTPROC)load("glGetMultiTexParameterIivEXT");
	glad_glGetMultiTexParameterIuivEXT = (PFNGLGETMULTITEXPARAMETERIUIVEXTPROC)load("glGetMultiTexParameterIuivEXT");
	glad_glProgramUniform1uiEXT = (PFNGLPROGRAMUNIFORM1UIEXTPROC)load("glProgramUniform1uiEXT");
	glad_glProgramUniform2uiEXT = (PFNGLPROGRAMUNIFORM2UIEXTPROC)load("glProgramUniform2uiEXT");
	glad_glProgramUniform3uiEXT = (PFNGLPROGRAMUNIFORM3UIEXTPROC)load("glProgramUniform3uiEXT");
	glad_glProgramUniform4uiEXT = (PFNGLPROGRAMUNIFORM4UIEXTPROC)load("glProgramUniform4uiEXT");
	glad_glProgramUniform1uivEXT = (PFNGLPROGRAMUNIFORM1UIVEXTPROC)load("glProgramUniform1uivEXT");
	glad_glProgramUniform2uivEXT = (PFNGLPROGRAMUNIFORM2UIVEXTPROC)load("glProgramUniform2uivEXT");
	glad_glProgramUniform3uivEXT = (PFNGLPROGRAMUNIFORM3UIVEXTPROC)load("glProgramUniform3uivEXT");
	glad_glProgramUniform4uivEXT = (PFNGLPROGRAMUNIFORM4UIVEXTPROC)load("glProgramUniform4uivEXT");
	glad_glNamedProgramLocalParameters4fvEXT = (PFNGLNAMEDPROGRAMLOCALPARAMETERS4FVEXTPROC)load("glNamedProgramLocalParameters4fvEXT");
	glad_glNamedProgramLocalParameterI4iEXT = (PFNGLNAMEDPROGRAMLOCALPARAMETERI4IEXTPROC)load("glNamedProgramLocalParameterI4iEXT");
	glad_glNamedProgramLocalParameterI4ivEXT = (PFNGLNAMEDPROGRAMLOCALPARAMETERI4IVEXTPROC)load("glNamedProgramLocalParameterI4ivEXT");
	glad_glNamedProgramLocalParametersI4ivEXT = (PFNGLNAMEDPROGRAMLOCALPARAMETERSI4IVEXTPROC)load("glNamedProgramLocalParametersI4ivEXT");
	glad_glNamedProgramLocalParameterI4uiEXT = (PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIEXTPROC)load("glNamedProgramLocalParameterI4uiEXT");
	glad_glNamedProgramLocalParameterI4uivEXT = (PFNGLNAMEDPROGRAMLOCALPARAMETERI4UIVEXTPROC)load("glNamedProgramLocalParameterI4uivEXT");
	glad_glNamedProgramLocalParametersI4uivEXT = (PFNGLNAMEDPROGRAMLOCALPARAMETERSI4UIVEXTPROC)load("glNamedProgramLocalParametersI4uivEXT");
	glad_glGetNamedProgramLocalParameterIivEXT = (PFNGLGETNAMEDPROGRAMLOCALPARAMETERIIVEXTPROC)load("glGetNamedProgramLocalParameterIivEXT");
	glad_glGetNamedProgramLocalParameterIuivEXT = (PFNGLGETNAMEDPROGRAMLOCALPARAMETERIUIVEXTPROC)load("glGetNamedProgramLocalParameterIuivEXT");
	glad_glEnableClientStateiEXT = (PFNGLENABLECLIENTSTATEIEXTPROC)load("glEnableClientStateiEXT");
	glad_glDisableClientStateiEXT = (PFNGLDISABLECLIENTSTATEIEXTPROC)load("glDisableClientStateiEXT");
	glad_glGetFloati_vEXT = (PFNGLGETFLOATI_VEXTPROC)load("glGetFloati_vEXT");
	glad_glGetDoublei_vEXT = (PFNGLGETDOUBLEI_VEXTPROC)load("glGetDoublei_vEXT");
	glad_glGetPointeri_vEXT = (PFNGLGETPOINTERI_VEXTPROC)load("glGetPointeri_vEXT");
	glad_glNamedProgramStringEXT = (PFNGLNAMEDPROGRAMSTRINGEXTPROC)load("glNamedProgramStringEXT");
	glad_glNamedProgramLocalParameter4dEXT = (PFNGLNAMEDPROGRAMLOCALPARAMETER4DEXTPROC)load("glNamedProgramLocalParameter4dEXT");
	glad_glNamedProgramLocalParameter4dvEXT = (PFNGLNAMEDPROGRAMLOCALPARAMETER4DVEXTPROC)load("glNamedProgramLocalParameter4dvEXT");
	glad_glNamedProgramLocalParameter4fEXT = (PFNGLNAMEDPROGRAMLOCALPARAMETER4FEXTPROC)load("glNamedProgramLocalParameter4fEXT");
	glad_glNamedProgramLocalParameter4fvEXT = (PFNGLNAMEDPROGRAMLOCALPARAMETER4FVEXTPROC)load("glNamedProgramLocalParameter4fvEXT");
	glad_glGetNamedProgramLocalParameterdvEXT = (PFNGLGETNAMEDPROGRAMLOCALPARAMETERDVEXTPROC)load("glGetNamedProgramLocalParameterdvEXT");
	glad_glGetNamedProgramLocalParameterfvEXT = (PFNGLGETNAMEDPROGRAMLOCALPARAMETERFVEXTPROC)load("glGetNamedProgramLocalParameterfvEXT");
	glad_glGetNamedProgramivEXT = (PFNGLGETNAMEDPROGRAMIVEXTPROC)load("glGetNamedProgramivEXT");
	glad_glGetNamedProgramStringEXT = (PFNGLGETNAMEDPROGRAMSTRINGEXTPROC)load("glGetNamedProgramStringEXT");
	glad_glNamedRenderbufferStorageEXT = (PFNGLNAMEDRENDERBUFFERSTORAGEEXTPROC)load("glNamedRenderbufferStorageEXT");
	glad_glGetNamedRenderbufferParameterivEXT = (PFNGLGETNAMEDRENDERBUFFERPARAMETERIVEXTPROC)load("glGetNamedRenderbufferParameterivEXT");
	glad_glNamedRenderbufferStorageMultisampleEXT = (PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC)load("glNamedRenderbufferStorageMultisampleEXT");
	glad_glNamedRenderbufferStorageMultisampleCoverageEXT = (PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLECOVERAGEEXTPROC)load("glNamedRenderbufferStorageMultisampleCoverageEXT");
	glad_glCheckNamedFramebufferStatusEXT = (PFNGLCHECKNAMEDFRAMEBUFFERSTATUSEXTPROC)load("glCheckNamedFramebufferStatusEXT");
	glad_glNamedFramebufferTexture1DEXT = (PFNGLNAMEDFRAMEBUFFERTEXTURE1DEXTPROC)load("glNamedFramebufferTexture1DEXT");
	glad_glNamedFramebufferTexture2DEXT = (PFNGLNAMEDFRAMEBUFFERTEXTURE2DEXTPROC)load("glNamedFramebufferTexture2DEXT");
	glad_glNamedFramebufferTexture3DEXT = (PFNGLNAMEDFRAMEBUFFERTEXTURE3DEXTPROC)load("glNamedFramebufferTexture3DEXT");
	glad_glNamedFramebufferRenderbufferEXT = (PFNGLNAMEDFRAMEBUFFERRENDERBUFFEREXTPROC)load("glNamedFramebufferRenderbufferEXT");
	glad_glGetNamedFramebufferAttachmentParameterivEXT = (PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC)load("glGetNamedFramebufferAttachmentParameterivEXT");
	glad_glGenerateTextureMipmapEXT = (PFNGLGENERATETEXTUREMIPMAPEXTPROC)load("glGenerateTextureMipmapEXT");
	glad_glGenerateMultiTexMipmapEXT = (PFNGLGENERATEMULTITEXMIPMAPEXTPROC)load("glGenerateMultiTexMipmapEXT");
	glad_glFramebufferDrawBufferEXT = (PFNGLFRAMEBUFFERDRAWBUFFEREXTPROC)load("glFramebufferDrawBufferEXT");
	glad_glFramebufferDrawBuffersEXT = (PFNGLFRAMEBUFFERDRAWBUFFERSEXTPROC)load("glFramebufferDrawBuffersEXT");
	glad_glFramebufferReadBufferEXT = (PFNGLFRAMEBUFFERREADBUFFEREXTPROC)load("glFramebufferReadBufferEXT");
	glad_glGetFramebufferParameterivEXT = (PFNGLGETFRAMEBUFFERPARAMETERIVEXTPROC)load("glGetFramebufferParameterivEXT");
	glad_glNamedCopyBufferSubDataEXT = (PFNGLNAMEDCOPYBUFFERSUBDATAEXTPROC)load("glNamedCopyBufferSubDataEXT");
	glad_glNamedFramebufferTextureEXT = (PFNGLNAMEDFRAMEBUFFERTEXTUREEXTPROC)load("glNamedFramebufferTextureEXT");
	glad_glNamedFramebufferTextureLayerEXT = (PFNGLNAMEDFRAMEBUFFERTEXTURELAYEREXTPROC)load("glNamedFramebufferTextureLayerEXT");
	glad_glNamedFramebufferTextureFaceEXT = (PFNGLNAMEDFRAMEBUFFERTEXTUREFACEEXTPROC)load("glNamedFramebufferTextureFaceEXT");
	glad_glTextureRenderbufferEXT = (PFNGLTEXTURERENDERBUFFEREXTPROC)load("glTextureRenderbufferEXT");
	glad_glMultiTexRenderbufferEXT = (PFNGLMULTITEXRENDERBUFFEREXTPROC)load("glMultiTexRenderbufferEXT");
	glad_glVertexArrayVertexOffsetEXT = (PFNGLVERTEXARRAYVERTEXOFFSETEXTPROC)load("glVertexArrayVertexOffsetEXT");
	glad_glVertexArrayColorOffsetEXT = (PFNGLVERTEXARRAYCOLOROFFSETEXTPROC)load("glVertexArrayColorOffsetEXT");
	glad_glVertexArrayEdgeFlagOffsetEXT = (PFNGLVERTEXARRAYEDGEFLAGOFFSETEXTPROC)load("glVertexArrayEdgeFlagOffsetEXT");
	glad_glVertexArrayIndexOffsetEXT = (PFNGLVERTEXARRAYINDEXOFFSETEXTPROC)load("glVertexArrayIndexOffsetEXT");
	glad_glVertexArrayNormalOffsetEXT = (PFNGLVERTEXARRAYNORMALOFFSETEXTPROC)load("glVertexArrayNormalOffsetEXT");
	glad_glVertexArrayTexCoordOffsetEXT = (PFNGLVERTEXARRAYTEXCOORDOFFSETEXTPROC)load("glVertexArrayTexCoordOffsetEXT");
	glad_glVertexArrayMultiTexCoordOffsetEXT = (PFNGLVERTEXARRAYMULTITEXCOORDOFFSETEXTPROC)load("glVertexArrayMultiTexCoordOffsetEXT");
	glad_glVertexArrayFogCoordOffsetEXT = (PFNGLVERTEXARRAYFOGCOORDOFFSETEXTPROC)load("glVertexArrayFogCoordOffsetEXT");
	glad_glVertexArraySecondaryColorOffsetEXT = (PFNGLVERTEXARRAYSECONDARYCOLOROFFSETEXTPROC)load("glVertexArraySecondaryColorOffsetEXT");
	glad_glVertexArrayVertexAttribOffsetEXT = (PFNGLVERTEXARRAYVERTEXATTRIBOFFSETEXTPROC)load("glVertexArrayVertexAttribOffsetEXT");
	glad_glVertexArrayVertexAttribIOffsetEXT = (PFNGLVERTEXARRAYVERTEXATTRIBIOFFSETEXTPROC)load("glVertexArrayVertexAttribIOffsetEXT");
	glad_glEnableVertexArrayEXT = (PFNGLENABLEVERTEXARRAYEXTPROC)load("glEnableVertexArrayEXT");
	glad_glDisableVertexArrayEXT = (PFNGLDISABLEVERTEXARRAYEXTPROC)load("glDisableVertexArrayEXT");
	glad_glEnableVertexArrayAttribEXT = (PFNGLENABLEVERTEXARRAYATTRIBEXTPROC)load("glEnableVertexArrayAttribEXT");
	glad_glDisableVertexArrayAttribEXT = (PFNGLDISABLEVERTEXARRAYATTRIBEXTPROC)load("glDisableVertexArrayAttribEXT");
	glad_glGetVertexArrayIntegervEXT = (PFNGLGETVERTEXARRAYINTEGERVEXTPROC)load("glGetVertexArrayIntegervEXT");
	glad_glGetVertexArrayPointervEXT = (PFNGLGETVERTEXARRAYPOINTERVEXTPROC)load("glGetVertexArrayPointervEXT");
	glad_glGetVertexArrayIntegeri_vEXT = (PFNGLGETVERTEXARRAYINTEGERI_VEXTPROC)load("glGetVertexArrayIntegeri_vEXT");
	glad_glGetVertexArrayPointeri_vEXT = (PFNGLGETVERTEXARRAYPOINTERI_VEXTPROC)load("glGetVertexArrayPointeri_vEXT");
	glad_glMapNamedBufferRangeEXT = (PFNGLMAPNAMEDBUFFERRANGEEXTPROC)load("glMapNamedBufferRangeEXT");
	glad_glFlushMappedNamedBufferRangeEXT = (PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEEXTPROC)load("glFlushMappedNamedBufferRangeEXT");
	glad_glNamedBufferStorageEXT = (PFNGLNAMEDBUFFERSTORAGEEXTPROC)load("glNamedBufferStorageEXT");
	glad_glClearNamedBufferDataEXT = (PFNGLCLEARNAMEDBUFFERDATAEXTPROC)load("glClearNamedBufferDataEXT");
	glad_glClearNamedBufferSubDataEXT = (PFNGLCLEARNAMEDBUFFERSUBDATAEXTPROC)load("glClearNamedBufferSubDataEXT");
	glad_glNamedFramebufferParameteriEXT = (PFNGLNAMEDFRAMEBUFFERPARAMETERIEXTPROC)load("glNamedFramebufferParameteriEXT");
	glad_glGetNamedFramebufferParameterivEXT = (PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVEXTPROC)load("glGetNamedFramebufferParameterivEXT");
	glad_glProgramUniform1dEXT = (PFNGLPROGRAMUNIFORM1DEXTPROC)load("glProgramUniform1dEXT");
	glad_glProgramUniform2dEXT = (PFNGLPROGRAMUNIFORM2DEXTPROC)load("glProgramUniform2dEXT");
	glad_glProgramUniform3dEXT = (PFNGLPROGRAMUNIFORM3DEXTPROC)load("glProgramUniform3dEXT");
	glad_glProgramUniform4dEXT = (PFNGLPROGRAMUNIFORM4DEXTPROC)load("glProgramUniform4dEXT");
	glad_glProgramUniform1dvEXT = (PFNGLPROGRAMUNIFORM1DVEXTPROC)load("glProgramUniform1dvEXT");
	glad_glProgramUniform2dvEXT = (PFNGLPROGRAMUNIFORM2DVEXTPROC)load("glProgramUniform2dvEXT");
	glad_glProgramUniform3dvEXT = (PFNGLPROGRAMUNIFORM3DVEXTPROC)load("glProgramUniform3dvEXT");
	glad_glProgramUniform4dvEXT = (PFNGLPROGRAMUNIFORM4DVEXTPROC)load("glProgramUniform4dvEXT");
	glad_glProgramUniformMatrix2dvEXT = (PFNGLPROGRAMUNIFORMMATRIX2DVEXTPROC)load("glProgramUniformMatrix2dvEXT");
	glad_glProgramUniformMatrix3dvEXT = (PFNGLPROGRAMUNIFORMMATRIX3DVEXTPROC)load("glProgramUniformMatrix3dvEXT");
	glad_glProgramUniformMatrix4dvEXT = (PFNGLPROGRAMUNIFORMMATRIX4DVEXTPROC)load("glProgramUniformMatrix4dvEXT");
	glad_glProgramUniformMatrix2x3dvEXT = (PFNGLPROGRAMUNIFORMMATRIX2X3DVEXTPROC)load("glProgramUniformMatrix2x3dvEXT");
	glad_glProgramUniformMatrix2x4dvEXT = (PFNGLPROGRAMUNIFORMMATRIX2X4DVEXTPROC)load("glProgramUniformMatrix2x4dvEXT");
	glad_glProgramUniformMatrix3x2dvEXT = (PFNGLPROGRAMUNIFORMMATRIX3X2DVEXTPROC)load("glProgramUniformMatrix3x2dvEXT");
	glad_glProgramUniformMatrix3x4dvEXT = (PFNGLPROGRAMUNIFORMMATRIX3X4DVEXTPROC)load("glProgramUniformMatrix3x4dvEXT");
	glad_glProgramUniformMatrix4x2dvEXT = (PFNGLPROGRAMUNIFORMMATRIX4X2DVEXTPROC)load("glProgramUniformMatrix4x2dvEXT");
	glad_glProgramUniformMatrix4x3dvEXT = (PFNGLPROGRAMUNIFORMMATRIX4X3DVEXTPROC)load("glProgramUniformMatrix4x3dvEXT");
	glad_glTextureBufferRangeEXT = (PFNGLTEXTUREBUFFERRANGEEXTPROC)load("glTextureBufferRangeEXT");
	glad_glTextureStorage1DEXT = (PFNGLTEXTURESTORAGE1DEXTPROC)load("glTextureStorage1DEXT");
	glad_glTextureStorage2DEXT = (PFNGLTEXTURESTORAGE2DEXTPROC)load("glTextureStorage2DEXT");
	glad_glTextureStorage3DEXT = (PFNGLTEXTURESTORAGE3DEXTPROC)load("glTextureStorage3DEXT");
	glad_glTextureStorage2DMultisampleEXT = (PFNGLTEXTURESTORAGE2DMULTISAMPLEEXTPROC)load("glTextureStorage2DMultisampleEXT");
	glad_glTextureStorage3DMultisampleEXT = (PFNGLTEXTURESTORAGE3DMULTISAMPLEEXTPROC)load("glTextureStorage3DMultisampleEXT");
	glad_glVertexArrayBindVertexBufferEXT = (PFNGLVERTEXARRAYBINDVERTEXBUFFEREXTPROC)load("glVertexArrayBindVertexBufferEXT");
	glad_glVertexArrayVertexAttribFormatEXT = (PFNGLVERTEXARRAYVERTEXATTRIBFORMATEXTPROC)load("glVertexArrayVertexAttribFormatEXT");
	glad_glVertexArrayVertexAttribIFormatEXT = (PFNGLVERTEXARRAYVERTEXATTRIBIFORMATEXTPROC)load("glVertexArrayVertexAttribIFormatEXT");
	glad_glVertexArrayVertexAttribLFormatEXT = (PFNGLVERTEXARRAYVERTEXATTRIBLFORMATEXTPROC)load("glVertexArrayVertexAttribLFormatEXT");
	glad_glVertexArrayVertexAttribBindingEXT = (PFNGLVERTEXARRAYVERTEXATTRIBBINDINGEXTPROC)load("glVertexArrayVertexAttribBindingEXT");
	glad_glVertexArrayVertexBindingDivisorEXT = (PFNGLVERTEXARRAYVERTEXBINDINGDIVISOREXTPROC)load("glVertexArrayVertexBindingDivisorEXT");
	glad_glVertexArrayVertexAttribLOffsetEXT = (PFNGLVERTEXARRAYVERTEXATTRIBLOFFSETEXTPROC)load("glVertexArrayVertexAttribLOffsetEXT");
	glad_glTexturePageCommitmentEXT = (PFNGLTEXTUREPAGECOMMITMENTEXTPROC)load("glTexturePageCommitmentEXT");
	glad_glVertexArrayVertexAttribDivisorEXT = (PFNGLVERTEXARRAYVERTEXATTRIBDIVISOREXTPROC)load("glVertexArrayVertexAttribDivisorEXT");
}
static void load_GL_AMD_sample_positions(GLADloadproc load) {
	if (!GLAD_GL_AMD_sample_positions) return;
	glad_glSetMultisamplefvAMD = (PFNGLSETMULTISAMPLEFVAMDPROC)load("glSetMultisamplefvAMD");
}
static void load_GL_NV_vertex_program(GLADloadproc load) {
	if (!GLAD_GL_NV_vertex_program) return;
	glad_glAreProgramsResidentNV = (PFNGLAREPROGRAMSRESIDENTNVPROC)load("glAreProgramsResidentNV");
	glad_glBindProgramNV = (PFNGLBINDPROGRAMNVPROC)load("glBindProgramNV");
	glad_glDeleteProgramsNV = (PFNGLDELETEPROGRAMSNVPROC)load("glDeleteProgramsNV");
	glad_glExecuteProgramNV = (PFNGLEXECUTEPROGRAMNVPROC)load("glExecuteProgramNV");
	glad_glGenProgramsNV = (PFNGLGENPROGRAMSNVPROC)load("glGenProgramsNV");
	glad_glGetProgramParameterdvNV = (PFNGLGETPROGRAMPARAMETERDVNVPROC)load("glGetProgramParameterdvNV");
	glad_glGetProgramParameterfvNV = (PFNGLGETPROGRAMPARAMETERFVNVPROC)load("glGetProgramParameterfvNV");
	glad_glGetProgramivNV = (PFNGLGETPROGRAMIVNVPROC)load("glGetProgramivNV");
	glad_glGetProgramStringNV = (PFNGLGETPROGRAMSTRINGNVPROC)load("glGetProgramStringNV");
	glad_glGetTrackMatrixivNV = (PFNGLGETTRACKMATRIXIVNVPROC)load("glGetTrackMatrixivNV");
	glad_glGetVertexAttribdvNV = (PFNGLGETVERTEXATTRIBDVNVPROC)load("glGetVertexAttribdvNV");
	glad_glGetVertexAttribfvNV = (PFNGLGETVERTEXATTRIBFVNVPROC)load("glGetVertexAttribfvNV");
	glad_glGetVertexAttribivNV = (PFNGLGETVERTEXATTRIBIVNVPROC)load("glGetVertexAttribivNV");
	glad_glGetVertexAttribPointervNV = (PFNGLGETVERTEXATTRIBPOINTERVNVPROC)load("glGetVertexAttribPointervNV");
	glad_glIsProgramNV = (PFNGLISPROGRAMNVPROC)load("glIsProgramNV");
	glad_glLoadProgramNV = (PFNGLLOADPROGRAMNVPROC)load("glLoadProgramNV");
	glad_glProgramParameter4dNV = (PFNGLPROGRAMPARAMETER4DNVPROC)load("glProgramParameter4dNV");
	glad_glProgramParameter4dvNV = (PFNGLPROGRAMPARAMETER4DVNVPROC)load("glProgramParameter4dvNV");
	glad_glProgramParameter4fNV = (PFNGLPROGRAMPARAMETER4FNVPROC)load("glProgramParameter4fNV");
	glad_glProgramParameter4fvNV = (PFNGLPROGRAMPARAMETER4FVNVPROC)load("glProgramParameter4fvNV");
	glad_glProgramParameters4dvNV = (PFNGLPROGRAMPARAMETERS4DVNVPROC)load("glProgramParameters4dvNV");
	glad_glProgramParameters4fvNV = (PFNGLPROGRAMPARAMETERS4FVNVPROC)load("glProgramParameters4fvNV");
	glad_glRequestResidentProgramsNV = (PFNGLREQUESTRESIDENTPROGRAMSNVPROC)load("glRequestResidentProgramsNV");
	glad_glTrackMatrixNV = (PFNGLTRACKMATRIXNVPROC)load("glTrackMatrixNV");
	glad_glVertexAttribPointerNV = (PFNGLVERTEXATTRIBPOINTERNVPROC)load("glVertexAttribPointerNV");
	glad_glVertexAttrib1dNV = (PFNGLVERTEXATTRIB1DNVPROC)load("glVertexAttrib1dNV");
	glad_glVertexAttrib1dvNV = (PFNGLVERTEXATTRIB1DVNVPROC)load("glVertexAttrib1dvNV");
	glad_glVertexAttrib1fNV = (PFNGLVERTEXATTRIB1FNVPROC)load("glVertexAttrib1fNV");
	glad_glVertexAttrib1fvNV = (PFNGLVERTEXATTRIB1FVNVPROC)load("glVertexAttrib1fvNV");
	glad_glVertexAttrib1sNV = (PFNGLVERTEXATTRIB1SNVPROC)load("glVertexAttrib1sNV");
	glad_glVertexAttrib1svNV = (PFNGLVERTEXATTRIB1SVNVPROC)load("glVertexAttrib1svNV");
	glad_glVertexAttrib2dNV = (PFNGLVERTEXATTRIB2DNVPROC)load("glVertexAttrib2dNV");
	glad_glVertexAttrib2dvNV = (PFNGLVERTEXATTRIB2DVNVPROC)load("glVertexAttrib2dvNV");
	glad_glVertexAttrib2fNV = (PFNGLVERTEXATTRIB2FNVPROC)load("glVertexAttrib2fNV");
	glad_glVertexAttrib2fvNV = (PFNGLVERTEXATTRIB2FVNVPROC)load("glVertexAttrib2fvNV");
	glad_glVertexAttrib2sNV = (PFNGLVERTEXATTRIB2SNVPROC)load("glVertexAttrib2sNV");
	glad_glVertexAttrib2svNV = (PFNGLVERTEXATTRIB2SVNVPROC)load("glVertexAttrib2svNV");
	glad_glVertexAttrib3dNV = (PFNGLVERTEXATTRIB3DNVPROC)load("glVertexAttrib3dNV");
	glad_glVertexAttrib3dvNV = (PFNGLVERTEXATTRIB3DVNVPROC)load("glVertexAttrib3dvNV");
	glad_glVertexAttrib3fNV = (PFNGLVERTEXATTRIB3FNVPROC)load("glVertexAttrib3fNV");
	glad_glVertexAttrib3fvNV = (PFNGLVERTEXATTRIB3FVNVPROC)load("glVertexAttrib3fvNV");
	glad_glVertexAttrib3sNV = (PFNGLVERTEXATTRIB3SNVPROC)load("glVertexAttrib3sNV");
	glad_glVertexAttrib3svNV = (PFNGLVERTEXATTRIB3SVNVPROC)load("glVertexAttrib3svNV");
	glad_glVertexAttrib4dNV = (PFNGLVERTEXATTRIB4DNVPROC)load("glVertexAttrib4dNV");
	glad_glVertexAttrib4dvNV = (PFNGLVERTEXATTRIB4DVNVPROC)load("glVertexAttrib4dvNV");
	glad_glVertexAttrib4fNV = (PFNGLVERTEXATTRIB4FNVPROC)load("glVertexAttrib4fNV");
	glad_glVertexAttrib4fvNV = (PFNGLVERTEXATTRIB4FVNVPROC)load("glVertexAttrib4fvNV");
	glad_glVertexAttrib4sNV = (PFNGLVERTEXATTRIB4SNVPROC)load("glVertexAttrib4sNV");
	glad_glVertexAttrib4svNV = (PFNGLVERTEXATTRIB4SVNVPROC)load("glVertexAttrib4svNV");
	glad_glVertexAttrib4ubNV = (PFNGLVERTEXATTRIB4UBNVPROC)load("glVertexAttrib4ubNV");
	glad_glVertexAttrib4ubvNV = (PFNGLVERTEXATTRIB4UBVNVPROC)load("glVertexAttrib4ubvNV");
	glad_glVertexAttribs1dvNV = (PFNGLVERTEXATTRIBS1DVNVPROC)load("glVertexAttribs1dvNV");
	glad_glVertexAttribs1fvNV = (PFNGLVERTEXATTRIBS1FVNVPROC)load("glVertexAttribs1fvNV");
	glad_glVertexAttribs1svNV = (PFNGLVERTEXATTRIBS1SVNVPROC)load("glVertexAttribs1svNV");
	glad_glVertexAttribs2dvNV = (PFNGLVERTEXATTRIBS2DVNVPROC)load("glVertexAttribs2dvNV");
	glad_glVertexAttribs2fvNV = (PFNGLVERTEXATTRIBS2FVNVPROC)load("glVertexAttribs2fvNV");
	glad_glVertexAttribs2svNV = (PFNGLVERTEXATTRIBS2SVNVPROC)load("glVertexAttribs2svNV");
	glad_glVertexAttribs3dvNV = (PFNGLVERTEXATTRIBS3DVNVPROC)load("glVertexAttribs3dvNV");
	glad_glVertexAttribs3fvNV = (PFNGLVERTEXATTRIBS3FVNVPROC)load("glVertexAttribs3fvNV");
	glad_glVertexAttribs3svNV = (PFNGLVERTEXATTRIBS3SVNVPROC)load("glVertexAttribs3svNV");
	glad_glVertexAttribs4dvNV = (PFNGLVERTEXATTRIBS4DVNVPROC)load("glVertexAttribs4dvNV");
	glad_glVertexAttribs4fvNV = (PFNGLVERTEXATTRIBS4FVNVPROC)load("glVertexAttribs4fvNV");
	glad_glVertexAttribs4svNV = (PFNGLVERTEXATTRIBS4SVNVPROC)load("glVertexAttribs4svNV");
	glad_glVertexAttribs4ubvNV = (PFNGLVERTEXATTRIBS4UBVNVPROC)load("glVertexAttribs4ubvNV");
}
static void load_GL_EXT_vertex_shader(GLADloadproc load) {
	if (!GLAD_GL_EXT_vertex_shader) return;
	glad_glBeginVertexShaderEXT = (PFNGLBEGINVERTEXSHADEREXTPROC)load("glBeginVertexShaderEXT");
	glad_glEndVertexShaderEXT = (PFNGLENDVERTEXSHADEREXTPROC)load("glEndVertexShaderEXT");
	glad_glBindVertexShaderEXT = (PFNGLBINDVERTEXSHADEREXTPROC)load("glBindVertexShaderEXT");
	glad_glGenVertexShadersEXT = (PFNGLGENVERTEXSHADERSEXTPROC)load("glGenVertexShadersEXT");
	glad_glDeleteVertexShaderEXT = (PFNGLDELETEVERTEXSHADEREXTPROC)load("glDeleteVertexShaderEXT");
	glad_glShaderOp1EXT = (PFNGLSHADEROP1EXTPROC)load("glShaderOp1EXT");
	glad_glShaderOp2EXT = (PFNGLSHADEROP2EXTPROC)load("glShaderOp2EXT");
	glad_glShaderOp3EXT = (PFNGLSHADEROP3EXTPROC)load("glShaderOp3EXT");
	glad_glSwizzleEXT = (PFNGLSWIZZLEEXTPROC)load("glSwizzleEXT");
	glad_glWriteMaskEXT = (PFNGLWRITEMASKEXTPROC)load("glWriteMaskEXT");
	glad_glInsertComponentEXT = (PFNGLINSERTCOMPONENTEXTPROC)load("glInsertComponentEXT");
	glad_glExtractComponentEXT = (PFNGLEXTRACTCOMPONENTEXTPROC)load("glExtractComponentEXT");
	glad_glGenSymbolsEXT = (PFNGLGENSYMBOLSEXTPROC)load("glGenSymbolsEXT");
	glad_glSetInvariantEXT = (PFNGLSETINVARIANTEXTPROC)load("glSetInvariantEXT");
	glad_glSetLocalConstantEXT = (PFNGLSETLOCALCONSTANTEXTPROC)load("glSetLocalConstantEXT");
	glad_glVariantbvEXT = (PFNGLVARIANTBVEXTPROC)load("glVariantbvEXT");
	glad_glVariantsvEXT = (PFNGLVARIANTSVEXTPROC)load("glVariantsvEXT");
	glad_glVariantivEXT = (PFNGLVARIANTIVEXTPROC)load("glVariantivEXT");
	glad_glVariantfvEXT = (PFNGLVARIANTFVEXTPROC)load("glVariantfvEXT");
	glad_glVariantdvEXT = (PFNGLVARIANTDVEXTPROC)load("glVariantdvEXT");
	glad_glVariantubvEXT = (PFNGLVARIANTUBVEXTPROC)load("glVariantubvEXT");
	glad_glVariantusvEXT = (PFNGLVARIANTUSVEXTPROC)load("glVariantusvEXT");
	glad_glVariantuivEXT = (PFNGLVARIANTUIVEXTPROC)load("glVariantuivEXT");
	glad_glVariantPointerEXT = (PFNGLVARIANTPOINTEREXTPROC)load("glVariantPointerEXT");
	glad_glEnableVariantClientStateEXT = (PFNGLENABLEVARIANTCLIENTSTATEEXTPROC)load("glEnableVariantClientStateEXT");
	glad_glDisableVariantClientStateEXT = (PFNGLDISABLEVARIANTCLIENTSTATEEXTPROC)load("glDisableVariantClientStateEXT");
	glad_glBindLightParameterEXT = (PFNGLBINDLIGHTPARAMETEREXTPROC)load("glBindLightParameterEXT");
	glad_glBindMaterialParameterEXT = (PFNGLBINDMATERIALPARAMETEREXTPROC)load("glBindMaterialParameterEXT");
	glad_glBindTexGenParameterEXT = (PFNGLBINDTEXGENPARAMETEREXTPROC)load("glBindTexGenParameterEXT");
	glad_glBindTextureUnitParameterEXT = (PFNGLBINDTEXTUREUNITPARAMETEREXTPROC)load("glBindTextureUnitParameterEXT");
	glad_glBindParameterEXT = (PFNGLBINDPARAMETEREXTPROC)load("glBindParameterEXT");
	glad_glIsVariantEnabledEXT = (PFNGLISVARIANTENABLEDEXTPROC)load("glIsVariantEnabledEXT");
	glad_glGetVariantBooleanvEXT = (PFNGLGETVARIANTBOOLEANVEXTPROC)load("glGetVariantBooleanvEXT");
	glad_glGetVariantIntegervEXT = (PFNGLGETVARIANTINTEGERVEXTPROC)load("glGetVariantIntegervEXT");
	glad_glGetVariantFloatvEXT = (PFNGLGETVARIANTFLOATVEXTPROC)load("glGetVariantFloatvEXT");
	glad_glGetVariantPointervEXT = (PFNGLGETVARIANTPOINTERVEXTPROC)load("glGetVariantPointervEXT");
	glad_glGetInvariantBooleanvEXT = (PFNGLGETINVARIANTBOOLEANVEXTPROC)load("glGetInvariantBooleanvEXT");
	glad_glGetInvariantIntegervEXT = (PFNGLGETINVARIANTINTEGERVEXTPROC)load("glGetInvariantIntegervEXT");
	glad_glGetInvariantFloatvEXT = (PFNGLGETINVARIANTFLOATVEXTPROC)load("glGetInvariantFloatvEXT");
	glad_glGetLocalConstantBooleanvEXT = (PFNGLGETLOCALCONSTANTBOOLEANVEXTPROC)load("glGetLocalConstantBooleanvEXT");
	glad_glGetLocalConstantIntegervEXT = (PFNGLGETLOCALCONSTANTINTEGERVEXTPROC)load("glGetLocalConstantIntegervEXT");
	glad_glGetLocalConstantFloatvEXT = (PFNGLGETLOCALCONSTANTFLOATVEXTPROC)load("glGetLocalConstantFloatvEXT");
}
static void load_GL_EXT_blend_func_separate(GLADloadproc load) {
	if (!GLAD_GL_EXT_blend_func_separate) return;
	glad_glBlendFuncSeparateEXT = (PFNGLBLENDFUNCSEPARATEEXTPROC)load("glBlendFuncSeparateEXT");
}
static void load_GL_APPLE_fence(GLADloadproc load) {
	if (!GLAD_GL_APPLE_fence) return;
	glad_glGenFencesAPPLE = (PFNGLGENFENCESAPPLEPROC)load("glGenFencesAPPLE");
	glad_glDeleteFencesAPPLE = (PFNGLDELETEFENCESAPPLEPROC)load("glDeleteFencesAPPLE");
	glad_glSetFenceAPPLE = (PFNGLSETFENCEAPPLEPROC)load("glSetFenceAPPLE");
	glad_glIsFenceAPPLE = (PFNGLISFENCEAPPLEPROC)load("glIsFenceAPPLE");
	glad_glTestFenceAPPLE = (PFNGLTESTFENCEAPPLEPROC)load("glTestFenceAPPLE");
	glad_glFinishFenceAPPLE = (PFNGLFINISHFENCEAPPLEPROC)load("glFinishFenceAPPLE");
	glad_glTestObjectAPPLE = (PFNGLTESTOBJECTAPPLEPROC)load("glTestObjectAPPLE");
	glad_glFinishObjectAPPLE = (PFNGLFINISHOBJECTAPPLEPROC)load("glFinishObjectAPPLE");
}
static void load_GL_OES_byte_coordinates(GLADloadproc load) {
	if (!GLAD_GL_OES_byte_coordinates) return;
	glad_glMultiTexCoord1bOES = (PFNGLMULTITEXCOORD1BOESPROC)load("glMultiTexCoord1bOES");
	glad_glMultiTexCoord1bvOES = (PFNGLMULTITEXCOORD1BVOESPROC)load("glMultiTexCoord1bvOES");
	glad_glMultiTexCoord2bOES = (PFNGLMULTITEXCOORD2BOESPROC)load("glMultiTexCoord2bOES");
	glad_glMultiTexCoord2bvOES = (PFNGLMULTITEXCOORD2BVOESPROC)load("glMultiTexCoord2bvOES");
	glad_glMultiTexCoord3bOES = (PFNGLMULTITEXCOORD3BOESPROC)load("glMultiTexCoord3bOES");
	glad_glMultiTexCoord3bvOES = (PFNGLMULTITEXCOORD3BVOESPROC)load("glMultiTexCoord3bvOES");
	glad_glMultiTexCoord4bOES = (PFNGLMULTITEXCOORD4BOESPROC)load("glMultiTexCoord4bOES");
	glad_glMultiTexCoord4bvOES = (PFNGLMULTITEXCOORD4BVOESPROC)load("glMultiTexCoord4bvOES");
	glad_glTexCoord1bOES = (PFNGLTEXCOORD1BOESPROC)load("glTexCoord1bOES");
	glad_glTexCoord1bvOES = (PFNGLTEXCOORD1BVOESPROC)load("glTexCoord1bvOES");
	glad_glTexCoord2bOES = (PFNGLTEXCOORD2BOESPROC)load("glTexCoord2bOES");
	glad_glTexCoord2bvOES = (PFNGLTEXCOORD2BVOESPROC)load("glTexCoord2bvOES");
	glad_glTexCoord3bOES = (PFNGLTEXCOORD3BOESPROC)load("glTexCoord3bOES");
	glad_glTexCoord3bvOES = (PFNGLTEXCOORD3BVOESPROC)load("glTexCoord3bvOES");
	glad_glTexCoord4bOES = (PFNGLTEXCOORD4BOESPROC)load("glTexCoord4bOES");
	glad_glTexCoord4bvOES = (PFNGLTEXCOORD4BVOESPROC)load("glTexCoord4bvOES");
	glad_glVertex2bOES = (PFNGLVERTEX2BOESPROC)load("glVertex2bOES");
	glad_glVertex2bvOES = (PFNGLVERTEX2BVOESPROC)load("glVertex2bvOES");
	glad_glVertex3bOES = (PFNGLVERTEX3BOESPROC)load("glVertex3bOES");
	glad_glVertex3bvOES = (PFNGLVERTEX3BVOESPROC)load("glVertex3bvOES");
	glad_glVertex4bOES = (PFNGLVERTEX4BOESPROC)load("glVertex4bOES");
	glad_glVertex4bvOES = (PFNGLVERTEX4BVOESPROC)load("glVertex4bvOES");
}
static void load_GL_ARB_transpose_matrix(GLADloadproc load) {
	if (!GLAD_GL_ARB_transpose_matrix) return;
	glad_glLoadTransposeMatrixfARB = (PFNGLLOADTRANSPOSEMATRIXFARBPROC)load("glLoadTransposeMatrixfARB");
	glad_glLoadTransposeMatrixdARB = (PFNGLLOADTRANSPOSEMATRIXDARBPROC)load("glLoadTransposeMatrixdARB");
	glad_glMultTransposeMatrixfARB = (PFNGLMULTTRANSPOSEMATRIXFARBPROC)load("glMultTransposeMatrixfARB");
	glad_glMultTransposeMatrixdARB = (PFNGLMULTTRANSPOSEMATRIXDARBPROC)load("glMultTransposeMatrixdARB");
}
static void load_GL_ARB_provoking_vertex(GLADloadproc load) {
	if (!GLAD_GL_ARB_provoking_vertex) return;
	glad_glProvokingVertex = (PFNGLPROVOKINGVERTEXPROC)load("glProvokingVertex");
}
static void load_GL_EXT_fog_coord(GLADloadproc load) {
	if (!GLAD_GL_EXT_fog_coord) return;
	glad_glFogCoordfEXT = (PFNGLFOGCOORDFEXTPROC)load("glFogCoordfEXT");
	glad_glFogCoordfvEXT = (PFNGLFOGCOORDFVEXTPROC)load("glFogCoordfvEXT");
	glad_glFogCoorddEXT = (PFNGLFOGCOORDDEXTPROC)load("glFogCoorddEXT");
	glad_glFogCoorddvEXT = (PFNGLFOGCOORDDVEXTPROC)load("glFogCoorddvEXT");
	glad_glFogCoordPointerEXT = (PFNGLFOGCOORDPOINTEREXTPROC)load("glFogCoordPointerEXT");
}
static void load_GL_EXT_vertex_array(GLADloadproc load) {
	if (!GLAD_GL_EXT_vertex_array) return;
	glad_glArrayElementEXT = (PFNGLARRAYELEMENTEXTPROC)load("glArrayElementEXT");
	glad_glColorPointerEXT = (PFNGLCOLORPOINTEREXTPROC)load("glColorPointerEXT");
	glad_glDrawArraysEXT = (PFNGLDRAWARRAYSEXTPROC)load("glDrawArraysEXT");
	glad_glEdgeFlagPointerEXT = (PFNGLEDGEFLAGPOINTEREXTPROC)load("glEdgeFlagPointerEXT");
	glad_glGetPointervEXT = (PFNGLGETPOINTERVEXTPROC)load("glGetPointervEXT");
	glad_glIndexPointerEXT = (PFNGLINDEXPOINTEREXTPROC)load("glIndexPointerEXT");
	glad_glNormalPointerEXT = (PFNGLNORMALPOINTEREXTPROC)load("glNormalPointerEXT");
	glad_glTexCoordPointerEXT = (PFNGLTEXCOORDPOINTEREXTPROC)load("glTexCoordPointerEXT");
	glad_glVertexPointerEXT = (PFNGLVERTEXPOINTEREXTPROC)load("glVertexPointerEXT");
}
static void load_GL_EXT_blend_equation_separate(GLADloadproc load) {
	if (!GLAD_GL_EXT_blend_equation_separate) return;
	glad_glBlendEquationSeparateEXT = (PFNGLBLENDEQUATIONSEPARATEEXTPROC)load("glBlendEquationSeparateEXT");
}
static void load_GL_NV_framebuffer_mixed_samples(GLADloadproc load) {
	if (!GLAD_GL_NV_framebuffer_mixed_samples) return;
	glad_glRasterSamplesEXT = (PFNGLRASTERSAMPLESEXTPROC)load("glRasterSamplesEXT");
	glad_glCoverageModulationTableNV = (PFNGLCOVERAGEMODULATIONTABLENVPROC)load("glCoverageModulationTableNV");
	glad_glGetCoverageModulationTableNV = (PFNGLGETCOVERAGEMODULATIONTABLENVPROC)load("glGetCoverageModulationTableNV");
	glad_glCoverageModulationNV = (PFNGLCOVERAGEMODULATIONNVPROC)load("glCoverageModulationNV");
}
static void load_GL_NVX_conditional_render(GLADloadproc load) {
	if (!GLAD_GL_NVX_conditional_render) return;
	glad_glBeginConditionalRenderNVX = (PFNGLBEGINCONDITIONALRENDERNVXPROC)load("glBeginConditionalRenderNVX");
	glad_glEndConditionalRenderNVX = (PFNGLENDCONDITIONALRENDERNVXPROC)load("glEndConditionalRenderNVX");
}
static void load_GL_ARB_multi_draw_indirect(GLADloadproc load) {
	if (!GLAD_GL_ARB_multi_draw_indirect) return;
	glad_glMultiDrawArraysIndirect = (PFNGLMULTIDRAWARRAYSINDIRECTPROC)load("glMultiDrawArraysIndirect");
	glad_glMultiDrawElementsIndirect = (PFNGLMULTIDRAWELEMENTSINDIRECTPROC)load("glMultiDrawElementsIndirect");
}
static void load_GL_EXT_raster_multisample(GLADloadproc load) {
	if (!GLAD_GL_EXT_raster_multisample) return;
	glad_glRasterSamplesEXT = (PFNGLRASTERSAMPLESEXTPROC)load("glRasterSamplesEXT");
}
static void load_GL_NV_copy_image(GLADloadproc load) {
	if (!GLAD_GL_NV_copy_image) return;
	glad_glCopyImageSubDataNV = (PFNGLCOPYIMAGESUBDATANVPROC)load("glCopyImageSubDataNV");
}
static void load_GL_ARB_transform_feedback2(GLADloadproc load) {
	if (!GLAD_GL_ARB_transform_feedback2) return;
	glad_glBindTransformFeedback = (PFNGLBINDTRANSFORMFEEDBACKPROC)load("glBindTransformFeedback");
	glad_glDeleteTransformFeedbacks = (PFNGLDELETETRANSFORMFEEDBACKSPROC)load("glDeleteTransformFeedbacks");
	glad_glGenTransformFeedbacks = (PFNGLGENTRANSFORMFEEDBACKSPROC)load("glGenTransformFeedbacks");
	glad_glIsTransformFeedback = (PFNGLISTRANSFORMFEEDBACKPROC)load("glIsTransformFeedback");
	glad_glPauseTransformFeedback = (PFNGLPAUSETRANSFORMFEEDBACKPROC)load("glPauseTransformFeedback");
	glad_glResumeTransformFeedback = (PFNGLRESUMETRANSFORMFEEDBACKPROC)load("glResumeTransformFeedback");
	glad_glDrawTransformFeedback = (PFNGLDRAWTRANSFORMFEEDBACKPROC)load("glDrawTransformFeedback");
}
static void load_GL_ARB_transform_feedback3(GLADloadproc load) {
	if (!GLAD_GL_ARB_transform_feedback3) return;
	glad_glDrawTransformFeedbackStream = (PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC)load("glDrawTransformFeedbackStream");
	glad_glBeginQueryIndexed = (PFNGLBEGINQUERYINDEXEDPROC)load("glBeginQueryIndexed");
	glad_glEndQueryIndexed = (PFNGLENDQUERYINDEXEDPROC)load("glEndQueryIndexed");
	glad_glGetQueryIndexediv = (PFNGLGETQUERYINDEXEDIVPROC)load("glGetQueryIndexediv");
}
static void load_GL_EXT_debug_marker(GLADloadproc load) {
	if (!GLAD_GL_EXT_debug_marker) return;
	glad_glInsertEventMarkerEXT = (PFNGLINSERTEVENTMARKEREXTPROC)load("glInsertEventMarkerEXT");
	glad_glPushGroupMarkerEXT = (PFNGLPUSHGROUPMARKEREXTPROC)load("glPushGroupMarkerEXT");
	glad_glPopGroupMarkerEXT = (PFNGLPOPGROUPMARKEREXTPROC)load("glPopGroupMarkerEXT");
}
static void load_GL_EXT_pixel_transform(GLADloadproc load) {
	if (!GLAD_GL_EXT_pixel_transform) return;
	glad_glPixelTransformParameteriEXT = (PFNGLPIXELTRANSFORMPARAMETERIEXTPROC)load("glPixelTransformParameteriEXT");
	glad_glPixelTransformParameterfEXT = (PFNGLPIXELTRANSFORMPARAMETERFEXTPROC)load("glPixelTransformParameterfEXT");
	glad_glPixelTransformParameterivEXT = (PFNGLPIXELTRANSFORMPARAMETERIVEXTPROC)load("glPixelTransformParameterivEXT");
	glad_glPixelTransformParameterfvEXT = (PFNGLPIXELTRANSFORMPARAMETERFVEXTPROC)load("glPixelTransformParameterfvEXT");
	glad_glGetPixelTransformParameterivEXT = (PFNGLGETPIXELTRANSFORMPARAMETERIVEXTPROC)load("glGetPixelTransformParameterivEXT");
	glad_glGetPixelTransformParameterfvEXT = (PFNGLGETPIXELTRANSFORMPARAMETERFVEXTPROC)load("glGetPixelTransformParameterfvEXT");
}
static void load_GL_ATI_fragment_shader(GLADloadproc load) {
	if (!GLAD_GL_ATI_fragment_shader) return;
	glad_glGenFragmentShadersATI = (PFNGLGENFRAGMENTSHADERSATIPROC)load("glGenFragmentShadersATI");
	glad_glBindFragmentShaderATI = (PFNGLBINDFRAGMENTSHADERATIPROC)load("glBindFragmentShaderATI");
	glad_glDeleteFragmentShaderATI = (PFNGLDELETEFRAGMENTSHADERATIPROC)load("glDeleteFragmentShaderATI");
	glad_glBeginFragmentShaderATI = (PFNGLBEGINFRAGMENTSHADERATIPROC)load("glBeginFragmentShaderATI");
	glad_glEndFragmentShaderATI = (PFNGLENDFRAGMENTSHADERATIPROC)load("glEndFragmentShaderATI");
	glad_glPassTexCoordATI = (PFNGLPASSTEXCOORDATIPROC)load("glPassTexCoordATI");
	glad_glSampleMapATI = (PFNGLSAMPLEMAPATIPROC)load("glSampleMapATI");
	glad_glColorFragmentOp1ATI = (PFNGLCOLORFRAGMENTOP1ATIPROC)load("glColorFragmentOp1ATI");
	glad_glColorFragmentOp2ATI = (PFNGLCOLORFRAGMENTOP2ATIPROC)load("glColorFragmentOp2ATI");
	glad_glColorFragmentOp3ATI = (PFNGLCOLORFRAGMENTOP3ATIPROC)load("glColorFragmentOp3ATI");
	glad_glAlphaFragmentOp1ATI = (PFNGLALPHAFRAGMENTOP1ATIPROC)load("glAlphaFragmentOp1ATI");
	glad_glAlphaFragmentOp2ATI = (PFNGLALPHAFRAGMENTOP2ATIPROC)load("glAlphaFragmentOp2ATI");
	glad_glAlphaFragmentOp3ATI = (PFNGLALPHAFRAGMENTOP3ATIPROC)load("glAlphaFragmentOp3ATI");
	glad_glSetFragmentShaderConstantATI = (PFNGLSETFRAGMENTSHADERCONSTANTATIPROC)load("glSetFragmentShaderConstantATI");
}
static void load_GL_ARB_vertex_array_object(GLADloadproc load) {
	if (!GLAD_GL_ARB_vertex_array_object) return;
	glad_glBindVertexArray = (PFNGLBINDVERTEXARRAYPROC)load("glBindVertexArray");
	glad_glDeleteVertexArrays = (PFNGLDELETEVERTEXARRAYSPROC)load("glDeleteVertexArrays");
	glad_glGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC)load("glGenVertexArrays");
	glad_glIsVertexArray = (PFNGLISVERTEXARRAYPROC)load("glIsVertexArray");
}
static void load_GL_SUN_triangle_list(GLADloadproc load) {
	if (!GLAD_GL_SUN_triangle_list) return;
	glad_glReplacementCodeuiSUN = (PFNGLREPLACEMENTCODEUISUNPROC)load("glReplacementCodeuiSUN");
	glad_glReplacementCodeusSUN = (PFNGLREPLACEMENTCODEUSSUNPROC)load("glReplacementCodeusSUN");
	glad_glReplacementCodeubSUN = (PFNGLREPLACEMENTCODEUBSUNPROC)load("glReplacementCodeubSUN");
	glad_glReplacementCodeuivSUN = (PFNGLREPLACEMENTCODEUIVSUNPROC)load("glReplacementCodeuivSUN");
	glad_glReplacementCodeusvSUN = (PFNGLREPLACEMENTCODEUSVSUNPROC)load("glReplacementCodeusvSUN");
	glad_glReplacementCodeubvSUN = (PFNGLREPLACEMENTCODEUBVSUNPROC)load("glReplacementCodeubvSUN");
	glad_glReplacementCodePointerSUN = (PFNGLREPLACEMENTCODEPOINTERSUNPROC)load("glReplacementCodePointerSUN");
}
static void load_GL_ARB_transform_feedback_instanced(GLADloadproc load) {
	if (!GLAD_GL_ARB_transform_feedback_instanced) return;
	glad_glDrawTransformFeedbackInstanced = (PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC)load("glDrawTransformFeedbackInstanced");
	glad_glDrawTransformFeedbackStreamInstanced = (PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC)load("glDrawTransformFeedbackStreamInstanced");
}
static void load_GL_SGIX_async(GLADloadproc load) {
	if (!GLAD_GL_SGIX_async) return;
	glad_glAsyncMarkerSGIX = (PFNGLASYNCMARKERSGIXPROC)load("glAsyncMarkerSGIX");
	glad_glFinishAsyncSGIX = (PFNGLFINISHASYNCSGIXPROC)load("glFinishAsyncSGIX");
	glad_glPollAsyncSGIX = (PFNGLPOLLASYNCSGIXPROC)load("glPollAsyncSGIX");
	glad_glGenAsyncMarkersSGIX = (PFNGLGENASYNCMARKERSSGIXPROC)load("glGenAsyncMarkersSGIX");
	glad_glDeleteAsyncMarkersSGIX = (PFNGLDELETEASYNCMARKERSSGIXPROC)load("glDeleteAsyncMarkersSGIX");
	glad_glIsAsyncMarkerSGIX = (PFNGLISASYNCMARKERSGIXPROC)load("glIsAsyncMarkerSGIX");
}
static void load_GL_INTEL_performance_query(GLADloadproc load) {
	if (!GLAD_GL_INTEL_performance_query) return;
	glad_glBeginPerfQueryINTEL = (PFNGLBEGINPERFQUERYINTELPROC)load("glBeginPerfQueryINTEL");
	glad_glCreatePerfQueryINTEL = (PFNGLCREATEPERFQUERYINTELPROC)load("glCreatePerfQueryINTEL");
	glad_glDeletePerfQueryINTEL = (PFNGLDELETEPERFQUERYINTELPROC)load("glDeletePerfQueryINTEL");
	glad_glEndPerfQueryINTEL = (PFNGLENDPERFQUERYINTELPROC)load("glEndPerfQueryINTEL");
	glad_glGetFirstPerfQueryIdINTEL = (PFNGLGETFIRSTPERFQUERYIDINTELPROC)load("glGetFirstPerfQueryIdINTEL");
	glad_glGetNextPerfQueryIdINTEL = (PFNGLGETNEXTPERFQUERYIDINTELPROC)load("glGetNextPerfQueryIdINTEL");
	glad_glGetPerfCounterInfoINTEL = (PFNGLGETPERFCOUNTERINFOINTELPROC)load("glGetPerfCounterInfoINTEL");
	glad_glGetPerfQueryDataINTEL = (PFNGLGETPERFQUERYDATAINTELPROC)load("glGetPerfQueryDataINTEL");
	glad_glGetPerfQueryIdByNameINTEL = (PFNGLGETPERFQUERYIDBYNAMEINTELPROC)load("glGetPerfQueryIdByNameINTEL");
	glad_glGetPerfQueryInfoINTEL = (PFNGLGETPERFQUERYINFOINTELPROC)load("glGetPerfQueryInfoINTEL");
}
static void load_GL_NV_gpu_shader5(GLADloadproc load) {
	if (!GLAD_GL_NV_gpu_shader5) return;
	glad_glUniform1i64NV = (PFNGLUNIFORM1I64NVPROC)load("glUniform1i64NV");
	glad_glUniform2i64NV = (PFNGLUNIFORM2I64NVPROC)load("glUniform2i64NV");
	glad_glUniform3i64NV = (PFNGLUNIFORM3I64NVPROC)load("glUniform3i64NV");
	glad_glUniform4i64NV = (PFNGLUNIFORM4I64NVPROC)load("glUniform4i64NV");
	glad_glUniform1i64vNV = (PFNGLUNIFORM1I64VNVPROC)load("glUniform1i64vNV");
	glad_glUniform2i64vNV = (PFNGLUNIFORM2I64VNVPROC)load("glUniform2i64vNV");
	glad_glUniform3i64vNV = (PFNGLUNIFORM3I64VNVPROC)load("glUniform3i64vNV");
	glad_glUniform4i64vNV = (PFNGLUNIFORM4I64VNVPROC)load("glUniform4i64vNV");
	glad_glUniform1ui64NV = (PFNGLUNIFORM1UI64NVPROC)load("glUniform1ui64NV");
	glad_glUniform2ui64NV = (PFNGLUNIFORM2UI64NVPROC)load("glUniform2ui64NV");
	glad_glUniform3ui64NV = (PFNGLUNIFORM3UI64NVPROC)load("glUniform3ui64NV");
	glad_glUniform4ui64NV = (PFNGLUNIFORM4UI64NVPROC)load("glUniform4ui64NV");
	glad_glUniform1ui64vNV = (PFNGLUNIFORM1UI64VNVPROC)load("glUniform1ui64vNV");
	glad_glUniform2ui64vNV = (PFNGLUNIFORM2UI64VNVPROC)load("glUniform2ui64vNV");
	glad_glUniform3ui64vNV = (PFNGLUNIFORM3UI64VNVPROC)load("glUniform3ui64vNV");
	glad_glUniform4ui64vNV = (PFNGLUNIFORM4UI64VNVPROC)load("glUniform4ui64vNV");
	glad_glGetUniformi64vNV = (PFNGLGETUNIFORMI64VNVPROC)load("glGetUniformi64vNV");
	glad_glProgramUniform1i64NV = (PFNGLPROGRAMUNIFORM1I64NVPROC)load("glProgramUniform1i64NV");
	glad_glProgramUniform2i64NV = (PFNGLPROGRAMUNIFORM2I64NVPROC)load("glProgramUniform2i64NV");
	glad_glProgramUniform3i64NV = (PFNGLPROGRAMUNIFORM3I64NVPROC)load("glProgramUniform3i64NV");
	glad_glProgramUniform4i64NV = (PFNGLPROGRAMUNIFORM4I64NVPROC)load("glProgramUniform4i64NV");
	glad_glProgramUniform1i64vNV = (PFNGLPROGRAMUNIFORM1I64VNVPROC)load("glProgramUniform1i64vNV");
	glad_glProgramUniform2i64vNV = (PFNGLPROGRAMUNIFORM2I64VNVPROC)load("glProgramUniform2i64vNV");
	glad_glProgramUniform3i64vNV = (PFNGLPROGRAMUNIFORM3I64VNVPROC)load("glProgramUniform3i64vNV");
	glad_glProgramUniform4i64vNV = (PFNGLPROGRAMUNIFORM4I64VNVPROC)load("glProgramUniform4i64vNV");
	glad_glProgramUniform1ui64NV = (PFNGLPROGRAMUNIFORM1UI64NVPROC)load("glProgramUniform1ui64NV");
	glad_glProgramUniform2ui64NV = (PFNGLPROGRAMUNIFORM2UI64NVPROC)load("glProgramUniform2ui64NV");
	glad_glProgramUniform3ui64NV = (PFNGLPROGRAMUNIFORM3UI64NVPROC)load("glProgramUniform3ui64NV");
	glad_glProgramUniform4ui64NV = (PFNGLPROGRAMUNIFORM4UI64NVPROC)load("glProgramUniform4ui64NV");
	glad_glProgramUniform1ui64vNV = (PFNGLPROGRAMUNIFORM1UI64VNVPROC)load("glProgramUniform1ui64vNV");
	glad_glProgramUniform2ui64vNV = (PFNGLPROGRAMUNIFORM2UI64VNVPROC)load("glProgramUniform2ui64vNV");
	glad_glProgramUniform3ui64vNV = (PFNGLPROGRAMUNIFORM3UI64VNVPROC)load("glProgramUniform3ui64vNV");
	glad_glProgramUniform4ui64vNV = (PFNGLPROGRAMUNIFORM4UI64VNVPROC)load("glProgramUniform4ui64vNV");
}
static void load_GL_NV_bindless_multi_draw_indirect_count(GLADloadproc load) {
	if (!GLAD_GL_NV_bindless_multi_draw_indirect_count) return;
	glad_glMultiDrawArraysIndirectBindlessCountNV = (PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSCOUNTNVPROC)load("glMultiDrawArraysIndirectBindlessCountNV");
	glad_glMultiDrawElementsIndirectBindlessCountNV = (PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSCOUNTNVPROC)load("glMultiDrawElementsIndirectBindlessCountNV");
}
static void load_GL_ARB_ES2_compatibility(GLADloadproc load) {
	if (!GLAD_GL_ARB_ES2_compatibility) return;
	glad_glReleaseShaderCompiler = (PFNGLRELEASESHADERCOMPILERPROC)load("glReleaseShaderCompiler");
	glad_glShaderBinary = (PFNGLSHADERBINARYPROC)load("glShaderBinary");
	glad_glGetShaderPrecisionFormat = (PFNGLGETSHADERPRECISIONFORMATPROC)load("glGetShaderPrecisionFormat");
	glad_glDepthRangef = (PFNGLDEPTHRANGEFPROC)load("glDepthRangef");
	glad_glClearDepthf = (PFNGLCLEARDEPTHFPROC)load("glClearDepthf");
}
static void load_GL_ARB_indirect_parameters(GLADloadproc load) {
	if (!GLAD_GL_ARB_indirect_parameters) return;
	glad_glMultiDrawArraysIndirectCountARB = (PFNGLMULTIDRAWARRAYSINDIRECTCOUNTARBPROC)load("glMultiDrawArraysIndirectCountARB");
	glad_glMultiDrawElementsIndirectCountARB = (PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTARBPROC)load("glMultiDrawElementsIndirectCountARB");
}
static void load_GL_NV_half_float(GLADloadproc load) {
	if (!GLAD_GL_NV_half_float) return;
	glad_glVertex2hNV = (PFNGLVERTEX2HNVPROC)load("glVertex2hNV");
	glad_glVertex2hvNV = (PFNGLVERTEX2HVNVPROC)load("glVertex2hvNV");
	glad_glVertex3hNV = (PFNGLVERTEX3HNVPROC)load("glVertex3hNV");
	glad_glVertex3hvNV = (PFNGLVERTEX3HVNVPROC)load("glVertex3hvNV");
	glad_glVertex4hNV = (PFNGLVERTEX4HNVPROC)load("glVertex4hNV");
	glad_glVertex4hvNV = (PFNGLVERTEX4HVNVPROC)load("glVertex4hvNV");
	glad_glNormal3hNV = (PFNGLNORMAL3HNVPROC)load("glNormal3hNV");
	glad_glNormal3hvNV = (PFNGLNORMAL3HVNVPROC)load("glNormal3hvNV");
	glad_glColor3hNV = (PFNGLCOLOR3HNVPROC)load("glColor3hNV");
	glad_glColor3hvNV = (PFNGLCOLOR3HVNVPROC)load("glColor3hvNV");
	glad_glColor4hNV = (PFNGLCOLOR4HNVPROC)load("glColor4hNV");
	glad_glColor4hvNV = (PFNGLCOLOR4HVNVPROC)load("glColor4hvNV");
	glad_glTexCoord1hNV = (PFNGLTEXCOORD1HNVPROC)load("glTexCoord1hNV");
	glad_glTexCoord1hvNV = (PFNGLTEXCOORD1HVNVPROC)load("glTexCoord1hvNV");
	glad_glTexCoord2hNV = (PFNGLTEXCOORD2HNVPROC)load("glTexCoord2hNV");
	glad_glTexCoord2hvNV = (PFNGLTEXCOORD2HVNVPROC)load("glTexCoord2hvNV");
	glad_glTexCoord3hNV = (PFNGLTEXCOORD3HNVPROC)load("glTexCoord3hNV");
	glad_glTexCoord3hvNV = (PFNGLTEXCOORD3HVNVPROC)load("glTexCoord3hvNV");
	glad_glTexCoord4hNV = (PFNGLTEXCOORD4HNVPROC)load("glTexCoord4hNV");
	glad_glTexCoord4hvNV = (PFNGLTEXCOORD4HVNVPROC)load("glTexCoord4hvNV");
	glad_glMultiTexCoord1hNV = (PFNGLMULTITEXCOORD1HNVPROC)load("glMultiTexCoord1hNV");
	glad_glMultiTexCoord1hvNV = (PFNGLMULTITEXCOORD1HVNVPROC)load("glMultiTexCoord1hvNV");
	glad_glMultiTexCoord2hNV = (PFNGLMULTITEXCOORD2HNVPROC)load("glMultiTexCoord2hNV");
	glad_glMultiTexCoord2hvNV = (PFNGLMULTITEXCOORD2HVNVPROC)load("glMultiTexCoord2hvNV");
	glad_glMultiTexCoord3hNV = (PFNGLMULTITEXCOORD3HNVPROC)load("glMultiTexCoord3hNV");
	glad_glMultiTexCoord3hvNV = (PFNGLMULTITEXCOORD3HVNVPROC)load("glMultiTexCoord3hvNV");
	glad_glMultiTexCoord4hNV = (PFNGLMULTITEXCOORD4HNVPROC)load("glMultiTexCoord4hNV");
	glad_glMultiTexCoord4hvNV = (PFNGLMULTITEXCOORD4HVNVPROC)load("glMultiTexCoord4hvNV");
	glad_glFogCoordhNV = (PFNGLFOGCOORDHNVPROC)load("glFogCoordhNV");
	glad_glFogCoordhvNV = (PFNGLFOGCOORDHVNVPROC)load("glFogCoordhvNV");
	glad_glSecondaryColor3hNV = (PFNGLSECONDARYCOLOR3HNVPROC)load("glSecondaryColor3hNV");
	glad_glSecondaryColor3hvNV = (PFNGLSECONDARYCOLOR3HVNVPROC)load("glSecondaryColor3hvNV");
	glad_glVertexWeighthNV = (PFNGLVERTEXWEIGHTHNVPROC)load("glVertexWeighthNV");
	glad_glVertexWeighthvNV = (PFNGLVERTEXWEIGHTHVNVPROC)load("glVertexWeighthvNV");
	glad_glVertexAttrib1hNV = (PFNGLVERTEXATTRIB1HNVPROC)load("glVertexAttrib1hNV");
	glad_glVertexAttrib1hvNV = (PFNGLVERTEXATTRIB1HVNVPROC)load("glVertexAttrib1hvNV");
	glad_glVertexAttrib2hNV = (PFNGLVERTEXATTRIB2HNVPROC)load("glVertexAttrib2hNV");
	glad_glVertexAttrib2hvNV = (PFNGLVERTEXATTRIB2HVNVPROC)load("glVertexAttrib2hvNV");
	glad_glVertexAttrib3hNV = (PFNGLVERTEXATTRIB3HNVPROC)load("glVertexAttrib3hNV");
	glad_glVertexAttrib3hvNV = (PFNGLVERTEXATTRIB3HVNVPROC)load("glVertexAttrib3hvNV");
	glad_glVertexAttrib4hNV = (PFNGLVERTEXATTRIB4HNVPROC)load("glVertexAttrib4hNV");
	glad_glVertexAttrib4hvNV = (PFNGLVERTEXATTRIB4HVNVPROC)load("glVertexAttrib4hvNV");
	glad_glVertexAttribs1hvNV = (PFNGLVERTEXATTRIBS1HVNVPROC)load("glVertexAttribs1hvNV");
	glad_glVertexAttribs2hvNV = (PFNGLVERTEXATTRIBS2HVNVPROC)load("glVertexAttribs2hvNV");
	glad_glVertexAttribs3hvNV = (PFNGLVERTEXATTRIBS3HVNVPROC)load("glVertexAttribs3hvNV");
	glad_glVertexAttribs4hvNV = (PFNGLVERTEXATTRIBS4HVNVPROC)load("glVertexAttribs4hvNV");
}
static void load_GL_EXT_coordinate_frame(GLADloadproc load) {
	if (!GLAD_GL_EXT_coordinate_frame) return;
	glad_glTangent3bEXT = (PFNGLTANGENT3BEXTPROC)load("glTangent3bEXT");
	glad_glTangent3bvEXT = (PFNGLTANGENT3BVEXTPROC)load("glTangent3bvEXT");
	glad_glTangent3dEXT = (PFNGLTANGENT3DEXTPROC)load("glTangent3dEXT");
	glad_glTangent3dvEXT = (PFNGLTANGENT3DVEXTPROC)load("glTangent3dvEXT");
	glad_glTangent3fEXT = (PFNGLTANGENT3FEXTPROC)load("glTangent3fEXT");
	glad_glTangent3fvEXT = (PFNGLTANGENT3FVEXTPROC)load("glTangent3fvEXT");
	glad_glTangent3iEXT = (PFNGLTANGENT3IEXTPROC)load("glTangent3iEXT");
	glad_glTangent3ivEXT = (PFNGLTANGENT3IVEXTPROC)load("glTangent3ivEXT");
	glad_glTangent3sEXT = (PFNGLTANGENT3SEXTPROC)load("glTangent3sEXT");
	glad_glTangent3svEXT = (PFNGLTANGENT3SVEXTPROC)load("glTangent3svEXT");
	glad_glBinormal3bEXT = (PFNGLBINORMAL3BEXTPROC)load("glBinormal3bEXT");
	glad_glBinormal3bvEXT = (PFNGLBINORMAL3BVEXTPROC)load("glBinormal3bvEXT");
	glad_glBinormal3dEXT = (PFNGLBINORMAL3DEXTPROC)load("glBinormal3dEXT");
	glad_glBinormal3dvEXT = (PFNGLBINORMAL3DVEXTPROC)load("glBinormal3dvEXT");
	glad_glBinormal3fEXT = (PFNGLBINORMAL3FEXTPROC)load("glBinormal3fEXT");
	glad_glBinormal3fvEXT = (PFNGLBINORMAL3FVEXTPROC)load("glBinormal3fvEXT");
	glad_glBinormal3iEXT = (PFNGLBINORMAL3IEXTPROC)load("glBinormal3iEXT");
	glad_glBinormal3ivEXT = (PFNGLBINORMAL3IVEXTPROC)load("glBinormal3ivEXT");
	glad_glBinormal3sEXT = (PFNGLBINORMAL3SEXTPROC)load("glBinormal3sEXT");
	glad_glBinormal3svEXT = (PFNGLBINORMAL3SVEXTPROC)load("glBinormal3svEXT");
	glad_glTangentPointerEXT = (PFNGLTANGENTPOINTEREXTPROC)load("glTangentPointerEXT");
	glad_glBinormalPointerEXT = (PFNGLBINORMALPOINTEREXTPROC)load("glBinormalPointerEXT");
}
static void load_GL_EXT_polygon_offset_clamp(GLADloadproc load) {
	if (!GLAD_GL_EXT_polygon_offset_clamp) return;
	glad_glPolygonOffsetClampEXT = (PFNGLPOLYGONOFFSETCLAMPEXTPROC)load("glPolygonOffsetClampEXT");
}
static void load_GL_EXT_compiled_vertex_array(GLADloadproc load) {
	if (!GLAD_GL_EXT_compiled_vertex_array) return;
	glad_glLockArraysEXT = (PFNGLLOCKARRAYSEXTPROC)load("glLockArraysEXT");
	glad_glUnlockArraysEXT = (PFNGLUNLOCKARRAYSEXTPROC)load("glUnlockArraysEXT");
}
static void load_GL_NV_depth_buffer_float(GLADloadproc load) {
	if (!GLAD_GL_NV_depth_buffer_float) return;
	glad_glDepthRangedNV = (PFNGLDEPTHRANGEDNVPROC)load("glDepthRangedNV");
	glad_glClearDepthdNV = (PFNGLCLEARDEPTHDNVPROC)load("glClearDepthdNV");
	glad_glDepthBoundsdNV = (PFNGLDEPTHBOUNDSDNVPROC)load("glDepthBoundsdNV");
}
static void load_GL_NV_occlusion_query(GLADloadproc load) {
	if (!GLAD_GL_NV_occlusion_query) return;
	glad_glGenOcclusionQueriesNV = (PFNGLGENOCCLUSIONQUERIESNVPROC)load("glGenOcclusionQueriesNV");
	glad_glDeleteOcclusionQueriesNV = (PFNGLDELETEOCCLUSIONQUERIESNVPROC)load("glDeleteOcclusionQueriesNV");
	glad_glIsOcclusionQueryNV = (PFNGLISOCCLUSIONQUERYNVPROC)load("glIsOcclusionQueryNV");
	glad_glBeginOcclusionQueryNV = (PFNGLBEGINOCCLUSIONQUERYNVPROC)load("glBeginOcclusionQueryNV");
	glad_glEndOcclusionQueryNV = (PFNGLENDOCCLUSIONQUERYNVPROC)load("glEndOcclusionQueryNV");
	glad_glGetOcclusionQueryivNV = (PFNGLGETOCCLUSIONQUERYIVNVPROC)load("glGetOcclusionQueryivNV");
	glad_glGetOcclusionQueryuivNV = (PFNGLGETOCCLUSIONQUERYUIVNVPROC)load("glGetOcclusionQueryuivNV");
}
static void load_GL_APPLE_flush_buffer_range(GLADloadproc load) {
	if (!GLAD_GL_APPLE_flush_buffer_range) return;
	glad_glBufferParameteriAPPLE = (PFNGLBUFFERPARAMETERIAPPLEPROC)load("glBufferParameteriAPPLE");
	glad_glFlushMappedBufferRangeAPPLE = (PFNGLFLUSHMAPPEDBUFFERRANGEAPPLEPROC)load("glFlushMappedBufferRangeAPPLE");
}
static void load_GL_ARB_imaging(GLADloadproc load) {
	if (!GLAD_GL_ARB_imaging) return;
	glad_glBlendColor = (PFNGLBLENDCOLORPROC)load("glBlendColor");
	glad_glBlendEquation = (PFNGLBLENDEQUATIONPROC)load("glBlendEquation");
	glad_glColorTable = (PFNGLCOLORTABLEPROC)load("glColorTable");
	glad_glColorTableParameterfv = (PFNGLCOLORTABLEPARAMETERFVPROC)load("glColorTableParameterfv");
	glad_glColorTableParameteriv = (PFNGLCOLORTABLEPARAMETERIVPROC)load("glColorTableParameteriv");
	glad_glCopyColorTable = (PFNGLCOPYCOLORTABLEPROC)load("glCopyColorTable");
	glad_glGetColorTable = (PFNGLGETCOLORTABLEPROC)load("glGetColorTable");
	glad_glGetColorTableParameterfv = (PFNGLGETCOLORTABLEPARAMETERFVPROC)load("glGetColorTableParameterfv");
	glad_glGetColorTableParameteriv = (PFNGLGETCOLORTABLEPARAMETERIVPROC)load("glGetColorTableParameteriv");
	glad_glColorSubTable = (PFNGLCOLORSUBTABLEPROC)load("glColorSubTable");
	glad_glCopyColorSubTable = (PFNGLCOPYCOLORSUBTABLEPROC)load("glCopyColorSubTable");
	glad_glConvolutionFilter1D = (PFNGLCONVOLUTIONFILTER1DPROC)load("glConvolutionFilter1D");
	glad_glConvolutionFilter2D = (PFNGLCONVOLUTIONFILTER2DPROC)load("glConvolutionFilter2D");
	glad_glConvolutionParameterf = (PFNGLCONVOLUTIONPARAMETERFPROC)load("glConvolutionParameterf");
	glad_glConvolutionParameterfv = (PFNGLCONVOLUTIONPARAMETERFVPROC)load("glConvolutionParameterfv");
	glad_glConvolutionParameteri = (PFNGLCONVOLUTIONPARAMETERIPROC)load("glConvolutionParameteri");
	glad_glConvolutionParameteriv = (PFNGLCONVOLUTIONPARAMETERIVPROC)load("glConvolutionParameteriv");
	glad_glCopyConvolutionFilter1D = (PFNGLCOPYCONVOLUTIONFILTER1DPROC)load("glCopyConvolutionFilter1D");
	glad_glCopyConvolutionFilter2D = (PFNGLCOPYCONVOLUTIONFILTER2DPROC)load("glCopyConvolutionFilter2D");
	glad_glGetConvolutionFilter = (PFNGLGETCONVOLUTIONFILTERPROC)load("glGetConvolutionFilter");
	glad_glGetConvolutionParameterfv = (PFNGLGETCONVOLUTIONPARAMETERFVPROC)load("glGetConvolutionParameterfv");
	glad_glGetConvolutionParameteriv = (PFNGLGETCONVOLUTIONPARAMETERIVPROC)load("glGetConvolutionParameteriv");
	glad_glGetSeparableFilter = (PFNGLGETSEPARABLEFILTERPROC)load("glGetSeparableFilter");
	glad_glSeparableFilter2D = (PFNGLSEPARABLEFILTER2DPROC)load("glSeparableFilter2D");
	glad_glGetHistogram = (PFNGLGETHISTOGRAMPROC)load("glGetHistogram");
	glad_glGetHistogramParameterfv = (PFNGLGETHISTOGRAMPARAMETERFVPROC)load("glGetHistogramParameterfv");
	glad_glGetHistogramParameteriv = (PFNGLGETHISTOGRAMPARAMETERIVPROC)load("glGetHistogramParameteriv");
	glad_glGetMinmax = (PFNGLGETMINMAXPROC)load("glGetMinmax");
	glad_glGetMinmaxParameterfv = (PFNGLGETMINMAXPARAMETERFVPROC)load("glGetMinmaxParameterfv");
	glad_glGetMinmaxParameteriv = (PFNGLGETMINMAXPARAMETERIVPROC)load("glGetMinmaxParameteriv");
	glad_glHistogram = (PFNGLHISTOGRAMPROC)load("glHistogram");
	glad_glMinmax = (PFNGLMINMAXPROC)load("glMinmax");
	glad_glResetHistogram = (PFNGLRESETHISTOGRAMPROC)load("glResetHistogram");
	glad_glResetMinmax = (PFNGLRESETMINMAXPROC)load("glResetMinmax");
}
static void load_GL_ARB_draw_buffers_blend(GLADloadproc load) {
	if (!GLAD_GL_ARB_draw_buffers_blend) return;
	glad_glBlendEquationiARB = (PFNGLBLENDEQUATIONIARBPROC)load("glBlendEquationiARB");
	glad_glBlendEquationSeparateiARB = (PFNGLBLENDEQUATIONSEPARATEIARBPROC)load("glBlendEquationSeparateiARB");
	glad_glBlendFunciARB = (PFNGLBLENDFUNCIARBPROC)load("glBlendFunciARB");
	glad_glBlendFuncSeparateiARB = (PFNGLBLENDFUNCSEPARATEIARBPROC)load("glBlendFuncSeparateiARB");
}
static void load_GL_ARB_clear_buffer_object(GLADloadproc load) {
	if (!GLAD_GL_ARB_clear_buffer_object) return;
	glad_glClearBufferData = (PFNGLCLEARBUFFERDATAPROC)load("glClearBufferData");
	glad_glClearBufferSubData = (PFNGLCLEARBUFFERSUBDATAPROC)load("glClearBufferSubData");
}
static void load_GL_ARB_multisample(GLADloadproc load) {
	if (!GLAD_GL_ARB_multisample) return;
	glad_glSampleCoverageARB = (PFNGLSAMPLECOVERAGEARBPROC)load("glSampleCoverageARB");
}
static void load_GL_EXT_debug_label(GLADloadproc load) {
	if (!GLAD_GL_EXT_debug_label) return;
	glad_glLabelObjectEXT = (PFNGLLABELOBJECTEXTPROC)load("glLabelObjectEXT");
	glad_glGetObjectLabelEXT = (PFNGLGETOBJECTLABELEXTPROC)load("glGetObjectLabelEXT");
}
static void load_GL_ARB_sample_shading(GLADloadproc load) {
	if (!GLAD_GL_ARB_sample_shading) return;
	glad_glMinSampleShadingARB = (PFNGLMINSAMPLESHADINGARBPROC)load("glMinSampleShadingARB");
}
static void load_GL_NV_internalformat_sample_query(GLADloadproc load) {
	if (!GLAD_GL_NV_internalformat_sample_query) return;
	glad_glGetInternalformatSampleivNV = (PFNGLGETINTERNALFORMATSAMPLEIVNVPROC)load("glGetInternalformatSampleivNV");
}
static void load_GL_INTEL_map_texture(GLADloadproc load) {
	if (!GLAD_GL_INTEL_map_texture) return;
	glad_glSyncTextureINTEL = (PFNGLSYNCTEXTUREINTELPROC)load("glSyncTextureINTEL");
	glad_glUnmapTexture2DINTEL = (PFNGLUNMAPTEXTURE2DINTELPROC)load("glUnmapTexture2DINTEL");
	glad_glMapTexture2DINTEL = (PFNGLMAPTEXTURE2DINTELPROC)load("glMapTexture2DINTEL");
}
static void load_GL_ARB_compute_shader(GLADloadproc load) {
	if (!GLAD_GL_ARB_compute_shader) return;
	glad_glDispatchCompute = (PFNGLDISPATCHCOMPUTEPROC)load("glDispatchCompute");
	glad_glDispatchComputeIndirect = (PFNGLDISPATCHCOMPUTEINDIRECTPROC)load("glDispatchComputeIndirect");
}
static void load_GL_IBM_vertex_array_lists(GLADloadproc load) {
	if (!GLAD_GL_IBM_vertex_array_lists) return;
	glad_glColorPointerListIBM = (PFNGLCOLORPOINTERLISTIBMPROC)load("glColorPointerListIBM");
	glad_glSecondaryColorPointerListIBM = (PFNGLSECONDARYCOLORPOINTERLISTIBMPROC)load("glSecondaryColorPointerListIBM");
	glad_glEdgeFlagPointerListIBM = (PFNGLEDGEFLAGPOINTERLISTIBMPROC)load("glEdgeFlagPointerListIBM");
	glad_glFogCoordPointerListIBM = (PFNGLFOGCOORDPOINTERLISTIBMPROC)load("glFogCoordPointerListIBM");
	glad_glIndexPointerListIBM = (PFNGLINDEXPOINTERLISTIBMPROC)load("glIndexPointerListIBM");
	glad_glNormalPointerListIBM = (PFNGLNORMALPOINTERLISTIBMPROC)load("glNormalPointerListIBM");
	glad_glTexCoordPointerListIBM = (PFNGLTEXCOORDPOINTERLISTIBMPROC)load("glTexCoordPointerListIBM");
	glad_glVertexPointerListIBM = (PFNGLVERTEXPOINTERLISTIBMPROC)load("glVertexPointerListIBM");
}
static void load_GL_ARB_color_buffer_float(GLADloadproc load) {
	if (!GLAD_GL_ARB_color_buffer_float) return;
	glad_glClampColorARB = (PFNGLCLAMPCOLORARBPROC)load("glClampColorARB");
}
static void load_GL_ARB_bindless_texture(GLADloadproc load) {
	if (!GLAD_GL_ARB_bindless_texture) return;
	glad_glGetTextureHandleARB = (PFNGLGETTEXTUREHANDLEARBPROC)load("glGetTextureHandleARB");
	glad_glGetTextureSamplerHandleARB = (PFNGLGETTEXTURESAMPLERHANDLEARBPROC)load("glGetTextureSamplerHandleARB");
	glad_glMakeTextureHandleResidentARB = (PFNGLMAKETEXTUREHANDLERESIDENTARBPROC)load("glMakeTextureHandleResidentARB");
	glad_glMakeTextureHandleNonResidentARB = (PFNGLMAKETEXTUREHANDLENONRESIDENTARBPROC)load("glMakeTextureHandleNonResidentARB");
	glad_glGetImageHandleARB = (PFNGLGETIMAGEHANDLEARBPROC)load("glGetImageHandleARB");
	glad_glMakeImageHandleResidentARB = (PFNGLMAKEIMAGEHANDLERESIDENTARBPROC)load("glMakeImageHandleResidentARB");
	glad_glMakeImageHandleNonResidentARB = (PFNGLMAKEIMAGEHANDLENONRESIDENTARBPROC)load("glMakeImageHandleNonResidentARB");
	glad_glUniformHandleui64ARB = (PFNGLUNIFORMHANDLEUI64ARBPROC)load("glUniformHandleui64ARB");
	glad_glUniformHandleui64vARB = (PFNGLUNIFORMHANDLEUI64VARBPROC)load("glUniformHandleui64vARB");
	glad_glProgramUniformHandleui64ARB = (PFNGLPROGRAMUNIFORMHANDLEUI64ARBPROC)load("glProgramUniformHandleui64ARB");
	glad_glProgramUniformHandleui64vARB = (PFNGLPROGRAMUNIFORMHANDLEUI64VARBPROC)load("glProgramUniformHandleui64vARB");
	glad_glIsTextureHandleResidentARB = (PFNGLISTEXTUREHANDLERESIDENTARBPROC)load("glIsTextureHandleResidentARB");
	glad_glIsImageHandleResidentARB = (PFNGLISIMAGEHANDLERESIDENTARBPROC)load("glIsImageHandleResidentARB");
	glad_glVertexAttribL1ui64ARB = (PFNGLVERTEXATTRIBL1UI64ARBPROC)load("glVertexAttribL1ui64ARB");
	glad_glVertexAttribL1ui64vARB = (PFNGLVERTEXATTRIBL1UI64VARBPROC)load("glVertexAttribL1ui64vARB");
	glad_glGetVertexAttribLui64vARB = (PFNGLGETVERTEXATTRIBLUI64VARBPROC)load("glGetVertexAttribLui64vARB");
}
static void load_GL_ARB_window_pos(GLADloadproc load) {
	if (!GLAD_GL_ARB_window_pos) return;
	glad_glWindowPos2dARB = (PFNGLWINDOWPOS2DARBPROC)load("glWindowPos2dARB");
	glad_glWindowPos2dvARB = (PFNGLWINDOWPOS2DVARBPROC)load("glWindowPos2dvARB");
	glad_glWindowPos2fARB = (PFNGLWINDOWPOS2FARBPROC)load("glWindowPos2fARB");
	glad_glWindowPos2fvARB = (PFNGLWINDOWPOS2FVARBPROC)load("glWindowPos2fvARB");
	glad_glWindowPos2iARB = (PFNGLWINDOWPOS2IARBPROC)load("glWindowPos2iARB");
	glad_glWindowPos2ivARB = (PFNGLWINDOWPOS2IVARBPROC)load("glWindowPos2ivARB");
	glad_glWindowPos2sARB = (PFNGLWINDOWPOS2SARBPROC)load("glWindowPos2sARB");
	glad_glWindowPos2svARB = (PFNGLWINDOWPOS2SVARBPROC)load("glWindowPos2svARB");
	glad_glWindowPos3dARB = (PFNGLWINDOWPOS3DARBPROC)load("glWindowPos3dARB");
	glad_glWindowPos3dvARB = (PFNGLWINDOWPOS3DVARBPROC)load("glWindowPos3dvARB");
	glad_glWindowPos3fARB = (PFNGLWINDOWPOS3FARBPROC)load("glWindowPos3fARB");
	glad_glWindowPos3fvARB = (PFNGLWINDOWPOS3FVARBPROC)load("glWindowPos3fvARB");
	glad_glWindowPos3iARB = (PFNGLWINDOWPOS3IARBPROC)load("glWindowPos3iARB");
	glad_glWindowPos3ivARB = (PFNGLWINDOWPOS3IVARBPROC)load("glWindowPos3ivARB");
	glad_glWindowPos3sARB = (PFNGLWINDOWPOS3SARBPROC)load("glWindowPos3sARB");
	glad_glWindowPos3svARB = (PFNGLWINDOWPOS3SVARBPROC)load("glWindowPos3svARB");
}
static void load_GL_ARB_internalformat_query(GLADloadproc load) {
	if (!GLAD_GL_ARB_internalformat_query) return;
	glad_glGetInternalformativ = (PFNGLGETINTERNALFORMATIVPROC)load("glGetInternalformativ");
}
static void load_GL_EXT_shader_image_load_store(GLADloadproc load) {
	if (!GLAD_GL_EXT_shader_image_load_store) return;
	glad_glBindImageTextureEXT = (PFNGLBINDIMAGETEXTUREEXTPROC)load("glBindImageTextureEXT");
	glad_glMemoryBarrierEXT = (PFNGLMEMORYBARRIEREXTPROC)load("glMemoryBarrierEXT");
}
static void load_GL_EXT_copy_texture(GLADloadproc load) {
	if (!GLAD_GL_EXT_copy_texture) return;
	glad_glCopyTexImage1DEXT = (PFNGLCOPYTEXIMAGE1DEXTPROC)load("glCopyTexImage1DEXT");
	glad_glCopyTexImage2DEXT = (PFNGLCOPYTEXIMAGE2DEXTPROC)load("glCopyTexImage2DEXT");
	glad_glCopyTexSubImage1DEXT = (PFNGLCOPYTEXSUBIMAGE1DEXTPROC)load("glCopyTexSubImage1DEXT");
	glad_glCopyTexSubImage2DEXT = (PFNGLCOPYTEXSUBIMAGE2DEXTPROC)load("glCopyTexSubImage2DEXT");
	glad_glCopyTexSubImage3DEXT = (PFNGLCOPYTEXSUBIMAGE3DEXTPROC)load("glCopyTexSubImage3DEXT");
}
static void load_GL_NV_register_combiners2(GLADloadproc load) {
	if (!GLAD_GL_NV_register_combiners2) return;
	glad_glCombinerStageParameterfvNV = (PFNGLCOMBINERSTAGEPARAMETERFVNVPROC)load("glCombinerStageParameterfvNV");
	glad_glGetCombinerStageParameterfvNV = (PFNGLGETCOMBINERSTAGEPARAMETERFVNVPROC)load("glGetCombinerStageParameterfvNV");
}
static void load_GL_NV_draw_texture(GLADloadproc load) {
	if (!GLAD_GL_NV_draw_texture) return;
	glad_glDrawTextureNV = (PFNGLDRAWTEXTURENVPROC)load("glDrawTextureNV");
}
static void load_GL_EXT_draw_instanced(GLADloadproc load) {
	if (!GLAD_GL_EXT_draw_instanced) return;
	glad_glDrawArraysInstancedEXT = (PFNGLDRAWARRAYSINSTANCEDEXTPROC)load("glDrawArraysInstancedEXT");
	glad_glDrawElementsInstancedEXT = (PFNGLDRAWELEMENTSINSTANCEDEXTPROC)load("glDrawElementsInstancedEXT");
}
static void load_GL_ARB_viewport_array(GLADloadproc load) {
	if (!GLAD_GL_ARB_viewport_array) return;
	glad_glViewportArrayv = (PFNGLVIEWPORTARRAYVPROC)load("glViewportArrayv");
	glad_glViewportIndexedf = (PFNGLVIEWPORTINDEXEDFPROC)load("glViewportIndexedf");
	glad_glViewportIndexedfv = (PFNGLVIEWPORTINDEXEDFVPROC)load("glViewportIndexedfv");
	glad_glScissorArrayv = (PFNGLSCISSORARRAYVPROC)load("glScissorArrayv");
	glad_glScissorIndexed = (PFNGLSCISSORINDEXEDPROC)load("glScissorIndexed");
	glad_glScissorIndexedv = (PFNGLSCISSORINDEXEDVPROC)load("glScissorIndexedv");
	glad_glDepthRangeArrayv = (PFNGLDEPTHRANGEARRAYVPROC)load("glDepthRangeArrayv");
	glad_glDepthRangeIndexed = (PFNGLDEPTHRANGEINDEXEDPROC)load("glDepthRangeIndexed");
	glad_glGetFloati_v = (PFNGLGETFLOATI_VPROC)load("glGetFloati_v");
	glad_glGetDoublei_v = (PFNGLGETDOUBLEI_VPROC)load("glGetDoublei_v");
}
static void load_GL_ARB_separate_shader_objects(GLADloadproc load) {
	if (!GLAD_GL_ARB_separate_shader_objects) return;
	glad_glUseProgramStages = (PFNGLUSEPROGRAMSTAGESPROC)load("glUseProgramStages");
	glad_glActiveShaderProgram = (PFNGLACTIVESHADERPROGRAMPROC)load("glActiveShaderProgram");
	glad_glCreateShaderProgramv = (PFNGLCREATESHADERPROGRAMVPROC)load("glCreateShaderProgramv");
	glad_glBindProgramPipeline = (PFNGLBINDPROGRAMPIPELINEPROC)load("glBindProgramPipeline");
	glad_glDeleteProgramPipelines = (PFNGLDELETEPROGRAMPIPELINESPROC)load("glDeleteProgramPipelines");
	glad_glGenProgramPipelines = (PFNGLGENPROGRAMPIPELINESPROC)load("glGenProgramPipelines");
	glad_glIsProgramPipeline = (PFNGLISPROGRAMPIPELINEPROC)load("glIsProgramPipeline");
	glad_glGetProgramPipelineiv = (PFNGLGETPROGRAMPIPELINEIVPROC)load("glGetProgramPipelineiv");
	glad_glProgramUniform1i = (PFNGLPROGRAMUNIFORM1IPROC)load("glProgramUniform1i");
	glad_glProgramUniform1iv = (PFNGLPROGRAMUNIFORM1IVPROC)load("glProgramUniform1iv");
	glad_glProgramUniform1f = (PFNGLPROGRAMUNIFORM1FPROC)load("glProgramUniform1f");
	glad_glProgramUniform1fv = (PFNGLPROGRAMUNIFORM1FVPROC)load("glProgramUniform1fv");
	glad_glProgramUniform1d = (PFNGLPROGRAMUNIFORM1DPROC)load("glProgramUniform1d");
	glad_glProgramUniform1dv = (PFNGLPROGRAMUNIFORM1DVPROC)load("glProgramUniform1dv");
	glad_glProgramUniform1ui = (PFNGLPROGRAMUNIFORM1UIPROC)load("glProgramUniform1ui");
	glad_glProgramUniform1uiv = (PFNGLPROGRAMUNIFORM1UIVPROC)load("glProgramUniform1uiv");
	glad_glProgramUniform2i = (PFNGLPROGRAMUNIFORM2IPROC)load("glProgramUniform2i");
	glad_glProgramUniform2iv = (PFNGLPROGRAMUNIFORM2IVPROC)load("glProgramUniform2iv");
	glad_glProgramUniform2f = (PFNGLPROGRAMUNIFORM2FPROC)load("glProgramUniform2f");
	glad_glProgramUniform2fv = (PFNGLPROGRAMUNIFORM2FVPROC)load("glProgramUniform2fv");
	glad_glProgramUniform2d = (PFNGLPROGRAMUNIFORM2DPROC)load("glProgramUniform2d");
	glad_glProgramUniform2dv = (PFNGLPROGRAMUNIFORM2DVPROC)load("glProgramUniform2dv");
	glad_glProgramUniform2ui = (PFNGLPROGRAMUNIFORM2UIPROC)load("glProgramUniform2ui");
	glad_glProgramUniform2uiv = (PFNGLPROGRAMUNIFORM2UIVPROC)load("glProgramUniform2uiv");
	glad_glProgramUniform3i = (PFNGLPROGRAMUNIFORM3IPROC)load("glProgramUniform3i");
	glad_glProgramUniform3iv = (PFNGLPROGRAMUNIFORM3IVPROC)load("glProgramUniform3iv");
	glad_glProgramUniform3f = (PFNGLPROGRAMUNIFORM3FPROC)load("glProgramUniform3f");
	glad_glProgramUniform3fv = (PFNGLPROGRAMUNIFORM3FVPROC)load("glProgramUniform3fv");
	glad_glProgramUniform3d = (PFNGLPROGRAMUNIFORM3DPROC)load("glProgramUniform3d");
	glad_glProgramUniform3dv = (PFNGLPROGRAMUNIFORM3DVPROC)load("glProgramUniform3dv");
	glad_glProgramUniform3ui = (PFNGLPROGRAMUNIFORM3UIPROC)load("glProgramUniform3ui");
	glad_glProgramUniform3uiv = (PFNGLPROGRAMUNIFORM3UIVPROC)load("glProgramUniform3uiv");
	glad_glProgramUniform4i = (PFNGLPROGRAMUNIFORM4IPROC)load("glProgramUniform4i");
	glad_glProgramUniform4iv = (PFNGLPROGRAMUNIFORM4IVPROC)load("glProgramUniform4iv");
	glad_glProgramUniform4f = (PFNGLPROGRAMUNIFORM4FPROC)load("glProgramUniform4f");
	glad_glProgramUniform4fv = (PFNGLPROGRAMUNIFORM4FVPROC)load("glProgramUniform4fv");
	glad_glProgramUniform4d = (PFNGLPROGRAMUNIFORM4DPROC)load("glProgramUniform4d");
	glad_glProgramUniform4dv = (PFNGLPROGRAMUNIFORM4DVPROC)load("glProgramUniform4dv");
	glad_glProgramUniform4ui = (PFNGLPROGRAMUNIFORM4UIPROC)load("glProgramUniform4ui");
	glad_glProgramUniform4uiv = (PFNGLPROGRAMUNIFORM4UIVPROC)load("glProgramUniform4uiv");
	glad_glProgramUniformMatrix2fv = (PFNGLPROGRAMUNIFORMMATRIX2FVPROC)load("glProgramUniformMatrix2fv");
	glad_glProgramUniformMatrix3fv = (PFNGLPROGRAMUNIFORMMATRIX3FVPROC)load("glProgramUniformMatrix3fv");
	glad_glProgramUniformMatrix4fv = (PFNGLPROGRAMUNIFORMMATRIX4FVPROC)load("glProgramUniformMatrix4fv");
	glad_glProgramUniformMatrix2dv = (PFNGLPROGRAMUNIFORMMATRIX2DVPROC)load("glProgramUniformMatrix2dv");
	glad_glProgramUniformMatrix3dv = (PFNGLPROGRAMUNIFORMMATRIX3DVPROC)load("glProgramUniformMatrix3dv");
	glad_glProgramUniformMatrix4dv = (PFNGLPROGRAMUNIFORMMATRIX4DVPROC)load("glProgramUniformMatrix4dv");
	glad_glProgramUniformMatrix2x3fv = (PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC)load("glProgramUniformMatrix2x3fv");
	glad_glProgramUniformMatrix3x2fv = (PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC)load("glProgramUniformMatrix3x2fv");
	glad_glProgramUniformMatrix2x4fv = (PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC)load("glProgramUniformMatrix2x4fv");
	glad_glProgramUniformMatrix4x2fv = (PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC)load("glProgramUniformMatrix4x2fv");
	glad_glProgramUniformMatrix3x4fv = (PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC)load("glProgramUniformMatrix3x4fv");
	glad_glProgramUniformMatrix4x3fv = (PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC)load("glProgramUniformMatrix4x3fv");
	glad_glProgramUniformMatrix2x3dv = (PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC)load("glProgramUniformMatrix2x3dv");
	glad_glProgramUniformMatrix3x2dv = (PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC)load("glProgramUniformMatrix3x2dv");
	glad_glProgramUniformMatrix2x4dv = (PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC)load("glProgramUniformMatrix2x4dv");
	glad_glProgramUniformMatrix4x2dv = (PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC)load("glProgramUniformMatrix4x2dv");
	glad_glProgramUniformMatrix3x4dv = (PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC)load("glProgramUniformMatrix3x4dv");
	glad_glProgramUniformMatrix4x3dv = (PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC)load("glProgramUniformMatrix4x3dv");
	glad_glValidateProgramPipeline = (PFNGLVALIDATEPROGRAMPIPELINEPROC)load("glValidateProgramPipeline");
	glad_glGetProgramPipelineInfoLog = (PFNGLGETPROGRAMPIPELINEINFOLOGPROC)load("glGetProgramPipelineInfoLog");
}
static void load_GL_EXT_depth_bounds_test(GLADloadproc load) {
	if (!GLAD_GL_EXT_depth_bounds_test) return;
	glad_glDepthBoundsEXT = (PFNGLDEPTHBOUNDSEXTPROC)load("glDepthBoundsEXT");
}
static void load_GL_HP_image_transform(GLADloadproc load) {
	if (!GLAD_GL_HP_image_transform) return;
	glad_glImageTransformParameteriHP = (PFNGLIMAGETRANSFORMPARAMETERIHPPROC)load("glImageTransformParameteriHP");
	glad_glImageTransformParameterfHP = (PFNGLIMAGETRANSFORMPARAMETERFHPPROC)load("glImageTransformParameterfHP");
	glad_glImageTransformParameterivHP = (PFNGLIMAGETRANSFORMPARAMETERIVHPPROC)load("glImageTransformParameterivHP");
	glad_glImageTransformParameterfvHP = (PFNGLIMAGETRANSFORMPARAMETERFVHPPROC)load("glImageTransformParameterfvHP");
	glad_glGetImageTransformParameterivHP = (PFNGLGETIMAGETRANSFORMPARAMETERIVHPPROC)load("glGetImageTransformParameterivHP");
	glad_glGetImageTransformParameterfvHP = (PFNGLGETIMAGETRANSFORMPARAMETERFVHPPROC)load("glGetImageTransformParameterfvHP");
}
static void load_GL_NV_video_capture(GLADloadproc load) {
	if (!GLAD_GL_NV_video_capture) return;
	glad_glBeginVideoCaptureNV = (PFNGLBEGINVIDEOCAPTURENVPROC)load("glBeginVideoCaptureNV");
	glad_glBindVideoCaptureStreamBufferNV = (PFNGLBINDVIDEOCAPTURESTREAMBUFFERNVPROC)load("glBindVideoCaptureStreamBufferNV");
	glad_glBindVideoCaptureStreamTextureNV = (PFNGLBINDVIDEOCAPTURESTREAMTEXTURENVPROC)load("glBindVideoCaptureStreamTextureNV");
	glad_glEndVideoCaptureNV = (PFNGLENDVIDEOCAPTURENVPROC)load("glEndVideoCaptureNV");
	glad_glGetVideoCaptureivNV = (PFNGLGETVIDEOCAPTUREIVNVPROC)load("glGetVideoCaptureivNV");
	glad_glGetVideoCaptureStreamivNV = (PFNGLGETVIDEOCAPTURESTREAMIVNVPROC)load("glGetVideoCaptureStreamivNV");
	glad_glGetVideoCaptureStreamfvNV = (PFNGLGETVIDEOCAPTURESTREAMFVNVPROC)load("glGetVideoCaptureStreamfvNV");
	glad_glGetVideoCaptureStreamdvNV = (PFNGLGETVIDEOCAPTURESTREAMDVNVPROC)load("glGetVideoCaptureStreamdvNV");
	glad_glVideoCaptureNV = (PFNGLVIDEOCAPTURENVPROC)load("glVideoCaptureNV");
	glad_glVideoCaptureStreamParameterivNV = (PFNGLVIDEOCAPTURESTREAMPARAMETERIVNVPROC)load("glVideoCaptureStreamParameterivNV");
	glad_glVideoCaptureStreamParameterfvNV = (PFNGLVIDEOCAPTURESTREAMPARAMETERFVNVPROC)load("glVideoCaptureStreamParameterfvNV");
	glad_glVideoCaptureStreamParameterdvNV = (PFNGLVIDEOCAPTURESTREAMPARAMETERDVNVPROC)load("glVideoCaptureStreamParameterdvNV");
}
static void load_GL_ARB_sampler_objects(GLADloadproc load) {
	if (!GLAD_GL_ARB_sampler_objects) return;
	glad_glGenSamplers = (PFNGLGENSAMPLERSPROC)load("glGenSamplers");
	glad_glDeleteSamplers = (PFNGLDELETESAMPLERSPROC)load("glDeleteSamplers");
	glad_glIsSampler = (PFNGLISSAMPLERPROC)load("glIsSampler");
	glad_glBindSampler = (PFNGLBINDSAMPLERPROC)load("glBindSampler");
	glad_glSamplerParameteri = (PFNGLSAMPLERPARAMETERIPROC)load("glSamplerParameteri");
	glad_glSamplerParameteriv = (PFNGLSAMPLERPARAMETERIVPROC)load("glSamplerParameteriv");
	glad_glSamplerParameterf = (PFNGLSAMPLERPARAMETERFPROC)load("glSamplerParameterf");
	glad_glSamplerParameterfv = (PFNGLSAMPLERPARAMETERFVPROC)load("glSamplerParameterfv");
	glad_glSamplerParameterIiv = (PFNGLSAMPLERPARAMETERIIVPROC)load("glSamplerParameterIiv");
	glad_glSamplerParameterIuiv = (PFNGLSAMPLERPARAMETERIUIVPROC)load("glSamplerParameterIuiv");
	glad_glGetSamplerParameteriv = (PFNGLGETSAMPLERPARAMETERIVPROC)load("glGetSamplerParameteriv");
	glad_glGetSamplerParameterIiv = (PFNGLGETSAMPLERPARAMETERIIVPROC)load("glGetSamplerParameterIiv");
	glad_glGetSamplerParameterfv = (PFNGLGETSAMPLERPARAMETERFVPROC)load("glGetSamplerParameterfv");
	glad_glGetSamplerParameterIuiv = (PFNGLGETSAMPLERPARAMETERIUIVPROC)load("glGetSamplerParameterIuiv");
}
static void load_GL_ARB_matrix_palette(GLADloadproc load) {
	if (!GLAD_GL_ARB_matrix_palette) return;
	glad_glCurrentPaletteMatrixARB = (PFNGLCURRENTPALETTEMATRIXARBPROC)load("glCurrentPaletteMatrixARB");
	glad_glMatrixIndexubvARB = (PFNGLMATRIXINDEXUBVARBPROC)load("glMatrixIndexubvARB");
	glad_glMatrixIndexusvARB = (PFNGLMATRIXINDEXUSVARBPROC)load("glMatrixIndexusvARB");
	glad_glMatrixIndexuivARB = (PFNGLMATRIXINDEXUIVARBPROC)load("glMatrixIndexuivARB");
	glad_glMatrixIndexPointerARB = (PFNGLMATRIXINDEXPOINTERARBPROC)load("glMatrixIndexPointerARB");
}
static void load_GL_SGIS_texture_color_mask(GLADloadproc load) {
	if (!GLAD_GL_SGIS_texture_color_mask) return;
	glad_glTextureColorMaskSGIS = (PFNGLTEXTURECOLORMASKSGISPROC)load("glTextureColorMaskSGIS");
}
static void load_GL_ARB_texture_compression(GLADloadproc load) {
	if (!GLAD_GL_ARB_texture_compression) return;
	glad_glCompressedTexImage3DARB = (PFNGLCOMPRESSEDTEXIMAGE3DARBPROC)load("glCompressedTexImage3DARB");
	glad_glCompressedTexImage2DARB = (PFNGLCOMPRESSEDTEXIMAGE2DARBPROC)load("glCompressedTexImage2DARB");
	glad_glCompressedTexImage1DARB = (PFNGLCOMPRESSEDTEXIMAGE1DARBPROC)load("glCompressedTexImage1DARB");
	glad_glCompressedTexSubImage3DARB = (PFNGLCOMPRESSEDTEXSUBIMAGE3DARBPROC)load("glCompressedTexSubImage3DARB");
	glad_glCompressedTexSubImage2DARB = (PFNGLCOMPRESSEDTEXSUBIMAGE2DARBPROC)load("glCompressedTexSubImage2DARB");
	glad_glCompressedTexSubImage1DARB = (PFNGLCOMPRESSEDTEXSUBIMAGE1DARBPROC)load("glCompressedTexSubImage1DARB");
	glad_glGetCompressedTexImageARB = (PFNGLGETCOMPRESSEDTEXIMAGEARBPROC)load("glGetCompressedTexImageARB");
}
static void load_GL_ARB_shader_subroutine(GLADloadproc load) {
	if (!GLAD_GL_ARB_shader_subroutine) return;
	glad_glGetSubroutineUniformLocation = (PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC)load("glGetSubroutineUniformLocation");
	glad_glGetSubroutineIndex = (PFNGLGETSUBROUTINEINDEXPROC)load("glGetSubroutineIndex");
	glad_glGetActiveSubroutineUniformiv = (PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC)load("glGetActiveSubroutineUniformiv");
	glad_glGetActiveSubroutineUniformName = (PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC)load("glGetActiveSubroutineUniformName");
	glad_glGetActiveSubroutineName = (PFNGLGETACTIVESUBROUTINENAMEPROC)load("glGetActiveSubroutineName");
	glad_glUniformSubroutinesuiv = (PFNGLUNIFORMSUBROUTINESUIVPROC)load("glUniformSubroutinesuiv");
	glad_glGetUniformSubroutineuiv = (PFNGLGETUNIFORMSUBROUTINEUIVPROC)load("glGetUniformSubroutineuiv");
	glad_glGetProgramStageiv = (PFNGLGETPROGRAMSTAGEIVPROC)load("glGetProgramStageiv");
}
static void load_GL_ARB_texture_storage_multisample(GLADloadproc load) {
	if (!GLAD_GL_ARB_texture_storage_multisample) return;
	glad_glTexStorage2DMultisample = (PFNGLTEXSTORAGE2DMULTISAMPLEPROC)load("glTexStorage2DMultisample");
	glad_glTexStorage3DMultisample = (PFNGLTEXSTORAGE3DMULTISAMPLEPROC)load("glTexStorage3DMultisample");
}
static void load_GL_EXT_vertex_attrib_64bit(GLADloadproc load) {
	if (!GLAD_GL_EXT_vertex_attrib_64bit) return;
	glad_glVertexAttribL1dEXT = (PFNGLVERTEXATTRIBL1DEXTPROC)load("glVertexAttribL1dEXT");
	glad_glVertexAttribL2dEXT = (PFNGLVERTEXATTRIBL2DEXTPROC)load("glVertexAttribL2dEXT");
	glad_glVertexAttribL3dEXT = (PFNGLVERTEXATTRIBL3DEXTPROC)load("glVertexAttribL3dEXT");
	glad_glVertexAttribL4dEXT = (PFNGLVERTEXATTRIBL4DEXTPROC)load("glVertexAttribL4dEXT");
	glad_glVertexAttribL1dvEXT = (PFNGLVERTEXATTRIBL1DVEXTPROC)load("glVertexAttribL1dvEXT");
	glad_glVertexAttribL2dvEXT = (PFNGLVERTEXATTRIBL2DVEXTPROC)load("glVertexAttribL2dvEXT");
	glad_glVertexAttribL3dvEXT = (PFNGLVERTEXATTRIBL3DVEXTPROC)load("glVertexAttribL3dvEXT");
	glad_glVertexAttribL4dvEXT = (PFNGLVERTEXATTRIBL4DVEXTPROC)load("glVertexAttribL4dvEXT");
	glad_glVertexAttribLPointerEXT = (PFNGLVERTEXATTRIBLPOINTEREXTPROC)load("glVertexAttribLPointerEXT");
	glad_glGetVertexAttribLdvEXT = (PFNGLGETVERTEXATTRIBLDVEXTPROC)load("glGetVertexAttribLdvEXT");
}
static void load_GL_OES_query_matrix(GLADloadproc load) {
	if (!GLAD_GL_OES_query_matrix) return;
	glad_glQueryMatrixxOES = (PFNGLQUERYMATRIXXOESPROC)load("glQueryMatrixxOES");
}
static void load_GL_MESA_window_pos(GLADloadproc load) {
	if (!GLAD_GL_MESA_window_pos) return;
	glad_glWindowPos2dMESA = (PFNGLWINDOWPOS2DMESAPROC)load("glWindowPos2dMESA");
	glad_glWindowPos2dvMESA = (PFNGLWINDOWPOS2DVMESAPROC)load("glWindowPos2dvMESA");
	glad_glWindowPos2fMESA = (PFNGLWINDOWPOS2FMESAPROC)load("glWindowPos2fMESA");
	glad_glWindowPos2fvMESA = (PFNGLWINDOWPOS2FVMESAPROC)load("glWindowPos2fvMESA");
	glad_glWindowPos2iMESA = (PFNGLWINDOWPOS2IMESAPROC)load("glWindowPos2iMESA");
	glad_glWindowPos2ivMESA = (PFNGLWINDOWPOS2IVMESAPROC)load("glWindowPos2ivMESA");
	glad_glWindowPos2sMESA = (PFNGLWINDOWPOS2SMESAPROC)load("glWindowPos2sMESA");
	glad_glWindowPos2svMESA = (PFNGLWINDOWPOS2SVMESAPROC)load("glWindowPos2svMESA");
	glad_glWindowPos3dMESA = (PFNGLWINDOWPOS3DMESAPROC)load("glWindowPos3dMESA");
	glad_glWindowPos3dvMESA = (PFNGLWINDOWPOS3DVMESAPROC)load("glWindowPos3dvMESA");
	glad_glWindowPos3fMESA = (PFNGLWINDOWPOS3FMESAPROC)load("glWindowPos3fMESA");
	glad_glWindowPos3fvMESA = (PFNGLWINDOWPOS3FVMESAPROC)load("glWindowPos3fvMESA");
	glad_glWindowPos3iMESA = (PFNGLWINDOWPOS3IMESAPROC)load("glWindowPos3iMESA");
	glad_glWindowPos3ivMESA = (PFNGLWINDOWPOS3IVMESAPROC)load("glWindowPos3ivMESA");
	glad_glWindowPos3sMESA = (PFNGLWINDOWPOS3SMESAPROC)load("glWindowPos3sMESA");
	glad_glWindowPos3svMESA = (PFNGLWINDOWPOS3SVMESAPROC)load("glWindowPos3svMESA");
	glad_glWindowPos4dMESA = (PFNGLWINDOWPOS4DMESAPROC)load("glWindowPos4dMESA");
	glad_glWindowPos4dvMESA = (PFNGLWINDOWPOS4DVMESAPROC)load("glWindowPos4dvMESA");
	glad_glWindowPos4fMESA = (PFNGLWINDOWPOS4FMESAPROC)load("glWindowPos4fMESA");
	glad_glWindowPos4fvMESA = (PFNGLWINDOWPOS4FVMESAPROC)load("glWindowPos4fvMESA");
	glad_glWindowPos4iMESA = (PFNGLWINDOWPOS4IMESAPROC)load("glWindowPos4iMESA");
	glad_glWindowPos4ivMESA = (PFNGLWINDOWPOS4IVMESAPROC)load("glWindowPos4ivMESA");
	glad_glWindowPos4sMESA = (PFNGLWINDOWPOS4SMESAPROC)load("glWindowPos4sMESA");
	glad_glWindowPos4svMESA = (PFNGLWINDOWPOS4SVMESAPROC)load("glWindowPos4svMESA");
}
static void load_GL_ARB_copy_buffer(GLADloadproc load) {
	if (!GLAD_GL_ARB_copy_buffer) return;
	glad_glCopyBufferSubData = (PFNGLCOPYBUFFERSUBDATAPROC)load("glCopyBufferSubData");
}
static void load_GL_APPLE_object_purgeable(GLADloadproc load) {
	if (!GLAD_GL_APPLE_object_purgeable) return;
	glad_glObjectPurgeableAPPLE = (PFNGLOBJECTPURGEABLEAPPLEPROC)load("glObjectPurgeableAPPLE");
	glad_glObjectUnpurgeableAPPLE = (PFNGLOBJECTUNPURGEABLEAPPLEPROC)load("glObjectUnpurgeableAPPLE");
	glad_glGetObjectParameterivAPPLE = (PFNGLGETOBJECTPARAMETERIVAPPLEPROC)load("glGetObjectParameterivAPPLE");
}
static void load_GL_ARB_occlusion_query(GLADloadproc load) {
	if (!GLAD_GL_ARB_occlusion_query) return;
	glad_glGenQueriesARB = (PFNGLGENQUERIESARBPROC)load("glGenQueriesARB");
	glad_glDeleteQueriesARB = (PFNGLDELETEQUERIESARBPROC)load("glDeleteQueriesARB");
	glad_glIsQueryARB = (PFNGLISQUERYARBPROC)load("glIsQueryARB");
	glad_glBeginQueryARB = (PFNGLBEGINQUERYARBPROC)load("glBeginQueryARB");
	glad_glEndQueryARB = (PFNGLENDQUERYARBPROC)load("glEndQueryARB");
	glad_glGetQueryivARB = (PFNGLGETQUERYIVARBPROC)load("glGetQueryivARB");
	glad_glGetQueryObjectivARB = (PFNGLGETQUERYOBJECTIVARBPROC)load("glGetQueryObjectivARB");
	glad_glGetQueryObjectuivARB = (PFNGLGETQUERYOBJECTUIVARBPROC)load("glGetQueryObjectuivARB");
}
static void load_GL_SGI_color_table(GLADloadproc load) {
	if (!GLAD_GL_SGI_color_table) return;
	glad_glColorTableSGI = (PFNGLCOLORTABLESGIPROC)load("glColorTableSGI");
	glad_glColorTableParameterfvSGI = (PFNGLCOLORTABLEPARAMETERFVSGIPROC)load("glColorTableParameterfvSGI");
	glad_glColorTableParameterivSGI = (PFNGLCOLORTABLEPARAMETERIVSGIPROC)load("glColorTableParameterivSGI");
	glad_glCopyColorTableSGI = (PFNGLCOPYCOLORTABLESGIPROC)load("glCopyColorTableSGI");
	glad_glGetColorTableSGI = (PFNGLGETCOLORTABLESGIPROC)load("glGetColorTableSGI");
	glad_glGetColorTableParameterfvSGI = (PFNGLGETCOLORTABLEPARAMETERFVSGIPROC)load("glGetColorTableParameterfvSGI");
	glad_glGetColorTableParameterivSGI = (PFNGLGETCOLORTABLEPARAMETERIVSGIPROC)load("glGetColorTableParameterivSGI");
}
static void load_GL_EXT_gpu_shader4(GLADloadproc load) {
	if (!GLAD_GL_EXT_gpu_shader4) return;
	glad_glGetUniformuivEXT = (PFNGLGETUNIFORMUIVEXTPROC)load("glGetUniformuivEXT");
	glad_glBindFragDataLocationEXT = (PFNGLBINDFRAGDATALOCATIONEXTPROC)load("glBindFragDataLocationEXT");
	glad_glGetFragDataLocationEXT = (PFNGLGETFRAGDATALOCATIONEXTPROC)load("glGetFragDataLocationEXT");
	glad_glUniform1uiEXT = (PFNGLUNIFORM1UIEXTPROC)load("glUniform1uiEXT");
	glad_glUniform2uiEXT = (PFNGLUNIFORM2UIEXTPROC)load("glUniform2uiEXT");
	glad_glUniform3uiEXT = (PFNGLUNIFORM3UIEXTPROC)load("glUniform3uiEXT");
	glad_glUniform4uiEXT = (PFNGLUNIFORM4UIEXTPROC)load("glUniform4uiEXT");
	glad_glUniform1uivEXT = (PFNGLUNIFORM1UIVEXTPROC)load("glUniform1uivEXT");
	glad_glUniform2uivEXT = (PFNGLUNIFORM2UIVEXTPROC)load("glUniform2uivEXT");
	glad_glUniform3uivEXT = (PFNGLUNIFORM3UIVEXTPROC)load("glUniform3uivEXT");
	glad_glUniform4uivEXT = (PFNGLUNIFORM4UIVEXTPROC)load("glUniform4uivEXT");
}
static void load_GL_NV_geometry_program4(GLADloadproc load) {
	if (!GLAD_GL_NV_geometry_program4) return;
	glad_glProgramVertexLimitNV = (PFNGLPROGRAMVERTEXLIMITNVPROC)load("glProgramVertexLimitNV");
	glad_glFramebufferTextureEXT = (PFNGLFRAMEBUFFERTEXTUREEXTPROC)load("glFramebufferTextureEXT");
	glad_glFramebufferTextureLayerEXT = (PFNGLFRAMEBUFFERTEXTURELAYEREXTPROC)load("glFramebufferTextureLayerEXT");
	glad_glFramebufferTextureFaceEXT = (PFNGLFRAMEBUFFERTEXTUREFACEEXTPROC)load("glFramebufferTextureFaceEXT");
}
static void load_GL_AMD_debug_output(GLADloadproc load) {
	if (!GLAD_GL_AMD_debug_output) return;
	glad_glDebugMessageEnableAMD = (PFNGLDEBUGMESSAGEENABLEAMDPROC)load("glDebugMessageEnableAMD");
	glad_glDebugMessageInsertAMD = (PFNGLDEBUGMESSAGEINSERTAMDPROC)load("glDebugMessageInsertAMD");
	glad_glDebugMessageCallbackAMD = (PFNGLDEBUGMESSAGECALLBACKAMDPROC)load("glDebugMessageCallbackAMD");
	glad_glGetDebugMessageLogAMD = (PFNGLGETDEBUGMESSAGELOGAMDPROC)load("glGetDebugMessageLogAMD");
}
static void load_GL_ARB_multitexture(GLADloadproc load) {
	if (!GLAD_GL_ARB_multitexture) return;
	glad_glActiveTextureARB = (PFNGLACTIVETEXTUREARBPROC)load("glActiveTextureARB");
	glad_glClientActiveTextureARB = (PFNGLCLIENTACTIVETEXTUREARBPROC)load("glClientActiveTextureARB");
	glad_glMultiTexCoord1dARB = (PFNGLMULTITEXCOORD1DARBPROC)load("glMultiTexCoord1dARB");
	glad_glMultiTexCoord1dvARB = (PFNGLMULTITEXCOORD1DVARBPROC)load("glMultiTexCoord1dvARB");
	glad_glMultiTexCoord1fARB = (PFNGLMULTITEXCOORD1FARBPROC)load("glMultiTexCoord1fARB");
	glad_glMultiTexCoord1fvARB = (PFNGLMULTITEXCOORD1FVARBPROC)load("glMultiTexCoord1fvARB");
	glad_glMultiTexCoord1iARB = (PFNGLMULTITEXCOORD1IARBPROC)load("glMultiTexCoord1iARB");
	glad_glMultiTexCoord1ivARB = (PFNGLMULTITEXCOORD1IVARBPROC)load("glMultiTexCoord1ivARB");
	glad_glMultiTexCoord1sARB = (PFNGLMULTITEXCOORD1SARBPROC)load("glMultiTexCoord1sARB");
	glad_glMultiTexCoord1svARB = (PFNGLMULTITEXCOORD1SVARBPROC)load("glMultiTexCoord1svARB");
	glad_glMultiTexCoord2dARB = (PFNGLMULTITEXCOORD2DARBPROC)load("glMultiTexCoord2dARB");
	glad_glMultiTexCoord2dvARB = (PFNGLMULTITEXCOORD2DVARBPROC)load("glMultiTexCoord2dvARB");
	glad_glMultiTexCoord2fARB = (PFNGLMULTITEXCOORD2FARBPROC)load("glMultiTexCoord2fARB");
	glad_glMultiTexCoord2fvARB = (PFNGLMULTITEXCOORD2FVARBPROC)load("glMultiTexCoord2fvARB");
	glad_glMultiTexCoord2iARB = (PFNGLMULTITEXCOORD2IARBPROC)load("glMultiTexCoord2iARB");
	glad_glMultiTexCoord2ivARB = (PFNGLMULTITEXCOORD2IVARBPROC)load("glMultiTexCoord2ivARB");
	glad_glMultiTexCoord2sARB = (PFNGLMULTITEXCOORD2SARBPROC)load("glMultiTexCoord2sARB");
	glad_glMultiTexCoord2svARB = (PFNGLMULTITEXCOORD2SVARBPROC)load("glMultiTexCoord2svARB");
	glad_glMultiTexCoord3dARB = (PFNGLMULTITEXCOORD3DARBPROC)load("glMultiTexCoord3dARB");
	glad_glMultiTexCoord3dvARB = (PFNGLMULTITEXCOORD3DVARBPROC)load("glMultiTexCoord3dvARB");
	glad_glMultiTexCoord3fARB = (PFNGLMULTITEXCOORD3FARBPROC)load("glMultiTexCoord3fARB");
	glad_glMultiTexCoord3fvARB = (PFNGLMULTITEXCOORD3FVARBPROC)load("glMultiTexCoord3fvARB");
	glad_glMultiTexCoord3iARB = (PFNGLMULTITEXCOORD3IARBPROC)load("glMultiTexCoord3iARB");
	glad_glMultiTexCoord3ivARB = (PFNGLMULTITEXCOORD3IVARBPROC)load("glMultiTexCoord3ivARB");
	glad_glMultiTexCoord3sARB = (PFNGLMULTITEXCOORD3SARBPROC)load("glMultiTexCoord3sARB");
	glad_glMultiTexCoord3svARB = (PFNGLMULTITEXCOORD3SVARBPROC)load("glMultiTexCoord3svARB");
	glad_glMultiTexCoord4dARB = (PFNGLMULTITEXCOORD4DARBPROC)load("glMultiTexCoord4dARB");
	glad_glMultiTexCoord4dvARB = (PFNGLMULTITEXCOORD4DVARBPROC)load("glMultiTexCoord4dvARB");
	glad_glMultiTexCoord4fARB = (PFNGLMULTITEXCOORD4FARBPROC)load("glMultiTexCoord4fARB");
	glad_glMultiTexCoord4fvARB = (PFNGLMULTITEXCOORD4FVARBPROC)load("glMultiTexCoord4fvARB");
	glad_glMultiTexCoord4iARB = (PFNGLMULTITEXCOORD4IARBPROC)load("glMultiTexCoord4iARB");
	glad_glMultiTexCoord4ivARB = (PFNGLMULTITEXCOORD4IVARBPROC)load("glMultiTexCoord4ivARB");
	glad_glMultiTexCoord4sARB = (PFNGLMULTITEXCOORD4SARBPROC)load("glMultiTexCoord4sARB");
	glad_glMultiTexCoord4svARB = (PFNGLMULTITEXCOORD4SVARBPROC)load("glMultiTexCoord4svARB");
}
static void load_GL_SGIX_polynomial_ffd(GLADloadproc load) {
	if (!GLAD_GL_SGIX_polynomial_ffd) return;
	glad_glDeformationMap3dSGIX = (PFNGLDEFORMATIONMAP3DSGIXPROC)load("glDeformationMap3dSGIX");
	glad_glDeformationMap3fSGIX = (PFNGLDEFORMATIONMAP3FSGIXPROC)load("glDeformationMap3fSGIX");
	glad_glDeformSGIX = (PFNGLDEFORMSGIXPROC)load("glDeformSGIX");
	glad_glLoadIdentityDeformationMapSGIX = (PFNGLLOADIDENTITYDEFORMATIONMAPSGIXPROC)load("glLoadIdentityDeformationMapSGIX");
}
static void load_GL_EXT_provoking_vertex(GLADloadproc load) {
	if (!GLAD_GL_EXT_provoking_vertex) return;
	glad_glProvokingVertexEXT = (PFNGLPROVOKINGVERTEXEXTPROC)load("glProvokingVertexEXT");
}
static void load_GL_ARB_point_parameters(GLADloadproc load) {
	if (!GLAD_GL_ARB_point_parameters) return;
	glad_glPointParameterfARB = (PFNGLPOINTPARAMETERFARBPROC)load("glPointParameterfARB");
	glad_glPointParameterfvARB = (PFNGLPOINTPARAMETERFVARBPROC)load("glPointParameterfvARB");
}
static void load_GL_ARB_shader_image_load_store(GLADloadproc load) {
	if (!GLAD_GL_ARB_shader_image_load_store) return;
	glad_glBindImageTexture = (PFNGLBINDIMAGETEXTUREPROC)load("glBindImageTexture");
	glad_glMemoryBarrier = (PFNGLMEMORYBARRIERPROC)load("glMemoryBarrier");
}
static void load_GL_ARB_texture_barrier(GLADloadproc load) {
	if (!GLAD_GL_ARB_texture_barrier) return;
	glad_glTextureBarrier = (PFNGLTEXTUREBARRIERPROC)load("glTextureBarrier");
}
static void load_GL_NV_bindless_multi_draw_indirect(GLADloadproc load) {
	if (!GLAD_GL_NV_bindless_multi_draw_indirect) return;
	glad_glMultiDrawArraysIndirectBindlessNV = (PFNGLMULTIDRAWARRAYSINDIRECTBINDLESSNVPROC)load("glMultiDrawArraysIndirectBindlessNV");
	glad_glMultiDrawElementsIndirectBindlessNV = (PFNGLMULTIDRAWELEMENTSINDIRECTBINDLESSNVPROC)load("glMultiDrawElementsIndirectBindlessNV");
}
static void load_GL_EXT_transform_feedback(GLADloadproc load) {
	if (!GLAD_GL_EXT_transform_feedback) return;
	glad_glBeginTransformFeedbackEXT = (PFNGLBEGINTRANSFORMFEEDBACKEXTPROC)load("glBeginTransformFeedbackEXT");
	glad_glEndTransformFeedbackEXT = (PFNGLENDTRANSFORMFEEDBACKEXTPROC)load("glEndTransformFeedbackEXT");
	glad_glBindBufferRangeEXT = (PFNGLBINDBUFFERRANGEEXTPROC)load("glBindBufferRangeEXT");
	glad_glBindBufferOffsetEXT = (PFNGLBINDBUFFEROFFSETEXTPROC)load("glBindBufferOffsetEXT");
	glad_glBindBufferBaseEXT = (PFNGLBINDBUFFERBASEEXTPROC)load("glBindBufferBaseEXT");
	glad_glTransformFeedbackVaryingsEXT = (PFNGLTRANSFORMFEEDBACKVARYINGSEXTPROC)load("glTransformFeedbackVaryingsEXT");
	glad_glGetTransformFeedbackVaryingEXT = (PFNGLGETTRANSFORMFEEDBACKVARYINGEXTPROC)load("glGetTransformFeedbackVaryingEXT");
}
static void load_GL_NV_gpu_program4(GLADloadproc load) {
	if (!GLAD_GL_NV_gpu_program4) return;
	glad_glProgramLocalParameterI4iNV = (PFNGLPROGRAMLOCALPARAMETERI4INVPROC)load("glProgramLocalParameterI4iNV");
	glad_glProgramLocalParameterI4ivNV = (PFNGLPROGRAMLOCALPARAMETERI4IVNVPROC)load("glProgramLocalParameterI4ivNV");
	glad_glProgramLocalParametersI4ivNV = (PFNGLPROGRAMLOCALPARAMETERSI4IVNVPROC)load("glProgramLocalParametersI4ivNV");
	glad_glProgramLocalParameterI4uiNV = (PFNGLPROGRAMLOCALPARAMETERI4UINVPROC)load("glProgramLocalParameterI4uiNV");
	glad_glProgramLocalParameterI4uivNV = (PFNGLPROGRAMLOCALPARAMETERI4UIVNVPROC)load("glProgramLocalParameterI4uivNV");
	glad_glProgramLocalParametersI4uivNV = (PFNGLPROGRAMLOCALPARAMETERSI4UIVNVPROC)load("glProgramLocalParametersI4uivNV");
	glad_glProgramEnvParameterI4iNV = (PFNGLPROGRAMENVPARAMETERI4INVPROC)load("glProgramEnvParameterI4iNV");
	glad_glProgramEnvParameterI4ivNV = (PFNGLPROGRAMENVPARAMETERI4IVNVPROC)load("glProgramEnvParameterI4ivNV");
	glad_glProgramEnvParametersI4ivNV = (PFNGLPROGRAMENVPARAMETERSI4IVNVPROC)load("glProgramEnvParametersI4ivNV");
	glad_glProgramEnvParameterI4uiNV = (PFNGLPROGRAMENVPARAMETERI4UINVPROC)load("glProgramEnvParameterI4uiNV");
	glad_glProgramEnvParameterI4uivNV = (PFNGLPROGRAMENVPARAMETERI4UIVNVPROC)load("glProgramEnvParameterI4uivNV");
	glad_glProgramEnvParametersI4uivNV = (PFNGLPROGRAMENVPARAMETERSI4UIVNVPROC)load("glProgramEnvParametersI4uivNV");
	glad_glGetProgramLocalParameterIivNV = (PFNGLGETPROGRAMLOCALPARAMETERIIVNVPROC)load("glGetProgramLocalParameterIivNV");
	glad_glGetProgramLocalParameterIuivNV = (PFNGLGETPROGRAMLOCALPARAMETERIUIVNVPROC)load("glGetProgramLocalParameterIuivNV");
	glad_glGetProgramEnvParameterIivNV = (PFNGLGETPROGRAMENVPARAMETERIIVNVPROC)load("glGetProgramEnvParameterIivNV");
	glad_glGetProgramEnvParameterIuivNV = (PFNGLGETPROGRAMENVPARAMETERIUIVNVPROC)load("glGetProgramEnvParameterIuivNV");
}
static void load_GL_NV_gpu_program5(GLADloadproc load) {
	if (!GLAD_GL_NV_gpu_program5) return;
	glad_glProgramSubroutineParametersuivNV = (PFNGLPROGRAMSUBROUTINEPARAMETERSUIVNVPROC)load("glProgramSubroutineParametersuivNV");
	glad_glGetProgramSubroutineParameteruivNV = (PFNGLGETPROGRAMSUBROUTINEPARAMETERUIVNVPROC)load("glGetProgramSubroutineParameteruivNV");
}
static void load_GL_ARB_geometry_shader4(GLADloadproc load) {
	if (!GLAD_GL_ARB_geometry_shader4) return;
	glad_glProgramParameteriARB = (PFNGLPROGRAMPARAMETERIARBPROC)load("glProgramParameteriARB");
	glad_glFramebufferTextureARB = (PFNGLFRAMEBUFFERTEXTUREARBPROC)load("glFramebufferTextureARB");
	glad_glFramebufferTextureLayerARB = (PFNGLFRAMEBUFFERTEXTURELAYERARBPROC)load("glFramebufferTextureLayerARB");
	glad_glFramebufferTextureFaceARB = (PFNGLFRAMEBUFFERTEXTUREFACEARBPROC)load("glFramebufferTextureFaceARB");
}
static void load_GL_NV_conservative_raster(GLADloadproc load) {
	if (!GLAD_GL_NV_conservative_raster) return;
	glad_glSubpixelPrecisionBiasNV = (PFNGLSUBPIXELPRECISIONBIASNVPROC)load("glSubpixelPrecisionBiasNV");
}
static void load_GL_SGIX_sprite(GLADloadproc load) {
	if (!GLAD_GL_SGIX_sprite) return;
	glad_glSpriteParameterfSGIX = (PFNGLSPRITEPARAMETERFSGIXPROC)load("glSpriteParameterfSGIX");
	glad_glSpriteParameterfvSGIX = (PFNGLSPRITEPARAMETERFVSGIXPROC)load("glSpriteParameterfvSGIX");
	glad_glSpriteParameteriSGIX = (PFNGLSPRITEPARAMETERISGIXPROC)load("glSpriteParameteriSGIX");
	glad_glSpriteParameterivSGIX = (PFNGLSPRITEPARAMETERIVSGIXPROC)load("glSpriteParameterivSGIX");
}
static void load_GL_ARB_get_program_binary(GLADloadproc load) {
	if (!GLAD_GL_ARB_get_program_binary) return;
	glad_glGetProgramBinary = (PFNGLGETPROGRAMBINARYPROC)load("glGetProgramBinary");
	glad_glProgramBinary = (PFNGLPROGRAMBINARYPROC)load("glProgramBinary");
	glad_glProgramParameteri = (PFNGLPROGRAMPARAMETERIPROC)load("glProgramParameteri");
}
static void load_GL_AMD_occlusion_query_event(GLADloadproc load) {
	if (!GLAD_GL_AMD_occlusion_query_event) return;
	glad_glQueryObjectParameteruiAMD = (PFNGLQUERYOBJECTPARAMETERUIAMDPROC)load("glQueryObjectParameteruiAMD");
}
static void load_GL_SGIS_multisample(GLADloadproc load) {
	if (!GLAD_GL_SGIS_multisample) return;
	glad_glSampleMaskSGIS = (PFNGLSAMPLEMASKSGISPROC)load("glSampleMaskSGIS");
	glad_glSamplePatternSGIS = (PFNGLSAMPLEPATTERNSGISPROC)load("glSamplePatternSGIS");
}
static void load_GL_EXT_framebuffer_object(GLADloadproc load) {
	if (!GLAD_GL_EXT_framebuffer_object) return;
	glad_glIsRenderbufferEXT = (PFNGLISRENDERBUFFEREXTPROC)load("glIsRenderbufferEXT");
	glad_glBindRenderbufferEXT = (PFNGLBINDRENDERBUFFEREXTPROC)load("glBindRenderbufferEXT");
	glad_glDeleteRenderbuffersEXT = (PFNGLDELETERENDERBUFFERSEXTPROC)load("glDeleteRenderbuffersEXT");
	glad_glGenRenderbuffersEXT = (PFNGLGENRENDERBUFFERSEXTPROC)load("glGenRenderbuffersEXT");
	glad_glRenderbufferStorageEXT = (PFNGLRENDERBUFFERSTORAGEEXTPROC)load("glRenderbufferStorageEXT");
	glad_glGetRenderbufferParameterivEXT = (PFNGLGETRENDERBUFFERPARAMETERIVEXTPROC)load("glGetRenderbufferParameterivEXT");
	glad_glIsFramebufferEXT = (PFNGLISFRAMEBUFFEREXTPROC)load("glIsFramebufferEXT");
	glad_glBindFramebufferEXT = (PFNGLBINDFRAMEBUFFEREXTPROC)load("glBindFramebufferEXT");
	glad_glDeleteFramebuffersEXT = (PFNGLDELETEFRAMEBUFFERSEXTPROC)load("glDeleteFramebuffersEXT");
	glad_glGenFramebuffersEXT = (PFNGLGENFRAMEBUFFERSEXTPROC)load("glGenFramebuffersEXT");
	glad_glCheckFramebufferStatusEXT = (PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC)load("glCheckFramebufferStatusEXT");
	glad_glFramebufferTexture1DEXT = (PFNGLFRAMEBUFFERTEXTURE1DEXTPROC)load("glFramebufferTexture1DEXT");
	glad_glFramebufferTexture2DEXT = (PFNGLFRAMEBUFFERTEXTURE2DEXTPROC)load("glFramebufferTexture2DEXT");
	glad_glFramebufferTexture3DEXT = (PFNGLFRAMEBUFFERTEXTURE3DEXTPROC)load("glFramebufferTexture3DEXT");
	glad_glFramebufferRenderbufferEXT = (PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC)load("glFramebufferRenderbufferEXT");
	glad_glGetFramebufferAttachmentParameterivEXT = (PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC)load("glGetFramebufferAttachmentParameterivEXT");
	glad_glGenerateMipmapEXT = (PFNGLGENERATEMIPMAPEXTPROC)load("glGenerateMipmapEXT");
}
static void load_GL_APPLE_vertex_array_range(GLADloadproc load) {
	if (!GLAD_GL_APPLE_vertex_array_range) return;
	glad_glVertexArrayRangeAPPLE = (PFNGLVERTEXARRAYRANGEAPPLEPROC)load("glVertexArrayRangeAPPLE");
	glad_glFlushVertexArrayRangeAPPLE = (PFNGLFLUSHVERTEXARRAYRANGEAPPLEPROC)load("glFlushVertexArrayRangeAPPLE");
	glad_glVertexArrayParameteriAPPLE = (PFNGLVERTEXARRAYPARAMETERIAPPLEPROC)load("glVertexArrayParameteriAPPLE");
}
static void load_GL_NV_register_combiners(GLADloadproc load) {
	if (!GLAD_GL_NV_register_combiners) return;
	glad_glCombinerParameterfvNV = (PFNGLCOMBINERPARAMETERFVNVPROC)load("glCombinerParameterfvNV");
	glad_glCombinerParameterfNV = (PFNGLCOMBINERPARAMETERFNVPROC)load("glCombinerParameterfNV");
	glad_glCombinerParameterivNV = (PFNGLCOMBINERPARAMETERIVNVPROC)load("glCombinerParameterivNV");
	glad_glCombinerParameteriNV = (PFNGLCOMBINERPARAMETERINVPROC)load("glCombinerParameteriNV");
	glad_glCombinerInputNV = (PFNGLCOMBINERINPUTNVPROC)load("glCombinerInputNV");
	glad_glCombinerOutputNV = (PFNGLCOMBINEROUTPUTNVPROC)load("glCombinerOutputNV");
	glad_glFinalCombinerInputNV = (PFNGLFINALCOMBINERINPUTNVPROC)load("glFinalCombinerInputNV");
	glad_glGetCombinerInputParameterfvNV = (PFNGLGETCOMBINERINPUTPARAMETERFVNVPROC)load("glGetCombinerInputParameterfvNV");
	glad_glGetCombinerInputParameterivNV = (PFNGLGETCOMBINERINPUTPARAMETERIVNVPROC)load("glGetCombinerInputParameterivNV");
	glad_glGetCombinerOutputParameterfvNV = (PFNGLGETCOMBINEROUTPUTPARAMETERFVNVPROC)load("glGetCombinerOutputParameterfvNV");
	glad_glGetCombinerOutputParameterivNV = (PFNGLGETCOMBINEROUTPUTPARAMETERIVNVPROC)load("glGetCombinerOutputParameterivNV");
	glad_glGetFinalCombinerInputParameterfvNV = (PFNGLGETFINALCOMBINERINPUTPARAMETERFVNVPROC)load("glGetFinalCombinerInputParameterfvNV");
	glad_glGetFinalCombinerInputParameterivNV = (PFNGLGETFINALCOMBINERINPUTPARAMETERIVNVPROC)load("glGetFinalCombinerInputParameterivNV");
}
static void load_GL_ARB_draw_buffers(GLADloadproc load) {
	if (!GLAD_GL_ARB_draw_buffers) return;
	glad_glDrawBuffersARB = (PFNGLDRAWBUFFERSARBPROC)load("glDrawBuffersARB");
}
static void load_GL_ARB_debug_output(GLADloadproc load) {
	if (!GLAD_GL_ARB_debug_output) return;
	glad_glDebugMessageControlARB = (PFNGLDEBUGMESSAGECONTROLARBPROC)load("glDebugMessageControlARB");
	glad_glDebugMessageInsertARB = (PFNGLDEBUGMESSAGEINSERTARBPROC)load("glDebugMessageInsertARB");
	glad_glDebugMessageCallbackARB = (PFNGLDEBUGMESSAGECALLBACKARBPROC)load("glDebugMessageCallbackARB");
	glad_glGetDebugMessageLogARB = (PFNGLGETDEBUGMESSAGELOGARBPROC)load("glGetDebugMessageLogARB");
}
static void load_GL_EXT_cull_vertex(GLADloadproc load) {
	if (!GLAD_GL_EXT_cull_vertex) return;
	glad_glCullParameterdvEXT = (PFNGLCULLPARAMETERDVEXTPROC)load("glCullParameterdvEXT");
	glad_glCullParameterfvEXT = (PFNGLCULLPARAMETERFVEXTPROC)load("glCullParameterfvEXT");
}
static void load_GL_IBM_multimode_draw_arrays(GLADloadproc load) {
	if (!GLAD_GL_IBM_multimode_draw_arrays) return;
	glad_glMultiModeDrawArraysIBM = (PFNGLMULTIMODEDRAWARRAYSIBMPROC)load("glMultiModeDrawArraysIBM");
	glad_glMultiModeDrawElementsIBM = (PFNGLMULTIMODEDRAWELEMENTSIBMPROC)load("glMultiModeDrawElementsIBM");
}
static void load_GL_APPLE_vertex_array_object(GLADloadproc load) {
	if (!GLAD_GL_APPLE_vertex_array_object) return;
	glad_glBindVertexArrayAPPLE = (PFNGLBINDVERTEXARRAYAPPLEPROC)load("glBindVertexArrayAPPLE");
	glad_glDeleteVertexArraysAPPLE = (PFNGLDELETEVERTEXARRAYSAPPLEPROC)load("glDeleteVertexArraysAPPLE");
	glad_glGenVertexArraysAPPLE = (PFNGLGENVERTEXARRAYSAPPLEPROC)load("glGenVertexArraysAPPLE");
	glad_glIsVertexArrayAPPLE = (PFNGLISVERTEXARRAYAPPLEPROC)load("glIsVertexArrayAPPLE");
}
static void load_GL_SGIS_detail_texture(GLADloadproc load) {
	if (!GLAD_GL_SGIS_detail_texture) return;
	glad_glDetailTexFuncSGIS = (PFNGLDETAILTEXFUNCSGISPROC)load("glDetailTexFuncSGIS");
	glad_glGetDetailTexFuncSGIS = (PFNGLGETDETAILTEXFUNCSGISPROC)load("glGetDetailTexFuncSGIS");
}
static void load_GL_ARB_draw_instanced(GLADloadproc load) {
	if (!GLAD_GL_ARB_draw_instanced) return;
	glad_glDrawArraysInstancedARB = (PFNGLDRAWARRAYSINSTANCEDARBPROC)load("glDrawArraysInstancedARB");
	glad_glDrawElementsInstancedARB = (PFNGLDRAWELEMENTSINSTANCEDARBPROC)load("glDrawElementsInstancedARB");
}
static void load_GL_ARB_shading_language_include(GLADloadproc load) {
	if (!GLAD_GL_ARB_shading_language_include) return;
	glad_glNamedStringARB = (PFNGLNAMEDSTRINGARBPROC)load("glNamedStringARB");
	glad_glDeleteNamedStringARB = (PFNGLDELETENAMEDSTRINGARBPROC)load("glDeleteNamedStringARB");
	glad_glCompileShaderIncludeARB = (PFNGLCOMPILESHADERINCLUDEARBPROC)load("glCompileShaderIncludeARB");
	glad_glIsNamedStringARB = (PFNGLISNAMEDSTRINGARBPROC)load("glIsNamedStringARB");
	glad_glGetNamedStringARB = (PFNGLGETNAMEDSTRINGARBPROC)load("glGetNamedStringARB");
	glad_glGetNamedStringivARB = (PFNGLGETNAMEDSTRINGIVARBPROC)load("glGetNamedStringivARB");
}
static void load_GL_INGR_blend_func_separate(GLADloadproc load) {
	if (!GLAD_GL_INGR_blend_func_separate) return;
	glad_glBlendFuncSeparateINGR = (PFNGLBLENDFUNCSEPARATEINGRPROC)load("glBlendFuncSeparateINGR");
}
static void load_GL_NV_path_rendering(GLADloadproc load) {
	if (!GLAD_GL_NV_path_rendering) return;
	glad_glGenPathsNV = (PFNGLGENPATHSNVPROC)load("glGenPathsNV");
	glad_glDeletePathsNV = (PFNGLDELETEPATHSNVPROC)load("glDeletePathsNV");
	glad_glIsPathNV = (PFNGLISPATHNVPROC)load("glIsPathNV");
	glad_glPathCommandsNV = (PFNGLPATHCOMMANDSNVPROC)load("glPathCommandsNV");
	glad_glPathCoordsNV = (PFNGLPATHCOORDSNVPROC)load("glPathCoordsNV");
	glad_glPathSubCommandsNV = (PFNGLPATHSUBCOMMANDSNVPROC)load("glPathSubCommandsNV");
	glad_glPathSubCoordsNV = (PFNGLPATHSUBCOORDSNVPROC)load("glPathSubCoordsNV");
	glad_glPathStringNV = (PFNGLPATHSTRINGNVPROC)load("glPathStringNV");
	glad_glPathGlyphsNV = (PFNGLPATHGLYPHSNVPROC)load("glPathGlyphsNV");
	glad_glPathGlyphRangeNV = (PFNGLPATHGLYPHRANGENVPROC)load("glPathGlyphRangeNV");
	glad_glWeightPathsNV = (PFNGLWEIGHTPATHSNVPROC)load("glWeightPathsNV");
	glad_glCopyPathNV = (PFNGLCOPYPATHNVPROC)load("glCopyPathNV");
	glad_glInterpolatePathsNV = (PFNGLINTERPOLATEPATHSNVPROC)load("glInterpolatePathsNV");
	glad_glTransformPathNV = (PFNGLTRANSFORMPATHNVPROC)load("glTransformPathNV");
	glad_glPathParameterivNV = (PFNGLPATHPARAMETERIVNVPROC)load("glPathParameterivNV");
	glad_glPathParameteriNV = (PFNGLPATHPARAMETERINVPROC)load("glPathParameteriNV");
	glad_glPathParameterfvNV = (PFNGLPATHPARAMETERFVNVPROC)load("glPathParameterfvNV");
	glad_glPathParameterfNV = (PFNGLPATHPARAMETERFNVPROC)load("glPathParameterfNV");
	glad_glPathDashArrayNV = (PFNGLPATHDASHARRAYNVPROC)load("glPathDashArrayNV");
	glad_glPathStencilFuncNV = (PFNGLPATHSTENCILFUNCNVPROC)load("glPathStencilFuncNV");
	glad_glPathStencilDepthOffsetNV = (PFNGLPATHSTENCILDEPTHOFFSETNVPROC)load("glPathStencilDepthOffsetNV");
	glad_glStencilFillPathNV = (PFNGLSTENCILFILLPATHNVPROC)load("glStencilFillPathNV");
	glad_glStencilStrokePathNV = (PFNGLSTENCILSTROKEPATHNVPROC)load("glStencilStrokePathNV");
	glad_glStencilFillPathInstancedNV = (PFNGLSTENCILFILLPATHINSTANCEDNVPROC)load("glStencilFillPathInstancedNV");
	glad_glStencilStrokePathInstancedNV = (PFNGLSTENCILSTROKEPATHINSTANCEDNVPROC)load("glStencilStrokePathInstancedNV");
	glad_glPathCoverDepthFuncNV = (PFNGLPATHCOVERDEPTHFUNCNVPROC)load("glPathCoverDepthFuncNV");
	glad_glCoverFillPathNV = (PFNGLCOVERFILLPATHNVPROC)load("glCoverFillPathNV");
	glad_glCoverStrokePathNV = (PFNGLCOVERSTROKEPATHNVPROC)load("glCoverStrokePathNV");
	glad_glCoverFillPathInstancedNV = (PFNGLCOVERFILLPATHINSTANCEDNVPROC)load("glCoverFillPathInstancedNV");
	glad_glCoverStrokePathInstancedNV = (PFNGLCOVERSTROKEPATHINSTANCEDNVPROC)load("glCoverStrokePathInstancedNV");
	glad_glGetPathParameterivNV = (PFNGLGETPATHPARAMETERIVNVPROC)load("glGetPathParameterivNV");
	glad_glGetPathParameterfvNV = (PFNGLGETPATHPARAMETERFVNVPROC)load("glGetPathParameterfvNV");
	glad_glGetPathCommandsNV = (PFNGLGETPATHCOMMANDSNVPROC)load("glGetPathCommandsNV");
	glad_glGetPathCoordsNV = (PFNGLGETPATHCOORDSNVPROC)load("glGetPathCoordsNV");
	glad_glGetPathDashArrayNV = (PFNGLGETPATHDASHARRAYNVPROC)load("glGetPathDashArrayNV");
	glad_glGetPathMetricsNV = (PFNGLGETPATHMETRICSNVPROC)load("glGetPathMetricsNV");
	glad_glGetPathMetricRangeNV = (PFNGLGETPATHMETRICRANGENVPROC)load("glGetPathMetricRangeNV");
	glad_glGetPathSpacingNV = (PFNGLGETPATHSPACINGNVPROC)load("glGetPathSpacingNV");
	glad_glIsPointInFillPathNV = (PFNGLISPOINTINFILLPATHNVPROC)load("glIsPointInFillPathNV");
	glad_glIsPointInStrokePathNV = (PFNGLISPOINTINSTROKEPATHNVPROC)load("glIsPointInStrokePathNV");
	glad_glGetPathLengthNV = (PFNGLGETPATHLENGTHNVPROC)load("glGetPathLengthNV");
	glad_glPointAlongPathNV = (PFNGLPOINTALONGPATHNVPROC)load("glPointAlongPathNV");
	glad_glMatrixLoad3x2fNV = (PFNGLMATRIXLOAD3X2FNVPROC)load("glMatrixLoad3x2fNV");
	glad_glMatrixLoad3x3fNV = (PFNGLMATRIXLOAD3X3FNVPROC)load("glMatrixLoad3x3fNV");
	glad_glMatrixLoadTranspose3x3fNV = (PFNGLMATRIXLOADTRANSPOSE3X3FNVPROC)load("glMatrixLoadTranspose3x3fNV");
	glad_glMatrixMult3x2fNV = (PFNGLMATRIXMULT3X2FNVPROC)load("glMatrixMult3x2fNV");
	glad_glMatrixMult3x3fNV = (PFNGLMATRIXMULT3X3FNVPROC)load("glMatrixMult3x3fNV");
	glad_glMatrixMultTranspose3x3fNV = (PFNGLMATRIXMULTTRANSPOSE3X3FNVPROC)load("glMatrixMultTranspose3x3fNV");
	glad_glStencilThenCoverFillPathNV = (PFNGLSTENCILTHENCOVERFILLPATHNVPROC)load("glStencilThenCoverFillPathNV");
	glad_glStencilThenCoverStrokePathNV = (PFNGLSTENCILTHENCOVERSTROKEPATHNVPROC)load("glStencilThenCoverStrokePathNV");
	glad_glStencilThenCoverFillPathInstancedNV = (PFNGLSTENCILTHENCOVERFILLPATHINSTANCEDNVPROC)load("glStencilThenCoverFillPathInstancedNV");
	glad_glStencilThenCoverStrokePathInstancedNV = (PFNGLSTENCILTHENCOVERSTROKEPATHINSTANCEDNVPROC)load("glStencilThenCoverStrokePathInstancedNV");
	glad_glPathGlyphIndexRangeNV = (PFNGLPATHGLYPHINDEXRANGENVPROC)load("glPathGlyphIndexRangeNV");
	glad_glPathGlyphIndexArrayNV = (PFNGLPATHGLYPHINDEXARRAYNVPROC)load("glPathGlyphIndexArrayNV");
	glad_glPathMemoryGlyphIndexArrayNV = (PFNGLPATHMEMORYGLYPHINDEXARRAYNVPROC)load("glPathMemoryGlyphIndexArrayNV");
	glad_glProgramPathFragmentInputGenNV = (PFNGLPROGRAMPATHFRAGMENTINPUTGENNVPROC)load("glProgramPathFragmentInputGenNV");
	glad_glGetProgramResourcefvNV = (PFNGLGETPROGRAMRESOURCEFVNVPROC)load("glGetProgramResourcefvNV");
	glad_glPathColorGenNV = (PFNGLPATHCOLORGENNVPROC)load("glPathColorGenNV");
	glad_glPathTexGenNV = (PFNGLPATHTEXGENNVPROC)load("glPathTexGenNV");
	glad_glPathFogGenNV = (PFNGLPATHFOGGENNVPROC)load("glPathFogGenNV");
	glad_glGetPathColorGenivNV = (PFNGLGETPATHCOLORGENIVNVPROC)load("glGetPathColorGenivNV");
	glad_glGetPathColorGenfvNV = (PFNGLGETPATHCOLORGENFVNVPROC)load("glGetPathColorGenfvNV");
	glad_glGetPathTexGenivNV = (PFNGLGETPATHTEXGENIVNVPROC)load("glGetPathTexGenivNV");
	glad_glGetPathTexGenfvNV = (PFNGLGETPATHTEXGENFVNVPROC)load("glGetPathTexGenfvNV");
}
static void load_GL_ATI_vertex_streams(GLADloadproc load) {
	if (!GLAD_GL_ATI_vertex_streams) return;
	glad_glVertexStream1sATI = (PFNGLVERTEXSTREAM1SATIPROC)load("glVertexStream1sATI");
	glad_glVertexStream1svATI = (PFNGLVERTEXSTREAM1SVATIPROC)load("glVertexStream1svATI");
	glad_glVertexStream1iATI = (PFNGLVERTEXSTREAM1IATIPROC)load("glVertexStream1iATI");
	glad_glVertexStream1ivATI = (PFNGLVERTEXSTREAM1IVATIPROC)load("glVertexStream1ivATI");
	glad_glVertexStream1fATI = (PFNGLVERTEXSTREAM1FATIPROC)load("glVertexStream1fATI");
	glad_glVertexStream1fvATI = (PFNGLVERTEXSTREAM1FVATIPROC)load("glVertexStream1fvATI");
	glad_glVertexStream1dATI = (PFNGLVERTEXSTREAM1DATIPROC)load("glVertexStream1dATI");
	glad_glVertexStream1dvATI = (PFNGLVERTEXSTREAM1DVATIPROC)load("glVertexStream1dvATI");
	glad_glVertexStream2sATI = (PFNGLVERTEXSTREAM2SATIPROC)load("glVertexStream2sATI");
	glad_glVertexStream2svATI = (PFNGLVERTEXSTREAM2SVATIPROC)load("glVertexStream2svATI");
	glad_glVertexStream2iATI = (PFNGLVERTEXSTREAM2IATIPROC)load("glVertexStream2iATI");
	glad_glVertexStream2ivATI = (PFNGLVERTEXSTREAM2IVATIPROC)load("glVertexStream2ivATI");
	glad_glVertexStream2fATI = (PFNGLVERTEXSTREAM2FATIPROC)load("glVertexStream2fATI");
	glad_glVertexStream2fvATI = (PFNGLVERTEXSTREAM2FVATIPROC)load("glVertexStream2fvATI");
	glad_glVertexStream2dATI = (PFNGLVERTEXSTREAM2DATIPROC)load("glVertexStream2dATI");
	glad_glVertexStream2dvATI = (PFNGLVERTEXSTREAM2DVATIPROC)load("glVertexStream2dvATI");
	glad_glVertexStream3sATI = (PFNGLVERTEXSTREAM3SATIPROC)load("glVertexStream3sATI");
	glad_glVertexStream3svATI = (PFNGLVERTEXSTREAM3SVATIPROC)load("glVertexStream3svATI");
	glad_glVertexStream3iATI = (PFNGLVERTEXSTREAM3IATIPROC)load("glVertexStream3iATI");
	glad_glVertexStream3ivATI = (PFNGLVERTEXSTREAM3IVATIPROC)load("glVertexStream3ivATI");
	glad_glVertexStream3fATI = (PFNGLVERTEXSTREAM3FATIPROC)load("glVertexStream3fATI");
	glad_glVertexStream3fvATI = (PFNGLVERTEXSTREAM3FVATIPROC)load("glVertexStream3fvATI");
	glad_glVertexStream3dATI = (PFNGLVERTEXSTREAM3DATIPROC)load("glVertexStream3dATI");
	glad_glVertexStream3dvATI = (PFNGLVERTEXSTREAM3DVATIPROC)load("glVertexStream3dvATI");
	glad_glVertexStream4sATI = (PFNGLVERTEXSTREAM4SATIPROC)load("glVertexStream4sATI");
	glad_glVertexStream4svATI = (PFNGLVERTEXSTREAM4SVATIPROC)load("glVertexStream4svATI");
	glad_glVertexStream4iATI = (PFNGLVERTEXSTREAM4IATIPROC)load("glVertexStream4iATI");
	glad_glVertexStream4ivATI = (PFNGLVERTEXSTREAM4IVATIPROC)load("glVertexStream4ivATI");
	glad_glVertexStream4fATI = (PFNGLVERTEXSTREAM4FATIPROC)load("glVertexStream4fATI");
	glad_glVertexStream4fvATI = (PFNGLVERTEXSTREAM4FVATIPROC)load("glVertexStream4fvATI");
	glad_glVertexStream4dATI = (PFNGLVERTEXSTREAM4DATIPROC)load("glVertexStream4dATI");
	glad_glVertexStream4dvATI = (PFNGLVERTEXSTREAM4DVATIPROC)load("glVertexStream4dvATI");
	glad_glNormalStream3bATI = (PFNGLNORMALSTREAM3BATIPROC)load("glNormalStream3bATI");
	glad_glNormalStream3bvATI = (PFNGLNORMALSTREAM3BVATIPROC)load("glNormalStream3bvATI");
	glad_glNormalStream3sATI = (PFNGLNORMALSTREAM3SATIPROC)load("glNormalStream3sATI");
	glad_glNormalStream3svATI = (PFNGLNORMALSTREAM3SVATIPROC)load("glNormalStream3svATI");
	glad_glNormalStream3iATI = (PFNGLNORMALSTREAM3IATIPROC)load("glNormalStream3iATI");
	glad_glNormalStream3ivATI = (PFNGLNORMALSTREAM3IVATIPROC)load("glNormalStream3ivATI");
	glad_glNormalStream3fATI = (PFNGLNORMALSTREAM3FATIPROC)load("glNormalStream3fATI");
	glad_glNormalStream3fvATI = (PFNGLNORMALSTREAM3FVATIPROC)load("glNormalStream3fvATI");
	glad_glNormalStream3dATI = (PFNGLNORMALSTREAM3DATIPROC)load("glNormalStream3dATI");
	glad_glNormalStream3dvATI = (PFNGLNORMALSTREAM3DVATIPROC)load("glNormalStream3dvATI");
	glad_glClientActiveVertexStreamATI = (PFNGLCLIENTACTIVEVERTEXSTREAMATIPROC)load("glClientActiveVertexStreamATI");
	glad_glVertexBlendEnviATI = (PFNGLVERTEXBLENDENVIATIPROC)load("glVertexBlendEnviATI");
	glad_glVertexBlendEnvfATI = (PFNGLVERTEXBLENDENVFATIPROC)load("glVertexBlendEnvfATI");
}
static void load_GL_NV_vdpau_interop(GLADloadproc load) {
	if (!GLAD_GL_NV_vdpau_interop) return;
	glad_glVDPAUInitNV = (PFNGLVDPAUINITNVPROC)load("glVDPAUInitNV");
	glad_glVDPAUFiniNV = (PFNGLVDPAUFININVPROC)load("glVDPAUFiniNV");
	glad_glVDPAURegisterVideoSurfaceNV = (PFNGLVDPAUREGISTERVIDEOSURFACENVPROC)load("glVDPAURegisterVideoSurfaceNV");
	glad_glVDPAURegisterOutputSurfaceNV = (PFNGLVDPAUREGISTEROUTPUTSURFACENVPROC)load("glVDPAURegisterOutputSurfaceNV");
	glad_glVDPAUIsSurfaceNV = (PFNGLVDPAUISSURFACENVPROC)load("glVDPAUIsSurfaceNV");
	glad_glVDPAUUnregisterSurfaceNV = (PFNGLVDPAUUNREGISTERSURFACENVPROC)load("glVDPAUUnregisterSurfaceNV");
	glad_glVDPAUGetSurfaceivNV = (PFNGLVDPAUGETSURFACEIVNVPROC)load("glVDPAUGetSurfaceivNV");
	glad_glVDPAUSurfaceAccessNV = (PFNGLVDPAUSURFACEACCESSNVPROC)load("glVDPAUSurfaceAccessNV");
	glad_glVDPAUMapSurfacesNV = (PFNGLVDPAUMAPSURFACESNVPROC)load("glVDPAUMapSurfacesNV");
	glad_glVDPAUUnmapSurfacesNV = (PFNGLVDPAUUNMAPSURFACESNVPROC)load("glVDPAUUnmapSurfacesNV");
}
static void load_GL_ARB_internalformat_query2(GLADloadproc load) {
	if (!GLAD_GL_ARB_internalformat_query2) return;
	glad_glGetInternalformati64v = (PFNGLGETINTERNALFORMATI64VPROC)load("glGetInternalformati64v");
}
static void load_GL_SUN_vertex(GLADloadproc load) {
	if (!GLAD_GL_SUN_vertex) return;
	glad_glColor4ubVertex2fSUN = (PFNGLCOLOR4UBVERTEX2FSUNPROC)load("glColor4ubVertex2fSUN");
	glad_glColor4ubVertex2fvSUN = (PFNGLCOLOR4UBVERTEX2FVSUNPROC)load("glColor4ubVertex2fvSUN");
	glad_glColor4ubVertex3fSUN = (PFNGLCOLOR4UBVERTEX3FSUNPROC)load("glColor4ubVertex3fSUN");
	glad_glColor4ubVertex3fvSUN = (PFNGLCOLOR4UBVERTEX3FVSUNPROC)load("glColor4ubVertex3fvSUN");
	glad_glColor3fVertex3fSUN = (PFNGLCOLOR3FVERTEX3FSUNPROC)load("glColor3fVertex3fSUN");
	glad_glColor3fVertex3fvSUN = (PFNGLCOLOR3FVERTEX3FVSUNPROC)load("glColor3fVertex3fvSUN");
	glad_glNormal3fVertex3fSUN = (PFNGLNORMAL3FVERTEX3FSUNPROC)load("glNormal3fVertex3fSUN");
	glad_glNormal3fVertex3fvSUN = (PFNGLNORMAL3FVERTEX3FVSUNPROC)load("glNormal3fVertex3fvSUN");
	glad_glColor4fNormal3fVertex3fSUN = (PFNGLCOLOR4FNORMAL3FVERTEX3FSUNPROC)load("glColor4fNormal3fVertex3fSUN");
	glad_glColor4fNormal3fVertex3fvSUN = (PFNGLCOLOR4FNORMAL3FVERTEX3FVSUNPROC)load("glColor4fNormal3fVertex3fvSUN");
	glad_glTexCoord2fVertex3fSUN = (PFNGLTEXCOORD2FVERTEX3FSUNPROC)load("glTexCoord2fVertex3fSUN");
	glad_glTexCoord2fVertex3fvSUN = (PFNGLTEXCOORD2FVERTEX3FVSUNPROC)load("glTexCoord2fVertex3fvSUN");
	glad_glTexCoord4fVertex4fSUN = (PFNGLTEXCOORD4FVERTEX4FSUNPROC)load("glTexCoord4fVertex4fSUN");
	glad_glTexCoord4fVertex4fvSUN = (PFNGLTEXCOORD4FVERTEX4FVSUNPROC)load("glTexCoord4fVertex4fvSUN");
	glad_glTexCoord2fColor4ubVertex3fSUN = (PFNGLTEXCOORD2FCOLOR4UBVERTEX3FSUNPROC)load("glTexCoord2fColor4ubVertex3fSUN");
	glad_glTexCoord2fColor4ubVertex3fvSUN = (PFNGLTEXCOORD2FCOLOR4UBVERTEX3FVSUNPROC)load("glTexCoord2fColor4ubVertex3fvSUN");
	glad_glTexCoord2fColor3fVertex3fSUN = (PFNGLTEXCOORD2FCOLOR3FVERTEX3FSUNPROC)load("glTexCoord2fColor3fVertex3fSUN");
	glad_glTexCoord2fColor3fVertex3fvSUN = (PFNGLTEXCOORD2FCOLOR3FVERTEX3FVSUNPROC)load("glTexCoord2fColor3fVertex3fvSUN");
	glad_glTexCoord2fNormal3fVertex3fSUN = (PFNGLTEXCOORD2FNORMAL3FVERTEX3FSUNPROC)load("glTexCoord2fNormal3fVertex3fSUN");
	glad_glTexCoord2fNormal3fVertex3fvSUN = (PFNGLTEXCOORD2FNORMAL3FVERTEX3FVSUNPROC)load("glTexCoord2fNormal3fVertex3fvSUN");
	glad_glTexCoord2fColor4fNormal3fVertex3fSUN = (PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC)load("glTexCoord2fColor4fNormal3fVertex3fSUN");
	glad_glTexCoord2fColor4fNormal3fVertex3fvSUN = (PFNGLTEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC)load("glTexCoord2fColor4fNormal3fVertex3fvSUN");
	glad_glTexCoord4fColor4fNormal3fVertex4fSUN = (PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FSUNPROC)load("glTexCoord4fColor4fNormal3fVertex4fSUN");
	glad_glTexCoord4fColor4fNormal3fVertex4fvSUN = (PFNGLTEXCOORD4FCOLOR4FNORMAL3FVERTEX4FVSUNPROC)load("glTexCoord4fColor4fNormal3fVertex4fvSUN");
	glad_glReplacementCodeuiVertex3fSUN = (PFNGLREPLACEMENTCODEUIVERTEX3FSUNPROC)load("glReplacementCodeuiVertex3fSUN");
	glad_glReplacementCodeuiVertex3fvSUN = (PFNGLREPLACEMENTCODEUIVERTEX3FVSUNPROC)load("glReplacementCodeuiVertex3fvSUN");
	glad_glReplacementCodeuiColor4ubVertex3fSUN = (PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FSUNPROC)load("glReplacementCodeuiColor4ubVertex3fSUN");
	glad_glReplacementCodeuiColor4ubVertex3fvSUN = (PFNGLREPLACEMENTCODEUICOLOR4UBVERTEX3FVSUNPROC)load("glReplacementCodeuiColor4ubVertex3fvSUN");
	glad_glReplacementCodeuiColor3fVertex3fSUN = (PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FSUNPROC)load("glReplacementCodeuiColor3fVertex3fSUN");
	glad_glReplacementCodeuiColor3fVertex3fvSUN = (PFNGLREPLACEMENTCODEUICOLOR3FVERTEX3FVSUNPROC)load("glReplacementCodeuiColor3fVertex3fvSUN");
	glad_glReplacementCodeuiNormal3fVertex3fSUN = (PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FSUNPROC)load("glReplacementCodeuiNormal3fVertex3fSUN");
	glad_glReplacementCodeuiNormal3fVertex3fvSUN = (PFNGLREPLACEMENTCODEUINORMAL3FVERTEX3FVSUNPROC)load("glReplacementCodeuiNormal3fVertex3fvSUN");
	glad_glReplacementCodeuiColor4fNormal3fVertex3fSUN = (PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FSUNPROC)load("glReplacementCodeuiColor4fNormal3fVertex3fSUN");
	glad_glReplacementCodeuiColor4fNormal3fVertex3fvSUN = (PFNGLREPLACEMENTCODEUICOLOR4FNORMAL3FVERTEX3FVSUNPROC)load("glReplacementCodeuiColor4fNormal3fVertex3fvSUN");
	glad_glReplacementCodeuiTexCoord2fVertex3fSUN = (PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FSUNPROC)load("glReplacementCodeuiTexCoord2fVertex3fSUN");
	glad_glReplacementCodeuiTexCoord2fVertex3fvSUN = (PFNGLREPLACEMENTCODEUITEXCOORD2FVERTEX3FVSUNPROC)load("glReplacementCodeuiTexCoord2fVertex3fvSUN");
	glad_glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN = (PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FSUNPROC)load("glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN");
	glad_glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN = (PFNGLREPLACEMENTCODEUITEXCOORD2FNORMAL3FVERTEX3FVSUNPROC)load("glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN");
	glad_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN = (PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FSUNPROC)load("glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN");
	glad_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN = (PFNGLREPLACEMENTCODEUITEXCOORD2FCOLOR4FNORMAL3FVERTEX3FVSUNPROC)load("glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN");
}
static void load_GL_SGIX_igloo_interface(GLADloadproc load) {
	if (!GLAD_GL_SGIX_igloo_interface) return;
	glad_glIglooInterfaceSGIX = (PFNGLIGLOOINTERFACESGIXPROC)load("glIglooInterfaceSGIX");
}
static void load_GL_ARB_draw_indirect(GLADloadproc load) {
	if (!GLAD_GL_ARB_draw_indirect) return;
	glad_glDrawArraysIndirect = (PFNGLDRAWARRAYSINDIRECTPROC)load("glDrawArraysIndirect");
	glad_glDrawElementsIndirect = (PFNGLDRAWELEMENTSINDIRECTPROC)load("glDrawElementsIndirect");
}
static void load_GL_NV_vertex_program4(GLADloadproc load) {
	if (!GLAD_GL_NV_vertex_program4) return;
	glad_glVertexAttribI1iEXT = (PFNGLVERTEXATTRIBI1IEXTPROC)load("glVertexAttribI1iEXT");
	glad_glVertexAttribI2iEXT = (PFNGLVERTEXATTRIBI2IEXTPROC)load("glVertexAttribI2iEXT");
	glad_glVertexAttribI3iEXT = (PFNGLVERTEXATTRIBI3IEXTPROC)load("glVertexAttribI3iEXT");
	glad_glVertexAttribI4iEXT = (PFNGLVERTEXATTRIBI4IEXTPROC)load("glVertexAttribI4iEXT");
	glad_glVertexAttribI1uiEXT = (PFNGLVERTEXATTRIBI1UIEXTPROC)load("glVertexAttribI1uiEXT");
	glad_glVertexAttribI2uiEXT = (PFNGLVERTEXATTRIBI2UIEXTPROC)load("glVertexAttribI2uiEXT");
	glad_glVertexAttribI3uiEXT = (PFNGLVERTEXATTRIBI3UIEXTPROC)load("glVertexAttribI3uiEXT");
	glad_glVertexAttribI4uiEXT = (PFNGLVERTEXATTRIBI4UIEXTPROC)load("glVertexAttribI4uiEXT");
	glad_glVertexAttribI1ivEXT = (PFNGLVERTEXATTRIBI1IVEXTPROC)load("glVertexAttribI1ivEXT");
	glad_glVertexAttribI2ivEXT = (PFNGLVERTEXATTRIBI2IVEXTPROC)load("glVertexAttribI2ivEXT");
	glad_glVertexAttribI3ivEXT = (PFNGLVERTEXATTRIBI3IVEXTPROC)load("glVertexAttribI3ivEXT");
	glad_glVertexAttribI4ivEXT = (PFNGLVERTEXATTRIBI4IVEXTPROC)load("glVertexAttribI4ivEXT");
	glad_glVertexAttribI1uivEXT = (PFNGLVERTEXATTRIBI1UIVEXTPROC)load("glVertexAttribI1uivEXT");
	glad_glVertexAttribI2uivEXT = (PFNGLVERTEXATTRIBI2UIVEXTPROC)load("glVertexAttribI2uivEXT");
	glad_glVertexAttribI3uivEXT = (PFNGLVERTEXATTRIBI3UIVEXTPROC)load("glVertexAttribI3uivEXT");
	glad_glVertexAttribI4uivEXT = (PFNGLVERTEXATTRIBI4UIVEXTPROC)load("glVertexAttribI4uivEXT");
	glad_glVertexAttribI4bvEXT = (PFNGLVERTEXATTRIBI4BVEXTPROC)load("glVertexAttribI4bvEXT");
	glad_glVertexAttribI4svEXT = (PFNGLVERTEXATTRIBI4SVEXTPROC)load("glVertexAttribI4svEXT");
	glad_glVertexAttribI4ubvEXT = (PFNGLVERTEXATTRIBI4UBVEXTPROC)load("glVertexAttribI4ubvEXT");
	glad_glVertexAttribI4usvEXT = (PFNGLVERTEXATTRIBI4USVEXTPROC)load("glVertexAttribI4usvEXT");
	glad_glVertexAttribIPointerEXT = (PFNGLVERTEXATTRIBIPOINTEREXTPROC)load("glVertexAttribIPointerEXT");
	glad_glGetVertexAttribIivEXT = (PFNGLGETVERTEXATTRIBIIVEXTPROC)load("glGetVertexAttribIivEXT");
	glad_glGetVertexAttribIuivEXT = (PFNGLGETVERTEXATTRIBIUIVEXTPROC)load("glGetVertexAttribIuivEXT");
}
static void load_GL_SGIS_fog_function(GLADloadproc load) {
	if (!GLAD_GL_SGIS_fog_function) return;
	glad_glFogFuncSGIS = (PFNGLFOGFUNCSGISPROC)load("glFogFuncSGIS");
	glad_glGetFogFuncSGIS = (PFNGLGETFOGFUNCSGISPROC)load("glGetFogFuncSGIS");
}
static void load_GL_EXT_x11_sync_object(GLADloadproc load) {
	if (!GLAD_GL_EXT_x11_sync_object) return;
	glad_glImportSyncEXT = (PFNGLIMPORTSYNCEXTPROC)load("glImportSyncEXT");
}
static void load_GL_ARB_sync(GLADloadproc load) {
	if (!GLAD_GL_ARB_sync) return;
	glad_glFenceSync = (PFNGLFENCESYNCPROC)load("glFenceSync");
	glad_glIsSync = (PFNGLISSYNCPROC)load("glIsSync");
	glad_glDeleteSync = (PFNGLDELETESYNCPROC)load("glDeleteSync");
	glad_glClientWaitSync = (PFNGLCLIENTWAITSYNCPROC)load("glClientWaitSync");
	glad_glWaitSync = (PFNGLWAITSYNCPROC)load("glWaitSync");
	glad_glGetInteger64v = (PFNGLGETINTEGER64VPROC)load("glGetInteger64v");
	glad_glGetSynciv = (PFNGLGETSYNCIVPROC)load("glGetSynciv");
}
static void load_GL_NV_sample_locations(GLADloadproc load) {
	if (!GLAD_GL_NV_sample_locations) return;
	glad_glFramebufferSampleLocationsfvNV = (PFNGLFRAMEBUFFERSAMPLELOCATIONSFVNVPROC)load("glFramebufferSampleLocationsfvNV");
	glad_glNamedFramebufferSampleLocationsfvNV = (PFNGLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVNVPROC)load("glNamedFramebufferSampleLocationsfvNV");
	glad_glResolveDepthValuesNV = (PFNGLRESOLVEDEPTHVALUESNVPROC)load("glResolveDepthValuesNV");
}
static void load_GL_ARB_compute_variable_group_size(GLADloadproc load) {
	if (!GLAD_GL_ARB_compute_variable_group_size) return;
	glad_glDispatchComputeGroupSizeARB = (PFNGLDISPATCHCOMPUTEGROUPSIZEARBPROC)load("glDispatchComputeGroupSizeARB");
}
static void load_GL_OES_fixed_point(GLADloadproc load) {
	if (!GLAD_GL_OES_fixed_point) return;
	glad_glAlphaFuncxOES = (PFNGLALPHAFUNCXOESPROC)load("glAlphaFuncxOES");
	glad_glClearColorxOES = (PFNGLCLEARCOLORXOESPROC)load("glClearColorxOES");
	glad_glClearDepthxOES = (PFNGLCLEARDEPTHXOESPROC)load("glClearDepthxOES");
	glad_glClipPlanexOES = (PFNGLCLIPPLANEXOESPROC)load("glClipPlanexOES");
	glad_glColor4xOES = (PFNGLCOLOR4XOESPROC)load("glColor4xOES");
	glad_glDepthRangexOES = (PFNGLDEPTHRANGEXOESPROC)load("glDepthRangexOES");
	glad_glFogxOES = (PFNGLFOGXOESPROC)load("glFogxOES");
	glad_glFogxvOES = (PFNGLFOGXVOESPROC)load("glFogxvOES");
	glad_glFrustumxOES = (PFNGLFRUSTUMXOESPROC)load("glFrustumxOES");
	glad_glGetClipPlanexOES = (PFNGLGETCLIPPLANEXOESPROC)load("glGetClipPlanexOES");
	glad_glGetFixedvOES = (PFNGLGETFIXEDVOESPROC)load("glGetFixedvOES");
	glad_glGetTexEnvxvOES = (PFNGLGETTEXENVXVOESPROC)load("glGetTexEnvxvOES");
	glad_glGetTexParameterxvOES = (PFNGLGETTEXPARAMETERXVOESPROC)load("glGetTexParameterxvOES");
	glad_glLightModelxOES = (PFNGLLIGHTMODELXOESPROC)load("glLightModelxOES");
	glad_glLightModelxvOES = (PFNGLLIGHTMODELXVOESPROC)load("glLightModelxvOES");
	glad_glLightxOES = (PFNGLLIGHTXOESPROC)load("glLightxOES");
	glad_glLightxvOES = (PFNGLLIGHTXVOESPROC)load("glLightxvOES");
	glad_glLineWidthxOES = (PFNGLLINEWIDTHXOESPROC)load("glLineWidthxOES");
	glad_glLoadMatrixxOES = (PFNGLLOADMATRIXXOESPROC)load("glLoadMatrixxOES");
	glad_glMaterialxOES = (PFNGLMATERIALXOESPROC)load("glMaterialxOES");
	glad_glMaterialxvOES = (PFNGLMATERIALXVOESPROC)load("glMaterialxvOES");
	glad_glMultMatrixxOES = (PFNGLMULTMATRIXXOESPROC)load("glMultMatrixxOES");
	glad_glMultiTexCoord4xOES = (PFNGLMULTITEXCOORD4XOESPROC)load("glMultiTexCoord4xOES");
	glad_glNormal3xOES = (PFNGLNORMAL3XOESPROC)load("glNormal3xOES");
	glad_glOrthoxOES = (PFNGLORTHOXOESPROC)load("glOrthoxOES");
	glad_glPointParameterxvOES = (PFNGLPOINTPARAMETERXVOESPROC)load("glPointParameterxvOES");
	glad_glPointSizexOES = (PFNGLPOINTSIZEXOESPROC)load("glPointSizexOES");
	glad_glPolygonOffsetxOES = (PFNGLPOLYGONOFFSETXOESPROC)load("glPolygonOffsetxOES");
	glad_glRotatexOES = (PFNGLROTATEXOESPROC)load("glRotatexOES");
	glad_glScalexOES = (PFNGLSCALEXOESPROC)load("glScalexOES");
	glad_glTexEnvxOES = (PFNGLTEXENVXOESPROC)load("glTexEnvxOES");
	glad_glTexEnvxvOES = (PFNGLTEXENVXVOESPROC)load("glTexEnvxvOES");
	glad_glTexParameterxOES = (PFNGLTEXPARAMETERXOESPROC)load("glTexParameterxOES");
	glad_glTexParameterxvOES = (PFNGLTEXPARAMETERXVOESPROC)load("glTexParameterxvOES");
	glad_glTranslatexOES = (PFNGLTRANSLATEXOESPROC)load("glTranslatexOES");
	glad_glGetLightxvOES = (PFNGLGETLIGHTXVOESPROC)load("glGetLightxvOES");
	glad_glGetMaterialxvOES = (PFNGLGETMATERIALXVOESPROC)load("glGetMaterialxvOES");
	glad_glPointParameterxOES = (PFNGLPOINTPARAMETERXOESPROC)load("glPointParameterxOES");
	glad_glSampleCoveragexOES = (PFNGLSAMPLECOVERAGEXOESPROC)load("glSampleCoveragexOES");
	glad_glAccumxOES = (PFNGLACCUMXOESPROC)load("glAccumxOES");
	glad_glBitmapxOES = (PFNGLBITMAPXOESPROC)load("glBitmapxOES");
	glad_glBlendColorxOES = (PFNGLBLENDCOLORXOESPROC)load("glBlendColorxOES");
	glad_glClearAccumxOES = (PFNGLCLEARACCUMXOESPROC)load("glClearAccumxOES");
	glad_glColor3xOES = (PFNGLCOLOR3XOESPROC)load("glColor3xOES");
	glad_glColor3xvOES = (PFNGLCOLOR3XVOESPROC)load("glColor3xvOES");
	glad_glColor4xvOES = (PFNGLCOLOR4XVOESPROC)load("glColor4xvOES");
	glad_glConvolutionParameterxOES = (PFNGLCONVOLUTIONPARAMETERXOESPROC)load("glConvolutionParameterxOES");
	glad_glConvolutionParameterxvOES = (PFNGLCONVOLUTIONPARAMETERXVOESPROC)load("glConvolutionParameterxvOES");
	glad_glEvalCoord1xOES = (PFNGLEVALCOORD1XOESPROC)load("glEvalCoord1xOES");
	glad_glEvalCoord1xvOES = (PFNGLEVALCOORD1XVOESPROC)load("glEvalCoord1xvOES");
	glad_glEvalCoord2xOES = (PFNGLEVALCOORD2XOESPROC)load("glEvalCoord2xOES");
	glad_glEvalCoord2xvOES = (PFNGLEVALCOORD2XVOESPROC)load("glEvalCoord2xvOES");
	glad_glFeedbackBufferxOES = (PFNGLFEEDBACKBUFFERXOESPROC)load("glFeedbackBufferxOES");
	glad_glGetConvolutionParameterxvOES = (PFNGLGETCONVOLUTIONPARAMETERXVOESPROC)load("glGetConvolutionParameterxvOES");
	glad_glGetHistogramParameterxvOES = (PFNGLGETHISTOGRAMPARAMETERXVOESPROC)load("glGetHistogramParameterxvOES");
	glad_glGetLightxOES = (PFNGLGETLIGHTXOESPROC)load("glGetLightxOES");
	glad_glGetMapxvOES = (PFNGLGETMAPXVOESPROC)load("glGetMapxvOES");
	glad_glGetMaterialxOES = (PFNGLGETMATERIALXOESPROC)load("glGetMaterialxOES");
	glad_glGetPixelMapxv = (PFNGLGETPIXELMAPXVPROC)load("glGetPixelMapxv");
	glad_glGetTexGenxvOES = (PFNGLGETTEXGENXVOESPROC)load("glGetTexGenxvOES");
	glad_glGetTexLevelParameterxvOES = (PFNGLGETTEXLEVELPARAMETERXVOESPROC)load("glGetTexLevelParameterxvOES");
	glad_glIndexxOES = (PFNGLINDEXXOESPROC)load("glIndexxOES");
	glad_glIndexxvOES = (PFNGLINDEXXVOESPROC)load("glIndexxvOES");
	glad_glLoadTransposeMatrixxOES = (PFNGLLOADTRANSPOSEMATRIXXOESPROC)load("glLoadTransposeMatrixxOES");
	glad_glMap1xOES = (PFNGLMAP1XOESPROC)load("glMap1xOES");
	glad_glMap2xOES = (PFNGLMAP2XOESPROC)load("glMap2xOES");
	glad_glMapGrid1xOES = (PFNGLMAPGRID1XOESPROC)load("glMapGrid1xOES");
	glad_glMapGrid2xOES = (PFNGLMAPGRID2XOESPROC)load("glMapGrid2xOES");
	glad_glMultTransposeMatrixxOES = (PFNGLMULTTRANSPOSEMATRIXXOESPROC)load("glMultTransposeMatrixxOES");
	glad_glMultiTexCoord1xOES = (PFNGLMULTITEXCOORD1XOESPROC)load("glMultiTexCoord1xOES");
	glad_glMultiTexCoord1xvOES = (PFNGLMULTITEXCOORD1XVOESPROC)load("glMultiTexCoord1xvOES");
	glad_glMultiTexCoord2xOES = (PFNGLMULTITEXCOORD2XOESPROC)load("glMultiTexCoord2xOES");
	glad_glMultiTexCoord2xvOES = (PFNGLMULTITEXCOORD2XVOESPROC)load("glMultiTexCoord2xvOES");
	glad_glMultiTexCoord3xOES = (PFNGLMULTITEXCOORD3XOESPROC)load("glMultiTexCoord3xOES");
	glad_glMultiTexCoord3xvOES = (PFNGLMULTITEXCOORD3XVOESPROC)load("glMultiTexCoord3xvOES");
	glad_glMultiTexCoord4xvOES = (PFNGLMULTITEXCOORD4XVOESPROC)load("glMultiTexCoord4xvOES");
	glad_glNormal3xvOES = (PFNGLNORMAL3XVOESPROC)load("glNormal3xvOES");
	glad_glPassThroughxOES = (PFNGLPASSTHROUGHXOESPROC)load("glPassThroughxOES");
	glad_glPixelMapx = (PFNGLPIXELMAPXPROC)load("glPixelMapx");
	glad_glPixelStorex = (PFNGLPIXELSTOREXPROC)load("glPixelStorex");
	glad_glPixelTransferxOES = (PFNGLPIXELTRANSFERXOESPROC)load("glPixelTransferxOES");
	glad_glPixelZoomxOES = (PFNGLPIXELZOOMXOESPROC)load("glPixelZoomxOES");
	glad_glPrioritizeTexturesxOES = (PFNGLPRIORITIZETEXTURESXOESPROC)load("glPrioritizeTexturesxOES");
	glad_glRasterPos2xOES = (PFNGLRASTERPOS2XOESPROC)load("glRasterPos2xOES");
	glad_glRasterPos2xvOES = (PFNGLRASTERPOS2XVOESPROC)load("glRasterPos2xvOES");
	glad_glRasterPos3xOES = (PFNGLRASTERPOS3XOESPROC)load("glRasterPos3xOES");
	glad_glRasterPos3xvOES = (PFNGLRASTERPOS3XVOESPROC)load("glRasterPos3xvOES");
	glad_glRasterPos4xOES = (PFNGLRASTERPOS4XOESPROC)load("glRasterPos4xOES");
	glad_glRasterPos4xvOES = (PFNGLRASTERPOS4XVOESPROC)load("glRasterPos4xvOES");
	glad_glRectxOES = (PFNGLRECTXOESPROC)load("glRectxOES");
	glad_glRectxvOES = (PFNGLRECTXVOESPROC)load("glRectxvOES");
	glad_glTexCoord1xOES = (PFNGLTEXCOORD1XOESPROC)load("glTexCoord1xOES");
	glad_glTexCoord1xvOES = (PFNGLTEXCOORD1XVOESPROC)load("glTexCoord1xvOES");
	glad_glTexCoord2xOES = (PFNGLTEXCOORD2XOESPROC)load("glTexCoord2xOES");
	glad_glTexCoord2xvOES = (PFNGLTEXCOORD2XVOESPROC)load("glTexCoord2xvOES");
	glad_glTexCoord3xOES = (PFNGLTEXCOORD3XOESPROC)load("glTexCoord3xOES");
	glad_glTexCoord3xvOES = (PFNGLTEXCOORD3XVOESPROC)load("glTexCoord3xvOES");
	glad_glTexCoord4xOES = (PFNGLTEXCOORD4XOESPROC)load("glTexCoord4xOES");
	glad_glTexCoord4xvOES = (PFNGLTEXCOORD4XVOESPROC)load("glTexCoord4xvOES");
	glad_glTexGenxOES = (PFNGLTEXGENXOESPROC)load("glTexGenxOES");
	glad_glTexGenxvOES = (PFNGLTEXGENXVOESPROC)load("glTexGenxvOES");
	glad_glVertex2xOES = (PFNGLVERTEX2XOESPROC)load("glVertex2xOES");
	glad_glVertex2xvOES = (PFNGLVERTEX2XVOESPROC)load("glVertex2xvOES");
	glad_glVertex3xOES = (PFNGLVERTEX3XOESPROC)load("glVertex3xOES");
	glad_glVertex3xvOES = (PFNGLVERTEX3XVOESPROC)load("glVertex3xvOES");
	glad_glVertex4xOES = (PFNGLVERTEX4XOESPROC)load("glVertex4xOES");
	glad_glVertex4xvOES = (PFNGLVERTEX4XVOESPROC)load("glVertex4xvOES");
}
static void load_GL_EXT_framebuffer_multisample(GLADloadproc load) {
	if (!GLAD_GL_EXT_framebuffer_multisample) return;
	glad_glRenderbufferStorageMultisampleEXT = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC)load("glRenderbufferStorageMultisampleEXT");
}
static void load_GL_SGIS_texture4D(GLADloadproc load) {
	if (!GLAD_GL_SGIS_texture4D) return;
	glad_glTexImage4DSGIS = (PFNGLTEXIMAGE4DSGISPROC)load("glTexImage4DSGIS");
	glad_glTexSubImage4DSGIS = (PFNGLTEXSUBIMAGE4DSGISPROC)load("glTexSubImage4DSGIS");
}
static void load_GL_EXT_texture3D(GLADloadproc load) {
	if (!GLAD_GL_EXT_texture3D) return;
	glad_glTexImage3DEXT = (PFNGLTEXIMAGE3DEXTPROC)load("glTexImage3DEXT");
	glad_glTexSubImage3DEXT = (PFNGLTEXSUBIMAGE3DEXTPROC)load("glTexSubImage3DEXT");
}
static void load_GL_EXT_multisample(GLADloadproc load) {
	if (!GLAD_GL_EXT_multisample) return;
	glad_glSampleMaskEXT = (PFNGLSAMPLEMASKEXTPROC)load("glSampleMaskEXT");
	glad_glSamplePatternEXT = (PFNGLSAMPLEPATTERNEXTPROC)load("glSamplePatternEXT");
}
static void load_GL_EXT_secondary_color(GLADloadproc load) {
	if (!GLAD_GL_EXT_secondary_color) return;
	glad_glSecondaryColor3bEXT = (PFNGLSECONDARYCOLOR3BEXTPROC)load("glSecondaryColor3bEXT");
	glad_glSecondaryColor3bvEXT = (PFNGLSECONDARYCOLOR3BVEXTPROC)load("glSecondaryColor3bvEXT");
	glad_glSecondaryColor3dEXT = (PFNGLSECONDARYCOLOR3DEXTPROC)load("glSecondaryColor3dEXT");
	glad_glSecondaryColor3dvEXT = (PFNGLSECONDARYCOLOR3DVEXTPROC)load("glSecondaryColor3dvEXT");
	glad_glSecondaryColor3fEXT = (PFNGLSECONDARYCOLOR3FEXTPROC)load("glSecondaryColor3fEXT");
	glad_glSecondaryColor3fvEXT = (PFNGLSECONDARYCOLOR3FVEXTPROC)load("glSecondaryColor3fvEXT");
	glad_glSecondaryColor3iEXT = (PFNGLSECONDARYCOLOR3IEXTPROC)load("glSecondaryColor3iEXT");
	glad_glSecondaryColor3ivEXT = (PFNGLSECONDARYCOLOR3IVEXTPROC)load("glSecondaryColor3ivEXT");
	glad_glSecondaryColor3sEXT = (PFNGLSECONDARYCOLOR3SEXTPROC)load("glSecondaryColor3sEXT");
	glad_glSecondaryColor3svEXT = (PFNGLSECONDARYCOLOR3SVEXTPROC)load("glSecondaryColor3svEXT");
	glad_glSecondaryColor3ubEXT = (PFNGLSECONDARYCOLOR3UBEXTPROC)load("glSecondaryColor3ubEXT");
	glad_glSecondaryColor3ubvEXT = (PFNGLSECONDARYCOLOR3UBVEXTPROC)load("glSecondaryColor3ubvEXT");
	glad_glSecondaryColor3uiEXT = (PFNGLSECONDARYCOLOR3UIEXTPROC)load("glSecondaryColor3uiEXT");
	glad_glSecondaryColor3uivEXT = (PFNGLSECONDARYCOLOR3UIVEXTPROC)load("glSecondaryColor3uivEXT");
	glad_glSecondaryColor3usEXT = (PFNGLSECONDARYCOLOR3USEXTPROC)load("glSecondaryColor3usEXT");
	glad_glSecondaryColor3usvEXT = (PFNGLSECONDARYCOLOR3USVEXTPROC)load("glSecondaryColor3usvEXT");
	glad_glSecondaryColorPointerEXT = (PFNGLSECONDARYCOLORPOINTEREXTPROC)load("glSecondaryColorPointerEXT");
}
static void load_GL_ATI_vertex_array_object(GLADloadproc load) {
	if (!GLAD_GL_ATI_vertex_array_object) return;
	glad_glNewObjectBufferATI = (PFNGLNEWOBJECTBUFFERATIPROC)load("glNewObjectBufferATI");
	glad_glIsObjectBufferATI = (PFNGLISOBJECTBUFFERATIPROC)load("glIsObjectBufferATI");
	glad_glUpdateObjectBufferATI = (PFNGLUPDATEOBJECTBUFFERATIPROC)load("glUpdateObjectBufferATI");
	glad_glGetObjectBufferfvATI = (PFNGLGETOBJECTBUFFERFVATIPROC)load("glGetObjectBufferfvATI");
	glad_glGetObjectBufferivATI = (PFNGLGETOBJECTBUFFERIVATIPROC)load("glGetObjectBufferivATI");
	glad_glFreeObjectBufferATI = (PFNGLFREEOBJECTBUFFERATIPROC)load("glFreeObjectBufferATI");
	glad_glArrayObjectATI = (PFNGLARRAYOBJECTATIPROC)load("glArrayObjectATI");
	glad_glGetArrayObjectfvATI = (PFNGLGETARRAYOBJECTFVATIPROC)load("glGetArrayObjectfvATI");
	glad_glGetArrayObjectivATI = (PFNGLGETARRAYOBJECTIVATIPROC)load("glGetArrayObjectivATI");
	glad_glVariantArrayObjectATI = (PFNGLVARIANTARRAYOBJECTATIPROC)load("glVariantArrayObjectATI");
	glad_glGetVariantArrayObjectfvATI = (PFNGLGETVARIANTARRAYOBJECTFVATIPROC)load("glGetVariantArrayObjectfvATI");
	glad_glGetVariantArrayObjectivATI = (PFNGLGETVARIANTARRAYOBJECTIVATIPROC)load("glGetVariantArrayObjectivATI");
}
static void load_GL_ARB_sparse_texture(GLADloadproc load) {
	if (!GLAD_GL_ARB_sparse_texture) return;
	glad_glTexPageCommitmentARB = (PFNGLTEXPAGECOMMITMENTARBPROC)load("glTexPageCommitmentARB");
}
static void load_GL_ARB_sparse_buffer(GLADloadproc load) {
	if (!GLAD_GL_ARB_sparse_buffer) return;
	glad_glBufferPageCommitmentARB = (PFNGLBUFFERPAGECOMMITMENTARBPROC)load("glBufferPageCommitmentARB");
	glad_glNamedBufferPageCommitmentEXT = (PFNGLNAMEDBUFFERPAGECOMMITMENTEXTPROC)load("glNamedBufferPageCommitmentEXT");
	glad_glNamedBufferPageCommitmentARB = (PFNGLNAMEDBUFFERPAGECOMMITMENTARBPROC)load("glNamedBufferPageCommitmentARB");
}
static void load_GL_EXT_draw_range_elements(GLADloadproc load) {
	if (!GLAD_GL_EXT_draw_range_elements) return;
	glad_glDrawRangeElementsEXT = (PFNGLDRAWRANGEELEMENTSEXTPROC)load("glDrawRangeElementsEXT");
}