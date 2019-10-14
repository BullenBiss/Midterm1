import '../QtModule.qbs' as QtModule

QtModule {
    qtModuleName: "TextToSpeech"
    Depends { name: "Qt"; submodules: ["core-private","texttospeech"]}

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
    cpp.includePaths: ["C:/Qt/5.13.0/msvc2017/include/QtTextToSpeech/5.13.0","C:/Qt/5.13.0/msvc2017/include/QtTextToSpeech/5.13.0/QtTextToSpeech"]
    cpp.libraryPaths: []
    
}
