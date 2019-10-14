import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "AxBase"
    Depends { name: "Qt"; submodules: ["gui-private","axbase"]}

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
    cpp.includePaths: ["C:/Qt/5.13.0/msvc2017/include/ActiveQt/5.13.0","C:/Qt/5.13.0/msvc2017/include/ActiveQt/5.13.0/ActiveQt"]
    cpp.libraryPaths: []
    isStaticLibrary: true
}
