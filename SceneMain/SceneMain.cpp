#include "SceneMain.hpp"
#include "PerspectiveCamera.hpp"
#include "ParticleSystem/ParticleSystem.hpp"
#include "ParticleSystem/ParticleEmitter.hpp"

SceneMain::SceneMain() : debugCounter(0.0), fpsCount(0) {
	this->setName("SCENE");

	//SCENE INIT
	if (!loadResources())
	{VBE_ASSERT(false, "Could not load resources for SceneMain" );}

	//Center mouse
//	Input::setMousePos(SCRWIDTH/2,SCRHEIGHT/2,game->getWindow());

	//GL stuff..:
	glClearColor(0,0,0,1);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.01f);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_CULL_FACE); //enable backface culling
	glCullFace(GL_BACK);

	//Create camera
	PerspectiveCamera* cam = new PerspectiveCamera();
	cam->pos = vec3f(0,0,100);
	cam->addTo(this);

	ParticleSystem* particles = new ParticleSystem();
	particles->addTo(this);

	ParticleEmitter* emitter = new ParticleEmitter(30000);
	emitter->addTo(cam );
	emitter->setName("pe");
}

SceneMain::~SceneMain() {
	Textures.clear();
	Meshes.clear();
	Programs.clear();

	AudioManager::clear();
}

bool SceneMain::loadResources() {
	//shaders
	ShaderProgram* p = new ShaderProgram();
	if(!p->makeProgram("data/shaders/particle.vert","data/shaders/particle.frag")) return false;
	Programs.add("particle",p);
	return true;
}

void SceneMain::update(float deltaTime) {
	++fpsCount;
	debugCounter += deltaTime;
	if (debugCounter > 1) {
		VBE_LOG("FPS: " << fpsCount << ". Amount of GameObjects: " << getGame()->getObjectCount() );
		debugCounter--;
		fpsCount = 0;
	}
	ParticleEmitter* pe = (ParticleEmitter*)getGame()->getObjectByName("pe");
	vec2f lol = vec2f(20*sin(GLOBALCLOCK.getElapsedTime().asSeconds()*5),20*cos(GLOBALCLOCK.getElapsedTime().asSeconds()*5));
	lol *= 2*sin(GLOBALCLOCK.getElapsedTime().asSeconds()*10);
	pe->pos.x = lol.x;
	pe->pos.y = lol.y;
}


