cmake_minimum_required(VERSION 3.19)
project(GoidaZvon LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_resources(RESOURCE_FILES res.qrc)

qt_add_executable(GoidaZvon
    WIN32 MACOSX_BUNDLE

    ${RESOURCE_FILES}

    main.cpp

    header/mainwindow.h
    header/login.h
    header/loadingscreen.h

    src/mainwindow.cpp
    src/login.cpp
    src/loadingscreen.cpp

    misc/clickQLabel.h
    misc/clickQLabel.cpp
)

qt_add_ui(GoidaZvon SOURCES
    forms/login.ui
    forms/loadingscreen.ui
)

target_link_libraries(GoidaZvon
    PRIVATE
        Qt::Core
        Qt::Widgets
)

include(GNUInstallDirs)

install(TARGETS GoidaZvon
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET GoidaZvon
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
