#include <glib_pch.hpp>
#include "core/glib_context.h"

#if (defined GLIB_GAPI)
#include <glib_framebuf.h>
#include <glib_tools.h>
#endif	// GLIB_WINDOW
#if (GLIB_GAPI & GLIB_GAPI_OGL)
#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace GLIB
{
	static bool s_GLinit = false;

	GContextOgl::GContextOgl(GLFWwindow* pNativeWindow) :
		m_pNativeWindow(pNativeWindow)
	{
	}
	GContextOgl::~GContextOgl() = default;

	// --==<core_methods>==--
	bool GContextOgl::OnInit()
	{
		glfwMakeContextCurrent(m_pNativeWindow);
		if (!s_GLinit) { s_GLinit = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress); }
		m_GContextInfo = GContextInfo(glGetString(GL_RENDERER), glGetString(GL_VERSION),
			glGetString(GL_VENDOR), glGetString(GL_SHADING_LANGUAGE_VERSION));
		glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &m_GContextInfo.nMaxTextures);
		glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &m_GContextInfo.nMaxVertexAttribs);
		std::cout << std::endl << "Graphics Context: GLFW_" << glfwGetVersionString() << std::endl <<
			"OpenGL Renderer: " << m_GContextInfo.strRenderer << std::endl <<
			"OpenGL Version: " << m_GContextInfo.strVersion << std::endl <<
			"OpenGL Vendor: " << m_GContextInfo.strVendor << std::endl <<
			"OpenGL Shading Language: " << m_GContextInfo.strShadingLanguage << "\n\n";
		
		return true;
	}
	void GContextOgl::OnQuit()
	{
		glfwTerminate();
	}

	void GContextOgl::SwapBuffers()
	{
		glfwSwapBuffers(m_pNativeWindow);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	}
	// --==</core_methods>==--
}
#endif	// GLIB_GAPI