# 设置 CMake 最低版本
cmake_minimum_required(VERSION 3.14)

# 项目名称
project(ComicBookReader)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找 Qt5 必要组件
find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets Concurrent)


add_compile_options(-Wno-deprecated-declarations)


# 添加 QuaZip 和 Poppler 的头文件路径
include_directories(
    /usr/include/quazip5               # QuaZip 头文件路径
    /usr/include/poppler/qt5           # Poppler 头文件路径
    ${CMAKE_SOURCE_DIR}/include        # 项目头文件路径
)

# 添加 QuaZip 和 Poppler 的库路径
link_directories(
    /usr/lib/x86_64-linux-gnu          # QuaZip 和 Poppler 库路径
)

# 自动查找源文件和头文件
file(GLOB_RECURSE SRC_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE HEADER_FILES ${CMAKE_SOURCE_DIR}/include/*.h)

# 定义 UI 文件
set(UI
    ${CMAKE_SOURCE_DIR}/src/gui/mainwindow.ui
)

# 定义资源文件
set(RESOURCES
    ${CMAKE_SOURCE_DIR}/resources.qrc
)

# 生成 UI 和资源文件
qt5_wrap_ui(UI_HEADERS ${UI})
qt5_wrap_cpp(MOC_HEADERS ${HEADER_FILES})
qt5_add_resources(RESOURCE_FILES ${RESOURCES})

# 定义可执行文件
add_executable(${PROJECT_NAME}
    ${SRC_FILES}
    ${MOC_HEADERS}
    ${UI_HEADERS}
    ${RESOURCE_FILES}
)

# 链接 Qt 和 QuaZip、Poppler 库
target_link_libraries(${PROJECT_NAME}
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
    Qt5::Concurrent
    quazip5                         # QuaZip 库
    poppler-qt5                     # Poppler 库
    unrar                           # unrar 库
)

# 打印配置日志（可选）
message(STATUS "Project Name: ${PROJECT_NAME}")
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "QuaZip Include Path: /usr/include/quazip5")
message(STATUS "QuaZip Library Path: /usr/lib/x86_64-linux-gnu")
