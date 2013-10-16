#include "SceneMain.hpp"
#include "PerspectiveCamera.hpp"
#include "ParticleSystem/ParticleSystem.hpp"
#include "ParticleSystem/Myparticleemitter.hpp"

SceneMain::SceneMain() : debugCounter(0.0), fpsCount(0) {
	this->setName("SCENE");

	//SCENE INIT
	if (!loadResources())
	{VBE_ASSERT(false, "Could not load resources for SceneMain" );}

	//Center mouse
//	Input::setMousePos(SCRWIDTH/2,SCRHEIGHT/2,game->getWindow());
	radius =0;
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

	particles = new ParticleSystem();
	particles->addTo(this);

	MyParticleEmitter* emitter = new MyParticleEmitter(2000);
	emitter->addTo(cam);
	emitter->setName("pe");
	ParticleEmitter* emitter2 = new ParticleEmitter(10000);
	emitter2->addTo(cam);
	emitter2->setName("pe2");
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
	if(!p->makeProgram("data/shaders/particle.vert","data/shaders/particle.geom","data/shaders/particle.frag")) return false;
	Programs.add("particle",p);
	return true;
}

void SceneMain::update(float deltaTime) {
	++fpsCount;
	debugCounter += deltaTime;
	if (debugCounter > 1) {
		VBE_LOG("FPS: " << fpsCount << ". Amount of GameObjects: " << getGame()->getObjectCount() << ". Amount of particles: " << particles->getParticleCount());
		debugCounter--;
		fpsCount = 0;
	}

	float t = GLOBALCLOCK.getElapsedTime().asSeconds();
	radius = sin(t*0.132)*2.0f;
	float tt = t*12.521;
	MyParticleEmitter* pe = (MyParticleEmitter*)getGame()->getObjectByName("pe");
	pe->color = vec4f(sin(tt), sin(2*tt+0.231), sin(3*tt+0.4123),1.0f);
	pe->color = pe->color*0.5f+0.5f;
	pe->color = glm::normalize(pe->color);

	float speed = 5;
	vec2f lol = vec2f(30*sin(t*speed),30*sin(t*speed*2));
	lol.y *= 0.6f;

	pe->pos.x = lol.x*radius;
	pe->pos.y = lol.y*radius;

	ParticleEmitter* pe2 = (ParticleEmitter*)getGame()->getObjectByName("pe2");
	pe2->pos.x = lol.x*radius;
	pe2->pos.y = lol.y*radius;
}


