SET(SOURCES screens/ui_Screen1.c
    screens/ui_Screen2.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    ui_events.c
    images/ui_img_act021_png.c
    images/ui_img_1076440284.c
    fonts/ui_font_Font1.c)

add_library(ui ${SOURCES})
