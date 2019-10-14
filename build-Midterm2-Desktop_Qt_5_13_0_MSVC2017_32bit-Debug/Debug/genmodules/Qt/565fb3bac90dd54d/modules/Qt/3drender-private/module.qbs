import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "3DRender"
    Depends { name: "Qt"; submodules: ["core-private","gui-private","3dcore-private","3drender","concurrent"]}

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
    cpp.includePaths: ["C:/Qt/5.13.0/msvc2017/include/Qt3DRender/5.13.0","C:/Qt/5.13.0/msvc2017/include/Qt3DRender/5.13.0/Qt3DRender"]
    cpp.libraryPaths: []
    
}
