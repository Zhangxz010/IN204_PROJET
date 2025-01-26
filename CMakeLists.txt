# Définir la version minimale requise de CMake
cmake_minimum_required(VERSION 3.14)

# Nom du projet et normes C++
project(ComicBookReader)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ajouter des options de compilation
add_compile_options(-Wno-deprecated-declarations)

# Définir les chemins des fichiers d'en-tête et des bibliothèques
include_directories(
    /usr/include/quazip5               # Chemin des fichiers d'en-tête de QuaZip
    /usr/include/poppler/qt5           # Chemin des fichiers d'en-tête de Poppler
    ${CMAKE_SOURCE_DIR}/include        # Chemin des fichiers d'en-tête du projet
)
link_directories(
    /usr/lib/x86_64-linux-gnu          # Chemin des bibliothèques QuaZip et Poppler
)

# Rechercher automatiquement les fichiers source, d'en-tête et UI
file(GLOB_RECURSE SRC_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE HEADER_FILES ${CMAKE_SOURCE_DIR}/include/*.h)
set(UI_FILES
    ${CMAKE_SOURCE_DIR}/src/gui/mainwindow.ui
)
set(RESOURCES_FILES
    ${CMAKE_SOURCE_DIR}/resources.qrc
)

# Générer les fichiers nécessaires à Qt
qt5_wrap_ui(UI_HEADERS ${UI_FILES})
qt5_wrap_cpp(MOC_HEADERS ${HEADER_FILES})
qt5_add_resources(RESOURCE_FILES ${RESOURCES_FILES})

# Définir l'exécutable
add_executable(${PROJECT_NAME}
    ${SRC_FILES}
    ${MOC_HEADERS}
    ${UI_HEADERS}
    ${RESOURCE_FILES}
)

# Lier les bibliothèques nécessaires
find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets Concurrent)
target_link_libraries(${PROJECT_NAME}
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
    Qt5::Concurrent
    quazip5                         # Bibliothèque QuaZip
    poppler-qt5                     # Bibliothèque Poppler
    unrar                           # Bibliothèque unrar
)

# Afficher les messages de configuration (optionnel)
message(STATUS "Nom du projet : ${PROJECT_NAME}")
message(STATUS "Norme C++ : ${CMAKE_CXX_STANDARD}")
message(STATUS "Chemin des en-têtes QuaZip : /usr/include/quazip5")
message(STATUS "Chemin des bibliothèques QuaZip : /usr/lib/x86_64-linux-gnu")
