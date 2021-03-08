#include <nwg_pch.hpp>
#include "imgui_core.hpp"

// dear imgui, v1.79 WIP
// (demo code)

// Message to the person tempted to delete this file when integrating Dear ImGui into their code base:
// Do NOT remove this file from your project! Think again! It is the most useful reference code that you and other
// coders will want to refer to and call. Have the GUI::ShowDemoWindow() function wired in an always-available
// debug menu of your game/app! Removing this file from your project is hindering access to documentation for everyone
// in your team, likely leading you to poorer usage of the library.
// Everything in this file will be stripped out by the linker if you don't call GUI::ShowDemoWindow().
// If you want to link core Dear ImGui in your shipped builds but want a thorough guarantee that the demo will not be
// linked, you can setup your imconfig.h with #define IMGUI_DISABLE_DEMO_WINDOWS and those functions will be empty.
// In other situation, whenever you have Dear ImGui available you probably want this to be available for reference.
// Thank you,
// -Your beloved friend, imgui_demo.cpp (which you won't delete)

// Message to beginner C/C++ programmers about the meaning of the 'static' keyword:
// In this demo code, we frequently we use 'static' variables inside functions. A static variable persist across calls,
// so it is essentially like a global variable but declared inside the scope of the function. We do this as a way to
// gather code and data in the same place, to make the demo source code faster to read, faster to write, and smaller
// in size. It also happens to be a convenient way of storing simple UI related information as long as your function
// doesn't need to be reentrant or used in multiple threads. This might be a pattern you will want to use in your code,
// but most of the real data you would be editing is likely going to be stored outside your functions.

// The Demo code in this file is designed to be easy to copy-and-paste in into your application!
// Because of this:
// - We never omit the GUI:: prefix when calling functions, even though most code here is in the same namespace.
// - We try to declare static variables in the local scope, as close as possible to the code using them.
// - We never use any of the helpers/facilities used internally by Dear ImGui, unless available in the public API.
// - We never use maths operators on ImVec2/ImVec4. For our other sources files we use them, and they are provided
//   by imgui_internal.h using the IMGUI_DEFINE_MATH_OPERATORS define. For your own sources file they are optional
//   and require you either enable those, either provide your own via IM_VEC2_CLASS_EXTRA in imconfig.h.
//   Because we can't assume anything about your support of maths operators, we cannot use them in imgui_demo.cpp.

// Clang/GCC warnings with -Weverything
#if defined(__clang__)
#if __has_warning("-Wunknown-warning-option")
#pragma clang diagnostic ignored "-Wunknown-warning-option"         // warning: unknown warning group 'xxx'                     // not all warnings are known by all Clang versions and they tend to be rename-happy.. so ignoring warnings triggers new warnings on some configuration. Great!
#endif
#pragma clang diagnostic ignored "-Wunknown-pragmas"                // warning: unknown warning group 'xxx'
#pragma clang diagnostic ignored "-Wold-style-cast"                 // warning: use of old-style cast                           // yes, they are more terse.
#pragma clang diagnostic ignored "-Wdeprecated-declarations"        // warning: 'xx' is deprecated: The POSIX name for this..   // for strdup used in demo code (so user can copy & paste the code)
#pragma clang diagnostic ignored "-Wint-to-void-pointer-cast"       // warning: cast to 'void *' from smaller integer type
#pragma clang diagnostic ignored "-Wformat-security"                // warning: format string is not a string literal
#pragma clang diagnostic ignored "-Wexit-time-destructors"          // warning: declaration requires an exit-time destructor    // exit-time destruction order is undefined. if MemFree() leads to users code that has been disabled before exit it might cause problems. ImGui coding style welcomes static/globals.
#pragma clang diagnostic ignored "-Wunused-macros"                  // warning: macro is not used                               // we define snprintf/vsnprintf on Windows so they are available, but not always used.
#pragma clang diagnostic ignored "-Wzero-as-null-pointer-constant"  // warning: zero as null pointer constant                   // some standard header variations use #define NULL 0
#pragma clang diagnostic ignored "-Wdouble-promotion"               // warning: implicit conversion from 'float' to 'double' when passing argument to function  // using printf() is a misery with this as C++ va_arg ellipsis changes float to double.
#pragma clang diagnostic ignored "-Wreserved-id-macro"              // warning: macro name is a reserved identifier
#pragma clang diagnostic ignored "-Wimplicit-int-float-conversion"  // warning: implicit conversion from 'xxx' to 'float' may lose precision
#elif defined(__GNUC__)
#pragma GCC diagnostic ignored "-Wpragmas"                  // warning: unknown option after '#pragma GCC diagnostic' kind
#pragma GCC diagnostic ignored "-Wint-to-pointer-cast"      // warning: cast to pointer from integer of different size
#pragma GCC diagnostic ignored "-Wformat-security"          // warning: format string is not a string literal (potentially insecure)
#pragma GCC diagnostic ignored "-Wdouble-promotion"         // warning: implicit conversion from 'float' to 'double' when passing argument to function
#pragma GCC diagnostic ignored "-Wconversion"               // warning: conversion to 'xxxx' from 'xxxx' may alter its value
#pragma GCC diagnostic ignored "-Wmisleading-indentation"   // [__GNUC__ >= 6] warning: this 'if' clause does not guard this statement      // GCC 6.0+ only. See #883 on GitHub.
#endif

// Play it nice with Windows users (Update: May 2018, Notepad now supports Unix-style carriage returns!)
#ifdef _WIN32
#define IM_NEWLINE  "\r\n"
#else
#define IM_NEWLINE  "\n"
#endif

// Helpers
#if defined(_MSC_VER) && !defined(snprintf)
#define snprintf    _snprintf
#endif
#if defined(_MSC_VER) && !defined(vsnprintf)
#define vsnprintf   _vsnprintf
#endif

// Helpers macros
// We normally try to not use many helpers in imgui_demo.cpp in order to make code easier to copy and paste,
// but making an exception here as those are largely simplifying code...
// In other imgui sources we can use nicer internal functions from imgui_internal.h (ImMin/ImMax) but not in the demo.
#define IM_MIN(A, B)            (((A) < (B)) ? (A) : (B))
#define IM_MAX(A, B)            (((A) >= (B)) ? (A) : (B))
#define IM_CLAMP(V, MN, MX)     ((V) < (MN) ? (MN) : (V) > (MX) ? (MX) : (V))

//-----------------------------------------------------------------------------
// [SECTION] Forward Declarations, Helpers
//-----------------------------------------------------------------------------

#if !defined(IMGUI_DISABLE_DEMO_WINDOWS)

// Forward Declarations
static void ShowExampleAppDockSpace(bool* p_open);
static void ShowExampleAppDocuments(bool* p_open);
static void ShowExampleAppMainMenuBar();
static void ShowExampleAppConsole(bool* p_open);
static void ShowExampleAppLog(bool* p_open);
static void ShowExampleAppLayout(bool* p_open);
static void ShowExampleAppPropertyEditor(bool* p_open);
static void ShowExampleAppLongText(bool* p_open);
static void ShowExampleAppAutoResize(bool* p_open);
static void ShowExampleAppConstrainedResize(bool* p_open);
static void ShowExampleAppSimpleOverlay(bool* p_open);
static void ShowExampleCoreWindowTitles(bool* p_open);
static void ShowExampleAppCustomRendering(bool* p_open);
static void ShowExampleMenuFile();

// Helper to display a little (?) mark which shows a tooltip when hovered.
// In your own code you may want to display an actual icon if you are using a merged icon fonts (see docs/FONTS.md)
static void HelpMarker(const char* desc)
{
    GUI::TextDisabled("(?)");
    if (GUI::IsItemHovered())
    {
        GUI::BeginTooltip();
        GUI::PushTextWrapPos(GUI::GetFontSize() * 35.0f);
        GUI::TextUnformatted(desc);
        GUI::PopTextWrapPos();
        GUI::EndTooltip();
    }
}

static void ShowDockingDisabledMessage()
{
    imgui_io& io = GUI::GetIO();
    GUI::Text("ERROR: Docking is not enabled! See Demo > Configuration.");
    GUI::Text("Set io.ConfigFlags |= ImGuiConfigFlags_DockingEnable in your code, or ");
    GUI::SameLine(0.0f, 0.0f);
    if (GUI::SmallButton("click here"))
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
}

// Helper to display basic user controls.
void GUI::ShowUserGuide()
{
    imgui_io& io = GUI::GetIO();
    GUI::BulletText("Double-click on title bar to collapse window.");
    GUI::BulletText(
        "Click and drag on lower corner to resize window\n"
        "(double-click to auto fit window to its contents).");
    GUI::BulletText("CTRL+Click on a slider or drag box to input value as text.");
    GUI::BulletText("TAB/SHIFT+TAB to cycle through keyboard editable fields.");
    if (io.FontAllowUserScaling)
        GUI::BulletText("CTRL+Mouse Wheel to zoom window contents.");
    GUI::BulletText("While inputing text:\n");
    GUI::Indent();
    GUI::BulletText("CTRL+Left/Right to word jump.");
    GUI::BulletText("CTRL+A or double-click to select all.");
    GUI::BulletText("CTRL+X/C/V to use clipboard cut/copy/paste.");
    GUI::BulletText("CTRL+Z,CTRL+Y to undo/redo.");
    GUI::BulletText("ESCAPE to revert.");
    GUI::BulletText("You can apply arithmetic operators +,*,/ on numerical values.\nUse +- to subtract.");
    GUI::Unindent();
    GUI::BulletText("With keyboard navigation enabled:");
    GUI::Indent();
    GUI::BulletText("Arrow keys to navigate.");
    GUI::BulletText("Space to activate a widget.");
    GUI::BulletText("Return to input text into a widget.");
    GUI::BulletText("Escape to deactivate a widget, close popup, exit child window.");
    GUI::BulletText("Alt to jump to the menu layer of a window.");
    GUI::BulletText("CTRL+Tab to select a window.");
    GUI::Unindent();
}

//-----------------------------------------------------------------------------
// [SECTION] Demo Window / ShowDemoWindow()
//-----------------------------------------------------------------------------
// - ShowDemoWindowWidgets()
// - ShowDemoWindowLayout()
// - ShowDemoWindowPopups()
// - ShowDemoWindowColumns()
// - ShowDemoWindowMisc()
//-----------------------------------------------------------------------------

// We split the contents of the big ShowDemoWindow() function into smaller functions
// (because the link time of very large functions grow non-linearly)
static void ShowDemoWindowWidgets();
static void ShowDemoWindowLayout();
static void ShowDemoWindowPopups();
static void ShowDemoWindowColumns();
static void ShowDemoWindowMisc();

// Demonstrate most Dear ImGui features (this is big function!)
// You may execute this function to experiment with the UI and understand what it does.
// You may then search for keywords in the code when you are interested by a specific feature.
void GUI::ShowDemoWindow(bool* p_open)
{
    // exceptionally add an extra assert here for people confused about initial Dear ImGui setup
    // most ImGui functions would normally just crash if the context is missing.
    IM_ASSERT(GUI::GetCurrentContext() != NULL && "Missing dear imgui context. Refer to examples app!");

    // Examples Apps (accessible from the "Examples" menu)
    static bool show_app_main_menu_bar = false;
    static bool show_app_dockspace = false;
    static bool show_app_documents = false;

    static bool show_app_console = false;
    static bool show_app_log = false;
    static bool show_app_layout = false;
    static bool show_app_property_editor = false;
    static bool show_app_long_text = false;
    static bool show_app_auto_resize = false;
    static bool show_app_constrained_resize = false;
    static bool show_app_simple_overlay = false;
    static bool show_app_window_titles = false;
    static bool show_app_custom_rendering = false;

    if (show_app_main_menu_bar)       ShowExampleAppMainMenuBar();
    if (show_app_dockspace)           ShowExampleAppDockSpace(&show_app_dockspace);     // Process the Docking app first, as explicit DockSpace() nodes needs to be submitted early (read comments near the DockSpace function)
    if (show_app_documents)           ShowExampleAppDocuments(&show_app_documents);     // Process the Document app next, as it may also use a DockSpace()

    if (show_app_console)             ShowExampleAppConsole(&show_app_console);
    if (show_app_log)                 ShowExampleAppLog(&show_app_log);
    if (show_app_layout)              ShowExampleAppLayout(&show_app_layout);
    if (show_app_property_editor)     ShowExampleAppPropertyEditor(&show_app_property_editor);
    if (show_app_long_text)           ShowExampleAppLongText(&show_app_long_text);
    if (show_app_auto_resize)         ShowExampleAppAutoResize(&show_app_auto_resize);
    if (show_app_constrained_resize)  ShowExampleAppConstrainedResize(&show_app_constrained_resize);
    if (show_app_simple_overlay)      ShowExampleAppSimpleOverlay(&show_app_simple_overlay);
    if (show_app_window_titles)       ShowExampleCoreWindowTitles(&show_app_window_titles);
    if (show_app_custom_rendering)    ShowExampleAppCustomRendering(&show_app_custom_rendering);

    // Dear ImGui Apps (accessible from the "Tools" menu)
    static bool show_app_metrics = false;
    static bool show_app_style_editor = false;
    static bool show_app_about = false;

    if (show_app_metrics)       { GUI::ShowMetricsWindow(&show_app_metrics); }
    if (show_app_about)         { GUI::ShowAboutWindow(&show_app_about); }
    if (show_app_style_editor)
    {
        GUI::Begin("Dear ImGui Style Editor", &show_app_style_editor);
        GUI::ShowStyleEditor();
        GUI::End();
    }

    // Demonstrate the various window flags. Typically you would just use the default!
    static bool no_titlebar = false;
    static bool no_scrollbar = false;
    static bool no_menu = false;
    static bool no_move = false;
    static bool no_resize = false;
    static bool no_collapse = false;
    static bool no_close = false;
    static bool no_nav = false;
    static bool no_background = false;
    static bool no_bring_to_front = false;
    static bool no_docking = false;

    ImGuiWindowFlags window_flags = 0;
    if (no_titlebar)        window_flags |= ImGuiWindowFlags_NoTitleBar;
    if (no_scrollbar)       window_flags |= ImGuiWindowFlags_NoScrollbar;
    if (!no_menu)           window_flags |= ImGuiWindowFlags_MenuBar;
    if (no_move)            window_flags |= ImGuiWindowFlags_NoMove;
    if (no_resize)          window_flags |= ImGuiWindowFlags_NoResize;
    if (no_collapse)        window_flags |= ImGuiWindowFlags_NoCollapse;
    if (no_nav)             window_flags |= ImGuiWindowFlags_NoNav;
    if (no_background)      window_flags |= ImGuiWindowFlags_NoBackground;
    if (no_bring_to_front)  window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus;
    if (no_docking)         window_flags |= ImGuiWindowFlags_NoDocking;
    if (no_close)           p_open = NULL; // Don't pass our bool* to Begin

    // We specify a default position/size in case there's no data in the .ini file.
    // We only do it to make the demo applications a little more welcoming, but typically this isn't required.
    imgui_viewport* main_viewport = GUI::GetMainViewport();
    GUI::SetNextWindowPos(ImVec2(main_viewport->GetWorkPos().x + 650, main_viewport->GetWorkPos().y + 20), ImGuiCond_FirstUseEver);
    GUI::SetNextWindowSize(ImVec2(550, 680), ImGuiCond_FirstUseEver);

    // Main body of the Demo window starts here.
    if (!GUI::Begin("Dear ImGui Demo", p_open, window_flags))
    {
        // Early out if the window is collapsed, as an optimization.
        GUI::End();
        return;
    }

    // Most "big" widgets share a common width settings by default. See 'Demo->Layout->Widgets Width' for details.

    // e.g. Use 2/3 of the space for widgets and 1/3 for labels (default)
    //GUI::PushItemWidth(GUI::GetWindowWidth() * 0.65f);

    // e.g. Leave a fixed amount of width for labels (by passing a negative value), the rest goes to widgets.
    GUI::PushItemWidth(GUI::GetFontSize() * -12);

    // Menu Bar
    if (GUI::BeginMenuBar())
    {
        if (GUI::BeginMenu("Menu"))
        {
            ShowExampleMenuFile();
            GUI::EndMenu();
        }
        if (GUI::BeginMenu("Examples"))
        {
            GUI::MenuItem("Main menu bar", NULL, &show_app_main_menu_bar);
            GUI::MenuItem("Console", NULL, &show_app_console);
            GUI::MenuItem("Log", NULL, &show_app_log);
            GUI::MenuItem("Simple layout", NULL, &show_app_layout);
            GUI::MenuItem("Property editor", NULL, &show_app_property_editor);
            GUI::MenuItem("Long text display", NULL, &show_app_long_text);
            GUI::MenuItem("Auto-resizing window", NULL, &show_app_auto_resize);
            GUI::MenuItem("Constrained-resizing window", NULL, &show_app_constrained_resize);
            GUI::MenuItem("Simple overlay", NULL, &show_app_simple_overlay);
            GUI::MenuItem("Manipulating window titles", NULL, &show_app_window_titles);
            GUI::MenuItem("Custom rendering", NULL, &show_app_custom_rendering);
            GUI::MenuItem("Dockspace", NULL, &show_app_dockspace);
            GUI::MenuItem("Documents", NULL, &show_app_documents);
            GUI::EndMenu();
        }
        if (GUI::BeginMenu("Tools"))
        {
            GUI::MenuItem("Metrics", NULL, &show_app_metrics);
            GUI::MenuItem("Style Editor", NULL, &show_app_style_editor);
            GUI::MenuItem("About Dear ImGui", NULL, &show_app_about);
            GUI::EndMenu();
        }
        GUI::EndMenuBar();
    }

    GUI::Text("dear imgui says hello. (%s)", IMGUI_VERSION);
    GUI::Spacing();

    if (GUI::CollapsingHeader("Help"))
    {
        GUI::Text("ABOUT THIS DEMO:");
        GUI::BulletText("Sections below are demonstrating many aspects of the library.");
        GUI::BulletText("The \"Examples\" menu above leads to more demo contents.");
        GUI::BulletText("The \"Tools\" menu above gives access to: About Box, Style Editor,\n"
                          "and Metrics (general purpose Dear ImGui debugging tool).");
        GUI::Separator();

        GUI::Text("PROGRAMMER GUIDE:");
        GUI::BulletText("See the ShowDemoWindow() code in imgui_demo.cpp. <- you are here!");
        GUI::BulletText("See comments in imgui.cpp.");
        GUI::BulletText("See example applications in the examples/ folder.");
        GUI::BulletText("Read the FAQ at http://www.dearimgui.org/faq/");
        GUI::BulletText("Set 'io.ConfigFlags |= NavEnableKeyboard' for keyboard controls.");
        GUI::BulletText("Set 'io.ConfigFlags |= NavEnableGamepad' for gamepad controls.");
        GUI::Separator();

        GUI::Text("USER GUIDE:");
        GUI::ShowUserGuide();
    }

    if (GUI::CollapsingHeader("Configuration"))
    {
        imgui_io& io = GUI::GetIO();

        if (GUI::TreeNode("Configuration##2"))
        {
            GUI::CheckboxFlags("io.ConfigFlags: NavEnableKeyboard",    (unsigned int*)&io.ConfigFlags, ImGuiConfigFlags_NavEnableKeyboard);
            GUI::CheckboxFlags("io.ConfigFlags: NavEnableGamepad",     (unsigned int*)&io.ConfigFlags, ImGuiConfigFlags_NavEnableGamepad);
            GUI::SameLine(); HelpMarker("Required back-end to feed in gamepad inputs in io.NavInputs[] and set io.BackendFlags |= ImGuiBackendFlags_HasGamepad.\n\nRead instructions in imgui.cpp for details.");
            GUI::CheckboxFlags("io.ConfigFlags: NavEnableSetMousePos", (unsigned int*)&io.ConfigFlags, ImGuiConfigFlags_NavEnableSetMousePos);
            GUI::SameLine(); HelpMarker("Instruct navigation to move the mouse cursor. See comment for ImGuiConfigFlags_NavEnableSetMousePos.");
            GUI::CheckboxFlags("io.ConfigFlags: NoMouse",              (unsigned int*)&io.ConfigFlags, ImGuiConfigFlags_NoMouse);

            // The "NoMouse" option above can get us stuck with a disable mouse! Provide an alternative way to fix it:
            if (io.ConfigFlags & ImGuiConfigFlags_NoMouse)
            {
                if (fmodf((float)GUI::GetTime(), 0.40f) < 0.20f)
                {
                    GUI::SameLine();
                    GUI::Text("<<PRESS SPACE TO DISABLE>>");
                }
                if (GUI::IsKeyPressed(GUI::GetKeyIndex(ImGuiKey_Space)))
                    io.ConfigFlags &= ~ImGuiConfigFlags_NoMouse;
            }
            GUI::CheckboxFlags("io.ConfigFlags: NoMouseCursorChange", (unsigned int*)&io.ConfigFlags, ImGuiConfigFlags_NoMouseCursorChange);
            GUI::SameLine(); HelpMarker("Instruct back-end to not alter mouse cursor shape and visibility.");

            GUI::CheckboxFlags("io.ConfigFlags: DockingEnable", (unsigned int *)&io.ConfigFlags, ImGuiConfigFlags_DockingEnable);
            GUI::SameLine(); HelpMarker(io.ConfigDockingWithShift ? "[beta] Use SHIFT to dock window into each others." : "[beta] Drag from title bar to dock windows into each others.");
            if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
            {
                GUI::Indent();
                GUI::Checkbox("io.ConfigDockingNoSplit", &io.ConfigDockingNoSplit);
                GUI::SameLine(); HelpMarker("Simplified docking mode: disable window splitting, so docking is limited to merging multiple windows together into tab-bars.");
                GUI::Checkbox("io.ConfigDockingWithShift", &io.ConfigDockingWithShift);
                GUI::SameLine(); HelpMarker("Enable docking when holding Shift only (allows to drop in wider space, reduce visual noise)");
                GUI::Checkbox("io.ConfigDockingAlwaysTabBar", &io.ConfigDockingAlwaysTabBar);
                GUI::SameLine(); HelpMarker("Create a docking node and tab-bar on single floating windows.");
                GUI::Checkbox("io.ConfigDockingTransparentPayload", &io.ConfigDockingTransparentPayload);
                GUI::SameLine(); HelpMarker("Make window or viewport transparent when docking and only display docking boxes on the target viewport. Useful if rendering of multiple viewport cannot be synced. Best used with ConfigViewportsNoAutoMerge.");
                GUI::Unindent();
            }

            GUI::CheckboxFlags("io.ConfigFlags: ViewportsEnable", (unsigned int *)&io.ConfigFlags, ImGuiConfigFlags_ViewportsEnable);
            GUI::SameLine(); HelpMarker("[beta] Enable beta multi-viewports support. See imgui_platform_io for details.");
            if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
            {
                GUI::Indent();
                GUI::Checkbox("io.ConfigViewportsNoAutoMerge", &io.ConfigViewportsNoAutoMerge);
                GUI::SameLine(); HelpMarker("Set to make all floating imgui windows always create their own viewport. Otherwise, they are merged into the main host viewports when overlapping it.");
                GUI::Checkbox("io.ConfigViewportsNoTaskBarIcon", &io.ConfigViewportsNoTaskBarIcon);
                GUI::SameLine(); HelpMarker("Toggling this at runtime is normally unsupported (most platform back-ends won't refresh the task bar icon state right away).");
                GUI::Checkbox("io.ConfigViewportsNoDecoration", &io.ConfigViewportsNoDecoration);
                GUI::SameLine(); HelpMarker("Toggling this at runtime is normally unsupported (most platform back-ends won't refresh the decoration right away).");
                GUI::Checkbox("io.ConfigViewportsNoDefaultParent", &io.ConfigViewportsNoDefaultParent);
                GUI::SameLine(); HelpMarker("Toggling this at runtime is normally unsupported (most platform back-ends won't refresh the parenting right away).");
                GUI::Unindent();
            }

            GUI::Checkbox("io.ConfigInputTextCursorBlink", &io.ConfigInputTextCursorBlink);
            GUI::SameLine(); HelpMarker("Set to false to disable blinking cursor, for users who consider it distracting");
            GUI::Checkbox("io.ConfigWindowsResizeFromEdges", &io.ConfigWindowsResizeFromEdges);
            GUI::SameLine(); HelpMarker("Enable resizing of windows from their edges and from the lower-left corner.\nThis requires (io.BackendFlags & ImGuiBackendFlags_HasMouseCursors) because it needs mouse cursor feedback.");
            GUI::Checkbox("io.ConfigWindowsMoveFromTitleBarOnly", &io.ConfigWindowsMoveFromTitleBarOnly);
            GUI::Checkbox("io.MouseDrawCursor", &io.MouseDrawCursor);
            GUI::SameLine(); HelpMarker("Instruct Dear ImGui to render a mouse cursor itself. Note that a mouse cursor rendered via your application GPU rendering path will feel more laggy than hardware cursor, but will be more in sync with your other visuals.\n\nSome desktop applications may use both kinds of cursors (e.g. enable software cursor only when resizing/dragging something).");
            GUI::Text("Also see Style->Rendering for rendering options.");
            GUI::TreePop();
            GUI::Separator();
        }

        if (GUI::TreeNode("Backend Flags"))
        {
            HelpMarker(
                "Those flags are set by the back-ends (imgui_impl_xxx files) to specify their capabilities.\n"
                "Here we expose then as read-only fields to avoid breaking interactions with your back-end.");
            // Make a local copy to avoid modifying actual back-end flags.
            ImGuiBackendFlags backend_flags = io.BackendFlags;
            GUI::CheckboxFlags("io.BackendFlags: HasGamepad",             (unsigned int*)&backend_flags, ImGuiBackendFlags_HasGamepad);
            GUI::CheckboxFlags("io.BackendFlags: HasMouseCursors",        (unsigned int*)&backend_flags, ImGuiBackendFlags_HasMouseCursors);
            GUI::CheckboxFlags("io.BackendFlags: HasSetMousePos",         (unsigned int*)&backend_flags, ImGuiBackendFlags_HasSetMousePos);
            GUI::CheckboxFlags("io.BackendFlags: PlatformHasViewports",   (unsigned int*)&backend_flags, ImGuiBackendFlags_PlatformHasViewports);
            GUI::CheckboxFlags("io.BackendFlags: HasMouseHoveredViewport",(unsigned int*)&backend_flags, ImGuiBackendFlags_HasMouseHoveredViewport);
            GUI::CheckboxFlags("io.BackendFlags: RendererHasVtxOffset",   (unsigned int*)&backend_flags, ImGuiBackendFlags_RendererHasVtxOffset);
            GUI::CheckboxFlags("io.BackendFlags: RendererHasViewports",   (unsigned int*)&backend_flags, ImGuiBackendFlags_RendererHasViewports);
            GUI::TreePop();
            GUI::Separator();
        }

        if (GUI::TreeNode("Style"))
        {
            HelpMarker("The same contents can be accessed in 'Tools->Style Editor' or by calling the ShowStyleEditor() function.");
            GUI::ShowStyleEditor();
            GUI::TreePop();
            GUI::Separator();
        }

        if (GUI::TreeNode("Capture/Logging"))
        {
            HelpMarker(
                "The logging API redirects all text output so you can easily capture the content of "
                "a window or a block. Tree nodes can be automatically expanded.\n"
                "Try opening any of the contents below in this window and then click one of the \"Log To\" button.");
            GUI::LogButtons();

            HelpMarker("You can also call GUI::LogText() to output directly to the log without a visual output.");
            if (GUI::Button("Copy \"Hello, world!\" to clipboard"))
            {
                GUI::LogToClipboard();
                GUI::LogText("Hello, world!");
                GUI::LogFinish();
            }
            GUI::TreePop();
        }
    }

    if (GUI::CollapsingHeader("Window options"))
    {
        GUI::Checkbox("No titlebar", &no_titlebar); GUI::SameLine(150);
        GUI::Checkbox("No scrollbar", &no_scrollbar); GUI::SameLine(300);
        GUI::Checkbox("No menu", &no_menu);
        GUI::Checkbox("No move", &no_move); GUI::SameLine(150);
        GUI::Checkbox("No resize", &no_resize); GUI::SameLine(300);
        GUI::Checkbox("No collapse", &no_collapse);
        GUI::Checkbox("No close", &no_close); GUI::SameLine(150);
        GUI::Checkbox("No nav", &no_nav); GUI::SameLine(300);
        GUI::Checkbox("No background", &no_background);
        GUI::Checkbox("No bring to front", &no_bring_to_front);
        GUI::Checkbox("No docking", &no_docking);
    }

    // All demo contents
    ShowDemoWindowWidgets();
    ShowDemoWindowLayout();
    ShowDemoWindowPopups();
    ShowDemoWindowColumns();
    ShowDemoWindowMisc();

    // End of ShowDemoWindow()
    GUI::End();
}

static void ShowDemoWindowWidgets()
{
    if (!GUI::CollapsingHeader("Widgets"))
        return;

    if (GUI::TreeNode("Basic"))
    {
        static int clicked = 0;
        if (GUI::Button("Button"))
            clicked++;
        if (clicked & 1)
        {
            GUI::SameLine();
            GUI::Text("Thanks for clicking me!");
        }

        static bool check = true;
        GUI::Checkbox("checkbox", &check);

        static int e = 0;
        GUI::RadioButton("radio a", &e, 0); GUI::SameLine();
        GUI::RadioButton("radio b", &e, 1); GUI::SameLine();
        GUI::RadioButton("radio c", &e, 2);

        // Color buttons, demonstrate using PushID() to add unique identifier in the ID stack, and changing style.
        for (int i = 0; i < 7; i++)
        {
            if (i > 0)
                GUI::SameLine();
            GUI::PushID(i);
            GUI::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(i / 7.0f, 0.6f, 0.6f));
            GUI::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(i / 7.0f, 0.7f, 0.7f));
            GUI::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(i / 7.0f, 0.8f, 0.8f));
            GUI::Button("Click");
            GUI::PopStyleColor(3);
            GUI::PopID();
        }

        // Use AlignTextToFramePadding() to align text baseline to the baseline of framed widgets elements
        // (otherwise a Text+SameLine+Button sequence will have the text a little too high by default!)
        // See 'Demo->Layout->Text Baseline Alignment' for details.
        GUI::AlignTextToFramePadding();
        GUI::Text("Hold to repeat:");
        GUI::SameLine();

        // Arrow buttons with Repeater
        static int counter = 0;
        float spacing = GUI::GetStyle().ItemInnerSpacing.x;
        GUI::PushButtonRepeat(true);
        if (GUI::ArrowButton("##left", ImGuiDir_Left)) { counter--; }
        GUI::SameLine(0.0f, spacing);
        if (GUI::ArrowButton("##right", ImGuiDir_Right)) { counter++; }
        GUI::PopButtonRepeat();
        GUI::SameLine();
        GUI::Text("%d", counter);

        GUI::Text("Hover over me");
        if (GUI::IsItemHovered())
            GUI::SetTooltip("I am a tooltip");

        GUI::SameLine();
        GUI::Text("- or me");
        if (GUI::IsItemHovered())
        {
            GUI::BeginTooltip();
            GUI::Text("I am a fancy tooltip");
            static float arr[] = { 0.6f, 0.1f, 1.0f, 0.5f, 0.92f, 0.1f, 0.2f };
            GUI::PlotLines("Curve", arr, IM_ARRAYSIZE(arr));
            GUI::EndTooltip();
        }

        GUI::Separator();

        GUI::LabelText("label", "Value");

        {
            // Using the _simplified_ one-liner Combo() api here
            // See "Combo" section for examples of how to use the more complete BeginCombo()/EndCombo() api.
            const char* items[] = { "AAAA", "BBBB", "CCCC", "DDDD", "EEEE", "FFFF", "GGGG", "HHHH", "IIIIIII", "JJJJ", "KKKKKKK" };
            static int item_current = 0;
            GUI::Combo("combo", &item_current, items, IM_ARRAYSIZE(items));
            GUI::SameLine(); HelpMarker("Refer to the \"Combo\" section below for an explanation of the full BeginCombo/EndCombo API, and demonstration of various flags.\n");
        }

        {
            // To wire InputText() with std::string or any other custom string type,
            // see the "Text Input > Resize Callback" section of this demo, and the misc/cpp/imgui_stdlib.h file.
            static char str0[128] = "Hello, world!";
            GUI::InputText("input text", str0, IM_ARRAYSIZE(str0));
            GUI::SameLine(); HelpMarker(
                "USER:\n"
                "Hold SHIFT or use mouse to select text.\n"
                "CTRL+Left/Right to word jump.\n"
                "CTRL+A or double-click to select all.\n"
                "CTRL+X,CTRL+C,CTRL+V clipboard.\n"
                "CTRL+Z,CTRL+Y undo/redo.\n"
                "ESCAPE to revert.\n\n"
                "PROGRAMMER:\n"
                "You can use the ImGuiInputTextFlags_CallbackResize facility if you need to wire InputText() "
                "to a dynamic string type. See misc/cpp/imgui_stdlib.h for an example (this is not demonstrated "
                "in imgui_demo.cpp).");

            static char str1[128] = "";
            GUI::InputTextWithHint("input text (w/ hint)", "enter text here", str1, IM_ARRAYSIZE(str1));

            static int i0 = 123;
            GUI::InputInt("input int", &i0);
            GUI::SameLine(); HelpMarker(
                "You can apply arithmetic operators +,*,/ on numerical values.\n"
                "  e.g. [ 100 ], input \'*2\', result becomes [ 200 ]\n"
                "Use +- to subtract.");

            static float f0 = 0.001f;
            GUI::InputFloat("input float", &f0, 0.01f, 1.0f, "%.3f");

            static double d0 = 999999.00000001;
            GUI::InputDouble("input double", &d0, 0.01f, 1.0f, "%.8f");

            static float f1 = 1.e10f;
            GUI::InputFloat("input scientific", &f1, 0.0f, 0.0f, "%e");
            GUI::SameLine(); HelpMarker(
                "You can input value using the scientific notation,\n"
                "  e.g. \"1e+8\" becomes \"100000000\".");

            static float vec4a[4] = { 0.10f, 0.20f, 0.30f, 0.44f };
            GUI::InputFloat3("input float3", vec4a);
        }

        {
            static int i1 = 50, i2 = 42;
            GUI::DragInt("drag int", &i1, 1);
            GUI::SameLine(); HelpMarker(
                "Click and drag to edit value.\n"
                "Hold SHIFT/ALT for faster/slower edit.\n"
                "Double-click or CTRL+click to input value.");

            GUI::DragInt("drag int 0..100", &i2, 1, 0, 100, "%d%%");

            static float f1 = 1.00f, f2 = 0.0067f;
            GUI::DragFloat("drag float", &f1, 0.005f);
            GUI::DragFloat("drag small float", &f2, 0.0001f, 0.0f, 0.0f, "%.06f ns");
        }

        {
            static int i1 = 0;
            GUI::SliderInt("slider int", &i1, -1, 3);
            GUI::SameLine(); HelpMarker("CTRL+click to input value.");

            static float f1 = 0.123f, f2 = 0.0f;
            GUI::SliderFloat("slider float", &f1, 0.0f, 1.0f, "ratio = %.3f");
            GUI::SliderFloat("slider float (log)", &f2, -10.0f, 10.0f, "%.4f", ImGuiSliderFlags_Logarithmic);

            static float angle = 0.0f;
            GUI::SliderAngle("slider angle", &angle);

            // Using the format string to display a name instead of an integer.
            // Here we completely omit '%d' from the format string, so it'll only display a name.
            // This technique can also be used with DragInt().
            enum Element { Element_Fire, Element_Earth, Element_Air, Element_Water, Element_COUNT };
            static int elem = Element_Fire;
            const char* elems_names[Element_COUNT] = { "Fire", "Earth", "Air", "Water" };
            const char* elem_name = (elem >= 0 && elem < Element_COUNT) ? elems_names[elem] : "Unknown";
            GUI::SliderInt("slider enum", &elem, 0, Element_COUNT - 1, elem_name);
            GUI::SameLine(); HelpMarker("Using the format string parameter to display a name instead of the underlying integer.");
        }

        {
            static float col1[3] = { 1.0f, 0.0f, 0.2f };
            static float col2[4] = { 0.4f, 0.7f, 0.0f, 0.5f };
            GUI::ColorEdit3("color 1", col1);
            GUI::SameLine(); HelpMarker(
                "Click on the colored square to open a color picker.\n"
                "Click and hold to use drag and drop.\n"
                "Right-click on the colored square to show options.\n"
                "CTRL+click on individual component to input value.\n");

            GUI::ColorEdit4("color 2", col2);
        }

        {
            // List box
            const char* items[] = { "Apple", "Banana", "Cherry", "Kiwi", "Mango", "Orange", "Pineapple", "Strawberry", "Watermelon" };
            static int item_current = 1;
            GUI::ListBox("listbox\n(single select)", &item_current, items, IM_ARRAYSIZE(items), 4);

            //static int listbox_item_current2 = 2;
            //GUI::SetNextItemWidth(-1);
            //GUI::ListBox("##listbox2", &listbox_item_current2, listbox_items, IM_ARRAYSIZE(listbox_items), 4);
        }

        GUI::TreePop();
    }

    // Testing ImGuiOnceUponAFrame helper.
    //static ImGuiOnceUponAFrame once;
    //for (int i = 0; i < 5; i++)
    //    if (once)
    //        GUI::Text("This will be displayed only once.");

    if (GUI::TreeNode("Trees"))
    {
        if (GUI::TreeNode("Basic trees"))
        {
            for (int i = 0; i < 5; i++)
            {
                // Use SetNextItemOpen() so set the default state of a node to be open. We could
                // also use TreeNodeEx() with the ImGuiTreeNodeFlags_DefaultOpen flag to achieve the same thing!
                if (i == 0)
                    GUI::SetNextItemOpen(true, ImGuiCond_Once);

                if (GUI::TreeNode((void*)(intptr_t)i, "Child %d", i))
                {
                    GUI::Text("blah blah");
                    GUI::SameLine();
                    if (GUI::SmallButton("button")) {}
                    GUI::TreePop();
                }
            }
            GUI::TreePop();
        }

        if (GUI::TreeNode("Advanced, with Selectable nodes"))
        {
            HelpMarker(
                "This is a more typical looking tree with selectable nodes.\n"
                "Click to select, CTRL+Click to toggle, click on arrows or double-click to open.");
            static ImGuiTreeNodeFlags base_flags = ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_OpenOnDoubleClick | ImGuiTreeNodeFlags_SpanAvailWidth;
            static bool align_label_with_current_x_position = false;
            static bool test_drag_and_drop = false;
            GUI::CheckboxFlags("ImGuiTreeNodeFlags_OpenOnArrow",       (unsigned int*)&base_flags, ImGuiTreeNodeFlags_OpenOnArrow);
            GUI::CheckboxFlags("ImGuiTreeNodeFlags_OpenOnDoubleClick", (unsigned int*)&base_flags, ImGuiTreeNodeFlags_OpenOnDoubleClick);
            GUI::CheckboxFlags("ImGuiTreeNodeFlags_SpanAvailWidth",    (unsigned int*)&base_flags, ImGuiTreeNodeFlags_SpanAvailWidth); GUI::SameLine(); HelpMarker("Extend hit area to all available width instead of allowing more items to be laid out after the node.");
            GUI::CheckboxFlags("ImGuiTreeNodeFlags_SpanFullWidth",     (unsigned int*)&base_flags, ImGuiTreeNodeFlags_SpanFullWidth);
            GUI::Checkbox("Align label with current X position", &align_label_with_current_x_position);
            GUI::Checkbox("Test tree node as drag source", &test_drag_and_drop);
            GUI::Text("Hello!");
            if (align_label_with_current_x_position)
                GUI::Unindent(GUI::GetTreeNodeToLabelSpacing());

            // 'selection_mask' is dumb representation of what may be user-side selection state.
            //  You may retain selection state inside or outside your objects in whatever format you see fit.
            // 'node_clicked' is temporary storage of what node we have clicked to process selection at the end
            /// of the loop. May be a pointer to your own node type, etc.
            static int selection_mask = (1 << 2);
            int node_clicked = -1;
            for (int i = 0; i < 6; i++)
            {
                // Disable the default "open on single-click behavior" + set Selected flag according to our selection.
                ImGuiTreeNodeFlags node_flags = base_flags;
                const bool is_selected = (selection_mask & (1 << i)) != 0;
                if (is_selected)
                    node_flags |= ImGuiTreeNodeFlags_Selected;
                if (i < 3)
                {
                    // Items 0..2 are Tree Node
                    bool node_open = GUI::TreeNodeEx((void*)(intptr_t)i, node_flags, "Selectable Node %d", i);
                    if (GUI::IsItemClicked())
                        node_clicked = i;
                    if (test_drag_and_drop && GUI::BeginDragDropSource())
                    {
                        GUI::SetDragDropPayload("_TREENODE", NULL, 0);
                        GUI::Text("This is a drag and drop source");
                        GUI::EndDragDropSource();
                    }
                    if (node_open)
                    {
                        GUI::BulletText("Blah blah\nBlah Blah");
                        GUI::TreePop();
                    }
                }
                else
                {
                    // Items 3..5 are Tree Leaves
                    // The only reason we use TreeNode at all is to allow selection of the leaf. Otherwise we can
                    // use BulletText() or advance the cursor by GetTreeNodeToLabelSpacing() and call Text().
                    node_flags |= ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_NoTreePushOnOpen; // ImGuiTreeNodeFlags_Bullet
                    GUI::TreeNodeEx((void*)(intptr_t)i, node_flags, "Selectable Leaf %d", i);
                    if (GUI::IsItemClicked())
                        node_clicked = i;
                    if (test_drag_and_drop && GUI::BeginDragDropSource())
                    {
                        GUI::SetDragDropPayload("_TREENODE", NULL, 0);
                        GUI::Text("This is a drag and drop source");
                        GUI::EndDragDropSource();
                    }
                }
            }
            if (node_clicked != -1)
            {
                // Update selection state
                // (process outside of tree loop to avoid visual inconsistencies during the clicking frame)
                if (GUI::GetIO().KeyCtrl)
                    selection_mask ^= (1 << node_clicked);          // CTRL+click to toggle
                else //if (!(selection_mask & (1 << node_clicked))) // Depending on selection behavior you want, may want to preserve selection when clicking on item that is part of the selection
                    selection_mask = (1 << node_clicked);           // Click to single-select
            }
            if (align_label_with_current_x_position)
                GUI::Indent(GUI::GetTreeNodeToLabelSpacing());
            GUI::TreePop();
        }
        GUI::TreePop();
    }

    if (GUI::TreeNode("Collapsing Headers"))
    {
        static bool closable_group = true;
        GUI::Checkbox("Show 2nd header", &closable_group);
        if (GUI::CollapsingHeader("Header", ImGuiTreeNodeFlags_None))
        {
            GUI::Text("IsItemHovered: %d", GUI::IsItemHovered());
            for (int i = 0; i < 5; i++)
                GUI::Text("Some content %d", i);
        }
        if (GUI::CollapsingHeader("Header with a close button", &closable_group))
        {
            GUI::Text("IsItemHovered: %d", GUI::IsItemHovered());
            for (int i = 0; i < 5; i++)
                GUI::Text("More content %d", i);
        }
        /*
        if (GUI::CollapsingHeader("Header with a bullet", ImGuiTreeNodeFlags_Bullet))
            GUI::Text("IsItemHovered: %d", GUI::IsItemHovered());
        */
        GUI::TreePop();
    }

    if (GUI::TreeNode("Bullets"))
    {
        GUI::BulletText("Bullet point 1");
        GUI::BulletText("Bullet point 2\nOn multiple lines");
        if (GUI::TreeNode("Tree node"))
        {
            GUI::BulletText("Another bullet point");
            GUI::TreePop();
        }
        GUI::Bullet(); GUI::Text("Bullet point 3 (two calls)");
        GUI::Bullet(); GUI::SmallButton("Button");
        GUI::TreePop();
    }

    if (GUI::TreeNode("Text"))
    {
        if (GUI::TreeNode("Colored Text"))
        {
            // Using shortcut. You can use PushStyleColor()/PopStyleColor() for more flexibility.
            GUI::TextColored(ImVec4(1.0f, 0.0f, 1.0f, 1.0f), "Pink");
            GUI::TextColored(ImVec4(1.0f, 1.0f, 0.0f, 1.0f), "Yellow");
            GUI::TextDisabled("Disabled");
            GUI::SameLine(); HelpMarker("The TextDisabled color is stored in imgui_style.");
            GUI::TreePop();
        }

        if (GUI::TreeNode("Word Wrapping"))
        {
            // Using shortcut. You can use PushTextWrapPos()/PopTextWrapPos() for more flexibility.
            GUI::TextWrapped("This text should automatically wrap on the edge of the window. The current implementation for text wrapping follows simple rules suitable for English and possibly other languages.");
            GUI::Spacing();

            static float wrap_width = 200.0f;
            GUI::SliderFloat("Wrap width", &wrap_width, -20, 600, "%.0f");

            imgui_draw_list* draw_list = GUI::GetWindowDrawList();
            for (int n = 0; n < 2; n++)
            {
                GUI::Text("Test paragraph %d:", n);
                ImVec2 pos = GUI::GetCursorScreenPos();
                ImVec2 marker_min = ImVec2(pos.x + wrap_width, pos.y);
                ImVec2 marker_max = ImVec2(pos.x + wrap_width + 10, pos.y + GUI::GetTextLineHeight());
                GUI::PushTextWrapPos(GUI::GetCursorPos().x + wrap_width);
                if (n == 0)
                    GUI::Text("The lazy dog is a good dog. This paragraph should fit within %.0f pixels. Testing a 1 character word. The quick brown fox jumps over the lazy dog.", wrap_width);
                if (n == 1)
                    GUI::Text("aaaaaaaa bbbbbbbb, c cccccccc,dddddddd. d eeeeeeee   ffffffff. gggggggg!hhhhhhhh");

                // Draw actual text bounding box, following by marker of our expected limit (should not overlap!)
                draw_list->AddRect(GUI::GetItemRectMin(), GUI::GetItemRectMax(), IM_COL32(255, 255, 0, 255));
                draw_list->AddRectFilled(marker_min, marker_max, IM_COL32(255, 0, 255, 255));
                GUI::PopTextWrapPos();
            }

            GUI::TreePop();
        }

        if (GUI::TreeNode("UTF-8 Text"))
        {
            // UTF-8 test with Japanese characters
            // (Needs a suitable font? Try "Google Noto" or "Arial Unicode". See docs/FONTS.md for details.)
            // - From C++11 you can use the u8"my text" syntax to encode literal strings as UTF-8
            // - For earlier compiler, you may be able to encode your sources as UTF-8 (e.g. in Visual Studio, you
            //   can save your source files as 'UTF-8 without signature').
            // - FOR THIS DEMO FILE ONLY, BECAUSE WE WANT TO SUPPORT OLD COMPILERS, WE ARE *NOT* INCLUDING RAW UTF-8
            //   CHARACTERS IN THIS SOURCE FILE. Instead we are encoding a few strings with hexadecimal constants.
            //   Don't do this in your application! Please use u8"text in any language" in your application!
            // Note that characters values are preserved even by InputText() if the font cannot be displayed,
            // so you can safely copy & paste garbled characters into another application.
            GUI::TextWrapped(
                "CJK text will only appears if the font was loaded with the appropriate CJK character ranges. "
                "Call io.Font->AddFontFromFileTTF() manually to load extra character ranges. "
                "Read docs/FONTS.md for details.");
            GUI::Text("Hiragana: \xe3\x81\x8b\xe3\x81\x8d\xe3\x81\x8f\xe3\x81\x91\xe3\x81\x93 (kakikukeko)"); // Normally we would use u8"blah blah" with the proper characters directly in the string.
            GUI::Text("Kanjis: \xe6\x97\xa5\xe6\x9c\xac\xe8\xaa\x9e (nihongo)");
            static char buf[32] = "\xe6\x97\xa5\xe6\x9c\xac\xe8\xaa\x9e";
            //static char buf[32] = u8"NIHONGO"; // <- this is how you would write it with C++11, using real kanjis
            GUI::InputText("UTF-8 input", buf, IM_ARRAYSIZE(buf));
            GUI::TreePop();
        }
        GUI::TreePop();
    }

    if (GUI::TreeNode("Images"))
    {
        imgui_io& io = GUI::GetIO();
        GUI::TextWrapped("Below we are displaying the font texture (which is the only texture we have access to in this demo). Use the 'imgui_texture_id' type as storage to pass pointers or identifier to your own texture data. Hover the texture for a zoomed view!");

        // Below we are displaying the font texture because it is the only texture we have access to inside the demo!
        // Remember that imgui_texture_id is just storage for whatever you want it to be. It is essentially a value that
        // will be passed to the rendering back-end via the imgui_draw_cmd structure.
        // If you use one of the default imgui_impl_XXXX.cpp rendering back-end, they all have comments at the top
        // of their respective source file to specify what they expect to be stored in imgui_texture_id, for example:
        // - The imgui_impl_dx11.cpp renderer expect a 'ID3D11ShaderResourceView*' pointer
        // - The imgui_impl_opengl3.cpp renderer expect a GLuint OpenGL texture identifier, etc.
        // More:
        // - If you decided that imgui_texture_id = MyEngineTexture*, then you can pass your MyEngineTexture* pointers
        //   to GUI::Image(), and gather width/height through your own functions, etc.
        // - You can use ShowMetricsWindow() to inspect the draw data that are being passed to your renderer,
        //   it will help you debug issues if you are confused about it.
        // - Consider using the lower-level imgui_draw_list::AddImage() API, via GUI::GetWindowDrawList()->AddImage().
        // - Read https://github.com/ocornut/imgui/blob/master/docs/FAQ.md
        // - Read https://github.com/ocornut/imgui/wiki/Image-Loading-and-Displaying-Examples
        imgui_texture_id my_tex_id = io.Fonts->TexID;
        float my_tex_w = (float)io.Fonts->TexWidth;
        float my_tex_h = (float)io.Fonts->TexHeight;
        {
            GUI::Text("%.0fx%.0f", my_tex_w, my_tex_h);
            ImVec2 pos = GUI::GetCursorScreenPos();
            ImVec2 uv_min = ImVec2(0.0f, 0.0f);                 // Top-left
            ImVec2 uv_max = ImVec2(1.0f, 1.0f);                 // Lower-right
            ImVec4 tint_col = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);   // No tint
            ImVec4 border_col = ImVec4(1.0f, 1.0f, 1.0f, 0.5f); // 50% opaque white
            GUI::Image(my_tex_id, ImVec2(my_tex_w, my_tex_h), uv_min, uv_max, tint_col, border_col);
            if (GUI::IsItemHovered())
            {
                GUI::BeginTooltip();
                float region_sz = 32.0f;
                float region_x = io.MousePos.x - pos.x - region_sz * 0.5f;
                float region_y = io.MousePos.y - pos.y - region_sz * 0.5f;
                float zoom = 4.0f;
                if (region_x < 0.0f) { region_x = 0.0f; }
                else if (region_x > my_tex_w - region_sz) { region_x = my_tex_w - region_sz; }
                if (region_y < 0.0f) { region_y = 0.0f; }
                else if (region_y > my_tex_h - region_sz) { region_y = my_tex_h - region_sz; }
                GUI::Text("Min: (%.2f, %.2f)", region_x, region_y);
                GUI::Text("Max: (%.2f, %.2f)", region_x + region_sz, region_y + region_sz);
                ImVec2 uv0 = ImVec2((region_x) / my_tex_w, (region_y) / my_tex_h);
                ImVec2 uv1 = ImVec2((region_x + region_sz) / my_tex_w, (region_y + region_sz) / my_tex_h);
                GUI::Image(my_tex_id, ImVec2(region_sz * zoom, region_sz * zoom), uv0, uv1, tint_col, border_col);
                GUI::EndTooltip();
            }
        }
        GUI::TextWrapped("And now some textured buttons..");
        static int pressed_count = 0;
        for (int i = 0; i < 8; i++)
        {
            GUI::PushID(i);
            int frame_padding = -1 + i;                             // -1 == uses default padding (style.FramePadding)
            ImVec2 size = ImVec2(32.0f, 32.0f);                     // Size of the image we want to make visible
            ImVec2 uv0 = ImVec2(0.0f, 0.0f);                        // UV coordinates for lower-left
            ImVec2 uv1 = ImVec2(32.0f / my_tex_w, 32 / my_tex_h);   // UV coordinates for (32,32) in our texture
            ImVec4 bg_col = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);         // Black background
            ImVec4 tint_col = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);       // No tint
            if (GUI::ImageButton(my_tex_id, size, uv0, uv1, frame_padding, bg_col, tint_col))
                pressed_count += 1;
            GUI::PopID();
            GUI::SameLine();
        }
        GUI::NewLine();
        GUI::Text("Pressed %d times.", pressed_count);
        GUI::TreePop();
    }

    if (GUI::TreeNode("Combo"))
    {
        // Expose flags as checkbox for the demo
        static ImGuiComboFlags flags = 0;
        GUI::CheckboxFlags("ImGuiComboFlags_PopupAlignLeft", (unsigned int*)&flags, ImGuiComboFlags_PopupAlignLeft);
        GUI::SameLine(); HelpMarker("Only makes a difference if the popup is larger than the combo");
        if (GUI::CheckboxFlags("ImGuiComboFlags_NoArrowButton", (unsigned int*)&flags, ImGuiComboFlags_NoArrowButton))
            flags &= ~ImGuiComboFlags_NoPreview;     // Clear the other flag, as we cannot combine both
        if (GUI::CheckboxFlags("ImGuiComboFlags_NoPreview", (unsigned int*)&flags, ImGuiComboFlags_NoPreview))
            flags &= ~ImGuiComboFlags_NoArrowButton; // Clear the other flag, as we cannot combine both

        // Using the generic BeginCombo() API, you have full control over how to display the combo contents.
        // (your selection data could be an index, a pointer to the object, an id for the object, a flag intrusively
        // stored in the object itself, etc.)
        const char* items[] = { "AAAA", "BBBB", "CCCC", "DDDD", "EEEE", "FFFF", "GGGG", "HHHH", "IIII", "JJJJ", "KKKK", "LLLLLLL", "MMMM", "OOOOOOO" };
        static int item_current_idx = 0;                    // Here our selection data is an index.
        const char* combo_label = items[item_current_idx];  // Label to preview before opening the combo (technically could be anything)(
        if (GUI::BeginCombo("combo 1", combo_label, flags))
        {
            for (int n = 0; n < IM_ARRAYSIZE(items); n++)
            {
                const bool is_selected = (item_current_idx == n);
                if (GUI::Selectable(items[n], is_selected))
                    item_current_idx = n;

                // Set the initial focus when opening the combo (scrolling + keyboard navigation focus)
                if (is_selected)
                    GUI::SetItemDefaultFocus();
            }
            GUI::EndCombo();
        }

        // Simplified one-liner Combo() API, using values packed in a single constant string
        static int item_current_2 = 0;
        GUI::Combo("combo 2 (one-liner)", &item_current_2, "aaaa\0bbbb\0cccc\0dddd\0eeee\0\0");

        // Simplified one-liner Combo() using an array of const char*
        static int item_current_3 = -1; // If the selection isn't within 0..count, Combo won't display a preview
        GUI::Combo("combo 3 (array)", &item_current_3, items, IM_ARRAYSIZE(items));

        // Simplified one-liner Combo() using an accessor function
        struct FuncHolder { static bool ItemGetter(void* data, int idx, const char** out_str) { *out_str = ((const char**)data)[idx]; return true; } };
        static int item_current_4 = 0;
        GUI::Combo("combo 4 (function)", &item_current_4, &FuncHolder::ItemGetter, items, IM_ARRAYSIZE(items));

        GUI::TreePop();
    }

    if (GUI::TreeNode("Selectables"))
    {
        // Selectable() has 2 overloads:
        // - The one taking "bool selected" as a read-only selection information.
        //   When Selectable() has been clicked it returns true and you can alter selection state accordingly.
        // - The one taking "bool* p_selected" as a read-write selection information (convenient in some cases)
        // The earlier is more flexible, as in real application your selection may be stored in many different ways
        // and not necessarily inside a bool value (e.g. in flags within objects, as an external list, etc).
        if (GUI::TreeNode("Basic"))
        {
            static bool selection[5] = { false, true, false, false, false };
            GUI::Selectable("1. I am selectable", &selection[0]);
            GUI::Selectable("2. I am selectable", &selection[1]);
            GUI::Text("3. I am not selectable");
            GUI::Selectable("4. I am selectable", &selection[3]);
            if (GUI::Selectable("5. I am double clickable", selection[4], ImGuiSelectableFlags_AllowDoubleClick))
                if (GUI::IsMouseDoubleClicked(0))
                    selection[4] = !selection[4];
            GUI::TreePop();
        }
        if (GUI::TreeNode("Selection State: Single Selection"))
        {
            static int selected = -1;
            for (int n = 0; n < 5; n++)
            {
                char buf[32];
                sprintf(buf, "Object %d", n);
                if (GUI::Selectable(buf, selected == n))
                    selected = n;
            }
            GUI::TreePop();
        }
        if (GUI::TreeNode("Selection State: Multiple Selection"))
        {
            HelpMarker("Hold CTRL and click to select multiple items.");
            static bool selection[5] = { false, false, false, false, false };
            for (int n = 0; n < 5; n++)
            {
                char buf[32];
                sprintf(buf, "Object %d", n);
                if (GUI::Selectable(buf, selection[n]))
                {
                    if (!GUI::GetIO().KeyCtrl)    // Clear selection when CTRL is not held
                        memset(selection, 0, sizeof(selection));
                    selection[n] ^= 1;
                }
            }
            GUI::TreePop();
        }
        if (GUI::TreeNode("Rendering more text into the same line"))
        {
            // Using the Selectable() override that takes "bool* p_selected" parameter,
            // this function toggle your bool value automatically.
            static bool selected[3] = { false, false, false };
            GUI::Selectable("main.c",    &selected[0]); GUI::SameLine(300); GUI::Text(" 2,345 bytes");
            GUI::Selectable("Hello.cpp", &selected[1]); GUI::SameLine(300); GUI::Text("12,345 bytes");
            GUI::Selectable("Hello.h",   &selected[2]); GUI::SameLine(300); GUI::Text(" 2,345 bytes");
            GUI::TreePop();
        }
        if (GUI::TreeNode("In columns"))
        {
            GUI::Columns(3, NULL, false);
            static bool selected[16] = {};
            for (int i = 0; i < 16; i++)
            {
                char label[32]; sprintf(label, "Item %d", i);
                if (GUI::Selectable(label, &selected[i])) {}
                GUI::NextColumn();
            }
            GUI::Columns(1);
            GUI::TreePop();
        }
        if (GUI::TreeNode("Grid"))
        {
            static int selected[4 * 4] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 };
            for (int i = 0; i < 4 * 4; i++)
            {
                GUI::PushID(i);
                if (GUI::Selectable("Sailor", selected[i] != 0, 0, ImVec2(50, 50)))
                {
                    // Toggle
                    selected[i] = !selected[i];

                    // Note: We _unnecessarily_ test for both x/y and i here only to silence some static analyzer.
                    // The second part of each test is unnecessary.
                    int x = i % 4;
                    int y = i / 4;
                    if (x > 0)           { selected[i - 1] ^= 1; }
                    if (x < 3 && i < 15) { selected[i + 1] ^= 1; }
                    if (y > 0 && i > 3)  { selected[i - 4] ^= 1; }
                    if (y < 3 && i < 12) { selected[i + 4] ^= 1; }
                }
                if ((i % 4) < 3) GUI::SameLine();
                GUI::PopID();
            }
            GUI::TreePop();
        }
        if (GUI::TreeNode("Alignment"))
        {
            HelpMarker(
                "By default, Selectables uses style.SelectableTextAlign but it can be overridden on a per-item "
                "basis using PushStyleVar(). You'll probably want to always keep your default situation to "
                "left-align otherwise it becomes difficult to layout multiple items on a same line");
            static bool selected[3 * 3] = { true, false, true, false, true, false, true, false, true };
            for (int y = 0; y < 3; y++)
            {
                for (int x = 0; x < 3; x++)
                {
                    ImVec2 alignment = ImVec2((float)x / 2.0f, (float)y / 2.0f);
                    char name[32];
                    sprintf(name, "(%.1f,%.1f)", alignment.x, alignment.y);
                    if (x > 0) GUI::SameLine();
                    GUI::PushStyleVar(imgui_styleVar_SelectableTextAlign, alignment);
                    GUI::Selectable(name, &selected[3 * y + x], ImGuiSelectableFlags_None, ImVec2(80, 80));
                    GUI::PopStyleVar();
                }
            }
            GUI::TreePop();
        }
        GUI::TreePop();
    }

    // To wire InputText() with std::string or any other custom string type,
    // see the "Text Input > Resize Callback" section of this demo, and the misc/cpp/imgui_stdlib.h file.
    if (GUI::TreeNode("Text Input"))
    {
        if (GUI::TreeNode("Multi-line Text Input"))
        {
            // Note: we are using a fixed-sized buffer for simplicity here. See ImGuiInputTextFlags_CallbackResize
            // and the code in misc/cpp/imgui_stdlib.h for how to setup InputText() for dynamically resizing strings.
            static char text[1024 * 16] =
                "/*\n"
                " The Pentium F00F bug, shorthand for F0 0F C7 C8,\n"
                " the hexadecimal encoding of one offending instruction,\n"
                " more formally, the invalid operand with locked CMPXCHG8B\n"
                " instruction bug, is a design flaw in the majority of\n"
                " Intel Pentium, Pentium MMX, and Pentium OverDrive\n"
                " processors (all in the P5 microarchitecture).\n"
                "*/\n\n"
                "label:\n"
                "\tlock cmpxchg8b eax\n";

            static ImGuiInputTextFlags flags = ImGuiInputTextFlags_AllowTabInput;
            HelpMarker("You can use the ImGuiInputTextFlags_CallbackResize facility if you need to wire InputTextMultiline() to a dynamic string type. See misc/cpp/imgui_stdlib.h for an example. (This is not demonstrated in imgui_demo.cpp because we don't want to include <string> in here)");
            GUI::CheckboxFlags("ImGuiInputTextFlags_ReadOnly", (unsigned int*)&flags, ImGuiInputTextFlags_ReadOnly);
            GUI::CheckboxFlags("ImGuiInputTextFlags_AllowTabInput", (unsigned int*)&flags, ImGuiInputTextFlags_AllowTabInput);
            GUI::CheckboxFlags("ImGuiInputTextFlags_CtrlEnterForNewLine", (unsigned int*)&flags, ImGuiInputTextFlags_CtrlEnterForNewLine);
            GUI::InputTextMultiline("##source", text, IM_ARRAYSIZE(text), ImVec2(-FLT_MIN, GUI::GetTextLineHeight() * 16), flags);
            GUI::TreePop();
        }

        if (GUI::TreeNode("Filtered Text Input"))
        {
            struct TextFilters
            {
                // Return 0 (pass) if the character is 'i' or 'm' or 'g' or 'u' or 'i'
                static int FilterImGuiLetters(ImGuiInputTextCallbackData* data)
                {
                    if (data->EventChar < 256 && strchr("imgui", (char)data->EventChar))
                        return 0;
                    return 1;
                }
            };

            static char buf1[64] = ""; GUI::InputText("default",     buf1, 64);
            static char buf2[64] = ""; GUI::InputText("decimal",     buf2, 64, ImGuiInputTextFlags_CharsDecimal);
            static char buf3[64] = ""; GUI::InputText("hexadecimal", buf3, 64, ImGuiInputTextFlags_CharsHexadecimal | ImGuiInputTextFlags_CharsUppercase);
            static char buf4[64] = ""; GUI::InputText("uppercase",   buf4, 64, ImGuiInputTextFlags_CharsUppercase);
            static char buf5[64] = ""; GUI::InputText("no blank",    buf5, 64, ImGuiInputTextFlags_CharsNoBlank);
            static char buf6[64] = ""; GUI::InputText("\"imgui\" letters", buf6, 64, ImGuiInputTextFlags_CallbackCharFilter, TextFilters::FilterImGuiLetters);
            GUI::TreePop();
        }

        if (GUI::TreeNode("Password Input"))
        {
            static char password[64] = "password123";
            GUI::InputText("password", password, IM_ARRAYSIZE(password), ImGuiInputTextFlags_Password);
            GUI::SameLine(); HelpMarker("Display all characters as '*'.\nDisable clipboard cut and copy.\nDisable logging.\n");
            GUI::InputTextWithHint("password (w/ hint)", "<password>", password, IM_ARRAYSIZE(password), ImGuiInputTextFlags_Password);
            GUI::InputText("password (clear)", password, IM_ARRAYSIZE(password));
            GUI::TreePop();
        }

        if (GUI::TreeNode("Completion, History, Edit Callbacks"))
        {
            struct Funcs
            {
                static int MyCallback(ImGuiInputTextCallbackData* data)
                {
                    if (data->EventFlag == ImGuiInputTextFlags_CallbackCompletion)
                    {
                        data->InsertChars(data->CursorPos, "..");
                    }
                    else if (data->EventFlag == ImGuiInputTextFlags_CallbackHistory)
                    {
                        if (data->EventKey == ImGuiKey_UpArrow)
                        {
                            data->DeleteChars(0, data->BufTextLen);
                            data->InsertChars(0, "Pressed Up!");
                            data->SelectAll();
                        }
                        else if (data->EventKey == ImGuiKey_DownArrow)
                        {
                            data->DeleteChars(0, data->BufTextLen);
                            data->InsertChars(0, "Pressed Down!");
                            data->SelectAll();
                        }
                    }
                    else if (data->EventFlag == ImGuiInputTextFlags_CallbackEdit)
                    {
                        // Toggle casing of first character
                        char c = data->Buf[0];
                        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) data->Buf[0] ^= 32;
                        data->BufDirty = true;

                        // Increment a counter
                        int* p_int = (int*)data->UserData;
                        *p_int = *p_int + 1;
                    }
                    return 0;
                }
            };
            static char buf1[64];
            GUI::InputText("Completion", buf1, 64, ImGuiInputTextFlags_CallbackCompletion, Funcs::MyCallback);
            GUI::SameLine(); HelpMarker("Here we append \"..\" each time Tab is pressed. See 'Examples>Console' for a more meaningful demonstration of using this callback.");

            static char buf2[64];
            GUI::InputText("History", buf2, 64, ImGuiInputTextFlags_CallbackHistory, Funcs::MyCallback);
            GUI::SameLine(); HelpMarker("Here we replace and select text each time Up/Down are pressed. See 'Examples>Console' for a more meaningful demonstration of using this callback.");

            static char buf3[64];
            static int edit_count = 0;
            GUI::InputText("Edit", buf3, 64, ImGuiInputTextFlags_CallbackEdit, Funcs::MyCallback, (void*)&edit_count);
            GUI::SameLine(); HelpMarker("Here we toggle the casing of the first character on every edits + count edits.");
            GUI::SameLine(); GUI::Text("(%d)", edit_count);

            GUI::TreePop();
        }

        if (GUI::TreeNode("Resize Callback"))
        {
            // To wire InputText() with std::string or any other custom string type,
            // you can use the ImGuiInputTextFlags_CallbackResize flag + create a custom GUI::InputText() wrapper
            // using your preferred type. See misc/cpp/imgui_stdlib.h for an implementation of this using std::string.
            HelpMarker(
                "Using ImGuiInputTextFlags_CallbackResize to wire your custom string type to InputText().\n\n"
                "See misc/cpp/imgui_stdlib.h for an implementation of this for std::string.");
            struct Funcs
            {
                static int MyResizeCallback(ImGuiInputTextCallbackData* data)
                {
                    if (data->EventFlag == ImGuiInputTextFlags_CallbackResize)
                    {
                        ImVector<char>* my_str = (ImVector<char>*)data->UserData;
                        IM_ASSERT(my_str->begin() == data->Buf);
                        my_str->resize(data->BufSize); // NB: On resizing calls, generally data->BufSize == data->BufTextLen + 1
                        data->Buf = my_str->begin();
                    }
                    return 0;
                }

                // Note: Because GUI:: is a namespace you would typically add your own function into the namespace.
                // For example, you code may declare a function 'GUI::InputText(const char* label, MyString* my_str)'
                static bool MyInputTextMultiline(const char* label, ImVector<char>* my_str, const ImVec2& size = ImVec2(0, 0), ImGuiInputTextFlags flags = 0)
                {
                    IM_ASSERT((flags & ImGuiInputTextFlags_CallbackResize) == 0);
                    return GUI::InputTextMultiline(label, my_str->begin(), (size_t)my_str->size(), size, flags | ImGuiInputTextFlags_CallbackResize, Funcs::MyResizeCallback, (void*)my_str);
                }
            };

            // For this demo we are using ImVector as a string container.
            // Note that because we need to store a terminating zero character, our size/capacity are 1 more
            // than usually reported by a typical string class.
            static ImVector<char> my_str;
            if (my_str.empty())
                my_str.push_back(0);
            Funcs::MyInputTextMultiline("##MyStr", &my_str, ImVec2(-FLT_MIN, GUI::GetTextLineHeight() * 16));
            GUI::Text("Data: %p\nSize: %d\nCapacity: %d", (void*)my_str.begin(), my_str.size(), my_str.capacity());
            GUI::TreePop();
        }

        GUI::TreePop();
    }

    // Plot/Graph widgets are currently fairly limited.
    // Consider writing your own plotting widget, or using a third-party one
    // (for third-party Plot widgets, see 'Wiki->Useful Widgets' or https://github.com/ocornut/imgui/labels/plot%2Fgraph)
    if (GUI::TreeNode("Plots Widgets"))
    {
        static bool animate = true;
        GUI::Checkbox("Animate", &animate);

        static float arr[] = { 0.6f, 0.1f, 1.0f, 0.5f, 0.92f, 0.1f, 0.2f };
        GUI::PlotLines("Frame Times", arr, IM_ARRAYSIZE(arr));

        // Fill an array of contiguous float values to plot
        // Tip: If your float aren't contiguous but part of a structure, you can pass a pointer to your first float
        // and the sizeof() of your structure in the "stride" parameter.
        static float values[90] = {};
        static int values_offset = 0;
        static double refresh_time = 0.0;
        if (!animate || refresh_time == 0.0)
            refresh_time = GUI::GetTime();
        while (refresh_time < GUI::GetTime()) // Create data at fixed 60 Hz rate for the demo
        {
            static float phase = 0.0f;
            values[values_offset] = cosf(phase);
            values_offset = (values_offset + 1) % IM_ARRAYSIZE(values);
            phase += 0.10f * values_offset;
            refresh_time += 1.0f / 60.0f;
        }

        // Plots can display overlay texts
        // (in this example, we will display an average value)
        {
            float average = 0.0f;
            for (int n = 0; n < IM_ARRAYSIZE(values); n++)
                average += values[n];
            average /= (float)IM_ARRAYSIZE(values);
            char overlay[32];
            sprintf(overlay, "avg %f", average);
            GUI::PlotLines("Lines", values, IM_ARRAYSIZE(values), values_offset, overlay, -1.0f, 1.0f, ImVec2(0, 80.0f));
        }
        GUI::PlotHistogram("Histogram", arr, IM_ARRAYSIZE(arr), 0, NULL, 0.0f, 1.0f, ImVec2(0, 80.0f));

        // Use functions to generate output
        // FIXME: This is rather awkward because current plot API only pass in indices.
        // We probably want an API passing floats and user provide sample rate/count.
        struct Funcs
        {
            static float Sin(void*, int i) { return sinf(i * 0.1f); }
            static float Saw(void*, int i) { return (i & 1) ? 1.0f : -1.0f; }
        };
        static int func_type = 0, display_count = 70;
        GUI::Separator();
        GUI::SetNextItemWidth(100);
        GUI::Combo("func", &func_type, "Sin\0Saw\0");
        GUI::SameLine();
        GUI::SliderInt("Sample count", &display_count, 1, 400);
        float (*func)(void*, int) = (func_type == 0) ? Funcs::Sin : Funcs::Saw;
        GUI::PlotLines("Lines", func, NULL, display_count, 0, NULL, -1.0f, 1.0f, ImVec2(0, 80));
        GUI::PlotHistogram("Histogram", func, NULL, display_count, 0, NULL, -1.0f, 1.0f, ImVec2(0, 80));
        GUI::Separator();

        // Animate a simple progress bar
        static float progress = 0.0f, progress_dir = 1.0f;
        if (animate)
        {
            progress += progress_dir * 0.4f * GUI::GetIO().DeltaTime;
            if (progress >= +1.1f) { progress = +1.1f; progress_dir *= -1.0f; }
            if (progress <= -0.1f) { progress = -0.1f; progress_dir *= -1.0f; }
        }

        // Typically we would use ImVec2(-1.0f,0.0f) or ImVec2(-FLT_MIN,0.0f) to use all available width,
        // or ImVec2(width,0.0f) for a specified width. ImVec2(0.0f,0.0f) uses ItemWidth.
        GUI::ProgressBar(progress, ImVec2(0.0f, 0.0f));
        GUI::SameLine(0.0f, GUI::GetStyle().ItemInnerSpacing.x);
        GUI::Text("Progress Bar");

        float progress_saturated = IM_CLAMP(progress, 0.0f, 1.0f);
        char buf[32];
        sprintf(buf, "%d/%d", (int)(progress_saturated * 1753), 1753);
        GUI::ProgressBar(progress, ImVec2(0.f, 0.f), buf);
        GUI::TreePop();
    }

    if (GUI::TreeNode("Color/Picker Widgets"))
    {
        static ImVec4 color = ImVec4(114.0f / 255.0f, 144.0f / 255.0f, 154.0f / 255.0f, 200.0f / 255.0f);

        static bool alpha_preview = true;
        static bool alpha_half_preview = false;
        static bool drag_and_drop = true;
        static bool options_menu = true;
        static bool hdr = false;
        GUI::Checkbox("With Alpha Preview", &alpha_preview);
        GUI::Checkbox("With Half Alpha Preview", &alpha_half_preview);
        GUI::Checkbox("With Drag and Drop", &drag_and_drop);
        GUI::Checkbox("With Options Menu", &options_menu); GUI::SameLine(); HelpMarker("Right-click on the individual color widget to show options.");
        GUI::Checkbox("With HDR", &hdr); GUI::SameLine(); HelpMarker("Currently all this does is to lift the 0..1 limits on dragging widgets.");
        ImGuiColorEditFlags misc_flags = (hdr ? ImGuiColorEditFlags_HDR : 0) | (drag_and_drop ? 0 : ImGuiColorEditFlags_NoDragDrop) | (alpha_half_preview ? ImGuiColorEditFlags_AlphaPreviewHalf : (alpha_preview ? ImGuiColorEditFlags_AlphaPreview : 0)) | (options_menu ? 0 : ImGuiColorEditFlags_NoOptions);

        GUI::Text("Color widget:");
        GUI::SameLine(); HelpMarker(
            "Click on the colored square to open a color picker.\n"
            "CTRL+click on individual component to input value.\n");
        GUI::ColorEdit3("MyColor##1", (float*)&color, misc_flags);

        GUI::Text("Color widget HSV with Alpha:");
        GUI::ColorEdit4("MyColor##2", (float*)&color, ImGuiColorEditFlags_DisplayHSV | misc_flags);

        GUI::Text("Color widget with Float Display:");
        GUI::ColorEdit4("MyColor##2f", (float*)&color, ImGuiColorEditFlags_Float | misc_flags);

        GUI::Text("Color button with Picker:");
        GUI::SameLine(); HelpMarker(
            "With the ImGuiColorEditFlags_NoInputs flag you can hide all the slider/text inputs.\n"
            "With the ImGuiColorEditFlags_NoLabel flag you can pass a non-empty label which will only "
            "be used for the tooltip and picker popup.");
        GUI::ColorEdit4("MyColor##3", (float*)&color, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel | misc_flags);

        GUI::Text("Color button with Custom Picker Popup:");

        // Generate a default palette. The palette will persist and can be edited.
        static bool saved_palette_init = true;
        static ImVec4 saved_palette[32] = {};
        if (saved_palette_init)
        {
            for (int n = 0; n < IM_ARRAYSIZE(saved_palette); n++)
            {
                GUI::ColorConvertHSVtoRGB(n / 31.0f, 0.8f, 0.8f,
                    saved_palette[n].x, saved_palette[n].y, saved_palette[n].z);
                saved_palette[n].w = 1.0f; // Alpha
            }
            saved_palette_init = false;
        }

        static ImVec4 backup_color;
        bool open_popup = GUI::ColorButton("MyColor##3b", color, misc_flags);
        GUI::SameLine(0, GUI::GetStyle().ItemInnerSpacing.x);
        open_popup |= GUI::Button("Palette");
        if (open_popup)
        {
            GUI::OpenPopup("mypicker");
            backup_color = color;
        }
        if (GUI::BeginPopup("mypicker"))
        {
            GUI::Text("MY CUSTOM COLOR PICKER WITH AN AMAZING PALETTE!");
            GUI::Separator();
            GUI::ColorPicker4("##picker", (float*)&color, misc_flags | ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_NoSmallPreview);
            GUI::SameLine();

            GUI::BeginGroup(); // Lock X position
            GUI::Text("Current");
            GUI::ColorButton("##current", color, ImGuiColorEditFlags_NoPicker | ImGuiColorEditFlags_AlphaPreviewHalf, ImVec2(60, 40));
            GUI::Text("Previous");
            if (GUI::ColorButton("##previous", backup_color, ImGuiColorEditFlags_NoPicker | ImGuiColorEditFlags_AlphaPreviewHalf, ImVec2(60, 40)))
                color = backup_color;
            GUI::Separator();
            GUI::Text("Palette");
            for (int n = 0; n < IM_ARRAYSIZE(saved_palette); n++)
            {
                GUI::PushID(n);
                if ((n % 8) != 0)
                    GUI::SameLine(0.0f, GUI::GetStyle().ItemSpacing.y);

                ImGuiColorEditFlags palette_button_flags = ImGuiColorEditFlags_NoAlpha | ImGuiColorEditFlags_NoPicker | ImGuiColorEditFlags_NoTooltip;
                if (GUI::ColorButton("##palette", saved_palette[n], palette_button_flags, ImVec2(20, 20)))
                    color = ImVec4(saved_palette[n].x, saved_palette[n].y, saved_palette[n].z, color.w); // Preserve alpha!

                // Allow user to drop colors into each palette entry. Note that ColorButton() is already a
                // drag source by default, unless specifying the ImGuiColorEditFlags_NoDragDrop flag.
                if (GUI::BeginDragDropTarget())
                {
                    if (const ImGuiPayload* payload = GUI::AcceptDragDropPayload(IMGUI_PAYLOAD_TYPE_COLOR_3F))
                        memcpy((float*)&saved_palette[n], payload->Data, sizeof(float) * 3);
                    if (const ImGuiPayload* payload = GUI::AcceptDragDropPayload(IMGUI_PAYLOAD_TYPE_COLOR_4F))
                        memcpy((float*)&saved_palette[n], payload->Data, sizeof(float) * 4);
                    GUI::EndDragDropTarget();
                }

                GUI::PopID();
            }
            GUI::EndGroup();
            GUI::EndPopup();
        }

        GUI::Text("Color button only:");
        static bool no_border = false;
        GUI::Checkbox("ImGuiColorEditFlags_NoBorder", &no_border);
        GUI::ColorButton("MyColor##3c", *(ImVec4*)&color, misc_flags | (no_border ? ImGuiColorEditFlags_NoBorder : 0), ImVec2(80, 80));

        GUI::Text("Color picker:");
        static bool alpha = true;
        static bool alpha_bar = true;
        static bool side_preview = true;
        static bool ref_color = false;
        static ImVec4 ref_color_v(1.0f, 0.0f, 1.0f, 0.5f);
        static int display_mode = 0;
        static int picker_mode = 0;
        GUI::Checkbox("With Alpha", &alpha);
        GUI::Checkbox("With Alpha Bar", &alpha_bar);
        GUI::Checkbox("With Side Preview", &side_preview);
        if (side_preview)
        {
            GUI::SameLine();
            GUI::Checkbox("With Ref Color", &ref_color);
            if (ref_color)
            {
                GUI::SameLine();
                GUI::ColorEdit4("##RefColor", &ref_color_v.x, ImGuiColorEditFlags_NoInputs | misc_flags);
            }
        }
        GUI::Combo("Display Mode", &display_mode, "Auto/Current\0None\0RGB Only\0HSV Only\0Hex Only\0");
        GUI::SameLine(); HelpMarker(
            "ColorEdit defaults to displaying RGB inputs if you don't specify a display mode, "
            "but the user can change it with a right-click.\n\nColorPicker defaults to displaying RGB+HSV+Hex "
            "if you don't specify a display mode.\n\nYou can change the defaults using SetColorEditOptions().");
        GUI::Combo("Picker Mode", &picker_mode, "Auto/Current\0Hue bar + SV rect\0Hue wheel + SV triangle\0");
        GUI::SameLine(); HelpMarker("User can right-click the picker to change mode.");
        ImGuiColorEditFlags flags = misc_flags;
        if (!alpha)            flags |= ImGuiColorEditFlags_NoAlpha;        // This is by default if you call ColorPicker3() instead of ColorPicker4()
        if (alpha_bar)         flags |= ImGuiColorEditFlags_AlphaBar;
        if (!side_preview)     flags |= ImGuiColorEditFlags_NoSidePreview;
        if (picker_mode == 1)  flags |= ImGuiColorEditFlags_PickerHueBar;
        if (picker_mode == 2)  flags |= ImGuiColorEditFlags_PickerHueWheel;
        if (display_mode == 1) flags |= ImGuiColorEditFlags_NoInputs;       // Disable all RGB/HSV/Hex displays
        if (display_mode == 2) flags |= ImGuiColorEditFlags_DisplayRGB;     // Override display mode
        if (display_mode == 3) flags |= ImGuiColorEditFlags_DisplayHSV;
        if (display_mode == 4) flags |= ImGuiColorEditFlags_DisplayHex;
        GUI::ColorPicker4("MyColor##4", (float*)&color, flags, ref_color ? &ref_color_v.x : NULL);

        GUI::Text("Set defaults in code:");
        GUI::SameLine(); HelpMarker(
            "SetColorEditOptions() is designed to allow you to set boot-time default.\n"
            "We don't have Push/Pop functions because you can force options on a per-widget basis if needed,"
            "and the user can change non-forced ones with the options menu.\nWe don't have a getter to avoid"
            "encouraging you to persistently save values that aren't forward-compatible.");
        if (GUI::Button("Default: Uint8 + HSV + Hue Bar"))
            GUI::SetColorEditOptions(ImGuiColorEditFlags_Uint8 | ImGuiColorEditFlags_DisplayHSV | ImGuiColorEditFlags_PickerHueBar);
        if (GUI::Button("Default: Float + HDR + Hue Wheel"))
            GUI::SetColorEditOptions(ImGuiColorEditFlags_Float | ImGuiColorEditFlags_HDR | ImGuiColorEditFlags_PickerHueWheel);

        // HSV encoded support (to avoid RGB<>HSV round trips and singularities when S==0 or V==0)
        static ImVec4 color_hsv(0.23f, 1.0f, 1.0f, 1.0f); // Stored as HSV!
        GUI::Spacing();
        GUI::Text("HSV encoded colors");
        GUI::SameLine(); HelpMarker(
            "By default, colors are given to ColorEdit and ColorPicker in RGB, but ImGuiColorEditFlags_InputHSV"
            "allows you to store colors as HSV and pass them to ColorEdit and ColorPicker as HSV. This comes with the"
            "added benefit that you can manipulate hue values with the picker even when saturation or value are zero.");
        GUI::Text("Color widget with InputHSV:");
        GUI::ColorEdit4("HSV shown as RGB##1", (float*)&color_hsv, ImGuiColorEditFlags_DisplayRGB | ImGuiColorEditFlags_InputHSV | ImGuiColorEditFlags_Float);
        GUI::ColorEdit4("HSV shown as HSV##1", (float*)&color_hsv, ImGuiColorEditFlags_DisplayHSV | ImGuiColorEditFlags_InputHSV | ImGuiColorEditFlags_Float);
        GUI::DragFloat4("Raw HSV values", (float*)&color_hsv, 0.01f, 0.0f, 1.0f);

        GUI::TreePop();
    }

    if (GUI::TreeNode("Drag/Slider Flags"))
    {
        // Demonstrate using advanced flags for DragXXX and SliderXXX functions. Note that the flags are the same!
        static ImGuiSliderFlags flags = ImGuiSliderFlags_None;
        GUI::CheckboxFlags("ImGuiSliderFlags_ClampOnInput", (unsigned int*)&flags, ImGuiSliderFlags_ClampOnInput);
        GUI::SameLine(); HelpMarker("Always clamp value to min/max bounds (if any) when input manually with CTRL+Click.");
        GUI::CheckboxFlags("ImGuiSliderFlags_Logarithmic", (unsigned int*)&flags, ImGuiSliderFlags_Logarithmic);
        GUI::SameLine(); HelpMarker("Enable logarithmic editing (more precision for small values).");
        GUI::CheckboxFlags("ImGuiSliderFlags_NoRoundToFormat", (unsigned int*)&flags, ImGuiSliderFlags_NoRoundToFormat);
        GUI::SameLine(); HelpMarker("Disable rounding underlying value to match precision of the format string (e.g. %.3f values are rounded to those 3 digits).");
        GUI::CheckboxFlags("ImGuiSliderFlags_NoInput", (unsigned int*)&flags, ImGuiSliderFlags_NoInput);
        GUI::SameLine(); HelpMarker("Disable CTRL+Click or Enter key allowing to input text directly into the widget.");

        // Drags
        static float drag_f = 0.5f;
        static int drag_i = 50;
        GUI::Text("Underlying float value: %f", drag_f);
        GUI::DragFloat("DragFloat (0 -> 1)", &drag_f, 0.005f, 0.0f, 1.0f, "%.3f", flags);
        GUI::DragFloat("DragFloat (0 -> +inf)", &drag_f, 0.005f, 0.0f, FLT_MAX, "%.3f", flags);
        GUI::DragFloat("DragFloat (-inf -> 1)", &drag_f, 0.005f, -FLT_MAX, 1.0f, "%.3f", flags);
        GUI::DragFloat("DragFloat (-inf -> +inf)", &drag_f, 0.005f, -FLT_MAX, +FLT_MAX, "%.3f", flags);
        GUI::DragInt("DragInt (0 -> 100)", &drag_i, 0.5f, 0, 100, "%d", flags);

        // Sliders
        static float slider_f = 0.5f;
        static int slider_i = 50;
        GUI::Text("Underlying float value: %f", slider_f);
        GUI::SliderFloat("SliderFloat (0 -> 1)", &slider_f, 0.0f, 1.0f, "%.3f", flags);
        GUI::SliderInt("SliderInt (0 -> 100)", &slider_i, 0, 100, "%d", flags);

        GUI::TreePop();
    }

    if (GUI::TreeNode("Range Widgets"))
    {
        static float begin = 10, end = 90;
        static int begin_i = 100, end_i = 1000;
        GUI::DragFloatRange2("range float", &begin, &end, 0.25f, 0.0f, 100.0f, "Min: %.1f %%", "Max: %.1f %%", ImGuiSliderFlags_ClampOnInput);
        GUI::DragIntRange2("range int", &begin_i, &end_i, 5, 0, 1000, "Min: %d units", "Max: %d units");
        GUI::DragIntRange2("range int (no bounds)", &begin_i, &end_i, 5, 0, 0, "Min: %d units", "Max: %d units");
        GUI::TreePop();
    }

    if (GUI::TreeNode("Data Types"))
    {
        // DragScalar/InputScalar/SliderScalar functions allow various data types
        // - signed/unsigned
        // - 8/16/32/64-bits
        // - integer/float/double
        // To avoid polluting the public API with all possible combinations, we use the ImGuiDataType enum
        // to pass the type, and passing all arguments by pointer.
        // This is the reason the test code below creates local variables to hold "zero" "one" etc. for each types.
        // In practice, if you frequently use a given type that is not covered by the normal API entry points,
        // you can wrap it yourself inside a 1 line function which can take typed argument as value instead of void*,
        // and then pass their address to the generic function. For example:
        //   bool MySliderU64(const char *label, u64* value, u64 min = 0, u64 max = 0, const char* format = "%lld")
        //   {
        //      return SliderScalar(label, ImGuiDataType_U64, value, &min, &max, format);
        //   }

        // Setup limits (as helper variables so we can take their address, as explained above)
        // Note: SliderScalar() functions have a maximum usable range of half the natural type maximum, hence the /2.
        #ifndef LLONG_MIN
        ImS64 LLONG_MIN = -9223372036854775807LL - 1;
        ImS64 LLONG_MAX = 9223372036854775807LL;
        ImU64 ULLONG_MAX = (2ULL * 9223372036854775807LL + 1);
        #endif
        const char    s8_zero  = 0,   s8_one  = 1,   s8_fifty  = 50, s8_min  = -128,        s8_max = 127;
        const ImU8    u8_zero  = 0,   u8_one  = 1,   u8_fifty  = 50, u8_min  = 0,           u8_max = 255;
        const short   s16_zero = 0,   s16_one = 1,   s16_fifty = 50, s16_min = -32768,      s16_max = 32767;
        const ImU16   u16_zero = 0,   u16_one = 1,   u16_fifty = 50, u16_min = 0,           u16_max = 65535;
        const ImS32   s32_zero = 0,   s32_one = 1,   s32_fifty = 50, s32_min = INT_MIN/2,   s32_max = INT_MAX/2,    s32_hi_a = INT_MAX/2 - 100,    s32_hi_b = INT_MAX/2;
        const ImU32   u32_zero = 0,   u32_one = 1,   u32_fifty = 50, u32_min = 0,           u32_max = UINT_MAX/2,   u32_hi_a = UINT_MAX/2 - 100,   u32_hi_b = UINT_MAX/2;
        const ImS64   s64_zero = 0,   s64_one = 1,   s64_fifty = 50, s64_min = LLONG_MIN/2, s64_max = LLONG_MAX/2,  s64_hi_a = LLONG_MAX/2 - 100,  s64_hi_b = LLONG_MAX/2;
        const ImU64   u64_zero = 0,   u64_one = 1,   u64_fifty = 50, u64_min = 0,           u64_max = ULLONG_MAX/2, u64_hi_a = ULLONG_MAX/2 - 100, u64_hi_b = ULLONG_MAX/2;
        const float   f32_zero = 0.f, f32_one = 1.f, f32_lo_a = -10000000000.0f, f32_hi_a = +10000000000.0f;
        const double  f64_zero = 0.,  f64_one = 1.,  f64_lo_a = -1000000000000000.0, f64_hi_a = +1000000000000000.0;

        // State
        static char   s8_v  = 127;
        static ImU8   u8_v  = 255;
        static short  s16_v = 32767;
        static ImU16  u16_v = 65535;
        static ImS32  s32_v = -1;
        static ImU32  u32_v = (ImU32)-1;
        static ImS64  s64_v = -1;
        static ImU64  u64_v = (ImU64)-1;
        static float  f32_v = 0.123f;
        static double f64_v = 90000.01234567890123456789;

        const float drag_speed = 0.2f;
        static bool drag_clamp = false;
        GUI::Text("Drags:");
        GUI::Checkbox("Clamp integers to 0..50", &drag_clamp); GUI::SameLine(); HelpMarker("As with every widgets in dear imgui, we never modify values unless there is a user interaction.\nYou can override the clamping limits by using CTRL+Click to input a value.");
        GUI::DragScalar("drag s8",        ImGuiDataType_S8,     &s8_v,  drag_speed, drag_clamp ? &s8_zero  : NULL, drag_clamp ? &s8_fifty  : NULL);
        GUI::DragScalar("drag u8",        ImGuiDataType_U8,     &u8_v,  drag_speed, drag_clamp ? &u8_zero  : NULL, drag_clamp ? &u8_fifty  : NULL, "%u ms");
        GUI::DragScalar("drag s16",       ImGuiDataType_S16,    &s16_v, drag_speed, drag_clamp ? &s16_zero : NULL, drag_clamp ? &s16_fifty : NULL);
        GUI::DragScalar("drag u16",       ImGuiDataType_U16,    &u16_v, drag_speed, drag_clamp ? &u16_zero : NULL, drag_clamp ? &u16_fifty : NULL, "%u ms");
        GUI::DragScalar("drag s32",       ImGuiDataType_S32,    &s32_v, drag_speed, drag_clamp ? &s32_zero : NULL, drag_clamp ? &s32_fifty : NULL);
        GUI::DragScalar("drag u32",       ImGuiDataType_U32,    &u32_v, drag_speed, drag_clamp ? &u32_zero : NULL, drag_clamp ? &u32_fifty : NULL, "%u ms");
        GUI::DragScalar("drag s64",       ImGuiDataType_S64,    &s64_v, drag_speed, drag_clamp ? &s64_zero : NULL, drag_clamp ? &s64_fifty : NULL);
        GUI::DragScalar("drag u64",       ImGuiDataType_U64,    &u64_v, drag_speed, drag_clamp ? &u64_zero : NULL, drag_clamp ? &u64_fifty : NULL);
        GUI::DragScalar("drag float",     ImGuiDataType_Float,  &f32_v, 0.005f,  &f32_zero, &f32_one, "%f");
        GUI::DragScalar("drag float log", ImGuiDataType_Float,  &f32_v, 0.005f,  &f32_zero, &f32_one, "%f", ImGuiSliderFlags_Logarithmic);
        GUI::DragScalar("drag double",    ImGuiDataType_Double, &f64_v, 0.0005f, &f64_zero, NULL,     "%.10f grams");
        GUI::DragScalar("drag double log",ImGuiDataType_Double, &f64_v, 0.0005f, &f64_zero, &f64_one, "0 < %.10f < 1", ImGuiSliderFlags_Logarithmic);

        GUI::Text("Sliders");
        GUI::SliderScalar("slider s8 full",       ImGuiDataType_S8,     &s8_v,  &s8_min,   &s8_max,   "%d");
        GUI::SliderScalar("slider u8 full",       ImGuiDataType_U8,     &u8_v,  &u8_min,   &u8_max,   "%u");
        GUI::SliderScalar("slider s16 full",      ImGuiDataType_S16,    &s16_v, &s16_min,  &s16_max,  "%d");
        GUI::SliderScalar("slider u16 full",      ImGuiDataType_U16,    &u16_v, &u16_min,  &u16_max,  "%u");
        GUI::SliderScalar("slider s32 low",       ImGuiDataType_S32,    &s32_v, &s32_zero, &s32_fifty,"%d");
        GUI::SliderScalar("slider s32 high",      ImGuiDataType_S32,    &s32_v, &s32_hi_a, &s32_hi_b, "%d");
        GUI::SliderScalar("slider s32 full",      ImGuiDataType_S32,    &s32_v, &s32_min,  &s32_max,  "%d");
        GUI::SliderScalar("slider u32 low",       ImGuiDataType_U32,    &u32_v, &u32_zero, &u32_fifty,"%u");
        GUI::SliderScalar("slider u32 high",      ImGuiDataType_U32,    &u32_v, &u32_hi_a, &u32_hi_b, "%u");
        GUI::SliderScalar("slider u32 full",      ImGuiDataType_U32,    &u32_v, &u32_min,  &u32_max,  "%u");
        GUI::SliderScalar("slider s64 low",       ImGuiDataType_S64,    &s64_v, &s64_zero, &s64_fifty,"%I64d");
        GUI::SliderScalar("slider s64 high",      ImGuiDataType_S64,    &s64_v, &s64_hi_a, &s64_hi_b, "%I64d");
        GUI::SliderScalar("slider s64 full",      ImGuiDataType_S64,    &s64_v, &s64_min,  &s64_max,  "%I64d");
        GUI::SliderScalar("slider u64 low",       ImGuiDataType_U64,    &u64_v, &u64_zero, &u64_fifty,"%I64u ms");
        GUI::SliderScalar("slider u64 high",      ImGuiDataType_U64,    &u64_v, &u64_hi_a, &u64_hi_b, "%I64u ms");
        GUI::SliderScalar("slider u64 full",      ImGuiDataType_U64,    &u64_v, &u64_min,  &u64_max,  "%I64u ms");
        GUI::SliderScalar("slider float low",     ImGuiDataType_Float,  &f32_v, &f32_zero, &f32_one);
        GUI::SliderScalar("slider float low log", ImGuiDataType_Float,  &f32_v, &f32_zero, &f32_one,  "%.10f", ImGuiSliderFlags_Logarithmic);
        GUI::SliderScalar("slider float high",    ImGuiDataType_Float,  &f32_v, &f32_lo_a, &f32_hi_a, "%e");
        GUI::SliderScalar("slider double low",    ImGuiDataType_Double, &f64_v, &f64_zero, &f64_one,  "%.10f grams");
        GUI::SliderScalar("slider double low log",ImGuiDataType_Double, &f64_v, &f64_zero, &f64_one,  "%.10f", ImGuiSliderFlags_Logarithmic);
        GUI::SliderScalar("slider double high",   ImGuiDataType_Double, &f64_v, &f64_lo_a, &f64_hi_a, "%e grams");

        static bool inputs_step = true;
        GUI::Text("Inputs");
        GUI::Checkbox("Show step buttons", &inputs_step);
        GUI::InputScalar("input s8",      ImGuiDataType_S8,     &s8_v,  inputs_step ? &s8_one  : NULL, NULL, "%d");
        GUI::InputScalar("input u8",      ImGuiDataType_U8,     &u8_v,  inputs_step ? &u8_one  : NULL, NULL, "%u");
        GUI::InputScalar("input s16",     ImGuiDataType_S16,    &s16_v, inputs_step ? &s16_one : NULL, NULL, "%d");
        GUI::InputScalar("input u16",     ImGuiDataType_U16,    &u16_v, inputs_step ? &u16_one : NULL, NULL, "%u");
        GUI::InputScalar("input s32",     ImGuiDataType_S32,    &s32_v, inputs_step ? &s32_one : NULL, NULL, "%d");
        GUI::InputScalar("input s32 hex", ImGuiDataType_S32,    &s32_v, inputs_step ? &s32_one : NULL, NULL, "%08X", ImGuiInputTextFlags_CharsHexadecimal);
        GUI::InputScalar("input u32",     ImGuiDataType_U32,    &u32_v, inputs_step ? &u32_one : NULL, NULL, "%u");
        GUI::InputScalar("input u32 hex", ImGuiDataType_U32,    &u32_v, inputs_step ? &u32_one : NULL, NULL, "%08X", ImGuiInputTextFlags_CharsHexadecimal);
        GUI::InputScalar("input s64",     ImGuiDataType_S64,    &s64_v, inputs_step ? &s64_one : NULL);
        GUI::InputScalar("input u64",     ImGuiDataType_U64,    &u64_v, inputs_step ? &u64_one : NULL);
        GUI::InputScalar("input float",   ImGuiDataType_Float,  &f32_v, inputs_step ? &f32_one : NULL);
        GUI::InputScalar("input double",  ImGuiDataType_Double, &f64_v, inputs_step ? &f64_one : NULL);

        GUI::TreePop();
    }

    if (GUI::TreeNode("Multi-component Widgets"))
    {
        static float vec4f[4] = { 0.10f, 0.20f, 0.30f, 0.44f };
        static int vec4i[4] = { 1, 5, 100, 255 };

        GUI::InputFloat2("input float2", vec4f);
        GUI::DragFloat2("drag float2", vec4f, 0.01f, 0.0f, 1.0f);
        GUI::SliderFloat2("slider float2", vec4f, 0.0f, 1.0f);
        GUI::InputInt2("input int2", vec4i);
        GUI::DragInt2("drag int2", vec4i, 1, 0, 255);
        GUI::SliderInt2("slider int2", vec4i, 0, 255);
        GUI::Spacing();

        GUI::InputFloat3("input float3", vec4f);
        GUI::DragFloat3("drag float3", vec4f, 0.01f, 0.0f, 1.0f);
        GUI::SliderFloat3("slider float3", vec4f, 0.0f, 1.0f);
        GUI::InputInt3("input int3", vec4i);
        GUI::DragInt3("drag int3", vec4i, 1, 0, 255);
        GUI::SliderInt3("slider int3", vec4i, 0, 255);
        GUI::Spacing();

        GUI::InputFloat4("input float4", vec4f);
        GUI::DragFloat4("drag float4", vec4f, 0.01f, 0.0f, 1.0f);
        GUI::SliderFloat4("slider float4", vec4f, 0.0f, 1.0f);
        GUI::InputInt4("input int4", vec4i);
        GUI::DragInt4("drag int4", vec4i, 1, 0, 255);
        GUI::SliderInt4("slider int4", vec4i, 0, 255);

        GUI::TreePop();
    }

    if (GUI::TreeNode("Vertical Sliders"))
    {
        const float spacing = 4;
        GUI::PushStyleVar(imgui_styleVar_ItemSpacing, ImVec2(spacing, spacing));

        static int int_value = 0;
        GUI::VSliderInt("##int", ImVec2(18, 160), &int_value, 0, 5);
        GUI::SameLine();

        static float values[7] = { 0.0f, 0.60f, 0.35f, 0.9f, 0.70f, 0.20f, 0.0f };
        GUI::PushID("set1");
        for (int i = 0; i < 7; i++)
        {
            if (i > 0) GUI::SameLine();
            GUI::PushID(i);
            GUI::PushStyleColor(ImGuiCol_FrameBg, (ImVec4)ImColor::HSV(i / 7.0f, 0.5f, 0.5f));
            GUI::PushStyleColor(ImGuiCol_FrameBgHovered, (ImVec4)ImColor::HSV(i / 7.0f, 0.6f, 0.5f));
            GUI::PushStyleColor(ImGuiCol_FrameBgActive, (ImVec4)ImColor::HSV(i / 7.0f, 0.7f, 0.5f));
            GUI::PushStyleColor(ImGuiCol_SliderGrab, (ImVec4)ImColor::HSV(i / 7.0f, 0.9f, 0.9f));
            GUI::VSliderFloat("##v", ImVec2(18, 160), &values[i], 0.0f, 1.0f, "");
            if (GUI::IsItemActive() || GUI::IsItemHovered())
                GUI::SetTooltip("%.3f", values[i]);
            GUI::PopStyleColor(4);
            GUI::PopID();
        }
        GUI::PopID();

        GUI::SameLine();
        GUI::PushID("set2");
        static float values2[4] = { 0.20f, 0.80f, 0.40f, 0.25f };
        const int rows = 3;
        const ImVec2 small_slider_size(18, (float)(int)((160.0f - (rows - 1) * spacing) / rows));
        for (int nx = 0; nx < 4; nx++)
        {
            if (nx > 0) GUI::SameLine();
            GUI::BeginGroup();
            for (int ny = 0; ny < rows; ny++)
            {
                GUI::PushID(nx * rows + ny);
                GUI::VSliderFloat("##v", small_slider_size, &values2[nx], 0.0f, 1.0f, "");
                if (GUI::IsItemActive() || GUI::IsItemHovered())
                    GUI::SetTooltip("%.3f", values2[nx]);
                GUI::PopID();
            }
            GUI::EndGroup();
        }
        GUI::PopID();

        GUI::SameLine();
        GUI::PushID("set3");
        for (int i = 0; i < 4; i++)
        {
            if (i > 0) GUI::SameLine();
            GUI::PushID(i);
            GUI::PushStyleVar(imgui_styleVar_GrabMinSize, 40);
            GUI::VSliderFloat("##v", ImVec2(40, 160), &values[i], 0.0f, 1.0f, "%.2f\nsec");
            GUI::PopStyleVar();
            GUI::PopID();
        }
        GUI::PopID();
        GUI::PopStyleVar();
        GUI::TreePop();
    }

    if (GUI::TreeNode("Drag and Drop"))
    {
        if (GUI::TreeNode("Drag and drop in standard widgets"))
        {
            // ColorEdit widgets automatically act as drag source and drag target.
            // They are using standardized payload strings IMGUI_PAYLOAD_TYPE_COLOR_3F and IMGUI_PAYLOAD_TYPE_COLOR_4F
            // to allow your own widgets to use colors in their drag and drop interaction.
            // Also see 'Demo->Widgets->Color/Picker Widgets->Palette' demo.
            HelpMarker("You can drag from the colored squares.");
            static float col1[3] = { 1.0f, 0.0f, 0.2f };
            static float col2[4] = { 0.4f, 0.7f, 0.0f, 0.5f };
            GUI::ColorEdit3("color 1", col1);
            GUI::ColorEdit4("color 2", col2);
            GUI::TreePop();
        }

        if (GUI::TreeNode("Drag and drop to copy/swap items"))
        {
            enum Mode
            {
                Mode_Copy,
                Mode_Move,
                Mode_Swap
            };
            static int mode = 0;
            if (GUI::RadioButton("Copy", mode == Mode_Copy)) { mode = Mode_Copy; } GUI::SameLine();
            if (GUI::RadioButton("Move", mode == Mode_Move)) { mode = Mode_Move; } GUI::SameLine();
            if (GUI::RadioButton("Swap", mode == Mode_Swap)) { mode = Mode_Swap; }
            static const char* names[9] =
            {
                "Bobby", "Beatrice", "Betty",
                "Brianna", "Barry", "Bernard",
                "Bibi", "Blaine", "Bryn"
            };
            for (int n = 0; n < IM_ARRAYSIZE(names); n++)
            {
                GUI::PushID(n);
                if ((n % 3) != 0)
                    GUI::SameLine();
                GUI::Button(names[n], ImVec2(60, 60));

                // Our buttons are both drag sources and drag targets here!
                if (GUI::BeginDragDropSource(ImGuiDragDropFlags_None))
                {
                    // Set payload to carry the index of our item (could be anything)
                    GUI::SetDragDropPayload("DND_DEMO_CELL", &n, sizeof(int));

                    // Display preview (could be anything, e.g. when dragging an image we could decide to display
                    // the filename and a small preview of the image, etc.)
                    if (mode == Mode_Copy) { GUI::Text("Copy %s", names[n]); }
                    if (mode == Mode_Move) { GUI::Text("Move %s", names[n]); }
                    if (mode == Mode_Swap) { GUI::Text("Swap %s", names[n]); }
                    GUI::EndDragDropSource();
                }
                if (GUI::BeginDragDropTarget())
                {
                    if (const ImGuiPayload* payload = GUI::AcceptDragDropPayload("DND_DEMO_CELL"))
                    {
                        IM_ASSERT(payload->DataSize == sizeof(int));
                        int payload_n = *(const int*)payload->Data;
                        if (mode == Mode_Copy)
                        {
                            names[n] = names[payload_n];
                        }
                        if (mode == Mode_Move)
                        {
                            names[n] = names[payload_n];
                            names[payload_n] = "";
                        }
                        if (mode == Mode_Swap)
                        {
                            const char* tmp = names[n];
                            names[n] = names[payload_n];
                            names[payload_n] = tmp;
                        }
                    }
                    GUI::EndDragDropTarget();
                }
                GUI::PopID();
            }
            GUI::TreePop();
        }

        if (GUI::TreeNode("Drag to reorder items (simple)"))
        {
            // Simple reordering
            HelpMarker(
                "We don't use the drag and drop api at all here! "
                "Instead we query when the item is held but not hovered, and order items accordingly.");
            static const char* item_names[] = { "Item One", "Item Two", "Item Three", "Item Four", "Item Five" };
            for (int n = 0; n < IM_ARRAYSIZE(item_names); n++)
            {
                const char* item = item_names[n];
                GUI::Selectable(item);

                if (GUI::IsItemActive() && !GUI::IsItemHovered())
                {
                    int n_next = n + (GUI::GetMouseDragDelta(0).y < 0.f ? -1 : 1);
                    if (n_next >= 0 && n_next < IM_ARRAYSIZE(item_names))
                    {
                        item_names[n] = item_names[n_next];
                        item_names[n_next] = item;
                        GUI::ResetMouseDragDelta();
                    }
                }
            }
            GUI::TreePop();
        }

        GUI::TreePop();
    }

    if (GUI::TreeNode("Querying Status (Active/Focused/Hovered etc.)"))
    {
        // Select an item type
        const char* item_names[] =
        {
            "Text", "Button", "Button (w/ repeat)", "Checkbox", "SliderFloat", "InputText", "InputFloat",
            "InputFloat3", "ColorEdit4", "MenuItem", "TreeNode", "TreeNode (w/ double-click)", "ListBox"
        };
        static int item_type = 1;
        GUI::Combo("Item Type", &item_type, item_names, IM_ARRAYSIZE(item_names), IM_ARRAYSIZE(item_names));
        GUI::SameLine();
        HelpMarker("Testing how various types of items are interacting with the IsItemXXX functions.");

        // Submit selected item item so we can query their status in the code following it.
        bool ret = false;
        static bool b = false;
        static float col4f[4] = { 1.0f, 0.5, 0.0f, 1.0f };
        static char str[16] = {};
        if (item_type == 0) { GUI::Text("ITEM: Text"); }                                              // Testing text items with no identifier/interaction
        if (item_type == 1) { ret = GUI::Button("ITEM: Button"); }                                    // Testing button
        if (item_type == 2) { GUI::PushButtonRepeat(true); ret = GUI::Button("ITEM: Button"); GUI::PopButtonRepeat(); } // Testing button (with repeater)
        if (item_type == 3) { ret = GUI::Checkbox("ITEM: Checkbox", &b); }                            // Testing checkbox
        if (item_type == 4) { ret = GUI::SliderFloat("ITEM: SliderFloat", &col4f[0], 0.0f, 1.0f); }   // Testing basic item
        if (item_type == 5) { ret = GUI::InputText("ITEM: InputText", &str[0], IM_ARRAYSIZE(str)); }  // Testing input text (which handles tabbing)
        if (item_type == 6) { ret = GUI::InputFloat("ITEM: InputFloat", col4f, 1.0f); }               // Testing +/- buttons on scalar input
        if (item_type == 7) { ret = GUI::InputFloat3("ITEM: InputFloat3", col4f); }                   // Testing multi-component items (IsItemXXX flags are reported merged)
        if (item_type == 8) { ret = GUI::ColorEdit4("ITEM: ColorEdit4", col4f); }                     // Testing multi-component items (IsItemXXX flags are reported merged)
        if (item_type == 9) { ret = GUI::MenuItem("ITEM: MenuItem"); }                                // Testing menu item (they use ImGuiButtonFlags_PressedOnRelease button policy)
        if (item_type == 10){ ret = GUI::TreeNode("ITEM: TreeNode"); if (ret) GUI::TreePop(); }     // Testing tree node
        if (item_type == 11){ ret = GUI::TreeNodeEx("ITEM: TreeNode w/ ImGuiTreeNodeFlags_OpenOnDoubleClick", ImGuiTreeNodeFlags_OpenOnDoubleClick | ImGuiTreeNodeFlags_NoTreePushOnOpen); } // Testing tree node with ImGuiButtonFlags_PressedOnDoubleClick button policy.
        if (item_type == 12){ const char* items[] = { "Apple", "Banana", "Cherry", "Kiwi" }; static int current = 1; ret = GUI::ListBox("ITEM: ListBox", &current, items, IM_ARRAYSIZE(items), IM_ARRAYSIZE(items)); }

        // Display the values of IsItemHovered() and other common item state functions.
        // Note that the ImGuiHoveredFlags_XXX flags can be combined.
        // Because BulletText is an item itself and that would affect the output of IsItemXXX functions,
        // we query every state in a single call to avoid storing them and to simplify the code.
        GUI::BulletText(
            "Return value = %d\n"
            "IsItemFocused() = %d\n"
            "IsItemHovered() = %d\n"
            "IsItemHovered(_AllowWhenBlockedByPopup) = %d\n"
            "IsItemHovered(_AllowWhenBlockedByActiveItem) = %d\n"
            "IsItemHovered(_AllowWhenOverlapped) = %d\n"
            "IsItemHovered(_RectOnly) = %d\n"
            "IsItemActive() = %d\n"
            "IsItemEdited() = %d\n"
            "IsItemActivated() = %d\n"
            "IsItemDeactivated() = %d\n"
            "IsItemDeactivatedAfterEdit() = %d\n"
            "IsItemVisible() = %d\n"
            "IsItemClicked() = %d\n"
            "IsItemToggledOpen() = %d\n"
            "GetItemRectMin() = (%.1f, %.1f)\n"
            "GetItemRectMax() = (%.1f, %.1f)\n"
            "GetItemRectSize() = (%.1f, %.1f)",
            ret,
            GUI::IsItemFocused(),
            GUI::IsItemHovered(),
            GUI::IsItemHovered(ImGuiHoveredFlags_AllowWhenBlockedByPopup),
            GUI::IsItemHovered(ImGuiHoveredFlags_AllowWhenBlockedByActiveItem),
            GUI::IsItemHovered(ImGuiHoveredFlags_AllowWhenOverlapped),
            GUI::IsItemHovered(ImGuiHoveredFlags_RectOnly),
            GUI::IsItemActive(),
            GUI::IsItemEdited(),
            GUI::IsItemActivated(),
            GUI::IsItemDeactivated(),
            GUI::IsItemDeactivatedAfterEdit(),
            GUI::IsItemVisible(),
            GUI::IsItemClicked(),
            GUI::IsItemToggledOpen(),
            GUI::GetItemRectMin().x, GUI::GetItemRectMin().y,
            GUI::GetItemRectMax().x, GUI::GetItemRectMax().y,
            GUI::GetItemRectSize().x, GUI::GetItemRectSize().y
        );

        static bool embed_all_inside_a_child_window = false;
        GUI::Checkbox("Embed everything inside a child window (for additional testing)", &embed_all_inside_a_child_window);
        if (embed_all_inside_a_child_window)
            GUI::BeginChild("outer_child", ImVec2(0, GUI::GetFontSize() * 20.0f), true);

        // Testing IsWindowFocused() function with its various flags.
        // Note that the ImGuiFocusedFlags_XXX flags can be combined.
        GUI::BulletText(
            "IsWindowFocused() = %d\n"
            "IsWindowFocused(_ChildWindows) = %d\n"
            "IsWindowFocused(_ChildWindows|_RootWindow) = %d\n"
            "IsWindowFocused(_RootWindow) = %d\n"
            "IsWindowFocused(_AnyWindow) = %d\n",
            GUI::IsWindowFocused(),
            GUI::IsWindowFocused(ImGuiFocusedFlags_ChildWindows),
            GUI::IsWindowFocused(ImGuiFocusedFlags_ChildWindows | ImGuiFocusedFlags_RootWindow),
            GUI::IsWindowFocused(ImGuiFocusedFlags_RootWindow),
            GUI::IsWindowFocused(ImGuiFocusedFlags_AnyWindow));

        // Testing IsWindowHovered() function with its various flags.
        // Note that the ImGuiHoveredFlags_XXX flags can be combined.
        GUI::BulletText(
            "IsWindowHovered() = %d\n"
            "IsWindowHovered(_AllowWhenBlockedByPopup) = %d\n"
            "IsWindowHovered(_AllowWhenBlockedByActiveItem) = %d\n"
            "IsWindowHovered(_ChildWindows) = %d\n"
            "IsWindowHovered(_ChildWindows|_RootWindow) = %d\n"
            "IsWindowHovered(_ChildWindows|_AllowWhenBlockedByPopup) = %d\n"
            "IsWindowHovered(_RootWindow) = %d\n"
            "IsWindowHovered(_AnyWindow) = %d\n",
            GUI::IsWindowHovered(),
            GUI::IsWindowHovered(ImGuiHoveredFlags_AllowWhenBlockedByPopup),
            GUI::IsWindowHovered(ImGuiHoveredFlags_AllowWhenBlockedByActiveItem),
            GUI::IsWindowHovered(ImGuiHoveredFlags_ChildWindows),
            GUI::IsWindowHovered(ImGuiHoveredFlags_ChildWindows | ImGuiHoveredFlags_RootWindow),
            GUI::IsWindowHovered(ImGuiHoveredFlags_ChildWindows | ImGuiHoveredFlags_AllowWhenBlockedByPopup),
            GUI::IsWindowHovered(ImGuiHoveredFlags_RootWindow),
            GUI::IsWindowHovered(ImGuiHoveredFlags_AnyWindow));

        GUI::BeginChild("child", ImVec2(0, 50), true);
        GUI::Text("This is another child window for testing the _ChildWindows flag.");
        GUI::EndChild();
        if (embed_all_inside_a_child_window)
            GUI::EndChild();

        static char unused_str[] = "This widget is only here to be able to tab-out of the widgets above.";
        GUI::InputText("unused", unused_str, IM_ARRAYSIZE(unused_str), ImGuiInputTextFlags_ReadOnly);

        // Calling IsItemHovered() after begin returns the hovered status of the title bar.
        // This is useful in particular if you want to create a context menu associated to the title bar of a window.
        // This will also work when docked into a Tab (the Tab replace the Title Bar and guarantee the same properties).
        static bool test_window = false;
        GUI::Checkbox("Hovered/Active tests after Begin() for title bar testing", &test_window);
        if (test_window)
        {
            // FIXME-DOCK: This window cannot be docked within the ImGui Demo window, this will cause a feedback loop and get them stuck.
            // Could we fix this through an ImGuiWindowClass feature? Or an API call to tag our parent as "don't skip items"?
            GUI::Begin("Title bar Hovered/Active tests", &test_window);
            if (GUI::BeginPopupContextItem()) // <-- This is using IsItemHovered()
            {
                if (GUI::MenuItem("Close")) { test_window = false; }
                GUI::EndPopup();
            }
            GUI::Text(
                "IsItemHovered() after begin = %d (== is title bar hovered)\n"
                "IsItemActive() after begin = %d (== is window being clicked/moved)\n",
                GUI::IsItemHovered(), GUI::IsItemActive());
            GUI::End();
        }

        GUI::TreePop();
    }
}

static void ShowDemoWindowLayout()
{
    if (!GUI::CollapsingHeader("Layout & Scrolling"))
        return;

    if (GUI::TreeNode("Child windows"))
    {
        HelpMarker("Use child windows to begin into a self-contained independent scrolling/clipping regions within a host window.");
        static bool disable_mouse_wheel = false;
        static bool disable_menu = false;
        GUI::Checkbox("Disable Mouse Wheel", &disable_mouse_wheel);
        GUI::Checkbox("Disable Menu", &disable_menu);

        // Child 1: no border, enable horizontal scrollbar
        {
            ImGuiWindowFlags window_flags = ImGuiWindowFlags_HorizontalScrollbar;
            if (disable_mouse_wheel)
                window_flags |= ImGuiWindowFlags_NoScrollWithMouse;
            GUI::BeginChild("ChildL", ImVec2(GUI::GetWindowContentRegiowidth() * 0.5f, 260), false, window_flags);
            for (int i = 0; i < 100; i++)
                GUI::Text("%04d: scrollable region", i);
            GUI::EndChild();
        }

        GUI::SameLine();

        // Child 2: rounded border
        {
            ImGuiWindowFlags window_flags = ImGuiWindowFlags_None;
            if (disable_mouse_wheel)
                window_flags |= ImGuiWindowFlags_NoScrollWithMouse;
            if (!disable_menu)
                window_flags |= ImGuiWindowFlags_MenuBar;
            GUI::PushStyleVar(imgui_styleVar_ChildRounding, 5.0f);
            GUI::BeginChild("ChildR", ImVec2(0, 260), true, window_flags);
            if (!disable_menu && GUI::BeginMenuBar())
            {
                if (GUI::BeginMenu("Menu"))
                {
                    ShowExampleMenuFile();
                    GUI::EndMenu();
                }
                GUI::EndMenuBar();
            }
            GUI::Columns(2);
            for (int i = 0; i < 100; i++)
            {
                char buf[32];
                sprintf(buf, "%03d", i);
                GUI::Button(buf, ImVec2(-FLT_MIN, 0.0f));
                GUI::NextColumn();
            }
            GUI::EndChild();
            GUI::PopStyleVar();
        }

        GUI::Separator();

        // Demonstrate a few extra things
        // - Changing ImGuiCol_ChildBg (which is transparent black in default styles)
        // - Using SetCursorPos() to position child window (the child window is an item from the POV of parent window)
        //   You can also call SetNextWindowPos() to position the child window. The parent window will effectively
        //   layout from this position.
        // - Using GUI::GetItemRectMin/Max() to query the "item" state (because the child window is an item from
        //   the POV of the parent window). See 'Demo->Querying Status (Active/Focused/Hovered etc.)' for details.
        {
            static int offset_x = 0;
            GUI::SetNextItemWidth(100);
            GUI::DragInt("Offset X", &offset_x, 1.0f, -1000, 1000);

            GUI::SetCursorPosX(GUI::GetCursorPosX() + (float)offset_x);
            GUI::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(255, 0, 0, 100));
            GUI::BeginChild("Red", ImVec2(200, 100), true, ImGuiWindowFlags_None);
            for (int n = 0; n < 50; n++)
                GUI::Text("Some test %d", n);
            GUI::EndChild();
            bool child_is_hovered = GUI::IsItemHovered();
            ImVec2 child_rect_min = GUI::GetItemRectMin();
            ImVec2 child_rect_max = GUI::GetItemRectMax();
            GUI::PopStyleColor();
            GUI::Text("Hovered: %d", child_is_hovered);
            GUI::Text("Rect of child window is: (%.0f,%.0f) (%.0f,%.0f)", child_rect_min.x, child_rect_min.y, child_rect_max.x, child_rect_max.y);
        }

        GUI::TreePop();
    }

    if (GUI::TreeNode("Widgets Width"))
    {
        // Use SetNextItemWidth() to set the width of a single upcoming item.
        // Use PushItemWidth()/PopItemWidth() to set the width of a group of items.
        // In real code use you'll probably want to choose width values that are proportional to your font size
        // e.g. Using '20.0f * GetFontSize()' as width instead of '200.0f', etc.

        static float f = 0.0f;
        GUI::Text("SetNextItemWidth/PushItemWidth(100)");
        GUI::SameLine(); HelpMarker("Fixed width.");
        GUI::SetNextItemWidth(100);
        GUI::DragFloat("float##1", &f);

        GUI::Text("SetNextItemWidth/PushItemWidth(GetWindowWidth() * 0.5f)");
        GUI::SameLine(); HelpMarker("Half of window width.");
        GUI::SetNextItemWidth(GUI::GetWindowWidth() * 0.5f);
        GUI::DragFloat("float##2", &f);

        GUI::Text("SetNextItemWidth/PushItemWidth(GetContentRegionAvail().x * 0.5f)");
        GUI::SameLine(); HelpMarker("Half of available width.\n(~ right-cursor_pos)\n(works within a column set)");
        GUI::SetNextItemWidth(GUI::GetContentRegionAvail().x * 0.5f);
        GUI::DragFloat("float##3", &f);

        GUI::Text("SetNextItemWidth/PushItemWidth(-100)");
        GUI::SameLine(); HelpMarker("Align to right edge minus 100");
        GUI::SetNextItemWidth(-100);
        GUI::DragFloat("float##4", &f);

        // Demonstrate using PushItemWidth to surround three items.
        // Calling SetNextItemWidth() before each of them would have the same effect.
        GUI::Text("SetNextItemWidth/PushItemWidth(-1)");
        GUI::SameLine(); HelpMarker("Align to right edge");
        GUI::PushItemWidth(-1);
        GUI::DragFloat("##float5a", &f);
        GUI::DragFloat("##float5b", &f);
        GUI::DragFloat("##float5c", &f);
        GUI::PopItemWidth();

        GUI::TreePop();
    }

    if (GUI::TreeNode("Basic Horizontal Layout"))
    {
        GUI::TextWrapped("(Use GUI::SameLine() to keep adding items to the right of the preceding item)");

        // Text
        GUI::Text("Two items: Hello"); GUI::SameLine();
        GUI::TextColored(ImVec4(1,1,0,1), "Sailor");

        // Adjust spacing
        GUI::Text("More spacing: Hello"); GUI::SameLine(0, 20);
        GUI::TextColored(ImVec4(1,1,0,1), "Sailor");

        // Button
        GUI::AlignTextToFramePadding();
        GUI::Text("Normal buttons"); GUI::SameLine();
        GUI::Button("Banana"); GUI::SameLine();
        GUI::Button("Apple"); GUI::SameLine();
        GUI::Button("Corniflower");

        // Button
        GUI::Text("Small buttons"); GUI::SameLine();
        GUI::SmallButton("Like this one"); GUI::SameLine();
        GUI::Text("can fit within a text block.");

        // Aligned to arbitrary position. Easy/cheap column.
        GUI::Text("Aligned");
        GUI::SameLine(150); GUI::Text("x=150");
        GUI::SameLine(300); GUI::Text("x=300");
        GUI::Text("Aligned");
        GUI::SameLine(150); GUI::SmallButton("x=150");
        GUI::SameLine(300); GUI::SmallButton("x=300");

        // Checkbox
        static bool c1 = false, c2 = false, c3 = false, c4 = false;
        GUI::Checkbox("My", &c1); GUI::SameLine();
        GUI::Checkbox("Tailor", &c2); GUI::SameLine();
        GUI::Checkbox("Is", &c3); GUI::SameLine();
        GUI::Checkbox("Rich", &c4);

        // Various
        static float f0 = 1.0f, f1 = 2.0f, f2 = 3.0f;
        GUI::PushItemWidth(80);
        const char* items[] = { "AAAA", "BBBB", "CCCC", "DDDD" };
        static int item = -1;
        GUI::Combo("Combo", &item, items, IM_ARRAYSIZE(items)); GUI::SameLine();
        GUI::SliderFloat("X", &f0, 0.0f, 5.0f); GUI::SameLine();
        GUI::SliderFloat("Y", &f1, 0.0f, 5.0f); GUI::SameLine();
        GUI::SliderFloat("Z", &f2, 0.0f, 5.0f);
        GUI::PopItemWidth();

        GUI::PushItemWidth(80);
        GUI::Text("Lists:");
        static int selection[4] = { 0, 1, 2, 3 };
        for (int i = 0; i < 4; i++)
        {
            if (i > 0) GUI::SameLine();
            GUI::PushID(i);
            GUI::ListBox("", &selection[i], items, IM_ARRAYSIZE(items));
            GUI::PopID();
            //if (GUI::IsItemHovered()) GUI::SetTooltip("ListBox %d hovered", i);
        }
        GUI::PopItemWidth();

        // Dummy
        ImVec2 button_sz(40, 40);
        GUI::Button("A", button_sz); GUI::SameLine();
        GUI::Dummy(button_sz); GUI::SameLine();
        GUI::Button("B", button_sz);

        // Manually wrapping
        // (we should eventually provide this as an automatic layout feature, but for now you can do it manually)
        GUI::Text("Manually wrapping:");
        imgui_style& style = GUI::GetStyle();
        int buttons_count = 20;
        float window_visible_x2 = GUI::GetWindowPos().x + GUI::GetWindowContentRegionMax().x;
        for (int n = 0; n < buttons_count; n++)
        {
            GUI::PushID(n);
            GUI::Button("Box", button_sz);
            float last_button_x2 = GUI::GetItemRectMax().x;
            float next_button_x2 = last_button_x2 + style.ItemSpacing.x + button_sz.x; // Expected position if next button was on same line
            if (n + 1 < buttons_count && next_button_x2 < window_visible_x2)
                GUI::SameLine();
            GUI::PopID();
        }

        GUI::TreePop();
    }

    if (GUI::TreeNode("Tabs"))
    {
        if (GUI::TreeNode("Basic"))
        {
            ImGuiTabBarFlags tab_bar_flags = ImGuiTabBarFlags_None;
            if (GUI::BeginTabBar("MyTabBar", tab_bar_flags))
            {
                if (GUI::BeginTabItem("Avocado"))
                {
                    GUI::Text("This is the Avocado tab!\nblah blah blah blah blah");
                    GUI::EndTabItem();
                }
                if (GUI::BeginTabItem("Broccoli"))
                {
                    GUI::Text("This is the Broccoli tab!\nblah blah blah blah blah");
                    GUI::EndTabItem();
                }
                if (GUI::BeginTabItem("Cucumber"))
                {
                    GUI::Text("This is the Cucumber tab!\nblah blah blah blah blah");
                    GUI::EndTabItem();
                }
                GUI::EndTabBar();
            }
            GUI::Separator();
            GUI::TreePop();
        }

        if (GUI::TreeNode("Advanced & Close Button"))
        {
            // Expose a couple of the available flags. In most cases you may just call BeginTabBar() with no flags (0).
            static ImGuiTabBarFlags tab_bar_flags = ImGuiTabBarFlags_Reorderable;
            GUI::CheckboxFlags("ImGuiTabBarFlags_Reorderable", (unsigned int*)&tab_bar_flags, ImGuiTabBarFlags_Reorderable);
            GUI::CheckboxFlags("ImGuiTabBarFlags_AutoSelectnew_oneabs", (unsigned int*)&tab_bar_flags, ImGuiTabBarFlags_AutoSelectnew_oneabs);
            GUI::CheckboxFlags("ImGuiTabBarFlags_TabListPopupButton", (unsigned int*)&tab_bar_flags, ImGuiTabBarFlags_TabListPopupButton);
            GUI::CheckboxFlags("ImGuiTabBarFlags_NoCloseWithMiddleMouseButton", (unsigned int*)&tab_bar_flags, ImGuiTabBarFlags_NoCloseWithMiddleMouseButton);
            if ((tab_bar_flags & ImGuiTabBarFlags_FittingPolicyMask_) == 0)
                tab_bar_flags |= ImGuiTabBarFlags_FittingPolicyDefault_;
            if (GUI::CheckboxFlags("ImGuiTabBarFlags_FittingPolicyResizeDown", (unsigned int*)&tab_bar_flags, ImGuiTabBarFlags_FittingPolicyResizeDown))
                tab_bar_flags &= ~(ImGuiTabBarFlags_FittingPolicyMask_ ^ ImGuiTabBarFlags_FittingPolicyResizeDown);
            if (GUI::CheckboxFlags("ImGuiTabBarFlags_FittingPolicyScroll", (unsigned int*)&tab_bar_flags, ImGuiTabBarFlags_FittingPolicyScroll))
                tab_bar_flags &= ~(ImGuiTabBarFlags_FittingPolicyMask_ ^ ImGuiTabBarFlags_FittingPolicyScroll);

            // Tab Bar
            const char* names[4] = { "Artichoke", "Beetroot", "Celery", "Daikon" };
            static bool opened[4] = { true, true, true, true }; // Persistent user state
            for (int n = 0; n < IM_ARRAYSIZE(opened); n++)
            {
                if (n > 0) { GUI::SameLine(); }
                GUI::Checkbox(names[n], &opened[n]);
            }

            // Passing a bool* to BeginTabItem() is similar to passing one to Begin():
            // the underlying bool will be set to false when the tab is closed.
            if (GUI::BeginTabBar("MyTabBar", tab_bar_flags))
            {
                for (int n = 0; n < IM_ARRAYSIZE(opened); n++)
                    if (opened[n] && GUI::BeginTabItem(names[n], &opened[n], ImGuiTabItemFlags_None))
                    {
                        GUI::Text("This is the %s tab!", names[n]);
                        if (n & 1)
                            GUI::Text("I am an odd tab.");
                        GUI::EndTabItem();
                    }
                GUI::EndTabBar();
            }
            GUI::Separator();
            GUI::TreePop();
        }
        GUI::TreePop();
    }

    if (GUI::TreeNode("Groups"))
    {
        HelpMarker(
            "BeginGroup() basically locks the horizontal position for new line. "
            "EndGroup() bundles the whole group so that you can use \"item\" functions such as "
            "IsItemHovered()/IsItemActive() or SameLine() etc. on the whole group.");
        GUI::BeginGroup();
        {
            GUI::BeginGroup();
            GUI::Button("AAA");
            GUI::SameLine();
            GUI::Button("BBB");
            GUI::SameLine();
            GUI::BeginGroup();
            GUI::Button("CCC");
            GUI::Button("DDD");
            GUI::EndGroup();
            GUI::SameLine();
            GUI::Button("EEE");
            GUI::EndGroup();
            if (GUI::IsItemHovered())
                GUI::SetTooltip("First group hovered");
        }
        // Capture the group size and create widgets using the same size
        ImVec2 size = GUI::GetItemRectSize();
        const float values[5] = { 0.5f, 0.20f, 0.80f, 0.60f, 0.25f };
        GUI::PlotHistogram("##values", values, IM_ARRAYSIZE(values), 0, NULL, 0.0f, 1.0f, size);

        GUI::Button("ACTION", ImVec2((size.x - GUI::GetStyle().ItemSpacing.x) * 0.5f, size.y));
        GUI::SameLine();
        GUI::Button("REACTION", ImVec2((size.x - GUI::GetStyle().ItemSpacing.x) * 0.5f, size.y));
        GUI::EndGroup();
        GUI::SameLine();

        GUI::Button("LEVERAGE\nBUZZWORD", size);
        GUI::SameLine();

        if (GUI::ListBoxHeader("List", size))
        {
            GUI::Selectable("Selected", true);
            GUI::Selectable("Not Selected", false);
            GUI::ListBoxFooter();
        }

        GUI::TreePop();
    }

    if (GUI::TreeNode("Text Baseline Alignment"))
    {
        {
            GUI::BulletText("Text baseline:");
            GUI::SameLine(); HelpMarker(
                "This is testing the vertical alignment that gets applied on text to keep it aligned with widgets. "
                "Lines only composed of text or \"small\" widgets use less vertical space than lines with framed widgets.");
            GUI::Indent();

            GUI::Text("KO Blahblah"); GUI::SameLine();
            GUI::Button("Some framed item"); GUI::SameLine();
            HelpMarker("Baseline of button will look misaligned with text..");

            // If your line starts with text, call AlignTextToFramePadding() to align text to upcoming widgets.
            // (because we don't know what's coming after the Text() statement, we need to move the text baseline
            // down by FramePadding.y ahead of time)
            GUI::AlignTextToFramePadding();
            GUI::Text("OK Blahblah"); GUI::SameLine();
            GUI::Button("Some framed item"); GUI::SameLine();
            HelpMarker("We call AlignTextToFramePadding() to vertically align the text baseline by +FramePadding.y");

            // SmallButton() uses the same vertical padding as Text
            GUI::Button("TEST##1"); GUI::SameLine();
            GUI::Text("TEST"); GUI::SameLine();
            GUI::SmallButton("TEST##2");

            // If your line starts with text, call AlignTextToFramePadding() to align text to upcoming widgets.
            GUI::AlignTextToFramePadding();
            GUI::Text("Text aligned to framed item"); GUI::SameLine();
            GUI::Button("Item##1"); GUI::SameLine();
            GUI::Text("Item"); GUI::SameLine();
            GUI::SmallButton("Item##2"); GUI::SameLine();
            GUI::Button("Item##3");

            GUI::Unindent();
        }

        GUI::Spacing();

        {
            GUI::BulletText("Multi-line text:");
            GUI::Indent();
            GUI::Text("One\nTwo\nThree"); GUI::SameLine();
            GUI::Text("Hello\nWorld"); GUI::SameLine();
            GUI::Text("Banana");

            GUI::Text("Banana"); GUI::SameLine();
            GUI::Text("Hello\nWorld"); GUI::SameLine();
            GUI::Text("One\nTwo\nThree");

            GUI::Button("HOP##1"); GUI::SameLine();
            GUI::Text("Banana"); GUI::SameLine();
            GUI::Text("Hello\nWorld"); GUI::SameLine();
            GUI::Text("Banana");

            GUI::Button("HOP##2"); GUI::SameLine();
            GUI::Text("Hello\nWorld"); GUI::SameLine();
            GUI::Text("Banana");
            GUI::Unindent();
        }

        GUI::Spacing();

        {
            GUI::BulletText("Misc items:");
            GUI::Indent();

            // SmallButton() sets FramePadding to zero. Text baseline is aligned to match baseline of previous Button.
            GUI::Button("80x80", ImVec2(80, 80));
            GUI::SameLine();
            GUI::Button("50x50", ImVec2(50, 50));
            GUI::SameLine();
            GUI::Button("Button()");
            GUI::SameLine();
            GUI::SmallButton("SmallButton()");

            // Tree
            const float spacing = GUI::GetStyle().ItemInnerSpacing.x;
            GUI::Button("Button##1");
            GUI::SameLine(0.0f, spacing);
            if (GUI::TreeNode("Node##1"))
            {
                // Placeholder tree data
                for (int i = 0; i < 6; i++)
                    GUI::BulletText("Item %d..", i);
                GUI::TreePop();
            }

            // Vertically align text node a bit lower so it'll be vertically centered with upcoming widget.
            // Otherwise you can use SmallButton() (smaller fit).
            GUI::AlignTextToFramePadding();

            // Common mistake to avoid: if we want to SameLine after TreeNode we need to do it before we add
            // other contents below the node.
            bool node_open = GUI::TreeNode("Node##2");
            GUI::SameLine(0.0f, spacing); GUI::Button("Button##2");
            if (node_open)
            {
                // Placeholder tree data
                for (int i = 0; i < 6; i++)
                    GUI::BulletText("Item %d..", i);
                GUI::TreePop();
            }

            // Bullet
            GUI::Button("Button##3");
            GUI::SameLine(0.0f, spacing);
            GUI::BulletText("Bullet text");

            GUI::AlignTextToFramePadding();
            GUI::BulletText("Node");
            GUI::SameLine(0.0f, spacing); GUI::Button("Button##4");
            GUI::Unindent();
        }

        GUI::TreePop();
    }

    if (GUI::TreeNode("Scrolling"))
    {
        // Vertical scroll functions
        HelpMarker("Use SetScrollHereY() or SetScrollFromPosY() to scroll to a given vertical position.");

        static int track_item = 50;
        static bool enable_track = true;
        static bool enable_extra_decorations = false;
        static float scroll_to_off_px = 0.0f;
        static float scroll_to_pos_px = 200.0f;

        GUI::Checkbox("Decoration", &enable_extra_decorations);

        GUI::Checkbox("Track", &enable_track);
        GUI::PushItemWidth(100);
        GUI::SameLine(140); enable_track |= GUI::DragInt("##item", &track_item, 0.25f, 0, 99, "Item = %d");

        bool scroll_to_off = GUI::Button("Scroll Offset");
        GUI::SameLine(140); scroll_to_off |= GUI::DragFloat("##off", &scroll_to_off_px, 1.00f, 0, FLT_MAX, "+%.0f px");

        bool scroll_to_pos = GUI::Button("Scroll To Pos");
        GUI::SameLine(140); scroll_to_pos |= GUI::DragFloat("##pos", &scroll_to_pos_px, 1.00f, -10, FLT_MAX, "X/Y = %.0f px");
        GUI::PopItemWidth();

        if (scroll_to_off || scroll_to_pos)
            enable_track = false;

        imgui_style& style = GUI::GetStyle();
        float child_w = (GUI::GetContentRegionAvail().x - 4 * style.ItemSpacing.x) / 5;
        if (child_w < 1.0f)
            child_w = 1.0f;
        GUI::PushID("##VerticalScrolling");
        for (int i = 0; i < 5; i++)
        {
            if (i > 0) GUI::SameLine();
            GUI::BeginGroup();
            const char* names[] = { "Top", "25%", "Center", "75%", "Bottom" };
            GUI::TextUnformatted(names[i]);

            const ImGuiWindowFlags child_flags = enable_extra_decorations ? ImGuiWindowFlags_MenuBar : 0;
            const ImGuiID child_id = GUI::GetID((void*)(intptr_t)i);
            const bool child_is_visible = GUI::BeginChild(child_id, ImVec2(child_w, 200.0f), true, child_flags);
            if (GUI::BeginMenuBar())
            {
                GUI::TextUnformatted("abc");
                GUI::EndMenuBar();
            }
            if (scroll_to_off)
                GUI::SetScrollY(scroll_to_off_px);
            if (scroll_to_pos)
                GUI::SetScrollFromPosY(GUI::GetCursorStartPos().y + scroll_to_pos_px, i * 0.25f);
            if (child_is_visible) // Avoid calling SetScrollHereY when running with culled items
            {
                for (int item = 0; item < 100; item++)
                {
                    if (enable_track && item == track_item)
                    {
                        GUI::TextColored(ImVec4(1, 1, 0, 1), "Item %d", item);
                        GUI::SetScrollHereY(i * 0.25f); // 0.0f:top, 0.5f:center, 1.0f:bottom
                    }
                    else
                    {
                        GUI::Text("Item %d", item);
                    }
                }
            }
            float scroll_y = GUI::GetScrollY();
            float scroll_max_y = GUI::GetScrollMaxY();
            GUI::EndChild();
            GUI::Text("%.0f/%.0f", scroll_y, scroll_max_y);
            GUI::EndGroup();
        }
        GUI::PopID();

        // Horizontal scroll functions
        GUI::Spacing();
        HelpMarker(
            "Use SetScrollHereX() or SetScrollFromPosX() to scroll to a given horizontal position.\n\n"
            "Because the clipping rectangle of most window hides half worth of WindowPadding on the "
            "left/right, using SetScrollFromPosX(+1) will usually result in clipped text whereas the "
            "equivalent SetScrollFromPosY(+1) wouldn't.");
        GUI::PushID("##HorizontalScrolling");
        for (int i = 0; i < 5; i++)
        {
            float child_height = GUI::GetTextLineHeight() + style.ScrollbarSize + style.WindowPadding.y * 2.0f;
            ImGuiWindowFlags child_flags = ImGuiWindowFlags_HorizontalScrollbar | (enable_extra_decorations ? ImGuiWindowFlags_AlwaysVerticalScrollbar : 0);
            ImGuiID child_id = GUI::GetID((void*)(intptr_t)i);
            bool child_is_visible = GUI::BeginChild(child_id, ImVec2(-100, child_height), true, child_flags);
            if (scroll_to_off)
                GUI::SetScrollX(scroll_to_off_px);
            if (scroll_to_pos)
                GUI::SetScrollFromPosX(GUI::GetCursorStartPos().x + scroll_to_pos_px, i * 0.25f);
            if (child_is_visible) // Avoid calling SetScrollHereY when running with culled items
            {
                for (int item = 0; item < 100; item++)
                {
                    if (enable_track && item == track_item)
                    {
                        GUI::TextColored(ImVec4(1, 1, 0, 1), "Item %d", item);
                        GUI::SetScrollHereX(i * 0.25f); // 0.0f:left, 0.5f:center, 1.0f:right
                    }
                    else
                    {
                        GUI::Text("Item %d", item);
                    }
                    GUI::SameLine();
                }
            }
            float scroll_x = GUI::GetScrollX();
            float scroll_max_x = GUI::GetScrollMaxX();
            GUI::EndChild();
            GUI::SameLine();
            const char* names[] = { "Left", "25%", "Center", "75%", "Right" };
            GUI::Text("%s\n%.0f/%.0f", names[i], scroll_x, scroll_max_x);
            GUI::Spacing();
        }
        GUI::PopID();

        // Miscellaneous Horizontal Scrolling Demo
        HelpMarker(
            "Horizontal scrolling for a window is enabled via the ImGuiWindowFlags_HorizontalScrollbar flag.\n\n"
            "You may want to also explicitly specify content width by using SetNextWindowContentWidth() before Begin().");
        static int lines = 7;
        GUI::SliderInt("Lines", &lines, 1, 15);
        GUI::PushStyleVar(imgui_styleVar_FrameRounding, 3.0f);
        GUI::PushStyleVar(imgui_styleVar_FramePadding, ImVec2(2.0f, 1.0f));
        ImVec2 scrolling_child_size = ImVec2(0, GUI::GetFrameHeightWithSpacing() * 7 + 30);
        GUI::BeginChild("scrolling", scrolling_child_size, true, ImGuiWindowFlags_HorizontalScrollbar);
        for (int line = 0; line < lines; line++)
        {
            // Display random stuff. For the sake of this trivial demo we are using basic Button() + SameLine()
            // If you want to create your own time line for a real application you may be better off manipulating
            // the cursor position yourself, aka using SetCursorPos/SetCursorScreenPos to position the widgets
            // yourself. You may also want to use the lower-level imgui_draw_list API.
            int num_buttons = 10 + ((line & 1) ? line * 9 : line * 3);
            for (int n = 0; n < num_buttons; n++)
            {
                if (n > 0) GUI::SameLine();
                GUI::PushID(n + line * 1000);
                char num_buf[16];
                sprintf(num_buf, "%d", n);
                const char* label = (!(n % 15)) ? "FizzBuzz" : (!(n % 3)) ? "Fizz" : (!(n % 5)) ? "Buzz" : num_buf;
                float hue = n * 0.05f;
                GUI::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::HSV(hue, 0.6f, 0.6f));
                GUI::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::HSV(hue, 0.7f, 0.7f));
                GUI::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::HSV(hue, 0.8f, 0.8f));
                GUI::Button(label, ImVec2(40.0f + sinf((float)(line + n)) * 20.0f, 0.0f));
                GUI::PopStyleColor(3);
                GUI::PopID();
            }
        }
        float scroll_x = GUI::GetScrollX();
        float scroll_max_x = GUI::GetScrollMaxX();
        GUI::EndChild();
        GUI::PopStyleVar(2);
        float scroll_x_delta = 0.0f;
        GUI::SmallButton("<<");
        if (GUI::IsItemActive())
            scroll_x_delta = -GUI::GetIO().DeltaTime * 1000.0f;
        GUI::SameLine();
        GUI::Text("Scroll from code"); GUI::SameLine();
        GUI::SmallButton(">>");
        if (GUI::IsItemActive())
            scroll_x_delta = +GUI::GetIO().DeltaTime * 1000.0f;
        GUI::SameLine();
        GUI::Text("%.0f/%.0f", scroll_x, scroll_max_x);
        if (scroll_x_delta != 0.0f)
        {
            // Demonstrate a trick: you can use Begin to set yourself in the context of another window
            // (here we are already out of your child window)
            GUI::BeginChild("scrolling");
            GUI::SetScrollX(GUI::GetScrollX() + scroll_x_delta);
            GUI::EndChild();
        }
        GUI::Spacing();

        static bool show_horizontal_contents_size_demo_window = false;
        GUI::Checkbox("Show Horizontal contents size demo window", &show_horizontal_contents_size_demo_window);

        if (show_horizontal_contents_size_demo_window)
        {
            static bool show_h_scrollbar = true;
            static bool show_button = true;
            static bool show_tree_nodes = true;
            static bool show_text_wrapped = false;
            static bool show_columns = true;
            static bool show_tab_bar = true;
            static bool show_child = false;
            static bool explicit_content_size = false;
            static float contents_size_x = 300.0f;
            if (explicit_content_size)
                GUI::SetNextWindowContentSize(ImVec2(contents_size_x, 0.0f));
            GUI::Begin("Horizontal contents size demo window", &show_horizontal_contents_size_demo_window, show_h_scrollbar ? ImGuiWindowFlags_HorizontalScrollbar : 0);
            GUI::PushStyleVar(imgui_styleVar_ItemSpacing, ImVec2(2, 0));
            GUI::PushStyleVar(imgui_styleVar_FramePadding, ImVec2(2, 0));
            HelpMarker("Test of different widgets react and impact the work rectangle growing when horizontal scrolling is enabled.\n\nUse 'Metrics->Tools->Show windows rectangles' to visualize rectangles.");
            GUI::Checkbox("H-scrollbar", &show_h_scrollbar);
            GUI::Checkbox("Button", &show_button);            // Will grow contents size (unless explicitly overwritten)
            GUI::Checkbox("Tree nodes", &show_tree_nodes);    // Will grow contents size and display highlight over full width
            GUI::Checkbox("Text wrapped", &show_text_wrapped);// Will grow and use contents size
            GUI::Checkbox("Columns", &show_columns);          // Will use contents size
            GUI::Checkbox("Tab bar", &show_tab_bar);          // Will use contents size
            GUI::Checkbox("Child", &show_child);              // Will grow and use contents size
            GUI::Checkbox("Explicit content size", &explicit_content_size);
            GUI::Text("Scroll %.1f/%.1f %.1f/%.1f", GUI::GetScrollX(), GUI::GetScrollMaxX(), GUI::GetScrollY(), GUI::GetScrollMaxY());
            if (explicit_content_size)
            {
                GUI::SameLine();
                GUI::SetNextItemWidth(100);
                GUI::DragFloat("##csx", &contents_size_x);
                ImVec2 p = GUI::GetCursorScreenPos();
                GUI::GetWindowDrawList()->AddRectFilled(p, ImVec2(p.x + 10, p.y + 10), IM_COL32_WHITE);
                GUI::GetWindowDrawList()->AddRectFilled(ImVec2(p.x + contents_size_x - 10, p.y), ImVec2(p.x + contents_size_x, p.y + 10), IM_COL32_WHITE);
                GUI::Dummy(ImVec2(0, 10));
            }
            GUI::PopStyleVar(2);
            GUI::Separator();
            if (show_button)
            {
                GUI::Button("this is a 300-wide button", ImVec2(300, 0));
            }
            if (show_tree_nodes)
            {
                bool open = true;
                if (GUI::TreeNode("this is a tree node"))
                {
                    if (GUI::TreeNode("another one of those tree node..."))
                    {
                        GUI::Text("Some tree contents");
                        GUI::TreePop();
                    }
                    GUI::TreePop();
                }
                GUI::CollapsingHeader("CollapsingHeader", &open);
            }
            if (show_text_wrapped)
            {
                GUI::TextWrapped("This text should automatically wrap on the edge of the work rectangle.");
            }
            if (show_columns)
            {
                GUI::Columns(4);
                for (int n = 0; n < 4; n++)
                {
                    GUI::Text("Width %.2f", GUI::GetColumwidth());
                    GUI::NextColumn();
                }
                GUI::Columns(1);
            }
            if (show_tab_bar && GUI::BeginTabBar("Hello"))
            {
                if (GUI::BeginTabItem("OneOneOne")) { GUI::EndTabItem(); }
                if (GUI::BeginTabItem("TwoTwoTwo")) { GUI::EndTabItem(); }
                if (GUI::BeginTabItem("ThreeThreeThree")) { GUI::EndTabItem(); }
                if (GUI::BeginTabItem("FourFourFour")) { GUI::EndTabItem(); }
                GUI::EndTabBar();
            }
            if (show_child)
            {
                GUI::BeginChild("child", ImVec2(0, 0), true);
                GUI::EndChild();
            }
            GUI::End();
        }

        GUI::TreePop();
    }

    if (GUI::TreeNode("Clipping"))
    {
        static ImVec2 size(100.0f, 100.0f);
        static ImVec2 offset(30.0f, 30.0f);
        GUI::DragFloat2("size", (float*)&size, 0.5f, 1.0f, 200.0f, "%.0f");
        GUI::TextWrapped("(Click and drag to scroll)");

        for (int n = 0; n < 3; n++)
        {
            if (n > 0)
                GUI::SameLine();
            GUI::PushID(n);
            GUI::BeginGroup(); // Lock X position

            GUI::InvisibleButton("##empty", size);
            if (GUI::IsItemActive() && GUI::IsMouseDragging(ImGuiMouseButton_Left))
            {
                offset.x += GUI::GetIO().MouseDelta.x;
                offset.y += GUI::GetIO().MouseDelta.y;
            }
            const ImVec2 p0 = GUI::GetItemRectMin();
            const ImVec2 p1 = GUI::GetItemRectMax();
            const char* text_str = "Line 1 hello\nLine 2 clip me!";
            const ImVec2 text_pos = ImVec2(p0.x + offset.x, p0.y + offset.y);
            imgui_draw_list* draw_list = GUI::GetWindowDrawList();

            switch (n)
            {
            case 0:
                HelpMarker(
                    "Using GUI::PushClipRect():\n"
                    "Will alter ImGui hit-testing logic + imgui_draw_list rendering.\n"
                    "(use this if you want your clipping rectangle to affect interactions)");
                GUI::PushClipRect(p0, p1, true);
                draw_list->AddRectFilled(p0, p1, IM_COL32(90, 90, 120, 255));
                draw_list->AddText(text_pos, IM_COL32_WHITE, text_str);
                GUI::PopClipRect();
                break;
            case 1:
                HelpMarker(
                    "Using imgui_draw_list::PushClipRect():\n"
                    "Will alter imgui_draw_list rendering only.\n"
                    "(use this as a shortcut if you are only using imgui_draw_list calls)");
                draw_list->PushClipRect(p0, p1, true);
                draw_list->AddRectFilled(p0, p1, IM_COL32(90, 90, 120, 255));
                draw_list->AddText(text_pos, IM_COL32_WHITE, text_str);
                draw_list->PopClipRect();
                break;
            case 2:
                HelpMarker(
                    "Using imgui_draw_list::AddText() with a fine ClipRect:\n"
                    "Will alter only this specific imgui_draw_list::AddText() rendering.\n"
                    "(this is often used internally to avoid altering the clipping rectangle and minimize draw calls)");
                ImVec4 clip_rect(p0.x, p0.y, p1.x, p1.y); // AddText() takes a ImVec4* here so let's convert.
                draw_list->AddRectFilled(p0, p1, IM_COL32(90, 90, 120, 255));
                draw_list->AddText(GUI::GetFont(), GUI::GetFontSize(), text_pos, IM_COL32_WHITE, text_str, NULL, 0.0f, &clip_rect);
                break;
            }
            GUI::EndGroup();
            GUI::PopID();
        }

        GUI::TreePop();
    }
}

static void ShowDemoWindowPopups()
{
    if (!GUI::CollapsingHeader("Popups & Modal windows"))
        return;

    // The properties of popups windows are:
    // - They block normal mouse hovering detection outside them. (*)
    // - Unless modal, they can be closed by clicking anywhere outside them, or by pressing ESCAPE.
    // - Their visibility state (~bool) is held internally by Dear ImGui instead of being held by the programmer as
    //   we are used to with regular Begin() calls. User can manipulate the visibility state by calling OpenPopup().
    // (*) One can use IsItemHovered(ImGuiHoveredFlags_AllowWhenBlockedByPopup) to bypass it and detect hovering even
    //     when normally blocked by a popup.
    // Those three properties are connected. The library needs to hold their visibility state BECAUSE it can close
    // popups at any time.

    // Typical use for regular windows:
    //   bool my_tool_is_active = false; if (GUI::Button("Open")) my_tool_is_active = true; [...] if (my_tool_is_active) Begin("My Tool", &my_tool_is_active) { [...] } End();
    // Typical use for popups:
    //   if (GUI::Button("Open")) GUI::OpenPopup("MyPopup"); if (GUI::BeginPopup("MyPopup") { [...] EndPopup(); }

    // With popups we have to go through a library call (here OpenPopup) to manipulate the visibility state.
    // This may be a bit confusing at first but it should quickly make sense. Follow on the examples below.

    if (GUI::TreeNode("Popups"))
    {
        GUI::TextWrapped(
            "When a popup is active, it inhibits interacting with windows that are behind the popup. "
            "Clicking outside the popup closes it.");

        static int selected_fish = -1;
        const char* names[] = { "Bream", "Haddock", "Mackerel", "Pollock", "Tilefish" };
        static bool toggles[] = { true, false, false, false, false };

        // Simple selection popup (if you want to show the current selection inside the Button itself,
        // you may want to build a string using the "###" operator to preserve a constant ID with a variable label)
        if (GUI::Button("Select.."))
            GUI::OpenPopup("my_select_popup");
        GUI::SameLine();
        GUI::TextUnformatted(selected_fish == -1 ? "<None>" : names[selected_fish]);
        if (GUI::BeginPopup("my_select_popup"))
        {
            GUI::Text("Aquarium");
            GUI::Separator();
            for (int i = 0; i < IM_ARRAYSIZE(names); i++)
                if (GUI::Selectable(names[i]))
                    selected_fish = i;
            GUI::EndPopup();
        }

        // Showing a menu with toggles
        if (GUI::Button("Toggle.."))
            GUI::OpenPopup("my_toggle_popup");
        if (GUI::BeginPopup("my_toggle_popup"))
        {
            for (int i = 0; i < IM_ARRAYSIZE(names); i++)
                GUI::MenuItem(names[i], "", &toggles[i]);
            if (GUI::BeginMenu("Sub-menu"))
            {
                GUI::MenuItem("Click me");
                GUI::EndMenu();
            }

            GUI::Separator();
            GUI::Text("Tooltip here");
            if (GUI::IsItemHovered())
                GUI::SetTooltip("I am a tooltip over a popup");

            if (GUI::Button("Stacked Popup"))
                GUI::OpenPopup("another popup");
            if (GUI::BeginPopup("another popup"))
            {
                for (int i = 0; i < IM_ARRAYSIZE(names); i++)
                    GUI::MenuItem(names[i], "", &toggles[i]);
                if (GUI::BeginMenu("Sub-menu"))
                {
                    GUI::MenuItem("Click me");
                    if (GUI::Button("Stacked Popup"))
                        GUI::OpenPopup("another popup");
                    if (GUI::BeginPopup("another popup"))
                    {
                        GUI::Text("I am the last one here.");
                        GUI::EndPopup();
                    }
                    GUI::EndMenu();
                }
                GUI::EndPopup();
            }
            GUI::EndPopup();
        }

        // Call the more complete ShowExampleMenuFile which we use in various places of this demo
        if (GUI::Button("File Menu.."))
            GUI::OpenPopup("my_file_popup");
        if (GUI::BeginPopup("my_file_popup"))
        {
            ShowExampleMenuFile();
            GUI::EndPopup();
        }

        GUI::TreePop();
    }

    if (GUI::TreeNode("Context menus"))
    {
        // BeginPopupContextItem() is a helper to provide common/simple popup behavior of essentially doing:
        //    if (IsItemHovered() && IsMouseReleased(ImGuiMouseButton_Right))
        //       OpenPopup(id);
        //    return BeginPopup(id);
        // For more advanced uses you may want to replicate and customize this code.
        // See details in BeginPopupContextItem().
        static float value = 0.5f;
        GUI::Text("Value = %.3f (<-- right-click here)", value);
        if (GUI::BeginPopupContextItem("item context menu"))
        {
            if (GUI::Selectable("Set to zero")) value = 0.0f;
            if (GUI::Selectable("Set to PI")) value = 3.1415f;
            GUI::SetNextItemWidth(-1);
            GUI::DragFloat("##Value", &value, 0.1f, 0.0f, 0.0f);
            GUI::EndPopup();
        }

        // We can also use OpenPopupContextItem() which is the same as BeginPopupContextItem() but without the
        // Begin() call. So here we will make it that clicking on the text field with the right mouse button (1)
        // will toggle the visibility of the popup above.
        GUI::Text("(You can also right-click me to open the same popup as above.)");
        GUI::OpenPopupContextItem("item context menu", 1);

        // When used after an item that has an ID (e.g.Button), we can skip providing an ID to BeginPopupContextItem().
        // BeginPopupContextItem() will use the last item ID as the popup ID.
        // In addition here, we want to include your editable label inside the button label.
        // We use the ### operator to override the ID (read FAQ about ID for details)
        static char name[32] = "Label1";
        char buf[64];
        sprintf(buf, "Button: %s###Button", name); // ### operator override ID ignoring the preceding label
        GUI::Button(buf);
        if (GUI::BeginPopupContextItem())
        {
            GUI::Text("Edit name:");
            GUI::InputText("##edit", name, IM_ARRAYSIZE(name));
            if (GUI::Button("Close"))
                GUI::CloseCurrentPopup();
            GUI::EndPopup();
        }
        GUI::SameLine(); GUI::Text("(<-- right-click here)");

        GUI::TreePop();
    }

    if (GUI::TreeNode("Modals"))
    {
        GUI::TextWrapped("Modal windows are like popups but the user cannot close them by clicking outside.");

        if (GUI::Button("Delete.."))
            GUI::OpenPopup("Delete?");

        // Always center this window when appearing
        ImVec2 center = GUI::GetMainViewport()->GetCenter();
        //ImVec2 parent_pos = GUI::GetWindowPos();
        //ImVec2 parent_size = GUI::GetWindowSize();
        //ImVec2 center(parent_pos.x + parent_size.x * 0.5f, parent_pos.y + parent_size.y * 0.5f);
        GUI::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));

        if (GUI::BeginPopupModal("Delete?", NULL, ImGuiWindowFlags_AlwaysAutoResize))
        {
            GUI::Text("All those beautiful files will be deleted.\nThis operation cannot be undone!\n\n");
            GUI::Separator();

            //static int unused_i = 0;
            //GUI::Combo("Combo", &unused_i, "Delete\0Delete harder\0");

            static bool dont_ask_me_next_time = false;
            GUI::PushStyleVar(imgui_styleVar_FramePadding, ImVec2(0, 0));
            GUI::Checkbox("Don't ask me next time", &dont_ask_me_next_time);
            GUI::PopStyleVar();

            if (GUI::Button("OK", ImVec2(120, 0))) { GUI::CloseCurrentPopup(); }
            GUI::SetItemDefaultFocus();
            GUI::SameLine();
            if (GUI::Button("Cancel", ImVec2(120, 0))) { GUI::CloseCurrentPopup(); }
            GUI::EndPopup();
        }

        if (GUI::Button("Stacked modals.."))
            GUI::OpenPopup("Stacked 1");
        if (GUI::BeginPopupModal("Stacked 1", NULL, ImGuiWindowFlags_MenuBar))
        {
            if (GUI::BeginMenuBar())
            {
                if (GUI::BeginMenu("File"))
                {
                    if (GUI::MenuItem("Some menu item")) {}
                    GUI::EndMenu();
                }
                GUI::EndMenuBar();
            }
            GUI::Text("Hello from Stacked The First\nUsing style.Colors[ImGuiCol_ModalWindowDimBg] behind it.");

            // Testing behavior of widgets stacking their own regular popups over the modal.
            static int item = 1;
            static float color[4] = { 0.4f, 0.7f, 0.0f, 0.5f };
            GUI::Combo("Combo", &item, "aaaa\0bbbb\0cccc\0dddd\0eeee\0\0");
            GUI::ColorEdit4("color", color);

            if (GUI::Button("Add another modal.."))
                GUI::OpenPopup("Stacked 2");

            // Also demonstrate passing a bool* to BeginPopupModal(), this will create a regular close button which
            // will close the popup. Note that the visibility state of popups is owned by imgui, so the input value
            // of the bool actually doesn't matter here.
            bool unused_open = true;
            if (GUI::BeginPopupModal("Stacked 2", &unused_open))
            {
                GUI::Text("Hello from Stacked The Second!");
                if (GUI::Button("Close"))
                    GUI::CloseCurrentPopup();
                GUI::EndPopup();
            }

            if (GUI::Button("Close"))
                GUI::CloseCurrentPopup();
            GUI::EndPopup();
        }

        GUI::TreePop();
    }

    if (GUI::TreeNode("Menus inside a regular window"))
    {
        GUI::TextWrapped("Below we are testing adding menu items to a regular window. It's rather unusual but should work!");
        GUI::Separator();

        // Note: As a quirk in this very specific example, we want to differentiate the parent of this menu from the
        // parent of the various popup menus above. To do so we are encloding the items in a PushID()/PopID() block
        // to make them two different menusets. If we don't, opening any popup above and hovering our menu here would
        // open it. This is because once a menu is active, we allow to switch to a sibling menu by just hovering on it,
        // which is the desired behavior for regular menus.
        GUI::PushID("foo");
        GUI::MenuItem("Menu item", "CTRL+M");
        if (GUI::BeginMenu("Menu inside a regular window"))
        {
            ShowExampleMenuFile();
            GUI::EndMenu();
        }
        GUI::PopID();
        GUI::Separator();
        GUI::TreePop();
    }
}

static void ShowDemoWindowColumns()
{
    if (!GUI::CollapsingHeader("Columns"))
        return;

    GUI::PushID("Columns");

    static bool disable_indent = false;
    GUI::Checkbox("Disable tree indentation", &disable_indent);
    GUI::SameLine();
    HelpMarker("Disable the indenting of tree nodes so demo columns can use the full window width.");
    if (disable_indent)
        GUI::PushStyleVar(imgui_styleVar_IndentSpacing, 0.0f);

    // Basic columns
    if (GUI::TreeNode("Basic"))
    {
        GUI::Text("Without border:");
        GUI::Columns(3, "mycolumns3", false);  // 3-ways, no border
        GUI::Separator();
        for (int n = 0; n < 14; n++)
        {
            char label[32];
            sprintf(label, "Item %d", n);
            if (GUI::Selectable(label)) {}
            //if (GUI::Button(label, ImVec2(-FLT_MIN,0.0f))) {}
            GUI::NextColumn();
        }
        GUI::Columns(1);
        GUI::Separator();

        GUI::Text("With border:");
        GUI::Columns(4, "mycolumns"); // 4-ways, with border
        GUI::Separator();
        GUI::Text("ID"); GUI::NextColumn();
        GUI::Text("Name"); GUI::NextColumn();
        GUI::Text("Path"); GUI::NextColumn();
        GUI::Text("Hovered"); GUI::NextColumn();
        GUI::Separator();
        const char* names[3] = { "One", "Two", "Three" };
        const char* paths[3] = { "/path/one", "/path/two", "/path/three" };
        static int selected = -1;
        for (int i = 0; i < 3; i++)
        {
            char label[32];
            sprintf(label, "%04d", i);
            if (GUI::Selectable(label, selected == i, ImGuiSelectableFlags_SpanAllColumns))
                selected = i;
            bool hovered = GUI::IsItemHovered();
            GUI::NextColumn();
            GUI::Text(names[i]); GUI::NextColumn();
            GUI::Text(paths[i]); GUI::NextColumn();
            GUI::Text("%d", hovered); GUI::NextColumn();
        }
        GUI::Columns(1);
        GUI::Separator();
        GUI::TreePop();
    }

    if (GUI::TreeNode("Borders"))
    {
        // NB: Future columns API should allow automatic horizontal borders.
        static bool h_borders = true;
        static bool v_borders = true;
        static int columns_count = 4;
        const int lines_count = 3;
        GUI::SetNextItemWidth(GUI::GetFontSize() * 8);
        GUI::DragInt("##columns_count", &columns_count, 0.1f, 2, 10, "%d columns");
        if (columns_count < 2)
            columns_count = 2;
        GUI::SameLine();
        GUI::Checkbox("horizontal", &h_borders);
        GUI::SameLine();
        GUI::Checkbox("vertical", &v_borders);
        GUI::Columns(columns_count, NULL, v_borders);
        for (int i = 0; i < columns_count * lines_count; i++)
        {
            if (h_borders && GUI::GetColumnIndex() == 0)
                GUI::Separator();
            GUI::Text("%c%c%c", 'a' + i, 'a' + i, 'a' + i);
            GUI::Text("Width %.2f", GUI::GetColumwidth());
            GUI::Text("Avail %.2f", GUI::GetContentRegionAvail().x);
            GUI::Text("Offset %.2f", GUI::GetColumnOffset());
            GUI::Text("Long text that is likely to clip");
            GUI::Button("Button", ImVec2(-FLT_MIN, 0.0f));
            GUI::NextColumn();
        }
        GUI::Columns(1);
        if (h_borders)
            GUI::Separator();
        GUI::TreePop();
    }

    // Create multiple items in a same cell before switching to next column
    if (GUI::TreeNode("Mixed items"))
    {
        GUI::Columns(3, "mixed");
        GUI::Separator();

        GUI::Text("Hello");
        GUI::Button("Banana");
        GUI::NextColumn();

        GUI::Text("ImGui");
        GUI::Button("Apple");
        static float foo = 1.0f;
        GUI::InputFloat("red", &foo, 0.05f, 0, "%.3f");
        GUI::Text("An extra line here.");
        GUI::NextColumn();

        GUI::Text("Sailor");
        GUI::Button("Corniflower");
        static float bar = 1.0f;
        GUI::InputFloat("blue", &bar, 0.05f, 0, "%.3f");
        GUI::NextColumn();

        if (GUI::CollapsingHeader("Category A")) { GUI::Text("Blah blah blah"); } GUI::NextColumn();
        if (GUI::CollapsingHeader("Category B")) { GUI::Text("Blah blah blah"); } GUI::NextColumn();
        if (GUI::CollapsingHeader("Category C")) { GUI::Text("Blah blah blah"); } GUI::NextColumn();
        GUI::Columns(1);
        GUI::Separator();
        GUI::TreePop();
    }

    // Word wrapping
    if (GUI::TreeNode("Word-wrapping"))
    {
        GUI::Columns(2, "word-wrapping");
        GUI::Separator();
        GUI::TextWrapped("The quick brown fox jumps over the lazy dog.");
        GUI::TextWrapped("Hello Left");
        GUI::NextColumn();
        GUI::TextWrapped("The quick brown fox jumps over the lazy dog.");
        GUI::TextWrapped("Hello Right");
        GUI::Columns(1);
        GUI::Separator();
        GUI::TreePop();
    }

    // Scrolling columns
    /*
    if (GUI::TreeNode("Vertical Scrolling"))
    {
        GUI::BeginChild("##header", ImVec2(0, GUI::GetTextLineHeightWithSpacing()+GUI::GetStyle().ItemSpacing.y));
        GUI::Columns(3);
        GUI::Text("ID"); GUI::NextColumn();
        GUI::Text("Name"); GUI::NextColumn();
        GUI::Text("Path"); GUI::NextColumn();
        GUI::Columns(1);
        GUI::Separator();
        GUI::EndChild();
        GUI::BeginChild("##scrollingregion", ImVec2(0, 60));
        GUI::Columns(3);
        for (int i = 0; i < 10; i++)
        {
            GUI::Text("%04d", i); GUI::NextColumn();
            GUI::Text("Foobar"); GUI::NextColumn();
            GUI::Text("/path/foobar/%04d/", i); GUI::NextColumn();
        }
        GUI::Columns(1);
        GUI::EndChild();
        GUI::TreePop();
    }
    */

    if (GUI::TreeNode("Horizontal Scrolling"))
    {
        GUI::SetNextWindowContentSize(ImVec2(1500.0f, 0.0f));
        ImVec2 child_size = ImVec2(0, GUI::GetFontSize() * 20.0f);
        GUI::BeginChild("##ScrollingRegion", child_size, false, ImGuiWindowFlags_HorizontalScrollbar);
        GUI::Columns(10);
        int ITEMS_COUNT = 2000;
        ImGuiListClipper clipper(ITEMS_COUNT);  // Also demonstrate using the clipper for large list
        while (clipper.Step())
        {
            for (int i = clipper.DisplayStart; i < clipper.DisplayEnd; i++)
                for (int j = 0; j < 10; j++)
                {
                    GUI::Text("Line %d Column %d...", i, j);
                    GUI::NextColumn();
                }
        }
        GUI::Columns(1);
        GUI::EndChild();
        GUI::TreePop();
    }

    if (GUI::TreeNode("Tree"))
    {
        GUI::Columns(2, "tree", true);
        for (int x = 0; x < 3; x++)
        {
            bool open1 = GUI::TreeNode((void*)(intptr_t)x, "Node%d", x);
            GUI::NextColumn();
            GUI::Text("Node contents");
            GUI::NextColumn();
            if (open1)
            {
                for (int y = 0; y < 3; y++)
                {
                    bool open2 = GUI::TreeNode((void*)(intptr_t)y, "Node%d.%d", x, y);
                    GUI::NextColumn();
                    GUI::Text("Node contents");
                    if (open2)
                    {
                        GUI::Text("Even more contents");
                        if (GUI::TreeNode("Tree in column"))
                        {
                            GUI::Text("The quick brown fox jumps over the lazy dog");
                            GUI::TreePop();
                        }
                    }
                    GUI::NextColumn();
                    if (open2)
                        GUI::TreePop();
                }
                GUI::TreePop();
            }
        }
        GUI::Columns(1);
        GUI::TreePop();
    }

    if (disable_indent)
        GUI::PopStyleVar();
    GUI::PopID();
}

static void ShowDemoWindowMisc()
{
    if (GUI::CollapsingHeader("Filtering"))
    {
        // Helper class to easy setup a text filter.
        // You may want to implement a more feature-full filtering scheme in your own application.
        static ImGuiTextFilter filter;
        GUI::Text("Filter usage:\n"
                    "  \"\"         display all lines\n"
                    "  \"xxx\"      display lines containing \"xxx\"\n"
                    "  \"xxx,yyy\"  display lines containing \"xxx\" or \"yyy\"\n"
                    "  \"-xxx\"     hide lines containing \"xxx\"");
        filter.Draw();
        const char* lines[] = { "aaa1.c", "bbb1.c", "ccc1.c", "aaa2.cpp", "bbb2.cpp", "ccc2.cpp", "abc.h", "hello, world" };
        for (int i = 0; i < IM_ARRAYSIZE(lines); i++)
            if (filter.PassFilter(lines[i]))
                GUI::BulletText("%s", lines[i]);
    }

    if (GUI::CollapsingHeader("Inputs, Navigation & Focus"))
    {
        imgui_io& io = GUI::GetIO();

        // Display imgui_io output flags
        GUI::Text("WantCaptureMouse: %d", io.WantCaptureMouse);
        GUI::Text("WantCaptureKeyboard: %d", io.WantCaptureKeyboard);
        GUI::Text("WantTextInput: %d", io.WantTextInput);
        GUI::Text("WantSetMousePos: %d", io.WantSetMousePos);
        GUI::Text("NavActive: %d, NavVisible: %d", io.NavActive, io.NavVisible);

        // Display Keyboard/Mouse state
        if (GUI::TreeNode("Keyboard, Mouse & Navigation State"))
        {
            if (GUI::IsMousePosValid())
                GUI::Text("Mouse pos: (%g, %g)", io.MousePos.x, io.MousePos.y);
            else
                GUI::Text("Mouse pos: <INVALID>");
            GUI::Text("Mouse delta: (%g, %g)", io.MouseDelta.x, io.MouseDelta.y);
            GUI::Text("Mouse down:");     for (int i = 0; i < IM_ARRAYSIZE(io.MouseDown); i++) if (io.MouseDownDuration[i] >= 0.0f)   { GUI::SameLine(); GUI::Text("b%d (%.02f secs)", i, io.MouseDownDuration[i]); }
            GUI::Text("Mouse clicked:");  for (int i = 0; i < IM_ARRAYSIZE(io.MouseDown); i++) if (GUI::IsMouseClicked(i))          { GUI::SameLine(); GUI::Text("b%d", i); }
            GUI::Text("Mouse dblclick:"); for (int i = 0; i < IM_ARRAYSIZE(io.MouseDown); i++) if (GUI::IsMouseDoubleClicked(i))    { GUI::SameLine(); GUI::Text("b%d", i); }
            GUI::Text("Mouse released:"); for (int i = 0; i < IM_ARRAYSIZE(io.MouseDown); i++) if (GUI::IsMouseReleased(i))         { GUI::SameLine(); GUI::Text("b%d", i); }
            GUI::Text("Mouse wheel: %.1f", io.MouseWheel);

            GUI::Text("Keys down:");      for (int i = 0; i < IM_ARRAYSIZE(io.KeysDown); i++) if (io.KeysDownDuration[i] >= 0.0f)     { GUI::SameLine(); GUI::Text("%d (0x%X) (%.02f secs)", i, i, io.KeysDownDuration[i]); }
            GUI::Text("Keys pressed:");   for (int i = 0; i < IM_ARRAYSIZE(io.KeysDown); i++) if (GUI::IsKeyPressed(i))             { GUI::SameLine(); GUI::Text("%d (0x%X)", i, i); }
            GUI::Text("Keys release:");   for (int i = 0; i < IM_ARRAYSIZE(io.KeysDown); i++) if (GUI::IsKeyReleased(i))            { GUI::SameLine(); GUI::Text("%d (0x%X)", i, i); }
            GUI::Text("Keys mods: %s%s%s%s", io.KeyCtrl ? "CTRL " : "", io.KeyShift ? "SHIFT " : "", io.KeyAlt ? "ALT " : "", io.KeySuper ? "SUPER " : "");
            GUI::Text("Chars queue:");    for (int i = 0; i < io.InputQueueCharacters.Size; i++) { ImWchar c = io.InputQueueCharacters[i]; GUI::SameLine();  GUI::Text("\'%c\' (0x%04X)", (c > ' ' && c <= 255) ? (char)c : '?', c); } // FIXME: We should convert 'c' to UTF-8 here but the functions are not public.

            GUI::Text("NavInputs down:");     for (int i = 0; i < IM_ARRAYSIZE(io.NavInputs); i++) if (io.NavInputs[i] > 0.0f)              { GUI::SameLine(); GUI::Text("[%d] %.2f", i, io.NavInputs[i]); }
            GUI::Text("NavInputs pressed:");  for (int i = 0; i < IM_ARRAYSIZE(io.NavInputs); i++) if (io.NavInputsDownDuration[i] == 0.0f) { GUI::SameLine(); GUI::Text("[%d]", i); }
            GUI::Text("NavInputs duration:"); for (int i = 0; i < IM_ARRAYSIZE(io.NavInputs); i++) if (io.NavInputsDownDuration[i] >= 0.0f) { GUI::SameLine(); GUI::Text("[%d] %.2f", i, io.NavInputsDownDuration[i]); }

            GUI::Button("Hovering me sets the\nkeyboard capture flag");
            if (GUI::IsItemHovered())
                GUI::CaptureKeyboardFromApp(true);
            GUI::SameLine();
            GUI::Button("Holding me clears the\nthe keyboard capture flag");
            if (GUI::IsItemActive())
                GUI::CaptureKeyboardFromApp(false);

            GUI::TreePop();
        }

        if (GUI::TreeNode("Tabbing"))
        {
            GUI::Text("Use TAB/SHIFT+TAB to cycle through keyboard editable fields.");
            static char buf[32] = "hello";
            GUI::InputText("1", buf, IM_ARRAYSIZE(buf));
            GUI::InputText("2", buf, IM_ARRAYSIZE(buf));
            GUI::InputText("3", buf, IM_ARRAYSIZE(buf));
            GUI::PushAllowKeyboardFocus(false);
            GUI::InputText("4 (tab skip)", buf, IM_ARRAYSIZE(buf));
            //GUI::SameLine(); HelpMarker("Use GUI::PushAllowKeyboardFocus(bool) to disable tabbing through certain widgets.");
            GUI::PopAllowKeyboardFocus();
            GUI::InputText("5", buf, IM_ARRAYSIZE(buf));
            GUI::TreePop();
        }

        if (GUI::TreeNode("Focus from code"))
        {
            bool focus_1 = GUI::Button("Focus on 1"); GUI::SameLine();
            bool focus_2 = GUI::Button("Focus on 2"); GUI::SameLine();
            bool focus_3 = GUI::Button("Focus on 3");
            int has_focus = 0;
            static char buf[128] = "click on a button to set focus";

            if (focus_1) GUI::SetKeyboardFocusHere();
            GUI::InputText("1", buf, IM_ARRAYSIZE(buf));
            if (GUI::IsItemActive()) has_focus = 1;

            if (focus_2) GUI::SetKeyboardFocusHere();
            GUI::InputText("2", buf, IM_ARRAYSIZE(buf));
            if (GUI::IsItemActive()) has_focus = 2;

            GUI::PushAllowKeyboardFocus(false);
            if (focus_3) GUI::SetKeyboardFocusHere();
            GUI::InputText("3 (tab skip)", buf, IM_ARRAYSIZE(buf));
            if (GUI::IsItemActive()) has_focus = 3;
            GUI::PopAllowKeyboardFocus();

            if (has_focus)
                GUI::Text("Item with focus: %d", has_focus);
            else
                GUI::Text("Item with focus: <none>");

            // Use >= 0 parameter to SetKeyboardFocusHere() to focus an upcoming item
            static float f3[3] = { 0.0f, 0.0f, 0.0f };
            int focus_ahead = -1;
            if (GUI::Button("Focus on X")) { focus_ahead = 0; } GUI::SameLine();
            if (GUI::Button("Focus on Y")) { focus_ahead = 1; } GUI::SameLine();
            if (GUI::Button("Focus on Z")) { focus_ahead = 2; }
            if (focus_ahead != -1) GUI::SetKeyboardFocusHere(focus_ahead);
            GUI::SliderFloat3("Float3", &f3[0], 0.0f, 1.0f);

            GUI::TextWrapped("NB: Cursor & selection are preserved when refocusing last used item in code.");
            GUI::TreePop();
        }

        if (GUI::TreeNode("Dragging"))
        {
            GUI::TextWrapped("You can use GUI::GetMouseDragDelta(0) to query for the dragged amount on any widget.");
            for (int button = 0; button < 3; button++)
            {
                GUI::Text("IsMouseDragging(%d):", button);
                GUI::Text("  w/ default threshold: %d,", GUI::IsMouseDragging(button));
                GUI::Text("  w/ zero threshold: %d,", GUI::IsMouseDragging(button, 0.0f));
                GUI::Text("  w/ large threshold: %d,", GUI::IsMouseDragging(button, 20.0f));
            }

            GUI::Button("Drag Me");
            if (GUI::IsItemActive())
                GUI::GetForegroundDrawList()->AddLine(io.MouseClickedPos[0], io.MousePos, GUI::GetColorU32(ImGuiCol_Button), 4.0f); // Draw a line between the button and the mouse cursor

            // Drag operations gets "unlocked" when the mouse has moved past a certain threshold
            // (the default threshold is stored in io.MouseDragThreshold). You can request a lower or higher
            // threshold using the second parameter of IsMouseDragging() and GetMouseDragDelta().
            ImVec2 value_raw = GUI::GetMouseDragDelta(0, 0.0f);
            ImVec2 value_with_lock_threshold = GUI::GetMouseDragDelta(0);
            ImVec2 mouse_delta = io.MouseDelta;
            GUI::Text("GetMouseDragDelta(0):");
            GUI::Text("  w/ default threshold: (%.1f, %.1f)", value_with_lock_threshold.x, value_with_lock_threshold.y);
            GUI::Text("  w/ zero threshold: (%.1f, %.1f)", value_raw.x, value_raw.y);
            GUI::Text("io.MouseDelta: (%.1f, %.1f)", mouse_delta.x, mouse_delta.y);
            GUI::TreePop();
        }

        if (GUI::TreeNode("Mouse cursors"))
        {
            const char* mouse_cursors_names[] = { "Arrow", "TextInput", "ResizeAll", "ResizeNS", "ResizeEW", "ResizeNESW", "ResizeNWSE", "Hand", "NotAllowed" };
            IM_ASSERT(IM_ARRAYSIZE(mouse_cursors_names) == imgui_mouse_cursor_COUNT);

            imgui_mouse_cursor current = GUI::GetMouseCursor();
            GUI::Text("Current mouse cursor = %d: %s", current, mouse_cursors_names[current]);
            GUI::Text("Hover to see mouse cursors:");
            GUI::SameLine(); HelpMarker(
                "Your application can render a different mouse cursor based on what GUI::GetMouseCursor() returns. "
                "If software cursor rendering (io.MouseDrawCursor) is set ImGui will draw the right cursor for you, "
                "otherwise your backend needs to handle it.");
            for (int i = 0; i < imgui_mouse_cursor_COUNT; i++)
            {
                char label[32];
                sprintf(label, "Mouse cursor %d: %s", i, mouse_cursors_names[i]);
                GUI::Bullet(); GUI::Selectable(label, false);
                if (GUI::IsItemHovered() || GUI::IsItemFocused())
                    GUI::SetMouseCursor(i);
            }
            GUI::TreePop();
        }
    }
}

//-----------------------------------------------------------------------------
// [SECTION] About Window / ShowAboutWindow()
// Access from Dear ImGui Demo -> Tools -> About
//-----------------------------------------------------------------------------

void GUI::ShowAboutWindow(bool* p_open)
{
    if (!GUI::Begin("About Dear ImGui", p_open, ImGuiWindowFlags_AlwaysAutoResize))
    {
        GUI::End();
        return;
    }
    GUI::Text("Dear ImGui %s", GUI::GetVersion());
    GUI::Separator();
    GUI::Text("By Omar Cornut and all Dear ImGui contributors.");
    GUI::Text("Dear ImGui is licensed under the MIT License, see LICENSE for more information.");

    static bool show_config_info = false;
    GUI::Checkbox("Config/Build Information", &show_config_info);
    if (show_config_info)
    {
        imgui_io& io = GUI::GetIO();
        imgui_style& style = GUI::GetStyle();

        bool copy_to_clipboard = GUI::Button("Copy to clipboard");
        ImVec2 child_size = ImVec2(0, GUI::GetTextLineHeightWithSpacing() * 18);
        GUI::BeginChildFrame(GUI::GetID("cfg_infos"), child_size, ImGuiWindowFlags_NoMove);
        if (copy_to_clipboard)
        {
            GUI::LogToClipboard();
            GUI::LogText("```\n"); // Back quotes will make text appears without formatting when pasting on GitHub
        }

        GUI::Text("Dear ImGui %s (%d)", IMGUI_VERSION, IMGUI_VERSION_NUM);
        GUI::Separator();
        GUI::Text("sizeof(size_t): %d, sizeof(ImDrawIdx): %d, sizeof(ImDrawVert): %d", (int)sizeof(size_t), (int)sizeof(ImDrawIdx), (int)sizeof(ImDrawVert));
        GUI::Text("define: __cplusplus=%d", (int)__cplusplus);
#ifdef IMGUI_DISABLE_OBSOLETE_FUNCTIONS
        GUI::Text("define: IMGUI_DISABLE_OBSOLETE_FUNCTIONS");
#endif
#ifdef IMGUI_DISABLE_WIN32_DEFAULT_CLIPBOARD_FUNCTIONS
        GUI::Text("define: IMGUI_DISABLE_WIN32_DEFAULT_CLIPBOARD_FUNCTIONS");
#endif
#ifdef IMGUI_DISABLE_WIN32_DEFAULT_IME_FUNCTIONS
        GUI::Text("define: IMGUI_DISABLE_WIN32_DEFAULT_IME_FUNCTIONS");
#endif
#ifdef IMGUI_DISABLE_WIN32_FUNCTIONS
        GUI::Text("define: IMGUI_DISABLE_WIN32_FUNCTIONS");
#endif
#ifdef IMGUI_DISABLE_DEFAULT_FORMAT_FUNCTIONS
        GUI::Text("define: IMGUI_DISABLE_DEFAULT_FORMAT_FUNCTIONS");
#endif
#ifdef IMGUI_DISABLE_DEFAULT_MATH_FUNCTIONS
        GUI::Text("define: IMGUI_DISABLE_DEFAULT_MATH_FUNCTIONS");
#endif
#ifdef IMGUI_DISABLE_DEFAULT_FILE_FUNCTIONS
        GUI::Text("define: IMGUI_DISABLE_DEFAULT_FILE_FUNCTIONS");
#endif
#ifdef IMGUI_DISABLE_FILE_FUNCTIONS
        GUI::Text("define: IMGUI_DISABLE_FILE_FUNCTIONS");
#endif
#ifdef IMGUI_DISABLE_DEFAULT_ALLOCATORS
        GUI::Text("define: IMGUI_DISABLE_DEFAULT_ALLOCATORS");
#endif
#ifdef IMGUI_USE_BGRA_PACKED_COLOR
        GUI::Text("define: IMGUI_USE_BGRA_PACKED_COLOR");
#endif
#ifdef _WIN32
        GUI::Text("define: _WIN32");
#endif
#ifdef _WIN64
        GUI::Text("define: _WIN64");
#endif
#ifdef __linux__
        GUI::Text("define: __linux__");
#endif
#ifdef __APPLE__
        GUI::Text("define: __APPLE__");
#endif
#ifdef _MSC_VER
        GUI::Text("define: _MSC_VER=%d", _MSC_VER);
#endif
#ifdef __MINGW32__
        GUI::Text("define: __MINGW32__");
#endif
#ifdef __MINGW64__
        GUI::Text("define: __MINGW64__");
#endif
#ifdef __GNUC__
        GUI::Text("define: __GNUC__=%d", (int)__GNUC__);
#endif
#ifdef __clang_version__
        GUI::Text("define: __clang_version__=%s", __clang_version__);
#endif
#ifdef IMGUI_HAS_VIEWPORT
        GUI::Text("define: IMGUI_HAS_VIEWPORT");
#endif
#ifdef IMGUI_HAS_DOCK
        GUI::Text("define: IMGUI_HAS_DOCK");
#endif
        GUI::Separator();
        GUI::Text("io.BackendPlatformName: %s", io.BackendPlatformName ? io.BackendPlatformName : "NULL");
        GUI::Text("io.BackendRendererName: %s", io.BackendRendererName ? io.BackendRendererName : "NULL");
        GUI::Text("io.ConfigFlags: 0x%08X", io.ConfigFlags);
        if (io.ConfigFlags & ImGuiConfigFlags_NavEnableKeyboard)        GUI::Text(" NavEnableKeyboard");
        if (io.ConfigFlags & ImGuiConfigFlags_NavEnableGamepad)         GUI::Text(" NavEnableGamepad");
        if (io.ConfigFlags & ImGuiConfigFlags_NavEnableSetMousePos)     GUI::Text(" NavEnableSetMousePos");
        if (io.ConfigFlags & ImGuiConfigFlags_NavNoCaptureKeyboard)     GUI::Text(" NavNoCaptureKeyboard");
        if (io.ConfigFlags & ImGuiConfigFlags_NoMouse)                  GUI::Text(" NoMouse");
        if (io.ConfigFlags & ImGuiConfigFlags_NoMouseCursorChange)      GUI::Text(" NoMouseCursorChange");
        if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)            GUI::Text(" DockingEnable");
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)          GUI::Text(" ViewportsEnable");
        if (io.ConfigFlags & ImGuiConfigFlags_DpiEnableScaleViewports)  GUI::Text(" DpiEnableScaleViewports");
        if (io.ConfigFlags & ImGuiConfigFlags_DpiEnableScaleFonts)      GUI::Text(" DpiEnableScaleFonts");
        if (io.MouseDrawCursor)                                         GUI::Text("io.MouseDrawCursor");
        if (io.ConfigViewportsNoAutoMerge)                              GUI::Text("io.ConfigViewportsNoAutoMerge");
        if (io.ConfigViewportsNoTaskBarIcon)                            GUI::Text("io.ConfigViewportsNoTaskBarIcon");
        if (io.ConfigViewportsNoDecoration)                             GUI::Text("io.ConfigViewportsNoDecoration");
        if (io.ConfigViewportsNoDefaultParent)                          GUI::Text("io.ConfigViewportsNoDefaultParent");
        if (io.ConfigDockingNoSplit)                                    GUI::Text("io.ConfigDockingNoSplit");
        if (io.ConfigDockingWithShift)                                  GUI::Text("io.ConfigDockingWithShift");
        if (io.ConfigDockingAlwaysTabBar)                               GUI::Text("io.ConfigDockingAlwaysTabBar");
        if (io.ConfigDockingTransparentPayload)                         GUI::Text("io.ConfigDockingTransparentPayload");
        if (io.ConfigMacOSXBehaviors)                                   GUI::Text("io.ConfigMacOSXBehaviors");
        if (io.ConfigInputTextCursorBlink)                              GUI::Text("io.ConfigInputTextCursorBlink");
        if (io.ConfigWindowsResizeFromEdges)                            GUI::Text("io.ConfigWindowsResizeFromEdges");
        if (io.ConfigWindowsMoveFromTitleBarOnly)                       GUI::Text("io.ConfigWindowsMoveFromTitleBarOnly");
        if (io.ConfigWindowsMemoryCompactTimer >= 0.0f)                 GUI::Text("io.ConfigWindowsMemoryCompactTimer = %.1ff", io.ConfigWindowsMemoryCompactTimer);
        GUI::Text("io.BackendFlags: 0x%08X", io.BackendFlags);
        if (io.BackendFlags & ImGuiBackendFlags_HasGamepad)             GUI::Text(" HasGamepad");
        if (io.BackendFlags & ImGuiBackendFlags_HasMouseCursors)        GUI::Text(" HasMouseCursors");
        if (io.BackendFlags & ImGuiBackendFlags_HasSetMousePos)         GUI::Text(" HasSetMousePos");
        if (io.BackendFlags & ImGuiBackendFlags_PlatformHasViewports)   GUI::Text(" PlatformHasViewports");
        if (io.BackendFlags & ImGuiBackendFlags_HasMouseHoveredViewport)GUI::Text(" HasMouseHoveredViewport");
        if (io.BackendFlags & ImGuiBackendFlags_RendererHasVtxOffset)   GUI::Text(" RendererHasVtxOffset");
        if (io.BackendFlags & ImGuiBackendFlags_RendererHasViewports)   GUI::Text(" RendererHasViewports");
        GUI::Separator();
        GUI::Text("io.Fonts: %d fonts, Flags: 0x%08X, TexSize: %d,%d", io.Fonts->Fonts.Size, io.Fonts->Flags, io.Fonts->TexWidth, io.Fonts->TexHeight);
        GUI::Text("io.DisplaySize: %.2f,%.2f", io.DisplaySize.x, io.DisplaySize.y);
        GUI::Text("io.DisplayFramebufferScale: %.2f,%.2f", io.DisplayFramebufferScale.x, io.DisplayFramebufferScale.y);
        GUI::Separator();
        GUI::Text("style.WindowPadding: %.2f,%.2f", style.WindowPadding.x, style.WindowPadding.y);
        GUI::Text("style.WindowBorderSize: %.2f", style.WindowBorderSize);
        GUI::Text("style.FramePadding: %.2f,%.2f", style.FramePadding.x, style.FramePadding.y);
        GUI::Text("style.FrameRounding: %.2f", style.FrameRounding);
        GUI::Text("style.FrameBorderSize: %.2f", style.FrameBorderSize);
        GUI::Text("style.ItemSpacing: %.2f,%.2f", style.ItemSpacing.x, style.ItemSpacing.y);
        GUI::Text("style.ItemInnerSpacing: %.2f,%.2f", style.ItemInnerSpacing.x, style.ItemInnerSpacing.y);

        if (copy_to_clipboard)
        {
            GUI::LogText("\n```\n");
            GUI::LogFinish();
        }
        GUI::EndChildFrame();
    }
    GUI::End();
}

//-----------------------------------------------------------------------------
// [SECTION] Style Editor / ShowStyleEditor()
//-----------------------------------------------------------------------------
// - ShowStyleSelector()
// - ShowFontSelector()
// - ShowStyleEditor()
//-----------------------------------------------------------------------------

// Demo helper function to select among default colors. See ShowStyleEditor() for more advanced options.
// Here we use the simplified Combo() api that packs items into a single literal string.
// Useful for quick combo boxes where the choices are known locally.
bool GUI::ShowStyleSelector(const char* label)
{
    static int style_idx = -1;
    if (GUI::Combo(label, &style_idx, "Classic\0Dark\0Light\0"))
    {
        switch (style_idx)
        {
        case 0: GUI::StyleColorsClassic(); break;
        case 1: GUI::StyleColorsDark(); break;
        case 2: GUI::StyleColorsLight(); break;
        }
        return true;
    }
    return false;
}

// Demo helper function to select among loaded fonts.
// Here we use the regular BeginCombo()/EndCombo() api which is more the more flexible one.
void GUI::ShowFontSelector(const char* label)
{
    imgui_io& io = GUI::GetIO();
    ImFont* font_current = GUI::GetFont();
    if (GUI::BeginCombo(label, font_current->GetDebugName()))
    {
        for (int n = 0; n < io.Fonts->Fonts.Size; n++)
        {
            ImFont* font = io.Fonts->Fonts[n];
            GUI::PushID((void*)font);
            if (GUI::Selectable(font->GetDebugName(), font == font_current))
                io.FontDefault = font;
            GUI::PopID();
        }
        GUI::EndCombo();
    }
    GUI::SameLine();
    HelpMarker(
        "- Load additional fonts with io.Fonts->AddFontFromFileTTF().\n"
        "- The font atlas is built when calling io.Fonts->GetTexDataAsXXXX() or io.Fonts->Build().\n"
        "- Read FAQ and docs/FONTS.md for more details.\n"
        "- If you need to add/remove fonts at runtime (e.g. for DPI change), do it before calling NewFrame().");
}

// [Internal] Display details for a single font, called by ShowStyleEditor().
static void NodeFont(ImFont* font)
{
    imgui_io& io = GUI::GetIO();
    imgui_style& style = GUI::GetStyle();
    bool font_details_opened = GUI::TreeNode(font, "Font: \"%s\"\n%.2f px, %d glyphs, %d file(s)",
        font->ConfigData ? font->ConfigData[0].Name : "", font->FontSize, font->Glyphs.Size, font->ConfigDataCount);
    GUI::SameLine(); if (GUI::SmallButton("Set as default")) { io.FontDefault = font; }
    if (!font_details_opened)
        return;

    GUI::PushFont(font);
    GUI::Text("The quick brown fox jumps over the lazy dog");
    GUI::PopFont();
    GUI::DragFloat("Font scale", &font->Scale, 0.005f, 0.3f, 2.0f, "%.1f");   // Scale only this font
    GUI::SameLine(); HelpMarker(
        "Note than the default embedded font is NOT meant to be scaled.\n\n"
        "Font are currently rendered into bitmaps at a given size at the time of building the atlas. "
        "You may oversample them to get some flexibility with scaling. "
        "You can also render at multiple sizes and select which one to use at runtime.\n\n"
        "(Glimmer of hope: the atlas system will be rewritten in the future to make scaling more flexible.)");
    GUI::InputFloat("Font offset", &font->DisplayOffset.y, 1, 1, "%.0f");
    GUI::Text("Ascent: %f, Descent: %f, Height: %f", font->Ascent, font->Descent, font->Ascent - font->Descent);
    GUI::Text("Fallback character: '%c' (U+%04X)", font->FallbackChar, font->FallbackChar);
    GUI::Text("Ellipsis character: '%c' (U+%04X)", font->EllipsisChar, font->EllipsisChar);
    const int surface_sqrt = (int)sqrtf((float)font->MetricsTotalSurface);
    GUI::Text("Texture Area: about %d px ~%dx%d px", font->MetricsTotalSurface, surface_sqrt, surface_sqrt);
    for (int config_i = 0; config_i < font->ConfigDataCount; config_i++)
        if (font->ConfigData)
            if (const ImFontConfig* cfg = &font->ConfigData[config_i])
                GUI::BulletText("Input %d: \'%s\', Oversample: (%d,%d), PixelSnapH: %d",
                    config_i, cfg->Name, cfg->OversampleH, cfg->OversampleV, cfg->PixelSnapH);
    if (GUI::TreeNode("Glyphs", "Glyphs (%d)", font->Glyphs.Size))
    {
        // Display all glyphs of the fonts in separate pages of 256 characters
        const ImU32 glyph_col = GUI::GetColorU32(ImGuiCol_Text);
        for (unsigned int base = 0; base <= IM_UNICODE_CODEPOINT_MAX; base += 256)
        {
            // Skip ahead if a large bunch of glyphs are not present in the font (test in chunks of 4k)
            // This is only a small optimization to reduce the number of iterations when IM_UNICODE_MAX_CODEPOINT
            // is large // (if ImWchar==ImWchar32 we will do at least about 272 queries here)
            if (!(base & 4095) && font->IsGlyphRangeUnused(base, base + 4095))
            {
                base += 4096 - 256;
                continue;
            }

            int count = 0;
            for (unsigned int n = 0; n < 256; n++)
                if (font->FindGlyphNoFallback((ImWchar)(base + n)))
                    count++;
            if (count <= 0)
                continue;
            if (!GUI::TreeNode((void*)(intptr_t)base, "U+%04X..U+%04X (%d %s)", base, base + 255, count, count > 1 ? "glyphs" : "glyph"))
                continue;
            float cell_size = font->FontSize * 1;
            float cell_spacing = style.ItemSpacing.y;
            ImVec2 base_pos = GUI::GetCursorScreenPos();
            imgui_draw_list* draw_list = GUI::GetWindowDrawList();
            for (unsigned int n = 0; n < 256; n++)
            {
                // We use ImFont::RenderChar as a shortcut because we don't have UTF-8 conversion functions
                // available here and thus cannot easily generate a zero-terminated UTF-8 encoded string.
                ImVec2 cell_p1(base_pos.x + (n % 16) * (cell_size + cell_spacing), base_pos.y + (n / 16) * (cell_size + cell_spacing));
                ImVec2 cell_p2(cell_p1.x + cell_size, cell_p1.y + cell_size);
                const ImFontGlyph* glyph = font->FindGlyphNoFallback((ImWchar)(base + n));
                draw_list->AddRect(cell_p1, cell_p2, glyph ? IM_COL32(255, 255, 255, 100) : IM_COL32(255, 255, 255, 50));
                if (glyph)
                    font->RenderChar(draw_list, cell_size, cell_p1, glyph_col, (ImWchar)(base + n));
                if (glyph && GUI::IsMouseHoveringRect(cell_p1, cell_p2))
                {
                    GUI::BeginTooltip();
                    GUI::Text("Codepoint: U+%04X", base + n);
                    GUI::Separator();
                    GUI::Text("Visible: %d", glyph->Visible);
                    GUI::Text("AdvanceX: %.1f", glyph->AdvanceX);
                    GUI::Text("Pos: (%.2f,%.2f)->(%.2f,%.2f)", glyph->X0, glyph->Y0, glyph->X1, glyph->Y1);
                    GUI::Text("UV: (%.3f,%.3f)->(%.3f,%.3f)", glyph->U0, glyph->V0, glyph->U1, glyph->V1);
                    GUI::EndTooltip();
                }
            }
            GUI::Dummy(ImVec2((cell_size + cell_spacing) * 16, (cell_size + cell_spacing) * 16));
            GUI::TreePop();
        }
        GUI::TreePop();
    }
    GUI::TreePop();
}

void GUI::ShowStyleEditor(imgui_style* ref)
{
    // You can pass in a reference imgui_style structure to compare to, revert to and save to
    // (without a reference style pointer, we will use one compared locally as a reference)
    imgui_style& style = GUI::GetStyle();
    static imgui_style ref_saved_style;

    // Default to using internal storage as reference
    static bool init = true;
    if (init && ref == NULL)
        ref_saved_style = style;
    init = false;
    if (ref == NULL)
        ref = &ref_saved_style;

    GUI::PushItemWidth(GUI::GetWindowWidth() * 0.50f);

    if (GUI::ShowStyleSelector("Colors##Selector"))
        ref_saved_style = style;
    GUI::ShowFontSelector("Fonts##Selector");

    // Simplified Settings (expose floating-pointer border sizes as boolean representing 0.0f or 1.0f)
    if (GUI::SliderFloat("FrameRounding", &style.FrameRounding, 0.0f, 12.0f, "%.0f"))
        style.GrabRounding = style.FrameRounding; // Make GrabRounding always the same value as FrameRounding
    { bool border = (style.WindowBorderSize > 0.0f); if (GUI::Checkbox("WindowBorder", &border)) { style.WindowBorderSize = border ? 1.0f : 0.0f; } }
    GUI::SameLine();
    { bool border = (style.FrameBorderSize > 0.0f);  if (GUI::Checkbox("FrameBorder",  &border)) { style.FrameBorderSize  = border ? 1.0f : 0.0f; } }
    GUI::SameLine();
    { bool border = (style.PopupBorderSize > 0.0f);  if (GUI::Checkbox("PopupBorder",  &border)) { style.PopupBorderSize  = border ? 1.0f : 0.0f; } }

    // Save/Revert button
    if (GUI::Button("Save Ref"))
        *ref = ref_saved_style = style;
    GUI::SameLine();
    if (GUI::Button("Revert Ref"))
        style = *ref;
    GUI::SameLine();
    HelpMarker(
        "Save/Revert in local non-persistent storage. Default Colors definition are not affected. "
        "Use \"Export\" below to save them somewhere.");

    GUI::Separator();

    if (GUI::BeginTabBar("##tabs", ImGuiTabBarFlags_None))
    {
        if (GUI::BeginTabItem("Sizes"))
        {
            GUI::Text("Main");
            GUI::SliderFloat2("WindowPadding", (float*)&style.WindowPadding, 0.0f, 20.0f, "%.0f");
            GUI::SliderFloat2("FramePadding", (float*)&style.FramePadding, 0.0f, 20.0f, "%.0f");
            GUI::SliderFloat2("ItemSpacing", (float*)&style.ItemSpacing, 0.0f, 20.0f, "%.0f");
            GUI::SliderFloat2("ItemInnerSpacing", (float*)&style.ItemInnerSpacing, 0.0f, 20.0f, "%.0f");
            GUI::SliderFloat2("TouchExtraPadding", (float*)&style.TouchExtraPadding, 0.0f, 10.0f, "%.0f");
            GUI::SliderFloat("IndentSpacing", &style.IndentSpacing, 0.0f, 30.0f, "%.0f");
            GUI::SliderFloat("ScrollbarSize", &style.ScrollbarSize, 1.0f, 20.0f, "%.0f");
            GUI::SliderFloat("GrabMinSize", &style.GrabMinSize, 1.0f, 20.0f, "%.0f");
            GUI::Text("Borders");
            GUI::SliderFloat("WindowBorderSize", &style.WindowBorderSize, 0.0f, 1.0f, "%.0f");
            GUI::SliderFloat("ChildBorderSize", &style.ChildBorderSize, 0.0f, 1.0f, "%.0f");
            GUI::SliderFloat("PopupBorderSize", &style.PopupBorderSize, 0.0f, 1.0f, "%.0f");
            GUI::SliderFloat("FrameBorderSize", &style.FrameBorderSize, 0.0f, 1.0f, "%.0f");
            GUI::SliderFloat("TabBorderSize", &style.TabBorderSize, 0.0f, 1.0f, "%.0f");
            GUI::Text("Rounding");
            GUI::SliderFloat("WindowRounding", &style.WindowRounding, 0.0f, 12.0f, "%.0f");
            GUI::SliderFloat("ChildRounding", &style.ChildRounding, 0.0f, 12.0f, "%.0f");
            GUI::SliderFloat("FrameRounding", &style.FrameRounding, 0.0f, 12.0f, "%.0f");
            GUI::SliderFloat("PopupRounding", &style.PopupRounding, 0.0f, 12.0f, "%.0f");
            GUI::SliderFloat("ScrollbarRounding", &style.ScrollbarRounding, 0.0f, 12.0f, "%.0f");
            GUI::SliderFloat("GrabRounding", &style.GrabRounding, 0.0f, 12.0f, "%.0f");
            GUI::SliderFloat("LogSliderDeadzone", &style.LogSliderDeadzone, 0.0f, 12.0f, "%.0f");
            GUI::SliderFloat("TabRounding", &style.TabRounding, 0.0f, 12.0f, "%.0f");
            GUI::Text("Alignment");
            GUI::SliderFloat2("WindowTitleAlign", (float*)&style.WindowTitleAlign, 0.0f, 1.0f, "%.2f");
            int window_menu_button_position = style.WindowMenuButtonPosition + 1;
            if (GUI::Combo("WindowMenuButtonPosition", (int*)&window_menu_button_position, "None\0Left\0Right\0"))
                style.WindowMenuButtonPosition = window_menu_button_position - 1;
            GUI::Combo("ColorButtonPosition", (int*)&style.ColorButtonPosition, "Left\0Right\0");
            GUI::SliderFloat2("ButtonTextAlign", (float*)&style.ButtonTextAlign, 0.0f, 1.0f, "%.2f");
            GUI::SameLine(); HelpMarker("Alignment applies when a button is larger than its text content.");
            GUI::SliderFloat2("SelectableTextAlign", (float*)&style.SelectableTextAlign, 0.0f, 1.0f, "%.2f");
            GUI::SameLine(); HelpMarker("Alignment applies when a selectable is larger than its text content.");
            GUI::Text("Safe Area Padding");
            GUI::SameLine(); HelpMarker("Adjust if you cannot see the edges of your screen (e.g. on a TV where scaling has not been configured).");
            GUI::SliderFloat2("DisplaySafeAreaPadding", (float*)&style.DisplaySafeAreaPadding, 0.0f, 30.0f, "%.0f");
            GUI::EndTabItem();
        }

        if (GUI::BeginTabItem("Colors"))
        {
            static int output_dest = 0;
            static bool output_only_modified = true;
            if (GUI::Button("Export"))
            {
                if (output_dest == 0)
                    GUI::LogToClipboard();
                else
                    GUI::LogToTTY();
                GUI::LogText("ImVec4* colors = GUI::GetStyle().Colors;" IM_NEWLINE);
                for (int i = 0; i < ImGuiCol_COUNT; i++)
                {
                    const ImVec4& col = style.Colors[i];
                    const char* name = GUI::GetStyleColorName(i);
                    if (!output_only_modified || memcmp(&col, &ref->Colors[i], sizeof(ImVec4)) != 0)
                        GUI::LogText("colors[ImGuiCol_%s]%*s= ImVec4(%.2ff, %.2ff, %.2ff, %.2ff);" IM_NEWLINE,
                            name, 23 - (int)strlen(name), "", col.x, col.y, col.z, col.w);
                }
                GUI::LogFinish();
            }
            GUI::SameLine(); GUI::SetNextItemWidth(120); GUI::Combo("##output_type", &output_dest, "To Clipboard\0To TTY\0");
            GUI::SameLine(); GUI::Checkbox("Only Modified Colors", &output_only_modified);

            static ImGuiTextFilter filter;
            filter.Draw("Filter colors", GUI::GetFontSize() * 16);

            static ImGuiColorEditFlags alpha_flags = 0;
            if (GUI::RadioButton("Opaque", alpha_flags == ImGuiColorEditFlags_None))             { alpha_flags = ImGuiColorEditFlags_None; } GUI::SameLine();
            if (GUI::RadioButton("Alpha",  alpha_flags == ImGuiColorEditFlags_AlphaPreview))     { alpha_flags = ImGuiColorEditFlags_AlphaPreview; } GUI::SameLine();
            if (GUI::RadioButton("Both",   alpha_flags == ImGuiColorEditFlags_AlphaPreviewHalf)) { alpha_flags = ImGuiColorEditFlags_AlphaPreviewHalf; } GUI::SameLine();
            HelpMarker(
                "In the color list:\n"
                "Left-click on colored square to open color picker,\n"
                "Right-click to open edit options menu.");

            GUI::BeginChild("##colors", ImVec2(0, 0), true, ImGuiWindowFlags_AlwaysVerticalScrollbar | ImGuiWindowFlags_AlwaysHorizontalScrollbar | ImGuiWindowFlags_NavFlattened);
            GUI::PushItemWidth(-160);
            for (int i = 0; i < ImGuiCol_COUNT; i++)
            {
                const char* name = GUI::GetStyleColorName(i);
                if (!filter.PassFilter(name))
                    continue;
                GUI::PushID(i);
                GUI::ColorEdit4("##color", (float*)&style.Colors[i], ImGuiColorEditFlags_AlphaBar | alpha_flags);
                if (memcmp(&style.Colors[i], &ref->Colors[i], sizeof(ImVec4)) != 0)
                {
                    // Tips: in a real user application, you may want to merge and use an icon font into the main font,
                    // so instead of "Save"/"Revert" you'd use icons!
                    // Read the FAQ and docs/FONTS.md about using icon fonts. It's really easy and super convenient!
                    GUI::SameLine(0.0f, style.ItemInnerSpacing.x); if (GUI::Button("Save")) { ref->Colors[i] = style.Colors[i]; }
                    GUI::SameLine(0.0f, style.ItemInnerSpacing.x); if (GUI::Button("Revert")) { style.Colors[i] = ref->Colors[i]; }
                }
                GUI::SameLine(0.0f, style.ItemInnerSpacing.x);
                GUI::TextUnformatted(name);
                GUI::PopID();
            }
            GUI::PopItemWidth();
            GUI::EndChild();

            GUI::EndTabItem();
        }

        if (GUI::BeginTabItem("Fonts"))
        {
            imgui_io& io = GUI::GetIO();
            ImFontAtlas* atlas = io.Fonts;
            HelpMarker("Read FAQ and docs/FONTS.md for details on font loading.");
            GUI::PushItemWidth(120);
            for (int i = 0; i < atlas->Fonts.Size; i++)
            {
                ImFont* font = atlas->Fonts[i];
                GUI::PushID(font);
                NodeFont(font);
                GUI::PopID();
            }
            if (GUI::TreeNode("Atlas texture", "Atlas texture (%dx%d pixels)", atlas->TexWidth, atlas->TexHeight))
            {
                ImVec4 tint_col = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
                ImVec4 border_col = ImVec4(1.0f, 1.0f, 1.0f, 0.5f);
                GUI::Image(atlas->TexID, ImVec2((float)atlas->TexWidth, (float)atlas->TexHeight), ImVec2(0, 0), ImVec2(1, 1), tint_col, border_col);
                GUI::TreePop();
            }

            // Post-baking font scaling. Note that this is NOT the nice way of scaling fonts, read below.
            // (we enforce hard clamping manually as by default DragFloat/SliderFloat allows CTRL+Click text to get out of bounds).
            const float MIN_SCALE = 0.3f;
            const float MAX_SCALE = 2.0f;
            HelpMarker(
                "Those are old settings provided for convenience.\n"
                "However, the _correct_ way of scaling your UI is currently to reload your font at the designed size, "
                "rebuild the font atlas, and call style.ScaleAllSizes() on a reference imgui_style structure.\n"
                "Using those settings here will give you poor quality results.");
            static float window_scale = 1.0f;
            if (GUI::DragFloat("window scale", &window_scale, 0.005f, MIN_SCALE, MAX_SCALE, "%.2f", ImGuiSliderFlags_ClampOnInput)) // Scale only this window
                GUI::SetWindowFontScale(window_scale);
            GUI::DragFloat("global scale", &io.FontGlobalScale, 0.005f, MIN_SCALE, MAX_SCALE, "%.2f", ImGuiSliderFlags_ClampOnInput); // Scale everything
            GUI::PopItemWidth();

            GUI::EndTabItem();
        }

        if (GUI::BeginTabItem("Rendering"))
        {
            GUI::Checkbox("Anti-aliased lines", &style.AntiAliasedLines);
            GUI::SameLine(); HelpMarker("When disabling anti-aliasing lines, you'll probably want to disable borders in your style as well.");
            GUI::Checkbox("Anti-aliased lines use texture", &style.AntiAliasedLinesUseTex);
            GUI::SameLine(); HelpMarker("Faster lines using texture data. Require back-end to render with bilinear filtering (not point/nearest filtering).");
            GUI::Checkbox("Anti-aliased fill", &style.AntiAliasedFill);
            GUI::PushItemWidth(100);
            GUI::DragFloat("Curve Tessellation Tolerance", &style.CurveTessellationTol, 0.02f, 0.10f, 10.0f, "%.2f");
            if (style.CurveTessellationTol < 0.10f) style.CurveTessellationTol = 0.10f;

            // When editing the "Circle Segment Max Error" value, draw a preview of its effect on auto-tessellated circles.
            GUI::DragFloat("Circle Segment Max Error", &style.CircleSegmentMaxError, 0.01f, 0.10f, 10.0f, "%.2f");
            if (GUI::IsItemActive())
            {
                GUI::SetNextWindowPos(GUI::GetCursorScreenPos());
                GUI::BeginTooltip();
                ImVec2 p = GUI::GetCursorScreenPos();
                float RAD_MIN = 10.0f, RAD_MAX = 80.0f;
                float off_x = 10.0f;
                for (int n = 0; n < 7; n++)
                {
                    const float rad = RAD_MIN + (RAD_MAX - RAD_MIN) * (float)n / (7.0f - 1.0f);
                    GUI::GetWindowDrawList()->AddCircle(ImVec2(p.x + off_x + rad, p.y + RAD_MAX), rad, GUI::GetColorU32(ImGuiCol_Text), 0);
                    off_x += 10.0f + rad * 2.0f;
                }
                GUI::Dummy(ImVec2(off_x, RAD_MAX * 2.0f));
                GUI::EndTooltip();
            }
            GUI::SameLine();
            HelpMarker("When drawing circle primitives with \"num_segments == 0\" tesselation will be calculated automatically.");

            GUI::DragFloat("Global Alpha", &style.Alpha, 0.005f, 0.20f, 1.0f, "%.2f"); // Not exposing zero here so user doesn't "lose" the UI (zero alpha clips all widgets). But application code could have a toggle to switch between zero and non-zero.
            GUI::PopItemWidth();

            GUI::EndTabItem();
        }

        GUI::EndTabBar();
    }

    GUI::PopItemWidth();
}

//-----------------------------------------------------------------------------
// [SECTION] Example App: Main Menu Bar / ShowExampleAppMainMenuBar()
//-----------------------------------------------------------------------------
// - ShowExampleAppMainMenuBar()
// - ShowExampleMenuFile()
//-----------------------------------------------------------------------------

// Demonstrate creating a "main" fullscreen menu bar and populating it.
// Note the difference between BeginMainMenuBar() and BeginMenuBar():
// - BeginMenuBar() = menu-bar inside current window (which needs the ImGuiWindowFlags_MenuBar flag!)
// - BeginMainMenuBar() = helper to create menu-bar-sized window at the top of the main viewport + call BeginMenuBar() into it.
static void ShowExampleAppMainMenuBar()
{
    if (GUI::BeginMainMenuBar())
    {
        if (GUI::BeginMenu("File"))
        {
            ShowExampleMenuFile();
            GUI::EndMenu();
        }
        if (GUI::BeginMenu("Edit"))
        {
            if (GUI::MenuItem("Undo", "CTRL+Z")) {}
            if (GUI::MenuItem("Redo", "CTRL+Y", false, false)) {}  // Disabled item
            GUI::Separator();
            if (GUI::MenuItem("Cut", "CTRL+X")) {}
            if (GUI::MenuItem("Copy", "CTRL+C")) {}
            if (GUI::MenuItem("Paste", "CTRL+V")) {}
            GUI::EndMenu();
        }
        GUI::EndMainMenuBar();
    }
}

// Note that shortcuts are currently provided for display only
// (future version will add explicit flags to BeginMenu() to request processing shortcuts)
static void ShowExampleMenuFile()
{
    GUI::MenuItem("(demo menu)", NULL, false, false);
    if (GUI::MenuItem("New")) {}
    if (GUI::MenuItem("Open", "Ctrl+O")) {}
    if (GUI::BeginMenu("Open Recent"))
    {
        GUI::MenuItem("fish_hat.c");
        GUI::MenuItem("fish_hat.inl");
        GUI::MenuItem("fish_hat.h");
        if (GUI::BeginMenu("More.."))
        {
            GUI::MenuItem("Hello");
            GUI::MenuItem("Sailor");
            if (GUI::BeginMenu("Recurse.."))
            {
                ShowExampleMenuFile();
                GUI::EndMenu();
            }
            GUI::EndMenu();
        }
        GUI::EndMenu();
    }
    if (GUI::MenuItem("Save", "Ctrl+S")) {}
    if (GUI::MenuItem("Save As..")) {}

    GUI::Separator();
    if (GUI::BeginMenu("Options"))
    {
        static bool enabled = true;
        GUI::MenuItem("Enabled", "", &enabled);
        GUI::BeginChild("child", ImVec2(0, 60), true);
        for (int i = 0; i < 10; i++)
            GUI::Text("Scrolling Text %d", i);
        GUI::EndChild();
        static float f = 0.5f;
        static int n = 0;
        GUI::SliderFloat("Value", &f, 0.0f, 1.0f);
        GUI::InputFloat("Input", &f, 0.1f);
        GUI::Combo("Combo", &n, "Yes\0No\0Maybe\0\0");
        GUI::EndMenu();
    }

    if (GUI::BeginMenu("Colors"))
    {
        float sz = GUI::GetTextLineHeight();
        for (int i = 0; i < ImGuiCol_COUNT; i++)
        {
            const char* name = GUI::GetStyleColorName((ImGuiCol)i);
            ImVec2 p = GUI::GetCursorScreenPos();
            GUI::GetWindowDrawList()->AddRectFilled(p, ImVec2(p.x + sz, p.y + sz), GUI::GetColorU32((ImGuiCol)i));
            GUI::Dummy(ImVec2(sz, sz));
            GUI::SameLine();
            GUI::MenuItem(name);
        }
        GUI::EndMenu();
    }

    // Here we demonstrate appending again to the "Options" menu (which we already created above)
    // Of course in this demo it is a little bit silly that this function calls BeginMenu("Options") twice.
    // In a real code-base using it would make senses to use this feature from very different code locations.
    if (GUI::BeginMenu("Options")) // <-- Append!
    {
        static bool b = true;
        GUI::Checkbox("SomeOption", &b);
        GUI::EndMenu();
    }

    if (GUI::BeginMenu("Disabled", false)) // Disabled
    {
        IM_ASSERT(0);
    }
    if (GUI::MenuItem("Checked", NULL, true)) {}
    if (GUI::MenuItem("Quit", "Alt+F4")) {}
}

//-----------------------------------------------------------------------------
// [SECTION] Example App: Debug Console / ShowExampleAppConsole()
//-----------------------------------------------------------------------------

// Demonstrate creating a simple console window, with scrolling, filtering, completion and history.
// For the console example, we are using a more C++ like approach of declaring a class to hold both data and functions.
struct ExampleAppConsole
{
    char                  InputBuf[256];
    ImVector<char*>       Items;
    ImVector<const char*> Commands;
    ImVector<char*>       History;
    int                   HistoryPos;    // -1: new line, 0..History.Size-1 browsing history.
    ImGuiTextFilter       Filter;
    bool                  AutoScroll;
    bool                  ScrollToBottom;

    ExampleAppConsole()
    {
        ClearLog();
        memset(InputBuf, 0, sizeof(InputBuf));
        HistoryPos = -1;

        // "CLASSIFY" is here to provide the test case where "C"+[tab] completes to "CL" and display multiple matches.
        Commands.push_back("HELP");
        Commands.push_back("HISTORY");
        Commands.push_back("CLEAR");
        Commands.push_back("CLASSIFY");
        AutoScroll = true;
        ScrollToBottom = false;
        AddLog("Welcome to Dear ImGui!");
    }
    ~ExampleAppConsole()
    {
        ClearLog();
        for (int i = 0; i < History.Size; i++)
            free(History[i]);
    }

    // Portable helpers
    static int   Stricmp(const char* s1, const char* s2)         { int d; while ((d = toupper(*s2) - toupper(*s1)) == 0 && *s1) { s1++; s2++; } return d; }
    static int   Strnicmp(const char* s1, const char* s2, int n) { int d = 0; while (n > 0 && (d = toupper(*s2) - toupper(*s1)) == 0 && *s1) { s1++; s2++; n--; } return d; }
    static char* Strdup(const char* s)                           { size_t len = strlen(s) + 1; void* buf = malloc(len); IM_ASSERT(buf); return (char*)memcpy(buf, (const void*)s, len); }
    static void  Strtrim(char* s)                                { char* str_end = s + strlen(s); while (str_end > s && str_end[-1] == ' ') str_end--; *str_end = 0; }

    void    ClearLog()
    {
        for (int i = 0; i < Items.Size; i++)
            free(Items[i]);
        Items.clear();
    }

    void    AddLog(const char* fmt, ...) IM_FMTARGS(2)
    {
        // FIXME-OPT
        char buf[1024];
        va_list args;
        va_start(args, fmt);
        vsnprintf(buf, IM_ARRAYSIZE(buf), fmt, args);
        buf[IM_ARRAYSIZE(buf)-1] = 0;
        va_end(args);
        Items.push_back(Strdup(buf));
    }

    void    Draw(const char* title, bool* p_open)
    {
        GUI::SetNextWindowSize(ImVec2(520, 600), ImGuiCond_FirstUseEver);
        if (!GUI::Begin(title, p_open))
        {
            GUI::End();
            return;
        }

        // As a specific feature guaranteed by the library, after calling Begin() the last Item represent the title bar.
        // So e.g. IsItemHovered() will return true when hovering the title bar.
        // Here we create a context menu only available from the title bar.
        if (GUI::BeginPopupContextItem())
        {
            if (GUI::MenuItem("Close Console"))
                *p_open = false;
            GUI::EndPopup();
        }

        GUI::TextWrapped(
            "This example implements a console with basic coloring, completion and history. A more elaborate "
            "implementation may want to store entries along with extra data such as timestamp, emitter, etc.");
        GUI::TextWrapped("Enter 'HELP' for help, press TAB to use text completion.");

        // TODO: display items starting from the bottom

        if (GUI::SmallButton("Add Debug Text"))  { AddLog("%d some text", Items.Size); AddLog("some more text"); AddLog("display very important message here!"); } GUI::SameLine();
        if (GUI::SmallButton("Add Debug Error")) { AddLog("[error] something went wrong"); } GUI::SameLine();
        if (GUI::SmallButton("Clear"))           { ClearLog(); } GUI::SameLine();
        bool copy_to_clipboard = GUI::SmallButton("Copy");
        //static float t = 0.0f; if (GUI::GetTime() - t > 0.02f) { t = GUI::GetTime(); AddLog("Spam %f", t); }

        GUI::Separator();

        // Options menu
        if (GUI::BeginPopup("Options"))
        {
            GUI::Checkbox("Auto-scroll", &AutoScroll);
            GUI::EndPopup();
        }

        // Options, Filter
        if (GUI::Button("Options"))
            GUI::OpenPopup("Options");
        GUI::SameLine();
        Filter.Draw("Filter (\"incl,-excl\") (\"error\")", 180);
        GUI::Separator();

        // Reserve enough left-over height for 1 separator + 1 input text
        const float footer_height_to_reserve = GUI::GetStyle().ItemSpacing.y + GUI::GetFrameHeightWithSpacing();
        GUI::BeginChild("ScrollingRegion", ImVec2(0, -footer_height_to_reserve), false, ImGuiWindowFlags_HorizontalScrollbar);
        if (GUI::BeginPopupContextWindow())
        {
            if (GUI::Selectable("Clear")) ClearLog();
            GUI::EndPopup();
        }

        // Display every line as a separate entry so we can change their color or add custom widgets.
        // If you only want raw text you can use GUI::TextUnformatted(log.begin(), log.end());
        // NB- if you have thousands of entries this approach may be too inefficient and may require user-side clipping
        // to only process visible items. The clipper will automatically measure the height of your first item and then
        // "seek" to display only items in the visible area.
        // To use the clipper we can replace your standard loop:
        //      for (int i = 0; i < Items.Size; i++)
        //   With:
        //      ImGuiListClipper clipper(Items.Size);
        //      while (clipper.Step())
        //         for (int i = clipper.DisplayStart; i < clipper.DisplayEnd; i++)
        // - That your items are evenly spaced (same height)
        // - That you have cheap random access to your elements (you can access them given their index,
        //   without processing all the ones before)
        // You cannot this code as-is if a filter is active because it breaks the 'cheap random-access' property.
        // We would need random-access on the post-filtered list.
        // A typical application wanting coarse clipping and filtering may want to pre-compute an array of indices
        // or offsets of items that passed the filtering test, recomputing this array when user changes the filter,
        // and appending newly elements as they are inserted. This is left as a task to the user until we can manage
        // to improve this example code!
        // If your items are of variable height:
        // - Split them into same height items would be simpler and facilitate random-seeking into your list.
        // - Consider using manual call to IsRectVisible() and skipping extraneous decoration from your items.
        GUI::PushStyleVar(imgui_styleVar_ItemSpacing, ImVec2(4, 1)); // Tighten spacing
        if (copy_to_clipboard)
            GUI::LogToClipboard();
        for (int i = 0; i < Items.Size; i++)
        {
            const char* item = Items[i];
            if (!Filter.PassFilter(item))
                continue;

            // Normally you would store more information in your item than just a string.
            // (e.g. make Items[] an array of structure, store color/type etc.)
            ImVec4 color;
            bool has_color = false;
            if (strstr(item, "[error]"))          { color = ImVec4(1.0f, 0.4f, 0.4f, 1.0f); has_color = true; }
            else if (strncmp(item, "# ", 2) == 0) { color = ImVec4(1.0f, 0.8f, 0.6f, 1.0f); has_color = true; }
            if (has_color)
                GUI::PushStyleColor(ImGuiCol_Text, color);
            GUI::TextUnformatted(item);
            if (has_color)
                GUI::PopStyleColor();
        }
        if (copy_to_clipboard)
            GUI::LogFinish();

        if (ScrollToBottom || (AutoScroll && GUI::GetScrollY() >= GUI::GetScrollMaxY()))
            GUI::SetScrollHereY(1.0f);
        ScrollToBottom = false;

        GUI::PopStyleVar();
        GUI::EndChild();
        GUI::Separator();

        // Command-line
        bool reclaim_focus = false;
        ImGuiInputTextFlags input_text_flags = ImGuiInputTextFlags_EnterReturnsTrue | ImGuiInputTextFlags_CallbackCompletion | ImGuiInputTextFlags_CallbackHistory;
        if (GUI::InputText("Input", InputBuf, IM_ARRAYSIZE(InputBuf), input_text_flags, &TextEditCallbackStub, (void*)this))
        {
            char* s = InputBuf;
            Strtrim(s);
            if (s[0])
                ExecCommand(s);
            strcpy(s, "");
            reclaim_focus = true;
        }

        // Auto-focus on window apparition
        GUI::SetItemDefaultFocus();
        if (reclaim_focus)
            GUI::SetKeyboardFocusHere(-1); // Auto focus previous widget

        GUI::End();
    }

    void    ExecCommand(const char* command_line)
    {
        AddLog("# %s\n", command_line);

        // Insert into history. First find match and delete it so it can be pushed to the back.
        // This isn't trying to be smart or optimal.
        HistoryPos = -1;
        for (int i = History.Size - 1; i >= 0; i--)
            if (Stricmp(History[i], command_line) == 0)
            {
                free(History[i]);
                History.erase(History.begin() + i);
                break;
            }
        History.push_back(Strdup(command_line));

        // Process command
        if (Stricmp(command_line, "CLEAR") == 0)
        {
            ClearLog();
        }
        else if (Stricmp(command_line, "HELP") == 0)
        {
            AddLog("Commands:");
            for (int i = 0; i < Commands.Size; i++)
                AddLog("- %s", Commands[i]);
        }
        else if (Stricmp(command_line, "HISTORY") == 0)
        {
            int first = History.Size - 10;
            for (int i = first > 0 ? first : 0; i < History.Size; i++)
                AddLog("%3d: %s\n", i, History[i]);
        }
        else
        {
            AddLog("Unknown command: '%s'\n", command_line);
        }

        // On command input, we scroll to bottom even if AutoScroll==false
        ScrollToBottom = true;
    }

    // In C++11 you'd be better off using lambdas for this sort of forwarding callbacks
    static int TextEditCallbackStub(ImGuiInputTextCallbackData* data)
    {
        ExampleAppConsole* console = (ExampleAppConsole*)data->UserData;
        return console->TextEditCallback(data);
    }

    int     TextEditCallback(ImGuiInputTextCallbackData* data)
    {
        //AddLog("cursor: %d, selection: %d-%d", data->CursorPos, data->SelectionStart, data->SelectionEnd);
        switch (data->EventFlag)
        {
        case ImGuiInputTextFlags_CallbackCompletion:
            {
                // Example of TEXT COMPLETION

                // Locate beginning of current word
                const char* word_end = data->Buf + data->CursorPos;
                const char* word_start = word_end;
                while (word_start > data->Buf)
                {
                    const char c = word_start[-1];
                    if (c == ' ' || c == '\t' || c == ',' || c == ';')
                        break;
                    word_start--;
                }

                // Build a list of candidates
                ImVector<const char*> candidates;
                for (int i = 0; i < Commands.Size; i++)
                    if (Strnicmp(Commands[i], word_start, (int)(word_end - word_start)) == 0)
                        candidates.push_back(Commands[i]);

                if (candidates.Size == 0)
                {
                    // No match
                    AddLog("No match for \"%.*s\"!\n", (int)(word_end - word_start), word_start);
                }
                else if (candidates.Size == 1)
                {
                    // Single match. Delete the beginning of the word and replace it entirely so we've got nice casing.
                    data->DeleteChars((int)(word_start - data->Buf), (int)(word_end - word_start));
                    data->InsertChars(data->CursorPos, candidates[0]);
                    data->InsertChars(data->CursorPos, " ");
                }
                else
                {
                    // Multiple matches. Complete as much as we can..
                    // So inputing "C"+Tab will complete to "CL" then display "CLEAR" and "CLASSIFY" as matches.
                    int match_len = (int)(word_end - word_start);
                    for (;;)
                    {
                        int c = 0;
                        bool all_candidates_matches = true;
                        for (int i = 0; i < candidates.Size && all_candidates_matches; i++)
                            if (i == 0)
                                c = toupper(candidates[i][match_len]);
                            else if (c == 0 || c != toupper(candidates[i][match_len]))
                                all_candidates_matches = false;
                        if (!all_candidates_matches)
                            break;
                        match_len++;
                    }

                    if (match_len > 0)
                    {
                        data->DeleteChars((int)(word_start - data->Buf), (int)(word_end - word_start));
                        data->InsertChars(data->CursorPos, candidates[0], candidates[0] + match_len);
                    }

                    // List matches
                    AddLog("Possible matches:\n");
                    for (int i = 0; i < candidates.Size; i++)
                        AddLog("- %s\n", candidates[i]);
                }

                break;
            }
        case ImGuiInputTextFlags_CallbackHistory:
            {
                // Example of HISTORY
                const int prev_history_pos = HistoryPos;
                if (data->EventKey == ImGuiKey_UpArrow)
                {
                    if (HistoryPos == -1)
                        HistoryPos = History.Size - 1;
                    else if (HistoryPos > 0)
                        HistoryPos--;
                }
                else if (data->EventKey == ImGuiKey_DownArrow)
                {
                    if (HistoryPos != -1)
                        if (++HistoryPos >= History.Size)
                            HistoryPos = -1;
                }

                // A better implementation would preserve the data on the current input line along with cursor position.
                if (prev_history_pos != HistoryPos)
                {
                    const char* history_str = (HistoryPos >= 0) ? History[HistoryPos] : "";
                    data->DeleteChars(0, data->BufTextLen);
                    data->InsertChars(0, history_str);
                }
            }
        }
        return 0;
    }
};

static void ShowExampleAppConsole(bool* p_open)
{
    static ExampleAppConsole console;
    console.Draw("Example: Console", p_open);
}

//-----------------------------------------------------------------------------
// [SECTION] Example App: Debug Log / ShowExampleAppLog()
//-----------------------------------------------------------------------------

// Usage:
//  static ExampleAppLog my_log;
//  my_log.AddLog("Hello %d world\n", 123);
//  my_log.Draw("title");
struct ExampleAppLog
{
    ImGuiTextBuffer     Buf;
    ImGuiTextFilter     Filter;
    ImVector<int>       LineOffsets; // Index to lines offset. We maintain this with AddLog() calls.
    bool                AutoScroll;  // Keep scrolling if already at the bottom.

    ExampleAppLog()
    {
        AutoScroll = true;
        Clear();
    }

    void    Clear()
    {
        Buf.clear();
        LineOffsets.clear();
        LineOffsets.push_back(0);
    }

    void    AddLog(const char* fmt, ...) IM_FMTARGS(2)
    {
        int old_size = Buf.size();
        va_list args;
        va_start(args, fmt);
        Buf.appendfv(fmt, args);
        va_end(args);
        for (int new_size = Buf.size(); old_size < new_size; old_size++)
            if (Buf[old_size] == '\n')
                LineOffsets.push_back(old_size + 1);
    }

    void    Draw(const char* title, bool* p_open = NULL)
    {
        if (!GUI::Begin(title, p_open))
        {
            GUI::End();
            return;
        }

        // Options menu
        if (GUI::BeginPopup("Options"))
        {
            GUI::Checkbox("Auto-scroll", &AutoScroll);
            GUI::EndPopup();
        }

        // Main window
        if (GUI::Button("Options"))
            GUI::OpenPopup("Options");
        GUI::SameLine();
        bool clear = GUI::Button("Clear");
        GUI::SameLine();
        bool copy = GUI::Button("Copy");
        GUI::SameLine();
        Filter.Draw("Filter", -100.0f);

        GUI::Separator();
        GUI::BeginChild("scrolling", ImVec2(0, 0), false, ImGuiWindowFlags_HorizontalScrollbar);

        if (clear)
            Clear();
        if (copy)
            GUI::LogToClipboard();

        GUI::PushStyleVar(imgui_styleVar_ItemSpacing, ImVec2(0, 0));
        const char* buf = Buf.begin();
        const char* buf_end = Buf.end();
        if (Filter.IsActive())
        {
            // In this example we don't use the clipper when Filter is enabled.
            // This is because we don't have a random access on the result on our filter.
            // A real application processing logs with ten of thousands of entries may want to store the result of
            // search/filter.. especially if the filtering function is not trivial (e.g. reg-exp).
            for (int line_no = 0; line_no < LineOffsets.Size; line_no++)
            {
                const char* line_start = buf + LineOffsets[line_no];
                const char* line_end = (line_no + 1 < LineOffsets.Size) ? (buf + LineOffsets[line_no + 1] - 1) : buf_end;
                if (Filter.PassFilter(line_start, line_end))
                    GUI::TextUnformatted(line_start, line_end);
            }
        }
        else
        {
            // The simplest and easy way to display the entire buffer:
            //   GUI::TextUnformatted(buf_begin, buf_end);
            // And it'll just work. TextUnformatted() has specialization for large blob of text and will fast-forward
            // to skip non-visible lines. Here we instead demonstrate using the clipper to only process lines that are
            // within the visible area.
            // If you have tens of thousands of items and their processing cost is non-negligible, coarse clipping them
            // on your side is recommended. Using ImGuiListClipper requires
            // - A) random access into your data
            // - B) items all being the  same height,
            // both of which we can handle since we an array pointing to the beginning of each line of text.
            // When using the filter (in the block of code above) we don't have random access into the data to display
            // anymore, which is why we don't use the clipper. Storing or skimming through the search result would make
            // it possible (and would be recommended if you want to search through tens of thousands of entries).
            ImGuiListClipper clipper;
            clipper.Begin(LineOffsets.Size);
            while (clipper.Step())
            {
                for (int line_no = clipper.DisplayStart; line_no < clipper.DisplayEnd; line_no++)
                {
                    const char* line_start = buf + LineOffsets[line_no];
                    const char* line_end = (line_no + 1 < LineOffsets.Size) ? (buf + LineOffsets[line_no + 1] - 1) : buf_end;
                    GUI::TextUnformatted(line_start, line_end);
                }
            }
            clipper.End();
        }
        GUI::PopStyleVar();

        if (AutoScroll && GUI::GetScrollY() >= GUI::GetScrollMaxY())
            GUI::SetScrollHereY(1.0f);

        GUI::EndChild();
        GUI::End();
    }
};

// Demonstrate creating a simple log window with basic filtering.
static void ShowExampleAppLog(bool* p_open)
{
    static ExampleAppLog log;

    // For the demo: add a debug button _BEFORE_ the normal log window contents
    // We take advantage of a rarely used feature: multiple calls to Begin()/End() are appending to the _same_ window.
    // Most of the contents of the window will be added by the log.Draw() call.
    GUI::SetNextWindowSize(ImVec2(500, 400), ImGuiCond_FirstUseEver);
    GUI::Begin("Example: Log", p_open);
    if (GUI::SmallButton("[Debug] Add 5 entries"))
    {
        static int counter = 0;
        const char* categories[3] = { "info", "warn", "error" };
        const char* words[] = { "Bumfuzzled", "Cattywampus", "Snickersnee", "Abibliophobia", "Absquatulate", "Nincompoop", "Pauciloquent" };
        for (int n = 0; n < 5; n++)
        {
            const char* category = categories[counter % IM_ARRAYSIZE(categories)];
            const char* word = words[counter % IM_ARRAYSIZE(words)];
            log.AddLog("[%05d] [%s] Hello, current time is %.1f, here's a word: '%s'\n",
                GUI::GetFrameCount(), category, GUI::GetTime(), word);
            counter++;
        }
    }
    GUI::End();

    // Actually call in the regular Log helper (which will Begin() into the same window as we just did)
    log.Draw("Example: Log", p_open);
}

//-----------------------------------------------------------------------------
// [SECTION] Example App: Simple Layout / ShowExampleAppLayout()
//-----------------------------------------------------------------------------

// Demonstrate create a window with multiple child windows.
static void ShowExampleAppLayout(bool* p_open)
{
    GUI::SetNextWindowSize(ImVec2(500, 440), ImGuiCond_FirstUseEver);
    if (GUI::Begin("Example: Simple layout", p_open, ImGuiWindowFlags_MenuBar))
    {
        if (GUI::BeginMenuBar())
        {
            if (GUI::BeginMenu("File"))
            {
                if (GUI::MenuItem("Close")) *p_open = false;
                GUI::EndMenu();
            }
            GUI::EndMenuBar();
        }

        // Left
        static int selected = 0;
        {
            GUI::BeginChild("left pane", ImVec2(150, 0), true);
            for (int i = 0; i < 100; i++)
            {
                char label[128];
                sprintf(label, "MyObject %d", i);
                if (GUI::Selectable(label, selected == i))
                    selected = i;
            }
            GUI::EndChild();
        }
        GUI::SameLine();

        // Right
        {
            GUI::BeginGroup();
            GUI::BeginChild("item view", ImVec2(0, -GUI::GetFrameHeightWithSpacing())); // Leave room for 1 line below us
            GUI::Text("MyObject: %d", selected);
            GUI::Separator();
            if (GUI::BeginTabBar("##Tabs", ImGuiTabBarFlags_None))
            {
                if (GUI::BeginTabItem("Description"))
                {
                    GUI::TextWrapped("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. ");
                    GUI::EndTabItem();
                }
                if (GUI::BeginTabItem("Details"))
                {
                    GUI::Text("ID: 0123456789");
                    GUI::EndTabItem();
                }
                GUI::EndTabBar();
            }
            GUI::EndChild();
            if (GUI::Button("Revert")) {}
            GUI::SameLine();
            if (GUI::Button("Save")) {}
            GUI::EndGroup();
        }
    }
    GUI::End();
}

//-----------------------------------------------------------------------------
// [SECTION] Example App: Property Editor / ShowExampleAppPropertyEditor()
//-----------------------------------------------------------------------------

static void ShowPlaceholderObject(const char* prefix, int uid)
{
    // Use object uid as identifier. Most commonly you could also use the object pointer as a base ID.
    GUI::PushID(uid);
    GUI::AlignTextToFramePadding();   // Text and Tree nodes are less high than framed widgets, here we add vertical spacing to make the tree lines equal high.
    bool node_open = GUI::TreeNode("Object", "%s_%u", prefix, uid);
    GUI::NextColumn();
    GUI::AlignTextToFramePadding();
    GUI::Text("my sailor is rich");
    GUI::NextColumn();
    if (node_open)
    {
        static float placeholder_members[8] = { 0.0f, 0.0f, 1.0f, 3.1416f, 100.0f, 999.0f };
        for (int i = 0; i < 8; i++)
        {
            GUI::PushID(i); // Use field index as identifier.
            if (i < 2)
            {
                ShowPlaceholderObject("Child", 424242);
            }
            else
            {
                // Here we use a TreeNode to highlight on hover (we could use e.g. Selectable as well)
                GUI::AlignTextToFramePadding();
                ImGuiTreeNodeFlags flags = ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_NoTreePushOnOpen | ImGuiTreeNodeFlags_Bullet;
                GUI::TreeNodeEx("Field", flags, "Field_%d", i);
                GUI::NextColumn();
                GUI::SetNextItemWidth(-1);
                if (i >= 5)
                    GUI::InputFloat("##value", &placeholder_members[i], 1.0f);
                else
                    GUI::DragFloat("##value", &placeholder_members[i], 0.01f);
                GUI::NextColumn();
            }
            GUI::PopID();
        }
        GUI::TreePop();
    }
    GUI::PopID();
}

// Demonstrate create a simple property editor.
static void ShowExampleAppPropertyEditor(bool* p_open)
{
    GUI::SetNextWindowSize(ImVec2(430, 450), ImGuiCond_FirstUseEver);
    if (!GUI::Begin("Example: Property editor", p_open))
    {
        GUI::End();
        return;
    }

    HelpMarker(
        "This example shows how you may implement a property editor using two columns.\n"
        "All objects/fields data are dummies here.\n"
        "Remember that in many simple cases, you can use GUI::SameLine(xxx) to position\n"
        "your cursor horizontally instead of using the Columns() API.");

    GUI::PushStyleVar(imgui_styleVar_FramePadding, ImVec2(2, 2));
    GUI::Columns(2);
    GUI::Separator();

    // Iterate placeholder objects (all the same data)
    for (int obj_i = 0; obj_i < 3; obj_i++)
        ShowPlaceholderObject("Object", obj_i);

    GUI::Columns(1);
    GUI::Separator();
    GUI::PopStyleVar();
    GUI::End();
}

//-----------------------------------------------------------------------------
// [SECTION] Example App: Long Text / ShowExampleAppLongText()
//-----------------------------------------------------------------------------

// Demonstrate/test rendering huge amount of text, and the incidence of clipping.
static void ShowExampleAppLongText(bool* p_open)
{
    GUI::SetNextWindowSize(ImVec2(520, 600), ImGuiCond_FirstUseEver);
    if (!GUI::Begin("Example: Long text display", p_open))
    {
        GUI::End();
        return;
    }

    static int test_type = 0;
    static ImGuiTextBuffer log;
    static int lines = 0;
    GUI::Text("Printing unusually long amount of text.");
    GUI::Combo("Test type", &test_type,
        "Single call to TextUnformatted()\0"
        "Multiple calls to Text(), clipped\0"
        "Multiple calls to Text(), not clipped (slow)\0");
    GUI::Text("Buffer contents: %d lines, %d bytes", lines, log.size());
    if (GUI::Button("Clear")) { log.clear(); lines = 0; }
    GUI::SameLine();
    if (GUI::Button("Add 1000 lines"))
    {
        for (int i = 0; i < 1000; i++)
            log.appendf("%i The quick brown fox jumps over the lazy dog\n", lines + i);
        lines += 1000;
    }
    GUI::BeginChild("Log");
    switch (test_type)
    {
    case 0:
        // Single call to TextUnformatted() with a big buffer
        GUI::TextUnformatted(log.begin(), log.end());
        break;
    case 1:
        {
            // Multiple calls to Text(), manually coarsely clipped - demonstrate how to use the ImGuiListClipper helper.
            GUI::PushStyleVar(imgui_styleVar_ItemSpacing, ImVec2(0, 0));
            ImGuiListClipper clipper(lines);
            while (clipper.Step())
                for (int i = clipper.DisplayStart; i < clipper.DisplayEnd; i++)
                    GUI::Text("%i The quick brown fox jumps over the lazy dog", i);
            GUI::PopStyleVar();
            break;
        }
    case 2:
        // Multiple calls to Text(), not clipped (slow)
        GUI::PushStyleVar(imgui_styleVar_ItemSpacing, ImVec2(0, 0));
        for (int i = 0; i < lines; i++)
            GUI::Text("%i The quick brown fox jumps over the lazy dog", i);
        GUI::PopStyleVar();
        break;
    }
    GUI::EndChild();
    GUI::End();
}

//-----------------------------------------------------------------------------
// [SECTION] Example App: Auto Resize / ShowExampleAppAutoResize()
//-----------------------------------------------------------------------------

// Demonstrate creating a window which gets auto-resized according to its content.
static void ShowExampleAppAutoResize(bool* p_open)
{
    if (!GUI::Begin("Example: Auto-resizing window", p_open, ImGuiWindowFlags_AlwaysAutoResize))
    {
        GUI::End();
        return;
    }

    static int lines = 10;
    GUI::TextUnformatted(
        "Window will resize every-frame to the size of its content.\n"
        "Note that you probably don't want to query the window size to\n"
        "output your content because that would create a feedback loop.");
    GUI::SliderInt("Number of lines", &lines, 1, 20);
    for (int i = 0; i < lines; i++)
        GUI::Text("%*sThis is line %d", i * 4, "", i); // Pad with space to extend size horizontally
    GUI::End();
}

//-----------------------------------------------------------------------------
// [SECTION] Example App: Constrained Resize / ShowExampleAppConstrainedResize()
//-----------------------------------------------------------------------------

// Demonstrate creating a window with custom resize constraints.
static void ShowExampleAppConstrainedResize(bool* p_open)
{
    struct CustomConstraints
    {
        // Helper functions to demonstrate programmatic constraints
        static void Square(ImGuiSizeCallbackData* data) { data->DesiredSize.x = data->DesiredSize.y = IM_MAX(data->DesiredSize.x, data->DesiredSize.y); }
        static void Step(ImGuiSizeCallbackData* data)   { float step = (float)(int)(intptr_t)data->UserData; data->DesiredSize = ImVec2((int)(data->DesiredSize.x / step + 0.5f) * step, (int)(data->DesiredSize.y / step + 0.5f) * step); }
    };

    const char* test_desc[] =
    {
        "Resize vertical only",
        "Resize horizontal only",
        "Width > 100, Height > 100",
        "Width 400-500",
        "Height 400-500",
        "Custom: Always Square",
        "Custom: Fixed Steps (100)",
    };

    static bool auto_resize = false;
    static int type = 0;
    static int display_lines = 10;
    if (type == 0) GUI::SetNextWindowSizeConstraints(ImVec2(-1, 0),    ImVec2(-1, FLT_MAX));      // Vertical only
    if (type == 1) GUI::SetNextWindowSizeConstraints(ImVec2(0, -1),    ImVec2(FLT_MAX, -1));      // Horizontal only
    if (type == 2) GUI::SetNextWindowSizeConstraints(ImVec2(100, 100), ImVec2(FLT_MAX, FLT_MAX)); // Width > 100, Height > 100
    if (type == 3) GUI::SetNextWindowSizeConstraints(ImVec2(400, -1),  ImVec2(500, -1));          // Width 400-500
    if (type == 4) GUI::SetNextWindowSizeConstraints(ImVec2(-1, 400),  ImVec2(-1, 500));          // Height 400-500
    if (type == 5) GUI::SetNextWindowSizeConstraints(ImVec2(0, 0),     ImVec2(FLT_MAX, FLT_MAX), CustomConstraints::Square);                     // Always Square
    if (type == 6) GUI::SetNextWindowSizeConstraints(ImVec2(0, 0),     ImVec2(FLT_MAX, FLT_MAX), CustomConstraints::Step, (void*)(intptr_t)100); // Fixed Step

    ImGuiWindowFlags flags = auto_resize ? ImGuiWindowFlags_AlwaysAutoResize : 0;
    if (GUI::Begin("Example: Constrained Resize", p_open, flags))
    {
        if (GUI::IsWindowDocked())
            GUI::Text("Warning: Sizing Constraints won't work if the window is docked!");
        if (GUI::Button("200x200")) { GUI::SetWindowSize(ImVec2(200, 200)); } GUI::SameLine();
        if (GUI::Button("500x500")) { GUI::SetWindowSize(ImVec2(500, 500)); } GUI::SameLine();
        if (GUI::Button("800x200")) { GUI::SetWindowSize(ImVec2(800, 200)); }
        GUI::SetNextItemWidth(200);
        GUI::Combo("Constraint", &type, test_desc, IM_ARRAYSIZE(test_desc));
        GUI::SetNextItemWidth(200);
        GUI::DragInt("Lines", &display_lines, 0.2f, 1, 100);
        GUI::Checkbox("Auto-resize", &auto_resize);
        for (int i = 0; i < display_lines; i++)
            GUI::Text("%*sHello, sailor! Making this line long enough for the example.", i * 4, "");
    }
    GUI::End();
}

//-----------------------------------------------------------------------------
// [SECTION] Example App: Simple Overlay / ShowExampleAppSimpleOverlay()
//-----------------------------------------------------------------------------

// Demonstrate creating a simple static window with no decoration
// + a context-menu to choose which corner of the screen to use.
static void ShowExampleAppSimpleOverlay(bool* p_open)
{
    // FIXME-VIEWPORT: Select a default viewport
    const float DISTANCE = 10.0f;
    static int corner = 0;
    imgui_io& io = GUI::GetIO();
    if (corner != -1)
    {
        imgui_viewport* viewport = GUI::GetMainViewport();
        ImVec2 work_area_pos = viewport->GetWorkPos();   // Instead of using viewport->Pos we use GetWorkPos() to avoid menu bars, if any!
        ImVec2 work_area_size = viewport->GetWorkSize();
        ImVec2 window_pos = ImVec2((corner & 1) ? (work_area_pos.x + work_area_size.x - DISTANCE) : (work_area_pos.x + DISTANCE), (corner & 2) ? (work_area_pos.y + work_area_size.y - DISTANCE) : (work_area_pos.y + DISTANCE));
        ImVec2 window_pos_pivot = ImVec2((corner & 1) ? 1.0f : 0.0f, (corner & 2) ? 1.0f : 0.0f);
        GUI::SetNextWindowPos(window_pos, ImGuiCond_Always, window_pos_pivot);
        GUI::SetNextWindowViewport(viewport->ID);
    }
    GUI::SetNextWindowBgAlpha(0.35f); // Transparent background
    ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoNav;
    if (corner != -1)
        window_flags |= ImGuiWindowFlags_NoMove;
    if (GUI::Begin("Example: Simple overlay", p_open, window_flags))
    {
        GUI::Text("Simple overlay\n" "in the corner of the screen.\n" "(right-click to change position)");
        GUI::Separator();
        if (GUI::IsMousePosValid())
            GUI::Text("Mouse Position: (%.1f,%.1f)", io.MousePos.x, io.MousePos.y);
        else
            GUI::Text("Mouse Position: <invalid>");
        if (GUI::BeginPopupContextWindow())
        {
            if (GUI::MenuItem("Custom",       NULL, corner == -1)) corner = -1;
            if (GUI::MenuItem("Top-left",     NULL, corner == 0)) corner = 0;
            if (GUI::MenuItem("Top-right",    NULL, corner == 1)) corner = 1;
            if (GUI::MenuItem("Bottom-left",  NULL, corner == 2)) corner = 2;
            if (GUI::MenuItem("Bottom-right", NULL, corner == 3)) corner = 3;
            if (p_open && GUI::MenuItem("Close")) *p_open = false;
            GUI::EndPopup();
        }
    }
    GUI::End();
}

//-----------------------------------------------------------------------------
// [SECTION] Example App: Manipulating Window Titles / ShowExampleCoreWindowTitles()
//-----------------------------------------------------------------------------

// Demonstrate using "##" and "###" in identifiers to manipulate ID generation.
// This apply to all regular items as well.
// Read FAQ section "How can I have multiple widgets with the same label?" for details.
static void ShowExampleCoreWindowTitles(bool*)
{
    // By default, Windows are uniquely identified by their title.
    // You can use the "##" and "###" markers to manipulate the display/ID.

    // Using "##" to display same title but have unique identifier.
    GUI::SetNextWindowPos(ImVec2(100, 100), ImGuiCond_FirstUseEver);
    GUI::Begin("Same title as another window##1");
    GUI::Text("This is window 1.\nMy title is the same as window 2, but my identifier is unique.");
    GUI::End();

    GUI::SetNextWindowPos(ImVec2(100, 200), ImGuiCond_FirstUseEver);
    GUI::Begin("Same title as another window##2");
    GUI::Text("This is window 2.\nMy title is the same as window 1, but my identifier is unique.");
    GUI::End();

    // Using "###" to display a changing title but keep a static identifier "AnimatedTitle"
    char buf[128];
    sprintf(buf, "Animated title %c %d###AnimatedTitle", "|/-\\"[(int)(GUI::GetTime() / 0.25f) & 3], GUI::GetFrameCount());
    GUI::SetNextWindowPos(ImVec2(100, 300), ImGuiCond_FirstUseEver);
    GUI::Begin(buf);
    GUI::Text("This window has a changing title.");
    GUI::End();
}

//-----------------------------------------------------------------------------
// [SECTION] Example App: Custom Rendering using imgui_draw_list API / ShowExampleAppCustomRendering()
//-----------------------------------------------------------------------------

// Demonstrate using the low-level imgui_draw_list to draw custom shapes.
static void ShowExampleAppCustomRendering(bool* p_open)
{
    if (!GUI::Begin("Example: Custom rendering", p_open))
    {
        GUI::End();
        return;
    }

    // Tip: If you do a lot of custom rendering, you probably want to use your own geometrical types and benefit of
    // overloaded operators, etc. Define IM_VEC2_CLASS_EXTRA in imconfig.h to create implicit conversions between your
    // types and ImVec2/ImVec4. Dear ImGui defines overloaded operators but they are internal to imgui.cpp and not
    // exposed outside (to avoid messing with your types) In this example we are not using the maths operators!

    if (GUI::BeginTabBar("##TabBar"))
    {
        if (GUI::BeginTabItem("Primitives"))
        {
            GUI::PushItemWidth(-GUI::GetFontSize() * 10);
            imgui_draw_list* draw_list = GUI::GetWindowDrawList();

            // Draw gradients
            // (note that those are currently exacerbating our sRGB/Linear issues)
            // Calling GUI::GetColorU32() multiplies the given colors by the current Style Alpha, but you may pass the IM_COL32() directly as well..
            GUI::Text("Gradients");
            ImVec2 gradient_size = ImVec2(GUI::CalcItemWidth(), GUI::GetFrameHeight());
            {
                ImVec2 p0 = GUI::GetCursorScreenPos();
                ImVec2 p1 = ImVec2(p0.x + gradient_size.x, p0.y + gradient_size.y);
                ImU32 col_a = GUI::GetColorU32(IM_COL32(0, 0, 0, 255));
                ImU32 col_b = GUI::GetColorU32(IM_COL32(255, 255, 255, 255));
                draw_list->AddRectFilledMultiColor(p0, p1, col_a, col_b, col_b, col_a);
                GUI::InvisibleButton("##gradient1", gradient_size);
            }
            {
                ImVec2 p0 = GUI::GetCursorScreenPos();
                ImVec2 p1 = ImVec2(p0.x + gradient_size.x, p0.y + gradient_size.y);
                ImU32 col_a = GUI::GetColorU32(IM_COL32(0, 255, 0, 255));
                ImU32 col_b = GUI::GetColorU32(IM_COL32(255, 0, 0, 255));
                draw_list->AddRectFilledMultiColor(p0, p1, col_a, col_b, col_b, col_a);
                GUI::InvisibleButton("##gradient2", gradient_size);
            }

            // Draw a bunch of primitives
            GUI::Text("All primitives");
            static float sz = 36.0f;
            static float thickness = 3.0f;
            static int ngon_sides = 6;
            static bool circle_segments_override = false;
            static int circle_segments_override_v = 12;
            static ImVec4 colf = ImVec4(1.0f, 1.0f, 0.4f, 1.0f);
            GUI::DragFloat("Size", &sz, 0.2f, 2.0f, 72.0f, "%.0f");
            GUI::DragFloat("Thickness", &thickness, 0.05f, 1.0f, 8.0f, "%.02f");
            GUI::SliderInt("N-gon sides", &ngon_sides, 3, 12);
            GUI::Checkbox("##circlesegmentoverride", &circle_segments_override);
            GUI::SameLine(0.0f, GUI::GetStyle().ItemInnerSpacing.x);
            if (GUI::SliderInt("Circle segments", &circle_segments_override_v, 3, 40))
                circle_segments_override = true;
            GUI::ColorEdit4("Color", &colf.x);

            const ImVec2 p = GUI::GetCursorScreenPos();
            const ImU32 col = ImColor(colf);
            const float spacing = 10.0f;
            const ImDrawCornerFlags corners_none = 0;
            const ImDrawCornerFlags corners_all = ImDrawCornerFlags_All;
            const ImDrawCornerFlags corners_tl_br = ImDrawCornerFlags_TopLeft | ImDrawCornerFlags_BotRight;
            const int circle_segments = circle_segments_override ? circle_segments_override_v : 0;
            float x = p.x + 4.0f;
            float y = p.y + 4.0f;
            for (int n = 0; n < 2; n++)
            {
                // First line uses a thickness of 1.0f, second line uses the configurable thickness
                float th = (n == 0) ? 1.0f : thickness;
                draw_list->AddNgon(ImVec2(x + sz*0.5f, y + sz*0.5f), sz*0.5f, col, ngon_sides, th);                 x += sz + spacing;  // N-gon
                draw_list->AddCircle(ImVec2(x + sz*0.5f, y + sz*0.5f), sz*0.5f, col, circle_segments, th);          x += sz + spacing;  // Circle
                draw_list->AddRect(ImVec2(x, y), ImVec2(x + sz, y + sz), col, 0.0f,  corners_none, th);             x += sz + spacing;  // Square
                draw_list->AddRect(ImVec2(x, y), ImVec2(x + sz, y + sz), col, 10.0f, corners_all, th);              x += sz + spacing;  // Square with all rounded corners
                draw_list->AddRect(ImVec2(x, y), ImVec2(x + sz, y + sz), col, 10.0f, corners_tl_br, th);            x += sz + spacing;  // Square with two rounded corners
                draw_list->AddTriangle(ImVec2(x+sz*0.5f,y), ImVec2(x+sz, y+sz-0.5f), ImVec2(x, y+sz-0.5f), col, th);x += sz + spacing;  // Triangle
                //draw_list->AddTriangle(ImVec2(x+sz*0.2f,y), ImVec2(x, y+sz-0.5f), ImVec2(x+sz*0.4f, y+sz-0.5f), col, th);x+= sz*0.4f + spacing; // Thin triangle
                draw_list->AddLine(ImVec2(x, y), ImVec2(x + sz, y), col, th);                                       x += sz + spacing;  // Horizontal line (note: drawing a filled rectangle will be faster!)
                draw_list->AddLine(ImVec2(x, y), ImVec2(x, y + sz), col, th);                                       x += spacing;       // Vertical line (note: drawing a filled rectangle will be faster!)
                draw_list->AddLine(ImVec2(x, y), ImVec2(x + sz, y + sz), col, th);                                  x += sz + spacing;  // Diagonal line
                draw_list->AddBezierCurve(ImVec2(x, y), ImVec2(x + sz*1.3f, y + sz*0.3f), ImVec2(x + sz - sz*1.3f, y + sz - sz*0.3f), ImVec2(x + sz, y + sz), col, th);
                x = p.x + 4;
                y += sz + spacing;
            }
            draw_list->AddNgonFilled(ImVec2(x + sz * 0.5f, y + sz * 0.5f), sz*0.5f, col, ngon_sides);               x += sz + spacing;  // N-gon
            draw_list->AddCircleFilled(ImVec2(x + sz*0.5f, y + sz*0.5f), sz*0.5f, col, circle_segments);            x += sz + spacing;  // Circle
            draw_list->AddRectFilled(ImVec2(x, y), ImVec2(x + sz, y + sz), col);                                    x += sz + spacing;  // Square
            draw_list->AddRectFilled(ImVec2(x, y), ImVec2(x + sz, y + sz), col, 10.0f);                             x += sz + spacing;  // Square with all rounded corners
            draw_list->AddRectFilled(ImVec2(x, y), ImVec2(x + sz, y + sz), col, 10.0f, corners_tl_br);              x += sz + spacing;  // Square with two rounded corners
            draw_list->AddTriangleFilled(ImVec2(x+sz*0.5f,y), ImVec2(x+sz, y+sz-0.5f), ImVec2(x, y+sz-0.5f), col);  x += sz + spacing;  // Triangle
            //draw_list->AddTriangleFilled(ImVec2(x+sz*0.2f,y), ImVec2(x, y+sz-0.5f), ImVec2(x+sz*0.4f, y+sz-0.5f), col); x += sz*0.4f + spacing; // Thin triangle
            draw_list->AddRectFilled(ImVec2(x, y), ImVec2(x + sz, y + thickness), col);                             x += sz + spacing;  // Horizontal line (faster than AddLine, but only handle integer thickness)
            draw_list->AddRectFilled(ImVec2(x, y), ImVec2(x + thickness, y + sz), col);                             x += spacing * 2.0f;// Vertical line (faster than AddLine, but only handle integer thickness)
            draw_list->AddRectFilled(ImVec2(x, y), ImVec2(x + 1, y + 1), col);                                      x += sz;            // Pixel (faster than AddLine)
            draw_list->AddRectFilledMultiColor(ImVec2(x, y), ImVec2(x + sz, y + sz), IM_COL32(0, 0, 0, 255), IM_COL32(255, 0, 0, 255), IM_COL32(255, 255, 0, 255), IM_COL32(0, 255, 0, 255));

            GUI::Dummy(ImVec2((sz + spacing) * 8.8f, (sz + spacing) * 3.0f));
            GUI::PopItemWidth();
            GUI::EndTabItem();
        }

        if (GUI::BeginTabItem("Canvas"))
        {
            static ImVector<ImVec2> points;
            static ImVec2 scrolling(0.0f, 0.0f);
            static bool opt_enable_grid = true;
            static bool opt_enable_context_menu = true;
            static bool adding_line = false;

            GUI::Checkbox("Enable grid", &opt_enable_grid);
            GUI::Checkbox("Enable context menu", &opt_enable_context_menu);
            GUI::Text("Mouse Left: drag to add lines,\nMouse Right: drag to scroll, click for context menu.");

            // Typically you would use a BeginChild()/EndChild() pair to benefit from a clipping region + own scrolling.
            // Here we demonstrate that this can be replaced by simple offsetting + custom drawing + PushClipRect/PopClipRect() calls.
            // To use a child window instead we could use, e.g:
            //      GUI::PushStyleVar(imgui_styleVar_WindowPadding, ImVec2(0, 0));      // Disable padding
            //      GUI::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(50, 50, 50, 255));  // Set a background color
            //      GUI::BeginChild("canvas", ImVec2(0.0f, 0.0f), true, ImGuiWindowFlags_NoMove);
            //      GUI::PopStyleColor();
            //      GUI::PopStyleVar();
            //      [...]
            //      GUI::EndChild();

            // Using InvisibleButton() as a convenience 1) it will advance the layout cursor and 2) allows us to use IsItemHovered()/IsItemActive()
            ImVec2 canvas_p0 = GUI::GetCursorScreenPos();      // imgui_draw_list API uses screen coordinates!
            ImVec2 canvas_sz = GUI::GetContentRegionAvail();   // Resize canvas to what's available
            if (canvas_sz.x < 50.0f) canvas_sz.x = 50.0f;
            if (canvas_sz.y < 50.0f) canvas_sz.y = 50.0f;
            ImVec2 canvas_p1 = ImVec2(canvas_p0.x + canvas_sz.x, canvas_p0.y + canvas_sz.y);

            // Draw border and background color
            imgui_io& io = GUI::GetIO();
            imgui_draw_list* draw_list = GUI::GetWindowDrawList();
            draw_list->AddRectFilled(canvas_p0, canvas_p1, IM_COL32(50, 50, 50, 255));
            draw_list->AddRect(canvas_p0, canvas_p1, IM_COL32(255, 255, 255, 255));

            // This will catch our interactions
            GUI::InvisibleButton("canvas", canvas_sz, ImGuiButtonFlags_MouseButtonLeft | ImGuiButtonFlags_MouseButtonRight);
            const bool is_hovered = GUI::IsItemHovered(); // Hovered
            const bool is_active = GUI::IsItemActive();   // Held
            const ImVec2 origin(canvas_p0.x + scrolling.x, canvas_p0.y + scrolling.y); // Lock scrolled origin
            const ImVec2 mouse_pos_in_canvas(io.MousePos.x - origin.x, io.MousePos.y - origin.y);

            // Add first and second point
            if (is_hovered && !adding_line && GUI::IsMouseClicked(ImGuiMouseButton_Left))
            {
                points.push_back(mouse_pos_in_canvas);
                points.push_back(mouse_pos_in_canvas);
                adding_line = true;
            }
            if (adding_line)
            {
                points.back() = mouse_pos_in_canvas;
                if (!GUI::IsMouseDown(ImGuiMouseButton_Left))
                    adding_line = false;
            }

            // Pan (we use a zero mouse threshold when there's no context menu)
            // You may decide to make that threshold dynamic based on whether the mouse is hovering something etc.
            const float mouse_threshold_for_pan = opt_enable_context_menu ? -1.0f : 0.0f;
            if (is_active && GUI::IsMouseDragging(ImGuiMouseButton_Right, mouse_threshold_for_pan))
            {
                scrolling.x += io.MouseDelta.x;
                scrolling.y += io.MouseDelta.y;
            }

            // Context menu (under default mouse threshold)
            ImVec2 drag_delta = GUI::GetMouseDragDelta(ImGuiMouseButton_Right);
            if (opt_enable_context_menu && GUI::IsMouseReleased(ImGuiMouseButton_Right) && drag_delta.x == 0.0f && drag_delta.y == 0.0f)
                GUI::OpenPopupContextItem("context");
            if (GUI::BeginPopup("context"))
            {
                if (adding_line)
                    points.resize(points.size() - 2);
                adding_line = false;
                if (GUI::MenuItem("Remove one", NULL, false, points.Size > 0)) { points.resize(points.size() - 2); }
                if (GUI::MenuItem("Remove all", NULL, false, points.Size > 0)) { points.clear(); }
                GUI::EndPopup();
            }

            // Draw grid + all lines in the canvas
            draw_list->PushClipRect(canvas_p0, canvas_p1, true);
            if (opt_enable_grid)
            {
                const float GRID_STEP = 64.0f;
                for (float x = fmodf(scrolling.x, GRID_STEP); x < canvas_sz.x; x += GRID_STEP)
                    draw_list->AddLine(ImVec2(canvas_p0.x + x, canvas_p0.y), ImVec2(canvas_p0.x + x, canvas_p1.y), IM_COL32(200, 200, 200, 40));
                for (float y = fmodf(scrolling.y, GRID_STEP); y < canvas_sz.y; y += GRID_STEP)
                    draw_list->AddLine(ImVec2(canvas_p0.x, canvas_p0.y + y), ImVec2(canvas_p1.x, canvas_p0.y + y), IM_COL32(200, 200, 200, 40));
            }
            for (int n = 0; n < points.Size; n += 2)
                draw_list->AddLine(ImVec2(origin.x + points[n].x, origin.y + points[n].y), ImVec2(origin.x + points[n + 1].x, origin.y + points[n + 1].y), IM_COL32(255, 255, 0, 255), 2.0f);
            draw_list->PopClipRect();

            GUI::EndTabItem();
        }

        if (GUI::BeginTabItem("BG/FG draw lists"))
        {
            static bool draw_bg = true;
            static bool draw_fg = true;
            GUI::Checkbox("Draw in Background draw list", &draw_bg);
            GUI::SameLine(); HelpMarker("The Background draw list will be rendered below every Dear ImGui windows.");
            GUI::Checkbox("Draw in Foreground draw list", &draw_fg);
            GUI::SameLine(); HelpMarker("The Foreground draw list will be rendered over every Dear ImGui windows.");
            ImVec2 window_pos = GUI::GetWindowPos();
            ImVec2 window_size = GUI::GetWindowSize();
            ImVec2 window_center = ImVec2(window_pos.x + window_size.x * 0.5f, window_pos.y + window_size.y * 0.5f);
            if (draw_bg)
                GUI::GetBackgroundDrawList()->AddCircle(window_center, window_size.x * 0.6f, IM_COL32(255, 0, 0, 200), 0, 10 + 4);
            if (draw_fg)
                GUI::GetForegroundDrawList()->AddCircle(window_center, window_size.y * 0.6f, IM_COL32(0, 255, 0, 200), 0, 10);
            GUI::EndTabItem();
        }

        GUI::EndTabBar();
    }

    GUI::End();
}

//-----------------------------------------------------------------------------
// [SECTION] Example App: Docking, DockSpace / ShowExampleAppDockSpace()
//-----------------------------------------------------------------------------

// Demonstrate using DockSpace() to create an explicit docking node within an existing window.
// Note that you already dock windows into each others _without_ a DockSpace() by just moving windows
// from their title bar (or by holding SHIFT if io.ConfigDockingWithShift is set).
// DockSpace() is only useful to construct to a central location for your application.
void ShowExampleAppDockSpace(bool* p_open)
{
    static bool opt_fullscreen = true;
    static bool opt_padding = false;
    static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

    // We are using the ImGuiWindowFlags_NoDocking flag to make the parent window not dockable into,
    // because it would be confusing to have two docking targets within each others.
    ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
    if (opt_fullscreen)
    {
        imgui_viewport* viewport = GUI::GetMainViewport();
        GUI::SetNextWindowPos(viewport->GetWorkPos());
        GUI::SetNextWindowSize(viewport->GetWorkSize());
        GUI::SetNextWindowViewport(viewport->ID);
        GUI::PushStyleVar(imgui_styleVar_WindowRounding, 0.0f);
        GUI::PushStyleVar(imgui_styleVar_WindowBorderSize, 0.0f);
        window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
        window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
    }
    else
    {
        dockspace_flags &= ~ImGuiDockNodeFlags_PassthruCentralNode;
    }

    // When using ImGuiDockNodeFlags_PassthruCentralNode, DockSpace() will render our background
    // and handle the pass-thru hole, so we ask Begin() to not render a background.
    if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode)
        window_flags |= ImGuiWindowFlags_NoBackground;

    // Important: note that we proceed even if Begin() returns false (aka window is collapsed).
    // This is because we want to keep our DockSpace() active. If a DockSpace() is inactive,
    // all active windows docked into it will lose their parent and become undocked.
    // We cannot preserve the docking relationship between an active window and an inactive docking, otherwise
    // any change of dockspace/settings would lead to windows being stuck in limbo and never being visible.
    if (!opt_padding)
        GUI::PushStyleVar(imgui_styleVar_WindowPadding, ImVec2(0.0f, 0.0f));
    GUI::Begin("DockSpace Demo", p_open, window_flags);
    if (!opt_padding)
        GUI::PopStyleVar();

    if (opt_fullscreen)
        GUI::PopStyleVar(2);

    // DockSpace
    imgui_io& io = GUI::GetIO();
    if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
    {
        ImGuiID dockspace_id = GUI::GetID("MyDockSpace");
        GUI::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
    }
    else
    {
        ShowDockingDisabledMessage();
    }

    if (GUI::BeginMenuBar())
    {
        if (GUI::BeginMenu("Options"))
        {
            // Disabling fullscreen would allow the window to be moved to the front of other windows,
            // which we can't undo at the moment without finer window depth/z control.
            GUI::MenuItem("Fullscreen", NULL, &opt_fullscreen);
            GUI::MenuItem("Padding", NULL, &opt_padding);
            GUI::Separator();

            if (GUI::MenuItem("Flag: NoSplit",                "", (dockspace_flags & ImGuiDockNodeFlags_NoSplit) != 0))                 { dockspace_flags ^= ImGuiDockNodeFlags_NoSplit; }
            if (GUI::MenuItem("Flag: NoResize",               "", (dockspace_flags & ImGuiDockNodeFlags_NoResize) != 0))                { dockspace_flags ^= ImGuiDockNodeFlags_NoResize; }
            if (GUI::MenuItem("Flag: NoDockingInCentralNode", "", (dockspace_flags & ImGuiDockNodeFlags_NoDockingInCentralNode) != 0))  { dockspace_flags ^= ImGuiDockNodeFlags_NoDockingInCentralNode; }
            if (GUI::MenuItem("Flag: AutoHideTabBar",         "", (dockspace_flags & ImGuiDockNodeFlags_AutoHideTabBar) != 0))          { dockspace_flags ^= ImGuiDockNodeFlags_AutoHideTabBar; }
            if (GUI::MenuItem("Flag: PassthruCentralNode",    "", (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode) != 0, opt_fullscreen)) { dockspace_flags ^= ImGuiDockNodeFlags_PassthruCentralNode; }
            GUI::Separator();

            if (GUI::MenuItem("Close", NULL, false, p_open != NULL))
                *p_open = false;
            GUI::EndMenu();
        }
        HelpMarker(
            "When docking is enabled, you can ALWAYS dock MOST window into another! Try it now!" "\n\n"
            " > if io.ConfigDockingWithShift==false (default):" "\n"
            "   drag windows from title bar to dock" "\n"
            " > if io.ConfigDockingWithShift==true:" "\n"
            "   drag windows from anywhere and hold Shift to dock" "\n\n"
            "This demo app has nothing to do with it!" "\n\n"
            "This demo app only demonstrate the use of GUI::DockSpace() which allows you to manually create a docking node _within_ another window. This is useful so you can decorate your main application window (e.g. with a menu bar)." "\n\n"
            "GUI::DockSpace() comes with one hard constraint: it needs to be submitted _before_ any window which may be docked into it. Therefore, if you use a dock spot as the central point of your application, you'll probably want it to be part of the very first window you are submitting to imgui every frame." "\n\n"
            "(NB: because of this constraint, the implicit \"Debug\" window can not be docked into an explicit DockSpace() node, because that window is submitted as part of the NewFrame() call. An easy workaround is that you can create your own implicit \"Debug##2\" window after calling DockSpace() and leave it in the window stack for anyone to use.)"
        );

        GUI::EndMenuBar();
    }

    GUI::End();
}

//-----------------------------------------------------------------------------
// [SECTION] Example App: Documents Handling / ShowExampleAppDocuments()
//-----------------------------------------------------------------------------

// Simplified structure to mimic a Document model
struct MyDocument
{
    const char* Name;       // Document title
    bool        Open;       // Set when open (we keep an array of all available documents to simplify demo code!)
    bool        OpenPrev;   // Copy of Open from last update.
    bool        Dirty;      // Set when the document has been modified
    bool        WantClose;  // Set when the document
    ImVec4      Color;      // An arbitrary variable associated to the document

    MyDocument(const char* name, bool open = true, const ImVec4& color = ImVec4(1.0f, 1.0f, 1.0f, 1.0f))
    {
        Name = name;
        Open = OpenPrev = open;
        Dirty = false;
        WantClose = false;
        Color = color;
    }
    void DoOpen()       { Open = true; }
    void DoQueueClose() { WantClose = true; }
    void DoForceClose() { Open = false; Dirty = false; }
    void DoSave()       { Dirty = false; }

    // Display placeholder contents for the Document
    static void DisplayContents(MyDocument* doc)
    {
        GUI::PushID(doc);
        GUI::Text("Document \"%s\"", doc->Name);
        GUI::PushStyleColor(ImGuiCol_Text, doc->Color);
        GUI::TextWrapped("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.");
        GUI::PopStyleColor();
        if (GUI::Button("Modify", ImVec2(100, 0)))
            doc->Dirty = true;
        GUI::SameLine();
        if (GUI::Button("Save", ImVec2(100, 0)))
            doc->DoSave();
        GUI::ColorEdit3("color", &doc->Color.x);  // Useful to test drag and drop and hold-dragged-to-open-tab behavior.
        GUI::PopID();
    }

    // Display context menu for the Document
    static void DisplayContextMenu(MyDocument* doc)
    {
        if (!GUI::BeginPopupContextItem())
            return;

        char buf[256];
        sprintf(buf, "Save %s", doc->Name);
        if (GUI::MenuItem(buf, "CTRL+S", false, doc->Open))
            doc->DoSave();
        if (GUI::MenuItem("Close", "CTRL+W", false, doc->Open))
            doc->DoQueueClose();
        GUI::EndPopup();
    }
};

struct ExampleAppDocuments
{
    ImVector<MyDocument> Documents;

    ExampleAppDocuments()
    {
        Documents.push_back(MyDocument("Lettuce",             true,  ImVec4(0.4f, 0.8f, 0.4f, 1.0f)));
        Documents.push_back(MyDocument("Eggplant",            true,  ImVec4(0.8f, 0.5f, 1.0f, 1.0f)));
        Documents.push_back(MyDocument("Carrot",              true,  ImVec4(1.0f, 0.8f, 0.5f, 1.0f)));
        Documents.push_back(MyDocument("Tomato",              false, ImVec4(1.0f, 0.3f, 0.4f, 1.0f)));
        Documents.push_back(MyDocument("A Rather Long Title", false));
        Documents.push_back(MyDocument("Some Document",       false));
    }
};

// [Optional] Notify the system of Tabs/Windows closure that happened outside the regular tab interface.
// If a tab has been closed programmatically (aka closed from another source such as the Checkbox() in the demo,
// as opposed to clicking on the regular tab closing button) and stops being submitted, it will take a frame for
// the tab bar to notice its absence. During this frame there will be a gap in the tab bar, and if the tab that has
// disappeared was the selected one, the tab bar will report no selected tab during the frame. This will effectively
// give the impression of a flicker for one frame.
// We call SetTabItemClosed() to manually notify the Tab Bar or Docking system of removed tabs to avoid this glitch.
// Note that this completely optional, and only affect tab bars with the ImGuiTabBarFlags_Reorderable flag.
static void NotifyOfDocumentsClosedElsewhere(ExampleAppDocuments& app)
{
    for (int doc_n = 0; doc_n < app.Documents.Size; doc_n++)
    {
        MyDocument* doc = &app.Documents[doc_n];
        if (!doc->Open && doc->OpenPrev)
            GUI::SetTabItemClosed(doc->Name);
        doc->OpenPrev = doc->Open;
    }
}

void ShowExampleAppDocuments(bool* p_open)
{
    static ExampleAppDocuments app;

    // Options
    enum Target
    {
        Target_None,
        Target_Tab,                 // Create documents as local tab into a local tab bar
        Target_DockSpaceAndWindow   // Create documents as regular windows, and create an embedded dockspace
    };
    static Target opt_target = Target_Tab;
    static bool opt_reorderable = true;
    static ImGuiTabBarFlags opt_fitting_flags = ImGuiTabBarFlags_FittingPolicyDefault_;

    // When (opt_target == Target_DockSpaceAndWindow) there is the possibily that one of our child Document window (e.g. "Eggplant")
    // that we emit gets docked into the same spot as the parent window ("Example: Documents").
    // This would create a problematic feedback loop because selecting the "Eggplant" tab would make the "Example: Documents" tab
    // not visible, which in turn would stop submitting the "Eggplant" window.
    // We avoid this problem by submitting our documents window even if our parent window is not currently visible.
    // Another solution may be to make the "Example: Documents" window use the ImGuiWindowFlags_NoDocking.

    bool window_contents_visible = GUI::Begin("Example: Documents", p_open, ImGuiWindowFlags_MenuBar);
    if (!window_contents_visible && opt_target != Target_DockSpaceAndWindow)
    {
        GUI::End();
        return;
    }

    // Menu
    if (GUI::BeginMenuBar())
    {
        if (GUI::BeginMenu("File"))
        {
            int open_count = 0;
            for (int doc_n = 0; doc_n < app.Documents.Size; doc_n++)
                open_count += app.Documents[doc_n].Open ? 1 : 0;

            if (GUI::BeginMenu("Open", open_count < app.Documents.Size))
            {
                for (int doc_n = 0; doc_n < app.Documents.Size; doc_n++)
                {
                    MyDocument* doc = &app.Documents[doc_n];
                    if (!doc->Open)
                        if (GUI::MenuItem(doc->Name))
                            doc->DoOpen();
                }
                GUI::EndMenu();
            }
            if (GUI::MenuItem("Close All Documents", NULL, false, open_count > 0))
                for (int doc_n = 0; doc_n < app.Documents.Size; doc_n++)
                    app.Documents[doc_n].DoQueueClose();
            if (GUI::MenuItem("Exit", "Alt+F4")) {}
            GUI::EndMenu();
        }
        GUI::EndMenuBar();
    }

    // [Debug] List documents with one checkbox for each
    for (int doc_n = 0; doc_n < app.Documents.Size; doc_n++)
    {
        MyDocument* doc = &app.Documents[doc_n];
        if (doc_n > 0)
            GUI::SameLine();
        GUI::PushID(doc);
        if (GUI::Checkbox(doc->Name, &doc->Open))
            if (!doc->Open)
                doc->DoForceClose();
        GUI::PopID();
    }
    GUI::PushItemWidth(GUI::GetFontSize() * 12);
    GUI::Combo("Output", (int*)&opt_target, "None\0TabBar+Tabs\0DockSpace+Window\0");
    GUI::PopItemWidth();
    bool redock_all = false;
    if (opt_target == Target_Tab)                { GUI::SameLine(); GUI::Checkbox("Reorderable Tabs", &opt_reorderable); }
    if (opt_target == Target_DockSpaceAndWindow) { GUI::SameLine(); redock_all = GUI::Button("Redock all"); }

    GUI::Separator();

    // Tabs
    if (opt_target == Target_Tab)
    {
        ImGuiTabBarFlags tab_bar_flags = (opt_fitting_flags) | (opt_reorderable ? ImGuiTabBarFlags_Reorderable : 0);
        if (GUI::BeginTabBar("##tabs", tab_bar_flags))
        {
            if (opt_reorderable)
                NotifyOfDocumentsClosedElsewhere(app);

            // [DEBUG] Stress tests
            //if ((GUI::GetFrameCount() % 30) == 0) docs[1].Open ^= 1;            // [DEBUG] Automatically show/hide a tab. Test various interactions e.g. dragging with this on.
            //if (GUI::GetIO().KeyCtrl) GUI::SetTabItemSelected(docs[1].Name);  // [DEBUG] Test SetTabItemSelected(), probably not very useful as-is anyway..

            // Submit Tabs
            for (int doc_n = 0; doc_n < app.Documents.Size; doc_n++)
            {
                MyDocument* doc = &app.Documents[doc_n];
                if (!doc->Open)
                    continue;

                ImGuiTabItemFlags tab_flags = (doc->Dirty ? ImGuiTabItemFlags_UnsavedDocument : 0);
                bool visible = GUI::BeginTabItem(doc->Name, &doc->Open, tab_flags);

                // Cancel attempt to close when unsaved add to save queue so we can display a popup.
                if (!doc->Open && doc->Dirty)
                {
                    doc->Open = true;
                    doc->DoQueueClose();
                }

                MyDocument::DisplayContextMenu(doc);
                if (visible)
                {
                    MyDocument::DisplayContents(doc);
                    GUI::EndTabItem();
                }
            }

            GUI::EndTabBar();
        }
    }
    else if (opt_target == Target_DockSpaceAndWindow)
    {
        if (GUI::GetIO().ConfigFlags & ImGuiConfigFlags_DockingEnable)
        {
            NotifyOfDocumentsClosedElsewhere(app);

            // Create a DockSpace node where any window can be docked
            ImGuiID dockspace_id = GUI::GetID("MyDockSpace");
            GUI::DockSpace(dockspace_id);

            // Create Windows
            for (int doc_n = 0; doc_n < app.Documents.Size; doc_n++)
            {
                MyDocument* doc = &app.Documents[doc_n];
                if (!doc->Open)
                    continue;

                GUI::SetNextWindowDockID(dockspace_id, redock_all ? ImGuiCond_Always : ImGuiCond_FirstUseEver);
                ImGuiWindowFlags window_flags = (doc->Dirty ? ImGuiWindowFlags_UnsavedDocument : 0);
                bool visible = GUI::Begin(doc->Name, &doc->Open, window_flags);

                // Cancel attempt to close when unsaved add to save queue so we can display a popup.
                if (!doc->Open && doc->Dirty)
                {
                    doc->Open = true;
                    doc->DoQueueClose();
                }

                MyDocument::DisplayContextMenu(doc);
                if (visible)
                    MyDocument::DisplayContents(doc);

                GUI::End();
            }
        }
        else
        {
            ShowDockingDisabledMessage();
        }
    }

    // Early out other contents
    if (!window_contents_visible)
    {
        GUI::End();
        return;
    }

    // Update closing queue
    static ImVector<MyDocument*> close_queue;
    if (close_queue.empty())
    {
        // Close queue is locked once we started a popup
        for (int doc_n = 0; doc_n < app.Documents.Size; doc_n++)
        {
            MyDocument* doc = &app.Documents[doc_n];
            if (doc->WantClose)
            {
                doc->WantClose = false;
                close_queue.push_back(doc);
            }
        }
    }

    // Display closing confirmation UI
    if (!close_queue.empty())
    {
        int close_queue_unsaved_documents = 0;
        for (int n = 0; n < close_queue.Size; n++)
            if (close_queue[n]->Dirty)
                close_queue_unsaved_documents++;

        if (close_queue_unsaved_documents == 0)
        {
            // Close documents when all are unsaved
            for (int n = 0; n < close_queue.Size; n++)
                close_queue[n]->DoForceClose();
            close_queue.clear();
        }
        else
        {
            if (!GUI::IsPopupOpen("Save?"))
                GUI::OpenPopup("Save?");
            if (GUI::BeginPopupModal("Save?"))
            {
                GUI::Text("Save change to the following items?");
                GUI::SetNextItemWidth(-1.0f);
                if (GUI::ListBoxHeader("##", close_queue_unsaved_documents, 6))
                {
                    for (int n = 0; n < close_queue.Size; n++)
                        if (close_queue[n]->Dirty)
                            GUI::Text("%s", close_queue[n]->Name);
                    GUI::ListBoxFooter();
                }

                if (GUI::Button("Yes", ImVec2(80, 0)))
                {
                    for (int n = 0; n < close_queue.Size; n++)
                    {
                        if (close_queue[n]->Dirty)
                            close_queue[n]->DoSave();
                        close_queue[n]->DoForceClose();
                    }
                    close_queue.clear();
                    GUI::CloseCurrentPopup();
                }
                GUI::SameLine();
                if (GUI::Button("No", ImVec2(80, 0)))
                {
                    for (int n = 0; n < close_queue.Size; n++)
                        close_queue[n]->DoForceClose();
                    close_queue.clear();
                    GUI::CloseCurrentPopup();
                }
                GUI::SameLine();
                if (GUI::Button("Cancel", ImVec2(80, 0)))
                {
                    close_queue.clear();
                    GUI::CloseCurrentPopup();
                }
                GUI::EndPopup();
            }
        }
    }

    GUI::End();
}

// End of Demo code
#else

void GUI::ShowAboutWindow(bool*) {}
void GUI::ShowDemoWindow(bool*) {}
void GUI::ShowUserGuide() {}
void GUI::ShowStyleEditor(imgui_style*) {}

#endif