include(VBE/VBE.pro)
INCLUDEPATH += .
DEFINES += __DLOG
SOURCES += \
	main.cpp \
	SceneMain/SceneMain.cpp \
	SceneMain/PerspectiveCamera.cpp \
	Commons.cpp \
    SceneMain/Fireball.cpp \
    SceneMain/ParticleSystem/MyParticleEmitter.cpp \
    SceneMain/ParticleSystem/FireParticleEmitter.cpp

HEADERS += \
	SceneMain/SceneMain.hpp \
	SceneMain/PerspectiveCamera.hpp \
	Commons.hpp \
    SceneMain/Fireball.hpp \
    SceneMain/ParticleSystem/MyParticleEmitter.hpp \
    SceneMain/ParticleSystem/FireParticleEmitter.hpp

OTHER_FILES += \
    data/shaders/fireball.vert \
    data/shaders/fireball.frag

