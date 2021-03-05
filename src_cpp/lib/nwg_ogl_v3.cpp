#include <nwg_pch.hpp>
#include "nwg_ogl_v3.h"
#include "nwg_ogl_loader.h"
namespace NWG
{
	void OglLoadV3() {
#if (defined GL_VERSION_3_0)
		OglColorMaski = (PFNGLCOLORMASKIPROC)OglGetProc("glColorMaski");
		OglGetBooleani_v = (PFNGLGETBOOLEANI_VPROC)OglGetProc("glGetBooleani_v");
		OglGetIntegeri_v = (PFNGLGETINTEGERI_VPROC)OglGetProc("glGetIntegeri_v");
		OglEnablei = (PFNGLENABLEIPROC)OglGetProc("glEnablei");
		OglDisablei = (PFNGLDISABLEIPROC)OglGetProc("glDisablei");
		OglIsEnabledi = (PFNGLISENABLEDIPROC)OglGetProc("glIsEnabledi");
		OglBeginTransformFeedback = (PFNGLBEGINTRANSFORMFEEDBACKPROC)OglGetProc("glBeginTransformFeedback");
		OglEndTransformFeedback = (PFNGLENDTRANSFORMFEEDBACKPROC)OglGetProc("glEndTransformFeedback");
		OglBindBufferRange = (PFNGLBINDBUFFERRANGEPROC)OglGetProc("glBindBufferRange");
		OglBindBufferBase = (PFNGLBINDBUFFERBASEPROC)OglGetProc("glBindBufferBase");
		OglTransformFeedbackVaryings = (PFNGLTRANSFORMFEEDBACKVARYINGSPROC)OglGetProc("glTransformFeedbackVaryings");
		OglGetTransformFeedbackVarying = (PFNGLGETTRANSFORMFEEDBACKVARYINGPROC)OglGetProc("glGetTransformFeedbackVarying");
		OglClampColor = (PFNGLCLAMPCOLORPROC)OglGetProc("glClampColor");
		OglBeginConditionalRender = (PFNGLBEGINCONDITIONALRENDERPROC)OglGetProc("glBeginConditionalRender");
		OglEndConditionalRender = (PFNGLENDCONDITIONALRENDERPROC)OglGetProc("glEndConditionalRender");
		OglVertexAttribIPointer = (PFNGLVERTEXATTRIBIPOINTERPROC)OglGetProc("glVertexAttribIPointer");
		OglGetVertexAttribIiv = (PFNGLGETVERTEXATTRIBIIVPROC)OglGetProc("glGetVertexAttribIiv");
		OglGetVertexAttribIuiv = (PFNGLGETVERTEXATTRIBIUIVPROC)OglGetProc("glGetVertexAttribIuiv");
		OglVertexAttribI1i = (PFNGLVERTEXATTRIBI1IPROC)OglGetProc("glVertexAttribI1i");
		OglVertexAttribI2i = (PFNGLVERTEXATTRIBI2IPROC)OglGetProc("glVertexAttribI2i");
		OglVertexAttribI3i = (PFNGLVERTEXATTRIBI3IPROC)OglGetProc("glVertexAttribI3i");
		OglVertexAttribI4i = (PFNGLVERTEXATTRIBI4IPROC)OglGetProc("glVertexAttribI4i");
		OglVertexAttribI1ui = (PFNGLVERTEXATTRIBI1UIPROC)OglGetProc("glVertexAttribI1ui");
		OglVertexAttribI2ui = (PFNGLVERTEXATTRIBI2UIPROC)OglGetProc("glVertexAttribI2ui");
		OglVertexAttribI3ui = (PFNGLVERTEXATTRIBI3UIPROC)OglGetProc("glVertexAttribI3ui");
		OglVertexAttribI4ui = (PFNGLVERTEXATTRIBI4UIPROC)OglGetProc("glVertexAttribI4ui");
		OglVertexAttribI1iv = (PFNGLVERTEXATTRIBI1IVPROC)OglGetProc("glVertexAttribI1iv");
		OglVertexAttribI2iv = (PFNGLVERTEXATTRIBI2IVPROC)OglGetProc("glVertexAttribI2iv");
		OglVertexAttribI3iv = (PFNGLVERTEXATTRIBI3IVPROC)OglGetProc("glVertexAttribI3iv");
		OglVertexAttribI4iv = (PFNGLVERTEXATTRIBI4IVPROC)OglGetProc("glVertexAttribI4iv");
		OglVertexAttribI1uiv = (PFNGLVERTEXATTRIBI1UIVPROC)OglGetProc("glVertexAttribI1uiv");
		OglVertexAttribI2uiv = (PFNGLVERTEXATTRIBI2UIVPROC)OglGetProc("glVertexAttribI2uiv");
		OglVertexAttribI3uiv = (PFNGLVERTEXATTRIBI3UIVPROC)OglGetProc("glVertexAttribI3uiv");
		OglVertexAttribI4uiv = (PFNGLVERTEXATTRIBI4UIVPROC)OglGetProc("glVertexAttribI4uiv");
		OglVertexAttribI4bv = (PFNGLVERTEXATTRIBI4BVPROC)OglGetProc("glVertexAttribI4bv");
		OglVertexAttribI4sv = (PFNGLVERTEXATTRIBI4SVPROC)OglGetProc("glVertexAttribI4sv");
		OglVertexAttribI4ubv = (PFNGLVERTEXATTRIBI4UBVPROC)OglGetProc("glVertexAttribI4ubv");
		OglVertexAttribI4usv = (PFNGLVERTEXATTRIBI4USVPROC)OglGetProc("glVertexAttribI4usv");
		OglGetUniformuiv = (PFNGLGETUNIFORMUIVPROC)OglGetProc("glGetUniformuiv");
		OglBindFragDataLocation = (PFNGLBINDFRAGDATALOCATIONPROC)OglGetProc("glBindFragDataLocation");
		OglGetFragDataLocation = (PFNGLGETFRAGDATALOCATIONPROC)OglGetProc("glGetFragDataLocation");
		OglUniform1uiv = (PFNGLUNIFORM1UIVPROC)OglGetProc("glUniform1uiv");
		OglUniform2uiv = (PFNGLUNIFORM2UIVPROC)OglGetProc("glUniform2uiv");
		OglUniform3uiv = (PFNGLUNIFORM3UIVPROC)OglGetProc("glUniform3uiv");
		OglUniform4uiv = (PFNGLUNIFORM4UIVPROC)OglGetProc("glUniform4uiv");
		OglTexParameterIiv = (PFNGLTEXPARAMETERIIVPROC)OglGetProc("glTexParameterIiv");
		OglTexParameterIuiv = (PFNGLTEXPARAMETERIUIVPROC)OglGetProc("glTexParameterIuiv");
		OglGetTexParameterIiv = (PFNGLGETTEXPARAMETERIIVPROC)OglGetProc("glGetTexParameterIiv");
		OglGetTexParameterIuiv = (PFNGLGETTEXPARAMETERIUIVPROC)OglGetProc("glGetTexParameterIuiv");
		OglClearefferiv = (PFNGLCLEARBUFFERIVPROC)OglGetProc("glClearefferiv");
		OglClearefferuiv = (PFNGLCLEARBUFFERUIVPROC)OglGetProc("glClearefferuiv");
		OglClearefferfv = (PFNGLCLEARBUFFERFVPROC)OglGetProc("glClearefferfv");
		OglClearefferfi = (PFNGLCLEARBUFFERFIPROC)OglGetProc("glClearefferfi");
		OglGetStringi = (PFNGLGETSTRINGIPROC)OglGetProc("glGetStringi");
#endif	// GL_VERSION_3_0
#if (defined GL_VERSION_3_1)
		OglDrawArraysInstanced = (PFNGLDRAWARRAYSINSTANCEDPROC)OglGetProc("glDrawArraysInstanced");
		OglDrawElementsInstanced = (PFNGLDRAWELEMENTSINSTANCEDPROC)OglGetProc("glDrawElementsInstanced");
		OglTexBuffer = (PFNGLTEXBUFFERPROC)OglGetProc("glTexBuffer");
		OglPrimitiveRestartIndex = (PFNGLPRIMITIVERESTARTINDEXPROC)OglGetProc("glPrimitiveRestartIndex");
#endif	// GL_VERSION_3_1
#if (defined GL_VERSION_3_2)
#endif	// GL_VERSION_3_2
#if (defined GL_VERSION_3_3)
		OglGetInteger64i_v = (PFNGLGETINTEGER64I_VPROC)OglGetProc("glGetInteger64i_v");
		OglGetBufferParameteri64v = (PFNGLGETBUFFERPARAMETERI64VPROC)OglGetProc("glGetBufferParameteri64v");
		OglFramebufferTexture = (PFNGLFRAMEBUFFERTEXTUREPROC)OglGetProc("glFramebufferTexture");
		OglVertexAttribDivisor = (PFNGLVERTEXATTRIBDIVISORPROC)OglGetProc("glVertexAttribDivisor");
#endif	// GL_VERSION_3_3
	}
}
#ifdef GL_VERSION_3_0
PFNGLCOLORMASKIPROC OglColorMaski;
PFNGLGETBOOLEANI_VPROC OglGetBooleani_v;
PFNGLGETINTEGERI_VPROC OglGetIntegeri_v;
PFNGLENABLEIPROC OglEnablei;
PFNGLDISABLEIPROC OglDisablei;
PFNGLISENABLEDIPROC OglIsEnabledi;
PFNGLBEGINTRANSFORMFEEDBACKPROC OglBeginTransformFeedback;
PFNGLENDTRANSFORMFEEDBACKPROC OglEndTransformFeedback;
PFNGLBINDBUFFERRANGEPROC OglBindBufferRange;
PFNGLBINDBUFFERBASEPROC OglBindBufferBase;
PFNGLTRANSFORMFEEDBACKVARYINGSPROC OglTransformFeedbackVaryings;
PFNGLGETTRANSFORMFEEDBACKVARYINGPROC OglGetTransformFeedbackVarying;
PFNGLCLAMPCOLORPROC OglClampColor;
PFNGLBEGINCONDITIONALRENDERPROC OglBeginConditionalRender;
PFNGLENDCONDITIONALRENDERPROC OglEndConditionalRender;
PFNGLVERTEXATTRIBIPOINTERPROC OglVertexAttribIPointer;
PFNGLGETVERTEXATTRIBIIVPROC OglGetVertexAttribIiv;
PFNGLGETVERTEXATTRIBIUIVPROC OglGetVertexAttribIuiv;
PFNGLVERTEXATTRIBI1IPROC OglVertexAttribI1i;
PFNGLVERTEXATTRIBI2IPROC OglVertexAttribI2i;
PFNGLVERTEXATTRIBI3IPROC OglVertexAttribI3i;
PFNGLVERTEXATTRIBI4IPROC OglVertexAttribI4i;
PFNGLVERTEXATTRIBI1UIPROC OglVertexAttribI1ui;
PFNGLVERTEXATTRIBI2UIPROC OglVertexAttribI2ui;
PFNGLVERTEXATTRIBI3UIPROC OglVertexAttribI3ui;
PFNGLVERTEXATTRIBI4UIPROC OglVertexAttribI4ui;
PFNGLVERTEXATTRIBI1IVPROC OglVertexAttribI1iv;
PFNGLVERTEXATTRIBI2IVPROC OglVertexAttribI2iv;
PFNGLVERTEXATTRIBI3IVPROC OglVertexAttribI3iv;
PFNGLVERTEXATTRIBI4IVPROC OglVertexAttribI4iv;
PFNGLVERTEXATTRIBI1UIVPROC OglVertexAttribI1uiv;
PFNGLVERTEXATTRIBI2UIVPROC OglVertexAttribI2uiv;
PFNGLVERTEXATTRIBI3UIVPROC OglVertexAttribI3uiv;
PFNGLVERTEXATTRIBI4UIVPROC OglVertexAttribI4uiv;
PFNGLVERTEXATTRIBI4BVPROC OglVertexAttribI4bv;
PFNGLVERTEXATTRIBI4SVPROC OglVertexAttribI4sv;
PFNGLVERTEXATTRIBI4UBVPROC OglVertexAttribI4ubv;
PFNGLVERTEXATTRIBI4USVPROC OglVertexAttribI4usv;
PFNGLGETUNIFORMUIVPROC OglGetUniformuiv;
PFNGLBINDFRAGDATALOCATIONPROC OglBindFragDataLocation;
PFNGLGETFRAGDATALOCATIONPROC OglGetFragDataLocation;
PFNGLUNIFORM1UIPROC OglUniform1ui;
PFNGLUNIFORM2UIPROC OglUniform2ui;
PFNGLUNIFORM3UIPROC OglUniform3ui;
PFNGLUNIFORM4UIPROC OglUniform4ui;
PFNGLUNIFORM1UIVPROC OglUniform1uiv;
PFNGLUNIFORM2UIVPROC OglUniform2uiv;
PFNGLUNIFORM3UIVPROC OglUniform3uiv;
PFNGLUNIFORM4UIVPROC OglUniform4uiv;
PFNGLTEXPARAMETERIIVPROC OglTexParameterIiv;
PFNGLTEXPARAMETERIUIVPROC OglTexParameterIuiv;
PFNGLGETTEXPARAMETERIIVPROC OglGetTexParameterIiv;
PFNGLGETTEXPARAMETERIUIVPROC OglGetTexParameterIuiv;
PFNGLCLEARBUFFERIVPROC OglClearefferiv;
PFNGLCLEARBUFFERUIVPROC OglClearefferuiv;
PFNGLCLEARBUFFERFVPROC OglClearefferfv;
PFNGLCLEARBUFFERFIPROC OglClearefferfi;
PFNGLGETSTRINGIPROC OglGetStringi;
#endif	// GL_VERSION_3_0

#ifdef GL_VERSION_3_1
PFNGLDRAWARRAYSINSTANCEDPROC OglDrawArraysInstanced;
PFNGLDRAWELEMENTSINSTANCEDPROC OglDrawElementsInstanced;
PFNGLTEXBUFFERPROC OglTexBuffer;
PFNGLPRIMITIVERESTARTINDEXPROC OglPrimitiveRestartIndex;
#endif	// GL_VERSION_3_1

#ifdef GL_VERSION_3_2
PFNGLGETINTEGER64I_VPROC OglGetInteger64i_v;
PFNGLGETBUFFERPARAMETERI64VPROC OglGetBufferParameteri64v;
PFNGLFRAMEBUFFERTEXTUREPROC OglFramebufferTexture;
#endif	// GL_VERSION_3_2

#ifdef GL_VERSION_3_3
PFNGLVERTEXATTRIBDIVISORPROC OglVertexAttribDivisor;
#endif	// GL_VERSION_3_3