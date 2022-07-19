find_package(Qt5 COMPONENTS Widgets Core REQUIRED)
find_package(MVVM REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

set(SOURCES
    graphmodel.cpp
    graphwidget.cpp
    mainwindow.cpp
    statusbarwidget.cpp
)

set(HEADERS
    graphmodel.h
    graphwidget.h
    mainwindow.h
    statusbarwidget.h
)

set(UI_FORMS
    graphwidget.ui
    mainwindow.ui
    statusbarwidget.ui
)

set(SOURCES ${SOURCES} ${HEADERS} ${UI_FORMS})

add_library(gui_static STATIC ${SOURCES})
target_link_libraries(gui_static PUBLIC Qt5::Core Qt5::Widgets)
target_link_libraries(gui_static PUBLIC ${MVVM_LIBRARIES})

