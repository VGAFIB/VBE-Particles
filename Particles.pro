include(VBE/VBE.pro)
INCLUDEPATH += .

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
    data/shaders/particle.vert \
    data/shaders/particle.frag \
    data/shaders/particle.geom \
    data/shaders/fireball.vert \
    data/shaders/fireball.frag

