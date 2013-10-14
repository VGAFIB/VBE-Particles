
include(VBE/VBE.pro)
DEFINES += __LOG __DLOG
INCLUDEPATH += .

SOURCES += \
	main.cpp \
	SceneMain/SceneMain.cpp \
	SceneMain/PerspectiveCamera.cpp \
    Commons.cpp \
    SceneMain/ParticleSystem/ParticleSystem.cpp \
    SceneMain/ParticleSystem/Particle.cpp \
    SceneMain/ParticleSystem/ParticleEmitter.cpp

HEADERS += \
	SceneMain/SceneMain.hpp \
	SceneMain/PerspectiveCamera.hpp \
    Commons.hpp \
    SceneMain/ParticleSystem/ParticleSystem.hpp \
    SceneMain/ParticleSystem/Particle.hpp \
    SceneMain/ParticleSystem/ParticleEmitter.hpp

OTHER_FILES += \
    data/shaders/particle.vert \
    data/shaders/particle.frag

