import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "WinExtras"
    Depends { name: "Qt"; submodules: ["gui-private","core-private","winextras"]}

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
    cpp.defines: []
    cpp.includePaths: ["C:/Qt/5.13.0/msvc2017/include/QtWinExtras/5.13.0","C:/Qt/5.13.0/msvc2017/include/QtWinExtras/5.13.0/QtWinExtras"]
    cpp.libraryPaths: []
    
}
