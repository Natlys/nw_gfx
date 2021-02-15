static void load_GL_ES_VERSION_2_0(GLADloadproc load) {
	if (!GLAD_GL_ES_VERSION_2_0) return;
	glad_glActiveTexture = (PFNGLACTIVETEXTUREPROC)load("glActiveTexture");
	glad_glAttachShader = (PFNGLATTACHSHADERPROC)load("glAttachShader");
	glad_glBindAttribLocation = (PFNGLBINDATTRIBLOCATIONPROC)load("glBindAttribLocation");
	glad_glBindBuffer = (PFNGLBINDBUFFERPROC)load("glBindBuffer");
	glad_glBindFramebuffer = (PFNGLBINDFRAMEBUFFERPROC)load("glBindFramebuffer");
	glad_glBindRenderbuffer = (PFNGLBINDRENDERBUFFERPROC)load("glBindRenderbuffer");
	glad_glBindTexture = (PFNGLBINDTEXTUREPROC)load("glBindTexture");
	glad_glBlendColor = (PFNGLBLENDCOLORPROC)load("glBlendColor");
	glad_glBlendEquation = (PFNGLBLENDEQUATIONPROC)load("glBlendEquation");
	glad_glBlendEquationSeparate = (PFNGLBLENDEQUATIONSEPARATEPROC)load("glBlendEquationSeparate");
	glad_glBlendFunc = (PFNGLBLENDFUNCPROC)load("glBlendFunc");
	glad_glBlendFuncSeparate = (PFNGLBLENDFUNCSEPARATEPROC)load("glBlendFuncSeparate");
	glad_glBufferData = (PFNGLBUFFERDATAPROC)load("glBufferData");
	glad_glBufferSubData = (PFNGLBUFFERSUBDATAPROC)load("glBufferSubData");
	glad_glCheckFramebufferStatus = (PFNGLCHECKFRAMEBUFFERSTATUSPROC)load("glCheckFramebufferStatus");
	glad_glClear = (PFNGLCLEARPROC)load("glClear");
	glad_glClearColor = (PFNGLCLEARCOLORPROC)load("glClearColor");
	glad_glClearDepthf = (PFNGLCLEARDEPTHFPROC)load("glClearDepthf");
	glad_glClearStencil = (PFNGLCLEARSTENCILPROC)load("glClearStencil");
	glad_glColorMask = (PFNGLCOLORMASKPROC)load("glColorMask");
	glad_glCompileShader = (PFNGLCOMPILESHADERPROC)load("glCompileShader");
	glad_glCompressedTexImage2D = (PFNGLCOMPRESSEDTEXIMAGE2DPROC)load("glCompressedTexImage2D");
	glad_glCompressedTexSubImage2D = (PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)load("glCompressedTexSubImage2D");
	glad_glCopyTexImage2D = (PFNGLCOPYTEXIMAGE2DPROC)load("glCopyTexImage2D");
	glad_glCopyTexSubImage2D = (PFNGLCOPYTEXSUBIMAGE2DPROC)load("glCopyTexSubImage2D");
	glad_glCreateProgram = (PFNGLCREATEPROGRAMPROC)load("glCreateProgram");
	glad_glCreateShader = (PFNGLCREATESHADERPROC)load("glCreateShader");
	glad_glCullFace = (PFNGLCULLFACEPROC)load("glCullFace");
	glad_glDeleteBuffers = (PFNGLDELETEBUFFERSPROC)load("glDeleteBuffers");
	glad_glDeleteFramebuffers = (PFNGLDELETEFRAMEBUFFERSPROC)load("glDeleteFramebuffers");
	glad_glDeleteProgram = (PFNGLDELETEPROGRAMPROC)load("glDeleteProgram");
	glad_glDeleteRenderbuffers = (PFNGLDELETERENDERBUFFERSPROC)load("glDeleteRenderbuffers");
	glad_glDeleteShader = (PFNGLDELETESHADERPROC)load("glDeleteShader");
	glad_glDeleteTextures = (PFNGLDELETETEXTURESPROC)load("glDeleteTextures");
	glad_glDepthFunc = (PFNGLDEPTHFUNCPROC)load("glDepthFunc");
	glad_glDepthMask = (PFNGLDEPTHMASKPROC)load("glDepthMask");
	glad_glDepthRangef = (PFNGLDEPTHRANGEFPROC)load("glDepthRangef");
	glad_glDetachShader = (PFNGLDETACHSHADERPROC)load("glDetachShader");
	glad_glDisable = (PFNGLDISABLEPROC)load("glDisable");
	glad_glDisableVertexAttribArray = (PFNGLDISABLEVERTEXATTRIBARRAYPROC)load("glDisableVertexAttribArray");
	glad_glDrawArrays = (PFNGLDRAWARRAYSPROC)load("glDrawArrays");
	glad_glDrawElements = (PFNGLDRAWELEMENTSPROC)load("glDrawElements");
	glad_glEnable = (PFNGLENABLEPROC)load("glEnable");
	glad_glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC)load("glEnableVertexAttribArray");
	glad_glFinish = (PFNGLFINISHPROC)load("glFinish");
	glad_glFlush = (PFNGLFLUSHPROC)load("glFlush");
	glad_glFramebufferRenderbuffer = (PFNGLFRAMEBUFFERRENDERBUFFERPROC)load("glFramebufferRenderbuffer");
	glad_glFramebufferTexture2D = (PFNGLFRAMEBUFFERTEXTURE2DPROC)load("glFramebufferTexture2D");
	glad_glFrontFace = (PFNGLFRONTFACEPROC)load("glFrontFace");
	glad_glGenBuffers = (PFNGLGENBUFFERSPROC)load("glGenBuffers");
	glad_glGenerateMipmap = (PFNGLGENERATEMIPMAPPROC)load("glGenerateMipmap");
	glad_glGenFramebuffers = (PFNGLGENFRAMEBUFFERSPROC)load("glGenFramebuffers");
	glad_glGenRenderbuffers = (PFNGLGENRENDERBUFFERSPROC)load("glGenRenderbuffers");
	glad_glGenTextures = (PFNGLGENTEXTURESPROC)load("glGenTextures");
	glad_glGetActiveAttrib = (PFNGLGETACTIVEATTRIBPROC)load("glGetActiveAttrib");
	glad_glGetActiveUniform = (PFNGLGETACTIVEUNIFORMPROC)load("glGetActiveUniform");
	glad_glGetAttachedShaders = (PFNGLGETATTACHEDSHADERSPROC)load("glGetAttachedShaders");
	glad_glGetAttribLocation = (PFNGLGETATTRIBLOCATIONPROC)load("glGetAttribLocation");
	glad_glGetBooleanv = (PFNGLGETBOOLEANVPROC)load("glGetBooleanv");
	glad_glGetBufferParameteriv = (PFNGLGETBUFFERPARAMETERIVPROC)load("glGetBufferParameteriv");
	glad_glGetError = (PFNGLGETERRORPROC)load("glGetError");
	glad_glGetFloatv = (PFNGLGETFLOATVPROC)load("glGetFloatv");
	glad_glGetFramebufferAttachmentParameteriv = (PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC)load("glGetFramebufferAttachmentParameteriv");
	glad_glGetIntegerv = (PFNGLGETINTEGERVPROC)load("glGetIntegerv");
	glad_glGetProgramiv = (PFNGLGETPROGRAMIVPROC)load("glGetProgramiv");
	glad_glGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC)load("glGetProgramInfoLog");
	glad_glGetRenderbufferParameteriv = (PFNGLGETRENDERBUFFERPARAMETERIVPROC)load("glGetRenderbufferParameteriv");
	glad_glGetShaderiv = (PFNGLGETSHADERIVPROC)load("glGetShaderiv");
	glad_glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC)load("glGetShaderInfoLog");
	glad_glGetShaderPrecisionFormat = (PFNGLGETSHADERPRECISIONFORMATPROC)load("glGetShaderPrecisionFormat");
	glad_glGetShaderSource = (PFNGLGETSHADERSOURCEPROC)load("glGetShaderSource");
	glad_glGetString = (PFNGLGETSTRINGPROC)load("glGetString");
	glad_glGetTexParameterfv = (PFNGLGETTEXPARAMETERFVPROC)load("glGetTexParameterfv");
	glad_glGetTexParameteriv = (PFNGLGETTEXPARAMETERIVPROC)load("glGetTexParameteriv");
	glad_glGetUniformfv = (PFNGLGETUNIFORMFVPROC)load("glGetUniformfv");
	glad_glGetUniformiv = (PFNGLGETUNIFORMIVPROC)load("glGetUniformiv");
	glad_glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC)load("glGetUniformLocation");
	glad_glGetVertexAttribfv = (PFNGLGETVERTEXATTRIBFVPROC)load("glGetVertexAttribfv");
	glad_glGetVertexAttribiv = (PFNGLGETVERTEXATTRIBIVPROC)load("glGetVertexAttribiv");
	glad_glGetVertexAttribPointerv = (PFNGLGETVERTEXATTRIBPOINTERVPROC)load("glGetVertexAttribPointerv");
	glad_glHint = (PFNGLHINTPROC)load("glHint");
	glad_glIsBuffer = (PFNGLISBUFFERPROC)load("glIsBuffer");
	glad_glIsEnabled = (PFNGLISENABLEDPROC)load("glIsEnabled");
	glad_glIsFramebuffer = (PFNGLISFRAMEBUFFERPROC)load("glIsFramebuffer");
	glad_glIsProgram = (PFNGLISPROGRAMPROC)load("glIsProgram");
	glad_glIsRenderbuffer = (PFNGLISRENDERBUFFERPROC)load("glIsRenderbuffer");
	glad_glIsShader = (PFNGLISSHADERPROC)load("glIsShader");
	glad_glIsTexture = (PFNGLISTEXTUREPROC)load("glIsTexture");
	glad_glLineWidth = (PFNGLLINEWIDTHPROC)load("glLineWidth");
	glad_glLinkProgram = (PFNGLLINKPROGRAMPROC)load("glLinkProgram");
	glad_glPixelStorei = (PFNGLPIXELSTOREIPROC)load("glPixelStorei");
	glad_glPolygonOffset = (PFNGLPOLYGONOFFSETPROC)load("glPolygonOffset");
	glad_glReadPixels = (PFNGLREADPIXELSPROC)load("glReadPixels");
	glad_glReleaseShaderCompiler = (PFNGLRELEASESHADERCOMPILERPROC)load("glReleaseShaderCompiler");
	glad_glRenderbufferStorage = (PFNGLRENDERBUFFERSTORAGEPROC)load("glRenderbufferStorage");
	glad_glSampleCoverage = (PFNGLSAMPLECOVERAGEPROC)load("glSampleCoverage");
	glad_glScissor = (PFNGLSCISSORPROC)load("glScissor");
	glad_glShaderBinary = (PFNGLSHADERBINARYPROC)load("glShaderBinary");
	glad_glShaderSource = (PFNGLSHADERSOURCEPROC)load("glShaderSource");
	glad_glStencilFunc = (PFNGLSTENCILFUNCPROC)load("glStencilFunc");
	glad_glStencilFuncSeparate = (PFNGLSTENCILFUNCSEPARATEPROC)load("glStencilFuncSeparate");
	glad_glStencilMask = (PFNGLSTENCILMASKPROC)load("glStencilMask");
	glad_glStencilMaskSeparate = (PFNGLSTENCILMASKSEPARATEPROC)load("glStencilMaskSeparate");
	glad_glStencilOp = (PFNGLSTENCILOPPROC)load("glStencilOp");
	glad_glStencilOpSeparate = (PFNGLSTENCILOPSEPARATEPROC)load("glStencilOpSeparate");
	glad_glTexImage2D = (PFNGLTEXIMAGE2DPROC)load("glTexImage2D");
	glad_glTexParameterf = (PFNGLTEXPARAMETERFPROC)load("glTexParameterf");
	glad_glTexParameterfv = (PFNGLTEXPARAMETERFVPROC)load("glTexParameterfv");
	glad_glTexParameteri = (PFNGLTEXPARAMETERIPROC)load("glTexParameteri");
	glad_glTexParameteriv = (PFNGLTEXPARAMETERIVPROC)load("glTexParameteriv");
	glad_glTexSubImage2D = (PFNGLTEXSUBIMAGE2DPROC)load("glTexSubImage2D");
	glad_glUniform1f = (PFNGLUNIFORM1FPROC)load("glUniform1f");
	glad_glUniform1fv = (PFNGLUNIFORM1FVPROC)load("glUniform1fv");
	glad_glUniform1i = (PFNGLUNIFORM1IPROC)load("glUniform1i");
	glad_glUniform1iv = (PFNGLUNIFORM1IVPROC)load("glUniform1iv");
	glad_glUniform2f = (PFNGLUNIFORM2FPROC)load("glUniform2f");
	glad_glUniform2fv = (PFNGLUNIFORM2FVPROC)load("glUniform2fv");
	glad_glUniform2i = (PFNGLUNIFORM2IPROC)load("glUniform2i");
	glad_glUniform2iv = (PFNGLUNIFORM2IVPROC)load("glUniform2iv");
	glad_glUniform3f = (PFNGLUNIFORM3FPROC)load("glUniform3f");
	glad_glUniform3fv = (PFNGLUNIFORM3FVPROC)load("glUniform3fv");
	glad_glUniform3i = (PFNGLUNIFORM3IPROC)load("glUniform3i");
	glad_glUniform3iv = (PFNGLUNIFORM3IVPROC)load("glUniform3iv");
	glad_glUniform4f = (PFNGLUNIFORM4FPROC)load("glUniform4f");
	glad_glUniform4fv = (PFNGLUNIFORM4FVPROC)load("glUniform4fv");
	glad_glUniform4i = (PFNGLUNIFORM4IPROC)load("glUniform4i");
	glad_glUniform4iv = (PFNGLUNIFORM4IVPROC)load("glUniform4iv");
	glad_glUniformMatrix2fv = (PFNGLUNIFORMMATRIX2FVPROC)load("glUniformMatrix2fv");
	glad_glUniformMatrix3fv = (PFNGLUNIFORMMATRIX3FVPROC)load("glUniformMatrix3fv");
	glad_glUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC)load("glUniformMatrix4fv");
	glad_glUseProgram = (PFNGLUSEPROGRAMPROC)load("glUseProgram");
	glad_glValidateProgram = (PFNGLVALIDATEPROGRAMPROC)load("glValidateProgram");
	glad_glVertexAttrib1f = (PFNGLVERTEXATTRIB1FPROC)load("glVertexAttrib1f");
	glad_glVertexAttrib1fv = (PFNGLVERTEXATTRIB1FVPROC)load("glVertexAttrib1fv");
	glad_glVertexAttrib2f = (PFNGLVERTEXATTRIB2FPROC)load("glVertexAttrib2f");
	glad_glVertexAttrib2fv = (PFNGLVERTEXATTRIB2FVPROC)load("glVertexAttrib2fv");
	glad_glVertexAttrib3f = (PFNGLVERTEXATTRIB3FPROC)load("glVertexAttrib3f");
	glad_glVertexAttrib3fv = (PFNGLVERTEXATTRIB3FVPROC)load("glVertexAttrib3fv");
	glad_glVertexAttrib4f = (PFNGLVERTEXATTRIB4FPROC)load("glVertexAttrib4f");
	glad_glVertexAttrib4fv = (PFNGLVERTEXATTRIB4FVPROC)load("glVertexAttrib4fv");
	glad_glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC)load("glVertexAttribPointer");
	glad_glViewport = (PFNGLVIEWPORTPROC)load("glViewport");
}
static void load_GL_ES_VERSION_3_0(GLADloadproc load) {
	if (!GLAD_GL_ES_VERSION_3_0) return;
	glad_glReadBuffer = (PFNGLREADBUFFERPROC)load("glReadBuffer");
	glad_glDrawRangeElements = (PFNGLDRAWRANGEELEMENTSPROC)load("glDrawRangeElements");
	glad_glTexImage3D = (PFNGLTEXIMAGE3DPROC)load("glTexImage3D");
	glad_glTexSubImage3D = (PFNGLTEXSUBIMAGE3DPROC)load("glTexSubImage3D");
	glad_glCopyTexSubImage3D = (PFNGLCOPYTEXSUBIMAGE3DPROC)load("glCopyTexSubImage3D");
	glad_glCompressedTexImage3D = (PFNGLCOMPRESSEDTEXIMAGE3DPROC)load("glCompressedTexImage3D");
	glad_glCompressedTexSubImage3D = (PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC)load("glCompressedTexSubImage3D");
	glad_glGenQueries = (PFNGLGENQUERIESPROC)load("glGenQueries");
	glad_glDeleteQueries = (PFNGLDELETEQUERIESPROC)load("glDeleteQueries");
	glad_glIsQuery = (PFNGLISQUERYPROC)load("glIsQuery");
	glad_glBeginQuery = (PFNGLBEGINQUERYPROC)load("glBeginQuery");
	glad_glEndQuery = (PFNGLENDQUERYPROC)load("glEndQuery");
	glad_glGetQueryiv = (PFNGLGETQUERYIVPROC)load("glGetQueryiv");
	glad_glGetQueryObjectuiv = (PFNGLGETQUERYOBJECTUIVPROC)load("glGetQueryObjectuiv");
	glad_glUnmapBuffer = (PFNGLUNMAPBUFFERPROC)load("glUnmapBuffer");
	glad_glGetBufferPointerv = (PFNGLGETBUFFERPOINTERVPROC)load("glGetBufferPointerv");
	glad_glDrawBuffers = (PFNGLDRAWBUFFERSPROC)load("glDrawBuffers");
	glad_glUniformMatrix2x3fv = (PFNGLUNIFORMMATRIX2X3FVPROC)load("glUniformMatrix2x3fv");
	glad_glUniformMatrix3x2fv = (PFNGLUNIFORMMATRIX3X2FVPROC)load("glUniformMatrix3x2fv");
	glad_glUniformMatrix2x4fv = (PFNGLUNIFORMMATRIX2X4FVPROC)load("glUniformMatrix2x4fv");
	glad_glUniformMatrix4x2fv = (PFNGLUNIFORMMATRIX4X2FVPROC)load("glUniformMatrix4x2fv");
	glad_glUniformMatrix3x4fv = (PFNGLUNIFORMMATRIX3X4FVPROC)load("glUniformMatrix3x4fv");
	glad_glUniformMatrix4x3fv = (PFNGLUNIFORMMATRIX4X3FVPROC)load("glUniformMatrix4x3fv");
	glad_glBlitFramebuffer = (PFNGLBLITFRAMEBUFFERPROC)load("glBlitFramebuffer");
	glad_glRenderbufferStorageMultisample = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC)load("glRenderbufferStorageMultisample");
	glad_glFramebufferTextureLayer = (PFNGLFRAMEBUFFERTEXTURELAYERPROC)load("glFramebufferTextureLayer");
	glad_glMapBufferRange = (PFNGLMAPBUFFERRANGEPROC)load("glMapBufferRange");
	glad_glFlushMappedBufferRange = (PFNGLFLUSHMAPPEDBUFFERRANGEPROC)load("glFlushMappedBufferRange");
	glad_glBindVertexArray = (PFNGLBINDVERTEXARRAYPROC)load("glBindVertexArray");
	glad_glDeleteVertexArrays = (PFNGLDELETEVERTEXARRAYSPROC)load("glDeleteVertexArrays");
	glad_glGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC)load("glGenVertexArrays");
	glad_glIsVertexArray = (PFNGLISVERTEXARRAYPROC)load("glIsVertexArray");
	glad_glGetIntegeri_v = (PFNGLGETINTEGERI_VPROC)load("glGetIntegeri_v");
	glad_glBeginTransformFeedback = (PFNGLBEGINTRANSFORMFEEDBACKPROC)load("glBeginTransformFeedback");
	glad_glEndTransformFeedback = (PFNGLENDTRANSFORMFEEDBACKPROC)load("glEndTransformFeedback");
	glad_glBindBufferRange = (PFNGLBINDBUFFERRANGEPROC)load("glBindBufferRange");
	glad_glBindBufferBase = (PFNGLBINDBUFFERBASEPROC)load("glBindBufferBase");
	glad_glTransformFeedbackVaryings = (PFNGLTRANSFORMFEEDBACKVARYINGSPROC)load("glTransformFeedbackVaryings");
	glad_glGetTransformFeedbackVarying = (PFNGLGETTRANSFORMFEEDBACKVARYINGPROC)load("glGetTransformFeedbackVarying");
	glad_glVertexAttribIPointer = (PFNGLVERTEXATTRIBIPOINTERPROC)load("glVertexAttribIPointer");
	glad_glGetVertexAttribIiv = (PFNGLGETVERTEXATTRIBIIVPROC)load("glGetVertexAttribIiv");
	glad_glGetVertexAttribIuiv = (PFNGLGETVERTEXATTRIBIUIVPROC)load("glGetVertexAttribIuiv");
	glad_glVertexAttribI4i = (PFNGLVERTEXATTRIBI4IPROC)load("glVertexAttribI4i");
	glad_glVertexAttribI4ui = (PFNGLVERTEXATTRIBI4UIPROC)load("glVertexAttribI4ui");
	glad_glVertexAttribI4iv = (PFNGLVERTEXATTRIBI4IVPROC)load("glVertexAttribI4iv");
	glad_glVertexAttribI4uiv = (PFNGLVERTEXATTRIBI4UIVPROC)load("glVertexAttribI4uiv");
	glad_glGetUniformuiv = (PFNGLGETUNIFORMUIVPROC)load("glGetUniformuiv");
	glad_glGetFragDataLocation = (PFNGLGETFRAGDATALOCATIONPROC)load("glGetFragDataLocation");
	glad_glUniform1ui = (PFNGLUNIFORM1UIPROC)load("glUniform1ui");
	glad_glUniform2ui = (PFNGLUNIFORM2UIPROC)load("glUniform2ui");
	glad_glUniform3ui = (PFNGLUNIFORM3UIPROC)load("glUniform3ui");
	glad_glUniform4ui = (PFNGLUNIFORM4UIPROC)load("glUniform4ui");
	glad_glUniform1uiv = (PFNGLUNIFORM1UIVPROC)load("glUniform1uiv");
	glad_glUniform2uiv = (PFNGLUNIFORM2UIVPROC)load("glUniform2uiv");
	glad_glUniform3uiv = (PFNGLUNIFORM3UIVPROC)load("glUniform3uiv");
	glad_glUniform4uiv = (PFNGLUNIFORM4UIVPROC)load("glUniform4uiv");
	glad_glClearBufferiv = (PFNGLCLEARBUFFERIVPROC)load("glClearBufferiv");
	glad_glClearBufferuiv = (PFNGLCLEARBUFFERUIVPROC)load("glClearBufferuiv");
	glad_glClearBufferfv = (PFNGLCLEARBUFFERFVPROC)load("glClearBufferfv");
	glad_glClearBufferfi = (PFNGLCLEARBUFFERFIPROC)load("glClearBufferfi");
	glad_glGetStringi = (PFNGLGETSTRINGIPROC)load("glGetStringi");
	glad_glCopyBufferSubData = (PFNGLCOPYBUFFERSUBDATAPROC)load("glCopyBufferSubData");
	glad_glGetUniformIndices = (PFNGLGETUNIFORMINDICESPROC)load("glGetUniformIndices");
	glad_glGetActiveUniformsiv = (PFNGLGETACTIVEUNIFORMSIVPROC)load("glGetActiveUniformsiv");
	glad_glGetUniformBlockIndex = (PFNGLGETUNIFORMBLOCKINDEXPROC)load("glGetUniformBlockIndex");
	glad_glGetActiveUniformBlockiv = (PFNGLGETACTIVEUNIFORMBLOCKIVPROC)load("glGetActiveUniformBlockiv");
	glad_glGetActiveUniformBlockName = (PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC)load("glGetActiveUniformBlockName");
	glad_glUniformBlockBinding = (PFNGLUNIFORMBLOCKBINDINGPROC)load("glUniformBlockBinding");
	glad_glDrawArraysInstanced = (PFNGLDRAWARRAYSINSTANCEDPROC)load("glDrawArraysInstanced");
	glad_glDrawElementsInstanced = (PFNGLDRAWELEMENTSINSTANCEDPROC)load("glDrawElementsInstanced");
	glad_glFenceSync = (PFNGLFENCESYNCPROC)load("glFenceSync");
	glad_glIsSync = (PFNGLISSYNCPROC)load("glIsSync");
	glad_glDeleteSync = (PFNGLDELETESYNCPROC)load("glDeleteSync");
	glad_glClientWaitSync = (PFNGLCLIENTWAITSYNCPROC)load("glClientWaitSync");
	glad_glWaitSync = (PFNGLWAITSYNCPROC)load("glWaitSync");
	glad_glGetInteger64v = (PFNGLGETINTEGER64VPROC)load("glGetInteger64v");
	glad_glGetSynciv = (PFNGLGETSYNCIVPROC)load("glGetSynciv");
	glad_glGetInteger64i_v = (PFNGLGETINTEGER64I_VPROC)load("glGetInteger64i_v");
	glad_glGetBufferParameteri64v = (PFNGLGETBUFFERPARAMETERI64VPROC)load("glGetBufferParameteri64v");
	glad_glGenSamplers = (PFNGLGENSAMPLERSPROC)load("glGenSamplers");
	glad_glDeleteSamplers = (PFNGLDELETESAMPLERSPROC)load("glDeleteSamplers");
	glad_glIsSampler = (PFNGLISSAMPLERPROC)load("glIsSampler");
	glad_glBindSampler = (PFNGLBINDSAMPLERPROC)load("glBindSampler");
	glad_glSamplerParameteri = (PFNGLSAMPLERPARAMETERIPROC)load("glSamplerParameteri");
	glad_glSamplerParameteriv = (PFNGLSAMPLERPARAMETERIVPROC)load("glSamplerParameteriv");
	glad_glSamplerParameterf = (PFNGLSAMPLERPARAMETERFPROC)load("glSamplerParameterf");
	glad_glSamplerParameterfv = (PFNGLSAMPLERPARAMETERFVPROC)load("glSamplerParameterfv");
	glad_glGetSamplerParameteriv = (PFNGLGETSAMPLERPARAMETERIVPROC)load("glGetSamplerParameteriv");
	glad_glGetSamplerParameterfv = (PFNGLGETSAMPLERPARAMETERFVPROC)load("glGetSamplerParameterfv");
	glad_glVertexAttribDivisor = (PFNGLVERTEXATTRIBDIVISORPROC)load("glVertexAttribDivisor");
	glad_glBindTransformFeedback = (PFNGLBINDTRANSFORMFEEDBACKPROC)load("glBindTransformFeedback");
	glad_glDeleteTransformFeedbacks = (PFNGLDELETETRANSFORMFEEDBACKSPROC)load("glDeleteTransformFeedbacks");
	glad_glGenTransformFeedbacks = (PFNGLGENTRANSFORMFEEDBACKSPROC)load("glGenTransformFeedbacks");
	glad_glIsTransformFeedback = (PFNGLISTRANSFORMFEEDBACKPROC)load("glIsTransformFeedback");
	glad_glPauseTransformFeedback = (PFNGLPAUSETRANSFORMFEEDBACKPROC)load("glPauseTransformFeedback");
	glad_glResumeTransformFeedback = (PFNGLRESUMETRANSFORMFEEDBACKPROC)load("glResumeTransformFeedback");
	glad_glGetProgramBinary = (PFNGLGETPROGRAMBINARYPROC)load("glGetProgramBinary");
	glad_glProgramBinary = (PFNGLPROGRAMBINARYPROC)load("glProgramBinary");
	glad_glProgramParameteri = (PFNGLPROGRAMPARAMETERIPROC)load("glProgramParameteri");
	glad_glInvalidateFramebuffer = (PFNGLINVALIDATEFRAMEBUFFERPROC)load("glInvalidateFramebuffer");
	glad_glInvalidateSubFramebuffer = (PFNGLINVALIDATESUBFRAMEBUFFERPROC)load("glInvalidateSubFramebuffer");
	glad_glTexStorage2D = (PFNGLTEXSTORAGE2DPROC)load("glTexStorage2D");
	glad_glTexStorage3D = (PFNGLTEXSTORAGE3DPROC)load("glTexStorage3D");
	glad_glGetInternalformativ = (PFNGLGETINTERNALFORMATIVPROC)load("glGetInternalformativ");
}
static void load_GL_ES_VERSION_3_1(GLADloadproc load) {
	if (!GLAD_GL_ES_VERSION_3_1) return;
	glad_glDispatchCompute = (PFNGLDISPATCHCOMPUTEPROC)load("glDispatchCompute");
	glad_glDispatchComputeIndirect = (PFNGLDISPATCHCOMPUTEINDIRECTPROC)load("glDispatchComputeIndirect");
	glad_glDrawArraysIndirect = (PFNGLDRAWARRAYSINDIRECTPROC)load("glDrawArraysIndirect");
	glad_glDrawElementsIndirect = (PFNGLDRAWELEMENTSINDIRECTPROC)load("glDrawElementsIndirect");
	glad_glFramebufferParameteri = (PFNGLFRAMEBUFFERPARAMETERIPROC)load("glFramebufferParameteri");
	glad_glGetFramebufferParameteriv = (PFNGLGETFRAMEBUFFERPARAMETERIVPROC)load("glGetFramebufferParameteriv");
	glad_glGetProgramInterfaceiv = (PFNGLGETPROGRAMINTERFACEIVPROC)load("glGetProgramInterfaceiv");
	glad_glGetProgramResourceIndex = (PFNGLGETPROGRAMRESOURCEINDEXPROC)load("glGetProgramResourceIndex");
	glad_glGetProgramResourceName = (PFNGLGETPROGRAMRESOURCENAMEPROC)load("glGetProgramResourceName");
	glad_glGetProgramResourceiv = (PFNGLGETPROGRAMRESOURCEIVPROC)load("glGetProgramResourceiv");
	glad_glGetProgramResourceLocation = (PFNGLGETPROGRAMRESOURCELOCATIONPROC)load("glGetProgramResourceLocation");
	glad_glUseProgramStages = (PFNGLUSEPROGRAMSTAGESPROC)load("glUseProgramStages");
	glad_glActiveShaderProgram = (PFNGLACTIVESHADERPROGRAMPROC)load("glActiveShaderProgram");
	glad_glCreateShaderProgramv = (PFNGLCREATESHADERPROGRAMVPROC)load("glCreateShaderProgramv");
	glad_glBindProgramPipeline = (PFNGLBINDPROGRAMPIPELINEPROC)load("glBindProgramPipeline");
	glad_glDeleteProgramPipelines = (PFNGLDELETEPROGRAMPIPELINESPROC)load("glDeleteProgramPipelines");
	glad_glGenProgramPipelines = (PFNGLGENPROGRAMPIPELINESPROC)load("glGenProgramPipelines");
	glad_glIsProgramPipeline = (PFNGLISPROGRAMPIPELINEPROC)load("glIsProgramPipeline");
	glad_glGetProgramPipelineiv = (PFNGLGETPROGRAMPIPELINEIVPROC)load("glGetProgramPipelineiv");
	glad_glProgramUniform1i = (PFNGLPROGRAMUNIFORM1IPROC)load("glProgramUniform1i");
	glad_glProgramUniform2i = (PFNGLPROGRAMUNIFORM2IPROC)load("glProgramUniform2i");
	glad_glProgramUniform3i = (PFNGLPROGRAMUNIFORM3IPROC)load("glProgramUniform3i");
	glad_glProgramUniform4i = (PFNGLPROGRAMUNIFORM4IPROC)load("glProgramUniform4i");
	glad_glProgramUniform1ui = (PFNGLPROGRAMUNIFORM1UIPROC)load("glProgramUniform1ui");
	glad_glProgramUniform2ui = (PFNGLPROGRAMUNIFORM2UIPROC)load("glProgramUniform2ui");
	glad_glProgramUniform3ui = (PFNGLPROGRAMUNIFORM3UIPROC)load("glProgramUniform3ui");
	glad_glProgramUniform4ui = (PFNGLPROGRAMUNIFORM4UIPROC)load("glProgramUniform4ui");
	glad_glProgramUniform1f = (PFNGLPROGRAMUNIFORM1FPROC)load("glProgramUniform1f");
	glad_glProgramUniform2f = (PFNGLPROGRAMUNIFORM2FPROC)load("glProgramUniform2f");
	glad_glProgramUniform3f = (PFNGLPROGRAMUNIFORM3FPROC)load("glProgramUniform3f");
	glad_glProgramUniform4f = (PFNGLPROGRAMUNIFORM4FPROC)load("glProgramUniform4f");
	glad_glProgramUniform1iv = (PFNGLPROGRAMUNIFORM1IVPROC)load("glProgramUniform1iv");
	glad_glProgramUniform2iv = (PFNGLPROGRAMUNIFORM2IVPROC)load("glProgramUniform2iv");
	glad_glProgramUniform3iv = (PFNGLPROGRAMUNIFORM3IVPROC)load("glProgramUniform3iv");
	glad_glProgramUniform4iv = (PFNGLPROGRAMUNIFORM4IVPROC)load("glProgramUniform4iv");
	glad_glProgramUniform1uiv = (PFNGLPROGRAMUNIFORM1UIVPROC)load("glProgramUniform1uiv");
	glad_glProgramUniform2uiv = (PFNGLPROGRAMUNIFORM2UIVPROC)load("glProgramUniform2uiv");
	glad_glProgramUniform3uiv = (PFNGLPROGRAMUNIFORM3UIVPROC)load("glProgramUniform3uiv");
	glad_glProgramUniform4uiv = (PFNGLPROGRAMUNIFORM4UIVPROC)load("glProgramUniform4uiv");
	glad_glProgramUniform1fv = (PFNGLPROGRAMUNIFORM1FVPROC)load("glProgramUniform1fv");
	glad_glProgramUniform2fv = (PFNGLPROGRAMUNIFORM2FVPROC)load("glProgramUniform2fv");
	glad_glProgramUniform3fv = (PFNGLPROGRAMUNIFORM3FVPROC)load("glProgramUniform3fv");
	glad_glProgramUniform4fv = (PFNGLPROGRAMUNIFORM4FVPROC)load("glProgramUniform4fv");
	glad_glProgramUniformMatrix2fv = (PFNGLPROGRAMUNIFORMMATRIX2FVPROC)load("glProgramUniformMatrix2fv");
	glad_glProgramUniformMatrix3fv = (PFNGLPROGRAMUNIFORMMATRIX3FVPROC)load("glProgramUniformMatrix3fv");
	glad_glProgramUniformMatrix4fv = (PFNGLPROGRAMUNIFORMMATRIX4FVPROC)load("glProgramUniformMatrix4fv");
	glad_glProgramUniformMatrix2x3fv = (PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC)load("glProgramUniformMatrix2x3fv");
	glad_glProgramUniformMatrix3x2fv = (PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC)load("glProgramUniformMatrix3x2fv");
	glad_glProgramUniformMatrix2x4fv = (PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC)load("glProgramUniformMatrix2x4fv");
	glad_glProgramUniformMatrix4x2fv = (PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC)load("glProgramUniformMatrix4x2fv");
	glad_glProgramUniformMatrix3x4fv = (PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC)load("glProgramUniformMatrix3x4fv");
	glad_glProgramUniformMatrix4x3fv = (PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC)load("glProgramUniformMatrix4x3fv");
	glad_glValidateProgramPipeline = (PFNGLVALIDATEPROGRAMPIPELINEPROC)load("glValidateProgramPipeline");
	glad_glGetProgramPipelineInfoLog = (PFNGLGETPROGRAMPIPELINEINFOLOGPROC)load("glGetProgramPipelineInfoLog");
	glad_glBindImageTexture = (PFNGLBINDIMAGETEXTUREPROC)load("glBindImageTexture");
	glad_glGetBooleani_v = (PFNGLGETBOOLEANI_VPROC)load("glGetBooleani_v");
	glad_glMemoryBarrier = (PFNGLMEMORYBARRIERPROC)load("glMemoryBarrier");
	glad_glMemoryBarrierByRegion = (PFNGLMEMORYBARRIERBYREGIONPROC)load("glMemoryBarrierByRegion");
	glad_glTexStorage2DMultisample = (PFNGLTEXSTORAGE2DMULTISAMPLEPROC)load("glTexStorage2DMultisample");
	glad_glGetMultisamplefv = (PFNGLGETMULTISAMPLEFVPROC)load("glGetMultisamplefv");
	glad_glSampleMaski = (PFNGLSAMPLEMASKIPROC)load("glSampleMaski");
	glad_glGetTexLevelParameteriv = (PFNGLGETTEXLEVELPARAMETERIVPROC)load("glGetTexLevelParameteriv");
	glad_glGetTexLevelParameterfv = (PFNGLGETTEXLEVELPARAMETERFVPROC)load("glGetTexLevelParameterfv");
	glad_glBindVertexBuffer = (PFNGLBINDVERTEXBUFFERPROC)load("glBindVertexBuffer");
	glad_glVertexAttribFormat = (PFNGLVERTEXATTRIBFORMATPROC)load("glVertexAttribFormat");
	glad_glVertexAttribIFormat = (PFNGLVERTEXATTRIBIFORMATPROC)load("glVertexAttribIFormat");
	glad_glVertexAttribBinding = (PFNGLVERTEXATTRIBBINDINGPROC)load("glVertexAttribBinding");
	glad_glVertexBindingDivisor = (PFNGLVERTEXBINDINGDIVISORPROC)load("glVertexBindingDivisor");
}
static void load_GL_NV_non_square_matrices(GLADloadproc load) {
	if (!GLAD_GL_NV_non_square_matrices) return;
	glad_glUniformMatrix2x3fvNV = (PFNGLUNIFORMMATRIX2X3FVNVPROC)load("glUniformMatrix2x3fvNV");
	glad_glUniformMatrix3x2fvNV = (PFNGLUNIFORMMATRIX3X2FVNVPROC)load("glUniformMatrix3x2fvNV");
	glad_glUniformMatrix2x4fvNV = (PFNGLUNIFORMMATRIX2X4FVNVPROC)load("glUniformMatrix2x4fvNV");
	glad_glUniformMatrix4x2fvNV = (PFNGLUNIFORMMATRIX4X2FVNVPROC)load("glUniformMatrix4x2fvNV");
	glad_glUniformMatrix3x4fvNV = (PFNGLUNIFORMMATRIX3X4FVNVPROC)load("glUniformMatrix3x4fvNV");
	glad_glUniformMatrix4x3fvNV = (PFNGLUNIFORMMATRIX4X3FVNVPROC)load("glUniformMatrix4x3fvNV");
}
static void load_GL_EXT_sparse_texture(GLADloadproc load) {
	if (!GLAD_GL_EXT_sparse_texture) return;
	glad_glTexPageCommitmentARB = (PFNGLTEXPAGECOMMITMENTARBPROC)load("glTexPageCommitmentARB");
}
static void load_GL_NV_draw_instanced(GLADloadproc load) {
	if (!GLAD_GL_NV_draw_instanced) return;
	glad_glDrawArraysInstancedNV = (PFNGLDRAWARRAYSINSTANCEDNVPROC)load("glDrawArraysInstancedNV");
	glad_glDrawElementsInstancedNV = (PFNGLDRAWELEMENTSINSTANCEDNVPROC)load("glDrawElementsInstancedNV");
}
static void load_GL_EXT_base_instance(GLADloadproc load) {
	if (!GLAD_GL_EXT_base_instance) return;
	glad_glDrawArraysInstancedBaseInstanceEXT = (PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEEXTPROC)load("glDrawArraysInstancedBaseInstanceEXT");
	glad_glDrawElementsInstancedBaseInstanceEXT = (PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEEXTPROC)load("glDrawElementsInstancedBaseInstanceEXT");
	glad_glDrawElementsInstancedBaseVertexBaseInstanceEXT = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEEXTPROC)load("glDrawElementsInstancedBaseVertexBaseInstanceEXT");
}
static void load_GL_EXT_instanced_arrays(GLADloadproc load) {
	if (!GLAD_GL_EXT_instanced_arrays) return;
	glad_glDrawArraysInstancedEXT = (PFNGLDRAWARRAYSINSTANCEDEXTPROC)load("glDrawArraysInstancedEXT");
	glad_glDrawElementsInstancedEXT = (PFNGLDRAWELEMENTSINSTANCEDEXTPROC)load("glDrawElementsInstancedEXT");
	glad_glVertexAttribDivisorEXT = (PFNGLVERTEXATTRIBDIVISOREXTPROC)load("glVertexAttribDivisorEXT");
}
static void load_GL_EXT_draw_buffers_indexed(GLADloadproc load) {
	if (!GLAD_GL_EXT_draw_buffers_indexed) return;
	glad_glEnableiEXT = (PFNGLENABLEIEXTPROC)load("glEnableiEXT");
	glad_glDisableiEXT = (PFNGLDISABLEIEXTPROC)load("glDisableiEXT");
	glad_glBlendEquationiEXT = (PFNGLBLENDEQUATIONIEXTPROC)load("glBlendEquationiEXT");
	glad_glBlendEquationSeparateiEXT = (PFNGLBLENDEQUATIONSEPARATEIEXTPROC)load("glBlendEquationSeparateiEXT");
	glad_glBlendFunciEXT = (PFNGLBLENDFUNCIEXTPROC)load("glBlendFunciEXT");
	glad_glBlendFuncSeparateiEXT = (PFNGLBLENDFUNCSEPARATEIEXTPROC)load("glBlendFuncSeparateiEXT");
	glad_glColorMaskiEXT = (PFNGLCOLORMASKIEXTPROC)load("glColorMaskiEXT");
	glad_glIsEnablediEXT = (PFNGLISENABLEDIEXTPROC)load("glIsEnablediEXT");
}
static void load_GL_ANGLE_translated_shader_source(GLADloadproc load) {
	if (!GLAD_GL_ANGLE_translated_shader_source) return;
	glad_glGetTranslatedShaderSourceANGLE = (PFNGLGETTRANSLATEDSHADERSOURCEANGLEPROC)load("glGetTranslatedShaderSourceANGLE");
}
static void load_GL_NV_coverage_sample(GLADloadproc load) {
	if (!GLAD_GL_NV_coverage_sample) return;
	glad_glCoverageMaskNV = (PFNGLCOVERAGEMASKNVPROC)load("glCoverageMaskNV");
	glad_glCoverageOperationNV = (PFNGLCOVERAGEOPERATIONNVPROC)load("glCoverageOperationNV");
}
static void load_GL_ANGLE_framebuffer_multisample(GLADloadproc load) {
	if (!GLAD_GL_ANGLE_framebuffer_multisample) return;
	glad_glRenderbufferStorageMultisampleANGLE = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLEANGLEPROC)load("glRenderbufferStorageMultisampleANGLE");
}
static void load_GL_OES_vertex_array_object(GLADloadproc load) {
	if (!GLAD_GL_OES_vertex_array_object) return;
	glad_glBindVertexArrayOES = (PFNGLBINDVERTEXARRAYOESPROC)load("glBindVertexArrayOES");
	glad_glDeleteVertexArraysOES = (PFNGLDELETEVERTEXARRAYSOESPROC)load("glDeleteVertexArraysOES");
	glad_glGenVertexArraysOES = (PFNGLGENVERTEXARRAYSOESPROC)load("glGenVertexArraysOES");
	glad_glIsVertexArrayOES = (PFNGLISVERTEXARRAYOESPROC)load("glIsVertexArrayOES");
}
static void load_GL_QCOM_tiled_rendering(GLADloadproc load) {
	if (!GLAD_GL_QCOM_tiled_rendering) return;
	glad_glStartTilingQCOM = (PFNGLSTARTTILINGQCOMPROC)load("glStartTilingQCOM");
	glad_glEndTilingQCOM = (PFNGLENDTILINGQCOMPROC)load("glEndTilingQCOM");
}
static void load_GL_EXT_robustness(GLADloadproc load) {
	if (!GLAD_GL_EXT_robustness) return;
	glad_glGetGraphicsResetStatusEXT = (PFNGLGETGRAPHICSRESETSTATUSEXTPROC)load("glGetGraphicsResetStatusEXT");
	glad_glReadnPixelsEXT = (PFNGLREADNPIXELSEXTPROC)load("glReadnPixelsEXT");
	glad_glGetnUniformfvEXT = (PFNGLGETNUNIFORMFVEXTPROC)load("glGetnUniformfvEXT");
	glad_glGetnUniformivEXT = (PFNGLGETNUNIFORMIVEXTPROC)load("glGetnUniformivEXT");
}
static void load_GL_EXT_disjoint_timer_query(GLADloadproc load) {
	if (!GLAD_GL_EXT_disjoint_timer_query) return;
	glad_glGenQueriesEXT = (PFNGLGENQUERIESEXTPROC)load("glGenQueriesEXT");
	glad_glDeleteQueriesEXT = (PFNGLDELETEQUERIESEXTPROC)load("glDeleteQueriesEXT");
	glad_glIsQueryEXT = (PFNGLISQUERYEXTPROC)load("glIsQueryEXT");
	glad_glBeginQueryEXT = (PFNGLBEGINQUERYEXTPROC)load("glBeginQueryEXT");
	glad_glEndQueryEXT = (PFNGLENDQUERYEXTPROC)load("glEndQueryEXT");
	glad_glQueryCounterEXT = (PFNGLQUERYCOUNTEREXTPROC)load("glQueryCounterEXT");
	glad_glGetQueryivEXT = (PFNGLGETQUERYIVEXTPROC)load("glGetQueryivEXT");
	glad_glGetQueryObjectivEXT = (PFNGLGETQUERYOBJECTIVEXTPROC)load("glGetQueryObjectivEXT");
	glad_glGetQueryObjectuivEXT = (PFNGLGETQUERYOBJECTUIVEXTPROC)load("glGetQueryObjectuivEXT");
	glad_glGetQueryObjecti64vEXT = (PFNGLGETQUERYOBJECTI64VEXTPROC)load("glGetQueryObjecti64vEXT");
	glad_glGetQueryObjectui64vEXT = (PFNGLGETQUERYOBJECTUI64VEXTPROC)load("glGetQueryObjectui64vEXT");
}
static void load_GL_EXT_primitive_bounding_box(GLADloadproc load) {
	if (!GLAD_GL_EXT_primitive_bounding_box) return;
	glad_glPrimitiveBoundingBoxEXT = (PFNGLPRIMITIVEBOUNDINGBOXEXTPROC)load("glPrimitiveBoundingBoxEXT");
}
static void load_GL_QCOM_driver_control(GLADloadproc load) {
	if (!GLAD_GL_QCOM_driver_control) return;
	glad_glGetDriverControlsQCOM = (PFNGLGETDRIVERCONTROLSQCOMPROC)load("glGetDriverControlsQCOM");
	glad_glGetDriverControlStringQCOM = (PFNGLGETDRIVERCONTROLSTRINGQCOMPROC)load("glGetDriverControlStringQCOM");
	glad_glEnableDriverControlQCOM = (PFNGLENABLEDRIVERCONTROLQCOMPROC)load("glEnableDriverControlQCOM");
	glad_glDisableDriverControlQCOM = (PFNGLDISABLEDRIVERCONTROLQCOMPROC)load("glDisableDriverControlQCOM");
}
static void load_GL_OES_geometry_shader(GLADloadproc load) {
	if (!GLAD_GL_OES_geometry_shader) return;
	glad_glFramebufferTextureOES = (PFNGLFRAMEBUFFERTEXTUREOESPROC)load("glFramebufferTextureOES");
}
static void load_GL_OES_tessellation_shader(GLADloadproc load) {
	if (!GLAD_GL_OES_tessellation_shader) return;
	glad_glPatchParameteriOES = (PFNGLPATCHPARAMETERIOESPROC)load("glPatchParameteriOES");
}
static void load_GL_OES_texture_view(GLADloadproc load) {
	if (!GLAD_GL_OES_texture_view) return;
	glad_glTextureViewOES = (PFNGLTEXTUREVIEWOESPROC)load("glTextureViewOES");
}
static void load_GL_EXT_multisampled_render_to_texture(GLADloadproc load) {
	if (!GLAD_GL_EXT_multisampled_render_to_texture) return;
	glad_glRenderbufferStorageMultisampleEXT = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLEEXTPROC)load("glRenderbufferStorageMultisampleEXT");
	glad_glFramebufferTexture2DMultisampleEXT = (PFNGLFRAMEBUFFERTEXTURE2DMULTISAMPLEEXTPROC)load("glFramebufferTexture2DMultisampleEXT");
}
static void load_GL_EXT_buffer_storage(GLADloadproc load) {
	if (!GLAD_GL_EXT_buffer_storage) return;
	glad_glBufferStorageEXT = (PFNGLBUFFERSTORAGEEXTPROC)load("glBufferStorageEXT");
}
static void load_GL_OES_texture_buffer(GLADloadproc load) {
	if (!GLAD_GL_OES_texture_buffer) return;
	glad_glTexBufferOES = (PFNGLTEXBUFFEROESPROC)load("glTexBufferOES");
	glad_glTexBufferRangeOES = (PFNGLTEXBUFFERRANGEOESPROC)load("glTexBufferRangeOES");
}
static void load_GL_OES_get_program_binary(GLADloadproc load) {
	if (!GLAD_GL_OES_get_program_binary) return;
	glad_glGetProgramBinaryOES = (PFNGLGETPROGRAMBINARYOESPROC)load("glGetProgramBinaryOES");
	glad_glProgramBinaryOES = (PFNGLPROGRAMBINARYOESPROC)load("glProgramBinaryOES");
}
static void load_GL_APPLE_framebuffer_multisample(GLADloadproc load) {
	if (!GLAD_GL_APPLE_framebuffer_multisample) return;
	glad_glRenderbufferStorageMultisampleAPPLE = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLEAPPLEPROC)load("glRenderbufferStorageMultisampleAPPLE");
	glad_glResolveMultisampleFramebufferAPPLE = (PFNGLRESOLVEMULTISAMPLEFRAMEBUFFERAPPLEPROC)load("glResolveMultisampleFramebufferAPPLE");
}
static void load_GL_NV_copy_buffer(GLADloadproc load) {
	if (!GLAD_GL_NV_copy_buffer) return;
	glad_glCopyBufferSubDataNV = (PFNGLCOPYBUFFERSUBDATANVPROC)load("glCopyBufferSubDataNV");
}
static void load_GL_EXT_texture_view(GLADloadproc load) {
	if (!GLAD_GL_EXT_texture_view) return;
	glad_glTextureViewEXT = (PFNGLTEXTUREVIEWEXTPROC)load("glTextureViewEXT");
}
static void load_GL_NV_framebuffer_blit(GLADloadproc load) {
	if (!GLAD_GL_NV_framebuffer_blit) return;
	glad_glBlitFramebufferNV = (PFNGLBLITFRAMEBUFFERNVPROC)load("glBlitFramebufferNV");
}
static void load_GL_QCOM_alpha_test(GLADloadproc load) {
	if (!GLAD_GL_QCOM_alpha_test) return;
	glad_glAlphaFuncQCOM = (PFNGLALPHAFUNCQCOMPROC)load("glAlphaFuncQCOM");
}
static void load_GL_OES_texture_border_clamp(GLADloadproc load) {
	if (!GLAD_GL_OES_texture_border_clamp) return;
	glad_glTexParameterIivOES = (PFNGLTEXPARAMETERIIVOESPROC)load("glTexParameterIivOES");
	glad_glTexParameterIuivOES = (PFNGLTEXPARAMETERIUIVOESPROC)load("glTexParameterIuivOES");
	glad_glGetTexParameterIivOES = (PFNGLGETTEXPARAMETERIIVOESPROC)load("glGetTexParameterIivOES");
	glad_glGetTexParameterIuivOES = (PFNGLGETTEXPARAMETERIUIVOESPROC)load("glGetTexParameterIuivOES");
	glad_glSamplerParameterIivOES = (PFNGLSAMPLERPARAMETERIIVOESPROC)load("glSamplerParameterIivOES");
	glad_glSamplerParameterIuivOES = (PFNGLSAMPLERPARAMETERIUIVOESPROC)load("glSamplerParameterIuivOES");
	glad_glGetSamplerParameterIivOES = (PFNGLGETSAMPLERPARAMETERIIVOESPROC)load("glGetSamplerParameterIivOES");
	glad_glGetSamplerParameterIuivOES = (PFNGLGETSAMPLERPARAMETERIUIVOESPROC)load("glGetSamplerParameterIuivOES");
}
static void load_GL_EXT_occlusion_query_boolean(GLADloadproc load) {
	if (!GLAD_GL_EXT_occlusion_query_boolean) return;
	glad_glGenQueriesEXT = (PFNGLGENQUERIESEXTPROC)load("glGenQueriesEXT");
	glad_glDeleteQueriesEXT = (PFNGLDELETEQUERIESEXTPROC)load("glDeleteQueriesEXT");
	glad_glIsQueryEXT = (PFNGLISQUERYEXTPROC)load("glIsQueryEXT");
	glad_glBeginQueryEXT = (PFNGLBEGINQUERYEXTPROC)load("glBeginQueryEXT");
	glad_glEndQueryEXT = (PFNGLENDQUERYEXTPROC)load("glEndQueryEXT");
	glad_glGetQueryivEXT = (PFNGLGETQUERYIVEXTPROC)load("glGetQueryivEXT");
	glad_glGetQueryObjectuivEXT = (PFNGLGETQUERYOBJECTUIVEXTPROC)load("glGetQueryObjectuivEXT");
}
static void load_GL_EXT_multi_draw_indirect(GLADloadproc load) {
	if (!GLAD_GL_EXT_multi_draw_indirect) return;
	glad_glMultiDrawArraysIndirectEXT = (PFNGLMULTIDRAWARRAYSINDIRECTEXTPROC)load("glMultiDrawArraysIndirectEXT");
	glad_glMultiDrawElementsIndirectEXT = (PFNGLMULTIDRAWELEMENTSINDIRECTEXTPROC)load("glMultiDrawElementsIndirectEXT");
}
static void load_GL_APPLE_sync(GLADloadproc load) {
	if (!GLAD_GL_APPLE_sync) return;
	glad_glFenceSyncAPPLE = (PFNGLFENCESYNCAPPLEPROC)load("glFenceSyncAPPLE");
	glad_glIsSyncAPPLE = (PFNGLISSYNCAPPLEPROC)load("glIsSyncAPPLE");
	glad_glDeleteSyncAPPLE = (PFNGLDELETESYNCAPPLEPROC)load("glDeleteSyncAPPLE");
	glad_glClientWaitSyncAPPLE = (PFNGLCLIENTWAITSYNCAPPLEPROC)load("glClientWaitSyncAPPLE");
	glad_glWaitSyncAPPLE = (PFNGLWAITSYNCAPPLEPROC)load("glWaitSyncAPPLE");
	glad_glGetInteger64vAPPLE = (PFNGLGETINTEGER64VAPPLEPROC)load("glGetInteger64vAPPLE");
	glad_glGetSyncivAPPLE = (PFNGLGETSYNCIVAPPLEPROC)load("glGetSyncivAPPLE");
}
static void load_GL_OES_copy_image(GLADloadproc load) {
	if (!GLAD_GL_OES_copy_image) return;
	glad_glCopyImageSubDataOES = (PFNGLCOPYIMAGESUBDATAOESPROC)load("glCopyImageSubDataOES");
}
static void load_GL_QCOM_extended_get2(GLADloadproc load) {
	if (!GLAD_GL_QCOM_extended_get2) return;
	glad_glExtGetShadersQCOM = (PFNGLEXTGETSHADERSQCOMPROC)load("glExtGetShadersQCOM");
	glad_glExtGetProgramsQCOM = (PFNGLEXTGETPROGRAMSQCOMPROC)load("glExtGetProgramsQCOM");
	glad_glExtIsProgramBinaryQCOM = (PFNGLEXTISPROGRAMBINARYQCOMPROC)load("glExtIsProgramBinaryQCOM");
	glad_glExtGetProgramBinarySourceQCOM = (PFNGLEXTGETPROGRAMBINARYSOURCEQCOMPROC)load("glExtGetProgramBinarySourceQCOM");
}
static void load_GL_EXT_draw_elements_base_vertex(GLADloadproc load) {
	if (!GLAD_GL_EXT_draw_elements_base_vertex) return;
	glad_glDrawElementsBaseVertexEXT = (PFNGLDRAWELEMENTSBASEVERTEXEXTPROC)load("glDrawElementsBaseVertexEXT");
	glad_glDrawRangeElementsBaseVertexEXT = (PFNGLDRAWRANGEELEMENTSBASEVERTEXEXTPROC)load("glDrawRangeElementsBaseVertexEXT");
	glad_glDrawElementsInstancedBaseVertexEXT = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXEXTPROC)load("glDrawElementsInstancedBaseVertexEXT");
	glad_glMultiDrawElementsBaseVertexEXT = (PFNGLMULTIDRAWELEMENTSBASEVERTEXEXTPROC)load("glMultiDrawElementsBaseVertexEXT");
}
static void load_GL_NV_framebuffer_multisample(GLADloadproc load) {
	if (!GLAD_GL_NV_framebuffer_multisample) return;
	glad_glRenderbufferStorageMultisampleNV = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLENVPROC)load("glRenderbufferStorageMultisampleNV");
}
static void load_GL_OES_texture_storage_multisample_2d_array(GLADloadproc load) {
	if (!GLAD_GL_OES_texture_storage_multisample_2d_array) return;
	glad_glTexStorage3DMultisampleOES = (PFNGLTEXSTORAGE3DMULTISAMPLEOESPROC)load("glTexStorage3DMultisampleOES");
}
static void load_GL_OES_draw_buffers_indexed(GLADloadproc load) {
	if (!GLAD_GL_OES_draw_buffers_indexed) return;
	glad_glEnableiOES = (PFNGLENABLEIOESPROC)load("glEnableiOES");
	glad_glDisableiOES = (PFNGLDISABLEIOESPROC)load("glDisableiOES");
	glad_glBlendEquationiOES = (PFNGLBLENDEQUATIONIOESPROC)load("glBlendEquationiOES");
	glad_glBlendEquationSeparateiOES = (PFNGLBLENDEQUATIONSEPARATEIOESPROC)load("glBlendEquationSeparateiOES");
	glad_glBlendFunciOES = (PFNGLBLENDFUNCIOESPROC)load("glBlendFunciOES");
	glad_glBlendFuncSeparateiOES = (PFNGLBLENDFUNCSEPARATEIOESPROC)load("glBlendFuncSeparateiOES");
	glad_glColorMaskiOES = (PFNGLCOLORMASKIOESPROC)load("glColorMaskiOES");
	glad_glIsEnablediOES = (PFNGLISENABLEDIOESPROC)load("glIsEnablediOES");
}
static void load_GL_OES_EGL_image(GLADloadproc load) {
	if (!GLAD_GL_OES_EGL_image) return;
	glad_glEGLImageTargetTexture2DOES = (PFNGLEGLIMAGETARGETTEXTURE2DOESPROC)load("glEGLImageTargetTexture2DOES");
	glad_glEGLImageTargetRenderbufferStorageOES = (PFNGLEGLIMAGETARGETRENDERBUFFERSTORAGEOESPROC)load("glEGLImageTargetRenderbufferStorageOES");
}
static void load_GL_NV_draw_buffers(GLADloadproc load) {
	if (!GLAD_GL_NV_draw_buffers) return;
	glad_glDrawBuffersNV = (PFNGLDRAWBUFFERSNVPROC)load("glDrawBuffersNV");
}
static void load_GL_EXT_draw_buffers(GLADloadproc load) {
	if (!GLAD_GL_EXT_draw_buffers) return;
	glad_glDrawBuffersEXT = (PFNGLDRAWBUFFERSEXTPROC)load("glDrawBuffersEXT");
}
static void load_GL_NV_instanced_arrays(GLADloadproc load) {
	if (!GLAD_GL_NV_instanced_arrays) return;
	glad_glVertexAttribDivisorNV = (PFNGLVERTEXATTRIBDIVISORNVPROC)load("glVertexAttribDivisorNV");
}
static void load_GL_EXT_texture_storage(GLADloadproc load) {
	if (!GLAD_GL_EXT_texture_storage) return;
	glad_glTexStorage1DEXT = (PFNGLTEXSTORAGE1DEXTPROC)load("glTexStorage1DEXT");
	glad_glTexStorage2DEXT = (PFNGLTEXSTORAGE2DEXTPROC)load("glTexStorage2DEXT");
	glad_glTexStorage3DEXT = (PFNGLTEXSTORAGE3DEXTPROC)load("glTexStorage3DEXT");
	glad_glTextureStorage1DEXT = (PFNGLTEXTURESTORAGE1DEXTPROC)load("glTextureStorage1DEXT");
	glad_glTextureStorage2DEXT = (PFNGLTEXTURESTORAGE2DEXTPROC)load("glTextureStorage2DEXT");
	glad_glTextureStorage3DEXT = (PFNGLTEXTURESTORAGE3DEXTPROC)load("glTextureStorage3DEXT");
}
static void load_GL_EXT_copy_image(GLADloadproc load) {
	if (!GLAD_GL_EXT_copy_image) return;
	glad_glCopyImageSubDataEXT = (PFNGLCOPYIMAGESUBDATAEXTPROC)load("glCopyImageSubDataEXT");
}
static void load_GL_OES_sample_shading(GLADloadproc load) {
	if (!GLAD_GL_OES_sample_shading) return;
	glad_glMinSampleShadingOES = (PFNGLMINSAMPLESHADINGOESPROC)load("glMinSampleShadingOES");
}
static void load_GL_NV_viewport_array(GLADloadproc load) {
	if (!GLAD_GL_NV_viewport_array) return;
	glad_glViewportArrayvNV = (PFNGLVIEWPORTARRAYVNVPROC)load("glViewportArrayvNV");
	glad_glViewportIndexedfNV = (PFNGLVIEWPORTINDEXEDFNVPROC)load("glViewportIndexedfNV");
	glad_glViewportIndexedfvNV = (PFNGLVIEWPORTINDEXEDFVNVPROC)load("glViewportIndexedfvNV");
	glad_glScissorArrayvNV = (PFNGLSCISSORARRAYVNVPROC)load("glScissorArrayvNV");
	glad_glScissorIndexedNV = (PFNGLSCISSORINDEXEDNVPROC)load("glScissorIndexedNV");
	glad_glScissorIndexedvNV = (PFNGLSCISSORINDEXEDVNVPROC)load("glScissorIndexedvNV");
	glad_glDepthRangeArrayfvNV = (PFNGLDEPTHRANGEARRAYFVNVPROC)load("glDepthRangeArrayfvNV");
	glad_glDepthRangeIndexedfNV = (PFNGLDEPTHRANGEINDEXEDFNVPROC)load("glDepthRangeIndexedfNV");
	glad_glGetFloati_vNV = (PFNGLGETFLOATI_VNVPROC)load("glGetFloati_vNV");
	glad_glEnableiNV = (PFNGLENABLEINVPROC)load("glEnableiNV");
	glad_glDisableiNV = (PFNGLDISABLEINVPROC)load("glDisableiNV");
	glad_glIsEnablediNV = (PFNGLISENABLEDINVPROC)load("glIsEnablediNV");
}
static void load_GL_EXT_map_buffer_range(GLADloadproc load) {
	if (!GLAD_GL_EXT_map_buffer_range) return;
	glad_glMapBufferRangeEXT = (PFNGLMAPBUFFERRANGEEXTPROC)load("glMapBufferRangeEXT");
	glad_glFlushMappedBufferRangeEXT = (PFNGLFLUSHMAPPEDBUFFERRANGEEXTPROC)load("glFlushMappedBufferRangeEXT");
}
static void load_GL_OES_mapbuffer(GLADloadproc load) {
	if (!GLAD_GL_OES_mapbuffer) return;
	glad_glMapBufferOES = (PFNGLMAPBUFFEROESPROC)load("glMapBufferOES");
	glad_glUnmapBufferOES = (PFNGLUNMAPBUFFEROESPROC)load("glUnmapBufferOES");
	glad_glGetBufferPointervOES = (PFNGLGETBUFFERPOINTERVOESPROC)load("glGetBufferPointervOES");
}
static void load_GL_NV_polygon_mode(GLADloadproc load) {
	if (!GLAD_GL_NV_polygon_mode) return;
	glad_glPolygonModeNV = (PFNGLPOLYGONMODENVPROC)load("glPolygonModeNV");
}
static void load_GL_IMG_multisampled_render_to_texture(GLADloadproc load) {
	if (!GLAD_GL_IMG_multisampled_render_to_texture) return;
	glad_glRenderbufferStorageMultisampleIMG = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLEIMGPROC)load("glRenderbufferStorageMultisampleIMG");
	glad_glFramebufferTexture2DMultisampleIMG = (PFNGLFRAMEBUFFERTEXTURE2DMULTISAMPLEIMGPROC)load("glFramebufferTexture2DMultisampleIMG");
}
static void load_GL_OES_draw_elements_base_vertex(GLADloadproc load) {
	if (!GLAD_GL_OES_draw_elements_base_vertex) return;
	glad_glDrawElementsBaseVertexOES = (PFNGLDRAWELEMENTSBASEVERTEXOESPROC)load("glDrawElementsBaseVertexOES");
	glad_glDrawRangeElementsBaseVertexOES = (PFNGLDRAWRANGEELEMENTSBASEVERTEXOESPROC)load("glDrawRangeElementsBaseVertexOES");
	glad_glDrawElementsInstancedBaseVertexOES = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXOESPROC)load("glDrawElementsInstancedBaseVertexOES");
	glad_glMultiDrawElementsBaseVertexOES = (PFNGLMULTIDRAWELEMENTSBASEVERTEXOESPROC)load("glMultiDrawElementsBaseVertexOES");
}
static void load_GL_APPLE_copy_texture_levels(GLADloadproc load) {
	if (!GLAD_GL_APPLE_copy_texture_levels) return;
	glad_glCopyTextureLevelsAPPLE = (PFNGLCOPYTEXTURELEVELSAPPLEPROC)load("glCopyTextureLevelsAPPLE");
}
static void load_GL_EXT_multiview_draw_buffers(GLADloadproc load) {
	if (!GLAD_GL_EXT_multiview_draw_buffers) return;
	glad_glReadBufferIndexedEXT = (PFNGLREADBUFFERINDEXEDEXTPROC)load("glReadBufferIndexedEXT");
	glad_glDrawBuffersIndexedEXT = (PFNGLDRAWBUFFERSINDEXEDEXTPROC)load("glDrawBuffersIndexedEXT");
	glad_glGetIntegeri_vEXT = (PFNGLGETINTEGERI_VEXTPROC)load("glGetIntegeri_vEXT");
}
static void load_GL_QCOM_extended_get(GLADloadproc load) {
	if (!GLAD_GL_QCOM_extended_get) return;
	glad_glExtGetTexturesQCOM = (PFNGLEXTGETTEXTURESQCOMPROC)load("glExtGetTexturesQCOM");
	glad_glExtGetBuffersQCOM = (PFNGLEXTGETBUFFERSQCOMPROC)load("glExtGetBuffersQCOM");
	glad_glExtGetRenderbuffersQCOM = (PFNGLEXTGETRENDERBUFFERSQCOMPROC)load("glExtGetRenderbuffersQCOM");
	glad_glExtGetFramebuffersQCOM = (PFNGLEXTGETFRAMEBUFFERSQCOMPROC)load("glExtGetFramebuffersQCOM");
	glad_glExtGetTexLevelParameterivQCOM = (PFNGLEXTGETTEXLEVELPARAMETERIVQCOMPROC)load("glExtGetTexLevelParameterivQCOM");
	glad_glExtTexObjectStateOverrideiQCOM = (PFNGLEXTTEXOBJECTSTATEOVERRIDEIQCOMPROC)load("glExtTexObjectStateOverrideiQCOM");
	glad_glExtGetTexSubImageQCOM = (PFNGLEXTGETTEXSUBIMAGEQCOMPROC)load("glExtGetTexSubImageQCOM");
	glad_glExtGetBufferPointervQCOM = (PFNGLEXTGETBUFFERPOINTERVQCOMPROC)load("glExtGetBufferPointervQCOM");
}
static void load_GL_EXT_geometry_shader(GLADloadproc load) {
	if (!GLAD_GL_EXT_geometry_shader) return;
	glad_glFramebufferTextureEXT = (PFNGLFRAMEBUFFERTEXTUREEXTPROC)load("glFramebufferTextureEXT");
}
static void load_GL_EXT_texture_border_clamp(GLADloadproc load) {
	if (!GLAD_GL_EXT_texture_border_clamp) return;
	glad_glTexParameterIivEXT = (PFNGLTEXPARAMETERIIVEXTPROC)load("glTexParameterIivEXT");
	glad_glTexParameterIuivEXT = (PFNGLTEXPARAMETERIUIVEXTPROC)load("glTexParameterIuivEXT");
	glad_glGetTexParameterIivEXT = (PFNGLGETTEXPARAMETERIIVEXTPROC)load("glGetTexParameterIivEXT");
	glad_glGetTexParameterIuivEXT = (PFNGLGETTEXPARAMETERIUIVEXTPROC)load("glGetTexParameterIuivEXT");
	glad_glSamplerParameterIivEXT = (PFNGLSAMPLERPARAMETERIIVEXTPROC)load("glSamplerParameterIivEXT");
	glad_glSamplerParameterIuivEXT = (PFNGLSAMPLERPARAMETERIUIVEXTPROC)load("glSamplerParameterIuivEXT");
	glad_glGetSamplerParameterIivEXT = (PFNGLGETSAMPLERPARAMETERIIVEXTPROC)load("glGetSamplerParameterIivEXT");
	glad_glGetSamplerParameterIuivEXT = (PFNGLGETSAMPLERPARAMETERIUIVEXTPROC)load("glGetSamplerParameterIuivEXT");
}
static void load_GL_ANGLE_framebuffer_blit(GLADloadproc load) {
	if (!GLAD_GL_ANGLE_framebuffer_blit) return;
	glad_glBlitFramebufferANGLE = (PFNGLBLITFRAMEBUFFERANGLEPROC)load("glBlitFramebufferANGLE");
}
static void load_GL_OES_texture_3D(GLADloadproc load) {
	if (!GLAD_GL_OES_texture_3D) return;
	glad_glTexImage3DOES = (PFNGLTEXIMAGE3DOESPROC)load("glTexImage3DOES");
	glad_glTexSubImage3DOES = (PFNGLTEXSUBIMAGE3DOESPROC)load("glTexSubImage3DOES");
	glad_glCopyTexSubImage3DOES = (PFNGLCOPYTEXSUBIMAGE3DOESPROC)load("glCopyTexSubImage3DOES");
	glad_glCompressedTexImage3DOES = (PFNGLCOMPRESSEDTEXIMAGE3DOESPROC)load("glCompressedTexImage3DOES");
	glad_glCompressedTexSubImage3DOES = (PFNGLCOMPRESSEDTEXSUBIMAGE3DOESPROC)load("glCompressedTexSubImage3DOES");
	glad_glFramebufferTexture3DOES = (PFNGLFRAMEBUFFERTEXTURE3DOESPROC)load("glFramebufferTexture3DOES");
}
static void load_GL_EXT_tessellation_shader(GLADloadproc load) {
	if (!GLAD_GL_EXT_tessellation_shader) return;
	glad_glPatchParameteriEXT = (PFNGLPATCHPARAMETERIEXTPROC)load("glPatchParameteriEXT");
}
static void load_GL_OES_primitive_bounding_box(GLADloadproc load) {
	if (!GLAD_GL_OES_primitive_bounding_box) return;
	glad_glPrimitiveBoundingBoxOES = (PFNGLPRIMITIVEBOUNDINGBOXOESPROC)load("glPrimitiveBoundingBoxOES");
}
static void load_GL_NV_read_buffer(GLADloadproc load) {
	if (!GLAD_GL_NV_read_buffer) return;
	glad_glReadBufferNV = (PFNGLREADBUFFERNVPROC)load("glReadBufferNV");
}
static void load_GL_ANGLE_instanced_arrays(GLADloadproc load) {
	if (!GLAD_GL_ANGLE_instanced_arrays) return;
	glad_glDrawArraysInstancedANGLE = (PFNGLDRAWARRAYSINSTANCEDANGLEPROC)load("glDrawArraysInstancedANGLE");
	glad_glDrawElementsInstancedANGLE = (PFNGLDRAWELEMENTSINSTANCEDANGLEPROC)load("glDrawElementsInstancedANGLE");
	glad_glVertexAttribDivisorANGLE = (PFNGLVERTEXATTRIBDIVISORANGLEPROC)load("glVertexAttribDivisorANGLE");
}
static void load_GL_EXT_discard_framebuffer(GLADloadproc load) {
	if (!GLAD_GL_EXT_discard_framebuffer) return;
	glad_glDiscardFramebufferEXT = (PFNGLDISCARDFRAMEBUFFEREXTPROC)load("glDiscardFramebufferEXT");
}
static void load_GL_EXT_texture_buffer(GLADloadproc load) {
	if (!GLAD_GL_EXT_texture_buffer) return;
	glad_glTexBufferEXT = (PFNGLTEXBUFFEREXTPROC)load("glTexBufferEXT");
	glad_glTexBufferRangeEXT = (PFNGLTEXBUFFERRANGEEXTPROC)load("glTexBufferRangeEXT");
}