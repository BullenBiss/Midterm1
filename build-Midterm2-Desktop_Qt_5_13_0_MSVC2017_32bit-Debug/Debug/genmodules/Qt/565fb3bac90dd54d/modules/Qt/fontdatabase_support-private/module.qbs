import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "FontDatabaseSupport"
    Depends { name: "Qt"; submodules: ["core-private","gui-private"]}

    architectures: ["x86"]
    targetPlatform: "windows"
    hasLibrary: true
    staticLibsDebug: ["ole32","gdi32","user32","advapi32","C:/Qt/5.13.0/msvc2017/lib/qtfreetyped.lib","C:/Qt/5.13.0/msvc2017/lib/qtlibpngd.lib","dwrite","d2d1"]
    staticLibsRelease: ["ole32","gdi32","user32","advapi32","C:/Qt/5.13.0/msvc2017/lib/qtfreetype.lib","C:/Qt/5.13.0/msvc2017/lib/qtlibpng.lib","dwrite","d2d1"]
    dynamicLibsDebug: []
    dynamicLibsRelease: []
    linkerFlagsDebug: []
    linkerFlagsRelease: []
    frameworksDebug: []
    frameworksRelease: []
    frameworkPathsDebug: []
    frameworkPathsRelease: []
    libNameForLinkerDebug: "Qt5FontDatabaseSupportd.lib"
    libNameForLinkerRelease: "Qt5FontDatabaseSupport.lib"
    libFilePathDebug: "C:/Qt/5.13.0/msvc2017/lib/Qt5FontDatabaseSupportd.lib"
    libFilePathRelease: "C:/Qt/5.13.0/msvc2017/lib/Qt5FontDatabaseSupport.lib"
    pluginTypes: []
    moduleConfig: ["lex","yacc","depend_includepath","testcase_targets","import_qpa_plugin","windows","qt_build_extra","file_copies","qmake_use","qt","warn_on","release","link_prl","flat","debug_and_release","precompile_header","autogen_precompile_source","embed_manifest_dll","embed_manifest_exe","release","no_plugin_manifest","win32","msvc","copy_dir_files","sse2","aesni","sse3","ssse3","sse4_1","sse4_2","avx","avx2","avx512f","avx512bw","avx512cd","avx512dq","avx512er","avx512ifma","avx512pf","avx512vbmi","avx512vl","compile_examples","f16c","force_debug_info","largefile","precompile_header","rdrnd","shani","x86SimdAlways","prefix_build","force_independent","utf8_source","create_prl","link_prl","prepare_docs","qt_docs_targets","no_private_qt_headers_warning","QTDIR_build","qt_example_installs","exceptions_off","testcase_exceptions","warning_clean","release","ReleaseBuild","Release","build_pass","c++11","static","internal_module","relative_qt_rpath","git_build","qmake_cache","target_qt","c++11","strict_c++","c++14","c++1z","qt_install_headers","need_fwd_pri","qt_install_module","debug_and_release","build_all","skip_target_version_ext","release","ReleaseBuild","Release","build_pass","have_target","staticlib","exclusive_builds","debug_info","no_autoqmake","thread","opengl","moc","resources"]
    cpp.defines: ["QT_FONTDATABASE_SUPPORT_LIB"]
    cpp.includePaths: ["C:/Qt/5.13.0/msvc2017/include","C:/Qt/5.13.0/msvc2017/include/QtFontDatabaseSupport","C:/Qt/5.13.0/msvc2017/include/QtFontDatabaseSupport/5.13.0","C:/Qt/5.13.0/msvc2017/include/QtFontDatabaseSupport/5.13.0/QtFontDatabaseSupport"]
    cpp.libraryPaths: ["C:/opensslx86/lib","C:/Utils/postgresqlx86/pgsql/lib","C:/opensslx86/lib","C:/Utils/postgresqlx86/pgsql/lib","C:/opensslx86/lib","C:/Utils/postgresqlx86/pgsql/lib","C:/opensslx86/lib","C:/Utils/postgresqlx86/pgsql/lib"]
    isStaticLibrary: true
Group {
        files: [Qt["fontdatabase_support-private"].libFilePath]
        filesAreTargets: true
        fileTags: ["staticlibrary"]
    }
}
