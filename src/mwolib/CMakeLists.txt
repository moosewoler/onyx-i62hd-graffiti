ENABLE_QT()

set (OUTPUT_LIB_NAME mwo)

file(GLOB_RECURSE HDRS *.h)
file(GLOB_RECURSE SRCS *.cpp *.c)
set (SRCS ${HDRS} ${SRCS})

# TODO: put QT Moc files here.
set (MOC_HDRS graffiti_hui.h)
QT4_WRAP_CPP(MOC_SRCS ${MOC_HDRS})

## TODO: put resources here.
##set (RESOURCE_SRCS images.qrc)
##QT4_ADD_RESOURCES(IMAGES_RES ${RESOURCE_SRCS})

add_library(${OUTPUT_LIB_NAME} ${SRCS} ${MOC_SRCS} ${IMAGES_RES})
target_link_libraries(${OUTPUT_LIB_NAME}
   onyx_data
   onyx_screen
   onyx_sys
   onyx_ui
   ${QT_LIBRARIES}
   ${ADD_LIB}
)
