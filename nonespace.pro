TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
INCLUDEPATH += -I/usr/include/allegro5
LIBS += -lallegro -lallegro_primitives -lallegro_image -lallegro_font -lallegro_ttf -lpthread

SOURCES += \
    main.c \
    start.c \
    select.c \
    run.c \
    spaceship.c \
    blast.c \
    gif/gif.c \
    gif/lzw.c \
    gif/bitmap.c \
    gif/algif.c \
    weapen.c \
    enemy.c \
    boss.c \
    collision.c

HEADERS += \
    main.h \
    main.h \
    start.h \
    select.h \
    run.h \
    spaceship.h \
    blast.h \
    gif/algif.h \
    weapen.h \
    enemy.h \
    boss.h \
    collision.h

DISTFILES +=

