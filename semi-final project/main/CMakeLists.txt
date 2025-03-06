cmake_minimum_required(VERSION 3.19)
project(GoidaZvon LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)
set (CMAKE_CXX_STANDARD 23)

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

    misc/httplib.h
    misc/clickQLabel.h
    misc/clickQLabel.cpp
    register.h register.cpp register.ui
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

if(WIN32)
    set(LIBRARY_PATH "C:/msys64/ucrt64/lib")

    target_link_libraries(GoidaZvon PRIVATE
        ${LIBRARY_PATH}/libssl.a
        ${LIBRARY_PATH}/libcrypto.a
        ${LIBRARY_PATH}/libcrypt32.a
        ${LIBRARY_PATH}/libbcrypt.a
        ${LIBRARY_PATH}/libws2_32.a
    )
elseif(UNIX)
    find_package(OpenSSL REQUIRED)
    target_link_libraries(GoidaZvon PRIVATE
        OpenSSL::SSL
        OpenSSL::Crypto
    )
endif()

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
