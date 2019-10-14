import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "Zlib"
    Depends { name: "Qt"; submodules: []}

    architectures: ["x86"]
    targetPlatform: "windows"
    hasLibrary: false
    staticLibsDebug: []
    staticLibsRelease: []
    dynamicLibsDebug: []
    dynamicLibsRelease: []
    linkerFlagsDebug: []
    linkerFlagsRelease: []
    frameworksDebug: []
    frameworksRelease: []
    frameworkPathsDebug: []
    frameworkPathsRelease: []
    libNameForLinkerDebug: undefined
    libNameForLinkerRelease: undefined
    libFilePathDebug: undefined
    libFilePathRelease: undefined
    pluginTypes: []
    moduleConfig: []
    cpp.defines: ["QT_ZLIB_LIB"]
    cpp.includePaths: ["C:/Qt/5.13.0/msvc2017/include","C:/Qt/5.13.0/msvc2017/include/QtZlib","C:/Qt/5.13.0/msvc2017/include/QtZlib/5.13.0","C:/Qt/5.13.0/msvc2017/include/QtZlib/5.13.0/QtZlib"]
    cpp.libraryPaths: []
    
}
