#include "Fireball.hpp"
#include "PerspectiveCamera.hpp"
#include "ParticleSystem/FireParticleEmitter.hpp"
#include "ParticleSystem/MyParticleEmitter.hpp"

Fireball::Fireball() {
	model.mesh = Meshes.get("fireballMesh");
	model.program = Programs.get("fireballShader");
	FireParticleEmitter* emitter = new FireParticleEmitter(1000);
	emitter->addTo(this);
	MyParticleEmitter* emitter2 = new MyParticleEmitter(200);
	emitter2->addTo(this);
}

void Fireball::update(float deltaTime){
	float angle = GLOBALCLOCK.getElapsedTime().asSeconds()*100;
	transform = glm::rotate(mat4f(1.0f),angle,vec3f(0,1,0));
}

void Fireball::draw() const {
	PerspectiveCamera* cam = static_cast<PerspectiveCamera*>(getGame()->getObjectByName("cam"));
	model.program->uniform("modelViewProjectionMatrix")->set(cam->projection*cam->view*fullTransform);
	model.program->uniform("sampler")->set(Textures.get("fireballTex"));
	model.draw();
}
