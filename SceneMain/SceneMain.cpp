#include "SceneMain.hpp"
#include "PerspectiveCamera.hpp"
#include "ParticleSystem/ParticleSystem.hpp"
#include "ParticleSystem/MyParticleEmitter.hpp"
#include "Fireball.hpp"

SceneMain::SceneMain() : debugCounter(0.0), fpsCount(0) {
	this->setName("SCENE");

	//SCENE INIT
	if (!loadResources())
	{VBE_ASSERT(false, "Could not load resources for SceneMain" );}

	//Center mouse
	//	Input::setMousePos(SCRWIDTH/2,SCRHEIGHT/2,game->getWindow());
	radius = 0;
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
	cam->pos = vec3f(0,0,10);
	cam->addTo(this);

	particles = new ParticleSystem();
	particles->addTo(this);
	Fireball* fir = new Fireball();
	fir->addTo(this);
	//	MyParticleEmitter* emitter = new MyParticleEmitter(200);
	//	emitter->addTo(cam);
	//	emitter->setName("pe");
	//	ParticleEmitter* emitter2 = new ParticleEmitter(100);
	//	emitter2->addTo(cam);
	//	emitter2->setName("pe2");
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
	Programs.add("particleShader",p);
	p = new ShaderProgram();
	if(!p->makeProgram("data/shaders/fireball.vert","data/shaders/fireball.frag")) return false;
	Programs.add("fireballShader",p);
	//Textures
	Texture* tex = new Texture(1);
	if(!tex->loadFromFile("data/labuena.png",true)) return false;
	Textures.add("fireballTex",tex);
	//Meshes
	Meshes.add("fireballMesh",new Mesh("data/fireball.obj"));
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
	Fireball* fireball = GameObject::getFirstObjectOfType<Fireball>();
	vec3f newpos = vec3f(5*(Input::getMousePos().x/float(SCRWIDTH)*2 - 1),
						-5*(Input::getMousePos().y/float(SCRHEIGHT)*2 - 1),
						 0);

	vec3f dir = newpos - fireball->pos;

	fireball->vel += dir*deltaTime*4.0f;
}


